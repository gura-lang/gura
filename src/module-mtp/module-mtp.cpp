//=============================================================================
// Gura module: mtp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(mtp)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// mtp.detect_devices() {block?}
Gura_DeclareFunction(detect_devices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Detects MTP devices and returns a list of `mtp.device` instances.\n");
}

Gura_ImplementFunction(detect_devices)
{
	DeviceOwner deviceOwner;
	if (!deviceOwner.EnumerateDevices(env)) return Value::Nil;
	Value valueRtn;
	Object_list *pObjList = valueRtn.InitAsList(env);
	foreach_const (DeviceOwner, ppDevice, deviceOwner) {
		Device *pDevice = *ppDevice;
		pObjList->Add(Value(new Object_device(pDevice->Reference())));
	}
	return ReturnValue(env, arg, valueRtn);
}

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
	DeviceOwner deviceOwner;
	if (!deviceOwner.EnumerateDevices(env)) return Value::Nil;
	foreach (DeviceOwner, ppDevice, deviceOwner) {
		Device *pDevice = *ppDevice;
		::printf("friendlyName: %s\n", pDevice->GetFriendlyName());
		::printf("manufacturer: %s\n", pDevice->GetManufacturer());
		::printf("description:  %s\n", pDevice->GetDescription());
		StorageOwner storageOwner;
		if (!storageOwner.EnumerateStorages(env, pDevice)) return Value::Nil;
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
	if (!InitPlatform()) return false;
	// Realization of symbol
	Gura_RealizeUserSymbol(Undefined);
	Gura_RealizeUserSymbol(FixedROM);
	Gura_RealizeUserSymbol(RemovableROM);
	Gura_RealizeUserSymbol(FixedRAM);
	Gura_RealizeUserSymbol(RemovableRAM);
	Gura_RealizeUserSymbol(GenericFlat);
	Gura_RealizeUserSymbol(GenericHierarchical);
	Gura_RealizeUserSymbol(DCF);
	Gura_RealizeUserSymbol(ReadWrite);
	Gura_RealizeUserSymbol(ReadOnly);
	Gura_RealizeUserSymbol(ReadOnlyWithObjectDeletion);
	// Realization of class
	Gura_RealizeAndPrepareUserClass(device, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(storage, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(stat, env.LookupClass(VTYPE_object));
 	// Assignment of function
	Gura_AssignFunction(detect_devices);
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
	//::CoUninitialize();
}

Gura_EndModuleBody(mtp, mtp)

Gura_RegisterModule(mtp)
