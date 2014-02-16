//-----------------------------------------------------------------------------
// Gura module: png
//-----------------------------------------------------------------------------
#include "stdafx.h"

#define SetRGBOrder(png_ptr) ::png_set_bgr(png_ptr)

Gura_BeginModuleBody(png)

//-----------------------------------------------------------------------------
// Gura interfaces for image
// These methods are available after importing png module.
//-----------------------------------------------------------------------------
// image#pngread(stream:stream:r):reduce
Gura_DeclareMethod(image, pngread)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Reads a PNG image from a stream.");
}

Gura_ImplementMethod(image, pngread)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_PNG::ReadStream(env, sig, pThis->GetImage(), args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// image#pngwrite(stream:stream:w):reduce
Gura_DeclareMethod(image, pngwrite)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, "Writes a PNG image to a stream.");
}

Gura_ImplementMethod(image, pngwrite)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_PNG::WriteStream(env, sig, pThis->GetImage(), args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: png
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	Gura_AssignMethodTo(VTYPE_image, image, pngread);
	Gura_AssignMethodTo(VTYPE_image, image, pngwrite);
	ImageStreamer::Register(new ImageStreamer_PNG());
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_PNG
//-----------------------------------------------------------------------------
bool ImageStreamer_PNG::IsResponsible(Signal sig, Stream &stream)
{
	if (stream.IsReadable()) {
		char buff[8];
		size_t bytesPeeked = stream.Peek(sig, buff, 8);
		if (sig.IsSignalled()) return false;
		if (bytesPeeked == 8 &&
			::memcmp(buff, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0) return true;
	}
	return stream.HasNameSuffix(".png");
}

bool ImageStreamer_PNG::Read(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return ReadStream(env, sig, pImage, stream);
}

bool ImageStreamer_PNG::Write(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return WriteStream(env, sig, pImage, stream);
}

bool ImageStreamer_PNG::ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckEmpty(sig)) return false;
	Handler handler(sig, stream);
	png_structp png_ptr = ::png_create_read_struct(
			PNG_LIBPNG_VER_STRING, &handler, Handler::Error, Handler::Warning);
	png_infop info_ptr = ::png_create_info_struct(png_ptr);
	png_infop end_info = ::png_create_info_struct(png_ptr);
	if (::setjmp(png_jmpbuf(png_ptr))) {
		::png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
		return false;
	}
	::png_set_read_fn(png_ptr, &handler, Handler::ReadData);
	::png_read_info(png_ptr, info_ptr);
	png_uint_32 width, height;
	int bit_depth, color_type, interlace_type;
	::png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth,
							&color_type, &interlace_type, NULL, NULL);
	if (bit_depth == 16 ) {
		::png_set_strip_16(png_ptr); // 16-bit RGB is converted into 8-bit.
	}
	if (color_type == PNG_COLOR_TYPE_GRAY) {
		::png_set_expand(png_ptr);
		::png_set_add_alpha(png_ptr, 0x00, PNG_FILLER_AFTER);
		if (pImage->GetFormat() == Image::FORMAT_RGBA) {
			::png_set_add_alpha(png_ptr, 0x00, PNG_FILLER_AFTER);
		}
	} else if (color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
		::png_set_gray_to_rgb(png_ptr);
		if (pImage->GetFormat() == Image::FORMAT_RGB) {
			::png_set_strip_alpha(png_ptr);
		}
	} else if (color_type == PNG_COLOR_TYPE_PALETTE) {
		::png_set_palette_to_rgb(png_ptr);
		SetRGBOrder(png_ptr);
		if (pImage->GetFormat() != Image::FORMAT_RGBA) {
			::png_set_strip_alpha(png_ptr);
		} else if (::png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) {
			::png_set_tRNS_to_alpha(png_ptr);
		} else {
			::png_set_add_alpha(png_ptr, 0xff, PNG_FILLER_AFTER);
		}
	} else if (color_type == PNG_COLOR_TYPE_RGB) {
		SetRGBOrder(png_ptr);
		if (pImage->GetFormat() == Image::FORMAT_RGBA) {
			::png_set_add_alpha(png_ptr, 0xff, PNG_FILLER_AFTER);
		}
	} else if (color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
		SetRGBOrder(png_ptr);
		if (pImage->GetFormat() == Image::FORMAT_RGB) {
			::png_set_strip_alpha(png_ptr);
		}
	}
	if (::png_get_valid(png_ptr, info_ptr, PNG_INFO_PLTE)) {
		png_color *palette;
		int num_palette;
		::png_get_PLTE(png_ptr, info_ptr, &palette, &num_palette);
		if (num_palette > 0) {
			AutoPtr<Palette> pPalette(pImage->CreateEmptyPalette(env, num_palette));
			for (int i = 0; i < num_palette; i++, palette++) {
				pPalette->SetEntry(i, palette->red, palette->green, palette->blue);
			}
		}
	}
	::png_set_packing(png_ptr);
	::png_read_update_info(png_ptr, info_ptr);
	::png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth,
							&color_type, &interlace_type, NULL, NULL);
	if (!pImage->AllocBuffer(sig, width, height, 0xff)) {
		::png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
		return false;
	}
	png_bytep *row_pointers = new png_bytep [height];
	for (size_t y = 0; y < static_cast<size_t>(height); y++) {
		row_pointers[y] = reinterpret_cast<png_bytep>(pImage->GetPointer(y));
	}
	::png_read_image(png_ptr, row_pointers);
	::png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
	delete [] row_pointers;
	if (sig.IsSignalled()) return false;
	return true;
}

bool ImageStreamer_PNG::WriteStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckValid(sig)) return false;
	Handler handler(sig, stream);
	png_structp png_ptr = ::png_create_write_struct(
			PNG_LIBPNG_VER_STRING, &handler, Handler::Error, Handler::Warning);
	png_infop info_ptr = ::png_create_info_struct(png_ptr);
	if (::setjmp(png_jmpbuf(png_ptr))) {
		::png_destroy_write_struct(&png_ptr, &info_ptr);
		return false;
	}
	::png_set_write_fn(png_ptr, &handler, Handler::WriteData, Handler::FlushData);
	png_uint_32 width = static_cast<png_uint_32>(pImage->GetWidth());
	png_uint_32 height = static_cast<png_uint_32>(pImage->GetHeight());
	int bit_depth = 8;
	int color_type = 
		(pImage->GetFormat() == Image::FORMAT_RGB)? PNG_COLOR_TYPE_RGB :
		(pImage->GetFormat() == Image::FORMAT_RGBA)? PNG_COLOR_TYPE_RGB_ALPHA :
		PNG_COLOR_TYPE_RGB;
	int interlace_type = PNG_INTERLACE_NONE;
	int compression_type = PNG_COMPRESSION_TYPE_DEFAULT;
	int filter_method = PNG_FILTER_TYPE_DEFAULT;
	::png_set_IHDR(png_ptr, info_ptr, width, height, bit_depth,
				color_type, interlace_type, compression_type, filter_method);
	SetRGBOrder(png_ptr);
	::png_write_info(png_ptr, info_ptr);
	png_bytep *row_pointers = new png_bytep [height];
	for (size_t y = 0; y < static_cast<size_t>(height); y++) {
		row_pointers[y] = reinterpret_cast<png_bytep>(pImage->GetPointer(y));
	}
	::png_write_image(png_ptr, row_pointers);
	::png_write_end(png_ptr, info_ptr);
	::png_destroy_write_struct(&png_ptr, &info_ptr);
	delete [] row_pointers;
	return true;
}

//-----------------------------------------------------------------------------
// Handler
//-----------------------------------------------------------------------------
void Handler::Error(png_structp png_ptr, png_const_charp error_msg)
{
	Handler *pHandler = reinterpret_cast<Handler *>(::png_get_error_ptr(png_ptr));
	Signal &sig = pHandler->GetSignal();
	sig.SetError(ERR_FormatError, "%s",
							reinterpret_cast<const char *>(error_msg));
	::longjmp(png_jmpbuf(png_ptr), 1);
}

void Handler::Warning(png_structp png_ptr, png_const_charp warning_msg)
{
	// just ignore it
}

void Handler::ReadData(png_structp png_ptr, png_bytep data, png_size_t length)
{
	Handler *pHandler = reinterpret_cast<Handler *>(::png_get_io_ptr(png_ptr));
	Signal &sig = pHandler->GetSignal();
	Stream &stream = pHandler->GetStream();
	stream.Read(sig, data, length);
	if (sig.IsSignalled()) {
		::png_error(png_ptr, "read data error");
	}
}

void Handler::WriteData(png_structp png_ptr, png_bytep data, png_size_t length)
{
	Handler *pHandler = reinterpret_cast<Handler *>(::png_get_io_ptr(png_ptr));
	Signal &sig = pHandler->GetSignal();
	Stream &stream = pHandler->GetStream();
	stream.Write(sig, data, length);
	if (sig.IsSignalled()) {
		::png_error(png_ptr, "write data error");
	}
}

void Handler::FlushData(png_structp png_ptr)
{
	Handler *pHandler = reinterpret_cast<Handler *>(::png_get_io_ptr(png_ptr));
	Signal &sig = pHandler->GetSignal();
	Stream &stream = pHandler->GetStream();
	stream.Flush(sig);
	if (sig.IsSignalled()) {
		::png_error(png_ptr, "flush data error");
	}
}

Gura_EndModuleBody(png, png)

Gura_RegisterModule(png)
