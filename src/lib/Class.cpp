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
	if (pFunc == NULL) return;
	Signal &sig = pClassCustom->GetSignal();
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(valueThis);
	pFunc->Eval(*this, sig, *pArgs);
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
	for (const Class *pClass = _pClass.get(); pClass != NULL;
									pClass = pClass->GetClassSuper()) {
		if (pClass->GetValueType() == valType) return true;
	}
	return false;
}

Value Object::EmptyIndexGet(Environment &env, Signal sig)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitemx__), ENVREF_Escalate);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
		return Value::Null;
	}
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(valueThis);
	return pFunc->Eval(*this, sig, *pArgs);
}

void Object::EmptyIndexSet(Environment &env, Signal sig, const Value &value)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setitemx__), ENVREF_Escalate);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "empty-indexed setting access is not supported");
		return;
	}
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetValue(value);
	pArgs->SetThis(valueThis);
	pFunc->Eval(*this, sig, *pArgs);
}

Value Object::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitem__), ENVREF_Escalate);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "indexed getting access is not supported");
		return Value::Null;
	}
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetValue(valueIdx);
	pArgs->SetThis(valueThis);
	return pFunc->Eval(*this, sig, *pArgs);
}

void Object::IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setitem__), ENVREF_Escalate);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "indexed setting access is not supported");
		return;
	}
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetValues(valueIdx, value);
	pArgs->SetThis(valueThis);
	pFunc->Eval(*this, sig, *pArgs);
}

bool Object::DirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	//foreach_const (ValueMap, iter, GetTopFrame().GetValueMap()) {
	//	symbols.insert(iter->first);
	//}
	foreach_const (FrameOwner, ppFrame, GetFrameOwner()) {
		const Frame *pFrame = *ppFrame;
		if (pFrame->IsType(ENVTYPE_class) || pFrame->IsType(ENVTYPE_object)) {
			foreach_const (ValueMap, iter, pFrame->GetValueMap()) {
				symbols.insert(iter->first);
			}
		}
	}
	return DoDirProp(env, sig, symbols);
}

Value Object::EvalMethod(Environment &env, Signal sig, const Function *pFunc, const ValueList &valListArg)
{
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(valueThis);
	pArgs->SetValueListArg(valListArg);
	return pFunc->Eval(env, sig, *pArgs);
}

Value Object::EvalMethod(Environment &env, Signal sig, const Symbol *pSymbol,
							const ValueList &valListArg, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	const Function *pFunc = LookupFunction(pSymbol, ENVREF_Escalate);
	if (pFunc == NULL) return Value::Null;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	evaluatedFlag = true;
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(valueThis);
	pArgs->SetValueListArg(valListArg);
	return pFunc->Eval(env, sig, *pArgs);
}

Value Object::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getprop__), ENVREF_Escalate);
	if (pFunc == NULL) return Value::Null;
	evaluatedFlag = true;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetValue(Value(pSymbol));
	pArgs->SetThis(valueThis);
	return pFunc->Eval(*this, sig, *pArgs);
}

Value Object::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setprop__), ENVREF_Escalate);
	if (pFunc == NULL) return Value::Null;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged); // reference to this
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetValues(Value(pSymbol), value);
	pArgs->SetThis(valueThis);
	Value result = pFunc->Eval(*this, sig, *pArgs);
	evaluatedFlag = result.GetBoolean();
	return value;
}

String Object::ToString(bool exprFlag)
{
	Signal sig;
	bool evaluatedFlag = false;
	Value value = EvalMethod(*this, sig, Gura_Symbol(__str__),
											ValueList::Null, evaluatedFlag);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(object)
{
	Object *pObj = new Object(env.LookupClass(VTYPE_object));
	return ReturnValue(env, sig, args, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of primitive methods
//-----------------------------------------------------------------------------
// object#is(obj)
Gura_DeclareMethodPrimitive(Object, is)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any);
}

Gura_ImplementMethod(Object, is)
{
	return Value(args.GetThis().Is(args.GetValue(0)));
}

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
	if ((valType == VTYPE_number || valType == VTYPE_rational) &&
								valTypeCmp == VTYPE_complex) return Value(true);
	if (valType == VTYPE_rational && valTypeCmp == VTYPE_number) return Value(true);
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

// object#nomap() {block?}
Gura_DeclareMethodPrimitive(Object, nomap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(Object, nomap)
{
	Value rtn(args.GetThis());
	rtn.AddFlags(VFLAG_NoMap);
	return ReturnValue(env, sig, args, rtn);
}

// object#tonumber():[strict,raise,zero,nil]
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

// object#tostring()
Gura_DeclareMethodPrimitive(Object, tostring)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Object, tostring)
{
	String str = args.GetThis().ToString(false);
	if (sig.IsSignalled()) return Value::Null;
	return Value(str);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// object.__call__(symbol:symbol, args*, dict%):map {block?}
class Gura_Method(Object, __call__) : public Function {
public:
	Gura_Method(Object, __call__)(Environment &env, const char *name = "__call__");
	virtual Value Call(Environment &env, Signal sig, Args &args) const;
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

Value Gura_Method(Object, __call__)::Call(Environment &env, Signal sig, Args &args) const
{
	const Fundamental *pThis = args.GetThisFundamental();
	if (args.GetExprListArg().size() < 1) {
		sig.SetError(ERR_ValueError, "invalid argument for __call__()");
		return Value::Null;
	}
	SeqPostHandler *pSeqPostHandler = NULL;
	Value value = args.GetExprListArg().front()->Exec2(env, sig, pSeqPostHandler);
	if (sig.IsSignalled()) return Value::Null;
	if (!value.Is_symbol()) {
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
	if (!valueFunc.Is_function()) {
		sig.SetError(ERR_ValueError, "invalid argument for __call__()");
		return Value::Null;
	}
	const Function *pFunc = valueFunc.GetFunction();
	AutoPtr<Args> pArgsSub(new Args(args));
	AutoPtr<ExprOwner> pExprOwnerArg(new ExprOwner());
	ExprList::const_iterator ppExprArg = args.GetExprListArg().begin();
	ppExprArg++;
	for ( ; ppExprArg != args.GetExprListArg().end(); ppExprArg++) {
		const Expr *pExprArg = *ppExprArg;
		pExprOwnerArg->push_back(pExprArg->Reference());
	}
	pArgsSub->SetExprOwnerArg(pExprOwnerArg.release());
	return pFunc->Call(env, sig, *pArgsSub);
}

Value Gura_Method(Object, __call__)::DoEval(Environment &env, Signal sig, Args &args) const
{
	return Value::Null;
}

// object#__iter__()
Gura_DeclareMethod(Object, __iter__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Object, __iter__)
{
	Iterator *pIterator = args.GetThis().CreateIterator(sig);
	if (sig.IsSignalled()) return Value::Null;
	return Value(new Object_iterator(env, pIterator));
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

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
bool Class::IsClass() const { return true; }
bool Class::IsCustom() const { return false; }

Class::Class(Environment *pEnvOuter, ValueType valType) :
	Fundamental(pEnvOuter, ENVTYPE_class),
	_pClassSuper(pEnvOuter->IsClass()?
			Class::Reference(dynamic_cast<Class *>(pEnvOuter)) : NULL),
	_pConstructor(NULL), _pSymbol(Gura_Symbol(_anonymous_)), _valType(valType) 
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


Value Class::EmptyIndexGetPrimitive(Environment &env, Signal sig, const Value &valueThis) const
{
	sig.SetError(ERR_ValueError, "empty-indexed getting access is not supported");
	return Value::Null;
}

Value Class::IndexGetPrimitive(Environment &env, Signal sig,
									const Value &valueThis, const Value &valueIdx) const
{
	sig.SetError(ERR_ValueError, "indexed getting access is not supported");
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

String Class::ToString(bool exprFlag)
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

bool Class::Format_d(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%d qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_u(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%u qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_b(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%b qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_o(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%o qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_x(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%x qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_e(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%e qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_f(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%f qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_g(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%g qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::Format_s(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return pFormatter->PutAlignedString(sig, flags,
							value.ToString(false).c_str(), flags.precision);
}

bool Class::Format_c(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	sig.SetError(ERR_ValueError,
			"value type %s can not be formatted with %%c qualifier",
			MakeValueTypeName().c_str());
	return false;
}

bool Class::BuildContent(Environment &env, Signal sig, const Value &valueThis,
			const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable)
{
	AutoPtr<Environment> pEnvLocal(new Environment(this, ENVTYPE_local));
	foreach_const (ExprList, ppExpr, pExprBlock->GetExprOwner()) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsAssign()) {
			SeqPostHandler *pSeqPostHandler = NULL;
			const Expr_Assign *pExprAssign =
								dynamic_cast<const Expr_Assign *>(pExpr);
			pExprAssign->Exec(*pEnvLocal, sig, *this, pSymbolsAssignable, pSeqPostHandler);
		} else if (pExpr->IsCaller()) {
			SeqPostHandler *pSeqPostHandler = NULL;
			const Expr_Caller *pExprCaller =
								dynamic_cast<const Expr_Caller *>(pExpr);
			Value valueCar = pExprCaller->GetCar()->Exec2(*pEnvLocal, sig, pSeqPostHandler);
			if (sig.IsSignalled()) return false;
			Callable *pCallable = valueCar.GetObject();
			if (pCallable == NULL) {
				sig.SetError(ERR_TypeError, "object is not callable");
			} else {
				AutoPtr<Args> pArgs(new Args());
				pArgs->SetExprOwnerArg(pExprCaller->GetExprOwner().Reference());
				pArgs->SetThis(valueThis);
				pArgs->SetAttrs(pExprCaller->GetAttrs());
				pArgs->SetAttrsOpt(pExprCaller->GetAttrsOpt());
				pArgs->SetBlock(Expr_Block::Reference(pExprCaller->GetBlock()));
				pCallable->DoCall(*this, sig, *pArgs);
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
