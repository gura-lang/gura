#include "stdafx.h"

#define USE_TINYBUFF 0

namespace Gura {

// nil / undefined
ValueType VTYPE_nil				= static_cast<ValueType>(0);
ValueType VTYPE_undefined		= static_cast<ValueType>(1);
// primitive types
ValueType VTYPE_symbol			= static_cast<ValueType>(2);
ValueType VTYPE_boolean			= static_cast<ValueType>(3);
ValueType VTYPE_number			= static_cast<ValueType>(4);
ValueType VTYPE_complex			= static_cast<ValueType>(5);
ValueType VTYPE_fraction		= static_cast<ValueType>(6);
ValueType VTYPE_string			= static_cast<ValueType>(7);
// for declaration
ValueType VTYPE_quote			= static_cast<ValueType>(0);
ValueType VTYPE_any				= static_cast<ValueType>(0);
// container types
ValueType VTYPE_Module			= static_cast<ValueType>(0);
ValueType VTYPE_Class			= static_cast<ValueType>(0);
// sequence
ValueType VTYPE_Sequence		= static_cast<ValueType>(0);
// object types
ValueType VTYPE_object			= static_cast<ValueType>(0);
ValueType VTYPE_args			= static_cast<ValueType>(0);
ValueType VTYPE_audio			= static_cast<ValueType>(0);
ValueType VTYPE_binary			= static_cast<ValueType>(0);
ValueType VTYPE_codec			= static_cast<ValueType>(0);
ValueType VTYPE_color			= static_cast<ValueType>(0);
ValueType VTYPE_datetime		= static_cast<ValueType>(0);
ValueType VTYPE_declaration		= static_cast<ValueType>(0);
ValueType VTYPE_dict			= static_cast<ValueType>(0);
ValueType VTYPE_directory		= static_cast<ValueType>(0);
ValueType VTYPE_environment		= static_cast<ValueType>(0);
ValueType VTYPE_error			= static_cast<ValueType>(0);
ValueType VTYPE_expr			= static_cast<ValueType>(0);
ValueType VTYPE_function		= static_cast<ValueType>(0);
ValueType VTYPE_help			= static_cast<ValueType>(0);
ValueType VTYPE_image			= static_cast<ValueType>(0);
ValueType VTYPE_iterator		= static_cast<ValueType>(0);
ValueType VTYPE_list			= static_cast<ValueType>(0);
ValueType VTYPE_matrix			= static_cast<ValueType>(0);
ValueType VTYPE_operator		= static_cast<ValueType>(0);
ValueType VTYPE_palette			= static_cast<ValueType>(0);
ValueType VTYPE_pointer			= static_cast<ValueType>(0);
ValueType VTYPE_semaphore		= static_cast<ValueType>(0);
ValueType VTYPE_stream			= static_cast<ValueType>(0);
ValueType VTYPE_timedelta		= static_cast<ValueType>(0);
ValueType VTYPE_uri				= static_cast<ValueType>(0);
ValueType VTYPE_Struct			= static_cast<ValueType>(0);

//-----------------------------------------------------------------------------
// static variables
//-----------------------------------------------------------------------------
ValueTypePool *ValueTypePool::_pInst = NULL;

const Value Value::Null;
const Value Value::Undefined(VTYPE_undefined, VFLAG_Owner);
const Value Value::Zero(0);
const Value Value::One(1);
const Value Value::True(true);
const Value Value::False(false);
const Value::KeyCompare Value::KeyCompareCase(false);
const Value::KeyCompare Value::KeyCompareIgnoreCase(true);
const ValueList ValueList::Null;
const ValueTypeMap ValueTypeMap::Null;
const ValueMap ValueMap::Null;
const ValueDict ValueDict::Null;

//-----------------------------------------------------------------------------
// ValueTypeInfo
//-----------------------------------------------------------------------------
ValueTypeInfo::~ValueTypeInfo()
{
	Class::Delete(_pClass);
}

void ValueTypeInfo::SetClass(Class *pClass)
{
	_pClass = pClass;
	pClass->SetSymbol(_pSymbol);
	pClass->SetValueType(_valType);
}

String ValueTypeInfo::MakeFullName() const
{
	String rtn;
	if (_pModule != NULL) {
		rtn += _pModule->GetName();
		rtn += ".";
	}
	rtn += _pSymbol->GetName();
	return rtn;
}

Expr *ValueTypeInfo::MakeExpr() const
{
	if (_pModule == NULL) {
		return new Expr_Symbol(_pSymbol);
	}
	return new Expr_Member(_pModule->MakeExpr(), new Expr_Symbol(_pSymbol));
}

//-----------------------------------------------------------------------------
// ValueTypeMap
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ValueTypePool
//-----------------------------------------------------------------------------
ValueTypePool::~ValueTypePool()
{
	foreach (ValueTypeList, ppValueTypeInfo, _valueTypeList) {
		ValueTypeInfo::Delete(*ppValueTypeInfo);
	}
}

void ValueTypePool::Initialize(Environment &env)
{
	if (_pInst == NULL) {
		_pInst = new ValueTypePool();
		_pInst->_Initialize(env);
	}
}

void ValueTypePool::_Initialize(Environment &env)
{
	// primitive types (this order is significant for IsPrimitive())
	// nil / undefined
	Gura_RealizeVTYPE(nil);			// must be at 1st
	Gura_RealizeVTYPE(undefined);	// must be at 2nd
	// primitive types
	Gura_RealizeVTYPE(symbol);		// must be at 3rd
	Gura_RealizeVTYPE(boolean);		// must be at 4th
	Gura_RealizeVTYPE(number);		// must be at 5th
	Gura_RealizeVTYPE(complex);		// must be at 6th
	Gura_RealizeVTYPE(fraction);	// must be at 7th
	Gura_RealizeVTYPE(string);		// must be at 8th
	// for declaration
	Gura_RealizeVTYPE(quote);
	Gura_RealizeVTYPE(any);
	// container types
	Gura_RealizeVTYPEEx(Module,		"module");
	Gura_RealizeVTYPEEx(Class,		"class");
	// sequence
	Gura_RealizeVTYPE(Sequence);
	// object types
	Gura_RealizeVTYPE(object);
	Gura_RealizeVTYPE(args);
	Gura_RealizeVTYPE(audio);
	Gura_RealizeVTYPE(binary);
	Gura_RealizeVTYPE(codec);
	Gura_RealizeVTYPE(color);
	Gura_RealizeVTYPE(datetime);
	Gura_RealizeVTYPE(declaration);
	Gura_RealizeVTYPE(dict);
	Gura_RealizeVTYPE(directory);
	Gura_RealizeVTYPE(environment);
	Gura_RealizeVTYPE(error);
	Gura_RealizeVTYPE(expr);
	Gura_RealizeVTYPE(function);
	Gura_RealizeVTYPE(help);
	Gura_RealizeVTYPE(image);
	Gura_RealizeVTYPE(iterator);
	Gura_RealizeVTYPE(list);
	Gura_RealizeVTYPE(matrix);
	Gura_RealizeVTYPE(operator);
	Gura_RealizeVTYPE(palette);
	Gura_RealizeVTYPE(pointer);
	Gura_RealizeVTYPE(semaphore);
	Gura_RealizeVTYPE(stream);
	Gura_RealizeVTYPE(timedelta);
	Gura_RealizeVTYPE(uri);
	Gura_RealizeVTYPEEx(Struct,		"struct");
	Class *pClass = new Class(&env, VTYPE_object);
	Gura_VTYPEInfo(object		)->SetClass(pClass);
	// classes for primitive types
	Gura_VTYPEInfo(nil			)->SetClass(new Class_nil(pClass));
	Gura_VTYPEInfo(undefined	)->SetClass(new Class_undefined(pClass));
	Gura_VTYPEInfo(symbol		)->SetClass(new Class_symbol(pClass));
	Gura_VTYPEInfo(boolean		)->SetClass(new Class_boolean(pClass));
	Gura_VTYPEInfo(number		)->SetClass(new Class_number(pClass));
	Gura_VTYPEInfo(complex		)->SetClass(new Class_complex(pClass));
	Gura_VTYPEInfo(fraction		)->SetClass(new Class_fraction(pClass));
	Gura_VTYPEInfo(string		)->SetClass(new Class_string(pClass));
	// for declaration
	Gura_VTYPEInfo(quote		)->SetClass(new Class_quote(pClass));
	Gura_VTYPEInfo(any			)->SetClass(new Class_any(pClass));
	// other built-in object classes
	Gura_VTYPEInfo(args			)->SetClass(new Class_args(pClass));
	Gura_VTYPEInfo(audio		)->SetClass(new Class_audio(pClass));
	Gura_VTYPEInfo(binary		)->SetClass(new Class_binary(pClass));
	Gura_VTYPEInfo(codec		)->SetClass(new Class_codec(pClass));
	Gura_VTYPEInfo(color		)->SetClass(new Class_color(pClass));
	Gura_VTYPEInfo(datetime		)->SetClass(new Class_datetime(pClass));
	Gura_VTYPEInfo(declaration	)->SetClass(new Class_declaration(pClass));
	Gura_VTYPEInfo(dict			)->SetClass(new Class_dict(pClass));
	Gura_VTYPEInfo(directory	)->SetClass(new Class_directory(pClass));
	Gura_VTYPEInfo(environment	)->SetClass(new Class_environment(pClass));
	Gura_VTYPEInfo(error		)->SetClass(new Class_error(pClass));
	Gura_VTYPEInfo(expr			)->SetClass(new Class_expr(pClass));
	Gura_VTYPEInfo(function		)->SetClass(new Class_function(pClass));
	Gura_VTYPEInfo(help			)->SetClass(new Class_help(pClass));
	Gura_VTYPEInfo(image		)->SetClass(new Class_image(pClass));
	Gura_VTYPEInfo(iterator		)->SetClass(new Class_iterator(pClass));
	Gura_VTYPEInfo(list			)->SetClass(new Class_list(pClass));
	Gura_VTYPEInfo(matrix		)->SetClass(new Class_matrix(pClass));
	Gura_VTYPEInfo(operator		)->SetClass(new Class_operator(pClass));
	Gura_VTYPEInfo(palette		)->SetClass(new Class_palette(pClass));
	Gura_VTYPEInfo(pointer		)->SetClass(new Class_pointer(pClass));
	Gura_VTYPEInfo(semaphore	)->SetClass(new Class_semaphore(pClass));
	Gura_VTYPEInfo(stream		)->SetClass(new Class_stream(pClass));
	Gura_VTYPEInfo(timedelta	)->SetClass(new Class_timedelta(pClass));
	Gura_VTYPEInfo(uri			)->SetClass(new Class_uri(pClass));
	Gura_VTYPEInfo(Struct		)->SetClass(new StructClass(pClass));
	pClass->Prepare(env); // methods of Object can only be initialized here
}

void ValueTypePool::DoPrepareClass(Environment &env)
{
	// nil / undefined
	env.LookupClass(VTYPE_nil)->Prepare(env);
	env.LookupClass(VTYPE_undefined)->Prepare(env);
	// primitive types
	env.LookupClass(VTYPE_symbol)->Prepare(env);
	env.LookupClass(VTYPE_boolean)->Prepare(env);
	env.LookupClass(VTYPE_number)->Prepare(env);
	env.LookupClass(VTYPE_complex)->Prepare(env);
	env.LookupClass(VTYPE_fraction)->Prepare(env);
	env.LookupClass(VTYPE_string)->Prepare(env);
	// declaration
	env.LookupClass(VTYPE_quote)->Prepare(env);
	env.LookupClass(VTYPE_any)->Prepare(env);
	// object types
	env.LookupClass(VTYPE_args)->Prepare(env);
	env.LookupClass(VTYPE_audio)->Prepare(env);
	env.LookupClass(VTYPE_binary)->Prepare(env);
	env.LookupClass(VTYPE_codec)->Prepare(env);
	env.LookupClass(VTYPE_color)->Prepare(env);
	env.LookupClass(VTYPE_datetime)->Prepare(env);
	env.LookupClass(VTYPE_declaration)->Prepare(env);
	env.LookupClass(VTYPE_dict)->Prepare(env);
	env.LookupClass(VTYPE_directory)->Prepare(env);
	env.LookupClass(VTYPE_environment)->Prepare(env);
	env.LookupClass(VTYPE_error)->Prepare(env);
	env.LookupClass(VTYPE_expr)->Prepare(env);
	env.LookupClass(VTYPE_function)->Prepare(env);
	env.LookupClass(VTYPE_help)->Prepare(env);
	env.LookupClass(VTYPE_image)->Prepare(env);
	env.LookupClass(VTYPE_iterator)->Prepare(env);
	env.LookupClass(VTYPE_list)->Prepare(env);
	env.LookupClass(VTYPE_matrix)->Prepare(env);
	env.LookupClass(VTYPE_operator)->Prepare(env);
	env.LookupClass(VTYPE_palette)->Prepare(env);
	env.LookupClass(VTYPE_pointer)->Prepare(env);
	env.LookupClass(VTYPE_semaphore)->Prepare(env);
	env.LookupClass(VTYPE_stream)->Prepare(env);
	env.LookupClass(VTYPE_timedelta)->Prepare(env);
	env.LookupClass(VTYPE_uri)->Prepare(env);
	env.LookupClass(VTYPE_Struct)->Prepare(env);
}

ValueTypeInfo *ValueTypePool::Add(const Symbol *pSymbol)
{
	ValueType valType = static_cast<ValueType>(_valueTypeList.size());
	ValueTypeInfo *pValTypeInfo = new ValueTypeInfo(valType, pSymbol, NULL);
	_valueTypeList.push_back(pValTypeInfo);
	return pValTypeInfo;
}

ValueTypeInfo *ValueTypePool::Lookup(ValueType valType)
{
	return _valueTypeList[valType];
}

ValueTypeInfo *ValueTypePool::LookupWithCheck(ValueType valType)
{
	if (valType >= _valueTypeList.size()) return NULL;
	return _valueTypeList[valType];
}

ValueTypePool *ValueTypePool::GetInstance()
{
	return _pInst;
}

//-----------------------------------------------------------------------------
// Value
//-----------------------------------------------------------------------------
Value::Value(const Value &value) : _valType(value._valType), _valFlags(value._valFlags)
{
	if (value.GetTinyBuffFlag()) {
		_u = value._u;
	} else if (value.IsNumber()) {
		_u.num = value._u.num;
	} else if (value.IsBoolean()) {
		_u.flag = value._u.flag;
	} else if (value.IsObject()) {
		_u.pObj = Object::Reference(value._u.pObj);
	} else if (value.IsSymbol()) {
		_u.pSymbol = value._u.pSymbol;
	} else if (value.IsComplex()) {
		_u.pComp = new Complex(*value._u.pComp);
	} else if (value.IsFraction()) {
		_u.pFrac = new Fraction(*value._u.pFrac);
	} else if (value.IsString()) {
		_u.pStr = new String(*value._u.pStr);
	} else if (value.IsModule()) {
		_u.pModule = Module::Reference(value._u.pModule);
	} else if (value.IsClass()) {
		_u.pClass = Class::Reference(value._u.pClass);
	} else if (value.IsSequence()) {
		_u.pSequence = Sequence::Reference(value._u.pSequence);
	} else {
		// nothing to do
	}
}

Value::Value(Object *pObj, UShort valFlags) :
						_valType(pObj->GetValueType()), _valFlags(valFlags)
{
	_u.pObj = pObj;
}

Value::~Value()
{
	if (IsInvalid()) return;
	// when the application terminates, it calls a destructor for statically
	// defined values such as Value::Null. until that timing, it's likely
	// that VTYPE_xxxx referenced in FreeResource() are not initialized and
	// it causes application error. to avoid such a case, the above line is
	// necessary.
	FreeResource();
}

// VTYPE_string
Value::Value(Environment &env, const String &str) : _valType(VTYPE_string), _valFlags(VFLAG_Owner)
{
#if USE_TINYBUFF
	size_t len = str.size();
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str.c_str(), len + 1);
	} else {
		_u.pStr = new String(str);
	}
#else
	_u.pStr = new String(str);
#endif
}

Value::Value(Environment &env, const char *str) : _valType(VTYPE_string), _valFlags(VFLAG_Owner)
{
#if USE_TINYBUFF
	size_t len = ::strlen(str);
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str, len + 1);
	} else {
		_u.pStr = new String(str);
	}
#else
	_u.pStr = new String(str);
#endif
}

Value::Value(Environment &env, const char *str, size_t len) : _valType(VTYPE_string), _valFlags(VFLAG_Owner)
{
#if USE_TINYBUFF
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str, len);
		_u.tinyBuff[len] = '\0';
	} else {
		_u.pStr = new String(str, len);
	}
#else
	_u.pStr = new String(str, len);
#endif
}

// VTYPE_iterator
Value::Value(Environment &env, Iterator *pIterator) : _valType(VTYPE_iterator), _valFlags(VFLAG_Owner)
{
	_u.pObj = new Object_iterator(env, pIterator);
}

// VTYPE_stream
Value::Value(Environment &env, Stream *pStream) : _valType(VTYPE_stream), _valFlags(VFLAG_Owner)
{
	_u.pObj = new Object_stream(env, pStream);
}

// VTYPE_function
Value::Value(Environment &env, Function *pFunc, const Value &valueThis) :
									_valType(VTYPE_function), _valFlags(VFLAG_Owner)
{
	_u.pObj = new Object_function(env, pFunc, valueThis);
}

// VTYPE_expr
Value::Value(Environment &env, Expr *pExpr) : _valType(VTYPE_expr), _valFlags(VFLAG_Owner)
{
	_u.pObj = new Object_expr(env, pExpr);
}

// VTYPE_datetime
Value::Value(Environment &env, const DateTime &dateTime) : _valType(VTYPE_datetime), _valFlags(VFLAG_Owner)
{
	_u.pObj = new Object_datetime(env, dateTime);
}

// VTYPE_timedelta
Value::Value(Environment &env, const TimeDelta &timeDelta) : _valType(VTYPE_timedelta), _valFlags(VFLAG_Owner)
{
	_u.pObj = new Object_timedelta(env, timeDelta);
}

void Value::FreeResource()
{
	if (GetTinyBuffFlag()) {
		// nothing to do
	} else if (IsComplex()) {
		delete _u.pComp;
		_u.pComp = NULL;
	} else if (IsFraction()) {
		delete _u.pFrac;
		_u.pFrac = NULL;
	} else if (IsString()) {
		delete _u.pStr;
		_u.pStr = NULL;
	} else if (IsModule()) {
		if (IsOwner()) Module::Delete(_u.pModule);
		_u.pModule = NULL;
	} else if (IsClass()) {
		if (IsOwner()) Class::Delete(_u.pClass);
		_u.pClass = NULL;
	} else if (IsSequence()) {
		if (IsOwner()) Sequence::Delete(_u.pSequence);
		_u.pSequence = NULL;
	} else if (IsObject()) {
		if (IsOwner()) Object::Delete(_u.pObj);
		_u.pObj = NULL;
	} else { // Number, Boolean
		// nothing to do
	}
	_valType = VTYPE_nil;
}

Value &Value::operator=(const Value &value)
{
	FreeResource();
	_valType = value._valType;
	_valFlags = value._valFlags;
	if (GetTinyBuffFlag()) {
		_u = value._u;
	} else if (value.IsNumber()) {
		_u.num = value._u.num;
	} else if (value.IsBoolean()) {
		_u.flag = value._u.flag;
	} else if (value.IsSymbol()) {
		_u.pSymbol = value._u.pSymbol;
	} else if (value.IsComplex()) {
		_u.pComp = new Complex(*value._u.pComp);
	} else if (value.IsFraction()) {
		_u.pFrac = new Fraction(*value._u.pFrac);
	} else if (value.IsString()) {
		_u.pStr = new String(*value._u.pStr);
	} else if (value.IsModule()) {
		_u.pModule = Module::Reference(value._u.pModule);
	} else if (value.IsClass()) {
		_u.pClass = Class::Reference(value._u.pClass);
	} else if (value.IsSequence()) {
		_u.pSequence = Sequence::Reference(value._u.pSequence);
	} else if (value.IsObject()) {
		_u.pObj = Object::Reference(value._u.pObj);
	} else {
		// nothing to do
		//_valType = VTYPE_nil;
	}
	return *this;
}

bool Value::MustBe(Signal &sig, bool flag, const char *expected) const
{
	if (flag) return true;
	sig.SetError(ERR_ValueError, "value must be %s", expected);
	return false;
}

Fundamental *Value::ExtractFundamental(Signal sig)
{
	if (GetTinyBuffFlag()) {
		// nothing to do
	} else if (IsModule()) {
		return GetModule();
	} else if (IsClass()) {
		return GetClass();
	} else if (IsObject()) {
		Fundamental *pFund = GetFundamental();
		if (pFund->IsFunction()) {
			const Object_function *pObjFunc =
								dynamic_cast<const Object_function *>(pFund);
			Class *pClass = pObjFunc->GetFunction()->GetClassToConstruct();
			if (pClass != NULL) {
				InitAsClass(Class::Reference(pClass));
				pFund = pClass;
			}
		}
		return pFund;
	}
	sig.SetError(ERR_ValueError,
		"%s can not be specified as l-value of member", MakeValueTypeName().c_str());
	return NULL;
}

bool Value::IsFlatList() const
{
	return IsList() && GetList().IsFlat();
}

bool Value::IsInstanceOf(ValueType valType) const
{
	if (_valType == valType) return true;
	const ValueTypeInfo *pValueTypeInfo =
							ValueTypePool::GetInstance()->Lookup(_valType);
	if (pValueTypeInfo == NULL) return false;
	for (Class *pClass = pValueTypeInfo->GetClass(); pClass != NULL;
										pClass = pClass->GetClassSuper()) {
		if (pClass->GetValueType() == valType) return true;
	}
	return false;
}

const char *Value::GetString() const
{
	if (GetTinyBuffFlag()) return _u.tinyBuff;
	return _u.pStr->c_str();
}

String Value::GetStringSTL() const
{
	if (GetTinyBuffFlag()) return String(_u.tinyBuff);
	return *_u.pStr;
}

const Binary &Value::GetBinary() const
{
	return dynamic_cast<Object_binary *>(_u.pObj)->GetBinary();
}

const DateTime &Value::GetDateTime() const
{
	return dynamic_cast<Object_datetime *>(_u.pObj)->GetDateTime();
}

const TimeDelta &Value::GetTimeDelta() const
{
	return dynamic_cast<Object_timedelta *>(_u.pObj)->GetTimeDelta();
}

Value Value::EmptyIndexGet(Environment &env, Signal sig) const
{
	if (IsPrimitive()) {
		return env.LookupClass(_valType)->EmptyIndexGetPrimitive(env, sig, *this);
	} else if (IsObject()) {
		return GetObject()->EmptyIndexGet(env, sig);
	}
	sig.SetError(ERR_TypeError, "object should be specified as l-value of indexer");
	return Value::Null;
}

void Value::EmptyIndexSet(Environment &env, Signal sig, const Value &value)
{
	if (IsObject()) {
		GetObject()->EmptyIndexSet(env, sig, value);
		return;
	}
	sig.SetError(ERR_TypeError, "object should be specified as l-value of indexer");
}

Value Value::IndexGet(Environment &env, Signal sig, const Value &valueIdx) const
{
	if (IsPrimitive()) {
		return env.LookupClass(_valType)->IndexGetPrimitive(env, sig, *this, valueIdx);
	} else if (IsObject()) {
		return GetObject()->IndexGet(env, sig, valueIdx);
	}
	sig.SetError(ERR_TypeError, "object should be specified as l-value of indexer");
	return Value::Null;
}

void Value::IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value)
{
	if (IsObject()) {
		GetObject()->IndexSet(env, sig, valueIdx, value);
		return;
	}
	sig.SetError(ERR_TypeError, "object should be specified as l-value of indexer");
}

bool Value::DirProp(Environment &env, Signal sig, SymbolSet &symbols, bool escalateFlag)
{
	if (GetTinyBuffFlag()) {
		// nothing to do
	} else if (IsModule()) {
		return GetModule()->DirProp(env, sig, symbols);
	} else if (IsClass()) {
		return GetClass()->DirProp(env, sig, symbols, escalateFlag);
	} else if (IsFunction()) {
		Class *pClass = GetFunction()->GetClassToConstruct();
		if (pClass != NULL) {
			return pClass->DirProp(env, sig, symbols, escalateFlag);
		}
	} else if (IsObject()) {
		return GetObject()->DirProp(env, sig, symbols);
	}
	return env.LookupClass(_valType)->DirProp(env, sig, symbols, escalateFlag);
}

void Value::DirValueType(SymbolSet &symbols, bool escalateFlag)
{
	if (GetTinyBuffFlag()) {
		// nothing to do
	} else if (IsModule()) {
		GetModule()->DirValueType(symbols);
	} else if (IsClass()) {
		// nothing to do
	} else if (IsObject()) {
		// nothing to do
	}
}

ErrorType Value::GetErrorType() const
{
	return dynamic_cast<Object_error *>(_u.pObj)->GetError().GetType();
}

ValueList &Value::GetList()
{
	return dynamic_cast<Object_list *>(_u.pObj)->GetList();
}

const ValueList &Value::GetList() const
{
	return dynamic_cast<const Object_list *>(_u.pObj)->GetList();
}

ValueDict &Value::GetDict()
{
	return dynamic_cast<Object_dict *>(_u.pObj)->GetDict();
}

const ValueDict &Value::GetDict() const
{
	return IsDict()?
		dynamic_cast<const Object_dict *>(_u.pObj)->GetDict() : ValueDict::Null;
}

Iterator *Value::GetIterator() const
{
	return IsIterator()?
		dynamic_cast<const Object_iterator *>(_u.pObj)->GetIterator() : NULL;
}

Stream &Value::GetStream() const
{
	return dynamic_cast<Object_stream *>(_u.pObj)->GetStream();
}

Directory *Value::GetDirectory() const
{
	return dynamic_cast<Object_directory *>(_u.pObj)->GetDirectory();
}

const Expr *Value::GetExpr() const
{
	return IsExpr()? dynamic_cast<Object_expr *>(_u.pObj)->GetExpr() : NULL;
}

Function *Value::GetFunction()
{
	return IsFunction()? dynamic_cast<Object_function *>(_u.pObj)->GetFunction() : NULL;
}

Expr *Value::CloneExpr() const
{
	return
		IsExpr()? Expr::Reference(dynamic_cast<Object_expr *>(_u.pObj)->GetExpr()) :
		IsSymbol()? new Expr_Symbol(_u.pSymbol) : NULL;
}

Fundamental *Value::GetFundamental()
{
	if (GetTinyBuffFlag()) {
		// nothing to do
	} else if (IsObject()) {
		return _u.pObj;
	} else if (IsClass()) {
		return _u.pClass;
	} else if (IsModule()) {
		return _u.pModule;
	}
	return NULL;
}

Iterator *Value::CreateIterator(Signal sig) const
{
	if (IsObject()) {
		return _u.pObj->CreateIterator(sig);
	}
	sig.SetError(ERR_ValueError, "value of %s cannot generate iterator",
											MakeValueTypeName().c_str());
	return NULL;
}

String Value::ToString(Signal sig, bool exprFlag) const
{
	if (IsNumber()) {
		return NumberToString(_u.num);
	} else if (IsBoolean()) {
		return String(_u.flag?
			Gura_Symbol(true_)->GetName() : Gura_Symbol(false_)->GetName());
	} else if (IsSymbol()) {
		String str;
		if (exprFlag) str += '`';
		str += _u.pSymbol->GetName();
		return str;
	} else if (IsComplex()) {
		const Complex &comp = *_u.pComp;
		String str;
		char buff[32];
		if (comp.real() == 0. && comp.imag() == 0.) {
			::sprintf(buff, GetNumberFormat(), 0.);
			str += buff;
		} else if (comp.real() == 0.) {
			if (_u.pComp->imag() < 0.) str += "-";
			::sprintf(buff, GetNumberFormat(), ::fabs(_u.pComp->imag()));
			str += buff;
			str += Gura_Symbol(j)->GetName();
		} else if (comp.imag() == 0.) {
			::sprintf(buff, GetNumberFormat(), _u.pComp->real());
			str += buff;
		} else {
			::sprintf(buff, GetNumberFormat(), _u.pComp->real());
			str += buff;
			str += (_u.pComp->imag() >= 0.)? "+" : "-";
			::sprintf(buff, GetNumberFormat(), ::fabs(_u.pComp->imag()));
			str += buff;
			str += Gura_Symbol(j)->GetName();
		}
		return str;
	} else if (IsFraction()) {
		const Fraction &frac = *_u.pFrac;
		String str;
		if (exprFlag) {
			str += "fraction(";
			str += NumberToString(frac.numerator);
			str += ", ";
			str += NumberToString(frac.denominator);
			str += ")";
		} else {
			str += NumberToString(frac.numerator);
			str += "/";
			str += NumberToString(frac.denominator);
		}
		return str;
	} else if (IsString()) {
		const char *str = GetString();
		if (exprFlag) return MakeQuotedString(str);
		return String(str);
	} else if (IsModule()) {
		return _u.pModule->ToString(sig, exprFlag);
	} else if (IsClass()) {
		return _u.pClass->ToString(sig, exprFlag);
	} else if (IsSequence()) {
		return _u.pSequence->ToString();
	} else if (IsObject()) {
		return _u.pObj->ToString(sig, exprFlag);
	}
	return String(exprFlag? "nil" : "");
}

Number Value::ToNumber(bool allowPartFlag, bool &successFlag) const
{
	successFlag = true;
	if (IsNumber()) {
		return _u.num;
	} else if (IsBoolean()) {
		return _u.flag? 1. : 0.;
	} else if (IsString()) {
		const char *str = GetString();
		Number num = 0.;
		char *p = const_cast<char *>(str);
		if (str[0] == '0' &&
				(str[1] == 'x' || str[1] == 'X' || IsOctDigit(str[1]))) {
			num = static_cast<Number>(::strtoul(str, &p, 0));
		} else {
			num = ::strtod(str, &p);
		}
		successFlag = (p > str && (allowPartFlag || *p == '\0'));
		return num;
	} else if (IsFraction()) {
		const Fraction &frac = *_u.pFrac;
		if (frac.denominator == 0) {
			successFlag = false;
			return 0.;
		}
		return frac.numerator / frac.denominator;
	} else {
		successFlag = false;
		return 0.;
	}
}

int Value::Compare(const Value &value1, const Value &value2, bool ignoreCaseFlag)
{
	int rtn = -1;
	if (value1.GetValueType() != value2.GetValueType()) {
		rtn = static_cast<int>(value1.GetValueType()) -
								static_cast<int>(value2.GetValueType());
	} else if (value1.IsNumber()) {
		rtn = (value1.GetNumber() == value2.GetNumber())? 0 :
				(value1.GetNumber() < value2.GetNumber())? -1 : +1;
	} else if (value1.IsBoolean()) {
		rtn = static_cast<int>(value1.GetBoolean()) -
								static_cast<int>(value2.GetBoolean());
	} else if (value1.IsSymbol()) {
		rtn = static_cast<int>(value1.GetSymbol()->GetUniqNum()) -
										value2.GetSymbol()->GetUniqNum();
	} else if (value1.IsString()) {
		if (ignoreCaseFlag) {
			rtn = ::strcasecmp(value1.GetString(), value2.GetString());
		} else {
			rtn = ::strcmp(value1.GetString(), value2.GetString());
		}
	} else if (value1.IsBinary()) {
		const Binary &buff1 = value1.GetBinary();
		const Binary &buff2 = value2.GetBinary();
		if (buff1.size() < buff2.size()) {
			rtn = -1;
		} else if (buff1.size() > buff2.size()) {
			rtn = 1;
		} else {
			rtn = ::memcmp(buff1.data(), buff2.data(), buff1.size());
		}
	} else if (value1.IsDateTime()) {
		const DateTime &dt1 = value1.GetDateTime();
		const DateTime &dt2 = value2.GetDateTime();
		rtn = DateTime::Compare(dt1, dt2);
	} else if (value1.IsTimeDelta()) {
		rtn = TimeDelta::Compare(value1.GetTimeDelta(), value2.GetTimeDelta());
	} else if (value1.IsList()) {
		bool emptyFlag1 = value1.GetList().empty();
		bool emptyFlag2 = value2.GetList().empty();
		if (emptyFlag1 || emptyFlag2) {
			rtn = -(static_cast<int>(emptyFlag1) - static_cast<int>(emptyFlag2));
		} else {
			rtn = Value::Compare(value1.GetList().front(), value2.GetList().front());
		}
	} else if (value1.IsObject() &&
					!value1.GetTinyBuffFlag() && !value2.GetTinyBuffFlag()) {
		rtn = value1.GetObject()->Compare(value2.GetObject());
	} else if (value1.IsInvalid() && value2.IsInvalid()) {
		rtn = 0;
	}
	return rtn;
}

bool Value::Accept(ValueVisitor &visitor) const
{
	return IsList()? GetList().Accept(visitor) : visitor.Visit(*this);
}

void Value::InitAsModule(Module *pModule)
{
	FreeResource();
	_valType = VTYPE_Module, _u.pModule = pModule;
}

void Value::InitAsClass(Class *pClass)
{
	FreeResource();
	_valType = VTYPE_Class, _u.pClass = pClass;
}

void Value::InitAsObject(Object *pObj)
{
	FreeResource();
	_valType = pObj->GetValueType(), _u.pObj = pObj;
	_valFlags = VFLAG_Owner;
}

ValueList &Value::InitAsList(Environment &env)
{
	Object_list *pObj = new Object_list(env);
	InitAsObject(pObj);
	return pObj->GetList();
}

ValueList &Value::InitAsList(Environment &env, size_t n)
{
	Object_list *pObj = new Object_list(env, n);
	InitAsObject(pObj);
	return pObj->GetList();
}

ValueList &Value::InitAsList(Environment &env, const ValueList &valList)
{
	Object_list *pObj = new Object_list(env, valList);
	InitAsObject(pObj);
	return pObj->GetList();
}

ValueList &Value::InitAsList(Environment &env, size_t n, const Value &value)
{
	Object_list *pObj =
			(n == 0)? new Object_list(env) : new Object_list(env, n, value);
	InitAsObject(pObj);
	return pObj->GetList();
}

ValueDict &Value::InitAsDict(Environment &env, bool ignoreCaseFlag)
{
	Object_dict *pObj = new Object_dict(env, new ValueDict(ignoreCaseFlag));
	InitAsObject(pObj);
	return pObj->GetDict();
}

bool Value::CastType(Environment &env, Signal sig, ValueType valType, Value &valueCasted) const
{
	valueCasted = *this;
	if (IsType(valType)) return true;
	AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(nil), valType));
	return env.LookupClass(valType)->CastFrom(env, sig, valueCasted, pDecl.get());
}

Value Value::CreateAsList(Environment &env, const Value &v1)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(1);
	valList.push_back(v1);
	return rtn;
}

Value Value::CreateAsList(Environment &env, const Value &v1, const Value &v2)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(2);
	valList.push_back(v1);
	valList.push_back(v2);
	return rtn;
}

Value Value::CreateAsList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(3);
	valList.push_back(v1);
	valList.push_back(v2);
	valList.push_back(v3);
	return rtn;
}

Value Value::CreateAsList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(4);
	valList.push_back(v1);
	valList.push_back(v2);
	valList.push_back(v3);
	valList.push_back(v4);
	return rtn;
}

Value Value::CreateAsList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4, const Value &v5)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(5);
	valList.push_back(v1);
	valList.push_back(v2);
	valList.push_back(v3);
	valList.push_back(v4);
	valList.push_back(v5);
	return rtn;
}

Value Value::CreateAsList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4, const Value &v5, const Value &v6)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(6);
	valList.push_back(v1);
	valList.push_back(v2);
	valList.push_back(v3);
	valList.push_back(v4);
	valList.push_back(v5);
	valList.push_back(v6);
	return rtn;
}

bool Value::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value)
{
	const ValueTypeInfo *pValueTypeInfo = value.GetValueTypeInfo();
	ULong valType = static_cast<ULong>(value.GetValueType());
	if (!stream.SerializePackedULong(sig, valType)) return false;
	return pValueTypeInfo->GetClass()->Serialize(env, sig, stream, value);
}

bool Value::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value, bool mustBeValidFlag)
{
	ULong valType = static_cast<ULong>(VTYPE_nil);
	if (!stream.DeserializePackedULong(sig, valType)) return false;
	if (mustBeValidFlag && valType == VTYPE_nil) {
		sig.SetError(ERR_IOError, "invalid value in the stream");
		return false;
	}
	const ValueTypeInfo *pValueTypeInfo =
			ValueTypePool::GetInstance()->LookupWithCheck(static_cast<ValueType>(valType));
	if (pValueTypeInfo == NULL) {
		sig.SetError(ERR_IOError, "invalid value type in the stream");
		return false;
	}
	return pValueTypeInfo->GetClass()->Deserialize(env, sig, stream, value);
}

//-----------------------------------------------------------------------------
// ValueList
//-----------------------------------------------------------------------------
ValueList::ValueList(const ValueList &valList)
{
	reserve(valList.size());
	foreach_const (ValueList, pValue, valList) {
		push_back(*pValue);
	}
}

bool ValueList::IsFlat() const
{
	foreach_const (ValueList, pValue, *this) {
		if (pValue->IsList()) return false;
	}
	return true;
}

bool ValueList::IsContain(const Value &value) const
{
	foreach_const (ValueList, pValue, *this) {
		if (Value::Compare(*pValue, value) == 0) return true;
	}
	return false;
}

bool ValueList::IsContainIterator() const
{
	foreach_const (ValueList, pValue, *this) {
		if (pValue->IsIterator()) return true;
	}
	return false;
}

bool ValueList::CheckMatrix(size_t *pnRow, size_t *pnCol) const
{
	if (empty()) return false;
	size_t nRow = size();
	size_t nCol = 1;
	if (front().IsList()) {
		nCol = front().GetList().size();
		foreach_const (ValueList, pValueRow, *this) {
			if (!pValueRow->IsList()) {
				return false;
			} else if (pValueRow->GetList().size() != nCol) {
				return false;
			}
		}
	} else {
		foreach_const (ValueList, pValueCol, *this) {
			if (pValueCol->IsList()) return false;
		}
	}
	if (pnRow != NULL) *pnRow = nRow;
	if (pnCol != NULL) *pnCol = nCol;
	return true;
}

bool ValueList::AssumeSameLength(Signal sig,
						const ValueList &valList1, const ValueList &valList2)
{
	if (valList1.size() == valList2.size()) return true;
	sig.SetError(ERR_ValueError, "lists are different in length");
	return false;
}

void ValueList::ExtractFlat(ValueList &valList) const
{
	foreach_const (ValueList, pValue, *this) {
		if (pValue->IsList()) {
			pValue->GetList().ExtractFlat(valList);
		} else {
			valList.push_back(*pValue);
		}
	}
}

bool ValueList::Accept(ValueVisitor &visitor) const
{
	foreach_const (ValueList, pValue, *this) {
		if (!pValue->Accept(visitor)) return false;
	}
	return true;
}

void ValueList::Append(const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		push_back(*pValue);
	}
}

void ValueList::Print(Signal sig, int indentLevel) const
{
	foreach_const (ValueList, pValue, *this) {
		if (pValue->IsList()) {
			pValue->GetList().Print(sig, indentLevel + 1);
		} else {
			::printf("%*s%s\n",
					indentLevel * 2, "", pValue->ToString(sig).c_str());
		}
	}
}

bool ValueList::ToStringList(Signal sig, StringList &strList) const
{
	foreach_const (ValueList, pValue, *this) {
		String str = pValue->ToString(sig, false);
		if (sig.IsSignalled()) return false;
		strList.push_back(str);
	}
	return true;
}

bool ValueList::Serialize(Environment &env, Signal sig, Stream &stream) const
{
	ULong num = static_cast<ULong>(size());
	if (!stream.SerializePackedULong(sig, num)) return false;
	foreach_const (ValueList, pValue, *this) {
		if (!Value::Serialize(env, sig, stream, *pValue)) return false;
	}
	return true;
}

bool ValueList::Deserialize(Environment &env, Signal sig, Stream &stream)
{
	ULong num = 0;
	if (!stream.DeserializePackedULong(sig, num)) return false;
	reserve(num);
	Value value;
	while (num-- > 0) {
		if (!Value::Deserialize(env, sig, stream, value, false)) return false;
		push_back(value);
	}
	return true;
}

//-----------------------------------------------------------------------------
// ValueMap
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ValueDict
//-----------------------------------------------------------------------------
void ValueDict::Store(Environment &env, const String &strIndex, const String &strValue)
{
	insert(ValueDict::value_type(Value(env, strIndex), Value(env, strValue)));
}

bool ValueDict::Store(Signal sig, const ValueList &valList, StoreMode storeMode)
{
	enum { FIELD_Key, FIELD_Value } field = FIELD_Key;
	Value valueIdx;
	const ValueList *pValList = &valList;
	if (valList.size() == 1 && valList[0].IsList()) {
		pValList = &valList[0].GetList();
	}
	foreach_const (ValueList, pValue, *pValList) {
		if (field == FIELD_Key) {
			Value value;
			valueIdx = *pValue;
			if (valueIdx.IsList()) {
				const ValueList &valListElem = valueIdx.GetList();
				if (valListElem.size() != 2) {
					sig.SetError(ERR_KeyError, "invalid key-value format");
					return false;
				}
				valueIdx = valListElem[0];
				value = valListElem[1];
			}
			if (!ValueDict::IsValidKey(valueIdx)) {
				sig.SetError(ERR_KeyError, "invalid value type for key");
				return false;
			}
			if (value.IsValid()) {
				ValueDict::iterator iterDst = find(valueIdx);
				if (iterDst == end()) {
					insert(ValueDict::value_type(valueIdx, value));
				} else if (storeMode == STORE_AllowDup) {
					iterDst->second = value;
				} else if (storeMode == STORE_Default) {
					// nothing to do
				} else {
					sig.SetError(ERR_KeyError, "duplicated key '%s'", valueIdx.ToString(sig).c_str());
					return false;
				}
			} else {
				field = FIELD_Value;
			}
		} else { // FIELD_Value
			ValueDict::iterator iterDst = find(valueIdx);
			if (iterDst == end()) {
				insert(ValueDict::value_type(valueIdx, *pValue));
			} else if (storeMode == STORE_AllowDup) {
				iterDst->second = *pValue;
			} else if (storeMode == STORE_Default) {
				// nothing to do
			} else {
				sig.SetError(ERR_KeyError, "duplicated key '%s'", valueIdx.ToString(sig).c_str());
				return false;
			}
			field = FIELD_Key;
		}
	}
	if (field == FIELD_Value) {
		sig.SetError(ERR_KeyError, "unmatching key-value pair");
		return false;
	}
	return true;
}

bool ValueDict::Store(Signal sig, const ValueDict &valDict, StoreMode storeMode)
{
	foreach_const (ValueDict, iterSrc, valDict) {
		const Value &valueIdx = iterSrc->first;
		ValueDict::iterator iterDst = find(valueIdx);
		if (iterDst == end()) {
			insert(*iterSrc);
		} else if (storeMode == STORE_AllowDup) {
			iterDst->second = iterSrc->second;
		} else if (storeMode == STORE_Default) {
			// nothing to do
		} else {
			sig.SetError(ERR_KeyError, "duplicated key '%s'", valueIdx.ToString(sig).c_str());
			return false;
		}
	}
	return true;
}

bool ValueDict::Store(Signal sig, const Value &valueIdx, const Value &value, StoreMode storeMode)
{
	if (!ValueDict::IsValidKey(valueIdx)) {
		sig.SetError(ERR_KeyError, "invalid value type for key");
		return false;
	}
	ValueDict::iterator iterDst = find(valueIdx);
	if (iterDst == end()) {
		insert(ValueDict::value_type(valueIdx, value));
	} else if (storeMode == STORE_AllowDup) {
		iterDst->second = value;
	} else if (storeMode == STORE_Default) {
		// nothing to do
	} else {
		sig.SetError(ERR_KeyError, "duplicated key '%s'", valueIdx.ToString(sig).c_str());
		return false;
	}
	return true;
}

bool ValueDict::Serialize(Environment &env, Signal sig, Stream &stream) const
{
	ULong num = static_cast<ULong>(size());
	if (!stream.SerializePackedULong(sig, num)) return false;
	foreach_const (ValueDict, iter, *this) {
		if (!Value::Serialize(env, sig, stream, iter->first)) return false;
		if (!Value::Serialize(env, sig, stream, iter->second)) return false;
	}
	return true;
}

bool ValueDict::Deserialize(Environment &env, Signal sig, Stream &stream)
{
	ULong num = 0;
	if (!stream.DeserializePackedULong(sig, num)) return false;
	Value valueIdx, value;
	while (num-- > 0) {
		if (!Value::Deserialize(env, sig, stream, valueIdx, false)) return false;
		if (!Value::Deserialize(env, sig, stream, value, false)) return false;
		insert(ValueDict::value_type(valueIdx, value));
	}
	return true;
}

//-----------------------------------------------------------------------------
// ValueVisitor_Flatten
//-----------------------------------------------------------------------------
bool ValueVisitor_Flatten::Visit(const Value &value)
{
	_valList.push_back(value);
	return true;
}

}
