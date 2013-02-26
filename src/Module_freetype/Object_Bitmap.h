#ifndef __FREETYPE_OBJECT_BITMAP_H__
#define __FREETYPE_OBJECT_BITMAP_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Bitmap declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Bitmap);

class Object_Bitmap : public Object {
public:
	Gura_DeclareObjectAccessor(Bitmap)
private:
	FT_Bitmap _bitmap;
public:
	inline Object_Bitmap(const FT_Bitmap &bitmap) :
			Object(Gura_UserClass(Bitmap)), _bitmap(bitmap) {}
	inline Object_Bitmap(const Object_Bitmap &obj) :
			Object(obj), _bitmap(obj._bitmap) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Bitmap &GetEntity() { return _bitmap; }
	inline const FT_Bitmap &GetEntity() const { return _bitmap; }
};

}}

#endif
