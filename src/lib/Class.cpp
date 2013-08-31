#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------
// object#isnil()
Gura_DeclareMethodPrimitive(Object, isnil)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
}

Gura_ImplementMethod(Object, isnil)
{
	return Value(args.GetThis().IsInvalid());
}

// object#istype(type+:expr):map
Gura_DeclareMethodPrimitive(Object, istype)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(Object, istype)
{
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(0));
	if (pValueTypeInfo == NULL) return Value::Null;
	ValueType valType = args.GetThis().GetValueType();
	ValueType valTypeCmp = pValueTypeInfo->GetValueType();
	if ((valType == VTYPE_number || valType == VTYPE_fraction) &&
								valTypeCmp == VTYPE_complex) return Value(true);
	if (valType == VTYPE_fraction && valTypeCmp == VTYPE_number) return Value(true);
	return Value(valType == valTypeCmp);
}

// object#isinstance(type+:expr):map
Gura_DeclareMethodPrimitive(Object, isinstance)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(Object, isinstance)
{
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(0));
	if (pValueTypeInfo == NULL) return Value::Null;
	return args.GetThis().IsInstanceOf(pValueTypeInfo->GetValueType());
}

// num = object#tonumber():[strict,raise,zero,nil]
Gura_DeclareMethodPrimitive(Object, tonumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(strict));
	DeclareAttr(Gura_Symbol(raise));
	DeclareAttr(Gura_Symbol(zero));
	DeclareAttr(Gura_Symbol(nil));
}

Gura_ImplementMethod(Object, tonumber)
{
	bool allowPartFlag = !args.IsSet(Gura_Symbol(strict));
	bool successFlag;
	Number num = args.GetThis().ToNumber(allowPartFlag, successFlag);
	if (successFlag) {
		return Value(num);
	} else if (args.IsSet(Gura_Symbol(raise))) {
		sig.SetError(ERR_ValueError, "failed to convert to number");
		return Value::Null;
	} else if (args.IsSet(Gura_Symbol(zero))) {
		return Value(0.);
	} else { // args.IsSet(Gura_UserSymbol(nil)
		return Value::Null;
	}
}

// num = object#tostring()
Gura_DeclareMethodPrimitive(Object, tostring)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Object, tostring)
{
	String str = args.GetThis().ToString(sig, false);
	if (sig.IsSignalled()) return Value::Null;
	return Value(env, str.c_str());
}

// object.getprop!(symbol:symbol, default?:nomap):map
Gura_DeclareClassMethodAlias(Object, getprop_X, "getprop!")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "default", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_NoMap);
}

Gura_ImplementClassMethod(Object, getprop_X)
{
	Fundamental *pThis = args.GetThisFundamental();
	const SymbolSet &attrs = SymbolSet::Null;
	if (args.IsDefined(1)) {
		Value value = args.GetValue(1);
		return pThis->GetProp(env, sig, args.GetSymbol(0), attrs, &value);
	} else {
		return pThis->GetProp(env, sig, args.GetSymbol(0), attrs);
	}
}

// object.setprop!(symbol:symbol, value):map
Gura_DeclareClassMethodAlias(Object, setprop_X, "setprop!")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementClassMethod(Object, setprop_X)
{
	Fundamental *pThis = args.GetThisFundamental();
	pThis->AssignValue(args.GetSymbol(0), args.GetValue(1), EXTRA_Public);
	return Value::Null;
}

// object.__call__(symbol:symbol, args*, dict%):map {block?}
class Gura_Method(Object, __call__) : public Function {
public:
	Gura_Method(Object, __call__)(Environment &env, const char *name = "__call__");
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

Gura_Method(Object, __call__)::Gura_Method(Object, __call__)(Environment &env, const char *name) :
						Function(env, Symbol::Add(name), FUNCTYPE_Class, FLAG_None)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareDictArg("dict");
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Value Gura_Method(Object, __call__)::EvalExpr(Environment &env, Signal sig, Args &args) const
{
	Fundamental *pThis = args.GetThisFundamental();
	ExprOwner exprOwnerArgs(args.GetExprListArg());
	const Expr *pExprArg = exprOwnerArgs.front();
	size_t nElems = 0;
	ValueList valListArg;
	if (!pExprArg->ExecInArg(env, sig, valListArg, nElems, false)) return Value::Null;
	if (valListArg.size() != 1) {
		sig.SetError(ERR_ValueError, "invalid argument for __call__()");
		return Value::Null;
	}
	const Value &value = valListArg.front();
	if (!value.IsSymbol()) {
		sig.SetError(ERR_ValueError, "invalid argument for __call__()");
		return Value::Null;
	}
	const Symbol *pSymbol = value.GetSymbol();
	Value valueFunc;
	const Value *pValue = pThis->LookupValue(pSymbol, ENVREF_Escalate);
	if (pValue == NULL) {
		const SymbolSet &attrs = SymbolSet::Null;
		valueFunc = pThis->GetProp(env, sig, pSymbol, attrs);
		if (sig.IsSignalled()) return Value::Null;
	} else {
		valueFunc = *pValue;
	}
	if (!valueFunc.IsFunction()) {
		sig.SetError(ERR_ValueError, "invalid argument for __call__()");
		return Value::Null;
	}
	const Function *pFunc = valueFunc.GetFunction();
	exprOwnerArgs.erase(exprOwnerArgs.begin());
	Args argsSub(args, exprOwnerArgs);
	return pFunc->EvalExpr(env, sig, argsSub);
}

Value Gura_Method(Object, __call__)::DoEval(Environment &env, Signal sig, Args &args) const
{
	return Value::Null;
}

// object#clone()
Gura_DeclareMethod(Object, clone)
{
}

Gura_ImplementMethod(Object, clone)
{
	Object *pObj = args.GetThisObj()->Clone();
	if (pObj == NULL) {
		sig.SetError(ERR_ValueError, "failed to create a clone object");
		return Value::Null;
	}
	return Value(pObj);
}

// num = object#__iter__()
Gura_DeclareMethod(Object, __iter__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Object, __iter__)
{
	Iterator *pIterator = args.GetThis().CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	return Value(env, pIterator);
}

bool Class::IsClass() const { return true; }
bool Class::IsCustom() const { return false; }

Class::Class(Environment *pEnvOuter, ValueType valType) :
	Fundamental(pEnvOuter, ENVTYPE_class),
	_pClassSuper(pEnvOuter->IsClass()?
			Class::Reference(dynamic_cast<Class *>(pEnvOuter)) : NULL),
	_pConstructor(NULL), _pSymbol(Gura_Symbol(_anonymous_)), _valType(valType) 
{
}

Class::~Class()
{
}

Object *Class::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return new Object((pClass == NULL)? this : pClass);
}

bool Class::DirProp(Environment &env, Signal sig, SymbolSet &symbols, bool escalateFlag)
{
	if (escalateFlag) {
		foreach_const (FrameOwner, ppFrame, GetFrameOwner()) {
			const Frame *pFrame = *ppFrame;
			if (pFrame->IsType(ENVTYPE_class) || pFrame->IsType(ENVTYPE_object)) {
				foreach_const (ValueMap, iter, pFrame->GetValueMap()) {
					symbols.insert(iter->first);
				}
			}
		}
	} else {
		foreach_const (ValueMap, iter, GetTopFrame()->GetValueMap()) {
			symbols.insert(iter->first);
		}
	}
	return DoDirProp(env, sig, symbols);
}

Value Class::GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
				const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const
{
	return Value::Null;
}

bool Class::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class::CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl)
{
	return false;
}

String Class::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<class:";
	str += GetName();
	str += ">";
	return str;
}

// assignment
void Class::Prepare(Environment &env)
{
	Gura_AssignMethod(Object, isnil);		// primitive method
	Gura_AssignMethod(Object, istype);		// primitive method
	Gura_AssignMethod(Object, isinstance);	// primitive method
	Gura_AssignMethod(Object, tonumber);	// primitive method
	Gura_AssignMethod(Object, tostring);	// primitive method
	Gura_AssignMethod(Object, setprop_X);
	Gura_AssignMethod(Object, getprop_X);
	Gura_AssignMethod(Object, __call__);
	Gura_AssignMethod(Object, clone);
	Gura_AssignMethod(Object, __iter__);
}

bool Class::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	sig.SetError(ERR_IOError, "can't serialize class or module");
	return false;
}

bool Class::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	sig.SetError(ERR_IOError, "can't deserialize class or module");
	return false;
}

bool Class::BuildContent(Environment &env, Signal sig, const Value &valueThis,
			const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable)
{
	Environment envLocal(this, ENVTYPE_local);
	foreach_const (ExprList, ppExpr, pExprBlock->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsAssign()) {
			const Expr_Assign *pExprAssign =
								dynamic_cast<const Expr_Assign *>(pExpr);
			pExprAssign->Exec(envLocal, sig, *this, pSymbolsAssignable);
		} else if (pExpr->IsCaller()) {
			const Expr_Caller *pExprCaller =
								dynamic_cast<const Expr_Caller *>(pExpr);
			Value valueCar = pExprCaller->GetCar()->Exec(envLocal, sig);
			if (sig.IsSignalled()) return false;
			ICallable *pCallable = valueCar.GetObject();
			if (pCallable == NULL) {
				sig.SetError(ERR_TypeError, "object is not callable");
			} else {
				const Function *pFuncLeader = NULL;
				pCallable->Call(*this, sig, valueThis, NULL, false,
						pExprCaller, pExprCaller->GetExprOwner(), &pFuncLeader);
			}
		} else {
			sig.SetError(ERR_SyntaxError, "invalid element in class constructor");
		}
		if (sig.IsSignalled()) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Class_nil
//-----------------------------------------------------------------------------
Class_nil::Class_nil(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_nil)
{
}

void Class_nil::Prepare(Environment &env)
{
}

bool Class_nil::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_nil::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_nil::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

//-----------------------------------------------------------------------------
// Class_undefined
//-----------------------------------------------------------------------------
Class_undefined::Class_undefined(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_undefined)
{
}

void Class_undefined::Prepare(Environment &env)
{
}

bool Class_undefined::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_undefined::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_undefined::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

//-----------------------------------------------------------------------------
// Class_symbol
//-----------------------------------------------------------------------------
Class_symbol::Class_symbol(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_symbol)
{
}

void Class_symbol::Prepare(Environment &env)
{
}

bool Class_symbol::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsString()) {
		value = Value(Symbol::Add(value.GetString()));
		return true;
	}
	return false;
}

bool Class_symbol::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return stream.SerializeSymbol(sig, value.GetSymbol());
}

bool Class_symbol::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	const Symbol *pSymbol = NULL;
	if (!stream.DeserializeSymbol(sig, &pSymbol)) return false;
	value = Value(pSymbol);
	return true;
}

//-----------------------------------------------------------------------------
// Class_boolean
//-----------------------------------------------------------------------------
Class_boolean::Class_boolean(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_boolean)
{
}

void Class_boolean::Prepare(Environment &env)
{
}

bool Class_boolean::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsList()) {
		return true;	// ?????
	} else {
		value = Value(value.GetBoolean());
		return true;
	}
}

bool Class_boolean::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return stream.SerializeUChar(sig, static_cast<UChar>(value.GetBoolean()));
}

bool Class_boolean::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	UChar num = 0;
	if (!stream.DeserializeUChar(sig, num)) return false;
	value = Value(num != 0);
	return true;
}

//-----------------------------------------------------------------------------
// Class_number
//-----------------------------------------------------------------------------
// number#real()
Gura_DeclareMethodPrimitive(number, real)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(number, real)
{
	Number num = args.GetThis().GetNumber();
	return Value(num);
}

// number#imag()
Gura_DeclareMethodPrimitive(number, imag)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(number, imag)
{
	return Value::Zero;
}

// number#norm()
Gura_DeclareMethodPrimitive(number, norm)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(number, norm)
{
	Number num = args.GetThis().GetNumber();
	return Value(num * num);
}

// number#abs()
Gura_DeclareMethodPrimitive(number, abs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(number, abs)
{
	Number num = args.GetThis().GetNumber();
	return Value(::fabs(num));
}

// number#arg():[deg]
Gura_DeclareMethodPrimitive(number, arg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(deg));
}

Gura_ImplementMethod(number, arg)
{
	return Value::Zero;
}

// number#roundoff(threshold:number => 1e-10)
Gura_DeclareMethodPrimitive(number, roundoff)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
}

Gura_ImplementMethod(number, roundoff)
{
	Number num = args.GetThis().GetNumber();
	if (num < args.GetNumber(0)) num = 0;
	return Value(num);
}

Class_number::Class_number(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_number)
{
}

void Class_number::Prepare(Environment &env)
{
	Gura_AssignMethod(number, real);		// primitive method
	Gura_AssignMethod(number, imag);		// primitive method
	Gura_AssignMethod(number, norm);		// primitive method
	Gura_AssignMethod(number, abs);			// primitive method
	Gura_AssignMethod(number, arg);			// primitive method
	Gura_AssignMethod(number, roundoff);	// primitive method
}

bool Class_number::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	bool allowPartFlag = false;
	bool successFlag = false;
	Number num = value.ToNumber(allowPartFlag, successFlag);
	if (successFlag) {
		value = Value(num);
		return true;
	}
	//sig.SetError(ERR_ValueError, "failed to convert to a number");
	return false;
}

bool Class_number::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return stream.SerializeDouble(sig, value.GetNumber());
}

bool Class_number::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	double num = 0;
	if (!stream.DeserializeDouble(sig, num)) return false;
	value = Value(num);
	return true;
}

//-----------------------------------------------------------------------------
// Class_complex
//-----------------------------------------------------------------------------
// complex#real()
Gura_DeclareMethodPrimitive(complex, real)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(complex, real)
{
	Complex num = args.GetThis().GetComplex();
	return Value(num.real());
}

// complex#imag()
Gura_DeclareMethodPrimitive(complex, imag)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(complex, imag)
{
	Complex num = args.GetThis().GetComplex();
	return Value(num.imag());
}

// complex#norm()
Gura_DeclareMethodPrimitive(complex, norm)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(complex, norm)
{
	Complex num = args.GetThis().GetComplex();
	return Value(std::norm(num));
}

// complex#abs()
Gura_DeclareMethodPrimitive(complex, abs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(complex, abs)
{
	Complex num = args.GetThis().GetComplex();
	return Value(std::abs(num));
}

// complex#arg():[deg]
Gura_DeclareMethodPrimitive(complex, arg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(deg));
}

Gura_ImplementMethod(complex, arg)
{
	Complex num = args.GetThis().GetComplex();
	double angle = std::arg(num);
	if (args.IsSet(Gura_Symbol(deg))) angle = RadToDeg(angle);
	return Value(angle);
}

// complex#roundoff(threshold:number => 1e-10)
Gura_DeclareMethodPrimitive(complex, roundoff)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once, FLAG_None,
											new Expr_Value(RoundOffThreshold));
}

Gura_ImplementMethod(complex, roundoff)
{
	Complex num = args.GetThis().GetComplex();
	double numThreshold = args.GetDouble(0);
	double numReal = num.real(), numImag = num.imag();
	if (numReal < numThreshold) numReal = 0;
	if (numImag < numThreshold) numImag = 0;
	if (numImag == 0) return Value(numReal);
	return Value(Complex(numReal, numImag));
}

Class_complex::Class_complex(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_complex)
{
}

void Class_complex::Prepare(Environment &env)
{
	Gura_AssignMethod(complex, real);		// primitive method
	Gura_AssignMethod(complex, imag);		// primitive method
	Gura_AssignMethod(complex, norm);		// primitive method
	Gura_AssignMethod(complex, abs);		// primitive method
	Gura_AssignMethod(complex, arg);		// primitive method
	Gura_AssignMethod(complex, roundoff);	// primitive method
}

Value Class_complex::GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
				const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const
{
	return Value::Null;
}

bool Class_complex::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsNumber()) {		// cast number to complex
		return true;
	} else if (value.IsFraction()) {
		bool allowPartFlag = false;
		bool successFlag = false;
		Number num = value.ToNumber(allowPartFlag, successFlag);
		if (successFlag) {
			value = Value(num);
			return true;
		}
	}
	return false;
}

bool Class_complex::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	const Complex *pComp = value.GetComplexPtr();
	if (!stream.SerializeDouble(sig, pComp->real())) return false;
	if (!stream.SerializeDouble(sig, pComp->imag())) return false;
	return true;
}

bool Class_complex::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	double re = 0, im = 0;
	if (!stream.DeserializeDouble(sig, re)) return false;
	if (!stream.DeserializeDouble(sig, im)) return false;
	value = Value(Complex(re, im));
	return true;
}

//-----------------------------------------------------------------------------
// Class_fraction
//-----------------------------------------------------------------------------
// fraction(numerator:number, denominator?:number):map {block?}
Gura_DeclareFunction(fraction)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numerator", VTYPE_number);
	DeclareArg(env, "denominator", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_fraction));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Creates a fraction value.");
}

Gura_ImplementFunction(fraction)
{
	int numerator = args.GetInt(0);
	int denominator = args.IsNumber(1)? args.GetInt(1) : 1;
	if (denominator == 0) {
		sig.SetError(ERR_ZeroDivisionError, "denominator can't be zero");
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(Fraction(numerator, denominator)));
}

// fraction#numerator()
Gura_DeclareMethodPrimitive(fraction, numerator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(fraction, numerator)
{
	const Fraction &num = args.GetThis().GetFraction();
	return Value(num.numerator);
}

// fraction#denominator()
Gura_DeclareMethodPrimitive(fraction, denominator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(fraction, denominator)
{
	const Fraction &num = args.GetThis().GetFraction();
	return Value(num.denominator);
}

// fraction#reduce()
Gura_DeclareMethodPrimitive(fraction, reduce)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(fraction, reduce)
{
	const Fraction &num = args.GetThis().GetFraction();
	return Value(num.Reduce());
}

Class_fraction::Class_fraction(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_fraction)
{
}

void Class_fraction::Prepare(Environment &env)
{
	Gura_AssignFunction(fraction);
	Gura_AssignMethod(fraction, numerator);		// primitive method
	Gura_AssignMethod(fraction, denominator);	// primitive method
	Gura_AssignMethod(fraction, reduce);		// primitive method
}

Value Class_fraction::GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
				const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const
{
	return Value::Null;
}

bool Class_fraction::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsNumber()) {		// cast number to fraction
		return true;
	}
	return false;
}

bool Class_fraction::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	const Fraction *pFrac = value.GetFractionPtr();
	if (!stream.SerializeDouble(sig, pFrac->numerator)) return false;
	if (!stream.SerializeDouble(sig, pFrac->denominator)) return false;
	return true;
}

bool Class_fraction::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	double numerator = 0, denominator = 0;
	if (!stream.DeserializeDouble(sig, numerator)) return false;
	if (!stream.DeserializeDouble(sig, denominator)) return false;
	if (denominator == 0) {
		sig.SetError(ERR_ZeroDivisionError, "denominator can't be zero");
		return false;
	}
	value = Value(Fraction(static_cast<int>(numerator), static_cast<int>(denominator)));
	return true;
}

//-----------------------------------------------------------------------------
// Class_quote
//-----------------------------------------------------------------------------
Class_quote::Class_quote(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_quote)
{
}

void Class_quote::Prepare(Environment &env)
{
}

bool Class_quote::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_quote::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_quote::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

//-----------------------------------------------------------------------------
// Class_any
//-----------------------------------------------------------------------------
Class_any::Class_any(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_any)
{
}

void Class_any::Prepare(Environment &env)
{
}

bool Class_any::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class_any::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return true;
}

bool Class_any::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	value = Value::Null;
	return true;
}

}
