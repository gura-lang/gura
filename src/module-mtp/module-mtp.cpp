//=============================================================================
// Gura module: mtp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(mtp)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// mtp.test():void
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"MTP Test\n");
}

Gura_ImplementFunction(test)
{
	LIBMTP_raw_device_t *rawdevices;
	int numrawdevices;
	::LIBMTP_Init();

	LIBMTP_error_number_t err = ::LIBMTP_Detect_Raw_Devices(&rawdevices, &numrawdevices);
	::free(rawdevices);
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
	// Assignment of function
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(mtp, mtp)

Gura_RegisterModule(mtp)
