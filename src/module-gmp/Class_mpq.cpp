//=============================================================================
// Gura class: gmp.mpq
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

mpq_class FromRational(const Rational &ratio);

//-----------------------------------------------------------------------------
// Object_mpq
//-----------------------------------------------------------------------------
Object_mpq::Object_mpq(mpq_t num) : Object(Gura_UserClass(mpq)), _num(num)
{
}

bool Object_mpq::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(numer));
	symbols.insert(Gura_Symbol(denom));
	return true;
}

Value Object_mpq::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(numer))) {
		return Value(new Object_mpz(_num.get_num_mpz_t()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(denom))) {
		return Value(new Object_mpz(_num.get_den_mpz_t()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_mpq::ToString(bool exprFlag)
{
	String str;
	str += _num.get_num().get_str();
	if (_num.get_den() != 1) {
		str += "/";
		str += _num.get_den().get_str();
	}
	str += "Lr";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpq(numer?, denom?:number) {block?}
Gura_DeclareFunction(mpq)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "numer", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "denom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpq));
}

Gura_ImplementFunction(mpq)
{
	mpq_t num;
	::mpq_init(num);
	if (args.IsInvalid(0)) {
		// nothing to do
	} else if (args.Is_number(0)) {
		::mpz_set_si(mpq_numref(num), args.GetInt(0));
		if (args.Is_number(1)) {
			::mpz_set_si(mpq_denref(num), args.GetInt(1));
		}
	} else if (args.Is_string(0)) {
		if (::mpq_set_str(num, args.GetString(0), 0) < 0) {
			::mpq_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpq");
			return Value::Null;
		}
	} else {
		::mpq_clear(num);
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpq(num)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// string#mpq(base?:number):map {block?}
Gura_DeclareMethod(string, mpq)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, mpq)
{
	const char *strThis = args.GetThis().GetString();
	int base = args.Is_number(0)? args.GetInt(0) : 0;
	mpq_t num;
	::mpq_init(num);
	if (::mpq_set_str(num, strThis, base) < 0) {
		::mpq_clear(num);
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpq");
		return false;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpq(num)));
}

//-----------------------------------------------------------------------------
// Implementation of operators
//-----------------------------------------------------------------------------
// unary operator +
Gura_ImplementUnaryOperator(Pos, mpq)
{
	mpq_class num = Object_mpq::GetEntity(value);
	mpq_class numResult = +num;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

// unary operator -
Gura_ImplementUnaryOperator(Neg, mpq)
{
	mpq_class num = Object_mpq::GetEntity(value);
	mpq_class numResult = -num;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

// binary operator +
Gura_ImplementBinaryOperator(Add, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Add, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Add, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Add, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Add, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Add, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = FromRational(valueRight.GetRational());
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Add, rational, mpq)
{
	mpq_class numLeft = FromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Add, rational, mpz)
{
	mpq_class numLeft = FromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Add, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = FromRational(valueRight.GetRational());
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

// binary operator -
Gura_ImplementBinaryOperator(Sub, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Sub, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Sub, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Sub, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Sub, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Sub, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = FromRational(valueRight.GetRational());
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Sub, rational, mpq)
{
	mpq_class numLeft = FromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Sub, rational, mpz)
{
	mpq_class numLeft = FromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Sub, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = FromRational(valueRight.GetRational());
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

// binary operator *
Gura_ImplementBinaryOperator(Mul, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Mul, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Mul, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Mul, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Mul, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Mul, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = FromRational(valueRight.GetRational());
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Mul, rational, mpq)
{
	mpq_class numLeft = FromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Mul, rational, mpz)
{
	mpq_class numLeft = FromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Mul, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = FromRational(valueRight.GetRational());
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

// binary operator /
Gura_ImplementBinaryOperator(Div, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Div, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Div, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Div, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Div, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Div, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = FromRational(valueRight.GetRational());
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Div, rational, mpq)
{
	mpq_class numLeft = FromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Div, rational, mpz)
{
	mpq_class numLeft = FromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

Gura_ImplementBinaryOperator(Div, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = FromRational(valueRight.GetRational());
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult.get_mpq_t()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpq)
{
	// function assignment
	Gura_AssignFunction(mpq);
	// method assignment
	Gura_AssignMethodTo(VTYPE_string, string, mpq);
	// operator assignment
	Gura_AssignUnaryOperator(Pos, mpq);
	Gura_AssignUnaryOperator(Neg, mpq);
	Gura_AssignBinaryOperator(Add, mpq, mpq);
	Gura_AssignBinaryOperator(Add, mpq, mpz);
	Gura_AssignBinaryOperator(Add, mpz, mpq);
	Gura_AssignBinaryOperator(Add, mpq, number);
	Gura_AssignBinaryOperator(Add, number, mpq);
	Gura_AssignBinaryOperator(Add, mpq, rational);
	Gura_AssignBinaryOperator(Add, rational, mpq);
	Gura_AssignBinaryOperator(Add, rational, mpz);
	Gura_AssignBinaryOperator(Add, mpz, rational);
	Gura_AssignBinaryOperator(Sub, mpq, mpq);
	Gura_AssignBinaryOperator(Sub, mpq, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, mpq);
	Gura_AssignBinaryOperator(Sub, mpq, number);
	Gura_AssignBinaryOperator(Sub, number, mpq);
	Gura_AssignBinaryOperator(Sub, rational, mpq);
	Gura_AssignBinaryOperator(Sub, mpq, rational);
	Gura_AssignBinaryOperator(Sub, rational, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, rational);
	Gura_AssignBinaryOperator(Mul, mpq, mpq);
	Gura_AssignBinaryOperator(Mul, mpq, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, mpq);
	Gura_AssignBinaryOperator(Mul, mpq, number);
	Gura_AssignBinaryOperator(Mul, number, mpq);
	Gura_AssignBinaryOperator(Mul, rational, mpq);
	Gura_AssignBinaryOperator(Mul, mpq, rational);
	Gura_AssignBinaryOperator(Mul, rational, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, rational);
	Gura_AssignBinaryOperator(Div, mpq, mpq);
	Gura_AssignBinaryOperator(Div, mpq, mpz);
	Gura_AssignBinaryOperator(Div, mpz, mpq);
	Gura_AssignBinaryOperator(Div, mpq, number);
	Gura_AssignBinaryOperator(Div, number, mpq);
	Gura_AssignBinaryOperator(Div, rational, mpq);
	Gura_AssignBinaryOperator(Div, mpq, rational);
	Gura_AssignBinaryOperator(Div, rational, mpz);
	Gura_AssignBinaryOperator(Div, mpz, rational);
}

Gura_ImplementCastFrom(mpq)
{
	if (value.Is_number()) {
		mpq_t num;
		::mpq_init(num);
		::mpq_set_d(num, value.GetDouble());
		value = Value(new Object_mpq(num));
		return true;
	} else if (value.Is_string()) {
		mpq_t num;
		::mpq_init(num);
		if (::mpq_set_str(num, value.GetString(), 0) < 0) {
			::mpq_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpq");
			return false;
		}
		value = Value(new Object_mpq(num));
		return true;
	} else if (value.Is_rational()) {
		mpq_class num = FromRational(value.GetRational());
		value = Value(new Object_mpq(num.get_mpq_t()));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(mpq)
{
	if (decl.IsType(VTYPE_number)) {
		double num = Object_mpq::GetEntity(value).get_d();
		value = Value(num);
		return true;
	}
	return false;
}

mpq_class FromRational(const Rational &ratio)
{
	mpq_t num;
	::mpq_init(num);
	::mpz_set_si(mpq_numref(num), ratio.numer);
	::mpz_set_si(mpq_denref(num), ratio.denom);
	return mpq_class(num);
}

Gura_EndModuleScope(gmp)
