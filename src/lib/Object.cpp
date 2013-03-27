#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object
//-----------------------------------------------------------------------------
bool Object::IsObject() const { return true; }

Object::Object(Class *pClass) :
	Fundamental(pClass, ENVTYPE_instance), _pClass(Class::Reference(pClass))
{
}

Object::~Object()
{
	if (!_pClass->IsCustom()) return;
	CustomClass *pClassCustom = dynamic_cast<CustomClass *>(_pClass.get());
	const Function *pFunc =
			pClassCustom->LookupFunction(Gura_Symbol(__del__), ENVREFMODE_NoEscalate, 0);
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
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitemx__), ENVREFMODE_Normal, 0);
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
	const Function *pFunc = LookupFunction(Gura_Symbol(__setitemx__), ENVREFMODE_Normal, 0);
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
	const Function *pFunc = LookupFunction(Gura_Symbol(__getitem__), ENVREFMODE_Normal, 0);
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
	const Function *pFunc = LookupFunction(Gura_Symbol(__setitem__), ENVREFMODE_Normal, 0);
	if (pFunc == NULL) {
		sig.SetError(ERR_ValueError, "indexed setting access is not supported");
		return;
	}
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	ValueList valListArg(valueIdx, value);
	Args args(valListArg, valueThis);
	pFunc->Eval(*this, sig, args);
}

bool Object::DirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	//foreach_const (ValueMap, iter, GetTopFrame().GetValueMap()) {
	//	symbols.insert(iter->first);
	//}
	foreach_const (FrameOwner, ppFrame, GetFrameOwner()) {
		const Frame *pFrame = *ppFrame;
		if (pFrame->IsType(ENVTYPE_class) || pFrame->IsType(ENVTYPE_instance)) {
			foreach_const (ValueMap, iter, pFrame->GetValueMap()) {
				symbols.insert(iter->first);
			}
		}
	}
	return DoDirProp(env, sig, symbols);
}

Value Object::EvalMethod(Environment &env, Signal sig, const Function *pFunc, const ValueList &valListArg)
{
	const Function *pFuncLeader = NULL;
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	Args args(valListArg, valueThis, NULL, false, &pFuncLeader);
	return pFunc->Eval(env, sig, args);
}

Value Object::EvalMethod(Environment &env, Signal sig, const Symbol *pSymbol,
							const ValueList &valListArg, bool &evaluatedFlag)
{
	const Function *pFuncLeader = NULL;
	evaluatedFlag = false;
	const Function *pFunc = LookupFunction(pSymbol, ENVREFMODE_Normal, 0);
	if (pFunc == NULL) return Value::Null;
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	evaluatedFlag = true;
	Args args(valListArg, valueThis, NULL, false, &pFuncLeader);
	return pFunc->Eval(env, sig, args);
}

Value Object::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__getprop__), ENVREFMODE_Normal, 0);
	if (pFunc == NULL) return Value::Null;
	evaluatedFlag = true;
	Value valueThis(this, Value::FLAG_NoOwner); // reference to this
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(pSymbol));
	Args args(valListArg, valueThis);
	return pFunc->Eval(*this, sig, args);
}

Value Object::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Function *pFunc = LookupFunction(Gura_Symbol(__setprop__), ENVREFMODE_Normal, 0);
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
	Value value = EvalMethod(*this, sig, Gura_Symbol(__str__),
											ValueList::Null, evaluatedFlag);
	if (sig.IsSignalled()) return String("");
	if (evaluatedFlag) return value.ToString(sig, false);
	String str;
	str += "<";
	str += _pClass->GetName();
	str += ">";
	return str;
}

}
