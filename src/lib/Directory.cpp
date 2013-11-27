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
			size_t len = str.size();
			if (len == 0 || !IsFileSeparator(str[len - 1])) {
				str += pDirectory->GetSeparator();
			}
			str += pathName;
			pathName = str;
		}
	}
	if (pathNameTrail != NULL) {
		size_t len = pathName.size();
		if (len == 0 || !IsFileSeparator(pathName[len - 1])) {
			pathName += GetSeparator();
		}
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

Directory *Directory::Open(Environment &env, Signal sig,
				const char *pathName, PathManager::NotFoundMode notFoundMode)
{
	return Open(env, sig, NULL, &pathName, notFoundMode);
}

Directory *Directory::Open(Environment &env, Signal sig, Directory *pParent,
				const char **pPathName, PathManager::NotFoundMode notFoundMode)
{
	Directory *pDirectory = pParent;
	do {
		PathManager *pPathManager =
				PathManager::FindResponsible(env, sig, pDirectory, *pPathName);
		if (sig.IsSignalled()) return NULL;
		if (pPathManager == NULL) {
			sig.SetError(ERR_ValueError, "unsupported directory name");
			return NULL;
		}
		pDirectory = pPathManager->DoOpenDirectory(env, sig,
									pDirectory, pPathName, notFoundMode);
		if (sig.IsSignalled() || pDirectory == NULL) return NULL;
	} while (**pPathName != '\0');
	return pDirectory;
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
				if (PathManager::DoesMatchName(pPattern->c_str(),
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
					value = Value(pDirectoryChild->MakePathName(_addSepFlag));
				}
				Directory::Delete(pDirectoryChild);
				break;
			}
		}
		Directory::Delete(pDirectoryChild);
	}
	return true;
}

String Directory::Iterator_Walk::ToString() const
{
	String str;
	str = "path.walk(";
	str += _statFlag? ":stat" : ":name";
	str += ")";
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
		} else if (PathManager::IsWildCardChar(ch)) {
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
	AutoPtr<Directory> pDirectory(Directory::Open(env, sig,
									pathName.c_str(), PathManager::NF_Signal));
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
		if (PathManager::DoesMatchName(_patternSegs[_depth].c_str(),
								pDirectoryChild->GetName(), _ignoreCaseFlag)) {
			bool typeMatchFlag =
					(pDirectoryChild->IsContainer() && _dirFlag) ||
					(!pDirectoryChild->IsContainer() && _fileFlag);
			if (_depth + 1 < _patternSegs.size()) {
				if (pDirectoryChild->IsContainer()) {
					_directoryQue.push_back(Directory::Reference(pDirectoryChild));
					_depthQue.push_back(static_cast<UInt>(_depth + 1));
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
		value = Value(pDirectoryChild->MakePathName(_addSepFlag));
	}
	Directory::Delete(pDirectoryChild);
	return true;
}

String Directory::Iterator_Glob::ToString() const
{
	return String("path.glob");
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
				const char **pPathName, PathManager::NotFoundMode notFoundMode)
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
			} else if (notFoundMode == PathManager::NF_NoSignal) {
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
