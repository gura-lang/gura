//=============================================================================
// Gura class: mtp.storage
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Implementation of Object_storage
//-----------------------------------------------------------------------------
Object_storage::Object_storage(Storage *pStorage) :
					Object(Gura_UserClass(storage)), _pStorage(pStorage)
{
}

String Object_storage::ToString(bool exprFlag)
{
	String rtn = "<mtp.storage:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of property
//-----------------------------------------------------------------------------
// mtp.storage#storage_type
Gura_DeclareProperty_R(storage, storage_type)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, storage_type)
{
	const Storage *pStorage = Object_storage::GetObject(valueThis)->GetStorage();
	return Value(pStorage->GetStorageType());
}

// mtp.storage#filesystem_type
Gura_DeclareProperty_R(storage, filesystem_type)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, filesystem_type)
{
	const Storage *pStorage = Object_storage::GetObject(valueThis)->GetStorage();
	return Value(pStorage->GetFilesystemType());
}

// mtp.storage#access_capability
Gura_DeclareProperty_R(storage, access_capability)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, access_capability)
{
	const Storage *pStorage = Object_storage::GetObject(valueThis)->GetStorage();
	return Value(pStorage->GetAccessCapability());
}

// mtp.storage#max_capacity
Gura_DeclareProperty_R(storage, max_capacity)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, max_capacity)
{
	const Storage *pStorage = Object_storage::GetObject(valueThis)->GetStorage();
	return Value(pStorage->GetMaxCapacity());
}

// mtp.storage#free_space_in_bytes
Gura_DeclareProperty_R(storage, free_space_in_bytes)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, free_space_in_bytes)
{
	const Storage *pStorage = Object_storage::GetObject(valueThis)->GetStorage();
	return Value(pStorage->GetFreeSpaceInBytes());
}

// mtp.storage#free_space_in_objects
Gura_DeclareProperty_R(storage, free_space_in_objects)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, free_space_in_objects)
{
	const Storage *pStorage = Object_storage::GetObject(valueThis)->GetStorage();
	return Value(pStorage->GetFreeSpaceInObjects());
}

// mtp.storage#storage_description
Gura_DeclareProperty_R(storage, storage_description)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, storage_description)
{
	const Storage *pStorage = Object_storage::GetObject(valueThis)->GetStorage();
	return Value(pStorage->GetStorageDescription());
}

// mtp.storage#volume_identifier
Gura_DeclareProperty_R(storage, volume_identifier)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, volume_identifier)
{
	const Storage *pStorage = Object_storage::GetObject(valueThis)->GetStorage();
	return Value(pStorage->GetVolumeIdentifier());
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// mtp.storage#method1()
Gura_DeclareMethod(storage, method1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "arg1", VTYPE_string);
	//DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(storage, method1)
{
	//Object_storage *pThis = Object_storage::GetObjectThis(arg);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class mtp.storage
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(storage)
{
	// Assignment of property
	Gura_AssignProperty(storage, storage_type);
	Gura_AssignProperty(storage, filesystem_type);
	Gura_AssignProperty(storage, access_capability);
	Gura_AssignProperty(storage, max_capacity);
	Gura_AssignProperty(storage, free_space_in_bytes);
	Gura_AssignProperty(storage, free_space_in_objects);
	Gura_AssignProperty(storage, storage_description);
	Gura_AssignProperty(storage, volume_identifier);
	// Assignment of method
	Gura_AssignMethod(storage, method1);
	// Assignment of value
	Gura_AssignValue(storage, Value(Reference()));
}

Gura_EndModuleScope(mtp)
