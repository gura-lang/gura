#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
Device::Device(LPCWSTR deviceID) : _cntRef(1), _deviceID(deviceID)
{
}

bool Device::Open(Signal &sig)
{
	HRESULT hr;
	hr = ::CoCreateInstance(CLSID_PortableDeviceFTM, nullptr,
				CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&_pPortableDevice));
	if (FAILED(hr)) {
		sig.SetError(ERR_RuntimeError, "failed to get interface of PortableDeviceFTM");
		return false;
	}
	hr = _pPortableDevice->Open(_deviceID.c_str(), nullptr);
	//pnpDeviceIDs[currentDeviceIndex], clientInformation.Get());
	if (FAILED(hr)) {
		sig.SetError(ERR_RuntimeError, "failed to open device");
		return false;
	}
	return true;
}

bool Device::Enumerate(Signal &sig, DeviceOwner &deviceOwner)
{
	HRESULT hr;
	std::unique_ptr<LPWSTR []> deviceIDs;
	ComPtr<IPortableDeviceManager> pPortableDeviceManager;
	hr = ::CoCreateInstance(CLSID_PortableDeviceManager, nullptr,
				CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceManager));
	if (FAILED(hr)) goto error_done;
	DWORD nDeviceIDs = 0;
	hr = pPortableDeviceManager->GetDevices(nullptr, &nDeviceIDs);
	if (FAILED(hr)) goto error_done;
	deviceIDs.reset(new LPWSTR[nDeviceIDs]);
	hr = pPortableDeviceManager->GetDevices(deviceIDs.get(), &nDeviceIDs);
	if (FAILED(hr)) goto error_done;
	for (DWORD i = 0; i < nDeviceIDs; i++) {
		LPWSTR deviceID = deviceIDs[i];
		deviceOwner.push_back(new Device(deviceID));
		do {
			DWORD len = 0;
			hr = pPortableDeviceManager->GetDeviceFriendlyName(deviceID, nullptr, &len);
			if (FAILED(hr)) goto error_done;
			std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
			hr = pPortableDeviceManager->GetDeviceFriendlyName(deviceID, wstr.get(), &len);
			if (FAILED(hr)) goto error_done;
			//friendlyName = WSTRToString(wstr.get());
		} while (0);
		
		
		::CoTaskMemFree(deviceID);
	}
	return true;
error_done:
	sig.SetError(ERR_RuntimeError, "%s", HRESULTToString(hr).c_str());
	return false;
}

//-----------------------------------------------------------------------------
// DeviceOwner
//-----------------------------------------------------------------------------
DeviceOwner::~DeviceOwner()
{
	Clear();
}

void DeviceOwner::Clear()
{
	foreach (DeviceOwner, ppDevice, *this) {
		Device *pDevice = *ppDevice;
		Device::Delete(pDevice);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
String WSTRToString(LPCWSTR wstr)
{
	// cnt includes null-terminater
	int cnt = ::WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
	char *psz = new char [cnt + 1];
	::WideCharToMultiByte(CP_UTF8, 0, wstr, -1, psz, cnt, nullptr, nullptr);
	psz[cnt] = '\0';
	return String(psz);
}

String HRESULTToString(HRESULT hr)
{
	String rtn;
	LPWSTR wstr;
	::FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
				nullptr, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				reinterpret_cast<LPTSTR>(&wstr), 0, nullptr);
	if (wstr != nullptr) rtn = WSTRToString(wstr);
	::LocalFree(wstr);
	return rtn;
}

Gura_EndModuleScope(mtp)
