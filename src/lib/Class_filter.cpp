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

void Filter::CalcPadding(size_t sizeIn, size_t sizeFilter, size_t strides, PaddingType paddingType,
						 size_t *pSizeOut, size_t *pSizePad)
{
	size_t sizeOut = 0, sizePad = 0;
	if (paddingType == PADDINGTYPE_Valid) {
		// sizeIn = 9, strides = 3
		// +++++++++  +++++++++  +++++++++  +++++++++
		// **         ***        ****       *****
		//    **         ***        ****       *****
		//       **         ***
		//
		// sizeIn = 10, strides = 3
		// ++++++++++  ++++++++++  ++++++++++  ++++++++++
		// **          ***         ****        *****
		//    **          ***         ****        *****
		//       **          ***         ****
		//
		sizeOut = (sizeIn - sizeFilter + strides) / strides;
	} else if (paddingType == PADDINGTYPE_Same) {
		// sizeIn = 9, strides = 3 ... sizeOut = 3
		// +++++++++  +++++++++  +++++++++.  .+++++++++.
		// **         ***        ****        *****
		//    **         ***        ****        *****
		//       **         ***        ****        *****
		//
		// sizeIn = 10, strides = 3 ... sizeOut = 4
		// ++++++++++.  .++++++++++.  .++++++++++..  ..++++++++++..
		// **           ***           ****           *****
		//    **           ***           ****           *****
		//       **           ***           ****           *****
		//          **           ***           ****           *****
		//
		sizeOut = (sizeIn + strides - 1) / strides;
		sizePad = strides * (sizeOut - 1) + sizeFilter - sizeIn;
	} else {
		// nothing to do 
	}
	*pSizeOut = sizeOut;
	*pSizePad = sizePad;
}

void Filter::CalcPadding(size_t sizeIn, size_t sizeFilter, size_t strides, PaddingType paddingType,
						 size_t *pSizeOut, size_t *pSizePadHead, size_t *pSizePadTail)
{
	size_t sizePad = 0;
	CalcPadding(sizeIn, sizeFilter, strides, paddingType, pSizeOut, &sizePad);
	*pSizePadHead = sizePad / 2;
	*pSizePadTail = sizePad - *pSizePadHead;
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
	Object(env.LookupClass(VTYPE_filter)), _pFilter(pFilter)
{
}

Object_filter::Object_filter(Class *pClass, Filter *pFilter) :
	Object(pClass), _pFilter(pFilter)
{
}

String Object_filter::ToString(bool exprFlag)
{
	String str;
	str += "<filter@";
	str += _pFilter->ToString();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// filter.calcpadding(size_in:number, size_filter:number, strides:number, padding:symbol)
Gura_DeclareClassMethod(filter, calcpadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "size_in", VTYPE_number);
	DeclareArg(env, "size_filter", VTYPE_number);
	DeclareArg(env, "strides", VTYPE_number);
	DeclareArg(env, "padding", VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"Calculates padding amounts from given input size, filter size and strides.\n"
		"The argument `padding` specifies padding manner and can take `` `same`` or `` `valid``.\n"
		"The returned value is a list of `[size_out, padding]`.");
}

Gura_ImplementClassMethod(filter, calcpadding)
{
	size_t sizeIn = arg.GetSizeT(0);
	size_t sizeFilter = arg.GetSizeT(1);
	size_t strides = arg.GetSizeT(2);
	Filter::PaddingType paddingType = Filter::SymbolToPaddingType(env, arg.GetSymbol(3));
	if (paddingType == Filter::PADDINGTYPE_None) return Value::Nil;
	size_t sizeOut = 0, sizePad = 0;
	Filter::CalcPadding(sizeIn, sizeFilter, strides, paddingType, &sizeOut, &sizePad);
	return Value::CreateList(env, Value(sizeOut), Value(sizePad));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_filter::Class_filter(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_filter)
{
}

void Class_filter::DoPrepare(Environment &env)
{
	// Assignment of methods
	Gura_AssignMethod(filter, calcpadding);
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
