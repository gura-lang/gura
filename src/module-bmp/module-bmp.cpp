//-----------------------------------------------------------------------------
// Gura module: bmp
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(bmp)

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing bmp module.
//-----------------------------------------------------------------------------
// image#read@bmp(stream:stream:r):reduce
Gura_DeclareMethodAlias(image, read_at_bmp, "read@bmp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en),
		"Reads an BMP image from a stream.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, read_at_bmp)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetObjectThis(arg);
	if (!ImageStreamer_BMP::ReadStream(env, pThis->GetImage(), arg.GetStream(0))) return Value::Nil;
	return arg.GetValueThis();
}

// image#write@bmp(stream:stream:w):reduce
Gura_DeclareMethodAlias(image, write_at_bmp, "write@bmp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(
		Gura_Symbol(en),
		"Writes a BMP image to a stream.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, write_at_bmp)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetObjectThis(arg);
	if (!ImageStreamer_BMP::WriteStream(env, pThis->GetImage(), arg.GetStream(0))) return Value::Nil;
	return arg.GetValueThis();
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
	Gura_AssignMethodTo(VTYPE_image, image, read_at_bmp);
	Gura_AssignMethodTo(VTYPE_image, image, write_at_bmp);
	ImageStreamer::Register(new ImageStreamer_BMP());
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_BMP
//-----------------------------------------------------------------------------
bool ImageStreamer_BMP::IsResponsible(Signal &sig, Stream &stream)
{
	if (stream.IsReadable()) {
		char buff[2];
		size_t bytesPeeked = stream.Peek(sig, buff, 2);
		if (sig.IsSignalled()) return false;
		return bytesPeeked == 2 && ::memcmp(buff, "BM", 2) == 0;
	}
	return stream.HasNameSuffix(".bmp");
}

bool ImageStreamer_BMP::Read(Environment &env,
									Image *pImage, Stream &stream)
{
	Signal &sig = env.GetSignal();
	return ImageStreamer_BMP::ReadStream(env, pImage, stream);
}

bool ImageStreamer_BMP::Write(Environment &env,
									Image *pImage, Stream &stream)
{
	Signal &sig = env.GetSignal();
	return ImageStreamer_BMP::WriteStream(env, pImage, stream);
}

bool ImageStreamer_BMP::ReadStream(Environment &env, Image *pImage, Stream &stream)
{
	Signal &sig = env.GetSignal();
	if (!pImage->CheckEmpty(sig)) return false;
	Image::BitmapFileHeader bfh;
	if (stream.Read(sig, &bfh, Image::BitmapFileHeader::Size) < Image::BitmapFileHeader::Size) {
		SetError_InvalidBMPFormat(sig);
		return false;
	}
	if (Gura_UnpackUInt16(bfh.bfType) != 0x4d42) {
		sig.SetError(ERR_FormatError, "Not a BMP file");
		return false;
	}
	UInt32 bfOffBits = Gura_UnpackUInt32(bfh.bfOffBits);
	Image::BitmapInfoHeader bih;
	if (stream.Read(sig, &bih, Image::BitmapInfoHeader::Size) < Image::BitmapInfoHeader::Size) {
		sig.SetError(ERR_FormatError, "invalid DIB format");
		return false;
	}
	Int32 biWidth = Gura_UnpackInt32(bih.biWidth);
	Int32 biHeight = Gura_UnpackInt32(bih.biHeight);
	UInt16 biBitCount = Gura_UnpackUInt16(bih.biBitCount);
	if (!pImage->ReadDIBPalette(env, stream, biBitCount)) return false;
	if (bfOffBits != 0) {
		stream.Seek(sig, bfOffBits, Stream::SeekSet);
		if (sig.IsSignalled()) return false;
	}
	return pImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, false);
}

bool ImageStreamer_BMP::WriteStream(Environment &env, Image *pImage, Stream &stream)
{
	Signal &sig = env.GetSignal();
	if (!pImage->CheckValid(sig)) return false;
	int biWidth = static_cast<int>(pImage->GetWidth());
	int biHeight = static_cast<int>(pImage->GetHeight());
	int biBitCount = pImage->CalcDIBBitCount();
	do {
		Image::BitmapFileHeader bfh;
		::memset(&bfh, 0x00, Image::BitmapFileHeader::Size);
		UInt32 bfOffBits = Image::BitmapFileHeader::Size + Image::BitmapInfoHeader::Size;
		bfOffBits += static_cast<UInt32>(Image::CalcDIBPaletteSize(biBitCount));
		UInt32 bfSize = static_cast<UInt32>(pImage->GetBufferSize() + bfOffBits);
		Gura_PackUInt16(bfh.bfType,			0x4d42);
		Gura_PackUInt32(bfh.bfSize,			bfSize);
		Gura_PackUInt32(bfh.bfOffBits,		bfOffBits);
		if (stream.Write(sig, &bfh, Image::BitmapFileHeader::Size) < Image::BitmapFileHeader::Size) {
			sig.SetError(ERR_IOError, "failed to write bitmap data");
			return false;
		}
	} while (0);
	do {
		Image::BitmapInfoHeader bih;
		::memset(&bih, 0x00, Image::BitmapInfoHeader::Size);
		Gura_PackUInt32(bih.biSize,			Image::BitmapInfoHeader::Size);
		Gura_PackUInt32(bih.biWidth,			biWidth);
		Gura_PackUInt32(bih.biHeight,		biHeight);
		Gura_PackUInt16(bih.biPlanes,		1);
		Gura_PackUInt16(bih.biBitCount,		biBitCount);
		Gura_PackUInt32(bih.biCompression,	0);
		Gura_PackUInt32(bih.biSizeImage,		0);
		Gura_PackUInt32(bih.biXPelsPerMeter,	3780);
		Gura_PackUInt32(bih.biYPelsPerMeter,	3780);
		Gura_PackUInt32(bih.biClrUsed,		0);
		Gura_PackUInt32(bih.biClrImportant,	0);
		if (stream.Write(sig, &bih, Image::BitmapInfoHeader::Size) < Image::BitmapInfoHeader::Size) {
			sig.SetError(ERR_IOError, "failed to write bitmap data");
			return false;
		}
	} while (0);
	if (!pImage->WriteDIBPalette(env, stream, biBitCount)) return false;
	return pImage->WriteDIB(sig, stream, biBitCount, false);
}

void ImageStreamer_BMP::SetError_InvalidBMPFormat(Signal &sig)
{
	sig.SetError(ERR_FormatError, "invalid BMP format");
}

Gura_EndModuleBody(bmp, bmp)

Gura_RegisterModule(bmp)
