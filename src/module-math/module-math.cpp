//-----------------------------------------------------------------------------
// Gura math module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(math)

//-----------------------------------------------------------------------------
// Gura module functions
//-----------------------------------------------------------------------------
// math.real(num):map
Gura_DeclareFunction(real)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a real part of a complex number.");
}

Gura_ImplementFunction(real)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(value.GetNumber());
	} else if (value.IsComplex()) {
		result.SetNumber(value.GetComplex().real());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.imag(num):map
Gura_DeclareFunction(imag)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an imaginary part of a complex number.");
}

Gura_ImplementFunction(imag)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(0.);
	} else if (value.IsComplex()) {
		result.SetNumber(value.GetComplex().imag());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.arg(num):map:[deg]
Gura_DeclareFunction(arg)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an argument value of a complex number in radian.");
}

Gura_ImplementFunction(arg)
{
	const Value &value = args.GetValue(0);
	double result = 0;
	if (value.IsNumber()) {
		// nothing to do
	} else if (value.IsComplex()) {
		result = std::arg(value.GetComplex());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
		return Value::Null;
	}
	if (args.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

// math.norm(num):map
Gura_DeclareFunction(norm)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a norm value of a complex number.");
}

Gura_ImplementFunction(norm)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(value.GetNumber() * value.GetNumber());
	} else if (value.IsComplex()) {
		result.SetNumber(std::norm(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.conj(num):map
Gura_DeclareFunction(conj)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a conjugate of a complex number.");
}

Gura_ImplementFunction(conj)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(value.GetNumber());
	} else if (value.IsComplex()) {
		result.SetComplex(std::conj(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.acos(num):map:[deg]
Gura_DeclareFunctionWithDiffUnary(acos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an inverse cosine value.");
}

Gura_ImplementFunction(acos)
{
	const Value &value = args.GetValue(0);
	double result = 0;
	if (value.IsNumber()) {
		result = ::acos(value.GetNumber());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
		return Value::Null;
	}
	if (args.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementDiffUnary(acos)
{
	// acos(x)' = -1 / sqrt(1 - x ** 2)
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), new Expr_Value(-1),
			CreateExprCaller(Gura_Symbol(sqrt), new Expr_BinaryOp(env.GetOperator(OPTYPE_Sub),
					new Expr_Value(1),
					new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow),
							Expr::Reference(pExprArg), new Expr_Value(2)))));
}

// math.asin(num):map:[deg]
Gura_DeclareFunctionWithDiffUnary(asin)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an inverse sine value.");
}

Gura_ImplementFunction(asin)
{
	const Value &value = args.GetValue(0);
	double result = 0;
	if (value.IsNumber()) {
		result = ::asin(value.GetNumber());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
		return Value::Null;
	}
	if (args.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementDiffUnary(asin)
{
	// asin(x)' = 1 / sqrt(1 - x ** 2)
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), new Expr_Value(1),
			CreateExprCaller(Gura_Symbol(sqrt), new Expr_BinaryOp(env.GetOperator(OPTYPE_Sub),
					new Expr_Value(1),
					new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow),
							Expr::Reference(pExprArg), new Expr_Value(2)))));
}

// math.atan(num):map:[deg]
Gura_DeclareFunctionWithDiffUnary(atan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an inverse tangent value.");
}

Gura_ImplementFunction(atan)
{
	const Value &value = args.GetValue(0);
	double result = 0;
	if (value.IsNumber()) {
		result = ::atan(value.GetNumber());
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
		return Value::Null;
	}
	if (args.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

Gura_ImplementDiffUnary(atan)
{
	// atan(x)' = 1 / (1 + x ** 2)
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), new Expr_Value(1),
			new Expr_BinaryOp(env.GetOperator(OPTYPE_Add),
					new Expr_Value(1),
					new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow),
							Expr::Reference(pExprArg), new Expr_Value(2))));
}

// math.atan2(num1, num2):map:[deg]
Gura_DeclareFunction(atan2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num1", VTYPE_any);
	DeclareArg(env, "num2", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an inverse tangent value of a fraction of num1 and num2.");
}

Gura_ImplementFunction(atan2)
{
	const Value &value1 = args.GetValue(0);
	const Value &value2 = args.GetValue(1);
	double result = 0;
	if (value1.IsNumber() && value2.IsNumber()) {
		result = ::atan2(value1.GetNumber(), value2.GetNumber());
	} else if (value1.IsValid() && value2.IsValid()) {
		SetError_InvalidValType(sig, value1, value2);
		return Value::Null;
	}
	if (args.IsSet(Gura_Symbol(deg))) result = RadToDeg(result);
	return Value(result);
}

// math.ceil(num):map
Gura_DeclareFunction(ceil)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a nearest integer number above or equal to the specified value.");
}

Gura_ImplementFunction(ceil)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(::ceil(value.GetNumber()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.cos(num):map:[deg]
Gura_DeclareFunctionWithDiffUnary(cos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a cosine value.");
}

Gura_ImplementFunction(cos)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		double num = value.GetNumber();
		if (args.IsSet(Gura_Symbol(deg))) num = DegToRad(num);
		result.SetNumber(::cos(num));
	} else if (value.IsComplex()) {
		result.SetComplex(std::cos(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementDiffUnary(cos)
{
	// cos(x)' = -sin(x)
	return new Expr_UnaryOp(env.GetOperator(OPTYPE_Neg),
			CreateExprCaller(Gura_Symbol(sin), Expr::Reference(pExprArg)), false);
}

// math.cosh(num):map
Gura_DeclareFunction(cosh)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a hyperbolic cosine value.");
}

Gura_ImplementFunction(cosh)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(::cosh(value.GetNumber()));
	} else if (value.IsComplex()) {
		result.SetComplex(std::cosh(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.exp(num):map
Gura_DeclareFunctionWithDiffUnary(exp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an exponential value.");
}

Gura_ImplementFunction(exp)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(::exp(value.GetNumber()));
	} else if (value.IsComplex()) {
		result.SetComplex(std::exp(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementDiffUnary(exp)
{
	// exp(x)' = exp(x)
	return CreateExprCaller(Gura_Symbol(exp), Expr::Reference(pExprArg));
}

// math.abs(num):map
Gura_DeclareFunction(abs)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns an absolute value.");
}

Gura_ImplementFunction(abs)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(::fabs(value.GetNumber()));
	} else if (value.IsComplex()) {
		result.SetComplex(std::abs(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.floor(num):map
Gura_DeclareFunction(floor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a nearest integer number below or equal to the specified value.");
}

Gura_ImplementFunction(floor)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(::floor(value.GetNumber()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.log(num):map
Gura_DeclareFunctionWithDiffUnary(log)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a natural logarithm value.");
}

Gura_ImplementFunction(log)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		if (value.GetNumber() > 0.) {
			result.SetNumber(::log(value.GetNumber()));
		} else {
			SetError_InvalidValue(sig, value);
		}
	} else if (value.IsComplex()) {
		result.SetComplex(std::log(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementDiffUnary(log)
{
	// log(x)' = 1 / x
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div),
							new Expr_Value(1), Expr::Reference(pExprArg));
}

// math.log10(num):map
Gura_DeclareFunctionWithDiffUnary(log10)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a decadic logarithm value.");
}

Gura_ImplementFunction(log10)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		if (value.GetNumber() > 0.) {
			result.SetNumber(::log10(value.GetNumber()));
		} else {
			SetError_InvalidValue(sig, value);
		}
	} else if (value.IsComplex()) {
		result.SetComplex(std::log10(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementDiffUnary(log10)
{
	// log10(x)' = 1 / (x * log(10))
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), new Expr_Value(1),
			new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul),
				Expr::Reference(pExprArg), CreateExprCaller(Gura_Symbol(log), new Expr_Value(10))));
}

// math.sin(num):map:[deg]
Gura_DeclareFunctionWithDiffUnary(sin)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a sine value.");
}

Gura_ImplementFunction(sin)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		double num = value.GetNumber();
		if (args.IsSet(Gura_Symbol(deg))) num = DegToRad(num);
		result.SetNumber(::sin(num));
	} else if (value.IsComplex()) {
		result.SetComplex(std::sin(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementDiffUnary(sin)
{
	// sin(x)' = cos(x)
	return CreateExprCaller(Gura_Symbol(cos), Expr::Reference(pExprArg));
}

// math.sinh(num):map
Gura_DeclareFunction(sinh)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a hyperbolic sine value.");
}

Gura_ImplementFunction(sinh)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(::sinh(value.GetNumber()));
	} else if (value.IsComplex()) {
		result.SetComplex(std::sinh(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.sqrt(num):map
Gura_DeclareFunctionWithDiffUnary(sqrt)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a square root value.");
}

Gura_ImplementFunction(sqrt)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		if (value.GetNumber() >= 0) {
			result.SetNumber(::sqrt(value.GetNumber()));
		} else {
			result.SetComplex(Complex(0, ::sqrt(-value.GetNumber())));
		}
	} else if (value.IsComplex()) {
		result.SetComplex(std::sqrt(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementDiffUnary(sqrt)
{
	// sqrt(x)' = 1 / (2 * sqrt(x))
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), new Expr_Value(1),
			new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul),
					new Expr_Value(2),
					CreateExprCaller(Gura_Symbol(sqrt), Expr::Reference(pExprArg))));
}

// math.tan(num):map:[deg]
Gura_DeclareFunctionWithDiffUnary(tan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a tangent value.");
}

Gura_ImplementFunction(tan)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		double num = value.GetNumber();
		if (args.IsSet(Gura_Symbol(deg))) num = DegToRad(num);
		result.SetNumber(::tan(num));
	} else if (value.IsComplex()) {
		result.SetComplex(std::tan(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

Gura_ImplementDiffUnary(tan)
{
	// tan(x)' = 1 / cos(x) ** 2
	return new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), new Expr_Value(1),
			new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow),
					CreateExprCaller(Gura_Symbol(cos), Expr::Reference(pExprArg)),
					new Expr_Value(2)));
}

// math.tanh(num):map
Gura_DeclareFunction(tanh)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a hyperbolic tangent value.");
}

Gura_ImplementFunction(tanh)
{
	const Value &value = args.GetValue(0);
	Value result;
	if (value.IsNumber()) {
		result.SetNumber(::tanh(value.GetNumber()));
	} else if (value.IsComplex()) {
		result.SetComplex(std::tanh(value.GetComplex()));
	} else if (value.IsValid()) {
		SetError_InvalidValType(sig, value);
	}
	return result;
}

// math.hypot(x, y):map
Gura_DeclareFunction(hypot)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_any);
	DeclareArg(env, "y", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a hyperbolic tangent value.");
}

Gura_ImplementFunction(hypot)
{
	const Value &x = args.GetValue(0);
	const Value &y = args.GetValue(1);
	Value result;
	if (x.IsNumber() && y.IsNumber()) {
		result.SetNumber(::hypot(x.GetNumber(), y.GetNumber()));
	} else if (x.IsValid() || y.IsValid()) {
		SetError_InvalidValType(sig, x, y);
	}
	return result;
}

// math.least_square(x:iterator, y:iterator, dim:number = 1, var:symbol = `x)
Gura_DeclareFunction(least_square)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_iterator);
	DeclareArg(env, "y", VTYPE_iterator);
	DeclareArg(env, "dim", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(1));
	DeclareArg(env, "var", VTYPE_symbol, OCCUR_Once, FLAG_None,
											new Expr_Symbol(Gura_Symbol(x)));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Calculates a least square method using a sequence of pairs of x and y,\n"
	"and returns an expression of the fitted curve. You can specify the dimension\n"
	"by an argument n. In default, a symbol of the expression's variable is `x\n"
	"and it can be changed by specifying an argument var.");
}

Gura_ImplementFunction(least_square)
{
	size_t nDim = args.GetSizeT(2);
	if (nDim == 0) {
		sig.SetError(ERR_ValueError, "invalid dimension");
		return Value::Null;
	}
	size_t nCols = nDim + 1;
	size_t nRows = nCols;
	Iterator *pIterX = args.GetIterator(0);
	Iterator *pIterY = args.GetIterator(1);
	const Symbol *pSymbolVar = args.GetSymbol(3);
	NumberList sumListXX(nCols * 2, 0), sumListXY(nCols, 0);
	bool flagX = false, flagY = false;
	for (;;) {
		Value valueX, valueY;
		flagX = pIterX->Next(env, sig, valueX);
		if (sig.IsSignalled()) return Value::Null;
		flagY = pIterY->Next(env, sig, valueY);
		if (sig.IsSignalled()) return Value::Null;
		if (!(flagX && flagY)) break;
		if (!valueX.IsNumber()) {
			sig.SetError(ERR_ValueError, "cannot calculate non-number value");
			return Value::Null;
		}
		if (!valueY.IsNumber()) {
			sig.SetError(ERR_ValueError, "cannot calculate non-number value");
			return Value::Null;
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
		return Value::Null;
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
		return Value::Null;
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
			new Expr_Symbol(pSymbolVar));
		pAlpha++;
		pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExpr, pExprLeft);
		for ( ; pAlpha != alphaList.end(); pAlpha++) {
			size_t n = pAlpha - alphaList.begin();
			pExprLeft = new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul),
				new Expr_Value(*pAlpha),
				new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow),
					new Expr_Symbol(pSymbolVar),
					new Expr_Value(n)));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExpr, pExprLeft);
		}
		Function *pFunc = new CustomFunction(env,
							Gura_Symbol(_anonymous_), pExpr, FUNCTYPE_Function);
		pFunc->SetMode(RSLTMODE_Normal, FLAG_Map);
		pFunc->DeclareArg(env, pSymbolVar, VTYPE_number);
		result = Value(env, pFunc, Value::Null);
	} while (0);
	return result;
}

// math.bezier(nums[]+:number)
class Func_BezierPrototype : public Function {
private:
	NumberList _nums;
public:
	Func_BezierPrototype(Environment &env, const ValueList &nums);
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
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

Value Func_BezierPrototype::DoEval(Environment &env, Signal sig, Args &args) const
{
	Number t = args.GetNumber(0);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "nums", VTYPE_number, OCCUR_OnceOrMore, FLAG_List);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a list that consists of functions that generate coordinates of bezier\n"
	"curves with specified control points. One or more lists of control points can\n"
	"be specified. This means that if you give it two lists of numbers as arguments,\n"
	"it returns two functions of bezier curve.");
}

Gura_ImplementFunction(bezier)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach_const (ValueList, pValue, args.GetList(0)) {
		Function *pFunc = new Func_BezierPrototype(env, pValue->GetList());
		pFunc->SetMode(RSLTMODE_Normal, FLAG_Map);
		pFunc->DeclareArg(env, "t", VTYPE_number);
		valList.push_back(Value(env, pFunc, Value::Null));
	}
	return result;
}

// math.diff(expr:expr, var:symbol):map {block?}
Gura_DeclareFunction(diff)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr);
	DeclareArg(env, "var", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a mathematical differential expression of the given expr\n"
	"by a variable var.\n"
	"Example:\n"
	"math.diff(`(math.sin(x ** 2)), `x)");
}

Gura_ImplementFunction(diff)
{
	Expr *pExprDiff = args.GetExpr(0)->MathDiff(env, sig, args.GetSymbol(1));
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_expr(env, pExprDiff)));
}

// math.optimize(expr:expr):map {block?}
Gura_DeclareFunction(optimize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(optimize)
{
	Expr *pExprOpt = args.GetExpr(0)->MathOptimize(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_expr(env, pExprOpt)));
}

// math.fft(seq[])
Gura_DeclareFunction(fft)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "seq", VTYPE_any, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(fft)
{
	
	return Value::Null;
}

// math.integral(func, sequence)
Gura_DeclareFunction(integral)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(integral)
{
	return Value::Null;
}

// math.dot_product(a[], b[])
Gura_DeclareFunction(dot_product)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_any, OCCUR_Once, FLAG_List);
	DeclareArg(env, "b", VTYPE_any, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(dot_product)
{
	const ValueList &valList1 = args.GetList(0);
	const ValueList &valList2 = args.GetList(1);
	if (valList1.size() != valList2.size()) {
		sig.SetError(ERR_ValueError, "different length of lists");
		return Value::Null;
	}
	ValueList::const_iterator pValue1 = valList1.begin();
	ValueList::const_iterator pValue2 = valList2.begin();
	Value valueSum(0);
	for ( ; pValue1 != valList1.end(); pValue1++, pValue2++) {
		Value value;
		do {
			value = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, sig, *pValue1, *pValue2);
			if (sig.IsSignalled()) return Value::Null;
		} while (0);
		do {
			valueSum = env.GetOperator(OPTYPE_Add)->EvalBinary(env, sig, valueSum, value);
			if (sig.IsSignalled()) return Value::Null;
		} while (0);
	}
	return valueSum;
}

// math.cross_product(a[], b[])
static Value CalcCrossElem(Environment &env, Signal sig,
		const Value &ax, const Value &ay, const Value &bx, const Value &by);

Gura_DeclareFunction(cross_product)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_any, OCCUR_Once, FLAG_List);
	DeclareArg(env, "b", VTYPE_any, OCCUR_Once, FLAG_List);
}

Gura_ImplementFunction(cross_product)
{
	const ValueList &valList1 = args.GetList(0);
	const ValueList &valList2 = args.GetList(1);
	if (valList1.size() != valList2.size()) {
		sig.SetError(ERR_ValueError, "different length of lists");
		return Value::Null;
	}
	if (valList1.size() == 2) {
		return CalcCrossElem(env, sig,
					valList1[0], valList1[1], valList2[0], valList2[1]);
	} else if (valList1.size() == 3) {
		Value result;
		ValueList &valList = result.InitAsList(env);
		valList.reserve(3);
		Value value;
		value = CalcCrossElem(env, sig,
					valList1[1], valList1[2], valList2[1], valList2[2]);
		if (sig.IsSignalled()) return Value::Null;
		valList.push_back(value);
		value = CalcCrossElem(env, sig,
					valList1[2], valList1[0], valList2[2], valList2[0]);
		if (sig.IsSignalled()) return Value::Null;
		valList.push_back(value);
		value = CalcCrossElem(env, sig,
					valList1[0], valList1[1], valList2[0], valList2[1]);
		if (sig.IsSignalled()) return Value::Null;
		valList.push_back(value);
		return result;
	} else {
		sig.SetError(ERR_ValueError,
				"only support two or three dimension vector for cross product");
		return Value::Null;
	}
}

Value CalcCrossElem(Environment &env, Signal sig,
		const Value &ax, const Value &ay, const Value &bx, const Value &by)
{
	Value valueLeft;
	do {
		valueLeft = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, sig, ax, by);
		if (sig.IsSignalled()) return Value::Null;
	} while (0);
	Value valueRight;
	do {
		valueRight = env.GetOperator(OPTYPE_Mul)->EvalBinary(env, sig, ay, bx);
		if (sig.IsSignalled()) return Value::Null;
	} while (0);
	Value value;
	do {
		value = env.GetOperator(OPTYPE_Sub)->EvalBinary(env, sig, valueLeft, valueRight);
		if (sig.IsSignalled()) return Value::Null;
	} while (0);
	return value;
}

// math.covariance(a:iterator, b:iterator)
Gura_DeclareFunction(covariance)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_iterator);
	DeclareArg(env, "b", VTYPE_iterator);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a covariance between the sequences of values.");
}

Gura_ImplementFunction(covariance)
{
	size_t cntA, cntB;
	Iterator *pIteratorA = args.GetIterator(0);
	Iterator *pIteratorB = args.GetIterator(1);
	Value valueAveA = pIteratorA->Clone()->Average(env, sig, cntA);
	if (!valueAveA.IsNumber()) return Value::Null;
	Value valueAveB = pIteratorB->Clone()->Average(env, sig, cntB);
	if (!valueAveB.IsNumber()) return Value::Null;
	if (cntA != cntB) {
		sig.SetError(ERR_ValueError, "different length of iterators");
		return Value::Null;
	}
	Number result = 0;
	Number averageA = valueAveA.GetNumber();
	Number averageB = valueAveB.GetNumber();
	Value valueA, valueB;
	while (pIteratorA->Next(env, sig, valueA) && pIteratorB->Next(env, sig, valueB)) {
		if (valueA.IsNumber() && valueB.IsNumber()) {
			result +=
				(valueA.GetNumber() - averageA) * (valueB.GetNumber() - averageB);
		} else {
			sig.SetError(ERR_ValueError, "invalid data type of element");
			return Value::Null;
		}
	}
	if (sig.IsSignalled()) return Value::Null;
	return Value(result / static_cast<Number>(cntA));
}

// math.gcd(a:number, b+:number):map
Gura_DeclareFunction(gcd)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a greatest common divisor among two or more numbers.");
}

Gura_ImplementFunction(gcd)
{
	const ValueList &valList = args.GetList(1);
	ValueList::const_iterator pValue = valList.begin();
	int gcd = CalcGCD(args.GetInt(0), pValue->GetInt());
	pValue++;
	for ( ; pValue != valList.end(); pValue++) {
		gcd = CalcGCD(gcd, pValue->GetInt());
	}
	return Value(gcd);
}

// math.lcm(a:number, b+:number):map
Gura_DeclareFunction(lcm)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number, OCCUR_OnceOrMore);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Returns a least common multiple among two or more numbers.");
}

Gura_ImplementFunction(lcm)
{
	const ValueList &valList = args.GetList(1);
	ValueList::const_iterator pValue = valList.begin();
	int lcm = CalcLCM(args.GetInt(0), pValue->GetInt());
	pValue++;
	for ( ; pValue != valList.end(); pValue++) {
		lcm = CalcLCM(lcm, pValue->GetInt());
	}
	return Value(lcm);
}

// Module entry
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
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
Expr_Caller *CreateExprCaller(const Symbol *pSymbol, Expr *pExprArg)
{
	return new Expr_Caller(
		new Expr_Member(new Expr_Symbol(Gura_Symbol(math)), new Expr_Symbol(pSymbol)),
		new Expr_Lister(pExprArg), NULL);
}

Gura_EndModuleBody(math, math)

Gura_RegisterModule(math)
