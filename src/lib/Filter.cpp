//=============================================================================
// Filter
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter
//-----------------------------------------------------------------------------
Filter::~Filter()
{
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

}
