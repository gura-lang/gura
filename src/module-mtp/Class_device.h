#ifndef __MTP_CLASS_DEVICE_H__
#define __MTP_CLASS_DEVICE_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
class Device {
private:
	int _cntRef;
	LIBMTP_mtpdevice_t *_mtpDevice;
public:
	Gura_DeclareReferenceAccessor(Device);
public:
	Device(LIBMTP_mtpdevice_t *mtpDevice);
protected:
	~Device();
public:
	const char *GetFriendlyName() const;
};

//-----------------------------------------------------------------------------
// Object_device declaration
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
};

Gura_EndModuleScope(mtp)

#endif
