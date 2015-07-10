#ifndef __CAIRO_CLASS_SURFACE_H__
#define __CAIRO_CLASS_SURFACE_H__

Gura_BeginModuleScope(cairo)

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
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline cairo_surface_t *GetEntity() { return _surface; }
};

Gura_EndModuleScope(cairo)

#endif
