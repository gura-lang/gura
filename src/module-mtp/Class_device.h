#ifndef __MTP_CLASS_DEVICE_H__
#define __MTP_CLASS_DEVICE_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Object_device declaration
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
