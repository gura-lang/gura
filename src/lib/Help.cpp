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

bool Help::Present(Environment &env) const
{
	Signal &sig = env.GetSignal();
	const char *formatName = GetFormatName();
	const HelpPresenter *pHelpPresenter = env.GetGlobal()->
						GetHelpPresenterOwner().FindByFormatName(formatName);
	if (pHelpPresenter != nullptr) {
		return pHelpPresenter->DoPresent(env, this);
	}
	if (!env.ImportModules(sig, formatName, false, false)) return false;
	pHelpPresenter = env.GetGlobal()->
						GetHelpPresenterOwner().FindByFormatName(formatName);
	if (pHelpPresenter != nullptr) {
		return pHelpPresenter->DoPresent(env, this);
	}
	sig.SetError(ERR_FormatError, "unsupported format of help documdent: %s", formatName);
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
// HelpPresenter
//-----------------------------------------------------------------------------
HelpPresenter::HelpPresenter(const String &formatName) : _formatName(formatName)
{
}

HelpPresenter::~HelpPresenter()
{
}

void HelpPresenter::Register(Environment &env, HelpPresenter *pHelpPresenter)
{
	env.GetGlobal()->GetHelpPresenterOwner().push_back(pHelpPresenter);
}

//-----------------------------------------------------------------------------
// HelpPresenterCustom
//-----------------------------------------------------------------------------
bool HelpPresenterCustom::DoPresent(Environment &env, const Help *pHelp) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Argument> pArg(new Argument(_pFunc.get()));
	if (!pArg->StoreValue(
			env, Value(new Object_help(env, pHelp->Reference())))) return false;
	_pFunc->Eval(env, *pArg);
	return !sig.IsSignalled();
}

//-----------------------------------------------------------------------------
// HelpPresenterList
//-----------------------------------------------------------------------------
const HelpPresenter *HelpPresenterList::FindByFormatName(const char *formatName) const
{
	foreach_const (HelpPresenterList, ppHelpPresenter, *this) {
		const HelpPresenter *pHelpPresenter = *ppHelpPresenter;
		if (::strcmp(pHelpPresenter->GetFormatName(), formatName) == 0) {
			return pHelpPresenter;
		}
	}
	return nullptr;
}

//-----------------------------------------------------------------------------
// HelpPresenterOwner
//-----------------------------------------------------------------------------
HelpPresenterOwner::~HelpPresenterOwner()
{
	Clear();
}

void HelpPresenterOwner::Clear()
{
	foreach (HelpPresenterOwner, ppHelpPresenter, *this) {
		delete *ppHelpPresenter;
	}
	clear();
}

}
