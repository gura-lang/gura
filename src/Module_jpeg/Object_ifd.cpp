#include "Object_ifd.h"

Gura_BeginModule(jpeg)

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

template<typename IFDHeader_T, typename TagRaw_T, typename ValueRaw_T, typename SHORT_T,
		typename LONG_T, typename RATIONAL_T, typename SLONG_T, typename SRATIONAL_T>
Object_ifd *ParseIFD_T(Environment &env, Signal sig,
					char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	if (offset + SIZE_IFDHeader >= bytesAPP1 - 1) {
		SetError_InvalidFormat(sig);
		return NULL;
	}
	IFDHeader_T *pIFDHeader = reinterpret_cast<IFDHeader_T *>(buff + offset);
	size_t nTags = XUnpackUShort(pIFDHeader->TagCount);
	offset += SIZE_IFDHeader;
	if (offset + nTags * SIZE_TagRaw + UNITSIZE_SHORT >= bytesAPP1 - 1) {
		SetError_InvalidFormat(sig);
		return NULL;
	}
	if (pOffsetNext != NULL) {
		SHORT_T *pShort = reinterpret_cast<SHORT_T *>(buff + offset + nTags * SIZE_TagRaw);
		*pOffsetNext = XUnpackUShort(pShort->num);
	}
	AutoPtr<Object_ifd> pObjIFD(new Object_ifd());
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
			size_t offsetSub = XUnpackULong(pValueRaw->LONG.num);
			size_t offsetNext = 0;
			AutoPtr<Object_ifd> pObjIFDSub(ParseIFD_T<IFDHeader_T, TagRaw_T,
					ValueRaw_T, SHORT_T,
					LONG_T, RATIONAL_T, SLONG_T, SRATIONAL_T>(env, sig,
									buff, bytesAPP1, offsetSub, &offsetNext));
			if (pObjIFDSub.IsNull()) return NULL;
			pObjIFD->GetTagOwner().push_back(new Tag(tag, type, pObjIFDSub.release()));
		} else {
			Value value;
			switch (type) {
			case TYPE_BYTE: {
				char *p = pValueRaw->BYTE;
				if (count > 4) {
					size_t offset = XUnpackULong(pValueRaw->LONG.num);
					if (offset + count >= bytesAPP1 - 1) {
						SetError_InvalidFormat(sig);
						return NULL;
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
						return NULL;
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
						return NULL;
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
						return NULL;
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
					return NULL;
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
						return NULL;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_RATIONAL) {
						RATIONAL_T *pRational = reinterpret_cast<RATIONAL_T *>(buff + offset);
						Value valueItem = RationalToValue(sig, *pRational);
						if (valueItem.IsInvalid()) return NULL;
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
						return NULL;
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
						return NULL;
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
					return NULL;
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
						return NULL;
					}
					for (unsigned int i = 0; i < count; i++, offset += UNITSIZE_SRATIONAL) {
						SRATIONAL_T *pRational = reinterpret_cast<SRATIONAL_T *>(buff + offset);
						Value valueItem = RationalToValue(sig, *pRational);
						if (valueItem.IsInvalid()) return NULL;
						valList.push_back(valueItem);
					}
				}
				break;
			}
			default: {
				
				break;
			}
			}
			pObjIFD->GetTagOwner().push_back(new Tag(tag, type, value));
		}
	}
	return pObjIFD.release();
}

Object_ifd *ParseIFD_BE(Environment &env, Signal sig,
				char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	return ParseIFD_T<IFDHeader_BE, TagRaw_BE, ValueRaw_BE, SHORT_BE,
		LONG_BE, RATIONAL_BE, SLONG_BE, SRATIONAL_BE>(env, sig, buff, bytesAPP1, offset, pOffsetNext);
}

Object_ifd *ParseIFD_LE(Environment &env, Signal sig,
				char *buff, size_t bytesAPP1, size_t offset, size_t *pOffsetNext)
{
	return ParseIFD_T<IFDHeader_LE, TagRaw_LE, ValueRaw_LE, SHORT_LE,
		LONG_LE, RATIONAL_LE, SLONG_LE, SRATIONAL_LE>(env, sig, buff, bytesAPP1, offset, pOffsetNext);
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
		GetObjectIFD()->GetTagOwner().Print(indentLevel + 1);
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
// Object_ifd implementation
//-----------------------------------------------------------------------------
Object_ifd::Object_ifd() : Object(Gura_UserClass(ifd))
{
}

Object_ifd::~Object_ifd()
{
}

Object *Object_ifd::Clone() const
{
	return NULL;
}

Value Object_ifd::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	return Value::Null;
}

bool Object_ifd::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	//symbols.insert(Gura_UserSymbol(surface));
	//symbols.insert(Gura_UserSymbol(width));
	//symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_ifd::DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	//if (pSymbol->IsIdentical(Gura_UserSymbol(surface))) {
	//	return Value(Object_surface::Reference(_pObjSurface.get()));
	//}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_ifd::ToString(Signal sig, bool exprFlag)
{
	return String("<jpeg.ifd>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for ifd
//-----------------------------------------------------------------------------

// implementation of class ifd
Gura_ImplementUserClass(ifd)
{
}

}}
