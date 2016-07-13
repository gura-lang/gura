//=============================================================================
// Renderer.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Renderer
//-----------------------------------------------------------------------------
Renderer::Renderer(Object *pObjAssoc) : _cntRef(1), _pObjAssoc(pObjAssoc)
{
}

bool Renderer::Render(const Elem *pElem, const Configuration *pCfg, SimpleStream &stream)
{
	return pElem->Render(this, pCfg, stream);
}

bool Renderer::EvalSpecialCommand(const ElemList &elemArgs, const Configuration *pCfg, SimpleStream &stream)
{
	return true;
}

Gura_EndModuleScope(doxygen)
