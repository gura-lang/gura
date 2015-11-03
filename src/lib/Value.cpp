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
	if (valueSrc.IsDumbCopiable()) {
		valueDst._u = valueSrc._u;
	} else if (valueSrc.Is_string()) {
		valueDst._u.pStrShrd = valueSrc._u.pStrShrd->Reference();
	} else if (valueSrc.IsFundamental()) {
		valueDst._u.pFund = Fundamental::Reference(valueSrc._u.pFund);
	} else if (valueSrc.Is_complex()) {
		valueDst._u.pComp = new Complex(*valueSrc._u.pComp);
	} else if (valueSrc.Is_rational()) {
		valueDst._u.pRatio = new Rational(*valueSrc._u.pRatio);
	}
}

void Gura_ReleaseValue(Value &value)
{
	if (value.GetTinyBuffFlag()) {
		// nothing to do
	} else if (value.Is_string()) {
		StringShared::Delete(value._u.pStrShrd);
		value._u.pStrShrd = nullptr;
	} else if (value.IsFundamental()) {
		if (value.IsFundOwner()) Fundamental::Delete(value._u.pFund);
		value._u.pFund = nullptr;
	} else if (value.Is_complex()) {
		delete value._u.pComp;
		value._u.pComp = nullptr;
	} else if (value.Is_rational()) {
		delete value._u.pRatio;
		value._u.pRatio = nullptr;
	}
	value._valType = VTYPE_undefined;
	value._valFlags = VFLAG_None;
}

//-----------------------------------------------------------------------------
// Value
//-----------------------------------------------------------------------------
const Value Value::Undefined(VTYPE_undefined, VFLAG_None);	// undefined
const Value Value::Nil;										// nil
const Value Value::True(true);								// boolean
const Value Value::False(false);							// boolean
const Value Value::Zero(0);									// number
const Value Value::One(1);									// number

const Value::LessThan Value::LessThanCase(false);
const Value::LessThan Value::LessThanIgnoreCase(true);

Value::Value(const Value &value)
{
	Gura_CopyValue(*this, value);
}

Value::Value(Module *pModule, UShort valFlags) :
				_valType(VTYPE_Module), _valFlags(valFlags)
{
	_u.pFund = pModule;
}

Value::Value(Class *pClass, UShort valFlags) :
				_valType(VTYPE_Class), _valFlags(valFlags)
{
	_u.pFund = pClass;
}

Value::Value(Object *pObj, UShort valFlags) :
				_valType(pObj->GetClass()->GetValueType()), _valFlags(valFlags)
{
	_u.pFund = pObj;
}

Value::~Value()
{
	if (IsInvalid()) return;
	// when the application terminates, it calls a destructor for statically
	// defined values such as Value::Nil. until that timing, it's likely
	// that VTYPE_xxxx referenced in Gura_ReleaseValue() are not initialized and
	// it causes application error. to avoid such a case, the above line is
	// necessary.
	Gura_ReleaseValue(*this);
}

// VTYPE_string
Value::Value(const String &str) : _valType(VTYPE_string), _valFlags(VFLAG_None)
{
	size_t len = str.size();
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str.c_str(), len + 1);
	} else {
		_u.pStrShrd = new StringShared(str);
	}
}

Value::Value(const char *str) : _valType(VTYPE_string), _valFlags(VFLAG_None)
{
	size_t len = ::strlen(str);
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str, len + 1);
	} else {
		_u.pStrShrd = new StringShared(str);
	}
}

Value::Value(const char *str, size_t len) : _valType(VTYPE_string), _valFlags(VFLAG_None)
{
	if (len < sizeof(_u) - 1) {
		_valFlags |= VFLAG_TinyBuff;
		::memcpy(_u.tinyBuff, str, len);
		_u.tinyBuff[len] = '\0';
	} else {
		_u.pStrShrd = new StringShared(String(str, len));
	}
}

Value &Value::operator=(const Value &value)
{
	Gura_ReleaseValue(*this);
	Gura_CopyValue(*this, value);
	return *this;
}

bool Value::MustBe(Signal &sig, bool flag, const char *expected) const
{
	if (flag) return true;
	sig.SetError(ERR_ValueError, "value must be %s", expected);
	return false;
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
	return _u.pStrShrd->GetString();
}

String Value::GetStringSTL() const
{
	if (GetTinyBuffFlag()) return String(_u.tinyBuff);
	return _u.pStrShrd->GetStringSTL();
}

Binary &Value::GetBinary() const
{
	return dynamic_cast<Object_binary *>(GetObject())->GetBinary();
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
	} else if (IsFundamental()) {
		return GetFundamental() == value.GetFundamental();
	}
	return false;
}

Value Value::EmptyIndexGet(Environment &env) const
{
	Signal &sig = env.GetSignal();
	if (IsPrimitive()) {
		return env.LookupClass(_valType)->EmptyIndexGetPrimitive(env, *this);
	} else if (IsObject()) {
		return GetObject()->EmptyIndexGet(env);
	}
	sig.SetError(ERR_TypeError, "object should be specified as l-value of indexer");
	return Value::Nil;
}

void Value::EmptyIndexSet(Environment &env, const Value &value)
{
	Signal &sig = env.GetSignal();
	if (IsObject()) {
		GetObject()->EmptyIndexSet(env, value);
		return;
	}
	sig.SetError(ERR_TypeError, "object should be specified as l-value of indexer");
}

Value Value::IndexGet(Environment &env, const Value &valueIdx) const
{
	Signal &sig = env.GetSignal();
	if (IsPrimitive()) {
		return env.LookupClass(_valType)->IndexGetPrimitive(env, *this, valueIdx);
	} else if (IsObject()) {
		return GetObject()->IndexGet(env, valueIdx);
	}
	sig.SetError(ERR_TypeError, "object should be specified as l-value of indexer");
	return Value::Nil;
}

void Value::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	Signal &sig = env.GetSignal();
	if (IsObject()) {
		GetObject()->IndexSet(env, valueIdx, value);
		return;
	}
	sig.SetError(ERR_TypeError, "object should be specified as l-value of indexer");
}

bool Value::DirProp(Environment &env, SymbolSet &symbols, bool escalateFlag) const
{
	if (IsModule()) {
		return GetModule()->DirProp(env, symbols);
	} else if (IsClass()) {
		return GetClassItself()->DirProp(env, symbols, escalateFlag);
	} else if (IsObject()) {
		return GetObject()->DirProp(env, symbols);
	} else {
		return GetClass()->DirProp(env, symbols, escalateFlag);
	}
}

void Value::DirValueType(SymbolSet &symbols, bool escalateFlag) const
{
	if (IsModule()) {
		GetModule()->DirValueType(symbols);
	} else if (IsClass()) {
		// nothing to do
	} else if (IsObject()) {
		// nothing to do
	}
}

Value Value::GetProp(const Symbol *pSymbol, const SymbolSet &attrs) const
{
	Fundamental *pFund = nullptr;
	if (IsPrimitive()) {
		Class *pClass = GetClass();
		bool evaluatedFlag = false;
		Value rtn = pClass->GetPropPrimitive(*this, pSymbol, attrs, evaluatedFlag);
		if (evaluatedFlag) return rtn;
		pFund = pClass;
	} else {
		pFund = GetFundamental();
	}
	EnvRefMode envRefMode =
		pFund->IsModule()? ENVREF_Module :
		!(pFund->IsClass() || pFund->IsObject())? ENVREF_Escalate :
		IsPrivileged()? ENVREF_Escalate : ENVREF_Restricted;
	int cntSuperSkip = GetSuperSkipCount();
	Value rtn = pFund->GetProp(*pFund, pSymbol, attrs, nullptr, envRefMode, cntSuperSkip);
	return rtn;
}

Callable *Value::GetCallable(const Symbol *pSymbol, const SymbolSet &attrs) const
{
	Fundamental *pFund = IsPrimitive()? GetClass() : GetFundamental();
	Callable *pCallable = pFund->GetCallable(pSymbol);
	if (pFund->IsSignalled()) return nullptr;
	if (pCallable != nullptr) return pCallable->Reference();
	Value valueCar = GetProp(pSymbol, attrs);
	if (pFund->IsSignalled()) return nullptr;
	if (valueCar.IsFundamental()) {
		// the pointer must be referenced because valueCar will be destroyed
		// after this scope vanishes.
		return valueCar.GetFundamental()->Reference();
	}
	pFund->SetError(ERR_TypeError, "object is not callable");
	return nullptr;
}

ErrorType Value::GetErrorType() const
{
	return dynamic_cast<Object_error *>(GetObject())->GetError().GetType();
}

ValueList &Value::GetList() const
{
	return dynamic_cast<Object_list *>(GetObject())->GetList();
}

ValueDict &Value::GetDict() const
{
	return dynamic_cast<Object_dict *>(GetObject())->GetDict();
}

Iterator *Value::GetIterator() const
{
	return dynamic_cast<Object_iterator *>(GetObject())->GetIterator();
}

Stream &Value::GetStream() const
{
	return dynamic_cast<Object_stream *>(GetObject())->GetStream();
}

Expr *Value::GetExpr() const
{
	return dynamic_cast<Object_expr *>(GetObject())->GetExpr();
}

Function *Value::GetFunction() const
{
	return dynamic_cast<Object_function *>(GetObject())->GetFunction();
}

Iterator *Value::CreateIterator(Signal &sig) const
{
	if (IsObject()) {
		return GetObject()->CreateIterator(sig);
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
	} else if (IsFundamental()) {
		return _u.pFund->ToString(exprFlag);
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

int Value::Compare(Environment &env, const Value &value1, const Value &value2)
{
	Signal &sig = env.GetSignal();
	if (value1.IsInvalid() && value2.IsInvalid()) return 0;
	const OperatorEntry *pOperatorEntry = env.GetOperator(OPTYPE_Cmp)->
						Lookup(value1.GetValueType(), value2.GetValueType());
	if (pOperatorEntry != nullptr) {
		Value result = pOperatorEntry->DoEval(env, value1, value2);
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
	_valType = VTYPE_Module, _u.pFund = pModule;
	_valFlags = VFLAG_FundOwner;
}

void Value::InitAsClass(Class *pClass)
{
	Gura_ReleaseValue(*this);
	_valType = VTYPE_Class, _u.pFund = pClass;
	_valFlags = VFLAG_FundOwner;
}

void Value::InitAsObject(Object *pObj)
{
	Gura_ReleaseValue(*this);
	_valType = pObj->GetClass()->GetValueType(), _u.pFund = pObj;
	_valFlags = VFLAG_FundOwner;
}

void Value::_SetObject(Object *pObj)
{
	_valType = pObj->GetClass()->GetValueType(), _u.pFund = pObj;
	_valFlags = VFLAG_FundOwner;
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
	Object_dict *pObj = new Object_dict(env, new ValueDict(ignoreCaseFlag), true);
	InitAsObject(pObj);
	return pObj->GetDict();
}

bool Value::CastType(Environment &env, ValueType valType, Value &valueCasted) const
{
	valueCasted = *this;
	if (IsType(valType)) return true;
	AutoPtr<Declaration> pDecl(new Declaration(Gura_Symbol(nil), valType));
	return env.LookupClass(valType)->CastFrom(env, valueCasted, pDecl.get());
}

Value Value::CreateList(Environment &env)
{
	Value rtn;
	rtn.InitAsList(env);
	return rtn;
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

bool Value::Serialize(Environment &env, Stream &stream, const Value &value)
{
	Signal &sig = env.GetSignal();
	const ValueTypeInfo *pValueTypeInfo = value.GetValueTypeInfo();
	ULong valType = static_cast<ULong>(value.GetValueType());
	if (!stream.SerializePackedULong(sig, valType)) return false;
	return pValueTypeInfo->GetClass()->Serialize(env, stream, value);
}

bool Value::Deserialize(Environment &env, Stream &stream, Value &value, bool mustBeValidFlag)
{
	Signal &sig = env.GetSignal();
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
	return pValueTypeInfo->GetClass()->Deserialize(env, stream, value);
}

bool Value::LessThan::operator()(const Value &value1, const Value &value2) const
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
const ValueList ValueList::Empty;

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

bool ValueList::DoesContain(Environment &env, const Value &value) const
{
	Signal &sig = env.GetSignal();
	foreach_const (ValueList, pValue, *this) {
		int rtn = Value::Compare(env, *pValue, value);
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

bool ValueList::AssumeSameLength(Signal &sig,
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

bool ValueList::Append(Environment &env, Iterator *pIterator)
{
	Signal &sig = env.GetSignal();
	if (pIterator->IsInfinite()) {
		Iterator::SetError_InfiniteNotAllowed(sig);
		return false;
	}
	Value value;
	while (pIterator->Next(env, value)) {
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

Binary ValueList::Joinb(Signal &sig) const
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

void ValueList::Print(Signal &sig, int indentLevel) const
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

void ValueList::PrintEach(Environment &env, Stream *pStream) const
{
	Signal &sig = env.GetSignal();
	foreach_const (ValueList, pValue, *this) {
		const Value &value = *pValue;
		pStream->Print(sig, value.ToString(false).c_str());
		if (sig.IsSignalled()) break;
	}
}

void ValueList::PrintfEach(Environment &env, Stream *pStream, const char *format) const
{
	Signal &sig = env.GetSignal();
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

void ValueList::PrintlnEach(Environment &env, Stream *pStream) const
{
	Signal &sig = env.GetSignal();
	foreach_const (ValueList, pValue, *this) {
		const Value &value = *pValue;
		pStream->Println(sig, value.ToString(false).c_str());
		if (sig.IsSignalled()) break;
	}
}

bool ValueList::ToStringList(Signal &sig, StringList &strList) const
{
	foreach_const (ValueList, pValue, *this) {
		String str = pValue->ToString(false);
		if (sig.IsSignalled()) return false;
		strList.push_back(str);
	}
	return true;
}

bool ValueList::Serialize(Environment &env, Stream &stream) const
{
	Signal &sig = env.GetSignal();
	ULong num = static_cast<ULong>(size());
	if (!stream.SerializePackedULong(sig, num)) return false;
	foreach_const (ValueList, pValue, *this) {
		if (!Value::Serialize(env, stream, *pValue)) return false;
	}
	return true;
}

bool ValueList::Deserialize(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	ULong num = 0;
	if (!stream.DeserializePackedULong(sig, num)) return false;
	reserve(num);
	Value value;
	while (num-- > 0) {
		if (!Value::Deserialize(env, stream, value, false)) return false;
		push_back(value);
	}
	return true;
}

//-----------------------------------------------------------------------------
// ValueMap
//-----------------------------------------------------------------------------
const ValueMap ValueMap::Empty;

//-----------------------------------------------------------------------------
// ValueDict
//-----------------------------------------------------------------------------
const ValueDict ValueDict::Empty;

const Value *ValueDict::Find(Signal &sig, const Value &valueIdx) const
{
	if (!valueIdx.IsValidKey()) {
		sig.SetError(ERR_KeyError, "invalid value type for key");
		return nullptr;
	}
	const_iterator iter = find(valueIdx);
	return (iter == end())? nullptr : &iter->second;
}

bool ValueDict::Store(Signal &sig, const ValueList &valList, StoreMode storeMode)
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

bool ValueDict::Store(Signal &sig, const ValueDict &valDict, StoreMode storeMode)
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

bool ValueDict::Store(Signal &sig, const Value &valueIdx, const Value &value, StoreMode storeMode)
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

bool ValueDict::Serialize(Environment &env, Stream &stream) const
{
	Signal &sig = env.GetSignal();
	ULong num = static_cast<ULong>(size());
	if (!stream.SerializePackedULong(sig, num)) return false;
	foreach_const (ValueDict, iter, *this) {
		if (!Value::Serialize(env, stream, iter->first)) return false;
		if (!Value::Serialize(env, stream, iter->second)) return false;
	}
	return true;
}

bool ValueDict::Deserialize(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	ULong num = 0;
	if (!stream.DeserializePackedULong(sig, num)) return false;
	Value valueIdx, value;
	while (num-- > 0) {
		if (!Value::Deserialize(env, stream, valueIdx, false)) return false;
		if (!Value::Deserialize(env, stream, value, false)) return false;
		insert(ValueDict::value_type(valueIdx, value));
	}
	return true;
}

void ValueDict::SetError_InvalidKey(Signal &sig, const Value &valueKey)
{
	sig.SetError(ERR_KeyError, "invalid value type for key");
}

void ValueDict::SetError_InvalidIterator(Signal &sig)
{
	sig.SetError(ERR_KeyError, "invalid iterator of dict");
}

void ValueDict::SetError_KeyNotFound(Signal &sig, const Value &valueKey)
{
	sig.SetError(ERR_KeyError, "dictionary doesn't have a key '%s'", valueKey.ToString().c_str());
}

void ValueDict::SetError_NotWritable(Signal &sig)
{
	sig.SetError(ERR_ValueError, "not a writable dictionary");
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
