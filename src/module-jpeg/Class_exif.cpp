//-----------------------------------------------------------------------------
// Reference: http://www.exif.org/
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "Class_exif.h"

Gura_BeginModuleScope(jpeg)

//-----------------------------------------------------------------------------
// Object_exif implementation
//-----------------------------------------------------------------------------
Object_exif::Object_exif() : Object(Gura_UserClass(exif)), _bigendianFlag(false)
{
	_strip.validFlag = false;
	_strip.width = _strip.height = 0;
}

Object_exif::~Object_exif()
{
}

Object *Object_exif::Clone() const
{
	return nullptr;
}

Value Object_exif::IndexGet(Environment &env, const Value &valueIdx)
{
	Signal &sig = GetSignal();
	if (_pObj0thIFD.IsNull()) return Value::Nil;
	return _pObj0thIFD->IndexGet(env, valueIdx);
}

String Object_exif::ToString(bool exprFlag)
{
	return String("<jpeg.exif>");
}

Object_exif *Object_exif::ReadStream(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	AutoPtr<Memory> pMemory(new MemoryHeap(65536));
	char *buff = reinterpret_cast<char *>(pMemory->GetPointer());
	SHORT_BE *pShort = reinterpret_cast<SHORT_BE *>(buff);
	if (!ReadBuff(sig, stream, pShort, UNITSIZE_SHORT)) return nullptr;
	if (Gura_UnpackUInt16(pShort->num) != MARKER_SOI) {
		sig.SetError(ERR_FormatError, "invalid jpeg file");
		return nullptr;
	}
	size_t bytesAPP1 = 0;
	for (;;) {
		if (!ReadBuff(sig, stream, pShort, UNITSIZE_SHORT)) return nullptr;
		unsigned short marker = Gura_UnpackUInt16(pShort->num);
		if (marker < MARKER_APP0 || MARKER_APP15 < marker) {
			return nullptr;	// exif doesn't exist
		}
		if (!ReadBuff(sig, stream, pShort, UNITSIZE_SHORT)) return nullptr;
		unsigned short bytes = Gura_UnpackUInt16(pShort->num);
		if (bytes < UNITSIZE_SHORT) {
			sig.SetError(ERR_FormatError, "invalid jpeg file");
			return nullptr;
		}
		if (marker == MARKER_APP1) {
			char code[6];
			if (!ReadBuff(sig, stream, code, 6)) return nullptr;
			if (::memcmp(code, "Exif\0\0", 6) != 0) {
				return nullptr;	// exif doesn't exist
			}
			bytesAPP1 = bytes;
			break;
		}
		if (!stream.Seek(sig, bytes - 2, Stream::SeekCur)) return nullptr;
	}
	if (!ReadBuff(sig, stream, buff, bytesAPP1)) return nullptr;
	AutoPtr<Object_exif> pObj(new Object_exif());
	if (::memcmp(buff, "MM", 2) == 0) {
		pObj->_bigendianFlag = true;
		TIFF_BE *pTIFF = reinterpret_cast<TIFF_BE *>(buff + 2);
		if (Gura_UnpackUInt16(pTIFF->Code) != 0x002a) {
			SetError_InvalidFormat(sig);
			return nullptr;
		}
		size_t offset = Gura_UnpackUInt32(pTIFF->Offset0thIFD);
		pObj->_pObj0thIFD.reset(ParseIFD_BE(env, sig, Symbol::Add("ifd0"),
										buff, bytesAPP1, offset, &offset));
		if (pObj->_pObj0thIFD.IsNull()) return nullptr;
		if (offset != 0) {
			pObj->_pObj1stIFD.reset(ParseIFD_BE(env, sig, Symbol::Add("ifd1"),
										buff, bytesAPP1, offset, &offset));
			if (pObj->_pObj1stIFD.IsNull()) return nullptr;
		}
	} else if (::memcmp(buff, "II", 2) == 0) {
		pObj->_bigendianFlag = false;
		TIFF_LE *pTIFF = reinterpret_cast<TIFF_LE *>(buff + 2);
		if (Gura_UnpackUInt16(pTIFF->Code) != 0x002a) {
			SetError_InvalidFormat(sig);
			return nullptr;
		}
		size_t offset = Gura_UnpackUInt32(pTIFF->Offset0thIFD);
		pObj->_pObj0thIFD.reset(ParseIFD_LE(env, sig, Symbol::Add("ifd0"),
										buff, bytesAPP1, offset, &offset));
		if (pObj->_pObj0thIFD.IsNull()) return nullptr;
		if (offset != 0) {
			pObj->_pObj1stIFD.reset(ParseIFD_LE(env, sig, Symbol::Add("ifd1"),
										buff, bytesAPP1, offset, &offset));
			if (pObj->_pObj1stIFD.IsNull()) return nullptr;
		}
	} else {
		SetError_InvalidFormat(sig);
		return nullptr;
	}
	if (pObj->_pObj1stIFD.IsNull()) return pObj.release();
	// extract thumbnail image
	UInt16 compression = 0;
	Object_tag *pObjTag_Compression =
		pObj->_pObj1stIFD->GetTagOwner().FindById(TAG_Compression);
	if (pObjTag_Compression != nullptr && pObjTag_Compression->GetType() == TYPE_SHORT) {
		compression = pObjTag_Compression->GetValue().GetUInt16();
	}
	if (compression == 1) {	// uncompressed
		Object_tag *pObjTag_ImageWidth =
			pObj->_pObj1stIFD->GetTagOwner().FindById(TAG_ImageWidth);
		Object_tag *pObjTag_ImageLength =
			pObj->_pObj1stIFD->GetTagOwner().FindById(TAG_ImageLength);
		Object_tag *pObjTag_StripOffsets =
			pObj->_pObj1stIFD->GetTagOwner().FindById(TAG_StripOffsets);
		Object_tag *pObjTag_StripByteCounts =
			pObj->_pObj1stIFD->GetTagOwner().FindById(TAG_StripByteCounts);
		if (pObjTag_ImageWidth == nullptr ||
					pObjTag_ImageLength == nullptr ||
					pObjTag_StripOffsets == nullptr ||
					pObjTag_StripByteCounts == nullptr) {
			// nothing to do
		} else if (!pObjTag_ImageWidth->IsTypeSHORTorLONG() ||
					!pObjTag_ImageLength->IsTypeSHORTorLONG() ||
					!pObjTag_StripOffsets->IsTypeSHORTorLONG() ||
					!pObjTag_StripByteCounts->IsTypeSHORTorLONG()) {
			// nothing to do
		} else {
			pObj->_strip.validFlag = true;
			pObj->_strip.width = pObjTag_ImageWidth->GetValue().GetUInt32();
			pObj->_strip.height = pObjTag_ImageLength->GetValue().GetUInt32();
			size_t offsetThumbnail = pObjTag_StripOffsets->GetValue().GetUInt32();
			size_t bytesThumbnail = pObjTag_StripByteCounts->GetValue().GetUInt32();
			if (offsetThumbnail + bytesThumbnail >= bytesAPP1 - 1) {
				SetError_InvalidFormat(sig);
				return nullptr;
			}
			pObj->_pObjBinaryThumbnail.reset(new Object_binary(env,
								buff + offsetThumbnail, bytesThumbnail, false));
		}
	} else if (compression == 6) {	// JPEG compression
		Object_tag *pObjTag_JPEGInterchangeFormat =
			pObj->_pObj1stIFD->GetTagOwner().FindById(TAG_JPEGInterchangeFormat);
		Object_tag *pObjTag_JPEGInterchangeFormatLength =
			 pObj->_pObj1stIFD->GetTagOwner().FindById(TAG_JPEGInterchangeFormatLength);
		if (pObjTag_JPEGInterchangeFormat == nullptr ||
					pObjTag_JPEGInterchangeFormatLength == nullptr) {
			// nothing to do
		} else if (pObjTag_JPEGInterchangeFormat->GetType() != TYPE_LONG ||
					pObjTag_JPEGInterchangeFormatLength->GetType() != TYPE_LONG) {
			// nothing to do
		} else {
			size_t offsetThumbnail = pObjTag_JPEGInterchangeFormat->GetValue().GetUInt32();
			size_t bytesThumbnail = pObjTag_JPEGInterchangeFormatLength->GetValue().GetUInt32();
			if (offsetThumbnail + bytesThumbnail >= bytesAPP1 - 1) {
				SetError_InvalidFormat(sig);
				return nullptr;
			}
			pObj->_pObjBinaryThumbnail.reset(new Object_binary(env,
								buff + offsetThumbnail, bytesThumbnail, false));
		}
	} else {
		SetError_InvalidFormat(sig);
		return nullptr;
	}
	return pObj.release();
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// jpeg.exif#endian
Gura_DeclareProperty_R(exif, endian)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(exif, endian)
{
	Object_exif *pObjThis = Object_exif::GetObject(valueThis);
	return Value(pObjThis->GetBigendianFlag()? Gura_UserSymbol(big) : Gura_UserSymbol(little));
}

// jpeg.exif#ifd0
Gura_DeclareProperty_R(exif, ifd0)
{
	SetPropAttr(VTYPE_ifd, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(exif, ifd0)
{
	Object_exif *pObjThis = Object_exif::GetObject(valueThis);
	Object_ifd *pObj0thIFD = pObjThis->GetObj0thIFD();
	if (pObj0thIFD == nullptr) return Value::Nil;
	return Value(Object_ifd::Reference(pObj0thIFD));
}

// jpeg.exif#ifd1
Gura_DeclareProperty_R(exif, ifd1)
{
	SetPropAttr(VTYPE_ifd, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(exif, ifd1)
{
	Object_exif *pObjThis = Object_exif::GetObject(valueThis);
	Object_ifd *pObj1stIFD = pObjThis->GetObj1stIFD();
	if (pObj1stIFD == nullptr) return Value::Nil;
	return Value(Object_ifd::Reference(pObj1stIFD));
}

// jpeg.exif#thumbnail
Gura_DeclareProperty_R(exif, thumbnail)
{
	SetPropAttr(VTYPE_image, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(exif, thumbnail)
{
	Signal &sig = env.GetSignal();
	Object_exif *pObjThis = Object_exif::GetObject(valueThis);
	Object_binary *pObjBinaryThumbnail = pObjThis->GetObjBinaryThumbnail();
	Object_image *pObjImageThumbnail = pObjThis->GetObjImageThumbnail();
	const Object_exif::Strip &strip = pObjThis->GetStrip();
	if (pObjBinaryThumbnail == nullptr) return Value::Nil;
	if (pObjImageThumbnail == nullptr) {
		AutoPtr<Object_image> pObjImage(new Object_image(env, new Image(Image::FORMAT_RGBA)));
		if (strip.validFlag) {
			if (!pObjImage->GetImage()->AllocBuffer(sig, strip.width, strip.height, 0x00)) {
				return Value::Nil;
			}
			const Binary &buff = pObjBinaryThumbnail->GetBinary();
			size_t bytesExpect = strip.width * strip.height * 3;
			if (buff.size() < bytesExpect) {
				return Value::Nil;
			}
			Binary::const_iterator p = buff.begin();
			std::unique_ptr<Image::Scanner> pScannerDst(
				pObjImage->GetImage()->CreateScanner(Image::SCAN_LeftTopHorz));
			do {
				unsigned char red = *p++;
				unsigned char green = *p++;
				unsigned char blue = *p++;
				pScannerDst->StorePixel(red, green, blue, 0);
			} while (pScannerDst->Next());
		} else {
			AutoPtr<Stream> pStream(
				new Pointer::StreamEx(
					env, new Object_binary::PointerEx(0, pObjBinaryThumbnail->Reference())));
			if (!ImageStreamer_JPEG::ReadStream(env, pObjImage->GetImage(), *pStream, false)) {
				return Value::Nil;
			}
		}
		pObjImageThumbnail = pObjImage.release();
		pObjThis->SetObjImageThumbnail(pObjImageThumbnail);
	}
	return Value(Object_image::Reference(pObjImageThumbnail));
}

// jpeg.exif#thumbnail@jpeg
Gura_DeclarePropertyAlias_R(exif, thumbnail_at_jpeg, "thumbnail@jpeg")
{
	SetPropAttr(VTYPE_binary, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(exif, thumbnail_at_jpeg)
{
	Object_exif *pObjThis = Object_exif::GetObject(valueThis);
	const Object_exif::Strip &strip = pObjThis->GetStrip();
	Object_binary *pObjBinaryThumbnail = pObjThis->GetObjBinaryThumbnail();
	if (pObjBinaryThumbnail == nullptr || strip.validFlag) return Value::Nil;
	return Value(Object_binary::Reference(pObjBinaryThumbnail));
}

//-----------------------------------------------------------------------------
// Gura interfaces for jpeg.exif
//-----------------------------------------------------------------------------
// jpeg.exif(stream?:stream):map:[raise] {block?}
Gura_DeclareFunction(exif)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(raise));
	SetClassToConstruct(Gura_UserClass(exif));
	AddHelp(
		Gura_Symbol(en),
		"Reads EXIF data from `stream` and creates a `jpeg.exif` instance.\n"
		"\n"
		"If no EXIF information exists in the stream, this function returns `nil`.\n"
		"If the attribute `:raise` is specified, an error occurs for that case.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("exif", "jpeg.exif"));
}

Gura_ImplementFunction(exif)
{
	Value value;
	if (arg.Is_stream(0)) {
		Object_exif *pObj = Object_exif::ReadStream(env, arg.GetStream(0));
		if (env.IsSignalled()) return Value::Nil;
		if (pObj != nullptr) {
			value = Value(pObj);
		} else if (arg.IsSet(Gura_Symbol(raise))) {
			env.SetError(ERR_FormatError, "Exif information doesn't exist");
			return Value::Nil;
		}
	} else {
		Object_exif *pObj = new Object_exif();
		value = Value(pObj);
	}
	return ReturnValue(env, arg, value);
}

// jpeg.exif#each() {block?}
Gura_DeclareMethod(exif, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that returns `jpeg.tag` values as elements\n"
		"that are stored in the property `jpeg.exif#ifd0`.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(exif, each)
{
	Object_exif *pThis = Object_exif::GetObjectThis(arg);
	Object_ifd *pObj0thIFD = pThis->GetObj0thIFD();
	return ReturnIterator(env, arg,
					new IteratorTag(Object_ifd::Reference(pObj0thIFD)));
}

// implementation of class exif
Gura_ImplementUserClass(exif)
{
	// Assignment of properties
	Gura_AssignProperty(exif, endian);
	Gura_AssignProperty(exif, ifd0);
	Gura_AssignProperty(exif, ifd1);
	Gura_AssignProperty(exif, thumbnail);
	Gura_AssignProperty(exif, thumbnail_at_jpeg);
	// Assignment of function
	Gura_AssignFunction(exif);
	// Assignment of method
	Gura_AssignMethod(exif, each);
}

Gura_EndModuleScope(jpeg)
