//=============================================================================
// Gura module: codecs
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(codecs)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// codecs.dir()
Gura_DeclareFunction(dir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"returns a list that contains registered encodings."
	);
}

Gura_ImplementFunction(dir)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	const CodecFactory::List *pList = CodecFactory::GetList();
	if (pList != NULL) {
		foreach_const (CodecFactory::List, ppFactory, *pList) {
			CodecFactory *pFactory = *ppFactory;
			valList.push_back(Value(pFactory->GetEncoding()));
		}
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(dir);
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(codecs, codecs)

Gura_RegisterModule(codecs)
