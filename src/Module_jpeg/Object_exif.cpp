#include "Object_exif.h"

Gura_BeginModule(jpeg)

enum {
	SIZE_IFDHeader	= 2,
	SIZE_TagRaw		= 12,
};

enum {
	MARKER_SOI	= 0xffd8,
	MARKER_APP1	= 0xffe1,
};

enum {
	TYPE_BYTE		= 1,
	TYPE_ASCII		= 2,
	TYPE_SHORT		= 3,
	TYPE_LONG		= 4,
	TYPE_RATIONAL	= 5,
	TYPE_UNDEFINED	= 7,
	TYPE_SLONG		= 9,
	TYPE_SRATIONAL	= 10,
};

enum {
	UNITSIZE_BYTE		= 1,
	UNITSIZE_ASCII		= 1,
	UNITSIZE_SHORT		= 2,
	UNITSIZE_LONG		= 4,
	UNITSIZE_RATIONAL	= 8,
	UNITSIZE_UNDEFINED	= 0,
	UNITSIZE_SLONG		= 4,
	UNITSIZE_SRATIONAL	= 8,
};

enum {
	TAG_ImageWidth					= 0x0100,
	TAG_ImageLength					= 0x0101,
	TAG_BitsPerSample				= 0x0102,
	TAG_Compression					= 0x0103,
	TAG_PhotometricInterpretation	= 0x0106,
	TAG_Orientation					= 0x0112,
	TAG_SamplesPerPixel				= 0x0115,
	TAG_PlanarConfiguration			= 0x011c,
	TAG_YCbCrSubSampling			= 0x0212,
	TAG_YCbCrPositioning			= 0x0213,
	TAG_XResolution					= 0x011a,
	TAG_YResolution					= 0x011b,
	TAG_ResolutionUnit				= 0x0128,
	TAG_StripOffsets				= 0x0111,
	TAG_RowsPerStrip				= 0x0116,
	TAG_StripByteCounts				= 0x0117,
	TAG_JPEGInterchangeFormat		= 0x0201,
	TAG_JPEGInterchangeFormatLength	= 0x0202,
	TAG_TransferFunction			= 0x012d,
	TAG_WhitePoint					= 0x013e,
	TAG_PrimaryChromaticities		= 0x013f,
	TAG_YCbCrCoefficients			= 0x0211,
	TAG_ReferenceBlackWhite			= 0x0214,
	TAG_DateTime					= 0x0132,
	TAG_ImageDescription			= 0x010e,
	TAG_Make						= 0x010f,
	TAG_Model						= 0x0110,
	TAG_Software					= 0x0131,
	TAG_Artist						= 0x013b,
	TAG_Copyright					= 0x0d68,
	TAG_ExifIFDPointer				= 0x8769,
	TAG_GPSInfoIFDPointer			= 0x8825,
	TAG_ExifVersion					= 0x9000,
	TAG_FlashPixVersion				= 0xa000,
	TAG_ColorSpace					= 0xa001,
	TAG_ComponentsConfiguration		= 0x9101,
	TAG_CompressedBitsPerPixel		= 0x9102,
	TAG_PixelXDimension				= 0xa002,
	TAG_PixelYDimension				= 0xa003,
	TAG_MakerNote					= 0x927c,
	TAG_UserComment					= 0x9286,
	TAG_RelatedSoundFile			= 0xa004,
	TAG_DateTimeOriginal			= 0x9003,
	TAG_DateTimeDigitized			= 0x9004,
	TAG_SubSecTime					= 0x9290,
	TAG_SubSecTimeOriginal			= 0x9291,
	TAG_SubSecTimeDigitized			= 0x9292,
	TAG_ExposureTime				= 0x829a,
	TAG_FNumber						= 0x829d,
	TAG_ExposureProgram				= 0x8822,
	TAG_SpectralSensitivity			= 0x8824,
	TAG_ISOSpeedRatings				= 0x8827,
	TAG_OECF						= 0x8828,
	TAG_ShutterSpeedValue			= 0x9201,
	TAG_ApertureValue				= 0x9202,
	TAG_BrightnessValue				= 0x9203,
	TAG_ExposureBiasValue			= 0x9204,
	TAG_MaxApertureValue			= 0x9205,
	TAG_SubjectDistance				= 0x9206,
	TAG_MeteringMode				= 0x9207,
	TAG_LightSource					= 0x9208,
	TAG_Flash						= 0x9209,
	TAG_FocalLength					= 0x920a,
	TAG_FlashEnergy					= 0xa20b,
	TAG_SpatialFrequencyResponse	= 0xa20c,
	TAG_FocalPlaneXResolution		= 0xa20e,
	TAG_FocalPlaneYResolution		= 0xa20f,
	TAG_FocalPlaneResolutionUnit	= 0xa210,
	TAG_SubjectLocation				= 0xa214,
	TAG_ExposureIndex				= 0xa215,
	TAG_SensingMethod				= 0xa217,
	TAG_FileSource					= 0xa300,
	TAG_SceneType					= 0xa301,
	TAG_CFAPattern					= 0xa302,
	TAG_InteroperabilityIFDPointer	= 0xa005,
	TAG_GPSVersionID				= 0x0000,
	TAG_GPSLatitudeRef				= 0x0001,
	TAG_GPSLatitude					= 0x0002,
	TAG_GPSLongitudeRef				= 0x0003,
	TAG_GPSLongitude				= 0x0004,
	TAG_GPSAltitudeRef				= 0x0005,
	TAG_GPSAltitude					= 0x0006,
	TAG_GPSTimeStamp				= 0x0007,
	TAG_GPSSatellites				= 0x0008,
	TAG_GPSStatus					= 0x0009,
	TAG_GPSMeasureMode				= 0x000a,
	TAG_GPSDOP						= 0x000b,
	TAG_GPSSpeedRef					= 0x000c,
	TAG_GPSSpeed					= 0x000d,
	TAG_GPSTrackRef					= 0x000e,
	TAG_GPSTrack					= 0x000f,
	TAG_GPSImgDirectionRef			= 0x0010,
	TAG_GPSImgDirection				= 0x0011,
	TAG_GPSMapDatum					= 0x0012,
	TAG_GPSDestLatitudeRef			= 0x0013,
	TAG_GPSDestLatitude				= 0x0014,
	TAG_GPSDestLongitudeRef			= 0x0015,
	TAG_GPSDestLongitude			= 0x0016,
	TAG_GPSBearingRef				= 0x0017,
	TAG_GPSBearing					= 0x0018,
	TAG_GPSDestDistanceRef			= 0x0019,
	TAG_GPSDestDistance				= 0x001a,
};

struct Header {
	XPackedUShort_BE(SOI);
	XPackedUShort_BE(APP1);
	XPackedUShort_BE(Size);
	char ExifCode[6];
};

struct TIFF_BE {
	XPackedUShort_BE(Code);
	XPackedULong_BE(Offset0thIFD);
};

struct TIFF_LE {
	XPackedUShort_LE(Code);
	XPackedULong_LE(Offset0thIFD);
};

struct IFDHeader_BE {
	XPackedUShort_BE(TagCount);
};

struct IFDHeader_LE {
	XPackedUShort_LE(TagCount);
};

struct RATIONAL_BE {
	XPackedULong_BE(numerator);
	XPackedULong_BE(denominator);
};

struct RATIONAL_LE {
	XPackedULong_LE(numerator);
	XPackedULong_LE(denominator);
};

struct SRATIONAL_BE {
	XPackedULong_BE(numerator);
	XPackedULong_BE(denominator);
};

struct SRATIONAL_LE {
	XPackedULong_LE(numerator);
	XPackedULong_LE(denominator);
};

struct SHORT_BE {
	XPackedUShort_BE(num);
};

struct SHORT_LE {
	XPackedUShort_LE(num);
};

struct LONG_BE {
	XPackedULong_BE(num);
};

struct LONG_LE {
	XPackedULong_LE(num);
};

struct SLONG_BE {
	XPackedULong_BE(num);
};

struct SLONG_LE {
	XPackedULong_LE(num);
};

union ValueRaw_BE {
	char BYTE[4];
	char ASCII[4];
	struct {
		XPackedUShort_BE(num);
		XPackedUShort_BE(second);
	} SHORT;
	struct {
		XPackedULong_BE(num);
	} LONG;
	struct {
		XPackedULong_BE(num);
	} SLONG;
};

struct TagRaw_BE {
	XPackedUShort_BE(Tag);
	XPackedUShort_BE(Type);
	XPackedULong_BE(Count);
	unsigned char ValueRaw[4];
};

union ValueRaw_LE {
	char BYTE[4];
	char ASCII[4];
	struct {
		XPackedUShort_LE(num);
		XPackedUShort_LE(second);
	} SHORT;
	struct {
		XPackedULong_LE(num);
	} LONG;
	struct {
		XPackedULong_LE(num);
	} SLONG;
};

struct TagRaw_LE {
	XPackedUShort_LE(Tag);
	XPackedUShort_LE(Type);
	XPackedULong_LE(Count);
	unsigned char ValueRaw[4];
};

struct TagInfo {
	unsigned short tag;
	const char *name;
	unsigned short type;
	const char *nameForOwner;
};

struct TypeInfo {
	unsigned short type;
	const char *name;
	size_t unitSize;
};

static const TagInfo g_tagInfoTbl[] = {
	{ TAG_ImageWidth,					"ImageWidth",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_ImageLength,					"ImageLength",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_BitsPerSample,				"BitsPerSample",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_Compression,					"Compression",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_PhotometricInterpretation,	"PhotometricInterpretation",	TYPE_UNDEFINED,	NULL,				},
	{ TAG_Orientation,					"Orientation",					TYPE_SHORT,		NULL,				},
	{ TAG_SamplesPerPixel,				"SamplesPerPixel",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_PlanarConfiguration,			"PlanarConfiguration",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_YCbCrSubSampling,				"YCbCrSubSampling",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_YCbCrPositioning,				"YCbCrPositioning",				TYPE_SHORT,		NULL,				},
	{ TAG_XResolution,					"XResolution",					TYPE_RATIONAL,	NULL,				},
	{ TAG_YResolution,					"YResolution",					TYPE_RATIONAL,	NULL,				},
	{ TAG_ResolutionUnit,				"ResolutionUnit",				TYPE_SHORT,		NULL,				},
	{ TAG_StripOffsets,					"StripOffsets",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_RowsPerStrip,					"RowsPerStrip",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_StripByteCounts,				"StripByteCounts",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_JPEGInterchangeFormat,		"JPEGInterchangeFormat",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_JPEGInterchangeFormatLength,	"JPEGInterchangeFormatLength",	TYPE_UNDEFINED,	NULL,				},
	{ TAG_TransferFunction,				"TransferFunction",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_WhitePoint,					"WhitePoint",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_PrimaryChromaticities,		"PrimaryChromaticities",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_YCbCrCoefficients,			"YCbCrCoefficients",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_ReferenceBlackWhite,			"ReferenceBlackWhite",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_DateTime,						"DateTime",						TYPE_ASCII,		NULL,				},
	{ TAG_ImageDescription,				"ImageDescription",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_Make,							"Make",							TYPE_ASCII,		NULL,				},
	{ TAG_Model,						"Model",						TYPE_ASCII,		NULL,				},
	{ TAG_Software,						"Software",						TYPE_UNDEFINED,	NULL,				},
	{ TAG_Artist,						"Artist",						TYPE_UNDEFINED,	NULL,				},
	{ TAG_Copyright,					"Copyright",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_ExifIFDPointer,				"ExifIFDPointer",				TYPE_SHORT,		"Exif",				},
	{ TAG_GPSInfoIFDPointer,			"GPSInfoIFDPointer",			TYPE_SHORT,		"GPSInfo",			},
	{ TAG_ExifVersion,					"ExifVersion",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_FlashPixVersion,				"FlashPixVersion",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_ColorSpace,					"ColorSpace",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_ComponentsConfiguration,		"ComponentsConfiguration",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_CompressedBitsPerPixel,		"CompressedBitsPerPixel",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_PixelXDimension,				"PixelXDimension",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_PixelYDimension,				"PixelYDimension",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_MakerNote,					"MakerNote",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_UserComment,					"UserComment",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_RelatedSoundFile,				"RelatedSoundFile",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_DateTimeOriginal,				"DateTimeOriginal",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_DateTimeDigitized,			"DateTimeDigitized",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_SubSecTime,					"SubSecTime",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_SubSecTimeOriginal,			"SubSecTimeOriginal",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_SubSecTimeDigitized,			"SubSecTimeDigitized",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_ExposureTime,					"ExposureTime",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_FNumber,						"FNumber",						TYPE_UNDEFINED,	NULL,				},
	{ TAG_ExposureProgram,				"ExposureProgram",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_SpectralSensitivity,			"SpectralSensitivity",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_ISOSpeedRatings,				"ISOSpeedRatings",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_OECF,							"OECF",							TYPE_UNDEFINED,	NULL,				},
	{ TAG_ShutterSpeedValue,			"ShutterSpeedValue",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_ApertureValue,				"ApertureValue",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_BrightnessValue,				"BrightnessValue",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_ExposureBiasValue,			"ExposureBiasValue",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_MaxApertureValue,				"MaxApertureValue",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_SubjectDistance,				"SubjectDistance",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_MeteringMode,					"MeteringMode",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_LightSource,					"LightSource",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_Flash,						"Flash",						TYPE_UNDEFINED,	NULL,				},
	{ TAG_FocalLength,					"FocalLength",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_FlashEnergy,					"FlashEnergy",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_SpatialFrequencyResponse,		"SpatialFrequencyResponse",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_FocalPlaneXResolution,		"FocalPlaneXResolution",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_FocalPlaneYResolution,		"FocalPlaneYResolution",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_FocalPlaneResolutionUnit,		"FocalPlaneResolutionUnit",		TYPE_UNDEFINED,	NULL,				},
	{ TAG_SubjectLocation,				"SubjectLocation",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_ExposureIndex,				"ExposureIndex",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_SensingMethod,				"SensingMethod",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_FileSource,					"FileSource",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_SceneType,					"SceneType",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_CFAPattern,					"CFAPattern",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_InteroperabilityIFDPointer,	"InteroperabilityIFDPointer",	TYPE_SHORT,		"Interoperability"	},
	{ TAG_GPSVersionID,					"GPSVersionID",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSLatitudeRef,				"GPSLatitudeRef",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSLatitude,					"GPSLatitude",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSLongitudeRef,				"GPSLongitudeRef",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSLongitude,					"GPSLongitude",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSAltitudeRef,				"GPSAltitudeRef",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSAltitude,					"GPSAltitude",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSTimeStamp,					"GPSTimeStamp",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSSatellites,				"GPSSatellites",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSStatus,					"GPSStatus",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSMeasureMode,				"GPSMeasureMode",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSDOP,						"GPSDOP",						TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSSpeedRef,					"GPSSpeedRef",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSSpeed,						"GPSSpeed",						TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSTrackRef,					"GPSTrackRef",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSTrack,						"GPSTrack",						TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSImgDirectionRef,			"GPSImgDirectionRef",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSImgDirection,				"GPSImgDirection",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSMapDatum,					"GPSMapDatum",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSDestLatitudeRef,			"GPSDestLatitudeRef",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSDestLatitude,				"GPSDestLatitude",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSDestLongitudeRef,			"GPSDestLongitudeRef",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSDestLongitude,				"GPSDestLongitude",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSBearingRef,				"GPSBearingRef",				TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSBearing,					"GPSBearing",					TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSDestDistanceRef,			"GPSDestDistanceRef",			TYPE_UNDEFINED,	NULL,				},
	{ TAG_GPSDestDistance,				"GPSDestDistance",				TYPE_UNDEFINED,	NULL,				},
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

const TagInfo *TagToInfo(unsigned short tag)
{
	const TagInfo *pTagInfo = g_tagInfoTbl;
	for (int i = 0; i < NUMBEROF(g_tagInfoTbl); i++, pTagInfo++) {
		if (pTagInfo->tag == tag) return pTagInfo;
	}
	return NULL;
}

const TypeInfo *TypeToInfo(unsigned short type)
{
	const TypeInfo *pTypeInfo = g_typeInfoTbl;
	for (int i = 0; i < NUMBEROF(g_typeInfoTbl); i++, pTypeInfo++) {
		if (pTypeInfo->type == type) return pTypeInfo;
	}
	return NULL;
}

template<typename RATIONAL_T>
Value RationalToValue(Signal sig, const RATIONAL_T &rational)
{
	unsigned long numerator = XUnpackULong(rational.numerator);
	unsigned long denominator = XUnpackULong(rational.denominator);
	if (denominator == 0) {
		sig.SetError(ERR_ValueError, "rational denominator can't be zero");
		return Value::Null;
	}
	return Value(Fraction(numerator, denominator));
}

template<typename SRATIONAL_T>
Value SRationalToValue(Signal sig, const SRATIONAL_T &rational)
{
	long numerator = XUnpackLong(rational.numerator);
	long denominator = XUnpackLong(rational.denominator);
	if (denominator == 0) {
		sig.SetError(ERR_ValueError, "rational denominator can't be zero");
		return Value::Null;
	}
	
	return Value(Fraction(numerator, denominator));
}

template<typename IFDHeader_T, typename TagRaw_T, typename ValueRaw_T, typename SHORT_T,
		typename LONG_T, typename RATIONAL_T, typename SLONG_T, typename SRATIONAL_T>
bool ParseIFD_T(Environment &env, Signal sig, IFD *pIFD,
					char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	if (offset + SIZE_IFDHeader >= bytesAPP1 - 1) {
		SetError_InvalidFormat(sig);
		return false;
	}
	IFDHeader_T *pIFDHeader = reinterpret_cast<IFDHeader_T *>(buff + offset);
	size_t nTags = XUnpackUShort(pIFDHeader->TagCount);
	offset += SIZE_IFDHeader;
	if (offset + nTags * SIZE_TagRaw + UNITSIZE_SHORT >= bytesAPP1 - 1) {
		SetError_InvalidFormat(sig);
		return false;
	}
	if (pOffsetNext != NULL) {
		SHORT_T *pShort = reinterpret_cast<SHORT_T *>(buff + offset + nTags * SIZE_TagRaw);
		*pOffsetNext = XUnpackUShort(pShort->num);
	}
	for (size_t iTag = 0; iTag < nTags; iTag++, offset += SIZE_TagRaw) {
		TagRaw_T *pTagRaw = reinterpret_cast<TagRaw_T *>(buff + offset);
		unsigned short tag = XUnpackUShort(pTagRaw->Tag);
		unsigned short type = XUnpackUShort(pTagRaw->Type);
		unsigned long count = XUnpackULong(pTagRaw->Count);
		ValueRaw_T *pValueRaw = reinterpret_cast<ValueRaw_T *>(pTagRaw->ValueRaw);
		const TagInfo *pTagInfo = TagToInfo(tag);
#if 0
		do {
			const TypeInfo *pTypeInfo = TypeToInfo(type);
			::printf("%s [%04x], %s [%04x], %08x, %08x\n",
					(pTagInfo == NULL)? "(unknown)" : pTagInfo->name, tag,
					(pTypeInfo == NULL)? "(unknown)" : pTypeInfo->name, type,
					count, XUnpackULong(pValueRaw->LONG.num));
		} while (0);
#endif
		if (pTagInfo != NULL && pTagInfo->nameForOwner != NULL) {
			std::auto_ptr<IFD> pIFDSub(new IFD());
			size_t offsetSub = XUnpackULong(pValueRaw->LONG.num);
			size_t offsetNext = 0;
			if (!ParseIFD_T<IFDHeader_T, TagRaw_T, ValueRaw_T, SHORT_T,
					LONG_T, RATIONAL_T, SLONG_T, SRATIONAL_T>(env, sig,
							pIFDSub.get(), buff, bytesAPP1, offsetSub, &offsetNext)) {
				return false;
			}
			pIFD->GetTagOwner().push_back(new Tag(tag, type, pIFDSub.release()));
		} else {
			Value value;
			switch (type) {
			case TYPE_BYTE: {
				char *p = pValueRaw->BYTE;
				if (count > 4) {
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return false;
					}
					p = buff + offset;
				}
				value.InitAsBinary(env, p, count, false);
				break;
			}
			case TYPE_ASCII: {
				char *p = pValueRaw->ASCII;
				if (count > 4) {
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return false;
					}
					p = buff + offset;
				}
				value = Value(env, p, count - 1);
				break;
			}
			case TYPE_SHORT: {
				if (count == 1) {
					value = Value(XUnpackUShort(pValueRaw->SHORT.num));
				} else if (count == 2) {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					valList.push_back(Value(XUnpackUShort(pValueRaw->SHORT.num)));
					valList.push_back(Value(XUnpackUShort(pValueRaw->SHORT.second)));
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + UNITSIZE_SHORT * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return false;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SHORT) {
						SHORT_T *pShort = reinterpret_cast<SHORT_T *>(buff + offset);
						valList.push_back(Value(XUnpackUShort(pShort->num)));
					}
				}
				break;
			}
			case TYPE_LONG: {
				if (count == 1) {
					value = Value(XUnpackULong(pValueRaw->LONG.num));
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + UNITSIZE_LONG * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return false;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_LONG) {
						LONG_T *pLong = reinterpret_cast<LONG_T *>(buff + offset);
						valList.push_back(Value(XUnpackULong(pLong->num)));
					}
				}
				break;
			}
			case TYPE_RATIONAL: {
				size_t offset = XUnpackULong(pValueRaw->LONG.num);
				if (offset + UNITSIZE_RATIONAL * count >= bytesAPP1 - 1) {
					SetError_InvalidFormat(sig);
					return false;
				}
				if (count == 1) {
					RATIONAL_T *pRational = reinterpret_cast<RATIONAL_T *>(buff + offset);
					value = RationalToValue(sig, *pRational);
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + UNITSIZE_RATIONAL * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return false;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_RATIONAL) {
						RATIONAL_T *pRational = reinterpret_cast<RATIONAL_T *>(buff + offset);
						Value valueItem = RationalToValue(sig, *pRational);
						if (valueItem.IsInvalid()) return false;
						valList.push_back(valueItem);
					}
				}
				break;
			}
			case TYPE_UNDEFINED: {
				char *p = pValueRaw->BYTE;
				if (count > 4) {
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return false;
					}
					p = buff + offset;
				}
				value.InitAsBinary(env, p, count, false);
				break;
			}
			case TYPE_SLONG: {
				if (count == 1) {
					value = Value(XUnpackLong(pValueRaw->SLONG.num));
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackLong(pValueRaw->SLONG.num);
					if (offset + UNITSIZE_SLONG * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return false;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SLONG) {
						SLONG_T *pLong = reinterpret_cast<SLONG_T *>(buff + offset);
						valList.push_back(Value(XUnpackULong(pLong->num)));
					}
				}
				break;
			}
			case TYPE_SRATIONAL: {
				size_t offset = XUnpackULong(pValueRaw->LONG.num);
				if (offset + UNITSIZE_SRATIONAL * count >= bytesAPP1 - 1) {
					SetError_InvalidFormat(sig);
					return false;
				}
				if (count == 1) {
					SRATIONAL_T *pRational = reinterpret_cast<SRATIONAL_T *>(buff + offset);
					value = RationalToValue(sig, *pRational);
				} else {
					ValueList &valList = value.InitAsList(env);
					valList.reserve(count);
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + UNITSIZE_SRATIONAL * count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return false;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SRATIONAL) {
						SRATIONAL_T *pRational = reinterpret_cast<SRATIONAL_T *>(buff + offset);
						Value valueItem = SRationalToValue(sig, *pRational);
						if (valueItem.IsInvalid()) return false;
						valList.push_back(valueItem);
					}
				}
				break;
			}
			default: {
				
				break;
			}
			}
			pIFD->GetTagOwner().push_back(new Tag(tag, type, value));
		}
	}
	return true;
}

inline bool ParseIFD_BE(Environment &env, Signal sig, IFD *pIFD,
				char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	return ParseIFD_T<IFDHeader_BE, TagRaw_BE, ValueRaw_BE, SHORT_BE,
		LONG_BE, RATIONAL_BE, SLONG_BE, SRATIONAL_BE>(env, sig, pIFD, buff, bytesAPP1, offset, pOffsetNext);
}

inline bool ParseIFD_LE(Environment &env, Signal sig, IFD *pIFD,
				char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	return ParseIFD_T<IFDHeader_LE, TagRaw_LE, ValueRaw_LE, SHORT_LE,
		LONG_LE, RATIONAL_LE, SLONG_LE, SRATIONAL_LE>(env, sig, pIFD, buff, bytesAPP1, offset, pOffsetNext);
}

//-----------------------------------------------------------------------------
// Tag
//-----------------------------------------------------------------------------
void Tag::Print(int indentLevel) const
{
	Signal sig;
	const TagInfo *pTagInfo = TagToInfo(_tag);
	const TypeInfo *pTypeInfo = TypeToInfo(_type);
	if (IsIFDPointer()) {
		::printf("%*s%s [%04x]\n", indentLevel * 2, "",
			(pTagInfo == NULL)? "(unknown)" : pTagInfo->name, _tag);
		GetIFD()->GetTagOwner().Print(indentLevel + 1);
	} else {
		::printf("%*s%s [%04x], %s [%04x], %s\n", indentLevel * 2, "",
			(pTagInfo == NULL)? "(unknown)" : pTagInfo->name, _tag,
			(pTypeInfo == NULL)? "(unknown)" : pTypeInfo->name, _type,
			_value.ToString(sig).c_str());
	}
}

//-----------------------------------------------------------------------------
// TagList
//-----------------------------------------------------------------------------
void TagList::Print(int indentLevel) const
{
	foreach_const (TagList, ppTag, *this) {
		const Tag *pTag = *ppTag;
		pTag->Print(indentLevel);
	}
}

//-----------------------------------------------------------------------------
// TagOwner
//-----------------------------------------------------------------------------
TagOwner::~TagOwner()
{
	Clear();
}

void TagOwner::Clear()
{
	foreach (TagOwner, ppTag, *this) {
		Tag *pTag = *ppTag;
		delete pTag;
	}
	clear();
}

//-----------------------------------------------------------------------------
// Object_exif implementation
//-----------------------------------------------------------------------------
Object_exif::Object_exif() : Object(Gura_UserClass(exif)),
							_pIFD0th(new IFD()), _pIFD1st(new IFD())
{
}

Object_exif::~Object_exif()
{
}

Object *Object_exif::Clone() const
{
	return NULL;
}

String Object_exif::ToString(Signal sig, bool exprFlag)
{
	return String("<jpeg.exif>");
}

bool Object_exif::ReadStream(Signal sig, Stream &stream)
{
	Environment &env = *this;
	OAL::Memory mem;
	mem.Allocate(65536);
	char *buff = reinterpret_cast<char *>(mem.GetPointer());
	if (!ReadBuff(sig, stream, buff, 12)) return false;
	size_t bytesAPP1 = 0;
	do {
		Header *pHeader = reinterpret_cast<Header *>(buff);
		if (XUnpackUShort(pHeader->SOI) != MARKER_SOI) {
			SetError_InvalidFormat(sig);
			return false;
		}
		if (XUnpackUShort(pHeader->APP1) != MARKER_APP1) {
			SetError_InvalidFormat(sig);
			return false;
		}
		bytesAPP1 = XUnpackUShort(pHeader->Size);
		if (bytesAPP1 < 8) {
			SetError_InvalidFormat(sig);
			return false;
		}
		if (::memcmp(pHeader->ExifCode, "Exif\0\0", 6) != 0) {
			SetError_InvalidFormat(sig);
			return false;
		}
	} while (0);
	if (!ReadBuff(sig, stream, buff, bytesAPP1)) return false;
	if (::memcmp(buff, "MM", 2) == 0) {
		TIFF_BE *pTIFF = reinterpret_cast<TIFF_BE *>(buff + 2);
		if (XUnpackUShort(pTIFF->Code) != 0x002a) {
			SetError_InvalidFormat(sig);
			return false;
		}
		size_t offset = XUnpackULong(pTIFF->Offset0thIFD);
		if (!ParseIFD_BE(env, sig, _pIFD0th.get(), buff, bytesAPP1, offset, &offset)) {
			return false;
		}
	} else if (::memcmp(buff, "II", 2) == 0) {
		TIFF_LE *pTIFF = reinterpret_cast<TIFF_LE *>(buff + 2);
		if (XUnpackUShort(pTIFF->Code) != 0x002a) {
			SetError_InvalidFormat(sig);
			return false;
		}
		size_t offset = XUnpackULong(pTIFF->Offset0thIFD);
		if (!ParseIFD_LE(env, sig, _pIFD0th.get(), buff, bytesAPP1, offset, &offset)) {
			return false;
		}
	}
	_pIFD0th->GetTagOwner().Print();
	//GetConsole()->Dump(sig, buff, bytesAPP1);
	return true;
}

//-----------------------------------------------------------------------------
// Gura interfaces for exif
//-----------------------------------------------------------------------------
// implementation of class exif
Gura_ImplementUserClass(exif)
{
}

}}
