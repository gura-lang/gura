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
	virtual void DoPrepare(Environment &env);
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
	virtual String ToString(bool exprFlag);
};

}

#endif
