//=============================================================================
// Image
//=============================================================================
#ifndef __GURA_IMAGE_H__
#define __GURA_IMAGE_H__

#include "Memory.h"

namespace Gura {

class Matrix;
class Palette;

//-----------------------------------------------------------------------------
// Image
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Image {
public:
	struct BitmapFileHeader {
		enum { Size = 14 };
		Gura_PackedUInt16_LE(bfType);
		Gura_PackedUInt32_LE(bfSize);
		Gura_PackedUInt16_LE(bfReserved1);
		Gura_PackedUInt16_LE(bfReserved2);
		Gura_PackedUInt32_LE(bfOffBits);
	};
	struct BitmapInfoHeader {
		enum { Size = 40 };
		Gura_PackedUInt32_LE(biSize);
		Gura_PackedInt32_LE(biWidth);
		Gura_PackedInt32_LE(biHeight);
		Gura_PackedUInt16_LE(biPlanes);
		Gura_PackedUInt16_LE(biBitCount);
		Gura_PackedUInt32_LE(biCompression);
		Gura_PackedUInt32_LE(biSizeImage);
		Gura_PackedInt32_LE(biXPelsPerMeter);
		Gura_PackedInt32_LE(biYPelsPerMeter);
		Gura_PackedUInt32_LE(biClrUsed);
		Gura_PackedUInt32_LE(biClrImportant);
	};
public:
	enum {
		OffsetR	= 2,
		OffsetG	= 1,
		OffsetB	= 0,
		OffsetA	= 3,
	};
	enum Format {
		FORMAT_None,
		FORMAT_RGB, FORMAT_RGBA,
	};
	enum ScanDir {
		SCAN_None,
		SCAN_LeftTopHorz, SCAN_LeftTopVert,
		SCAN_RightTopHorz, SCAN_RightTopVert,
		SCAN_LeftBottomHorz, SCAN_LeftBottomVert,
		SCAN_RightBottomHorz, SCAN_RightBottomVert,
	};
public:
	struct Accum {
		size_t r;
		size_t g;
		size_t b;
		size_t a;
		size_t cnt;
		inline void AddRGB(UInt8 _r, UInt8 _g, UInt8 _b) {
			r += _r;
			g += _g;
			b += _b;
			cnt++;
		}
		inline void AddRGBA(UInt8 _r, UInt8 _g, UInt8 _b, UInt8 _a) {
			r += _r;
			g += _g;
			b += _b;
			a += _a;
			cnt++;
		}
		inline void AddRGB(const UInt8 *pPixel) {
			r += Image::GetPixelR(pPixel);
			g += Image::GetPixelG(pPixel);
			b += Image::GetPixelB(pPixel);
			cnt++;
		}
		inline void AddRGBA(const UInt8 *pPixel) {
			r += Image::GetPixelR(pPixel);
			g += Image::GetPixelG(pPixel);
			b += Image::GetPixelB(pPixel);
			a += Image::GetPixelA(pPixel);
			cnt++;
		}
		inline void StoreRGB(UInt8 *pPixel) {
			StorePixel(pPixel,
				static_cast<UInt8>(r),
				static_cast<UInt8>(g),
				static_cast<UInt8>(b));
		}
		inline void StoreRGBA(UInt8 *pPixel) {
			StorePixel(pPixel,
				static_cast<UInt8>(r),
				static_cast<UInt8>(g),
				static_cast<UInt8>(b),
				static_cast<UInt8>(a));
		}
	};
	class GURA_DLLDECLARE Scanner {
	private:
		AutoPtr<Image> _pImage;
		UInt8 *_pPixel;
		size_t _iPixel, _iLine;
		size_t _nPixels, _nLines;
		int _pitchPixel;
		int _pitchLine;
	public:
		Scanner(Image *pImage, size_t x, size_t y,
								size_t width, size_t height, ScanDir scanDir);
		~Scanner();
		inline void SetPointer(UInt8 *pPixel) { _pPixel = pPixel; }
		inline void ResetIndex() { _iPixel = 0, _iLine = 0; }
		inline Image *GetImage() { return _pImage.get(); }
		inline UInt8 *GetPointer() { return _pPixel; }
		inline UInt8 GetR() const { return _pPixel[OffsetR]; }
		inline UInt8 GetG() const { return _pPixel[OffsetG]; }
		inline UInt8 GetB() const { return _pPixel[OffsetB]; }
		inline UInt8 GetA() const { return _pPixel[OffsetA]; }
		inline void FwdPixel() {
			_iPixel++;
			_pPixel += _pitchPixel;
		}
		inline void BwdPixel() {
			_iPixel--;
			_pPixel -= _pitchPixel;
		}
		inline void FwdLine() {
			_iLine++;
			_pPixel += _pitchLine;
		}
		inline void BwdLine() {
			_iLine--;
			_pPixel -= _pitchLine;
		}
		inline bool NextPixel() {
			_iPixel++;
			_pPixel += _pitchPixel;
			return _iPixel < _nPixels;
		}
		inline bool NextLine() {
			_iPixel = 0;
			_iLine++;
			if (_iLine >= _nLines) return false;
			_pPixel += _pitchLine;
			return true;
		}
		inline bool Next() {
			_iPixel++;
			_pPixel += _pitchPixel;
			if (_iPixel < _nPixels) return true;
			_iPixel = 0;
			_iLine++;
			if (_iLine >= _nLines) return false;
			_pPixel += _pitchLine;
			return true;
		}
		inline bool Next(Scanner &scannerSlave) {
			_iPixel++;
			_pPixel += _pitchPixel;
			scannerSlave._pPixel += scannerSlave._pitchPixel;
			if (_iPixel < _nPixels) return true;
			_iPixel = 0;
			_iLine++;
			if (_iLine >= _nLines) return false;
			_pPixel += _pitchLine;
			scannerSlave._pPixel += scannerSlave._pitchLine;
			return true;
		}
		inline size_t CountPixels() const { return _nPixels; }
		inline size_t CountLines() const { return _nLines; }
		inline size_t GetPixelIdx() const { return _iPixel; }
		inline size_t GetLineIdx() const { return _iLine; }
		inline void StorePixel(UInt8 r, UInt8 g, UInt8 b) {
			_pPixel[OffsetR] = r;
			_pPixel[OffsetG] = g;
			_pPixel[OffsetB] = b;
		}
		inline void StorePixel(UInt8 r, UInt8 g, UInt8 b, UInt8 a) {
			_pPixel[OffsetR] = r;
			_pPixel[OffsetG] = g;
			_pPixel[OffsetB] = b;
			_pPixel[OffsetA] = a;
		}
	};
	class IteratorScan : public Iterator {
	private:
		Scanner _scanner;
		bool _doneFlag;
	public:
		inline IteratorScan(Image *pImage,
				size_t x, size_t y, size_t width, size_t height, ScanDir scanDir) :
			Iterator(Finite),
			_scanner(pImage, x, y, width, height, scanDir), _doneFlag(false) {}
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
protected:
	int _cntRef;
	Format _format;
	size_t _width, _height;
	struct {
		size_t bitsPerPixel;
		size_t bytesPerPixel;
		size_t bytesPerLine;
	} _metrics;
	AutoPtr<Memory> _pMemory;
	AutoPtr<Palette> _pPalette;
public:
	Gura_DeclareReferenceAccessor(Image);
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Image");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	Image(Format format);
	Image(const Image &image);
protected:
	virtual ~Image();
public:
	Image *Clone() const;
	inline Memory *GetMemory() { return _pMemory.get(); }
	inline const Memory *GetMemory() const { return _pMemory.get(); }
	inline Format GetFormat() const { return _format; }
	inline size_t GetWidth() const { return _width; }
	inline size_t GetHeight() const { return _height; }
	inline UInt8 *GetBuffer() {
		return reinterpret_cast<UInt8 *>(_pMemory->GetPointer());
	}
	inline const UInt8 *GetBuffer() const {
		return reinterpret_cast<const UInt8 *>(_pMemory->GetPointer());
	}
	inline bool IsValid() const { return !_pMemory.IsNull(); }
	inline size_t GetBitsPerPixel() const { return _metrics.bitsPerPixel; }
	inline size_t GetBytesPerPixel() const { return _metrics.bytesPerPixel; }
	inline size_t GetBytesPerLine() const { return _metrics.bytesPerLine; }
	inline size_t GetBufferSize() const {
		return GetBytesPerLine() * _height;
	}
	inline UInt8 *GetPointer(size_t y) {
		return GetBuffer() + GetBytesPerLine() * y;
	}
	inline UInt8 *GetPointer(size_t x, size_t y) {
		return GetBuffer() + GetBytesPerLine() * y + GetBytesPerPixel() * x;
	}
	inline const UInt8 *GetPointer(size_t y) const {
		return GetBuffer() + GetBytesPerLine() * y;
	}
	inline const UInt8 *GetPointer(size_t x, size_t y) const {
		return GetBuffer() + GetBytesPerLine() * y + GetBytesPerPixel() * x;
	}
	inline Scanner *CreateScanner(size_t x, size_t y,
				size_t width, size_t height, ScanDir scanDir = SCAN_LeftTopHorz) {
		return new Scanner(Image::Reference(this), x, y, width, height, scanDir);
	}
	inline Scanner *CreateScanner(ScanDir scanDir = SCAN_LeftTopHorz) {
		return new Scanner(Image::Reference(this), 0, 0, _width, _height, scanDir);
	}
	bool CheckEmpty(Signal &sig) const;
	bool CheckValid(Signal &sig) const;
	bool AllocBuffer(size_t width, size_t height);
	bool AllocBuffer(size_t width, size_t height, UInt8 fillValue);
	bool AllocBuffer(Signal &sig, size_t width, size_t height);
	bool AllocBuffer(Signal &sig, size_t width, size_t height, UInt8 fillValue);
	void FreeBuffer();
	inline bool CheckCoord(int x, int y) const {
		return 0 <= x && x < static_cast<int>(_width) &&
				0 <= y && y < static_cast<int>(_height);
	}
	bool CheckCoord(Signal &sig, size_t x, size_t y) const;
	bool AdjustCoord(int &x, int &y, int &width, int &height) const;
	void PutPixel(UInt8 *buff, const Color &color);
	void GetPixel(const UInt8 *buff, Color &color);
	bool Store(Signal &sig, size_t x, size_t y, size_t width, size_t height,
						const Symbol *pSymbol, const Matrix *pMat);
	bool Store(Environment &env, size_t x, size_t y, size_t width, size_t height,
						const Symbol *pSymbol, Iterator *pIterator);
	bool Extract(Signal &sig, size_t x, size_t y, size_t width, size_t height,
						const Symbol *pSymbol, Matrix *pMat);
	bool Extract(Signal &sig, size_t x, size_t y, size_t width, size_t height,
						const Symbol *pSymbol, ValueList &valList);
	void ReplaceColorRect(size_t x, size_t y, size_t width, size_t height,
						const Color &colorOrg, const Color &color, double tolerance);
	inline void ReplaceColor(const Color &colorOrg, Color &color, double tolerance) {
		ReplaceColorRect(0, 0, _width, _height, colorOrg, color, tolerance);
	}
	void FillRect(size_t x, size_t y, size_t width, size_t height, const Color &color);
	inline void Fill(const Color &color) {
		FillRect(0, 0, _width, _height, color);
	}
	void FillRectAlpha(size_t x, size_t y,
			size_t width, size_t height, UInt8 alpha);
	void FillRectAlpha(size_t x, size_t y,
			size_t width, size_t height, UInt8 alpha, const Color &color, double tolerance);
	inline void FillAlpha(UInt8 alpha) {
		FillRectAlpha(0, 0, _width, _height, alpha);
	}
	inline void FillAlpha(UInt8 alpha, const Color &color, double tolerance) {
		FillRectAlpha(0, 0, _width, _height, alpha, color, tolerance);
	}
	const Palette *GetPalette() const { return _pPalette.get(); }
	Image *ReduceColor(Signal &sig, const Palette *pPalette);
	Image *GrayScale(Signal &sig);
	Image *MapColorLevel(Signal &sig, const UInt8 *mapR, const UInt8 *mapG, const UInt8 *mapB);
	Image *Blur(Signal &sig, int radius, Number sigma);
	Image *Flip(Signal &sig, bool horzFlag, bool vertFlag);
	Image *Rotate90(Signal &sig, bool clockwiseFlag);
	Image *Rotate(Signal &sig, double angle, const Color &color);
	Image *Crop(Signal &sig, size_t x, size_t y, size_t width, size_t height);
	Image *Resize(Signal &sig, size_t width, size_t height);
	void Paste(size_t x, size_t y, Image *pImage,
		size_t width, size_t height, size_t xOffset, size_t yOffset, UInt8 alpha);
	Palette *CreateEmptyPalette(Environment &env, size_t nEntries);
	void SetPalette(Palette *pPalette);
	bool Read(Environment &env, Stream &stream, const char *imageType);
	bool Write(Environment &env, Stream &stream, const char *imageType);
	int CalcDIBBitCount() const;
	static inline size_t CalcDIBPaletteSize(int biBitCount) {
		return (biBitCount <= 8)? (1 << biBitCount) * 4 : 0;
	}
	size_t CalcDIBImageSize(int biBitCount, bool maskFlag) const;
	bool ReadDIBPalette(Environment &env, Stream &stream, int biBitCount);
	bool WriteDIBPalette(Environment &env, Stream &stream, int biBitCount);
	bool ReadDIB(Signal &sig, Stream &stream,
				int biWidth, int biHeight, int biBitCount, bool maskFlag);
	bool WriteDIB(Signal &sig, Stream &stream, int biBitCount, bool maskFlag);
	static ScanDir SymbolToScanDir(const Symbol *pSymbol);
	size_t SymbolToPixelOffset(Signal &sig, const Symbol *pSymbol) const;
	static Format SymbolToFormat(Signal &sig, const Symbol *pSymbol);
	static const Symbol *FormatToSymbol(Format format);
	static inline UInt8 GetPixelGray(UInt8 *buff) {
		return Color::CalcGray(GetPixelR(buff), GetPixelG(buff), GetPixelB(buff));
	}
	static inline void StorePixel(UInt8 *buff, UInt8 r, UInt8 g, UInt8 b) {
		*(buff + OffsetR) = r;
		*(buff + OffsetG) = g;
		*(buff + OffsetB) = b;
	}
	static inline void StorePixel(UInt8 *buff, UInt8 r, UInt8 g, UInt8 b, UInt8 a) {
		*(buff + OffsetR) = r;
		*(buff + OffsetG) = g;
		*(buff + OffsetB) = b;
		*(buff + OffsetA) = a;
	}
	static inline void StorePixel(UInt8 *pPixelDst, const UInt8 *pPixelSrc, bool alphaFlag) {
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		if (alphaFlag) *pPixelDst++ = *pPixelSrc++;
	}
	static inline void StorePixelRGB(UInt8 *pPixelDst, const UInt8 *pPixelSrc) {
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
	}
	static inline void StorePixelRGBA(UInt8 *pPixelDst, const UInt8 *pPixelSrc) {
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
	}
	static inline void StorePixelRGBA(UInt8 *pPixelDst, const UInt8 *pPixelSrc, UInt8 a) {
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = a;
	}
	static inline UInt8 GetPixelR(const UInt8 *buff) {
		return *(buff + OffsetR);
	}
	static inline UInt8 GetPixelG(const UInt8 *buff) {
		return *(buff + OffsetG);
	}
	static inline UInt8 GetPixelB(const UInt8 *buff) {
		return *(buff + OffsetB);
	}
	static inline UInt8 GetPixelA(const UInt8 *buff) {
		return *(buff + OffsetA);
	}
	static inline void RotateCoord(int &xm, int &ym,
							int x, int y, int cos1024, int sin1024) {
		xm = (x * cos1024 - y * sin1024) >> 10;
		ym = (x * sin1024 + y * cos1024) >> 10;
	}
#if GURA_USE_MSWIN_DIB
public:
	inline HBITMAP GetHBITMAP() {
		return dynamic_cast<MemoryDIB *>(GetMemory())->GetHBITMAP();
	}
#endif
private:
	void InitMetrics();
	Image *CreateDerivation(Signal &sig,
				size_t width, size_t height, Palette *pPalette = nullptr);
};

//-----------------------------------------------------------------------------
// ImageStreamer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ImageStreamer {
public:
	typedef std::vector<ImageStreamer *> List;
private:
	const char *_imageType;
	static List *_pList;
public:
	inline ImageStreamer(const char *imageType) : _imageType(imageType) {}
	inline const char *GetImageType() const { return _imageType; }
	virtual bool IsResponsible(Signal &sig, Stream &stream) = 0;
	virtual bool Read(Environment &env, Image *pImage, Stream &stream) = 0;
	virtual bool Write(Environment &env, Image *pImage, Stream &stream) = 0;
public:
	static void Register(ImageStreamer *pImageStreamer);
	static ImageStreamer *FindResponsible(Signal &sig, Stream &stream, const char *imageType);
	static ImageStreamer *FindByImageType(const char *imageType);
};

}

#endif
