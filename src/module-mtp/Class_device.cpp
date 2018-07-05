//=============================================================================
// Gura class: mtp.device
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Implementation of Object_device
//-----------------------------------------------------------------------------
Object_device::Object_device(Device *pDevice) : Object(Gura_UserClass(device)), _pDevice(pDevice)
{
}

String Object_device::ToString(bool exprFlag)
{
	String rtn = "<mtp.device:";
	rtn += _pDevice->GetFriendlyName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of property
//-----------------------------------------------------------------------------
// mtp.device#friendlyname
Gura_DeclareProperty_R(device, friendlyname)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"Friendly name."
		);
}

Gura_ImplementPropertyGetter(device, friendlyname)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	return Value(pDevice->GetFriendlyName());
}

// mtp.device#manufacturer
Gura_DeclareProperty_R(device, manufacturer)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"Manufacturer name."
		);
}

Gura_ImplementPropertyGetter(device, manufacturer)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	return Value(pDevice->GetManufacturer());
}

// mtp.device#storages
Gura_DeclareProperty_R(device, storages)
{
	SetPropAttr(VTYPE_list);
	AddHelp(
		Gura_Symbol(en),
		"Returns a list of `mtp.storage` instances."
		);
}

Gura_ImplementPropertyGetter(device, storages)
{
	Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	StorageOwner storageOwner;
	if (!storageOwner.EnumerateStorages(env, pDevice)) return Value::Nil;
	Value valueRtn;
	Object_list *pObjList = valueRtn.InitAsList(env);
	foreach_const (StorageOwner, ppStorage, storageOwner) {
		Storage *pStorage = *ppStorage;
		pObjList->Add(Value(new Object_storage(pStorage->Reference())));
	}
	return valueRtn;
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class mtp.device
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(device)
{
	// Assignment of property
	Gura_AssignProperty(device, friendlyname);
	Gura_AssignProperty(device, manufacturer);
	Gura_AssignProperty(device, storages);
	// Assignment of method
	// Assignment of value
	Gura_AssignValue(device, Value(Reference()));
}

Gura_EndModuleScope(mtp)
