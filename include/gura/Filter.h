//=============================================================================
// Filter
//=============================================================================
#ifndef __GURA_FILTER_H__
#define __GURA_FILTER_H__

#include "Array.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter {
public:
	enum PaddingType {
		PADDINGTYPE_None,
		PADDINGTYPE_Valid,
		PADDINGTYPE_Same,
	};
	enum ChannelAt {
		CHANNELAT_None,
		CHANNELAT_Last,
		CHANNELAT_First,
	};
public:
	inline Filter() {}
	virtual ~Filter();
public:
	static PaddingType SymbolToPaddingType(Signal &sig, const Symbol *pSymbol);
	static PaddingType SymbolToPaddingType(const Symbol *pSymbol);
	static const Symbol *PaddingTypeToSymbol(PaddingType paddingType);
	static ChannelAt SymbolToChannelAt(Signal &sig, const Symbol *pSymbol);
	static ChannelAt SymbolToChannelAt(const Symbol *pSymbol);
	static const Symbol *ChannelAtToSymbol(ChannelAt channelAt);
};

}

#endif
