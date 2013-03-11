//-----------------------------------------------------------------------------
// Reference: http://www.exif.org/
//-----------------------------------------------------------------------------
#include "Module_jpeg.h"
#include "Object_exif.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Object_exif implementation
//-----------------------------------------------------------------------------
Object_exif::Object_exif() : Object(Gura_UserClass(exif)), _bigendianFlag(false)
{
}

Object_exif::~Object_exif()
{
}

Object *Object_exif::Clone() const
{
	return NULL;
}

Value Object_exif::IndexGet(Environment &env, Signal sig, const Value &valueIdx)
{
	if (_pObj0thIFD.IsNull()) return Value::Null;
	return _pObj0thIFD->IndexGet(env, sig, valueIdx);
}

bool Object_exif::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	if (_pObj0thIFD.IsNull()) return true;
	symbols.insert(Gura_UserSymbol(ifd0));
	symbols.insert(Gura_UserSymbol(ifd1));
	symbols.insert(Gura_UserSymbol(thumbnail));
	return _pObj0thIFD->DoDirProp(sig, symbols);
}

Value Object_exif::DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Environment &env = *this;
	if (_pObj0thIFD.IsNull()) return Value::Null;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(endian))) {
		return Value(_bigendianFlag? Gura_UserSymbol(big) : Gura_UserSymbol(little));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ifd0))) {
		return Value(Object_ifd::Reference(_pObj0thIFD.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ifd1))) {
		if (_pObj1stIFD.IsNull()) return Value::Null;
		return Value(Object_ifd::Reference(_pObj1stIFD.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(thumbnail))) {
		if (_pObjBinaryThumbnail.IsNull()) return Value::Null;
		if (_pObjImageThumbnail.IsNull()) {
			Stream_Binary stream(sig,
					Object_binary::Reference(_pObjBinaryThumbnail.get()), false);
			AutoPtr<Object_image> pObjImage(new Object_image(env, Image::FORMAT_RGBA));
			if (!ImageStreamer_JPEG::ReadStream(sig, pObjImage.get(), stream)) {
				return Value::Null;
			}
			_pObjImageThumbnail.reset(pObjImage.release());
		}
		return Value(Object_image::Reference(_pObjImageThumbnail.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(thumbnail_jpeg))) {
		if (_pObjBinaryThumbnail.IsNull()) return Value::Null;
		return Value(Object_binary::Reference(_pObjBinaryThumbnail.get()));
	}
	return _pObj0thIFD->DoGetProp(sig, pSymbol, attrs, evaluatedFlag);
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
	SHORT_BE *pShort = reinterpret_cast<SHORT_BE *>(buff);
	if (!ReadBuff(sig, stream, pShort, UNITSIZE_SHORT)) return false;
	if (XUnpackUShort(pShort->num) != MARKER_SOI) {
		sig.SetError(ERR_FormatError, "invalid jpeg file");
		return false;
	}
	size_t bytesAPP1 = 0;
	for (;;) {
		if (!ReadBuff(sig, stream, pShort, UNITSIZE_SHORT)) return false;
		unsigned short marker = XUnpackUShort(pShort->num);
		if (marker < MARKER_APP0 || MARKER_APP15 < marker) {
			sig.SetError(ERR_FormatError, "Exif information doesn't exist");
			return false;
		}
		if (!ReadBuff(sig, stream, pShort, UNITSIZE_SHORT)) return false;
		unsigned short bytes = XUnpackUShort(pShort->num);
		if (bytes < UNITSIZE_SHORT) {
			sig.SetError(ERR_FormatError, "invalid jpeg file");
			return false;
		}
		if (marker == MARKER_APP1) {
			char code[6];
			if (!ReadBuff(sig, stream, code, 6)) return false;
			if (::memcmp(code, "Exif\0\0", 6) != 0) {
				sig.SetError(ERR_FormatError, "Exif information doesn't exist");
				return false;
			}
			bytesAPP1 = bytes;
			break;
		}
		if (!stream.Seek(sig, bytes - 2, Stream::SeekCur)) return false;
	}
	if (!ReadBuff(sig, stream, buff, bytesAPP1)) return false;
	if (::memcmp(buff, "MM", 2) == 0) {
		_bigendianFlag = true;
		TIFF_BE *pTIFF = reinterpret_cast<TIFF_BE *>(buff + 2);
		if (XUnpackUShort(pTIFF->Code) != 0x002a) {
			SetError_InvalidFormat(sig);
			return false;
		}
		size_t offset = XUnpackULong(pTIFF->Offset0thIFD);
		_pObj0thIFD.reset(ParseIFD_BE(env, sig, Symbol::Add("ifd0"),
										buff, bytesAPP1, offset, &offset));
		if (_pObj0thIFD.IsNull()) return false;
		if (offset != 0) {
			_pObj1stIFD.reset(ParseIFD_BE(env, sig, Symbol::Add("ifd1"),
										buff, bytesAPP1, offset, &offset));
			if (_pObj1stIFD.IsNull()) return false;
		}
	} else if (::memcmp(buff, "II", 2) == 0) {
		_bigendianFlag = false;
		TIFF_LE *pTIFF = reinterpret_cast<TIFF_LE *>(buff + 2);
		if (XUnpackUShort(pTIFF->Code) != 0x002a) {
			SetError_InvalidFormat(sig);
			return false;
		}
		size_t offset = XUnpackULong(pTIFF->Offset0thIFD);
		_pObj0thIFD.reset(ParseIFD_LE(env, sig, Symbol::Add("ifd0"),
										buff, bytesAPP1, offset, &offset));
		if (_pObj0thIFD.IsNull()) return false;
		if (offset != 0) {
			_pObj1stIFD.reset(ParseIFD_LE(env, sig, Symbol::Add("ifd1"),
										buff, bytesAPP1, offset, &offset));
			if (_pObj1stIFD.IsNull()) return false;
		}
	} else {
		SetError_InvalidFormat(sig);
		return false;
	}
	if (!_pObj1stIFD.IsNull()) {
		Object_Tag *pObjTag_JPEGInterchangeFormat =
			_pObj1stIFD->GetTagOwner().FindById(TAG_JPEGInterchangeFormat);
		Object_Tag *pObjTag_JPEGInterchangeFormatLength =
			 _pObj1stIFD->GetTagOwner().FindById(TAG_JPEGInterchangeFormatLength);
		if (pObjTag_JPEGInterchangeFormat == NULL ||
						pObjTag_JPEGInterchangeFormatLength == NULL) {
			// nothing to do
		} else if (pObjTag_JPEGInterchangeFormat->GetType() != TYPE_LONG ||
						pObjTag_JPEGInterchangeFormatLength->GetType() != TYPE_LONG) {
			// nothing to do
		} else {
			size_t offsetThumbnail = pObjTag_JPEGInterchangeFormat->GetValue().GetULong();
			size_t bytesThumbnail = pObjTag_JPEGInterchangeFormatLength->GetValue().GetULong();
			if (offsetThumbnail + bytesThumbnail >= bytesAPP1 - 1) {
				SetError_InvalidFormat(sig);
				return false;
			}
			_pObjBinaryThumbnail.reset(new Object_binary(env,
								buff + offsetThumbnail, bytesThumbnail, false));
		}
	}
	return true;
}

//-----------------------------------------------------------------------------
// Gura interfaces for exif
//-----------------------------------------------------------------------------
// cairo.exif#each() {block?}
Gura_DeclareMethod(exif, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(exif, each)
{
	Object_exif *pThis = Object_exif::GetThisObj(args);
	Object_ifd *pObj0thIFD = pThis->GetObj0thIFD();
	return ReturnIterator(env, sig, args,
					new IteratorTag(Object_ifd::Reference(pObj0thIFD)));
}

// implementation of class exif
Gura_ImplementUserClass(exif)
{
	Gura_AssignMethod(exif, each);
}

}}
