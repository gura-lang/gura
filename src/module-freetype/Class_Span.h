#ifndef __FREETYPE_CLASS_SPAN_H__
#define __FREETYPE_CLASS_SPAN_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Span declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Span);

class Object_Span : public Object {
public:
	Gura_DeclareObjectAccessor(Span)
private:
	FT_Span _span;
public:
	inline Object_Span(const FT_Span &span) :
			Object(Gura_UserClass(Span)), _span(span) {}
	inline Object_Span(const Object_Span &obj) :
			Object(obj), _span(obj._span) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FT_Span &GetEntity() { return _span; }
	inline const FT_Span &GetEntity() const { return _span; }
};

Gura_EndModuleScope(freetype)

#endif
