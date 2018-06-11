//=============================================================================
// Gura module: mtp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(mtp)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// mtp.test():void
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"MTP Test\n");
}

void ListFiles(LIBMTP_mtpdevice_t *mtpDevice, uint32_t storageId, uint32_t itemIdParent, int indentLevel)
{
	LIBMTP_file_t *fileInfo = ::LIBMTP_Get_Files_And_Folders(mtpDevice, storageId, itemIdParent);
	if (fileInfo == nullptr) {
		::LIBMTP_Dump_Errorstack(mtpDevice);
		::LIBMTP_Clear_Errorstack(mtpDevice);
	} else {
		while (fileInfo != nullptr) {
			if (fileInfo->filetype == LIBMTP_FILETYPE_FOLDER) {
				printf("%*s[%s]\n", indentLevel * 2, "", fileInfo->filename);
				ListFiles(mtpDevice, storageId, fileInfo->item_id, indentLevel + 1);
			} else {
				printf("%*s%s\n", indentLevel * 2, "", fileInfo->filename);
			}
			LIBMTP_file_t *fileInfoNext = fileInfo->next;
			::LIBMTP_destroy_file_t(fileInfo);
			fileInfo = fileInfoNext;
		}
	}
}

Gura_ImplementFunction(test)
{
	LIBMTP_raw_device_t *rawDevices;
	int nRawDevices;
	::printf("libmtp version: %s\n", LIBMTP_VERSION_STRING);
	::LIBMTP_Init();

	LIBMTP_error_number_t err = ::LIBMTP_Detect_Raw_Devices(&rawDevices, &nRawDevices);
	if (err == LIBMTP_ERROR_NO_DEVICE_ATTACHED) {
	} else if (err == LIBMTP_ERROR_CONNECTING) {
	} else if (err == LIBMTP_ERROR_MEMORY_ALLOCATION) {
	} else if (err == LIBMTP_ERROR_GENERAL) {
	} // else if (err == LIBMTP_ERROR_NONE)
	for (int i = 0; i < nRawDevices; i++) {
		LIBMTP_mtpdevice_t *mtpDevice = ::LIBMTP_Open_Raw_Device_Uncached(&rawDevices[i]);
		if (mtpDevice == nullptr) {
			continue;
		}
		const char *friendlyName = LIBMTP_Get_Friendlyname(mtpDevice); // may be nullptr
		::printf("%s\n", friendlyName);
		LIBMTP_devicestorage_t *deviceStorage;
		for (deviceStorage = mtpDevice->storage; deviceStorage != nullptr; deviceStorage = deviceStorage->next) {
			ListFiles(mtpDevice, deviceStorage->id, LIBMTP_FILES_AND_FOLDERS_ROOT, 0);
		}
		::LIBMTP_Release_Device(mtpDevice);
	}
	::free(rawDevices);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entry
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// Realization of class
	Gura_RealizeAndPrepareUserClass(device, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(storage, env.LookupClass(VTYPE_object));
	// Assignment of function
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(mtp, mtp)

Gura_RegisterModule(mtp)
