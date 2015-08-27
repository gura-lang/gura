//-----------------------------------------------------------------------------
// Gura module: ppm
// PPM specification:
// http://local.wasp.uwa.edu.au/~pbourke/dataformats/ppm/
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(ppm)

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing ppm module.
//-----------------------------------------------------------------------------
// image#read@ppm(stream:stream:r):reduce
Gura_DeclareMethodAlias(image, read_ppm, "read@ppm")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads a PPM/PGM image from a stream.");
}

Gura_ImplementMethod(image, read_ppm)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetObjectThis(args);
	if (!ImageStreamer_PPM::ReadStream(env, sig, pThis->GetImage(), args.GetStream(0))) return Value::Nil;
	return args.GetValueThis();
}

// image#write@ppm(stream:stream:w):reduce:[gray]
Gura_DeclareMethodAlias(image, write_ppm, "write@ppm")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareAttr(Gura_Symbol(gray));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Writes a PPM/PGM image to a stream.");
}

Gura_ImplementMethod(image, write_ppm)
{
	Signal &sig = env.GetSignal();
	Object_image *pThis = Object_image::GetObjectThis(args);
	if (!ImageStreamer_PPM::WriteStream(env, sig, pThis->GetImage(), args.GetStream(0), args.IsSet(Gura_Symbol(gray)))) {
		return Value::Nil;
	}
	return args.GetValueThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: ppm
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	Gura_AssignMethodTo(VTYPE_image, image, read_ppm);
	Gura_AssignMethodTo(VTYPE_image, image, write_ppm);
	ImageStreamer::Register(new ImageStreamer_PPM());
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_PPM
//-----------------------------------------------------------------------------
bool ImageStreamer_PPM::IsResponsible(Signal &sig, Stream &stream)
{
	if (stream.IsReadable()) {
		char buff[2];
		size_t bytesPeeked = stream.Peek(sig, buff, 2);
		if (sig.IsSignalled()) return false;
		return bytesPeeked == 2 && (::memcmp(buff, "P2", 2) == 0 ||
				::memcmp(buff, "P3", 2) == 0 || ::memcmp(buff, "P6", 2) == 0);
	}
	return stream.HasNameSuffix(".ppm") || stream.HasNameSuffix(".pbm");
}

bool ImageStreamer_PPM::Read(Environment &env,
									Image *pImage, Stream &stream)
{
	Signal &sig = env.GetSignal();
	return ReadStream(env, sig, pImage, stream);
}

bool ImageStreamer_PPM::Write(Environment &env,
									Image *pImage, Stream &stream)
{
	Signal &sig = env.GetSignal();
	return WriteStream(env, sig, pImage, stream, false);
}

bool ImageStreamer_PPM::ReadStream(Environment &env, Signal &sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckEmpty(sig)) return false;
	char format = '\0';
	size_t width = 0, height = 0, depth = 0;
	do {
		enum {
			STAT_Begin, STAT_Format, STAT_Width, STAT_Height, STAT_Depth,
			STAT_Success, STAT_SkipSpace, STAT_SeekEOL,
		} stat = STAT_Begin, statNext = STAT_Begin;
		bool eatNextFlag = true;
		bool successFlag = false;
		for (;;) {
			char ch;
			if (eatNextFlag && stream.Read(sig, &ch, 1) < 1) break;
			eatNextFlag = true;
			if (stat == STAT_Begin) {
				if (ch == 'P') {
					stat = STAT_Format;
				} else {
					break;
				}
			} else if (stat == STAT_Format) {
				if (ch == '2') {
					format = ch;
					statNext = STAT_Width;
					stat = STAT_SkipSpace;
				} else if (ch == '3') {
					format = ch;
					statNext = STAT_Width;
					stat = STAT_SkipSpace;
				} else if (ch == '6') {
					format = ch;
					statNext = STAT_Width;
					stat = STAT_SkipSpace;
				} else {
					break;
				}
			} else if (stat == STAT_Width) {
				if (IsDigit(ch)) {
					width = width * 10 + (ch - '0');
				} else if (IsSpace(ch)) {
					statNext = STAT_Height;
					stat = STAT_SkipSpace;
				} else {
					break;
				}
			} else if (stat == STAT_Height) {
				if (IsDigit(ch)) {
					height = height * 10 + (ch - '0');
				} else if (IsSpace(ch)) {
					statNext = STAT_Depth;
					stat = STAT_SkipSpace;
				} else {
					break;
				}
			} else if (stat == STAT_Depth) {
				if (IsDigit(ch)) {
					depth = depth * 10 + (ch - '0');
				} else if (IsSpace(ch)) {
					eatNextFlag = false;
					stat = STAT_Success;
				} else {
					break;
				}
			} else if (stat == STAT_Success) {
				if (ch == '\n') {
					successFlag = true;
					break;
				} else if (IsSpace(ch)) {
					// nothing to do
				} else {
					break;
				}
			} else if (stat == STAT_SkipSpace) {
				if (IsSpace(ch)) {
					// nothing to do
				} else if (ch == '#') {
					stat = STAT_SeekEOL;
				} else {
					eatNextFlag = false;
					stat = statNext;
				}
			} else if (stat == STAT_SeekEOL) {
				if (ch == '\n') {
					stat = STAT_SkipSpace;
				} else {
					// nothing to do
				}
			}
		}
		if (!successFlag || width == 0 || height == 0 || depth == 0) {
			SetError_InvalidPPMFormat(sig);
			return false;
		}
	} while (0);
	if (!pImage->AllocBuffer(sig, width, height, 0xff)) return false;
	if (format == '2') {
		sig.SetError(ERR_FormatError, "unsupported PPM format");
		return false;
	} else if (format == '3') {
		size_t iLine = 0, iPixel = 0;
		size_t bytesPitch = pImage->GetBytesPerLine();
		UChar *pLine = pImage->GetPointer(0);
		UChar *pPixel = pLine;
		ULong red = 0, green = 0, blue = 0;
		enum {
			STAT_SkipSpace, STAT_Red, STAT_Green, STAT_Blue,
		} stat = STAT_SkipSpace, statNext = STAT_Red;
		bool eatNextFlag = true;
		bool successFlag = false;
		for (;;) {
			char ch;
			if (eatNextFlag && stream.Read(sig, &ch, 1) < 1) break;
			eatNextFlag = true;
			if (stat == STAT_SkipSpace) {
				if (IsSpace(ch)) {
					// nothing to do
				} else {
					eatNextFlag = false;
					stat = statNext;
				}
			} else if (stat == STAT_Red) {
				if (IsDigit(ch)) {
					red = red * 10 + (ch - '0');
				} else if (IsSpace(ch)) {
					statNext = STAT_Green;
					stat = STAT_SkipSpace;
				} else {
					break;
				}
			} else if (stat == STAT_Green) {
				if (IsDigit(ch)) {
					green = green * 10 + (ch - '0');
				} else if (IsSpace(ch)) {
					statNext = STAT_Blue;
					stat = STAT_SkipSpace;
				} else {
					break;
				}
			} else if (stat == STAT_Blue) {
				if (IsDigit(ch)) {
					blue = blue * 10 + (ch - '0');
				} else if (IsSpace(ch)) {
					if (depth != 255) {
						red = red * 255 / depth;
						green = green * 255 / depth;
						blue = blue * 255 / depth;
					}
					Image::StorePixel(pPixel,
						 static_cast<UChar>(red),
						 static_cast<UChar>(green),
						 static_cast<UChar>(blue));
					pPixel += pImage->GetBytesPerPixel();
					iPixel++;
					if (iPixel >= width) {
						if (++iLine >= height) {
							successFlag = true;
							break;
						}
						iPixel = 0, pLine += bytesPitch, pPixel = pLine;
					}
					red = green = blue = 0;
					statNext = STAT_Red;
					stat = STAT_SkipSpace;
				} else {
					successFlag = false;
					break;
				}
			}
		}
		if (!successFlag) {
			sig.SetError(ERR_FormatError, "invalid format of PPM file");
			return false;
		}
	} else if (format == '6') {
		UChar buff[3];
		size_t iLine = 0, iPixel = 0;
		size_t bytesPitch = pImage->GetBytesPerLine();
		UChar *pLine = pImage->GetPointer(0);
		UChar *pPixel = pLine;
		while (stream.Read(sig, buff, 3) == 3) {
			if (iPixel >= width) {
				if (++iLine >= height) break;
				iPixel = 0, pLine += bytesPitch, pPixel = pLine;
			}
			Image::StorePixel(pPixel, buff[0], buff[1], buff[2]);
			pPixel += pImage->GetBytesPerPixel();
			iPixel++;
		}
		if (sig.IsSignalled()) return false;
	}
	return true;
}

bool ImageStreamer_PPM::WriteStream(Environment &env, Signal &sig, Image *pImage, Stream &stream, bool grayFlag)
{
	if (!pImage->CheckValid(sig)) return false;
	char buff[64];
	size_t width = pImage->GetWidth(), height = pImage->GetHeight();
	::sprintf(buff, "P%d %d %d 255\n", grayFlag? 2 : 6, width, height);
	stream.Write(sig, buff, ::strlen(buff));
	size_t iLine = 0, iPixel = 0;
	UChar *pLine = pImage->GetPointer(0);
	UChar *pPixel = pLine;
	size_t bytesPitch = pImage->GetBytesPerLine();
	if (grayFlag) {
		for (;;) {
			if (iPixel >= width) {
				if (++iLine >= height) break;
				iPixel = 0, pLine += bytesPitch, pPixel = pLine;
			}
			buff[0] = Image::GetPixelGray(pPixel);
			if (stream.Write(sig, buff, 1) < 1) {
				sig.SetError(ERR_IOError, "failed to write bitmap data");
				return false;
			}
			pPixel += pImage->GetBytesPerPixel();
			iPixel++;
		}
	} else {
		for (;;) {
			if (iPixel >= width) {
				if (++iLine >= height) break;
				iPixel = 0, pLine += bytesPitch, pPixel = pLine;
			}
			buff[0] = Image::GetPixelR(pPixel);
			buff[1] = Image::GetPixelG(pPixel);
			buff[2] = Image::GetPixelB(pPixel);
			if (stream.Write(sig, buff, 3) < 3) {
				sig.SetError(ERR_IOError, "failed to write bitmap data");
				return false;
			}
			pPixel += pImage->GetBytesPerPixel();
			iPixel++;
		}
	}
	return true;
}

void ImageStreamer_PPM::SetError_InvalidPPMFormat(Signal &sig)
{
	sig.SetError(ERR_FormatError, "invalid PPM format");
}


Gura_EndModuleBody(ppm, ppm)

Gura_RegisterModule(ppm)
