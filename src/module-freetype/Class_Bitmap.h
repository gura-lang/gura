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
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Bitmap *GetEntity() { return _pBitmap; }
	inline const FT_Bitmap *GetEntity() const { return _pBitmap; }
};

Gura_EndModuleScope(freetype)

#endif
