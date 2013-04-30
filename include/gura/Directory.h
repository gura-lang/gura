#ifndef __GURA_DIRECTORY_H__
#define __GURA_DIRECTORY_H__

#include "PathManager.h"

namespace Gura {

class Environment;
class Object;
class Stream;

//-----------------------------------------------------------------------------
// Directory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Directory {
public:
	enum Type {
		TYPE_None, TYPE_Item, TYPE_Container,
		TYPE_BoundaryContainer, TYPE_RootContainer,
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
		return PathManager::DoesMatchName(pattern, GetName(), ignoreCaseFlag);
	}
	Directory *Next(Environment &env, Signal sig);
	inline Object *GetStatObj(Signal sig) { return DoGetStatObj(sig); }
	String MakePathName(bool addSepFlag, const char *pathNameTrail = NULL) const;
	int CountDepth() const;
	virtual Stream *DoOpenStream(Environment &env, Signal sig, unsigned long attr) = 0;
protected:
	virtual Directory *DoNext(Environment &env, Signal sig) = 0;
	virtual Object *DoGetStatObj(Signal sig);
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
				const char **pPathName, PathManager::NotFoundMode notFoundMode);
};

}

}

#endif
