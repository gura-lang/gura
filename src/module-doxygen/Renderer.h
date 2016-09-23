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
	AutoPtr<Stream> _pStream;
	AutoPtr<Configuration> _pCfg;
public:
	Gura_DeclareReferenceAccessor(Renderer);
public:
	Renderer(Object *pObjAssoc);
protected:
	inline ~Renderer() {}
public:
	inline Signal &GetSignal() { return _pObjAssoc->GetSignal(); }
	inline Object *GetObjectAssoc() { return _pObjAssoc; }
	inline void SetStream(Stream *pStream) { _pStream.reset(pStream); }
	inline void SetConfiguration(Configuration *pCfg) { _pCfg.reset(pCfg); }
	inline Stream *GetStream() { return _pStream.get(); }
	inline Configuration *GetConfiguration() { return _pCfg.get(); }
};

Gura_EndModuleScope(doxygen)

#endif
