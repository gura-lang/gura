//-----------------------------------------------------------------------------
// Reference: http://www.exif.org/
//-----------------------------------------------------------------------------
#include "Module_jpeg.h"
#include "Object_exif.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Object_exif implementation
//-----------------------------------------------------------------------------
Object_exif::Object_exif() : Object(Gura_UserClass(exif))
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
	if (_pObj0thIFD.IsNull()) return Value::Null;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(ifd0))) {
		return Value(Object_ifd::Reference(_pObj0thIFD.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ifd1))) {
		if (_pObj1stIFD.IsNull()) return Value::Null;
		return Value(Object_ifd::Reference(_pObj1stIFD.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(thumbnail))) {
		return _valueThumbnail;
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
	if (!ReadBuff(sig, stream, buff, 12)) return false;
	size_t bytesAPP1 = 0;
	do {
		Header *pHeader = reinterpret_cast<Header *>(buff);
		if (XUnpackUShort(pHeader->SOI) != MARKER_SOI) {
			sig.SetError(ERR_FormatError, "invalid jpeg file");
			return false;
		}
		if (XUnpackUShort(pHeader->APP1) != MARKER_APP1) {
			sig.SetError(ERR_FormatError, "Exif information doesn't exist");
			return false;
		}
		bytesAPP1 = XUnpackUShort(pHeader->Size);
		if (bytesAPP1 < 8) {
			sig.SetError(ERR_FormatError, "Exif information doesn't exist");
			return false;
		}
		if (::memcmp(pHeader->ExifCode, "Exif\0\0", 6) != 0) {
			sig.SetError(ERR_FormatError, "Exif information doesn't exist");
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
		_pObj0thIFD.reset(ParseIFD_BE(env, sig, Symbol::Add("ifd0"),
										buff, bytesAPP1, offset, &offset));
		if (_pObj0thIFD.IsNull()) return false;
		if (offset != 0) {
			_pObj1stIFD.reset(ParseIFD_BE(env, sig, Symbol::Add("ifd1"),
										buff, bytesAPP1, offset, &offset));
			if (_pObj1stIFD.IsNull()) return false;
		}
	} else if (::memcmp(buff, "II", 2) == 0) {
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
			//GetConsole()->Dump(sig, buff + offsetThumbnail, bytesThumbnail);
			StreamMemReader streamThumbnail(sig, buff + offsetThumbnail, bytesThumbnail);
			AutoPtr<Object_image> pObjImage(new Object_image(env, Image::FORMAT_RGBA));
			if (!ImageStreamer_JPEG::ReadStream(sig, pObjImage.get(), streamThumbnail)) {
				return false;
			}
			_valueThumbnail = Value(pObjImage.release());
			//_valueThumbnail = Value(new Object_binary(env, buff + offsetThumbnail, bytesThumbnail, false));
		}
	}
	//_pObj0thIFD->GetTagOwner().Print();
	//if (!_pObj1stIFD.IsNull()) _pObj1stIFD->GetTagOwner().Print();
	//GetConsole()->Dump(sig, buff, bytesAPP1);
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
