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
public:
	Gura_DeclareReferenceAccessor(Renderer);
public:
	Renderer();
protected:
	inline ~Renderer() {}
public:
};

Gura_EndModuleScope(doxygen)

#endif
