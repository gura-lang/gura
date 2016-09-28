//=============================================================================
// Help
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
const String Help::FMT_markdown("markdown");

Help::Help(const HelpProvider *pHelpProvider) :
	_cntRef(1), _pHelpProvider(pHelpProvider), _pSymbolLangCode(Gura_Symbol(en))
{
}

Help::Help(const Symbol *pSymbolLangCode, const String &formatName, const String &text) :
	_cntRef(1), _pSymbolLangCode(pSymbolLangCode), _formatName(formatName), _text(text)
{
}

Help::Help(const HelpProvider *pHelpProvider, const Symbol *pSymbolLangCode,
		   const String &formatName, const String &text) :
	_cntRef(1), _pHelpProvider(pHelpProvider), _pSymbolLangCode(pSymbolLangCode),
	_formatName(formatName), _text(text)
{
}

String Help::MakeHelpTitle() const
{
	return (_pHelpProvider == nullptr)? "" : _pHelpProvider->MakeHelpTitle();
}

bool Help::Render(Environment &env, const char *formatNameOut, Stream &stream) const
{
	Signal &sig = env.GetSignal();
	const HelpRenderer *pHelpRenderer =
		env.GetGlobal()->GetHelpRendererOwner().Find(_formatName.c_str(), formatNameOut);
	if (pHelpRenderer != nullptr) return pHelpRenderer->Render(env, this, stream);
	if (!env.ImportModules(sig, _formatName.c_str(), false, false)) return false;
	pHelpRenderer = env.GetGlobal()->GetHelpRendererOwner().Find(_formatName.c_str(), formatNameOut);
	if (pHelpRenderer != nullptr) return pHelpRenderer->Render(env, this, stream);
	sig.SetError(ERR_FormatError, "can't render %s document in %s format",
				 _formatName.c_str(), formatNameOut);
	return false;
}

bool Help::Present(Environment &env) const
{
	Signal &sig = env.GetSignal();
#if 0
	String strSep;
	String title = MakeHelpTitle();
	for (size_t i = 0; i < title.size(); i++) strSep += '-';
	env.GetConsole()->Printf(sig, "%s\n%s\n", title.c_str(), strSep.c_str());
	if (sig.IsSignalled()) return false;
#endif
	if (_pHelpProvider != nullptr && _pHelpProvider->GetHandler() != nullptr) {
		if (!HelpProvider::PresentTitle(env, _pHelpProvider->GetHandler())) return false;
	}
	if (_text.empty()) {
		env.GetConsole()->Println(sig, "(no help)");
		return sig.IsNoSignalled();
	}
	const HelpRenderer *pHelpRenderer =
		env.GetGlobal()->GetHelpRendererOwner().Find(_formatName.c_str(), "");
	if (pHelpRenderer != nullptr) return pHelpRenderer->Present(env, this);
	if (!env.ImportModules(sig, _formatName.c_str(), false, false)) return false;
	pHelpRenderer = env.GetGlobal()->GetHelpRendererOwner().Find(_formatName.c_str(), "");
	if (pHelpRenderer != nullptr) return pHelpRenderer->Present(env, this);
	sig.SetError(ERR_FormatError, "unsupported format of help documdent: %s", _formatName.c_str());
	return false;
}

Help *Help::CreateFromExprList(Environment &env, const ExprList &exprList)
{
	if (exprList.size() != 3) {
		env.SetError(ERR_ValueError, "invalid format for help");
		return nullptr;
	}
	ValueList valList;
	valList.reserve(exprList.size());
	foreach_const (ExprList, ppExprArg, exprList) {
		const Expr *pExprArg = *ppExprArg;
		Value result = pExprArg->Exec(env);
		if (env.IsSignalled()) return nullptr;
		valList.push_back(result);
	}
	if (!(valList[0].Is_symbol() && valList[1].Is_string() && valList[2].Is_string())) {
		env.SetError(ERR_ValueError, "invalid format for help");
		return nullptr;
	}
	return new Help(valList[0].GetSymbol(), valList[1].GetString(), valList[2].GetString());
}

//-----------------------------------------------------------------------------
// HelpList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// HelpOwner
//-----------------------------------------------------------------------------
HelpOwner::~HelpOwner()
{
	Clear();
}

void HelpOwner::Clear()
{
	foreach (HelpOwner, ppHelp, *this) {
		Help *pHelp = *ppHelp;
		Help::Delete(pHelp);
	}
	clear();
}

//-----------------------------------------------------------------------------
// HelpProvider
//-----------------------------------------------------------------------------
HelpProvider::~HelpProvider()
{
	foreach (HelpOwner, ppHelp, _helpOwner) {
		Help *pHelp = *ppHelp;
		pHelp->SetHelpProvider(nullptr);
	}
}

void HelpProvider::AddHelp(Help *pHelp)
{
	_helpOwner.push_back(pHelp);
}

void HelpProvider::AddHelp(const Symbol *pSymbol, const String &formatName, const String &text)
{
	AddHelp(new Help(this, pSymbol, formatName, text));
}

void HelpProvider::LinkHelp(HelpProvider *pHelpProvider)
{
	_pHelpProviderLink.reset(pHelpProvider);
}

const Help *HelpProvider::GetHelp(const Symbol *pSymbolLangCode, bool defaultFirstFlag) const
{
	const Help *pHelp = _pHelpProviderLink.IsNull()?
		nullptr : _pHelpProviderLink->GetHelp(pSymbolLangCode, defaultFirstFlag);
	if (pHelp != nullptr) return pHelp;
	if (_helpOwner.empty()) return nullptr;
	if (pSymbolLangCode == nullptr) return _helpOwner.front();
	foreach_const (HelpOwner, ppHelp, _helpOwner) {
		Help *pHelp = *ppHelp;
		if (pHelp->GetLangCode() == pSymbolLangCode) return pHelp;
	}
	return defaultFirstFlag? _helpOwner.front() : nullptr;
}

void HelpProvider::CopyHelp(const HelpProvider &helpProvider)
{
	foreach_const (HelpOwner, ppHelp, helpProvider.GetHelpOwner()) {
		Help *pHelp = *ppHelp;
		_helpOwner.push_back(pHelp->Reference());
	}
}

bool HelpProvider::PresentTitle(Environment &env, const Handler *pHandler)
{
	Signal &sig = env.GetSignal();
	String strSep;
	String title = pHandler->MakeHelpTitle();
	for (size_t i = 0; i < title.size(); i++) strSep += '-';
	env.GetConsole()->Printf(sig, "%s\n%s\n", title.c_str(), strSep.c_str());
	return env.IsNoSignalled();
}

//-----------------------------------------------------------------------------
// HelpRenderer
//-----------------------------------------------------------------------------
HelpRenderer::HelpRenderer(const String &formatName, const String &formatNameOut, Function *pFunc) :
	_formatName(formatName), _formatNameOut(formatNameOut), _pFunc(pFunc)
{
}

HelpRenderer::~HelpRenderer()
{
}

void HelpRenderer::Register(Environment &env, HelpRenderer *pHelpRenderer)
{
	env.GetGlobal()->GetHelpRendererOwner().push_back(pHelpRenderer);
}

bool HelpRenderer::Render(Environment &env, const Help *pHelp, Stream &stream) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->StoreValue(
			env, Value(new Object_help(env, pHelp->Reference())))) return false;
	if (!pArg->StoreValue(
			env, Value(new Object_stream(env, stream.Reference())))) return false;
	_pFunc->Eval(env, *pArg);
	return !sig.IsSignalled();
}

bool HelpRenderer::Present(Environment &env, const Help *pHelp) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->StoreValue(
			env, Value(new Object_help(env, pHelp->Reference())))) return false;
	_pFunc->Eval(env, *pArg);
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// HelpRendererList
//-----------------------------------------------------------------------------
const HelpRenderer *HelpRendererList::Find(const char *formatName, const char *formatNameOut) const
{
	foreach_const (HelpRendererList, ppHelpRenderer, *this) {
		const HelpRenderer *pHelpRenderer = *ppHelpRenderer;
		if (::strcmp(pHelpRenderer->GetFormatName(), formatName) == 0 &&
			::strcmp(pHelpRenderer->GetFormatNameOut(), formatNameOut) == 0) {
			return pHelpRenderer;
		}
	}
	return nullptr;
}

//-----------------------------------------------------------------------------
// HelpRendererOwner
//-----------------------------------------------------------------------------
HelpRendererOwner::~HelpRendererOwner()
{
	Clear();
}

void HelpRendererOwner::Clear()
{
	foreach (HelpRendererOwner, ppHelpRenderer, *this) {
		delete *ppHelpRenderer;
	}
	clear();
}

}
