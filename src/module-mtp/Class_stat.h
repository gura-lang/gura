//=============================================================================
// Gura class: mtp.stat
//=============================================================================
#ifndef __GURA_MODULE_MTP_CLASS_STAT_H__
#define __GURA_MODULE_MTP_CLASS_STAT_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Declaration of Object_stat
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(stat);

class Object_stat : public Object {
private:
	AutoPtr<Stat> _pStat;
public:
	Gura_DeclareObjectAccessor(stat)
public:
	Object_stat(Stat *pStat);
	virtual String ToString(bool exprFlag);
	inline const Stat *GetStat() const { return _pStat.get(); }
};

Gura_EndModuleScope(mtp)

#endif
