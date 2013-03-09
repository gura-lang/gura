#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------
// object#istype(type:expr):map
Gura_DeclareMethodPrimitive(Object, istype)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_expr);
}

Gura_ImplementMethod(Object, istype)
{
	SymbolList symbolList;
	if (!args.GetExpr(0)->GetChainedSymbolList(symbolList)) {
		sig.SetError(ERR_TypeError, "invalid type name");
		return Value::Null;
	}
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(symbolList);
	if (pValueTypeInfo == NULL) {
		sig.SetError(ERR_ValueError, "invalid type name");
		return Value::Null;
	}
	ValueType valType = args.GetThis().GetType();
	ValueType valTypeCmp = pValueTypeInfo->GetValueType();
	if (valType == VTYPE_number && valTypeCmp == VTYPE_complex) return Value(true);
	return Value(valType == valTypeCmp);
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
Gura_DeclareClassMethod(Object, getprop_X)
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
		return pThis->GetProp(sig, args.GetSymbol(0), attrs, &value);
	} else {
		return pThis->GetProp(sig, args.GetSymbol(0), attrs);
	}
}

// object.setprop!(symbol:symbol, value):map
Gura_DeclareClassMethod(Object, setprop_X)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementClassMethod(Object, setprop_X)
{
	Fundamental *pThis = args.GetThisFundamental();
	pThis->AssignValue(args.GetSymbol(0), args.GetValue(1), false);
	return Value::Null;
}

// object.call!(symbol:symbol, args*, dict%):map {block?}
class Gura_Method(Object, call_X) : public Function {
public:
	Gura_Method(Object, call_X)(Environment &env, const char *name);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

Gura_Method(Object, call_X)::Gura_Method(Object, call_X)(Environment &env, const char *name) :
						Function(env, Symbol::Add(name), FUNCTYPE_Class, FLAG_None)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareDictArg("dict");
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Value Gura_Method(Object, call_X)::EvalExpr(Environment &env, Signal sig, Args &args) const
{
	Fundamental *pThis = args.GetThisFundamental();
	ExprOwner exprOwnerArgs(args.GetExprListArg());
	const Expr *pExprArg = exprOwnerArgs.front();
	size_t nElems = 0;
	ValueList valListArg;
	if (!pExprArg->ExecInArg(env, sig, valListArg, nElems, false)) return Value::Null;
	if (valListArg.size() != 1) {
		sig.SetError(ERR_ValueError, "invalid argument for call!()");
		return Value::Null;
	}
	const Value &value = valListArg.front();
	if (!value.IsSymbol()) {
		sig.SetError(ERR_ValueError, "invalid argument for call!()");
		return Value::Null;
	}
	const Symbol *pSymbol = value.GetSymbol();
	Value valueFunc;
	const Value *pValue = pThis->LookupValue(pSymbol, true);
	if (pValue == NULL) {
		const SymbolSet &attrs = SymbolSet::Null;
		valueFunc = pThis->GetProp(sig, pSymbol, attrs);
		if (sig.IsSignalled()) return Value::Null;
	} else {
		valueFunc = *pValue;
	}
	if (!valueFunc.IsFunction()) {
		sig.SetError(ERR_ValueError, "invalid argument for call!()");
		return Value::Null;
	}
	const Function *pFunc = valueFunc.GetFunction();
	exprOwnerArgs.erase(exprOwnerArgs.begin());
	Args argsSub(args, exprOwnerArgs);
	return pFunc->EvalExpr(env, sig, argsSub);
}

Value Gura_Method(Object, call_X)::DoEval(Environment &env, Signal sig, Args &args) const
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
	// don't assign functions here, because the function objects themselves
	// shall be constructed in Class_function that is to be created after
	// this class!!!!!! instead, they must be assigned in Prepare() funtion below.
}

Class::~Class()
{
}

Object *Class::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return new Object((pClass == NULL)? this : pClass);
}

bool Class::DirProp(Signal sig, SymbolSet &symbols, bool escalateFlag)
{
	if (escalateFlag) {
		foreach_const (FrameList, ppFrame, GetFrameList()) {
			const Frame *pFrame = *ppFrame;
			if (pFrame->IsType(ENVTYPE_class) || pFrame->IsType(ENVTYPE_instance)) {
				foreach_const (ValueMap, iter, pFrame->GetValueMap()) {
					symbols.insert(iter->first);
				}
			}
		}
	} else {
		foreach_const (ValueMap, iter, GetTopFrame().GetValueMap()) {
			symbols.insert(iter->first);
		}
	}
	return DoDirProp(sig, symbols);
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
void Class::Prepare()
{
	Gura_AssignMethod(Object, istype);		// primitive method
	Gura_AssignMethod(Object, tonumber);	// primitive method
	Gura_AssignMethod(Object, tostring);	// primitive method
	Gura_AssignMethodEx(Object, setprop_X,	"setprop!");
	Gura_AssignMethodEx(Object, getprop_X,	"getprop!");
	Gura_AssignMethodEx(Object, call_X,		"call!");
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

//-----------------------------------------------------------------------------
// Class_nil
//-----------------------------------------------------------------------------
Class_nil::Class_nil(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_nil)
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
// Class_symbol
//-----------------------------------------------------------------------------
Class_symbol::Class_symbol(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_symbol)
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
	return stream.SerializeUChar(sig, static_cast<unsigned char>(value.GetBoolean()));
}

bool Class_boolean::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	unsigned char num = 0;
	if (!stream.DeserializeUChar(sig, num)) return false;
	value = Value(num != 0);
	return true;
}

//-----------------------------------------------------------------------------
// Class_number
//-----------------------------------------------------------------------------
// object#roundoff(threshold:number => 1e-10)
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
	Gura_AssignMethod(number, roundoff);	// primitive method
}

bool Class_number::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	bool allowPartFlag = false;
	bool successFlag;
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
Class_complex::Class_complex(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_complex)
{
}

bool Class_complex::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsNumber()) {		// cast number to complex
		return true;
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
// Class_
//-----------------------------------------------------------------------------
Class_fraction::Class_fraction(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_fraction)
{
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
	value = Value(Fraction(numerator, denominator));
	return true;
}

}
