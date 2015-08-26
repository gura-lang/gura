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
Gura_DeclareMethodAlias(image, read_bmp, "read@bmp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads an BMP image from a stream.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, read_bmp)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_BMP::ReadStream(env, pThis->GetImage(), args.GetStream(0))) return Value::Nil;
	return args.GetValueThis();
}

// image#write@bmp(stream:stream:w):reduce
Gura_DeclareMethodAlias(image, write_bmp, "write@bmp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Writes a BMP image to a stream.\n"
		"\n"
		"This method returns the reference to the target instance itself.\n");
}

Gura_ImplementMethod(image, write_bmp)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_BMP::WriteStream(env, pThis->GetImage(), args.GetStream(0))) return Value::Nil;
	return args.GetValueThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: bmp
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	Gura_AssignMethodTo(VTYPE_image, image, read_bmp);
	Gura_AssignMethodTo(VTYPE_image, image, write_bmp);
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
	if (Gura_UnpackUShort(bfh.bfType) != 0x4d42) {
		sig.SetError(ERR_FormatError, "Not a BMP file");
		return false;
	}
	ULong bfOffBits = Gura_UnpackULong(bfh.bfOffBits);
	Image::BitmapInfoHeader bih;
	if (stream.Read(sig, &bih, Image::BitmapInfoHeader::Size) < Image::BitmapInfoHeader::Size) {
		sig.SetError(ERR_FormatError, "invalid DIB format");
		return false;
	}
	int biWidth = Gura_UnpackLong(bih.biWidth);
	int biHeight = Gura_UnpackLong(bih.biHeight);
	UShort biBitCount = Gura_UnpackUShort(bih.biBitCount);
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
		ULong bfOffBits = Image::BitmapFileHeader::Size + Image::BitmapInfoHeader::Size;
		bfOffBits += static_cast<ULong>(Image::CalcDIBPaletteSize(biBitCount));
		ULong bfSize = static_cast<ULong>(pImage->GetBufferSize() + bfOffBits);
		Gura_PackUShort(bfh.bfType,			0x4d42);
		Gura_PackULong(bfh.bfSize,			bfSize);
		Gura_PackULong(bfh.bfOffBits,		bfOffBits);
		if (stream.Write(sig, &bfh, Image::BitmapFileHeader::Size) < Image::BitmapFileHeader::Size) {
			sig.SetError(ERR_IOError, "failed to write bitmap data");
			return false;
		}
	} while (0);
	do {
		Image::BitmapInfoHeader bih;
		::memset(&bih, 0x00, Image::BitmapInfoHeader::Size);
		Gura_PackULong(bih.biSize,			Image::BitmapInfoHeader::Size);
		Gura_PackULong(bih.biWidth,			biWidth);
		Gura_PackULong(bih.biHeight,		biHeight);
		Gura_PackUShort(bih.biPlanes,		1);
		Gura_PackUShort(bih.biBitCount,		biBitCount);
		Gura_PackULong(bih.biCompression,	0);
		Gura_PackULong(bih.biSizeImage,		0);
		Gura_PackULong(bih.biXPelsPerMeter,	3780);
		Gura_PackULong(bih.biYPelsPerMeter,	3780);
		Gura_PackULong(bih.biClrUsed,		0);
		Gura_PackULong(bih.biClrImportant,	0);
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
