//-----------------------------------------------------------------------------
// Gura bmp module
//-----------------------------------------------------------------------------
#include "Module_bmp.h"

Gura_BeginModule(bmp)

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing bmp module.
//-----------------------------------------------------------------------------
// image#bmpread(stream:stream:r):reduce
Gura_DeclareMethod(image, bmpread)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), SYN_markdown, "Reads an BMP image from a stream.");
}

Gura_ImplementMethod(image, bmpread)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_BMP::ReadStream(env, sig, pThis->GetImage(), args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// image#bmpwrite(stream:stream:w):reduce
Gura_DeclareMethod(image, bmpwrite)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(Gura_Symbol(en), SYN_markdown, "Writes a BMP image to a stream.");
}

Gura_ImplementMethod(image, bmpwrite)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_BMP::WriteStream(env, sig, pThis->GetImage(), args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: bmp
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	Gura_AssignMethodTo(VTYPE_image, image, bmpread);
	Gura_AssignMethodTo(VTYPE_image, image, bmpwrite);
	ImageStreamer::Register(new ImageStreamer_BMP());
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_BMP
//-----------------------------------------------------------------------------
bool ImageStreamer_BMP::IsResponsible(Signal sig, Stream &stream)
{
	if (stream.IsReadable()) {
		char buff[2];
		size_t bytesPeeked = stream.Peek(sig, buff, 2);
		if (sig.IsSignalled()) return false;
		return bytesPeeked == 2 && ::memcmp(buff, "BM", 2) == 0;
	}
	return stream.HasNameSuffix(".bmp");
}

bool ImageStreamer_BMP::Read(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return ImageStreamer_BMP::ReadStream(env, sig, pImage, stream);
}

bool ImageStreamer_BMP::Write(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return ImageStreamer_BMP::WriteStream(env, sig, pImage, stream);
}

bool ImageStreamer_BMP::ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckEmpty(sig)) return false;
	BitmapFileHeader bfh;
	if (stream.Read(sig, &bfh, BitmapFileHeader::Size) < BitmapFileHeader::Size) {
		SetError_InvalidBMPFormat(sig);
		return false;
	}
	if (Gura_UnpackUShort(bfh.bfType) != 0x4d42) {
		sig.SetError(ERR_FormatError, "Not a BMP file");
		return false;
	}
	ULong bfOffBits = Gura_UnpackULong(bfh.bfOffBits);
	BitmapInfoHeader bih;
	if (stream.Read(sig, &bih, BitmapInfoHeader::Size) < BitmapInfoHeader::Size) {
		sig.SetError(ERR_FormatError, "invalid DIB format");
		return false;
	}
	int biWidth = Gura_UnpackLong(bih.biWidth);
	int biHeight = Gura_UnpackLong(bih.biHeight);
	UShort biBitCount = Gura_UnpackUShort(bih.biBitCount);
	if (!pImage->ReadDIBPalette(env, sig, stream, biBitCount)) return false;
	if (bfOffBits != 0) {
		stream.Seek(sig, bfOffBits, Stream::SeekSet);
		if (sig.IsSignalled()) return false;
	}
	return pImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, false);
}

bool ImageStreamer_BMP::WriteStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckValid(sig)) return false;
	int biWidth = static_cast<int>(pImage->GetWidth());
	int biHeight = static_cast<int>(pImage->GetHeight());
	int biBitCount = pImage->CalcDIBBitCount();
	do {
		BitmapFileHeader bfh;
		::memset(&bfh, 0x00, BitmapFileHeader::Size);
		ULong bfOffBits = BitmapFileHeader::Size + BitmapInfoHeader::Size;
		bfOffBits += static_cast<ULong>(Image::CalcDIBPaletteSize(biBitCount));
		ULong bfSize = static_cast<ULong>(pImage->GetBufferSize() + bfOffBits);
		Gura_PackUShort(bfh.bfType,			0x4d42);
		Gura_PackULong(bfh.bfSize,			bfSize);
		Gura_PackULong(bfh.bfOffBits,		bfOffBits);
		if (stream.Write(sig, &bfh, BitmapFileHeader::Size) < BitmapFileHeader::Size) {
			sig.SetError(ERR_IOError, "failed to write bitmap data");
			return false;
		}
	} while (0);
	do {
		BitmapInfoHeader bih;
		::memset(&bih, 0x00, BitmapInfoHeader::Size);
		Gura_PackULong(bih.biSize,			BitmapInfoHeader::Size);
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
		if (stream.Write(sig, &bih, BitmapInfoHeader::Size) < BitmapInfoHeader::Size) {
			sig.SetError(ERR_IOError, "failed to write bitmap data");
			return false;
		}
	} while (0);
	if (!pImage->WriteDIBPalette(env, sig, stream, biBitCount)) return false;
	return pImage->WriteDIB(sig, stream, biBitCount, false);
}

void ImageStreamer_BMP::SetError_InvalidBMPFormat(Signal sig)
{
	sig.SetError(ERR_FormatError, "invalid BMP format");
}

Gura_EndModule(bmp, bmp)

Gura_RegisterModule(bmp)
