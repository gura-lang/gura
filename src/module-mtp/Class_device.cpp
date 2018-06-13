//=============================================================================
// Gura class: mtp.device
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Directory_MTP declaration
//-----------------------------------------------------------------------------
class Directory_MTP : public Directory {
private:
	AutoPtr<Device> _pDevice;
	uint32_t _storageId;
	uint32_t _itemId;
	LIBMTP_file_t *_fileInfo;
	LIBMTP_file_t *_fileInfoHead;
public:
	Directory_MTP(Directory *pParent, const char *name, Type type,
				  Device *pDevice, uint32_t storageId, uint32_t itemId);
	virtual ~Directory_MTP();
	virtual Directory *DoNext(Environment &env);
	virtual Stream *DoOpenStream(Environment &env, UInt32 attr);
	virtual Object *DoGetStatObj(Signal &sig);
};

//-----------------------------------------------------------------------------
// Directory_MTP implementation
//-----------------------------------------------------------------------------
Directory_MTP::Directory_MTP(Directory *pParent, const char *name, Type type,
							 Device *pDevice, uint32_t storageId, uint32_t itemId) :
	Directory(pParent, name, type, OAL::FileSeparator),
	_pDevice(pDevice), _storageId(storageId), _itemId(itemId),
	_fileInfo(nullptr), _fileInfoHead(nullptr)
{
}

Directory_MTP::~Directory_MTP()
{
	LIBMTP_file_t *fileInfo = _fileInfoHead;
	while (fileInfo != nullptr) {
		LIBMTP_file_t *fileInfoNext = fileInfo->next;
		::LIBMTP_destroy_file_t(fileInfo);
		fileInfo = fileInfoNext;
	}
}

Directory *Directory_MTP::DoNext(Environment &env)
{
	::printf("DoNext()\n");
	if (_fileInfoHead == nullptr) {
		_fileInfoHead = ::LIBMTP_Get_Files_And_Folders(_pDevice->GetMtpDevice(), _storageId, _itemId);
		_fileInfo = _fileInfoHead;
	} else {
		_fileInfo = _fileInfo->next;
	}
	if (_fileInfo == nullptr) return nullptr;
	Type type = (_fileInfo->filetype == LIBMTP_FILETYPE_FOLDER)? TYPE_Container : TYPE_Item;
	return new Directory_MTP(Reference(), _fileInfo->filename, type,
							 _pDevice->Reference(), _storageId, _fileInfo->item_id);
}

Stream *Directory_MTP::DoOpenStream(Environment &env, UInt32 attr)
{
	return nullptr;
}

Object *Directory_MTP::DoGetStatObj(Signal &sig)
{
	return nullptr;
}

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

Directory *Device::GenerateDirectory(Signal &sig, uint32_t storageId, const char *pathName) const
{
#if 0
	uint32_t itemIdParent = LIBMTP_FILES_AND_FOLDERS_ROOT;
	LIBMTP_file_t *fileInfo = ::LIBMTP_Get_Files_And_Folders(_mtpDevice, storageId, itemIdParent);
	if (fileInfo == nullptr) {
		::LIBMTP_Dump_Errorstack(_mtpDevice);
		::LIBMTP_Clear_Errorstack(_mtpDevice);
		sig.SetError(ERR_LibraryError, "failed to get file information from MTP");
		return nullptr;
	}	
	while (fileInfo != nullptr) {
		if (fileInfo->filetype == LIBMTP_FILETYPE_FOLDER) {
			printf("[%s]\n", fileInfo->filename);
			//ListFiles(mtpDevice, storageId, fileInfo->item_id, indentLevel + 1);
		} else {
			printf("%s\n", fileInfo->filename);
		}
		LIBMTP_file_t *fileInfoNext = fileInfo->next;
		::LIBMTP_destroy_file_t(fileInfo);
		fileInfo = fileInfoNext;
	}
#endif
	::printf("GenerateDirectory()\n");
	return new Directory_MTP(nullptr, "", Directory::TYPE_Container,
							 Reference(), storageId, LIBMTP_FILES_AND_FOLDERS_ROOT);
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
	rtn += _pDevice->GetFriendlyName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of property
//-----------------------------------------------------------------------------
// mtp.device#friendlyName
Gura_DeclareProperty_R(device, friendlyName)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(device, friendlyName)
{
	Object_device *pObjThis = Object_device::GetObject(valueThis);
	return Value(pObjThis->GetDevice()->GetFriendlyName());
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// mtp.device#GetStorages() {block?}
Gura_DeclareMethod(device, GetStorages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(device, GetStorages)
{
	const Device *pDevice = Object_device::GetObjectThis(arg)->GetDevice();
	Value valueRtn;
	Object_list *pObjList = valueRtn.InitAsList(env);
	pDevice->LookupStorages(pObjList);
	return ReturnValue(env, arg, valueRtn);
}

//-----------------------------------------------------------------------------
// Implementation of class mtp.device
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(device)
{
	// Assignment of property
	Gura_AssignProperty(device, friendlyName);
	// Assignment of method
	Gura_AssignMethod(device, GetStorages);
	// Assignment of value
	Gura_AssignValue(device, Value(Reference()));
}

Gura_EndModuleScope(mtp)
