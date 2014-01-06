//=============================================================================
// Help
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
const String Help::FMT_markdown("markdown");

Help::Help(const Symbol *pSymbol, const String &formatName, const String &text) :
		_cntRef(1), _pSymbol(pSymbol), _formatName(formatName), _text(text)
{
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

void HelpPresenter::Register(Environment &env, HelpPresenter *pHelpPresenter)
{
	env.GetGlobal()->GetHelpPresenterOwner().push_back(pHelpPresenter);
}

bool HelpPresenter::Present(Environment &env, Signal sig,
										const char *title, const Help *pHelp)
{
	const char *formatName = (pHelp == NULL)?
						Help::FMT_markdown.c_str() : pHelp->GetFormatName();
	const HelpPresenter *pHelpPresenter = env.GetGlobal()->
						GetHelpPresenterOwner().FindByFormatName(formatName);
	if (pHelpPresenter != NULL) {
		return pHelpPresenter->DoPresent(env, sig, title, pHelp);
	}
	if (!env.ImportModules(sig, formatName, false, false)) return false;
	pHelpPresenter = env.GetGlobal()->
						GetHelpPresenterOwner().FindByFormatName(formatName);
	if (pHelpPresenter != NULL) {
		return pHelpPresenter->DoPresent(env, sig, title, pHelp);
	}
	sig.SetError(ERR_FormatError, "unsupported format: %s", formatName);
	return false;
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
	return NULL;
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
