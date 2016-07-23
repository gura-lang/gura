//=============================================================================
// Structure.h
//=============================================================================
#ifndef __GURA_DOXYGEN_STRUCTURE_H__
#define __GURA_DOXYGEN_STRUCTURE_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Structure
//-----------------------------------------------------------------------------
class Structure {
protected:
	int _cntRef;
	bool _refAheadFlag;
	AutoPtr<ElemOwner> _pElemOwner;
public:
	Gura_DeclareReferenceAccessor(Structure);
public:
	Structure(bool refAheadFlag);
protected:
	inline ~Structure() {}
public:
	inline bool GetRefAheadFlag() const { return _refAheadFlag; }
	inline const ElemOwner &GetElemOwner() const { return *_pElemOwner; }
};

//-----------------------------------------------------------------------------
// StructureList
//-----------------------------------------------------------------------------
class StructureList : public std::vector<Structure *> {
};

//-----------------------------------------------------------------------------
// StructureOwner
//-----------------------------------------------------------------------------
class StructureOwner : public StructureList {
protected:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(StructureOwner);
public:
	StructureOwner();
protected:
	~StructureOwner();
public:
	void Clear();
};

//-----------------------------------------------------------------------------
// Iterator_Structure
//-----------------------------------------------------------------------------
class Iterator_Structure : public Iterator {
protected:
	AutoPtr<StructureOwner> _pStructureOwner;
	size_t _idx;
public:
	Iterator_Structure(StructureOwner *pStructureOwner);
	Iterator_Structure(const Iterator_Structure &iter);
	virtual Iterator *Clone() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleScope(doxygen)

#endif
