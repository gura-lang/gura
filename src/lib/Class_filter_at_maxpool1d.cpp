//=============================================================================
// Gura class: filter@maxpool1d
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter_MaxPool1d
//-----------------------------------------------------------------------------
Filter_MaxPool1d::FilterFuncTable Filter_MaxPool1d::filterFuncTable = {{nullptr}};

Array *Filter_MaxPool1d::Apply(
	Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_MaxPool1d &filter)
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply max pool filter on this array");
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayResult, pArray, filter);
}

//-----------------------------------------------------------------------------
// Object_filter_at_maxpool1d
//-----------------------------------------------------------------------------
Object_filter_at_maxpool1d::Object_filter_at_maxpool1d(Environment &env, const Filter_MaxPool1d &filter) :
	Object(env.LookupClass(VTYPE_filter_at_maxpool1d)), _filter(filter)
{
}

Object *Object_filter_at_maxpool1d::Clone() const
{
	return nullptr;
}
	
String Object_filter_at_maxpool1d::ToString(bool exprFlag)
{
	String str;
	str += "<filter@maxpool1d:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter@maxpool1d(size:number, strides?:number, padding?:symbol, channel_at?:symbol):map {block?}
Gura_DeclareFunctionAlias(filter_at_maxpool1d, "filter@maxpool1d")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "padding", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "channel_at", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_filter_at_maxpool1d));
	AddHelp(
		Gura_Symbol(en),
		"Creates a `filter@maxpool1d` instance.\n");
}

Gura_ImplementFunction(filter_at_maxpool1d)
{
	size_t size = arg.GetSizeT(0);
	size_t strides = arg.GetSizeT(1);
	Filter::PaddingType paddingType = Filter::PADDINGTYPE_Valid;
	if (arg.IsValid(2)) {
		Filter::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Filter::PADDINGTYPE_None) return Value::Nil;
	}
	Filter::ChannelAt channelAt = Filter::CHANNELAT_Last;
	if (arg.IsValid(3)) {
		Filter::SymbolToChannelAt(env, arg.GetSymbol(3));
		if (channelAt == Filter::CHANNELAT_None) return Value::Nil;
	}
	Object_filter_at_maxpool1d *pObj = new Object_filter_at_maxpool1d(
		env, Filter_MaxPool1d(size, strides, paddingType, channelAt));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter_at_maxpool1d::Class_filter_at_maxpool1d(Environment *pEnvOuter) :
	ClassFundamental(pEnvOuter, VTYPE_filter_at_maxpool1d)
{
}

void Class_filter_at_maxpool1d::DoPrepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(filter_at_maxpool1d);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_maxpool1d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
