//=============================================================================
// Value
//=============================================================================
#ifndef __GURA_VALUE_H__
#define __GURA_VALUE_H__

#include "Common.h"
#include "Symbol.h"
#include "Stream.h"
#include "DateTime.h"
#include "ValueType.h"
#include "Complex.h"
#include "Rational.h"
#include "Callable.h"

namespace Gura {

class Expr;
class Binary;
class Directory;
class Function;
class Iterator;
class Environment;
class Fundamental;
class Module;
class Class;
class Object;
class ValueList;
class ValueDict;
class ValueVisitor;

//-----------------------------------------------------------------------------
// Value Flags
//-----------------------------------------------------------------------------
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
// Functions to manage Value resources
//-----------------------------------------------------------------------------
extern "C" void Gura_CopyValue(Value &valueDst, const Value &valueSrc);
extern "C" void Gura_ReleaseValue(Value &value);

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
		bool operator()(const Value &value1, const Value &value2) const;
	};
public:
	enum {
		MaxSuperSkipCount = 255,
	};
private:
	UShort _valType;				// 2 bytes
	UShort _valFlags;				// 2 bytes
	union {							// 8 bytes
		char tinyBuff[1];
		bool flag;					// boolean
		Complex *pComp;				// complex
		Number num;					// number
		Rational *pRatio;			// rational
		StringShared *pStrShrd;		// string
		const Symbol *pSymbol;		// symbol
		Fundamental *pFund;			// Module/Class/object
	} _u;
public:
	static const Value Nil;			// nil
	static const Value Undefined;	// undefined
	static const Value True;		// boolean
	static const Value False;		// boolean
	static const Value Zero;		// number
	static const Value One;			// number
	static const KeyCompare KeyCompareCase;
	static const KeyCompare KeyCompareIgnoreCase;
public:
	Value(const Value &value);
	~Value();
	// VTYPE_nil
	inline Value() : _valType(VTYPE_nil), _valFlags(VFLAG_Owner) {}
	inline Value(ValueType valType, UShort valFlags) : _valType(valType), _valFlags(valFlags) {}
	// VTYPE_Module
	Value(Module *pModule, UShort valFlags = VFLAG_Owner);
	// VTYPE_Class
	Value(Class *pClass, UShort valFlags = VFLAG_Owner);
	// VTYPE_object etc
	Value(Object *pObj, UShort valFlags = VFLAG_Owner);
	// VTYPE_boolean
	inline Value(bool flag) : _valType(VTYPE_boolean), _valFlags(VFLAG_Owner) {
		_u.flag = flag;
	}
	// VTYPE_complex
	inline Value(const Complex &comp) : _valType(VTYPE_complex), _valFlags(VFLAG_Owner) {
		_u.pComp = new Complex(comp);
	}
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
	// VTYPE_rational
	inline Value(const Rational &ratio) : _valType(VTYPE_rational), _valFlags(VFLAG_Owner) {
		_u.pRatio = new Rational(ratio);
	}
	// VTYPE_string
	Value(const String &str);
	Value(const char *str);
	Value(const char *str, size_t len);
	// VTYPE_symbol
	inline Value(const Symbol *pSymbol) : _valType(VTYPE_symbol), _valFlags(VFLAG_Owner) {
		_u.pSymbol = pSymbol;
	}
	Value &operator=(const Value &value);
	inline UShort GetFlags() const			{ return _valFlags;								}
	inline void SetFlags(UShort valFlags)	{ _valFlags = valFlags;							}
	inline void AddFlags(UShort valFlags)	{ _valFlags |= valFlags;						}
	inline bool IsOwner() const				{ return (_valFlags & VFLAG_Owner) != 0;		}
	inline bool IsPrivileged() const		{ return (_valFlags & VFLAG_Privileged) != 0;	}
	inline bool GetTinyBuffFlag() const		{ return (_valFlags & VFLAG_TinyBuff) != 0;		}
	inline bool GetNoMapFlag() const		{ return (_valFlags & VFLAG_NoMap) != 0;		}
	inline int GetSuperSkipCount() const	{ return (_valFlags >> 8) & 0xff;				}
	inline void SetSuperSkipCount(int cntSuperSkip) {
		_valFlags = (_valFlags & 0x00ff) | (static_cast<UShort>(cntSuperSkip & 0xff) << 8);
	}
	inline ValueType GetValueType() const	{ return _valType;								}
	inline ValueTypeInfo *GetValueTypeInfo() const {
		return ValueTypePool::GetInstance()->Lookup(_valType);
	}
	inline String MakeValueTypeName() const { return GetValueTypeInfo()->MakeFullName();	}
	inline Class *GetClass() const			{ return GetValueTypeInfo()->GetClass();		}
	inline bool IsType(ValueType valType) const
											{ return _valType == valType;					}
	inline bool IsInvalid() const			{ return _valType <= VTYPE_undefined;			}
	inline bool IsValid() const				{ return _valType > VTYPE_undefined;			}
	inline bool IsPrimitive() const			{ return _valType <= VTYPE_symbol;				}
	inline bool IsFundamental() const		{ return _valType >= VTYPE_Module;				}
	inline bool IsObject() const			{ return _valType >= VTYPE_object;				}
	// invalid types
	inline bool IsNil() const				{ return IsType(VTYPE_nil);						}
	inline bool IsUndefined() const			{ return IsType(VTYPE_undefined);				}
	inline bool IsDefined() const			{ return !IsUndefined();						}
	// primitive types
	inline bool Is_boolean() const			{ return IsType(VTYPE_boolean);					}
	inline bool Is_complex() const			{ return IsType(VTYPE_complex);					}
	inline bool Is_number() const			{ return IsType(VTYPE_number);					}
	inline bool Is_rational() const			{ return IsType(VTYPE_rational);				}
	inline bool Is_string() const			{ return IsType(VTYPE_string);					}
	inline bool Is_symbol() const			{ return IsType(VTYPE_symbol);					}
	inline bool IsNumberOrComplex() const	{ return Is_number() || Is_complex();			}
	// container types
	inline bool IsModule() const			{ return IsType(VTYPE_Module);					}
	inline bool IsClass() const				{ return IsType(VTYPE_Class);					}
	// object types
	inline bool IsGenericObject() const		{ return IsType(VTYPE_object);					}
	inline bool IsStruct() const			{ return IsType(VTYPE_Struct);					}
	inline bool Is_argument() const			{ return IsType(VTYPE_argument);				}
	inline bool Is_audio() const			{ return IsType(VTYPE_audio);					}
	inline bool Is_binary() const			{ return IsType(VTYPE_binary);					}
	inline bool Is_codec() const			{ return IsType(VTYPE_codec);					}
	inline bool Is_color() const			{ return IsType(VTYPE_color);					}
	inline bool Is_datetime() const			{ return IsType(VTYPE_datetime);				}
	inline bool Is_declaration() const		{ return IsType(VTYPE_declaration);				}
	inline bool Is_dict() const				{ return IsType(VTYPE_dict);					}
	inline bool Is_directory() const		{ return IsType(VTYPE_directory);				}
	inline bool Is_environment() const		{ return IsType(VTYPE_environment);				}
	inline bool Is_error() const			{ return IsType(VTYPE_error);					}
	inline bool Is_expr() const				{ return IsType(VTYPE_expr);					}
	inline bool Is_formatter() const		{ return IsType(VTYPE_formatter);				}
	inline bool Is_function() const			{ return IsType(VTYPE_function);				}
	inline bool Is_help() const				{ return IsType(VTYPE_help);					}
	inline bool Is_image() const			{ return IsType(VTYPE_image);					}
	inline bool Is_iterator() const			{ return IsType(VTYPE_iterator);				}
	inline bool Is_list() const				{ return IsType(VTYPE_list);					}
	inline bool Is_matrix() const			{ return IsType(VTYPE_matrix);					}
	inline bool Is_monitor() const			{ return IsType(VTYPE_monitor);					}
	inline bool Is_operator() const			{ return IsType(VTYPE_operator);				}
	inline bool Is_palette() const			{ return IsType(VTYPE_palette);					}
	inline bool Is_pointer() const			{ return IsType(VTYPE_pointer);					}
	inline bool Is_semaphore() const		{ return IsType(VTYPE_semaphore);				}
	inline bool Is_stream() const			{ return IsType(VTYPE_stream);					}
	inline bool Is_suffixmgr() const		{ return IsType(VTYPE_suffixmgr);				}
	inline bool Is_template() const			{ return IsType(VTYPE_template);				}
	inline bool Is_timedelta() const		{ return IsType(VTYPE_timedelta);				}
	inline bool Is_uri() const				{ return IsType(VTYPE_uri);						}
	inline bool IsListOrIterator() const	{ return Is_list() || Is_iterator();			}
	inline bool IsValidKey() const			{ return Is_number() || Is_string() || Is_symbol(); }
	bool MustBe(Signal &sig, bool flag, const char *expected) const;
	inline bool MustBeInvalid(Signal &sig) const
								{ return MustBe(sig, IsInvalid(),		"invalid");			}
	inline bool MustBeUndefined(Signal &sig) const
								{ return MustBe(sig, IsUndefined(),		"undefined");		}
	inline bool MustBeValid(Signal &sig) const
								{ return MustBe(sig, IsValid(),			"valid");			}
	inline bool MustBeDefined(Signal &sig) const
								{ return MustBe(sig, IsDefined(),		"defined");			}
	// primitive types
	inline bool MustBe_boolean(Signal &sig) const
								{ return MustBe(sig, Is_boolean(), 		"boolean");			}
	inline bool MustBe_complex(Signal &sig) const
								{ return MustBe(sig, Is_complex(), 		"complex");			}
	inline bool MustBe_number(Signal &sig) const
								{ return MustBe(sig, Is_number(), 		"number");			}
	inline bool MustBe_rational(Signal &sig) const
								{ return MustBe(sig, Is_rational(), 	"rational");		}
	inline bool MustBe_string(Signal &sig) const
								{ return MustBe(sig, Is_string(), 		"string");			}
	inline bool MustBe_symbol(Signal &sig) const
								{ return MustBe(sig, Is_symbol(),		"symbol");			}
	// container types
	inline bool MustBeModule(Signal &sig) const
								{ return MustBe(sig, IsModule(), 		"module");			}
	inline bool MustBeClass(Signal &sig) const
								{ return MustBe(sig, IsClass(), 		"class");			}
	// object types
	inline bool MustBeGenericObject(Signal &sig) const
								{ return MustBe(sig, IsGenericObject(), "generic object");	}
	inline bool MustBeStruct(Signal &sig) const
								{ return MustBe(sig, IsStruct(), 		"struct");			}
	inline bool MustBe_argument(Signal &sig) const
								{ return MustBe(sig, Is_argument(), 	"argument");		}
	inline bool MustBe_audio(Signal &sig) const
								{ return MustBe(sig, Is_audio(), 		"audio");			}
	inline bool MustBe_binary(Signal &sig) const
								{ return MustBe(sig, Is_binary(), 		"binary");			}
	inline bool MustBe_codec(Signal &sig) const
								{ return MustBe(sig, Is_codec(), 		"codec");			}
	inline bool MustBe_color(Signal &sig) const
								{ return MustBe(sig, Is_color(), 		"color");			}
	inline bool MustBe_datetime(Signal &sig) const
								{ return MustBe(sig, Is_datetime(), 	"datetime");		}
	inline bool MustBe_declaration(Signal &sig) const
								{ return MustBe(sig, Is_declaration(),	"declaration");		}
	inline bool MustBe_dict(Signal &sig) const
								{ return MustBe(sig, Is_dict(), 		"dict");			}
	inline bool MustBe_directory(Signal &sig) const
								{ return MustBe(sig, Is_directory(), 	"directory");		}
	inline bool MustBe_environment(Signal &sig) const
								{ return MustBe(sig, Is_environment(),	"environment");		}
	inline bool MustBe_error(Signal &sig) const
								{ return MustBe(sig, Is_error(), 		"error");			}
	inline bool MustBe_expr(Signal &sig) const
								{ return MustBe(sig, Is_expr(), 		"expr");			}
	inline bool MustBe_formatter(Signal &sig) const
								{ return MustBe(sig, Is_formatter(), 	"formatter");		}
	inline bool MustBe_function(Signal &sig) const
								{ return MustBe(sig, Is_function(), 	"function");		}
	inline bool MustBe_help(Signal &sig) const
								{ return MustBe(sig, Is_help(), 		"help");			}
	inline bool MustBe_image(Signal &sig) const
								{ return MustBe(sig, Is_image(), 		"image");			}
	inline bool MustBe_iterator(Signal &sig) const
								{ return MustBe(sig, Is_iterator(), 	"iterator");		}
	inline bool MustBe_list(Signal &sig) const
								{ return MustBe(sig, Is_list(), 		"list");			}
	inline bool MustBe_matrix(Signal &sig) const
								{ return MustBe(sig, Is_matrix(), 		"matrix");			}
	inline bool MustBe_monitor(Signal &sig) const
								{ return MustBe(sig, Is_monitor(), 		"monitor");			}
	inline bool MustBe_operator(Signal &sig) const
								{ return MustBe(sig, Is_operator(), 	"operator");		}
	inline bool MustBe_palette(Signal &sig) const
								{ return MustBe(sig, Is_palette(), 		"palette");			}
	inline bool MustBe_pointer(Signal &sig) const
								{ return MustBe(sig, Is_pointer(), 		"pointer");			}
	inline bool MustBe_semaphore(Signal &sig) const
								{ return MustBe(sig, Is_semaphore(), 	"semaphore");		}
	inline bool MustBe_stream(Signal &sig) const
								{ return MustBe(sig, Is_stream(), 		"stream");			}
	inline bool MustBe_suffixmgr(Signal &sig) const
								{ return MustBe(sig, Is_suffixmgr(), 	"suffixmgr");		}
	inline bool MustBe_template(Signal &sig) const
								{ return MustBe(sig, Is_template(), 	"template");		}
	inline bool MustBe_timedelta(Signal &sig) const
								{ return MustBe(sig, Is_timedelta(), 	"timedelta");		}
	inline bool MustBe_uri(Signal &sig) const
								{ return MustBe(sig, Is_uri(), 			"uri");				}
	// setter methods
	inline void SetBoolean(bool flag) {
		Gura_ReleaseValue(*this); _valType = VTYPE_boolean, _u.flag = flag;
	}
	inline void SetComplex(const Complex &comp) {
		Gura_ReleaseValue(*this);
		if (comp.imag() == 0.) {
			 _valType = VTYPE_number, _u.num = comp.real();
		} else {
			 _valType = VTYPE_complex, _u.pComp = new Complex(comp);
		}
	}
	inline void SetNumber(Number num) {
		Gura_ReleaseValue(*this); _valType = VTYPE_number, _u.num = num;
	}
	inline void SetRational(const Rational &ratio) {
		Gura_ReleaseValue(*this);
		_valType = VTYPE_rational, _u.pRatio = new Rational(ratio);
	}
	inline void SetSymbol(const Symbol *pSymbol) {
		Gura_ReleaseValue(*this); _valType = VTYPE_symbol, _u.pSymbol = pSymbol;
	}
	// getter methods
	// VTYPE_boolean
	inline bool GetBoolean() const			{ return Is_boolean()? _u.flag : IsValid(); }
	// VTYPE_complex
	inline Complex GetComplex() const {
		return Is_complex()? *_u.pComp : Is_number()? Complex(GetNumber()) : Complex::Zero;
	}
	inline Complex *GetComplexPtr() const	{ return _u.pComp;							}
	// VTYPE_number
	inline Number GetNumber() const {
		return Is_number()? _u.num :
				Is_boolean()? (_u.flag? 1. : 0.) :
				Is_string()? ::strtod(GetString(), nullptr) : 0.;
	}
	inline int GetInt() const				{ return static_cast<int>(GetNumber());			}
	inline UInt GetUInt() const				{ return static_cast<UInt>(GetNumber());		}
	inline size_t GetSizeT() const			{ return static_cast<size_t>(GetNumber());		}
	inline char GetChar() const				{ return static_cast<char>(GetNumber());		}
	inline UChar GetUChar() const			{ return static_cast<UChar>(GetNumber());		}
	inline short GetShort() const			{ return static_cast<short>(GetNumber());		}
	inline UShort GetUShort() const			{ return static_cast<UShort>(GetNumber());		}
	inline long GetLong() const {
		Number num = GetNumber();
		return (num < 0x80000000)? static_cast<long>(num) :
						static_cast<long>(static_cast<ULong>(num));
	}
	inline ULong GetULong() const			{ return static_cast<ULong>(GetNumber());		}
	inline Int64 GetInt64() const			{ return static_cast<Int64>(GetNumber());		}
	inline UInt64 GetUInt64() const			{ return static_cast<UInt64>(GetNumber());		}
	inline float GetFloat() const			{ return static_cast<float>(GetNumber());		}
	inline double GetDouble() const			{ return static_cast<double>(GetNumber());		}
	// VTYPE_rational
	inline Rational &GetRational() const	{ return *_u.pRatio;							}
	inline Rational *GetRationalPtr() const	{ return _u.pRatio;								}
	// VTYPE_string
	const char *GetString() const;
	String GetStringSTL() const;
	// VTYPE_symbol
	inline const Symbol *GetSymbol() const	{ return Is_symbol()? _u.pSymbol : nullptr;		}
	// fundamental
	inline Fundamental *GetFundamental() const
											{ return _u.pFund;								}
	// VTYPE_Module
	inline Module *GetModule() const		{ return (Module *)_u.pFund;					}
	// VTYPE_Class
	inline Class *GetClassItself() const	{ return (Class *)_u.pFund;						}
	// object
	inline Object *GetObject() const		{ return (Object *)_u.pFund;					}
	// VTYPE_function
	Function *GetFunction() const;
	// VTYPE_binary
	Binary &GetBinary() const;
	// VTYPE_list
	ValueList &GetList() const;
	// VTYPE_dict
	ValueDict &GetDict() const;
	// VTYPE_stream
	Stream &GetStream() const;
	// VTYPE_iterator
	Iterator *GetIterator() const;
	// VTYPE_expr
	Expr *GetExpr() const;
	//-----------------------
	bool Is(const Value &value) const;
	Value EmptyIndexGet(Environment &env) const;
	void EmptyIndexSet(Environment &env, const Value &value);
	Value IndexGet(Environment &env, const Value &valueIdx) const;
	void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
	bool DirProp(Environment &env, SymbolSet &symbols, bool escalateFlag) const;
	void DirValueType(SymbolSet &symbols, bool escalateFlag) const;
	Value GetProp(const Symbol *pSymbol, const SymbolSet &attrs) const;
	Callable *GetCallable(const Symbol *pSymbol, const SymbolSet &attrs);
	ErrorType GetErrorType() const;
	bool IsFlatList() const;
	bool IsInstanceOf(ValueType valType) const;
	Fundamental *ExtractFundamental();
	inline Fundamental *ExtractFundamental() const {
		return const_cast<Value *>(this)->ExtractFundamental();
	}
	Expr *CloneExpr() const;
	Iterator *CreateIterator(Signal &sig) const;
	String ToString(bool exprFlag = true) const;
	Number ToNumber(bool allowPartFlag, bool &successFlag) const;
	bool Accept(ValueVisitor &visitor) const;
	void InitAsModule(Module *pModule);
	void InitAsClass(Class *pClass);
	void InitAsObject(Object *pObj);
	void _SetObject(Object *pObj);
	ValueList &InitAsList(Environment &env);
	ValueList &InitAsList(Environment &env, size_t n);
	ValueList &InitAsList(Environment &env, const ValueList &valList);
	ValueList &InitAsList(Environment &env, size_t n, const Value &value);
	ValueDict &InitAsDict(Environment &env, bool ignoreCaseFlag);
	bool CastType(Environment &env, ValueType valType, Value &valueCasted) const;
public:
	static int Compare(Environment &env, const Value &value1, const Value &value2);
	static int CompareBoolean(bool flag1, bool flag2);
	static int CompareComplex(const Complex &comp1, const Complex &comp2);
	static int CompareNumber(Number num1, Number num2);
	static int CompareRational(const Rational &ratio1, const Rational &ratio2);
	static int CompareString(const char *str1, const char *str2, bool ignoreCaseFlag);
	static int CompareSymbol(const Symbol *pSymbol1, const Symbol *pSymbol2);
	static Value CreateList(Environment &env);
	static Value CreateList(Environment &env, const Value &v1);
	static Value CreateList(Environment &env, const Value &v1, const Value &v2);
	static Value CreateList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3);
	static Value CreateList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4);
	static Value CreateList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4, const Value &v5);
	static Value CreateList(Environment &env, const Value &v1, const Value &v2,
			const Value &v3, const Value &v4, const Value &v5, const Value &v6);
	static Value CreateList(Environment &env, const char *buff, size_t n);
	static Value CreateList(Environment &env, const UChar *buff, size_t n);
	static Value CreateList(Environment &env, const short *buff, size_t n);
	static Value CreateList(Environment &env, const UShort *buff, size_t n);
	static Value CreateList(Environment &env, const long *buff, size_t n);
	static Value CreateList(Environment &env, const ULong *buff, size_t n);
	static Value CreateList(Environment &env, const int *buff, size_t n);
	static Value CreateList(Environment &env, const UInt *buff, size_t n);
	static Value CreateList(Environment &env, const Int64 *buff, size_t n);
	static Value CreateList(Environment &env, const UInt64 *buff, size_t n);
	static Value CreateList(Environment &env, const float *buff, size_t n);
	static Value CreateList(Environment &env, const double *buff, size_t n);
	static Value CreateList(Environment &env, const char *strs[], size_t n);
	static bool Serialize(Environment &env, Stream &stream, const Value &value);
	static bool Deserialize(Environment &env, Stream &stream, Value &value, bool mustBeValidFlag);
public:
	friend void Gura_CopyValue(Value &valueDst, const Value &valueSrc);
	friend void Gura_ReleaseValue(Value &value);
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
	static const ValueList Empty;
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
	bool DoesContain(Environment &env, const Value &value) const;
	bool DoesContainIterator() const;
	bool CheckMatrix(size_t *pnRow, size_t *pnCol) const;
	void ExtractFlat(ValueList &valList) const;
	bool Accept(ValueVisitor &visitor) const;
	void Append(const ValueList &valList);
	bool Append(Environment &env, Iterator *pIterator);
	String Join(const char *sep) const;
	Binary Joinb(Signal &sig) const;
	void Print(Signal &sig, int indentLevel = 0) const;
	void PrintEach(Environment &env, Stream *pStream) const;
	void PrintfEach(Environment &env, Stream *pStream, const char *format) const;
	void PrintlnEach(Environment &env, Stream *pStream) const;
	bool ToStringList(Signal &sig, StringList &strList) const;
	static bool AssumeSameLength(Signal &sig,
					const ValueList &valList1, const ValueList &valList2);
	bool Serialize(Environment &env, Stream &stream) const;
	bool Deserialize(Environment &env, Stream &stream);
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
	static const ValueMap Empty;
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(ValueMap);
public:
	inline ValueMap() : _cntRef(1) {}
private:
	inline ~ValueMap() {}
public:
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
		STORE_Strict,
		STORE_Overwrite,
		STORE_Timid,
	};
	static const ValueDict Empty;
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
	const Value *Find(Signal &sig, const Value &valueIdx) const;
	bool Store(Signal &sig, const ValueList &valList, StoreMode storeMode);
	bool Store(Signal &sig, const ValueDict &valDict, StoreMode storeMode);
	bool Store(Signal &sig, const Value &valueIdx, const Value &value, StoreMode storeMode);
	inline bool GetIgnoreCaseFlag() const { return _ignoreCaseFlag; }
	bool Serialize(Environment &env, Stream &stream) const;
	bool Deserialize(Environment &env, Stream &stream);
	static void SetError_InvalidKey(Signal &sig, const Value &valueKey);
	static void SetError_InvalidIterator(Signal &sig);
	static void SetError_KeyNotFound(Signal &sig, const Value &valueKey);
	static void SetError_NotWritable(Signal &sig);
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
