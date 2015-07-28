#ifndef __FREETYPE_CLASS_FONT_H__
#define __FREETYPE_CLASS_FONT_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_font declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(font);

class Object_font : public Object {
public:
	enum Mode {
		MODE_Blend, MODE_Alpha,
	};
public:
	Gura_DeclareObjectAccessor(font)
private:
	AutoPtr<Object_Face> _pObjFace;
	AutoPtr<Object_color> _pObjColor;
	Mode _mode;
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
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline FT_Face &GetFace() { return _pObjFace->GetEntity(); }
	inline void SetColor(const Color &color) { _pObjColor->SetColor(color); }
	inline const Color &GetColor() const { return _pObjColor->GetColor(); }
	inline void SetMode(Mode mode) { _mode = mode; }
	inline Mode GetMode() const { return _mode; }
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
	bool CalcSize(Environment &env, const String &str,
					size_t &width, size_t &height, const Function *pFuncDeco);
	bool DrawOnImage(Environment &env, Signal &sig, Image *pImage, int x, int y,
					const String &str, const Function *pFuncDeco);
private:
	FT_Error LoadAndDecorateChar(Environment &env, Signal &sig,
				unsigned long codeUTF32, size_t idx, const Function *pFuncDeco);
	void DrawMonoOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset);
	void DrawGrayOnImage(Image *pImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset);
};

Gura_EndModuleScope(freetype)

#endif
