#ifndef __GURA_DIRECTORY_H__
#define __GURA_DIRECTORY_H__

#include "Common.h"
#include "String.h"
#include "Iterator.h"
#include "OAL.h"

namespace Gura {

class Environment;
class Directory;
class DirectoryFactory;
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
protected:
	virtual ~Directory();
public:
	Directory(Directory *pParent, const char *name, Type type, char chSeparator);
	Directory(const Directory &directory);
	virtual int IncRef();
	virtual int DecRef();
	inline static Directory *Reference(const Directory *pDirectory) {
		if (pDirectory == NULL) return NULL;
		Directory *pDirectoryCasted = const_cast<Directory *>(pDirectory);
		pDirectoryCasted->IncRef();
		return pDirectoryCasted;
	}
	inline static void Delete(Directory *pDirectory) {
		if (pDirectory != NULL && pDirectory->DecRef() <= 0) {
			Delete(pDirectory->GetParent());
			delete pDirectory;
		}
	}
	inline static void DeleteChild(Directory *pDirectory) {
		if (pDirectory != NULL && pDirectory->DecRef() <= 0) {
			delete pDirectory;
		}
	}
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
	Stream *OpenStream(Environment &env, Signal sig,
							unsigned long attr, const char *encoding);
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
	static Stream *OpenStream(Environment &env, Signal sig, const char *pathName,
							unsigned long attr, const char *encoding);
protected:
	virtual Stream *DoOpenStream(Environment &env, Signal sig,
							unsigned long attr, const char *encoding) = 0;
	virtual Directory *DoNext(Environment &env, Signal sig) = 0;
	virtual Object *DoGetStatObj(Signal sig);
};

//-----------------------------------------------------------------------------
// DirectoryFactory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE DirectoryFactory {
public:
	typedef std::vector<DirectoryFactory *> List;
protected:
	int _cntRef;
private:
	static List *_pList;
public:
	inline DirectoryFactory() : _cntRef(1) {}
	inline int DecRef() { if (_cntRef > 0) _cntRef--; return _cntRef; }
	inline static DirectoryFactory *Reference(const DirectoryFactory *pFactory) {
		if (pFactory == NULL) return NULL;
		DirectoryFactory *pFactoryCasted = const_cast<DirectoryFactory *>(pFactory);
		pFactoryCasted->_cntRef++;
		return pFactoryCasted;
	}
	inline static void Delete(DirectoryFactory *pFactory) {
		if (pFactory != NULL && pFactory->DecRef() <= 0) delete pFactory;
	}
	virtual bool IsResponsible(Environment &env, Signal sig,
								const Directory *pParent, const char *pathName) = 0;
public:
	static void Register(DirectoryFactory *pDirectoryFactory);
	static Directory *OpenDirectory(Environment &env, Signal sig,
				Directory *pParent, const char **pPathName, Directory::NotFoundMode notFoundMode);
	static DirectoryFactory *FindResponsible(Environment &env, Signal sig,
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
	inline static Structure *Reference(const Structure *pStructure) {
		if (pStructure == NULL) return NULL;
		Structure *pStructureCasted = const_cast<Structure *>(pStructure);
		pStructureCasted->_cntRef++;
		return pStructureCasted;
	}
	inline static void Delete(Structure *pStructure) {
		if (pStructure == NULL) return;
		pStructure->_cntRef--;
		if (pStructure->_cntRef <= 0) delete pStructure;
	}
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
