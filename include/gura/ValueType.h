//=============================================================================
// ValueType
//=============================================================================
#ifndef __GURA_VALUETYPE_H__
#define __GURA_VALUETYPE_H__

#include "Common.h"
#include "Symbol.h"

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------
#define Gura_VTYPEInfo(name) \
(ValueTypePool::GetInstance()->_pValueTypeInfo_##name)

#define Gura_DeclareVTYPE(name) \
ValueTypeInfo *_pValueTypeInfo_##name

#define Gura_RealizeVTYPEAlias(name, str) do { \
	_pValueTypeInfo_##name = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(_pValueTypeInfo_##name); \
	VTYPE_##name = _pValueTypeInfo_##name->GetValueType(); \
} while (0)

#define Gura_RealizeVTYPE(name) \
Gura_RealizeVTYPEAlias(name, #name)

namespace Gura {

class Class;
class Module;

//-----------------------------------------------------------------------------
// ValueType
//-----------------------------------------------------------------------------
typedef UShort ValueType;

// nil / undefined
GURA_DLLDECLARE extern ValueType VTYPE_nil;
GURA_DLLDECLARE extern ValueType VTYPE_undefined;
// primitive types
GURA_DLLDECLARE extern ValueType VTYPE_boolean;
GURA_DLLDECLARE extern ValueType VTYPE_complex;
GURA_DLLDECLARE extern ValueType VTYPE_number;
GURA_DLLDECLARE extern ValueType VTYPE_rational;
GURA_DLLDECLARE extern ValueType VTYPE_string;
GURA_DLLDECLARE extern ValueType VTYPE_symbol;
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
GURA_DLLDECLARE extern ValueType VTYPE_array_char;
GURA_DLLDECLARE extern ValueType VTYPE_array_uchar;
GURA_DLLDECLARE extern ValueType VTYPE_array_short;
GURA_DLLDECLARE extern ValueType VTYPE_array_ushort;
GURA_DLLDECLARE extern ValueType VTYPE_array_long;
GURA_DLLDECLARE extern ValueType VTYPE_array_ulong;
GURA_DLLDECLARE extern ValueType VTYPE_array_int;
GURA_DLLDECLARE extern ValueType VTYPE_array_uint;
GURA_DLLDECLARE extern ValueType VTYPE_array_float;
GURA_DLLDECLARE extern ValueType VTYPE_array_double;
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
GURA_DLLDECLARE extern ValueType VTYPE_formatter;
GURA_DLLDECLARE extern ValueType VTYPE_function;
GURA_DLLDECLARE extern ValueType VTYPE_help;
GURA_DLLDECLARE extern ValueType VTYPE_image;
GURA_DLLDECLARE extern ValueType VTYPE_iterator;
GURA_DLLDECLARE extern ValueType VTYPE_list;
GURA_DLLDECLARE extern ValueType VTYPE_matrix;
GURA_DLLDECLARE extern ValueType VTYPE_monitor;
GURA_DLLDECLARE extern ValueType VTYPE_operator;
GURA_DLLDECLARE extern ValueType VTYPE_palette;
GURA_DLLDECLARE extern ValueType VTYPE_pointer;
GURA_DLLDECLARE extern ValueType VTYPE_semaphore;
GURA_DLLDECLARE extern ValueType VTYPE_stream;
GURA_DLLDECLARE extern ValueType VTYPE_suffixmgr;
GURA_DLLDECLARE extern ValueType VTYPE_template;
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
			_valType(valType), _pSymbol(pSymbol), _pClass(pClass), _pModule(nullptr) {}
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
	static const ValueTypeMap Empty;
	inline ValueTypeMap() {}
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
	Gura_DeclareVTYPE(boolean);
	Gura_DeclareVTYPE(complex);
	Gura_DeclareVTYPE(number);
	Gura_DeclareVTYPE(rational);
	Gura_DeclareVTYPE(string);
	Gura_DeclareVTYPE(symbol);
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
	Gura_DeclareVTYPE(array_char);
	Gura_DeclareVTYPE(array_uchar);
	Gura_DeclareVTYPE(array_short);
	Gura_DeclareVTYPE(array_ushort);
	Gura_DeclareVTYPE(array_long);
	Gura_DeclareVTYPE(array_ulong);
	Gura_DeclareVTYPE(array_int);
	Gura_DeclareVTYPE(array_uint);
	Gura_DeclareVTYPE(array_float);
	Gura_DeclareVTYPE(array_double);
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
	Gura_DeclareVTYPE(formatter);
	Gura_DeclareVTYPE(function);
	Gura_DeclareVTYPE(help);
	Gura_DeclareVTYPE(image);
	Gura_DeclareVTYPE(iterator);
	Gura_DeclareVTYPE(list);
	Gura_DeclareVTYPE(matrix);
	Gura_DeclareVTYPE(monitor);
	Gura_DeclareVTYPE(operator);
	Gura_DeclareVTYPE(palette);
	Gura_DeclareVTYPE(pointer);
	Gura_DeclareVTYPE(semaphore);
	Gura_DeclareVTYPE(stream);
	Gura_DeclareVTYPE(suffixmgr);
	Gura_DeclareVTYPE(template);
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

}

#endif
