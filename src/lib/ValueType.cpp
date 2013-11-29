#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Built-in Value Types
//-----------------------------------------------------------------------------
// nil / undefined
ValueType VTYPE_nil				= static_cast<ValueType>(0);
ValueType VTYPE_undefined		= static_cast<ValueType>(1);
// primitive types
ValueType VTYPE_boolean			= static_cast<ValueType>(2);
ValueType VTYPE_complex			= static_cast<ValueType>(3);
ValueType VTYPE_fraction		= static_cast<ValueType>(4);
ValueType VTYPE_number			= static_cast<ValueType>(5);
ValueType VTYPE_string			= static_cast<ValueType>(6);
ValueType VTYPE_symbol			= static_cast<ValueType>(7);
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
ValueType VTYPE_template		= static_cast<ValueType>(0);
ValueType VTYPE_timedelta		= static_cast<ValueType>(0);
ValueType VTYPE_uri				= static_cast<ValueType>(0);
ValueType VTYPE_Struct			= static_cast<ValueType>(0);

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
const ValueTypeMap ValueTypeMap::Null;

//-----------------------------------------------------------------------------
// ValueTypePool
//-----------------------------------------------------------------------------
ValueTypePool *ValueTypePool::_pInst = NULL;

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
	Gura_RealizeVTYPE(boolean);		// must be at 3rd
	Gura_RealizeVTYPE(complex);		// must be at 4th
	Gura_RealizeVTYPE(fraction);	// must be at 5th
	Gura_RealizeVTYPE(number);		// must be at 6th
	Gura_RealizeVTYPE(string);		// must be at 7th
	Gura_RealizeVTYPE(symbol);		// must be at 8th
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
	Gura_RealizeVTYPE(template);
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
	Gura_VTYPEInfo(template		)->SetClass(new Class_template(pClass));
	Gura_VTYPEInfo(timedelta	)->SetClass(new Class_timedelta(pClass));
	Gura_VTYPEInfo(uri			)->SetClass(new Class_uri(pClass));
	Gura_VTYPEInfo(Struct		)->SetClass(new ClassOfStruct(pClass));
	pClass->Prepare(env); // methods of Object can only be initialized here
}

void ValueTypePool::DoPrepareClass(Environment &env)
{
	// nil / undefined
	env.LookupClass(VTYPE_nil)->Prepare(env);
	env.LookupClass(VTYPE_undefined)->Prepare(env);
	// primitive types
	env.LookupClass(VTYPE_boolean)->Prepare(env);
	env.LookupClass(VTYPE_complex)->Prepare(env);
	env.LookupClass(VTYPE_fraction)->Prepare(env);
	env.LookupClass(VTYPE_number)->Prepare(env);
	env.LookupClass(VTYPE_string)->Prepare(env);
	env.LookupClass(VTYPE_symbol)->Prepare(env);
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
	env.LookupClass(VTYPE_template)->Prepare(env);
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

}
