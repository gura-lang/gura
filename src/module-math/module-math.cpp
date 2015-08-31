//-----------------------------------------------------------------------------
// Gura module: math
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(math)

//-----------------------------------------------------------------------------
// Gura module functions
//-----------------------------------------------------------------------------
// math.real(num):map
Gura_DeclareFunction(real)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a real part of a complex number.");
}

Gura_ImplementFunction(real)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(value.GetNumber());
	} else if (value.Is_complex()) {
		result.SetNumber(value.GetComplex().real());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.imag(num):map
Gura_DeclareFunction(imag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an imaginary part of a complex number.");
}

Gura_ImplementFunction(imag)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(0.);
	} else if (value.Is_complex()) {
		result.SetNumber(value.GetComplex().imag());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.arg(num):map:[deg]
Gura_DeclareFunction(arg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an argument value of a complex number in radian.");
}

Gura_ImplementFunction(arg)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	double result = 0;
	if (value.Is_number()) {
		// nothing to do
	} else if (value.Is_complex()) {
		result = std::arg(value.GetComplex());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
		return Value::Nil;
	}
	if (arg.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

// math.norm(num):map
Gura_DeclareFunction(norm)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a norm value of a complex number.");
}

Gura_ImplementFunction(norm)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(value.GetNumber() * value.GetNumber());
	} else if (value.Is_complex()) {
		result.SetNumber(std::norm(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.conj(num):map
Gura_DeclareFunction(conj)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a conjugate of a complex number.");
}

Gura_ImplementFunction(conj)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(value.GetNumber());
	} else if (value.Is_complex()) {
		result.SetComplex(std::conj(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.acos(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(acos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an inverse cosine value.");
}

Gura_ImplementFunction(acos)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	double result = 0;
	if (value.Is_number()) {
		result = ::acos(value.GetNumber());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
		return Value::Nil;
	}
	if (arg.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementMathDiff(acos)
{
	// acos(x)' = -1 / sqrt(1 - x ** 2)
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(-1),
		Expr_Caller::Create(
			Gura_Symbol(math), Gura_Symbol(sqrt),
			new Expr_BinaryOp(
				env.GetOperator(OPTYPE_Sub),
				new Expr_Value(1),
				new Expr_BinaryOp(
					env.GetOperator(OPTYPE_Pow),
					pExprArg->Clone(),
					new Expr_Value(2)))));
}

// math.asin(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(asin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an inverse sine value.");
}

Gura_ImplementFunction(asin)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	double result = 0;
	if (value.Is_number()) {
		result = ::asin(value.GetNumber());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
		return Value::Nil;
	}
	if (arg.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementMathDiff(asin)
{
	// asin(x)' = 1 / sqrt(1 - x ** 2)
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(1),
		Expr_Caller::Create(
			Gura_Symbol(math), Gura_Symbol(sqrt),
			new Expr_BinaryOp(
				env.GetOperator(OPTYPE_Sub),
				new Expr_Value(1),
				new Expr_BinaryOp(
					env.GetOperator(OPTYPE_Pow),
					pExprArg->Clone(),
					new Expr_Value(2)))));
}

// math.atan(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(atan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an inverse tangent value.");
}

Gura_ImplementFunction(atan)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	double result = 0;
	if (value.Is_number()) {
		result = ::atan(value.GetNumber());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
		return Value::Nil;
	}
	if (arg.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementMathDiff(atan)
{
	// atan(x)' = 1 / (1 + x ** 2)
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(1),
		new Expr_BinaryOp(
			env.GetOperator(OPTYPE_Add),
			new Expr_Value(1),
			new Expr_BinaryOp(
				env.GetOperator(OPTYPE_Pow),
				pExprArg->Clone(),
				new Expr_Value(2))));
}

// math.atan2(num1, num2):map:[deg]
Gura_DeclareFunction(atan2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num1", VTYPE_any);
	DeclareArg(env, "num2", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an inverse tangent value of a fraction of num1 and num2.");
}

Gura_ImplementFunction(atan2)
{
	Signal &sig = env.GetSignal();
	const Value &value1 = arg.GetValue(0);
	const Value &value2 = arg.GetValue(1);
	double result = 0;
	if (value1.Is_number() && value2.Is_number()) {
		result = ::atan2(value1.GetNumber(), value2.GetNumber());
	} else if (value1.IsValid() && value2.IsValid()) {
		SetError_InvalidValType(sig, value1, value2);
		return Value::Nil;
	}
	if (arg.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

// math.ceil(num):map
Gura_DeclareFunction(ceil)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a nearest integer number above or equal to the specified value.");
}

Gura_ImplementFunction(ceil)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(::ceil(value.GetNumber()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.cos(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(cos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a cosine value.");
}

Gura_ImplementFunction(cos)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		double num = value.GetNumber();
		if (arg.IsSet(Gura_Symbol(deg))) num = DegToRad(num);
		result.SetNumber(::cos(num));
	} else if (value.Is_complex()) {
		result.SetComplex(std::cos(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementMathDiff(cos)
{
	// cos(x)' = -sin(x)
	return new Expr_UnaryOp(
		env.GetOperator(OPTYPE_Neg),
		Expr_Caller::Create(
			Gura_Symbol(math), Gura_Symbol(sin),
			pExprArg->Clone()),
		false);
}

// math.cosh(num):map
Gura_DeclareFunction(cosh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a hyperbolic cosine value.");
}

Gura_ImplementFunction(cosh)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(::cosh(value.GetNumber()));
	} else if (value.Is_complex()) {
		result.SetComplex(std::cosh(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.exp(num):map
Gura_DeclareFunctionWithMathDiff(exp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an exponential value.");
}

Gura_ImplementFunction(exp)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(::exp(value.GetNumber()));
	} else if (value.Is_complex()) {
		result.SetComplex(std::exp(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementMathDiff(exp)
{
	// exp(x)' = exp(x)
	return Expr_Caller::Create(
		Gura_Symbol(math), Gura_Symbol(exp),
		pExprArg->Clone());
}

// math.abs(num):map
Gura_DeclareFunction(abs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an absolute value.");
}

Gura_ImplementFunction(abs)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(::fabs(value.GetNumber()));
	} else if (value.Is_complex()) {
		result.SetComplex(std::abs(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.floor(num):map
Gura_DeclareFunction(floor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a nearest integer number below or equal to the specified value.");
}

Gura_ImplementFunction(floor)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(::floor(value.GetNumber()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.log(num):map
Gura_DeclareFunctionWithMathDiff(log)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a natural logarithm value.");
}

Gura_ImplementFunction(log)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		if (value.GetNumber() > 0.) {
			result.SetNumber(::log(value.GetNumber()));
		} else {
			SetError_InvalidValue(sig, value);
		}
	} else if (value.Is_complex()) {
		result.SetComplex(std::log(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementMathDiff(log)
{
	// log(x)' = 1 / x
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(1),
		pExprArg->Clone());
}

// math.log10(num):map
Gura_DeclareFunctionWithMathDiff(log10)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a decadic logarithm value.");
}

Gura_ImplementFunction(log10)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		if (value.GetNumber() > 0.) {
			result.SetNumber(::log10(value.GetNumber()));
		} else {
			SetError_InvalidValue(sig, value);
		}
	} else if (value.Is_complex()) {
		result.SetComplex(std::log10(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementMathDiff(log10)
{
	// log10(x)' = 1 / (x * log(10))
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div), new Expr_Value(1),
		new Expr_BinaryOp(
			env.GetOperator(OPTYPE_Mul),
			pExprArg->Clone(),
			Expr_Caller::Create(
				Gura_Symbol(math), Gura_Symbol(log),
				new Expr_Value(10))));
}

// math.sin(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(sin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a sine value.");
}

Gura_ImplementFunction(sin)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		double num = value.GetNumber();
		if (arg.IsSet(Gura_Symbol(deg))) num = DegToRad(num);
		result.SetNumber(::sin(num));
	} else if (value.Is_complex()) {
		result.SetComplex(std::sin(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementMathDiff(sin)
{
	// sin(x)' = cos(x)
	return Expr_Caller::Create(
		Gura_Symbol(math), Gura_Symbol(cos),
		pExprArg->Clone());
}

// math.sinh(num):map
Gura_DeclareFunction(sinh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a hyperbolic sine value.");
}

Gura_ImplementFunction(sinh)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(::sinh(value.GetNumber()));
	} else if (value.Is_complex()) {
		result.SetComplex(std::sinh(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.sqrt(num):map
Gura_DeclareFunctionWithMathDiff(sqrt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a square root value.");
}

Gura_ImplementFunction(sqrt)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		if (value.GetNumber() >= 0) {
			result.SetNumber(::sqrt(value.GetNumber()));
		} else {
			result.SetComplex(Complex(0, ::sqrt(-value.GetNumber())));
		}
	} else if (value.Is_complex()) {
		result.SetComplex(std::sqrt(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementMathDiff(sqrt)
{
	// sqrt(x)' = 1 / (2 * sqrt(x))
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(1),
		new Expr_BinaryOp(
			env.GetOperator(OPTYPE_Mul),
			new Expr_Value(2),
			Expr_Caller::Create(
				Gura_Symbol(math), Gura_Symbol(sqrt),
				pExprArg->Clone())));
}

// math.tan(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(tan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a tangent value.");
}

Gura_ImplementFunction(tan)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		double num = value.GetNumber();
		if (arg.IsSet(Gura_Symbol(deg))) num = DegToRad(num);
		result.SetNumber(::tan(num));
	} else if (value.Is_complex()) {
		result.SetComplex(std::tan(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementMathDiff(tan)
{
	// tan(x)' = 1 / cos(x) ** 2
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(1),
		new Expr_BinaryOp(
			env.GetOperator(OPTYPE_Pow),
			Expr_Caller::Create(
				Gura_Symbol(math), Gura_Symbol(cos),
				pExprArg->Clone()),
			new Expr_Value(2)));
}

// math.tanh(num):map
Gura_DeclareFunction(tanh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a hyperbolic tangent value.");
}

Gura_ImplementFunction(tanh)
{
	Signal &sig = env.GetSignal();
	const Value &value = arg.GetValue(0);
	Value result;
	if (value.Is_number()) {
		result.SetNumber(::tanh(value.GetNumber()));
	} else if (value.Is_complex()) {
		result.SetComplex(std::tanh(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.hypot(x, y):map
Gura_DeclareFunction(hypot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_any);
	DeclareArg(env, "y", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a hyperbolic tangent value.");
}

Gura_ImplementFunction(hypot)
{
	Signal &sig = env.GetSignal();
	const Value &x = arg.GetValue(0);
	const Value &y = arg.GetValue(1);
	Value result;
	if (x.Is_number() && y.Is_number()) {
		result.SetNumber(::hypot(x.GetNumber(), y.GetNumber()));
	} else if (x.IsValid() || y.IsValid()) {
		SetError_InvalidValType(sig, x, y);
	}
	return result;
}

// math.least_square(x:iterator, y:iterator, dim:number = 1, var:symbol = `x)
Gura_DeclareFunction(least_square)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_iterator);
	DeclareArg(env, "y", VTYPE_iterator);
	DeclareArg(env, "dim", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(1));
	DeclareArg(env, "var", VTYPE_symbol, OCCUR_Once, FLAG_None, new Expr_Value(Gura_Symbol(x)));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Calculates a least square method using a sequence of pairs of `x` and `y`,\n"
		"and returns an expression of the fitted curve. You can specify the dimension\n"
		"by an argument `dim`. In default, a symbol of the expression's variable is `x\n"
		"and it can be changed by specifying an argument `var`.");
}

Gura_ImplementFunction(least_square)
{
	Signal &sig = env.GetSignal();
	size_t nDim = arg.GetSizeT(2);
	if (nDim == 0) {
		sig.SetError(ERR_ValueError, "invalid dimension");
		return Value::Nil;
	}
	size_t nCols = nDim + 1;
	size_t nRows = nCols;
	Iterator *pIterX = arg.GetIterator(0);
	Iterator *pIterY = arg.GetIterator(1);
	const Symbol *pSymbolVar = arg.GetSymbol(3);
	NumberList sumListXX(nCols * 2, 0), sumListXY(nCols, 0);
	bool flagX = false, flagY = false;
	for (;;) {
		Value valueX, valueY;
		flagX = pIterX->Next(env, valueX);
		if (sig.IsSignalled()) return Value::Nil;
		flagY = pIterY->Next(env, valueY);
		if (sig.IsSignalled()) return Value::Nil;
		if (!(flagX && flagY)) break;
		if (!valueX.Is_number()) {
			sig.SetError(ERR_ValueError, "cannot calculate non-number value");
			return Value::Nil;
		}
		if (!valueY.Is_number()) {
			sig.SetError(ERR_ValueError, "cannot calculate non-number value");
			return Value::Nil;
		}
		Number numX = valueX.GetNumber(), numY = valueY.GetNumber();
		Number productX = 1;
		NumberList::iterator pSumXX = sumListXX.begin();
		NumberList::iterator pSumXY = sumListXY.begin();
		for ( ; pSumXY != sumListXY.end(); pSumXX++, pSumXY++) {
			*pSumXX += productX;
			*pSumXY += productX * numY;
			productX *= numX;
		}
		for ( ; pSumXX != sumListXX.end(); pSumXX++) {
			*pSumXX += productX;
			productX *= numX;
		}
	}
	if (flagX || flagY) {
		sig.SetError(ERR_ValueError, "number of x and y must be the same");
		return Value::Nil;
	}
	NumberList mat;
	mat.reserve(nCols * nRows * 2);
	NumberList::iterator pSumXXBase = sumListXX.begin();
	for (size_t iRow = 0; iRow < nRows; iRow++, pSumXXBase++) {
		NumberList::iterator pSumXX = pSumXXBase;
		for (size_t iCol = 0; iCol < nCols; iCol++, pSumXX++) {
			mat.push_back(*pSumXX);
		}
		for (size_t iCol = 0; iCol < nCols; iCol++) {
			mat.push_back((iCol == iRow)? 1. : 0.);
		}
	}
	Number det;
	if (!Gura::InvertMatrix(mat, nCols, det)) {
		sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
		return Value::Nil;
	}
	NumberList alphaList;
	alphaList.reserve(nCols);
	//NumberList::iterator pMat = mat.begin() + nCols;
	size_t offset = nCols;
	for (size_t iRow = 0; iRow < nRows; iRow++) {
		Number alpha = 0;
		NumberList::iterator pSumXY = sumListXY.begin();
		for (size_t iCol = 0; iCol < nCols; iCol++, offset++, pSumXY++) {
			alpha += mat[offset] * *pSumXY;
		}
		alphaList.push_back(alpha);
		offset += nCols;
	}
	Value result;
	do {
		NumberList::iterator pAlpha = alphaList.begin();
		Expr *pExpr = new Expr_Value(*pAlpha);
		pAlpha++;
		Expr *pExprLeft = new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul),
			new Expr_Value(*pAlpha),
			new Expr_Identifier(pSymbolVar));
		pAlpha++;
		pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExpr, pExprLeft);
		for ( ; pAlpha != alphaList.end(); pAlpha++) {
			size_t n = pAlpha - alphaList.begin();
			pExprLeft = new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul),
				new Expr_Value(*pAlpha),
				new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow),
					new Expr_Identifier(pSymbolVar),
					new Expr_Value(n)));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExpr, pExprLeft);
		}
		Function *pFunc = new FunctionCustom(env,
							Gura_Symbol(_anonymous_), pExpr, FUNCTYPE_Function);
		pFunc->SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
		pFunc->DeclareArg(env, pSymbolVar, VTYPE_number);
		result = Value(new Object_function(env, pFunc));
	} while (0);
	return result;
}

// math.bezier(nums[]+:number)
class Func_BezierPrototype : public Function {
private:
	NumberList _nums;
public:
	Func_BezierPrototype(Environment &env, const ValueList &nums);
	virtual Value DoEval(Environment &env, Argument &arg) const;
};

Func_BezierPrototype::Func_BezierPrototype(Environment &env, const ValueList &nums) :
				Function(env, Gura_Symbol(_anonymous_), FUNCTYPE_Function, FLAG_None)
{
	_nums.reserve(nums.size());
	if (nums.size() == 3) {
		Number num0 = nums[0].GetNumber();
		Number num1 = nums[1].GetNumber();
		Number num2 = nums[2].GetNumber();
		_nums.push_back(num0);
		_nums.push_back(2 * num1 - 2 * num0);
		_nums.push_back(num2 - 2 * num1 + num0);
	} else if (nums.size() == 4) {
		Number num0 = nums[0].GetNumber();
		Number num1 = nums[1].GetNumber();
		Number num2 = nums[2].GetNumber();
		Number num3 = nums[3].GetNumber();
		_nums.push_back(num0);
		_nums.push_back(3 * num1 - 3 * num0);
		_nums.push_back(3 * num2 - 6 * num1 + 3 * num0);
		_nums.push_back(num3 - 3 * num2 + 3 * num1 - num0);
	} else {
		foreach_const (ValueList, pValue, nums) {
			_nums.push_back(pValue->GetNumber());
		}
	}
}

Value Func_BezierPrototype::DoEval(Environment &env, Argument &arg) const
{
	Number t = arg.GetNumber(0);
	if (_nums.size() == 2) {
		return Value(_nums[0] * (1 - t) + _nums[1] * t);
	} else if (_nums.size() == 3) {
		Number tt = t;
		Number result = _nums[0];
		result += _nums[1] * tt, tt *= t;
		result += _nums[2] * tt;
		return Value(result);
	} else if (_nums.size() == 4) {
		Number tt = t;
		Number result = _nums[0];
		result += _nums[1] * tt, tt *= t;
		result += _nums[2] * tt, tt *= t;
		result += _nums[3] * tt;
		return Value(result);
	} else {
		NumberList numsFace, numsBack;
		numsFace.reserve(_nums.size() - 1);
		numsBack.reserve(_nums.size() - 1);
		const NumberList *pnums = &_nums;
		NumberList *pnumsWk = &numsFace;
		bool flipFlag = false;
		for (size_t len = pnums->size(); len > 1; len--, flipFlag = !flipFlag) {
			NumberList::const_iterator p = pnums->begin();
			pnumsWk->clear();
			for (size_t n = pnums->size(); n > 1; n--, p++) {
				pnumsWk->push_back(*p * (1 - t) + *(p + 1) * t);
			}
			if (flipFlag) {
				pnums = &numsBack, pnumsWk = &numsFace;
			} else {
				pnums = &numsFace, pnumsWk = &numsBack;
			}
		}
		return Value(pnums->front());
	}
}

Gura_DeclareFunction(bezier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nums", VTYPE_number, OCCUR_OnceOrMore, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a list that consists of functions that generate coordinates of bezier\n"
		"curves with specified control points. One or more lists of control points can\n"
		"be specified. This means that if you give it two lists of numbers as arguments,\n"
		"it returns two functions of bezier curve.");
}

Gura_ImplementFunction(bezier)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		Function *pFunc = new Func_BezierPrototype(env, pValue->GetList());
		pFunc->SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
		pFunc->DeclareArg(env, "t", VTYPE_number);
		valList.push_back(Value(new Object_function(env, pFunc)));
	}
	return result;
}

// math.diff(expr:expr, var:symbol):map {block?}
Gura_DeclareFunction(diff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr);
	DeclareArg(env, "var", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a mathematical differential expression of the given `expr`\n"
		"by a variable `var`.\n"
		"\n"
		"Example: `math.diff(`(math.sin(x ** 2)), `x)`\n");
}

Gura_ImplementFunction(diff)
{
	Signal &sig = env.GetSignal();
	Expr *pExprDiff = arg.GetExpr(0)->MathDiff(env, arg.GetSymbol(1));
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_expr(env, pExprDiff)));
}

// math.optimize(expr:expr):map {block?}
Gura_DeclareFunction(optimize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(optimize)
{
	Signal &sig = env.GetSignal();
	Expr *pExprOpt = arg.GetExpr(0)->MathOptimize(env);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_expr(env, pExprOpt)));
}

// math.fft(seq[])
Gura_DeclareFunction(fft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "seq", VTYPE_any, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(fft)
{
	
	return Value::Nil;
}

// math.integral(func, sequence)
Gura_DeclareFunction(integral)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(integral)
{
	return Value::Nil;
}

// math.dot_product(a[], b[])
Gura_DeclareFunction(dot_product)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_any, OCCUR_Once, FLAG_List);
	DeclareArg(env, "b", VTYPE_any, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(dot_product)
{
	Signal &sig = env.GetSignal();
	const ValueList &valList1 = arg.GetList(0);
	const ValueList &valList2 = arg.GetList(1);
	if (valList1.size() != valList2.size()) {
		sig.SetError(ERR_ValueError, "different length of lists");
		return Value::Nil;
	}
	ValueList::const_iterator pValue1 = valList1.begin();
	ValueList::const_iterator pValue2 = valList2.begin();
	Value valueSum(0);
	for ( ; pValue1 != valList1.end(); pValue1++, pValue2++) {
		Value value;
		do {
			value = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, *pValue1, *pValue2);
			if (sig.IsSignalled()) return Value::Nil;
		} while (0);
		do {
			valueSum = env.GetOperator(OPTYPE_Add)->EvalBinary(env, valueSum, value);
			if (sig.IsSignalled()) return Value::Nil;
		} while (0);
	}
	return valueSum;
}

// math.cross_product(a[], b[])
static Value CalcCrossElem(Environment &env,
		const Value &ax, const Value &ay, const Value &bx, const Value &by);

Gura_DeclareFunction(cross_product)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_any, OCCUR_Once, FLAG_List);
	DeclareArg(env, "b", VTYPE_any, OCCUR_Once, FLAG_List);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(cross_product)
{
	Signal &sig = env.GetSignal();
	const ValueList &valList1 = arg.GetList(0);
	const ValueList &valList2 = arg.GetList(1);
	if (valList1.size() != valList2.size()) {
		sig.SetError(ERR_ValueError, "different length of lists");
		return Value::Nil;
	}
	if (valList1.size() == 2) {
		return CalcCrossElem(env, valList1[0], valList1[1], valList2[0], valList2[1]);
	} else if (valList1.size() == 3) {
		Value result;
		ValueList &valList = result.InitAsList(env);
		valList.reserve(3);
		Value value;
		value = CalcCrossElem(env, valList1[1], valList1[2], valList2[1], valList2[2]);
		if (sig.IsSignalled()) return Value::Nil;
		valList.push_back(value);
		value = CalcCrossElem(env, valList1[2], valList1[0], valList2[2], valList2[0]);
		if (sig.IsSignalled()) return Value::Nil;
		valList.push_back(value);
		value = CalcCrossElem(env, valList1[0], valList1[1], valList2[0], valList2[1]);
		if (sig.IsSignalled()) return Value::Nil;
		valList.push_back(value);
		return result;
	} else {
		sig.SetError(ERR_ValueError,
				"only support two or three dimension vector for cross product");
		return Value::Nil;
	}
}

Value CalcCrossElem(Environment &env,
		const Value &ax, const Value &ay, const Value &bx, const Value &by)
{
	Signal &sig = env.GetSignal();
	Value valueLeft;
	do {
		valueLeft = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, ax, by);
		if (sig.IsSignalled()) return Value::Nil;
	} while (0);
	Value valueRight;
	do {
		valueRight = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, ay, bx);
		if (sig.IsSignalled()) return Value::Nil;
	} while (0);
	Value value;
	do {
		value = env.GetOperator(OPTYPE_Sub)->EvalBinary(env, valueLeft, valueRight);
		if (sig.IsSignalled()) return Value::Nil;
	} while (0);
	return value;
}

// math.covariance(a:iterator, b:iterator)
Gura_DeclareFunction(covariance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_iterator);
	DeclareArg(env, "b", VTYPE_iterator);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a covariance between the sequences of values.");
}

Gura_ImplementFunction(covariance)
{
	Signal &sig = env.GetSignal();
	size_t cntA, cntB;
	Iterator *pIteratorA = arg.GetIterator(0);
	Iterator *pIteratorB = arg.GetIterator(1);
	Value valueAveA = pIteratorA->Clone()->Average(env, cntA);
	if (!valueAveA.Is_number()) return Value::Nil;
	Value valueAveB = pIteratorB->Clone()->Average(env, cntB);
	if (!valueAveB.Is_number()) return Value::Nil;
	if (cntA != cntB) {
		sig.SetError(ERR_ValueError, "different length of iterators");
		return Value::Nil;
	}
	Number result = 0;
	Number averageA = valueAveA.GetNumber();
	Number averageB = valueAveB.GetNumber();
	Value valueA, valueB;
	while (pIteratorA->Next(env, valueA) && pIteratorB->Next(env, valueB)) {
		if (valueA.Is_number() && valueB.Is_number()) {
			result +=
				(valueA.GetNumber() - averageA) * (valueB.GetNumber() - averageB);
		} else {
			sig.SetError(ERR_ValueError, "invalid data type of element");
			return Value::Nil;
		}
	}
	if (sig.IsSignalled()) return Value::Nil;
	return Value(result / static_cast<Number>(cntA));
}

// math.gcd(a:number, b+:number):map
Gura_DeclareFunction(gcd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a greatest common divisor among two or more numbers.");
}

Gura_ImplementFunction(gcd)
{
	const ValueList &valList = arg.GetList(1);
	ValueList::const_iterator pValue = valList.begin();
	int gcd = CalcGCD(arg.GetInt(0), pValue->GetInt());
	pValue++;
	for ( ; pValue != valList.end(); pValue++) {
		gcd = CalcGCD(gcd, pValue->GetInt());
	}
	return Value(gcd);
}

// math.lcm(a:number, b+:number):map
Gura_DeclareFunction(lcm)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a least common multiple among two or more numbers.");
}

Gura_ImplementFunction(lcm)
{
	const ValueList &valList = arg.GetList(1);
	ValueList::const_iterator pValue = valList.begin();
	int lcm = CalcLCM(arg.GetInt(0), pValue->GetInt());
	pValue++;
	for ( ; pValue != valList.end(); pValue++) {
		lcm = CalcLCM(lcm, pValue->GetInt());
	}
	return Value(lcm);
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// value assignment
	Gura_AssignValue(e,		Value(Math_E));
	Gura_AssignValue(pi,	Value(Math_PI));
	// function assignment
	Gura_AssignFunction(real);
	Gura_AssignFunction(imag);
	Gura_AssignFunction(arg);
	Gura_AssignFunction(norm);
	Gura_AssignFunction(conj);
	Gura_AssignFunction(acos);
	Gura_AssignFunction(asin);
	Gura_AssignFunction(atan);
	Gura_AssignFunction(atan2);
	Gura_AssignFunction(ceil);
	Gura_AssignFunction(cos);
	Gura_AssignFunction(cosh);
	Gura_AssignFunction(exp);
	Gura_AssignFunction(abs);
	Gura_AssignFunction(floor);
	Gura_AssignFunction(log);
	Gura_AssignFunction(log10);
	Gura_AssignFunction(sin);
	Gura_AssignFunction(sinh);
	Gura_AssignFunction(sqrt);
	Gura_AssignFunction(tan);
	Gura_AssignFunction(tanh);
	Gura_AssignFunction(hypot);
	Gura_AssignFunction(least_square);
	Gura_AssignFunction(bezier);
	Gura_AssignFunction(diff);
	Gura_AssignFunction(optimize);
	Gura_AssignFunction(fft);
	Gura_AssignFunction(dot_product);
	Gura_AssignFunction(cross_product);
	Gura_AssignFunction(covariance);
	Gura_AssignFunction(integral);
	Gura_AssignFunction(gcd);
	Gura_AssignFunction(lcm);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------

Gura_EndModuleBody(math, math)

Gura_RegisterModule(math)
