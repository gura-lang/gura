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
	ComPtr<IPortableDeviceValues> pPortableDeviceValues;
	ComPtr<IPortableDeviceManager> pPortableDeviceManager;
	ComPtr<IPortableDevice> pPortableDevice = nullptr;
	
	hr = ::CoCreateInstance(CLSID_PortableDeviceValues,
				nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceValues));
	if (FAILED(hr)) {
		env.SetError(ERR_RuntimeError, "failed to get interface of PortableDeviceValues");
		return Value::Nil;
	}

	hr = ::CoCreateInstance(CLSID_PortableDeviceManager,
				nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pPortableDeviceManager));
	if (FAILED(hr)) {
		env.SetError(ERR_RuntimeError, "failed to get interface of PortableDeviceManager");
		return Value::Nil;
	}
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

Gura_EndModuleBody(mtpx, mtpx)

Gura_RegisterModule(mtpx)
