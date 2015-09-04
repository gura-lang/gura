//=============================================================================
// Class
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object
//-----------------------------------------------------------------------------
bool Object::IsObject() const { return true; }

Object::Object(const Object &obj) :
		Fundamental(obj), _pClass(Class::Reference(obj._pClass.get()))
{
}

Object::Object(Class *pClass) :
		Fundamental(pClass, ENVTYPE_object), _pClass(Class::Reference(pClass))
{
}

Object::~Object()
{
	if (!_pClass->IsCustom()) return;
	ClassCustom *pClassCustom = dynamic_cast<ClassCustom *>(_pClass.get());
	const Function *pFunc =
			pClassCustom->LookupFunction(Gura_Symbol(__del__), ENVREF_NoEscalate);
	if (pFunc == nullptr) return;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(valueThis);
	pFunc->Eval(*this, *pArg);
}

Object *Object::Clone() const
{
	return new Object(*this);
}

const char *Object::GetClassName() const
{
	return (_pClass.IsNull())? "class" : _pClass->GetName();
}

bool Object::IsInstanceOf(ValueType valType) const
{
	for (const Class *pClass = _pClass.get(); pClass != nullptr;
									pClass = pClass->GetClassSuper()) {
		if (pClass->GetValueType() == valType) return true;
	}
	return false;
}

Value Object::EmptyIndexGet(Environment &env)
{
	Signal &sig = GetSignal();
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitemx__), ENVREF_Escalate);
	if (pFunc == nullptr) {
		sig.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
		return Value::Nil;
	}
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(valueThis);
	return pFunc->Eval(*this, *pArg);
}

void Object::EmptyIndexSet(Environment &env, const Value &value)
{
	Signal &sig = GetSignal();
	const Function *pFunc = LookupFunction(Gura_Symbol(__setitemx__), ENVREF_Escalate);
	if (pFunc == nullptr) {
		sig.SetError(ERR_ValueError, "empty-indexed setting access is not supported");
		return;
	}
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->AddValue(env, value)) return;
	pArg->SetValueThis(valueThis);
	pFunc->Eval(*this, *pArg);
}

Value Object::IndexGet(Environment &env, const Value &valueIdx)
{
	Signal &sig = GetSignal();
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitem__), ENVREF_Escalate);
	if (pFunc == nullptr) {
		sig.SetError(ERR_ValueError, "indexed getting access is not supported");
		return Value::Nil;
	}
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->AddValue(env, valueIdx)) return Value::Nil;
	pArg->SetValueThis(valueThis);
	return pFunc->Eval(*this, *pArg);
}

void Object::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	Signal &sig = GetSignal();
	const Function *pFunc = LookupFunction(Gura_Symbol(__setitem__), ENVREF_Escalate);
	if (pFunc == nullptr) {
		sig.SetError(ERR_ValueError, "indexed setting access is not supported");
		return;
	}
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->AddValue(env, valueIdx, value)) return;
	pArg->SetValueThis(valueThis);
	pFunc->Eval(*this, *pArg);
}

bool Object::DirProp(Environment &env, SymbolSet &symbols)
{
	foreach_const (FrameOwner, ppFrame, GetFrameOwner()) {
		const Frame *pFrame = *ppFrame;
		if (pFrame->IsType(ENVTYPE_class) || pFrame->IsType(ENVTYPE_object)) {
			foreach_const (ValueMap, iter, pFrame->GetValueMap()) {
				symbols.insert(iter->first);
			}
		}
	}
	return DoDirProp(env, symbols);
}

Value Object::EvalMethod(Environment &env, const Function *pFunc, const ValueList &valListArg)
{
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(valueThis);
	if (!pArg->AddValue(env, valListArg)) return Value::Nil;
	return pFunc->Eval(env, *pArg);
}

Value Object::EvalMethod(Environment &env, const Symbol *pSymbol,
							const ValueList &valListArg, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	const Function *pFunc = LookupFunction(pSymbol, ENVREF_Escalate);
	if (pFunc == nullptr) return Value::Nil;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	evaluatedFlag = true;
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(valueThis);
	if (!pArg->AddValue(env, valListArg)) return Value::Nil;
	return pFunc->Eval(env, *pArg);
}

Value Object::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getprop__), ENVREF_Escalate);
	if (pFunc == nullptr) return Value::Nil;
	evaluatedFlag = true;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->AddValue(env, Value(pSymbol))) return Value::Nil;
	pArg->SetValueThis(valueThis);
	return pFunc->Eval(*this, *pArg);
}

Value Object::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setprop__), ENVREF_Escalate);
	if (pFunc == nullptr) return Value::Nil;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->AddValue(env, Value(pSymbol), value)) return Value::Nil;
	pArg->SetValueThis(valueThis);
	Value result = pFunc->Eval(*this, *pArg);
	evaluatedFlag = result.GetBoolean();
	return value;
}

String Object::ToString(bool exprFlag)
{
	Signal sig;
	bool evaluatedFlag = false;
	Value value = EvalMethod(*this, Gura_Symbol(__str__),
											ValueList::Empty, evaluatedFlag);
	if (sig.IsSignalled()) return String("");
	if (evaluatedFlag) return value.ToString(false);
	String str;
	str += "<";
	str += _pClass->GetName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// object() {block?}
Gura_DeclareFunction(object)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(object)
{
	Object *pObj = new Object(env.LookupClass(VTYPE_object));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of primitive methods
//-----------------------------------------------------------------------------
// object#is(obj):map
Gura_DeclareMethodPrimitive(Object, is)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any);
}

Gura_ImplementMethod(Object, is)
{
	return Value(arg.GetValueThis().Is(arg.GetValue(0)));
}

// object#isnil()
Gura_DeclareMethodPrimitive(Object, isnil)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
}

Gura_ImplementMethod(Object, isnil)
{
	return Value(arg.GetValueThis().IsInvalid());
}

// object#istype(type+:expr):map
Gura_DeclareMethodPrimitive(Object, istype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(Object, istype)
{
	Signal &sig = env.GetSignal();
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, arg.GetList(0));
	if (pValueTypeInfo == nullptr) return Value::Nil;
	ValueType valType = arg.GetValueThis().GetValueType();
	ValueType valTypeCmp = pValueTypeInfo->GetValueType();
	if ((valType == VTYPE_number || valType == VTYPE_rational) &&
								valTypeCmp == VTYPE_complex) return Value(true);
	if (valType == VTYPE_rational && valTypeCmp == VTYPE_number) return Value(true);
	return Value(valType == valTypeCmp);
}

// object#isinstance(type+:expr):map
Gura_DeclareMethodPrimitive(Object, isinstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
}

Gura_ImplementMethod(Object, isinstance)
{
	Signal &sig = env.GetSignal();
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, arg.GetList(0));
	if (pValueTypeInfo == nullptr) return Value::Nil;
	return arg.GetValueThis().IsInstanceOf(pValueTypeInfo->GetValueType());
}

// object#nomap() {block?}
Gura_DeclareMethodPrimitive(Object, nomap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(Object, nomap)
{
	Value rtn(arg.GetValueThis());
	rtn.AddFlags(VFLAG_NoMap);
	return ReturnValue(env, arg, rtn);
}

// object#tonumber():[strict,raise,zero,nil]
Gura_DeclareMethodPrimitive(Object, tonumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(strict));
	DeclareAttr(Gura_Symbol(raise));
	DeclareAttr(Gura_Symbol(zero));
	DeclareAttr(Gura_Symbol(nil));
}

Gura_ImplementMethod(Object, tonumber)
{
	Signal &sig = env.GetSignal();
	bool allowPartFlag = !arg.IsSet(Gura_Symbol(strict));
	bool successFlag;
	Number num = arg.GetValueThis().ToNumber(allowPartFlag, successFlag);
	if (successFlag) {
		return Value(num);
	} else if (arg.IsSet(Gura_Symbol(raise))) {
		sig.SetError(ERR_ValueError, "failed to convert to number");
		return Value::Nil;
	} else if (arg.IsSet(Gura_Symbol(zero))) {
		return Value(0.);
	} else { // arg.IsSet(Gura_UserSymbol(nil)
		return Value::Nil;
	}
}

// object#tostring()
Gura_DeclareMethodPrimitive(Object, tostring)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Object, tostring)
{
	Signal &sig = env.GetSignal();
	String str = arg.GetValueThis().ToString(false);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(str);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// object.__call__(symbol:symbol, `args*):map:nonamed {block?}
Gura_DeclareMethod(Object, __call__)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map | FLAG_NoNamed);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(Object, __call__)
{
	Signal &sig = env.GetSignal();
	const Symbol *pSymbol = arg.GetSymbol(0);
	Fundamental *pThis = arg.GetFundamentalThis();
	if (pThis == nullptr) {
		pThis = arg.GetValueThis().GetClass();
	}
	Value valueToCall;
	const Value *pValue = pThis->LookupValue(pSymbol, ENVREF_Escalate);
	if (pValue == nullptr) {
		valueToCall = pThis->GetProp(env, pSymbol, SymbolSet::Empty);
		if (sig.IsSignalled()) return Value::Nil;
	} else {
		valueToCall = *pValue;
	}
	Fundamental *pFund = valueToCall.GetFundamental();
	if (pFund == nullptr) {
		sig.SetError(ERR_ValueError,
					 "instance associated with a symbol '%s' is not a callable",
					 pSymbol->GetName());
		return Value::Nil;
	}
	ExprList exprListArg;
	exprListArg.reserve(arg.GetList(1).size());
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		exprListArg.push_back(const_cast<Expr *>(pValue->GetExpr()));
	}
	CallerInfo callerInfo(exprListArg, arg.GetBlock(),
						  arg.GetAttrsShared(), arg.GetAttrsOptShared());
	return pFund->DoCall(env, callerInfo,
						 arg.GetValueThis(), nullptr, false, arg.GetTrailCtrlHolder());
}

// object#__iter__()
Gura_DeclareMethod(Object, __iter__)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Object, __iter__)
{
	Signal &sig = env.GetSignal();
	Iterator *pIterator = arg.GetValueThis().CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Nil;
	return Value(new Object_iterator(env, pIterator));
}

// object#clone()
Gura_DeclareMethod(Object, clone)
{
}

Gura_ImplementMethod(Object, clone)
{
	Signal &sig = env.GetSignal();
	Object *pObj = arg.GetObjectThis()->Clone();
	if (pObj == nullptr) {
		sig.SetError(ERR_ValueError, "failed to create a clone object");
		return Value::Nil;
	}
	return Value(pObj);
}

// object.getprop!(symbol:symbol, default?:nomap):map
Gura_DeclareClassMethodAlias(Object, getprop_X, "getprop!")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "default", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_NoMap);
}

Gura_ImplementClassMethod(Object, getprop_X)
{
	Fundamental *pThis = arg.GetFundamentalThis();
	const SymbolSet &attrs = SymbolSet::Empty;
	if (arg.IsDefined(1)) {
		Value value = arg.GetValue(1);
		return pThis->GetProp(env, arg.GetSymbol(0), attrs, &value);
	} else {
		return pThis->GetProp(env, arg.GetSymbol(0), attrs);
	}
}

// object.setprop!(symbol:symbol, value):map
Gura_DeclareClassMethodAlias(Object, setprop_X, "setprop!")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementClassMethod(Object, setprop_X)
{
	Fundamental *pThis = arg.GetFundamentalThis();
	pThis->AssignValue(arg.GetSymbol(0), arg.GetValue(1), EXTRA_Public);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
bool Class::IsClass() const { return true; }
bool Class::IsCustom() const { return false; }

Class::Class(Environment *pEnvOuter, ValueType valType) :
	Fundamental(pEnvOuter, ENVTYPE_class),
	_pClassSuper(pEnvOuter->IsClass()?
			Class::Reference(dynamic_cast<Class *>(pEnvOuter)) : nullptr),
	_valType(valType), _pSymbol(Gura_Symbol(_anonymous_)), _pConstructor(nullptr)
{
}

Object *Class::CreateDescendant(Environment &env, Class *pClass)
{
	return new Object((pClass == nullptr)? this : pClass);
}

bool Class::DirProp(Environment &env, SymbolSet &symbols, bool escalateFlag)
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
	return DoDirProp(env, symbols);
}

Value Class::GetPropPrimitive(Environment &env, const Value &valueThis,
				const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const
{
	return Value::Nil;
}


Value Class::EmptyIndexGetPrimitive(Environment &env, const Value &valueThis) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
	return Value::Nil;
}

Value Class::IndexGetPrimitive(Environment &env,
									const Value &valueThis, const Value &valueIdx) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError, "indexed getting access is not supported");
	return Value::Nil;
}

bool Class::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	return false;
}

bool Class::CastTo(Environment &env, Value &value, const Declaration &decl)
{
	return false;
}

String Class::ToString(bool exprFlag)
{
	String str;
	str += "<class:";
	str += GetName();
	//char buff[32];
	//::sprintf(buff, ":%08x", GetValueType());
	//str += buff;
	str += ">";
	return str;
}

// assignment
void Class::Prepare(Environment &env)
{
	Gura_AssignFunction(object);
	Gura_AssignMethod(Object, is);			// primitive method
	Gura_AssignMethod(Object, isnil);		// primitive method
	Gura_AssignMethod(Object, istype);		// primitive method
	Gura_AssignMethod(Object, isinstance);	// primitive method
	Gura_AssignMethod(Object, nomap);		// primitive method
	Gura_AssignMethod(Object, tonumber);	// primitive method
	Gura_AssignMethod(Object, tostring);	// primitive method
	Gura_AssignMethod(Object, __call__);
	Gura_AssignMethod(Object, __iter__);
	Gura_AssignMethod(Object, clone);
	Gura_AssignMethod(Object, getprop_X);
	Gura_AssignMethod(Object, setprop_X);
}

bool Class::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_IOError, "can't serialize class or module");
	return false;
}

bool Class::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_IOError, "can't deserialize class or module");
	return false;
}

bool Class::Format_d(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%d qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_u(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%u qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_b(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%b qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_o(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%o qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_x(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%x qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_e(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%e qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_f(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%f qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_g(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%g qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_s(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return pFormatter->PutAlignedString(sig, flags,
							value.ToString(false).c_str(), flags.precision);
}

bool Class::Format_c(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%c qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::BuildContent(Environment &env, const Value &valueThis,
			const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Environment> pEnvLocal(new Environment(this, ENVTYPE_local));
	foreach_const (ExprList, ppExpr, pExprBlock->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsAssign()) {
			SeqPostHandler *pSeqPostHandler = nullptr;
			const Expr_Assign *pExprAssign = dynamic_cast<const Expr_Assign *>(pExpr);
			pExprAssign->Exec(*pEnvLocal, *this, pSymbolsAssignable, pSeqPostHandler);
		} else if (pExpr->IsCaller()) {
			const Expr_Caller *pExprCaller = dynamic_cast<const Expr_Caller *>(pExpr);
			Value valueCar = pExprCaller->GetCar()->Exec(*pEnvLocal);
			if (sig.IsSignalled()) return false;
			Callable *pCallable = valueCar.GetObject();
			if (pCallable == nullptr) {
				sig.SetError(ERR_TypeError, "object is not callable");
			} else {
				pCallable->DoCall(*this, pExprCaller->GetCallerInfo(),
								  valueThis, nullptr, false, nullptr);
				if (sig.IsSignalled()) {
					sig.AddExprCause(pExprCaller);
					return false;
				}
			}
		} else {
			sig.SetError(ERR_SyntaxError, "invalid element in class constructor");
		}
		if (sig.IsSignalled()) return false;
	}
	return true;
}

}
