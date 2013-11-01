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
	if (_pObjHolder.get() == NULL) delete _pVector;
}

Object *Object_Vector::Clone() const
{
	return NULL;
}

String Object_Vector::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<freetype.Vector:x=%d,y=%d>", _pVector->x, _pVector->y);
	return String(buff);
}

bool Object_Vector::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	return true;
}

Value Object_Vector::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(_pVector->x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(_pVector->y);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Vector::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_pVector->x = static_cast<FT_Pos>(value.GetLong());
		return Value(_pVector->x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		_pVector->y = static_cast<FT_Pos>(value.GetLong());
		return Value(_pVector->y);
	}
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for freetype.Vector
//-----------------------------------------------------------------------------
// freetype.Vector(x:number, y:number):map {block?}
Gura_DeclareFunction(Vector)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	SetClassToConstruct(Gura_UserClass(Vector));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Vector)
{
	FT_Vector vector;
	vector.x = static_cast<FT_Pos>(args.GetInt(0));
	vector.y = static_cast<FT_Pos>(args.GetInt(1));
	AutoPtr<Object_Vector> pObjRtn(new Object_Vector(vector));
	return ReturnValue(env, sig, args, Value(pObjRtn.release()));
}

// freetype.Vector#Length()
Gura_DeclareMethod(Vector, Length)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Vector, Length)
{
	FT_Vector *vec = Object_Vector::GetThisObj(args)->GetEntity();
	FT_Fixed rtn = ::FT_Vector_Length(vec);
	//return Value(static_cast<double>(rtn) / (1 << 16));
	return Value(rtn);
}

// freetype.Vector#Transform(matrix:freetype.Matrix):reduce
Gura_DeclareMethod(Vector, Transform)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_Matrix);
}

Gura_ImplementMethod(Vector, Transform)
{
	FT_Vector *vec = Object_Vector::GetThisObj(args)->GetEntity();
	FT_Matrix *matrix = Object_Matrix::GetObject(args, 0)->GetEntity();
	::FT_Vector_Transform(vec, matrix);	// void function
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Class implementation for freetype.Vector
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Vector)
{
	Gura_AssignFunction(Vector);
	Gura_AssignMethod(Vector, Length);
	Gura_AssignMethod(Vector, Transform);
}

Gura_EndModuleScope(freetype)
