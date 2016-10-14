//=============================================================================
// Help
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
const String Help::FormatNameDefault("markdown");

Help::Help(const Symbol *pSymbolLangCode, const String &doc) :
	_cntRef(1), _pHelpProvider(nullptr), _pSymbolLangCode(pSymbolLangCode)
{
	ExtractFormatNameAndDoc(doc);
}

Help::Help(const Symbol *pSymbolLangCode, Template *pTemplateDoc) :
	_cntRef(1), _pHelpProvider(nullptr), _pSymbolLangCode(pSymbolLangCode),
	_pTemplateDoc(pTemplateDoc)
{
}

void Help::ExtractFormatNameAndDoc(const String &doc)
{
	if (doc[0] != '#') {
		_formatName = FormatNameDefault;
		_doc = doc;
		return;
	}
	String::const_iterator p = doc.begin();
	p++;
	String::const_iterator pMark = p;
	for ( ; p != doc.end() && *p != '\n'; p++) ;
	_formatName = String(pMark, p);
	if (p != doc.end()) p++;
	_doc = String(p, doc.end());
}

String Help::MakeHelpTitle() const
{
	return (_pHelpProvider == nullptr)? "" : _pHelpProvider->MakeHelpTitle();
}

bool Help::Render(Environment &env, const char *formatNameOut, Stream &stream) const
{
	const HelpRenderer *pHelpRenderer =
		env.GetGlobal()->GetHelpRendererOwner().Find(_formatName.c_str(), formatNameOut);
	if (pHelpRenderer != nullptr) return pHelpRenderer->Render(env, this, stream);
	if (!env.ImportModules(_formatName.c_str(), false, false)) return false;
	pHelpRenderer = env.GetGlobal()->GetHelpRendererOwner().Find(_formatName.c_str(), formatNameOut);
	if (pHelpRenderer != nullptr) return pHelpRenderer->Render(env, this, stream);
	env.SetError(ERR_FormatError, "can't render %s document in %s format",
				 _formatName.c_str(), formatNameOut);
	return false;
}

bool Help::Present(Environment &env)
{
	if (_pHelpProvider != nullptr && _pHelpProvider->GetHolder() != nullptr) {
		if (!HelpProvider::PresentTitle(env, _pHelpProvider->GetHolder())) return false;
	}
	if (!UpdateDocument(env)) return false;
	if (!HasDocument()) {
		return HelpProvider::PresentNoHelpDocument(env);
	}
	const HelpRenderer *pHelpRenderer =
		env.GetGlobal()->GetHelpRendererOwner().Find(_formatName.c_str(), "");
	if (pHelpRenderer != nullptr) return pHelpRenderer->Present(env, this);
	if (!env.ImportModules(_formatName.c_str(), false, false)) return false;
	pHelpRenderer = env.GetGlobal()->GetHelpRendererOwner().Find(_formatName.c_str(), "");
	if (pHelpRenderer != nullptr) return pHelpRenderer->Present(env, this);
	env.SetError(ERR_FormatError, "unsupported format of help documdent: %s", _formatName.c_str());
	return false;
}

bool Help::UpdateDocument(Environment &env)
{
	if (!_doc.empty() || _pTemplateDoc.IsNull()) return true;
	String doc;
	if (!_pTemplateDoc->Render(env, doc)) return false;
	ExtractFormatNameAndDoc(doc);
	return true;
}

Help *Help::CreateFromExprList(Environment &env, const ExprList &exprList)
{
	if (exprList.size() != 2) {
		env.SetError(ERR_ValueError, "invalid format of help");
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
	if (!valList[0].Is_symbol()) {
		env.SetError(ERR_ValueError, "invalid format of help");
		return nullptr;
	}
	const Symbol *pSymbolLangCode = valList[0].GetSymbol();
	Help *pHelp = nullptr;
	if (valList[1].Is_string()) {
		pHelp = new Help(pSymbolLangCode, valList[1].GetString());
	} else if (valList[1].Is_template()) {
		Template *pTemplate = Object_template::GetObject(valList[1])->GetTemplate();
		pHelp = new Help(pSymbolLangCode, pTemplate->Reference());
	} else {
		env.SetError(ERR_ValueError, "invalid format of help");
		return nullptr;
	}
	return pHelp;
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
	pHelp->SetHelpProvider(this);
	_helpOwner.push_back(pHelp);
}

void HelpProvider::AddHelpTemplate(Environment &env, const Symbol *pSymbol, const String &doc)
{
	AutoPtr<Template> pTemplate(new Template());
	if (!pTemplate->Parse(env, doc.begin(), doc.end(), true, false)) {
		env.GetSignal().ClearSignal();
		return;
	}
	AddHelp(new Help(pSymbol, pTemplate.release()));
}

void HelpProvider::LinkHelp(HelpProvider *pHelpProvider)
{
	_pHelpProviderLink.reset(pHelpProvider);
}

Help *HelpProvider::GetHelp(const Symbol *pSymbolLangCode, bool defaultFirstFlag)
{
	Help *pHelp = _pHelpProviderLink.IsNull()?
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

bool HelpProvider::PresentTitle(Environment &env, const Holder *pHolder)
{
	Signal &sig = env.GetSignal();
	String strSep;
	String title = pHolder->MakeHelpTitle();
	for (size_t i = 0; i < title.size() + 1; i++) strSep += '-';
	env.GetConsole()->Printf(sig, "%s\n%s\n", title.c_str(), strSep.c_str());
	return env.IsNoSignalled();
}

bool HelpProvider::PresentNoHelpDocument(Environment &env)
{
	Signal &sig = env.GetSignal();
	env.GetConsole()->Println(sig, "(no help document)");
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
