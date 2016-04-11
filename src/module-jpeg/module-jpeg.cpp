//-----------------------------------------------------------------------------
// Gura module: jpeg
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "Class_exif.h"

Gura_BeginModuleBody(jpeg)

// 4.6.4 TIFF Rev.6.0 Attribute Information
static const TagInfo g_tagInfoTbl[] = {
	// A. Tags relating to image data structure
	{ TAG_ImageWidth,					"ImageWidth",					TYPE_LONG,		nullptr,				},
	{ TAG_ImageLength,					"ImageLength",					TYPE_LONG,		nullptr,				},
	{ TAG_BitsPerSample,				"BitsPerSample",				TYPE_SHORT,		nullptr,				},
	{ TAG_Compression,					"Compression",					TYPE_SHORT,		nullptr,				},
	{ TAG_PhotometricInterpretation,	"PhotometricInterpretation",	TYPE_SHORT,		nullptr,				},
	{ TAG_Orientation,					"Orientation",					TYPE_SHORT,		nullptr,				},
	{ TAG_SamplesPerPixel,				"SamplesPerPixel",				TYPE_SHORT,		nullptr,				},
	{ TAG_PlanarConfiguration,			"PlanarConfiguration",			TYPE_SHORT,		nullptr,				},
	{ TAG_YCbCrSubSampling,				"YCbCrSubSampling",				TYPE_SHORT,		nullptr,				},
	{ TAG_YCbCrPositioning,				"YCbCrPositioning",				TYPE_SHORT,		nullptr,				},
	{ TAG_XResolution,					"XResolution",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_YResolution,					"YResolution",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_ResolutionUnit,				"ResolutionUnit",				TYPE_SHORT,		nullptr,				},
	// B. Tags relating to recording offset
	{ TAG_StripOffsets,					"StripOffsets",					TYPE_LONG,		nullptr,				},
	{ TAG_RowsPerStrip,					"RowsPerStrip",					TYPE_LONG,		nullptr,				},
	{ TAG_StripByteCounts,				"StripByteCounts",				TYPE_LONG,		nullptr,				},
	{ TAG_JPEGInterchangeFormat,		"JPEGInterchangeFormat",		TYPE_LONG,		nullptr,				},
	{ TAG_JPEGInterchangeFormatLength,	"JPEGInterchangeFormatLength",	TYPE_LONG,		nullptr,				},
	// C. Tags relating to image data characteristics
	{ TAG_TransferFunction,				"TransferFunction",				TYPE_SHORT,		nullptr,				},
	{ TAG_WhitePoint,					"WhitePoint",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_PrimaryChromaticities,		"PrimaryChromaticities",		TYPE_RATIONAL,	nullptr,				},
	{ TAG_YCbCrCoefficients,			"YCbCrCoefficients",			TYPE_RATIONAL,	nullptr,				},
	{ TAG_ReferenceBlackWhite,			"ReferenceBlackWhite",			TYPE_RATIONAL,	nullptr,				},
	// D. Other tags
	{ TAG_DateTime,						"DateTime",						TYPE_ASCII,		nullptr,				},
	{ TAG_ImageDescription,				"ImageDescription",				TYPE_ASCII,		nullptr,				},
	{ TAG_Make,							"Make",							TYPE_ASCII,		nullptr,				},
	{ TAG_Model,						"Model",						TYPE_ASCII,		nullptr,				},
	{ TAG_Software,						"Software",						TYPE_ASCII,		nullptr,				},
	{ TAG_Artist,						"Artist",						TYPE_ASCII,		nullptr,				},
	{ TAG_Copyright,					"Copyright",					TYPE_ASCII,		nullptr,				},
	// Pointers
	{ TAG_ExifIFDPointer,				"ExifIFDPointer",				TYPE_LONG,		"Exif",				},
	{ TAG_GPSInfoIFDPointer,			"GPSInfoIFDPointer",			TYPE_LONG,		"GPSInfo",			},
	{ TAG_invalid,						nullptr,							TYPE_UNDEFINED,	nullptr,				},
};

// 4.6.5 Exif IFD Attribute Information
static const TagInfo g_tagInfoTbl_Exif[] = {
	// A. Tags Relating to Version
	{ TAG_ExifVersion,					"ExifVersion",					TYPE_UNDEFINED,	nullptr,				},
	{ TAG_FlashPixVersion,				"FlashPixVersion",				TYPE_UNDEFINED,	nullptr,				},
	// B. Tag Relating to Image Data Characteristics
	{ TAG_ColorSpace,					"ColorSpace",					TYPE_SHORT,		nullptr,				},
	// C. Tags Relating to Image Configuration
	{ TAG_ComponentsConfiguration,		"ComponentsConfiguration",		TYPE_UNDEFINED,	nullptr,				},
	{ TAG_CompressedBitsPerPixel,		"CompressedBitsPerPixel",		TYPE_RATIONAL,	nullptr,				},
	{ TAG_PixelXDimension,				"PixelXDimension",				TYPE_LONG,		nullptr,				},
	{ TAG_PixelYDimension,				"PixelYDimension",				TYPE_LONG,		nullptr,				},
	// D. Tags Relating to User Information
	{ TAG_MakerNote,					"MakerNote",					TYPE_UNDEFINED,	nullptr,				},
	{ TAG_UserComment,					"UserComment",					TYPE_UNDEFINED,	nullptr,				},
	// E. Tags Relating to Related File Information
	{ TAG_RelatedSoundFile,				"RelatedSoundFile",				TYPE_ASCII,		nullptr,				},
	// F. Tags Relating to Date and Time
	{ TAG_DateTimeOriginal,				"DateTimeOriginal",				TYPE_ASCII,		nullptr,				},
	{ TAG_DateTimeDigitized,			"DateTimeDigitized",			TYPE_ASCII,		nullptr,				},
	{ TAG_SubSecTime,					"SubSecTime",					TYPE_ASCII,		nullptr,				},
	{ TAG_SubSecTimeOriginal,			"SubSecTimeOriginal",			TYPE_ASCII,		nullptr,				},
	{ TAG_SubSecTimeDigitized,			"SubSecTimeDigitized",			TYPE_ASCII,		nullptr,				},
	// G. Tags Relating to Picture-Taking Conditions
	{ TAG_ExposureTime,					"ExposureTime",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_FNumber,						"FNumber",						TYPE_RATIONAL,	nullptr,				},
	{ TAG_ExposureProgram,				"ExposureProgram",				TYPE_SHORT,		nullptr,				},
	{ TAG_SpectralSensitivity,			"SpectralSensitivity",			TYPE_ASCII,		nullptr,				},
	{ TAG_ISOSpeedRatings,				"ISOSpeedRatings",				TYPE_SHORT,		nullptr,				},
	{ TAG_OECF,							"OECF",							TYPE_UNDEFINED,	nullptr,				},
	{ TAG_ShutterSpeedValue,			"ShutterSpeedValue",			TYPE_SRATIONAL,	nullptr,				},
	{ TAG_ApertureValue,				"ApertureValue",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_BrightnessValue,				"BrightnessValue",				TYPE_SRATIONAL,	nullptr,				},
	{ TAG_ExposureBiasValue,			"ExposureBiasValue",			TYPE_SRATIONAL,	nullptr,				},
	{ TAG_MaxApertureValue,				"MaxApertureValue",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_SubjectDistance,				"SubjectDistance",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_MeteringMode,					"MeteringMode",					TYPE_SHORT,		nullptr,				},
	{ TAG_LightSource,					"LightSource",					TYPE_SHORT,		nullptr,				},
	{ TAG_Flash,						"Flash",						TYPE_SHORT,		nullptr,				},
	{ TAG_FocalLength,					"FocalLength",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_SubjectArea,					"SubjectArea",					TYPE_SHORT,		nullptr,				},
	{ TAG_FlashEnergy,					"FlashEnergy",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_SpatialFrequencyResponse,		"SpatialFrequencyResponse",		TYPE_UNDEFINED,	nullptr,				},
	{ TAG_FocalPlaneXResolution,		"FocalPlaneXResolution",		TYPE_RATIONAL,	nullptr,				},
	{ TAG_FocalPlaneYResolution,		"FocalPlaneYResolution",		TYPE_RATIONAL,	nullptr,				},
	{ TAG_FocalPlaneResolutionUnit,		"FocalPlaneResolutionUnit",		TYPE_SHORT,		nullptr,				},
	{ TAG_SubjectLocation,				"SubjectLocation",				TYPE_SHORT,		nullptr,				},
	{ TAG_ExposureIndex,				"ExposureIndex",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_SensingMethod,				"SensingMethod",				TYPE_SHORT,		nullptr,				},
	{ TAG_FileSource,					"FileSource",					TYPE_UNDEFINED,	nullptr,				},
	{ TAG_SceneType,					"SceneType",					TYPE_UNDEFINED,	nullptr,				},
	{ TAG_CFAPattern,					"CFAPattern",					TYPE_UNDEFINED,	nullptr,				},
	{ TAG_CustomRendered,				"CustomRendered",				TYPE_SHORT,		nullptr,				},
	{ TAG_ExposureMode,					"ExposureMode",					TYPE_SHORT,		nullptr,				},
	{ TAG_WhiteBalance,					"WhiteBalance",					TYPE_SHORT,		nullptr,				},
	{ TAG_DigitalZoomRatio,				"DigitalZoomRatio",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_FocalLengthIn35mmFilm,		"FocalLengthIn35mmFilm",		TYPE_SHORT,		nullptr,				},
	{ TAG_SceneCaptureType,				"SceneCaptureType",				TYPE_SHORT,		nullptr,				},
	{ TAG_GainControl,					"GainControl",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_Contrast,						"Contrast",						TYPE_SHORT,		nullptr,				},
	{ TAG_Saturation,					"Saturation",					TYPE_SHORT,		nullptr,				},
	{ TAG_Sharpness,					"Sharpness",					TYPE_SHORT,		nullptr,				},
	{ TAG_DeviceSettingDescription,		"DeviceSettingDescription",		TYPE_UNDEFINED,	nullptr,				},
	{ TAG_SubjectDistanceRange,			"SubjectDistanceRange",			TYPE_SHORT,		nullptr,				},
	// H. Other Tags
	{ TAG_ImageUniqueID,				"ImageUniqueID",				TYPE_ASCII,		nullptr,				},
	// Pointers
	{ TAG_InteroperabilityIFDPointer,	"InteroperabilityIFDPointer",	TYPE_LONG,		"Interoperability"	},
	{ TAG_invalid,						nullptr,							TYPE_UNDEFINED,	nullptr,				},
};

// 4.6.6 GPS Attribute Information
static const TagInfo g_tagInfoTbl_GPSInfo[] = {
	// A. Tags Relating to GPS
	{ TAG_GPSVersionID,					"GPSVersionID",					TYPE_BYTE,		nullptr,				},
	{ TAG_GPSLatitudeRef,				"GPSLatitudeRef",				TYPE_ASCII,		nullptr,				},
	{ TAG_GPSLatitude,					"GPSLatitude",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSLongitudeRef,				"GPSLongitudeRef",				TYPE_ASCII,		nullptr,				},
	{ TAG_GPSLongitude,					"GPSLongitude",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSAltitudeRef,				"GPSAltitudeRef",				TYPE_BYTE,		nullptr,				},
	{ TAG_GPSAltitude,					"GPSAltitude",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSTimeStamp,					"GPSTimeStamp",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSSatellites,				"GPSSatellites",				TYPE_ASCII,		nullptr,				},
	{ TAG_GPSStatus,					"GPSStatus",					TYPE_ASCII,		nullptr,				},
	{ TAG_GPSMeasureMode,				"GPSMeasureMode",				TYPE_ASCII,		nullptr,				},
	{ TAG_GPSDOP,						"GPSDOP",						TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSSpeedRef,					"GPSSpeedRef",					TYPE_ASCII,		nullptr,				},
	{ TAG_GPSSpeed,						"GPSSpeed",						TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSTrackRef,					"GPSTrackRef",					TYPE_ASCII,		nullptr,				},
	{ TAG_GPSTrack,						"GPSTrack",						TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSImgDirectionRef,			"GPSImgDirectionRef",			TYPE_ASCII,		nullptr,				},
	{ TAG_GPSImgDirection,				"GPSImgDirection",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSMapDatum,					"GPSMapDatum",					TYPE_ASCII,		nullptr,				},
	{ TAG_GPSDestLatitudeRef,			"GPSDestLatitudeRef",			TYPE_ASCII,		nullptr,				},
	{ TAG_GPSDestLatitude,				"GPSDestLatitude",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSDestLongitudeRef,			"GPSDestLongitudeRef",			TYPE_ASCII,		nullptr,				},
	{ TAG_GPSDestLongitude,				"GPSDestLongitude",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSBearingRef,				"GPSBearingRef",				TYPE_ASCII,		nullptr,				},
	{ TAG_GPSBearing,					"GPSBearing",					TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSDestDistanceRef,			"GPSDestDistanceRef",			TYPE_ASCII,		nullptr,				},
	{ TAG_GPSDestDistance,				"GPSDestDistance",				TYPE_RATIONAL,	nullptr,				},
	{ TAG_GPSProcessingMethod,			"GPSProcessingMethod",			TYPE_UNDEFINED,	nullptr,				},
	{ TAG_GPSAreaInformation,			"GPSAreaInformation",			TYPE_UNDEFINED,	nullptr,				},
	{ TAG_GPSDateStamp,					"GPSDateStamp",					TYPE_ASCII,		nullptr,				},
	{ TAG_GPSDifferential,				"GPSDifferential",				TYPE_SHORT,		nullptr,				},
	{ TAG_invalid,						nullptr,							TYPE_UNDEFINED,	nullptr,				},
};

// 4.6.7 Interoperability IFD Attribute Information
static const TagInfo g_tagInfoTbl_Interoperability[] = {
	{ TAG_InteroperabilityIndex,		"InteroperabilityIndex",		TYPE_ASCII,		nullptr,				},
	{ TAG_InteroperabilityVersion,		"InteroperabilityVersion",		TYPE_BYTE,		nullptr,				},
	{ TAG_RelatedImageWidth,			"RelatedImageWidth",			TYPE_SHORT,		nullptr,				},
	{ TAG_RelatedImageHeight,			"RelatedImageHeight",			TYPE_SHORT,		nullptr,				},
	{ TAG_invalid,						nullptr,							TYPE_UNDEFINED,	nullptr,				},
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
// image#read@jpeg(stream:stream:r, size?:number):reduce:[fast,rough]
Gura_DeclareMethodAlias(image, read_at_jpeg, "read@jpeg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_UserSymbol(fast));
	DeclareAttr(Gura_UserSymbol(rough));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads a JPEG image data from the specified `stream`.\n"
		"\n"
		"When the argument `size` is specified, the image would be shrinked so that\n"
		"it is boxed within the size.\n"
		"\n"
		"The attribute `:fast` indicates a fast but less-qualified decompression process.\n"
		"\n"
		"The attriubte `:rough` is only valid when `size` is specified and\n"
		"makes the shrinked image with nearest neighbor method.\n"
		"Othereise, shrinking shall be done with bilinear method.\n");
}

Gura_ImplementMethod(image, read_at_jpeg)
{
	bool fastFlag = arg.IsSet(Gura_UserSymbol(fast));
	bool roughFlag = arg.IsSet(Gura_UserSymbol(rough));
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetObjectThis(arg);
	bool rtn = arg.IsValid(1)?
		ImageStreamer_JPEG::ReadStreamWithScaling(
			env, pThis->GetImage(), arg.GetStream(0), fastFlag, arg.GetSizeT(1), roughFlag) :
		ImageStreamer_JPEG::ReadStream(
			env, pThis->GetImage(), arg.GetStream(0), fastFlag);
	if (!rtn) return Value::Nil;
	return arg.GetValueThis();
}

// image#write@jpeg(stream:stream:w, quality:number => 75):reduce
Gura_DeclareMethodAlias(image, write_at_jpeg, "write@jpeg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_Once,
			   FLAG_None, 0, new Expr_Value(75));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Writes a JPEG image data to the specified `stream`.\n"
		"\n"
		"The argument `quality` takes a number between 0 and 100\n"
		"with which a a higher number results in a higher quality of result\n"
		"but a less compression performance.\n"
		"The default value for it is 75.\n");
}

Gura_ImplementMethod(image, write_at_jpeg)
{
	Object_image *pThis = Object_image::GetObjectThis(arg);
	if (!ImageStreamer_JPEG::WriteStream(
			env, pThis->GetImage(), arg.GetStream(0), arg.GetInt(1))) {
		return Value::Nil;
	}
	return arg.GetValueThis();
}

// jpeg.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(test)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(fast);
	Gura_RealizeUserSymbol(rough);
	Gura_RealizeUserSymbol(endian);
	Gura_RealizeUserSymbol(big);
	Gura_RealizeUserSymbol(little);
	Gura_RealizeUserSymbol(uncompressed);
	Gura_RealizeUserSymbol(id);
	Gura_RealizeUserSymbol(name);
	Gura_RealizeUserSymbol(symbol);
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(typename);
	Gura_RealizeUserSymbol(value);
	Gura_RealizeUserSymbol(cooked);
	Gura_RealizeUserSymbol(ifd);
	Gura_RealizeUserSymbol(ifd0);
	Gura_RealizeUserSymbol(ifd1);
	Gura_RealizeUserSymbol(thumbnail);
	Gura_RealizeUserSymbolAlias(thumbnail_at_jpeg, "thumbnail@jpeg");
	Gura_RealizeUserSymbol(Exif);
	Gura_RealizeUserSymbol(Interoperability);
	Gura_RealizeUserSymbol(GPSInfo);
	// class realization
	Gura_RealizeAndPrepareUserClass(tag, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(ifd, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(exif, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(test);
	// method assignment to image
	Gura_AssignMethodTo(VTYPE_image, image, read_at_jpeg);
	Gura_AssignMethodTo(VTYPE_image, image, write_at_jpeg);
	// image streamer registration
	ImageStreamer::Register(new ImageStreamer_JPEG());
	do {
		const UShort tagId = TAG_Compression;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"uncompressed",					nullptr,	},
			{ 6,		"JPEG",							nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_PhotometricInterpretation;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 2,		"RGB",							nullptr,	},
			{ 6,		"YCbCr",						nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Orientation;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"LeftTopHorz",					nullptr,	},
			{ 2,		"RightTopHorz",					nullptr,	},
			{ 3,		"RightBottomHorz",				nullptr,	},
			{ 4,		"LeftBottomHorz",				nullptr,	},
			{ 5,		"LeftTopVert",					nullptr,	},
			{ 6,		"LeftBottomVert",				nullptr,	},
			{ 7,		"RightBottomVert",				nullptr,	},
			{ 8,		"RightTopVert",					nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_PlanarConfiguration;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"chunky",						nullptr,	},
			{ 2,		"planar",						nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_YCbCrPositioning;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"centered",						nullptr,	},
			{ 2,		"cosited",						nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ResolutionUnit;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 2,		"inches",						nullptr,	},
			{ 3,		"centimeters",					nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ColorSpace;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"sRGB",							nullptr,	},
			{ 0xffff,	"uncalibrated",					nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ComponentsConfiguration;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"not_exist",					nullptr,	},
			{ 1,		"Y",							nullptr,	},
			{ 2,		"Cb",							nullptr,	},
			{ 3,		"Cr",							nullptr,	},
			{ 4,		"R",							nullptr,	},
			{ 5,		"G",							nullptr,	},
			{ 6,		"B",							nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ExposureProgram;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"NotDefined",					nullptr,	},
			{ 1,		"Manual",						nullptr,	},
			{ 2,		"NormalProgram",				nullptr,	},
			{ 3,		"AperturePriority",				nullptr,	},
			{ 4,		"ShutterPriority",				nullptr,	},
			{ 5,		"CreativeProgram",				nullptr,	},
			{ 6,		"ActionProgram",				nullptr,	},
			{ 7,		"PortraitMode",					nullptr,	},
			{ 8,		"LandscapeMode",				nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);

	do {
		const UShort tagId = TAG_MeteringMode;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"unknown",						nullptr,	},
			{ 1,		"Average",						nullptr,	},
			{ 2,		"CenterWeightedAverage",		nullptr,	},
			{ 3,		"Spot",							nullptr,	},
			{ 4,		"MultiSpot",					nullptr,	},
			{ 5,		"Pattern",						nullptr,	},
			{ 6,		"Partial",						nullptr,	},
			{ 255,		"other",						nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_LightSource;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"unknown",						nullptr,	},
			{ 1,		"Daylight",						nullptr,	},
			{ 2,		"Fluorescent",					nullptr,	},
			{ 3,		"Tungsten",						nullptr,	},
			{ 4,		"Flash",						nullptr,	},
			{ 9,		"FineWeather",					nullptr,	},
			{ 10,		"CloudyWeather",				nullptr,	},
			{ 11,		"Shade",						nullptr,	},
			{ 12,		"DaylightFluorescent",			nullptr,	},
			{ 13,		"DayWhiteFluorescent",			nullptr,	},
			{ 14,		"CoolWhiteFluorescent",			nullptr,	},
			{ 15,		"WhiteFluorescent",				nullptr,	},
			{ 17,		"StandardLightA",				nullptr,	},
			{ 18,		"StandardLightB",				nullptr,	},
			{ 19,		"StandardLightC",				nullptr,	},
			{ 20,		"D55",							nullptr,	},
			{ 21,		"D65",							nullptr,	},
			{ 22,		"D75",							nullptr,	},
			{ 23,		"D50",							nullptr,	},
			{ 24,		"ISOStudioTungsten",			nullptr,	},
			{ 255,		"OtherLightSource",				nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Flash;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0x0000,	"FlashDidNotFire",																nullptr,	},
			{ 0x0001,	"FlashFired",																	nullptr,	},
			{ 0x0005,	"StrobeReturnLightNotDetected",													nullptr,	},
			{ 0x0007,	"StrobeReturnLightDetected",													nullptr,	},
			{ 0x0009,	"FlashFired_CompulsoryFlashMode",												nullptr,	},
			{ 0x000d,	"FlashFired_CompulsoryFlashMode_ReturnLightNotDetected",						nullptr,	},
			{ 0x000f,	"FlashFired_CompulsoryFlashMode_ReturnLightDetected",							nullptr,	},
			{ 0x0010,	"FlashDidNotFire_CompulsoryFlashMode",											nullptr,	},
			{ 0x0018,	"FlashDidNotFire_AutoMode",														nullptr,	},
			{ 0x0019,	"FlashFired_AutoMode",															nullptr,	},
			{ 0x001d,	"FlashFired_AutoMode_ReturnLightNotDetected",									nullptr,	},
			{ 0x001f,	"FlashFired_AutoMode_ReturnLightDetected",										nullptr,	},
			{ 0x0020,	"NoFlashFunction",																nullptr,	},
			{ 0x0041,	"FlashFired_RedEyeReductionMode",												nullptr,	},
			{ 0x0045,	"FlashFired_RedEyeReductionMode_ReturnLightNotDetected",						nullptr,	},
			{ 0x0047,	"FlashFired_RedEyeReductionMode_ReturnLightDetected",							nullptr,	},
			{ 0x0049,	"FlashFired_CompulsoryFlashMode_RedEyeReductionMode",							nullptr,	},
			{ 0x004d,	"FlashFired_CompulsoryFlashMode_RedEyeReductionMode_ReturnLightNotDetected",	nullptr,	},
			{ 0x004f,	"FlashFired_CompulsoryFlashMode_RedEyeReductionMode_ReturnLightDetected",		nullptr,	},
			{ 0x0059,	"FlashFired_AutoMode_RedEyeReductionMode",										nullptr,	},
			{ 0x005d,	"FlashFired_AutoMode_ReturnLightNotDetected_RedEyeReductionMode",				nullptr,	},
			{ 0x005f,	"FlashFired_AutoMode_ReturnLightDetected_RedEyeReductionMode",					nullptr,	},
			{ 0,		nullptr,																			nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_FocalPlaneResolutionUnit;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 2,		"inches",						nullptr,	},
			{ 3,		"centimeters",					nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_SensingMethod;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"NotDefined",					nullptr,	},
			{ 2,		"OneChipColorAreaSensor",		nullptr,	},
			{ 3,		"TwoChipColorAreaSensor",		nullptr,	},
			{ 4,		"ThreeChipColorAreaSensor",		nullptr,	},
			{ 5,		"ColorSequentialAreaSensor",	nullptr,	},
			{ 7,		"TrilinearSensor",				nullptr,	},
			{ 8,		"ColorSequentialLinearSensor",	nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_FileSource;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 3,		"DSC",							nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_SceneType;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 1,		"DirectlyPhotographedImage",	nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_CustomRendered;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"NormalProces",					nullptr,	},
			{ 1,		"CustomProcess",				nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_ExposureMode;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"AutoExposure",					nullptr,	},
			{ 1,		"ManualExposure",				nullptr,	},
			{ 2,		"AutoBracket",					nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_WhiteBalance;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"AutoWhiteBalance",				nullptr,	},
			{ 1,		"ManualWhiteBalance",			nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_SceneCaptureType;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"Standard",						nullptr,	},
			{ 1,		"Landscape",					nullptr,	},
			{ 2,		"Portrait",						nullptr,	},
			{ 3,		"NightScene",					nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_GainControl;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"None",							nullptr,	},
			{ 1,		"LowGainUp",					nullptr,	},
			{ 2,		"HighGainUp",					nullptr,	},
			{ 3,		"LowGainDown",					nullptr,	},
			{ 4,		"HighGainDown",					nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Contrast;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"Normal",						nullptr,	},
			{ 1,		"Soft",							nullptr,	},
			{ 2,		"Hard",							nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Saturation;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"Normal",						nullptr,	},
			{ 1,		"LowSaturation",				nullptr,	},
			{ 2,		"HighSaturation",				nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_Sharpness;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"Normal",						nullptr,	},
			{ 1,		"Soft",							nullptr,	},
			{ 2,		"Hard",							nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_SubjectDistanceRange;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"unknown",						nullptr,	},
			{ 1,		"Macro",						nullptr,	},
			{ 2,		"CloseView",					nullptr,	},
			{ 3,		"DistantView",					nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	do {
		const UShort tagId = TAG_GPSAltitudeRef;
		static SymbolAssoc::Entry entryTbl[] = {
			{ 0,		"SeaLevel",						nullptr,	},
			{ 1,		"SeaLavelReference",			nullptr,	},
			{ 0,		nullptr,							nullptr,	},
		};
		g_symbolAssocOwner.push_back(new SymbolAssoc(tagId, entryTbl));
	} while (0);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_JPEG
//-----------------------------------------------------------------------------
bool ImageStreamer_JPEG::IsResponsible(Signal &sig, Stream &stream)
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

bool ImageStreamer_JPEG::Read(Environment &env, Image *pImage, Stream &stream)
{
	return ReadStream(env, pImage, stream, false);
}

bool ImageStreamer_JPEG::Write(Environment &env, Image *pImage, Stream &stream)
{
	return WriteStream(env, pImage, stream, 75);
}

bool ImageStreamer_JPEG::ReadStream(Environment &env, Image *pImage, Stream &stream, bool fastFlag)
{
	Signal &sig = env.GetSignal();
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
	if (!pImage->AllocBuffer(sig, cinfo.image_width, cinfo.image_height, 0xff)) {
		::jpeg_destroy_decompress(&cinfo);
		return false;
	}
	if (fastFlag) {
		// Setting equivalent to -fast option of djpeg. See line.251 in djpeg.c.
		cinfo.two_pass_quantize = FALSE;
		cinfo.dither_mode = JDITHER_ORDERED;
		if (!cinfo.quantize_colors) cinfo.desired_number_of_colors = 216;
		cinfo.dct_method = JDCT_FASTEST;
		cinfo.do_fancy_upsampling = FALSE;
		::jpeg_calc_output_dimensions(&cinfo);	// update parameters in the structure
	}
	return DoDecompress(sig, pImage, cinfo);
}

bool ImageStreamer_JPEG::ReadStreamWithScaling(
	Environment &env, Image *pImage, Stream &stream,
	bool fastFlag, size_t size, bool roughFlag)
{
	Signal &sig = env.GetSignal();
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
	size_t width = cinfo.image_width;
	size_t height = cinfo.image_height;
	bool scalingFlag = false;
	if (width > height) {
		if (width > size) {
			width = size;
			height = cinfo.image_height * size / cinfo.image_width;
			if (height == 0) height = 1;
			scalingFlag = true;
		}
	} else {
		if (height > size) {
			width = cinfo.image_width * size / cinfo.image_height;
			height = size;
			if (width == 0) width = 1;
			scalingFlag = true;
		}
	}
	if (!pImage->AllocBuffer(sig, width, height, 0xff)) {
		::jpeg_destroy_decompress(&cinfo);
		return false;
	}
	if (!scalingFlag) return DoDecompress(sig, pImage, cinfo);
	bool calcDimensionsFlag = false;
	int scaleFactor = cinfo.image_width / width;
	if (scaleFactor >= 2) {
		cinfo.scale_num = 1;
		cinfo.scale_denom = 2;
		calcDimensionsFlag = true;
	} else if (scaleFactor >= 4) {
		cinfo.scale_num = 1;
		cinfo.scale_denom = 4;
		calcDimensionsFlag = true;
	} else if (scaleFactor >= 8) {
		cinfo.scale_num = 1;
		cinfo.scale_denom = 8;
		calcDimensionsFlag = true;
	}
	if (fastFlag) {
		// Setting equivalent to -fast option of djpeg. See line.251 in djpeg.c.
		cinfo.two_pass_quantize = FALSE;
		cinfo.dither_mode = JDITHER_ORDERED;
		if (!cinfo.quantize_colors) cinfo.desired_number_of_colors = 216;
		cinfo.dct_method = JDCT_FASTEST;
		cinfo.do_fancy_upsampling = FALSE;
		calcDimensionsFlag = true;
	}
	if (calcDimensionsFlag) {
		::jpeg_calc_output_dimensions(&cinfo);	// update parameters in the structure
	}
	return roughFlag?
		DoDecompressWithNearestNeighborScaling(sig, pImage, cinfo) :
		DoDecompressWithBilinearScaling(sig, pImage, cinfo);
}

bool ImageStreamer_JPEG::DoDecompress(Signal &sig, Image *pImage, jpeg_decompress_struct &cinfo)
{
	::jpeg_start_decompress(&cinfo);
	bool grayScaleFlag = (cinfo.output_components != 3);
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
		if (grayScaleFlag) {
			for (UInt i = 0; i < cinfo.output_width; i++) {
				*(dstp + Image::OffsetR) = *srcp;
				*(dstp + Image::OffsetG) = *srcp;
				*(dstp + Image::OffsetB) = *srcp;
				srcp++;
				dstp += pImage->GetBytesPerPixel();
			}
		} else {
			for (UInt i = 0; i < cinfo.output_width; i++) {
				*(dstp + Image::OffsetR) = *srcp++;
				*(dstp + Image::OffsetG) = *srcp++;
				*(dstp + Image::OffsetB) = *srcp++;
				dstp += pImage->GetBytesPerPixel();
			}
		}
	}
	::jpeg_finish_decompress(&cinfo);
	::jpeg_destroy_decompress(&cinfo);
	return true;
}

bool ImageStreamer_JPEG::DoDecompressWithBilinearScaling(
	Signal &sig, Image *pImage, jpeg_decompress_struct &cinfo)
{
	::jpeg_start_decompress(&cinfo);
	bool grayScaleFlag = (cinfo.output_components != 3);
	size_t widthDst = pImage->GetWidth();
	size_t heightDst = pImage->GetHeight();
	JSAMPARRAY scanlines = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo,
					JPOOL_IMAGE, cinfo.output_width * cinfo.output_components, 1);
	UChar *pLineDst = pImage->GetPointer(0);
	size_t bytesPerPixel = pImage->GetBytesPerPixel();
	size_t bytesPerLineDst = pImage->GetBytesPerLine();
	size_t accumsSize = widthDst * sizeof(Image::Accum);
	AutoPtr<Memory> pMemory(new MemoryHeap(accumsSize));
	Image::Accum *accums = reinterpret_cast<Image::Accum *>(pMemory->GetPointer());
	::memset(accums, 0x00, accumsSize);
	size_t numerY = 0;
	size_t yDst = 0;
	for (;;) {
		if (cinfo.output_scanline < cinfo.output_height) {
			::jpeg_read_scanlines(&cinfo, scanlines, 1);
			if (sig.IsSignalled()) {
				::jpeg_finish_decompress(&cinfo);
				::jpeg_destroy_decompress(&cinfo);
				return false;
			}
			const UChar *pPixelSrc = scanlines[0];
			Image::Accum *pAccum = accums;
			size_t xDst = 0;
			size_t numerX = 0;
			if (grayScaleFlag) {
				for (UInt xSrc = 0; xSrc < cinfo.output_width; xSrc++) {
					pAccum->AddRGB(pPixelSrc[0], pPixelSrc[0], pPixelSrc[0]);
					pPixelSrc += 1;
					numerX += widthDst;
					for ( ; numerX >= cinfo.output_width && xDst < widthDst;
						  numerX -= cinfo.output_width, xDst++) {
						pAccum++;
					}
				}
			} else {
				for (UInt xSrc = 0; xSrc < cinfo.output_width; xSrc++) {
					pAccum->AddRGB(pPixelSrc[0], pPixelSrc[1], pPixelSrc[2]);
					pPixelSrc += 3;
					numerX += widthDst;
					for ( ; numerX >= cinfo.output_width && xDst < widthDst;
						  numerX -= cinfo.output_width, xDst++) {
						pAccum++;
					}
				}
			}
		}
		numerY += heightDst;
		if (numerY >= cinfo.output_height) {
			if (accums[0].cnt == 0) accums[0].cnt = 0; // this must not happen
			Image::Accum *pAccum = accums;
			Image::Accum *pAccumPrev = accums;
			for (size_t xDst = 0; xDst < widthDst; xDst++, pAccum++) {
				size_t cnt = pAccum->cnt;
				if (cnt == 0) {
					*pAccum = *pAccumPrev;
				} else if (cnt == 1) {
					pAccumPrev = pAccum;
				} else if (cnt == 2) {
					pAccum->r >>= 1;
					pAccum->g >>= 1;
					pAccum->b >>= 1;
					pAccumPrev = pAccum;
				} else if (cnt == 4) {
					pAccum->r >>= 2;
					pAccum->g >>= 2;
					pAccum->b >>= 2;
					pAccumPrev = pAccum;
				} else {
					pAccum->r /= cnt;
					pAccum->g /= cnt;
					pAccum->b /= cnt;
					pAccumPrev = pAccum;
				}
			}
			for ( ; numerY >= cinfo.output_height && yDst < heightDst;
				  numerY -= cinfo.output_height, yDst++) {
				Image::Accum *pAccum = accums;
				UChar *pPixelDst = pLineDst;
				for (size_t xDst = 0; xDst < widthDst;
					 xDst++, pAccum++, pPixelDst += bytesPerPixel) {
					pAccum->StoreRGB(pPixelDst);
				}
				pLineDst += bytesPerLineDst;
			}
			::memset(accums, 0x00, accumsSize);
		}
		if (cinfo.output_scanline == cinfo.output_height) break;
	}
	::jpeg_finish_decompress(&cinfo);
	::jpeg_destroy_decompress(&cinfo);
	return true;
}

bool ImageStreamer_JPEG::DoDecompressWithNearestNeighborScaling(
	Signal &sig, Image *pImage, jpeg_decompress_struct &cinfo)
{
	::jpeg_start_decompress(&cinfo);
	bool grayScaleFlag = (cinfo.output_components != 3);
	size_t widthDst = pImage->GetWidth();
	size_t heightDst = pImage->GetHeight();
	JSAMPARRAY scanlines = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo,
					JPOOL_IMAGE, cinfo.output_width * cinfo.output_components, 1);
	UChar *pLineDst = pImage->GetPointer(0);
	size_t bytesPerPixelDst = pImage->GetBytesPerPixel();
	size_t bytesPerLineDst = pImage->GetBytesPerLine();
	size_t yDst = 0;
	size_t ySrc = 0, ySrcNext = 0;
	AutoPtr<Memory> pMemory(new MemoryHeap(sizeof(UInt) * widthDst));
	UInt *offsetDst = reinterpret_cast<UInt *>(pMemory->GetPointer());
	if (grayScaleFlag) {
		for (UInt xDst = 0; xDst < widthDst; xDst++) {
			offsetDst[xDst] = xDst * cinfo.output_width / widthDst;
		}
	} else {
		for (UInt xDst = 0; xDst < widthDst; xDst++) {
			offsetDst[xDst] = xDst * cinfo.output_width / widthDst * 3;
		}
	}
	while (cinfo.output_scanline < cinfo.output_height) {
		::jpeg_read_scanlines(&cinfo, scanlines, 1);
		if (sig.IsSignalled()) {
			::jpeg_finish_decompress(&cinfo);
			::jpeg_destroy_decompress(&cinfo);
			return false;
		}
		if (ySrc < ySrcNext) {
			ySrc++;
			continue;
		}
		ySrc++;
		const UChar *pLineSrc = scanlines[0];
		if (grayScaleFlag) {
			UChar *pPixelDst = pLineDst;
			for (UInt xDst = 0; xDst < widthDst; xDst++) {
				const UChar *pPixelSrc = pLineSrc + offsetDst[xDst];
				*(pPixelDst + Image::OffsetR) = *pPixelSrc;
				*(pPixelDst + Image::OffsetG) = *pPixelSrc;
				*(pPixelDst + Image::OffsetB) = *pPixelSrc;
				pPixelDst += bytesPerPixelDst;
			}
		} else {
			UChar *pPixelDst = pLineDst;
			for (UInt xDst = 0; xDst < widthDst; xDst++) {
				const UChar *pPixelSrc = pLineSrc + offsetDst[xDst];
				*(pPixelDst + Image::OffsetR) = *(pPixelSrc + 0);
				*(pPixelDst + Image::OffsetG) = *(pPixelSrc + 1);
				*(pPixelDst + Image::OffsetB) = *(pPixelSrc + 2);
				pPixelDst += bytesPerPixelDst;
			}
		}
		pLineDst += bytesPerLineDst;
		yDst++;
		ySrcNext = yDst * cinfo.output_height / heightDst;
	}
	::jpeg_finish_decompress(&cinfo);
	::jpeg_destroy_decompress(&cinfo);
	return true;
}

bool ImageStreamer_JPEG::WriteStream(Environment &env, Image *pImage, Stream &stream, int quality)
{
	Signal &sig = env.GetSignal();
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
		const UChar *pPixelSrc = pImage->GetPointer(0, cinfo.next_scanline);
		UChar *pPixelDst = scanlines[0];
		for (UInt i = 0; i < cinfo.image_width; i++) {
			*pPixelDst++ = *(pPixelSrc + Image::OffsetR);
			*pPixelDst++ = *(pPixelSrc + Image::OffsetG);
			*pPixelDst++ = *(pPixelSrc + Image::OffsetB);
			pPixelSrc += pImage->GetBytesPerPixel();
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
	if (cinfo->src == nullptr) {
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
	pSrcMgr->pub.next_input_byte	= nullptr;	// until buffer loaded
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
	if (cinfo->dest == nullptr) {
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
	for (Entry *pEntry = _entryTbl; pEntry->name != nullptr; pEntry++) {
		pEntry->pSymbol = Symbol::Add(pEntry->name);
	}
}

const Symbol *SymbolAssoc::NumToSymbol(UShort num) const
{
	for (const Entry *pEntry = _entryTbl; pEntry->name != nullptr; pEntry++) {
		if (pEntry->num == num) return pEntry->pSymbol;
	}
	return nullptr;
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
	return nullptr;
}

const Symbol *SymbolAssocList::NumToSymbol(UShort tagId, UShort num) const
{
	const SymbolAssoc *pSymbolAssoc = FindByTagId(tagId);
	return (pSymbolAssoc == nullptr)? nullptr : pSymbolAssoc->NumToSymbol(num);
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

bool ReadBuff(Signal &sig, Stream &stream, void *buff, size_t bytes)
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
	if (pTagInfo == nullptr) return nullptr;
	for (int i = 0; pTagInfo->name != nullptr; i++, pTagInfo++) {
		if (pTagInfo->id == id) return pTagInfo;
	}
	return nullptr;
}

const TypeInfo *TypeToInfo(UShort type)
{
	const TypeInfo *pTypeInfo = g_typeInfoTbl;
	for (int i = 0; i < ArraySizeOf(g_typeInfoTbl); i++, pTypeInfo++) {
		if (pTypeInfo->type == type) return pTypeInfo;
	}
	return nullptr;
}

Gura_EndModuleBody(jpeg, jpeg)

Gura_RegisterModule(jpeg)
