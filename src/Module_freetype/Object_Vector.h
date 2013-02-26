#ifndef __FREETYPE_OBJECT_VECTOR_H__
#define __FREETYPE_OBJECT_VECTOR_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Vector declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Vector);

class Object_Vector : public Object {
public:
	Gura_DeclareObjectAccessor(Vector)
private:
	FT_Vector _vector;
public:
	inline Object_Vector(const FT_Vector &vector) :
			Object(Gura_UserClass(Vector)), _vector(vector) {}
	inline Object_Vector(const Object_Vector &obj) :
			Object(obj), _vector(obj._vector) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Vector &GetEntity() { return _vector; }
	inline const FT_Vector &GetEntity() const { return _vector; }
};

}}

#endif
