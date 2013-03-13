#ifndef __FREETYPE_OBJECT_MATRIX_H__
#define __FREETYPE_OBJECT_MATRIX_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Matrix declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Matrix);

class Object_Matrix : public Object {
public:
	Gura_DeclareObjectAccessor(Matrix)
private:
	FT_Matrix _matrix;
public:
	inline Object_Matrix(const FT_Matrix &matrix) :
			Object(Gura_UserClass(Matrix)), _matrix(matrix) {}
	inline Object_Matrix(const Object_Matrix &obj) :
			Object(obj), _matrix(obj._matrix) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Matrix &GetEntity() { return _matrix; }
	inline const FT_Matrix &GetEntity() const { return _matrix; }
};

}}

#endif
