#ifndef __CAIRO_OBJECT_WIN32_SURFACE_H__
#define __CAIRO_OBJECT_WIN32_SURFACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_win32_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(win32_surface);

class Object_win32_surface : public Object_Writer_surface {
public:
	inline Object_win32_surface(cairo_surface_t *surface, Writer *pWriter) :
				Object_Writer_surface(surface, pWriter) {}
};

Gura_EndModuleScope(cairo)

#endif
