#ifndef __CAIRO_OBJECT_PDF_SURFACE_H__
#define __CAIRO_OBJECT_PDF_SURFACE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_pdf_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(pdf_surface);

class Object_pdf_surface : public Object_Writer_surface {
public:
	Gura_DeclareObjectAccessor(pdf_surface)
public:
	inline Object_pdf_surface(cairo_surface_t *surface, Writer *pWriter) :
				Object_Writer_surface(surface, pWriter) {}
};

Gura_EndModuleScope(cairo)

#endif
