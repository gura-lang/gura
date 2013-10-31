#ifndef __CAIRO_OBJECT_PATTERN_H__
#define __CAIRO_OBJECT_PATTERN_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_pattern declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(pattern);

class Object_pattern : public Object {
private:
	cairo_pattern_t *_pattern;
public:
	Gura_DeclareObjectAccessor(pattern)
public:
	inline Object_pattern(cairo_pattern_t *pattern) :
						Object(Gura_UserClass(pattern)), _pattern(pattern) {}
	virtual ~Object_pattern();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_pattern_t *GetEntity() { return _pattern; }
};

Gura_EndModuleScope(cairo)

#endif
