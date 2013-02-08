#ifndef __CAIRO_OBJECT_SVG_SURFACE_H__
#define __CAIRO_OBJECT_SVG_SURFACE_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_svg_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(svg_surface);

class Object_svg_surface : public Object_Writer_surface {
public:
	inline Object_svg_surface(cairo_surface_t *surface, Writer *pWriter) :
				Object_Writer_surface(surface, pWriter) {}
};

}}

#endif
