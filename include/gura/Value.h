#ifndef __GURA_VALUE_H__
#define __GURA_VALUE_H__

#include "Common.h"
#include "Symbol.h"
#include "Stream.h"
#include "DateTime.h"

namespace Gura {

class Expr;
class Binary;
class ObjectBase;
class Environment;
class Module;
class Function;
class Class;
class Object;
class Object_function;
class Object_string;
class Object_binary;
class Object_binaryptr;
class Object_list;
class Object_matrix;
class Object_dict;
class Object_datetime;
class Object_timedelta;
class Object_iterator;
class Object_stream;
class Object_expr;
class Object_environment;
class Object_error;
class Object_uri;
class Object_semaphore;
class Object_image;
class Object_color;
class Object_palette;
class Object_audio;
class Object_codec;
class Object_args;
class StructObject;

class ValueList;
class ValueDict;

class Iterator;

//-----------------------------------------------------------------------------
// ValueType
//-----------------------------------------------------------------------------
typedef unsigned short ValueType;

#define Gura_VTYPEInfo(name) \
(ValueTypePool::GetInstance()->_pValueTypeInfo_##name)

#define Gura_DeclareVTYPE(name) \
ValueTypeInfo *_pValueTypeInfo_##name

#define Gura_RealizeVTYPEEx(name, str) do { \
	_pValueTypeInfo_##name = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(_pValueTypeInfo_##name); \
	VTYPE_##name = _pValueTypeInfo_##name->GetValueType(); \
} while (0)

#define Gura_RealizeVTYPE(name) \
Gura_RealizeVTYPEEx(name, #name)

#define Gura_UserClass(name) \
(Class_##name::_pValueTypeInfo->GetClass())

#define Gura_ImplementClass(name) \
Class_##name::Class_##name(Environment *pEnvOuter) : Class(pEnvOuter)

#define Gura_DeclareUserClass(name) \
class DLLEXPORT Class_##name : public Class { \
public: \
	inline Class_##name(Environment *pEnvOuter, ValueType valType) : Class(pEnvOuter, valType) {} \
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl); \
	virtual bool CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl); \
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass); \
	virtual void Prepare(); \
public: \
	static ValueTypeInfo *_pValueTypeInfo; \
}; \
DLLEXPORT extern ValueType VTYPE_##name;

#define Gura_ImplementUserClass(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = NULL; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
bool Class_##name::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl) { return false; } \
bool Class_##name::CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl) { return false; } \
Object *Class_##name::CreateDescendant(Environment &env, Signal sig, Class *pClass) { return Class::CreateDescendant(env, sig, pClass); } \
void Class_##name::Prepare()

#define Gura_ImplementUserClassWithCast(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = NULL; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
Object *Class_##name::CreateDescendant(Environment &env, Signal sig, Class *pClass) { return Class::CreateDescendant(env, sig, pClass); } \
void Class_##name::Prepare()

#define Gura_ImplementUserInheritableClass(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = NULL; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
bool Class_##name::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl) { return false; } \
bool Class_##name::CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl) { return false; } \
void Class_##name::Prepare()

#define Gura_ImplementUserInheritableClassWithCast(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = NULL; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
void Class_##name::Prepare()

#define Gura_ImplementCastFrom(name) \
bool Class_##name::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)

#define Gura_ImplementCastTo(name) \
bool Class_##name::CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl)

#define Gura_ImplementDescendantCreator(name) \
Object *Class_##name::CreateDescendant(Environment &env, Signal sig, Class *pClass)

#define Gura_RealizeUserClassEx(name, str, pClassBase) do { \
	Class_##name::_pValueTypeInfo = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(Class_##name::_pValueTypeInfo); \
	VTYPE_##name = Class_##name::_pValueTypeInfo->GetValueType(); \
	Class_##name *pClass = new Class_##name(pClassBase, \
						Class_##name::_pValueTypeInfo->GetValueType()); \
	Class_##name::_pValueTypeInfo->SetClass(pClass); \
	pClass->Prepare(); \
} while (0)

#define Gura_RealizeUserClassExWithoutPrepare(name, str, pClassBase) do { \
	Class_##name::_pValueTypeInfo = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(Class_##name::_pValueTypeInfo); \
	VTYPE_##name = Class_##name::_pValueTypeInfo->GetValueType(); \
	Class_##name *pClass = new Class_##name(pClassBase, \
						Class_##name::_pValueTypeInfo->GetValueType()); \
	Class_##name::_pValueTypeInfo->SetClass(pClass); \
} while (0)

#define Gura_RealizeUserClass(name, pClassBase) \
Gura_RealizeUserClassEx(name, #name, pClassBase)

#define Gura_RealizeUserClassWithoutPrepare(name, pClassBase) \
Gura_RealizeUserClassExWithoutPrepare(name, #name, pClassBase)

// nil / undefined
DLLDECLARE extern ValueType VTYPE_nil;
DLLDECLARE extern ValueType VTYPE_undefined;
// primitive types
DLLDECLARE extern ValueType VTYPE_symbol;
DLLDECLARE extern ValueType VTYPE_boolean;
DLLDECLARE extern ValueType VTYPE_number;
DLLDECLARE extern ValueType VTYPE_complex;
// for declaration
DLLDECLARE extern ValueType VTYPE_quote;
DLLDECLARE extern ValueType VTYPE_any;
// container types
DLLDECLARE extern ValueType VTYPE_Module;
DLLDECLARE extern ValueType VTYPE_Class;
// object types
DLLDECLARE extern ValueType VTYPE_object;
DLLDECLARE extern ValueType VTYPE_function;
DLLDECLARE extern ValueType VTYPE_string;
DLLDECLARE extern ValueType VTYPE_binary;
DLLDECLARE extern ValueType VTYPE_binaryptr;
DLLDECLARE extern ValueType VTYPE_list;
DLLDECLARE extern ValueType VTYPE_matrix;
DLLDECLARE extern ValueType VTYPE_dict;
DLLDECLARE extern ValueType VTYPE_stream;
DLLDECLARE extern ValueType VTYPE_datetime;
DLLDECLARE extern ValueType VTYPE_timedelta;
DLLDECLARE extern ValueType VTYPE_iterator;
DLLDECLARE extern ValueType VTYPE_expr;
DLLDECLARE extern ValueType VTYPE_environment;
DLLDECLARE extern ValueType VTYPE_error;
DLLDECLARE extern ValueType VTYPE_uri;
DLLDECLARE extern ValueType VTYPE_semaphore;
DLLDECLARE extern ValueType VTYPE_Struct;
DLLDECLARE extern ValueType VTYPE_image;
DLLDECLARE extern ValueType VTYPE_color;
DLLDECLARE extern ValueType VTYPE_palette;
DLLDECLARE extern ValueType VTYPE_audio;
DLLDECLARE extern ValueType VTYPE_codec;
DLLDECLARE extern ValueType VTYPE_args;

//-----------------------------------------------------------------------------
// ValueTypeInfo
//-----------------------------------------------------------------------------
class DLLDECLARE ValueTypeInfo {
private:
	ValueType _valType;
	const Symbol *_pSymbol;
	Class *_pClass;
public:
	inline ValueTypeInfo(ValueType valType, const Symbol *pSymbol, Class *pClass) :
					_valType(valType), _pSymbol(pSymbol), _pClass(pClass) {}
	~ValueTypeInfo();
	inline static void Delete(ValueTypeInfo *pValTypeInfo) { delete pValTypeInfo; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline ValueType GetValueType() const { return _valType; }
	inline Class *GetClass() const { return _pClass; }
	void SetClass(Class *pClass);
};

//-----------------------------------------------------------------------------
// ValueTypeMap
//-----------------------------------------------------------------------------
class DLLDECLARE ValueTypeMap : public std::map<const Symbol *,
						const ValueTypeInfo *, Symbol::KeyCompare_UniqNumber> {
public:
	static const ValueTypeMap Null;
};

//-----------------------------------------------------------------------------
// ValueTypeList
//-----------------------------------------------------------------------------
typedef std::vector<ValueTypeInfo *> ValueTypeList;

//-----------------------------------------------------------------------------
// ValueTypePool
//-----------------------------------------------------------------------------
class DLLDECLARE ValueTypePool {
public:
	// primitive types
	Gura_DeclareVTYPE(nil);
	Gura_DeclareVTYPE(undefined);
	Gura_DeclareVTYPE(symbol);
	Gura_DeclareVTYPE(boolean);
	Gura_DeclareVTYPE(number);
	Gura_DeclareVTYPE(complex);
	// for declaration
	Gura_DeclareVTYPE(quote);
	Gura_DeclareVTYPE(any);
	// container types
	Gura_DeclareVTYPE(Module);
	Gura_DeclareVTYPE(Class);
	// object types
	Gura_DeclareVTYPE(object);
	Gura_DeclareVTYPE(function);
	Gura_DeclareVTYPE(string);
	Gura_DeclareVTYPE(binary);
	Gura_DeclareVTYPE(binaryptr);
	Gura_DeclareVTYPE(list);
	Gura_DeclareVTYPE(matrix);
	Gura_DeclareVTYPE(dict);
	Gura_DeclareVTYPE(stream);
	Gura_DeclareVTYPE(datetime);
	Gura_DeclareVTYPE(timedelta);
	Gura_DeclareVTYPE(iterator);
	Gura_DeclareVTYPE(expr);
	Gura_DeclareVTYPE(environment);
	Gura_DeclareVTYPE(error);
	Gura_DeclareVTYPE(uri);
	Gura_DeclareVTYPE(semaphore);
	Gura_DeclareVTYPE(Struct);
	Gura_DeclareVTYPE(image);
	Gura_DeclareVTYPE(color);
	Gura_DeclareVTYPE(palette);
	Gura_DeclareVTYPE(audio);
	Gura_DeclareVTYPE(codec);
	Gura_DeclareVTYPE(args);
private:
	static ValueTypePool *_pInst;
	ValueTypeList _valueTypeList;
private:
	inline ValueTypePool() {}
public:
	~ValueTypePool();
	static void Initialize(Environment &env);
	static ValueTypePool *GetInstance();
	inline ValueTypeList &GetList() { return _valueTypeList; }
	inline const ValueTypeList &GetList() const { return _valueTypeList; }
	ValueTypeInfo *Add(const Symbol *pSymbol);
	ValueTypeInfo *Lookup(ValueType valType);
	ValueTypeInfo *LookupWithCheck(ValueType valType);
	static void OnModuleEntry(Environment &env, Signal sig);
private:
	void _Initialize(Environment &env);
private:
	inline ValueTypePool(const ValueTypePool &valTypeInfoPool) {}
	inline void operator=(const ValueTypePool &valTypeInfoPool) {}
};

inline const Symbol *GetValueTypeSymbol(ValueType valType)
{
	return ValueTypePool::GetInstance()->Lookup(valType)->GetSymbol();
}

//-----------------------------------------------------------------------------
// ValueVisitor
//-----------------------------------------------------------------------------
class ValueVisitor {
public:
	virtual void Visit(Signal sig, const Value &value) = 0;
};

//-----------------------------------------------------------------------------
// Value
//-----------------------------------------------------------------------------
class DLLDECLARE Value {
public:
	class KeyCompare {
	private:
		bool _ignoreCaseFlag;
	public:
		inline KeyCompare(bool ignoreCaseFlag = false) : _ignoreCaseFlag(ignoreCaseFlag) {}
		inline bool operator()(const Value &value1, const Value &value2) const {
			return Compare(value1, value2, _ignoreCaseFlag) < 0;
		}
	};
public:
	enum {
		MaxSuperSkipCount = 255,
	};
	enum {
		FLAG_None		= 0,
		FLAG_NoOwner	= (0 << 0),
		FLAG_Owner		= (1 << 0),
		FLAG_TinyBuff	= (1 << 1),
		// b15-b8 are reserved for super-skip count
	};
private:
	unsigned short _valType;
	unsigned short _flags;
	union {
		Number num;				// VTYPE_number
		bool flag;				// VTYPE_boolean
		const Symbol *pSymbol;	// VTYPE_symbol
		Complex *pComp;			// VTYPE_complex
		Module *pModule;		// VTYPE_module
		Class *pClass;			// VTYPE_class
		Object *pObj;			// objects
		char tinyBuff[1];
	} _u;
private:
	static const Complex _compZero;
public:
	static const Value Null;
	static const Value Undefined;
	static const KeyCompare KeyCompareCase;
	static const KeyCompare KeyCompareIgnoreCase;
public:
	Value(const Value &value);
	~Value();
	// VTYPE_nil
	inline Value() : _valType(VTYPE_nil), _flags(FLAG_Owner) {}
	inline Value(ValueType valType, unsigned short flags) : _valType(valType), _flags(flags) {}
	// VTYPE_module
	inline Value(Module *pModule) : _valType(VTYPE_Module), _flags(FLAG_Owner) {
		_u.pModule = pModule;
	}
	inline Value(Module *pModule, unsigned short flags) : _valType(VTYPE_Module), _flags(flags) {
		_u.pModule = pModule;
	}
	// VTYPE_class
	inline Value(Class *pClass) : _valType(VTYPE_Class), _flags(FLAG_Owner) {
		_u.pClass = pClass;
	}
	inline Value(Class *pClass, unsigned short flags) : _valType(VTYPE_Class), _flags(flags) {
		_u.pClass = pClass;
	}
	// VTYPE_object etc
	Value(Object *pObj);
	Value(Object *pObj, unsigned short flags);
	// VTYPE_number
	inline Value(Number num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = num;
	}
	inline Value(int num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(unsigned int num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(char num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(unsigned char num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(short num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(unsigned short num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(long num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(unsigned long num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(int64 num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(uint64 num) : _valType(VTYPE_number), _flags(FLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	// VTYPE_boolean
	inline Value(bool flag) : _valType(VTYPE_boolean), _flags(FLAG_Owner) {
		_u.flag = flag;
	}
	// VTYPE_symbol
	inline Value(const Symbol *pSymbol) : _valType(VTYPE_symbol), _flags(FLAG_Owner) {
		_u.pSymbol = pSymbol;
	}
	// VTYPE_complex
	inline Value(const Complex &comp) : _valType(VTYPE_complex), _flags(FLAG_Owner) {
		_u.pComp = new Complex(comp);
	}
	// VTYPE_string, VTYPE_binary
	Value(Environment &env, const char *str);
	Value(Environment &env, const char *str, size_t len);
	// VTYPE_iterator
	Value(Environment &env, Iterator *pIterator);
	// VTYPE_stream
	Value(Environment &env, Stream *pStream);
	// VTYPE_expr
	Value(Environment &env, Expr *pExpr);
	// VTYPE_function
	Value(Environment &env, Function *pFunc, const Value &valueThis);
	// VTYPE_datetime
	Value(Environment &env, const DateTime &dateTime);
	// VTYPE_timedelta
	Value(Environment &env, const TimeDelta &timeDelta);
	Value &operator=(const Value &value);
	inline unsigned short GetFlags() const { return _flags; }
	inline void SetFlags(unsigned short flags) { _flags = flags; }
	inline bool IsOwner() const { return (_flags & FLAG_Owner)? true : false; }
	inline bool GetTinyBuffFlag() const { return (_flags & FLAG_TinyBuff)? true : false; }
	inline int GetSuperSkipCount() const { return (_flags >> 8) & 0xff; }
	inline void SetSuperSkipCount(int cntSuperSkip) {
		_flags = (_flags & 0x00ff) | (static_cast<unsigned short>(cntSuperSkip & 0xff) << 8);
	}
	const char *GetTypeName() const;
	inline ValueType GetType() const { return _valType; }
	inline bool IsType(ValueType valType) const { return _valType == valType;	}
	inline bool IsObject() const			{ return _valType >= VTYPE_object && !GetTinyBuffFlag(); }
	inline bool IsPrimitive() const			{ return _valType <= VTYPE_complex;	}
	inline bool IsInvalid() const			{ return IsType(VTYPE_nil) || IsType(VTYPE_undefined); }
	inline bool IsUndefined() const			{ return IsType(VTYPE_undefined);	}
	inline bool IsValid() const				{ return !IsInvalid();				}
	inline bool IsDefined() const			{ return !IsUndefined();			}
	inline bool IsSymbol() const			{ return IsType(VTYPE_symbol);		}
	inline bool IsBoolean() const			{ return IsType(VTYPE_boolean);		}
	inline bool IsNumber() const			{ return IsType(VTYPE_number);		}
	inline bool IsComplex() const			{ return IsType(VTYPE_complex);		}
	inline bool IsModule() const			{ return IsType(VTYPE_Module);		}
	inline bool IsClass() const				{ return IsType(VTYPE_Class);		}
	inline bool IsGenericObject() const		{ return IsType(VTYPE_object);		}
	inline bool IsFunction() const			{ return IsType(VTYPE_function);	}
	inline bool IsString() const			{ return IsType(VTYPE_string);		}
	inline bool IsBinary() const			{ return IsType(VTYPE_binary);		}
	inline bool IsBinaryPtr() const			{ return IsType(VTYPE_binaryptr);	}
	inline bool IsList() const				{ return IsType(VTYPE_list);		}
	inline bool IsMatrix() const			{ return IsType(VTYPE_matrix);		}
	inline bool IsDict() const				{ return IsType(VTYPE_dict);		}
	inline bool IsStream() const			{ return IsType(VTYPE_stream);		}
	inline bool IsDateTime() const			{ return IsType(VTYPE_datetime);	}
	inline bool IsTimeDelta() const			{ return IsType(VTYPE_timedelta);	}
	inline bool IsIterator() const			{ return IsType(VTYPE_iterator);	}
	inline bool IsExpr() const				{ return IsType(VTYPE_expr);		}
	inline bool IsEnvironment() const		{ return IsType(VTYPE_environment);	}
	inline bool IsError() const				{ return IsType(VTYPE_error);		}
	inline bool IsURI() const				{ return IsType(VTYPE_uri);			}
	inline bool IsSemaphore() const			{ return IsType(VTYPE_semaphore);	}
	inline bool IsStruct() const			{ return IsType(VTYPE_Struct);		}
	inline bool IsImage() const				{ return IsType(VTYPE_image);		}
	inline bool IsColor() const				{ return IsType(VTYPE_color);		}
	inline bool IsPalette() const			{ return IsType(VTYPE_palette);		}
	inline bool IsAudio() const				{ return IsType(VTYPE_audio);		}
	inline bool IsCodec() const				{ return IsType(VTYPE_codec);		}
	inline bool IsArgs() const				{ return IsType(VTYPE_args);		}
	inline bool IsListOrIterator() const	{ return IsList() || IsIterator();	}
	inline bool IsNumberOrComplex() const	{ return IsNumber() || IsComplex();	}
	bool MustBe(Signal &sig, bool flag, const char *expected) const;
	inline bool MustBeInvalid(Signal &sig) const	{ return MustBe(sig, IsInvalid(),	"invalid");		}
	inline bool MustBeUndefined(Signal &sig) const	{ return MustBe(sig, IsUndefined(),	"undefined");	}
	inline bool MustBeValid(Signal &sig) const		{ return MustBe(sig, IsValid(),		"valid");		}
	inline bool MustBeDefined(Signal &sig) const	{ return MustBe(sig, IsDefined(),	"defined");		}
	inline bool MustBeSymbol(Signal &sig) const		{ return MustBe(sig, IsSymbol(),	"symbol");		}
	inline bool MustBeBoolean(Signal &sig) const	{ return MustBe(sig, IsBoolean(), 	"boolean");		}
	inline bool MustBeNumber(Signal &sig) const		{ return MustBe(sig, IsNumber(), 	"number");		}
	inline bool MustBeComplex(Signal &sig) const	{ return MustBe(sig, IsComplex(), 	"complex");		}
	inline bool MustBeModule(Signal &sig) const		{ return MustBe(sig, IsModule(), 	"module");		}
	inline bool MustBeClass(Signal &sig) const		{ return MustBe(sig, IsClass(), 	"class");		}
	inline bool MustBeGenericObject(Signal &sig) const { return MustBe(sig, IsGenericObject(), 	"generic object");		}
	inline bool MustBeFunction(Signal &sig) const	{ return MustBe(sig, IsFunction(), 	"function");	}
	inline bool MustBeString(Signal &sig) const		{ return MustBe(sig, IsString(), 	"string");		}
	inline bool MustBeBinary(Signal &sig) const		{ return MustBe(sig, IsBinary(), 	"binary");		}
	inline bool MustBeBinaryPtr(Signal &sig) const	{ return MustBe(sig, IsBinaryPtr(), "binaryptr");	}
	inline bool MustBeList(Signal &sig) const		{ return MustBe(sig, IsList(), 		"list");		}
	inline bool MustBeMatrix(Signal &sig) const		{ return MustBe(sig, IsMatrix(), 	"matrix");		}
	inline bool MustBeDict(Signal &sig) const		{ return MustBe(sig, IsDict(), 		"dict");		}
	inline bool MustBeStream(Signal &sig) const		{ return MustBe(sig, IsStream(), 	"stream");		}
	inline bool MustBeDateTime(Signal &sig) const	{ return MustBe(sig, IsDateTime(), 	"datetime");	}
	inline bool MustBeTimeDelta(Signal &sig) const	{ return MustBe(sig, IsTimeDelta(), "timedelta");	}
	inline bool MustBeIterator(Signal &sig) const	{ return MustBe(sig, IsIterator(), 	"iterator");	}
	inline bool MustBeExpr(Signal &sig) const		{ return MustBe(sig, IsExpr(), 		"expr");		}
	inline bool MustBeEnvironment(Signal &sig) const{ return MustBe(sig, IsEnvironment(),"environment");}
	inline bool MustBeError(Signal &sig) const		{ return MustBe(sig, IsError(), 	"error");		}
	inline bool MustBeURI(Signal &sig) const		{ return MustBe(sig, IsURI(), 		"uri");			}
	inline bool MustBeSemaphore(Signal &sig) const	{ return MustBe(sig, IsSemaphore(), "semaphore");	}
	inline bool MustBeStruct(Signal &sig) const		{ return MustBe(sig, IsStruct(), 	"struct");		}
	inline bool MustBeImage(Signal &sig) const		{ return MustBe(sig, IsImage(), 	"image");		}
	inline bool MustBeColor(Signal &sig) const		{ return MustBe(sig, IsColor(), 	"color");		}
	inline bool MustBePalette(Signal &sig) const	{ return MustBe(sig, IsPalette(), 	"palette");		}
	inline bool MustBeAudio(Signal &sig) const		{ return MustBe(sig, IsAudio(), 	"audio");		}
	inline bool MustBeCodec(Signal &sig) const		{ return MustBe(sig, IsCodec(), 	"codec");		}
	inline bool MustBeArgs(Signal &sig) const		{ return MustBe(sig, IsArgs(), 		"args");		}
	inline void SetSymbol(const Symbol *pSymbol) {
		FreeResource(); _valType = VTYPE_symbol, _u.pSymbol = pSymbol;
	}
	inline void SetBoolean(bool flag) {
		FreeResource(); _valType = VTYPE_boolean, _u.flag = flag;
	}
	inline void SetNumber(Number num) {
		FreeResource(); _valType = VTYPE_number, _u.num = num;
	}
	inline void SetComplex(const Complex &comp) {
		FreeResource();
		if (comp.imag() == 0.) {
			 _valType = VTYPE_number, _u.num = comp.real();
		} else {
			 _valType = VTYPE_complex, _u.pComp = new Complex(comp);
		}
	}
	inline Number GetNumber() const {
		return IsNumber()? _u.num :
				IsBoolean()? (_u.flag? 1. : 0.) :
				IsString()? ::strtod(GetString(), NULL) : 0.;
	}
	// VTYPE_symbol
	inline const Symbol *GetSymbol() const {
		return IsSymbol()? _u.pSymbol : NULL;
	}
	// VTYPE_boolean
	inline bool GetBoolean() const {
		return IsBoolean()? _u.flag : IsValid();
	}
	// VTYPE_number
	inline int GetInt() const				{ return static_cast<int>(GetNumber());				}
	inline unsigned int GetUInt() const		{ return static_cast<unsigned int>(GetNumber());	}
	inline size_t GetSizeT() const			{ return static_cast<size_t>(GetNumber());			}
	inline char GetChar() const				{ return static_cast<char>(GetNumber());			}
	inline unsigned char GetUChar() const	{ return static_cast<unsigned char>(GetNumber());	}
	inline short GetShort() const			{ return static_cast<short>(GetNumber());			}
	inline unsigned short GetUShort() const	{ return static_cast<unsigned short>(GetNumber());	}
	inline long GetLong() const {
		Number num = GetNumber();
		return (num < 0x80000000)? static_cast<long>(num) :
						static_cast<long>(static_cast<unsigned long>(num));
	}
	inline unsigned long GetULong() const	{ return static_cast<unsigned long>(GetNumber());	}
	inline int64 GetInt64() const			{ return static_cast<int64>(GetNumber());			}
	inline uint64 GetUInt64() const			{ return static_cast<uint64>(GetNumber());			}
	inline float GetFloat() const			{ return static_cast<float>(GetNumber());			}
	inline double GetDouble() const			{ return static_cast<double>(GetNumber());			}
	// VTYPE_complex
	inline Complex GetComplex() const {
		return IsComplex()? *_u.pComp : IsNumber()? Complex(GetNumber()) : _compZero;
	}
	inline const Complex *GetComplexPtr() const {
		return _u.pComp;
	}
	// VTYPE_module
	inline Module *GetModule() { return IsModule()? _u.pModule : NULL; }
	inline const Module *GetModule() const { return IsModule()? _u.pModule : NULL; }
	// VTYPE_class
	inline Class *GetClass() { return IsClass()? _u.pClass : NULL; }
	inline const Class *GetClass() const { return IsClass()? _u.pClass : NULL; }
	// VTYPE_function
	Function *GetFunction();
	Object_function *GetFunctionObj();
	inline const Function *GetFunction() const {
		return const_cast<Value *>(this)->GetFunction();
	}
	inline const Object_function *GetFunctionObj() const {
		return const_cast<Value *>(this)->GetFunctionObj();
	}
	// VTYPE_string
	const char *GetString() const;
	String GetStringSTL() const;
	// VTYPE_binary
	const Binary &GetBinary() const;
	// VTYPE_binaryptr
	Object_binaryptr *GetBinaryPtr() const;
	// VTYPE_list
	ValueList &GetList();
	const ValueList &GetList() const;
	Object_list *GetListObj();
	Object_list *GetListObj() const;
	// VTYPE_matrix
	Object_matrix *GetMatrixObj();
	Object_matrix *GetMatrixObj() const;
	// VTYPE_dict
	ValueDict &GetDict();
	const ValueDict &GetDict() const;
	Object_dict *GetDictObj();
	Object_dict *GetDictObj() const;
	// VTYPE_stream
	Stream &GetStream() const;
	Object_stream *GetStreamObj() const;
	// VTYPE_datetime
	const DateTime &GetDateTime() const;
	// VTYPE_timedelta
	const TimeDelta &GetTimeDelta() const;
	// VTYPE_iterator
	Iterator *GetIterator() const;
	// VTYPE_expr
	const Expr *GetExpr() const;
	// VTYPE_image
	Object_image *GetImageObj();
	Object_image *GetImageObj() const;
	// VTYPE_color
	Object_color *GetColorObj();
	Object_color *GetColorObj() const;
	// VTYPE_palette
	Object_palette *GetPaletteObj();
	Object_palette *GetPaletteObj() const;
	//-----------------------
	bool DirProp(Environment &env, Signal sig, SymbolSet &symbols, bool escalateFlag);
	void DirValueType(SymbolSet &symbols, bool escalateFlag);
	ErrorType GetErrorType() const;
	bool IsFlatList() const;
	bool IsInstanceOf(ValueType valType) const;
	ObjectBase *ExtractObject(Signal sig);
	inline ObjectBase *ExtractObject(Signal sig) const {
		return const_cast<Value *>(this)->ExtractObject(sig);
	}
	Expr *CloneExpr() const;
	inline Object *GetObj() { return IsObject()? _u.pObj : NULL; }
	inline Object *GetObj() const { return IsObject()? _u.pObj : NULL; }
	inline Object *GetObject() { return IsObject()? _u.pObj : NULL; }
	inline Object *GetObject() const { return IsObject()? _u.pObj : NULL; }
	ObjectBase *GetObjectBase();
	Iterator *CreateIterator(Signal sig) const;
	String ToString(Signal sig, bool exprFlag = true) const;
	Number ToNumber(bool allowPartFlag, bool &successFlag) const;
	void Accept(Signal sig, ValueVisitor &visitor) const;
	void InitAsModule(Module *pModule);
	void InitAsClass(Class *pClass);
	void InitAsObject(Object *pObj);
	ValueList &InitAsList(Environment &env);
	ValueList &InitAsList(Environment &env, size_t n);
	ValueList &InitAsList(Environment &env, size_t n, const Value &value);
	Object_matrix *InitAsMatrix(Environment &env,
								int nRows, int nCols, const Value &valueElem);
	Object_matrix *InitAsMatrix(Environment &env, Signal sig, const ValueList &valList);
	ValueDict &InitAsDict(Environment &env, bool ignoreCaseFlag);
	Object_binary *InitAsBinary(Environment &env);
	Object_binary *InitAsBinary(Environment &env, const Binary &binary, bool writableFlag);
	Object_binary *InitAsBinary(Environment &env,
								const char *buff, size_t size, bool writableFlag);
	Object_binaryptr *InitAsBinaryPtr(Environment &env,
							Object_binary *pObjBinary, size_t offset);
	void InitAsExpr(Environment &env, Expr *pExpr);
	void InitAsIterator(Environment &env, Iterator *pIterator);
	void InitAsEnvironment(Environment &env);
public:
	static int Compare(const Value &value1, const Value &value2, bool ignoreCaseFlag = false);
	inline bool operator<(const Value &value) const {
		return Compare(*this, value) < 0;
	}
	static Value CreateAsList(Environment &env, const Value &v1);
	static Value CreateAsList(Environment &env, const Value &v1, const Value &v2);
	static Value CreateAsList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3);
	static Value CreateAsList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4);
	static Value CreateAsList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4, const Value &v5);
	static Value CreateAsList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4, const Value &v5, const Value &v6);
	static bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value);
	static bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value, bool mustBeValidFlag);
private:
	void FreeResource();
};

//-----------------------------------------------------------------------------
// ValueList
//-----------------------------------------------------------------------------
class DLLDECLARE ValueList : public std::vector<Value> {
public:
	static const ValueList Null;
public:
	inline ValueList() {}
	inline ValueList(size_t n) : std::vector<Value>(n) {}
	inline ValueList(size_t n, const Value &value) : std::vector<Value>(n, value) {}
	inline ValueList(const Value &value) {
		reserve(1);
		push_back(value);
	}
	inline ValueList(const Value &value1, const Value &value2) {
		reserve(2);
		push_back(value1), push_back(value2);
	}
	inline ValueList(const Value &value1, const Value &value2, const Value &value3) {
		reserve(3);
		push_back(value1), push_back(value2), push_back(value3);
	}
	ValueList(const ValueList &valList);
	bool IsFlat() const;
	bool IsContain(const Value &value) const;
	bool IsContainIterator() const;
	bool CheckMatrix(size_t *pnRow, size_t *pnCol) const;
	void ExtractFlat(ValueList &valList) const;
	void Accept(Signal sig, ValueVisitor &visitor) const;
	void Append(const ValueList &valList);
	void Print(Signal sig, int indentLevel = 0) const;
	bool ToStringList(Signal sig, StringList &strList) const;
	static bool AssumeSameLength(Signal sig,
					const ValueList &valList1, const ValueList &valList2);
	bool Serialize(Environment &env, Signal sig, Stream &stream) const;
	bool Deserialize(Environment &env, Signal sig, Stream &stream);
};

//-----------------------------------------------------------------------------
// ValuePtrList
//-----------------------------------------------------------------------------
typedef std::vector<const Value *> ValuePtrList;

//-----------------------------------------------------------------------------
// ValueMap
//-----------------------------------------------------------------------------
class DLLDECLARE ValueMap : public std::map<const Symbol *, Value, Symbol::KeyCompare_UniqNumber> {
public:
	static const ValueMap Null;
public:
	inline ValueMap() {}
	inline bool IsSet(const Symbol *pSymbol) const {
		return find(pSymbol) != const_cast<ValueMap *>(this)->end();
	}
	inline void Insert(const Symbol *pSymbol) {
		insert(value_type(pSymbol, Value::Null));
	}
	inline void Insert(const Symbol *pSymbol, const Value &value) {
		insert(value_type(pSymbol, value));
	}
};

//-----------------------------------------------------------------------------
// ValueDeque
//-----------------------------------------------------------------------------
typedef std::deque<Value> ValueDeque;

//-----------------------------------------------------------------------------
// ValueDict
//-----------------------------------------------------------------------------
class DLLDECLARE ValueDict : public std::map<Value, Value, Value::KeyCompare> {
public:
	enum StoreMode {
		STORE_Normal,
		STORE_AllowDup,
		STORE_Default,
	};
	static const ValueDict Null;
public:
	inline ValueDict() : std::map<Value, Value, Value::KeyCompare>() {}
	inline ValueDict(const Value::KeyCompare &comp) :
							std::map<Value, Value, Value::KeyCompare>(comp) {}
	bool Store(Signal sig, const ValueList &valList, StoreMode storeMode);
	bool Store(Signal sig, const ValueDict &valDict, StoreMode storeMode);
	bool Store(Signal sig, const Value &valueIdx, const Value &value, StoreMode storeMode);
	inline static bool IsValidKey(const Value &value) {
		return value.IsNumber() || value.IsString() || value.IsSymbol();
	}
	bool Serialize(Environment &env, Signal sig, Stream &stream) const;
	bool Deserialize(Environment &env, Signal sig, Stream &stream);
};

inline const char *GetNumberFormat() { return "%g"; }

}

#endif
