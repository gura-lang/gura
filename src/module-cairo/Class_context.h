#ifndef __CLASS_CAIRO_CONTEXT_H__
#define __CLASS_CAIRO_CONTEXT_H__

Gura_BeginModuleScope(cairo)

class Writer;
class Object_surface;

//-----------------------------------------------------------------------------
// Object_context declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(context);

class Object_context : public Object {
private:
	cairo_t *_cr;
	AutoPtr<Object_surface> _pObjSurface;
	AutoPtr<Object_surface> _pObjSurfaceSrc;
public:
	Gura_DeclareObjectAccessor(context)
public:
	inline Object_context(cairo_t *cr, Object_surface *pObjSurface) :
		Object(Gura_UserClass(context)), _cr(cr), _pObjSurface(pObjSurface) {}
	virtual ~Object_context();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline cairo_t *GetEntity() { return _cr; }
	inline Object_surface *GetSurfaceObj() { return _pObjSurface.get(); }
	inline void SetSurfaceSrcObj(Object_surface *pObjSurfaceSrc) {
		_pObjSurfaceSrc.reset(pObjSurfaceSrc);
	}
	void Destroy();
};

Gura_EndModuleScope(cairo)

#endif
