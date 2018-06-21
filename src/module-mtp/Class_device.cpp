//=============================================================================
// Gura class: mtp.device
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
Device::Device(LIBMTP_mtpdevice_t *mtpDevice) : _cntRef(1), _mtpDevice(mtpDevice)
{
}

Device::~Device()
{
	::LIBMTP_Release_Device(_mtpDevice);
}

void Device::LookupStorages(Object_list *pObjList) const
{
	LIBMTP_devicestorage_t *deviceStorage = _mtpDevice->storage;
	for ( ; deviceStorage != nullptr; deviceStorage = deviceStorage->next) {
		pObjList->Add(Value(new Object_storage(new Storage(Reference(), deviceStorage))));
	}
}

Directory_MTP *Device::GeneratePartialDirectory(
	Signal &sig, uint32_t storageId, const char *pathName, const char **pPathNamePartial) const
{
	const char *p = pathName;
	if (IsFileSeparator(*p)) p++;
	*pPathNamePartial = p;
	Directory_MTP *pDirectory = new Directory_MTP(
		nullptr, "/", Directory::TYPE_Container,
		Reference(), storageId, LIBMTP_FILES_AND_FOLDERS_ROOT,
		new Stat("", "", 0, DateTime(), LIBMTP_FILETYPE_FOLDER));
	while (*p != '\0') {
		if (!pDirectory->IsContainer()) {
			sig.SetError(ERR_IOError, "can't browse inside an item");
			return nullptr;
		}
		String field;
		for ( ; ; p++) {
			if (*p == '\0') {
				break;
			} else if (IsFileSeparator(*p)) {
				p++;
				break;
			}
			field += *p;
		}
		*pPathNamePartial = p;
		if (field.empty()) {
			sig.SetError(ERR_FormatError, "wrong format of path name");
			return nullptr;
		}
		//::printf("[%s]\n", field.c_str());
		LIBMTP_file_t *mtpfileHead = ::LIBMTP_Get_Files_And_Folders(_mtpDevice, storageId, pDirectory->GetItemId());
		if (mtpfileHead == nullptr) {
			::LIBMTP_Dump_Errorstack(_mtpDevice);
			::LIBMTP_Clear_Errorstack(_mtpDevice);
			sig.SetError(ERR_LibraryError, "failed to get file information from MTP");
			return nullptr;
		}
		LIBMTP_file_t *mtpfileFound = nullptr;
		for (LIBMTP_file_t *mtpfile = mtpfileHead; mtpfile != nullptr; mtpfile = mtpfile->next) {
			if (field == mtpfile->filename) {
				mtpfileFound = mtpfile;
				break;
			}
		}
		if (mtpfileFound == nullptr) {
			DestroyMtpfileList(mtpfileHead);
			break;
		}
		pDirectory = new Directory_MTP(
			pDirectory, mtpfileFound->filename,
			(mtpfileFound->filetype == LIBMTP_FILETYPE_FOLDER)?
								Directory::TYPE_Container : Directory::TYPE_Item,
			Reference(), storageId, mtpfileFound->item_id,
			new Stat(pDirectory->MakePathName(false).c_str(), mtpfileFound));
		DestroyMtpfileList(mtpfileHead);
	}
	return pDirectory;
}

Directory_MTP *Device::GenerateDirectory(Signal &sig, uint32_t storageId, const char *pathName) const
{
	const char *pathNamePartial = nullptr;
	AutoPtr<Directory_MTP> pDirectory(GeneratePartialDirectory(sig, storageId, pathName, &pathNamePartial));
	if (*pathNamePartial != '\0') {
		sig.SetError(ERR_IOError, "specified path doesn't exist");
		return nullptr;
	}
	return pDirectory.release();
}

//-----------------------------------------------------------------------------
// Device::Reader
//-----------------------------------------------------------------------------
Device::Reader::Reader(Signal &sig, Device *pDevice, uint32_t itemId, Stream *pStream) :
	_sig(sig), _pDevice(pDevice), _itemId(itemId), _pStream(pStream)
{
}

uint16_t Device::Reader::OnDataPut(void *params, uint32_t sendlen, unsigned char *data, uint32_t *putlen)
{
	//::printf("OnWrite()\n");
	*putlen = static_cast<uint32_t>(_pStream->Write(_sig, data, sendlen));
	return _sig.IsSignalled()? LIBMTP_HANDLER_RETURN_ERROR : LIBMTP_HANDLER_RETURN_OK;
}

uint16_t Device::Reader::OnDataPutStub(void *params, void *priv,
								 uint32_t sendlen, unsigned char *data, uint32_t *putlen)
{
	Reader *pReader = reinterpret_cast<Reader *>(priv);
	return pReader->OnDataPut(params, sendlen, data, putlen);
}

void Device::Reader::Run()
{
	if (::LIBMTP_Get_File_To_Handler(
			_pDevice->GetMtpDevice(), _itemId, OnDataPutStub, this, nullptr, nullptr) != 0) {
		_sig.SetError(ERR_LibraryError, "error while communicating in MTP protocol");
	}
}

//-----------------------------------------------------------------------------
// Directory_MTP implementation
//-----------------------------------------------------------------------------
Directory_MTP::Directory_MTP(Directory *pParent, const char *name, Type type,
							 Device *pDevice, uint32_t storageId, uint32_t itemId, Stat *pStat) :
	Directory(pParent, name, type, OAL::FileSeparatorUnix),
	_pDevice(pDevice), _storageId(storageId), _itemId(itemId), _pStat(pStat)
{
	_browsePack.mtpfileHead = nullptr;
	_browsePack.mtpfile = nullptr;
}

Directory_MTP::~Directory_MTP()
{
	DestroyMtpfileList(_browsePack.mtpfileHead);
}

Directory *Directory_MTP::DoNext(Environment &env)
{
	if (_browsePack.mtpfileHead == nullptr) {
		_browsePack.mtpfileHead = ::LIBMTP_Get_Files_And_Folders(_pDevice->GetMtpDevice(), _storageId, _itemId);
		_browsePack.mtpfile = _browsePack.mtpfileHead;
	} else {
		_browsePack.mtpfile = _browsePack.mtpfile->next;
	}
	if (_browsePack.mtpfile == nullptr) return nullptr;
	Type type = (_browsePack.mtpfile->filetype == LIBMTP_FILETYPE_FOLDER)? TYPE_Container : TYPE_Item;
	return new Directory_MTP(
		Reference(), _browsePack.mtpfile->filename, type,
		_pDevice->Reference(), _storageId, _browsePack.mtpfile->item_id,
		new Stat(MakePathName(false).c_str(), _browsePack.mtpfile));
}

Stream *Directory_MTP::DoOpenStream(Environment &env, UInt32 attr)
{
	return nullptr;
}

Object *Directory_MTP::DoGetStatObj(Signal &sig)
{
	return new Object_stat(_pStat->Reference());
}

//-----------------------------------------------------------------------------
// Implementation of Object_device
//-----------------------------------------------------------------------------
Object_device::Object_device(Device *pDevice) : Object(Gura_UserClass(device)), _pDevice(pDevice)
{
}

String Object_device::ToString(bool exprFlag)
{
	String rtn = "<mtp.device:";
	rtn += ::LIBMTP_Get_Friendlyname(_pDevice->GetMtpDevice());
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of property
//-----------------------------------------------------------------------------
// mtp.device#deviceversion
Gura_DeclareProperty_R(device, deviceversion)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(device, deviceversion)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	const char *str = ::LIBMTP_Get_Deviceversion(pDevice->GetMtpDevice());
	return (str == nullptr)? Value::Nil : Value(str);
}

// mtp.device#friendlyname
Gura_DeclareProperty_R(device, friendlyname)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(device, friendlyname)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	const char *str = ::LIBMTP_Get_Friendlyname(pDevice->GetMtpDevice());
	return (str == nullptr)? Value::Nil : Value(str);
}

// mtp.device#manufacturername
Gura_DeclareProperty_R(device, manufacturername)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(device, manufacturername)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	const char *str = ::LIBMTP_Get_Manufacturername(pDevice->GetMtpDevice());
	return (str == nullptr)? Value::Nil : Value(str);
}

// mtp.device#modelname
Gura_DeclareProperty_R(device, modelname)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(device, modelname)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	const char *str = ::LIBMTP_Get_Modelname(pDevice->GetMtpDevice());
	return (str == nullptr)? Value::Nil : Value(str);
}

// mtp.device#serialnumber
Gura_DeclareProperty_R(device, serialnumber)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(device, serialnumber)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	const char *str = ::LIBMTP_Get_Serialnumber(pDevice->GetMtpDevice());
	return (str == nullptr)? Value::Nil : Value(str);
}

// mtp.device#storages
Gura_DeclareProperty_R(device, storages)
{
	SetPropAttr(VTYPE_list);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(device, storages)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	Value valueRtn;
	Object_list *pObjList = valueRtn.InitAsList(env);
	pDevice->LookupStorages(pObjList);
	return valueRtn;
}

// mtp.device#syncpartner
Gura_DeclareProperty_R(device, syncpartner)
{
	SetPropAttr(VTYPE_string, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(device, syncpartner)
{
	const Device *pDevice = Object_device::GetObject(valueThis)->GetDevice();
	const char *str = ::LIBMTP_Get_Syncpartner(pDevice->GetMtpDevice());
	return (str == nullptr)? Value::Nil : Value(str);
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
	Gura_AssignProperty(device, deviceversion);
	Gura_AssignProperty(device, friendlyname);
	Gura_AssignProperty(device, manufacturername);
	Gura_AssignProperty(device, modelname);
	Gura_AssignProperty(device, serialnumber);
	Gura_AssignProperty(device, storages);
	Gura_AssignProperty(device, syncpartner);
	// Assignment of method
	// Assignment of value
	Gura_AssignValue(device, Value(Reference()));
}

Gura_EndModuleScope(mtp)
