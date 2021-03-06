#ifndef __FREETYPE_CLASS_GLYPH_H__
#define __FREETYPE_CLASS_GLYPH_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Glyph declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Glyph);

class Object_Glyph : public Object {
public:
	Gura_DeclareObjectAccessor(Glyph)
private:
	AutoPtr<Object> _pObjHolder;
	FT_Glyph *_pGlyph;
public:
	inline Object_Glyph(Object *pObjHolder, FT_Glyph *pGlyph) :
			Object(Gura_UserClass(Glyph)), _pObjHolder(pObjHolder), _pGlyph(pGlyph) {}
	~Object_Glyph();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FT_Glyph *GetEntity() { return _pGlyph; }
	inline const FT_Glyph *GetEntity() const { return _pGlyph; }
};

Gura_EndModuleScope(freetype)

#endif
