//=============================================================================
// Gura module: mtp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(mtp)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// mtp.detect_devices() {block?}
Gura_DeclareFunction(detect_devices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Detects MTP devices and returns a list of `mtp.device` instances.\n");
}

Gura_ImplementFunction(detect_devices)
{
	LIBMTP_raw_device_t *rawDevices = nullptr;
	int nRawDevices = 0;
	Value valueRtn;
	Object_list *pObjList = valueRtn.InitAsList(env);
	LIBMTP_error_number_t err = ::LIBMTP_Detect_Raw_Devices(&rawDevices, &nRawDevices);
	if (err == LIBMTP_ERROR_NONE) {
		// nothing ot do
	} else if (err == LIBMTP_ERROR_NO_DEVICE_ATTACHED) {
		// nothing ot do
	} else { // LIBMTP_ERROR_CONNECTING, LIBMTP_ERROR_MEMORY_ALLOCATION, LIBMTP_ERROR_GENERAL
		env.SetError(ERR_LibraryError, "error occured while detecting devices");
		return Value::Nil;
	}
	for (int i = 0; i < nRawDevices; i++) {
		LIBMTP_mtpdevice_t *mtpDevice = ::LIBMTP_Open_Raw_Device_Uncached(&rawDevices[i]);
		if (mtpDevice == nullptr) continue;
		pObjList->Add(Value(new Object_device(new Device(mtpDevice))));
	}	
	::free(rawDevices);
	return ReturnValue(env, arg, valueRtn);
}

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
	LIBMTP_file_t *mtpfile = ::LIBMTP_Get_Files_And_Folders(mtpDevice, storageId, itemIdParent);
	if (mtpfile == nullptr) {
		::LIBMTP_Dump_Errorstack(mtpDevice);
		::LIBMTP_Clear_Errorstack(mtpDevice);
	} else {
		while (mtpfile != nullptr) {
			if (mtpfile->filetype == LIBMTP_FILETYPE_FOLDER) {
				printf("%*s[%s]\n", indentLevel * 2, "", mtpfile->filename);
				ListFiles(mtpDevice, storageId, mtpfile->item_id, indentLevel + 1);
			} else {
				printf("%*s%s\n", indentLevel * 2, "", mtpfile->filename);
			}
			LIBMTP_file_t *mtpfileNext = mtpfile->next;
			::LIBMTP_destroy_file_t(mtpfile);
			mtpfile = mtpfileNext;
		}
	}
}

Gura_ImplementFunction(test)
{
	LIBMTP_raw_device_t *rawDevices;
	int nRawDevices;
	::printf("libmtp version: %s\n", LIBMTP_VERSION_STRING);
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
	::LIBMTP_Init();
	// Realization of symbol
	Gura_RealizeUserSymbol(Undefined);
	Gura_RealizeUserSymbol(FixedROM);
	Gura_RealizeUserSymbol(RemovableROM);
	Gura_RealizeUserSymbol(FixedRAM);
	Gura_RealizeUserSymbol(RemovableRAM);
	Gura_RealizeUserSymbol(GenericFlat);
	Gura_RealizeUserSymbol(GenericHierarchical);
	Gura_RealizeUserSymbol(DCF);
	Gura_RealizeUserSymbol(ReadWrite);
	Gura_RealizeUserSymbol(ReadOnly);
	Gura_RealizeUserSymbol(ReadOnlyWithObjectDeletion);
	// Realization of class
	Gura_RealizeAndPrepareUserClass(device, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(storage, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(stat, env.LookupClass(VTYPE_object));
	// Assignment of function
	Gura_AssignFunction(detect_devices);
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void DestroyMtpfileList(LIBMTP_file_t *mtpfile)
{
	while (mtpfile != nullptr) {
		LIBMTP_file_t *mtpfileNext = mtpfile->next;
		::LIBMTP_destroy_file_t(mtpfile);
		mtpfile = mtpfileNext;
	}
}

LIBMTP_filetype_t GetMtpfiletype(const char *fileName)
{
	struct Table {
		const char *extName;
		LIBMTP_filetype_t mtpfiletype;
	};
	static const Table tbl[] = {
		{ "wav",	LIBMTP_FILETYPE_WAV					},
		{ "mp3",	LIBMTP_FILETYPE_MP3					},
		{ "wma",	LIBMTP_FILETYPE_WMA					},
		{ "ogg",	LIBMTP_FILETYPE_OGG					},
		{ "mp4",	LIBMTP_FILETYPE_MP4					},
		{ "wmv",	LIBMTP_FILETYPE_WMV					},
		{ "avi",	LIBMTP_FILETYPE_AVI					},
		{ "mpeg",	LIBMTP_FILETYPE_MPEG				},
		{ "mpg",	LIBMTP_FILETYPE_MPEG				},
		{ "asf",	LIBMTP_FILETYPE_ASF					},
		{ "qt",		LIBMTP_FILETYPE_QT					},
		{ "mov",	LIBMTP_FILETYPE_QT					},
		{ "wma",	LIBMTP_FILETYPE_WMA					},
		{ "jpg",	LIBMTP_FILETYPE_JPEG				},
		{ "jpeg",	LIBMTP_FILETYPE_JPEG				},
		{ "jfif",	LIBMTP_FILETYPE_JFIF				},
		{ "tif",	LIBMTP_FILETYPE_TIFF				},
		{ "tiff",	LIBMTP_FILETYPE_TIFF				},
		{ "bmp",	LIBMTP_FILETYPE_BMP					},
		{ "gif",	LIBMTP_FILETYPE_GIF					},
		{ "pic",	LIBMTP_FILETYPE_PICT				},
		{ "pict",	LIBMTP_FILETYPE_PICT				},
		{ "png",	LIBMTP_FILETYPE_PNG					},
		{ "wmf",	LIBMTP_FILETYPE_WINDOWSIMAGEFORMAT	},
		{ "ics",	LIBMTP_FILETYPE_VCALENDAR2			},
		{ "exe",	LIBMTP_FILETYPE_WINEXEC				},
		{ "com",	LIBMTP_FILETYPE_WINEXEC				},
		{ "bat",	LIBMTP_FILETYPE_WINEXEC				},
		{ "dll",	LIBMTP_FILETYPE_WINEXEC				},
		{ "sys",	LIBMTP_FILETYPE_WINEXEC				},
		{ "aac",	LIBMTP_FILETYPE_AAC					},
		{ "mp2",	LIBMTP_FILETYPE_MP2					},
		{ "flac",	LIBMTP_FILETYPE_FLAC				},
		{ "m4a",	LIBMTP_FILETYPE_M4A					},
		{ "doc",	LIBMTP_FILETYPE_DOC					},
		{ "xml",	LIBMTP_FILETYPE_XML					},
		{ "xls",	LIBMTP_FILETYPE_XLS					},
		{ "ppt",	LIBMTP_FILETYPE_PPT					},
		{ "mht",	LIBMTP_FILETYPE_MHT					},
		{ "jp2",	LIBMTP_FILETYPE_JP2					},
		{ "jpx",	LIBMTP_FILETYPE_JPX					},
		{ "bin",	LIBMTP_FILETYPE_FIRMWARE			},
		{ "vcf",	LIBMTP_FILETYPE_VCARD3				},
	};
	const char *extName = ::strrchr(fileName, '.');
	if (extName == nullptr) return LIBMTP_FILETYPE_UNKNOWN;
	extName++;
	for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
		if (::strcasecmp(extName, tbl[i].extName) == 0) return tbl[i].mtpfiletype;
	}
	return LIBMTP_FILETYPE_UNKNOWN;
}

Gura_EndModuleBody(mtp, mtp)

Gura_RegisterModule(mtp)
