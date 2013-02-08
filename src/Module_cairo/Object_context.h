#ifndef __OBJECT_CAIRO_CONTEXT_H__
#define __OBJECT_CAIRO_CONTEXT_H__

Gura_BeginModule(cairo)

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
public:
	Gura_DeclareObjectAccessor(context)
public:
	inline Object_context(cairo_t *cr, Object_surface *pObjSurface) :
		Object(Gura_UserClass(context)), _cr(cr), _pObjSurface(pObjSurface) {}
	virtual ~Object_context();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_t *GetEntity() { return _cr; }
	inline Object_surface *GetSurfaceObj() { return _pObjSurface.get(); }
	void Destroy();
};

}}

#endif
