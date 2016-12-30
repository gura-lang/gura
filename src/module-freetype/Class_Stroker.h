#ifndef __FREETYPE_CLASS_STROKER_H__
#define __FREETYPE_CLASS_STROKER_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Stroker declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Stroker);

class Object_Stroker : public Object {
public:
	Gura_DeclareObjectAccessor(Stroker)
private:
	FT_Stroker _stroker;
public:
	inline Object_Stroker() : Object(Gura_UserClass(Stroker)) {}
	~Object_Stroker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FT_Stroker &GetEntity() { return _stroker; }
	inline const FT_Stroker &GetEntity() const { return _stroker; }
};

Gura_EndModuleScope(freetype)

#endif
