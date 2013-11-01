#ifndef __CAIRO_CLASS_PS_SURFACE_H__
#define __CAIRO_CLASS_PS_SURFACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_ps_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ps_surface);

class Object_ps_surface : public Object_Writer_surface {
public:
	Gura_DeclareObjectAccessor(ps_surface)
public:
	inline Object_ps_surface(cairo_surface_t *surface, Writer *pWriter) :
				Object_Writer_surface(surface, pWriter) {}
};

Gura_EndModuleScope(cairo)

#endif
