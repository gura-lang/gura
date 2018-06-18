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

Directory *Device::GenerateDirectory(Signal &sig, uint32_t storageId, const char *pathName) const
{
	const char *p = pathName;
	if (IsFileSeparator(*p)) p++;
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
			sig.SetError(ERR_IOError, "specified path doesn't exist");
			return nullptr;
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

//-----------------------------------------------------------------------------
// Downloader
//-----------------------------------------------------------------------------
class Downloader : public OAL::Thread {
private:
	Signal &_sig;
	AutoPtr<Device> _pDevice;
	uint32_t _itemId;
	AutoPtr<Stream> _pStream;
public:
	Downloader(Signal &sig, Device *pDevice, uint32_t itemId, Stream *pStream);
	uint16_t OnWrite(void *params, uint32_t sendlen, unsigned char *data, uint32_t *putlen);
	size_t OnWrite(char *buffer, size_t size, size_t nitems);
	static uint16_t OnWriteStub(void *params, void *priv,
								uint32_t sendlen, unsigned char *data, uint32_t *putlen);
	virtual void Run();
};

//-----------------------------------------------------------------------------
// Downloader
//-----------------------------------------------------------------------------
Downloader::Downloader(Signal &sig, Device *pDevice, uint32_t itemId, Stream *pStream) :
	_sig(sig), _pDevice(pDevice), _itemId(itemId), _pStream(pStream)
{
}

uint16_t Downloader::OnWrite(void *params, uint32_t sendlen, unsigned char *data, uint32_t *putlen)
{
	//::printf("OnWrite(%d)\n", nitems);
	*putlen = static_cast<uint32_t>(_pStream->Write(_sig, data, sendlen));
	return _sig.IsSignalled()? LIBMTP_HANDLER_RETURN_ERROR : LIBMTP_HANDLER_RETURN_OK;
}

uint16_t Downloader::OnWriteStub(void *params, void *priv,
								 uint32_t sendlen, unsigned char *data, uint32_t *putlen)
{
	Downloader *pDownloader = reinterpret_cast<Downloader *>(priv);
	return pDownloader->OnWrite(params, sendlen, data, putlen);
}

void Downloader::Run()
{
	/*
	int LIBMTP_Get_File_To_Handler(LIBMTP_mtpdevice_t *,
			       uint32_t const,
			       MTPDataPutFunc,
			       void *,
			       LIBMTP_progressfunc_t const,
			       void const * const);
	*/
	::LIBMTP_Get_File_To_Handler(_pDevice->GetMtpDevice(), _itemId, OnWriteStub, this, nullptr, nullptr);
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
	AutoPtr<StreamFIFO> pStreamFIFO(new StreamFIFO(env, 65536));
	AutoPtr<StreamFIFO> pStreamFIFORtn(new StreamFIFO(env, pStreamFIFO->GetEntity()->Reference()));
	OAL::Thread *pThread = new Downloader(env, _pDevice->Reference(), _itemId, pStreamFIFO.release());
	pThread->Start();
	return pStreamFIFORtn.release();
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
