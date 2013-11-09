#ifndef __GURA_PATHMANAGER_H__
#define __GURA_PATHMANAGER_H__

#include "Common.h"
#include "String.h"
#include "Iterator.h"
#include "OAL.h"

namespace Gura {

class Directory;

//-----------------------------------------------------------------------------
// PathManager
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PathManager {
public:
	enum NotFoundMode {
		NF_Signal, NF_NoSignal, NF_Wouldbe,
	};
	typedef std::vector<PathManager *> List;
	typedef std::deque<Directory *> DirectoryDeque;
public:
	class GURA_DLLDECLARE Iterator_Walk : public Iterator {
	public:
	private:
		bool _addSepFlag;
		bool _statFlag;
		bool _ignoreCaseFlag;
		bool _fileFlag;
		bool _dirFlag;
		AutoPtr<Directory> _pDirectory;
		int _depthMax;
		StringList _patterns;
		DirectoryDeque _directoryQue;
	public:
		Iterator_Walk(bool addSepFlag, bool statFlag,
				bool ignoreCaseFlag, bool fileFlag, bool dirFlag,
				Directory *pDirectory, int depthMax, const StringList &patterns);
		~Iterator_Walk();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class GURA_DLLDECLARE Iterator_Glob : public Iterator {
	public:
		typedef std::deque<size_t> DepthDeque;
	private:
		bool _addSepFlag;
		bool _statFlag;
		bool _ignoreCaseFlag;
		bool _fileFlag;
		bool _dirFlag;
		AutoPtr<Directory> _pDirectory;
		size_t _depth;
		DepthDeque _depthQue;
		StringList _patternSegs;
		DirectoryDeque _directoryQue;
	public:
		Iterator_Glob(bool addSepFlag, bool statFlag,
							bool ignoreCaseFlag, bool fileFlag, bool dirFlag);
		~Iterator_Glob();
		bool Init(Environment &env, Signal sig, const char *pattern);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
protected:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(PathManager);
public:
	inline PathManager() : _cntRef(1) {}
	virtual bool IsResponsible(Environment &env, Signal sig,
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
	static void Register(Environment &env, PathManager *pPathManager);
	static PathManager *FindResponsible(Environment &env, Signal sig,
				const Directory *pParent, const char *pathName);
	static bool DoesExist(Environment &env, Signal sig, const char *pathName);
	static bool IsContainer(Environment &env, Signal sig, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env, Signal sig,
				Directory *pParent, const char **pPathName,
				PathManager::NotFoundMode notFoundMode) = 0;
};

}

#endif
