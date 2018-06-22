//=============================================================================
// Gura class: mtp.storage
//=============================================================================
#ifndef __GURA_MODULE_MTP_CLASS_STORAGE_H__
#define __GURA_MODULE_MTP_CLASS_STORAGE_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Storage
//-----------------------------------------------------------------------------
class Storage {
private:
	int _cntRef;
	AutoPtr<Device> _pDevice;
	uint32_t _id;					// Unique ID for this storage
	uint16_t _storageType;			// Storage type
	uint16_t _filesystemType;		// Filesystem type
	uint16_t _accessCapability;		// Access capability
	uint64_t _maxCapacity;			// Maximum capability
	uint64_t _freeSpaceInBytes;		// Free space in bytes
	uint64_t _freeSpaceInObjects;	// Free space in objects
	String _storageDescription;		// A brief description of this storage 
	String _volumeIdentifier;		// A volume identifier
public:
	Gura_DeclareReferenceAccessor(Storage);
public:
	Storage(Device *pDevice, LIBMTP_devicestorage_t *deviceStorage);
protected:
	inline ~Storage() {}
public:
	inline uint32_t GetId() const { return _id; }
	inline uint16_t GetStorageType() const { return _storageType; }
	inline uint16_t GetFilesystemType() const { return _filesystemType; }
	inline uint16_t GetAccessCapability() const { return _accessCapability; }
	inline uint64_t GetMaxCapacity() const { return _maxCapacity; }
	inline uint64_t GetFreeSpaceInBytes() const { return _freeSpaceInBytes; }
	inline uint64_t GetFreeSpaceInObjects() const { return _freeSpaceInObjects; }
	inline const char *GetStorageDescription() const { return _storageDescription.c_str(); }
	inline const char *GetVolumeIdentifier() { return _volumeIdentifier.c_str(); }
	inline Directory_MTP *GenerateDirectory(Signal &sig, const char *pathName) const {
		return _pDevice->GenerateDirectory(sig, _id, pathName);
	}
	Stream *GenerateReaderStream(Environment &env, const char *pathName) const;
	bool RecvFile(Signal &sig, const char *pathName, Stream *pStream, const Function *pFuncBlock) const;
	bool SendFile(Signal &sig, const char *pathName, Stream *pStream, const Function *pFuncBlock) const;
	bool DeleteFile(Signal &sig, const char *pathName) const;
	bool MoveFile(Signal &sig, const char *pathNameOld, const char *pathNameNew) const;
	bool CopyFile(Signal &sig, const char *pathNameSrc, const char *pathNameDst) const;
	static uint16_t Callback_RecvFile(
		void *params, void *priv, uint32_t sendlen, unsigned char *data, uint32_t *putlen);
	static uint16_t Callback_SendFile(
		void *params, void *priv, uint32_t wantlen, unsigned char *data, uint32_t *gotlen);
	static int Callback_Progress(
		uint64_t const sent, uint64_t const total, void const * const data);
};

//-----------------------------------------------------------------------------
// Object_storage declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(storage);

class Object_storage : public Object {
private:
	AutoPtr<Storage> _pStorage;
public:
	Gura_DeclareObjectAccessor(storage)
public:
	Object_storage(Storage *pStorage);
	virtual String ToString(bool exprFlag);
	inline Storage *GetStorage() const { return _pStorage.get(); }
};

Gura_EndModuleScope(mtp)

#endif
