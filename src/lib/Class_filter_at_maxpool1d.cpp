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

Array *Filter_MaxPool1d::Apply(Signal &sig, Array *pArrayRtn, const Array *pArray) const
{
	FilterFuncT filterFunc = filterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply 1-dimension max pool filter on array@%s",
					 pArray->GetElemTypeName());
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayRtn, pArray, this);
}

String Filter_MaxPool1d::ToString() const
{
	String str;
	char buff[80];
	str += "maxpool1d";
	::sprintf(buff, ":size=%zu", GetSize());
	str += buff;
	::sprintf(buff, ":strides=%zu", GetStrides());
	str += buff;
	::sprintf(buff, ":padding=%s", PaddingTypeToSymbol(GetPaddingType())->GetName());
	str += buff;
	::sprintf(buff, ":channel_at=%s", ChannelAtToSymbol(GetChannelAt())->GetName());
	str += buff;
	return str;
}

//-----------------------------------------------------------------------------
// Object_filter_at_maxpool1d
//-----------------------------------------------------------------------------
Object_filter_at_maxpool1d::Object_filter_at_maxpool1d(Environment &env, Filter_MaxPool1d *pFilter) :
	Object_filter(env.LookupClass(VTYPE_filter_at_maxpool1d), pFilter)
{
}

Object *Object_filter_at_maxpool1d::Clone() const
{
	return nullptr;
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
		"Creates a `filter@maxpool1d` instance from the following arguments:\n"
		"\n"
		"- `size` .. Filter size.\n"
		"- `strides` .. Strides of sliding window. Default is one.\n"
		"- `padding` .. Padding style `` `valid`` or `` `same``. Default is `` `same``.\n"
		"- `channel_at` .. Channel position `` `first`` or `` `last``. Default is `` `last``. \n");
}

Gura_ImplementFunction(filter_at_maxpool1d)
{
	size_t size = arg.GetSizeT(0);
	size_t strides = arg.GetSizeT(1);
	Filter::PaddingType paddingType = Filter::PADDINGTYPE_Same;
	if (arg.IsValid(2)) {
		paddingType = Filter::SymbolToPaddingType(env, arg.GetSymbol(2));
		if (paddingType == Filter::PADDINGTYPE_None) return Value::Nil;
	}
	Filter::ChannelAt channelAt = Filter::CHANNELAT_Last;
	if (arg.IsValid(3)) {
		channelAt = Filter::SymbolToChannelAt(env, arg.GetSymbol(3));
		if (channelAt == Filter::CHANNELAT_None) return Value::Nil;
	}
	Object_filter_at_maxpool1d *pObj = new Object_filter_at_maxpool1d(
		env, new Filter_MaxPool1d(size, strides, paddingType, channelAt));
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// filter@maxpool1d#size
Gura_DeclareProperty_R(filter_at_maxpool1d, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_maxpool1d, size)
{
	const Filter_MaxPool1d *pFilter = Object_filter_at_maxpool1d::GetObject(valueThis)->GetFilter();
	return Value(pFilter->GetSize());
}

// filter@maxpool1d#strides
Gura_DeclareProperty_R(filter_at_maxpool1d, strides)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_maxpool1d, strides)
{
	const Filter_MaxPool1d *pFilter = Object_filter_at_maxpool1d::GetObject(valueThis)->GetFilter();
	return Value(pFilter->GetStrides());
}

// filter@maxpool1d#padding
Gura_DeclareProperty_R(filter_at_maxpool1d, padding)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_maxpool1d, padding)
{
	const Filter_MaxPool1d *pFilter = Object_filter_at_maxpool1d::GetObject(valueThis)->GetFilter();
	return Value(Filter::PaddingTypeToSymbol(pFilter->GetPaddingType()));
}

// filter@maxpool1d#channel_at
Gura_DeclareProperty_R(filter_at_maxpool1d, channel_at)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(filter_at_maxpool1d, channel_at)
{
	const Filter_MaxPool1d *pFilter = Object_filter_at_maxpool1d::GetObject(valueThis)->GetFilter();
	return Value(Filter::ChannelAtToSymbol(pFilter->GetChannelAt()));
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
	// Assignment of function
	Gura_AssignFunction(filter_at_maxpool1d);
	// Assignment of properties
	Gura_AssignProperty(filter_at_maxpool1d, size);
	Gura_AssignProperty(filter_at_maxpool1d, strides);
	Gura_AssignProperty(filter_at_maxpool1d, padding);
	Gura_AssignProperty(filter_at_maxpool1d, channel_at);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter_at_maxpool1d::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
