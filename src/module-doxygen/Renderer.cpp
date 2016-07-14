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

bool Renderer::EvalSpecialCommand(const CommandFormat *pCmdFmt, const ElemList &elemArgs,
								  const Configuration *pCfg, SimpleStream &stream)
{
	Environment &env = *_pObjAssoc;
	Signal &sig = env.GetSignal();
	const Function *pFunc = _pObjAssoc->LookupFunction(pCmdFmt->GetSymbolEx(), ENVREF_Escalate);
	if (pFunc == nullptr) return true;
	ValueList valListArg;
	valListArg.reserve(elemArgs.size());
	foreach_const (ElemList, ppElemArg, elemArgs) {
		const Elem *pElemArg = *ppElemArg;
		String strArg;
		SimpleStream_StringWriter streamArg(strArg);
		if (!pElemArg->Render(this, pCfg, streamArg)) return false;
		valListArg.push_back(Value(strArg));
	}
	Value value = _pObjAssoc->EvalMethod(env, pFunc, valListArg);
	if (value.Is_string()) {
		stream.Print(sig, value.GetString());
	}
	return env.IsNoSignalled();
}

Gura_EndModuleScope(doxygen)
