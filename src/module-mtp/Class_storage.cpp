//=============================================================================
// Gura class: mtp.storage
//=============================================================================
#include "stdafx.h"
#include "ptp.h"

Gura_BeginModuleScope(mtp)

const Symbol *StorageTypeToSymbol(uint16_t storageType);
const Symbol *FilesystemTypeToSymbol(uint16_t filesystemType);
const Symbol *AccessCapabilityToSymbol(uint16_t accessCapability);

//-----------------------------------------------------------------------------
// Storage
//-----------------------------------------------------------------------------
Storage::Storage(Device *pDevice, LIBMTP_devicestorage_t *deviceStorage) : _cntRef(1),
	_pDevice(pDevice),
	_id(deviceStorage->id),
	_storageType(deviceStorage->StorageType),
	_filesystemType(deviceStorage->FilesystemType),
	_accessCapability(deviceStorage->AccessCapability),
	_maxCapacity(deviceStorage->MaxCapacity),
	_freeSpaceInBytes(deviceStorage->FreeSpaceInBytes),
	_freeSpaceInObjects(deviceStorage->FreeSpaceInObjects)
{
	if (deviceStorage->StorageDescription != nullptr) {
		_storageDescription = deviceStorage->StorageDescription;
	}
	if (deviceStorage->VolumeIdentifier != nullptr) {
		_volumeIdentifier = deviceStorage->VolumeIdentifier;
	}
}

//-----------------------------------------------------------------------------
// Implementation of property
//-----------------------------------------------------------------------------
// mtp.storage#id
Gura_DeclareProperty_R(storage, id)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, id)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetId());
}

// mtp.storage#storageType
Gura_DeclareProperty_R(storage, storageType)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, storageType)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(StorageTypeToSymbol(pObjThis->GetStorage()->GetStorageType()));
}

// mtp.storage#filesystemType
Gura_DeclareProperty_R(storage, filesystemType)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, filesystemType)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(FilesystemTypeToSymbol(pObjThis->GetStorage()->GetFilesystemType()));
}

// mtp.storage#accessCapability
Gura_DeclareProperty_R(storage, accessCapability)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, accessCapability)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(AccessCapabilityToSymbol(pObjThis->GetStorage()->GetAccessCapability()));
}

// mtp.storage#maxCapacity
Gura_DeclareProperty_R(storage, maxCapacity)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, maxCapacity)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetMaxCapacity());
}

// mtp.storage#freeSpaceInBytes
Gura_DeclareProperty_R(storage, freeSpaceInBytes)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, freeSpaceInBytes)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetFreeSpaceInBytes());
}

// mtp.storage#freeSpaceInObjects
Gura_DeclareProperty_R(storage, freeSpaceInObjects)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, freeSpaceInObjects)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetFreeSpaceInObjects());
}

// mtp.storage#storageDescription
Gura_DeclareProperty_R(storage, storageDescription)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, storageDescription)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetStorageDescription());
}

// mtp.storage#volumeIdentifier
Gura_DeclareProperty_R(storage, volumeIdentifier)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(storage, volumeIdentifier)
{
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetVolumeIdentifier());
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// mtp.storage#opendir(pathname:string) {block?}
Gura_DeclareMethod(storage, opendir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(storage, opendir)
{
	const Storage *pStorage = Object_storage::GetObjectThis(arg)->GetStorage();
	const char *pathName = arg.GetString(0);
	AutoPtr<Directory> pDirectory(pStorage->GenerateDirectory(env, pathName));
	if (pDirectory.IsNull()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_directory(env, pDirectory.release())));
}

//-----------------------------------------------------------------------------
// Implementation of Object_storage
//-----------------------------------------------------------------------------
Object_storage::Object_storage(Storage *pStorage) : Object(Gura_UserClass(storage)), _pStorage(pStorage)
{
}

String Object_storage::ToString(bool exprFlag)
{
	String rtn = "<mtp.storage:";
	rtn += _pStorage->GetStorageDescription();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of class mtp.storage
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(storage)
{
	// Assignment of property
	Gura_AssignProperty(storage, id);
	Gura_AssignProperty(storage, storageType);
	Gura_AssignProperty(storage, filesystemType);
	Gura_AssignProperty(storage, accessCapability);
	Gura_AssignProperty(storage, maxCapacity);
	Gura_AssignProperty(storage, freeSpaceInBytes);
	Gura_AssignProperty(storage, freeSpaceInObjects);
	Gura_AssignProperty(storage, storageDescription);
	Gura_AssignProperty(storage, volumeIdentifier);
	// Assignment of method
	Gura_AssignMethod(storage, opendir);
	// Assignment of value
	Gura_AssignValue(storage, Value(Reference()));
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
const Symbol *StorageTypeToSymbol(uint16_t storageType)
{
	return
		(storageType == PTP_ST_Undefined)? Gura_UserSymbol(Undefined) :
		(storageType == PTP_ST_FixedROM)? Gura_UserSymbol(FixedROM) :
		(storageType == PTP_ST_RemovableROM)? Gura_UserSymbol(RemovableROM) :
		(storageType == PTP_ST_FixedRAM)? Gura_UserSymbol(FixedRAM) :
		(storageType == PTP_ST_RemovableRAM)? Gura_UserSymbol(RemovableRAM) :
		Gura_UserSymbol(Undefined);
}

const Symbol *FilesystemTypeToSymbol(uint16_t filesystemType)
{
	return
		(filesystemType == PTP_FST_Undefined)? Gura_UserSymbol(Undefined) :
		(filesystemType == PTP_FST_GenericFlat)? Gura_UserSymbol(GenericFlat) :
		(filesystemType == PTP_FST_GenericHierarchical)? Gura_UserSymbol(GenericHierarchical) :
		(filesystemType == PTP_FST_DCF)? Gura_UserSymbol(DCF) :
		Gura_UserSymbol(Undefined);
}

const Symbol *AccessCapabilityToSymbol(uint16_t accessCapability)
{
	return
		(accessCapability == PTP_AC_ReadWrite)? Gura_UserSymbol(ReadWrite) :
		(accessCapability == PTP_AC_ReadOnly)? Gura_UserSymbol(ReadOnly) :
		(accessCapability == PTP_AC_ReadOnly_with_Object_Deletion)? Gura_UserSymbol(ReadOnlyWithObjectDeletion) :
		Gura_UserSymbol(Undefined);
}

Gura_EndModuleScope(mtp)
