#ifndef __FREETYPE_CLASS_MATRIX_H__
#define __FREETYPE_CLASS_MATRIX_H__

Gura_BeginModuleScope(freetype)

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
	inline Object_Matrix() : Object(Gura_UserClass(Matrix)) {
		_matrix.xx = _matrix.xy = _matrix.yx = _matrix.yy = 0;
	}
	inline Object_Matrix(const FT_Matrix &matrix) :
			Object(Gura_UserClass(Matrix)), _matrix(matrix) {}
	inline Object_Matrix(const Object_Matrix &obj) :
			Object(obj), _matrix(obj._matrix) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FT_Matrix *GetEntity() { return &_matrix; }
	inline const FT_Matrix *GetEntity() const { return &_matrix; }
	bool ConvertFrom(Signal &sig, const ArrayT<Double> *pArrayT);
};

Gura_EndModuleScope(freetype)

#endif
