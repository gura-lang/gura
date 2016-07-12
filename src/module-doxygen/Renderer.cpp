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

bool Renderer::Render(const Elem *pElem, Stream &stream)
{
	return true;
}

Gura_EndModuleScope(doxygen)
