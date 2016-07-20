//=============================================================================
// Gura module: doxygen
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(doxygen)

AutoPtr<Function> g_pFunc_Presenter;

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// doxygen.setpresenter():void {block}
Gura_DeclareFunction(setpresenter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets a presentation procedure that shows helps written in Doxygen format.\n"
		"The procedure is written in the function's block that takes block parameters:\n"
		"`|title:string:nil, doc:doxygen.document:nil|`.\n"
	);
}

Gura_ImplementFunction(setpresenter)
{
	Signal &sig = env.GetSignal();
	const Function *pFuncBlock = arg.GetBlockFunc(env, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Nil;
	g_pFunc_Presenter.reset(pFuncBlock->Reference());
	return Value::Nil;
}

// doxygen.makescript(stream?:stream:w):void
Gura_DeclareFunction(makescript)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementFunction(makescript)
{
	Stream &stream = arg.IsValid(0)? arg.GetStream(0) : *env.GetConsole();
	CommandFormat::MakeScript(env, stream);
	return Value::Nil;
}

// doxygen.test(stream:stream):void
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
}

Gura_ImplementFunction(test)
{
	Stream &stream = arg.GetStream(0);
	AutoPtr<Configuration> pCfg(new Configuration());
	pCfg->ReadStream(env, stream);
	//cfg.Print();
	AutoPtr<Aliases> pAliases(pCfg->MakeAliases(env));
	pAliases->Print();
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// HelpPresenter_doxygen
//-----------------------------------------------------------------------------
bool HelpPresenter_doxygen::DoPresent(Environment &env,
									  const char *title, const Help *pHelp) const
{
	if (g_pFunc_Presenter.IsNull()) {
		env.SetError(ERR_FormatError, "presenter function is not registered");
		return false;
	}
	AutoPtr<Argument> pArg(new Argument(g_pFunc_Presenter.get()));
	if (title == nullptr) {
		if (!pArg->StoreValue(env, Value::Nil)) return false;
	} else {
		if (!pArg->StoreValue(env, Value(title))) return false;
	}
	if (pHelp == nullptr) {
		if (!pArg->StoreValue(env, Value::Nil)) return false;
	} else {
		const char *text = pHelp->GetText();
		AutoPtr<Document> pDocument(new Document());
		SimpleStream_CStringReader streamSrc(text);
		const Aliases *pAliases = nullptr;
		bool extractedFlag = true;
		if (!pDocument->ReadStream(env, streamSrc, pAliases, extractedFlag)) return false;
		if (!pArg->StoreValue(env, Value(new Object_document(pDocument->Reference())))) return false;
	}
	g_pFunc_Presenter->Eval(env, *pArg);
	return env.IsNoSignalled();
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	Elem::Initialize();
	CommandFormat::Initialize();
	// symbol realization
	Gura_RealizeUserSymbol(aliases);
	Gura_RealizeUserSymbol(elem);
	Gura_RealizeUserSymbol(structures);
	// class realization
	Gura_RealizeUserClass(elem, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(structure, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(document, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(configuration, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(aliases, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(renderer, env.LookupClass(VTYPE_object));
	// class preparation
	Gura_PrepareUserClass(elem);
	Gura_PrepareUserClass(structure);
	Gura_PrepareUserClass(document);
	Gura_PrepareUserClass(configuration);
	Gura_PrepareUserClass(aliases);
	Gura_PrepareUserClass(renderer);
	// function assignment
	Gura_AssignFunction(setpresenter);
	Gura_AssignFunction(makescript);
	Gura_AssignFunction(test);
	// registoration of HelpPresenter
	HelpPresenter::Register(env, new HelpPresenter_doxygen());
	return true;
}

Gura_ModuleTerminate()
{
	g_pFunc_Presenter.reset(nullptr);
}

Gura_EndModuleBody(doxygen, doxygen)

Gura_RegisterModule(doxygen)
