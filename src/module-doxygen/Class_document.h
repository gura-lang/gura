//=============================================================================
// Class_document.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CLASS_DOCUMENT_H__
#define __GURA_DOXYGEN_CLASS_DOCUMENT_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// doxygen.document class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(document);

class Object_document : public Object {
public:
	Gura_DeclareObjectAccessor(document)
private:
	AutoPtr<Elem> _pElem;
public:
	inline Object_document(Elem *pElem) : Object(Gura_UserClass(document)), _pElem(pElem) {}
	virtual ~Object_document();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Elem *GetElem() { return _pElem.get(); }
};

Gura_EndModuleScope(doxygen)

#endif
