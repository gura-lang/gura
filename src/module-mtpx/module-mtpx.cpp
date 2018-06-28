//=============================================================================
// Gura module: mtpx
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(mtpx)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// mtpx.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"\n");
}

Gura_ImplementFunction(test)
{
	HRESULT hr;
	//ComPtr<IPortableDevice> pPortableDevice;
	do {
		ComPtr<IPortableDeviceValues> pPortableDeviceValues;
		hr = ::CoCreateInstance(CLSID_PortableDeviceValues,
					nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceValues));
		if (FAILED(hr)) {
			env.SetError(ERR_RuntimeError, "failed to get interface of PortableDeviceValues");
			goto error_done;
		}
		hr = pPortableDeviceValues->SetStringValue(WPD_CLIENT_NAME, L"Gura mtp Module");
		if (FAILED(hr)) goto error_done;
		hr = pPortableDeviceValues->SetUnsignedIntegerValue(WPD_CLIENT_MAJOR_VERSION, GURA_VERSION_MAJOR);
		if (FAILED(hr)) goto error_done;
		hr = pPortableDeviceValues->SetUnsignedIntegerValue(WPD_CLIENT_MINOR_VERSION, GURA_VERSION_MINOR);
		if (FAILED(hr)) goto error_done;
		hr = pPortableDeviceValues->SetUnsignedIntegerValue(WPD_CLIENT_REVISION, GURA_VERSION_PATCH);
		if (FAILED(hr)) goto error_done;
	} while (0);
	do {
		ComPtr<IPortableDeviceManager> pPortableDeviceManager;
		hr = ::CoCreateInstance(CLSID_PortableDeviceManager,
					nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceManager));
		if (FAILED(hr)) {
			env.SetError(ERR_RuntimeError, "failed to get interface of PortableDeviceManager");
			goto error_done;
		}
		DWORD nDeviceIDs = 0;
		hr = pPortableDeviceManager->GetDevices(nullptr, &nDeviceIDs);
		if (FAILED(hr)) goto error_done;
		std::unique_ptr<LPWSTR []> deviceIDs(new LPWSTR[nDeviceIDs]);
		hr = pPortableDeviceManager->GetDevices(deviceIDs.get(), &nDeviceIDs);
		if (FAILED(hr)) goto error_done;
		for (DWORD i = 0; i < nDeviceIDs; i++) {
			LPWSTR deviceID = deviceIDs[i];
			String friendlyName;
			String manufacturer;
			String description;
			do {
				DWORD len = 0;
				hr = pPortableDeviceManager->GetDeviceFriendlyName(deviceID, nullptr, &len);
				if (FAILED(hr)) goto error_done;
				std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
				hr = pPortableDeviceManager->GetDeviceFriendlyName(deviceID, wstr.get(), &len);
				if (FAILED(hr)) goto error_done;
				friendlyName = WSTRToString(wstr.get());
			} while (0);
			do {
				DWORD len = 0;
				hr = pPortableDeviceManager->GetDeviceManufacturer(deviceID, nullptr, &len);
				if (FAILED(hr)) goto error_done;
				std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
				hr = pPortableDeviceManager->GetDeviceManufacturer(deviceID, wstr.get(), &len);
				if (FAILED(hr)) goto error_done;
				manufacturer = WSTRToString(wstr.get());
			} while (0);
			do {
				DWORD len = 0;
				hr = pPortableDeviceManager->GetDeviceDescription(deviceID, nullptr, &len);
				if (FAILED(hr)) goto error_done;
				std::unique_ptr<WCHAR []> wstr(new WCHAR[len]);	// len contains terminal null.
				hr = pPortableDeviceManager->GetDeviceDescription(deviceID, wstr.get(), &len);
				if (FAILED(hr)) goto error_done;
				description = WSTRToString(wstr.get());
			} while (0);
			::printf("friendlyName: %s\n", friendlyName.c_str());
			::printf("manufacturer: %s\n", manufacturer.c_str());
			::printf("description:  %s\n", description.c_str());
		}
		for (DWORD i = 0; i < nDeviceIDs; i++) {
			::CoTaskMemFree(deviceIDs[i]);
		}
	} while (0);
	return Value::Nil;
error_done:
	env.SetError(ERR_RuntimeError, "error while calling COM function");
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entry
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	HRESULT hr = ::CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (FAILED(hr)) return false;
 	// Assignment of function
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
	//::CoUninitialize();
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

Gura_EndModuleBody(mtpx, mtpx)

Gura_RegisterModule(mtpx)
