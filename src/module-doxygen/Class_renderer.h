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
	inline Object_renderer(Renderer *pRenderer) :
					Object(Gura_UserClass(renderer)), _pRenderer(pRenderer) {}
	virtual ~Object_renderer();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(doxygen)

#endif
