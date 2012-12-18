#ifndef __GURA_OBJECT_IMAGE_H__
#define __GURA_OBJECT_IMAGE_H__

#include "Object.h"
#include "Object_color.h"
#include "Object_palette.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_image
//-----------------------------------------------------------------------------
class DLLDECLARE Class_image : public Class {
public:
	Class_image(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_image
//-----------------------------------------------------------------------------
class DLLDECLARE Object_image : public Object {
#if USE_WINDOWS_DIB
protected:
	HBITMAP _hBmp;
public:
	inline HBITMAP GetHBITMAP() { return _hBmp; }
#else
protected:
	OAL::Memory _memory;
#endif
public:
	struct Accum {
		size_t red;
		size_t green;
		size_t blue;
		size_t alpha;
		size_t cnt;
		inline void AddRGB(const unsigned char *pPixel) {
			red   += Object_image::GetPixelR(pPixel);
			green += Object_image::GetPixelG(pPixel);
			blue  += Object_image::GetPixelB(pPixel);
			cnt++;
		}
		inline void AddRGBA(const unsigned char *pPixel) {
			red   += Object_image::GetPixelR(pPixel);
			green += Object_image::GetPixelG(pPixel);
			blue  += Object_image::GetPixelB(pPixel);
			alpha += Object_image::GetPixelA(pPixel);
			cnt++;
		}
		inline void StoreRGB(unsigned char *pPixel) {
			StorePixel(pPixel,
				static_cast<unsigned char>(red),
				static_cast<unsigned char>(green),
				static_cast<unsigned char>(blue));
		}
		inline void StoreRGBA(unsigned char *pPixel) {
			StorePixel(pPixel,
				static_cast<unsigned char>(red),
				static_cast<unsigned char>(green),
				static_cast<unsigned char>(blue),
				static_cast<unsigned char>(alpha));
		}
	};
	class DLLDECLARE Scanner {
	private:
		AutoPtr<Object_image> _pObjImage;
		unsigned char *_pPixel;
		size_t _iPixel, _iLine;
		size_t _nPixels, _nLines;
		int _pitchPixel;
		int _pitchLine;
	public:
		Scanner(Object_image *pObjImage, size_t x, size_t y,
								size_t width, size_t height, Image::ScanDir scanDir);
		~Scanner();
		inline Object_image *GetImageObj() { return _pObjImage.get(); }
		inline unsigned char *GetPointer() { return _pPixel; }
		inline unsigned char GetRed() const { return _pPixel[Image::OffsetRed]; }
		inline unsigned char GetGreen() const { return _pPixel[Image::OffsetGreen]; }
		inline unsigned char GetBlue() const { return _pPixel[Image::OffsetBlue]; }
		inline unsigned char GetAlpha() const { return _pPixel[Image::OffsetAlpha]; }
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
		inline void StorePixel(unsigned char red, unsigned char green, unsigned char blue) {
			_pPixel[Image::OffsetRed] = red;
			_pPixel[Image::OffsetGreen] = green;
			_pPixel[Image::OffsetBlue] = blue;
		}
		inline void StorePixel(unsigned char red, unsigned char green, unsigned char blue,
						unsigned char alpha) {
			_pPixel[Image::OffsetRed] = red;
			_pPixel[Image::OffsetGreen] = green;
			_pPixel[Image::OffsetBlue] = blue;
			_pPixel[Image::OffsetAlpha] = alpha;
		}
	};
	class IteratorEach : public Iterator {
	private:
		Scanner _scanner;
		bool _doneFlag;
	public:
		inline IteratorEach(Object_image *pObjImage,
				size_t x, size_t y, size_t width, size_t height, Image::ScanDir scanDir) :
			Iterator(false),
			_scanner(pObjImage, x, y, width, height, scanDir), _doneFlag(false) {}
		virtual ~IteratorEach();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareObjectAccessor(image)
protected:
	Image::Format _format;
	size_t _width, _height;
	unsigned char *_buff;
	struct {
		size_t bitsPerPixel;
		size_t bytesPerPixel;
		size_t bytesPerLine;
	} _metrics;
	AutoPtr<Object_palette> _pObjPalette;
public:
	Object_image(Environment &env, Image::Format format);
	Object_image(Class *pClass, Image::Format format);
	Object_image(const Object_image &obj);
	virtual ~Object_image();
	virtual Object *Clone() const;
	inline bool IsValid() const { return _buff != NULL; }
	inline Image::Format GetFormat() const { return _format; }
	inline size_t GetWidth() const { return _width; }
	inline size_t GetHeight() const { return _height; }
	inline unsigned char *GetBuffer() { return _buff; }
	inline size_t GetBitsPerPixel() const { return _metrics.bitsPerPixel; }
	inline size_t GetBytesPerPixel() const { return _metrics.bytesPerPixel; }
	inline size_t GetBytesPerLine() const { return _metrics.bytesPerLine; }
	inline size_t GetBufferSize() const {
		return GetBytesPerLine() * _height;
	}
	inline unsigned char *GetPointer(size_t y) {
		return _buff + GetBytesPerLine() * y;
	}
	inline unsigned char *GetPointer(size_t x, size_t y) {
		return _buff + GetBytesPerLine() * y + GetBytesPerPixel() * x;
	}
	inline const unsigned char *GetPointer(size_t y) const {
		return _buff + GetBytesPerLine() * y;
	}
	inline const unsigned char *GetPointer(size_t x, size_t y) const {
		return _buff + GetBytesPerLine() * y + GetBytesPerPixel() * x;
	}
	inline Scanner *CreateScanner(size_t x, size_t y,
				size_t width, size_t height, Image::ScanDir scanDir = Image::SCAN_LeftTopHorz) {
		return new Scanner(dynamic_cast<Object_image *>(Object::Reference(this)),
											x, y, width, height, scanDir);
	}
	inline Scanner *CreateScanner(Image::ScanDir scanDir = Image::SCAN_LeftTopHorz) {
		return new Scanner(dynamic_cast<Object_image *>(Object::Reference(this)),
											0, 0, _width, _height, scanDir);
	}
	bool CheckEmpty(Signal sig) const;
	bool CheckValid(Signal sig) const;
	virtual bool DoPropDir(Signal sig, SymbolSet &symbols);
	virtual Value DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual Value DoPropSet(Signal sig, const Symbol *pSymbol,
									const Value &value, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	bool AllocBuffer(Signal sig, size_t width, size_t height, unsigned char fillValue);
	void FreeBuffer();
	inline bool CheckCoord(int x, int y) const {
		return 0 <= x && x < static_cast<int>(_width) &&
				0 <= y && y < static_cast<int>(_height);
	}
	bool CheckCoord(Signal sig, size_t x, size_t y) const;
	bool AdjustCoord(int &x, int &y, int &width, int &height) const;
	void PutPixel(unsigned char *buff, const Object_color *pObjColor);
	void GetPixel(const unsigned char *buff, Object_color *pObjColor);
	bool Store(Signal sig, size_t x, size_t y, size_t width, size_t height,
						const Symbol *pSymbol, const Object_matrix *pObjMat);
	bool Store(Signal sig, size_t x, size_t y, size_t width, size_t height,
						const Symbol *pSymbol, Iterator *pIterator);
	bool Extract(Signal sig, size_t x, size_t y, size_t width, size_t height,
				const Symbol *pSymbol, Object_matrix *pObjMat);
	bool Extract(Signal sig, size_t x, size_t y, size_t width, size_t height,
				const Symbol *pSymbol, Object_list *pObjList);
	void ReplaceColorRect(size_t x, size_t y, size_t width, size_t height,
				const Object_color *pObjColorOrg, const Object_color *pObjColor);
	inline void ReplaceColor(const Object_color *pObjColorOrg, const Object_color *pObjColor) {
		ReplaceColorRect(0, 0, _width, _height, pObjColorOrg, pObjColor);
	}
	void FillRect(size_t x, size_t y, size_t width, size_t height, const Object_color *pObjColor);
	inline void Fill(const Object_color *pObjColor) {
		FillRect(0, 0, _width, _height, pObjColor);
	}
	void FillRectAlpha(size_t x, size_t y, size_t width, size_t height,
				unsigned char alpha, const Object_color *pObjColor);
	inline void FillAlpha(unsigned char alpha, const Object_color *pObjColor) {
		FillRectAlpha(0, 0, _width, _height, alpha, pObjColor);
	}
	const Object_palette *GetPaletteObj() const { return _pObjPalette.get(); }
	Object_image *ReduceColor(Signal sig, const Object_palette *pObjPalette);
	Object_image *GrayScale(Signal sig);
	Object_image *Blur(Signal sig, int radius);
	Object_image *Flip(Signal sig, bool horzFlag, bool vertFlag);
	Object_image *Rotate90(Signal sig, bool clockwiseFlag);
	Object_image *Rotate(Signal sig, double angle, const Object_color *pObjColor);
	Object_image *Crop(Signal sig, size_t x, size_t y, size_t width, size_t height);
	Object_image *Resize(Signal sig, size_t width, size_t height);
	void Paste(size_t x, size_t y, Object_image *pObj,
		size_t width, size_t height, size_t xOffset, size_t yOffset, unsigned char alpha);
	Object_palette *CreateEmptyPalette(size_t nEntries);
	void SetPaletteObj(Object_palette *pObjPalette);
	bool Read(Signal sig, Stream &stream, const char *imgType);
	bool Write(Signal sig, Stream &stream, const char *imgType);
	int CalcDIBBitCount() const;
	static inline size_t CalcDIBPaletteSize(int biBitCount) {
		return (biBitCount <= 8)? (1 << biBitCount) * 4 : 0;
	}
	size_t CalcDIBImageSize(int biBitCount, bool maskFlag) const;
	bool ReadDIBPalette(Signal sig, Stream &stream, int biBitCount);
	bool WriteDIBPalette(Signal sig, Stream &stream, int biBitCount);
	bool ReadDIB(Signal sig, Stream &stream,
				int biWidth, int biHeight, int biBitCount, bool maskFlag);
	bool WriteDIB(Signal sig, Stream &stream, int biBitCount, bool maskFlag);
	size_t SymbolToPixelOffset(Signal sig, const Symbol *pSymbol) const;
	static Image::Format SymbolToFormat(Signal sig, const Symbol *pSymbol);
	static const Symbol *FormatToSymbol(Image::Format format);
	static inline unsigned char GetPixelGray(unsigned char *buff) {
		return Color::CalcGray(GetPixelR(buff), GetPixelG(buff), GetPixelB(buff));
	}
	static inline void StorePixel(unsigned char *buff,
					unsigned char red, unsigned char green, unsigned char blue) {
		*(buff + Image::OffsetRed) = red;
		*(buff + Image::OffsetGreen) = green;
		*(buff + Image::OffsetBlue) = blue;
	}
	static inline void StorePixel(unsigned char *buff,
					unsigned char red, unsigned char green, unsigned char blue,
					unsigned char alpha) {
		*(buff + Image::OffsetRed) = red;
		*(buff + Image::OffsetGreen) = green;
		*(buff + Image::OffsetBlue) = blue;
		*(buff + Image::OffsetAlpha) = alpha;
	}
	static inline void StorePixel(unsigned char *pPixelDst,
								const unsigned char *pPixelSrc, bool alphaFlag) {
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		if (alphaFlag) *pPixelDst++ = *pPixelSrc++;
	}
	static inline void StorePixelRGB(unsigned char *pPixelDst,
													const unsigned char *pPixelSrc) {
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
	}
	static inline void StorePixelRGBA(unsigned char *pPixelDst,
													const unsigned char *pPixelSrc) {
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
	}
	static inline void StorePixelRGBA(unsigned char *pPixelDst,
						const unsigned char *pPixelSrc, unsigned char alpha) {
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = *pPixelSrc++;
		*pPixelDst++ = alpha;
	}
	static inline unsigned char GetPixelR(const unsigned char *buff) {
		return *(buff + Image::OffsetRed);
	}
	static inline unsigned char GetPixelG(const unsigned char *buff) {
		return *(buff + Image::OffsetGreen);
	}
	static inline unsigned char GetPixelB(const unsigned char *buff) {
		return *(buff + Image::OffsetBlue);
	}
	static inline unsigned char GetPixelA(const unsigned char *buff) {
		return *(buff + Image::OffsetAlpha);
	}
	static inline void RotateCoord(int &xm, int &ym,
							int x, int y, int cos1024, int sin1024) {
		xm = (x * cos1024 - y * sin1024) >> 10;
		ym = (x * sin1024 + y * cos1024) >> 10;
	}
private:
	void InitMetrics();
	Object_image *CreateDerivation(Signal sig,
				size_t width, size_t height, Object_palette *pObjPalette = NULL);
};

//-----------------------------------------------------------------------------
// ImageStreamer
//-----------------------------------------------------------------------------
class DLLDECLARE ImageStreamer {
public:
	typedef std::vector<ImageStreamer *> List;
private:
	const char *_imgType;
	static List *_pList;
public:
	inline ImageStreamer(const char *imgType) : _imgType(imgType) {}
	inline const char *GetImgType() const { return _imgType; }
	virtual bool IsResponsible(Signal sig, Stream &stream) = 0;
	virtual bool Read(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream) = 0;
	virtual bool Write(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream) = 0;
public:
	static void Register(ImageStreamer *pImageStreamer);
	static ImageStreamer *FindResponsible(Signal sig, Stream &stream, const char *imgType);
	static ImageStreamer *FindByImgType(const char *imgType);
};

}

#endif
