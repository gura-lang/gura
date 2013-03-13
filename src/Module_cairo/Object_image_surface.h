#ifndef __CAIRO_OBJECT_IMAGE_SURFACE_H__
#define __CAIRO_OBJECT_IMAGE_SURFACE_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_image_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(image_surface);

class Object_image_surface : public Object_surface {
private:
	AutoPtr<Object_image> _pObjImage;	// maybe NULL
public:
	Gura_DeclareObjectAccessor(image_surface)
public:
	inline Object_image_surface(cairo_surface_t *surface, Object_image *pObjImage) :
				Object_surface(surface), _pObjImage(pObjImage) {}
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
};

}}

#endif
