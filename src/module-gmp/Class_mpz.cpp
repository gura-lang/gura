//=============================================================================
// Gura class: gmp.mpz
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpz
//-----------------------------------------------------------------------------
Object_mpz::Object_mpz(mpz_t num) : Object(Gura_UserClass(mpz)), _num(num)
{
}

Object_mpz::Object_mpz(const mpz_class &num) : Object(Gura_UserClass(mpz)), _num(num)
{
}

bool Object_mpz::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_mpz::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

String Object_mpz::ToString(bool exprFlag)
{
	String str = _num.get_str();
	str += "L";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpz(value?) {block?}
Gura_DeclareFunction(mpz)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpz));
}

Gura_ImplementFunction(mpz)
{
	mpz_t num;
	::mpz_init(num);
	if (args.IsInvalid(0)) {
		// nothing to do
	} else if (args.Is_number(0)) {
		::mpz_set_d(num, args.GetDouble(0));
	} else if (args.Is_string(0)) {
		if (::mpz_set_str(num, args.GetString(0), 0) < 0) {
			::mpz_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpz");
			return Value::Null;
		}
	} else {
		::mpz_clear(num);
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpz(num)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// string#mpz(base?:number):map {block?}
Gura_DeclareMethod(string, mpz)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, mpz)
{
	const char *strThis = args.GetThis().GetString();
	int base = args.Is_number(0)? args.GetInt(0) : 0;
	mpz_t num;
	::mpz_init(num);
	if (::mpz_set_str(num, strThis, base) < 0) {
		::mpz_clear(num);
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpz");
		return false;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpz(num)));
}

//-----------------------------------------------------------------------------
// Implementation of operators
//-----------------------------------------------------------------------------
// unary operator +
Gura_ImplementUnaryOperator(Pos, mpz)
{
	mpz_class num = Object_mpz::GetEntity(value);
	mpz_class numResult = +num;
	return Value(new Object_mpz(numResult));
}

// unary operator -
Gura_ImplementUnaryOperator(Neg, mpz)
{
	mpz_class num = Object_mpz::GetEntity(value);
	mpz_class numResult = -num;
	return Value(new Object_mpz(numResult));
}

// unary operator ~
Gura_ImplementUnaryOperator(Inv, mpz)
{
	mpz_class num = Object_mpz::GetEntity(value);
	mpz_class numResult = ~num;
	return Value(new Object_mpz(numResult));
}

// binary operator +
Gura_ImplementBinaryOperator(Add, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft + numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Add, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft + numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Add, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft + numRight;
	return Value(new Object_mpz(numResult));
}

// binary operator -
Gura_ImplementBinaryOperator(Sub, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft - numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft - numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Sub, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft - numRight;
	return Value(new Object_mpz(numResult));
}

// binary operator *
Gura_ImplementBinaryOperator(Mul, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft * numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft * numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Mul, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft * numRight;
	return Value(new Object_mpz(numResult));
}

// binary operator /
Gura_ImplementBinaryOperator(Div, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpz_class numResult = numLeft / numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpz_class numResult = numLeft / numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Div, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpz_class numResult = numLeft / numRight;
	return Value(new Object_mpz(numResult));
}

// binary operator %
Gura_ImplementBinaryOperator(Mod, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft % numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Mod, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft % numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Mod, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft % numRight;
	return Value(new Object_mpz(numResult));
}

// binary operator ==
Gura_ImplementBinaryOperator(Eq, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

// binary operator !=
Gura_ImplementBinaryOperator(Ne, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

// binary operator >
Gura_ImplementBinaryOperator(Gt, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

// binary operator <
Gura_ImplementBinaryOperator(Lt, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

// binary operator >=
Gura_ImplementBinaryOperator(Ge, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

// binary operator <=
Gura_ImplementBinaryOperator(Le, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

// binary operator <=>
Gura_ImplementBinaryOperator(Cmp, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	int numResult = ::mpz_cmp(numLeft.get_mpz_t(), numRight.get_mpz_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	int numResult = ::mpz_cmp_d(numLeft.get_mpz_t(), numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	int numResult = -::mpz_cmp_d(numRight.get_mpz_t(), numLeft);
	return Value(numResult);
}

// binary operator &
Gura_ImplementBinaryOperator(And, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft & numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(And, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft & numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(And, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft & numRight;
	return Value(new Object_mpz(numResult));
}

// binary operator |
Gura_ImplementBinaryOperator(Or, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft | numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Or, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft | numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Or, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft | numRight;
	return Value(new Object_mpz(numResult));
}

// binary operator ^
Gura_ImplementBinaryOperator(Xor, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft ^ numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Xor, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft ^ numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Xor, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft ^ numRight;
	return Value(new Object_mpz(numResult));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpz)
{
	// assignment of functions
	Gura_AssignFunction(mpz);
	// assignment of methods
	Gura_AssignMethodTo(VTYPE_string, string, mpz);
	// assignment of operator
	Gura_AssignUnaryOperator(Pos, mpz);
	Gura_AssignUnaryOperator(Neg, mpz);
	Gura_AssignUnaryOperator(Inv, mpz);
	Gura_AssignBinaryOperator(Add, mpz, mpz);
	Gura_AssignBinaryOperator(Add, mpz, number);
	Gura_AssignBinaryOperator(Add, number, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, number);
	Gura_AssignBinaryOperator(Sub, number, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, number);
	Gura_AssignBinaryOperator(Mul, number, mpz);
	Gura_AssignBinaryOperator(Div, mpz, mpz);
	Gura_AssignBinaryOperator(Div, mpz, number);
	Gura_AssignBinaryOperator(Div, number, mpz);
	Gura_AssignBinaryOperator(Mod, mpz, mpz);
	Gura_AssignBinaryOperator(Mod, mpz, number);
	Gura_AssignBinaryOperator(Mod, number, mpz);
	Gura_AssignBinaryOperator(Eq, mpz, mpz);
	Gura_AssignBinaryOperator(Eq, mpz, number);
	Gura_AssignBinaryOperator(Eq, number, mpz);
	Gura_AssignBinaryOperator(Ne, mpz, mpz);
	Gura_AssignBinaryOperator(Ne, mpz, number);
	Gura_AssignBinaryOperator(Ne, number, mpz);
	Gura_AssignBinaryOperator(Gt, mpz, mpz);
	Gura_AssignBinaryOperator(Gt, mpz, number);
	Gura_AssignBinaryOperator(Gt, number, mpz);
	Gura_AssignBinaryOperator(Lt, mpz, mpz);
	Gura_AssignBinaryOperator(Lt, mpz, number);
	Gura_AssignBinaryOperator(Lt, number, mpz);
	Gura_AssignBinaryOperator(Ge, mpz, mpz);
	Gura_AssignBinaryOperator(Ge, mpz, number);
	Gura_AssignBinaryOperator(Ge, number, mpz);
	Gura_AssignBinaryOperator(Le, mpz, mpz);
	Gura_AssignBinaryOperator(Le, mpz, number);
	Gura_AssignBinaryOperator(Le, number, mpz);
	Gura_AssignBinaryOperator(Cmp, mpz, mpz);
	Gura_AssignBinaryOperator(Cmp, mpz, number);
	Gura_AssignBinaryOperator(Cmp, number, mpz);
	Gura_AssignBinaryOperator(And, mpz, mpz);
	Gura_AssignBinaryOperator(And, mpz, number);
	Gura_AssignBinaryOperator(And, number, mpz);
	Gura_AssignBinaryOperator(Or, mpz, mpz);
	Gura_AssignBinaryOperator(Or, mpz, number);
	Gura_AssignBinaryOperator(Or, number, mpz);
	Gura_AssignBinaryOperator(Xor, mpz, mpz);
	Gura_AssignBinaryOperator(Xor, mpz, number);
	Gura_AssignBinaryOperator(Xor, number, mpz);
}

Gura_ImplementCastFrom(mpz)
{
	if (value.Is_number()) {
		mpz_t num;
		::mpz_init(num);
		::mpz_set_d(num, value.GetDouble());
		value = Value(new Object_mpz(num));
		return true;
	} else if (value.Is_string()) {
		mpz_t num;
		::mpz_init(num);
		if (::mpz_set_str(num, value.GetString(), 0) < 0) {
			::mpz_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpz");
			return false;
		}
		value = Value(new Object_mpz(num));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(mpz)
{
	if (decl.IsType(VTYPE_number)) {
		double num = Object_mpz::GetEntity(value).get_d();
		value = Value(num);
		return true;
	}
	return false;
}

Gura_EndModuleScope(gmp)
