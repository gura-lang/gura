//-----------------------------------------------------------------------------
// Gura module: math
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(math)

//-----------------------------------------------------------------------------
// Implementation of mathematical functions
//-----------------------------------------------------------------------------
// math.abs(num):map
Gura_DeclareFunction(abs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns an absolute value.\n");
}

Gura_ImplementFunction(abs)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_abs)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.acos(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(acos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en),
		"Returns an inverse cosine value.\n"
		"\n"
		"In default, the result is returned in radian.\n"
		"Specifying an attribute `:deg` would return that in degree.\n");
}

Gura_ImplementFunction(acos)
{
	ULong flags = arg.IsSet(Gura_Symbol(deg))? FLAG_Deg : FLAG_None;
	return env.GetOperator(OPTYPE_Math_acos)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(acos)
{
	// acos(x)' = -1 / sqrt(1 - x ** 2)
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(-1),
		Expr::CreateCaller(
			Gura_Symbol(math), Gura_Symbol(sqrt),
			new Expr_BinaryOp(
				env.GetOperator(OPTYPE_Sub),
				new Expr_Value(1),
				new Expr_BinaryOp(
					env.GetOperator(OPTYPE_Pow),
					pExprArg->Clone(),
					new Expr_Value(2)))));
}

// math.arg(num):map:[deg]
Gura_DeclareFunction(arg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en),
		"Returns an argument, an angle from the real-axis in the complex plane, of a complex number.\n"
		"\n"
		"In default, the angle value is returned in radian.\n"
		"Specifying an attribute `:deg` would return that in degree.\n");
}

Gura_ImplementFunction(arg)
{
	ULong flags = arg.IsSet(Gura_Symbol(deg))? FLAG_Deg : FLAG_None;
	return env.GetOperator(OPTYPE_Math_arg)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.asin(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(asin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en),
		"Returns an inverse sine value.\n"
		"\n"
		"In default, the result is returned in radian.\n"
		"Specifying an attribute `:deg` would return that in degree.\n");
}

Gura_ImplementFunction(asin)
{
	ULong flags = arg.IsSet(Gura_Symbol(deg))? FLAG_Deg : FLAG_None;
	return env.GetOperator(OPTYPE_Math_asin)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(asin)
{
	// asin(x)' = 1 / sqrt(1 - x ** 2)
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(1),
		Expr::CreateCaller(
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
		Gura_Symbol(en),
		"Returns an inverse tangent value.\n");
}

Gura_ImplementFunction(atan)
{
	ULong flags = arg.IsSet(Gura_Symbol(deg))? FLAG_Deg : FLAG_None;
	return env.GetOperator(OPTYPE_Math_atan)->EvalMapUnary(env, arg.GetValue(0), flags);
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
		Gura_Symbol(en),
		"Returns an inverse tangent value of a fraction of num1 and num2.\n"
		"\n"
		"In default, the result is returned in radian.\n"
		"Specifying an attribute `:deg` would return that in degree.\n");
}

Gura_ImplementFunction(atan2)
{
	ULong flags = arg.IsSet(Gura_Symbol(deg))? FLAG_Deg : FLAG_None;
	return env.GetOperator(OPTYPE_Math_atan2)->EvalMapBinary(
		env, arg.GetValue(0), arg.GetValue(1), flags);
}

// math.ceil(num):map
Gura_DeclareFunction(ceil)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a nearest integer number above or equal to the specified value.\n");
}

Gura_ImplementFunction(ceil)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_ceil)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.conj(num):map
Gura_DeclareFunction(conj)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a conjugate of a complex number.");
}

Gura_ImplementFunction(conj)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_conj)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.cos(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(cos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en),
		"Returns a cosine value.\n"
		"\n"
		"In default, the given argument is treated as a radian number.\n"
		"Specifying an attribute `:deg` would treat that as a degree number.\n");
}

Gura_ImplementFunction(cos)
{
	ULong flags = arg.IsSet(Gura_Symbol(deg))? FLAG_Deg : FLAG_None;
	return env.GetOperator(OPTYPE_Math_cos)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(cos)
{
	// cos(x)' = -sin(x)
	return new Expr_UnaryOp(
		env.GetOperator(OPTYPE_Neg),
		Expr::CreateCaller(
			Gura_Symbol(math), Gura_Symbol(sin),
			pExprArg->Clone()));
}

// math.cosh(num):map
Gura_DeclareFunction(cosh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a hyperbolic cosine value.\n");
}

Gura_ImplementFunction(cosh)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_cosh)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.covariance(a, b)
Gura_DeclareFunction(covariance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_any);
	DeclareArg(env, "b", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a covariance between the `a` and `b`.");
}

Gura_ImplementFunction(covariance)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_covariance)->EvalBinary(
		env, arg.GetValue(0), arg.GetValue(1), flags);
}

// math.cross(a, b)
Gura_DeclareFunction(cross)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_any);
	DeclareArg(env, "b", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a cross product between `a` and `b`.");
}

Gura_ImplementFunction(cross)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_cross)->EvalBinary(
		env, arg.GetValue(0), arg.GetValue(1), flags);
}

// math.delta(num:number):map
Gura_DeclareFunction(delta)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Evaluates a delta function with a given argument `num`\n"
		"that returns `1` when `num == 0` and `0` otherwise.");
}

Gura_ImplementFunction(delta)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_delta)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.dot(a, b)
Gura_DeclareFunction(dot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "a", VTYPE_any);
	DeclareArg(env, "b", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a dot product between `a` and `b`.");
}

Gura_ImplementFunction(dot)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_dot)->EvalBinary(
		env, arg.GetValue(0), arg.GetValue(1), flags);
}

// math.exp(num):map
Gura_DeclareFunctionWithMathDiff(exp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns an exponential value.\n");
}

Gura_ImplementFunction(exp)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_exp)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(exp)
{
	// exp(x)' = exp(x)
	return Expr::CreateCaller(
		Gura_Symbol(math), Gura_Symbol(exp),
		pExprArg->Clone());
}

// math.floor(num):map
Gura_DeclareFunction(floor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a nearest integer number below or equal to the specified value.\n");
}

Gura_ImplementFunction(floor)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_floor)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.hypot(x, y):map
Gura_DeclareFunction(hypot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_any);
	DeclareArg(env, "y", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a hyperbolic tangent value.\n");
}

Gura_ImplementFunction(hypot)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_hypot)->EvalMapBinary(
		env, arg.GetValue(0), arg.GetValue(1), flags);
}

// math.imag(num):map
Gura_DeclareFunction(imag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns an imaginary part of a complex number.");
}

Gura_ImplementFunction(imag)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_imag)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.log(num):map
Gura_DeclareFunctionWithMathDiff(log)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a natural logarithm value.\n");
}

Gura_ImplementFunction(log)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_log)->EvalMapUnary(env, arg.GetValue(0), flags);
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
		Gura_Symbol(en),
		"Returns a decadic logarithm value.\n");
}

Gura_ImplementFunction(log10)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_log10)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(log10)
{
	// log10(x)' = 1 / (x * log(10))
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div), new Expr_Value(1),
		new Expr_BinaryOp(
			env.GetOperator(OPTYPE_Mul),
			pExprArg->Clone(),
			Expr::CreateCaller(
				Gura_Symbol(math), Gura_Symbol(log),
				new Expr_Value(10))));
}

// math.norm(num):map
Gura_DeclareFunction(norm)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a norm value of a complex number.\n");
}

Gura_ImplementFunction(norm)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_norm)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.real(num):map
Gura_DeclareFunction(real)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a real part of a complex number.\n");
}

Gura_ImplementFunction(real)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_real)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.relu(num):map
Gura_DeclareFunctionWithMathDiff(relu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Evaluates a rectified linear unit function with a given argument `num`\n"
		"that returns `num` when `num >= 0` and `0` otherwise.");
}

Gura_ImplementFunction(relu)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_relu)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(relu)
{
	// relu(x)' = unitstep(x)
	return Expr::CreateCaller(
		Gura_Symbol(math), Gura_Symbol(unitstep),
		pExprArg->Clone());
}

// math.sigmoid(num):map
Gura_DeclareFunctionWithMathDiff(sigmoid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a sigmoid value.\n");
}

Gura_ImplementFunction(sigmoid)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_sigmoid)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(sigmoid)
{
	// sigmoid(x)' = sigmoid(x) * (1 - sigmoid(x))
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Mul),
		Expr::CreateCaller(
			Gura_Symbol(math), Gura_Symbol(sigmoid),
			pExprArg->Clone()),
		new Expr_BinaryOp(
			env.GetOperator(OPTYPE_Sub),
			new Expr_Value(1),
			Expr::CreateCaller(
				Gura_Symbol(math), Gura_Symbol(sigmoid),
				pExprArg->Clone())));
}

// math.sin(num):map:[deg]
Gura_DeclareFunctionWithMathDiff(sin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	DeclareAttr(Gura_Symbol(deg));
	AddHelp(
		Gura_Symbol(en),
		"Returns a sine value.\n"
		"\n"
		"In default, the given argument is treated as a radian number.\n"
		"Specifying an attribute `:deg` would treat that as a degree number.\n");
}

Gura_ImplementFunction(sin)
{
	ULong flags = arg.IsSet(Gura_Symbol(deg))? FLAG_Deg : FLAG_None;
	return env.GetOperator(OPTYPE_Math_sin)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(sin)
{
	// sin(x)' = cos(x)
	return Expr::CreateCaller(
		Gura_Symbol(math), Gura_Symbol(cos),
		pExprArg->Clone());
}

// math.sinh(num):map
Gura_DeclareFunction(sinh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a hyperbolic sine value.\n");
}

Gura_ImplementFunction(sinh)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_sinh)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.sqrt(num):map
Gura_DeclareFunctionWithMathDiff(sqrt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Returns a square root value.\n");
}

Gura_ImplementFunction(sqrt)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_sqrt)->EvalMapUnary(env, arg.GetValue(0), flags);
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
			Expr::CreateCaller(
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
		Gura_Symbol(en),
		"Returns a tangent value.\n"
		"\n"
		"In default, the given argument is treated as a radian number.\n"
		"Specifying an attribute `:deg` would treat that as a degree number.\n");
}

Gura_ImplementFunction(tan)
{
	ULong flags = arg.IsSet(Gura_Symbol(deg))? FLAG_Deg : FLAG_None;
	return env.GetOperator(OPTYPE_Math_tan)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(tan)
{
	// tan(x)' = 1 / cos(x) ** 2
	return new Expr_BinaryOp(
		env.GetOperator(OPTYPE_Div),
		new Expr_Value(1),
		new Expr_BinaryOp(
			env.GetOperator(OPTYPE_Pow),
			Expr::CreateCaller(
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
		Gura_Symbol(en),
		"Returns a hyperbolic tangent value.\n");
}

Gura_ImplementFunction(tanh)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_tanh)->EvalMapUnary(env, arg.GetValue(0), flags);
}

// math.unitstep(num):map
Gura_DeclareFunctionWithMathDiff(unitstep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Evaluates a unit step function with a given argument `num`\n"
		"that returns `1` when `num >= 0` and `0` otherwise.");
}

Gura_ImplementFunction(unitstep)
{
	ULong flags = FLAG_None;
	return env.GetOperator(OPTYPE_Math_unitstep)->EvalMapUnary(env, arg.GetValue(0), flags);
}

Gura_ImplementMathDiff(unitstep)
{
	// unitstep(x)' = delta(x)
	return Expr::CreateCaller(
		Gura_Symbol(math), Gura_Symbol(delta),
		pExprArg->Clone());
}

//-----------------------------------------------------------------------------
// Implementation of other functions
//-----------------------------------------------------------------------------
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
	DeclareArg(env, "nums", VTYPE_number, OCCUR_OnceOrMore, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en), 
		"Returns a list that consists of functions that generate coordinates of bezier\n"
		"curves with specified control points. One or more lists of control points can\n"
		"be specified. This means that if you give it two lists of numbers as arguments,\n"
		"it returns two functions of bezier curve.");
}

Gura_ImplementFunction(bezier)
{
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	foreach_const (ValueList, pValue, arg.GetList(0)) {
		Function *pFunc = new Func_BezierPrototype(env, pValue->GetList());
		pFunc->SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
		pFunc->DeclareArg(env, "t", VTYPE_number);
		pObjList->Add(Value(new Object_function(env, pFunc)));
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
		Gura_Symbol(en),
		"Calculates a mathematical differential expression of the given `expr`\n"
		"by a variable `var`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("rtn", "expr")
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

// math.fft(seq[])
Gura_DeclareFunction(fft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "seq", VTYPE_any, OCCUR_Once, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(fft)
{
	
	return Value::Nil;
}

// math.gcd(a:number, b+:number):map
Gura_DeclareFunction(gcd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en),
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

// math.integral(func, sequence)
Gura_DeclareFunction(integral)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(integral)
{
	return Value::Nil;
}

// math.lcm(a:number, b+:number):map
Gura_DeclareFunction(lcm)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_number);
	DeclareArg(env, "b", VTYPE_number, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en),
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

// math.least_square(x:iterator, y:iterator, dim:number => 1, var:symbol => `x)
Gura_DeclareFunction(least_square)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_iterator);
	DeclareArg(env, "y", VTYPE_iterator);
	DeclareArg(env, "dim", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(1));
	DeclareArg(env, "var", VTYPE_symbol, OCCUR_Once, FLAG_None, 0, new Expr_Value(Gura_Symbol(x)));
	AddHelp(
		Gura_Symbol(en), 
		"Takes two iterators `x` and `y` that return coordinate of points\n"
		"and returns a function that fits them using least square metho.\n"
		"You can specify the fitting curve's dimension by an argument `dim`,\n"
		"which default value is one.\n"
		"The variable symbol used in the function is `x`,\n"
		"which can be changed by specifying an argument `var`.\n");
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
	DoubleList sumListXX(nCols * 2, 0), sumListXY(nCols, 0);
	do {
		Iterator *pIterX = arg.GetIterator(0);
		Iterator *pIterY = arg.GetIterator(1);
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
			Double numX = valueX.GetDouble(), numY = valueY.GetDouble();
			Double productX = 1;
			DoubleList::iterator pSumXX = sumListXX.begin();
			DoubleList::iterator pSumXY = sumListXY.begin();
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
	} while (0);
	DoubleList coefList;
	coefList.reserve(nCols);
	do {
		AutoPtr<ArrayT<Double> > pMat(ArrayT<Double>::Create(nCols, nRows));
		do {
			DoubleList::iterator pSumXXBase = sumListXX.begin();
			Double *pElem = pMat->GetPointer();
			for (size_t iRow = 0; iRow < nRows; iRow++, pSumXXBase++) {
				DoubleList::iterator pSumXX = pSumXXBase;
				for (size_t iCol = 0; iCol < nCols; iCol++, pElem++, pSumXX++) {
					*pElem = *pSumXX;
				}
			}
		} while (0);
		do {
			Double det = 0.0;
			AutoPtr<Array> pMatInv(Array::Invert(sig, nullptr, pMat.get(), det));
			if (pMatInv.IsNull()) return Value::Nil;
			const Double *pElem = reinterpret_cast<const Double *>(pMatInv->GetPointerRaw());
			for (size_t iRow = 0; iRow < nRows; iRow++) {
				Double coef = 0;
				DoubleList::iterator pSumXY = sumListXY.begin();
				for (size_t iCol = 0; iCol < nCols; iCol++, pElem++, pSumXY++) {
					coef += *pElem * *pSumXY;
				}
				coefList.push_back(coef);
			}
		} while (0);
	} while (0);
	AutoPtr<Function> pFunc;
	do {
		const Symbol *pSymbolVar = arg.GetSymbol(3);
		DoubleList::iterator pCoef = coefList.begin();
		Expr *pExpr = new Expr_Value(*pCoef);
		pCoef++;
		Expr *pExprLeft = new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul),
			new Expr_Value(*pCoef),
			new Expr_Identifier(pSymbolVar));
		pCoef++;
		pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExpr, pExprLeft);
		for ( ; pCoef != coefList.end(); pCoef++) {
			size_t n = pCoef - coefList.begin();
			pExprLeft = new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul),
				new Expr_Value(*pCoef),
				new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow),
					new Expr_Identifier(pSymbolVar),
					new Expr_Value(n)));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExpr, pExprLeft);
		}
		pFunc.reset(new FunctionCustom(
						env, Gura_Symbol(_anonymous_), pExpr, FUNCTYPE_Function));
		pFunc->SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
		pFunc->DeclareArg(env, pSymbolVar, VTYPE_number);
	} while (0);
	return Value(new Object_function(env, pFunc.release()));
}

// math.optimize(expr:expr):map {block?}
Gura_DeclareFunction(optimize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an optimized expression of the given argument `expr`,\n"
		"which needs to be made up of mathematical elements.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("rtn", "expr"));
}

Gura_ImplementFunction(optimize)
{
	Signal &sig = env.GetSignal();
	Expr *pExprOpt = arg.GetExpr(0)->MathOptimize(env);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_expr(env, pExprOpt)));
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
	// Assignment of values
	Gura_AssignValue(e,		Value(Math_E));
	Gura_AssignValue(pi,	Value(Math_PI));
	// Assignment of mathematical functions
	Gura_AssignFunction(abs);
	Gura_AssignFunction(acos);
	Gura_AssignFunction(arg);
	Gura_AssignFunction(asin);
	Gura_AssignFunction(atan);
	Gura_AssignFunction(atan2);
	Gura_AssignFunction(ceil);
	Gura_AssignFunction(conj);
	Gura_AssignFunction(cos);
	Gura_AssignFunction(cosh);
	Gura_AssignFunction(covariance);
	Gura_AssignFunction(cross);
	Gura_AssignFunction(delta);
	Gura_AssignFunction(dot);
	Gura_AssignFunction(exp);
	Gura_AssignFunction(floor);
	Gura_AssignFunction(hypot);
	Gura_AssignFunction(imag);
	Gura_AssignFunction(log);
	Gura_AssignFunction(log10);
	Gura_AssignFunction(norm);
	Gura_AssignFunction(real);
	Gura_AssignFunction(relu);
	Gura_AssignFunction(sigmoid);
	Gura_AssignFunction(sin);
	Gura_AssignFunction(sinh);
	Gura_AssignFunction(sqrt);
	Gura_AssignFunction(tan);
	Gura_AssignFunction(tanh);
	Gura_AssignFunction(unitstep);
	// Assignment of other functions
	Gura_AssignFunction(bezier);
	Gura_AssignFunction(diff);
	Gura_AssignFunction(fft);
	Gura_AssignFunction(gcd);
	Gura_AssignFunction(integral);
	Gura_AssignFunction(lcm);
	Gura_AssignFunction(least_square);
	Gura_AssignFunction(optimize);
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
