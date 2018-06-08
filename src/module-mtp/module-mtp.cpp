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
			LIBMTP_file_t *files = ::LIBMTP_Get_Files_And_Folders(
				mtpDevice, deviceStorage->id, LIBMTP_FILES_AND_FOLDERS_ROOT);
			if (files == nullptr) {
				::LIBMTP_Dump_Errorstack(mtpDevice);
				::LIBMTP_Clear_Errorstack(mtpDevice);
			} else {
				LIBMTP_file_t *file, *tmp;
				file = files;
				while (file != nullptr) {
					printf("Filename: %s\n", file->filename);
					if (file->filetype == LIBMTP_FILETYPE_FOLDER) {
						//dump_files(device, storageid, file->item_id);
					} else {
						
						//dump_fileinfo(file);
					}
					tmp = file;
					file = file->next;
					::LIBMTP_destroy_file_t(tmp);
				}
			}
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
	// Assignment of function
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(mtp, mtp)

Gura_RegisterModule(mtp)
