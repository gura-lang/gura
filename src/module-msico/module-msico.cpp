//-----------------------------------------------------------------------------
// Gura module: msico
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(msico)

//-----------------------------------------------------------------------------
// Object_content
//-----------------------------------------------------------------------------
Object_content::~Object_content()
{
}

Object *Object_content::Clone() const
{
	return NULL;
}

bool Object_content::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(images));
	return true;
}

Value Object_content::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(images))) {
		return Value(new Object_list(env, _valList));
	}
	evaluatedFlag = false;
	return Value::Null;
}

bool Object_content::Read(Environment &env, Signal sig,
									Stream &stream, Image::Format format)
{
	int cntIcons = 0;
	do {
		IconDir iconDir;
		if (stream.Read(sig, &iconDir, IconDir::Size) < IconDir::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		cntIcons = Gura_UnpackUShort(iconDir.idCount);
	} while (0);
	LongList imageOffsets;
	for (int iIcon = 0; iIcon < cntIcons; iIcon++) {
		IconDirEntry iconDirEntry;
		if (stream.Read(sig, &iconDirEntry, IconDirEntry::Size) < IconDirEntry::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		long imageOffset = Gura_UnpackLong(iconDirEntry.dwImageOffset);
		imageOffsets.push_back(imageOffset);
	}
	foreach (LongList, pImageOffset, imageOffsets) {
		long imageOffset = *pImageOffset;
		if (!stream.Seek(sig, imageOffset, Stream::SeekSet)) return false;
		Image::BitmapInfoHeader bih;
		if (stream.Read(sig, &bih, Image::BitmapInfoHeader::Size) < Image::BitmapInfoHeader::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		int biWidth = Gura_UnpackLong(bih.biWidth);
		int biHeight = Gura_UnpackLong(bih.biHeight) / 2;
		UShort biBitCount = Gura_UnpackUShort(bih.biBitCount);
		AutoPtr<Image> pImage(new Image(format));
		if (!pImage->ReadDIBPalette(env, sig, stream, biBitCount)) return false;
		if (!pImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, true)) {
			return false;
		}
		_valList.push_back(Value(new Object_image(env, pImage.release())));
	}
	return true;
}

bool Object_content::Write(Environment &env, Signal sig, Stream &stream)
{
	int cntIcons = static_cast<int>(_valList.size());
	do {
		IconDir iconDir;
		::memset(&iconDir, 0x00, sizeof(iconDir));
		Gura_PackUShort(iconDir.idReserved,	0x0000);
		Gura_PackUShort(iconDir.idType,		0x0001);
		Gura_PackUShort(iconDir.idCount,	cntIcons);
		stream.Write(sig, &iconDir, IconDir::Size);
		if (sig.IsSignalled()) return false;
	} while (0);
	ULong dwImageOffset = IconDir::Size + IconDirEntry::Size * cntIcons;
	foreach (ValueList, pValue, _valList) {
		Image *pImage = Object_image::GetObject(*pValue)->GetImage();
		size_t width = pImage->GetWidth(), height = pImage->GetHeight();
		if (width > 256 || height > 256) {
			sig.SetError(ERR_FormatError, "image %dx%d is too big for icon format",
																width, height);
			return false;
		}
		int biBitCount = pImage->CalcDIBBitCount();
		ULong dwBytesInRes = static_cast<ULong>(
						Image::BitmapInfoHeader::Size +
						Image::CalcDIBPaletteSize(biBitCount) +
						pImage->CalcDIBImageSize(biBitCount, true));
		IconDirEntry iconDirEntry;
		::memset(&iconDirEntry, 0x00, sizeof(iconDirEntry));
		iconDirEntry.bWidth = static_cast<UChar>(width & 0xff);
		iconDirEntry.bHeight = static_cast<UChar>(height & 0xff);
		iconDirEntry.bColorCount = (biBitCount < 8)?
						static_cast<UChar>(1 << biBitCount) : 0;
		iconDirEntry.bReserved = 0;
		UShort wPlanes = (biBitCount >= 8)? 1 : 0;
		Gura_PackUShort(iconDirEntry.wPlanes, wPlanes);
		UShort wBitCount = (biBitCount >= 8)? biBitCount : 0;
		Gura_PackUShort(iconDirEntry.wBitCount, wBitCount);
		Gura_PackULong(iconDirEntry.dwBytesInRes, dwBytesInRes);
		Gura_PackULong(iconDirEntry.dwImageOffset, dwImageOffset);
		stream.Write(sig, &iconDirEntry, IconDirEntry::Size);
		if (sig.IsSignalled()) return false;
		dwImageOffset += dwBytesInRes;
	}
	foreach (ValueList, pValue, _valList) {
		Image *pImage = Object_image::GetObject(*pValue)->GetImage();
		size_t width = pImage->GetWidth(), height = pImage->GetHeight();
		int biBitCount = pImage->CalcDIBBitCount();
		Image::BitmapInfoHeader bih;
		::memset(&bih, 0x00, sizeof(bih));
		Gura_PackULong(bih.biSize,			Image::BitmapInfoHeader::Size);
		Gura_PackLong(bih.biWidth,			width);
		Gura_PackLong(bih.biHeight,			height * 2);
		Gura_PackUShort(bih.biPlanes,		1);
		Gura_PackUShort(bih.biBitCount,		biBitCount);
		Gura_PackULong(bih.biCompression,	0);	// just set to zero
		Gura_PackULong(bih.biSizeImage,		0);	// just set to zero
		Gura_PackLong(bih.biXPelsPerMeter,	0);	// just set to zero
		Gura_PackLong(bih.biYPelsPerMeter,	0);	// just set to zero
		Gura_PackULong(bih.biClrUsed,		0);	// just set to zero
		Gura_PackULong(bih.biClrImportant,	0);	// just set to zero
		stream.Write(sig, &bih, Image::BitmapInfoHeader::Size);
		if (sig.IsSignalled()) return false;
		if (!pImage->WriteDIBPalette(env, sig, stream, biBitCount)) return false;
		if (!pImage->WriteDIB(sig, stream, biBitCount, true)) return false;
	}
	if (!stream.Flush(sig)) return false;
	return true;
}

void Object_content::AddImage(const Value &value)
{
	_valList.push_back(value);
}

String Object_content::ToString(bool exprFlag)
{
	String str;
	str = "<msico:";
	if (_valList.empty()) {
		str += "empty";
	} else {
		bool followFlag = false;
		foreach_const (ValueList, pValue, _valList) {
			if (!pValue->Is_image()) continue;
			Image *pImage = Object_image::GetObject(*pValue)->GetImage();
			char buff[64];
			if (followFlag) str += ",";
			::sprintf(buff, "%dx%d-%dbpp",
				pImage->GetWidth(), pImage->GetHeight(), pImage->CalcDIBBitCount());
			str += buff;
			followFlag = true;
		}
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_content
//-----------------------------------------------------------------------------
// msico.content#write(stream:stream:w):reduce
Gura_DeclareMethod(content, write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Writes an ICO image to a stream.");
}

Gura_ImplementMethod(content, write)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	Stream &stream = args.GetStream(0);
	if (!pThis->Write(env, sig, stream)) return Value::Null;
	return args.GetThis();
}

// msico.content#addimage(image:image):map:reduce
Gura_DeclareMethod(content, addimage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "image", VTYPE_image);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(content, addimage)
{
	Object_content *pThis = Object_content::GetThisObj(args);
	pThis->AddImage(args.GetValue(0));
	return args.GetThis();
}

// implementation of class msico
Gura_ImplementUserClass(content)
{
	Gura_AssignMethod(content, write);
	Gura_AssignMethod(content, addimage);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing msico module.
//-----------------------------------------------------------------------------
// image#msicoread(stream:stream:r, idx:number => 0):reduce
Gura_DeclareMethod(image, msicoread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once,
								FLAG_None, new Expr_Value(Value(0)));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads an ICO image from a stream.");
}

Gura_ImplementMethod(image, msicoread)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_ICO::ReadStream(env, sig, pThis->GetImage(),
					args.GetStream(0), args.GetInt(1))) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: msico
//-----------------------------------------------------------------------------
// msico.content(stream?:stream:r, format:symbol => `rgba) {block?}
Gura_DeclareFunction(content)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_Once,
							FLAG_None, new Expr_Value(Gura_Symbol(rgba)));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(content)
{
	Object_content *pObj = new Object_content();
	if (args.Is_stream(0)) {
		Stream &stream = args.GetStream(0);
		Image::Format format = Image::SymbolToFormat(sig, args.GetSymbol(1));
		if (sig.IsSignalled()) return Value::Null;
		if (!pObj->Read(env, sig, stream, format)) return Value::Null;
	}
	Value result(pObj);
	return ReturnValue(env, sig, args, result);
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(images);
	// class realization
	Gura_RealizeUserClass(content, env.LookupClass(VTYPE_object));
	// method assignment to image class
	Gura_AssignMethodTo(VTYPE_image, image, msicoread);
	// function assignment
	Gura_AssignFunction(content);
	// image streamer registration
	ImageStreamer::Register(new ImageStreamer_ICO());
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_ICO
//-----------------------------------------------------------------------------
bool ImageStreamer_ICO::IsResponsible(Signal sig, Stream &stream)
{
	return stream.HasNameSuffix(".ico");
}

bool ImageStreamer_ICO::Read(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return ReadStream(env, sig, pImage, stream, 0);
}

bool ImageStreamer_ICO::Write(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	sig.SetError(ERR_SystemError, "not implemented yet");
	return false;
	//return pImage->WriteICO(sig, stream, false);
}

bool ImageStreamer_ICO::ReadStream(Environment &env, Signal sig,
						Image *pImage, Stream &stream, int idx)
{
	int cntIcons = 0;
	do {
		IconDir iconDir;
		if (stream.Read(sig, &iconDir, IconDir::Size) < IconDir::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		cntIcons = Gura_UnpackUShort(iconDir.idCount);
	} while (0);
	if (idx >= cntIcons) {
		sig.SetError(ERR_FormatError, "index of icon is out of range");
		return false;
	}
	long dwImageOffset = 0;
	do {
		if (!stream.Seek(sig, idx * IconDirEntry::Size, Stream::SeekCur)) return false;
		IconDirEntry iconDirEntry;
		if (stream.Read(sig, &iconDirEntry, IconDirEntry::Size) < IconDirEntry::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		dwImageOffset = Gura_UnpackLong(iconDirEntry.dwImageOffset);
	} while (0);
	do {
		if (!stream.Seek(sig, dwImageOffset, Stream::SeekSet)) return false;
		Image::BitmapInfoHeader bih;
		if (stream.Read(sig, &bih, Image::BitmapInfoHeader::Size) < Image::BitmapInfoHeader::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		int biWidth = Gura_UnpackLong(bih.biWidth);
		int biHeight = Gura_UnpackLong(bih.biHeight) / 2;
		UShort biBitCount = Gura_UnpackUShort(bih.biBitCount);
		if (!pImage->ReadDIBPalette(env, sig, stream, biBitCount)) return false;
		if (!pImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, true)) {
			return false;
		}
	} while (0);
	return true;
}

Gura_EndModuleBody(msico, msico)

Gura_RegisterModule(msico)
