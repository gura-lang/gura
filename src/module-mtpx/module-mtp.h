//=============================================================================
// Gura module: mtp
//=============================================================================
#ifndef __GURA_MODULE_MTP_H__
#define __GURA_MODULE_MTP_H__
#include <gura.h>
#include <PortableDeviceApi.h>	// Windows Portable Device API interfaces
#include <PortableDevice.h>		// Windows Portable Device definitions
#include <wrl/client.h>
#include "Class_device.h"

using namespace Microsoft::WRL;

Gura_BeginModuleHeader(mtp)

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
String WSTRToString(LPCWSTR wstr);

Gura_EndModuleHeader(mtp)

#endif
