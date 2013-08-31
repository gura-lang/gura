//-----------------------------------------------------------------------------
// Gura tiff module
// http://www.libtiff.org/
// Following site is useful with many samples.
// http://www.ibm.com/developerworks/jp/linux/library/l-libtiff/
// http://www.ibm.com/developerworks/jp/linux/library/l-libtiff2/
//-----------------------------------------------------------------------------
#include "Module_tiff.h"

Gura_BeginModule(tiff)

//-----------------------------------------------------------------------------
// Handler
//-----------------------------------------------------------------------------
tsize_t Handler::TiffRead(thandle_t fd, tdata_t buf, tsize_t size)
{
	//::printf("TiffRead(%d)\n", size);
	Handler *pHandler = reinterpret_cast<Handler *>(fd);
	size = pHandler->Read(buf, size);
	return size;
}

toff_t Handler::TiffSeek(thandle_t fd, toff_t offset, int origin)
{
	//::printf("TiffSeek(%d, %d)\n", offset, origin);
	Handler *pHandler = reinterpret_cast<Handler *>(fd);
	Stream::SeekMode seekMode;
	if (origin == SEEK_SET) {
		seekMode = Stream::SeekSet;
	} else if (origin == SEEK_CUR) {
		seekMode = Stream::SeekCur;
	} else {
		return 0;
	}
	if (!pHandler->Seek(offset, seekMode)) {
	}
	return offset;
}

tsize_t Handler::TiffWrite(thandle_t fd, tdata_t buf, tsize_t size)
{
	Handler *pHandler = reinterpret_cast<Handler *>(fd);
	size = pHandler->Write(buf, size);
	return size;
}

int Handler::TiffClose(thandle_t fd)
{
	Handler *pHandler = reinterpret_cast<Handler *>(fd);
	pHandler->Flush();
	return 0;
}

toff_t Handler::TiffSize(thandle_t fd)
{
	Handler *pHandler = reinterpret_cast<Handler *>(fd);
	return pHandler->GetSize();
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing tiff module.
//-----------------------------------------------------------------------------
// image#tiffread(stream:stream:r):reduce
Gura_DeclareMethod(image, tiffread)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Reads a TIFF image from a stream.");
}

Gura_ImplementMethod(image, tiffread)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_TIFF::ReadStream(env, sig, pThis->GetImage(), args.GetStream(0))) {
		return Value::Null;
	}
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: tiff
//-----------------------------------------------------------------------------
// tiff.test(stream:stream:r)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementFunction(test)
{
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
	// method assignment to image
	Gura_AssignMethodTo(VTYPE_image, image, tiffread);
	//Gura_AssignMethodTo(VTYPE_image, image, tiffwrite);
	// image streamer registration
	ImageStreamer::Register(new ImageStreamer_TIFF());
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_TIFF
//-----------------------------------------------------------------------------
bool ImageStreamer_TIFF::IsResponsible(Signal sig, Stream &stream)
{
	if (stream.IsReadable()) {
	}
	return stream.HasNameSuffix(".tif") || stream.HasNameSuffix(".tiff");
}

bool ImageStreamer_TIFF::Read(Environment &env, Signal sig,
											Image *pImage, Stream &stream)
{
	return ReadStream(env, sig, pImage, stream);
}

bool ImageStreamer_TIFF::Write(Environment &env, Signal sig,
											Image *pImage, Stream &stream)
{
	return WriteStream(env, sig, pImage, stream);
}

bool ImageStreamer_TIFF::ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckEmpty(sig)) return false;
	Handler handler(sig, stream);
	TIFF *tiff = ::TIFFClientOpen("Gura", "rm",
		reinterpret_cast<thandle_t>(&handler),
		Handler::TiffRead, Handler::TiffWrite, Handler::TiffSeek,
		Handler::TiffClose, Handler::TiffSize, NULL, NULL);
	uint32 width, height;
	::TIFFGetField(tiff, TIFFTAG_IMAGEWIDTH, &width);
	::TIFFGetField(tiff, TIFFTAG_IMAGELENGTH, &height);
	if (!pImage->AllocBuffer(sig, width, height, 0xff)) {
		::TIFFClose(tiff);
		return false;
	}
	size_t bytesRaster = (width * height + 1) * sizeof(uint32);
	AutoPtr<Memory> pMemory(new MemoryHeap(bytesRaster));
	uint32 *raster = reinterpret_cast<uint32 *>(pMemory->GetPointer());
	if (!::TIFFReadRGBAImage(tiff, width, height, raster, 0)) {
		sig.SetError(ERR_FormatError, "invalid TIFF image");
		::TIFFClose(tiff);
		return false;
	}
	uint32 *pSrc = raster;
	std::auto_ptr<Image::Scanner>
			pScannerDst(pImage->CreateScanner(Image::SCAN_LeftBottomHorz));
	if (pImage->GetFormat() == Image::FORMAT_RGBA) {
		do {
			pScannerDst->StorePixel(
				static_cast<UChar>(*pSrc & 0xff),
				static_cast<UChar>((*pSrc >> 8) & 0xff),
				static_cast<UChar>((*pSrc >> 16) & 0xff),
				static_cast<UChar>((*pSrc >> 24) & 0xff));
			pSrc++;
		} while (pScannerDst->Next());
	} else {
		do {
			pScannerDst->StorePixel(
				static_cast<UChar>(*pSrc & 0xff),
				static_cast<UChar>((*pSrc >> 8) & 0xff),
				static_cast<UChar>((*pSrc >> 16) & 0xff));
			pSrc++;
		} while (pScannerDst->Next());
	}
	::TIFFClose(tiff);
	return true;
}

bool ImageStreamer_TIFF::WriteStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckValid(sig)) return false;
	return true;
}

Gura_EndModule(tiff, tiff)

Gura_RegisterModule(tiff)
