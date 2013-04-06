#ifndef __GURA_PALETTE_H__
#define __GURA_PALETTE_H__

#include "Common.h"

namespace Gura {

class Image;

//-----------------------------------------------------------------------------
// Palette
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Palette {
public:
	enum {
		OffsetRed	= 2,
		OffsetGreen	= 1,
		OffsetBlue	= 0,
		OffsetAlpha	= 3,
	};
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
	unsigned char *_buff;
	OAL::Memory _memory;
	static const unsigned char _rgb_Mono[];
	static const unsigned char _rgb_Basic[];
	static const unsigned char _rgb_Win256[];
	static const unsigned char _rgb_WebSafe[];
public:
	inline static Palette *Reference(const Palette *pPalette) {
		if (pPalette == NULL) return NULL;
		Palette *pPaletteCasted = const_cast<Palette *>(pPalette);
		pPaletteCasted->_cntRef++;
		return pPaletteCasted;
	}
	inline static void Delete(Palette *pPalette) {
		if (pPalette == NULL) return;
		pPalette->_cntRef--;
		if (pPalette->_cntRef <= 0) delete pPalette;
	}
public:
	Palette();
	Palette(const Palette &palette);
private:
	virtual ~Palette();
public:
	inline unsigned char *GetBuff() { return _buff; }
	static inline size_t CalcBuffSize(size_t nEntries) { return nEntries * 4; }
	inline size_t GetBuffSize() const { return CalcBuffSize(_nEntries); }
	inline unsigned char *GetEntry(size_t idx) { return _buff + idx * 4; }
	inline const unsigned char *GetEntry(size_t idx) const { return _buff + idx * 4; }
	inline void SetEntry(size_t idx, unsigned char red,
			unsigned char green, unsigned char blue, unsigned char alpha = 255) {
		unsigned char *entry = GetEntry(idx);
		entry[OffsetRed] = red;
		entry[OffsetGreen] = green;
		entry[OffsetBlue] = blue;
		entry[OffsetAlpha] = alpha;
	}
	inline void SetEntry(size_t idx, const Color &c, unsigned char alpha = 255) {
		SetEntry(idx, c.GetRed(), c.GetGreen(), c.GetBlue(), alpha);
	}
	inline size_t CountEntries() const { return _nEntries; }
	void AllocBuff(size_t nEntries);
	void ResizeBuff(size_t nEntries, size_t nEntriesToCopy);
	bool Prepare(Signal sig, const Symbol *pSymbol);
	Value GetColorValue(Environment &env, size_t idx);
	void SetColor(size_t idx, const Color &color);
	size_t LookupNearest(unsigned char red, unsigned char green, unsigned char blue) const;
	bool UpdateByImage(const Image *pImage, ShrinkMode shrinkMode);
	bool UpdateByImage(Signal sig, const Image *pImage, ShrinkMode shrinkMode);
	bool UpdateByPalette(const Palette *pPalette, ShrinkMode shrinkMode);
	bool UpdateByPalette(Signal sig, const Palette *pPalette, ShrinkMode shrinkMode);
	void Shrink(size_t nEntries, bool alignFlag);
	inline size_t LookupNearest(const unsigned char *pPixel) const {
		return LookupNearest(pPixel[OffsetRed], pPixel[OffsetGreen], pPixel[OffsetBlue]);
	}
	inline size_t LookupNearest(const Color &color) const {
		return LookupNearest(color.GetRed(), color.GetGreen(), color.GetBlue());
	}
	size_t NextBlankIndex() const;
	size_t NextBlankIndex(ColorSet &colorSet) const;
};

}

#endif
