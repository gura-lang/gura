//=============================================================================
// Platform_msw
//=============================================================================
#ifndef __GURA_MODULE_MTP_PLATFORM_MSW_H__
#define __GURA_MODULE_MTP_PLATFORM_MSW_H__
#include <gura.h>
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
public:
	Gura_DeclareReferenceAccessor(Device);
public:
	Device(LPCWSTR deviceID);
protected:
	inline ~Device() {}
public:
	bool Open(Signal &sig);
	LPCWSTR GetDeviceID() const { return _deviceID.c_str(); }
	inline void SetFriendlyName(const String &friendlyName) { _friendlyName = friendlyName; }
	inline void SetManufacturer(const String &manufacturer) { _manufacturer = manufacturer; }
	inline void SetDescription(const String &description) { _description = description; }
	inline const char *GetFriendlyName() const { return _friendlyName.c_str(); }
	inline const char *GetManufacturer() const { return _manufacturer.c_str(); }
	inline const char *GetDescription() const { return _description.c_str(); }
	static bool Enumerate(Signal &sig, DeviceOwner &deviceOwner);
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
};

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
String WSTRToString(LPCWSTR wstr);
String HRESULTToString(HRESULT hr);

Gura_EndModuleScope(mtp)

#endif
