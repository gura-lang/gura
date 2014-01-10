//=============================================================================
// SuffixHandler
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// SuffixHandler
//-----------------------------------------------------------------------------
SuffixHandler *SuffixHandler::LookupForString(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixHandlerMapForString().Lookup(pSymbolSuffix);
}

SuffixHandler *SuffixHandler::LookupForNumber(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixHandlerMapForNumber().Lookup(pSymbolSuffix);
}

void SuffixHandler::RegisterForString(Environment &env,
				const Symbol *pSymbolSuffix, SuffixHandler *pSuffixHandler)
{
	env.GetGlobal()->GetSuffixHandlerMapForString().Register(pSymbolSuffix, pSuffixHandler);
}

void SuffixHandler::RegisterForNumber(Environment &env,
				const Symbol *pSymbolSuffix, SuffixHandler *pSuffixHandler)
{
	env.GetGlobal()->GetSuffixHandlerMapForNumber().Register(pSymbolSuffix, pSuffixHandler);
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
