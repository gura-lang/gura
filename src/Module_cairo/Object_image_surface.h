#ifndef __CAIRO_OBJECT_IMAGE_SURFACE_H__
#define __CAIRO_OBJECT_IMAGE_SURFACE_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_image_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(image_surface);

class Object_image_surface : public Object_surface {
private:
	AutoPtr<Image> _pImage;	// maybe NULL
public:
	Gura_DeclareObjectAccessor(image_surface)
public:
	inline Object_image_surface(cairo_surface_t *surface, Image *pImage) :
				Object_surface(surface), _pImage(pImage) {}
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
};

}}

#endif
