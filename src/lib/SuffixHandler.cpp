//=============================================================================
// SuffixHandler
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// SuffixHandler
//-----------------------------------------------------------------------------
SuffixHandler *SuffixHandler::Lookup(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixHandlerMap().Lookup(pSymbolSuffix);
}

void SuffixHandler::Register(Environment &env,
				const Symbol *pSymbolSuffix, SuffixHandler *pSuffixHandler)
{
	env.GetGlobal()->GetSuffixHandlerMap().Register(pSymbolSuffix, pSuffixHandler);
}

//-----------------------------------------------------------------------------
// SuffixHandlerMap
//-----------------------------------------------------------------------------
SuffixHandlerMap::~SuffixHandlerMap()
{
	foreach (SuffixHandlerMap, iter, *this) {
		delete iter->second;
	}
}

void SuffixHandlerMap::Register(const Symbol *pSymbolSuffix, SuffixHandler *pSuffixHandler)
{
	iterator iter = find(pSymbolSuffix);
	if (iter == end()) {
		(*this)[pSymbolSuffix] = pSuffixHandler;
	} else {
		delete iter->second;
		iter->second = pSuffixHandler;
	}
}

SuffixHandler *SuffixHandlerMap::Lookup(const Symbol *pSymbolSuffix)
{
	iterator iter = find(pSymbolSuffix);
	return (iter == end())? NULL : iter->second;
}


}
