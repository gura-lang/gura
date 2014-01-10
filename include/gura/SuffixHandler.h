//=============================================================================
// SuffixHandler
//=============================================================================
#ifndef __GURA_SUFFIXHANDLER_H__
#define __GURA_SUFFIXHANDLER_H__

#include "Common.h"
#include "Signal.h"

namespace Gura {

class Environment;

//-----------------------------------------------------------------------------
// SuffixHandler
//-----------------------------------------------------------------------------
class SuffixHandler {
public:
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const = 0;
	static SuffixHandler *LookupForString(Environment &env, const Symbol *pSymbolSuffix);
	static SuffixHandler *LookupForNumber(Environment &env, const Symbol *pSymbolSuffix);
	static void RegisterForString(Environment &env,
				const Symbol *pSymbolSuffix, SuffixHandler *pSuffixHandler);
	static void RegisterForNumber(Environment &env,
				const Symbol *pSymbolSuffix, SuffixHandler *pSuffixHandler);
};

//-----------------------------------------------------------------------------
// SuffixHandlerMap
//-----------------------------------------------------------------------------
class SuffixHandlerMap : public std::map<const Symbol *,
							SuffixHandler *, Symbol::KeyCompare_UniqNumber> {
public:
	~SuffixHandlerMap();
	void Register(const Symbol *pSymbolSuffix, SuffixHandler *pSuffixHandler);
	SuffixHandler *Lookup(const Symbol *pSymbolSuffix);
};

}
#endif
