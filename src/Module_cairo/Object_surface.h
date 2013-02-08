#ifndef __CAIRO_OBJECT_SURFACE_H__
#define __CAIRO_OBJECT_SURFACE_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_surface declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(surface);

class Object_surface : public Object {
protected:
	cairo_surface_t *_surface;
public:
	Gura_DeclareObjectAccessor(surface)
public:
	inline Object_surface(cairo_surface_t *surface) :
				Object(Gura_UserClass(surface)), _surface(surface) {}
	virtual ~Object_surface();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_surface_t *GetEntity() { return _surface; }
};

}}

#endif
