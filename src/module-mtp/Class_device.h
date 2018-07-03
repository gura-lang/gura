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
private:
	AutoPtr<Device> _pDevice;
public:
	Gura_DeclareObjectAccessor(device)
public:
	Object_device(Device *pDevice);
	virtual String ToString(bool exprFlag);
	inline Device *GetDevice() { return _pDevice.get(); }
	inline const Device *GetDevice() const { return _pDevice.get(); }
};

Gura_EndModuleScope(mtp)

#endif
