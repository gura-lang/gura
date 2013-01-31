#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ObjectBase
//-----------------------------------------------------------------------------
ObjectBase::ObjectBase(Environment *pEnvOuter, EnvType envType) :
							Environment(pEnvOuter, envType), _cntRef(1)
{
}

ObjectBase::~ObjectBase()
{
}

bool ObjectBase::IsFunction() const { return false; }

bool ObjectBase::BuildContent(Environment &env, Signal sig, const Value &valueThis,
			const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable)
{
	Environment envLocal(&env, ENVTYPE_local);
	envLocal.AssignValue(Gura_Symbol(this), valueThis, false);
	foreach_const (ExprList, ppExpr, pExprBlock->GetExprList()) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsAssign()) {
			const Expr_Assign *pExprAssign =
								dynamic_cast<const Expr_Assign *>(pExpr);
			pExprAssign->Exec(envLocal, sig, *this, pSymbolsAssignable);
		} else {
			pExpr->Exec(envLocal, sig);
		}
		if (sig.IsSignalled()) return false;
	}
	return true;
}

Iterator *ObjectBase::CreateIterator(Signal sig)
{
	sig.SetError(ERR_ValueError, "object cannot generate iterator");
	return NULL;
}

Value ObjectBase::DoCall(Environment &env, Signal sig, Args &args)
{
	sig.SetError(ERR_TypeError, "object is not callable");
	return Value::Null;
}

bool ObjectBase::DoPropDir(Signal sig, SymbolSet &symbols)
{
	foreach_const (ValueMap, iter, GetTopFrame().GetValueMap()) {
		symbols.insert(iter->first);
	}
	return true;
}

void ObjectBase::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object
//-----------------------------------------------------------------------------
bool Object::IsObject() const { return true; }

Object::Object(Class *pClass) :
			ObjectBase(pClass, ENVTYPE_instance), _pClass(pClass->IncRef())
{
}

Object::~Object()
{
	if (!_pClass->IsCustom()) return;
	CustomClass *pClassCustom = dynamic_cast<CustomClass *>(_pClass.get());
	const Function *pFunc =
			pClassCustom->LookupFunction(Gura_Symbol(__del__), false);
	if (pFunc == NULL) return;
	Signal &sig = pClassCustom->GetSignal();
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	Args args(ValueList::Null, valueThis);
	pFunc->Eval(*this, sig, args);
}

Object *Object::Clone() const
{
	return new Object(*this);
}

void Object::Delete(Object *pObj)
{
	if (pObj != NULL && pObj->DecRef() <= 0) delete pObj;
}

const char *Object::GetClassName() const
{
	return (_pClass.IsNull())? "class" : _pClass->GetName();
}

bool Object::IsInstanceOf(ValueType valType) const
{
	for (const Class *pClass = _pClass.get(); pClass != NULL;
									pClass = pClass->GetClassSuper()) {
		if (pClass->GetValueType() == valType) return true;
	}
	return false;
}

int Object::Compare(const Object *pObj) const
{
	const char *p1 = reinterpret_cast<const char *>(this);
	const char *p2 = reinterpret_cast<const char *>(pObj);
	return (p1 < p2)? -1 : (p1 > p2)? +1 : 0;
}

Value Object::EmptyIndexGet(Environment &env, Signal sig)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitemx__), true);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
		return Value::Null;
	}
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	Args args(ValueList::Null, valueThis);
	return pFunc->Eval(*this, sig, args);
}

void Object::EmptyIndexSet(Environment &env, Signal sig, const Value &value)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setitemx__), true);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "empty-indexed setting access is not supported");
		return;
	}
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(value);
	Args args(valListArg, valueThis);
	pFunc->Eval(*this, sig, args);
}

Value Object::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitem__), true);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "indexed getting access is not supported");
		return Value::Null;
	}
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(valueIdx);
	Args args(valListArg, valueThis);
	return pFunc->Eval(*this, sig, args);
}

void Object::IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setitem__), true);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "indexed setting access is not supported");
		return;
	}
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	ValueList valListArg(valueIdx, value);
	Args args(valListArg, valueThis);
	pFunc->Eval(*this, sig, args);
}

Value Object::EvalMethod(Signal sig, const Function *pFunc, const ValueList &valListArg)
{
	const Function *pFuncSuccRequester = NULL;
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	Args args(valListArg, valueThis, NULL, false, &pFuncSuccRequester);
	return pFunc->Eval(*this, sig, args);
}

Value Object::EvalMethod(Signal sig, const Symbol *pSymbol,
							const ValueList &valListArg, bool &evaluatedFlag)
{
	const Function *pFuncSuccRequester = NULL;
	evaluatedFlag = false;
	const Function *pFunc = LookupFunction(pSymbol, true);
	if (pFunc == NULL) return Value::Null;
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	evaluatedFlag = true;
	Args args(valListArg, valueThis, NULL, false, &pFuncSuccRequester);
	return pFunc->Eval(*this, sig, args);
}

bool Object::DoPropDir(Signal sig, SymbolSet &symbols)
{
	foreach_const (FrameList, ppFrame, GetFrameList()) {
		const Frame *pFrame = *ppFrame;
		if (pFrame->IsType(ENVTYPE_class) || pFrame->IsType(ENVTYPE_instance)) {
			foreach_const (ValueMap, iter, pFrame->GetValueMap()) {
				symbols.insert(iter->first);
			}
		}
	}
	return true;
}

Value Object::DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getprop__), true);
	if (pFunc == NULL) return Value::Null;
	evaluatedFlag = true;
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(pSymbol));
	Args args(valListArg, valueThis);
	return pFunc->Eval(*this, sig, args);
}

Value Object::DoPropSet(Signal sig, const Symbol *pSymbol,
										const Value &value, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setprop__), true);
	if (pFunc == NULL) return Value::Null;
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	ValueList valListArg(Value(pSymbol), value);
	Args args(valListArg, valueThis);
	Value result = pFunc->Eval(*this, sig, args);
	evaluatedFlag = result.GetBoolean();
	return value;
}

String Object::ToString(Signal sig, bool exprFlag)
{
	bool evaluatedFlag = false;
	Value value = EvalMethod(sig, Gura_Symbol(__str__),
											ValueList::Null, evaluatedFlag);
	if (sig.IsSignalled()) return String("");
	if (evaluatedFlag) return value.ToString(sig, false);
	String str;
	str += "<";
	str += _pClass->GetName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object
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

// object#getprop!(symbol:symbol, default?:nomap):map
Gura_DeclareMethod(Object, getprop_X)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "default", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_NoMap);
}

Gura_ImplementMethod(Object, getprop_X)
{
	ObjectBase *pThis = args.GetThisObjBase();
	if (args.IsDefined(1)) {
		Value value = args.GetValue(1);
		return pThis->PropGet(sig, args.GetSymbol(0), &value);
	} else {
		return pThis->PropGet(sig, args.GetSymbol(0));
	}
}

// object#setprop!(symbol:symbol, value):map
Gura_DeclareMethod(Object, setprop_X)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementMethod(Object, setprop_X)
{
	ObjectBase *pThis = args.GetThisObjBase();
	pThis->AssignValue(args.GetSymbol(0), args.GetValue(1), false);
	return Value::Null;
}

// object#call!(symbol:symbol, args*, dict%):map {block?}
class Gura_Method(Object, call_X) : public Function {
public:
	Gura_Method(Object, call_X)(Environment &env, const char *name);
	virtual Value EvalExpr(Environment &env, Signal sig, Args &args) const;
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

Gura_Method(Object, call_X)::Gura_Method(Object, call_X)(Environment &env, const char *name) :
							Function(env, Symbol::Add(name), FUNCTYPE_Instance)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareDictArg("dict");
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Value Gura_Method(Object, call_X)::EvalExpr(Environment &env, Signal sig, Args &args) const
{
	ObjectBase *pThis = args.GetThisObjBase();
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
		valueFunc = pThis->PropGet(sig, pSymbol);
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

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------
bool Class::IsClass() const { return true; }
bool Class::IsCustom() const { return false; }

Class::Class(Environment *pEnvOuter, ValueType valType) :
	ObjectBase(pEnvOuter, ENVTYPE_class),
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

bool Class::DoPropDir(Signal sig, SymbolSet &symbols)
{
	foreach_const (FrameList, ppFrame, GetFrameList()) {
		const Frame *pFrame = *ppFrame;
		if (pFrame->IsType(ENVTYPE_class) || pFrame->IsType(ENVTYPE_instance)) {
			foreach_const (ValueMap, iter, pFrame->GetValueMap()) {
				symbols.insert(iter->first);
			}
		}
	}
	return true;
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
	const Complex *pNum = value.GetComplexPtr();
	if (!stream.SerializeDouble(sig, pNum->real())) return false;
	if (!stream.SerializeDouble(sig, pNum->imag())) return false;
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

}
