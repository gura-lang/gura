//=============================================================================
// Operators
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// unary operator +
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Pos, mpz)
{
	mpz_class num = Object_mpz::GetEntity(value);
	mpz_class numResult = +num;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementUnaryOperator(Pos, mpq)
{
	mpq_class num = Object_mpq::GetEntity(value);
	mpq_class numResult = +num;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementUnaryOperator(Pos, mpf)
{
	mpf_class num = Object_mpf::GetEntity(value);
	mpf_class numResult = +num;
	return Value(new Object_mpf(numResult));
}

//-----------------------------------------------------------------------------
// unary operator -
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Neg, mpz)
{
	mpz_class num = Object_mpz::GetEntity(value);
	mpz_class numResult = -num;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementUnaryOperator(Neg, mpq)
{
	mpq_class num = Object_mpq::GetEntity(value);
	mpq_class numResult = -num;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementUnaryOperator(Neg, mpf)
{
	mpf_class num = Object_mpf::GetEntity(value);
	mpf_class numResult = -num;
	return Value(new Object_mpf(numResult));
}

//-----------------------------------------------------------------------------
// unary operator ~
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperator(Inv, mpz)
{
	mpz_class num = Object_mpz::GetEntity(value);
	mpz_class numResult = ~num;
	return Value(new Object_mpz(numResult));
}

//-----------------------------------------------------------------------------
// binary operator +
//-----------------------------------------------------------------------------
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

Gura_ImplementBinaryOperator(Add, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpq, mpf)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpf::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

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

//-----------------------------------------------------------------------------
// binary operator -
//-----------------------------------------------------------------------------
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

Gura_ImplementBinaryOperator(Sub, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpq, mpf)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpf::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

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

//-----------------------------------------------------------------------------
// binary operator *
//-----------------------------------------------------------------------------
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

Gura_ImplementBinaryOperator(Mul, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpq, mpf)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpf::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

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

//-----------------------------------------------------------------------------
// binary operator /
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Div, mpz, mpz)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, number)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, mpf)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpf::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

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

//-----------------------------------------------------------------------------
// binary operator %
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Mod, mpz, mpz)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpz_class numResult = numLeft % numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Mod, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpz_class numResult = numLeft % numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Mod, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpz_class numResult = numLeft % numRight;
	return Value(new Object_mpz(numResult));
}

//-----------------------------------------------------------------------------
// binary operator ==
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// binary operator !=
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// binary operator >
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// binary operator <
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// binary operator >=
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// binary operator <=
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// binary operator <=>
//-----------------------------------------------------------------------------
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
// binary operator &
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// binary operator |
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// binary operator ^
//-----------------------------------------------------------------------------
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
// binary operator <<
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shl, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft << numRight;
	return Value(new Object_mpz(numResult));
}

//-----------------------------------------------------------------------------
// binary operator <<
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Shr, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft >> numRight;
	return Value(new Object_mpz(numResult));
}

//-----------------------------------------------------------------------------
// functions
//-----------------------------------------------------------------------------
void AssignOperators(Environment &env)
{
	// unary operator +
	Gura_AssignUnaryOperator(Pos, mpz);
	Gura_AssignUnaryOperator(Pos, mpq);
	Gura_AssignUnaryOperator(Pos, mpf);
	// unary operator -
	Gura_AssignUnaryOperator(Neg, mpz);
	Gura_AssignUnaryOperator(Neg, mpq);
	Gura_AssignUnaryOperator(Neg, mpf);
	// unary operator ~
	Gura_AssignUnaryOperator(Inv, mpz);
	// binary operator +
	Gura_AssignBinaryOperator(Add, mpz, mpz);
	Gura_AssignBinaryOperator(Add, mpz, number);
	Gura_AssignBinaryOperator(Add, number, mpz);
	Gura_AssignBinaryOperator(Add, mpq, mpq);
	Gura_AssignBinaryOperator(Add, mpq, mpz);
	Gura_AssignBinaryOperator(Add, mpz, mpq);
	Gura_AssignBinaryOperator(Add, mpq, mpf);
	Gura_AssignBinaryOperator(Add, mpf, mpq);
	Gura_AssignBinaryOperator(Add, mpq, number);
	Gura_AssignBinaryOperator(Add, number, mpq);
	Gura_AssignBinaryOperator(Add, mpq, rational);
	Gura_AssignBinaryOperator(Add, rational, mpq);
	Gura_AssignBinaryOperator(Add, rational, mpz);
	Gura_AssignBinaryOperator(Add, mpz, rational);
	Gura_AssignBinaryOperator(Add, mpf, mpf);
	Gura_AssignBinaryOperator(Add, mpf, number);
	Gura_AssignBinaryOperator(Add, number, mpf);
	Gura_AssignBinaryOperator(Add, mpf, mpz);
	Gura_AssignBinaryOperator(Add, mpz, mpf);
	// binary operator -
	Gura_AssignBinaryOperator(Sub, mpz, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, number);
	Gura_AssignBinaryOperator(Sub, number, mpz);
	Gura_AssignBinaryOperator(Sub, mpq, mpq);
	Gura_AssignBinaryOperator(Sub, mpq, mpz);
	Gura_AssignBinaryOperator(Sub, mpq, mpf);
	Gura_AssignBinaryOperator(Sub, mpf, mpq);
	Gura_AssignBinaryOperator(Sub, mpz, mpq);
	Gura_AssignBinaryOperator(Sub, mpq, number);
	Gura_AssignBinaryOperator(Sub, number, mpq);
	Gura_AssignBinaryOperator(Sub, rational, mpq);
	Gura_AssignBinaryOperator(Sub, mpq, rational);
	Gura_AssignBinaryOperator(Sub, rational, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, rational);
	Gura_AssignBinaryOperator(Sub, mpf, mpf);
	Gura_AssignBinaryOperator(Sub, mpf, number);
	Gura_AssignBinaryOperator(Sub, number, mpf);
	Gura_AssignBinaryOperator(Sub, mpf, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, mpf);
	// binary operator *
	Gura_AssignBinaryOperator(Mul, mpz, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, number);
	Gura_AssignBinaryOperator(Mul, number, mpz);
	Gura_AssignBinaryOperator(Mul, mpq, mpq);
	Gura_AssignBinaryOperator(Mul, mpq, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, mpq);
	Gura_AssignBinaryOperator(Mul, mpq, mpf);
	Gura_AssignBinaryOperator(Mul, mpf, mpq);
	Gura_AssignBinaryOperator(Mul, mpq, number);
	Gura_AssignBinaryOperator(Mul, number, mpq);
	Gura_AssignBinaryOperator(Mul, rational, mpq);
	Gura_AssignBinaryOperator(Mul, mpq, rational);
	Gura_AssignBinaryOperator(Mul, rational, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, rational);
	Gura_AssignBinaryOperator(Mul, mpf, mpf);
	Gura_AssignBinaryOperator(Mul, mpf, number);
	Gura_AssignBinaryOperator(Mul, number, mpf);
	Gura_AssignBinaryOperator(Mul, mpf, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, mpf);
	// binary operator /
 	Gura_AssignBinaryOperator(Div, mpz, mpz);
	Gura_AssignBinaryOperator(Div, mpz, number);
	Gura_AssignBinaryOperator(Div, number, mpz);
	Gura_AssignBinaryOperator(Div, mpq, mpq);
	Gura_AssignBinaryOperator(Div, mpq, mpz);
	Gura_AssignBinaryOperator(Div, mpz, mpq);
	Gura_AssignBinaryOperator(Div, mpq, mpf);
	Gura_AssignBinaryOperator(Div, mpf, mpq);
	Gura_AssignBinaryOperator(Div, mpq, number);
	Gura_AssignBinaryOperator(Div, number, mpq);
	Gura_AssignBinaryOperator(Div, rational, mpq);
	Gura_AssignBinaryOperator(Div, mpq, rational);
	Gura_AssignBinaryOperator(Div, rational, mpz);
	Gura_AssignBinaryOperator(Div, mpz, rational);
	Gura_AssignBinaryOperator(Div, mpf, mpf);
	Gura_AssignBinaryOperator(Div, mpf, number);
	Gura_AssignBinaryOperator(Div, number, mpf);
	Gura_AssignBinaryOperator(Div, mpf, mpz);
	Gura_AssignBinaryOperator(Div, mpz, mpf);
	// binary operator %
	Gura_AssignBinaryOperator(Mod, mpz, mpz);
	Gura_AssignBinaryOperator(Mod, mpz, number);
	Gura_AssignBinaryOperator(Mod, number, mpz);
	// binary operator ==
	Gura_AssignBinaryOperator(Eq, mpz, mpz);
	Gura_AssignBinaryOperator(Eq, mpz, number);
	Gura_AssignBinaryOperator(Eq, number, mpz);
	Gura_AssignBinaryOperator(Eq, mpf, mpf);
	Gura_AssignBinaryOperator(Eq, mpf, number);
	Gura_AssignBinaryOperator(Eq, number, mpf);
	Gura_AssignBinaryOperator(Eq, mpf, mpz);
	Gura_AssignBinaryOperator(Eq, mpz, mpf);
	// binary operator !=
	Gura_AssignBinaryOperator(Ne, mpz, mpz);
	Gura_AssignBinaryOperator(Ne, mpz, number);
	Gura_AssignBinaryOperator(Ne, number, mpz);
	Gura_AssignBinaryOperator(Ne, mpf, mpf);
	Gura_AssignBinaryOperator(Ne, mpf, number);
	Gura_AssignBinaryOperator(Ne, number, mpf);
	Gura_AssignBinaryOperator(Ne, mpf, mpz);
	Gura_AssignBinaryOperator(Ne, mpz, mpf);
	// binary operator >
	Gura_AssignBinaryOperator(Gt, mpz, mpz);
	Gura_AssignBinaryOperator(Gt, mpz, number);
	Gura_AssignBinaryOperator(Gt, number, mpz);
	Gura_AssignBinaryOperator(Gt, mpf, mpf);
	Gura_AssignBinaryOperator(Gt, mpf, number);
	Gura_AssignBinaryOperator(Gt, number, mpf);
	Gura_AssignBinaryOperator(Gt, mpf, mpz);
	Gura_AssignBinaryOperator(Gt, mpz, mpf);
	// binary operator <
	Gura_AssignBinaryOperator(Lt, mpz, mpz);
	Gura_AssignBinaryOperator(Lt, mpz, number);
	Gura_AssignBinaryOperator(Lt, number, mpz);
	Gura_AssignBinaryOperator(Lt, mpf, mpf);
	Gura_AssignBinaryOperator(Lt, mpf, number);
	Gura_AssignBinaryOperator(Lt, number, mpf);
	Gura_AssignBinaryOperator(Lt, mpf, mpz);
	Gura_AssignBinaryOperator(Lt, mpz, mpf);
	// binary operator >=
	Gura_AssignBinaryOperator(Ge, mpz, mpz);
	Gura_AssignBinaryOperator(Ge, mpz, number);
	Gura_AssignBinaryOperator(Ge, number, mpz);
	Gura_AssignBinaryOperator(Ge, mpf, mpf);
	Gura_AssignBinaryOperator(Ge, mpf, number);
	Gura_AssignBinaryOperator(Ge, number, mpf);
	Gura_AssignBinaryOperator(Ge, mpf, mpz);
	Gura_AssignBinaryOperator(Ge, mpz, mpf);
	// binary operator <=
	Gura_AssignBinaryOperator(Le, mpz, mpz);
	Gura_AssignBinaryOperator(Le, mpz, number);
	Gura_AssignBinaryOperator(Le, number, mpz);
	Gura_AssignBinaryOperator(Le, mpf, mpf);
	Gura_AssignBinaryOperator(Le, mpf, number);
	Gura_AssignBinaryOperator(Le, number, mpf);
	Gura_AssignBinaryOperator(Le, mpf, mpz);
	Gura_AssignBinaryOperator(Le, mpz, mpf);
	// binary operator <=>
	Gura_AssignBinaryOperator(Cmp, mpz, mpz);
	Gura_AssignBinaryOperator(Cmp, mpz, number);
	Gura_AssignBinaryOperator(Cmp, number, mpz);
	Gura_AssignBinaryOperator(Cmp, mpf, mpf);
	Gura_AssignBinaryOperator(Cmp, mpf, number);
	Gura_AssignBinaryOperator(Cmp, number, mpf);
	Gura_AssignBinaryOperator(Cmp, mpf, mpz);
	Gura_AssignBinaryOperator(Cmp, mpz, mpf);
	// binary operator &
	Gura_AssignBinaryOperator(And, mpz, mpz);
	Gura_AssignBinaryOperator(And, mpz, number);
	Gura_AssignBinaryOperator(And, number, mpz);
	// binary operator |
	Gura_AssignBinaryOperator(Or, mpz, mpz);
	Gura_AssignBinaryOperator(Or, mpz, number);
	Gura_AssignBinaryOperator(Or, number, mpz);
	// binary operator ^
	Gura_AssignBinaryOperator(Xor, mpz, mpz);
	Gura_AssignBinaryOperator(Xor, mpz, number);
	Gura_AssignBinaryOperator(Xor, number, mpz);
	// binary operator <<
	Gura_AssignBinaryOperator(Shl, mpz, number);
	// binary operator >>
	Gura_AssignBinaryOperator(Shr, mpz, number);
}

Gura_EndModuleScope(gmp)
