#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Object_device implementation
//-----------------------------------------------------------------------------
Object_device::Object_device() : Object(Gura_UserClass(device))
{
}

String Object_device::ToString(bool exprFlag)
{
	return String("<mtp.device>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for mtp.device
//-----------------------------------------------------------------------------
// implementation of class device
Gura_ImplementUserClass(device)
{
	// Assignment of value
	Gura_AssignValue(device, Value(Reference()));
}

Gura_EndModuleScope(mtp)
