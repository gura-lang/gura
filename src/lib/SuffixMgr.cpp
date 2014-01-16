//=============================================================================
// SuffixMgr
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// SuffixMgr
//-----------------------------------------------------------------------------
SuffixMgr *SuffixMgr::LookupForString(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixMgrMapForString().Lookup(pSymbolSuffix);
}

SuffixMgr *SuffixMgr::LookupForNumber(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixMgrMapForNumber().Lookup(pSymbolSuffix);
}

void SuffixMgr::AssignForString(Environment &env,
				const Symbol *pSymbolSuffix, SuffixMgr *pSuffixMgr)
{
	env.GetGlobal()->GetSuffixMgrMapForString().Assign(pSymbolSuffix, pSuffixMgr);
}

void SuffixMgr::AssignForNumber(Environment &env,
				const Symbol *pSymbolSuffix, SuffixMgr *pSuffixMgr)
{
	env.GetGlobal()->GetSuffixMgrMapForNumber().Assign(pSymbolSuffix, pSuffixMgr);
}

//-----------------------------------------------------------------------------
// SuffixMgrMap
//-----------------------------------------------------------------------------
SuffixMgrMap::~SuffixMgrMap()
{
	foreach (SuffixMgrMap, iter, *this) {
		delete iter->second;
	}
}

void SuffixMgrMap::Assign(const Symbol *pSymbolSuffix, SuffixMgr *pSuffixMgr)
{
	iterator iter = find(pSymbolSuffix);
	if (iter == end()) {
		(*this)[pSymbolSuffix] = pSuffixMgr;
	} else {
		delete iter->second;
		iter->second = pSuffixMgr;
	}
}

SuffixMgr *SuffixMgrMap::Lookup(const Symbol *pSymbolSuffix)
{
	iterator iter = find(pSymbolSuffix);
	return (iter == end())? NULL : iter->second;
}


}
