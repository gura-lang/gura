//=============================================================================
// SuffixMgr
//=============================================================================
#ifndef __GURA_SUFFIXMGR_H__
#define __GURA_SUFFIXMGR_H__

#include "Common.h"
#include "Signal.h"

#define Gura_ImplementSuffixMgrForNumber(suffix)								\
class SuffixMgr_Number_##suffix : public SuffixMgr {						\
public:																				\
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const;		\
};																					\
Value SuffixMgr_Number_##suffix::DoEval(Environment &env, Signal sig, const char *body) const

#define Gura_ImplementSuffixMgrForString(suffix)								\
class SuffixMgr_String_##suffix : public SuffixMgr {						\
public:																				\
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const;		\
};																					\
Value SuffixMgr_String_##suffix::DoEval(Environment &env, Signal sig, const char *body) const

#define Gura_AssignSuffixMgrForNumber(suffix)									\
SuffixMgr::AssignForNumber(env, Symbol::Add(#suffix), new SuffixMgr_Number_##suffix());

#define Gura_AssignSuffixMgrForString(suffix)									\
SuffixMgr::AssignForString(env, Symbol::Add(#suffix), new SuffixMgr_String_##suffix());

namespace Gura {

class Environment;

//-----------------------------------------------------------------------------
// SuffixMgr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SuffixMgr {
public:
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const = 0;
	static SuffixMgr *LookupForString(Environment &env, const Symbol *pSymbolSuffix);
	static SuffixMgr *LookupForNumber(Environment &env, const Symbol *pSymbolSuffix);
	static void AssignForString(Environment &env,
				const Symbol *pSymbolSuffix, SuffixMgr *pSuffixMgr);
	static void AssignForNumber(Environment &env,
				const Symbol *pSymbolSuffix, SuffixMgr *pSuffixMgr);
};

//-----------------------------------------------------------------------------
// SuffixMgrCustom
//-----------------------------------------------------------------------------
class SuffixMgrCustom : public SuffixMgr {
private:
	AutoPtr<Function> _pFunc;
public:
	inline SuffixMgrCustom(Function *pFunc) : _pFunc(pFunc) {}
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const;
};

//-----------------------------------------------------------------------------
// SuffixMgrMap
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SuffixMgrMap : public std::map<const Symbol *,
							SuffixMgr *, Symbol::KeyCompare_UniqNumber> {
public:
	~SuffixMgrMap();
	void Assign(const Symbol *pSymbolSuffix, SuffixMgr *pSuffixMgr);
	SuffixMgr *Lookup(const Symbol *pSymbolSuffix);
};

}
#endif
