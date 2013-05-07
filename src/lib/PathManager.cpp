#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// PathManager
//-----------------------------------------------------------------------------
void PathManager::Register(Environment &env, PathManager *pPathManager)
{
	PathManagerOwner &pathManagerOwner = env.GetGlobal()->GetPathManagerOwner();
	pathManagerOwner.push_back(pPathManager);
}

void PathManager::SplitFileName(const char *pathName, String *pDirName, String *pFileName)
{
	const char *p = pathName + ::strlen(pathName);
	for ( ; p > pathName; p--) {
		if (IsFileSeparator(*(p - 1))) break;
	}
	if (pDirName != NULL) *pDirName = String(pathName, p);
	if (pFileName != NULL) *pFileName = String(p);
}

void PathManager::SplitBottom(const char *pathName, String *pTop, String *pBottom)
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

const char *PathManager::SeekExtName(const char *pathName)
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

bool PathManager::HasWildCard(const char *pathName)
{
	for (const char *p = pathName; *p != '\0'; p++) {
		if (IsWildCardChar(*p)) return true;
	}
	return false;
}

bool PathManager::DoesMatchName(const char *pattern, const char *fileName, bool ignoreCaseFlag)
{
	if (*pattern == '!') {
		return !DoesMatchNameSub(pattern + 1, fileName, ignoreCaseFlag);
	}
	return DoesMatchNameSub(pattern, fileName, ignoreCaseFlag);
}
	
bool PathManager::DoesMatchNameSub(const char *pattern, const char *fileName, bool ignoreCaseFlag)
{
	if (*pattern == '\0') {
		return *fileName == '\0';
	} else if (*pattern == '*') {
		return DoesMatchNameSub(pattern + 1, fileName, ignoreCaseFlag) ||
			*fileName != '\0' && DoesMatchNameSub(pattern, fileName + 1, ignoreCaseFlag);
	} else if (*pattern == '?') {
		return *fileName != '\0' && DoesMatchNameSub(pattern + 1, fileName + 1, ignoreCaseFlag);
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
		return DoesMatchNameSub(pattern, fileName + 1, ignoreCaseFlag);
	} else {
		return CompareChar(*pattern, *fileName, ignoreCaseFlag) == 0 &&
						DoesMatchNameSub(pattern + 1, fileName + 1, ignoreCaseFlag);
	}
}

Directory *PathManager::OpenDirectory(Environment &env, Signal sig,
							const char *pathName, NotFoundMode notFoundMode)
{
	return OpenDirectory(env, sig, NULL, &pathName, notFoundMode);
}

Directory *PathManager::OpenDirectory(Environment &env, Signal sig,
		Directory *pParent, const char **pPathName, NotFoundMode notFoundMode)
{
	Directory *pDirectory = pParent;
	do {
		PathManager *pPathManager =
						FindResponsible(env, sig, pDirectory, *pPathName);
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

Stream *PathManager::OpenStream(Environment &env, Signal sig,
								const char *pathName, unsigned long attr)
{
	if (*pathName == '>') {
		pathName++;
		attr = (attr & ~Stream::ATTR_Readable) | Stream::ATTR_Writable;
		if (*pathName == '>') {
			pathName++;
			attr |= Stream::ATTR_Append;
		}
	}
	NotFoundMode notFoundMode = (attr & Stream::ATTR_Writable)?
									NF_Wouldbe : NF_Signal;
	AutoPtr<Directory> pDirectory(OpenDirectory(env, sig, pathName, notFoundMode));
	if (sig.IsSignalled()) return NULL;
	return pDirectory->DoOpenStream(env, sig, attr);
}

PathManager *PathManager::FindResponsible(Environment &env, Signal sig,
								const Directory *pParent, const char *pathName)
{
	PathManagerOwner &pathManagerOwner = env.GetGlobal()->GetPathManagerOwner();
	// The last-registered PathManager is searched first.
	foreach_reverse (PathManagerOwner, ppPathManager, pathManagerOwner) {
		PathManager *pPathManager = *ppPathManager;
		if (pPathManager->IsResponsible(env, sig, pParent, pathName)) {
			return pPathManager;
		}
		if (sig.IsSignalled()) break;
	}
	return NULL;
}

bool PathManager::DoesExist(Environment &env, Signal sig, const char *pathName)
{
	if (*pathName == '\0') return false;
	AutoPtr<Directory> pDirectory(OpenDirectory(env, sig, pathName, NF_NoSignal));
	return !pDirectory.IsNull();
}

bool PathManager::IsContainer(Environment &env, Signal sig, const char *pathName)
{
	if (*pathName == '\0') return false;
	AutoPtr<Directory> pDirectory(OpenDirectory(env, sig, pathName, NF_NoSignal));
	return !pDirectory.IsNull() && pDirectory->IsContainer();
}

//-----------------------------------------------------------------------------
// PathManager::Iterator_Walk
//-----------------------------------------------------------------------------
PathManager::Iterator_Walk::Iterator_Walk(bool addSepFlag, bool statFlag,
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

PathManager::Iterator_Walk::~Iterator_Walk()
{
	foreach (DirectoryDeque, ppDirectory, _directoryQue) {
		Directory::Delete(*ppDirectory);
	}
}

Iterator *PathManager::Iterator_Walk::GetSource()
{
	return NULL;
}

bool PathManager::Iterator_Walk::DoNext(Environment &env, Signal sig, Value &value)
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
				if (DoesMatchName(pPattern->c_str(),
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

String PathManager::Iterator_Walk::ToString(Signal sig) const
{
	String str;
	str = "<iterator:path.walk";
	str += _statFlag? ":stat" : ":name";
	str += ">";
	return str;
}

void PathManager::Iterator_Walk::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// PathManager::Iterator_Glob
//-----------------------------------------------------------------------------
PathManager::Iterator_Glob::Iterator_Glob(bool addSepFlag, bool statFlag,
							bool ignoreCaseFlag, bool fileFlag, bool dirFlag) :
	Iterator(false),
	_addSepFlag(addSepFlag), _statFlag(statFlag), _ignoreCaseFlag(ignoreCaseFlag),
	_fileFlag(fileFlag), _dirFlag(dirFlag), _pDirectory(NULL), _depth(0)
{
}

bool PathManager::Iterator_Glob::Init(Environment &env, Signal sig, const char *pattern)
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
		} else if (IsWildCardChar(ch)) {
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
	AutoPtr<Directory> pDirectory(PathManager::OpenDirectory(env, sig,
									pathName.c_str(), PathManager::NF_Signal));
	if (sig.IsSignalled()) return false;
	_directoryQue.push_back(pDirectory.release());
	_depthQue.push_back(0);
	return true;
}

PathManager::Iterator_Glob::~Iterator_Glob()
{
	foreach (DirectoryDeque, ppDirectory, _directoryQue) {
		Directory::Delete(*ppDirectory);
	}
}

Iterator *PathManager::Iterator_Glob::GetSource()
{
	return NULL;
}

bool PathManager::Iterator_Glob::DoNext(Environment &env, Signal sig, Value &value)
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
		if (DoesMatchName(_patternSegs[_depth].c_str(),
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

String PathManager::Iterator_Glob::ToString(Signal sig) const
{
	return String("<iterator:path.glob>");
}

void PathManager::Iterator_Glob::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
