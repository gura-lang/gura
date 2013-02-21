//-----------------------------------------------------------------------------
// Gura msico module
//-----------------------------------------------------------------------------
#include "Module_msico.h"

Gura_BeginModule(msico)

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

bool Object_content::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(images));
	return true;
}

Value Object_content::DoGetProp(Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	Environment &env = *this;
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
		cntIcons = XUnpackUShort(iconDir.idCount);
	} while (0);
	LongList imageOffsets;
	for (int iIcon = 0; iIcon < cntIcons; iIcon++) {
		IconDirEntry iconDirEntry;
		if (stream.Read(sig, &iconDirEntry, IconDirEntry::Size) < IconDirEntry::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		long imageOffset = XUnpackLong(iconDirEntry.dwImageOffset);
		imageOffsets.push_back(imageOffset);
	}
	foreach (LongList, pImageOffset, imageOffsets) {
		long imageOffset = *pImageOffset;
		if (!stream.Seek(sig, imageOffset, Stream::SeekSet)) return false;
		BitmapInfoHeader bih;
		if (stream.Read(sig, &bih, BitmapInfoHeader::Size) < BitmapInfoHeader::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		int biWidth = XUnpackLong(bih.biWidth);
		int biHeight = XUnpackLong(bih.biHeight) / 2;
		unsigned short biBitCount = XUnpackUShort(bih.biBitCount);
		Object_image *pObjImage = new Object_image(env, format);
		if (!pObjImage->ReadDIBPalette(sig, stream, biBitCount)) return false;
		if (!pObjImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, true)) {
			return false;
		}
		_valList.push_back(Value(pObjImage));
	}
	return true;
}

bool Object_content::Write(Environment &env, Signal sig, Stream &stream)
{
	int cntIcons = static_cast<int>(_valList.size());
	do {
		IconDir iconDir;
		::memset(&iconDir, 0x00, sizeof(iconDir));
		XPackUShort(iconDir.idReserved,	0x0000);
		XPackUShort(iconDir.idType,		0x0001);
		XPackUShort(iconDir.idCount,	cntIcons);
		stream.Write(sig, &iconDir, IconDir::Size);
		if (sig.IsSignalled()) return false;
	} while (0);
	unsigned long dwImageOffset = IconDir::Size + IconDirEntry::Size * cntIcons;
	foreach (ValueList, pValue, _valList) {
		Object_image *pObjImage = pValue->GetImageObj();
		size_t width = pObjImage->GetWidth(), height = pObjImage->GetHeight();
		if (width > 256 || height > 256) {
			sig.SetError(ERR_FormatError, "image %dx%d is too big for icon format",
																width, height);
			return false;
		}
		int biBitCount = pObjImage->CalcDIBBitCount();
		unsigned long dwBytesInRes = static_cast<unsigned long>(
						BitmapInfoHeader::Size +
						Object_image::CalcDIBPaletteSize(biBitCount) +
						pObjImage->CalcDIBImageSize(biBitCount, true));
		IconDirEntry iconDirEntry;
		::memset(&iconDirEntry, 0x00, sizeof(iconDirEntry));
		iconDirEntry.bWidth = static_cast<unsigned char>(width & 0xff);
		iconDirEntry.bHeight = static_cast<unsigned char>(height & 0xff);
		iconDirEntry.bColorCount = (biBitCount < 8)?
						static_cast<unsigned char>(1 << biBitCount) : 0;
		iconDirEntry.bReserved = 0;
		unsigned short wPlanes = (biBitCount >= 8)? 1 : 0;
		XPackUShort(iconDirEntry.wPlanes, wPlanes);
		unsigned short wBitCount = (biBitCount >= 8)? biBitCount : 0;
		XPackUShort(iconDirEntry.wBitCount, wBitCount);
		XPackULong(iconDirEntry.dwBytesInRes, dwBytesInRes);
		XPackULong(iconDirEntry.dwImageOffset, dwImageOffset);
		stream.Write(sig, &iconDirEntry, IconDirEntry::Size);
		if (sig.IsSignalled()) return false;
		dwImageOffset += dwBytesInRes;
	}
	foreach (ValueList, pValue, _valList) {
		Object_image *pObjImage = pValue->GetImageObj();
		size_t width = pObjImage->GetWidth(), height = pObjImage->GetHeight();
		int biBitCount = pObjImage->CalcDIBBitCount();
		BitmapInfoHeader bih;
		::memset(&bih, 0x00, sizeof(bih));
		XPackULong(bih.biSize,			BitmapInfoHeader::Size);
		XPackLong(bih.biWidth,			width);
		XPackLong(bih.biHeight,			height * 2);
		XPackUShort(bih.biPlanes,		1);
		XPackUShort(bih.biBitCount,		biBitCount);
		XPackULong(bih.biCompression,	0);	// just set to zero
		XPackULong(bih.biSizeImage,		0);	// just set to zero
		XPackLong(bih.biXPelsPerMeter,	0);	// just set to zero
		XPackLong(bih.biYPelsPerMeter,	0);	// just set to zero
		XPackULong(bih.biClrUsed,		0);	// just set to zero
		XPackULong(bih.biClrImportant,	0);	// just set to zero
		stream.Write(sig, &bih, BitmapInfoHeader::Size);
		if (sig.IsSignalled()) return false;
		if (!pObjImage->WriteDIBPalette(sig, stream, biBitCount)) return false;
		if (!pObjImage->WriteDIB(sig, stream, biBitCount, true)) return false;
	}
	if (!stream.Flush(sig)) return false;
	return true;
}

void Object_content::AddImage(const Value &value)
{
	_valList.push_back(value);
}

String Object_content::ToString(Signal sig, bool exprFlag)
{
	String str;
	str = "<msico:";
	if (_valList.empty()) {
		str += "empty";
	} else {
		bool followFlag = false;
		foreach_const (ValueList, pValue, _valList) {
			if (!pValue->IsImage()) continue;
			Object_image *pObjImage = pValue->GetImageObj();
			char buff[64];
			if (followFlag) str += ",";
			::sprintf(buff, "%dx%d-%dbpp",
				pObjImage->GetWidth(), pObjImage->GetHeight(), pObjImage->CalcDIBBitCount());
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
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(Gura_Symbol(en), "Writes a ICO image to a stream.");
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
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "image", VTYPE_image);
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
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once,
								FLAG_None, new Expr_Value(Value(0)));
	AddHelp(Gura_Symbol(en), "Reads an ICO image from a stream.");
}

Gura_ImplementMethod(image, msicoread)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_ICO::ReadStream(sig, pThis,
					args.GetStream(0), args.GetInt(1))) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: msico
//-----------------------------------------------------------------------------
// msico.content(stream?:stream:r, format:symbol => `rgba) {block?}
Gura_DeclareFunction(content)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_Once,
						FLAG_None, new Expr_Symbol(Gura_Symbol(rgba)));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(content)
{
	Object_content *pObj = new Object_content();
	if (args.IsStream(0)) {
		Stream &stream = args.GetStream(0);
		Image::Format format = Object_image::SymbolToFormat(sig, args.GetSymbol(1));
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
									Object_image *pObjImage, Stream &stream)
{
	return ReadStream(sig, pObjImage, stream, 0);
}

bool ImageStreamer_ICO::Write(Environment &env, Signal sig,
									Object_image *pObjImage, Stream &stream)
{
	sig.SetError(ERR_SystemError, "not implemented yet");
	return false;
	//return pObjImage->WriteICO(sig, stream, false);
}

bool ImageStreamer_ICO::ReadStream(Signal sig,
						Object_image *pObjImage, Stream &stream, int idx)
{
	int cntIcons = 0;
	do {
		IconDir iconDir;
		if (stream.Read(sig, &iconDir, IconDir::Size) < IconDir::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		cntIcons = XUnpackUShort(iconDir.idCount);
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
		dwImageOffset = XUnpackLong(iconDirEntry.dwImageOffset);
	} while (0);
	do {
		if (!stream.Seek(sig, dwImageOffset, Stream::SeekSet)) return false;
		BitmapInfoHeader bih;
		if (stream.Read(sig, &bih, BitmapInfoHeader::Size) < BitmapInfoHeader::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		int biWidth = XUnpackLong(bih.biWidth);
		int biHeight = XUnpackLong(bih.biHeight) / 2;
		unsigned short biBitCount = XUnpackUShort(bih.biBitCount);
		if (!pObjImage->ReadDIBPalette(sig, stream, biBitCount)) return false;
		if (!pObjImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, true)) {
			return false;
		}
	} while (0);
	return true;
}

Gura_EndModule(msico, msico)

Gura_RegisterModule(msico)
