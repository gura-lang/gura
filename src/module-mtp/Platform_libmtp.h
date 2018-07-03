//=============================================================================
// PLATFORM_libmtp.h
//=============================================================================
#ifndef __GURA_MODULE_MTP_PLATFORM_LIBMTP_H__
#define __GURA_MODULE_MTP_PLATFORM_LIBMTP_H__
#include <gura.h>
#include <libmtp.h>
#include <ptp.h>

Gura_BeginModuleScope(mtp)

class Directory_MTP;

//-----------------------------------------------------------------------------
// InitPlatform
//-----------------------------------------------------------------------------
bool InitPlatform();

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
class Device {
public:
	class Reader : public OAL::Thread {
	private:
		Signal &_sig;
		AutoPtr<Device> _pDevice;
		uint32_t _itemId;
		AutoPtr<Stream> _pStream;
	public:
		Reader(Signal &sig, Device *pDevice, uint32_t itemId, Stream *pStream);
		uint16_t OnDataPut(void *params, uint32_t sendlen, unsigned char *data, uint32_t *putlen);
		static uint16_t OnDataPutStub(void *params, void *priv,
									  uint32_t sendlen, unsigned char *data, uint32_t *putlen);
		virtual void Run();
	};
	// Writer can not be implemented because MTP protocol needs to know the whole file size
	// before transmitting data to a device while Writer is not capable of knowing it in advance.
private:
	int _cntRef;
	LIBMTP_mtpdevice_t *_mtpDevice;
public:
	Gura_DeclareReferenceAccessor(Device);
public:
	Device(LIBMTP_mtpdevice_t *mtpDevice);
protected:
	~Device();
public:
	Directory_MTP *GeneratePartialDirectory(
		Signal &sig, uint32_t storageId, const char *pathName, const char **pPathNamePartial) const;
	Directory_MTP *GenerateDirectory(Signal &sig, uint32_t storageId, const char *pathName) const;
	inline LIBMTP_mtpdevice_t *GetMtpDevice() const { return _mtpDevice; }
	inline const char *GetFriendlyName() const { return ::LIBMTP_Get_Friendlyname(_mtpDevice); }
	inline const char *GetManufacturer() const { return ::LIBMTP_Get_Manufacturername(_mtpDevice); }
	//inline const char *GetModelName() const { return ::LIBMTP_Get_Modelname(_mtpDevice); }
	//inline const char *GetSerialNumber() const { return ::LIBMTP_Get_Serialnumber(_mtpDevice); }
	//inline const char *GetDeviceVersion() const { return ::LIBMTP_Get_Deviceversion(_mtpDevice); }
	//inline const char *GetSyncPartner() const { return ::LIBMTP_Get_Syncpartner(_mtpDevice); }
#if 0
	inline int GetBatterylevel(uint8_t * const maximum_level, uint8_t * ) const {
		//int LIBMTP_Get_Batterylevel(LIBMTP_mtpdevice_t *, uint8_t * const, uint8_t * const);
		return 0;
	}
	inline int GetSecureTime() const {
		//int LIBMTP_Get_Secure_Time(LIBMTP_mtpdevice_t *, char ** const);
		return 0;
	}
	inline int GetDeviceCertificate() const {
		//int LIBMTP_Get_Device_Certificate(LIBMTP_mtpdevice_t *, char ** const);
		return 0;
	}
	inline int GetSupportedFileTypes() const {
		//int LIBMTP_Get_Supported_Filetypes(LIBMTP_mtpdevice_t *, uint16_t ** const, uint16_t * const);
		return 0;
	}
	//int LIBMTP_Set_Friendlyname(LIBMTP_mtpdevice_t*, char const * const);
	//int LIBMTP_Set_Syncpartner(LIBMTP_mtpdevice_t*, char const * const);
#endif
};

//-----------------------------------------------------------------------------
// DeviceList
//-----------------------------------------------------------------------------
class DeviceList : public std::vector<Device *> {
};

//-----------------------------------------------------------------------------
// DeviceOwner
//-----------------------------------------------------------------------------
class DeviceOwner : public DeviceList {
public:
	~DeviceOwner();
	void Clear();
	bool EnumerateDevices(Signal &sig);
};

//-----------------------------------------------------------------------------
// Storage
//-----------------------------------------------------------------------------
class Storage {
private:
	int _cntRef;
	AutoPtr<Device> _pDevice;
	uint32_t _id;						// Unique ID for this storage
	const Symbol *_pStorageType;		// Storage type
	const Symbol *_pFilesystemType;		// Filesystem type
	const Symbol *_pAccessCapability;	// Access capability
	uint64_t _maxCapacity;				// Maximum capability
	uint64_t _freeSpaceInBytes;			// Free space in bytes
	uint64_t _freeSpaceInObjects;		// Free space in objects
	String _storageDescription;			// A brief description of this storage 
	String _volumeIdentifier;			// A volume identifier
public:
	Gura_DeclareReferenceAccessor(Storage);
public:
	Storage(Device *pDevice, LIBMTP_devicestorage_t *deviceStorage);
protected:
	inline ~Storage() {}
public:
	inline uint32_t GetId() const { return _id; }
	inline const Symbol *GetStorageType() const { return _pStorageType; }
	inline const Symbol *GetFilesystemType() const { return _pFilesystemType; }
	inline const Symbol *GetAccessCapability() const { return _pAccessCapability; }
	inline uint64_t GetMaxCapacity() const { return _maxCapacity; }
	inline uint64_t GetFreeSpaceInBytes() const { return _freeSpaceInBytes; }
	inline uint64_t GetFreeSpaceInObjects() const { return _freeSpaceInObjects; }
	inline const char *GetStorageDescription() const { return _storageDescription.c_str(); }
	inline const char *GetVolumeIdentifier() const { return _volumeIdentifier.c_str(); }
	inline Directory_MTP *GenerateDirectory(Signal &sig, const char *pathName) const {
		return _pDevice->GenerateDirectory(sig, _id, pathName);
	}
	inline Directory_MTP *GeneratePartialDirectory(Signal &sig, const char *pathName,
												   const char **pPathNamePartial) const {
		return _pDevice->GeneratePartialDirectory(sig, _id, pathName, pPathNamePartial);
	}
	Stream *GenerateReaderStream(Environment &env, const char *pathName) const;
	bool RecvFile(Signal &sig, const char *pathName, Stream *pStream, const Function *pFuncBlock) const;
	bool SendFile(Signal &sig, const char *pathName, Stream *pStream, const Function *pFuncBlock) const;
	bool DeleteFile(Signal &sig, const char *pathName) const;
	bool MoveFile(Signal &sig, const char *pathNameOld, const char *pathNameNew, bool overwriteFlag) const;
	bool CopyFile(Signal &sig, const char *pathNameSrc, const char *pathNameDst, bool overwriteFlag) const;
	static uint16_t Callback_RecvFile(
		void *params, void *priv, uint32_t sendlen, unsigned char *data, uint32_t *putlen);
	static uint16_t Callback_SendFile(
		void *params, void *priv, uint32_t wantlen, unsigned char *data, uint32_t *gotlen);
	static int Callback_Progress(
		uint64_t const sent, uint64_t const total, void const * const data);
};

//-----------------------------------------------------------------------------
// StorageList
//-----------------------------------------------------------------------------
class StorageList : public std::vector<Storage *> {
};

//-----------------------------------------------------------------------------
// StorageOwner
//-----------------------------------------------------------------------------
class StorageOwner : public StorageList {
public:
	~StorageOwner();
	void Clear();
	bool EnumerateStorages(Signal &sig, Device *pDevice);
};

//-----------------------------------------------------------------------------
// Stat
//-----------------------------------------------------------------------------
class Stat {
private:
	int _cntRef;
	String _dirName;
	String _fileName;
	size_t _fileSize;
	DateTime _dtModification;
	LIBMTP_filetype_t _fileType;
public:
	Gura_DeclareReferenceAccessor(Stat);
public:
	Stat(const char *dirName, const LIBMTP_file_t *mtpfile);
	Stat(const char *dirName, const char *fileName, size_t fileSize,
		 const DateTime &dtModification, LIBMTP_filetype_t fileType);
protected:
	inline ~Stat() {}
public:
	inline const char *GetDirName() const { return _dirName.c_str(); }
	inline const char *GetFileName() const { return _fileName.c_str(); }
	inline size_t GetFileSize() const { return _fileSize; }
	inline bool IsFolder() const { return _fileType == LIBMTP_FILETYPE_FOLDER; }
	const DateTime &GetDtModification() const { return _dtModification; }
	String MakePathName() const;
};

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
		LIBMTP_file_t *mtpfileHead;
		LIBMTP_file_t *mtpfile;
	} _browsePack;
public:
	Directory_MTP(Directory *pParent, const char *name, Type type,
				  Device *pDevice, uint32_t storageId, uint32_t itemId, Stat *pStat);
	virtual ~Directory_MTP();
	virtual Directory *DoNext(Environment &env);
	virtual Stream *DoOpenStream(Environment &env, UInt32 attr);
	virtual Object *DoGetStatObj(Signal &sig);
	inline uint32_t GetItemId() const { return _itemId; }
	inline Stat *GetStat() const { return _pStat.get(); }
};

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
void DestroyMtpfileList(LIBMTP_file_t *mtpfile);
LIBMTP_filetype_t GetMtpfiletype(const char *fileName);

Gura_EndModuleScope(mtp)

#endif
