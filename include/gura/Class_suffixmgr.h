//=============================================================================
// Gura class: suffixmgr
//=============================================================================
#ifndef __GURA_CLASS_SUFFIXMGR_H__
#define __GURA_CLASS_SUFFIXMGR_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_suffixmgr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_suffixmgr : public Class {
public:
	Class_suffixmgr(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
};

//-----------------------------------------------------------------------------
// Object_suffixmgr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_suffixmgr : public Object {
public:
	Gura_DeclareObjectAccessor(suffixmgr)
private:
	SuffixMgrMap &_suffixMgrMap;
public:
	Object_suffixmgr(Environment &env, SuffixMgrMap &suffixMgrMap);
	Object_suffixmgr(Class *pClass, SuffixMgrMap &suffixMgrMap);
	inline SuffixMgrMap &GetSuffixMgrMap() { return _suffixMgrMap; }
	inline const SuffixMgrMap &GetSuffixMgrMap() const { return _suffixMgrMap; }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
