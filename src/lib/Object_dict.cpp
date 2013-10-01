//
// Object_dict
//
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_dict
//-----------------------------------------------------------------------------
Object *Object_dict::Clone() const
{
	return new Object_dict(*this);
}

Value Object_dict::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	const Value *pValue = Find(sig, valueIdx);
	if (sig.IsSignalled()) {
		return Value::Null;
	} else if (pValue == NULL) {
		SetError_KeyNotFound(sig, valueIdx);
		return Value::Null;
	}
	return *pValue;
}

void Object_dict::IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value)
{
	if (!ValueDict::IsValidKey(valueIdx)) {
		sig.SetError(ERR_KeyError, "invalid value type for key");
		return;
	}
	_valDict[valueIdx] = value;
}

Iterator *Object_dict::CreateIterator(Signal sig)
{
	return new IteratorItems(Object_dict::Reference(this));
}

String Object_dict::ToString(Signal sig, bool exprFlag)
{
	bool limitLenFlag = true;
	String str;
	str += "%{";
	foreach_const (ValueDict, iter, _valDict) {
		if (iter != _valDict.begin()) str += ", ";
		if (limitLenFlag && str.size() > 4096) {
			str += "...";
			break;
		}
		const Value &value = iter->first;
		if (value.IsString()) {
			str += MakeQuotedString(value.GetString());
		} else {
			str += value.ToString(sig, false);
		}
		str += " => ";
		str += iter->second.ToString(sig);
	}
	str += "}";
	return str;
}

const Value *Object_dict::Find(Signal sig, const Value &valueIdx) const
{
	if (!ValueDict::IsValidKey(valueIdx)) {
		sig.SetError(ERR_KeyError, "invalid value type for key");
		return NULL;
	}
	ValueDict::const_iterator iter = _valDict.find(valueIdx);
	return (iter == _valDict.end())? NULL : &iter->second;
}

void Object_dict::SetError_KeyNotFound(Signal sig, const Value &valueIdx)
{
	sig.SetError(ERR_KeyError, "dictionary doesn't have a key '%s'",
										valueIdx.ToString(sig).c_str());
}

//-----------------------------------------------------------------------------
// Object_dict::IteratorKeys
//-----------------------------------------------------------------------------
Object_dict::IteratorKeys::IteratorKeys(Object_dict *pObj) :
				Iterator(false), _pObj(pObj), _pCur(pObj->GetDict().begin())
{
}

Iterator *Object_dict::IteratorKeys::GetSource()
{
	return NULL;
}

bool Object_dict::IteratorKeys::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _pObj->GetDict().end()) return false;
	value = _pCur->first;
	_pCur++;
	return true;
}

String Object_dict::IteratorKeys::ToString(Signal sig) const
{
	return String("<iterator:dict#keys>");
}

void Object_dict::IteratorKeys::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_dict::IteratorValues
//-----------------------------------------------------------------------------
Object_dict::IteratorValues::IteratorValues(Object_dict *pObj) :
				Iterator(false), _pObj(pObj), _pCur(pObj->GetDict().begin())
{
}

Iterator *Object_dict::IteratorValues::GetSource()
{
	return NULL;
}

bool Object_dict::IteratorValues::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _pObj->GetDict().end()) return false;
	value = _pCur->second;
	_pCur++;
	return true;
}

String Object_dict::IteratorValues::ToString(Signal sig) const
{
	return String("<iterator:dict#values>");
}

void Object_dict::IteratorValues::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_dict::IteratorItems
//-----------------------------------------------------------------------------
Object_dict::IteratorItems::IteratorItems(Object_dict *pObj) :
				Iterator(false), _pObj(pObj), _pCur(pObj->GetDict().begin())
{
}

Iterator *Object_dict::IteratorItems::GetSource()
{
	return NULL;
}

bool Object_dict::IteratorItems::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pCur == _pObj->GetDict().end()) return false;
	ValueList &valList = value.InitAsList(*_pObj);
	valList.push_back(_pCur->first);
	valList.push_back(_pCur->second);
	_pCur++;
	return true;
}

String Object_dict::IteratorItems::ToString(Signal sig) const
{
	return String("<iterator:dict#items>");
}

void Object_dict::IteratorItems::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_dict::IteratorGet
//-----------------------------------------------------------------------------
Object_dict::IteratorGet::IteratorGet(Object_dict *pObj, Iterator *pIteratorKey,
					const Value &valDefault, bool raiseFlag, bool setDefaultFlag) :
	Iterator(pIteratorKey->IsInfinite()), _pObj(pObj), _pIteratorKey(pIteratorKey),
	_valDefault(valDefault), _raiseFlag(raiseFlag), _setDefaultFlag(setDefaultFlag)
{
}

Iterator *Object_dict::IteratorGet::GetSource()
{
	return NULL;
}

bool Object_dict::IteratorGet::DoNext(Environment &env, Signal sig, Value &value)
{
	Value valueIdx;
	if (!_pIteratorKey->Next(env, sig, valueIdx)) return false;
	const Value *pValue = _pObj->Find(sig, valueIdx);
	if (pValue != NULL) {
		value = *pValue;
	} else if (_raiseFlag) {
		Object_dict::SetError_KeyNotFound(sig, valueIdx);
		return false;
	} else {
		value = _valDefault;
		if (_setDefaultFlag) _pObj->IndexSet(env, sig, valueIdx, value);
		if (sig.IsSignalled()) return false;
	}
	return true;
}

String Object_dict::IteratorGet::ToString(Signal sig) const
{
	return String("<iterator:dict#get>");
}

void Object_dict::IteratorGet::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// dict(elem[]?):[icase] {block?}, %{block}
Gura_DeclareFunction(dict)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "elem", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_dict));
}

Gura_ImplementFunction(dict)
{
	Object_dict *pObj = new Object_dict(env, args.IsSet(Gura_Symbol(icase)));
	ValueDict &valDict = pObj->GetDict();
	ValueDict::StoreMode storeMode = ValueDict::STORE_Normal;
	if (args.GetValue(0).IsList() &&
					!valDict.Store(sig, args.GetList(0), storeMode)) {
		return Value::Null;
	}
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		AutoPtr<Environment> pEnvLister(new Environment(&env, ENVTYPE_lister));
		Value valueList =
				pExprBlock->GetExprOwner().ExecForList(*pEnvLister, sig, false, false);
		if (sig.IsSignalled() || !valueList.IsList()) return Value::Null;
		if (!valDict.Store(sig, valueList.GetList(), storeMode)) return Value::Null;
	}
	return Value(pObj);
}

//-----------------------------------------------------------------------------
// Gura Interface
//-----------------------------------------------------------------------------
// dict#len()
Gura_DeclareMethod(dict, len)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(dict, len)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	return Value(static_cast<Number>(pThis->GetDict().size()));
}

// dict#get(key, default?:nomap):map:[raise]
Gura_DeclareMethod(dict, get)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	DeclareArg(env, "default", VTYPE_any, OCCUR_ZeroOrOnce, FLAG_NoMap);
	DeclareAttr(Gura_Symbol(raise));
}

Gura_ImplementMethod(dict, get)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	const Value &valueIdx = args.GetValue(0);
	bool raiseFlag = args.IsSet(Gura_Symbol(raise));
	const Value *pValue = pThis->Find(sig, valueIdx);
	if (pValue != NULL) {
		return *pValue;
	} else if (raiseFlag) {
		Object_dict::SetError_KeyNotFound(sig, valueIdx);
		return Value::Null;
	} else {
		const Value &value = args.GetValue(1);
		return value;
	}
}

// dict#gets(key, default?):map:[raise]
Gura_DeclareMethod(dict, gets)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	DeclareArg(env, "default", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(raise));
}

Gura_ImplementMethod(dict, gets)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	const Value &valueIdx = args.GetValue(0);
	bool raiseFlag = args.IsSet(Gura_Symbol(raise));
	const Value *pValue = pThis->Find(sig, valueIdx);
	if (pValue != NULL) {
		return *pValue;
	} else if (raiseFlag) {
		Object_dict::SetError_KeyNotFound(sig, valueIdx);
		return Value::Null;
	} else {
		const Value &value = args.GetValue(1);
		return value;
	}
}

// dict#set(key, value:nomap):map:reduce
Gura_DeclareMethod(dict, set)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	DeclareArg(env, "value", VTYPE_any, OCCUR_Once, FLAG_NoMap);
}

Gura_ImplementMethod(dict, set)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	const Value &valueIdx = args.GetValue(0);
	pThis->IndexSet(env, sig, args.GetValue(0), args.GetValue(1));
	return args.GetThis();
}

// dict#setdefault(key, value:nomap):map
Gura_DeclareMethod(dict, setdefault)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	DeclareArg(env, "value", VTYPE_any, OCCUR_Once, FLAG_NoMap);
}

Gura_ImplementMethod(dict, setdefault)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	const Value &valueIdx = args.GetValue(0);
	const Value *pValue = pThis->Find(sig, valueIdx);
	if (pValue != NULL) return *pValue;
	const Value &value = args.GetValue(1);
	pThis->IndexSet(env, sig, valueIdx, value);
	if (sig.IsSignalled()) return Value::Null;
	return value;
}

// dict#sets(key, value):map:void
Gura_DeclareMethod(dict, sets)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementMethod(dict, sets)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	const Value &valueIdx = args.GetValue(0);
	pThis->IndexSet(env, sig, args.GetValue(0), args.GetValue(1));
	return Value::Null;
}

// dict#store(elems?):reduce:[default] {block?}
Gura_DeclareMethod(dict, store)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "elems", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(default_));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(dict, store)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	ValueDict &valDict = pThis->GetDict();
	ValueDict::StoreMode storeMode = args.IsSet(Gura_Symbol(default_))?
					ValueDict::STORE_Default : ValueDict::STORE_AllowDup;
	if (args.GetValue(0).IsList()) {
		if (!valDict.Store(sig, args.GetList(0), storeMode)) {
			return Value::Null;
		}
	} else if (args.GetValue(0).IsDict()) {
		if (!valDict.Store(sig, args.GetDict(0), storeMode)) {
			return Value::Null;
		}
	} else if (args.IsValid(0)) {
		sig.SetError(ERR_ValueError, "invalid argument type");
		return Value::Null;
	}
	if (args.IsBlockSpecified()) {
		const Expr_Block *pExprBlock = args.GetBlock(env, sig);
		if (sig.IsSignalled()) return Value::Null;
		AutoPtr<Environment> pEnvLister(new Environment(&env, ENVTYPE_lister));
		Value valueList =
				pExprBlock->GetExprOwner().ExecForList(*pEnvLister, sig, false, false);
		if (sig.IsSignalled() || !valueList.IsList()) return Value::Null;
		if (!valDict.Store(sig, valueList.GetList(), storeMode)) return Value::Null;
	}
	return args.GetThis();
}

// dict#haskey(key):map
Gura_DeclareMethod(dict, haskey)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
}

Gura_ImplementMethod(dict, haskey)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	const Value &valueIdx = args.GetValue(0);
	const Value *pValue = pThis->Find(sig, valueIdx);
	return Value(pValue != NULL);
}

// dict#keys() {block?}
Gura_DeclareMethod(dict, keys)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(dict, keys)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	Object_dict *pObj = Object_dict::Reference(pThis);
	return ReturnIterator(env, sig, args,
							new Object_dict::IteratorKeys(pObj));
}

// dict#values() {block?}
Gura_DeclareMethod(dict, values)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(dict, values)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	Object_dict *pObj = Object_dict::Reference(pThis);
	return ReturnIterator(env, sig, args,
							new Object_dict::IteratorValues(pObj));
}

// dict#items() {block?}
Gura_DeclareMethod(dict, items)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(dict, items)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	Object_dict *pObj = Object_dict::Reference(pThis);
	return ReturnIterator(env, sig, args,
							new Object_dict::IteratorItems(pObj));
}

// dict#clear()
Gura_DeclareMethod(dict, clear)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(dict, clear)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	pThis->GetDict().clear();
	return Value::Null;
}

// dict#erase(key):map
Gura_DeclareMethod(dict, erase)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
}

Gura_ImplementMethod(dict, erase)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	pThis->GetDict().erase(args.GetValue(0));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_dict::Class_dict(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_dict)
{
}

void Class_dict::Prepare(Environment &env)
{
	Gura_AssignFunction(dict);
	Gura_AssignFunctionEx(dict, "%");
	Gura_AssignMethod(dict, len);
	Gura_AssignMethod(dict, get);
	Gura_AssignMethod(dict, gets);
	Gura_AssignMethod(dict, set);
	Gura_AssignMethod(dict, sets);
	Gura_AssignMethod(dict, store);
	Gura_AssignMethod(dict, setdefault);
	Gura_AssignMethod(dict, haskey);
	Gura_AssignMethod(dict, keys);
	Gura_AssignMethod(dict, values);
	Gura_AssignMethod(dict, items);
	Gura_AssignMethod(dict, clear);
	Gura_AssignMethod(dict, erase);
}

bool Class_dict::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	bool ignoreCaseFlag = Object_dict::GetObject(value)->GetIgnoreCaseFlag();
	if (!stream.SerializeBoolean(sig, ignoreCaseFlag)) return false;
	return value.GetDict().Serialize(env, sig, stream);
}

bool Class_dict::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	bool ignoreCaseFlag = false;
	if (!stream.DeserializeBoolean(sig, ignoreCaseFlag)) return false;
	ValueDict &valDict = value.InitAsDict(env, ignoreCaseFlag);
	return valDict.Deserialize(env, sig, stream);
}

Object *Class_dict::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return new Object_dict((pClass == NULL)? this : pClass, true);
}

}
