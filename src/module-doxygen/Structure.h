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
	ElemOwner _elemOwner;
public:
	Gura_DeclareReferenceAccessor(Structure);
public:
	Structure();
protected:
	inline ~Structure() {}
public:
	inline void AddElem(Elem *pElem) { _elemOwner.push_back(pElem); }
	inline const ElemOwner &GetElemOwner() const { return _elemOwner; }
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

Gura_EndModuleScope(doxygen)

#endif
