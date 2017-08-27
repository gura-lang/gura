//=============================================================================
// Gura class: filter
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Filter
//-----------------------------------------------------------------------------
Filter::~Filter()
{
}

// .+++++++++++.. 12
// *****
//    *****
//       *****
//          *****
size_t Filter::CalcSizeOutSame(size_t size, size_t strides)
{
	return 0;
}

size_t Filter::CalcSizeOutValid(size_t size, size_t strides, size_t sizeFilter)
{
	return 0;
}

Filter::PaddingType Filter::SymbolToPaddingType(Signal &sig, const Symbol *pSymbol)
{
	PaddingType paddingType = SymbolToPaddingType(pSymbol);
	if (paddingType == PADDINGTYPE_None) {
		sig.SetError(ERR_ValueError, "invalid symbol to specify padding type: %s",
					 pSymbol->GetName());
	}
	return paddingType;
}

Filter::PaddingType Filter::SymbolToPaddingType(const Symbol *pSymbol)
{
	return
		pSymbol->IsIdentical(Gura_Symbol(valid))? PADDINGTYPE_Valid :
		pSymbol->IsIdentical(Gura_Symbol(same))? PADDINGTYPE_Same :
		PADDINGTYPE_None;
}

const Symbol *Filter::PaddingTypeToSymbol(PaddingType paddingType)
{
	return
		(paddingType == PADDINGTYPE_Valid)? Gura_Symbol(valid) :
		(paddingType == PADDINGTYPE_Same)? Gura_Symbol(same) :
		Gura_Symbol(none);
}

Filter::ChannelAt Filter::SymbolToChannelAt(Signal &sig, const Symbol *pSymbol)
{
	ChannelAt channelAt = SymbolToChannelAt(pSymbol);
	if (channelAt == CHANNELAT_None) {
		sig.SetError(ERR_ValueError, "invalid symbol to specify channel positioning: %s",
					 pSymbol->GetName());
	}
	return channelAt;
}

Filter::ChannelAt Filter::SymbolToChannelAt(const Symbol *pSymbol)
{
	return
		pSymbol->IsIdentical(Gura_Symbol(first))? CHANNELAT_First :
		pSymbol->IsIdentical(Gura_Symbol(last))? CHANNELAT_Last :
		CHANNELAT_None;
}

const Symbol *Filter::ChannelAtToSymbol(ChannelAt channelAt)
{
	return
		(channelAt == CHANNELAT_First)? Gura_Symbol(first) :
		(channelAt == CHANNELAT_Last)? Gura_Symbol(last) :
		Gura_Symbol(none);
}

//-----------------------------------------------------------------------------
// Object_filter
//-----------------------------------------------------------------------------
Object_filter::Object_filter(Environment &env, Filter *pFilter) :
	Object(env.LookupClass(VTYPE_filter_at_conv1d)), _pFilter(pFilter)
{
}

Object_filter::Object_filter(Class *pClass, Filter *pFilter) :
	Object(pClass), _pFilter(pFilter)
{
}

Object *Object_filter::Clone() const
{
	return nullptr;
}
	
String Object_filter::ToString(bool exprFlag)
{
	String str;
	str += "<filter";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter::Class_filter(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_filter)
{
}

void Class_filter::DoPrepare(Environment &env)
{
	// Assignment of value
	Gura_AssignValue(filter, Value(this));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_filter::CreateDescendant(Environment &env, Class *pClass)
{
	return nullptr;
}

}
