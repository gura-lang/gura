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
	AutoPtr<Object_color> _pObjColor;
	bool _blendingFlag;
	FT_UInt _width, _height;
	double _strength;
	double _slant;
	struct {
		double deg;
		double cosNum, sinNum;
	} _rotate;
public:
	Object_font(Object_Face *pObjFace, Object_color *pObjColor);
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline FT_Face &GetFace() { return _pObjFace->GetEntity(); }
	inline void SetColor(const Color &color) { _pObjColor->SetColor(color); }
	inline const Color &GetColor() const { return _pObjColor->GetColor(); }
	inline void SetBlendingFlag(bool blendingFlag) { _blendingFlag = blendingFlag; }
	inline int GetBlendingFlag() const { return _blendingFlag; }
	inline void SetWidth(FT_UInt width) { _width = width; }
	inline void SetHeight(FT_UInt height) { _height = height; }
	inline FT_UInt GetWidth() const { return _width; }
	inline FT_UInt GetHeight() const { return _height; }
	inline void SetStrength(double strength) { _strength = strength; }
	inline double GetStrength() const { return _strength; }
	inline void SetSlant(double slant) { _slant = slant; }
	inline double GetSlant() const { return _slant; }
	inline void SetRotate(double deg) {
		_rotate.deg = deg;
		double rad = deg * 3.14159265358979323846 / 180;
		_rotate.cosNum = ::cos(rad);
		_rotate.sinNum = ::sin(rad);
	}
	inline double GetRotate() const { return _rotate.deg; }
	void ClearDeco();
	bool CalcSize(Environment &env, Signal sig, const String &str,
					size_t &width, size_t &height, const Function *pFuncDeco);
	bool DrawOnImage(Environment &env, Signal sig, Image *pImage, int x, int y,
					const String &str, const Function *pFuncDeco);
private:
	FT_Error LoadAndDecorateChar(Environment &env, Signal sig,
				unsigned long codeUTF32, size_t idx, const Function *pFuncDeco);
	void DrawMonoOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset);
	void DrawGrayOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset);
};

}}

#endif
