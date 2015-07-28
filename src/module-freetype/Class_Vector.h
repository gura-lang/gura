#ifndef __FREETYPE_CLASS_VECTOR_H__
#define __FREETYPE_CLASS_VECTOR_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Vector declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Vector);

class Object_Vector : public Object {
public:
	Gura_DeclareObjectAccessor(Vector)
private:
	AutoPtr<Object> _pObjHolder;
	FT_Vector *_pVector;
public:
	Object_Vector(const FT_Vector &vector);
	Object_Vector(Object *pObjHolder, FT_Vector *pVector);
	~Object_Vector();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Vector *GetEntity() { return _pVector; }
	inline const FT_Vector *GetEntity() const { return _pVector; }
};

Gura_EndModuleScope(freetype)

#endif
