//=============================================================================
// PathManager
//=============================================================================
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
	AutoPtr<Directory> pDirectory(Directory::Open(env, sig, pathName, NF_NoSignal));
	return !pDirectory.IsNull();
}

bool PathManager::IsContainer(Environment &env, Signal sig, const char *pathName)
{
	if (*pathName == '\0') return false;
	AutoPtr<Directory> pDirectory(Directory::Open(env, sig, pathName, NF_NoSignal));
	return !pDirectory.IsNull() && pDirectory->IsContainer();
}

}
