#include "stdafx.h"

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Vector implementation
//-----------------------------------------------------------------------------
Object_Vector::Object_Vector(const FT_Vector &vector) :
			Object(Gura_UserClass(Vector)), _pVector(new FT_Vector(vector))
{
}

Object_Vector::Object_Vector(Object *pObjHolder, FT_Vector *pVector) :
		Object(Gura_UserClass(Vector)), _pObjHolder(pObjHolder), _pVector(pVector)
{
}

Object_Vector::~Object_Vector()
{
	if (_pObjHolder.get() == nullptr) delete _pVector;
}

Object *Object_Vector::Clone() const
{
	return nullptr;
}

String Object_Vector::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Vector:x=%d,y=%d>", _pVector->x, _pVector->y);
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// freetype.Vector#x
Gura_DeclareProperty_RW(Vector, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Vector, x)
{
	const FT_Vector *pVector = Object_Vector::GetObject(valueThis)->GetEntity();
	return Value(pVector->x);
}

Gura_ImplementPropertySetter(Vector, x)
{
	FT_Vector *pVector = Object_Vector::GetObject(valueThis)->GetEntity();
	pVector->x = static_cast<FT_Pos>(value.GetLong());
	return Value(pVector->x);
}

// freetype.Vector#y
Gura_DeclareProperty_RW(Vector, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Vector, y)
{
	const FT_Vector *pVector = Object_Vector::GetObject(valueThis)->GetEntity();
	return Value(pVector->y);
}

Gura_ImplementPropertySetter(Vector, y)
{
	FT_Vector *pVector = Object_Vector::GetObject(valueThis)->GetEntity();
	pVector->y = static_cast<FT_Pos>(value.GetLong());
	return Value(pVector->y);
}

//-----------------------------------------------------------------------------
// Gura interfaces for freetype.Vector
//-----------------------------------------------------------------------------
// freetype.Vector(x:number, y:number):map {block?}
Gura_DeclareFunction(Vector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	SetClassToConstruct(Gura_UserClass(Vector));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Vector)
{
	FT_Vector vector;
	vector.x = static_cast<FT_Pos>(arg.GetInt(0));
	vector.y = static_cast<FT_Pos>(arg.GetInt(1));
	AutoPtr<Object_Vector> pObjRtn(new Object_Vector(vector));
	return ReturnValue(env, arg, Value(pObjRtn.release()));
}

// freetype.Vector#Length()
Gura_DeclareMethod(Vector, Length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Vector, Length)
{
	FT_Vector *vec = Object_Vector::GetObjectThis(arg)->GetEntity();
	FT_Fixed rtn = ::FT_Vector_Length(vec);
	//return Value(static_cast<double>(rtn) / (1 << 16));
	return Value(rtn);
}

// freetype.Vector#Transform(matrix:freetype.Matrix):reduce
Gura_DeclareMethod(Vector, Transform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_Matrix);
}

Gura_ImplementMethod(Vector, Transform)
{
	FT_Vector *vec = Object_Vector::GetObjectThis(arg)->GetEntity();
	FT_Matrix *matrix = Object_Matrix::GetObject(arg, 0)->GetEntity();
	::FT_Vector_Transform(vec, matrix);	// void function
	return arg.GetValueThis();
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Vector
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Vector)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(Vector, x);
	Gura_AssignProperty(Vector, y);
#endif
	Gura_AssignFunction(Vector);
	Gura_AssignMethod(Vector, Length);
	Gura_AssignMethod(Vector, Transform);
}

Gura_EndModuleScope(freetype)
