//=============================================================================
// Gura class: mtp.device
//=============================================================================
#ifndef __GURA_MODULE_MTP_CLASS_DEVICE_H__
#define __GURA_MODULE_MTP_CLASS_DEVICE_H__
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
	void LookupStorages(Object_list *pObjList) const;
	Directory *GenerateDirectory(Signal &sig, uint32_t storageId, const char *pathName) const;
	inline LIBMTP_mtpdevice_t *GetMtpDevice() const { return _mtpDevice; }
	inline const char *GetManufacturerName() const { return ::LIBMTP_Get_Manufacturername(_mtpDevice); }
	inline const char *GetModelName() const { return ::LIBMTP_Get_Modelname(_mtpDevice); }
	inline const char *GetSerialNumber() const { return ::LIBMTP_Get_Serialnumber(_mtpDevice); }
	inline const char *GetDeviceVersion() const { return ::LIBMTP_Get_Deviceversion(_mtpDevice); }
	inline const char *GetFriendlyName() const { return ::LIBMTP_Get_Friendlyname(_mtpDevice); }
	inline const char *GetSyncPartner() const { return ::LIBMTP_Get_Syncpartner(_mtpDevice); }
	inline int GetBatteryLevel() const {
		//int LIBMTP_Get_Batterylevel(LIBMTP_mtpdevice_t *, uint8_t * const, uint8_t * const);
		return 0;
	}
	inline int GetSecureTime() const {
		//int LIBMTP_Get_Secure_Time(LIBMTP_mtpdevice_t *, char ** const);
		return 0;
	}
	inline int GetDeviceCertificate() const {
		//int LIBMTP_Get_Device_Certificate(LIBMTP_mtpdevice_t *, char ** const);
		return 0;
	}
	inline int GetSupportedFileTypes() const {
		//int LIBMTP_Get_Supported_Filetypes(LIBMTP_mtpdevice_t *, uint16_t ** const, uint16_t * const);
		return 0;
	}
	//int LIBMTP_Set_Friendlyname(LIBMTP_mtpdevice_t*, char const * const);
	//int LIBMTP_Set_Syncpartner(LIBMTP_mtpdevice_t*, char const * const);
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
	inline const Device *GetDevice() const { return _pDevice.get(); }
};

Gura_EndModuleScope(mtp)

#endif
