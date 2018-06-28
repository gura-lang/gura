//=============================================================================
// Gura class: mtp.device
//=============================================================================
#ifndef __GURA_MODULE_MTP_CLASS_DEVICE_H__
#define __GURA_MODULE_MTP_CLASS_DEVICE_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Declaration of Object_device
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(device);

class Object_device : public Object {
public:
	Gura_DeclareObjectAccessor(device)
public:
	Object_device();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(mtp)

#endif
