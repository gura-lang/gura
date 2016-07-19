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
public:
	Gura_DeclareReferenceAccessor(Structure);
public:
	Structure();
protected:
	inline ~Structure() {}
};

Gura_EndModuleScope(doxygen)

#endif
