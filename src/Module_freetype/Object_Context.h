#ifndef __FREETYPE_OBJECT_CONTEXT_H__
#define __FREETYPE_OBJECT_CONTEXT_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Context declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Context);

class Object_Context : public Object {
public:
	Gura_DeclareObjectAccessor(Context)
private:
	Handler *_pHandler;
	FT_Face _face;
	Color _color;
	unsigned char _alpha;
	struct {
		double strength;
		double slant;
		struct {
			double cosNum, sinNum;
		} rotate;
	} _deco;
public:
	inline Object_Context() : Object(Gura_UserClass(Context)),
								_pHandler(NULL), _face(NULL), _alpha(255) {
		ClearDeco();
	}
	virtual ~Object_Context();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetColor(const Color &color) { _color = color; }
	inline void SetAlpha(unsigned char alpha) { _alpha = alpha; }
	inline const Color &GetColor() const { return _color; }
	inline unsigned char GetAlpha() const { return _alpha; }
	inline FT_Face &GetFace() { return _face; }
	inline void ClearDeco() {
		_deco.strength = 0;
		_deco.slant = 0;
		_deco.rotate.cosNum = 1., _deco.rotate.sinNum = 0;
	}
	bool Initialize(Signal sig, Stream *pSstream, int index);
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
