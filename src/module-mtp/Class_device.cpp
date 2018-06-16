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
	AutoPtr<Stat> _pStat;
	struct {
		LIBMTP_file_t *fileInfoHead;
		LIBMTP_file_t *fileInfo;
	} _browsePack;
public:
	Directory_MTP(Directory *pParent, const char *name, Type type,
				  Device *pDevice, uint32_t storageId, uint32_t itemId, Stat *pStat);
	virtual ~Directory_MTP();
	virtual Directory *DoNext(Environment &env);
	virtual Stream *DoOpenStream(Environment &env, UInt32 attr);
	virtual Object *DoGetStatObj(Signal &sig);
	inline uint32_t GetItemId() const { return _itemId; }
};

//-----------------------------------------------------------------------------
// Directory_MTP implementation
//-----------------------------------------------------------------------------
Directory_MTP::Directory_MTP(Directory *pParent, const char *name, Type type,
							 Device *pDevice, uint32_t storageId, uint32_t itemId, Stat *pStat) :
	Directory(pParent, name, type, OAL::FileSeparatorUnix),
	_pDevice(pDevice), _storageId(storageId), _itemId(itemId), _pStat(pStat)
{
	_browsePack.fileInfoHead = nullptr;
	_browsePack.fileInfo = nullptr;
}

Directory_MTP::~Directory_MTP()
{
	DestroyFileInfoList(_browsePack.fileInfoHead);
}

Directory *Directory_MTP::DoNext(Environment &env)
{
	if (_browsePack.fileInfoHead == nullptr) {
		_browsePack.fileInfoHead = ::LIBMTP_Get_Files_And_Folders(_pDevice->GetMtpDevice(), _storageId, _itemId);
		_browsePack.fileInfo = _browsePack.fileInfoHead;
	} else {
		_browsePack.fileInfo = _browsePack.fileInfo->next;
	}
	if (_browsePack.fileInfo == nullptr) return nullptr;
	Type type = (_browsePack.fileInfo->filetype == LIBMTP_FILETYPE_FOLDER)? TYPE_Container : TYPE_Item;
	return new Directory_MTP(
		Reference(), _browsePack.fileInfo->filename, type,
		_pDevice->Reference(), _storageId, _browsePack.fileInfo->item_id, new Stat(_browsePack.fileInfo));
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
	const char *p = pathName;
	if (IsFileSeparator(*p)) p++;
	Directory_MTP *pDirectory = new Directory_MTP(
		nullptr, "/", Directory::TYPE_Container,
		Reference(), storageId, LIBMTP_FILES_AND_FOLDERS_ROOT,
		new Stat("", 0, DateTime(), LIBMTP_FILETYPE_FOLDER));
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
		if (field.empty()) {
			sig.SetError(ERR_FormatError, "wrong format of path name");
			return nullptr;
		}
		//::printf("[%s]\n", field.c_str());
		LIBMTP_file_t *fileInfoHead = ::LIBMTP_Get_Files_And_Folders(_mtpDevice, storageId, pDirectory->GetItemId());
		if (fileInfoHead == nullptr) {
			::LIBMTP_Dump_Errorstack(_mtpDevice);
			::LIBMTP_Clear_Errorstack(_mtpDevice);
			sig.SetError(ERR_LibraryError, "failed to get file information from MTP");
			return nullptr;
		}
		LIBMTP_file_t *fileInfoFound = nullptr;
		for (LIBMTP_file_t *fileInfo = fileInfoHead; fileInfo != nullptr; fileInfo = fileInfo->next) {
			if (field == fileInfo->filename) {
				fileInfoFound = fileInfo;
				break;
			}
		}
		if (fileInfoFound == nullptr) {
			DestroyFileInfoList(fileInfoHead);
			sig.SetError(ERR_IOError, "specified path doesn't exist");
			return nullptr;
		}
		pDirectory = new Directory_MTP(
			pDirectory, fileInfoFound->filename,
			(fileInfoFound->filetype == LIBMTP_FILETYPE_FOLDER)?
								Directory::TYPE_Container : Directory::TYPE_Item,
			Reference(), storageId, fileInfoFound->item_id, new Stat(fileInfoFound));
		DestroyFileInfoList(fileInfoHead);
	}
	return pDirectory;
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
