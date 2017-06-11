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
	return nullptr;
}

bool Object_content::Read(Environment &env,
									Stream &stream, Image::Format format)
{
	Signal &sig = env.GetSignal();
	int cntIcons = 0;
	do {
		IconDir iconDir;
		if (stream.Read(sig, &iconDir, IconDir::Size) < IconDir::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		cntIcons = Gura_UnpackUInt16(iconDir.idCount);
	} while (0);
	Int32List imageOffsets;
	for (int iIcon = 0; iIcon < cntIcons; iIcon++) {
		IconDirEntry iconDirEntry;
		if (stream.Read(sig, &iconDirEntry, IconDirEntry::Size) < IconDirEntry::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		long imageOffset = Gura_UnpackInt32(iconDirEntry.dwImageOffset);
		imageOffsets.push_back(imageOffset);
	}
	foreach (Int32List, pImageOffset, imageOffsets) {
		long imageOffset = *pImageOffset;
		if (!stream.Seek(sig, imageOffset, Stream::SeekSet)) return false;
		Image::BitmapInfoHeader bih;
		if (stream.Read(sig, &bih, Image::BitmapInfoHeader::Size) < Image::BitmapInfoHeader::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		int biWidth = Gura_UnpackInt32(bih.biWidth);
		int biHeight = Gura_UnpackInt32(bih.biHeight) / 2;
		UInt16 biBitCount = Gura_UnpackUInt16(bih.biBitCount);
		AutoPtr<Image> pImage(new Image(format));
		if (!pImage->ReadDIBPalette(env, stream, biBitCount)) return false;
		if (!pImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, true)) {
			return false;
		}
		_valList.push_back(Value(new Object_image(env, pImage.release())));
	}
	return true;
}

bool Object_content::Write(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	int cntIcons = static_cast<int>(_valList.size());
	do {
		IconDir iconDir;
		::memset(&iconDir, 0x00, sizeof(iconDir));
		Gura_PackUInt16(iconDir.idReserved,	0x0000);
		Gura_PackUInt16(iconDir.idType,		0x0001);
		Gura_PackUInt16(iconDir.idCount,	cntIcons);
		stream.Write(sig, &iconDir, IconDir::Size);
		if (sig.IsSignalled()) return false;
	} while (0);
	UInt32 dwImageOffset = IconDir::Size + IconDirEntry::Size * cntIcons;
	foreach (ValueList, pValue, _valList) {
		Image *pImage = Object_image::GetObject(*pValue)->GetImage();
		size_t width = pImage->GetWidth(), height = pImage->GetHeight();
		if (width > 256 || height > 256) {
			sig.SetError(ERR_FormatError, "image %dx%d is too big for icon format",
																width, height);
			return false;
		}
		int biBitCount = pImage->CalcDIBBitCount();
		UInt32 dwBytesInRes = static_cast<UInt32>(
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
		UInt16 wPlanes = (biBitCount >= 8)? 1 : 0;
		Gura_PackUInt16(iconDirEntry.wPlanes, wPlanes);
		UInt16 wBitCount = (biBitCount >= 8)? biBitCount : 0;
		Gura_PackUInt16(iconDirEntry.wBitCount, wBitCount);
		Gura_PackUInt32(iconDirEntry.dwBytesInRes, dwBytesInRes);
		Gura_PackUInt32(iconDirEntry.dwImageOffset, dwImageOffset);
		stream.Write(sig, &iconDirEntry, IconDirEntry::Size);
		if (sig.IsSignalled()) return false;
		dwImageOffset += dwBytesInRes;
	}
	foreach (ValueList, pValue, _valList) {
		Image *pImage = Object_image::GetObject(*pValue)->GetImage();
		size_t width = pImage->GetWidth(), height = pImage->GetHeight();
		int biBitCount = pImage->CalcDIBBitCount();
		int biCompression = 0;	// 0:RGB, 1:RLE8, 2:RLE4, 3:BITFIELDS, 4:JPEG, 5:PNG
		Image::BitmapInfoHeader bih;
		::memset(&bih, 0x00, sizeof(bih));
		Gura_PackUInt32(bih.biSize,			Image::BitmapInfoHeader::Size);
		Gura_PackInt32(bih.biWidth,			width);
		Gura_PackInt32(bih.biHeight,			height * 2);
		Gura_PackUInt16(bih.biPlanes,		1);
		Gura_PackUInt16(bih.biBitCount,		biBitCount);
		Gura_PackUInt32(bih.biCompression,	biCompression);
		Gura_PackUInt32(bih.biSizeImage,		0);	// just set to zero
		Gura_PackInt32(bih.biXPelsPerMeter,	0);	// just set to zero
		Gura_PackInt32(bih.biYPelsPerMeter,	0);	// just set to zero
		Gura_PackUInt32(bih.biClrUsed,		0);	// just set to zero
		Gura_PackUInt32(bih.biClrImportant,	0);	// just set to zero
		stream.Write(sig, &bih, Image::BitmapInfoHeader::Size);
		if (sig.IsSignalled()) return false;
		if (!pImage->WriteDIBPalette(env, stream, biBitCount)) return false;
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
			::sprintf(buff, "%lux%lu-%dbpp",
				pImage->GetWidth(), pImage->GetHeight(), pImage->CalcDIBBitCount());
			str += buff;
			followFlag = true;
		}
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// msico.content#images
Gura_DeclareProperty_R(content, images)
{
	SetPropAttr(VTYPE_image, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(content, images)
{
	Object_content *pObjThis = Object_content::GetObject(valueThis);
	return Value(new Object_list(env, pObjThis->GetValueList()));
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
		Gura_Symbol(en),
		"Writes an ICO image to a stream.");
}

Gura_ImplementMethod(content, write)
{
	Signal &sig = env.GetSignal();
	Object_content *pThis = Object_content::GetObjectThis(arg);
	Stream &stream = arg.GetStream(0);
	if (!pThis->Write(env, stream)) return Value::Nil;
	return arg.GetValueThis();
}

// msico.content#addimage(image:image):map:reduce
Gura_DeclareMethod(content, addimage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "image", VTYPE_image);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(content, addimage)
{
	Object_content *pThis = Object_content::GetObjectThis(arg);
	pThis->AddImage(arg.GetValue(0));
	return arg.GetValueThis();
}

// implementation of class msico
Gura_ImplementUserClass(content)
{
	// Assignment of properties
	Gura_AssignProperty(content, images);
	// Assignment of methods
	Gura_AssignMethod(content, write);
	Gura_AssignMethod(content, addimage);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing msico module.
//-----------------------------------------------------------------------------
// image#read@msico(stream:stream:r, idx:number => 0):reduce
Gura_DeclareMethodAlias(image, read_at_msico, "read@msico")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "idx", VTYPE_number, OCCUR_Once,
			   FLAG_None, 0, new Expr_Value(Value(0)));
	AddHelp(
		Gura_Symbol(en),
		"Reads an ICO image from a stream.");
}

Gura_ImplementMethod(image, read_at_msico)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetObjectThis(arg);
	if (!ImageStreamer_ICO::ReadStream(env, pThis->GetImage(),
					arg.GetStream(0), arg.GetInt(1))) return Value::Nil;
	return arg.GetValueThis();
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
			   FLAG_None, 0, new Expr_Value(Gura_Symbol(rgba)));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(content));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(content)
{
	Signal &sig = env.GetSignal();
	Object_content *pObj = new Object_content();
	if (arg.Is_stream(0)) {
		Stream &stream = arg.GetStream(0);
		Image::Format format = Image::SymbolToFormat(sig, arg.GetSymbol(1));
		if (sig.IsSignalled()) return Value::Nil;
		if (!pObj->Read(env, stream, format)) return Value::Nil;
	}
	Value result(pObj);
	return ReturnValue(env, arg, result);
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
	Gura_RealizeUserSymbol(images);
	// class realization
	Gura_RealizeAndPrepareUserClass(content, env.LookupClass(VTYPE_object));
	// method assignment to image class
	Gura_AssignMethodTo(VTYPE_image, image, read_at_msico);
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
bool ImageStreamer_ICO::IsResponsible(Signal &sig, Stream &stream)
{
	return stream.HasNameSuffix(".ico");
}

bool ImageStreamer_ICO::Read(Environment &env,
									Image *pImage, Stream &stream)
{
	Signal &sig = env.GetSignal();
	return ReadStream(env, pImage, stream, 0);
}

bool ImageStreamer_ICO::Write(Environment &env,
									Image *pImage, Stream &stream)
{
	Signal &sig = env.GetSignal();
	sig.SetError(ERR_SystemError, "not implemented yet");
	return false;
	//return pImage->WriteICO(sig, stream, false);
}

bool ImageStreamer_ICO::ReadStream(Environment &env,
						Image *pImage, Stream &stream, int idx)
{
	Signal &sig = env.GetSignal();
	int cntIcons = 0;
	do {
		IconDir iconDir;
		if (stream.Read(sig, &iconDir, IconDir::Size) < IconDir::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		cntIcons = Gura_UnpackUInt16(iconDir.idCount);
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
		dwImageOffset = Gura_UnpackInt32(iconDirEntry.dwImageOffset);
	} while (0);
	do {
		if (!stream.Seek(sig, dwImageOffset, Stream::SeekSet)) return false;
		Image::BitmapInfoHeader bih;
		if (stream.Read(sig, &bih, Image::BitmapInfoHeader::Size) < Image::BitmapInfoHeader::Size) {
			sig.SetError(ERR_FormatError, "invalid ICO format");
			return false;
		}
		int biWidth = Gura_UnpackInt32(bih.biWidth);
		int biHeight = Gura_UnpackInt32(bih.biHeight) / 2;
		UInt16 biBitCount = Gura_UnpackUInt16(bih.biBitCount);
		if (!pImage->ReadDIBPalette(env, stream, biBitCount)) return false;
		if (!pImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, true)) {
			return false;
		}
	} while (0);
	return true;
}

Gura_EndModuleBody(msico, msico)

Gura_RegisterModule(msico)
