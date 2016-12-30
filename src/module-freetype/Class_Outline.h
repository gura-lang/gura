#ifndef __FREETYPE_CLASS_OUTLINE_H__
#define __FREETYPE_CLASS_OUTLINE_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Outline declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Outline);

class Object_Outline : public Object {
public:
	Gura_DeclareObjectAccessor(Outline)
private:
	AutoPtr<Object> _pObjHolder;
	FT_Outline *_outline;
public:
	inline Object_Outline(Object *pObjHolder, FT_Outline *outline) :
			Object(Gura_UserClass(Outline)), _pObjHolder(pObjHolder), _outline(outline) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FT_Outline *GetEntity() { return _outline; }
	inline const FT_Outline *GetEntity() const { return _outline; }
};

Gura_EndModuleScope(freetype)

#endif
