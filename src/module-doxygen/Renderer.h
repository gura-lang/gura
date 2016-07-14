//=============================================================================
// Renderer.h
//=============================================================================
#ifndef __GURA_DOXYGEN_RENDERER_H__
#define __GURA_DOXYGEN_RENDERER_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Renderer
//-----------------------------------------------------------------------------
class Renderer {
protected:
	int _cntRef;
	Object *_pObjAssoc;
public:
	Gura_DeclareReferenceAccessor(Renderer);
public:
	Renderer(Object *pObjAssoc);
protected:
	inline ~Renderer() {}
public:
	inline Signal &GetSignal() { return _pObjAssoc->GetSignal(); }
	inline Object *GetObjectAssoc() { return _pObjAssoc; }
};

Gura_EndModuleScope(doxygen)

#endif
