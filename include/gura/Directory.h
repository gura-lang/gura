//=============================================================================
// Directory
//=============================================================================
#ifndef __GURA_DIRECTORY_H__
#define __GURA_DIRECTORY_H__

#include "PathMgr.h"

namespace Gura {

class Environment;
class Object;
class Stream;
class Directory;

//-----------------------------------------------------------------------------
// DirectoryDeque
//-----------------------------------------------------------------------------
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
		virtual bool DoNext(Environment &env, Signal &sig, Value &value);
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
		bool Init(Environment &env, Signal &sig, const char *pattern);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal &sig, Value &value);
		virtual String ToString() const;
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
	inline bool DoesMatchName(const char *pattern, bool ignoreCaseFlag) const {
		return PathMgr::DoesMatchName(pattern, GetName(), ignoreCaseFlag);
	}
	Directory *Next(Environment &env, Signal &sig);
	inline Object *GetStatObj(Signal &sig) { return DoGetStatObj(sig); }
	String MakePathName(bool addSepFlag, const char *pathNameTrail = nullptr) const;
	int CountDepth() const;
	virtual Stream *DoOpenStream(Environment &env, Signal &sig, ULong attr) = 0;
public:
	static Directory *Open(Environment &env, Signal &sig,
					const char *pathName, PathMgr::NotFoundMode notFoundMode);
	static Directory *Open(Environment &env, Signal &sig, Directory *pParent,
					const char **pPathName, PathMgr::NotFoundMode notFoundMode);
protected:
	virtual Directory *DoNext(Environment &env, Signal &sig) = 0;
	virtual Object *DoGetStatObj(Signal &sig);
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
			_pStructure(pStructure), _pRecordParent(pRecordParent),
			_pRecordChildren(containerFlag? new RecordList() : nullptr), _name(name) {}
	virtual ~Record();
	inline const char *GetName() const { return _name.c_str(); }
	inline bool IsRoot() const { return _pRecordParent == nullptr; }
	inline bool IsContainer() const { return _pRecordChildren != nullptr; }
	inline void AddChild(Record *pRecord) {
		if (_pRecordChildren != nullptr) _pRecordChildren->push_back(pRecord);
	}
	inline void InitIterator() {
		if (_pRecordChildren != nullptr) _ppRecordChild = _pRecordChildren->begin();
	}
	inline Directory *Next(Directory *pParent) {
		if (_pRecordChildren == nullptr) return nullptr;
		if (_ppRecordChild == _pRecordChildren->end()) return nullptr;
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
	Directory *GenerateDirectory(Signal &sig, Directory *pParent,
				const char **pPathName, PathMgr::NotFoundMode notFoundMode);
};

}

}

#endif
