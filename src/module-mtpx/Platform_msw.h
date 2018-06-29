//=============================================================================
// Platform_msw
//=============================================================================
#ifndef __GURA_MODULE_MTP_PLATFORM_MSW_H__
#define __GURA_MODULE_MTP_PLATFORM_MSW_H__
#include <gura.h>
#include <PortableDeviceApi.h>	// Windows Portable Device API interfaces
#include <PortableDevice.h>		// Windows Portable Device definitions
#include <wrl/client.h>

using namespace Microsoft::WRL;

Gura_BeginModuleScope(mtp)

class DeviceList;
class DeviceOwner;

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
class Device {
private:
	int _cntRef;
	std::basic_string<WCHAR> _deviceID;
	String _friendlyName;
	String _manufacturer;
	String _description;
	ComPtr<IPortableDevice> _pPortableDevice;
	ComPtr<IPortableDeviceContent> _pPortableDeviceContent;
public:
	Gura_DeclareReferenceAccessor(Device);
public:
	Device(LPCWSTR deviceID);
protected:
	inline ~Device() {}
public:
	bool Open(Signal &sig);
	inline LPCWSTR GetDeviceID() const { return _deviceID.c_str(); }
	inline IPortableDevice *GetPortableDevice() { return _pPortableDevice.Get(); }
	inline IPortableDeviceContent *GetPortableDeviceContent() { return _pPortableDeviceContent.Get(); }
	inline void SetFriendlyName(const String &friendlyName) { _friendlyName = friendlyName; }
	inline void SetManufacturer(const String &manufacturer) { _manufacturer = manufacturer; }
	inline void SetDescription(const String &description) { _description = description; }
	inline const char *GetFriendlyName() const { return _friendlyName.c_str(); }
	inline const char *GetManufacturer() const { return _manufacturer.c_str(); }
	inline const char *GetDescription() const { return _description.c_str(); }
};

//-----------------------------------------------------------------------------
// DeviceList
//-----------------------------------------------------------------------------
class DeviceList : public std::vector<Device *> {
};

//-----------------------------------------------------------------------------
// DeviceOwner
//-----------------------------------------------------------------------------
class DeviceOwner : public DeviceList {
public:
	~DeviceOwner();
	void Clear();
	bool EnumerateDevices(Signal &sig);
};

//-----------------------------------------------------------------------------
// Storage
//-----------------------------------------------------------------------------
class Storage {
private:
	int _cntRef;
	AutoPtr<Device> _pDevice;
	std::basic_string<WCHAR> _objectID;
	uint16_t _storageType;			// Storage type
	uint16_t _filesystemType;		// Filesystem type
	uint16_t _accessCapability;		// Access capability
	uint64_t _maxCapacity;			// Maximum capability
	uint64_t _freeSpaceInBytes;		// Free space in bytes
	uint64_t _freeSpaceInObjects;	// Free space in objects
	String _storageDescription;		// A brief description of this storage 
	String _volumeIdentifier;		// A volume identifier
	//ComPtr<IEnumPortableDeviceObjectIDs> _pEnumPortableDeviceObjectIDs;
public:
	Gura_DeclareReferenceAccessor(Storage);
public:
	Storage(Device *pDevice, LPCWSTR objectID);
protected:
	inline ~Storage() {}
public:
	//bool Open(Signal &sig);
	inline LPCWSTR GetObjectID() const { return _objectID.c_str(); }
	//inline IEnumPortableDeviceObjectIDs *GetEnumPortableDeviceObjectIDs() {
	//	return _pEnumPortableDeviceObjectIDs.Get();
	//}
};

//-----------------------------------------------------------------------------
// StorageList
//-----------------------------------------------------------------------------
class StorageList : public std::vector<Storage *> {
};

//-----------------------------------------------------------------------------
// StorageOwner
//-----------------------------------------------------------------------------
class StorageOwner : public StorageList {
public:
	~StorageOwner();
	void Clear();
	bool EnumerateStorages(Signal &sig, Device *pDevice);
};

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
String WSTRToString(LPCWSTR wstr);
String HRESULTToString(HRESULT hr);
bool CatchErr(Signal &sig, HRESULT hr);

Gura_EndModuleScope(mtp)

#endif
