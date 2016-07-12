//=============================================================================
// Class_renderer.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CLASS_RENDERER_H__
#define __GURA_DOXYGEN_CLASS_RENDERER_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// doxygen.renderer class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(renderer);

class Object_renderer : public Object {
public:
	Gura_DeclareObjectAccessor(renderer)
private:
	AutoPtr<Renderer> _pRenderer;
public:
	inline Object_renderer(Class *pClass) : Object(pClass) {}
	inline Object_renderer() : Object(Gura_UserClass(renderer)) {}
	virtual ~Object_renderer();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline void SetRenderer(Renderer *pRenderer) { _pRenderer.reset(pRenderer); }
	inline Renderer *GetRenderer() { return _pRenderer.get(); }
};

Gura_EndModuleScope(doxygen)

#endif
