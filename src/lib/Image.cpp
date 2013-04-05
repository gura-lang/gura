// Image

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Image
//-----------------------------------------------------------------------------
bool Image::CheckEmpty(Signal sig) const
{
	if (!IsValid()) return true;
	sig.SetError(ERR_ValueError, "image has already been initialized with a buffer");
	return false;
}

bool Image::CheckValid(Signal sig) const
{
	if (IsValid()) return true;
	sig.SetError(ERR_ValueError, "image does not have a buffer");
	return false;
}

size_t Image::SymbolToPixelOffset(Signal sig, const Symbol *pSymbol) const
{
	if (pSymbol->IsIdentical(Gura_Symbol(red))) {
		return Image::OffsetRed;
	} else if (pSymbol->IsIdentical(Gura_Symbol(green))) {
		return Image::OffsetGreen;
	} else if (pSymbol->IsIdentical(Gura_Symbol(blue))) {
		return Image::OffsetBlue;
	} else if (pSymbol->IsIdentical(Gura_Symbol(alpha))) {
		if (GetFormat() != Image::FORMAT_RGBA) {
			sig.SetError(ERR_FormatError, "only RGBA format contains alpha element");
			return 0;
		}
		return Image::OffsetAlpha;
	}
	sig.SetError(ERR_FormatError, "unsupported image element: %s", pSymbol->GetName());
	return 0;
}

Image::Format Image::SymbolToFormat(Signal sig, const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_Symbol(rgb))) {
		return Image::FORMAT_RGB;
	} else if (pSymbol->IsIdentical(Gura_Symbol(rgba))) {
		return Image::FORMAT_RGBA;
	} else {
		sig.SetError(ERR_FormatError, "specify `rgb or `rgba for image format");
		return Image::FORMAT_None;
	}
}

const Symbol *Image::FormatToSymbol(Image::Format format)
{
	if (format == Image::FORMAT_RGB) {
		return Gura_Symbol(rgb);
	} else if (format == Image::FORMAT_RGBA) {
		return Gura_Symbol(rgba);
	} else {
		return Gura_Symbol(nil);
	}
}

void Image::InitMetrics()
{
	_metrics.bitsPerPixel =
			(_format == Image::FORMAT_RGB)? 24 :
			(_format == Image::FORMAT_RGBA)? 32 : 0;
	_metrics.bytesPerPixel = _metrics.bitsPerPixel / 8;
	_metrics.bytesPerLine =
			(_format == Image::FORMAT_RGB)? ((_width * 3 + 3) / 4) * 4 :
			(_format == Image::FORMAT_RGBA)? _width * 4 : 0;
}

Image *Image::CreateDerivation(Signal sig,
						size_t width, size_t height, Object_palette *pObjPalette)
{
	Image *pImage = new Image(_format);
	if (!pImage->AllocBuffer(sig, width, height, 0x00)) {
		delete pImage;
		return NULL;
	}
	if (pObjPalette != NULL) {
		pImage->_pObjPalette.reset(pObjPalette);
	} else if (!_pObjPalette.IsNull()) {
		pImage->_pObjPalette.reset(Object_palette::Reference(_pObjPalette.get()));
	}
	return pImage;
}

bool Image::CheckCoord(Signal sig, size_t x, size_t y) const
{
	if (CheckCoord(static_cast<int>(x), static_cast<int>(y))) return true;
	sig.SetError(ERR_ValueError, "coordinate is out of range");
	return false;
}

bool Image::AdjustCoord(int &x, int &y, int &width, int &height) const
{
	int wdImage = static_cast<int>(GetWidth());
	int htImage = static_cast<int>(GetHeight());
	if (x >= wdImage) return false;
	if (y >= htImage) return false;
	if (x + width <= 0) return false;
	if (y + height <= 0) return false;
	if (x < 0) {
		width += x, x = 0;
	}
	if (y < 0) {
		height += y, y = 0;
	}
	if (x + width > wdImage) {
		width = wdImage - x;
	}
	if (y + height > htImage) {
		height = htImage - y;
	}
	return true;
}

void Image::PutPixel(unsigned char *buff, const Color &color)
{
	if (_format == Image::FORMAT_RGB) {
		*(buff + Image::OffsetRed)		= color.GetRed();
		*(buff + Image::OffsetGreen)	= color.GetGreen();
		*(buff + Image::OffsetBlue)		= color.GetBlue();
	} else if (_format == Image::FORMAT_RGBA) {
		*(buff + Image::OffsetRed)		= color.GetRed();
		*(buff + Image::OffsetGreen)	= color.GetGreen();
		*(buff + Image::OffsetBlue)		= color.GetBlue();
		*(buff + Image::OffsetAlpha)	= color.GetAlpha();
	}
}

void Image::GetPixel(const unsigned char *buff, Color &color)
{
	if (_format == Image::FORMAT_RGB) {
		color = Color(GetPixelR(buff), GetPixelG(buff), GetPixelB(buff), 255);
	} else if (_format == Image::FORMAT_RGBA) {
		color = Color(GetPixelR(buff), GetPixelG(buff), GetPixelB(buff), GetPixelA(buff));
	}
}

bool Image::Store(Signal sig, size_t x, size_t y, size_t width, size_t height,
					const Symbol *pSymbol, const Object_matrix *pObjMat)
{
	if (pObjMat->GetRows() < height || pObjMat->GetCols() < width) {
		sig.SetError(ERR_ValueError, "matrix size is too small");
		return false;
	}
	size_t bytesPerLine = GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	unsigned char *pLine = GetPointer(x, y);
	size_t offPixel = SymbolToPixelOffset(sig, pSymbol);
	if (sig.IsSignalled()) return false;
	for (size_t iLine = 0; iLine < height; iLine++, pLine += bytesPerLine) {
		unsigned char *pPixel = pLine + offPixel;
		ValueList::const_iterator pValueElem = pObjMat->GetPointer(iLine, 0);
		for (size_t iPixel = 0; iPixel < width;
							iPixel++, pPixel += bytesPerPixel, pValueElem++) {
			*pPixel = pValueElem->GetUChar();
		}
	}
	return true;
}

bool Image::Store(Environment &env, Signal sig, size_t x, size_t y, size_t width, size_t height,
					const Symbol *pSymbol, Iterator *pIterator)
{
	size_t bytesPerLine = GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	unsigned char *pLine = GetPointer(x, y);
	size_t offPixel = SymbolToPixelOffset(sig, pSymbol);
	if (sig.IsSignalled()) return false;
	for (size_t iLine = 0; iLine < height; iLine++, pLine += bytesPerLine) {
		unsigned char *pPixel = pLine + offPixel;
		for (size_t iPixel = 0; iPixel < width; iPixel++, pPixel += bytesPerPixel) {
			Value value;
			if (!pIterator->Next(env, sig, value)) return false;
			*pPixel = value.GetUChar();
		}
	}
	return true;
}

bool Image::Extract(Signal sig, size_t x, size_t y, size_t width, size_t height,
					const Symbol *pSymbol, Object_matrix *pObjMat)
{
	if (pObjMat->GetRows() < height || pObjMat->GetCols() < width) {
		sig.SetError(ERR_ValueError, "matrix size is too small");
		return false;
	}
	size_t bytesPerLine = GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	const unsigned char *pLine = GetPointer(x, y);
	size_t offPixel = SymbolToPixelOffset(sig, pSymbol);
	if (sig.IsSignalled()) return false;
	for (size_t iLine = 0; iLine < height; iLine++, pLine += bytesPerLine) {
		const unsigned char *pPixel = pLine + offPixel;
		ValueList::iterator pValueElem = pObjMat->GetPointer(iLine, 0);
		for (size_t iPixel = 0; iPixel < width;
							iPixel++, pPixel += bytesPerPixel, pValueElem++) {
			*pValueElem = Value(*pPixel);
		}
	}
	return true;
}

bool Image::Extract(Signal sig, size_t x, size_t y, size_t width, size_t height,
					const Symbol *pSymbol, Object_list *pObjList)
{
	if (pObjList->GetList().size() < height * width) {
		sig.SetError(ERR_ValueError, "list size is too small");
		return false;
	}
	size_t bytesPerLine = GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	const unsigned char *pLine = GetPointer(x, y);
	size_t offPixel = SymbolToPixelOffset(sig, pSymbol);
	if (sig.IsSignalled()) return false;
	ValueList::iterator pValueElem = pObjList->GetList().begin();
	for (size_t iLine = 0; iLine < height; iLine++, pLine += bytesPerLine) {
		const unsigned char *pPixel = pLine + offPixel;
		for (size_t iPixel = 0; iPixel < width;
							iPixel++, pPixel += bytesPerPixel, pValueElem++) {
			*pValueElem = Value(*pPixel);
		}
	}
	return true;
}

void Image::ReplaceColorRect(size_t x, size_t y, size_t width, size_t height,
				const Color &colorOrg, const Color &color)
{
	std::auto_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	unsigned char buffOrg[8], buff[8];
	PutPixel(buffOrg, colorOrg);
	PutPixel(buff, color);
	if (_format == Image::FORMAT_RGBA) {
		do {
			unsigned char *pPixel = pScanner->GetPointer();
			if (::memcmp(pPixel, buffOrg, 3) == 0) {
				StorePixelRGB(pScanner->GetPointer(), buff);
				//StorePixelRGBA(pScanner->GetPointer(), buff);
			}
		} while (pScanner->Next());
	} else {
		do {
			unsigned char *pPixel = pScanner->GetPointer();
			if (::memcmp(pPixel, buffOrg, 3) == 0) {
				StorePixelRGB(pScanner->GetPointer(), buff);
			}
		} while (pScanner->Next());
	}
}

void Image::FillRect(size_t x, size_t y, size_t width, size_t height,
												const Color &color)
{
	unsigned char buff[8];
	PutPixel(buff, color);
	std::auto_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	if (_format == Image::FORMAT_RGBA) {
		do {
			StorePixelRGBA(pScanner->GetPointer(), buff);
		} while (pScanner->Next());
	} else {
		do {
			StorePixelRGB(pScanner->GetPointer(), buff);
		} while (pScanner->Next());
	}
}

void Image::FillRectAlpha(size_t x, size_t y,
					size_t width, size_t height, unsigned char alpha)
{
	std::auto_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	do {
		unsigned char *pPixel = pScanner->GetPointer();
		*(pPixel + Image::OffsetAlpha) = alpha;
	} while (pScanner->Next());
}

void Image::FillRectAlpha(size_t x, size_t y,
		size_t width, size_t height, unsigned char alpha, const Color &color)
{
	std::auto_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	unsigned char buff[8];
	PutPixel(buff, color);
	do {
		unsigned char *pPixel = pScanner->GetPointer();
		if (::memcmp(pPixel, buff, 3) == 0) {
			*(pPixel + Image::OffsetAlpha) = alpha;
		}
	} while (pScanner->Next());
}

Image *Image::ReduceColor(Signal sig, const Object_palette *pObjPalette)
{
	Image *pImage = CreateDerivation(sig, _width, _height,
										Object_palette::Reference(pObjPalette));
	if (sig.IsSignalled()) return NULL;
	std::auto_ptr<Scanner> pScannerSrc(CreateScanner());
	std::auto_ptr<Scanner> pScannerDst(pImage->CreateScanner());
	if (_format == Image::FORMAT_RGBA) {
		do {
			size_t idx = pObjPalette->LookupNearest(pScannerSrc->GetPointer());
			StorePixelRGBA(pScannerDst->GetPointer(),
						pObjPalette->GetEntry(idx), pScannerSrc->GetAlpha());
		} while (pScannerSrc->Next(*pScannerDst));
	} else {
		do {
			size_t idx = pObjPalette->LookupNearest(pScannerSrc->GetPointer());
			StorePixelRGB(pScannerDst->GetPointer(), pObjPalette->GetEntry(idx));
		} while (pScannerSrc->Next(*pScannerDst));
	}
	return pImage;
}

Image *Image::GrayScale(Signal sig)
{
	Image *pImage = CreateDerivation(sig, _width, _height);
	if (sig.IsSignalled()) return NULL;
	std::auto_ptr<Scanner> pScannerSrc(CreateScanner());
	std::auto_ptr<Scanner> pScannerDst(pImage->CreateScanner());
	if (_format == Image::FORMAT_RGBA) {
		do {
			unsigned char gray = GetPixelGray(pScannerSrc->GetPointer());
			pScannerDst->StorePixel(gray, gray, gray, pScannerSrc->GetAlpha());
		} while (pScannerSrc->Next(*pScannerDst));
	} else {
		do {
			unsigned char gray = GetPixelGray(pScannerSrc->GetPointer());
			pScannerDst->StorePixel(gray, gray, gray);
		} while (pScannerSrc->Next(*pScannerDst));
	}
	return pImage;
}

Image *Image::Blur(Signal sig, int radius)
{
	//int kernel[17];
	
	return NULL;
}

Image *Image::Flip(Signal sig, bool horzFlag, bool vertFlag)
{
	Image *pImage = CreateDerivation(sig, _width, _height);
	if (sig.IsSignalled()) return NULL;
	if (horzFlag) {
		std::auto_ptr<Scanner> pScannerSrc(CreateScanner());
		std::auto_ptr<Scanner> pScannerDst(pImage->CreateScanner(
				vertFlag? Image::SCAN_RightBottomHorz : Image::SCAN_RightTopHorz));
		if (_format == Image::FORMAT_RGBA) {
			do {
				StorePixelRGBA(pScannerDst->GetPointer(), pScannerSrc->GetPointer());
			} while (pScannerSrc->Next(*pScannerDst));
		} else {
			do {
				StorePixelRGB(pScannerDst->GetPointer(), pScannerSrc->GetPointer());
			} while (pScannerSrc->Next(*pScannerDst));
		}
	} else if (vertFlag) {
		const unsigned char *pLineSrc = GetPointer(0);
		unsigned char *pLineDst = pImage->GetPointer(_height);
		size_t bytesPerLine = GetBytesPerLine();
		for (size_t y = 0; y < _height; y++) {
			pLineDst -= bytesPerLine;
			::memcpy(pLineDst, pLineSrc, bytesPerLine);
			pLineSrc += bytesPerLine;
		}
	}
	return pImage;
}

Image *Image::Rotate90(Signal sig, bool clockwiseFlag)
{
	size_t width = _height, height = _width;
	Image *pImage = CreateDerivation(sig, width, height);
	if (sig.IsSignalled()) return NULL;
	std::auto_ptr<Scanner> pScannerSrc(CreateScanner());
	std::auto_ptr<Scanner> pScannerDst(pImage->CreateScanner(
			clockwiseFlag? Image::SCAN_RightTopVert : Image::SCAN_LeftBottomVert));
	if (_format == Image::FORMAT_RGBA) {
		do {
			StorePixelRGBA(pScannerDst->GetPointer(), pScannerSrc->GetPointer());
		} while (pScannerSrc->Next(*pScannerDst));
	} else {
		do {
			StorePixelRGB(pScannerDst->GetPointer(), pScannerSrc->GetPointer());
		} while (pScannerSrc->Next(*pScannerDst));
	}
	return pImage;
}

Image *Image::Rotate(Signal sig, double angle, const Color &color)
{
	int angleInt = static_cast<int>(angle);
	if (static_cast<double>(angleInt) != angle) {
		// nothing to do
	} else if (angleInt == 180) {
		return Flip(sig, true, true);
	} else if ((angleInt + 270) % 360 == 0) {
		return Rotate90(sig, true);
	} else if ((angleInt + 90) % 360 == 0) {
		return Rotate90(sig, false);
	}
	double rad = angle * 3.14159265358979323846 / 180;
	int cos1024 = static_cast<int>(::cos(rad) * 1024);
	int sin1024 = -static_cast<int>(::sin(rad) * 1024);
	int width, height;
	int xCenter = static_cast<int>(_width / 2);
	int yCenter = static_cast<int>(_height / 2);
	int xCenterNew, yCenterNew;
	do {
		int left = -xCenter;
		int right = left + static_cast<int>(_width);
		int bottom = -yCenter;
		int top = bottom + static_cast<int>(_height);
		int xs[4], ys[4];
		RotateCoord(xs[0], ys[0], left, top, cos1024, sin1024);
		RotateCoord(xs[1], ys[1], left, bottom, cos1024, sin1024);
		RotateCoord(xs[2], ys[2], right, top, cos1024, sin1024);
		RotateCoord(xs[3], ys[3], right, bottom, cos1024, sin1024);
		int xMin = *std::min_element(xs, xs + 4);
		int xMax = *std::max_element(xs, xs + 4);
		int yMin = *std::min_element(ys, ys + 4);
		int yMax = *std::max_element(ys, ys + 4);
		width = xMax - xMin;
		height = yMax - yMin;
		xCenterNew = width / 2;
		yCenterNew = height / 2;
	} while (0);
	Image *pImage = CreateDerivation(sig, width, height);
	if (sig.IsSignalled()) return NULL;
	unsigned char *pLineDst = pImage->GetPointer(0);
	size_t bytesPerLineDst = pImage->GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	unsigned char buffBlank[8];
	PutPixel(buffBlank, color);
	for (int y = 0; y < height; y++) {
		unsigned char *pPixelDst = pLineDst;
		for (int x = 0; x < width; x++) {
			int xm, ym;
			RotateCoord(xm, ym, x - xCenterNew, y - yCenterNew, cos1024, sin1024);
			xm += xCenter, ym += yCenter;
			if (xm >= 0 && xm < static_cast<int>(_width) &&
								ym >= 0 && ym < static_cast<int>(_height)) {
				unsigned char *pPixelSrc = GetPointer(xm, ym);
				StorePixel(pPixelDst, pPixelSrc, _format == Image::FORMAT_RGBA);
			} else {
				StorePixel(pPixelDst, buffBlank, _format == Image::FORMAT_RGBA);
			}
			pPixelDst += bytesPerPixel;
		}
		pLineDst += bytesPerLineDst;
	}
	return pImage;
}

Image *Image::Crop(Signal sig, size_t x, size_t y, size_t width, size_t height)
{
	Image *pImage = CreateDerivation(sig, width, height);
	if (sig.IsSignalled()) return NULL;
	const unsigned char *pLineSrc = GetPointer(x, y);
	unsigned char *pLineDst = pImage->GetPointer(0);
	size_t bytesPerLineSrc = GetBytesPerLine();
	size_t bytesPerLineDst = pImage->GetBytesPerLine();
	for (size_t y = 0; y < height; y++) {
		::memcpy(pLineDst, pLineSrc, bytesPerLineDst);
		pLineSrc += bytesPerLineSrc;
		pLineDst += bytesPerLineDst;
	}
	return pImage;
}


Image *Image::Resize(Signal sig, size_t width, size_t height)
{
	Image *pImage = CreateDerivation(sig, width, height);
	if (sig.IsSignalled()) return NULL;
	const unsigned char *pLineSrc = GetPointer(0);
	unsigned char *pLineDst = pImage->GetPointer(0);
	size_t bytesPerPixel = GetBytesPerPixel();
	size_t bytesPerLineSrc = GetBytesPerLine();
	size_t bytesPerLineDst = pImage->GetBytesPerLine();
	OAL::Memory memory;
	size_t accumsSize = width * sizeof(Accum);
	Accum *accums = reinterpret_cast<Accum *>(memory.Allocate(accumsSize));
	::memset(accums, 0x00, accumsSize);
	size_t numerY = 0;
	if (_format == Image::FORMAT_RGB) {
		for (size_t ySrc = 0; ySrc < _height; ySrc++) {
			if (ySrc < _height) {
				const unsigned char *pPixelSrc = pLineSrc;
				unsigned char *pPixelDst = pLineDst;
				Accum *pAccum = accums;
				size_t numerX = 0;
				for (size_t xSrc = 0; xSrc < _width; xSrc++) {
					pAccum->AddRGB(pPixelSrc);
					pPixelSrc += bytesPerPixel;
					numerX += width;
					for ( ; numerX > _width; numerX -= _width) {
						pAccum++;
					}
				}
				pLineSrc += bytesPerLineSrc;
			}
			numerY += height;
			if (numerY > _height) {
				if (accums[0].cnt == 0) accums[0].cnt = 0; // this must not happen
				Accum *pAccum = accums;
				Accum *pAccumPrev = accums;
				for (size_t xDst = 0; xDst < width; xDst++, pAccum++) {
					size_t cnt = pAccum->cnt;
					if (cnt == 0) {
						*pAccum = *pAccumPrev;
					} else if (cnt == 1) {
						pAccumPrev = pAccum;
					} else if (cnt == 2) {
						pAccum->red >>= 1;
						pAccum->green >>= 1;
						pAccum->blue >>= 1;
						pAccumPrev = pAccum;
					} else if (cnt == 4) {
						pAccum->red >>= 2;
						pAccum->green >>= 2;
						pAccum->blue >>= 2;
						pAccumPrev = pAccum;
					} else {
						pAccum->red /= cnt;
						pAccum->green /= cnt;
						pAccum->blue /= cnt;
						pAccumPrev = pAccum;
					}
				}
				for ( ; numerY > _height; numerY -= _height) {
					Accum *pAccum = accums;
					unsigned char *pPixelDst = pLineDst;
					for (size_t xDst = 0; xDst < width;
									xDst++, pAccum++, pPixelDst += bytesPerPixel) {
						pAccum->StoreRGB(pPixelDst);
					}
					pLineDst += bytesPerLineDst;
				}
				::memset(accums, 0x00, accumsSize);
			}
		}
	} else if (_format == Image::FORMAT_RGBA) {
		for (size_t ySrc = 0; ySrc < _height; ySrc++) {
			if (ySrc < _height) {
				const unsigned char *pPixelSrc = pLineSrc;
				unsigned char *pPixelDst = pLineDst;
				Accum *pAccum = accums;
				size_t numerX = 0;
				for (size_t xSrc = 0; xSrc < _width; xSrc++) {
					pAccum->AddRGBA(pPixelSrc);
					pPixelSrc += bytesPerPixel;
					numerX += width;
					for ( ; numerX > _width; numerX -= _width) {
						pAccum++;
					}
				}
				pLineSrc += bytesPerLineSrc;
			}
			numerY += height;
			if (numerY > _height) {
				if (accums[0].cnt == 0) accums[0].cnt = 0; // this must not happen
				Accum *pAccum = accums;
				Accum *pAccumPrev = accums;
				for (size_t xDst = 0; xDst < width; xDst++, pAccum++) {
					size_t cnt = pAccum->cnt;
					if (cnt == 0) {
						*pAccum = *pAccumPrev;
					} else if (cnt == 1) {
						pAccumPrev = pAccum;
					} else if (cnt == 2) {
						pAccum->red >>= 1;
						pAccum->green >>= 1;
						pAccum->blue >>= 1;
						pAccum->alpha >>= 1;
						pAccumPrev = pAccum;
					} else if (cnt == 4) {
						pAccum->red >>= 2;
						pAccum->green >>= 2;
						pAccum->blue >>= 2;
						pAccum->alpha >>= 2;
						pAccumPrev = pAccum;
					} else {
						pAccum->red /= cnt;
						pAccum->green /= cnt;
						pAccum->blue /= cnt;
						pAccum->alpha /= cnt;
						pAccumPrev = pAccum;
					}
				}
				for ( ; numerY > _height; numerY -= _height) {
					Accum *pAccum = accums;
					unsigned char *pPixelDst = pLineDst;
					for (size_t xDst = 0; xDst < width;
								xDst++, pAccum++, pPixelDst += bytesPerPixel) {
						pAccum->StoreRGBA(pPixelDst);
					}
					pLineDst += bytesPerLineDst;
				}
				::memset(accums, 0x00, accumsSize);
			}
		}
	}
	return pImage;
}

void Image::Paste(size_t x, size_t y, Image *pImage,
	size_t width, size_t height, size_t xOffset, size_t yOffset, unsigned char alpha)
{
	const unsigned char *pLineSrc = pImage->GetPointer(xOffset, yOffset);
	unsigned char *pLineDst = GetPointer(x, y);
	size_t bytesPerLineSrc = pImage->GetBytesPerLine();
	size_t bytesPerLineDst = GetBytesPerLine();
	if (_format == pImage->GetFormat()) {
		size_t bytesToCopy = width * GetBytesPerPixel();
		for (size_t y = 0; y < height; y++) {
			::memcpy(pLineDst, pLineSrc, bytesToCopy);
			pLineSrc += bytesPerLineSrc;
			pLineDst += bytesPerLineDst;
		}
	} else if (_format == Image::FORMAT_RGB && pImage->GetFormat() == Image::FORMAT_RGBA) {
		for (size_t y = 0; y < height; y++) {
			const unsigned char *pPixelSrc = pLineSrc;
			unsigned char *pPixelDst = pLineDst;
			for (size_t x = 0; x < width; x++) {
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = *pPixelSrc++;
				pPixelSrc++;
			}
			pLineSrc += bytesPerLineSrc;
			pLineDst += bytesPerLineDst;
		}
	} else if (_format == Image::FORMAT_RGBA && pImage->GetFormat() == Image::FORMAT_RGB) {
		for (size_t y = 0; y < height; y++) {
			const unsigned char *pPixelSrc = pLineSrc;
			unsigned char *pPixelDst = pLineDst;
			for (size_t x = 0; x < width; x++) {
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = alpha;
			}
			pLineSrc += bytesPerLineSrc;
			pLineDst += bytesPerLineDst;
		}
	}
}

Object_palette *Image::CreateEmptyPalette(Environment &env, size_t nEntries)
{
	_pObjPalette.reset(new Object_palette(env, nEntries));
	return _pObjPalette.get();
}

void Image::SetPaletteObj(Object_palette *pObjPalette)
{
	_pObjPalette.reset(pObjPalette);
}

bool Image::Read(Environment &env, Signal sig, Stream &stream, const char *imgType)
{
	ImageStreamer *pImageStreamer = NULL;
	pImageStreamer = ImageStreamer::FindResponsible(sig, stream, imgType);
	if (sig.IsSignalled()) return false;
	if (pImageStreamer == NULL) {
		sig.SetError(ERR_FormatError, "unsupported image type");
		return false;
	}
	return pImageStreamer->Read(env, sig, this, stream);
}

bool Image::Write(Environment &env, Signal sig, Stream &stream, const char *imgType)
{
	ImageStreamer *pImageStreamer = NULL;
	pImageStreamer = ImageStreamer::FindResponsible(sig, stream, imgType);
	if (sig.IsSignalled()) return false;
	if (pImageStreamer == NULL) {
		sig.SetError(ERR_FormatError, "unsupported image type");
		return false;
	}
	return pImageStreamer->Write(env, sig, this, stream);
}

int Image::CalcDIBBitCount() const
{
	if (GetPaletteObj() == NULL) return static_cast<int>(GetBitsPerPixel());
	size_t nEntries = GetPaletteObj()->CountEntries();
	size_t nBits = 1;
	for ( ; nEntries > static_cast<size_t>(1 << nBits); nBits++) ;
	nBits =
		(nBits == 2 || nBits == 3)? 4 :
		(nBits == 5 || nBits == 6 || nBits == 7)? 8 :
		(nBits > 8)? 8 : nBits;
	return static_cast<int>(nBits);
}

size_t Image::CalcDIBImageSize(int biBitCount, bool maskFlag) const
{
	size_t bytesPerLine = 0;
	if (biBitCount == 1) {
		bytesPerLine = (_width + 7) / 8;
	} else if (biBitCount == 4) {
		bytesPerLine = (_width + 1) / 2;
	} else if (biBitCount == 8) {
		bytesPerLine = _width;
	} else if (biBitCount == 24) {
		bytesPerLine = _width * 3;
	} else if (biBitCount == 32) {
		bytesPerLine = _width * 4;
	}
	size_t bytes = ((bytesPerLine + 3) / 4 * 4) * _height;
	if (maskFlag) {
		size_t bytesPerLine = (_width + 7) / 8;
		bytes += ((bytesPerLine + 3) / 4 * 4) * _height;
	}
	return bytes;
}

bool Image::ReadDIBPalette(Environment &env, Signal sig, Stream &stream, int biBitCount)
{
	if (biBitCount == 24 || biBitCount == 32) return true;
	if (!(biBitCount == 1 || biBitCount == 4 || biBitCount == 8)) {
		sig.SetError(ERR_FormatError, "unsupported pixel depth %d", biBitCount);
		return false;
	}
	size_t nEntries = 1 << biBitCount;
	CreateEmptyPalette(env, nEntries);
	for (size_t idx = 0; idx < nEntries; idx++) {
		unsigned char buff[4];
		if (stream.Read(sig, buff, 4) < 4) {
			sig.SetError(ERR_FormatError, "failed to read DIB palette");
			return false;
		}
		_pObjPalette->SetEntry(idx, buff[2], buff[1], buff[0]);
	}
	return true;
}

bool Image::WriteDIBPalette(Environment &env, Signal sig, Stream &stream, int biBitCount)
{
	if (biBitCount == 24 || biBitCount == 32) return true;
	if (!(biBitCount == 1 || biBitCount == 4 || biBitCount == 8)) {
		sig.SetError(ERR_FormatError, "unsupported pixel depth %d", biBitCount);
		return false;
	}
	size_t nEntries = 1 << biBitCount;
	if (_pObjPalette.IsNull()) {
		_pObjPalette.reset(new Object_palette(env));
		if (biBitCount == 1) {
			_pObjPalette->Prepare(sig, Gura_Symbol(mono));
		} else if (biBitCount == 4) {
			_pObjPalette->Prepare(sig, Gura_Symbol(basic));
		} else { // biBitCount == 8
			_pObjPalette->Prepare(sig, Gura_Symbol(win256));
		}
		if (sig.IsSignalled()) return false;
	}
	size_t idx = 0;
	size_t idxMax = ChooseMin(nEntries, _pObjPalette->CountEntries());
	unsigned char buff[4];
	for ( ; idx < idxMax; idx++) {
		const unsigned char *pEntry = _pObjPalette->GetEntry(idx);
		buff[0] = GetPixelB(pEntry);
		buff[1] = GetPixelG(pEntry);
		buff[2] = GetPixelR(pEntry);
		buff[3] = 0x00;
		stream.Write(sig, buff, 4);
		if (sig.IsSignalled()) return false;
	}
	::memset(buff, 0x00, 4);
	for (; idx < nEntries; idx++) {
		stream.Write(sig, buff, 4);
		if (sig.IsSignalled()) return false;
	}
	return true;
}

bool Image::ReadDIB(Signal sig, Stream &stream,
				int biWidth, int biHeight, int biBitCount, bool maskFlag)
{
	bool vertRevFlag = true;
	if (biHeight < 0) {
		biHeight = -biHeight;
		vertRevFlag = false;
	}
	if (!AllocBuffer(sig, biWidth, biHeight, 0xff)) return false;
	if (biBitCount == 1) {
		size_t bytesPerLine = (biWidth + 7) / 8;
		size_t bytesAlign = (bytesPerLine + 3) / 4 * 4 - bytesPerLine;
		int bitsRest = 0;
		unsigned char ch;
		int iLine = 0, iPixel = 0;
		int bytesPitch = static_cast<int>(GetBytesPerLine());
		if (vertRevFlag) bytesPitch = -bytesPitch;
		unsigned char *pLine = GetPointer(vertRevFlag? biHeight - 1 : 0);
		unsigned char *pPixel = pLine;
		for (;;) {
			if (iPixel >= biWidth) {
				if (++iLine >= biHeight) break;
				iPixel = 0, pLine += bytesPitch, pPixel = pLine;
				stream.Seek(sig, static_cast<long>(bytesAlign), Stream::SeekCur);
				if (sig.IsSignalled()) return false;
				bitsRest = 0;
			}
			if (bitsRest == 0) {
				if (stream.Read(sig, &ch, 1) < 1) break;
				bitsRest = 8;
			}
			unsigned char idx = ch >> 7;
			ch <<= 1, bitsRest--;
			StorePixelRGB(pPixel, _pObjPalette->GetEntry(idx));
			pPixel += GetBytesPerPixel();
			iPixel++;
		}
		if (sig.IsSignalled()) return false;
	} else if (biBitCount == 4) {
		size_t bytesPerLine = (biWidth + 1) / 2;
		size_t bytesAlign = (bytesPerLine + 3) / 4 * 4 - bytesPerLine;
		unsigned char ch;
		std::auto_ptr<Scanner> pScanner(CreateScanner(
				vertRevFlag? Image::SCAN_LeftBottomHorz : Image::SCAN_LeftTopHorz));
		if (stream.Read(sig, &ch, 1) < 1) return false;
		int bitsRest = 8;
		for (;;) {
			unsigned char idx = ch >> 4;
			ch <<= 4, bitsRest -= 4;
			StorePixelRGB(pScanner->GetPointer(), _pObjPalette->GetEntry(idx));
			if (!pScanner->NextPixel()) {
				if (!pScanner->NextLine()) break;
				stream.Seek(sig, static_cast<long>(bytesAlign), Stream::SeekCur);
				if (sig.IsSignalled()) return false;
				bitsRest = 0;
			}
			if (bitsRest == 0) {
				if (stream.Read(sig, &ch, 1) < 1) break;
				bitsRest = 8;
			}
		}
		if (sig.IsSignalled()) return false;
	} else if (biBitCount == 8) {
		size_t bytesAlign = (biWidth + 3) / 4 * 4 - biWidth;
		unsigned char ch;
		std::auto_ptr<Scanner> pScanner(CreateScanner(
				vertRevFlag? Image::SCAN_LeftBottomHorz : Image::SCAN_LeftTopHorz));
		if (stream.Read(sig, &ch, 1) < 1) return false;
		for (;;) {
			StorePixelRGB(pScanner->GetPointer(), _pObjPalette->GetEntry(ch));
			if (!pScanner->NextPixel()) {
				if (!pScanner->NextLine()) break;
				stream.Seek(sig, static_cast<long>(bytesAlign), Stream::SeekCur);
				if (sig.IsSignalled()) return false;
			}
			if (stream.Read(sig, &ch, 1) < 1) break;
		}
		if (sig.IsSignalled()) return false;
	} else if (biBitCount == 24) {
		size_t bytesAlign = (3 * biWidth + 3) / 4 * 4 - 3 * biWidth;
		unsigned char buff[3];
		std::auto_ptr<Scanner> pScanner(CreateScanner(
				vertRevFlag? Image::SCAN_LeftBottomHorz : Image::SCAN_LeftTopHorz));
		for (;;) {
			if (stream.Read(sig, buff, 3) < 3) break;
			StorePixel(pScanner->GetPointer(), buff[2], buff[1], buff[0]);
			if (!pScanner->NextPixel()) {
				if (!pScanner->NextLine()) break;
				stream.Seek(sig, static_cast<long>(bytesAlign), Stream::SeekCur);
				if (sig.IsSignalled()) return false;
			}
		}
		if (sig.IsSignalled()) return false;
	} else if (biBitCount == 32) {
		unsigned char buff[4];
		std::auto_ptr<Scanner> pScanner(CreateScanner(
				vertRevFlag? Image::SCAN_LeftBottomHorz : Image::SCAN_LeftTopHorz));
		if (_format == Image::FORMAT_RGBA) {
			while (stream.Read(sig, buff, 4) == 4) {
				StorePixel(pScanner->GetPointer(), buff[2], buff[1], buff[0], buff[3]);
				if (!pScanner->Next()) break;
			}
		} else {
			while (stream.Read(sig, buff, 4) == 4) {
				StorePixel(pScanner->GetPointer(), buff[2], buff[1], buff[0]);
				if (!pScanner->Next()) break;
			}
		}
		if (sig.IsSignalled()) return false;
	} else {
		sig.SetError(ERR_FormatError, "invalid DIB format");
		return false;
	}
	if (maskFlag) {
		size_t bytesPerLine = (biWidth + 7) / 8;
		size_t bytesPerLineAligned = (bytesPerLine + 3) / 4 * 4;
		size_t bytesAlign = bytesPerLineAligned - bytesPerLine;
		if (GetFormat() == Image::FORMAT_RGBA) {
			// read AND bitmap
			int bitsRest = 0;
			unsigned char ch;
			int iLine = 0, iPixel = 0;
			int bytesPitch = static_cast<int>(GetBytesPerLine());
			if (vertRevFlag) bytesPitch = -bytesPitch;
			unsigned char *pLine = GetPointer(vertRevFlag? biHeight - 1 : 0);
			unsigned char *pPixel = pLine;
			for (;;) {
				if (iPixel >= biWidth) {
					if (++iLine >= biHeight) break;
					iPixel = 0, pLine += bytesPitch, pPixel = pLine;
					stream.Seek(sig, static_cast<long>(bytesAlign), Stream::SeekCur);
					if (sig.IsSignalled()) return false;
					bitsRest = 0;
				}
				if (bitsRest == 0) {
					if (stream.Read(sig, &ch, 1) < 1) break;
					bitsRest = 8;
				}
				unsigned char idx = ch >> 7;
				ch <<= 1, bitsRest--;
				pPixel[Image::OffsetAlpha] = idx? 0 : 255;
				pPixel += GetBytesPerPixel();
				iPixel++;
			}
		} else {
			// just skip AND bitmap
			long bytes = static_cast<long>((bytesPerLine + 3) / 4 * 4 * GetHeight());
			stream.Seek(sig, bytes, Stream::SeekCur);
		}
		if (sig.IsSignalled()) return false;
	}
	return true;
}

bool Image::WriteDIB(Signal sig, Stream &stream, int biBitCount, bool maskFlag)
{
	int biWidth = static_cast<int>(GetWidth());
	int biHeight = static_cast<int>(GetHeight());
	if (biBitCount == 1) {
		if (_pObjPalette.IsNull()) return false;
		size_t bytesPerLine = (biWidth + 7) / 8;
		size_t bytesAlign = (bytesPerLine + 3) / 4 * 4 - bytesPerLine;
		int bitsAccum = 0;
		unsigned char chAccum = 0x00;
		std::auto_ptr<Scanner> pScanner(CreateScanner(Image::SCAN_LeftBottomHorz));
		for (;;) {
			unsigned char ch = static_cast<unsigned char>(
							_pObjPalette->LookupNearest(pScanner->GetPointer()));
			chAccum |= ch << ((8 - 1) - bitsAccum);
			bitsAccum += 1;
			if (bitsAccum >= 8) {
				stream.Write(sig, &chAccum, 1);
				if (sig.IsSignalled()) return false;
				chAccum = 0x00;
				bitsAccum = 0;
			}
			if (!pScanner->NextPixel()) {
				if (bitsAccum > 0) {
					stream.Write(sig, &chAccum, 1);
					if (sig.IsSignalled()) return false;
					chAccum = 0x00;
					bitsAccum = 0;
				}
				stream.Write(sig, "\x00\x00\x00\x00", bytesAlign);
				if (sig.IsSignalled()) return false;
				if (!pScanner->NextLine()) break;
			}
		}
	} else if (biBitCount == 4) {
		if (_pObjPalette.IsNull()) return false;
		size_t bytesPerLine = (biWidth + 1) / 2;
		size_t bytesAlign = (bytesPerLine + 3) / 4 * 4 - bytesPerLine;
		int bitsAccum = 0;
		unsigned char chAccum = 0x00;
		std::auto_ptr<Scanner> pScanner(CreateScanner(Image::SCAN_LeftBottomHorz));
		for (;;) {
			unsigned char ch = static_cast<unsigned char>(
							_pObjPalette->LookupNearest(pScanner->GetPointer()));
			chAccum |= ch << ((8 - 4) - bitsAccum);
			bitsAccum += 4;
			if (bitsAccum >= 8) {
				stream.Write(sig, &chAccum, 1);
				if (sig.IsSignalled()) return false;
				chAccum = 0x00;
				bitsAccum = 0;
			}
			if (!pScanner->NextPixel()) {
				if (bitsAccum > 0) {
					stream.Write(sig, &chAccum, 1);
					if (sig.IsSignalled()) return false;
					chAccum = 0x00;
					bitsAccum = 0;
				}
				stream.Write(sig, "\x00\x00\x00\x00", bytesAlign);
				if (sig.IsSignalled()) return false;
				if (!pScanner->NextLine()) break;
			}
		}
	} else if (biBitCount == 8) {
		if (_pObjPalette.IsNull()) return false;
		size_t bytesAlign = (biWidth + 3) / 4 * 4 - biWidth;
		std::auto_ptr<Scanner> pScanner(CreateScanner(Image::SCAN_LeftBottomHorz));
		for (;;) {
			unsigned char ch = static_cast<unsigned char>(
							_pObjPalette->LookupNearest(pScanner->GetPointer()));
			stream.Write(sig, &ch, 1);
			if (sig.IsSignalled()) return false;
			if (!pScanner->NextPixel()) {
				stream.Write(sig, "\x00\x00\x00\x00", bytesAlign);
				if (sig.IsSignalled()) return false;
				if (!pScanner->NextLine()) break;
			}
		}
	} else if (biBitCount == 24) {
		size_t bytesAlign = ((3 * biWidth) + 3) / 4 * 4 - 3 * biWidth;
		unsigned char buff[3];
		std::auto_ptr<Scanner> pScanner(CreateScanner(Image::SCAN_LeftBottomHorz));
		for (;;) {
			buff[0] = pScanner->GetBlue();
			buff[1] = pScanner->GetGreen();
			buff[2] = pScanner->GetRed();
			stream.Write(sig, buff, 3);
			if (sig.IsSignalled()) return false;
			if (!pScanner->NextPixel()) {
				stream.Write(sig, "\x00\x00\x00\x00", bytesAlign);
				if (sig.IsSignalled()) return false;
				if (!pScanner->NextLine()) break;
			}
		}
	} else if (biBitCount == 32) {
		unsigned char buff[4];
		std::auto_ptr<Scanner> pScanner(CreateScanner(Image::SCAN_LeftBottomHorz));
		for (;;) {
			buff[0] = pScanner->GetBlue();
			buff[1] = pScanner->GetGreen();
			buff[2] = pScanner->GetRed();
			buff[3] = pScanner->GetAlpha();
			stream.Write(sig, buff, 4);
			if (sig.IsSignalled()) return false;
			if (!pScanner->Next()) break;
		}
	} else {
		sig.SetError(ERR_FormatError, "not supported bit depth");
		return false;
	}
	if (maskFlag) {
		size_t bytesPerLine = (biWidth + 7) / 8;
		size_t bytesPerLineAligned = (bytesPerLine + 3) / 4 * 4;
		size_t bytesAlign = bytesPerLineAligned - bytesPerLine;
		if (GetFormat() == Image::FORMAT_RGBA) {
			// write AND bitmap
			int bitsAccum = 0;
			unsigned char chAccum = 0x00;
			std::auto_ptr<Scanner> pScanner(CreateScanner(Image::SCAN_LeftBottomHorz));
			for (;;) {
				unsigned char ch = (pScanner->GetAlpha() < 128)? 1 : 0;
				chAccum |= ch << ((8 - 1) - bitsAccum);
				bitsAccum += 1;
				if (bitsAccum >= 8) {
					stream.Write(sig, &chAccum, 1);
					if (sig.IsSignalled()) return false;
					chAccum = 0x00;
					bitsAccum = 0;
				}
				if (!pScanner->NextPixel()) {
					if (bitsAccum > 0) {
						stream.Write(sig, &chAccum, 1);
						if (sig.IsSignalled()) return false;
						chAccum = 0x00;
						bitsAccum = 0;
					}
					stream.Write(sig, "\x00\x00\x00\x00", bytesAlign);
					if (sig.IsSignalled()) return false;
					if (!pScanner->NextLine()) break;
				}
			}
		} else {
			char *buff = new char [bytesPerLineAligned];
			::memset(buff, 0x00, bytesPerLineAligned);
			for (size_t y = 0; y < GetHeight(); y++) {
				stream.Write(sig, buff, bytesPerLineAligned);
				if (sig.IsSignalled()) break;
			}
			delete[] buff;
			if (sig.IsSignalled()) return false;
		}
	}
	return true;
}

void Image::SetBuffer(size_t width, size_t height, unsigned char *buff,
									size_t bytesPerPixel, size_t bytesPerLine)
{
	_width = width, _height = height;
	_buff = buff;
	_metrics.bitsPerPixel = bytesPerPixel * 8;
	_metrics.bytesPerPixel = bytesPerPixel;
	_metrics.bytesPerLine = bytesPerLine;
}

#if GURA_USE_MSWIN_DIB
//-----------------------------------------------------------------------------
// Image (Windows DIB section)
//-----------------------------------------------------------------------------
Image::Image(Format format) : _cntRef(1),
		_format(format), _width(0), _height(0), _buff(NULL),
		_hBmp(NULL), _pObjPalette(NULL)
{
	InitMetrics();
}

Image::Image(const Image &image) : _cntRef(1),
		_format(image._format), _width(0), _height(0), _buff(NULL),
		_hBmp(NULL), _pObjPalette(Object_palette::Reference(image._pObjPalette.get()))
{
	Signal sig;
	if (AllocBuffer(sig, image._width, image._height, 0x00)) {
		::memcpy(_buff, image._buff, GetBufferSize());
	}
}

Image::~Image()
{
	FreeBuffer();
}

Image *Image::Clone() const
{
	return new Image(*this);
}

bool Image::AllocBuffer(Signal sig,
					size_t width, size_t height, unsigned char fillValue)
{
	FreeBuffer();
	if (width == 0 || height == 0) {
		sig.SetError(ERR_MemoryError, "failed to allocate image buffer");
		return false;
	}
	BITMAPINFO bmi;
	BITMAPINFOHEADER &hdr = bmi.bmiHeader;
	::memset(&bmi, 0, sizeof(BITMAPINFO));
	hdr.biSize = sizeof(BITMAPINFOHEADER);
	hdr.biWidth = static_cast<int>(width);
	hdr.biHeight = -static_cast<int>(height);
	hdr.biPlanes = 1;
	hdr.biBitCount =
		(_format == Image::FORMAT_RGB)? 24 :
		(_format == Image::FORMAT_RGBA)? 32 : 32;
	hdr.biCompression = BI_RGB;
	hdr.biSizeImage = 0;
	hdr.biXPelsPerMeter = 0;
	hdr.biYPelsPerMeter = 0;
	hdr.biClrUsed = 0;
	hdr.biClrImportant = 0;
	void *buff = NULL;
	_hBmp = ::CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, &buff, NULL, 0);
	if (_hBmp == NULL || buff == NULL) {
		sig.SetError(ERR_MemoryError, "failed to allocate image buffer");
		return false;
	}
	_width = width, _height = height;
	_buff = reinterpret_cast<unsigned char *>(buff);
	InitMetrics();
	::memset(_buff, fillValue, GetBufferSize());
	return true;
}

void Image::FreeBuffer()
{
	if (_hBmp != NULL) ::DeleteObject(_hBmp);
	_width = 0, _height = 0;
	_buff = NULL;
	_hBmp = NULL;
}
#else // GURA_USE_MSWIN_DIB
//-----------------------------------------------------------------------------
// Image (on memory)
//-----------------------------------------------------------------------------
Image::Image(Format format) : _cntRef(1),
		_format(format), _width(0), _height(0), _buff(NULL), _pObjPalette(NULL)
{
	InitMetrics();
}

Image::Image(const Image &image) : _cntRef(1),
		_format(image._format), _width(0), _height(0), _buff(NULL),
		_pObjPalette(Object_palette::Reference(image._pObjPalette.get()))
{
	Signal sig;
	if (AllocBuffer(sig, image._width, image._height, 0x00)) {
		::memcpy(_buff, image._buff, GetBufferSize());
	}
}

Image::~Image()
{
	FreeBuffer();
}

Object *Image::Clone() const
{
	return new Image(*this);
}

bool Image::AllocBuffer(Signal sig,
					size_t width, size_t height, unsigned char fillValue)
{
	_memory.Free();
	if (width == 0 || height == 0) {
		sig.SetError(ERR_MemoryError, "failed to allocate image buffer");
		return false;
	}
	_width = width, _height = height;
	InitMetrics();
	_buff = reinterpret_cast<unsigned char *>(_memory.Allocate(GetBufferSize()));
	::memset(_buff, fillValue, GetBufferSize());
	return true;
}

void Image::FreeBuffer()
{
	_memory.Free();
	_width = 0, _height = 0;
	_buff = NULL;
}
#endif

//-----------------------------------------------------------------------------
// Image::Scanner
//-----------------------------------------------------------------------------
Image::Scanner::Scanner(Image *pImage,
			size_t x, size_t y, size_t width, size_t height, ScanDir scanDir) :
	_pImage(pImage), _iPixel(0), _iLine(0)
{
	int bytesPerPixel = static_cast<int>(_pImage->GetBytesPerPixel());
	int bytesPerLine = static_cast<int>(_pImage->GetBytesPerLine());
	switch (scanDir) {
	case Image::SCAN_LeftTopHorz:
		_pPixel = _pImage->GetPointer(x, y);
		_nPixels = width, _nLines = height;
		_pitchPixel = bytesPerPixel;
		_pitchLine = bytesPerLine - bytesPerPixel * static_cast<int>(width);
		break;
	case Image::SCAN_LeftTopVert:
		_pPixel = _pImage->GetPointer(x, y);
		_nPixels = height, _nLines = width;
		_pitchPixel = bytesPerLine;
		_pitchLine = bytesPerPixel - bytesPerLine * static_cast<int>(height);
		break;
	case Image::SCAN_RightTopHorz:
		_pPixel = _pImage->GetPointer(x + width - 1, y);
		_nPixels = width, _nLines = height;
		_pitchPixel = -bytesPerPixel;
		_pitchLine = bytesPerLine + bytesPerPixel * static_cast<int>(width);
		break;
	case Image::SCAN_RightTopVert:
		_pPixel = _pImage->GetPointer(x + width - 1, y);
		_nPixels = height, _nLines = width;
		_pitchPixel = bytesPerLine;
		_pitchLine = -bytesPerPixel - bytesPerLine * static_cast<int>(height);
		break;
	case Image::SCAN_LeftBottomHorz:
		_pPixel = _pImage->GetPointer(x, y + height - 1);
		_nPixels = width, _nLines = height;
		_pitchPixel = bytesPerPixel;
		_pitchLine = -bytesPerLine - bytesPerPixel * static_cast<int>(width);
		break;
	case Image::SCAN_LeftBottomVert:
		_pPixel = _pImage->GetPointer(x, y + height - 1);
		_nPixels = height, _nLines = width;
		_pitchPixel = -bytesPerLine;
		_pitchLine = bytesPerPixel + bytesPerLine * static_cast<int>(height);
		break;
	case Image::SCAN_RightBottomHorz:
		_pPixel = _pImage->GetPointer(x + width - 1, y + height - 1);
		_nPixels = width, _nLines = height;
		_pitchPixel = -bytesPerPixel;
		_pitchLine = -bytesPerLine + bytesPerPixel * static_cast<int>(width);
		break;
	case Image::SCAN_RightBottomVert:
		_pPixel = _pImage->GetPointer(x + width - 1, y + height - 1);
		_nPixels = height, _nLines = width;
		_pitchPixel = -bytesPerLine;
		_pitchLine = -bytesPerPixel + bytesPerLine * static_cast<int>(height);
		break;
	default:
		break;
	}
}

Image::Scanner::~Scanner()
{
}

//-----------------------------------------------------------------------------
// Image::IteratorEach
//-----------------------------------------------------------------------------
Iterator *Image::IteratorEach::GetSource()
{
	return NULL;
}

bool Image::IteratorEach::DoNext(Environment &env, Signal sig, Value &value)
{
	Image *pImage = _scanner.GetImage();
	//Environment &env = *pObjImage;
	if (_doneFlag) return false;
	unsigned char red = _scanner.GetRed();
	unsigned char green = _scanner.GetGreen();
	unsigned char blue = _scanner.GetBlue();
	unsigned char alpha = (pImage->GetFormat() == Image::FORMAT_RGBA)?
											_scanner.GetAlpha() : 0xff;
	value = Value(new Object_color(env, red, green, blue, alpha));
	_doneFlag = !_scanner.Next();
	return true;
}

String Image::IteratorEach::ToString(Signal sig) const
{
	return String("<iterator:image#each>");
}

void Image::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// ImageStreamer
//-----------------------------------------------------------------------------
ImageStreamer::List *ImageStreamer::_pList = NULL;
void ImageStreamer::Register(ImageStreamer *pImageStreamer)
{
	if (_pList == NULL) _pList = new List();
	_pList->push_back(pImageStreamer);
}

ImageStreamer *ImageStreamer::FindResponsible(Signal sig, Stream &stream, const char *imgType)
{
	if (_pList == NULL) return NULL;
	if (imgType != NULL) return FindByImgType(imgType);
	foreach (List, ppImageStreamer, *_pList) {
		ImageStreamer *pImageStreamer = *ppImageStreamer;
		if (pImageStreamer->IsResponsible(sig, stream)) return pImageStreamer;
		if (sig.IsSignalled()) break;
	}
	return NULL;
}

ImageStreamer *ImageStreamer::FindByImgType(const char *imgType)
{
	if (_pList == NULL) return NULL;
	foreach (List, ppImageStreamer, *_pList) {
		ImageStreamer *pImageStreamer = *ppImageStreamer;
		if (::strcasecmp(pImageStreamer->GetImgType(), imgType) == 0) {
			return pImageStreamer;
		}
	}
	return NULL;
}

}
