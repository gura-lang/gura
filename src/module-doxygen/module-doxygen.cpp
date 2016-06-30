//=============================================================================
// Gura module: doxygen
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(doxygen)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// doxygen.makescript(stream?:stream):void
Gura_DeclareFunction(makescript)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(makescript)
{
	Signal &sig = env.GetSignal();
	Stream *pStream = arg.IsValid(0)? &arg.GetStream(0) : env.GetConsole();
	const CommandFormatList &cmdFmtList = CommandFormat::GetCommandFormatList();
	pStream->Printf(sig, "Parser = class(doxygen.parser) {\n");
	if (sig.IsSignalled()) return Value::Nil;
	foreach_const (CommandFormatList, ppCmdFmt, cmdFmtList) {
		const CommandFormat *pCmdFmt = *ppCmdFmt;
		if (pCmdFmt->HasNormalCommandName()) {
			String str;
			str += "\t";
			str += pCmdFmt->MakeHandlerDeclaration();
			str += " = '@";
			str += pCmdFmt->GetName();
			str += "{'";
			size_t iArg = 0;
			foreach_const (CommandFormat::ArgOwner, ppArg, pCmdFmt->GetArgOwner()) {
				const CommandFormat::Arg *pArg = *ppArg;
				str += " + ";
				str += (iArg == 0)? "'" : "',";
				str += pArg->GetName();
				str += ":' + ";
				str += pArg->GetName();
				str += ".escape():surround";
				iArg++;
			}
			str += " + '}'";
			pStream->Println(sig, str.c_str());
		} else {
			pStream->Printf(sig, "\t// %s = ''\n", pCmdFmt->MakeHandlerDeclaration().c_str());
		}
		if (sig.IsSignalled()) return Value::Nil;
	}
	pStream->Printf(sig, "}\n");
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
	// symbol realization
	Gura_RealizeUserSymbol(OnCommand);
	// class realization
	Gura_RealizeUserClass(parser, env.LookupClass(VTYPE_object));
	// class preparation
	Gura_PrepareUserClass(parser);
	// function assignment
	Gura_AssignFunction(makescript);
	// registoration of HelpPresenter
	HelpPresenter::Register(env, new HelpPresenter_doxygen());
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(doxygen, doxygen)

Gura_RegisterModule(doxygen)
