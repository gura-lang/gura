//-----------------------------------------------------------------------------
// Gura freetype module
//-----------------------------------------------------------------------------
#ifndef __MODULE_FREETYPE_H__
#define __MODULE_FREETYPE_H__
#include <gura.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_BITMAP_H
#include FT_OUTLINE_H
#include FT_GLYPH_H

#if defined(HAVE_WINDOWS_H)
#include <shlobj.h>
#endif

Gura_BeginModule(freetype)

Gura_DeclareUserSymbol(num_faces);
Gura_DeclareUserSymbol(face_index);
Gura_DeclareUserSymbol(face_flags);
Gura_DeclareUserSymbol(style_flags);
Gura_DeclareUserSymbol(num_glyphs);
Gura_DeclareUserSymbol(family_name);
Gura_DeclareUserSymbol(style_name);
Gura_DeclareUserSymbol(num_fixed_sizes);
Gura_DeclareUserSymbol(available_sizes);
Gura_DeclareUserSymbol(num_charmaps);
Gura_DeclareUserSymbol(charmaps);
Gura_DeclareUserSymbol(generic);
Gura_DeclareUserSymbol(bbox);
Gura_DeclareUserSymbol(units_per_EM);
Gura_DeclareUserSymbol(ascender);
Gura_DeclareUserSymbol(descender);
Gura_DeclareUserSymbol(height);
Gura_DeclareUserSymbol(max_advance_width);
Gura_DeclareUserSymbol(max_advance_height);
Gura_DeclareUserSymbol(underline_position);
Gura_DeclareUserSymbol(underline_thickness);
Gura_DeclareUserSymbol(glyph);
Gura_DeclareUserSymbol(size);
Gura_DeclareUserSymbol(charmap);

//-----------------------------------------------------------------------------
// Handler
//-----------------------------------------------------------------------------
class Handler {
private:
	Signal _sig;
	Stream *_pStream;
	FT_StreamRec *_pStreamRec;
public:
	inline Handler(Signal sig, Stream *pStream) :
			_sig(sig), _pStream(pStream), _pStreamRec(new FT_StreamRec) {}
	~Handler();
	bool OpenFace(Signal sig, int index, FT_Face *aface);
private:
	FT_ULong Read(FT_ULong pos, FT_Byte *buffer, FT_ULong count);
	static FT_ULong ReadStub(FT_Stream streamFT,
				FT_ULong pos, FT_Byte *buffer, FT_ULong count);
};

//-----------------------------------------------------------------------------
// Object_Face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Face);

class Object_Face : public Object {
public:
	Gura_DeclareObjectAccessor(Face)
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
	inline Object_Face() : Object(Gura_UserClass(Face)),
								_pHandler(NULL), _face(NULL), _alpha(255) {
		ClearDeco();
	}
	virtual ~Object_Face();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
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
	bool DrawOnImage(Signal sig,
				Object_image *pObjImage, int x, int y, const String &str);
	inline void SetStrength(double strength) { _deco.strength = strength; }
	inline void SetSlant(double slant) { _deco.slant = slant; }
	inline void SetRotate(double degree) {
		double rad = degree * 3.14159265358979323846 / 180;
		_deco.rotate.cosNum = ::cos(rad);
		_deco.rotate.sinNum = ::sin(rad);
	}
private:
	FT_GlyphSlot LoadChar(unsigned long codeUTF32);
	void DrawMonoOnImage(Object_image *pObjImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset);
	void DrawGrayOnImage(Object_image *pObjImage, int x, int y,
				unsigned char *buffer, int width, int height, int pitch,
				int xOffset, int yOffset);
};

}}

#endif
