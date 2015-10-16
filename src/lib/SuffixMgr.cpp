//=============================================================================
// SuffixMgr
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// SuffixMgrEntry
//-----------------------------------------------------------------------------
SuffixMgrEntry::~SuffixMgrEntry()
{
}

//-----------------------------------------------------------------------------
// SuffixMgrEntryCustom
//-----------------------------------------------------------------------------
Value SuffixMgrEntryCustom::DoEval(Environment &env, const char *body) const
{
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->StoreValue(env, Value(body))) return Value::Nil;
	return _pFunc->Eval(env, *pArg);
}

//-----------------------------------------------------------------------------
// SuffixMgr
//-----------------------------------------------------------------------------
SuffixMgr::~SuffixMgr()
{
	foreach (Map, iter, _map) {
		delete iter->second;
	}
}

void SuffixMgr::Assign(const Symbol *pSymbolSuffix, SuffixMgrEntry *pSuffixMgrEntry)
{
	Map::iterator iter = _map.find(pSymbolSuffix);
	if (iter == _map.end()) {
		_map[pSymbolSuffix] = pSuffixMgrEntry;
	} else {
		delete iter->second;
		iter->second = pSuffixMgrEntry;
	}
}

SuffixMgrEntry *SuffixMgr::Lookup(const Symbol *pSymbolSuffix)
{
	Map::iterator iter = _map.find(pSymbolSuffix);
	return (iter == _map.end())? nullptr : iter->second;
}

SuffixMgrEntry *SuffixMgr::LookupForString(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixMgrForString().Lookup(pSymbolSuffix);
}

SuffixMgrEntry *SuffixMgr::LookupForNumber(Environment &env, const Symbol *pSymbolSuffix)
{
	return env.GetGlobal()->GetSuffixMgrForNumber().Lookup(pSymbolSuffix);
}

void SuffixMgr::AssignForString(Environment &env,
				const Symbol *pSymbolSuffix, SuffixMgrEntry *pSuffixMgrEntry)
{
	env.GetGlobal()->GetSuffixMgrForString().Assign(pSymbolSuffix, pSuffixMgrEntry);
}

void SuffixMgr::AssignForNumber(Environment &env,
				const Symbol *pSymbolSuffix, SuffixMgrEntry *pSuffixMgrEntry)
{
	env.GetGlobal()->GetSuffixMgrForNumber().Assign(pSymbolSuffix, pSuffixMgrEntry);
}

}
