//=============================================================================
// Gura module: mtpx
//=============================================================================
#ifndef __GURA_MODULE_MTPX_H__
#define __GURA_MODULE_MTPX_H__
#include <gura.h>
#include <PortableDeviceApi.h>	// Windows Portable Device API interfaces
#include <PortableDevice.h>		// Windows Portable Device definitions
#include <wrl/client.h>
using namespace Microsoft::WRL;

Gura_BeginModuleHeader(mtpx)

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
String WSTRToString(LPCWSTR wstr);

Gura_EndModuleHeader(mtpx)

#endif
