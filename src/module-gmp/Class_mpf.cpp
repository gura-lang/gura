//=============================================================================
// Gura class: gmp.mpf
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpf
//-----------------------------------------------------------------------------
Object_mpf::Object_mpf(mpf_t num) : Object(Gura_UserClass(mpf)), _num(num)
{
}

Object_mpf::Object_mpf(const mpf_class &num) : Object(Gura_UserClass(mpf)), _num(num)
{
}

bool Object_mpf::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(prec));
	return true;
}

Value Object_mpf::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(prec))) {
		return Value(_num.get_prec());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_mpf::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(prec))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		mp_bitcnt_t prec = value.GetInt();
		_num.set_prec(prec);
		return Value(prec);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_mpf::ToString(bool exprFlag)
{
	char *p = NULL;
	::gmp_asprintf(&p, "%.Ff", _num.get_mpf_t());
	String str = p;
	if (::strchr(p, '.') == NULL) str += '.';
	str += 'L';
	::free(p);
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpf(value?, prec?:number) {block?}
Gura_DeclareFunction(mpf)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "prec", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpf));
}

Gura_ImplementFunction(mpf)
{
	mpf_t num;
	if (args.Is_number(1)) {
		::mpf_init2(num, args.GetInt(1));
	} else {
		::mpf_init(num);
	}
	if (args.IsInvalid(0)) {
		// nothing to do
	} else if (args.Is_number(0)) {
		::mpf_set_d(num, args.GetDouble(0));
	} else if (args.Is_string(0)) {
		if (::mpf_set_str(num, args.GetString(0), 0) < 0) {
			::mpf_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return Value::Null;
		}
	} else {
		::mpf_clear(num);
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpf(num)));
}

//-----------------------------------------------------------------------------
// Implementation of class methods
//-----------------------------------------------------------------------------
// gmp.mpf.get_defaul_prec()
Gura_DeclareClassMethod(mpf, get_default_prec)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementClassMethod(mpf, get_default_prec)
{
	mp_bitcnt_t prec = ::mpf_get_default_prec();
	return Value(prec);
}

// gmp.mpf.set_defaul_prec(prec:number):void
Gura_DeclareClassMethod(mpf, set_default_prec)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "prec", VTYPE_number);
}

Gura_ImplementClassMethod(mpf, set_default_prec)
{
	mp_bitcnt_t prec = args.GetInt(0);
	::mpf_set_default_prec(prec);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Implementation of instance methods
//-----------------------------------------------------------------------------
// string#mpf(base?:number):map {block?}
Gura_DeclareMethod(string, mpf)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, mpf)
{
	const char *strThis = args.GetThis().GetString();
	int base = args.Is_number(0)? args.GetInt(0) : 0;
	mpf_t num;
	::mpf_init(num);
	if (::mpf_set_str(num, strThis, base) < 0) {
		::mpf_clear(num);
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
		return false;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpf(num)));
}

//-----------------------------------------------------------------------------
// Implementation of operators
//-----------------------------------------------------------------------------
// unary operator +
Gura_ImplementUnaryOperator(Pos, mpf)
{
	mpf_class num = Object_mpf::GetEntity(value);
	mpf_class numResult = +num;
	return Value(new Object_mpf(numResult));
}

// unary operator -
Gura_ImplementUnaryOperator(Neg, mpf)
{
	mpf_class num = Object_mpf::GetEntity(value);
	mpf_class numResult = -num;
	return Value(new Object_mpf(numResult));
}

// binary operator +
Gura_ImplementBinaryOperator(Add, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

// binary operator -
Gura_ImplementBinaryOperator(Sub, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

// binary operator *
Gura_ImplementBinaryOperator(Mul, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

// binary operator /
Gura_ImplementBinaryOperator(Div, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

// binary operator ==
Gura_ImplementBinaryOperator(Eq, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

// binary operator !=
Gura_ImplementBinaryOperator(Ne, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

// binary operator >
Gura_ImplementBinaryOperator(Gt, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

// binary operator <
Gura_ImplementBinaryOperator(Lt, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

// binary operator >=
Gura_ImplementBinaryOperator(Ge, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

// binary operator <=
Gura_ImplementBinaryOperator(Le, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

// binary operator <=>
Gura_ImplementBinaryOperator(Cmp, mpf, mpf)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	int numResult = ::mpf_cmp(numLeft.get_mpf_t(), numRight.get_mpf_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpf, number)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	int numResult = ::mpf_cmp_d(numLeft.get_mpf_t(), numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	int numResult = -::mpf_cmp_d(numRight.get_mpf_t(), numLeft);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	int numResult = ::mpf_cmp(numLeft.get_mpf_t(), numRight.get_mpf_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	int numResult = ::mpf_cmp(numLeft.get_mpf_t(), numRight.get_mpf_t());
	return Value(numResult);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpf)
{
	// assignment of function
	Gura_AssignFunction(mpf);
	// assignment of class methods
	Gura_AssignMethod(mpf, get_default_prec);
	Gura_AssignMethod(mpf, set_default_prec);
	// assignment of instance methods
	
	Gura_AssignMethodTo(VTYPE_string, string, mpf);
	// assignment of operators
	Gura_AssignUnaryOperator(Pos, mpf);
	Gura_AssignUnaryOperator(Neg, mpf);
	Gura_AssignBinaryOperator(Add, mpf, mpf);
	Gura_AssignBinaryOperator(Add, mpf, number);
	Gura_AssignBinaryOperator(Add, number, mpf);
	Gura_AssignBinaryOperator(Add, mpf, mpz);
	Gura_AssignBinaryOperator(Add, mpz, mpf);
	Gura_AssignBinaryOperator(Sub, mpf, mpf);
	Gura_AssignBinaryOperator(Sub, mpf, number);
	Gura_AssignBinaryOperator(Sub, number, mpf);
	Gura_AssignBinaryOperator(Sub, mpf, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, mpf);
	Gura_AssignBinaryOperator(Mul, mpf, mpf);
	Gura_AssignBinaryOperator(Mul, mpf, number);
	Gura_AssignBinaryOperator(Mul, number, mpf);
	Gura_AssignBinaryOperator(Mul, mpf, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, mpf);
	Gura_AssignBinaryOperator(Div, mpf, mpf);
	Gura_AssignBinaryOperator(Div, mpf, number);
	Gura_AssignBinaryOperator(Div, number, mpf);
	Gura_AssignBinaryOperator(Div, mpf, mpz);
	Gura_AssignBinaryOperator(Div, mpz, mpf);
	Gura_AssignBinaryOperator(Eq, mpf, mpf);
	Gura_AssignBinaryOperator(Eq, mpf, number);
	Gura_AssignBinaryOperator(Eq, number, mpf);
	Gura_AssignBinaryOperator(Eq, mpf, mpz);
	Gura_AssignBinaryOperator(Eq, mpz, mpf);
	Gura_AssignBinaryOperator(Ne, mpf, mpf);
	Gura_AssignBinaryOperator(Ne, mpf, number);
	Gura_AssignBinaryOperator(Ne, number, mpf);
	Gura_AssignBinaryOperator(Ne, mpf, mpz);
	Gura_AssignBinaryOperator(Ne, mpz, mpf);
	Gura_AssignBinaryOperator(Gt, mpf, mpf);
	Gura_AssignBinaryOperator(Gt, mpf, number);
	Gura_AssignBinaryOperator(Gt, number, mpf);
	Gura_AssignBinaryOperator(Gt, mpf, mpz);
	Gura_AssignBinaryOperator(Gt, mpz, mpf);
	Gura_AssignBinaryOperator(Lt, mpf, mpf);
	Gura_AssignBinaryOperator(Lt, mpf, number);
	Gura_AssignBinaryOperator(Lt, number, mpf);
	Gura_AssignBinaryOperator(Lt, mpf, mpz);
	Gura_AssignBinaryOperator(Lt, mpz, mpf);
	Gura_AssignBinaryOperator(Ge, mpf, mpf);
	Gura_AssignBinaryOperator(Ge, mpf, number);
	Gura_AssignBinaryOperator(Ge, number, mpf);
	Gura_AssignBinaryOperator(Ge, mpf, mpz);
	Gura_AssignBinaryOperator(Ge, mpz, mpf);
	Gura_AssignBinaryOperator(Le, mpf, mpf);
	Gura_AssignBinaryOperator(Le, mpf, number);
	Gura_AssignBinaryOperator(Le, number, mpf);
	Gura_AssignBinaryOperator(Le, mpf, mpz);
	Gura_AssignBinaryOperator(Le, mpz, mpf);
	Gura_AssignBinaryOperator(Cmp, mpf, mpf);
	Gura_AssignBinaryOperator(Cmp, mpf, number);
	Gura_AssignBinaryOperator(Cmp, number, mpf);
	Gura_AssignBinaryOperator(Cmp, mpf, mpz);
	Gura_AssignBinaryOperator(Cmp, mpz, mpf);
}

Gura_ImplementCastFrom(mpf)
{
	if (value.Is_number()) {
		mpf_t num;
		::mpf_init(num);
		::mpf_set_d(num, value.GetDouble());
		value = Value(new Object_mpf(num));
		return true;
	} else if (value.Is_string()) {
		mpf_t num;
		::mpf_init(num);
		if (::mpf_set_str(num, value.GetString(), 0) < 0) {
			::mpf_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return false;
		}
		value = Value(new Object_mpf(num));
		return true;
	} else if (value.IsType(VTYPE_mpz)) {
		
	} else if (value.IsType(VTYPE_mpq)) {
		
	}
	return false;
}

Gura_ImplementCastTo(mpf)
{
	if (decl.IsType(VTYPE_number)) {
		double num = Object_mpf::GetEntity(value).get_d();
		value = Value(num);
		return true;
	}
	return false;
}

Gura_EndModuleScope(gmp)
