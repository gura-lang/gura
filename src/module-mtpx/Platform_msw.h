//=============================================================================
// Platform_msw
//=============================================================================
#ifndef __GURA_MODULE_MTP_PLATFORM_MSW_H__
#define __GURA_MODULE_MTP_PLATFORM_MSW_H__
#include <gura.h>
#include <PortableDeviceApi.h>	// Windows Portable Device API interfaces
#include <PortableDevice.h>		// Windows Portable Device definitions
#include <ATLComTime.h>			// COleDateTime
#include <wrl/client.h>

using namespace Microsoft::WRL;

Gura_BeginModuleScope(mtp)

class DeviceList;
class DeviceOwner;
class Directory_MTP;

//-----------------------------------------------------------------------------
// StringW
//-----------------------------------------------------------------------------
typedef std::basic_string<WCHAR> StringW;

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
class Device {
public:
	class DirectoryFactory {
	private:
		Device *_pDevice;
		ComPtr<IPortableDeviceKeyCollection> _pPortableDeviceKeyCollection;
	public:
		DirectoryFactory(Device *pDevice);
		bool Initialize(Signal &sig);
		Directory_MTP *Create(Signal &sig, Directory *pDirectoryParent, LPCWSTR objectID);
	};
private:
	int _cntRef;
	StringW _deviceID;
	String _friendlyName;
	String _manufacturer;
	String _description;
	ComPtr<IPortableDevice> _pPortableDevice;
	ComPtr<IPortableDeviceContent> _pPortableDeviceContent;
	ComPtr<IPortableDeviceProperties> _pPortableDeviceProperties;
	std::unique_ptr<DirectoryFactory> _pDirectoryFactory;
public:
	Gura_DeclareReferenceAccessor(Device);
public:
	Device(LPCWSTR deviceID);
protected:
	inline ~Device() {}
public:
	bool Open(Signal &sig);
	Directory_MTP *GeneratePartialDirectory(
		Signal &sig, LPCWSTR objectID, const char *pathName, const char **pPathNamePartial) const;
	Directory_MTP *GenerateDirectory(Signal &sig, LPCWSTR objectID, const char *pathName) const;
	inline LPCWSTR GetDeviceID() const { return _deviceID.c_str(); }
	inline IPortableDevice *GetPortableDevice() { return _pPortableDevice.Get(); }
	inline IPortableDeviceContent *GetPortableDeviceContent() { return _pPortableDeviceContent.Get(); }
	inline IPortableDeviceProperties *GetPortableDeviceProperties() { return _pPortableDeviceProperties.Get(); }
	inline void SetFriendlyName(const String &friendlyName) { _friendlyName = friendlyName; }
	inline void SetManufacturer(const String &manufacturer) { _manufacturer = manufacturer; }
	inline void SetDescription(const String &description) { _description = description; }
	inline const char *GetFriendlyName() const { return _friendlyName.c_str(); }
	inline const char *GetManufacturer() const { return _manufacturer.c_str(); }
	inline const char *GetDescription() const { return _description.c_str(); }
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
	StringW _objectID;
	const Symbol *_pStorageType;		// Storage type
	const Symbol *_pFilesystemType;		// Filesystem type
	const Symbol *_pAccessCapability;	// Access capability
	UInt64 _maxCapacity;				// Maximum capability
	UInt64 _freeSpaceInBytes;			// Free space in bytes
	UInt64 _freeSpaceInObjects;			// Free space in objects
	String _storageDescription;			// A brief description of this storage 
	String _volumeIdentifier;			// A volume identifier
public:
	Gura_DeclareReferenceAccessor(Storage);
public:
	Storage(Device *pDevice, LPCWSTR objectID);
protected:
	inline ~Storage() {}
public:
	inline LPCWSTR GetObjectID() const { return _objectID.c_str(); }
	inline const Symbol *GetStorageType() const { return _pStorageType; }
	inline const Symbol *GetFilesystemType() const { return _pFilesystemType; }
	inline const Symbol *GetAccessCapability() const { return _pAccessCapability; }
	inline UInt64 GetMaxCapacity() const { return _maxCapacity; }
	inline UInt64 GetFreeSpaceInBytes() const { return _freeSpaceInBytes; }
	inline UInt64 GetFreeSpaceInObjects() const { return _freeSpaceInObjects; }
	inline const char *GetStorageDescription() const { return _storageDescription.c_str(); }
	inline const char *GetVolumeIdentifier() const { return _volumeIdentifier.c_str(); }
	inline void SetStorageType(const Symbol *pStorageType) { _pStorageType = pStorageType; }
	inline void SetFilesystemType(const Symbol *pFilesystemType) { _pFilesystemType = pFilesystemType; }
	inline void SetAccessCapability(const Symbol *pAccessCapability) { _pAccessCapability = pAccessCapability; }
	inline void SetMaxCapacity(UInt64 maxCapacity) { _maxCapacity = maxCapacity; }
	inline void SetFreeSpaceInBytes(UInt64 freeSpaceInBytes) { _freeSpaceInBytes = freeSpaceInBytes; }
	inline void SetFreeSpaceInObjects(UInt64 freeSpaceInObjects) { _freeSpaceInObjects = freeSpaceInObjects; }
	inline void SetStorageDescription(const char *storageDescription) { _storageDescription = storageDescription; }
	inline void SetVolumeIdentifier(const char *volumeIdentifier) { _volumeIdentifier = volumeIdentifier; }
	inline Directory_MTP *GenerateDirectory(Signal &sig, const char *pathName) const {
		return _pDevice->GenerateDirectory(sig, GetObjectID(), pathName);
	}
	inline Directory_MTP *GeneratePartialDirectory(Signal &sig, const char *pathName,
												   const char **pPathNamePartial) const {
		return _pDevice->GeneratePartialDirectory(sig, GetObjectID(), pathName, pPathNamePartial);
	}
#if 0
	Stream *GenerateReaderStream(Environment &env, const char *pathName) const;
	bool RecvFile(Signal &sig, const char *pathName, Stream *pStream, const Function *pFuncBlock) const;
	bool SendFile(Signal &sig, const char *pathName, Stream *pStream, const Function *pFuncBlock) const;
	bool DeleteFile(Signal &sig, const char *pathName) const;
	bool MoveFile(Signal &sig, const char *pathNameOld, const char *pathNameNew, bool overwriteFlag) const;
	bool CopyFile(Signal &sig, const char *pathNameSrc, const char *pathNameDst, bool overwriteFlag) const;
#endif
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
	bool _folderFlag;
public:
	Gura_DeclareReferenceAccessor(Stat);
public:
	Stat(const String &dirName, const String &fileName, size_t fileSize,
		 const DateTime &dtModification, bool folderFlag);
protected:
	inline ~Stat() {}
public:
	inline const char *GetDirName() const { return _dirName.c_str(); }
	inline const char *GetFileName() const { return _fileName.c_str(); }
	inline size_t GetFileSize() const { return _fileSize; }
	inline const DateTime &GetDtModification() const { return _dtModification; }
	inline bool IsFolder() const { return _folderFlag; }
	String MakePathName() const;
};

//-----------------------------------------------------------------------------
// Directory_MTP declaration
//-----------------------------------------------------------------------------
class Directory_MTP : public Directory {
public:
	class Factory {
	private:
		AutoPtr<Device> _pDevice;
		ComPtr<IPortableDeviceKeyCollection> _pPortableDeviceKeyCollection;
	public:
		Factory(Device *pDevice);
		bool Initialize(Signal &sig);
		Directory_MTP *Create(Signal &sig, Directory *pDirectoryParent, LPCWSTR objectID);
		inline Device *GetDevice() { return _pDevice.get(); }
	};
private:
	Factory _directoryFactory;
	StringW _objectID;
	AutoPtr<Stat> _pStat;
	ComPtr<IEnumPortableDeviceObjectIDs> _pEnumPortableDeviceObjectIDs;
	struct {
		LPWSTR objectIDs[32];
		DWORD nObjectIDs;
		DWORD iObjectID;
		bool lastFlag;
	} _browse;
public:
	Directory_MTP(Directory *pParent, const char *name, Type type,
		Device *pDevice, LPCWSTR objectID, Stat *pStat);
	virtual ~Directory_MTP();
	virtual Directory *DoNext(Environment &env);
	virtual Stream *DoOpenStream(Environment &env, UInt32 attr);
	virtual Object *DoGetStatObj(Signal &sig);
	inline Device *GetDevice() { return _directoryFactory.GetDevice(); }
	inline const LPCWSTR GetObjectID() const { return _objectID.c_str(); }
	void DestroyBrowse();
};

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
String WSTRToString(LPCWSTR wstr);
String HRESULTToString(HRESULT hr);
bool CatchErr(Signal &sig, HRESULT hr);

Gura_EndModuleScope(mtp)

#endif
