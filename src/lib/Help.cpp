//=============================================================================
// Help
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
const String Help::FMT_markdown("markdown");

Help::Help(const String &title) : _cntRef(1), _pSymbolLangCode(Gura_Symbol(en))
{
}

Help::Help(const Symbol *pSymbolLangCode, const String &formatName, const String &text) :
	_cntRef(1), _pSymbolLangCode(pSymbolLangCode), _formatName(formatName), _text(text)
{
}

Help::Help(const String &title, const Symbol *pSymbolLangCode,
		   const String &formatName, const String &text) :
	_cntRef(1), _title(title), _pSymbolLangCode(pSymbolLangCode),
	_formatName(formatName), _text(text)
{
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
	sig.SetError(ERR_FormatError, "unsupported format of help documdent: %s", _formatName.c_str());
	return false;
}

bool Help::Present(Environment &env) const
{
	Signal &sig = env.GetSignal();
	String strSep;
	for (size_t i = 0; i < _title.size(); i++) strSep += '-';
	env.GetConsole()->Printf(sig, "%s\n%s\n", _title.c_str(), strSep.c_str());
	if (sig.IsSignalled()) return false;
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
