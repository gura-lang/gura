//-----------------------------------------------------------------------------
// Gura jpeg module
//-----------------------------------------------------------------------------
#include "Module_jpeg.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing jpeg module.
//-----------------------------------------------------------------------------
// image#jpegread(stream:stream:r):reduce
Gura_DeclareMethod(image, jpegread)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	SetHelp("Reads a JPEG image from a stream.");
}

Gura_ImplementMethod(image, jpegread)
{
	Object_image *pSelf = Object_image::GetSelfObj(args);
	if (!ImageStreamer_JPEG::ReadStream(sig, pSelf, args.GetStream(0))) {
		return Value::Null;
	}
	return args.GetSelf();
}

// image#jpegwrite(stream:stream:w, quality:number => 75):reduce
Gura_DeclareMethod(image, jpegwrite)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_Once,
										FLAG_None, new Expr_Value(75));
	SetHelp("Writes a JPEG image to a stream.");
}

Gura_ImplementMethod(image, jpegwrite)
{
	Object_image *pSelf = Object_image::GetSelfObj(args);
	if (!ImageStreamer_JPEG::WriteStream(sig,
							pSelf, args.GetStream(0), args.GetInt(1))) {
		return Value::Null;
	}
	return args.GetSelf();
}

// jpeg.test()
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura module functions: jpeg
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
	// method assignment to image
	Gura_AssignMethodTo(VTYPE_image, image, jpegread);
	Gura_AssignMethodTo(VTYPE_image, image, jpegwrite);
	// image streamer registration
	ImageStreamer::Register(new ImageStreamer_JPEG());
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_JPEG
//-----------------------------------------------------------------------------
bool ImageStreamer_JPEG::IsResponsible(Signal sig, Stream &stream)
{
	if (stream.IsReadable()) {
		char buff[2];
		size_t bytesPeeked = stream.Peek(sig, buff, 2);
		if (sig.IsSignalled()) return false;
		// byte sequence "\xff\xd8" is SOI (Start of Image) marker in JPEG
		if (bytesPeeked == 2 && ::memcmp(buff, "\xff\xd8", 2) == 0) return true;
	}
	return stream.HasNameSuffix(".jpg") ||
				stream.HasNameSuffix(".jpeg") || stream.HasNameSuffix(".jpe");
}

bool ImageStreamer_JPEG::Read(Environment &env, Signal sig,
									Object_image *pObjImage, Stream &stream)
{
	return ReadStream(sig, pObjImage, stream);
}

bool ImageStreamer_JPEG::Write(Environment &env, Signal sig,
									Object_image *pObjImage, Stream &stream)
{
	return WriteStream(sig, pObjImage, stream, 75);
}

bool ImageStreamer_JPEG::ReadStream(Signal sig, Object_image *pObjImage, Stream &stream)
{
	if (!pObjImage->CheckEmpty(sig)) return false;
	ErrorMgr errMgr(sig);
	jpeg_decompress_struct cinfo;
	cinfo.err = ::jpeg_std_error(&errMgr.pub);
	errMgr.pub.error_exit = ErrorMgr::error_exit; // override error handler
	::jpeg_create_decompress(&cinfo);
	if (::setjmp(errMgr.jmpenv)) {
		::jpeg_destroy_decompress(&cinfo);
		return false;
	}
	SourceMgr::Setup(&cinfo, &sig, &stream);
	::jpeg_read_header(&cinfo, TRUE);
	::jpeg_start_decompress(&cinfo);
	if (!pObjImage->AllocBuffer(sig, cinfo.image_width, cinfo.image_height, 0xff)) {
		::jpeg_destroy_decompress(&cinfo);
		return false;
	}
	//::memset(pSelf->GetBuffer(), 0xff, pSelf->GetBufferSize());
	JSAMPARRAY scanlines = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo,
					JPOOL_IMAGE, cinfo.output_width * cinfo.output_components, 1);
	while (cinfo.output_scanline < cinfo.output_height) {
		::jpeg_read_scanlines(&cinfo, scanlines, 1);
		if (sig.IsSignalled()) {
			::jpeg_finish_decompress(&cinfo);
			::jpeg_destroy_decompress(&cinfo);
			return false;
		}
		const unsigned char *srcp = scanlines[0];
		unsigned char *dstp = pObjImage->GetPointer(0, cinfo.output_scanline - 1);
		for (unsigned int i = 0; i < cinfo.image_width; i++) {
			*(dstp + Image::OffsetRed) = *srcp++;
			*(dstp + Image::OffsetGreen) = *srcp++;
			*(dstp + Image::OffsetBlue) = *srcp++;
			dstp += pObjImage->GetBytesPerPixel();
		}
	}
	::jpeg_finish_decompress(&cinfo);
	::jpeg_destroy_decompress(&cinfo);
	return true;
}

bool ImageStreamer_JPEG::WriteStream(Signal sig,
						Object_image *pObjImage, Stream &stream, int quality)
{
	if (!pObjImage->CheckValid(sig)) return false;
	ErrorMgr errMgr(sig);
	jpeg_compress_struct cinfo;
	cinfo.err = ::jpeg_std_error(&errMgr.pub);
	errMgr.pub.error_exit = ErrorMgr::error_exit; // override error handler
	if (::setjmp(errMgr.jmpenv)) {
		::jpeg_destroy_compress(&cinfo);
		return false;
	}
	::jpeg_create_compress(&cinfo);
	DestinationMgr::Setup(&cinfo, &sig, &stream);
	cinfo.image_width		= static_cast<JDIMENSION>(pObjImage->GetWidth());
	cinfo.image_height		= static_cast<JDIMENSION>(pObjImage->GetHeight());
	cinfo.input_components	= 3;
	cinfo.in_color_space	= JCS_RGB;
	::jpeg_set_defaults(&cinfo);
	::jpeg_set_quality(&cinfo, quality, TRUE);
	::jpeg_start_compress(&cinfo, TRUE);
	JSAMPARRAY scanlines = (*cinfo.mem->alloc_sarray)((j_common_ptr)&cinfo,
					JPOOL_IMAGE, cinfo.image_width * cinfo.input_components, 1);
	while (cinfo.next_scanline < cinfo.image_height) {
		const unsigned char *srcp = pObjImage->GetPointer(0, cinfo.next_scanline);
		unsigned char *dstp = scanlines[0];
		for (unsigned int i = 0; i < cinfo.image_width; i++) {
			*dstp++ = *(srcp + Image::OffsetRed);
			*dstp++ = *(srcp + Image::OffsetGreen);
			*dstp++ = *(srcp + Image::OffsetBlue);
			srcp += pObjImage->GetBytesPerPixel();
		}
		::jpeg_write_scanlines(&cinfo, scanlines, 1);
	}
	::jpeg_finish_compress(&cinfo);
	::jpeg_destroy_compress(&cinfo);
	return true;
}

//-----------------------------------------------------------------------------
// ErrorMgr
//-----------------------------------------------------------------------------
void ErrorMgr::error_exit(j_common_ptr cinfo)
{
	ErrorMgr *pErrMgr = reinterpret_cast<ErrorMgr *>(cinfo->err);
	char buff[JMSG_LENGTH_MAX];
	(*cinfo->err->format_message)(cinfo, buff);
	pErrMgr->_sig.SetError(ERR_FormatError, "%s", buff);
	::longjmp(pErrMgr->jmpenv, 1);
}

//-----------------------------------------------------------------------------
// SourceMgr
//-----------------------------------------------------------------------------
void SourceMgr::Setup(j_decompress_ptr cinfo, Signal *pSig, Stream *pStream)
{
	if (cinfo->src == NULL) {
		cinfo->src = reinterpret_cast<jpeg_source_mgr *>((*cinfo->mem->alloc_small)(
			reinterpret_cast<j_common_ptr>(cinfo), JPOOL_PERMANENT, sizeof(SourceMgr)));
		SourceMgr *pSrcMgr = reinterpret_cast<SourceMgr *>(cinfo->src);
		pSrcMgr->buff = reinterpret_cast<JOCTET *>((*cinfo->mem->alloc_small)(
			reinterpret_cast<j_common_ptr>(cinfo), JPOOL_PERMANENT, BuffSize));
	}
	SourceMgr *pSrcMgr = reinterpret_cast<SourceMgr *>(cinfo->src);
	pSrcMgr->pub.init_source		= init_source;
	pSrcMgr->pub.fill_input_buffer	= fill_input_buffer;
	pSrcMgr->pub.skip_input_data	= skip_input_data;
	pSrcMgr->pub.resync_to_restart	= jpeg_resync_to_restart; // use default method
	pSrcMgr->pub.term_source		= term_source;
	pSrcMgr->pub.bytes_in_buffer	= 0;	// forces fill_input_buffer on first read
	pSrcMgr->pub.next_input_byte	= NULL;	// until buffer loaded
	pSrcMgr->pSig = pSig;
	pSrcMgr->pStream = pStream;
}

void SourceMgr::init_source(j_decompress_ptr cinfo)
{
	SourceMgr *pSrcMgr = reinterpret_cast<SourceMgr *>(cinfo->src);
	pSrcMgr->firstFlag = true;
}

boolean SourceMgr::fill_input_buffer(j_decompress_ptr cinfo)
{
	SourceMgr *pSrcMgr = reinterpret_cast<SourceMgr *>(cinfo->src);
	size_t nbytes = pSrcMgr->pStream->Read(*pSrcMgr->pSig, pSrcMgr->buff, BuffSize);
	
	if (nbytes == 0) {
		if (pSrcMgr->firstFlag) {
			ERREXIT(cinfo, JERR_INPUT_EMPTY);
		}
		WARNMS(cinfo, JWRN_JPEG_EOF);
		pSrcMgr->buff[0] = 0xff;
		pSrcMgr->buff[1] = JPEG_EOI;
		nbytes = 2;
	}
	pSrcMgr->pub.next_input_byte = pSrcMgr->buff;
	pSrcMgr->pub.bytes_in_buffer = nbytes;
	pSrcMgr->firstFlag = false;
	return TRUE;
}

void SourceMgr::skip_input_data(j_decompress_ptr cinfo, long num_bytes)
{
	jpeg_source_mgr *src = cinfo->src;
	if (num_bytes > 0) {
		while (num_bytes > static_cast<long>(src->bytes_in_buffer)) {
			num_bytes -= static_cast<long>(src->bytes_in_buffer);
			(*src->fill_input_buffer)(cinfo);
		}
		src->next_input_byte += num_bytes;
		src->bytes_in_buffer -= num_bytes;
	}
}

void SourceMgr::term_source(j_decompress_ptr cinfo)
{
}

//-----------------------------------------------------------------------------
// DestinationMgr
//-----------------------------------------------------------------------------
void DestinationMgr::Setup(j_compress_ptr cinfo, Signal *pSig, Stream *pStream)
{
	if (cinfo->dest == NULL) {
		cinfo->dest = reinterpret_cast<jpeg_destination_mgr *>((*cinfo->mem->alloc_small)(
			reinterpret_cast<j_common_ptr>(cinfo), JPOOL_PERMANENT, sizeof(DestinationMgr)));
	}
	DestinationMgr *pDstMgr = reinterpret_cast<DestinationMgr *>(cinfo->dest);
	pDstMgr->pub.init_destination		= init_destination;
	pDstMgr->pub.empty_output_buffer	= empty_output_buffer;
	pDstMgr->pub.term_destination		= term_destination;
	pDstMgr->pSig = pSig;
	pDstMgr->pStream = pStream;
}

void DestinationMgr::init_destination(j_compress_ptr cinfo)
{
	DestinationMgr *pDstMgr = reinterpret_cast<DestinationMgr *>(cinfo->dest);
	pDstMgr->buffer = reinterpret_cast<JOCTET *>((*cinfo->mem->alloc_small)(
		reinterpret_cast<j_common_ptr>(cinfo), JPOOL_IMAGE, BuffSize));
	pDstMgr->pub.next_output_byte = pDstMgr->buffer;
	pDstMgr->pub.free_in_buffer = BuffSize;
}

boolean DestinationMgr::empty_output_buffer(j_compress_ptr cinfo)
{
	DestinationMgr * pDstMgr = (DestinationMgr *) cinfo->dest;
	if (pDstMgr->pStream->Write(*pDstMgr->pSig, pDstMgr->buffer, BuffSize) != BuffSize) {
		ERREXIT(cinfo, JERR_FILE_WRITE);
	}
	pDstMgr->pub.next_output_byte = pDstMgr->buffer;
	pDstMgr->pub.free_in_buffer = BuffSize;
	return TRUE;
}

void DestinationMgr::term_destination(j_compress_ptr cinfo)
{
	DestinationMgr *pDstMgr = reinterpret_cast<DestinationMgr *>(cinfo->dest);
	size_t nbytes = BuffSize - pDstMgr->pub.free_in_buffer;
	if (nbytes > 0) {
		if (pDstMgr->pStream->Write(*pDstMgr->pSig, pDstMgr->buffer, nbytes) != nbytes) {
			ERREXIT(cinfo, JERR_FILE_WRITE);
		}
	}
	//pFile->Flush();
}

Gura_EndModule(jpeg, jpeg)

Gura_RegisterModule(jpeg)
