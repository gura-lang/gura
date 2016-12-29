//=============================================================================
// Class_structure.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CLASS_STRUCTURE_H__
#define __GURA_DOXYGEN_CLASS_STRUCTURE_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// doxygen.structure class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(structure);

class Object_structure : public Object {
public:
	Gura_DeclareObjectAccessor(structure)
private:
	AutoPtr<Structure> _pStructure;
public:
	inline Object_structure(Structure *pStructure = nullptr) :
					Object(Gura_UserClass(structure)), _pStructure(pStructure) {}
	virtual ~Object_structure();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Structure *GetStructure() { return _pStructure.get(); }
};

Gura_EndModuleScope(doxygen)

#endif
