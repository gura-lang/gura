#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Directory
//-----------------------------------------------------------------------------
Directory::Directory(Directory *pParent, const char *name, Type type, char chSeparator) :
	_cntRef(1), _pParent(pParent), _name(name), _type(type), _chSeparator(chSeparator)
{
}

Directory::Directory(const Directory &directory) : _cntRef(1),
	_pParent(Directory::Reference(directory._pParent)), _name(directory._name),
	_type(directory._type), _chSeparator(directory._chSeparator)
{
}

Directory::~Directory()
{
}

int Directory::DecRef()
{
	if (_cntRef > 0) _cntRef--;
	return _cntRef;
}

Stream *Directory::OpenStream(Environment &env, Signal sig,
									unsigned long attr, const char *encoding)
{
	return DoOpenStream(env, sig, attr, encoding);
}

Directory *Directory::Next(Environment &env, Signal sig)
{
	if (!IsContainer()) {
		sig.SetError(ERR_ValueError, "not a container entry");
		return NULL;
	}
	return DoNext(env, sig);
}

String Directory::MakePathName(bool addSepFlag, const char *pathNameTrail) const
{
	String pathName(_name);
	for (Directory *pDirectory = GetParent(); pDirectory != NULL;
										pDirectory = pDirectory->GetParent()) {
		// a "boundary container" directory may have an empty name
		if (*pDirectory->GetName() != '\0' || pDirectory->IsRootContainer()) {
			String str(pDirectory->GetName());
			str += pDirectory->GetSeparator();
			str += pathName;
			pathName = str;
		}
	}
	if (pathNameTrail != NULL) {
		pathName += GetSeparator();
		for (const char *p = pathNameTrail; *p != '\0'; p++) {
			char ch = IsFileSeparator(*p)? GetSeparator() : *p;
			pathName += ch;
		}
	} else if (addSepFlag && IsContainer() && !_name.empty()) {
		pathName += GetSeparator();
	}
	return pathName;
}

int Directory::CountDepth() const
{
	int depth = 0;
	for (const Directory *pDirectory = GetParent(); pDirectory != NULL;
										pDirectory = pDirectory->GetParent()) {
		depth++;
	}
	return depth;
}

Object *Directory::DoGetStatObj(Signal sig)
{
	sig.SetError(ERR_IOError, "can't retrieve stat object");
	return NULL;
}

void Directory::SplitFileName(const char *pathName, String *pDirName, String *pFileName)
{
	const char *p = pathName + ::strlen(pathName);
	for ( ; p > pathName; p--) {
		if (IsFileSeparator(*(p - 1))) break;
	}
	if (pDirName != NULL) *pDirName = String(pathName, p);
	if (pFileName != NULL) *pFileName = String(p);
}

void Directory::SplitBottom(const char *pathName, String *pTop, String *pBottom)
{
	const char *p = pathName + ::strlen(pathName);
	if (p > pathName && IsFileSeparator(*(p - 1))) p--;
	const char *pEnd = p;
	for ( ; p > pathName; p--) {
		if (IsFileSeparator(*(p - 1))) break;
	}
	if (pTop != NULL) *pTop = String(pathName, p);
	if (pBottom != NULL) *pBottom = String(p, pEnd);
}

const char *Directory::SeekExtName(const char *pathName)
{
	const char *pBtm = pathName + ::strlen(pathName);
	for (const char *p = pBtm; p >= pathName; p--) {
		if (*p == '.') {
			return (p == pathName || IsFileSeparator(*(p - 1)))? pBtm : p;
		}
		if (IsFileSeparator(*p)) break;
	}
	return pBtm;
}

bool Directory::HasWildCard(const char *pathName)
{
	for (const char *p = pathName; *p != '\0'; p++) {
		if (IsWildCardChar(*p)) return true;
	}
	return false;
}

bool Directory::IsMatchName(const char *pattern, const char *fileName, bool ignoreCaseFlag)
{
	if (*pattern == '!') {
		return !IsMatchNameSub(pattern + 1, fileName, ignoreCaseFlag);
	}
	return IsMatchNameSub(pattern, fileName, ignoreCaseFlag);
}
	
bool Directory::IsMatchNameSub(const char *pattern, const char *fileName, bool ignoreCaseFlag)
{
	if (*pattern == '\0') {
		return *fileName == '\0';
	} else if (*pattern == '*') {
		return IsMatchNameSub(pattern + 1, fileName, ignoreCaseFlag) ||
			*fileName != '\0' && IsMatchNameSub(pattern, fileName + 1, ignoreCaseFlag);
	} else if (*pattern == '?') {
		return *fileName != '\0' && IsMatchNameSub(pattern + 1, fileName + 1, ignoreCaseFlag);
	} else if (*pattern == '[') {
		bool negFlag = false;
		pattern++;
		if (*pattern == '!') {
			negFlag = true;
			pattern++;
			for ( ; *pattern != ']' && *pattern != '\0'; pattern++) {
				if (CompareChar(*fileName, *pattern, ignoreCaseFlag) == 0) return false;
			}
		} else {
			for ( ; *pattern != ']' && *pattern != '\0'; pattern++) {
				if (CompareChar(*fileName, *pattern, ignoreCaseFlag) != 0) return false;
			}
		}
		if (*pattern == ']') pattern++;
		return IsMatchNameSub(pattern, fileName + 1, ignoreCaseFlag);
	} else {
		return CompareChar(*pattern, *fileName, ignoreCaseFlag) == 0 &&
						IsMatchNameSub(pattern + 1, fileName + 1, ignoreCaseFlag);
	}
}

bool Directory::IsExist(Environment &env, Signal sig, const char *pathName)
{
	if (*pathName == '\0') return false;
	AutoPtr<Directory> pDirectory(OpenDirectory(env, sig, pathName, NF_NoSignal));
	return !pDirectory.IsNull();
}

bool Directory::IsContainer(Environment &env, Signal sig, const char *pathName)
{
	if (*pathName == '\0') return false;
	AutoPtr<Directory> pDirectory(OpenDirectory(env, sig, pathName, NF_NoSignal));
	return !pDirectory.IsNull() && pDirectory->IsContainer();
}

Directory *Directory::OpenDirectory(Environment &env, Signal sig,
							const char *pathName, NotFoundMode notFoundMode)
{
	return DirectoryFactory::OpenDirectory(env, sig, NULL, &pathName, notFoundMode);
}

Stream *Directory::OpenStream(Environment &env, Signal sig,
				const char *pathName, unsigned long attr, const char *encoding)
{
	if (*pathName == '>') {
		pathName++;
		attr = (attr & ~Stream::ATTR_Readable) | Stream::ATTR_Writable;
		if (*pathName == '>') {
			pathName++;
			attr |= Stream::ATTR_Append;
		}
	}
	Directory::NotFoundMode notFoundMode = (attr & Stream::ATTR_Writable)?
									Directory::NF_Wouldbe : Directory::NF_Signal;
	AutoPtr<Directory> pDirectory(OpenDirectory(env, sig, pathName, notFoundMode));
	if (sig.IsSignalled()) return NULL;
	return pDirectory->OpenStream(env, sig, attr, encoding);
}

//-----------------------------------------------------------------------------
// DirectoryFactory
//-----------------------------------------------------------------------------
DirectoryFactory::List *DirectoryFactory::_pList = NULL;

void DirectoryFactory::Register(DirectoryFactory *pDirectoryFactory)
{
	if (_pList == NULL) _pList = new List();
	_pList->push_back(pDirectoryFactory);
}

Directory *DirectoryFactory::OpenDirectory(Environment &env, Signal sig,
		Directory *pParent, const char **pPathName, Directory::NotFoundMode notFoundMode)
{
	Directory *pDirectory = pParent;
	do {
		DirectoryFactory *pDirectoryFactory =
						FindResponsible(env, sig, pDirectory, *pPathName);
		if (sig.IsSignalled()) return NULL;
		if (pDirectoryFactory == NULL) {
			sig.SetError(ERR_ValueError, "unsupported directory name");
			return NULL;
		}
		pDirectory = pDirectoryFactory->DoOpenDirectory(env, sig,
									pDirectory, pPathName, notFoundMode);
		if (sig.IsSignalled() || pDirectory == NULL) return NULL;
	} while (**pPathName != '\0');
	return pDirectory;
}

DirectoryFactory *DirectoryFactory::FindResponsible(Environment &env, Signal sig,
								const Directory *pParent, const char *pathName)
{
	if (_pList == NULL) return NULL;
	// The last-registered factory is searched first.
	foreach_reverse (List, ppDirectoryFactory, *_pList) {
		DirectoryFactory *pDirectoryFactory = *ppDirectoryFactory;
		if (pDirectoryFactory->IsResponsible(env, sig, pParent, pathName)) {
			return pDirectoryFactory;
		}
		if (sig.IsSignalled()) break;
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// Directory::Iterator_Walk
//-----------------------------------------------------------------------------
Directory::Iterator_Walk::Iterator_Walk(bool addSepFlag, bool statFlag,
				bool ignoreCaseFlag, bool fileFlag, bool dirFlag,
				Directory *pDirectory, int depthMax, const StringList &patterns) :
	Iterator(false),
	_addSepFlag(addSepFlag), _statFlag(statFlag), _ignoreCaseFlag(ignoreCaseFlag),
	_fileFlag(fileFlag), _dirFlag(dirFlag), _pDirectory(NULL), _depthMax(0),
	_patterns(patterns)
{
	_depthMax = (depthMax < 0)? -1 : pDirectory->CountDepth() + depthMax + 1;
	_directoryQue.push_back(pDirectory);
}

Directory::Iterator_Walk::~Iterator_Walk()
{
	foreach (DirectoryDeque, ppDirectory, _directoryQue) {
		Directory::Delete(*ppDirectory);
	}
}

Iterator *Directory::Iterator_Walk::GetSource()
{
	return NULL;
}

bool Directory::Iterator_Walk::DoNext(Environment &env, Signal sig, Value &value)
{
	for (;;) {
		Directory *pDirectoryChild = NULL;
		while (_pDirectory.IsNull() ||
				(pDirectoryChild = _pDirectory->Next(env, sig)) == NULL) {
			if (_directoryQue.empty()) {
				_pDirectory.reset(NULL);
				return false;
			}
			Directory *pDirectoryNext = _directoryQue.front();
			_directoryQue.pop_front();
			_pDirectory.reset(pDirectoryNext);
		}
		if (sig.IsSignalled()) return false;
		if (pDirectoryChild->IsContainer() &&
					(_depthMax < 0 || pDirectoryChild->CountDepth() < _depthMax)) {
			_directoryQue.push_back(Directory::Reference(pDirectoryChild));
		}
		bool typeMatchFlag =
				(pDirectoryChild->IsContainer() && _dirFlag) ||
				(!pDirectoryChild->IsContainer() && _fileFlag);
		if (typeMatchFlag) {
			bool matchFlag = false;
			foreach_const (StringList, pPattern, _patterns) {
				if (IsMatchName(pPattern->c_str(),
									pDirectoryChild->GetName(), _ignoreCaseFlag)) {
					matchFlag = true;
					break;
				}
			}
			if (_patterns.empty() || matchFlag) {
				if (_statFlag) {
					Object *pObj = pDirectoryChild->GetStatObj(sig);
					if (sig.IsSignalled()) return false;
					if (pObj != NULL) value = Value(pObj);
				} else {
					value = Value(env, pDirectoryChild->MakePathName(_addSepFlag).c_str());
				}
				Directory::Delete(pDirectoryChild);
				break;
			}
		}
		Directory::Delete(pDirectoryChild);
	}
	return true;
}

String Directory::Iterator_Walk::ToString(Signal sig) const
{
	String str;
	str = "<iterator:path.walk";
	str += _statFlag? ":stat" : ":name";
	str += ">";
	return str;
}

void Directory::Iterator_Walk::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Directory::Iterator_Glob
//-----------------------------------------------------------------------------
Directory::Iterator_Glob::Iterator_Glob(bool addSepFlag, bool statFlag,
							bool ignoreCaseFlag, bool fileFlag, bool dirFlag) :
	Iterator(false),
	_addSepFlag(addSepFlag), _statFlag(statFlag), _ignoreCaseFlag(ignoreCaseFlag),
	_fileFlag(fileFlag), _dirFlag(dirFlag), _pDirectory(NULL), _depth(0)
{
}

bool Directory::Iterator_Glob::Init(Environment &env, Signal sig, const char *pattern)
{
	String pathName, field;
	const char *patternTop = pattern;
	for (const char *p = pattern; ; p++) {
		char ch = *p;
		if (IsFileSeparator(ch) || ch == '\0') {
			patternTop = p;
			pathName += field;
			if (ch == '\0') break;
			patternTop++;
			pathName += ch;
			field.clear();
		} else if (Directory::IsWildCardChar(ch)) {
			break;
		} else {
			field += ch;
		}
	}
	field.clear();
	for (const char *p = patternTop; ; p++) {
		char ch = *p;
		if (IsFileSeparator(ch) || ch == '\0') {
			_patternSegs.push_back(field);
			if (ch == '\0') break;
		} else {
			field += ch;
		}
	}
	AutoPtr<Directory> pDirectory(Directory::OpenDirectory(env, sig,
									pathName.c_str(), Directory::NF_Signal));
	if (sig.IsSignalled()) return false;
	_directoryQue.push_back(pDirectory.release());
	_depthQue.push_back(0);
	return true;
}

Directory::Iterator_Glob::~Iterator_Glob()
{
	foreach (DirectoryDeque, ppDirectory, _directoryQue) {
		Directory::Delete(*ppDirectory);
	}
}

Iterator *Directory::Iterator_Glob::GetSource()
{
	return NULL;
}

bool Directory::Iterator_Glob::DoNext(Environment &env, Signal sig, Value &value)
{
	Directory *pDirectoryChild = NULL;
	for (;;) {
		while (_pDirectory.IsNull() ||
				(pDirectoryChild = _pDirectory->Next(env, sig)) == NULL) {
			if (_directoryQue.empty()) {
				_pDirectory.reset(NULL);
				return false;
			}
			Directory *pDirectoryNext = _directoryQue.front();
			_depth = _depthQue.front();
			_directoryQue.pop_front();
			_depthQue.pop_front();
			if (pDirectoryNext->IsContainer()) {
				_pDirectory.reset(pDirectoryNext);
			} else {
				_pDirectory.reset(NULL);
				pDirectoryChild = pDirectoryNext;
				goto found;
			}
		}
		if (sig.IsSignalled()) return false;
		if (IsMatchName(_patternSegs[_depth].c_str(),
								pDirectoryChild->GetName(), _ignoreCaseFlag)) {
			bool typeMatchFlag =
					(pDirectoryChild->IsContainer() && _dirFlag) ||
					(!pDirectoryChild->IsContainer() && _fileFlag);
			if (_depth + 1 < _patternSegs.size()) {
				if (pDirectoryChild->IsContainer()) {
					_directoryQue.push_back(Directory::Reference(pDirectoryChild));
					_depthQue.push_back(static_cast<unsigned int>(_depth + 1));
				}
			} else if (typeMatchFlag) {
				break;
			}
		}
		Directory::Delete(pDirectoryChild);
	}
found:
	if (_statFlag) {
		Object *pObj = pDirectoryChild->GetStatObj(sig);
		if (sig.IsSignalled()) return false;
		if (pObj != NULL) value = Value(pObj);
	} else {
		value = Value(env, pDirectoryChild->MakePathName(_addSepFlag).c_str());
	}
	Directory::Delete(pDirectoryChild);
	return true;
}

String Directory::Iterator_Glob::ToString(Signal sig) const
{
	return String("<iterator:path.glob>");
}

void Directory::Iterator_Glob::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

namespace DirBuilder {

//-----------------------------------------------------------------------------
// Record
//-----------------------------------------------------------------------------
Record::~Record()
{
	if (_pRecordChildren != NULL) {
		foreach (RecordList, ppRecordChild, *_pRecordChildren) {
			delete *ppRecordChild;
		}
	}
}

Record *Record::Find(const char *name)
{
	if (_pRecordChildren == NULL) return NULL;
	foreach (RecordList, ppRecordChild, *_pRecordChildren) {
		if (::strcmp((*ppRecordChild)->GetName(), name) == 0) {
			return *ppRecordChild;
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// Structure
//-----------------------------------------------------------------------------
Structure::Structure() : _cntRef(1), _pRecordRoot(NULL)
{
}

Structure::~Structure()
{
	delete _pRecordRoot;
}

Record *Structure::AddRecord(const char *pathName)
{
	const char *p = pathName;
	if (IsFileSeparator(*p)) p++;
	String field;
	Record *pRecord = NULL;
	Record *pRecordParent = GetRoot();
	for ( ; ; p++) {
		char ch = *p;
		if (!IsFileSeparator(ch) && ch != '\0') {
			field += ch;
			continue;
		}
		if (!field.empty()) {
			pRecord = pRecordParent->Find(field.c_str());
			if (pRecord == NULL) {
				bool containerFlag = IsFileSeparator(ch);
				pRecord = pRecordParent->GenerateChild(
										field.c_str(), containerFlag);
			}
			field.clear();
			pRecordParent = pRecord;
		}
		if (ch == '\0') break;
	}
	return pRecord;
}

Directory *Structure::GenerateDirectory(Signal sig, Directory *pParent,
				const char **pPathName, Directory::NotFoundMode notFoundMode)
{
	Directory *pDirectory = NULL;
	const char *p = *pPathName;
	if (IsFileSeparator(*p)) p++;
	String field;
	Record *pRecordParent = GetRoot();
	if (*p == '\0') {
		*pPathName = p;
		return pRecordParent->GenerateDirectory(pParent, true);
	}
	bool boundaryFlag = true;
	for ( ; ; p++) {
		char ch = *p;
		if (!IsFileSeparator(ch) && ch != '\0') {
			field += ch;
			continue;
		}
		Record *pRecord = NULL;
		if (field.empty()) {
			break;
		} else {
			pRecord = pRecordParent->Find(field.c_str());
			if (pRecord != NULL) {
				// nothing to do
			} else if (notFoundMode == Directory::NF_NoSignal) {
				pDirectory = NULL;
				break;
			} else {
				sig.SetError(ERR_IOError, "path not found");
				pDirectory = NULL;
				break;
			}
		}
		pDirectory = pRecord->GenerateDirectory(pParent, boundaryFlag);
		if (ch == '\0') break;
		boundaryFlag = false;
		pParent = pDirectory;
		pRecordParent = pRecord;
		field.clear();
	}
	*pPathName = p;
	return pDirectory;
}

}

}
