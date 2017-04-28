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
		Fundamental(*pClass, ENVTYPE_object), _pClass(Class::Reference(pClass))
{
}

Object::~Object()
{
	if (!_pClass->IsCustom()) return;
	ClassCustom *pClassCustom = dynamic_cast<ClassCustom *>(_pClass.get());
	const Function *pFunc =
			pClassCustom->LookupFunction(Gura_Symbol(__del__), ENVREF_NoEscalate);
	if (pFunc == nullptr) return;
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
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

Value Object::MultiIndexGet(Environment &env, const ValueList &valListIdx)
{
	typedef std::pair<ValueList::const_iterator, ValueList::const_iterator> IteratorPair;
	typedef std::vector<IteratorPair> IteratorPairStack;
	if (valListIdx.empty()) return EmptyIndexGet(env);
	if (valListIdx.size() == 1 && !valListIdx.front().IsListOrIterator()) {
		return IndexGet(env, valListIdx.front());
	}
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	IteratorPairStack iteratorPairStack;
	iteratorPairStack.push_back(IteratorPair(valListIdx.begin(), valListIdx.end()));
	IteratorPairStack::reverse_iterator pIteratorPair = iteratorPairStack.rbegin();
	ValueList::const_iterator pValueIdx = pIteratorPair->first;
	for (;;) {
		while (pValueIdx == pIteratorPair->second) {
			iteratorPairStack.pop_back();
			if (iteratorPairStack.empty()) goto done;
			pValueIdx = pIteratorPair->first;
		}
		if (pValueIdx->Is_iterator()) {
			Iterator *pIterator = pValueIdx->GetIterator();
			Value valueIdx;
			while (pIterator->Next(env, valueIdx)) {
				Value value = IndexGet(env, *pValueIdx);
				if (env.IsSignalled()) return Value::Nil;
				pObjList->AddFast(value);
			}
			if (env.IsSignalled()) return Value::Nil;
		} else if (pValueIdx->Is_list()) {
			const ValueList &valListIdxSub = pValueIdx->GetList();
			iteratorPairStack.push_back(IteratorPair(valListIdxSub.begin(), valListIdxSub.end()));
			pIteratorPair = iteratorPairStack.rbegin();
			pValueIdx = pIteratorPair->first;
		} else {
			Value value = IndexGet(env, *pValueIdx);
			if (env.IsSignalled()) return Value::Nil;
			pObjList->AddFast(value);
		}
	}
done:
	pObjList->DetermineValueType();
	return rtn;
}

void Object::MultiIndexSet(Environment &env, const ValueList &valListIdx, const Value &value)
{
}

Value Object::EmptyIndexGet(Environment &env)
{
	Signal &sig = GetSignal();
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitemx__), ENVREF_Escalate);
	if (pFunc == nullptr) {
		sig.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
		return Value::Nil;
	}
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
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
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->StoreValue(env, value)) return;
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
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->StoreValue(env, valueIdx)) return Value::Nil;
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
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->StoreValue(env, valueIdx, value)) return;
	pArg->SetValueThis(valueThis);
	pFunc->Eval(*this, *pArg);
}

bool Object::DirProp(Environment &env, SymbolSet &symbols)
{
	foreach_const (FrameOwner, ppFrame, GetFrameOwner()) {
		const Frame *pFrame = *ppFrame;
		if (pFrame->IsType(ENVTYPE_class) || pFrame->IsType(ENVTYPE_object)) {
			foreach_const (ValueExMap, iter, pFrame->GetValueExMap()) {
				symbols.insert(iter->first);
			}
		}
	}
	GetClass()->ListPropDeclarationSymbols(symbols, true);
	return DoDirProp(env, symbols);
}

Value Object::EvalMethod(Environment &env, const Function *pFunc, const ValueList &valListArg)
{
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(valueThis);
	if (!pArg->StoreValues(env, valListArg)) return Value::Nil;
	return pFunc->Eval(env, *pArg);
}

Value Object::EvalMethod(Environment &env, const Symbol *pSymbol,
							const ValueList &valListArg, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	const Function *pFunc = LookupFunction(pSymbol, ENVREF_Escalate);
	if (pFunc == nullptr) return Value::Nil;
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
	evaluatedFlag = true;
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(valueThis);
	if (!pArg->StoreValues(env, valListArg)) return Value::Nil;
	return pFunc->Eval(env, *pArg);
}

Value Object::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getprop__), ENVREF_Escalate);
	if (pFunc == nullptr) return Value::Nil;
	evaluatedFlag = true;
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->StoreValue(env, Value(pSymbol))) return Value::Nil;
	pArg->SetValueThis(valueThis);
	return pFunc->Eval(*this, *pArg);
}

Value Object::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setprop__), ENVREF_Escalate);
	if (pFunc == nullptr) return Value::Nil;
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Argument> pArg(new Argument(pFunc));
	if (!pArg->StoreValue(env, Value(pSymbol), value)) return Value::Nil;
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
	Fundamental *pThis = arg.GetValueThis().IsFundamental()?
					arg.GetFundamentalThis() : arg.GetValueThis().GetClass();
	Value valueToCall;
	const Value *pValue = pThis->LookupValue(pSymbol, ENVREF_Escalate);
	if (pValue == nullptr) {
		valueToCall = pThis->GetProp(pSymbol, SymbolSet::Empty);
		if (sig.IsSignalled()) return Value::Nil;
	} else {
		valueToCall = *pValue;
	}
	if (!valueToCall.IsFundamental()) {
		sig.SetError(ERR_ValueError,
					 "instance associated with a symbol '%s' is not a callable",
					 pSymbol->GetName());
		return Value::Nil;
	}
	Fundamental *pFund = valueToCall.GetFundamental();
	ExprList exprListArg;
	exprListArg.reserve(arg.GetList(1).size());
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		exprListArg.push_back(const_cast<Expr *>(pValue->GetExpr()));
	}
	CallerInfo callerInfo(exprListArg, arg.GetBlock(),
						  arg.GetAttrsShared(), arg.GetFunction()->GetAttrsOptShared());
	return pFund->DoCall(env, callerInfo, FLAG_None,
						 arg.GetValueThis(), nullptr, arg.GetTrailCtrlHolder());
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

// object#__propdecls__() {block?}
Gura_DeclareMethodPrimitive(Object, __propdecls__)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(Object, __propdecls__)
{
	AutoPtr<Iterator_propdeclaration> pIterator(new Iterator_propdeclaration());
	const Value &valueThis = arg.GetValueThis();
	const Class *pClass = valueThis.IsClass()? valueThis.GetClassItself() : valueThis.GetClass();
	const PropDeclarationMap *pPropDeclarationMap = pClass->GetPropDeclarationMap();
	if (pPropDeclarationMap != nullptr) {
		pIterator->AddPropDeclarations(*pPropDeclarationMap);
	}
	return ReturnIterator(env, arg, pIterator.release());
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
	const Value *pValueDefault = arg.IsDefined(1)? &arg.GetValue(1) : nullptr;
	return arg.GetValueThis().GetProp(env, arg.GetSymbol(0), SymbolSet::Empty, pValueDefault);
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
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(arg.GetList(0));
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
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(arg.GetList(0));
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
// Implementation of class
//-----------------------------------------------------------------------------
bool Class::IsClass() const { return true; }
bool Class::IsCustom() const { return false; }

Class::Class(Environment *pEnvOuter, ValueType valType) :
	Fundamental(*pEnvOuter, ENVTYPE_class),
	_pClassSuper(pEnvOuter->IsClass()?
			Class::Reference(dynamic_cast<Class *>(pEnvOuter)) : nullptr),
	_valType(valType), _pSymbol(Gura_Symbol(_anonymous_)), _pConstructor(nullptr),
	_pHelpProvider(new HelpProvider(this))
{
}

Class::~Class()
{
	_pHelpProvider->SetHolder(nullptr);
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
				foreach_const (ValueExMap, iter, pFrame->GetValueExMap()) {
					symbols.insert(iter->first);
				}
			}
		}
	} else {
		foreach_const (ValueExMap, iter, GetTopFrame()->GetValueExMap()) {
			symbols.insert(iter->first);
		}
	}
	ListPropDeclarationSymbols(symbols, escalateFlag);
	return DoDirProp(env, symbols);
}

bool Class::CastFrom(Environment &env, Value &value, ULong flags)
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
	if (GetConstructor() == nullptr) {
		str += GetName();
	} else {
		str += GetConstructor()->ToString();
	}
	str += ">";
	return str;
}

Value Class::DoCall(Environment &env, const CallerInfo &callerInfo, ULong flags,
					const Value &valueThis, const Iterator *pIteratorThis,
					const TrailCtrlHolder *pTrailCtrlHolder)
{
	if (GetConstructor() == nullptr) {
		SetError_NoConstructor();
		return Value::Nil;
	}
	AutoPtr<Argument> pArg(new Argument(GetConstructor(), callerInfo));
	pArg->SetValueThis(valueThis);
	pArg->SetTrailCtrlHolder(TrailCtrlHolder::Reference(pTrailCtrlHolder));
	if (!pArg->EvalExpr(env, callerInfo.GetExprListArg())) return Value::Nil;
	return GetConstructor()->EvalAuto(env, *pArg);
}

void Class::Prepare(Environment &env)
{
	DeriveOperators();
	DerivePropDeclarations();
	DoPrepare(env);
}

void Class::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(object);
	// Assignment of methods
	Gura_AssignMethod(Object, __call__);
	Gura_AssignMethod(Object, __iter__);
	Gura_AssignMethod(Object, __propdecls__);
	Gura_AssignMethod(Object, getprop_X);
	Gura_AssignMethod(Object, setprop_X);
	Gura_AssignMethod(Object, clone);
	Gura_AssignMethod(Object, is);			// primitive method
	Gura_AssignMethod(Object, isnil);		// primitive method
	Gura_AssignMethod(Object, istype);		// primitive method
	Gura_AssignMethod(Object, isinstance);	// primitive method
	Gura_AssignMethod(Object, nomap);		// primitive method
	Gura_AssignMethod(Object, tonumber);	// primitive method
	Gura_AssignMethod(Object, tostring);	// primitive method
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

void Class::AddOperatorEntry(OperatorEntry *pOperatorEntry)
{
	foreach (Operator::EntryList, ppOperatorEntry, _operatorEntryList) {
		if ((*ppOperatorEntry)->IsIdentical(*pOperatorEntry)) {
			_operatorEntryList.erase(ppOperatorEntry);
			break;
		}
	}
	_operatorEntryList.push_back(pOperatorEntry);
}

void Class::DeriveOperators()
{
	if (_pClassSuper.IsNull()) return;
	Environment &env = *this;
	ValueType valTypeSuper = _pClassSuper->GetValueType();
	Operator::EntryList operatorEntryList;
	foreach_const (Operator::EntryList, ppOperatorEntryOrg, _pClassSuper->GetOperatorEntryList()) {
		OperatorEntry *pOperatorEntryOrg = *ppOperatorEntryOrg;
		ValueType valTypeLeft = pOperatorEntryOrg->GetValueTypeLeft();
		ValueType valTypeRight = pOperatorEntryOrg->GetValueTypeRight();
		if (valTypeLeft == valTypeSuper && valTypeRight == valTypeSuper) {
			operatorEntryList.push_back(new OperatorEntryDerived(
											pOperatorEntryOrg, valTypeLeft, _valType));
			operatorEntryList.push_back(new OperatorEntryDerived(
											pOperatorEntryOrg, _valType, valTypeRight));
			operatorEntryList.push_back(new OperatorEntryDerived(
											pOperatorEntryOrg, _valType, _valType));
		} else if (valTypeLeft == valTypeSuper) {
			operatorEntryList.push_back(new OperatorEntryDerived(
											pOperatorEntryOrg, _valType, valTypeRight));
		} else if (valTypeRight == valTypeSuper) {
			operatorEntryList.push_back(new OperatorEntryDerived(
											pOperatorEntryOrg, valTypeLeft, _valType));
		}
	}
	foreach (Operator::EntryList, ppOperatorEntry, operatorEntryList) {
		Operator::Assign(env, *ppOperatorEntry);
	}
}

void Class::DerivePropDeclarations()
{
	if (_pClassSuper.IsNull()) return;
	if (_pClassSuper->_pPropDeclarationMap == nullptr) return;
	if (_pPropDeclarationMap.get() == nullptr) _pPropDeclarationMap.reset(new PropDeclarationMap());
	*_pPropDeclarationMap = *_pClassSuper->_pPropDeclarationMap;
}

void Class::AssignPropDeclaration(PropDeclaration *pPropDeclaration)
{
	if (_pPropDeclarationMap.get() == nullptr) _pPropDeclarationMap.reset(new PropDeclarationMap());
	(*_pPropDeclarationMap)[pPropDeclaration->GetSymbol()] = pPropDeclaration;
}

const PropDeclaration *Class::LookupPropDeclaration(const Symbol *pSymbol)
{
	if (_pPropDeclarationMap.get() == nullptr) return nullptr;
	auto iter = _pPropDeclarationMap->find(pSymbol);
	return (iter == _pPropDeclarationMap->end())? nullptr : iter->second;
}

void Class::ListPropDeclarationSymbols(SymbolSet &symbols, bool escalateFlag)
{
	if (_pPropDeclarationMap.get() != nullptr) {
		foreach (PropDeclarationMap, iter, *_pPropDeclarationMap) {
			symbols.insert(iter->first);
		}
	}
	if (escalateFlag && !_pClassSuper.IsNull()) {
		_pClassSuper->ListPropDeclarationSymbols(symbols, escalateFlag);
	}
}

bool Class::BuildContent(Environment &env, const Value &valueThis, const Expr_Block *pExprBlock)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Environment> pEnvLocal(Derive(ENVTYPE_local));
	foreach_const (ExprList, ppExpr, pExprBlock->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsAssign()) {
			const Expr_Assign *pExprAssign = dynamic_cast<const Expr_Assign *>(pExpr);
			pExprAssign->DoExecSub(*pEnvLocal, *this);
		} else if (pExpr->IsCaller()) {
			const Expr_Caller *pExprCaller = dynamic_cast<const Expr_Caller *>(pExpr);
			Value valueCar = pExprCaller->GetCar()->Exec(*pEnvLocal);
			if (sig.IsSignalled()) return false;
			if (valueCar.IsObject()) {
				Callable *pObj = valueCar.GetObject();
				pObj->DoCall(*this, pExprCaller->GetCallerInfo(), FLAG_None,
							 valueThis, nullptr, nullptr);
				if (sig.IsSignalled()) {
					sig.AddExprCause(pExprCaller);
					return false;
				}
			} else {
				sig.SetError(ERR_TypeError, "object is not callable");
				return false;
			}
		} else {
			sig.SetError(ERR_SyntaxError, "invalid element in class constructor");
		}
		if (sig.IsSignalled()) return false;
	}
	return true;
}

void Class::SetError_NoConstructor() const
{
	SetError(ERR_ValueError, "class %s doesn't have a constructor", GetName());
}

String Class::MakeHelpTitle() const
{
	return MakeValueTypeName();
}

//-----------------------------------------------------------------------------
// ClassPrimitive
//-----------------------------------------------------------------------------
Value ClassPrimitive::EvalEmptyIndexGet(Environment &env, const Value &valueThis) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
	return Value::Nil;
}

Value ClassPrimitive::EvalIndexGet(Environment &env,
								   const Value &valueThis, const Value &valueIdx) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError, "indexed getting access is not supported");
	return Value::Nil;
}

void ClassPrimitive::EvalIndexSet(Environment &env,
								   const Value &valueThis, const Value &valueIdx, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError, "indexed getting access is not supported");
}

//-----------------------------------------------------------------------------
// ClassFundamental
//-----------------------------------------------------------------------------
Value ClassFundamental::EvalEmptyIndexGet(Environment &env, const Value &valueThis) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
	return Value::Nil;
}

Value ClassFundamental::EvalIndexGet(Environment &env,
								   const Value &valueThis, const Value &valueIdx) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError, "indexed getting access is not supported");
	return Value::Nil;
}

void ClassFundamental::EvalIndexSet(Environment &env,
									 const Value &valueThis, const Value &valueIdx, const Value &value) const
{
	Signal &sig = GetSignal();
	sig.SetError(ERR_ValueError, "indexed getting access is not supported");
}

}
