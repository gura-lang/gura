// Object_image

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_image (common)
//-----------------------------------------------------------------------------
bool Object_image::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(width));
	symbols.insert(Gura_Symbol(height));
	symbols.insert(Gura_Symbol(palette));
	return true;
}

Value Object_image::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(FormatToSymbol(_format));
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		return Value(static_cast<unsigned int>(_width));
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		return Value(static_cast<unsigned int>(_height));
	} else if (pSymbol->IsIdentical(Gura_Symbol(palette))) {
		if (_pObjPalette.IsNull()) return Value::Null;
		return Value(Object_palette::Reference(_pObjPalette.get()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_image::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(palette))) {
		if (value.IsPalette()) {
			_pObjPalette.reset(Object_palette::Reference(Object_palette::GetObject(value)));
			return Value(Object_palette::Reference(_pObjPalette.get()));
		} else if (value.IsInvalid()) {
			_pObjPalette.reset(NULL);
			return Value::Null;
		} else {
			sig.SetError(ERR_ValueError, "palette object must be specified");
			return Value::Null;
		}
	}
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_image::ToString(Signal sig, bool exprFlag)
{
	String rtn;
	rtn = "<image:";
	rtn += FormatToSymbol(_format)->GetName();
	rtn += ":";
	if (IsValid()) {
		char buff[64];
		::sprintf(buff, "%dx%d",
				static_cast<int>(GetWidth()), static_cast<int>(GetHeight()));
		rtn += buff;
	} else {
		rtn += "invalid";
	}
	rtn += ">";
	return rtn;
}

bool Object_image::CheckEmpty(Signal sig) const
{
	if (!IsValid()) return true;
	sig.SetError(ERR_ValueError, "image has already been initialized with a buffer");
	return false;
}

bool Object_image::CheckValid(Signal sig) const
{
	if (IsValid()) return true;
	sig.SetError(ERR_ValueError, "image does not have a buffer");
	return false;
}

size_t Object_image::SymbolToPixelOffset(Signal sig, const Symbol *pSymbol) const
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

Image::Format Object_image::SymbolToFormat(Signal sig, const Symbol *pSymbol)
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

const Symbol *Object_image::FormatToSymbol(Image::Format format)
{
	if (format == Image::FORMAT_RGB) {
		return Gura_Symbol(rgb);
	} else if (format == Image::FORMAT_RGBA) {
		return Gura_Symbol(rgba);
	} else {
		return Gura_Symbol(nil);
	}
}

void Object_image::InitMetrics()
{
	_metrics.bitsPerPixel =
			(_format == Image::FORMAT_RGB)? 24 :
			(_format == Image::FORMAT_RGBA)? 32 : 0;
	_metrics.bytesPerPixel = _metrics.bitsPerPixel / 8;
	_metrics.bytesPerLine =
			(_format == Image::FORMAT_RGB)? ((_width * 3 + 3) / 4) * 4 :
			(_format == Image::FORMAT_RGBA)? _width * 4 : 0;
}

Object_image *Object_image::CreateDerivation(Signal sig,
						size_t width, size_t height, Object_palette *pObjPalette)
{
	Environment &env = *this;
	Object_image *pObj = new Object_image(env, _format);
	if (!pObj->AllocBuffer(sig, width, height, 0x00)) {
		delete pObj;
		return NULL;
	}
	if (pObjPalette != NULL) {
		pObj->_pObjPalette.reset(pObjPalette);
	} else if (!_pObjPalette.IsNull()) {
		pObj->_pObjPalette.reset(Object_palette::Reference(_pObjPalette.get()));
	}
	return pObj;
}

bool Object_image::CheckCoord(Signal sig, size_t x, size_t y) const
{
	if (CheckCoord(static_cast<int>(x), static_cast<int>(y))) return true;
	sig.SetError(ERR_ValueError, "coordinate is out of range");
	return false;
}

bool Object_image::AdjustCoord(int &x, int &y, int &width, int &height) const
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

void Object_image::PutPixel(unsigned char *buff, const Object_color *pObjColor)
{
	if (_format == Image::FORMAT_RGB) {
		*(buff + Image::OffsetRed)		= pObjColor->GetRed();
		*(buff + Image::OffsetGreen)	= pObjColor->GetGreen();
		*(buff + Image::OffsetBlue)		= pObjColor->GetBlue();
	} else if (_format == Image::FORMAT_RGBA) {
		*(buff + Image::OffsetRed)		= pObjColor->GetRed();
		*(buff + Image::OffsetGreen)	= pObjColor->GetGreen();
		*(buff + Image::OffsetBlue)		= pObjColor->GetBlue();
		*(buff + Image::OffsetAlpha)	= pObjColor->GetAlpha();
	}
}

void Object_image::GetPixel(const unsigned char *buff, Object_color *pObjColor)
{
	if (_format == Image::FORMAT_RGB) {
		pObjColor->Set(GetPixelR(buff), GetPixelG(buff), GetPixelB(buff), 255);
	} else if (_format == Image::FORMAT_RGBA) {
		pObjColor->Set(GetPixelR(buff), GetPixelG(buff), GetPixelB(buff), GetPixelA(buff));
	}
}

bool Object_image::Store(Signal sig, size_t x, size_t y, size_t width, size_t height,
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

bool Object_image::Store(Signal sig, size_t x, size_t y, size_t width, size_t height,
					const Symbol *pSymbol, Iterator *pIterator)
{
	Environment &env = *this;
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

bool Object_image::Extract(Signal sig, size_t x, size_t y, size_t width, size_t height,
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

bool Object_image::Extract(Signal sig, size_t x, size_t y, size_t width, size_t height,
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

void Object_image::ReplaceColorRect(size_t x, size_t y, size_t width, size_t height,
				const Object_color *pObjColorOrg, const Object_color *pObjColor)
{
	std::auto_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	unsigned char buffOrg[8], buff[8];
	PutPixel(buffOrg, pObjColorOrg);
	PutPixel(buff, pObjColor);
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

void Object_image::FillRect(size_t x, size_t y, size_t width, size_t height,
												const Object_color *pObjColor)
{
	unsigned char buff[8];
	PutPixel(buff, pObjColor);
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

void Object_image::FillRectAlpha(size_t x, size_t y, size_t width, size_t height,
							unsigned char alpha, const Object_color *pObjColor)
{
	std::auto_ptr<Scanner> pScanner(CreateScanner(x, y, width, height));
	if (pObjColor == NULL) {
		do {
			unsigned char *pPixel = pScanner->GetPointer();
			*(pPixel + Image::OffsetAlpha) = alpha;
		} while (pScanner->Next());
	} else {
		unsigned char buff[8];
		PutPixel(buff, pObjColor);
		do {
			unsigned char *pPixel = pScanner->GetPointer();
			if (::memcmp(pPixel, buff, 3) == 0) {
				*(pPixel + Image::OffsetAlpha) = alpha;
			}
		} while (pScanner->Next());
	}
}

Object_image *Object_image::ReduceColor(Signal sig, const Object_palette *pObjPalette)
{
	Object_image *pObj = CreateDerivation(sig, _width, _height,
										Object_palette::Reference(pObjPalette));
	if (sig.IsSignalled()) return NULL;
	std::auto_ptr<Scanner> pScannerSrc(CreateScanner());
	std::auto_ptr<Scanner> pScannerDst(pObj->CreateScanner());
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
	return pObj;
}

Object_image *Object_image::GrayScale(Signal sig)
{
	Object_image *pObj = CreateDerivation(sig, _width, _height);
	if (sig.IsSignalled()) return NULL;
	std::auto_ptr<Scanner> pScannerSrc(CreateScanner());
	std::auto_ptr<Scanner> pScannerDst(pObj->CreateScanner());
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
	return pObj;
}

Object_image *Object_image::Blur(Signal sig, int radius)
{
	//int kernel[17];
	
	return NULL;
}

Object_image *Object_image::Flip(Signal sig, bool horzFlag, bool vertFlag)
{
	Object_image *pObj = CreateDerivation(sig, _width, _height);
	if (sig.IsSignalled()) return NULL;
	if (horzFlag) {
		std::auto_ptr<Scanner> pScannerSrc(CreateScanner());
		std::auto_ptr<Scanner> pScannerDst(pObj->CreateScanner(
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
		unsigned char *pLineDst = pObj->GetPointer(_height);
		size_t bytesPerLine = GetBytesPerLine();
		for (size_t y = 0; y < _height; y++) {
			pLineDst -= bytesPerLine;
			::memcpy(pLineDst, pLineSrc, bytesPerLine);
			pLineSrc += bytesPerLine;
		}
	}
	return pObj;
}

Object_image *Object_image::Rotate90(Signal sig, bool clockwiseFlag)
{
	size_t width = _height, height = _width;
	Object_image *pObj = CreateDerivation(sig, width, height);
	if (sig.IsSignalled()) return NULL;
	std::auto_ptr<Scanner> pScannerSrc(CreateScanner());
	std::auto_ptr<Scanner> pScannerDst(pObj->CreateScanner(
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
	return pObj;
}

Object_image *Object_image::Rotate(Signal sig,
							double angle, const Object_color *pObjColor)
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
	Object_image *pObj = CreateDerivation(sig, width, height);
	if (sig.IsSignalled()) return NULL;
	unsigned char *pLineDst = pObj->GetPointer(0);
	size_t bytesPerLineDst = pObj->GetBytesPerLine();
	size_t bytesPerPixel = GetBytesPerPixel();
	unsigned char buffBlank[8];
	PutPixel(buffBlank, pObjColor);
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
	return pObj;
}

Object_image *Object_image::Crop(Signal sig, size_t x, size_t y, size_t width, size_t height)
{
	Object_image *pObj = CreateDerivation(sig, width, height);
	if (sig.IsSignalled()) return NULL;
	const unsigned char *pLineSrc = GetPointer(x, y);
	unsigned char *pLineDst = pObj->GetPointer(0);
	size_t bytesPerLineSrc = GetBytesPerLine();
	size_t bytesPerLineDst = pObj->GetBytesPerLine();
	for (size_t y = 0; y < height; y++) {
		::memcpy(pLineDst, pLineSrc, bytesPerLineDst);
		pLineSrc += bytesPerLineSrc;
		pLineDst += bytesPerLineDst;
	}
	return pObj;
}


Object_image *Object_image::Resize(Signal sig, size_t width, size_t height)
{
	Object_image *pObj = CreateDerivation(sig, width, height);
	if (sig.IsSignalled()) return NULL;
	const unsigned char *pLineSrc = GetPointer(0);
	unsigned char *pLineDst = pObj->GetPointer(0);
	size_t bytesPerPixel = GetBytesPerPixel();
	size_t bytesPerLineSrc = GetBytesPerLine();
	size_t bytesPerLineDst = pObj->GetBytesPerLine();
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
	return pObj;
}

void Object_image::Paste(size_t x, size_t y, Object_image *pObjImg,
	size_t width, size_t height, size_t xOffset, size_t yOffset, unsigned char alpha)
{
	const unsigned char *pLineSrc = pObjImg->GetPointer(xOffset, yOffset);
	unsigned char *pLineDst = GetPointer(x, y);
	size_t bytesPerLineSrc = pObjImg->GetBytesPerLine();
	size_t bytesPerLineDst = GetBytesPerLine();
	if (_format == pObjImg->GetFormat()) {
		size_t bytesToCopy = width * GetBytesPerPixel();
		for (size_t y = 0; y < height; y++) {
			::memcpy(pLineDst, pLineSrc, bytesToCopy);
			pLineSrc += bytesPerLineSrc;
			pLineDst += bytesPerLineDst;
		}
	} else if (_format == Image::FORMAT_RGB && pObjImg->GetFormat() == Image::FORMAT_RGBA) {
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
	} else if (_format == Image::FORMAT_RGBA && pObjImg->GetFormat() == Image::FORMAT_RGB) {
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

Object_palette *Object_image::CreateEmptyPalette(size_t nEntries)
{
	_pObjPalette.reset(new Object_palette(*this, nEntries));
	return _pObjPalette.get();
}

void Object_image::SetPaletteObj(Object_palette *pObjPalette)
{
	_pObjPalette.reset(pObjPalette);
}

bool Object_image::Read(Signal sig, Stream &stream, const char *imgType)
{
	Environment &env = *this;
	ImageStreamer *pImageStreamer = NULL;
	pImageStreamer = ImageStreamer::FindResponsible(sig, stream, imgType);
	if (sig.IsSignalled()) return false;
	if (pImageStreamer == NULL) {
		sig.SetError(ERR_FormatError, "unsupported image type");
		return false;
	}
	return pImageStreamer->Read(env, sig, this, stream);
}

bool Object_image::Write(Signal sig, Stream &stream, const char *imgType)
{
	Environment &env = *this;
	ImageStreamer *pImageStreamer = NULL;
	pImageStreamer = ImageStreamer::FindResponsible(sig, stream, imgType);
	if (sig.IsSignalled()) return false;
	if (pImageStreamer == NULL) {
		sig.SetError(ERR_FormatError, "unsupported image type");
		return false;
	}
	return pImageStreamer->Write(env, sig, this, stream);
}

int Object_image::CalcDIBBitCount() const
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

size_t Object_image::CalcDIBImageSize(int biBitCount, bool maskFlag) const
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

bool Object_image::ReadDIBPalette(Signal sig, Stream &stream, int biBitCount)
{
	if (biBitCount == 24 || biBitCount == 32) return true;
	if (!(biBitCount == 1 || biBitCount == 4 || biBitCount == 8)) {
		sig.SetError(ERR_FormatError, "unsupported pixel depth %d", biBitCount);
		return false;
	}
	size_t nEntries = 1 << biBitCount;
	CreateEmptyPalette(nEntries);
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

bool Object_image::WriteDIBPalette(Signal sig, Stream &stream, int biBitCount)
{
	Environment &env = *this;
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

bool Object_image::ReadDIB(Signal sig, Stream &stream,
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

bool Object_image::WriteDIB(Signal sig, Stream &stream, int biBitCount, bool maskFlag)
{
	Environment &env = *this;
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

void Object_image::SetBuffer(size_t width, size_t height, unsigned char *buff,
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
// Object_image (Windows DIB section)
//-----------------------------------------------------------------------------
Object_image::Object_image(Environment &env, Image::Format format) :
		Object(env.LookupClass(VTYPE_image)),
		_format(format), _width(0), _height(0), _buff(NULL),
		_hBmp(NULL), _pObjPalette(NULL)
{
	InitMetrics();
}

Object_image::Object_image(Class *pClass, Image::Format format) :
		Object(pClass),
		_format(format), _width(0), _height(0), _buff(NULL),
		_hBmp(NULL), _pObjPalette(NULL)
{
	InitMetrics();
}

Object_image::Object_image(const Object_image &obj) : Object(obj),
		_format(obj._format), _width(0), _height(0), _buff(NULL),
		_hBmp(NULL), _pObjPalette(Object_palette::Reference(obj._pObjPalette.get()))
{
	Signal sig;
	if (AllocBuffer(sig, obj._width, obj._height, 0x00)) {
		::memcpy(_buff, obj._buff, GetBufferSize());
	}
}

Object_image::~Object_image()
{
	FreeBuffer();
}

Object *Object_image::Clone() const
{
	return new Object_image(*this);
}

bool Object_image::AllocBuffer(Signal sig,
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

void Object_image::FreeBuffer()
{
	if (_hBmp != NULL) ::DeleteObject(_hBmp);
	_width = 0, _height = 0;
	_buff = NULL;
	_hBmp = NULL;
}
#else // GURA_USE_MSWIN_DIB
//-----------------------------------------------------------------------------
// Object_image (on memory)
//-----------------------------------------------------------------------------
Object_image::Object_image(Environment &env, Image::Format format) :
		Object(env.LookupClass(VTYPE_image)),
		_format(format), _width(0), _height(0), _buff(NULL), _pObjPalette(NULL)
{
	InitMetrics();
}

Object_image::Object_image(Class *pClass, Image::Format format) :
		Object(pClass),
		_format(format), _width(0), _height(0), _buff(NULL), _pObjPalette(NULL)
{
	InitMetrics();
}

Object_image::Object_image(const Object_image &obj) : Object(obj),
		_format(obj._format), _width(0), _height(0), _buff(NULL),
		_pObjPalette(Object_palette::Reference(obj._pObjPalette.get()))
{
	Signal sig;
	if (AllocBuffer(sig, obj._width, obj._height, 0x00)) {
		::memcpy(_buff, obj._buff, GetBufferSize());
	}
}

Object_image::~Object_image()
{
	FreeBuffer();
}

Object *Object_image::Clone() const
{
	return new Object_image(*this);
}

bool Object_image::AllocBuffer(Signal sig,
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

void Object_image::FreeBuffer()
{
	_memory.Free();
	_width = 0, _height = 0;
	_buff = NULL;
}
#endif

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// image(args+):map {block?}
Gura_DeclareFunction(image)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "args", VTYPE_any, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_image));
	AddHelp(Gura_Symbol(en), 
	"Returns an image object with specified characteristics. There are three patterns\n"
	"to call the function as follows.\n"
	"- image(stream:stream, format?:symbol, imgtype?:string)\n"
	"- image(format:symbol)\n"
	"- image(format:symbol, width:number, height:number, color?:color)\n"
	"In the first pattern, it creates an empty image with a specified format.\n"
	"The second reads image data from the stream and expand it in the buffer.\n"
	"The last allocates an image buffer of specified size and fills it with the color.\n"
	"Parameter format specifies the internal format. Available formats are `rgb and `rgba.");
}

Gura_ImplementFunction(image)
{
	if (sig.IsSignalled()) return Value::Null;
	ValueList valList = args.GetList(0);
	Object_image *pObj = NULL;
	if (valList[0].IsSymbol()) {
		Declaration(Gura_Symbol(format), VTYPE_symbol).
									ValidateAndCast(env, sig, valList[0]);
		if (sig.IsSignalled()) return Value::Null;
		Image::Format format =
					Object_image::SymbolToFormat(sig, valList[0].GetSymbol());
		if (sig.IsSignalled()) return Value::Null;
		pObj = new Object_image(env, format);
		if (valList.size() >= 2) {
			Declaration(Gura_Symbol(width), VTYPE_number).
										ValidateAndCast(env, sig, valList[1]);
			if (sig.IsSignalled()) return Value::Null;
			size_t width = valList[1].GetSizeT();
			size_t height = width;
			if (valList.size() >= 3) {
				Declaration(Gura_Symbol(height), VTYPE_number).
											ValidateAndCast(env, sig, valList[2]);
				if (sig.IsSignalled()) return Value::Null;
				height = valList[2].GetSizeT();
			}
			if (!pObj->AllocBuffer(sig, width, height, 0x00)) {
				delete pObj;
				return Value::Null;
			}
			if (valList.size() >= 4) {
				Declaration(Gura_Symbol(color), VTYPE_color).
										ValidateAndCast(env, sig, valList[3]);
				if (sig.IsSignalled()) return Value::Null;
				pObj->Fill(Object_color::GetObject(valList[3]));
			}
		}
	} else {
		Declaration(Gura_Symbol(stream), VTYPE_stream, OCCUR_Once, FLAG_Read, NULL).
									ValidateAndCast(env, sig, valList[0]);
		if (sig.IsSignalled()) return Value::Null;
		Stream &stream = valList[0].GetStream();
		Image::Format format = Image::FORMAT_RGBA;
		if (valList.size() >= 2) {
			Declaration(Gura_Symbol(format), VTYPE_symbol).
									ValidateAndCast(env, sig, valList[1]);
			if (sig.IsSignalled()) return Value::Null;
			format = Object_image::SymbolToFormat(sig, valList[1].GetSymbol());
			if (sig.IsSignalled()) return Value::Null;
		}
		pObj = new Object_image(env, format);
		const char *imgType = NULL;
		if (valList.size() >= 3) {
			Declaration(Gura_Symbol(imgtype), VTYPE_string).
									ValidateAndCast(env, sig, valList[2]);
			if (sig.IsSignalled()) return Value::Null;
			imgType = valList[2].GetString();
		}
		if (!pObj->Read(sig, stream, imgType)) return Value::Null;
	}
	Value result(pObj);
	return ReturnValue(env, sig, args, result);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
//-----------------------------------------------------------------------------
// image#size()
Gura_DeclareMethod(image, size)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image, size)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.push_back(static_cast<int>(pThis->GetWidth()));
	valList.push_back(static_cast<int>(pThis->GetHeight()));
	return result;
}

// image#allocbuff(width:number, height:number, color?:color):void
Gura_DeclareMethod(image, allocbuff)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, allocbuff)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckEmpty(sig)) return Value::Null;
	pThis->AllocBuffer(sig, args.GetSizeT(0), args.GetSizeT(1), 0x00);
	if (args.IsColor(2)) pThis->Fill(Object_color::GetObject(args, 2));
	return Value::Null;
}

// image#putpixel(x:number, y:number, color:color):map:void
Gura_DeclareMethod(image, putpixel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(image, putpixel)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	if (!pThis->CheckCoord(sig, x, y)) return Value::Null;
	unsigned char *p = pThis->GetPointer(x, y);
	pThis->PutPixel(p, Object_color::GetObject(args, 2));
	return Value::Null;
}

// image#getpixel(x:number, y:number):map
Gura_DeclareMethod(image, getpixel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
}

Gura_ImplementMethod(image, getpixel)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	if (!pThis->CheckCoord(sig, x, y)) return Value::Null;
	unsigned char *p = pThis->GetPointer(x, y);
	Object_color *pObjColor = new Object_color(env, 0, 0, 0, 0);
	pThis->GetPixel(p, pObjColor);
	return Value(pObjColor);
}

// image#store(x:number, y:number, width:number, height:number, element:symbol, src):void
Gura_DeclareMethod(image, store)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "element", VTYPE_symbol);
	DeclareArg(env, "src", VTYPE_any);
}

Gura_ImplementMethod(image, store)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0), y = args.GetSizeT(1);
	size_t width = args.GetSizeT(2), height = args.GetSizeT(3);
	if (!pThis->CheckCoord(sig, x, y)) return Value::Null;
	if (!pThis->CheckCoord(sig, x + width - 1, y + height - 1)) return Value::Null;
	const Symbol *pSymbol = args.GetSymbol(4);
	if (args.IsMatrix(5)) {
		pThis->Store(sig, x, y, width, height, pSymbol, Object_matrix::GetObject(args, 5));
	} else if (args.IsList(5) || args.IsIterator(5)) {
		AutoPtr<Iterator> pIterator(args.GetValue(5).CreateIterator(sig));
		pThis->Store(sig, x, y, width, height, pSymbol, pIterator.get());
	} else {
		sig.SetError(ERR_ValueError, "invalid object for image's source");
		return Value::Null;
	}
	return Value::Null;
}

// image#extract(x:number, y:number, width:number, height:number, element:symbol, dst):void
Gura_DeclareMethod(image, extract)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "element", VTYPE_symbol);
	DeclareArg(env, "dst", VTYPE_any);
}

Gura_ImplementMethod(image, extract)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0), y = args.GetSizeT(1);
	size_t width = args.GetSizeT(2), height = args.GetSizeT(3);
	if (!pThis->CheckCoord(sig, x, y)) return Value::Null;
	if (!pThis->CheckCoord(sig, x + width - 1, y + height - 1)) return Value::Null;
	const Symbol *pSymbol = args.GetSymbol(4);
	if (args.IsMatrix(5)) {
		pThis->Extract(sig, x, y, width, height, pSymbol, Object_matrix::GetObject(args, 5));
	} else if (args.IsList(5)) {
		pThis->Extract(sig, x, y, width, height, pSymbol, Object_list::GetObject(args, 5));
	} else {
		sig.SetError(ERR_ValueError, "invalid object for image's destination");
		return Value::Null;
	}
	return Value::Null;
}

// image#replacecolor(colorOrg:color, color:color):void
Gura_DeclareMethod(image, replacecolor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "colorOrg", VTYPE_color);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(image, replacecolor)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	pThis->ReplaceColor(Object_color::GetObject(args, 0), Object_color::GetObject(args, 1));
	return Value::Null;
}

// image#clear():void
Gura_DeclareMethod(image, clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(image, clear)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	AutoPtr<Object_color> pObjColor(new Object_color(env, 0, 0, 0, 0));
	pThis->Fill(pObjColor.get());
	return Value::Null;
}

// image#fill(color:color):void
Gura_DeclareMethod(image, fill)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(image, fill)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	pThis->Fill(Object_color::GetObject(args, 0));
	return Value::Null;
}

// image#fillrect(x:number, y:number, width:number, height:number, color:color):map:void
Gura_DeclareMethod(image, fillrect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color);
}

Gura_ImplementMethod(image, fillrect)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	int x = args.GetInt(0), y = args.GetInt(1);
	int width = args.GetInt(2), height = args.GetInt(3);
	if (!pThis->AdjustCoord(x, y, width, height)) return Value::Null;
	pThis->FillRect(x, y, width, height, Object_color::GetObject(args, 4));
	return Value::Null;
}

// image#setalpha(alpha:number, color?:color):reduce
Gura_DeclareMethod(image, setalpha)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "alpha", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, setalpha)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	if (pThis->GetFormat() != Image::FORMAT_RGBA) {
		sig.SetError(ERR_ValueError, "only RGBA format contains alpha element");
		return 0;
	}
	pThis->FillAlpha(args.GetUChar(0), args.IsValid(1)? Object_color::GetObject(args, 1) : NULL);
	return args.GetThis();
}

// image#reducecolor(palette?:palette)
Gura_DeclareMethod(image, reducecolor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "palette", VTYPE_palette, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, reducecolor)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	const Object_palette *pObjPalette = pThis->GetPaletteObj();
	if (args.IsPalette(0)) {
		pObjPalette = Object_palette::GetObject(args, 0);
	} else if (pObjPalette == NULL) {
		sig.SetError(ERR_ValueError, "palette must be specified");
		return Value::Null;
	}
	Object_image *pObj = pThis->ReduceColor(sig, pObjPalette);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj);
}

// image#grayscale()
Gura_DeclareMethod(image, grayscale)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image, grayscale)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	const Object_palette *pObjPalette = pThis->GetPaletteObj();
	Object_image *pObj = pThis->GrayScale(sig);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj);
}

// image#delpalette():reduce
Gura_DeclareMethod(image, delpalette)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(image, delpalette)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	pThis->SetPaletteObj(NULL);
	return args.GetThis();
}

// image#flip(orient:symbol):map
Gura_DeclareMethod(image, flip)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "orient", VTYPE_symbol);
}

Gura_ImplementMethod(image, flip)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	const Symbol *pSymbol = args.GetSymbol(0);
	bool horzFlag = false, vertFlag = false;
	if (pSymbol->IsIdentical(Gura_Symbol(horz))) {
		horzFlag = true;
	} else if (pSymbol->IsIdentical(Gura_Symbol(vert))) {
		vertFlag = true;
	} else if (pSymbol->IsIdentical(Gura_Symbol(both))) {
		horzFlag = vertFlag = true;
	} else {
		sig.SetError(ERR_ValueError, "orient must be one of `horz or `vert");
		return Value::Null;
	}
	if (!pThis->CheckValid(sig)) return Value::Null;
	Object_image *pObj = pThis->Flip(sig, horzFlag, vertFlag);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj);
}

// image#rotate(angle:number, background?:color):map
Gura_DeclareMethod(image, rotate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rotate", VTYPE_number);
	DeclareArg(env, "background", VTYPE_color, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, rotate)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	Value valueBg = args.GetValue(1);
	if (!valueBg.IsColor()) {
		valueBg = Value(new Object_color(env, 0, 0, 0, 0));
	}
	Object_image *pObj = pThis->Rotate(sig,
					args.GetNumber(0), Object_color::GetObject(valueBg));
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj);
}

// image#crop(x:number, y:number, width?:number, height?:number):map
Gura_DeclareMethod(image, crop)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, crop)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0);
	size_t y = args.GetSizeT(1);
	if (!pThis->CheckCoord(sig, x, y)) return Value::Null;
	size_t width = args.IsNumber(2)? args.GetSizeT(2) : pThis->GetWidth() - x;
	size_t height = args.IsNumber(3)? args.GetSizeT(3) : pThis->GetHeight() - y;
	if (!pThis->CheckCoord(sig, x + width - 1, y + height - 1)) return Value::Null;
	Object_image *pObj = pThis->Crop(sig, x, y, width, height);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj);
}

// image#resize(width?:number, height?:number):map:[box]
Gura_DeclareMethod(image, resize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(box));
}

Gura_ImplementMethod(image, resize)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	bool boxFlag = args.IsSet(Gura_Symbol(box));
	size_t width, height;
	if (!args.IsNumber(0) && !args.IsNumber(1)) {
		sig.SetError(ERR_ValueError, "width or height must be specified");
		return Value::Null;
	}
	if (args.IsNumber(0) && !args.IsNumber(1)) {
		width = args.GetSizeT(0);
		if (boxFlag) {
			height = width;
		} else {
			height = pThis->GetHeight() * width / pThis->GetWidth();
		}
	} else if (!args.IsNumber(0) && args.IsNumber(1)) {
		height = args.GetSizeT(1);
		if (boxFlag) {
			width = height;
		} else {
			width = pThis->GetWidth() * height / pThis->GetHeight();
		}
	} else {
		width = args.GetSizeT(0), height = args.GetSizeT(1);
	}
	Object_image *pObj = pThis->Resize(sig, width, height);
	if (sig.IsSignalled()) return Value::Null;
	return Value(pObj);
}

// image#thumbnail(width?:number, height?:number):map:[box]
Gura_DeclareMethod(image, thumbnail)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(box));
}

Gura_ImplementMethod(image, thumbnail)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	bool boxFlag = args.IsSet(Gura_Symbol(box));
	Object_image *pObj;
	if (!args.IsNumber(0) && !args.IsNumber(1)) {
		sig.SetError(ERR_ValueError, "width or height must be specified");
		return Value::Null;
	}
	size_t width = 0, height = 0;
	if (args.IsNumber(0) && !args.IsNumber(1)) {
		width = args.GetSizeT(0);
		if (boxFlag) {
			height = width;
		} else {
			if (pThis->GetWidth() < width) {
				pObj = dynamic_cast<Object_image *>(pThis->Clone());
			} else {
				height = pThis->GetHeight() * width / pThis->GetWidth();
				pObj = pThis->Resize(sig, width, height);
				if (sig.IsSignalled()) return Value::Null;
			}
			return Value(pObj);
		}
	} else if (!args.IsNumber(0) && args.IsNumber(1)) {
		height = args.GetSizeT(1);
		if (boxFlag) {
			width = height;
		} else {
			if (pThis->GetHeight() < height) {
				pObj = dynamic_cast<Object_image *>(pThis->Clone());
			} else {
				width = pThis->GetWidth() * height / pThis->GetHeight();
				pObj = pThis->Resize(sig, width, height);
				if (sig.IsSignalled()) return Value::Null;
			}
			return Value(pObj);
		}
	} else {
		width = args.GetSizeT(0);
		height = args.GetSizeT(1);
	}
	if (pThis->GetWidth() < width && pThis->GetHeight() < height) {
		pObj = dynamic_cast<Object_image *>(pThis->Clone());
	} else {
		size_t widthExp = pThis->GetWidth() * height / pThis->GetHeight();
		if (widthExp <= width) {
			width = widthExp;
		} else {
			height = pThis->GetHeight() * width / pThis->GetWidth();
		}
		pObj = pThis->Resize(sig, width, height);
		if (sig.IsSignalled()) return Value::Null;
	}
	return Value(pObj);
}

// image#paste(x:number, y:number, src:image, width?:number, height?:number,
//     xoffset:number => 0, yoffset:number => 0, alpha:number => 255):map:reduce
Gura_DeclareMethod(image, paste)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "src", VTYPE_image);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(255));
}

Gura_ImplementMethod(image, paste)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->CheckValid(sig)) return Value::Null;
	Object_image *pObjImg = Object_image::GetObject(args, 2);
	if (!pObjImg->CheckValid(sig)) return Value::Null;
	size_t x = args.GetSizeT(0);
	size_t y = args.GetSizeT(1);
	if (!pThis->CheckCoord(sig, x, y)) return Value::Null;
	size_t xOffset = args.GetSizeT(5);
	size_t yOffset = args.GetSizeT(6);
	if (!pObjImg->CheckCoord(sig, xOffset, yOffset)) return Value::Null;
	size_t width = args.IsNumber(3)?
				args.GetSizeT(3) : pObjImg->GetWidth() - xOffset;
	size_t height = args.IsNumber(4)?
				args.GetSizeT(4) : pObjImg->GetHeight() - yOffset;
	if (!pObjImg->CheckCoord(sig, xOffset + width - 1, yOffset + height - 1)) {
		return Value::Null;
	}
	if (x + width > pThis->GetWidth()) width = pThis->GetWidth() - x;
	if (y + height > pThis->GetHeight()) height = pThis->GetHeight() - y;
	unsigned char alpha = args.GetUChar(7);
	pThis->Paste(x, y, pObjImg, width, height, xOffset, yOffset, alpha);
	if (sig.IsSignalled()) return Value::Null;
	return args.GetThis();
}

// image#read(stream:stream:r, imgtype?:string):map:reduce
Gura_DeclareMethod(image, read)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareArg(env, "imgtype", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Reads image data from a stream.");
}

Gura_ImplementMethod(image, read)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->Read(sig, args.GetStream(0),
			args.IsString(1)? args.GetString(1) : NULL)) return Value::Null;
	return args.GetThis();
}

// image#write(stream:stream:w, imgtype?:string):map:reduce
Gura_DeclareMethod(image, write)
{
	SetMode(RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "imgtype", VTYPE_string, OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Writes image data to a stream.");
}

Gura_ImplementMethod(image, write)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!pThis->Write(sig, args.GetStream(0),
			args.IsString(1)? args.GetString(1) : NULL)) return Value::Null;
	return args.GetThis();
}

// image#each(x:number, y:number, width:number, height:number, scandir:symbol) {block?}
Gura_DeclareMethod(image, each)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "scandir", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), "Returns an iterator that scans pixels in the image.");
}

Gura_ImplementMethod(image, each)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	size_t x = args.IsNumber(0)? args.GetSizeT(0) : 0;
	size_t y = args.IsNumber(1)? args.GetSizeT(1) : 0;
	size_t width = args.IsNumber(2)? args.GetSizeT(2) : pThis->GetWidth();
	size_t height = args.IsNumber(3)? args.GetSizeT(3) : pThis->GetHeight();
	Image::ScanDir scanDir = Image::SCAN_LeftTopHorz;
	if (args.IsSymbol(4)) {
		const Symbol *pSymbol = args.GetSymbol(4);
		
	}
	Iterator *pIterator = new Object_image::IteratorEach(
					Object_image::Reference(pThis), x, y, width, height, scanDir);
	return ReturnIterator(env, sig, args, pIterator);
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_image::Class_image(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_image)
{
	Gura_AssignMethod(image, size);
	Gura_AssignMethod(image, allocbuff);
	Gura_AssignMethod(image, putpixel);
	Gura_AssignMethod(image, getpixel);
	Gura_AssignMethod(image, store);
	Gura_AssignMethod(image, extract);
	Gura_AssignMethod(image, replacecolor);
	Gura_AssignMethod(image, clear);
	Gura_AssignMethod(image, fill);
	Gura_AssignMethod(image, fillrect);
	Gura_AssignMethod(image, setalpha);
	Gura_AssignMethod(image, reducecolor);
	Gura_AssignMethod(image, grayscale);
	Gura_AssignMethod(image, delpalette);
	Gura_AssignMethod(image, flip);
	Gura_AssignMethod(image, rotate);
	Gura_AssignMethod(image, crop);
	Gura_AssignMethod(image, resize);
	Gura_AssignMethod(image, thumbnail);
	Gura_AssignMethod(image, paste);
	Gura_AssignMethod(image, read);
	Gura_AssignMethod(image, write);
	Gura_AssignMethod(image, each);
}

bool Class_image::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsString()) {
		AutoPtr<Stream> pStream(Directory::OpenStream(env, sig,
								value.GetString(), Stream::ATTR_Readable));
		if (sig.IsSignalled()) return false;
		AutoPtr<Object_image> pObjImage(new Object_image(env, Image::FORMAT_RGBA));
		pObjImage->Read(sig, *pStream, NULL);
		if (sig.IsSignalled()) {
			return false;
		}
		value = Value(pObjImage.release());
		return true;
	}
	return false;
}

void Class_image::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(image);
}

//-----------------------------------------------------------------------------
// Object_image::Scanner
//-----------------------------------------------------------------------------
Object_image::Scanner::Scanner(Object_image *pObjImage,
			size_t x, size_t y, size_t width, size_t height, Image::ScanDir scanDir) :
	_pObjImage(pObjImage), _iPixel(0), _iLine(0)
{
	int bytesPerPixel = static_cast<int>(_pObjImage->GetBytesPerPixel());
	int bytesPerLine = static_cast<int>(_pObjImage->GetBytesPerLine());
	switch (scanDir) {
	case Image::SCAN_LeftTopHorz:
		_pPixel = _pObjImage->GetPointer(x, y);
		_nPixels = width, _nLines = height;
		_pitchPixel = bytesPerPixel;
		_pitchLine = bytesPerLine - bytesPerPixel * static_cast<int>(width);
		break;
	case Image::SCAN_LeftTopVert:
		_pPixel = _pObjImage->GetPointer(x, y);
		_nPixels = height, _nLines = width;
		_pitchPixel = bytesPerLine;
		_pitchLine = bytesPerPixel - bytesPerLine * static_cast<int>(height);
		break;
	case Image::SCAN_RightTopHorz:
		_pPixel = _pObjImage->GetPointer(x + width - 1, y);
		_nPixels = width, _nLines = height;
		_pitchPixel = -bytesPerPixel;
		_pitchLine = bytesPerLine + bytesPerPixel * static_cast<int>(width);
		break;
	case Image::SCAN_RightTopVert:
		_pPixel = _pObjImage->GetPointer(x + width - 1, y);
		_nPixels = height, _nLines = width;
		_pitchPixel = bytesPerLine;
		_pitchLine = -bytesPerPixel - bytesPerLine * static_cast<int>(height);
		break;
	case Image::SCAN_LeftBottomHorz:
		_pPixel = _pObjImage->GetPointer(x, y + height - 1);
		_nPixels = width, _nLines = height;
		_pitchPixel = bytesPerPixel;
		_pitchLine = -bytesPerLine - bytesPerPixel * static_cast<int>(width);
		break;
	case Image::SCAN_LeftBottomVert:
		_pPixel = _pObjImage->GetPointer(x, y + height - 1);
		_nPixels = height, _nLines = width;
		_pitchPixel = -bytesPerLine;
		_pitchLine = bytesPerPixel + bytesPerLine * static_cast<int>(height);
		break;
	case Image::SCAN_RightBottomHorz:
		_pPixel = _pObjImage->GetPointer(x + width - 1, y + height - 1);
		_nPixels = width, _nLines = height;
		_pitchPixel = -bytesPerPixel;
		_pitchLine = -bytesPerLine + bytesPerPixel * static_cast<int>(width);
		break;
	case Image::SCAN_RightBottomVert:
		_pPixel = _pObjImage->GetPointer(x + width - 1, y + height - 1);
		_nPixels = height, _nLines = width;
		_pitchPixel = -bytesPerLine;
		_pitchLine = -bytesPerPixel + bytesPerLine * static_cast<int>(height);
		break;
	default:
		break;
	}
}

Object_image::Scanner::~Scanner()
{
}

//-----------------------------------------------------------------------------
// Object_image::IteratorEach
//-----------------------------------------------------------------------------
Iterator *Object_image::IteratorEach::GetSource()
{
	return NULL;
}

bool Object_image::IteratorEach::DoNext(Environment &env, Signal sig, Value &value)
{
	Object_image *pObjImage = _scanner.GetImageObj();
	//Environment &env = *pObjImage;
	if (_doneFlag) return false;
	unsigned char red = _scanner.GetRed();
	unsigned char green = _scanner.GetGreen();
	unsigned char blue = _scanner.GetBlue();
	unsigned char alpha = (pObjImage->GetFormat() == Image::FORMAT_RGBA)?
											_scanner.GetAlpha() : 0xff;
	value = Value(new Object_color(env, red, green, blue, alpha));
	_doneFlag = !_scanner.Next();
	return true;
}

String Object_image::IteratorEach::ToString(Signal sig) const
{
	return String("<iterator:image#each>");
}

void Object_image::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
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
