#ifndef __GURA_OBJECT_PALETTE_H__
#define __GURA_OBJECT_PALETTE_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_palette
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_palette : public Class {
public:
	Class_palette(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_palette
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_palette : public Object {
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
		AutoPtr<Object_palette> _pObjPalette;
		size_t _idx;
	public:
		inline IteratorEach(Object_palette *pObjPalette) :
			Iterator(false), _pObjPalette(pObjPalette), _idx(0) {}
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareObjectAccessor(palette)
private:
	size_t _nEntries;
	unsigned char *_buff;
	OAL::Memory _memory;
	static const unsigned char _rgb_Mono[];
	static const unsigned char _rgb_Basic[];
	static const unsigned char _rgb_Win256[];
	static const unsigned char _rgb_WebSafe[];
public:
	inline Object_palette(Class *pClass) :
						Object(pClass), _nEntries(0), _buff(NULL) {}
	Object_palette(Environment &env, size_t nEntries = 0);
	Object_palette(const Object_palette &obj);
	virtual ~Object_palette();
	virtual Object *Clone() const;
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
	virtual Iterator *CreateIterator(Signal sig);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value);
	Value GetColorValue(size_t idx);
	void SetColorObj(size_t idx, const Object_color *pObjColor);
	size_t LookupNearest(unsigned char red, unsigned char green, unsigned char blue) const;
	bool UpdateByImage(const Object_image *pObjImage, ShrinkMode shrinkMode);
	bool UpdateByImage(Signal sig, const Object_image *pObjImage, ShrinkMode shrinkMode);
	bool UpdateByPalette(const Object_palette *pObjPalette, ShrinkMode shrinkMode);
	bool UpdateByPalette(Signal sig, const Object_palette *pObjPalette, ShrinkMode shrinkMode);
	void Shrink(size_t nEntries, bool alignFlag);
	inline size_t LookupNearest(const unsigned char *pPixel) const {
		return LookupNearest(pPixel[OffsetRed], pPixel[OffsetGreen], pPixel[OffsetBlue]);
	}
	inline size_t LookupNearest(const Color &color) const {
		return LookupNearest(color.GetRed(), color.GetGreen(), color.GetBlue());
	}
	inline size_t LookupNearest(const Object_color *pObjColor) const {
		return LookupNearest(pObjColor->GetRed(), pObjColor->GetGreen(), pObjColor->GetBlue());
	}
	size_t NextBlankIndex() const;
	size_t NextBlankIndex(ColorSet &colorSet) const;
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
