//=============================================================================
// Image
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Image
//-----------------------------------------------------------------------------
Image::Image(Format format) : _cntRef(1),
			_format(format), _width(0), _height(0), _pPalette(nullptr)
{
	InitMetrics();
}

Image::Image(const Image &image) : _cntRef(1),
			_format(image._format), _width(0), _height(0),
			_pPalette(Palette::Reference(image.GetPalette()))
{
	if (AllocBuffer(image._width, image._height, 0x00)) {
		::memcpy(GetBuffer(), image.GetBuffer(), GetBufferSize());
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

bool Image::AllocBuffer(size_t width, size_t height)
{
	if (width == 0 || height == 0) return false;
	_width = width, _height = height;
	InitMetrics();
#if GURA_USE_MSWIN_DIB
	do {
		AutoPtr<MemoryDIB> pMemory(new MemoryDIB());
		if (!pMemory->AllocBuffer(width, height,
				(_format == FORMAT_RGB)? 24 : (_format == FORMAT_RGBA)? 32 : 32)) {
			return false;
		}
		_pMemory.reset(pMemory.release());
	} while (0);
#else
	_pMemory.reset(new MemoryHeap(GetBufferSize()));
#endif
	return true;
}

bool Image::AllocBuffer(size_t width, size_t height, UChar fillValue)
{
	if (!AllocBuffer(width, height)) return false;
	::memset(GetBuffer(), fillValue, GetBufferSize());
	return true;
}

bool Image::AllocBuffer(Signal &sig, size_t width, size_t height)
{
	if (AllocBuffer(width, height)) return true;
	sig.SetError(ERR_MemoryError, "failed to allocate image buffer");
	return false;
}

bool Image::AllocBuffer(Signal &sig, size_t width, size_t height, UChar fillValue)
{
	if (AllocBuffer(width, height, fillValue)) return true;
	sig.SetError(ERR_MemoryError, "failed to allocate image buffer");
	return false;
}

void Image::FreeBuffer()
{
	_pMemory.reset(nullptr);
	_width = 0, _height = 0;
}

bool Image::CheckEmpty(Signal &sig) const
{
	if (!IsValid()) return true;
	sig.SetError(ERR_ValueError, "image has already been initialized with a buffer");
	return false;
}

bool Image::CheckValid(Signal &sig) const
{
	if (IsValid()) return true;
	sig.SetError(ERR_ValueError, "image does not have a buffer");
	return false;
}

Image::ScanDir Image::SymbolToScanDir(const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_Symbol(left_top_horz))) {
		return SCAN_LeftTopHorz;
	} else if (pSymbol->IsIdentical(Gura_Symbol(left_top_vert))) {
		return SCAN_LeftTopVert;
	} else if (pSymbol->IsIdentical(Gura_Symbol(left_bottom_horz))) {
		return SCAN_LeftBottomHorz;
	} else if (pSymbol->IsIdentical(Gura_Symbol(left_bottom_vert))) {
		return SCAN_LeftBottomVert;
	} else if (pSymbol->IsIdentical(Gura_Symbol(right_top_horz))) {
		return SCAN_RightTopHorz;
	} else if (pSymbol->IsIdentical(Gura_Symbol(right_top_vert))) {
		return SCAN_RightTopVert;
	} else if (pSymbol->IsIdentical(Gura_Symbol(right_bottom_horz))) {
		return SCAN_RightBottomHorz;
	} else if (pSymbol->IsIdentical(Gura_Symbol(right_bottom_vert))) {
		return SCAN_RightBottomVert;
	} else {
		return SCAN_None;
	}
}

size_t Image::SymbolToPixelOffset(Signal &sig, const Symbol *pSymbol) const
{
	if (pSymbol->IsIdentical(Gura_Symbol(r))) {
		return OffsetR;
	} else if (pSymbol->IsIdentical(Gura_Symbol(g))) {
		return OffsetG;
	} else if (pSymbol->IsIdentical(Gura_Symbol(b))) {
		return OffsetB;
	} else if (pSymbol->IsIdentical(Gura_Symbol(a))) {
		if (GetFormat() != FORMAT_RGBA) {
			sig.SetError(ERR_FormatError, "only RGBA format contains alpha element");
			return 0;
		}
		return OffsetA;
	}
	sig.SetError(ERR_FormatError, "unsupported image element '%s'", pSymbol->GetName());
	return 0;
}

Image::Format Image::SymbolToFormat(Signal &sig, const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_Symbol(rgb))) {
		return FORMAT_RGB;
	} else if (pSymbol->IsIdentical(Gura_Symbol(rgba))) {
		return FORMAT_RGBA;
	} else {
		sig.SetError(ERR_FormatError, "specify `rgb or `rgba for image format");
		return FORMAT_None;
	}
}

const Symbol *Image::FormatToSymbol(Format format)
{
	if (format == FORMAT_RGB) {
		return Gura_Symbol(rgb);
	} else if (format == FORMAT_RGBA) {
		return Gura_Symbol(rgba);
	} else {
		return Gura_Symbol(nil);
	}
}

void Image::InitMetrics()
{
	_metrics.bitsPerPixel =
			(_format == FORMAT_RGB)? 24 :
			(_format == FORMAT_RGBA)? 32 : 0;
	_metrics.bytesPerPixel = _metrics.bitsPerPixel / 8;
	_metrics.bytesPerLine =
			(_format == FORMAT_RGB)? ((_width * 3 + 3) / 4) * 4 :
			(_format == FORMAT_RGBA)? _width * 4 : 0;
}

Image *Image::CreateDerivation(Signal &sig,
						size_t width, size_t height, Palette *pPalette)
{
	AutoPtr<Image> pImage(new Image(_format));
	if (!pImage->AllocBuffer(sig, width, height, 0x00)) return nullptr;
	if (pPalette != nullptr) {
		pImage->_pPalette.reset(pPalette);
	} else if (!_pPalette.IsNull()) {
		pImage->_pPalette.reset(Palette::Reference(_pPalette.get()));
	}
	return pImage.release();
}

bool Image::CheckCoord(Signal &sig, size_t x, size_t y) const
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

void Image::PutPixel(UChar *buff, const Color &color)
{
	if (_format == FORMAT_RGB) {
		*(buff + OffsetR)		= color.GetR();
		*(buff + OffsetG)	= color.GetG();
		*(buff + OffsetB)	= color.GetB();
	} else if (_format == FORMAT_RGBA) {
		*(buff + OffsetR)		= color.GetR();
		*(buff + OffsetG)	= color.GetG();
		*(buff + OffsetB)	= color.GetB();
		*(buff + OffsetA)	= color.GetA();
	}
}

void Image::GetPixel(const UChar *buff, Color &color)
{
	if (_format == FORMAT_RGB) {
		color = Color(GetPixelR(buff), GetPixelG(buff), GetPixelB(buff), 255);
	} else if (_format == FORMAT_RGBA) {
		color = Color(GetPixelR(buff), GetPixelG(buff), GetPixelB(buff), GetPixelA(buff));
	}
}

bool Image::Store(Environment &env, size_t x, size_t y, size_t width, size_t height,
							const Symbol *pSymbol, Iterator *pIterator)
{
	Signal &sig = env.GetSignal();
	size_t bytesPerLine = GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	UChar *pLine = GetPointer(x, y);
	size_t offPixel = SymbolToPixelOffset(sig, pSymbol);
	if (sig.IsSignalled()) return false;
	for (size_t iLine = 0; iLine < height; iLine++, pLine += bytesPerLine) {
		UChar *pPixel = pLine + offPixel;
		for (size_t iPixel = 0; iPixel < width; iPixel++, pPixel += bytesPerPixel) {
			Value value;
			if (!pIterator->Next(env, value)) return false;
			*pPixel = value.GetUChar();
		}
	}
	return true;
}

bool Image::Extract(Signal &sig, size_t x, size_t y, size_t width, size_t height,
									const Symbol *pSymbol, ValueList &valList)
{
	if (valList.size() < height * width) {
		sig.SetError(ERR_ValueError, "list size is too small");
		return false;
	}
	size_t bytesPerLine = GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	const UChar *pLine = GetPointer(x, y);
	size_t offPixel = SymbolToPixelOffset(sig, pSymbol);
	if (sig.IsSignalled()) return false;
	ValueList::iterator pValueElem = valList.begin();
	for (size_t iLine = 0; iLine < height; iLine++, pLine += bytesPerLine) {
		const UChar *pPixel = pLine + offPixel;
		for (size_t iPixel = 0; iPixel < width;
							iPixel++, pPixel += bytesPerPixel, pValueElem++) {
			*pValueElem = Value(*pPixel);
		}
	}
	return true;
}

void Image::ReplaceColorRect(size_t x, size_t y, size_t width, size_t height,
				const Color &colorOrg, const Color &color, double tolerance)
{
	std::unique_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	UChar buff[8];
	PutPixel(buff, color);
	if (tolerance == 0.) {
		UChar buffOrg[8];
		PutPixel(buffOrg, colorOrg);
		if (_format == FORMAT_RGBA) {
			do {
				UChar *pPixel = pScanner->GetPointer();
				if (::memcmp(pPixel, buffOrg, 3) == 0) {
					StorePixelRGB(pScanner->GetPointer(), buff);
				}
			} while (pScanner->Next());
		} else {
			do {
				UChar *pPixel = pScanner->GetPointer();
				if (::memcmp(pPixel, buffOrg, 3) == 0) {
					StorePixelRGB(pScanner->GetPointer(), buff);
				}
			} while (pScanner->Next());
		}
	} else {
		double toleranceSqu = tolerance * tolerance;
		if (_format == FORMAT_RGBA) {
			do {
				double dist = Color::CalcDistSqu(
						pScanner->GetR(), pScanner->GetG(), pScanner->GetB(),
						color.GetR(), color.GetG(), color.GetB());
				if (dist <= toleranceSqu) {
					StorePixelRGB(pScanner->GetPointer(), buff);
				}
			} while (pScanner->Next());
		} else {
			do {
				double dist = Color::CalcDistSqu(
						pScanner->GetR(), pScanner->GetG(), pScanner->GetB(),
						color.GetR(), color.GetG(), color.GetB());
				if (dist <= toleranceSqu) {
					StorePixelRGB(pScanner->GetPointer(), buff);
				}
			} while (pScanner->Next());
		}
	}
}

void Image::FillRect(size_t x, size_t y, size_t width, size_t height,
												const Color &color)
{
	UChar buff[8];
	PutPixel(buff, color);
	std::unique_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	if (_format == FORMAT_RGBA) {
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
					size_t width, size_t height, UChar a)
{
	std::unique_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	do {
		UChar *pPixel = pScanner->GetPointer();
		*(pPixel + OffsetA) = a;
	} while (pScanner->Next());
}

void Image::FillRectAlpha(size_t x, size_t y,
	size_t width, size_t height, UChar a, const Color &color, double tolerance)
{
	std::unique_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	if (tolerance == 0.) {
		UChar buff[8];
		PutPixel(buff, color);
		do {
			UChar *pPixel = pScanner->GetPointer();
			if (::memcmp(pPixel, buff, 3) == 0) {
				*(pPixel + OffsetA) = a;
			}
		} while (pScanner->Next());
	} else {
		double toleranceSqu = tolerance * tolerance;
		do {
			double dist = Color::CalcDistSqu(
					pScanner->GetR(), pScanner->GetG(), pScanner->GetB(),
					color.GetR(), color.GetG(), color.GetB());
			if (dist <= toleranceSqu) {
				UChar *pPixel = pScanner->GetPointer();
				*(pPixel + OffsetA) = a;
			}
		} while (pScanner->Next());
	}
}

Image *Image::ReduceColor(Signal &sig, const Palette *pPalette)
{
	AutoPtr<Image> pImage(CreateDerivation(sig, _width, _height,
										Palette::Reference(pPalette)));
	if (sig.IsSignalled()) return nullptr;
	std::unique_ptr<Scanner> pScannerSrc(CreateScanner());
	std::unique_ptr<Scanner> pScannerDst(pImage->CreateScanner());
	if (_format == FORMAT_RGBA) {
		do {
			size_t idx = pPalette->LookupNearest(pScannerSrc->GetPointer());
			StorePixelRGBA(pScannerDst->GetPointer(),
						pPalette->GetEntry(idx), pScannerSrc->GetA());
		} while (pScannerSrc->Next(*pScannerDst));
	} else {
		do {
			size_t idx = pPalette->LookupNearest(pScannerSrc->GetPointer());
			StorePixelRGB(pScannerDst->GetPointer(), pPalette->GetEntry(idx));
		} while (pScannerSrc->Next(*pScannerDst));
	}
	return pImage.release();
}

Image *Image::GrayScale(Signal &sig)
{
	AutoPtr<Image> pImage(CreateDerivation(sig, _width, _height));
	if (sig.IsSignalled()) return nullptr;
	std::unique_ptr<Scanner> pScannerSrc(CreateScanner());
	std::unique_ptr<Scanner> pScannerDst(pImage->CreateScanner());
	if (_format == FORMAT_RGBA) {
		do {
			UChar gray = GetPixelGray(pScannerSrc->GetPointer());
			pScannerDst->StorePixel(gray, gray, gray, pScannerSrc->GetA());
		} while (pScannerSrc->Next(*pScannerDst));
	} else {
		do {
			UChar gray = GetPixelGray(pScannerSrc->GetPointer());
			pScannerDst->StorePixel(gray, gray, gray);
		} while (pScannerSrc->Next(*pScannerDst));
	}
	return pImage.release();
}

Image *Image::MapColorLevel(Signal &sig, const UChar *mapR, const UChar *mapG, const UChar *mapB)
{
	AutoPtr<Image> pImage(CreateDerivation(sig, _width, _height));
	if (sig.IsSignalled()) return nullptr;
	std::unique_ptr<Scanner> pScannerSrc(CreateScanner());
	std::unique_ptr<Scanner> pScannerDst(pImage->CreateScanner());
	if (_format == FORMAT_RGBA) {
		do {
			UChar r = mapR[pScannerSrc->GetR()];
			UChar g = mapG[pScannerSrc->GetG()];
			UChar b = mapB[pScannerSrc->GetB()];
			pScannerDst->StorePixel(r, g, b, pScannerSrc->GetA());
		} while (pScannerSrc->Next(*pScannerDst));
	} else {
		do {
			UChar r = mapR[pScannerSrc->GetR()];
			UChar g = mapG[pScannerSrc->GetG()];
			UChar b = mapB[pScannerSrc->GetB()];
			pScannerDst->StorePixel(r, g, b);
		} while (pScannerSrc->Next(*pScannerDst));
	}
	return pImage.release();
}

Image *Image::Blur(Signal &sig, int radius, Number sigma)
{
	int diameter = radius * 2 + 1;
	AutoPtr<Image> pImage(CreateDerivation(sig, _width, _height));
	if (sig.IsSignalled()) return nullptr;
	int nKernels = diameter * diameter;
	Number *kernel = new Number[nKernels];
	Number factor = 2 * sigma * sigma;
	do {
		int iKernel = 0;
		for (int y = 0; y < diameter; y++) {
			for (int x = 0; x < diameter; x++) {
				Number distX = x - radius, distY = y - radius;
				Number elemKernel = ::exp(-(distX * distX + distY * distY) / factor);
				kernel[iKernel++] = elemKernel;
			}
		}
		Number sum = 0;
		Number *p = kernel;
		for (int iKernel = 0; iKernel < nKernels; iKernel++, p++) sum += *p;
		if (sum > 0) {
			Number *p = kernel;
			for (int iKernel = 0; iKernel < nKernels; iKernel++, p++) *p /= sum;
		}
#if 0
		do {
			int iKernel = 0;
			for (int y = 0; y < diameter; y++) {
				for (int x = 0; x < diameter; x++) {
					::printf("%10f", kernel[iKernel]);
					iKernel++;
				}
				::printf("\n");
			}
		} while (0);
#endif
	} while (0);
	//pImage->Fill(Color(255, 0, 0, 255));
	size_t width = GetWidth() - diameter, height = GetHeight() - diameter;
	std::unique_ptr<Scanner> pScannerSrc(CreateScanner(0, 0, width, height));
	std::unique_ptr<Scanner> pScannerDst(pImage->CreateScanner(radius, radius, width, height));
	std::unique_ptr<Scanner> pScanner(pImage->CreateScanner(0, 0, diameter, diameter));
	if (_format == FORMAT_RGBA) {
		//
		// image processing around border has not been implemented yet.
		//
		do {
			Number r = 0, g = 0, b = 0;
			UChar a = 255;
			Number *p = kernel;
			pScanner->SetPointer(pScannerSrc->GetPointer());
			pScanner->ResetIndex();
			do {
				r += *p * pScanner->GetR();
				g += *p * pScanner->GetG();
				b += *p * pScanner->GetB();
				p++;
			} while (pScanner->Next());
			pScannerDst->StorePixel(
					static_cast<UChar>(r),
					static_cast<UChar>(g),
					static_cast<UChar>(b), a);
		} while (pScannerSrc->Next(*pScannerDst));
	} else {
		do {
			Number r = 0, g = 0, b = 0;
			Number *p = kernel;
			pScanner->SetPointer(pScannerSrc->GetPointer());
			pScanner->ResetIndex();
			do {
				r += *p * pScanner->GetR();
				g += *p * pScanner->GetG();
				b += *p * pScanner->GetB();
				p++;
			} while (pScanner->Next());
			pScannerDst->StorePixel(
					static_cast<UChar>(r),
					static_cast<UChar>(g),
					static_cast<UChar>(b));
		} while (pScannerSrc->Next(*pScannerDst));
	}
	return pImage.release();
}

Image *Image::Flip(Signal &sig, bool horzFlag, bool vertFlag)
{
	AutoPtr<Image> pImage(CreateDerivation(sig, _width, _height));
	if (sig.IsSignalled()) return nullptr;
	if (horzFlag) {
		std::unique_ptr<Scanner> pScannerSrc(CreateScanner());
		std::unique_ptr<Scanner> pScannerDst(pImage->CreateScanner(
				vertFlag? SCAN_RightBottomHorz : SCAN_RightTopHorz));
		if (_format == FORMAT_RGBA) {
			do {
				StorePixelRGBA(pScannerDst->GetPointer(), pScannerSrc->GetPointer());
			} while (pScannerSrc->Next(*pScannerDst));
		} else {
			do {
				StorePixelRGB(pScannerDst->GetPointer(), pScannerSrc->GetPointer());
			} while (pScannerSrc->Next(*pScannerDst));
		}
	} else if (vertFlag) { // !horzFlag
		const UChar *pLineSrc = GetPointer(0);
		UChar *pLineDst = pImage->GetPointer(_height);
		size_t bytesPerLine = GetBytesPerLine();
		for (size_t y = 0; y < _height; y++) {
			pLineDst -= bytesPerLine;
			::memcpy(pLineDst, pLineSrc, bytesPerLine);
			pLineSrc += bytesPerLine;
		}
	}
	return pImage.release();
}

Image *Image::Rotate90(Signal &sig, bool clockwiseFlag)
{
	size_t width = _height, height = _width;
	AutoPtr<Image> pImage(CreateDerivation(sig, width, height));
	if (sig.IsSignalled()) return nullptr;
	std::unique_ptr<Scanner> pScannerSrc(CreateScanner());
	std::unique_ptr<Scanner> pScannerDst(pImage->CreateScanner(
			clockwiseFlag? SCAN_RightTopVert : SCAN_LeftBottomVert));
	if (_format == FORMAT_RGBA) {
		do {
			StorePixelRGBA(pScannerDst->GetPointer(), pScannerSrc->GetPointer());
		} while (pScannerSrc->Next(*pScannerDst));
	} else {
		do {
			StorePixelRGB(pScannerDst->GetPointer(), pScannerSrc->GetPointer());
		} while (pScannerSrc->Next(*pScannerDst));
	}
	return pImage.release();
}

Image *Image::Rotate(Signal &sig, double angle, const Color &color)
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
	double rad = DegToRad(angle);
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
	AutoPtr<Image> pImage(CreateDerivation(sig, width, height));
	if (sig.IsSignalled()) return nullptr;
	UChar *pLineDst = pImage->GetPointer(0);
	size_t bytesPerLineDst = pImage->GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	UChar buffBlank[8];
	PutPixel(buffBlank, color);
	for (int y = 0; y < height; y++) {
		UChar *pPixelDst = pLineDst;
		for (int x = 0; x < width; x++) {
			int xm, ym;
			RotateCoord(xm, ym, x - xCenterNew, y - yCenterNew, cos1024, sin1024);
			xm += xCenter, ym += yCenter;
			if (xm >= 0 && xm < static_cast<int>(_width) &&
								ym >= 0 && ym < static_cast<int>(_height)) {
				UChar *pPixelSrc = GetPointer(xm, ym);
				StorePixel(pPixelDst, pPixelSrc, _format == FORMAT_RGBA);
			} else {
				StorePixel(pPixelDst, buffBlank, _format == FORMAT_RGBA);
			}
			pPixelDst += bytesPerPixel;
		}
		pLineDst += bytesPerLineDst;
	}
	return pImage.release();
}

Image *Image::Crop(Signal &sig, size_t x, size_t y, size_t width, size_t height)
{
	AutoPtr<Image> pImage(CreateDerivation(sig, width, height));
	if (sig.IsSignalled()) return nullptr;
	const UChar *pLineSrc = GetPointer(x, y);
	UChar *pLineDst = pImage->GetPointer(0);
	size_t bytesPerLineSrc = GetBytesPerLine();
	size_t bytesPerLineDst = pImage->GetBytesPerLine();
	for (size_t y = 0; y < height; y++) {
		::memcpy(pLineDst, pLineSrc, bytesPerLineDst);
		pLineSrc += bytesPerLineSrc;
		pLineDst += bytesPerLineDst;
	}
	return pImage.release();
}

Image *Image::Resize(Signal &sig, size_t width, size_t height)
{
	AutoPtr<Image> pImage(CreateDerivation(sig, width, height));
	if (sig.IsSignalled()) return nullptr;
	const UChar *pLineSrc = GetPointer(0);
	UChar *pLineDst = pImage->GetPointer(0);
	size_t bytesPerPixel = GetBytesPerPixel();
	size_t bytesPerLineSrc = GetBytesPerLine();
	size_t bytesPerLineDst = pImage->GetBytesPerLine();
	size_t accumsSize = width * sizeof(Accum);
	AutoPtr<Memory> pMemory(new MemoryHeap(accumsSize));
	Accum *accums = reinterpret_cast<Accum *>(pMemory->GetPointer());
	::memset(accums, 0x00, accumsSize);
	size_t numerY = 0;
	if (_format == FORMAT_RGB) {
		size_t yDst = 0;
		for (size_t ySrc = 0; ySrc <= _height; ySrc++) {
			if (ySrc < _height) {
				const UChar *pPixelSrc = pLineSrc;
				Accum *pAccum = accums;
				size_t xDst = 0;
				size_t numerX = 0;
				for (size_t xSrc = 0; xSrc < _width; xSrc++) {
					pAccum->AddRGB(pPixelSrc);
					pPixelSrc += bytesPerPixel;
					numerX += width;
					for ( ; numerX >= _width && xDst < width; numerX -= _width, xDst++) {
						pAccum++;
					}
				}
				pLineSrc += bytesPerLineSrc;
			}
			numerY += height;
			if (numerY >= _height) {
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
						pAccum->r >>= 1;
						pAccum->g >>= 1;
						pAccum->b >>= 1;
						pAccumPrev = pAccum;
					} else if (cnt == 4) {
						pAccum->r >>= 2;
						pAccum->g >>= 2;
						pAccum->b >>= 2;
						pAccumPrev = pAccum;
					} else {
						pAccum->r /= cnt;
						pAccum->g /= cnt;
						pAccum->b /= cnt;
						pAccumPrev = pAccum;
					}
				}
				for ( ; numerY >= _height && yDst < height; numerY -= _height, yDst++) {
					Accum *pAccum = accums;
					UChar *pPixelDst = pLineDst;
					for (size_t xDst = 0; xDst < width;
									xDst++, pAccum++, pPixelDst += bytesPerPixel) {
						pAccum->StoreRGB(pPixelDst);
					}
					pLineDst += bytesPerLineDst;
				}
				::memset(accums, 0x00, accumsSize);
			}
		}
	} else if (_format == FORMAT_RGBA) {
		size_t yDst = 0;
		for (size_t ySrc = 0; ySrc <= _height; ySrc++) {
			if (ySrc < _height) {
				const UChar *pPixelSrc = pLineSrc;
				Accum *pAccum = accums;
				size_t xDst = 0;
				size_t numerX = 0;
				for (size_t xSrc = 0; xSrc < _width; xSrc++) {
					pAccum->AddRGBA(pPixelSrc);
					pPixelSrc += bytesPerPixel;
					numerX += width;
					for ( ; numerX >= _width && xDst < width; numerX -= _width, xDst++) {
						pAccum++;
					}
				}
				pLineSrc += bytesPerLineSrc;
			}
			numerY += height;
			if (numerY >= _height) {
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
						pAccum->r >>= 1;
						pAccum->g >>= 1;
						pAccum->b >>= 1;
						pAccum->a >>= 1;
						pAccumPrev = pAccum;
					} else if (cnt == 4) {
						pAccum->r >>= 2;
						pAccum->g >>= 2;
						pAccum->b >>= 2;
						pAccum->a >>= 2;
						pAccumPrev = pAccum;
					} else {
						pAccum->r /= cnt;
						pAccum->g /= cnt;
						pAccum->b /= cnt;
						pAccum->a /= cnt;
						pAccumPrev = pAccum;
					}
				}
				for ( ; numerY >= _height && yDst < height; numerY -= _height, yDst++) {
					Accum *pAccum = accums;
					UChar *pPixelDst = pLineDst;
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
	return pImage.release();
}

void Image::Paste(size_t x, size_t y, Image *pImage,
	size_t width, size_t height, size_t xOffset, size_t yOffset, UChar a)
{
	const UChar *pLineSrc = pImage->GetPointer(xOffset, yOffset);
	UChar *pLineDst = GetPointer(x, y);
	size_t bytesPerLineSrc = pImage->GetBytesPerLine();
	size_t bytesPerLineDst = GetBytesPerLine();
	if (_format == pImage->GetFormat()) {
		size_t bytesToCopy = width * GetBytesPerPixel();
		for (size_t y = 0; y < height; y++) {
			::memcpy(pLineDst, pLineSrc, bytesToCopy);
			pLineSrc += bytesPerLineSrc;
			pLineDst += bytesPerLineDst;
		}
	} else if (_format == FORMAT_RGB && pImage->GetFormat() == FORMAT_RGBA) {
		for (size_t y = 0; y < height; y++) {
			const UChar *pPixelSrc = pLineSrc;
			UChar *pPixelDst = pLineDst;
			for (size_t x = 0; x < width; x++) {
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = *pPixelSrc++;
				pPixelSrc++;
			}
			pLineSrc += bytesPerLineSrc;
			pLineDst += bytesPerLineDst;
		}
	} else if (_format == FORMAT_RGBA && pImage->GetFormat() == FORMAT_RGB) {
		for (size_t y = 0; y < height; y++) {
			const UChar *pPixelSrc = pLineSrc;
			UChar *pPixelDst = pLineDst;
			for (size_t x = 0; x < width; x++) {
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = *pPixelSrc++;
				*pPixelDst++ = a;
			}
			pLineSrc += bytesPerLineSrc;
			pLineDst += bytesPerLineDst;
		}
	}
}

Palette *Image::CreateEmptyPalette(Environment &env, size_t nEntries)
{
	_pPalette.reset(new Palette());
	_pPalette->AllocBuff(nEntries);
	return _pPalette.get();
}

void Image::SetPalette(Palette *pPalette)
{
	_pPalette.reset(pPalette);
}

bool Image::Read(Environment &env, Stream &stream, const char *imageType)
{
	Signal &sig = env.GetSignal();
	ImageStreamer *pImageStreamer = nullptr;
	pImageStreamer = ImageStreamer::FindResponsible(sig, stream, imageType);
	if (sig.IsSignalled()) return false;
	if (pImageStreamer == nullptr) {
		sig.SetError(ERR_FormatError, "unsupported image type");
		return false;
	}
	return pImageStreamer->Read(env, this, stream);
}

bool Image::Write(Environment &env, Stream &stream, const char *imageType)
{
	Signal &sig = env.GetSignal();
	ImageStreamer *pImageStreamer = nullptr;
	pImageStreamer = ImageStreamer::FindResponsible(sig, stream, imageType);
	if (sig.IsSignalled()) return false;
	if (pImageStreamer == nullptr) {
		sig.SetError(ERR_FormatError, "unsupported image type");
		return false;
	}
	return pImageStreamer->Write(env, this, stream);
}

int Image::CalcDIBBitCount() const
{
	if (GetPalette() == nullptr) return static_cast<int>(GetBitsPerPixel());
	size_t nEntries = GetPalette()->CountEntries();
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

bool Image::ReadDIBPalette(Environment &env, Stream &stream, int biBitCount)
{
	Signal &sig = env.GetSignal();
	if (biBitCount == 24 || biBitCount == 32) return true;
	if (!(biBitCount == 1 || biBitCount == 4 || biBitCount == 8)) {
		sig.SetError(ERR_FormatError, "unsupported pixel depth %d", biBitCount);
		return false;
	}
	size_t nEntries = 1 << biBitCount;
	CreateEmptyPalette(env, nEntries);
	for (size_t idx = 0; idx < nEntries; idx++) {
		UChar buff[4];
		if (stream.Read(sig, buff, 4) < 4) {
			sig.SetError(ERR_FormatError, "failed to read DIB palette");
			return false;
		}
		_pPalette->SetEntry(idx, buff[2], buff[1], buff[0]);
	}
	return true;
}

bool Image::WriteDIBPalette(Environment &env, Stream &stream, int biBitCount)
{
	Signal &sig = env.GetSignal();
	if (biBitCount == 24 || biBitCount == 32) return true;
	if (!(biBitCount == 1 || biBitCount == 4 || biBitCount == 8)) {
		sig.SetError(ERR_FormatError, "unsupported pixel depth %d", biBitCount);
		return false;
	}
	size_t nEntries = 1 << biBitCount;
	if (_pPalette.IsNull()) {
		_pPalette.reset(new Palette());
		if (biBitCount == 1) {
			_pPalette->Prepare(sig, Gura_Symbol(mono));
		} else if (biBitCount == 4) {
			_pPalette->Prepare(sig, Gura_Symbol(basic));
		} else { // biBitCount == 8
			_pPalette->Prepare(sig, Gura_Symbol(win256));
		}
		if (sig.IsSignalled()) return false;
	}
	size_t idx = 0;
	size_t idxMax = ChooseMin(nEntries, _pPalette->CountEntries());
	UChar buff[4];
	for ( ; idx < idxMax; idx++) {
		const UChar *pEntry = _pPalette->GetEntry(idx);
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

bool Image::ReadDIB(Signal &sig, Stream &stream,
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
		UChar ch;
		int iLine = 0, iPixel = 0;
		int bytesPitch = static_cast<int>(GetBytesPerLine());
		if (vertRevFlag) bytesPitch = -bytesPitch;
		UChar *pLine = GetPointer(vertRevFlag? biHeight - 1 : 0);
		UChar *pPixel = pLine;
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
			UChar idx = ch >> 7;
			ch <<= 1, bitsRest--;
			StorePixelRGB(pPixel, _pPalette->GetEntry(idx));
			pPixel += GetBytesPerPixel();
			iPixel++;
		}
		if (sig.IsSignalled()) return false;
	} else if (biBitCount == 4) {
		size_t bytesPerLine = (biWidth + 1) / 2;
		size_t bytesAlign = (bytesPerLine + 3) / 4 * 4 - bytesPerLine;
		UChar ch;
		std::unique_ptr<Scanner> pScanner(CreateScanner(
				vertRevFlag? SCAN_LeftBottomHorz : SCAN_LeftTopHorz));
		if (stream.Read(sig, &ch, 1) < 1) return false;
		int bitsRest = 8;
		for (;;) {
			UChar idx = ch >> 4;
			ch <<= 4, bitsRest -= 4;
			StorePixelRGB(pScanner->GetPointer(), _pPalette->GetEntry(idx));
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
		UChar ch;
		std::unique_ptr<Scanner> pScanner(CreateScanner(
				vertRevFlag? SCAN_LeftBottomHorz : SCAN_LeftTopHorz));
		if (stream.Read(sig, &ch, 1) < 1) return false;
		for (;;) {
			StorePixelRGB(pScanner->GetPointer(), _pPalette->GetEntry(ch));
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
		UChar buff[3];
		std::unique_ptr<Scanner> pScanner(CreateScanner(
				vertRevFlag? SCAN_LeftBottomHorz : SCAN_LeftTopHorz));
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
		UChar buff[4];
		std::unique_ptr<Scanner> pScanner(CreateScanner(
				vertRevFlag? SCAN_LeftBottomHorz : SCAN_LeftTopHorz));
		if (_format == FORMAT_RGBA) {
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
		if (GetFormat() == FORMAT_RGBA) {
			// read AND bitmap
			int bitsRest = 0;
			UChar ch;
			int iLine = 0, iPixel = 0;
			int bytesPitch = static_cast<int>(GetBytesPerLine());
			if (vertRevFlag) bytesPitch = -bytesPitch;
			UChar *pLine = GetPointer(vertRevFlag? biHeight - 1 : 0);
			UChar *pPixel = pLine;
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
				UChar idx = ch >> 7;
				ch <<= 1, bitsRest--;
				pPixel[OffsetA] = idx? 0 : 255;
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

bool Image::WriteDIB(Signal &sig, Stream &stream, int biBitCount, bool maskFlag)
{
	int biWidth = static_cast<int>(GetWidth());
	//int biHeight = static_cast<int>(GetHeight());
	if (biBitCount == 1) {
		if (_pPalette.IsNull()) return false;
		size_t bytesPerLine = (biWidth + 7) / 8;
		size_t bytesAlign = (bytesPerLine + 3) / 4 * 4 - bytesPerLine;
		int bitsAccum = 0;
		UChar chAccum = 0x00;
		std::unique_ptr<Scanner> pScanner(CreateScanner(SCAN_LeftBottomHorz));
		for (;;) {
			UChar ch = static_cast<UChar>(
							_pPalette->LookupNearest(pScanner->GetPointer()));
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
		if (_pPalette.IsNull()) return false;
		size_t bytesPerLine = (biWidth + 1) / 2;
		size_t bytesAlign = (bytesPerLine + 3) / 4 * 4 - bytesPerLine;
		int bitsAccum = 0;
		UChar chAccum = 0x00;
		std::unique_ptr<Scanner> pScanner(CreateScanner(SCAN_LeftBottomHorz));
		for (;;) {
			UChar ch = static_cast<UChar>(
							_pPalette->LookupNearest(pScanner->GetPointer()));
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
		if (_pPalette.IsNull()) return false;
		size_t bytesAlign = (biWidth + 3) / 4 * 4 - biWidth;
		std::unique_ptr<Scanner> pScanner(CreateScanner(SCAN_LeftBottomHorz));
		for (;;) {
			UChar ch = static_cast<UChar>(
							_pPalette->LookupNearest(pScanner->GetPointer()));
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
		UChar buff[3];
		std::unique_ptr<Scanner> pScanner(CreateScanner(SCAN_LeftBottomHorz));
		for (;;) {
			buff[0] = pScanner->GetB();
			buff[1] = pScanner->GetG();
			buff[2] = pScanner->GetR();
			stream.Write(sig, buff, 3);
			if (sig.IsSignalled()) return false;
			if (!pScanner->NextPixel()) {
				stream.Write(sig, "\x00\x00\x00\x00", bytesAlign);
				if (sig.IsSignalled()) return false;
				if (!pScanner->NextLine()) break;
			}
		}
	} else if (biBitCount == 32) {
		UChar buff[4];
		std::unique_ptr<Scanner> pScanner(CreateScanner(SCAN_LeftBottomHorz));
		for (;;) {
			buff[0] = pScanner->GetB();
			buff[1] = pScanner->GetG();
			buff[2] = pScanner->GetR();
			buff[3] = pScanner->GetA();
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
		if (GetFormat() == FORMAT_RGBA) {
			// write AND bitmap
			int bitsAccum = 0;
			UChar chAccum = 0x00;
			std::unique_ptr<Scanner> pScanner(CreateScanner(SCAN_LeftBottomHorz));
			for (;;) {
				UChar ch = (pScanner->GetA() < 128)? 1 : 0;
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
	case SCAN_LeftTopHorz:
		_pPixel = _pImage->GetPointer(x, y);
		_nPixels = width, _nLines = height;
		_pitchPixel = bytesPerPixel;
		_pitchLine = bytesPerLine - bytesPerPixel * static_cast<int>(width);
		break;
	case SCAN_LeftTopVert:
		_pPixel = _pImage->GetPointer(x, y);
		_nPixels = height, _nLines = width;
		_pitchPixel = bytesPerLine;
		_pitchLine = bytesPerPixel - bytesPerLine * static_cast<int>(height);
		break;
	case SCAN_RightTopHorz:
		_pPixel = _pImage->GetPointer(x + width - 1, y);
		_nPixels = width, _nLines = height;
		_pitchPixel = -bytesPerPixel;
		_pitchLine = bytesPerLine + bytesPerPixel * static_cast<int>(width);
		break;
	case SCAN_RightTopVert:
		_pPixel = _pImage->GetPointer(x + width - 1, y);
		_nPixels = height, _nLines = width;
		_pitchPixel = bytesPerLine;
		_pitchLine = -bytesPerPixel - bytesPerLine * static_cast<int>(height);
		break;
	case SCAN_LeftBottomHorz:
		_pPixel = _pImage->GetPointer(x, y + height - 1);
		_nPixels = width, _nLines = height;
		_pitchPixel = bytesPerPixel;
		_pitchLine = -bytesPerLine - bytesPerPixel * static_cast<int>(width);
		break;
	case SCAN_LeftBottomVert:
		_pPixel = _pImage->GetPointer(x, y + height - 1);
		_nPixels = height, _nLines = width;
		_pitchPixel = -bytesPerLine;
		_pitchLine = bytesPerPixel + bytesPerLine * static_cast<int>(height);
		break;
	case SCAN_RightBottomHorz:
		_pPixel = _pImage->GetPointer(x + width - 1, y + height - 1);
		_nPixels = width, _nLines = height;
		_pitchPixel = -bytesPerPixel;
		_pitchLine = -bytesPerLine + bytesPerPixel * static_cast<int>(width);
		break;
	case SCAN_RightBottomVert:
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
// Image::IteratorScan
//-----------------------------------------------------------------------------
Iterator *Image::IteratorScan::GetSource()
{
	return nullptr;
}

bool Image::IteratorScan::DoNext(Environment &env, Value &value)
{
	Image *pImage = _scanner.GetImage();
	if (_doneFlag) return false;
	UChar r = _scanner.GetR();
	UChar g = _scanner.GetG();
	UChar b = _scanner.GetB();
	UChar a = (pImage->GetFormat() == FORMAT_RGBA)? _scanner.GetA() : 0xff;
	value = Value(new Object_color(env, r, g, b, a));
	_doneFlag = !_scanner.Next();
	return true;
}

String Image::IteratorScan::ToString() const
{
	return String("image#scan");
}

void Image::IteratorScan::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// ImageStreamer
//-----------------------------------------------------------------------------
ImageStreamer::List *ImageStreamer::_pList = nullptr;
void ImageStreamer::Register(ImageStreamer *pImageStreamer)
{
	if (_pList == nullptr) _pList = new List();
	_pList->push_back(pImageStreamer);
}

ImageStreamer *ImageStreamer::FindResponsible(Signal &sig, Stream &stream, const char *imageType)
{
	if (_pList == nullptr) return nullptr;
	if (imageType != nullptr) return FindByImageType(imageType);
	foreach (List, ppImageStreamer, *_pList) {
		ImageStreamer *pImageStreamer = *ppImageStreamer;
		if (pImageStreamer->IsResponsible(sig, stream)) return pImageStreamer;
		if (sig.IsSignalled()) break;
	}
	return nullptr;
}

ImageStreamer *ImageStreamer::FindByImageType(const char *imageType)
{
	if (_pList == nullptr) return nullptr;
	foreach (List, ppImageStreamer, *_pList) {
		ImageStreamer *pImageStreamer = *ppImageStreamer;
		if (::strcasecmp(pImageStreamer->GetImageType(), imageType) == 0) {
			return pImageStreamer;
		}
	}
	return nullptr;
}

}
