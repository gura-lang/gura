//=============================================================================
// SuffixManager
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// SuffixManager
//-----------------------------------------------------------------------------
SuffixManager *SuffixManager::LookupForString(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixManagerMapForString().Lookup(pSymbolSuffix);
}

SuffixManager *SuffixManager::LookupForNumber(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixManagerMapForNumber().Lookup(pSymbolSuffix);
}

void SuffixManager::RegisterForString(Environment &env,
				const Symbol *pSymbolSuffix, SuffixManager *pSuffixManager)
{
	env.GetGlobal()->GetSuffixManagerMapForString().Register(pSymbolSuffix, pSuffixManager);
}

void SuffixManager::RegisterForNumber(Environment &env,
				const Symbol *pSymbolSuffix, SuffixManager *pSuffixManager)
{
	env.GetGlobal()->GetSuffixManagerMapForNumber().Register(pSymbolSuffix, pSuffixManager);
}

//-----------------------------------------------------------------------------
// SuffixManagerMap
//-----------------------------------------------------------------------------
SuffixManagerMap::~SuffixManagerMap()
{
	foreach (SuffixManagerMap, iter, *this) {
		delete iter->second;
	}
}

void SuffixManagerMap::Register(const Symbol *pSymbolSuffix, SuffixManager *pSuffixManager)
{
	iterator iter = find(pSymbolSuffix);
	if (iter == end()) {
		(*this)[pSymbolSuffix] = pSuffixManager;
	} else {
		delete iter->second;
		iter->second = pSuffixManager;
	}
}

SuffixManager *SuffixManagerMap::Lookup(const Symbol *pSymbolSuffix)
{
	iterator iter = find(pSymbolSuffix);
	return (iter == end())? NULL : iter->second;
}


}
