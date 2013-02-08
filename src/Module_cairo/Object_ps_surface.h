#ifndef __CAIRO_OBJECT_PS_SURFACE_H__
#define __CAIRO_OBJECT_PS_SURFACE_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_ps_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ps_surface);

class Object_ps_surface : public Object_Writer_surface {
public:
	inline Object_ps_surface(cairo_surface_t *surface, Writer *pWriter) :
				Object_Writer_surface(surface, pWriter) {}
};

}}

#endif
