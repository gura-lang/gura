#ifndef __FREETYPE_OBJECT_FONT_H__
#define __FREETYPE_OBJECT_FONT_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_font declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(font);

class Object_font : public Object {
public:
	Gura_DeclareObjectAccessor(font)
private:
	AutoPtr<Object_Face> _pObjFace;
	Color _color;
	bool _blendingFlag;
	struct {
		double strength;
		double slant;
		struct {
			double cosNum, sinNum;
		} rotate;
	} _deco;
public:
	Object_font(Object_Face *pObjFace);
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetColor(const Color &color, bool blendingFlag) {
		_color = color, _blendingFlag = blendingFlag;
	}
	inline const Color &GetColor() const { return _color; }
	inline int GetBlendingFlag() const { return _blendingFlag; }
	inline FT_Face &GetFace() { return _pObjFace->GetEntity(); }
	inline void ClearDeco() {
		_deco.strength = 0;
		_deco.slant = 0;
		_deco.rotate.cosNum = 1., _deco.rotate.sinNum = 0;
	}
	bool SetPixelSizes(Signal sig, size_t width, size_t height);
	bool CalcSize(Signal sig, const String &str, size_t &width, size_t &height);
	bool DrawOnImage(Signal sig, Image *pImage, int x, int y, const String &str);
	inline void SetStrength(double strength) { _deco.strength = strength; }
	inline void SetSlant(double slant) { _deco.slant = slant; }
	inline void SetRotate(double degree) {
		double rad = degree * 3.14159265358979323846 / 180;
		_deco.rotate.cosNum = ::cos(rad);
		_deco.rotate.sinNum = ::sin(rad);
	}
private:
	FT_GlyphSlot LoadChar(unsigned long codeUTF32);
	void DrawMonoOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset);
	void DrawGrayOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset);
};

}}

#endif
