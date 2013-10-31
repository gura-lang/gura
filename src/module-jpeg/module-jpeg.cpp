//-----------------------------------------------------------------------------
// Gura jpeg module
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "Object_exif.h"

Gura_BeginModuleBody(jpeg)

// 4.6.4 TIFF Rev.6.0 Attribute Information
static const TagInfo g_tagInfoTbl[] = {
	// A. Tags relating to image data structure
	{ TAG_ImageWidth,					"ImageWidth",					TYPE_LONG,		NULL,				},
	{ TAG_ImageLength,					"ImageLength",					TYPE_LONG,		NULL,				},
	{ TAG_BitsPerSample,				"BitsPerSample",				TYPE_SHORT,		NULL,				},
	{ TAG_Compression,					"Compression",					TYPE_SHORT,		NULL,				},
	{ TAG_PhotometricInterpretation,	"PhotometricInterpretation",	TYPE_SHORT,		NULL,				},
	{ TAG_Orientation,					"Orientation",					TYPE_SHORT,		NULL,				},
	{ TAG_SamplesPerPixel,				"SamplesPerPixel",				TYPE_SHORT,		NULL,				},
	{ TAG_PlanarConfiguration,			"PlanarConfiguration",			TYPE_SHORT,		NULL,				},
	{ TAG_YCbCrSubSampling,				"YCbCrSubSampling",				TYPE_SHORT,		NULL,				},
	{ TAG_YCbCrPositioning,				"YCbCrPositioning",				TYPE_SHORT,		NULL,				},
	{ TAG_XResolution,					"XResolution",					TYPE_RATIONAL,	NULL,				},
	{ TAG_YResolution,					"YResolution",					TYPE_RATIONAL,	NULL,				},
	{ TAG_ResolutionUnit,				"ResolutionUnit",				TYPE_SHORT,		NULL,				},
	// B. Tags relating to recording offset
	{ TAG_StripOffsets,					"StripOffsets",					TYPE_LONG,		NULL,				},
	{ TAG_RowsPerStrip,					"RowsPerStrip",					TYPE_LONG,		NULL,				},
	{ TAG_StripByteCounts,				"StripByteCounts",				TYPE_LONG,		NULL,				},
	{ TAG_JPEGInterchangeFormat,		"JPEGInterchangeFormat",		TYPE_LONG,		NULL,				},
	{ TAG_JPEGInterchangeFormatLength,	"JPEGInterchangeFormatLength",	TYPE_LONG,		NULL,				},
	// C. Tags relating to image data characteristics
	{ TAG_TransferFunction,				"TransferFunction",				TYPE_SHORT,		NULL,				},
	{ TAG_WhitePoint,					"WhitePoint",					TYPE_RATIONAL,	NULL,				},
	{ TAG_PrimaryChromaticities,		"PrimaryChromaticities",		TYPE_RATIONAL,	NULL,				},
	{ TAG_YCbCrCoefficients,			"YCbCrCoefficients",			TYPE_RATIONAL,	NULL,				},
	{ TAG_ReferenceBlackWhite,			"ReferenceBlackWhite",			TYPE_RATIONAL,	NULL,				},
	// D. Other tags
	{ TAG_DateTime,						"DateTime",						TYPE_ASCII,		NULL,				},
	{ TAG_ImageDescription,				"ImageDescription",				TYPE_ASCII,		NULL,				},
	{ TAG_Make,							"Make",							TYPE_ASCII,		NULL,				},
	{ TAG_Model,						"Model",						TYPE_ASCII,		NULL,				},
	{ TAG_Software,						"Software",						TYPE_ASCII,		NULL,				},
	{ TAG_Artist,						"Artist",						TYPE_ASCII,		NULL,				},
	{ TAG_Copyright,					"Copyright",					TYPE_ASCII,		NULL,				},
	// Pointers
	{ TAG_ExifIFDPointer,				"ExifIFDPointer",				TYPE_LONG,		"Exif",				},
	{ TAG_GPSInfoIFDPointer,			"GPSInfoIFDPointer",			TYPE_LONG,		"GPSInfo",			},
	{ TAG_invalid,						NULL,							TYPE_UNDEFINED,	NULL,				},
};

// 4.6.5 Exif IFD Attribute Information
static const TagInfo g_tagInfoTbl_Exif[] = {
	// A. Tags Relating to Version
	{ TAG_ExifVersion,					"ExifVersion",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_FlashPixVersion,				"FlashPixVersion",				TYPE_UNDEFINED,	NULL,				},
	// B. Tag Relating to Image Data Characteristics
	{ TAG_ColorSpace,					"ColorSpace",					TYPE_SHORT,		NULL,				},
	// C. Tags Relating to Image Configuration
	{ TAG_ComponentsConfiguration,		"ComponentsConfiguration",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_CompressedBitsPerPixel,		"CompressedBitsPerPixel",		TYPE_RATIONAL,	NULL,				},
	{ TAG_PixelXDimension,				"PixelXDimension",				TYPE_LONG,		NULL,				},
	{ TAG_PixelYDimension,				"PixelYDimension",				TYPE_LONG,		NULL,				},
	// D. Tags Relating to User Information
	{ TAG_MakerNote,					"MakerNote",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_UserComment,					"UserComment",					TYPE_UNDEFINED,	NULL,				},
	// E. Tags Relating to Related File Information
	{ TAG_RelatedSoundFile,				"RelatedSoundFile",				TYPE_ASCII,		NULL,				},
	// F. Tags Relating to Date and Time
	{ TAG_DateTimeOriginal,				"DateTimeOriginal",				TYPE_ASCII,		NULL,				},
	{ TAG_DateTimeDigitized,			"DateTimeDigitized",			TYPE_ASCII,		NULL,				},
	{ TAG_SubSecTime,					"SubSecTime",					TYPE_ASCII,		NULL,				},
	{ TAG_SubSecTimeOriginal,			"SubSecTimeOriginal",			TYPE_ASCII,		NULL,				},
	{ TAG_SubSecTimeDigitized,			"SubSecTimeDigitized",			TYPE_ASCII,		NULL,				},
	// G. Tags Relating to Picture-Taking Conditions
	{ TAG_ExposureTime,					"ExposureTime",					TYPE_RATIONAL,	NULL,				},
	{ TAG_FNumber,						"FNumber",						TYPE_RATIONAL,	NULL,				},
	{ TAG_ExposureProgram,				"ExposureProgram",				TYPE_SHORT,		NULL,				},
	{ TAG_SpectralSensitivity,			"SpectralSensitivity",			TYPE_ASCII,		NULL,				},
	{ TAG_ISOSpeedRatings,				"ISOSpeedRatings",				TYPE_SHORT,		NULL,				},
	{ TAG_OECF,							"OECF",							TYPE_UNDEFINED,	NULL,				},
	{ TAG_ShutterSpeedValue,			"ShutterSpeedValue",			TYPE_SRATIONAL,	NULL,				},
	{ TAG_ApertureValue,				"ApertureValue",				TYPE_RATIONAL,	NULL,				},
	{ TAG_BrightnessValue,				"BrightnessValue",				TYPE_SRATIONAL,	NULL,				},
	{ TAG_ExposureBiasValue,			"ExposureBiasValue",			TYPE_SRATIONAL,	NULL,				},
	{ TAG_MaxApertureValue,				"MaxApertureValue",				TYPE_RATIONAL,	NULL,				},
	{ TAG_SubjectDistance,				"SubjectDistance",				TYPE_RATIONAL,	NULL,				},
	{ TAG_MeteringMode,					"MeteringMode",					TYPE_SHORT,		NULL,				},
	{ TAG_LightSource,					"LightSource",					TYPE_SHORT,		NULL,				},
	{ TAG_Flash,						"Flash",						TYPE_SHORT,		NULL,				},
	{ TAG_FocalLength,					"FocalLength",					TYPE_RATIONAL,	NULL,				},
	{ TAG_SubjectArea,					"SubjectArea",					TYPE_SHORT,		NULL,				},
	{ TAG_FlashEnergy,					"FlashEnergy",					TYPE_RATIONAL,	NULL,				},
	{ TAG_SpatialFrequencyResponse,		"SpatialFrequencyResponse",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_FocalPlaneXResolution,		"FocalPlaneXResolution",		TYPE_RATIONAL,	NULL,				},
	{ TAG_FocalPlaneYResolution,		"FocalPlaneYResolution",		TYPE_RATIONAL,	NULL,				},
	{ TAG_FocalPlaneResolutionUnit,		"FocalPlaneResolutionUnit",		TYPE_SHORT,		NULL,				},
	{ TAG_SubjectLocation,				"SubjectLocation",				TYPE_SHORT,		NULL,				},
	{ TAG_ExposureIndex,				"ExposureIndex",				TYPE_RATIONAL,	NULL,				},
	{ TAG_SensingMethod,				"SensingMethod",				TYPE_SHORT,		NULL,				},
	{ TAG_FileSource,					"FileSource",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_SceneType,					"SceneType",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_CFAPattern,					"CFAPattern",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_CustomRendered,				"CustomRendered",				TYPE_SHORT,		NULL,				},
	{ TAG_ExposureMode,					"ExposureMode",					TYPE_SHORT,		NULL,				},
	{ TAG_WhiteBalance,					"WhiteBalance",					TYPE_SHORT,		NULL,				},
	{ TAG_DigitalZoomRatio,				"DigitalZoomRatio",				TYPE_RATIONAL,	NULL,				},
	{ TAG_FocalLengthIn35mmFilm,		"FocalLengthIn35mmFilm",		TYPE_SHORT,		NULL,				},
	{ TAG_SceneCaptureType,				"SceneCaptureType",				TYPE_SHORT,		NULL,				},
	{ TAG_GainControl,					"GainControl",					TYPE_RATIONAL,	NULL,				},
	{ TAG_Contrast,						"Contrast",						TYPE_SHORT,		NULL,				},
	{ TAG_Saturation,					"Saturation",					TYPE_SHORT,		NULL,				},
	{ TAG_Sharpness,					"Sharpness",					TYPE_SHORT,		NULL,				},
	{ TAG_DeviceSettingDescription,		"DeviceSettingDescription",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_SubjectDistanceRange,			"SubjectDistanceRange",			TYPE_SHORT,		NULL,				},
	// H. Other Tags
	{ TAG_ImageUniqueID,				"ImageUniqueID",				TYPE_ASCII,		NULL,				},
	// Pointers
	{ TAG_InteroperabilityIFDPointer,	"InteroperabilityIFDPointer",	TYPE_LONG,		"Interoperability"	},
	{ TAG_invalid,						NULL,							TYPE_UNDEFINED,	NULL,				},
};

// 4.6.6 GPS Attribute Information
static const TagInfo g_tagInfoTbl_GPSInfo[] = {
	// A. Tags Relating to GPS
	{ TAG_GPSVersionID,					"GPSVersionID",					TYPE_BYTE,		NULL,				},
	{ TAG_GPSLatitudeRef,				"GPSLatitudeRef",				TYPE_ASCII,		NULL,				},
	{ TAG_GPSLatitude,					"GPSLatitude",					TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSLongitudeRef,				"GPSLongitudeRef",				TYPE_ASCII,		NULL,				},
	{ TAG_GPSLongitude,					"GPSLongitude",					TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSAltitudeRef,				"GPSAltitudeRef",				TYPE_BYTE,		NULL,				},
	{ TAG_GPSAltitude,					"GPSAltitude",					TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSTimeStamp,					"GPSTimeStamp",					TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSSatellites,				"GPSSatellites",				TYPE_ASCII,		NULL,				},
	{ TAG_GPSStatus,					"GPSStatus",					TYPE_ASCII,		NULL,				},
	{ TAG_GPSMeasureMode,				"GPSMeasureMode",				TYPE_ASCII,		NULL,				},
	{ TAG_GPSDOP,						"GPSDOP",						TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSSpeedRef,					"GPSSpeedRef",					TYPE_ASCII,		NULL,				},
	{ TAG_GPSSpeed,						"GPSSpeed",						TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSTrackRef,					"GPSTrackRef",					TYPE_ASCII,		NULL,				},
	{ TAG_GPSTrack,						"GPSTrack",						TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSImgDirectionRef,			"GPSImgDirectionRef",			TYPE_ASCII,		NULL,				},
	{ TAG_GPSImgDirection,				"GPSImgDirection",				TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSMapDatum,					"GPSMapDatum",					TYPE_ASCII,		NULL,				},
	{ TAG_GPSDestLatitudeRef,			"GPSDestLatitudeRef",			TYPE_ASCII,		NULL,				},
	{ TAG_GPSDestLatitude,				"GPSDestLatitude",				TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSDestLongitudeRef,			"GPSDestLongitudeRef",			TYPE_ASCII,		NULL,				},
	{ TAG_GPSDestLongitude,				"GPSDestLongitude",				TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSBearingRef,				"GPSBearingRef",				TYPE_ASCII,		NULL,				},
	{ TAG_GPSBearing,					"GPSBearing",					TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSDestDistanceRef,			"GPSDestDistanceRef",			TYPE_ASCII,		NULL,				},
	{ TAG_GPSDestDistance,				"GPSDestDistance",				TYPE_RATIONAL,	NULL,				},
	{ TAG_GPSProcessingMethod,			"GPSProcessingMethod",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSAreaInformation,			"GPSAreaInformation",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSDateStamp,					"GPSDateStamp",					TYPE_ASCII,		NULL,				},
	{ TAG_GPSDifferential,				"GPSDifferential",				TYPE_SHORT,		NULL,				},
	{ TAG_invalid,						NULL,							TYPE_UNDEFINED,	NULL,				},
};

// 4.6.7 Interoperability IFD Attribute Information
static const TagInfo g_tagInfoTbl_Interoperability[] = {
	{ TAG_InteroperabilityIndex,		"InteroperabilityIndex",		TYPE_ASCII,		NULL,				},
	{ TAG_InteroperabilityVersion,		"InteroperabilityVersion",		TYPE_BYTE,		NULL,				},
	{ TAG_RelatedImageWidth,			"RelatedImageWidth",			TYPE_SHORT,		NULL,				},
	{ TAG_RelatedImageHeight,			"RelatedImageHeight",			TYPE_SHORT,		NULL,				},
	{ TAG_invalid,						NULL,							TYPE_UNDEFINED,	NULL,				},
};


static const TypeInfo g_typeInfoTbl[] = {
	{ TYPE_BYTE,		"BYTE",			UNITSIZE_BYTE,		},
	{ TYPE_ASCII,		"ASCII",		UNITSIZE_ASCII,		},
	{ TYPE_SHORT,		"SHORT",		UNITSIZE_SHORT,		},
	{ TYPE_LONG,		"LONG",			UNITSIZE_LONG,		},
	{ TYPE_RATIONAL,	"RATIONAL",		UNITSIZE_RATIONAL,	},
	{ TYPE_UNDEFINED,	"UNDEFINED",	UNITSIZE_UNDEFINED,	},
	{ TYPE_SLONG,		"SLONG",		UNITSIZE_SLONG,		},
	{ TYPE_SRATIONAL,	"SRATIONAL",	UNITSIZE_SRATIONAL,	},
};

SymbolAssocOwner g_symbolAssocOwner;

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing jpeg module.
//-----------------------------------------------------------------------------
// image#jpegread(stream:stream:r):reduce
Gura_DeclareMethod(image, jpegread)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Reads a JPEG image from a stream.");
}

Gura_ImplementMethod(image, jpegread)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_JPEG::ReadStream(env, sig, pThis->GetImage(), args.GetStream(0))) {
		return Value::Null;
	}
	return args.GetThis();
}

// image#jpegwrite(stream:stream:w, quality:number => 75):reduce
Gura_DeclareMethod(image, jpegwrite)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_Once,
										FLAG_None, new Expr_Value(75));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Writes a JPEG image to a stream.");
}

Gura_ImplementMethod(image, jpegwrite)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_JPEG::WriteStream(env, sig,
							pThis->GetImage(), args.GetStream(0), args.GetInt(1))) {
		return Value::Null;
	}
	return args.GetThis();
}

// jpeg.exif(stream?:stream) {block?}
Gura_DeclareFunction(exif)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(raise));
	SetClassToConstruct(Gura_UserClass(exif));
}

Gura_ImplementFunction(exif)
{
	Value value;
	if (args.IsStream(0)) {
		Object_exif *pObj = Object_exif::ReadStream(env, sig, args.GetStream(0));
		if (sig.IsSignalled()) return Value::Null;
		if (pObj != NULL) {
			value = Value(pObj);
		} else if (args.IsSet(Gura_Symbol(raise))) {
			sig.SetError(ERR_FormatError, "Exif information doesn't exist");
			return Value::Null;
		}
	} else {
		Object_exif *pObj = new Object_exif();
		value = Value(pObj);
	}
	return ReturnValue(env, sig, args, value);
}

// jpeg.test()
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura module functions: jpeg
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(endian);
	Gura_RealizeUserSymbol(big);
	Gura_RealizeUserSymbol(little);
	Gura_RealizeUserSymbol(uncompressed);
	Gura_RealizeUserSymbol(id);
	Gura_RealizeUserSymbol(name);
	Gura_RealizeUserSymbol(symbol);
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(value);
	Gura_RealizeUserSymbol(ifd);
	Gura_RealizeUserSymbol(ifd0);
	Gura_RealizeUserSymbol(ifd1);
	Gura_RealizeUserSymbol(thumbnail);
	Gura_RealizeUserSymbol(thumbnail_jpeg);
	Gura_RealizeUserSymbol(Exif);
	Gura_RealizeUserSymbol(Interoperability);
	Gura_RealizeUserSymbol(GPSInfo);
	// class realization
	Gura_RealizeUserClass(tag, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(ifd, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(exif, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(exif);
	Gura_AssignFunction(test);
	// method assignment to image
	Gura_AssignMethodTo(VTYPE_image, image, jpegread);
	Gura_AssignMethodTo(VTYPE_image, image, jpegwrite);
	// image streamer registration
	ImageStreamer::Register(new ImageStreamer_JPEG());
	do {
		const UShort tagId = TAG_Compression;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"uncompressed",					NULL,	},
			{ 6,		"JPEG",							NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_PhotometricInterpretation;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 2,		"RGB",							NULL,	},
			{ 6,		"YCbCr",						NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Orientation;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"LeftTopVert",					NULL,	},
			{ 2,		"RightTopVert",					NULL,	},
			{ 3,		"RightBottomVert",				NULL,	},
			{ 4,		"LefBottomVert",				NULL,	},
			{ 5,		"LeftTopHorz",					NULL,	},
			{ 6,		"RightTopHorz",					NULL,	},
			{ 7,		"RightBottomHorz",				NULL,	},
			{ 8,		"LeftBottomHorz",				NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_PlanarConfiguration;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"chunky",						NULL,	},
			{ 2,		"planar",						NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_YCbCrPositioning;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"centered",						NULL,	},
			{ 2,		"cosited",						NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ResolutionUnit;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 2,		"inches",						NULL,	},
			{ 3,		"centimeters",					NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ColorSpace;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"sRGB",							NULL,	},
			{ 0xffff,	"uncalibrated",					NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ComponentsConfiguration;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"not_exist",					NULL,	},
			{ 1,		"Y",							NULL,	},
			{ 2,		"Cb",							NULL,	},
			{ 3,		"Cr",							NULL,	},
			{ 4,		"R",							NULL,	},
			{ 5,		"G",							NULL,	},
			{ 6,		"B",							NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ExposureProgram;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"NotDefined",					NULL,	},
			{ 1,		"Manual",						NULL,	},
			{ 2,		"NormalProgram",				NULL,	},
			{ 3,		"AperturePriority",				NULL,	},
			{ 4,		"ShutterPriority",				NULL,	},
			{ 5,		"CreativeProgram",				NULL,	},
			{ 6,		"ActionProgram",				NULL,	},
			{ 7,		"PortraitMode",					NULL,	},
			{ 8,		"LandscapeMode",				NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);

	do {
		const UShort tagId = TAG_MeteringMode;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"unknown",						NULL,	},
			{ 1,		"Average",						NULL,	},
			{ 2,		"CenterWeightedAverage",		NULL,	},
			{ 3,		"Spot",							NULL,	},
			{ 4,		"MultiSpot",					NULL,	},
			{ 5,		"Pattern",						NULL,	},
			{ 6,		"Partial",						NULL,	},
			{ 255,		"other",						NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_LightSource;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"unknown",						NULL,	},
			{ 1,		"Daylight",						NULL,	},
			{ 2,		"Fluorescent",					NULL,	},
			{ 3,		"Tungsten",						NULL,	},
			{ 4,		"Flash",						NULL,	},
			{ 9,		"FineWeather",					NULL,	},
			{ 10,		"CloudyWeather",				NULL,	},
			{ 11,		"Shade",						NULL,	},
			{ 12,		"DaylightFluorescent",			NULL,	},
			{ 13,		"DayWhiteFluorescent",			NULL,	},
			{ 14,		"CoolWhiteFluorescent",			NULL,	},
			{ 15,		"WhiteFluorescent",				NULL,	},
			{ 17,		"StandardLightA",				NULL,	},
			{ 18,		"StandardLightB",				NULL,	},
			{ 19,		"StandardLightC",				NULL,	},
			{ 20,		"D55",							NULL,	},
			{ 21,		"D65",							NULL,	},
			{ 22,		"D75",							NULL,	},
			{ 23,		"D50",							NULL,	},
			{ 24,		"ISOStudioTungsten",			NULL,	},
			{ 255,		"OtherLightSource",				NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Flash;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0x0000,	"FlashDidNotFire",																NULL,	},
			{ 0x0001,	"FlashFired",																	NULL,	},
			{ 0x0005,	"StrobeReturnLightNotDetected",													NULL,	},
			{ 0x0007,	"StrobeReturnLightDetected",													NULL,	},
			{ 0x0009,	"FlashFired_CompulsoryFlashMode",												NULL,	},
			{ 0x000d,	"FlashFired_CompulsoryFlashMode_ReturnLightNotDetected",						NULL,	},
			{ 0x000f,	"FlashFired_CompulsoryFlashMode_ReturnLightDetected",							NULL,	},
			{ 0x0010,	"FlashDidNotFire_CompulsoryFlashMode",											NULL,	},
			{ 0x0018,	"FlashDidNotFire_AutoMode",														NULL,	},
			{ 0x0019,	"FlashFired_AutoMode",															NULL,	},
			{ 0x001d,	"FlashFired_AutoMode_ReturnLightNotDetected",									NULL,	},
			{ 0x001f,	"FlashFired_AutoMode_ReturnLightDetected",										NULL,	},
			{ 0x0020,	"NoFlashFunction",																NULL,	},
			{ 0x0041,	"FlashFired_RedEyeReductionMode",												NULL,	},
			{ 0x0045,	"FlashFired_RedEyeReductionMode_ReturnLightNotDetected",						NULL,	},
			{ 0x0047,	"FlashFired_RedEyeReductionMode_ReturnLightDetected",							NULL,	},
			{ 0x0049,	"FlashFired_CompulsoryFlashMode_RedEyeReductionMode",							NULL,	},
			{ 0x004d,	"FlashFired_CompulsoryFlashMode_RedEyeReductionMode_ReturnLightNotDetected",	NULL,	},
			{ 0x004f,	"FlashFired_CompulsoryFlashMode_RedEyeReductionMode_ReturnLightDetected",		NULL,	},
			{ 0x0059,	"FlashFired_AutoMode_RedEyeReductionMode",										NULL,	},
			{ 0x005d,	"FlashFired_AutoMode_ReturnLightNotDetected_RedEyeReductionMode",				NULL,	},
			{ 0x005f,	"FlashFired_AutoMode_ReturnLightDetected_RedEyeReductionMode",					NULL,	},
			{ 0,		NULL,																			NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_FocalPlaneResolutionUnit;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 2,		"inches",						NULL,	},
			{ 3,		"centimeters",					NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_SensingMethod;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"NotDefined",					NULL,	},
			{ 2,		"OneChipColorAreaSensor",		NULL,	},
			{ 3,		"TwoChipColorAreaSensor",		NULL,	},
			{ 4,		"ThreeChipColorAreaSensor",		NULL,	},
			{ 5,		"ColorSequentialAreaSensor",	NULL,	},
			{ 7,		"TrilinearSensor",				NULL,	},
			{ 8,		"ColorSequentialLinearSensor",	NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_FileSource;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 3,		"DSC",							NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_SceneType;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"DirectlyPhotographedImage",	NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_CustomRendered;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"NormalProces",					NULL,	},
			{ 1,		"CustomProcess",				NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ExposureMode;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"AutoExposure",					NULL,	},
			{ 1,		"ManualExposure",				NULL,	},
			{ 2,		"AutoBracket",					NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_WhiteBalance;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"AutoWhiteBalance",				NULL,	},
			{ 1,		"ManualWhiteBalance",			NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_SceneCaptureType;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"Standard",						NULL,	},
			{ 1,		"Landscape",					NULL,	},
			{ 2,		"Portrait",						NULL,	},
			{ 3,		"NightScene",					NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_GainControl;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"None",							NULL,	},
			{ 1,		"LowGainUp",					NULL,	},
			{ 2,		"HighGainUp",					NULL,	},
			{ 3,		"LowGainDown",					NULL,	},
			{ 4,		"HighGainDown",					NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Contrast;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"Normal",						NULL,	},
			{ 1,		"Soft",							NULL,	},
			{ 2,		"Hard",							NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Saturation;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"Normal",						NULL,	},
			{ 1,		"LowSaturation",				NULL,	},
			{ 2,		"HighSaturation",				NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Sharpness;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"Normal",						NULL,	},
			{ 1,		"Soft",							NULL,	},
			{ 2,		"Hard",							NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_SubjectDistanceRange;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"unknown",						NULL,	},
			{ 1,		"Macro",						NULL,	},
			{ 2,		"CloseView",					NULL,	},
			{ 3,		"DistantView",					NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_GPSAltitudeRef;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"SeaLevel",						NULL,	},
			{ 1,		"SeaLavelReference",			NULL,	},
			{ 0,		NULL,							NULL,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_JPEG
//-----------------------------------------------------------------------------
bool ImageStreamer_JPEG::IsResponsible(Signal sig, Stream &stream)
{
	if (stream.IsReadable()) {
		char buff[2];
		size_t bytesPeeked = stream.Peek(sig, buff, 2);
		if (sig.IsSignalled()) return false;
		// byte sequence "\xff\xd8" is SOI (Start of Image) marker in JPEG
		if (bytesPeeked == 2 && ::memcmp(buff, "\xff\xd8", 2) == 0) return true;
	}
	return stream.HasNameSuffix(".jpg") ||
				stream.HasNameSuffix(".jpeg") || stream.HasNameSuffix(".jpe");
}

bool ImageStreamer_JPEG::Read(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return ReadStream(env, sig, pImage, stream);
}

bool ImageStreamer_JPEG::Write(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return WriteStream(env, sig, pImage, stream, 75);
}

bool ImageStreamer_JPEG::ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckEmpty(sig)) return false;
	ErrorMgr errMgr(sig);
	jpeg_decompress_struct cinfo;
	cinfo.err = ::jpeg_std_error(&errMgr.pub);
	errMgr.pub.error_exit = ErrorMgr::error_exit; // override error handler
	::jpeg_create_decompress(&cinfo);
	if (::setjmp(errMgr.jmpenv)) {
		::jpeg_destroy_decompress(&cinfo);
		return false;
	}
	SourceMgr::Setup(&cinfo, &sig, &stream);
	::jpeg_read_header(&cinfo, TRUE);
	::jpeg_start_decompress(&cinfo);
	if (!pImage->AllocBuffer(sig, cinfo.image_width, cinfo.image_height, 0xff)) {
		::jpeg_destroy_decompress(&cinfo);
		return false;
	}
	//::memset(pThis->GetBuffer(), 0xff, pThis->GetBufferSize());
	JSAMPARRAY scanlines = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo,
					JPOOL_IMAGE, cinfo.output_width * cinfo.output_components, 1);
	while (cinfo.output_scanline < cinfo.output_height) {
		::jpeg_read_scanlines(&cinfo, scanlines, 1);
		if (sig.IsSignalled()) {
			::jpeg_finish_decompress(&cinfo);
			::jpeg_destroy_decompress(&cinfo);
			return false;
		}
		const UChar *srcp = scanlines[0];
		UChar *dstp = pImage->GetPointer(0, cinfo.output_scanline - 1);
		for (UInt i = 0; i < cinfo.image_width; i++) {
			*(dstp + Image::OffsetRed) = *srcp++;
			*(dstp + Image::OffsetGreen) = *srcp++;
			*(dstp + Image::OffsetBlue) = *srcp++;
			dstp += pImage->GetBytesPerPixel();
		}
	}
	::jpeg_finish_decompress(&cinfo);
	::jpeg_destroy_decompress(&cinfo);
	return true;
}

bool ImageStreamer_JPEG::WriteStream(Environment &env, Signal sig,
						Image *pImage, Stream &stream, int quality)
{
	if (!pImage->CheckValid(sig)) return false;
	ErrorMgr errMgr(sig);
	jpeg_compress_struct cinfo;
	cinfo.err = ::jpeg_std_error(&errMgr.pub);
	errMgr.pub.error_exit = ErrorMgr::error_exit; // override error handler
	if (::setjmp(errMgr.jmpenv)) {
		::jpeg_destroy_compress(&cinfo);
		return false;
	}
	::jpeg_create_compress(&cinfo);
	DestinationMgr::Setup(&cinfo, &sig, &stream);
	cinfo.image_width		= static_cast<JDIMENSION>(pImage->GetWidth());
	cinfo.image_height		= static_cast<JDIMENSION>(pImage->GetHeight());
	cinfo.input_components	= 3;
	cinfo.in_color_space	= JCS_RGB;
	::jpeg_set_defaults(&cinfo);
	::jpeg_set_quality(&cinfo, quality, TRUE);
	::jpeg_start_compress(&cinfo, TRUE);
	JSAMPARRAY scanlines = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo,
					JPOOL_IMAGE, cinfo.image_width * cinfo.input_components, 1);
	while (cinfo.next_scanline < cinfo.image_height) {
		const UChar *srcp = pImage->GetPointer(0, cinfo.next_scanline);
		UChar *dstp = scanlines[0];
		for (UInt i = 0; i < cinfo.image_width; i++) {
			*dstp++ = *(srcp + Image::OffsetRed);
			*dstp++ = *(srcp + Image::OffsetGreen);
			*dstp++ = *(srcp + Image::OffsetBlue);
			srcp += pImage->GetBytesPerPixel();
		}
		::jpeg_write_scanlines(&cinfo, scanlines, 1);
	}
	::jpeg_finish_compress(&cinfo);
	::jpeg_destroy_compress(&cinfo);
	return true;
}

//-----------------------------------------------------------------------------
// ErrorMgr
//-----------------------------------------------------------------------------
void ErrorMgr::error_exit(j_common_ptr cinfo)
{
	ErrorMgr *pErrMgr = reinterpret_cast<ErrorMgr *>(cinfo->err);
	char buff[JMSG_LENGTH_MAX];
	(*cinfo->err->format_message)(cinfo, buff);
	pErrMgr->_sig.SetError(ERR_FormatError, "%s", buff);
	::longjmp(pErrMgr->jmpenv, 1);
}

//-----------------------------------------------------------------------------
// SourceMgr
//-----------------------------------------------------------------------------
void SourceMgr::Setup(j_decompress_ptr cinfo, Signal *pSig, Stream *pStream)
{
	if (cinfo->src == NULL) {
		cinfo->src = reinterpret_cast<jpeg_source_mgr *>((*cinfo->mem->alloc_small)(
			reinterpret_cast<j_common_ptr>(cinfo), JPOOL_PERMANENT, sizeof(SourceMgr)));
		SourceMgr *pSrcMgr = reinterpret_cast<SourceMgr *>(cinfo->src);
		pSrcMgr->buff = reinterpret_cast<JOCTET *>((*cinfo->mem->alloc_small)(
			reinterpret_cast<j_common_ptr>(cinfo), JPOOL_PERMANENT, BuffSize));
	}
	SourceMgr *pSrcMgr = reinterpret_cast<SourceMgr *>(cinfo->src);
	pSrcMgr->pub.init_source		= init_source;
	pSrcMgr->pub.fill_input_buffer	= fill_input_buffer;
	pSrcMgr->pub.skip_input_data	= skip_input_data;
	pSrcMgr->pub.resync_to_restart	= jpeg_resync_to_restart; // use default method
	pSrcMgr->pub.term_source		= term_source;
	pSrcMgr->pub.bytes_in_buffer	= 0;	// forces fill_input_buffer on first read
	pSrcMgr->pub.next_input_byte	= NULL;	// until buffer loaded
	pSrcMgr->pSig = pSig;
	pSrcMgr->pStream = pStream;
}

void SourceMgr::init_source(j_decompress_ptr cinfo)
{
	SourceMgr *pSrcMgr = reinterpret_cast<SourceMgr *>(cinfo->src);
	pSrcMgr->firstFlag = true;
}

boolean SourceMgr::fill_input_buffer(j_decompress_ptr cinfo)
{
	SourceMgr *pSrcMgr = reinterpret_cast<SourceMgr *>(cinfo->src);
	size_t nbytes = pSrcMgr->pStream->Read(*pSrcMgr->pSig, pSrcMgr->buff, BuffSize);
	
	if (nbytes == 0) {
		if (pSrcMgr->firstFlag) {
			ERREXIT(cinfo, JERR_INPUT_EMPTY);
		}
		WARNMS(cinfo, JWRN_JPEG_EOF);
		pSrcMgr->buff[0] = 0xff;
		pSrcMgr->buff[1] = JPEG_EOI;
		nbytes = 2;
	}
	pSrcMgr->pub.next_input_byte = pSrcMgr->buff;
	pSrcMgr->pub.bytes_in_buffer = nbytes;
	pSrcMgr->firstFlag = false;
	return TRUE;
}

void SourceMgr::skip_input_data(j_decompress_ptr cinfo, long num_bytes)
{
	jpeg_source_mgr *src = cinfo->src;
	if (num_bytes > 0) {
		while (num_bytes > static_cast<long>(src->bytes_in_buffer)) {
			num_bytes -= static_cast<long>(src->bytes_in_buffer);
			(*src->fill_input_buffer)(cinfo);
		}
		src->next_input_byte += num_bytes;
		src->bytes_in_buffer -= num_bytes;
	}
}

void SourceMgr::term_source(j_decompress_ptr cinfo)
{
}

//-----------------------------------------------------------------------------
// DestinationMgr
//-----------------------------------------------------------------------------
void DestinationMgr::Setup(j_compress_ptr cinfo, Signal *pSig, Stream *pStream)
{
	if (cinfo->dest == NULL) {
		cinfo->dest = reinterpret_cast<jpeg_destination_mgr *>((*cinfo->mem->alloc_small)(
			reinterpret_cast<j_common_ptr>(cinfo), JPOOL_PERMANENT, sizeof(DestinationMgr)));
	}
	DestinationMgr *pDstMgr = reinterpret_cast<DestinationMgr *>(cinfo->dest);
	pDstMgr->pub.init_destination		= init_destination;
	pDstMgr->pub.empty_output_buffer	= empty_output_buffer;
	pDstMgr->pub.term_destination		= term_destination;
	pDstMgr->pSig = pSig;
	pDstMgr->pStream = pStream;
}

void DestinationMgr::init_destination(j_compress_ptr cinfo)
{
	DestinationMgr *pDstMgr = reinterpret_cast<DestinationMgr *>(cinfo->dest);
	pDstMgr->buffer = reinterpret_cast<JOCTET *>((*cinfo->mem->alloc_small)(
		reinterpret_cast<j_common_ptr>(cinfo), JPOOL_IMAGE, BuffSize));
	pDstMgr->pub.next_output_byte = pDstMgr->buffer;
	pDstMgr->pub.free_in_buffer = BuffSize;
}

boolean DestinationMgr::empty_output_buffer(j_compress_ptr cinfo)
{
	DestinationMgr * pDstMgr = (DestinationMgr *) cinfo->dest;
	if (pDstMgr->pStream->Write(*pDstMgr->pSig, pDstMgr->buffer, BuffSize) != BuffSize) {
		ERREXIT(cinfo, JERR_FILE_WRITE);
	}
	pDstMgr->pub.next_output_byte = pDstMgr->buffer;
	pDstMgr->pub.free_in_buffer = BuffSize;
	return TRUE;
}

void DestinationMgr::term_destination(j_compress_ptr cinfo)
{
	DestinationMgr *pDstMgr = reinterpret_cast<DestinationMgr *>(cinfo->dest);
	size_t nbytes = BuffSize - pDstMgr->pub.free_in_buffer;
	if (nbytes > 0) {
		if (pDstMgr->pStream->Write(*pDstMgr->pSig, pDstMgr->buffer, nbytes) != nbytes) {
			ERREXIT(cinfo, JERR_FILE_WRITE);
		}
	}
	//pFile->Flush();
}

//-----------------------------------------------------------------------------
// SymbolAssoc
//-----------------------------------------------------------------------------
SymbolAssoc::SymbolAssoc(UShort tagId, Entry *entryTbl) :
									_tagId(tagId), _entryTbl(entryTbl)
{
	for (Entry *pEntry = _entryTbl; pEntry->name != NULL; pEntry++) {
		pEntry->pSymbol = Symbol::Add(pEntry->name);
	}
}

const Symbol *SymbolAssoc::NumToSymbol(UShort num) const
{
	for (const Entry *pEntry = _entryTbl; pEntry->name != NULL; pEntry++) {
		if (pEntry->num == num) return pEntry->pSymbol;
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// SymbolAssocList
//-----------------------------------------------------------------------------
const SymbolAssoc *SymbolAssocList::FindByTagId(UShort tagId) const
{
	foreach_const (SymbolAssocList, ppSymbolAssoc, *this) {
		const SymbolAssoc *pSymbolAssoc = *ppSymbolAssoc;
		if (pSymbolAssoc->GetTagId() == tagId) return pSymbolAssoc;
	}
	return NULL;
}

const Symbol *SymbolAssocList::NumToSymbol(UShort tagId, UShort num) const
{
	const SymbolAssoc *pSymbolAssoc = FindByTagId(tagId);
	return (pSymbolAssoc == NULL)? NULL : pSymbolAssoc->NumToSymbol(num);
}

//-----------------------------------------------------------------------------
// SymbolAssocOwner
//-----------------------------------------------------------------------------
SymbolAssocOwner::~SymbolAssocOwner()
{
	Clear();
}

void SymbolAssocOwner::Clear()
{
	foreach (SymbolAssocOwner, ppSymbolAssoc, *this) {
		SymbolAssoc *pSymbolAssoc = *ppSymbolAssoc;
		delete pSymbolAssoc;
	}
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
void SetError_InvalidFormat(Signal &sig)
{
	sig.SetError(ERR_FormatError, "invalid Exif format");
}

bool ReadBuff(Signal sig, Stream &stream, void *buff, size_t bytes)
{
	size_t bytesRead = stream.Read(sig, buff, bytes);
	if (sig.IsSignalled()) return false;
	if (bytesRead < bytes) {
		SetError_InvalidFormat(sig);
		return false;
	}
	return true;
}

const TagInfo *TagIdToInfo(const Symbol *pSymbolOfIFD, UShort id)
{
	const TagInfo *pTagInfo =
		(pSymbolOfIFD == Gura_UserSymbol(Exif))? g_tagInfoTbl_Exif :
		(pSymbolOfIFD == Gura_UserSymbol(Interoperability))? g_tagInfoTbl_Interoperability :
		(pSymbolOfIFD == Gura_UserSymbol(GPSInfo))? g_tagInfoTbl_GPSInfo :
		g_tagInfoTbl;
	if (pTagInfo == NULL) return NULL;
	for (int i = 0; pTagInfo->name != NULL; i++, pTagInfo++) {
		if (pTagInfo->id == id) return pTagInfo;
	}
	return NULL;
}

const TypeInfo *TypeToInfo(UShort type)
{
	const TypeInfo *pTypeInfo = g_typeInfoTbl;
	for (int i = 0; i < ArraySizeOf(g_typeInfoTbl); i++, pTypeInfo++) {
		if (pTypeInfo->type == type) return pTypeInfo;
	}
	return NULL;
}

Gura_EndModuleBody(jpeg, jpeg)

Gura_RegisterModule(jpeg)
