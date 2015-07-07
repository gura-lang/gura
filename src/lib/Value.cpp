//=============================================================================
// Value
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Functions to manage Value resources
//-----------------------------------------------------------------------------
void Gura_CopyValue(Value &valueDst, const Value &valueSrc)
{
	valueDst._valType = valueSrc._valType;
	valueDst._valFlags = valueSrc._valFlags;
	if (valueSrc.GetTinyBuffFlag()) {
		valueDst._u = valueSrc._u;
	} else if (valueSrc.Is_boolean()) {
		valueDst._u.flag = valueSrc._u.flag;
	} else if (valueSrc.Is_complex()) {
		valueDst._u.pComp = new Complex(*valueSrc._u.pComp);
	} else if (valueSrc.Is_number()) {
		valueDst._u.num = valueSrc._u.num;
	} else if (valueSrc.Is_rational()) {
		valueDst._u.pRatio = new Rational(*valueSrc._u.pRatio);
	} else if (valueSrc.Is_string()) {
		valueDst._u.pStrRef = valueSrc._u.pStrRef->Reference();
	} else if (valueSrc.Is_symbol()) {
		valueDst._u.pSymbol = valueSrc._u.pSymbol;
	} else if (valueSrc.IsObject()) {
		valueDst._u.pObj = Object::Reference(valueSrc._u.pObj);
	} else if (valueSrc.IsModule()) {
		valueDst._u.pModule = Module::Reference(valueSrc._u.pModule);
	} else if (valueSrc.IsClass()) {
		valueDst._u.pClass = Class::Reference(valueSrc._u.pClass);
	} else if (valueSrc.IsSequence()) {
		valueDst._u.pSequence = Sequence::Reference(valueSrc._u.pSequence);
	} else {
		// nothing to do
		//valueDst._valType = VTYPE_nil;
	}
}

void Gura_ReleaseValue(Value &value)
{
	if (value.GetTinyBuffFlag()) {
		// nothing to do
	} else if (value.Is_complex()) {
		delete value._u.pComp;
		value._u.pComp = nullptr;
	} else if (value.Is_rational()) {
		delete value._u.pRatio;
		value._u.pRatio = nullptr;
	} else if (value.Is_string()) {
		StringRef::Delete(value._u.pStrRef);
		value._u.pStrRef = nullptr;
	} else if (value.IsObject()) {
		if (value.IsOwner()) Object::Delete(value._u.pObj);
		value._u.pObj = nullptr;
	} else if (value.IsModule()) {
		if (value.IsOwner()) Module::Delete(value._u.pModule);
		value._u.pModule = nullptr;
	} else if (value.IsClass()) {
		if (value.IsOwner()) Class::Delete(value._u.pClass);
		value._u.pClass = nullptr;
	} else if (value.IsSequence()) {
		if (value.IsOwner()) Sequence::Delete(value._u.pSequence);
		value._u.pSequence = nullptr;
	} else { // Number, Boolean
		// nothing to do
	}
	value._valType = VTYPE_nil;
}

//-----------------------------------------------------------------------------
// Value
//-----------------------------------------------------------------------------
const Value Value::Null;
const Value Value::Undefined(VTYPE_undefined, VFLAG_Owner);
const Value Value::Zero(0);
const Value Value::One(1);
const Value Value::True(true);
const Value Value::False(false);
const Value::KeyCompare Value::KeyCompareCase(false);
const Value::KeyCompare Value::KeyCompareIgnoreCase(true);

Value::Value(const Value &value)
{
	Gura_CopyValue(*this, value);
}

#if 0
Value::Value(const Value &value) : _valType(value._valType), _valFlags(value._valFlags)
{
	if (value.GetTinyBuffFlag()) {
		_u = value._u;
	} else if (value.Is_boolean()) {
		_u.flag = value._u.flag;
	} else if (value.Is_complex()) {
		_u.pComp = new Complex(*value._u.pComp);
	} else if (value.Is_number()) {
		_u.num = value._u.num;
	} else if (value.Is_rational()) {
		_u.pRatio = new Rational(*value._u.pRatio);
	} else if (value.Is_string()) {
		_u.pStrRef = value._u.pStrRef->Reference();
	} else if (value.Is_symbol()) {
		_u.pSymbol = value._u.pSymbol;
	} else if (value.IsObject()) {
		_u.pObj = Object::Reference(value._u.pObj);
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
#endif

Value::Value(Object *pObj, UShort valFlags) :
				_valType(pObj->GetClass()->GetValueType()), _valFlags(valFlags)
{
	_u.pObj = pObj;
}

Value::~Value()
{
	if (IsInvalid()) return;
	// when the application terminates, it calls a destructor for statically
	// defined values such as Value::Null. until that timing, it's likely
	// that VTYPE_xxxx referenced in Gura_ReleaseValue() are not initialized and
	// it causes application error. to avoid such a case, the above line is
	// necessary.
	Gura_ReleaseValue(*this);
}

// VTYPE_string
Value::Value(const String &str) : _valType(VTYPE_string), _valFlags(VFLAG_Owner)
{
	size_t len = str.size();
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str.c_str(), len + 1);
	} else {
		_u.pStrRef = new StringRef(str);
	}
}

Value::Value(const char *str) : _valType(VTYPE_string), _valFlags(VFLAG_Owner)
{
	size_t len = ::strlen(str);
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str, len + 1);
	} else {
		_u.pStrRef = new StringRef(str);
	}
}

Value::Value(const char *str, size_t len) : _valType(VTYPE_string), _valFlags(VFLAG_Owner)
{
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str, len);
		_u.tinyBuff[len] = '\0';
	} else {
		_u.pStrRef = new StringRef(String(str, len));
	}
}

Value &Value::operator=(const Value &value)
{
	Gura_ReleaseValue(*this);
	Gura_CopyValue(*this, value);
	return *this;
}

#if 0
Value &Value::operator=(const Value &value)
{
	Gura_ReleaseValue(*this);
	_valType = value._valType;
	_valFlags = value._valFlags;
	if (GetTinyBuffFlag()) {
		_u = value._u;
	} else if (value.Is_boolean()) {
		_u.flag = value._u.flag;
	} else if (value.Is_complex()) {
		_u.pComp = new Complex(*value._u.pComp);
	} else if (value.Is_number()) {
		_u.num = value._u.num;
	} else if (value.Is_rational()) {
		_u.pRatio = new Rational(*value._u.pRatio);
	} else if (value.Is_string()) {
		_u.pStrRef = value._u.pStrRef->Reference();
	} else if (value.Is_symbol()) {
		_u.pSymbol = value._u.pSymbol;
	} else if (value.IsObject()) {
		_u.pObj = Object::Reference(value._u.pObj);
	} else if (value.IsModule()) {
		_u.pModule = Module::Reference(value._u.pModule);
	} else if (value.IsClass()) {
		_u.pClass = Class::Reference(value._u.pClass);
	} else if (value.IsSequence()) {
		_u.pSequence = Sequence::Reference(value._u.pSequence);
	} else {
		// nothing to do
		//_valType = VTYPE_nil;
	}
	return *this;
}
#endif

bool Value::MustBe(Signal &sig, bool flag, const char *expected) const
{
	if (flag) return true;
	sig.SetError(ERR_ValueError, "value must be %s", expected);
	return false;
}

Fundamental *Value::ExtractFundamental(Signal sig)
{
	if (IsModule()) {
		return GetModule();
	} else if (IsClass()) {
		return GetClassItself();
	} else if (IsObject()) {
		Fundamental *pFund = GetFundamental();
		if (pFund->IsFunction()) {
			const Object_function *pObjFunc =
								dynamic_cast<const Object_function *>(pFund);
			Class *pClass = pObjFunc->GetFunction()->GetClassToConstruct();
			if (pClass != nullptr) {
				InitAsClass(Class::Reference(pClass));
				pFund = pClass;
			}
		}
		return pFund;
	}
	sig.SetError(ERR_ValueError,
		"%s can not be specified as l-value of member", MakeValueTypeName().c_str());
	return nullptr;
}

bool Value::IsFlatList() const
{
	return Is_list() && GetList().IsFlat();
}

bool Value::IsInstanceOf(ValueType valType) const
{
	if (_valType == valType) return true;
	const ValueTypeInfo *pValueTypeInfo =
							ValueTypePool::GetInstance()->Lookup(_valType);
	if (pValueTypeInfo == nullptr) return false;
	for (Class *pClass = pValueTypeInfo->GetClass(); pClass != nullptr;
										pClass = pClass->GetClassSuper()) {
		if (pClass->GetValueType() == valType) return true;
	}
	return false;
}

const char *Value::GetString() const
{
	if (GetTinyBuffFlag()) return _u.tinyBuff;
	return _u.pStrRef->GetString();
}

String Value::GetStringSTL() const
{
	if (GetTinyBuffFlag()) return String(_u.tinyBuff);
	return _u.pStrRef->GetStringSTL();
}

const Binary &Value::GetBinary() const
{
	return dynamic_cast<Object_binary *>(_u.pObj)->GetBinary();
}

bool Value::Is(const Value &value) const
{
	if (_valType != value.GetValueType()) {
		return false;
	} else if (Is_boolean()) {
		return GetBoolean() == value.GetBoolean();
	} else if (Is_complex()) {
		return GetComplex() == value.GetComplex();
	} else if (Is_number()) {
		return GetNumber() == value.GetNumber();
	} else if (Is_rational()) {
		return GetRational() == value.GetRational();
	} else if (Is_string()) {
		return ::strcmp(GetString(), value.GetString()) == 0;
	} else if (Is_symbol()) {
		return GetSymbol()->IsIdentical(value.GetSymbol());
	} else if (IsModule()) {
		return GetModule() == value.GetModule();
	} else if (IsClass()) {
		return GetClass() == value.GetClass();
	} else if (IsSequence()) {
		return GetSequence() == value.GetSequence();
	} else if (IsObject()) {
		return GetObject() == value.GetObject();
	}
	return false;
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
	if (IsModule()) {
		return GetModule()->DirProp(env, sig, symbols);
	} else if (IsClass()) {
		return GetClassItself()->DirProp(env, sig, symbols, escalateFlag);
	} else if (Is_function()) {
		Class *pClass = GetFunction()->GetClassToConstruct();
		if (pClass != nullptr) {
			return pClass->DirProp(env, sig, symbols, escalateFlag);
		}
	} else if (IsObject()) {
		return GetObject()->DirProp(env, sig, symbols);
	}
	return env.LookupClass(_valType)->DirProp(env, sig, symbols, escalateFlag);
}

void Value::DirValueType(SymbolSet &symbols, bool escalateFlag)
{
	if (IsModule()) {
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
	return Is_dict()?
		dynamic_cast<const Object_dict *>(_u.pObj)->GetDict() : ValueDict::Null;
}

Iterator *Value::GetIterator() const
{
	return Is_iterator()?
		dynamic_cast<const Object_iterator *>(_u.pObj)->GetIterator() : nullptr;
}

Stream &Value::GetStream() const
{
	return dynamic_cast<Object_stream *>(_u.pObj)->GetStream();
}

const Expr *Value::GetExpr() const
{
	return Is_expr()? dynamic_cast<Object_expr *>(_u.pObj)->GetExpr() : nullptr;
}

Function *Value::GetFunction()
{
	return Is_function()? dynamic_cast<Object_function *>(_u.pObj)->GetFunction() : nullptr;
}

Expr *Value::CloneExpr() const
{
	return
		Is_expr()? Expr::Reference(dynamic_cast<Object_expr *>(_u.pObj)->GetExpr()) :
		Is_symbol()? new Expr_Identifier(_u.pSymbol) : nullptr;
}

Fundamental *Value::GetFundamental()
{
	if (IsObject()) {
		return _u.pObj;
	} else if (IsClass()) {
		return _u.pClass;
	} else if (IsModule()) {
		return _u.pModule;
	}
	return nullptr;
}

Iterator *Value::CreateIterator(Signal sig) const
{
	if (IsObject()) {
		return _u.pObj->CreateIterator(sig);
	}
	sig.SetError(ERR_ValueError, "value of %s cannot generate iterator",
											MakeValueTypeName().c_str());
	return nullptr;
}

String Value::ToString(bool exprFlag) const
{
	if (Is_boolean()) {
		return String(_u.flag?
			Gura_Symbol(true_)->GetName() : Gura_Symbol(false_)->GetName());
	} else if (Is_complex()) {
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
	} else if (Is_number()) {
		return NumberToString(_u.num);
	} else if (Is_rational()) {
		const Rational &ratio = *_u.pRatio;
		return ratio.ToString();
	} else if (Is_string()) {
		const char *str = GetString();
		if (exprFlag) return MakeQuotedString(str);
		return String(str);
	} else if (Is_symbol()) {
		String str;
		if (exprFlag) str += '`';
		str += _u.pSymbol->GetName();
		return str;
	} else if (IsModule()) {
		return _u.pModule->ToString(exprFlag);
	} else if (IsClass()) {
		return _u.pClass->ToString(exprFlag);
	} else if (IsSequence()) {
		return _u.pSequence->ToString();
	} else if (IsObject()) {
		return _u.pObj->ToString(exprFlag);
	}
	return String(exprFlag? "nil" : "");
}

Number Value::ToNumber(bool allowPartFlag, bool &successFlag) const
{
	successFlag = true;
	if (Is_boolean()) {
		return _u.flag? 1. : 0.;
	} else if (Is_number()) {
		return _u.num;
	} else if (Is_rational()) {
		const Rational &ratio = *_u.pRatio;
		if (ratio.denom == 0) {
			successFlag = false;
			return 0.;
		}
		return ratio.numer / ratio.denom;
	} else if (Is_string()) {
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
	} else {
		successFlag = false;
		return 0.;
	}
}

int Value::Compare(Environment &env, Signal sig, const Value &value1, const Value &value2)
{
	if (value1.IsInvalid() && value2.IsInvalid()) return 0;
	const OperatorEntry *pOperatorEntry = env.GetOperator(OPTYPE_Cmp)->
						Lookup(value1.GetValueType(), value2.GetValueType());
	if (pOperatorEntry != nullptr) {
		Value result = pOperatorEntry->DoEval(env, sig, value1, value2);
		if (sig.IsSignalled()) return -1;
		if (!result.Is_number()) return -1;
		return result.GetInt();
	}
	if (value1.IsInvalid()) return -1;
	if (value2.IsInvalid()) return +1;
	sig.SetError(ERR_TypeError, "can't compare values between %s and %s",
		value1.MakeValueTypeName().c_str(), value2.MakeValueTypeName().c_str());
	return 0;
}

int Value::CompareBoolean(bool flag1, bool flag2)
{
	return static_cast<int>(flag1) - static_cast<int>(flag2);
}

int Value::CompareComplex(const Complex &comp1, const Complex &comp2)
{
	return (comp1 == comp2)? 0 : -1;
}

int Value::CompareNumber(Number num1, Number num2)
{
	return (num1 == num2)? 0 : (num1 < num2)? -1 : +1;
}

int Value::CompareRational(const Rational &ratio1, const Rational &ratio2)
{
	int ax = ratio1.numer * ratio2.denom, bx = ratio2.numer * ratio1.denom;
	return (ax == bx)? 0 : (ax < bx)? -1 : +1;
}

int Value::CompareString(const char *str1, const char *str2, bool ignoreCaseFlag)
{
	return ignoreCaseFlag? ::strcasecmp(str1, str2) : ::strcmp(str1, str2);
}

int Value::CompareSymbol(const Symbol *pSymbol1, const Symbol *pSymbol2)
{
	return (pSymbol1->GetUniqNum() == pSymbol2->GetUniqNum())? 0 :
			(pSymbol1->GetUniqNum() < pSymbol2->GetUniqNum())? -1 : +1;
}

bool Value::Accept(ValueVisitor &visitor) const
{
	return Is_list()? GetList().Accept(visitor) : visitor.Visit(*this);
}

void Value::InitAsModule(Module *pModule)
{
	Gura_ReleaseValue(*this);
	_valType = VTYPE_Module, _u.pModule = pModule;
	_valFlags = VFLAG_Owner;
}

void Value::InitAsClass(Class *pClass)
{
	Gura_ReleaseValue(*this);
	_valType = VTYPE_Class, _u.pClass = pClass;
	_valFlags = VFLAG_Owner;
}

void Value::InitAsObject(Object *pObj)
{
	Gura_ReleaseValue(*this);
	_valType = pObj->GetClass()->GetValueType(), _u.pObj = pObj;
	_valFlags = VFLAG_Owner;
}

void Value::_SetObject(Object *pObj)
{
	_valType = pObj->GetClass()->GetValueType(), _u.pObj = pObj;
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
	Object_list *pObj = (n == 0)?
		new Object_list(env) : new Object_list(env, n, value);
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

Value Value::CreateList(Environment &env, const Value &v1)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(1);
	valList.push_back(v1);
	return rtn;
}

Value Value::CreateList(Environment &env, const Value &v1, const Value &v2)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(2);
	valList.push_back(v1);
	valList.push_back(v2);
	return rtn;
}

Value Value::CreateList(Environment &env, const Value &v1, const Value &v2,
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

Value Value::CreateList(Environment &env, const Value &v1, const Value &v2,
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

Value Value::CreateList(Environment &env, const Value &v1, const Value &v2,
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

Value Value::CreateList(Environment &env, const Value &v1, const Value &v2,
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

template<typename T>
Value CreateListTmpl(Environment &env, T buff, size_t n)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env, n);
	T p = buff;
	for (size_t i = 0; i < n; i++, p++) valList.push_back(Value(*p));
	return rtn;
}

Value Value::CreateList(Environment &env, const char *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const UChar *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const short *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const UShort *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const long *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const ULong *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const int *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const UInt *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const Int64 *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const UInt64 *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const float *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const double *buff, size_t n)
{
	return CreateListTmpl(env, buff, n);
}

Value Value::CreateList(Environment &env, const char *buff[], size_t n)
{
	return CreateListTmpl(env, buff, n);
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
	if (pValueTypeInfo == nullptr) {
		sig.SetError(ERR_IOError, "invalid value type in the stream");
		return false;
	}
	return pValueTypeInfo->GetClass()->Deserialize(env, sig, stream, value);
}

bool Value::KeyCompare::operator()(const Value &value1, const Value &value2) const
{
	if (value1.GetValueType() != value2.GetValueType()) {
		return value1.GetValueType() < value2.GetValueType();
	} else if (value1.Is_number()) {
		return value1.GetNumber() < value2.GetNumber();
	} else if (value1.Is_string()) {
		return _ignoreCaseFlag?
			::strcasecmp(value1.GetString(), value2.GetString()) < 0 :
			::strcmp(value1.GetString(), value2.GetString()) < 0;
	} else if (value1.Is_symbol()) {
		return value1.GetSymbol()->GetUniqNum() < value2.GetSymbol()->GetUniqNum();
	} else if (value1.Is_list()) {
		const ValueList &valList1 = value1.GetList();
		const ValueList &valList2 = value2.GetList();
		if (valList1.size() < valList2.size()) return true;
		if (valList1.size() > valList2.size()) return false;
		ValueList::const_iterator pValue1 = valList1.begin();
		ValueList::const_iterator pValue2 = valList2.begin();
		for ( ; pValue1 != valList1.end(); pValue1++, pValue2++) {
			int cmp = operator()(*pValue1, *pValue2);
			if (cmp < 0) return true;
			if (cmp > 0) return false;
		}
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ValueList
//-----------------------------------------------------------------------------
const ValueList ValueList::Null;

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
		if (pValue->Is_list()) return false;
	}
	return true;
}

bool ValueList::DoesContain(Environment &env, Signal sig, const Value &value) const
{
	foreach_const (ValueList, pValue, *this) {
		int rtn = Value::Compare(env, sig, *pValue, value);
		if (sig.IsSignalled()) return false;
		if (rtn == 0) return true;
	}
	return false;
}

bool ValueList::DoesContainIterator() const
{
	foreach_const (ValueList, pValue, *this) {
		if (pValue->Is_iterator()) return true;
	}
	return false;
}

bool ValueList::CheckMatrix(size_t *pnRow, size_t *pnCol) const
{
	if (empty()) return false;
	size_t nRow = size();
	size_t nCol = 1;
	if (front().Is_list()) {
		nCol = front().GetList().size();
		foreach_const (ValueList, pValueRow, *this) {
			if (!pValueRow->Is_list()) {
				return false;
			} else if (pValueRow->GetList().size() != nCol) {
				return false;
			}
		}
	} else {
		foreach_const (ValueList, pValueCol, *this) {
			if (pValueCol->Is_list()) return false;
		}
	}
	if (pnRow != nullptr) *pnRow = nRow;
	if (pnCol != nullptr) *pnCol = nCol;
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
		if (pValue->Is_list()) {
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

bool ValueList::Append(Environment &env, Signal sig, Iterator *pIterator)
{
	if (pIterator->IsInfinite()) {
		Iterator::SetError_InfiniteNotAllowed(sig);
		return false;
	}
	Value value;
	while (pIterator->Next(env, sig, value)) {
		push_back(value);
	}
	return !sig.IsSignalled();
}

String ValueList::Join(const char *sep) const
{
	ValueList::const_iterator pValue = begin();
	if (pValue == end()) return "";
	String rtn = pValue->ToString(false);
	pValue++;
	for ( ; pValue != end(); pValue++) {
		rtn += sep;
		rtn += pValue->ToString(false);
	}
	return rtn;
}

Binary ValueList::Joinb(Signal sig) const
{
	Binary buff;
	foreach_const (ValueList, pValue, *this) {
		const Value &value = *pValue;
		if (!value.Is_binary()) {
			sig.SetError(ERR_ValueError, "invalid value type");
			return "";
		}
		buff += value.GetBinary();
	}
	return buff;
}

void ValueList::Print(Signal sig, int indentLevel) const
{
	foreach_const (ValueList, pValue, *this) {
		if (pValue->Is_list()) {
			pValue->GetList().Print(sig, indentLevel + 1);
		} else {
			::printf("%*s%s\n",
					indentLevel * 2, "", pValue->ToString().c_str());
		}
	}
}

void ValueList::PrintEach(Environment &env, Signal sig, Stream *pStream) const
{
	foreach_const (ValueList, pValue, *this) {
		const Value &value = *pValue;
		pStream->Print(sig, value.ToString(false).c_str());
		if (sig.IsSignalled()) break;
	}
}

void ValueList::PrintfEach(Environment &env, Signal sig, Stream *pStream, const char *format) const
{
	foreach_const (ValueList, pValue, *this) {
		const Value &value = *pValue;
		if (value.Is_list()) {
			pStream->PrintFmt(sig, format, value.GetList());
		} else {
			pStream->PrintFmt(sig, format, ValueList(value));
		}
		if (sig.IsSignalled()) break;
	}
}

void ValueList::PrintlnEach(Environment &env, Signal sig, Stream *pStream) const
{
	foreach_const (ValueList, pValue, *this) {
		const Value &value = *pValue;
		pStream->Println(sig, value.ToString(false).c_str());
		if (sig.IsSignalled()) break;
	}
}

bool ValueList::ToStringList(Signal sig, StringList &strList) const
{
	foreach_const (ValueList, pValue, *this) {
		String str = pValue->ToString(false);
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
const ValueMap ValueMap::Null;

//-----------------------------------------------------------------------------
// ValueDict
//-----------------------------------------------------------------------------
const ValueDict ValueDict::Null;

const Value *ValueDict::Find(Signal sig, const Value &valueIdx) const
{
	if (!valueIdx.IsValidKey()) {
		sig.SetError(ERR_KeyError, "invalid value type for key");
		return nullptr;
	}
	const_iterator iter = find(valueIdx);
	return (iter == end())? nullptr : &iter->second;
}

bool ValueDict::Store(Signal sig, const ValueList &valList, StoreMode storeMode)
{
	enum { FIELD_Key, FIELD_Value } field = FIELD_Key;
	Value valueIdx;
	const ValueList *pValList = &valList;
	if (valList.size() == 1 && valList[0].Is_list()) {
		pValList = &valList[0].GetList();
	}
	foreach_const (ValueList, pValue, *pValList) {
		if (field == FIELD_Key) {
			Value value;
			valueIdx = *pValue;
			if (valueIdx.Is_list()) {
				const ValueList &valListElem = valueIdx.GetList();
				if (valListElem.size() != 2) {
					sig.SetError(ERR_KeyError, "invalid key-value format");
					return false;
				}
				valueIdx = valListElem[0];
				value = valListElem[1];
			}
			if (!valueIdx.IsValidKey()) {
				sig.SetError(ERR_KeyError, "invalid value type for key");
				return false;
			}
			if (value.IsValid()) {
				ValueDict::iterator iterDst = find(valueIdx);
				if (iterDst == end()) {
					insert(ValueDict::value_type(valueIdx, value));
				} else if (storeMode == STORE_Overwrite) {
					iterDst->second = value;
				} else if (storeMode == STORE_Timid) {
					// nothing to do
				} else {
					sig.SetError(ERR_KeyError, "duplicated key '%s'", valueIdx.ToString().c_str());
					return false;
				}
			} else {
				field = FIELD_Value;
			}
		} else { // FIELD_Value
			ValueDict::iterator iterDst = find(valueIdx);
			if (iterDst == end()) {
				insert(ValueDict::value_type(valueIdx, *pValue));
			} else if (storeMode == STORE_Overwrite) {
				iterDst->second = *pValue;
			} else if (storeMode == STORE_Timid) {
				// nothing to do
			} else {
				sig.SetError(ERR_KeyError, "duplicated key '%s'", valueIdx.ToString().c_str());
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
		} else if (storeMode == STORE_Overwrite) {
			iterDst->second = iterSrc->second;
		} else if (storeMode == STORE_Timid) {
			// nothing to do
		} else {
			sig.SetError(ERR_KeyError, "duplicated key '%s'", valueIdx.ToString().c_str());
			return false;
		}
	}
	return true;
}

bool ValueDict::Store(Signal sig, const Value &valueIdx, const Value &value, StoreMode storeMode)
{
	if (!valueIdx.IsValidKey()) {
		sig.SetError(ERR_KeyError, "invalid value type for key");
		return false;
	}
	ValueDict::iterator iterDst = find(valueIdx);
	if (iterDst == end()) {
		insert(ValueDict::value_type(valueIdx, value));
	} else if (storeMode == STORE_Overwrite) {
		iterDst->second = value;
	} else if (storeMode == STORE_Timid) {
		// nothing to do
	} else {
		sig.SetError(ERR_KeyError, "duplicated key '%s'", valueIdx.ToString().c_str());
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
