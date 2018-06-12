//=============================================================================
// Gura class: mtp.storage
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Storage
//-----------------------------------------------------------------------------
Storage::Storage(LIBMTP_devicestorage_t *deviceStorage) : _cntRef(1)
{
	_id = deviceStorage->id;
	_storageType = deviceStorage->StorageType;
	_filesystemType = deviceStorage->FilesystemType;
	_acccessCapability = deviceStorage->AccessCapability;
	_maxCapacity = deviceStorage->MaxCapacity;
	_freeSpaceInBytes = deviceStorage->FreeSpaceInBytes;
	_freeSpaceInObjects = deviceStorage->FreeSpaceInObjects;
	if (deviceStorage->StorageDescription != nullptr) {
		_storageDescription = deviceStorage->StorageDescription;
	}
	if (deviceStorage->VolumeIdentifier != nullptr) {
		_volumeIdentifier = deviceStorage->VolumeIdentifier;
	}
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
	// Assignment of value
	Gura_AssignValue(storage, Value(Reference()));
}

Gura_EndModuleScope(mtp)
