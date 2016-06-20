//=============================================================================
// Gura module: doxygen
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(doxygen)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// doxygen.test(stream:stream):void:map
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(test)
{
	Parser parser(nullptr);
	const char *result = parser.ParseStream(env, arg.GetStream(0));
	if (result != nullptr) {
		::printf("%s\n", result);
	}
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// HelpPresenter_doxygen
//-----------------------------------------------------------------------------
bool HelpPresenter_doxygen::DoPresent(Environment &env,
									  const char *title, const Help *pHelp) const
{
#if 0
	Signal &sig = env.GetSignal();
	if (g_pFunc_Presenter.IsNull()) {
		sig.SetError(ERR_FormatError, "presenter function is not registered");
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
		AutoPtr<Document> pDocument(new Document());
		SimpleStream_CStringReader streamSrc(pHelp->GetText());
		if (!pDocument->ParseStream(sig, streamSrc)) return false;
		if (!pArg->StoreValue(env, Value(new Object_document(pDocument->Reference())))) return false;
	}
	g_pFunc_Presenter->Eval(env, *pArg);
	return !sig.IsSignalled();
#endif
	return true;
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
	CommandFormat::Initialize();
	// class realization
	Gura_RealizeUserClass(parser, env.LookupClass(VTYPE_object));
	// class preparation
	Gura_PrepareUserClass(parser);
	// function assignment
	Gura_AssignFunction(test);
	// registoration of HelpPresenter
	HelpPresenter::Register(env, new HelpPresenter_doxygen());
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(doxygen, doxygen)

Gura_RegisterModule(doxygen)
