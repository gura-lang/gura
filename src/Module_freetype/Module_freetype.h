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
Gura_DeclareUserSymbol(face_flag_scalable);
Gura_DeclareUserSymbol(face_flag_fixed_width);
Gura_DeclareUserSymbol(face_flag_sfnt);
Gura_DeclareUserSymbol(face_flag_horizontal);
Gura_DeclareUserSymbol(face_flag_vertical);
Gura_DeclareUserSymbol(face_flag_kerning);
Gura_DeclareUserSymbol(face_flag_fast_glyphs);
Gura_DeclareUserSymbol(face_flag_multiple_masters);
Gura_DeclareUserSymbol(face_flag_glyph_names);
Gura_DeclareUserSymbol(face_flag_external_stream);
Gura_DeclareUserSymbol(face_flag_hinter);
Gura_DeclareUserSymbol(face_flag_cid_keyed);
Gura_DeclareUserSymbol(face_flag_tricky);
Gura_DeclareUserSymbol(style_flag_italic);
Gura_DeclareUserSymbol(style_flag_bold);
Gura_DeclareUserSymbol(family_name);
Gura_DeclareUserSymbol(style_name);
Gura_DeclareUserSymbol(bbox);
Gura_DeclareUserSymbol(ascender);
Gura_DeclareUserSymbol(descender);
Gura_DeclareUserSymbol(height);

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
// Object_face declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(face);

class Object_face : public Object {
public:
	Gura_DeclareObjectAccessor(face)
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
	inline Object_face() : Object(Gura_UserClass(face)),
								_pHandler(NULL), _face(NULL), _alpha(255) {
		ClearDeco();
	}
	virtual ~Object_face();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
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
	bool Initialize(Signal sig, const char *pathName, int index);
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
