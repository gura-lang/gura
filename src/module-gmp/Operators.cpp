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

Gura_ImplementBinaryOperator(Add, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft + numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Add, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Add, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Add, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
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

Gura_ImplementBinaryOperator(Add, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft + numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Add, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft + numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Add, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft + numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Add, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Add, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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

Gura_ImplementBinaryOperator(Sub, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft - numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Sub, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Sub, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
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

Gura_ImplementBinaryOperator(Sub, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft - numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Sub, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft - numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Sub, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft - numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Sub, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Sub, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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

Gura_ImplementBinaryOperator(Mul, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	mpz_class numResult = numLeft * numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Mul, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Mul, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
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

Gura_ImplementBinaryOperator(Mul, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	mpz_class numResult = numLeft * numRight;
	return Value(new Object_mpz(numResult));
}

Gura_ImplementBinaryOperator(Mul, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	mpq_class numResult = numLeft * numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Mul, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Mul, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Mul, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	mpf_class numResult = numLeft * numRight;
	return Value(new Object_mpf(numResult));
}

//-----------------------------------------------------------------------------
// binary operator /
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Div, mpz, mpz)
{
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, mpq)
{
	Signal &sig = env.GetSignal();
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, mpf)
{
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, number)
{
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpz, rational)
{
	Signal &sig = env.GetSignal();
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, mpz)
{
	Signal &sig = env.GetSignal();
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, mpq)
{
	Signal &sig = env.GetSignal();
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
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
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, number)
{
	Signal &sig = env.GetSignal();
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpq, rational)
{
	Signal &sig = env.GetSignal();
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, mpf, mpz)
{
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpf, mpq)
{
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpf, mpf)
{
	Signal &sig = env.GetSignal();
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
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, mpf, rational)
{
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, number, mpz)
{
	Signal &sig = env.GetSignal();
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, number, mpq)
{
	Signal &sig = env.GetSignal();
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, number, mpf)
{
	Signal &sig = env.GetSignal();
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpf_class numResult = numLeft / numRight;
	return Value(new Object_mpf(numResult));
}

Gura_ImplementBinaryOperator(Div, rational, mpz)
{
	Signal &sig = env.GetSignal();
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, rational, mpq)
{
	Signal &sig = env.GetSignal();
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	if (numRight == 0) {
		Operator::SetError_DivideByZero(sig);
		return Value::Null;
	}
	mpq_class numResult = numLeft / numRight;
	return Value(new Object_mpq(numResult));
}

Gura_ImplementBinaryOperator(Div, rational, mpf)
{
	Signal &sig = env.GetSignal();
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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
	Signal &sig = env.GetSignal();
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
	Signal &sig = env.GetSignal();
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
	Signal &sig = env.GetSignal();
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

Gura_ImplementBinaryOperator(Eq, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Eq, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Eq, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Eq, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Eq, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Eq, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft == numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Eq, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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

Gura_ImplementBinaryOperator(Ne, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Ne, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Ne, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Ne, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Ne, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Ne, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft != numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ne, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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

Gura_ImplementBinaryOperator(Gt, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Gt, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Gt, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Gt, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Gt, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Gt, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft > numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Gt, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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

Gura_ImplementBinaryOperator(Lt, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Lt, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Lt, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Lt, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Lt, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Lt, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft < numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Lt, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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

Gura_ImplementBinaryOperator(Ge, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Ge, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Ge, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Ge, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Ge, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Ge, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft >= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Ge, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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

Gura_ImplementBinaryOperator(Le, mpz, mpq)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Le, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpz, rational)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Le, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Le, mpf, rational)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
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

Gura_ImplementBinaryOperator(Le, number, mpq)
{
	double numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
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

Gura_ImplementBinaryOperator(Le, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	bool numResult = (numLeft <= numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Le, rational, mpf)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
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

Gura_ImplementBinaryOperator(Cmp, mpz, mpq)
{
	mpq_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	int numResult = ::mpq_cmp(numLeft.get_mpq_t(), numRight.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpz, mpf)
{
	mpf_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	int numResult = ::mpf_cmp(numLeft.get_mpf_t(), numRight.get_mpf_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpz, number)
{
	mpz_class numLeft = Object_mpz::GetEntity(valueLeft);
	double numRight = valueRight.GetDouble();
	int numResult = ::mpz_cmp_d(numLeft.get_mpz_t(), numRight);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpz, rational)
{
	mpq_class numLeft = Object_mpz::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	int numResult = ::mpq_cmp(numLeft.get_mpq_t(), numRight.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpq, mpz)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpz::GetEntity(valueRight);
	int numResult = ::mpq_cmp(numLeft.get_mpq_t(), numRight.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpq, mpq)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	int numResult = ::mpq_cmp(numLeft.get_mpq_t(), numRight.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpq, mpf)
{
	mpf_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	int numResult = ::mpf_cmp(numLeft.get_mpf_t(), numRight.get_mpf_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpq, number)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = valueRight.GetDouble();
	int numResult = ::mpq_cmp(numLeft.get_mpq_t(), numRight.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpq, rational)
{
	mpq_class numLeft = Object_mpq::GetEntity(valueLeft);
	mpq_class numRight = MpqFromRational(valueRight.GetRational());
	int numResult = ::mpq_cmp(numLeft.get_mpq_t(), numRight.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpf, mpz)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpz::GetEntity(valueRight);
	int numResult = ::mpf_cmp(numLeft.get_mpf_t(), numRight.get_mpf_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, mpf, mpq)
{
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = Object_mpq::GetEntity(valueRight);
	int numResult = ::mpf_cmp(numLeft.get_mpf_t(), numRight.get_mpf_t());
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

Gura_ImplementBinaryOperator(Cmp, mpf, rational)
{
	Signal &sig = env.GetSignal();
	mpf_class numLeft = Object_mpf::GetEntity(valueLeft);
	mpf_class numRight = MpfFromRational(sig, valueRight.GetRational());
	if (sig.IsSignalled()) return Value::Null;
	int numResult = ::mpf_cmp(numLeft.get_mpf_t(), numRight.get_mpf_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, number, mpz)
{
	double numLeft = valueLeft.GetDouble();
	mpz_class numRight = Object_mpz::GetEntity(valueRight);
	int numResult = -::mpz_cmp_d(numRight.get_mpz_t(), numLeft);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, number, mpq)
{
	mpq_class numLeft = valueLeft.GetDouble();
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	int numResult = -::mpq_cmp(numRight.get_mpq_t(), numLeft.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, number, mpf)
{
	double numLeft = valueLeft.GetDouble();
	mpf_class numRight = Object_mpf::GetEntity(valueRight);
	int numResult = -::mpf_cmp_d(numRight.get_mpf_t(), numLeft);
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, rational, mpz)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpz::GetEntity(valueRight);
	int numResult = ::mpq_cmp(numLeft.get_mpq_t(), numRight.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, rational, mpq)
{
	mpq_class numLeft = MpqFromRational(valueLeft.GetRational());
	mpq_class numRight = Object_mpq::GetEntity(valueRight);
	int numResult = ::mpq_cmp(numLeft.get_mpq_t(), numRight.get_mpq_t());
	return Value(numResult);
}

Gura_ImplementBinaryOperator(Cmp, rational, mpf)
{
	Signal &sig = env.GetSignal();
	mpf_class numLeft = MpfFromRational(sig, valueLeft.GetRational());
	if (sig.IsSignalled()) return Value::Null;
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
// unary operator ..
//-----------------------------------------------------------------------------
Gura_ImplementUnaryOperatorSuffix(SeqInf, mpz)
{
	mpz_class numBegin = Object_mpz::GetEntity(value);
	return Value(new Object_iterator(env, new Iterator_GmpSeqInf(numBegin)));
}

//-----------------------------------------------------------------------------
// binary operator ..
//-----------------------------------------------------------------------------
Gura_ImplementBinaryOperator(Seq, mpz, mpz)
{
	const mpz_class &numBegin = Object_mpz::GetEntity(valueLeft);
	const mpz_class &numEnd = Object_mpz::GetEntity(valueRight);
	mpz_class numStep = (numEnd >= numBegin)? +1 : -1;
	return Value(new Object_iterator(env, new Iterator_GmpSeq(numBegin, numEnd, numStep)));
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
	Gura_AssignBinaryOperator(Add, mpz, mpq);
	Gura_AssignBinaryOperator(Add, mpz, mpf);
	Gura_AssignBinaryOperator(Add, mpz, number);
	Gura_AssignBinaryOperator(Add, mpz, rational);
	Gura_AssignBinaryOperator(Add, mpq, mpz);
	Gura_AssignBinaryOperator(Add, mpq, mpq);
	Gura_AssignBinaryOperator(Add, mpq, mpf);
	Gura_AssignBinaryOperator(Add, mpq, number);
	Gura_AssignBinaryOperator(Add, mpq, rational);
	Gura_AssignBinaryOperator(Add, mpf, mpz);
	Gura_AssignBinaryOperator(Add, mpf, mpq);
	Gura_AssignBinaryOperator(Add, mpf, mpf);
	Gura_AssignBinaryOperator(Add, mpf, number);
	Gura_AssignBinaryOperator(Add, mpf, rational);
	Gura_AssignBinaryOperator(Add, number, mpz);
	Gura_AssignBinaryOperator(Add, number, mpq);
	Gura_AssignBinaryOperator(Add, number, mpf);
	Gura_AssignBinaryOperator(Add, rational, mpz);
	Gura_AssignBinaryOperator(Add, rational, mpq);
	Gura_AssignBinaryOperator(Add, rational, mpf);
	// binary operator -
	Gura_AssignBinaryOperator(Sub, mpz, mpz);
	Gura_AssignBinaryOperator(Sub, mpz, mpq);
	Gura_AssignBinaryOperator(Sub, mpz, mpf);
	Gura_AssignBinaryOperator(Sub, mpz, number);
	Gura_AssignBinaryOperator(Sub, mpz, rational);
	Gura_AssignBinaryOperator(Sub, mpq, mpz);
	Gura_AssignBinaryOperator(Sub, mpq, mpq);
	Gura_AssignBinaryOperator(Sub, mpq, mpf);
	Gura_AssignBinaryOperator(Sub, mpq, number);
	Gura_AssignBinaryOperator(Sub, mpq, rational);
	Gura_AssignBinaryOperator(Sub, mpf, mpz);
	Gura_AssignBinaryOperator(Sub, mpf, mpq);
	Gura_AssignBinaryOperator(Sub, mpf, mpf);
	Gura_AssignBinaryOperator(Sub, mpf, number);
	Gura_AssignBinaryOperator(Sub, mpf, rational);
	Gura_AssignBinaryOperator(Sub, number, mpz);
	Gura_AssignBinaryOperator(Sub, number, mpq);
	Gura_AssignBinaryOperator(Sub, number, mpf);
	Gura_AssignBinaryOperator(Sub, rational, mpz);
	Gura_AssignBinaryOperator(Sub, rational, mpq);
	Gura_AssignBinaryOperator(Sub, rational, mpf);
	// binary operator *
	Gura_AssignBinaryOperator(Mul, mpz, mpz);
	Gura_AssignBinaryOperator(Mul, mpz, mpq);
	Gura_AssignBinaryOperator(Mul, mpz, mpf);
	Gura_AssignBinaryOperator(Mul, mpz, number);
	Gura_AssignBinaryOperator(Mul, mpz, rational);
	Gura_AssignBinaryOperator(Mul, mpq, mpz);
	Gura_AssignBinaryOperator(Mul, mpq, mpq);
	Gura_AssignBinaryOperator(Mul, mpq, mpf);
	Gura_AssignBinaryOperator(Mul, mpq, number);
	Gura_AssignBinaryOperator(Mul, mpq, rational);
	Gura_AssignBinaryOperator(Mul, mpf, mpz);
	Gura_AssignBinaryOperator(Mul, mpf, mpq);
	Gura_AssignBinaryOperator(Mul, mpf, mpf);
	Gura_AssignBinaryOperator(Mul, mpf, number);
	Gura_AssignBinaryOperator(Mul, mpf, rational);
	Gura_AssignBinaryOperator(Mul, number, mpz);
	Gura_AssignBinaryOperator(Mul, number, mpq);
	Gura_AssignBinaryOperator(Mul, number, mpf);
	Gura_AssignBinaryOperator(Mul, rational, mpz);
	Gura_AssignBinaryOperator(Mul, rational, mpq);
	Gura_AssignBinaryOperator(Mul, rational, mpf);
	// binary operator /
	Gura_AssignBinaryOperator(Div, mpz, mpz);
	Gura_AssignBinaryOperator(Div, mpz, mpq);
	Gura_AssignBinaryOperator(Div, mpz, mpf);
	Gura_AssignBinaryOperator(Div, mpz, number);
	Gura_AssignBinaryOperator(Div, mpz, rational);
	Gura_AssignBinaryOperator(Div, mpq, mpz);
	Gura_AssignBinaryOperator(Div, mpq, mpq);
	Gura_AssignBinaryOperator(Div, mpq, mpf);
	Gura_AssignBinaryOperator(Div, mpq, number);
	Gura_AssignBinaryOperator(Div, mpq, rational);
	Gura_AssignBinaryOperator(Div, mpf, mpz);
	Gura_AssignBinaryOperator(Div, mpf, mpq);
	Gura_AssignBinaryOperator(Div, mpf, mpf);
	Gura_AssignBinaryOperator(Div, mpf, number);
	Gura_AssignBinaryOperator(Div, mpf, rational);
	Gura_AssignBinaryOperator(Div, number, mpz);
	Gura_AssignBinaryOperator(Div, number, mpq);
	Gura_AssignBinaryOperator(Div, number, mpf);
	Gura_AssignBinaryOperator(Div, rational, mpz);
	Gura_AssignBinaryOperator(Div, rational, mpq);
	Gura_AssignBinaryOperator(Div, rational, mpf);
	// binary operator %
	Gura_AssignBinaryOperator(Mod, mpz, mpz);
	Gura_AssignBinaryOperator(Mod, mpz, number);
	Gura_AssignBinaryOperator(Mod, number, mpz);
	// binary operator ==
	Gura_AssignBinaryOperator(Eq, mpz, mpz);
	Gura_AssignBinaryOperator(Eq, mpz, mpq);
	Gura_AssignBinaryOperator(Eq, mpz, mpf);
	Gura_AssignBinaryOperator(Eq, mpz, number);
	Gura_AssignBinaryOperator(Eq, mpz, rational);
	Gura_AssignBinaryOperator(Eq, mpq, mpz);
	Gura_AssignBinaryOperator(Eq, mpq, mpq);
	Gura_AssignBinaryOperator(Eq, mpq, mpf);
	Gura_AssignBinaryOperator(Eq, mpq, number);
	Gura_AssignBinaryOperator(Eq, mpq, rational);
	Gura_AssignBinaryOperator(Eq, mpf, mpz);
	Gura_AssignBinaryOperator(Eq, mpf, mpq);
	Gura_AssignBinaryOperator(Eq, mpf, mpf);
	Gura_AssignBinaryOperator(Eq, mpf, number);
	Gura_AssignBinaryOperator(Eq, mpf, rational);
	Gura_AssignBinaryOperator(Eq, number, mpz);
	Gura_AssignBinaryOperator(Eq, number, mpq);
	Gura_AssignBinaryOperator(Eq, number, mpf);
	Gura_AssignBinaryOperator(Eq, rational, mpz);
	Gura_AssignBinaryOperator(Eq, rational, mpq);
	Gura_AssignBinaryOperator(Eq, rational, mpf);
	// binary operator !=
	Gura_AssignBinaryOperator(Ne, mpz, mpz);
	Gura_AssignBinaryOperator(Ne, mpz, mpq);
	Gura_AssignBinaryOperator(Ne, mpz, mpf);
	Gura_AssignBinaryOperator(Ne, mpz, number);
	Gura_AssignBinaryOperator(Ne, mpz, rational);
	Gura_AssignBinaryOperator(Ne, mpq, mpz);
	Gura_AssignBinaryOperator(Ne, mpq, mpq);
	Gura_AssignBinaryOperator(Ne, mpq, mpf);
	Gura_AssignBinaryOperator(Ne, mpq, number);
	Gura_AssignBinaryOperator(Ne, mpq, rational);
	Gura_AssignBinaryOperator(Ne, mpf, mpz);
	Gura_AssignBinaryOperator(Ne, mpf, mpq);
	Gura_AssignBinaryOperator(Ne, mpf, mpf);
	Gura_AssignBinaryOperator(Ne, mpf, number);
	Gura_AssignBinaryOperator(Ne, mpf, rational);
	Gura_AssignBinaryOperator(Ne, number, mpz);
	Gura_AssignBinaryOperator(Ne, number, mpq);
	Gura_AssignBinaryOperator(Ne, number, mpf);
	Gura_AssignBinaryOperator(Ne, rational, mpz);
	Gura_AssignBinaryOperator(Ne, rational, mpq);
	Gura_AssignBinaryOperator(Ne, rational, mpf);
	// binary operator >
	Gura_AssignBinaryOperator(Gt, mpz, mpz);
	Gura_AssignBinaryOperator(Gt, mpz, mpq);
	Gura_AssignBinaryOperator(Gt, mpz, mpf);
	Gura_AssignBinaryOperator(Gt, mpz, number);
	Gura_AssignBinaryOperator(Gt, mpz, rational);
	Gura_AssignBinaryOperator(Gt, mpq, mpz);
	Gura_AssignBinaryOperator(Gt, mpq, mpq);
	Gura_AssignBinaryOperator(Gt, mpq, mpf);
	Gura_AssignBinaryOperator(Gt, mpq, number);
	Gura_AssignBinaryOperator(Gt, mpq, rational);
	Gura_AssignBinaryOperator(Gt, mpf, mpz);
	Gura_AssignBinaryOperator(Gt, mpf, mpq);
	Gura_AssignBinaryOperator(Gt, mpf, mpf);
	Gura_AssignBinaryOperator(Gt, mpf, number);
	Gura_AssignBinaryOperator(Gt, mpf, rational);
	Gura_AssignBinaryOperator(Gt, number, mpz);
	Gura_AssignBinaryOperator(Gt, number, mpq);
	Gura_AssignBinaryOperator(Gt, number, mpf);
	Gura_AssignBinaryOperator(Gt, rational, mpz);
	Gura_AssignBinaryOperator(Gt, rational, mpq);
	Gura_AssignBinaryOperator(Gt, rational, mpf);
	// binary operator <
	Gura_AssignBinaryOperator(Lt, mpz, mpz);
	Gura_AssignBinaryOperator(Lt, mpz, mpq);
	Gura_AssignBinaryOperator(Lt, mpz, mpf);
	Gura_AssignBinaryOperator(Lt, mpz, number);
	Gura_AssignBinaryOperator(Lt, mpz, rational);
	Gura_AssignBinaryOperator(Lt, mpq, mpz);
	Gura_AssignBinaryOperator(Lt, mpq, mpq);
	Gura_AssignBinaryOperator(Lt, mpq, mpf);
	Gura_AssignBinaryOperator(Lt, mpq, number);
	Gura_AssignBinaryOperator(Lt, mpq, rational);
	Gura_AssignBinaryOperator(Lt, mpf, mpz);
	Gura_AssignBinaryOperator(Lt, mpf, mpq);
	Gura_AssignBinaryOperator(Lt, mpf, mpf);
	Gura_AssignBinaryOperator(Lt, mpf, number);
	Gura_AssignBinaryOperator(Lt, mpf, rational);
	Gura_AssignBinaryOperator(Lt, number, mpz);
	Gura_AssignBinaryOperator(Lt, number, mpq);
	Gura_AssignBinaryOperator(Lt, number, mpf);
	Gura_AssignBinaryOperator(Lt, rational, mpz);
	Gura_AssignBinaryOperator(Lt, rational, mpq);
	Gura_AssignBinaryOperator(Lt, rational, mpf);
	// binary operator >=
	Gura_AssignBinaryOperator(Ge, mpz, mpz);
	Gura_AssignBinaryOperator(Ge, mpz, mpq);
	Gura_AssignBinaryOperator(Ge, mpz, mpf);
	Gura_AssignBinaryOperator(Ge, mpz, number);
	Gura_AssignBinaryOperator(Ge, mpz, rational);
	Gura_AssignBinaryOperator(Ge, mpq, mpz);
	Gura_AssignBinaryOperator(Ge, mpq, mpq);
	Gura_AssignBinaryOperator(Ge, mpq, mpf);
	Gura_AssignBinaryOperator(Ge, mpq, number);
	Gura_AssignBinaryOperator(Ge, mpq, rational);
	Gura_AssignBinaryOperator(Ge, mpf, mpz);
	Gura_AssignBinaryOperator(Ge, mpf, mpq);
	Gura_AssignBinaryOperator(Ge, mpf, mpf);
	Gura_AssignBinaryOperator(Ge, mpf, number);
	Gura_AssignBinaryOperator(Ge, mpf, rational);
	Gura_AssignBinaryOperator(Ge, number, mpz);
	Gura_AssignBinaryOperator(Ge, number, mpq);
	Gura_AssignBinaryOperator(Ge, number, mpf);
	Gura_AssignBinaryOperator(Ge, rational, mpz);
	Gura_AssignBinaryOperator(Ge, rational, mpq);
	Gura_AssignBinaryOperator(Ge, rational, mpf);
	// binary operator <=
	Gura_AssignBinaryOperator(Le, mpz, mpz);
	Gura_AssignBinaryOperator(Le, mpz, mpq);
	Gura_AssignBinaryOperator(Le, mpz, mpf);
	Gura_AssignBinaryOperator(Le, mpz, number);
	Gura_AssignBinaryOperator(Le, mpz, rational);
	Gura_AssignBinaryOperator(Le, mpq, mpz);
	Gura_AssignBinaryOperator(Le, mpq, mpq);
	Gura_AssignBinaryOperator(Le, mpq, mpf);
	Gura_AssignBinaryOperator(Le, mpq, number);
	Gura_AssignBinaryOperator(Le, mpq, rational);
	Gura_AssignBinaryOperator(Le, mpf, mpz);
	Gura_AssignBinaryOperator(Le, mpf, mpq);
	Gura_AssignBinaryOperator(Le, mpf, mpf);
	Gura_AssignBinaryOperator(Le, mpf, number);
	Gura_AssignBinaryOperator(Le, mpf, rational);
	Gura_AssignBinaryOperator(Le, number, mpz);
	Gura_AssignBinaryOperator(Le, number, mpq);
	Gura_AssignBinaryOperator(Le, number, mpf);
	Gura_AssignBinaryOperator(Le, rational, mpz);
	Gura_AssignBinaryOperator(Le, rational, mpq);
	Gura_AssignBinaryOperator(Le, rational, mpf);
	// binary operator <=>
	Gura_AssignBinaryOperator(Cmp, mpz, mpz);
	Gura_AssignBinaryOperator(Cmp, mpz, mpq);
	Gura_AssignBinaryOperator(Cmp, mpz, mpf);
	Gura_AssignBinaryOperator(Cmp, mpz, number);
	Gura_AssignBinaryOperator(Cmp, mpz, rational);
	Gura_AssignBinaryOperator(Cmp, mpq, mpz);
	Gura_AssignBinaryOperator(Cmp, mpq, mpq);
	Gura_AssignBinaryOperator(Cmp, mpq, mpf);
	Gura_AssignBinaryOperator(Cmp, mpq, number);
	Gura_AssignBinaryOperator(Cmp, mpq, rational);
	Gura_AssignBinaryOperator(Cmp, mpf, mpz);
	Gura_AssignBinaryOperator(Cmp, mpf, mpq);
	Gura_AssignBinaryOperator(Cmp, mpf, mpf);
	Gura_AssignBinaryOperator(Cmp, mpf, number);
	Gura_AssignBinaryOperator(Cmp, mpf, rational);
	Gura_AssignBinaryOperator(Cmp, number, mpz);
	Gura_AssignBinaryOperator(Cmp, number, mpq);
	Gura_AssignBinaryOperator(Cmp, number, mpf);
	Gura_AssignBinaryOperator(Cmp, rational, mpz);
	Gura_AssignBinaryOperator(Cmp, rational, mpq);
	Gura_AssignBinaryOperator(Cmp, rational, mpf);
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
	// unary operator ..
	Gura_AssignUnaryOperatorSuffix(SeqInf, mpz);
	// binary operator ..
	Gura_AssignBinaryOperator(Seq, mpz, mpz);
}

Gura_EndModuleScope(gmp)
