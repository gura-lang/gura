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
	SuffixMgr &_suffixMgr;
public:
	Object_suffixmgr(Environment &env, SuffixMgr &suffixMgr);
	Object_suffixmgr(Class *pClass, SuffixMgr &suffixMgr);
	inline SuffixMgr &GetSuffixMgr() { return _suffixMgr; }
	inline const SuffixMgr &GetSuffixMgr() const { return _suffixMgr; }
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
