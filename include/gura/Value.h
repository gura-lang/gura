#ifndef __GURA_VALUE_H__
#define __GURA_VALUE_H__

#include "Common.h"
#include "Symbol.h"
#include "Stream.h"
#include "DateTime.h"

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------

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

namespace Gura {

class Expr;
class Binary;
class Fundamental;
class Environment;
class Module;
class Function;
class Directory;
class Class;
class Sequence;
class Object;
class ValueList;
class ValueDict;
class ValueVisitor;
class Iterator;

enum {
	VFLAG_None			= 0,
	VFLAG_NoOwner		= (0 << 0),
	VFLAG_Owner			= (1 << 0),
	VFLAG_TinyBuff		= (1 << 1),
	VFLAG_Privileged	= (1 << 2),
	VFLAG_NoMap			= (1 << 3),
	// b15-b8 are reserved for super-skip count
};

//-----------------------------------------------------------------------------
// ValueType
//-----------------------------------------------------------------------------
typedef UShort ValueType;

// nil / undefined
GURA_DLLDECLARE extern ValueType VTYPE_nil;
GURA_DLLDECLARE extern ValueType VTYPE_undefined;
// primitive types
GURA_DLLDECLARE extern ValueType VTYPE_symbol;
GURA_DLLDECLARE extern ValueType VTYPE_boolean;
GURA_DLLDECLARE extern ValueType VTYPE_number;
GURA_DLLDECLARE extern ValueType VTYPE_complex;
GURA_DLLDECLARE extern ValueType VTYPE_fraction;
GURA_DLLDECLARE extern ValueType VTYPE_string;
// declaration
GURA_DLLDECLARE extern ValueType VTYPE_quote;
GURA_DLLDECLARE extern ValueType VTYPE_any;
// container types
GURA_DLLDECLARE extern ValueType VTYPE_Module;
GURA_DLLDECLARE extern ValueType VTYPE_Class;
// sequence
GURA_DLLDECLARE extern ValueType VTYPE_Sequence;
// object types
GURA_DLLDECLARE extern ValueType VTYPE_object;
GURA_DLLDECLARE extern ValueType VTYPE_Struct;
GURA_DLLDECLARE extern ValueType VTYPE_args;
GURA_DLLDECLARE extern ValueType VTYPE_audio;
GURA_DLLDECLARE extern ValueType VTYPE_binary;
GURA_DLLDECLARE extern ValueType VTYPE_codec;
GURA_DLLDECLARE extern ValueType VTYPE_color;
GURA_DLLDECLARE extern ValueType VTYPE_datetime;
GURA_DLLDECLARE extern ValueType VTYPE_declaration;
GURA_DLLDECLARE extern ValueType VTYPE_dict;
GURA_DLLDECLARE extern ValueType VTYPE_directory;
GURA_DLLDECLARE extern ValueType VTYPE_environment;
GURA_DLLDECLARE extern ValueType VTYPE_error;
GURA_DLLDECLARE extern ValueType VTYPE_expr;
GURA_DLLDECLARE extern ValueType VTYPE_function;
GURA_DLLDECLARE extern ValueType VTYPE_help;
GURA_DLLDECLARE extern ValueType VTYPE_image;
GURA_DLLDECLARE extern ValueType VTYPE_iterator;
GURA_DLLDECLARE extern ValueType VTYPE_list;
GURA_DLLDECLARE extern ValueType VTYPE_matrix;
GURA_DLLDECLARE extern ValueType VTYPE_operator;
GURA_DLLDECLARE extern ValueType VTYPE_palette;
GURA_DLLDECLARE extern ValueType VTYPE_pointer;
GURA_DLLDECLARE extern ValueType VTYPE_semaphore;
GURA_DLLDECLARE extern ValueType VTYPE_stream;
GURA_DLLDECLARE extern ValueType VTYPE_timedelta;
GURA_DLLDECLARE extern ValueType VTYPE_uri;

//-----------------------------------------------------------------------------
// ValueTypeInfo
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ValueTypeInfo {
private:
	ValueType _valType;
	const Symbol *_pSymbol;
	Class *_pClass;
	const Module *_pModule;
public:
	inline ValueTypeInfo(ValueType valType, const Symbol *pSymbol, Class *pClass) :
			_valType(valType), _pSymbol(pSymbol), _pClass(pClass), _pModule(NULL) {}
	~ValueTypeInfo();
	inline static void Delete(ValueTypeInfo *pValTypeInfo) { delete pValTypeInfo; }
	inline void SetModule(const Module *pModule) { _pModule = pModule; }
	inline const Module *GetModule() const { return _pModule; }
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline ValueType GetValueType() const { return _valType; }
	inline Class *GetClass() const { return _pClass; }
	void SetClass(Class *pClass);
	String MakeFullName() const;
	Expr *MakeExpr() const;
};

//-----------------------------------------------------------------------------
// ValueTypeMap
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ValueTypeMap : public std::map<const Symbol *,
							ValueTypeInfo *, Symbol::KeyCompare_UniqNumber> {
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
class GURA_DLLDECLARE ValueTypePool {
public:
	// primitive types
	Gura_DeclareVTYPE(nil);
	Gura_DeclareVTYPE(undefined);
	Gura_DeclareVTYPE(symbol);
	Gura_DeclareVTYPE(boolean);
	Gura_DeclareVTYPE(number);
	Gura_DeclareVTYPE(complex);
	Gura_DeclareVTYPE(fraction);
	Gura_DeclareVTYPE(string);
	// for declaration
	Gura_DeclareVTYPE(quote);
	Gura_DeclareVTYPE(any);
	// container types
	Gura_DeclareVTYPE(Module);
	Gura_DeclareVTYPE(Class);
	// sequence
	Gura_DeclareVTYPE(Sequence);
	// object types
	Gura_DeclareVTYPE(object);
	Gura_DeclareVTYPE(Struct);
	Gura_DeclareVTYPE(args);
	Gura_DeclareVTYPE(audio);
	Gura_DeclareVTYPE(binary);
	Gura_DeclareVTYPE(codec);
	Gura_DeclareVTYPE(color);
	Gura_DeclareVTYPE(datetime);
	Gura_DeclareVTYPE(declaration);
	Gura_DeclareVTYPE(dict);
	Gura_DeclareVTYPE(directory);
	Gura_DeclareVTYPE(environment);
	Gura_DeclareVTYPE(error);
	Gura_DeclareVTYPE(expr);
	Gura_DeclareVTYPE(function);
	Gura_DeclareVTYPE(help);
	Gura_DeclareVTYPE(image);
	Gura_DeclareVTYPE(iterator);
	Gura_DeclareVTYPE(list);
	Gura_DeclareVTYPE(matrix);
	Gura_DeclareVTYPE(operator);
	Gura_DeclareVTYPE(palette);
	Gura_DeclareVTYPE(pointer);
	Gura_DeclareVTYPE(semaphore);
	Gura_DeclareVTYPE(stream);
	Gura_DeclareVTYPE(timedelta);
	Gura_DeclareVTYPE(uri);
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
	static void DoPrepareClass(Environment &env);
	ValueTypeInfo *Add(const Symbol *pSymbol);
	ValueTypeInfo *Lookup(ValueType valType);
	ValueTypeInfo *LookupWithCheck(ValueType valType);
private:
	void _Initialize(Environment &env);
private:
	inline ValueTypePool(const ValueTypePool &valTypeInfoPool) {}
	inline void operator=(const ValueTypePool &valTypeInfoPool) {}
};

//-----------------------------------------------------------------------------
// Value
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Value {
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
private:
	UShort _valType;			// 2 bytes
	UShort _valFlags;			// 2 bytes
	union {						// 8 bytes
		Number num;				// VTYPE_number
		bool flag;				// VTYPE_boolean
		const Symbol *pSymbol;	// VTYPE_symbol
		Complex *pComp;			// VTYPE_complex
		Fraction *pFrac;		// VTYPE_fraction
		String *pStr;			// VTYPE_string
		Module *pModule;		// VTYPE_module
		Class *pClass;			// VTYPE_class
		Sequence *pSequence;	// VTYPE_Sequence
		Object *pObj;			// objects
		char tinyBuff[1];
	} _u;
public:
	static const Value Null;
	static const Value Undefined;
	static const Value Zero;
	static const Value One;
	static const Value True;
	static const Value False;
	static const KeyCompare KeyCompareCase;
	static const KeyCompare KeyCompareIgnoreCase;
public:
	Value(const Value &value);
	~Value();
	// VTYPE_nil
	inline Value() : _valType(VTYPE_nil), _valFlags(VFLAG_Owner) {}
	inline Value(ValueType valType, UShort valFlags) : _valType(valType), _valFlags(valFlags) {}
	// VTYPE_Module
	inline Value(Module *pModule, UShort valFlags = VFLAG_Owner) :
								_valType(VTYPE_Module), _valFlags(valFlags) {
		_u.pModule = pModule;
	}
	// VTYPE_Class
	inline Value(Class *pClass, UShort valFlags = VFLAG_Owner) :
								_valType(VTYPE_Class), _valFlags(valFlags) {
		_u.pClass = pClass;
	}
	// VTYPE_Sequence
	inline Value(Sequence *pSequence, UShort valFlags = VFLAG_Owner) :
								_valType(VTYPE_Sequence), _valFlags(valFlags) {
		_u.pSequence = pSequence;
	}
	// VTYPE_object etc
	Value(Object *pObj, UShort valFlags = VFLAG_Owner);
	// VTYPE_number
	inline Value(Number num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = num;
	}
	inline Value(int num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(UInt num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(char num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(UChar num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(short num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(UShort num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(long num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(ULong num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(Int64 num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	inline Value(UInt64 num) : _valType(VTYPE_number), _valFlags(VFLAG_Owner) {
		_u.num = static_cast<Number>(num);
	}
	// VTYPE_boolean
	inline Value(bool flag) : _valType(VTYPE_boolean), _valFlags(VFLAG_Owner) {
		_u.flag = flag;
	}
	// VTYPE_symbol
	inline Value(const Symbol *pSymbol) : _valType(VTYPE_symbol), _valFlags(VFLAG_Owner) {
		_u.pSymbol = pSymbol;
	}
	// VTYPE_complex
	inline Value(const Complex &comp) : _valType(VTYPE_complex), _valFlags(VFLAG_Owner) {
		_u.pComp = new Complex(comp);
	}
	// VTYPE_fraction
	inline Value(const Fraction &frac) : _valType(VTYPE_fraction), _valFlags(VFLAG_Owner) {
		_u.pFrac = new Fraction(frac);
	}
	// VTYPE_string
	Value(Environment &env, const String &str);
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
	inline UShort GetFlags() const { return _valFlags; }
	inline void SetFlags(UShort valFlags) { _valFlags = valFlags; }
	inline void AddFlags(UShort valFlags) { _valFlags |= valFlags; }
	inline bool IsOwner() const { return (_valFlags & VFLAG_Owner)? true : false; }
	inline bool IsPrivileged() const { return (_valFlags & VFLAG_Privileged)? true : false; }
	inline bool GetTinyBuffFlag() const { return (_valFlags & VFLAG_TinyBuff)? true : false; }
	inline bool GetNoMapFlag() const { return (_valFlags & VFLAG_NoMap)? true : false; }
	inline int GetSuperSkipCount() const { return (_valFlags >> 8) & 0xff; }
	inline void SetSuperSkipCount(int cntSuperSkip) {
		_valFlags = (_valFlags & 0x00ff) | (static_cast<UShort>(cntSuperSkip & 0xff) << 8);
	}
	inline ValueType GetValueType() const { return _valType; }
	inline ValueTypeInfo *GetValueTypeInfo() const {
		return ValueTypePool::GetInstance()->Lookup(_valType);
	}
	inline String MakeValueTypeName() const {
		return ValueTypePool::GetInstance()->Lookup(_valType)->MakeFullName();
	}
	inline bool IsType(ValueType valType) const { return _valType == valType;	}
	inline bool IsObject() const			{ return _valType >= VTYPE_object && !GetTinyBuffFlag(); }
	inline bool IsPrimitive() const			{ return _valType <= VTYPE_string;	}
	inline bool IsInvalid() const			{ return IsType(VTYPE_nil) || IsType(VTYPE_undefined); }
	inline bool IsUndefined() const			{ return IsType(VTYPE_undefined);	}
	inline bool IsValid() const				{ return !IsInvalid();				}
	inline bool IsDefined() const			{ return !IsUndefined();			}
	// primitive types
	inline bool IsSymbol() const			{ return IsType(VTYPE_symbol);		}
	inline bool IsBoolean() const			{ return IsType(VTYPE_boolean);		}
	inline bool IsNumber() const			{ return IsType(VTYPE_number);		}
	inline bool IsComplex() const			{ return IsType(VTYPE_complex);		}
	inline bool IsFraction() const			{ return IsType(VTYPE_fraction);	}
	inline bool IsString() const			{ return IsType(VTYPE_string);		}
	inline bool IsNumberOrComplex() const	{ return IsNumber() || IsComplex();	}
	// container types
	inline bool IsModule() const			{ return IsType(VTYPE_Module);		}
	inline bool IsClass() const				{ return IsType(VTYPE_Class);		}
	// sequence
	inline bool IsSequence() const			{ return IsType(VTYPE_Sequence);	}
	// object types
	inline bool IsGenericObject() const		{ return IsType(VTYPE_object);		}
	inline bool IsStruct() const			{ return IsType(VTYPE_Struct);		}
	inline bool IsArgs() const				{ return IsType(VTYPE_args);		}
	inline bool IsAudio() const				{ return IsType(VTYPE_audio);		}
	inline bool IsBinary() const			{ return IsType(VTYPE_binary);		}
	inline bool IsCodec() const				{ return IsType(VTYPE_codec);		}
	inline bool IsColor() const				{ return IsType(VTYPE_color);		}
	inline bool IsDateTime() const			{ return IsType(VTYPE_datetime);	}
	inline bool IsDeclaration() const		{ return IsType(VTYPE_declaration);	}
	inline bool IsDict() const				{ return IsType(VTYPE_dict);		}
	inline bool IsDirectory() const			{ return IsType(VTYPE_directory);	}
	inline bool IsEnvironment() const		{ return IsType(VTYPE_environment);	}
	inline bool IsError() const				{ return IsType(VTYPE_error);		}
	inline bool IsExpr() const				{ return IsType(VTYPE_expr);		}
	inline bool IsFunction() const			{ return IsType(VTYPE_function);	}
	inline bool IsHelp() const				{ return IsType(VTYPE_help);		}
	inline bool IsImage() const				{ return IsType(VTYPE_image);		}
	inline bool IsIterator() const			{ return IsType(VTYPE_iterator);	}
	inline bool IsList() const				{ return IsType(VTYPE_list);		}
	inline bool IsMatrix() const			{ return IsType(VTYPE_matrix);		}
	inline bool IsOperator() const			{ return IsType(VTYPE_operator);	}
	inline bool IsPalette() const			{ return IsType(VTYPE_palette);		}
	inline bool IsPointer() const			{ return IsType(VTYPE_pointer);		}
	inline bool IsSemaphore() const			{ return IsType(VTYPE_semaphore);	}
	inline bool IsStream() const			{ return IsType(VTYPE_stream);		}
	inline bool IsTimeDelta() const			{ return IsType(VTYPE_timedelta);	}
	inline bool IsURI() const				{ return IsType(VTYPE_uri);			}
	inline bool IsListOrIterator() const	{ return IsList() || IsIterator();	}
	bool MustBe(Signal &sig, bool flag, const char *expected) const;
	inline bool MustBeInvalid(Signal &sig) const		{ return MustBe(sig, IsInvalid(),		"invalid");			}
	inline bool MustBeUndefined(Signal &sig) const		{ return MustBe(sig, IsUndefined(),		"undefined");		}
	inline bool MustBeValid(Signal &sig) const			{ return MustBe(sig, IsValid(),			"valid");			}
	inline bool MustBeDefined(Signal &sig) const		{ return MustBe(sig, IsDefined(),		"defined");			}
	// primitive types
	inline bool MustBeSymbol(Signal &sig) const			{ return MustBe(sig, IsSymbol(),		"symbol");			}
	inline bool MustBeBoolean(Signal &sig) const		{ return MustBe(sig, IsBoolean(), 		"boolean");			}
	inline bool MustBeNumber(Signal &sig) const			{ return MustBe(sig, IsNumber(), 		"number");			}
	inline bool MustBeComplex(Signal &sig) const		{ return MustBe(sig, IsComplex(), 		"complex");			}
	inline bool MustBeFraction(Signal &sig) const		{ return MustBe(sig, IsFraction(), 		"fraction");		}
	inline bool MustBeString(Signal &sig) const			{ return MustBe(sig, IsString(), 		"string");			}
	// container types
	inline bool MustBeModule(Signal &sig) const			{ return MustBe(sig, IsModule(), 		"module");			}
	inline bool MustBeClass(Signal &sig) const			{ return MustBe(sig, IsClass(), 		"class");			}
	// sequence
	inline bool MustBeSequence(Signal &sig) const		{ return MustBe(sig, IsSequence(), 		"sequence");		}
	// object types
	inline bool MustBeGenericObject(Signal &sig) const	{ return MustBe(sig, IsGenericObject(), "generic object");	}
	inline bool MustBeStruct(Signal &sig) const			{ return MustBe(sig, IsStruct(), 		"struct");			}
	inline bool MustBeArgs(Signal &sig) const			{ return MustBe(sig, IsArgs(), 			"args");			}
	inline bool MustBeAudio(Signal &sig) const			{ return MustBe(sig, IsAudio(), 		"audio");			}
	inline bool MustBeBinary(Signal &sig) const			{ return MustBe(sig, IsBinary(), 		"binary");			}
	inline bool MustBeCodec(Signal &sig) const			{ return MustBe(sig, IsCodec(), 		"codec");			}
	inline bool MustBeColor(Signal &sig) const			{ return MustBe(sig, IsColor(), 		"color");			}
	inline bool MustBeDateTime(Signal &sig) const		{ return MustBe(sig, IsDateTime(), 		"datetime");		}
	inline bool MustBeDeclaration(Signal &sig) const	{ return MustBe(sig, IsDeclaration(),	"declaration");		}
	inline bool MustBeDict(Signal &sig) const			{ return MustBe(sig, IsDict(), 			"dict");			}
	inline bool MustBeDirectory(Signal &sig) const		{ return MustBe(sig, IsDirectory(), 	"directory");		}
	inline bool MustBeEnvironment(Signal &sig) const	{ return MustBe(sig, IsEnvironment(),	"environment");		}
	inline bool MustBeError(Signal &sig) const			{ return MustBe(sig, IsError(), 		"error");			}
	inline bool MustBeExpr(Signal &sig) const			{ return MustBe(sig, IsExpr(), 			"expr");			}
	inline bool MustBeFunction(Signal &sig) const		{ return MustBe(sig, IsFunction(), 		"function");		}
	inline bool MustBeHelp(Signal &sig) const			{ return MustBe(sig, IsHelp(), 			"help");			}
	inline bool MustBeImage(Signal &sig) const			{ return MustBe(sig, IsImage(), 		"image");			}
	inline bool MustBeIterator(Signal &sig) const		{ return MustBe(sig, IsIterator(), 		"iterator");		}
	inline bool MustBeList(Signal &sig) const			{ return MustBe(sig, IsList(), 			"list");			}
	inline bool MustBeMatrix(Signal &sig) const			{ return MustBe(sig, IsMatrix(), 		"matrix");			}
	inline bool MustBeOperator(Signal &sig) const		{ return MustBe(sig, IsOperator(), 		"operator");		}
	inline bool MustBePalette(Signal &sig) const		{ return MustBe(sig, IsPalette(), 		"palette");			}
	inline bool MustBePointer(Signal &sig) const		{ return MustBe(sig, IsPointer(), 		"pointer");			}
	inline bool MustBeSemaphore(Signal &sig) const		{ return MustBe(sig, IsSemaphore(), 	"semaphore");		}
	inline bool MustBeStream(Signal &sig) const			{ return MustBe(sig, IsStream(), 		"stream");			}
	inline bool MustBeTimeDelta(Signal &sig) const		{ return MustBe(sig, IsTimeDelta(), 	"timedelta");		}
	inline bool MustBeURI(Signal &sig) const			{ return MustBe(sig, IsURI(), 			"uri");				}
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
	inline void SetFraction(const Fraction &frac) {
		FreeResource();
		_valType = VTYPE_fraction, _u.pFrac = new Fraction(frac);
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
	inline UInt GetUInt() const				{ return static_cast<UInt>(GetNumber());	}
	inline size_t GetSizeT() const			{ return static_cast<size_t>(GetNumber());			}
	inline char GetChar() const				{ return static_cast<char>(GetNumber());			}
	inline UChar GetUChar() const			{ return static_cast<UChar>(GetNumber());	}
	inline short GetShort() const			{ return static_cast<short>(GetNumber());			}
	inline UShort GetUShort() const			{ return static_cast<UShort>(GetNumber());	}
	inline long GetLong() const {
		Number num = GetNumber();
		return (num < 0x80000000)? static_cast<long>(num) :
						static_cast<long>(static_cast<ULong>(num));
	}
	inline ULong GetULong() const			{ return static_cast<ULong>(GetNumber());	}
	inline Int64 GetInt64() const			{ return static_cast<Int64>(GetNumber());			}
	inline UInt64 GetUInt64() const			{ return static_cast<UInt64>(GetNumber());			}
	inline float GetFloat() const			{ return static_cast<float>(GetNumber());			}
	inline double GetDouble() const			{ return static_cast<double>(GetNumber());			}
	// VTYPE_complex
	inline Complex GetComplex() const {
		return IsComplex()? *_u.pComp : IsNumber()? Complex(GetNumber()) : Complex::Zero;
	}
	inline const Complex *GetComplexPtr() const {
		return _u.pComp;
	}
	// VTYPE_fraction
	inline Fraction GetFraction() const {
		return IsFraction()? *_u.pFrac : Fraction::Zero;
	}
	inline const Fraction *GetFractionPtr() const {
		return _u.pFrac;
	}
	// VTYPE_Module
	inline Module *GetModule() { return IsModule()? _u.pModule : NULL; }
	inline const Module *GetModule() const { return IsModule()? _u.pModule : NULL; }
	// VTYPE_Class
	inline Class *GetClass() { return IsClass()? _u.pClass : NULL; }
	inline const Class *GetClass() const { return IsClass()? _u.pClass : NULL; }
	// VTYPE_Sequence
	inline Sequence *GetSequence() { return IsSequence()? _u.pSequence : NULL; }
	inline const Sequence *GetSequence() const { return IsSequence()? _u.pSequence : NULL; }
	// VTYPE_function
	Function *GetFunction();
	inline const Function *GetFunction() const {
		return const_cast<Value *>(this)->GetFunction();
	}
	// VTYPE_string
	const char *GetString() const;
	String GetStringSTL() const;
	// VTYPE_binary
	const Binary &GetBinary() const;
	// VTYPE_list
	ValueList &GetList();
	const ValueList &GetList() const;
	// VTYPE_dict
	ValueDict &GetDict();
	const ValueDict &GetDict() const;
	// VTYPE_stream
	Stream &GetStream() const;
	// VTYPE_directory
	Directory *GetDirectory() const;
	// VTYPE_datetime
	const DateTime &GetDateTime() const;
	// VTYPE_timedelta
	const TimeDelta &GetTimeDelta() const;
	// VTYPE_iterator
	Iterator *GetIterator() const;
	// VTYPE_expr
	const Expr *GetExpr() const;
	//-----------------------
	Value EmptyIndexGet(Environment &env, Signal sig) const;
	void EmptyIndexSet(Environment &env, Signal sig, const Value &value);
	Value IndexGet(Environment &env, Signal sig, const Value &valueIdx) const;
	void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value);
	bool DirProp(Environment &env, Signal sig, SymbolSet &symbols, bool escalateFlag);
	void DirValueType(SymbolSet &symbols, bool escalateFlag);
	ErrorType GetErrorType() const;
	bool IsFlatList() const;
	bool IsInstanceOf(ValueType valType) const;
	Fundamental *ExtractFundamental(Signal sig);
	inline Fundamental *ExtractFundamental(Signal sig) const {
		return const_cast<Value *>(this)->ExtractFundamental(sig);
	}
	Expr *CloneExpr() const;
	inline Object *GetObject() { return IsObject()? _u.pObj : NULL; }
	inline Object *GetObject() const { return IsObject()? _u.pObj : NULL; }
	Fundamental *GetFundamental();
	const Fundamental *GetFundamental() const {
		return const_cast<Value *>(this)->GetFundamental();
	}
	Iterator *CreateIterator(Signal sig) const;
	String ToString(Signal sig, bool exprFlag = true) const;
	Number ToNumber(bool allowPartFlag, bool &successFlag) const;
	bool Accept(ValueVisitor &visitor) const;
	void InitAsModule(Module *pModule);
	void InitAsClass(Class *pClass);
	void InitAsObject(Object *pObj);
	ValueList &InitAsList(Environment &env);
	ValueList &InitAsList(Environment &env, size_t n);
	ValueList &InitAsList(Environment &env, const ValueList &valList);
	ValueList &InitAsList(Environment &env, size_t n, const Value &value);
	ValueDict &InitAsDict(Environment &env, bool ignoreCaseFlag);
	bool CastType(Environment &env, Signal sig, ValueType valType, Value &valueCasted) const;
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
// ValueEx
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ValueEx : public Value {
private:
	ULong _extra;
public:
	inline ValueEx(ULong extra = 0) : _extra(extra) {}
	inline ValueEx(const Value &value, ULong extra = 0) :
						Value(value), _extra(extra) {}
	inline ValueEx(const ValueEx &valueEx) :
						Value(valueEx), _extra(valueEx._extra) {}
	inline ULong GetExtra() const { return _extra; }
	inline ValueEx &operator=(const ValueEx &valueEx) {
		Value::operator=(valueEx);
		_extra = valueEx._extra;
		return *this;
	}
};

//-----------------------------------------------------------------------------
// ValueList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ValueList : public std::vector<Value> {
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
	bool Accept(ValueVisitor &visitor) const;
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
class GURA_DLLDECLARE ValueMap : public std::map<const Symbol *, ValueEx, Symbol::KeyCompare_UniqNumber> {
public:
	static const ValueMap Null;
public:
	inline ValueMap() {}
	inline bool IsSet(const Symbol *pSymbol) const {
		return find(pSymbol) != const_cast<ValueMap *>(this)->end();
	}
};

//-----------------------------------------------------------------------------
// ValueDeque
//-----------------------------------------------------------------------------
typedef std::deque<Value> ValueDeque;

//-----------------------------------------------------------------------------
// ValueDict
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ValueDict : public std::map<Value, Value, Value::KeyCompare> {
public:
	enum StoreMode {
		STORE_Normal,
		STORE_AllowDup,
		STORE_Default,
	};
	static const ValueDict Null;
private:
	int _cntRef;
	bool _ignoreCaseFlag;
public:
	Gura_DeclareReferenceAccessor(ValueDict);
public:
	inline ValueDict() : std::map<Value, Value, Value::KeyCompare>(),
								_cntRef(1), _ignoreCaseFlag(false) {}
	inline ValueDict(bool ignoreCaseFlag) :
		std::map<Value, Value, Value::KeyCompare>(ignoreCaseFlag? Value::KeyCompareIgnoreCase : Value::KeyCompareCase),
		_cntRef(1), _ignoreCaseFlag(ignoreCaseFlag) {}
	inline ValueDict(const ValueDict &valDict) :
		std::map<Value, Value, Value::KeyCompare>(valDict),
		_cntRef(1), _ignoreCaseFlag(valDict._ignoreCaseFlag) {}
private:
	inline ~ValueDict() {}
public:
	void Store(Environment &env, const String &strIndex, const String &strValue);
	bool Store(Signal sig, const ValueList &valList, StoreMode storeMode);
	bool Store(Signal sig, const ValueDict &valDict, StoreMode storeMode);
	bool Store(Signal sig, const Value &valueIdx, const Value &value, StoreMode storeMode);
	inline static bool IsValidKey(const Value &value) {
		return value.IsNumber() || value.IsString() || value.IsSymbol();
	}
	inline bool GetIgnoreCaseFlag() const { return _ignoreCaseFlag; }
	bool Serialize(Environment &env, Signal sig, Stream &stream) const;
	bool Deserialize(Environment &env, Signal sig, Stream &stream);
};

//-----------------------------------------------------------------------------
// ValueVisitor
//-----------------------------------------------------------------------------
class ValueVisitor {
public:
	virtual bool Visit(const Value &value) = 0;
};

//-----------------------------------------------------------------------------
// ValueVisitor_Flatten
//-----------------------------------------------------------------------------
class ValueVisitor_Flatten : public ValueVisitor {
private:
	ValueList &_valList;
public:
	inline ValueVisitor_Flatten(ValueList &valList) : _valList(valList) {}
	virtual bool Visit(const Value &value);
};

inline const char *GetNumberFormat() { return "%g"; }

}

#endif
