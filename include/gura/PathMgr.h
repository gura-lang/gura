//=============================================================================
// PathMgr
//=============================================================================
#ifndef __GURA_PATHMGR_H__
#define __GURA_PATHMGR_H__

#include "Common.h"

namespace Gura {

class Directory;
class Environment;

//-----------------------------------------------------------------------------
// PathMgr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PathMgr {
public:
	enum NotFoundMode {
		NF_Signal, NF_NoSignal, NF_Wouldbe,
	};
	typedef std::vector<PathMgr *> List;
protected:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(PathMgr);
public:
	inline PathMgr() : _cntRef(1) {}
	virtual ~PathMgr();
	virtual bool IsResponsible(Environment &env,
								const Directory *pParent, const char *pathName) = 0;
public:
	inline static bool IsWildCardChar(char ch) {
		return ch == '*' || ch == '?' || ch == '[' || ch == ']';
	}
	static void SplitFileName(const char *pathName, String *pDirName, String *pFileName);
	static void SplitBottom(const char *pathName, String *pTop, String *pBottom);
	static const char *SeekExtName(const char *pathName);
	static bool HasWildCard(const char *pathName);
	static String GetExecutable();
	static const String &GetBaseDir();
	static bool DoesMatchName(const char *pattern,
							const char *fileName, bool ignoreCaseFlag);
	static bool DoesMatchNameSub(const char *pattern,
							const char *fileName, bool ignoreCaseFlag);
public:
	static void Register(Environment &env, PathMgr *pPathMgr);
	static PathMgr *FindResponsible(Environment &env,
				const Directory *pParent, const char *pathName);
	static bool DoesExist(Environment &env, const char *pathName);
	static bool IsContainer(Environment &env, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env,
				Directory *pParent, const char **pPathName,
				PathMgr::NotFoundMode notFoundMode) = 0;
};

//-----------------------------------------------------------------------------
// PathMgrOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PathMgrOwner : public std::vector<PathMgr *> {
public:
	~PathMgrOwner();
	void Clear();
};

}

#endif
