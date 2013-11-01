#ifndef __CAIRO_CLASS_SVG_SURFACE_H__
#define __CAIRO_CLASS_SVG_SURFACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_svg_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(svg_surface);

class Object_svg_surface : public Object_Writer_surface {
public:
	Gura_DeclareObjectAccessor(svg_surface)
public:
	inline Object_svg_surface(cairo_surface_t *surface, Writer *pWriter) :
				Object_Writer_surface(surface, pWriter) {}
};

Gura_EndModuleScope(cairo)

#endif
