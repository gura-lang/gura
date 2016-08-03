//=============================================================================
// Structure.h
//=============================================================================
#ifndef __GURA_DOXYGEN_STRUCTURE_H__
#define __GURA_DOXYGEN_STRUCTURE_H__

Gura_BeginModuleScope(doxygen)

class StructureOwner;

//-----------------------------------------------------------------------------
// Structure
//-----------------------------------------------------------------------------
class Structure {
protected:
	int _cntRef;
	bool _afterMemberFlag;
	AutoPtr<StructureOwner> _pStructureOwner;
	AutoPtr<ElemOwner> _pElemOwner;
public:
	Gura_DeclareReferenceAccessor(Structure);
public:
	Structure(bool afterMemberFlag);
protected:
	inline ~Structure() {}
public:
	inline bool GetAfterMemberFlag() const { return _afterMemberFlag; }
	inline StructureOwner &GetStructureOwner() { return *_pStructureOwner; }
	inline const StructureOwner &GetStructureOwner() const { return *_pStructureOwner; }
	inline ElemOwner &GetElemOwner() { return *_pElemOwner; }
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
