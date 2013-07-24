#ifndef __GURA_PALETTE_H__
#define __GURA_PALETTE_H__

#include "Common.h"
#include "Image.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Palette
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Palette {
public:
	enum ShrinkMode {
		ShrinkNone,
		ShrinkAlign,
		ShrinkMinimum,
	};
public:
	class IteratorEach : public Iterator {
	private:
		AutoPtr<Palette> _pPalette;
		size_t _idx;
	public:
		inline IteratorEach(Palette *pPalette) :
					Iterator(false), _pPalette(pPalette), _idx(0) {}
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
private:
	int _cntRef;
	size_t _nEntries;
	UChar *_buff;
	AutoPtr<Memory> _pMemory;
	static const UChar _rgb_Mono[];
	static const UChar _rgb_Basic[];
	static const UChar _rgb_Win256[];
	static const UChar _rgb_WebSafe[];
public:
	Gura_DeclareReferenceAccessor(Palette);
public:
	Palette();
	Palette(const Palette &palette);
private:
	virtual ~Palette();
public:
	inline UChar *GetBuff() { return _buff; }
	static inline size_t CalcBuffSize(size_t nEntries) { return nEntries * 4; }
	inline size_t GetBuffSize() const { return CalcBuffSize(_nEntries); }
	inline UChar *GetEntry(size_t idx) { return _buff + idx * 4; }
	inline const UChar *GetEntry(size_t idx) const { return _buff + idx * 4; }
	inline void SetEntry(size_t idx, UChar red,
			UChar green, UChar blue, UChar alpha = 255) {
		UChar *entry = GetEntry(idx);
		entry[Image::OffsetRed] = red;
		entry[Image::OffsetGreen] = green;
		entry[Image::OffsetBlue] = blue;
		entry[Image::OffsetAlpha] = alpha;
	}
	inline void SetEntry(size_t idx, const Color &c, UChar alpha = 255) {
		SetEntry(idx, c.GetRed(), c.GetGreen(), c.GetBlue(), alpha);
	}
	inline size_t CountEntries() const { return _nEntries; }
	void AllocBuff(size_t nEntries);
	void ResizeBuff(size_t nEntries, size_t nEntriesToCopy);
	bool Prepare(Signal sig, const Symbol *pSymbol);
	Value GetColorValue(Environment &env, size_t idx);
	void SetColor(size_t idx, const Color &color);
	size_t LookupNearest(UChar red, UChar green, UChar blue) const;
	bool UpdateByImage(const Image *pImage, ShrinkMode shrinkMode);
	bool UpdateByImage(Signal sig, const Image *pImage, ShrinkMode shrinkMode);
	bool UpdateByPalette(const Palette *pPalette, ShrinkMode shrinkMode);
	bool UpdateByPalette(Signal sig, const Palette *pPalette, ShrinkMode shrinkMode);
	void Shrink(size_t nEntries, bool alignFlag);
	inline size_t LookupNearest(const UChar *pPixel) const {
		return LookupNearest(pPixel[Image::OffsetRed], pPixel[Image::OffsetGreen], pPixel[Image::OffsetBlue]);
	}
	inline size_t LookupNearest(const Color &color) const {
		return LookupNearest(color.GetRed(), color.GetGreen(), color.GetBlue());
	}
	size_t NextBlankIndex() const;
	size_t NextBlankIndex(ColorSet &colorSet) const;
};

}

#endif
