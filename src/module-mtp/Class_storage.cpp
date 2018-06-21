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

Stream *Storage::GenerateReaderStream(Environment &env, const char *pathName) const
{
	AutoPtr<Directory_MTP> pDirectory(GenerateDirectory(env, pathName));
	if (pDirectory.IsNull()) return nullptr;
	AutoPtr<StreamFIFO> pStreamFIFO(new StreamFIFO(env, 65536));
	AutoPtr<StreamFIFO> pStreamFIFORtn(new StreamFIFO(env, pStreamFIFO->GetEntity()->Reference()));
	OAL::Thread *pThread = new Device::Reader(
		env, _pDevice->Reference(), pDirectory->GetItemId(), pStreamFIFO.release());
	pThread->Start();
	return pStreamFIFORtn.release();
}

bool Storage::RecvFile(Signal &sig, const char *pathName, Stream *pStream) const
{
	bool rtn = true;
	AutoPtr<Directory_MTP> pDirectory(GenerateDirectory(sig, pathName));
	if (pDirectory.IsNull()) return false;
	uint32_t itemId = pDirectory->GetItemId();
	if (::LIBMTP_Get_File_To_Handler(
			_pDevice->GetMtpDevice(), itemId, Handler_RecvFile, pStream, nullptr, nullptr) != 0) {
		sig.SetError(ERR_LibraryError, "error while communicating in MTP protocol");
		rtn = false;
	}
	return rtn;
}

bool Storage::SendFile(Signal &sig, const char *pathName, Stream *pStream) const
{
	if (pStream->IsInfinite()) {
		sig.SetError(ERR_ValueError, "infinite stream can not be specified");
		return false;
	}
	String dirName, fileName;
	PathMgr::SplitFileName(pathName, &dirName, &fileName);
	AutoPtr<Directory_MTP> pDirectory(GenerateDirectory(sig, dirName.c_str()));
	if (pDirectory.IsNull()) return false;
	uint32_t itemIdParent = pDirectory->GetItemId();
	LIBMTP_file_t *mtpfile = ::LIBMTP_new_file_t();
	mtpfile->filesize = static_cast<uint32_t>(pStream->GetSize());
	mtpfile->filename = ::strdup(fileName.c_str());
	mtpfile->filetype = GetMtpfiletype(fileName.c_str());
	mtpfile->parent_id = itemIdParent;
	mtpfile->storage_id = 0;
	bool rtn = true;
	if (::LIBMTP_Send_File_From_Handler(
			_pDevice->GetMtpDevice(), Handler_SendFile, pStream, mtpfile, nullptr, nullptr) != 0) {
		sig.SetError(ERR_LibraryError, "error while communicating in MTP protocol");
		rtn = false;
	}
	::LIBMTP_destroy_file_t(mtpfile);
	return rtn;
}

uint16_t Storage::Handler_RecvFile(
	void *params, void *priv, uint32_t sendlen, unsigned char *data, uint32_t *putlen)
{
	Stream *pStream = reinterpret_cast<Stream *>(priv);
	Signal &sig = pStream->GetSignal();
	*putlen = static_cast<uint32_t>(pStream->Write(sig, data, sendlen));
	return sig.IsSignalled()? LIBMTP_HANDLER_RETURN_ERROR : LIBMTP_HANDLER_RETURN_OK;
}

uint16_t Storage::Handler_SendFile(
	void *params, void *priv, uint32_t wantlen, unsigned char *data, uint32_t *gotlen)
{
	Stream *pStream = reinterpret_cast<Stream *>(priv);
	Signal &sig = pStream->GetSignal();
	*gotlen = static_cast<uint32_t>(pStream->Read(sig, data, wantlen));
	return sig.IsSignalled()? LIBMTP_HANDLER_RETURN_ERROR :
		(*gotlen == 0)? LIBMTP_HANDLER_RETURN_CANCEL : LIBMTP_HANDLER_RETURN_OK;
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
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(StorageTypeToSymbol(pObjThis->GetStorage()->GetStorageType()));
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
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(FilesystemTypeToSymbol(pObjThis->GetStorage()->GetFilesystemType()));
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
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(AccessCapabilityToSymbol(pObjThis->GetStorage()->GetAccessCapability()));
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
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetMaxCapacity());
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
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetFreeSpaceInBytes());
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
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetFreeSpaceInObjects());
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
	Object_storage *pObjThis = Object_storage::GetObject(valueThis);
	return Value(pObjThis->GetStorage()->GetStorageDescription());
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

// mtp.storage#reader(pathname:string) {block?}
Gura_DeclareMethod(storage, reader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(storage, reader)
{
	const Storage *pStorage = Object_storage::GetObjectThis(arg)->GetStorage();
	const char *pathName = arg.GetString(0);
	return ReturnValue(env, arg, Value(new Object_stream(env, pStorage->GenerateReaderStream(env, pathName))));
}

// mtp.srorage#recvfile(pathname:string, stream:stream:w):reduce
Gura_DeclareMethod(storage, recvfile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(storage, recvfile)
{
	const Storage *pStorage = Object_storage::GetObjectThis(arg)->GetStorage();
	const char *pathName = arg.GetString(0);
	Stream &stream = arg.GetStream(1);
	if (!pStorage->RecvFile(env, pathName, &stream)) return Value::Nil;
	return arg.GetValueThis();
}

// mtp.storage#sendfile(pathname:string, stream:stream:r):reduce
Gura_DeclareMethod(storage, sendfile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "pathname", VTYPE_string);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(storage, sendfile)
{
	const Storage *pStorage = Object_storage::GetObjectThis(arg)->GetStorage();
	const char *pathName = arg.GetString(0);
	Stream &stream = arg.GetStream(1);
	if (!pStorage->SendFile(env, pathName, &stream)) return Value::Nil;
	return arg.GetValueThis();
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
	Gura_AssignProperty(storage, storage_type);
	Gura_AssignProperty(storage, filesystem_type);
	Gura_AssignProperty(storage, access_capability);
	Gura_AssignProperty(storage, max_capacity);
	Gura_AssignProperty(storage, free_space_in_bytes);
	Gura_AssignProperty(storage, free_space_in_objects);
	Gura_AssignProperty(storage, storage_description);
	Gura_AssignProperty(storage, volume_identifier);
	// Assignment of method
	Gura_AssignMethod(storage, opendir);
	Gura_AssignMethod(storage, reader);
	Gura_AssignMethod(storage, recvfile);
	Gura_AssignMethod(storage, sendfile);
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
