#ifndef __FREETYPE_CLASS_BITMAP_H__
#define __FREETYPE_CLASS_BITMAP_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Bitmap declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Bitmap);

class Object_Bitmap : public Object {
public:
	Gura_DeclareObjectAccessor(Bitmap)
private:
	AutoPtr<Object> _pObjHolder;
	FT_Bitmap *_pBitmap;
public:
	inline Object_Bitmap(Object *pObjHolder, FT_Bitmap *pBitmap) :
			Object(Gura_UserClass(Bitmap)), _pObjHolder(pObjHolder), _pBitmap(pBitmap) {}
	~Object_Bitmap();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FT_Bitmap *GetEntity() { return _pBitmap; }
	inline const FT_Bitmap *GetEntity() const { return _pBitmap; }
};

Gura_EndModuleScope(freetype)

#endif
