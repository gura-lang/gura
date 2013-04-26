#ifndef __GURA_DIRECTORY_H__
#define __GURA_DIRECTORY_H__

#include "Common.h"
#include "String.h"
#include "Iterator.h"
#include "OAL.h"

namespace Gura {

class Environment;
class Directory;
class PathManager;
class Object;
class Stream;

typedef std::deque<Directory *> DirectoryDeque;

//-----------------------------------------------------------------------------
// Directory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Directory {
public:
	enum Type {
		TYPE_None, TYPE_Item, TYPE_Container,
		TYPE_BoundaryContainer, TYPE_RootContainer,
	};
	enum NotFoundMode {
		NF_Signal, NF_NoSignal, NF_Wouldbe,
	};
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
		virtual String ToString(Signal sig) const;
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
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
protected:
	int _cntRef;
	Directory *_pParent;
	String _name;
	Type _type;
	char _chSeparator;
public:
	Gura_DeclareReferenceAccessor(Directory);
protected:
	virtual ~Directory();
public:
	Directory(Directory *pParent, const char *name, Type type, char chSeparator);
	Directory(const Directory &directory);
	inline const char *GetName() const { return _name.c_str(); }
	inline Directory *GetParent() const { return _pParent; }
	inline char GetSeparator() const { return _chSeparator; }
	inline bool IsBoundaryContainer() const {
		return _type == TYPE_BoundaryContainer;
	}
	inline bool IsRootContainer() const {
		return _type == TYPE_RootContainer;
	}
	inline bool IsContainer() const {
		return _type == TYPE_Container ||
			_type == TYPE_BoundaryContainer || _type == TYPE_RootContainer;
	}
	inline bool IsMatchName(const char *pattern, bool ignoreCaseFlag) const {
		return IsMatchName(pattern, GetName(), ignoreCaseFlag);
	}
	Stream *OpenStream(Environment &env, Signal sig, unsigned long attr);
	Directory *Next(Environment &env, Signal sig);
	inline Object *GetStatObj(Signal sig) { return DoGetStatObj(sig); }
	String MakePathName(bool addSepFlag, const char *pathNameTrail = NULL) const;
	int CountDepth() const;
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
	static bool IsMatchName(const char *pattern,
							const char *fileName, bool ignoreCaseFlag);
	static bool IsMatchNameSub(const char *pattern,
							const char *fileName, bool ignoreCaseFlag);
	static bool IsExist(Environment &env, Signal sig, const char *pathName);
	static bool IsContainer(Environment &env, Signal sig, const char *pathName);
	static Directory *OpenDirectory(Environment &env, Signal sig,
							const char *pathName, NotFoundMode notFoundMode);
	static Stream *OpenStream(Environment &env, Signal sig,
							const char *pathName, unsigned long attr);
protected:
	virtual Stream *DoOpenStream(Environment &env, Signal sig, unsigned long attr) = 0;
	virtual Directory *DoNext(Environment &env, Signal sig) = 0;
	virtual Object *DoGetStatObj(Signal sig);
};

//-----------------------------------------------------------------------------
// PathManager
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE PathManager {
public:
	typedef std::vector<PathManager *> List;
protected:
	int _cntRef;
private:
	static List *_pList;
public:
	Gura_DeclareReferenceAccessor(PathManager);
public:
	inline PathManager() : _cntRef(1) {}
	virtual bool IsResponsible(Environment &env, Signal sig,
								const Directory *pParent, const char *pathName) = 0;
public:
	static void Register(PathManager *pPathManager);
	static Directory *OpenDirectory(Environment &env, Signal sig,
				Directory *pParent, const char **pPathName, Directory::NotFoundMode notFoundMode);
	static PathManager *FindResponsible(Environment &env, Signal sig,
				const Directory *pParent, const char *pathName);
	virtual Directory *DoOpenDirectory(Environment &env, Signal sig,
				Directory *pParent, const char **pPathName,
				Directory::NotFoundMode notFoundMode) = 0;
};

namespace DirBuilder {

//-----------------------------------------------------------------------------
// Record
//-----------------------------------------------------------------------------
class Structure;
class Record;

typedef std::vector<Record *> RecordList;

class GURA_DLLDECLARE Record {
protected:
	Structure *_pStructure;
	Record *_pRecordParent;
	RecordList *_pRecordChildren;
	RecordList::iterator _ppRecordChild;
	String _name;
public:
	inline Record(Structure *pStructure, Record *pRecordParent,
			const char *name, bool containerFlag) :
			_pStructure(pStructure), _pRecordParent(pRecordParent), _name(name),
			_pRecordChildren(containerFlag? new RecordList() : NULL) {}
	virtual ~Record();
	inline const char *GetName() const { return _name.c_str(); }
	inline bool IsRoot() const { return _pRecordParent == NULL; }
	inline bool IsContainer() const { return _pRecordChildren != NULL; }
	inline void AddChild(Record *pRecord) {
		if (_pRecordChildren != NULL) _pRecordChildren->push_back(pRecord);
	}
	inline void InitIterator() {
		if (_pRecordChildren != NULL) _ppRecordChild = _pRecordChildren->begin();
	}
	inline Directory *Next(Directory *pParent) {
		if (_pRecordChildren == NULL) return NULL;
		if (_ppRecordChild == _pRecordChildren->end()) return NULL;
		Record *pRecord = *_ppRecordChild++;
		return pRecord->GenerateDirectory(pParent, false);
	}
	Record *Find(const char *name);
	inline Record *GenerateChild(const char *name, bool containerFlag) {
		return DoGenerateChild(name, containerFlag);
	}
	inline Directory *GenerateDirectory(Directory *pParent, bool boundaryFlag) {
		if (IsContainer()) InitIterator();
		Directory::Type type =
			boundaryFlag? Directory::TYPE_BoundaryContainer :
			IsContainer()? Directory::TYPE_Container : Directory::TYPE_Item;
		return DoGenerateDirectory(pParent, type);
	}
	virtual Record *DoGenerateChild(const char *name, bool containerFlag) = 0;
	virtual Directory *DoGenerateDirectory(Directory *pParent, Directory::Type type) = 0;
};

//-----------------------------------------------------------------------------
// Structure
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Structure {
private:
	int _cntRef;
	Record *_pRecordRoot;
public:
	Gura_DeclareReferenceAccessor(Structure);
private:
	~Structure();
public:
	Structure();
	inline void SetRoot(Record *pRecordRoot) { _pRecordRoot = pRecordRoot; }
	inline Record *GetRoot() { return _pRecordRoot; }
	Record *AddRecord(const char *pathName);
	Directory *GenerateDirectory(Signal sig, Directory *pParent,
				const char **pPathName, Directory::NotFoundMode notFoundMode);
};

}

}

#endif
