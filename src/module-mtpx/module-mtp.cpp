//=============================================================================
// Gura module: mtp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(mtp)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// mtp.test()
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
	do {
		ComPtr<IPortableDeviceValues> pPortableDeviceValues;
		hr = ::CoCreateInstance(CLSID_PortableDeviceValues, nullptr,
					CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceValues));
		if (FAILED(hr)) {
			env.SetError(ERR_RuntimeError, "failed to get interface of PortableDeviceValues");
			return Value::Nil;
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
		hr = ::CoCreateInstance(CLSID_PortableDeviceManager, nullptr,
					CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceManager));
		if (FAILED(hr)) {
			env.SetError(ERR_RuntimeError, "failed to get interface of PortableDeviceManager");
			return Value::Nil;
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
	do {
		ComPtr<IPortableDevice> pPortableDevice;
		hr = CoCreateInstance(CLSID_PortableDeviceFTM, nullptr,
					CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDevice));
		if (FAILED(hr)) {
			env.SetError(ERR_RuntimeError, "failed to get interface of PortableDeviceFTM");
			return Value::Nil;
		}
		hr = pPortableDevice->Open(nullptr, nullptr); //pnpDeviceIDs[currentDeviceIndex], clientInformation.Get());
		
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

Gura_EndModuleBody(mtp, mtp)

Gura_RegisterModule(mtp)
