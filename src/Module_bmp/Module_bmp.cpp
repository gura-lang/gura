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
	SetHelp("Reads an BMP image from a stream.");
}

Gura_ImplementMethod(image, bmpread)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_BMP::ReadStream(sig, pThis, args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// image#bmpwrite(stream:stream:w):reduce
Gura_DeclareMethod(image, bmpwrite)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	SetHelp("Writes a BMP image to a stream.");
}

Gura_ImplementMethod(image, bmpwrite)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_BMP::WriteStream(sig, pThis, args.GetStream(0))) return Value::Null;
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
									Object_image *pObjImage, Stream &stream)
{
	return ImageStreamer_BMP::ReadStream(sig, pObjImage, stream);
}

bool ImageStreamer_BMP::Write(Environment &env, Signal sig,
									Object_image *pObjImage, Stream &stream)
{
	return ImageStreamer_BMP::WriteStream(sig, pObjImage, stream);
}

bool ImageStreamer_BMP::ReadStream(Signal sig, Object_image *pObjImage, Stream &stream)
{
	if (!pObjImage->CheckEmpty(sig)) return false;
	BitmapFileHeader bfh;
	if (stream.Read(sig, &bfh, BitmapFileHeader::Size) < BitmapFileHeader::Size) {
		SetError_InvalidBMPFormat(sig);
		return false;
	}
	if (XUnpackUShort(bfh.bfType) != 0x4d42) {
		sig.SetError(ERR_FormatError, "Not a BMP file");
		return false;
	}
	unsigned long bfOffBits = XUnpackULong(bfh.bfOffBits);
	BitmapInfoHeader bih;
	if (stream.Read(sig, &bih, BitmapInfoHeader::Size) < BitmapInfoHeader::Size) {
		sig.SetError(ERR_FormatError, "invalid DIB format");
		return false;
	}
	int biWidth = XUnpackLong(bih.biWidth);
	int biHeight = XUnpackLong(bih.biHeight);
	unsigned short biBitCount = XUnpackUShort(bih.biBitCount);
	if (!pObjImage->ReadDIBPalette(sig, stream, biBitCount)) return false;
	if (bfOffBits != 0) {
		stream.Seek(sig, bfOffBits, Stream::SeekSet);
		if (sig.IsSignalled()) return false;
	}
	return pObjImage->ReadDIB(sig, stream, biWidth, biHeight, biBitCount, false);
}

bool ImageStreamer_BMP::WriteStream(Signal sig, Object_image *pObjImage, Stream &stream)
{
	if (!pObjImage->CheckValid(sig)) return false;
	int biWidth = static_cast<int>(pObjImage->GetWidth());
	int biHeight = static_cast<int>(pObjImage->GetHeight());
	int biBitCount = pObjImage->CalcDIBBitCount();
	do {
		BitmapFileHeader bfh;
		::memset(&bfh, 0x00, BitmapFileHeader::Size);
		unsigned long bfOffBits = BitmapFileHeader::Size + BitmapInfoHeader::Size;
		bfOffBits += static_cast<unsigned long>(Object_image::CalcDIBPaletteSize(biBitCount));
		unsigned long bfSize = static_cast<unsigned long>(pObjImage->GetBufferSize() + bfOffBits);
		XPackUShort(bfh.bfType,			0x4d42);
		XPackULong(bfh.bfSize,			bfSize);
		XPackULong(bfh.bfOffBits,		bfOffBits);
		if (stream.Write(sig, &bfh, BitmapFileHeader::Size) < BitmapFileHeader::Size) {
			sig.SetError(ERR_IOError, "failed to write bitmap data");
			return false;
		}
	} while (0);
	do {
		BitmapInfoHeader bih;
		::memset(&bih, 0x00, BitmapInfoHeader::Size);
		XPackULong(bih.biSize,			BitmapInfoHeader::Size);
		XPackULong(bih.biWidth,			biWidth);
		XPackULong(bih.biHeight,		biHeight);
		XPackUShort(bih.biPlanes,		1);
		XPackUShort(bih.biBitCount,		biBitCount);
		XPackULong(bih.biCompression,	0);
		XPackULong(bih.biSizeImage,		0);
		XPackULong(bih.biXPelsPerMeter,	3780);
		XPackULong(bih.biYPelsPerMeter,	3780);
		XPackULong(bih.biClrUsed,		0);
		XPackULong(bih.biClrImportant,	0);
		if (stream.Write(sig, &bih, BitmapInfoHeader::Size) < BitmapInfoHeader::Size) {
			sig.SetError(ERR_IOError, "failed to write bitmap data");
			return false;
		}
	} while (0);
	if (!pObjImage->WriteDIBPalette(sig, stream, biBitCount)) return false;
	return pObjImage->WriteDIB(sig, stream, biBitCount, false);
}

void ImageStreamer_BMP::SetError_InvalidBMPFormat(Signal sig)
{
	sig.SetError(ERR_FormatError, "invalid BMP format");
}

Gura_EndModule(bmp, bmp)

Gura_RegisterModule(bmp)
