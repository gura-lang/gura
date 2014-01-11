//=============================================================================
// SuffixManager
//=============================================================================
#ifndef __GURA_SUFFIXMANAGER_H__
#define __GURA_SUFFIXMANAGER_H__

#include "Common.h"
#include "Signal.h"

#define Gura_ImplementSuffixManagerForNumber(suffix)								\
class SuffixManager_Number_##suffix : public SuffixManager {						\
public:																				\
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const;		\
};																					\
Value SuffixManager_Number_##suffix::DoEval(Environment &env, Signal sig, const char *body) const

#define Gura_ImplementSuffixManagerForString(suffix)								\
class SuffixManager_String_##suffix : public SuffixManager {						\
public:																				\
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const;		\
};																					\
Value SuffixManager_String_##suffix::DoEval(Environment &env, Signal sig, const char *body) const

#define Gura_RegisterSuffixManagerForNumber(suffix)									\
SuffixManager::RegisterForNumber(env, Symbol::Add(#suffix), new SuffixManager_Number_##suffix());

#define Gura_RegisterSuffixManagerForString(suffix)									\
SuffixManager::RegisterForString(env, Symbol::Add(#suffix), new SuffixManager_String_##suffix());

namespace Gura {

class Environment;

//-----------------------------------------------------------------------------
// SuffixManager
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SuffixManager {
public:
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const = 0;
	static SuffixManager *LookupForString(Environment &env, const Symbol *pSymbolSuffix);
	static SuffixManager *LookupForNumber(Environment &env, const Symbol *pSymbolSuffix);
	static void RegisterForString(Environment &env,
				const Symbol *pSymbolSuffix, SuffixManager *pSuffixManager);
	static void RegisterForNumber(Environment &env,
				const Symbol *pSymbolSuffix, SuffixManager *pSuffixManager);
};

//-----------------------------------------------------------------------------
// SuffixManagerMap
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SuffixManagerMap : public std::map<const Symbol *,
							SuffixManager *, Symbol::KeyCompare_UniqNumber> {
public:
	~SuffixManagerMap();
	void Register(const Symbol *pSymbolSuffix, SuffixManager *pSuffixManager);
	SuffixManager *Lookup(const Symbol *pSymbolSuffix);
};

}
#endif
