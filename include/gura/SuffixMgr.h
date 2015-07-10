//=============================================================================
// SuffixMgr
//=============================================================================
#ifndef __GURA_SUFFIXMGR_H__
#define __GURA_SUFFIXMGR_H__

#include "Common.h"
#include "Signal.h"

#define Gura_ImplementSuffixMgrForNumber(suffix)									\
class SuffixMgrEntry_Number_##suffix : public SuffixMgrEntry {						\
public:																				\
	virtual Value DoEval(Environment &env, Signal &sig, const char *body) const;		\
};																					\
Value SuffixMgrEntry_Number_##suffix::DoEval(Environment &env, Signal &sig, const char *body) const

#define Gura_ImplementSuffixMgrForString(suffix)									\
class SuffixMgrEntry_String_##suffix : public SuffixMgrEntry {						\
public:																				\
	virtual Value DoEval(Environment &env, Signal &sig, const char *body) const;		\
};																					\
Value SuffixMgrEntry_String_##suffix::DoEval(Environment &env, Signal &sig, const char *body) const

#define Gura_AssignSuffixMgrForNumber(suffix)										\
SuffixMgr::AssignForNumber(env, Symbol::Add(#suffix), new SuffixMgrEntry_Number_##suffix());

#define Gura_AssignSuffixMgrForString(suffix)										\
SuffixMgr::AssignForString(env, Symbol::Add(#suffix), new SuffixMgrEntry_String_##suffix());

namespace Gura {

class Environment;

//-----------------------------------------------------------------------------
// SuffixMgrEntry
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SuffixMgrEntry {
public:
	virtual ~SuffixMgrEntry();
	virtual Value DoEval(Environment &env, Signal &sig, const char *body) const = 0;
};

//-----------------------------------------------------------------------------
// SuffixMgrEntryCustom
//-----------------------------------------------------------------------------
class SuffixMgrEntryCustom : public SuffixMgrEntry {
private:
	AutoPtr<Function> _pFunc;
public:
	inline SuffixMgrEntryCustom(Function *pFunc) : _pFunc(pFunc) {}
	virtual Value DoEval(Environment &env, Signal &sig, const char *body) const;
};

//-----------------------------------------------------------------------------
// SuffixMgr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SuffixMgr {
public:
	typedef std::map<const Symbol *, SuffixMgrEntry *, Symbol::KeyCompare_UniqNumber> Map;
private:
	Map _map;
public:
	~SuffixMgr();
	void Assign(const Symbol *pSymbolSuffix, SuffixMgrEntry *pSuffixMgrEntry);
	SuffixMgrEntry *Lookup(const Symbol *pSymbolSuffix);
	static SuffixMgrEntry *LookupForString(Environment &env, const Symbol *pSymbolSuffix);
	static SuffixMgrEntry *LookupForNumber(Environment &env, const Symbol *pSymbolSuffix);
	static void AssignForString(Environment &env,
				const Symbol *pSymbolSuffix, SuffixMgrEntry *pSuffixMgrEntry);
	static void AssignForNumber(Environment &env,
				const Symbol *pSymbolSuffix, SuffixMgrEntry *pSuffixMgrEntry);
};

}
#endif
