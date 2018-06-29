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
public:
	Gura_DeclareObjectAccessor(stat)
public:
	Object_stat();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(mtp)

#endif
