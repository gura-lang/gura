//=============================================================================
// Gura class: dict
//=============================================================================
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
	const Value *pValue = GetDict().Find(sig, valueIdx);
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
	if (!valueIdx.IsValidKey()) {
		sig.SetError(ERR_KeyError, "invalid value type for key");
		return;
	}
	GetDict()[valueIdx] = value;
}

Iterator *Object_dict::CreateIterator(Signal sig)
{
	return new IteratorItems(Object_dict::Reference(this));
}

String Object_dict::ToString(bool exprFlag)
{
	bool limitLenFlag = true;
	String str;
	str += "%{";
	foreach_const (ValueDict, iter, GetDict()) {
		if (iter != GetDict().begin()) str += ", ";
		if (limitLenFlag && str.size() > 4096) {
			str += "...";
			break;
		}
		const Value &value = iter->first;
		if (value.Is_string()) {
			str += MakeQuotedString(value.GetString());
		} else {
			str += value.ToString(false);
		}
		str += " => ";
		str += iter->second.ToString();
	}
	str += "}";
	return str;
}

void Object_dict::SetError_KeyNotFound(Signal sig, const Value &valueIdx)
{
	sig.SetError(ERR_KeyError, "dictionary doesn't have a key '%s'",
										valueIdx.ToString().c_str());
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

String Object_dict::IteratorKeys::ToString() const
{
	return String("dict#keys");
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

String Object_dict::IteratorValues::ToString() const
{
	return String("dict#values");
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

String Object_dict::IteratorItems::ToString() const
{
	return String("dict#items");
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
	const Value *pValue = _pObj->GetDict().Find(sig, valueIdx);
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

String Object_dict::IteratorGet::ToString() const
{
	return String("dict#get");
}

void Object_dict::IteratorGet::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// dict(elems?):[icase] {block?}, %{block}
Gura_DeclareFunction(dict)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "elems", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_dict));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `dict` instance.\n"
		"It takes a list of key-value pairs in an argument or in a block as shown below.\n"
		"\n"
		"    d = dict([['apple', 100], ['grape', 200], ['banana', 80]])\n"
		"\n"
		"    d = dict {\n"
		"        ['apple', 100], ['grape', 200], ['banana', 80]\n"
		"    }\n"
		"\n"
		"You can specify values of `number`, `string` or `symbol` as dictionary keys.\n"
		"\n"
		"You can also use the operator `=>` to create a key-value pair like below:\n"
		"\n"
		"    d = dict(['apple' => 100, 'grape' => 200, 'banana' => 80])\n"
		"\n"
		"    d = dict {\n"
		"        'apple' => 100, 'grape' => 200, 'banana' => 80\n"
		"    }\n"
		"\n"
		"The symbol `%` is an alias of the function `dict()`."
		"\n"
		"    d = %{\n"
		"        'apple' => 100, 'grape' => 200, 'banana' => 80\n"
		"    }\n"
		"\n"
		"In default, if keys contain alphabet characters, different cases are distinguished.\n"
		"Appending the attribute `:icase` would ignore cases in them.\n");
}

Gura_ImplementFunction(dict)
{
	Object_dict *pObj = new Object_dict(env, new ValueDict(args.IsSet(Gura_Symbol(icase))));
	ValueDict &valDict = pObj->GetDict();
	ValueDict::StoreMode storeMode = ValueDict::STORE_Strict;
	if (args.GetValue(0).Is_list()) {
		if (!valDict.Store(sig, args.GetList(0), storeMode)) {
			return Value::Null;
		}
	} else if (args.GetValue(0).Is_dict()) {
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
		ValueList valList;
		foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
			SeqPostHandler *pSeqPostHandler = NULL;
			Value value = (*ppExpr)->Exec2(*pEnvLister, sig, pSeqPostHandler);
			if (sig.IsSignalled()) {
				sig.AddExprCause(*ppExpr);
				return Value::Null;
			}
			valList.push_back(value);
		}
		if (!valDict.Store(sig, valList, storeMode)) return Value::Null;
	}
	return Value(pObj);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// dict#clear()
Gura_DeclareMethod(dict, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Clears all the key-value pairs in the dictionary.");
}

Gura_ImplementMethod(dict, clear)
{
	ValueDict &valDict = Object_dict::GetThisObj(args)->GetDict();
	valDict.clear();
	return Value::Null;
}

// dict#erase(key):map
Gura_DeclareMethod(dict, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Erases a key-value pair that mathces the provided `key`.\n"
		"\n"
		"The `key` is either `number`, `string` or `symbol`.\n");
}

Gura_ImplementMethod(dict, erase)
{
	ValueDict &valDict = Object_dict::GetThisObj(args)->GetDict();
	valDict.erase(args.GetValue(0));
	return Value::Null;
}

// dict#get(key, default?):map:[raise]
Gura_DeclareMethod(dict, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	DeclareArg(env, "default", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(raise));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Seeks a value that is associated with the specified `key`.\n"
		"\n"
		"The method would return `nil` as its default value\n"
		"when the specified key doesn't exist in the dictionary.\n"
		"It would use different value if the argument `default` is specified.\n"
		"\n"
		"Since the `default` value is also processed with implicit mapping,\n"
		"you have to apply `object#nomap()` method to it\n"
		"if you want to specify a list or an iterator as a default value.\n"
		"\n"
		"When the attribute `:raise` is specified,\n"
		"an error occurs in the case of the key's absence.\n"
		"\n"
		"Another measure to get a value associated with a key is to use an index operator.\n"
		"The following two codes have the same effect.\n"
		"\n"
		"    v = d['foo']\n"
		"\n"
		"    v = d.get('foo'):raise\n");
}

Gura_ImplementMethod(dict, get)
{
	ValueDict &valDict = Object_dict::GetThisObj(args)->GetDict();
	const Value &valueIdx = args.GetValue(0);
	bool raiseFlag = args.IsSet(Gura_Symbol(raise));
	const Value *pValue = valDict.Find(sig, valueIdx);
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

// dict#haskey(key):map
Gura_DeclareMethod(dict, haskey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if the specified `key` exists in the dictionary.\n");
}

Gura_ImplementMethod(dict, haskey)
{
	ValueDict &valDict = Object_dict::GetThisObj(args)->GetDict();
	const Value &valueIdx = args.GetValue(0);
	const Value *pValue = valDict.Find(sig, valueIdx);
	return Value(pValue != NULL);
}

// dict#items() {block?}
Gura_DeclareMethod(dict, items)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an iterator of key-value pairs in the dictionary.\n"
		"\n"
		GURA_ITERATOR_HELP);
}

Gura_ImplementMethod(dict, items)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	Object_dict *pObj = Object_dict::Reference(pThis);
	return ReturnIterator(env, sig, args,
							new Object_dict::IteratorItems(pObj));
}

// dict#keys() {block?}
Gura_DeclareMethod(dict, keys)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an iterator of keys in the dictionary.\n"
		"\n"
		GURA_ITERATOR_HELP);
}

Gura_ImplementMethod(dict, keys)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	Object_dict *pObj = Object_dict::Reference(pThis);
	return ReturnIterator(env, sig, args,
							new Object_dict::IteratorKeys(pObj));
}

// dict#len()
Gura_DeclareMethod(dict, len)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns the number of key-value pairs in the dictionary.");
}

Gura_ImplementMethod(dict, len)
{
	ValueDict &valDict = Object_dict::GetThisObj(args)->GetDict();
	return Value(static_cast<Number>(valDict.size()));
}

// dict#set(key, value):map:reduce:[overwrite,strict,timid]
Gura_DeclareMethod(dict, set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "key", VTYPE_any);
	DeclareArg(env, "value", VTYPE_any);
	DeclareAttr(Gura_Symbol(overwrite));
	DeclareAttr(Gura_Symbol(strict));
	DeclareAttr(Gura_Symbol(timid));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Adds a new key-value pair.\n"
		"\n"
		"If the specified key already exists in the dictionary, it would be overwritten.\n"
		"This behavior can be customized with the following attributes:\n"
		"\n"
		"- `:overwrite` .. overwrite the existing one (default)\n"
		"- `:strict` .. raises an error\n"
		"- `:timid` .. keep the existing one\n");
}

Gura_ImplementMethod(dict, set)
{
	ValueDict &valDict = Object_dict::GetThisObj(args)->GetDict();
	const Value &valueIdx = args.GetValue(0);
	const Value &value = args.GetValue(1);
	ValueDict::StoreMode storeMode =
		args.IsSet(Gura_Symbol(strict))? ValueDict::STORE_Strict :
		args.IsSet(Gura_Symbol(timid))? ValueDict::STORE_Timid :
		ValueDict::STORE_Overwrite;
	if (!valDict.Store(sig, valueIdx, value, storeMode)) return Value::Null;
	return args.GetThis();
}

// dict#store(elems?):reduce:[overwrite,strict,timid] {block?}
Gura_DeclareMethod(dict, store)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "elems", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(overwrite));
	DeclareAttr(Gura_Symbol(strict));
	DeclareAttr(Gura_Symbol(timid));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Adds multiple key-value pairs.\n"
		"\n"
		"If the specified key already exists in the dictionary, it would be overwritten.\n"
		"This behavior can be customized with the following attributes:\n"
		"\n"
		"- `:overwrite` .. overwrite the existing one (default)\n"
		"- `:strict` .. raises an error\n"
		"- `:timid` .. keep the existing one\n");
}

Gura_ImplementMethod(dict, store)
{
	ValueDict &valDict = Object_dict::GetThisObj(args)->GetDict();
	ValueDict::StoreMode storeMode =
		args.IsSet(Gura_Symbol(strict))? ValueDict::STORE_Strict :
		args.IsSet(Gura_Symbol(timid))? ValueDict::STORE_Timid :
		ValueDict::STORE_Overwrite;
	if (args.GetValue(0).Is_list()) {
		if (!valDict.Store(sig, args.GetList(0), storeMode)) {
			return Value::Null;
		}
	} else if (args.GetValue(0).Is_dict()) {
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
		ValueList valList;
		foreach_const (ExprOwner, ppExpr, pExprBlock->GetExprOwner()) {
			SeqPostHandler *pSeqPostHandler = NULL;
			Value value = (*ppExpr)->Exec2(*pEnvLister, sig, pSeqPostHandler);
			if (sig.IsSignalled()) {
				sig.AddExprCause(*ppExpr);
				return Value::Null;
			}
			valList.push_back(value);
		}
		if (!valDict.Store(sig, valList, storeMode)) return Value::Null;
	}
	return args.GetThis();
}

// dict#values() {block?}
Gura_DeclareMethod(dict, values)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an iterator of values in the dictionary.\n"
		"\n"
		GURA_ITERATOR_HELP);
}

Gura_ImplementMethod(dict, values)
{
	Object_dict *pThis = Object_dict::GetThisObj(args);
	Object_dict *pObj = Object_dict::Reference(pThis);
	return ReturnIterator(env, sig, args,
							new Object_dict::IteratorValues(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_dict::Class_dict(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_dict)
{
}

void Class_dict::Prepare(Environment &env)
{
	Gura_AssignFunction(dict);
	Gura_AssignFunctionEx(dict, "%");
	Gura_AssignMethod(dict, clear);
	Gura_AssignMethod(dict, erase);
	Gura_AssignMethod(dict, get);
	Gura_AssignMethod(dict, haskey);
	Gura_AssignMethod(dict, items);
	Gura_AssignMethod(dict, keys);
	Gura_AssignMethod(dict, len);
	Gura_AssignMethod(dict, set);
	Gura_AssignMethod(dict, store);
	Gura_AssignMethod(dict, values);
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
	return new Object_dict((pClass == NULL)? this : pClass, new ValueDict());
}

}
