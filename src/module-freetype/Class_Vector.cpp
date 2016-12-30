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

bool Object_Vector::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	return true;
}

Value Object_Vector::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_pVector->x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_pVector->y);
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_Vector::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_pVector->x = static_cast<FT_Pos>(value.GetLong());
		return Value(_pVector->x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Nil;
		_pVector->y = static_cast<FT_Pos>(value.GetLong());
		return Value(_pVector->y);
	}
	evaluatedFlag = false;
	return Value::Nil;
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
	return Value::Nil;
}

Gura_ImplementPropertySetter(Vector, x)
{
	return Value::Nil;
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
	return Value::Nil;
}

Gura_ImplementPropertySetter(Vector, y)
{
	return Value::Nil;
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
