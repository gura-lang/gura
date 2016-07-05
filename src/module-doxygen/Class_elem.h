//=============================================================================
// Class_elem.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CLASS_ELEM_H__
#define __GURA_DOXYGEN_CLASS_ELEM_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// doxygen.elem class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(elem);

class Object_elem : public Object {
public:
	Gura_DeclareObjectAccessor(elem)
private:
	AutoPtr<Elem> _pElem;
public:
	inline Object_elem(Elem *pElem) : Object(Gura_UserClass(elem)), _pElem(pElem) {}
	virtual ~Object_elem();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Elem *GetElem() { return _pElem.get(); }
};

Gura_EndModuleScope(doxygen)

#endif
