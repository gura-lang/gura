#ifndef __FREETYPE_CLASS_CHARMAP_H__
#define __FREETYPE_CLASS_CHARMAP_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_CharMap declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(CharMap);

class Object_CharMap : public Object {
public:
	Gura_DeclareObjectAccessor(CharMap)
private:
	FT_CharMap _charMap;
public:
	inline Object_CharMap(const FT_CharMap &charMap) :
			Object(Gura_UserClass(CharMap)), _charMap(charMap) {}
	inline Object_CharMap(const Object_CharMap &obj) :
			Object(obj), _charMap(obj._charMap) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FT_CharMap &GetEntity() { return _charMap; }
	inline const FT_CharMap &GetEntity() const { return _charMap; }
};

Gura_EndModuleScope(freetype)

#endif
