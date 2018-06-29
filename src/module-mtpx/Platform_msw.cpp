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
	if (FailedHRESULT(sig, hr)) return false;
	hr = _pPortableDevice->Open(_deviceID.c_str(), nullptr);
	//pnpDeviceIDs[currentDeviceIndex], clientInformation.Get());
	if (FailedHRESULT(sig, hr)) return false;
	return true;
}

bool Device::Enumerate(Signal &sig, DeviceOwner &deviceOwner)
{
	HRESULT hr;
	ComPtr<IPortableDeviceManager> pPortableDeviceManager;
	hr = ::CoCreateInstance(CLSID_PortableDeviceManager, nullptr,
				CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceManager));
	if (FailedHRESULT(sig, hr)) return false;
	DWORD nDeviceIDs = 0;
	hr = pPortableDeviceManager->GetDevices(nullptr, &nDeviceIDs);
	if (FailedHRESULT(sig, hr)) return false;
	std::unique_ptr<LPWSTR []> deviceIDs(new LPWSTR[nDeviceIDs]);
	hr = pPortableDeviceManager->GetDevices(deviceIDs.get(), &nDeviceIDs);
	if (FailedHRESULT(sig, hr)) return false;
	for (DWORD i = 0; i < nDeviceIDs; i++) {
		LPWSTR deviceID = deviceIDs[i];
		Device *pDevice = new Device(deviceID);
		deviceOwner.push_back(pDevice);
		::CoTaskMemFree(deviceID);
		do {
			DWORD len = 0;
			hr = pPortableDeviceManager->GetDeviceFriendlyName(pDevice->GetDeviceID(), nullptr, &len);
			if (FailedHRESULT(sig, hr)) return false;
			std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
			hr = pPortableDeviceManager->GetDeviceFriendlyName(pDevice->GetDeviceID(), wstr.get(), &len);
			if (FailedHRESULT(sig, hr)) return false;
			pDevice->SetFriendlyName(WSTRToString(wstr.get()));
		} while (0);
		do {
			DWORD len = 0;
			hr = pPortableDeviceManager->GetDeviceManufacturer(pDevice->GetDeviceID(), nullptr, &len);
			if (FailedHRESULT(sig, hr)) return false;
			std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
			hr = pPortableDeviceManager->GetDeviceManufacturer(pDevice->GetDeviceID(), wstr.get(), &len);
			if (FailedHRESULT(sig, hr)) return false;
			pDevice->SetManufacturer(WSTRToString(wstr.get()));
		} while (0);
		do {
			DWORD len = 0;
			hr = pPortableDeviceManager->GetDeviceDescription(pDevice->GetDeviceID(), nullptr, &len);
			if (FailedHRESULT(sig, hr)) return false;
			std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
			hr = pPortableDeviceManager->GetDeviceDescription(pDevice->GetDeviceID(), wstr.get(), &len);
			if (FailedHRESULT(sig, hr)) return false;
			pDevice->SetDescription(WSTRToString(wstr.get()));
		} while (0);
	}
	return true;
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

bool FailedHRESULT(Signal &sig, HRESULT hr)
{
	if (FAILED(hr)) {
		sig.SetError(ERR_RuntimeError, "%s", HRESULTToString(hr).c_str());
		return true;
	}
	return false;
}

Gura_EndModuleScope(mtp)
