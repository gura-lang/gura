#ifndef __CAIRO_OBJECT_FONT_OPTIONS_H__
#define __CAIRO_OBJECT_FONT_OPTIONS_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_font_options declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(font_options);

class Object_font_options : public Object {
private:
	cairo_font_options_t *_options;
public:
	Gura_DeclareObjectAccessor(font_options)
public:
	inline Object_font_options(cairo_font_options_t *options) :
					Object(Gura_UserClass(font_options)), _options(options) {}
	virtual ~Object_font_options();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline cairo_font_options_t *GetEntity() { return _options; }
};

Gura_EndModuleScope(cairo)

#endif
