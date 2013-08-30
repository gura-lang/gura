#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
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
// HelpFormatter
//-----------------------------------------------------------------------------
HelpFormatter::HelpFormatter(const String &formatName) : _formatName(formatName)
{
}

void HelpFormatter::Register(Environment &env, HelpFormatter *pHelpFormatter)
{
	env.GetGlobal()->GetHelpFormatterOwner().push_back(pHelpFormatter);
}

bool HelpFormatter::Format(Environment &env, Signal sig, const char *formatName,
									SimpleStream &streamSrc, Stream &streamDst)
{
	const HelpFormatter *pHelpFormatter = env.GetGlobal()->
						GetHelpFormatterOwner().FindByFormatName(formatName);
	if (pHelpFormatter != NULL) {
		return pHelpFormatter->DoFormat(env, sig, streamSrc, streamDst);
	}
	if (!env.ImportModules(sig, formatName, false, false)) return false;
	pHelpFormatter = env.GetGlobal()->
						GetHelpFormatterOwner().FindByFormatName(formatName);
	if (pHelpFormatter != NULL) {
		return pHelpFormatter->DoFormat(env, sig, streamSrc, streamDst);
	}
	sig.SetError(ERR_FormatError, "unsupported format: %s", formatName);
	return false;
}

bool HelpFormatter::Format(Environment &env, Signal sig, const char *formatName,
									const char *text, Stream &streamDst)
{
	SimpleStream_CString streamSrc(text);
	return Format(env, sig, formatName, streamSrc, streamDst);
}

//-----------------------------------------------------------------------------
// HelpFormatterList
//-----------------------------------------------------------------------------
const HelpFormatter *HelpFormatterList::FindByFormatName(const char *formatName) const
{
	foreach_const (HelpFormatterList, ppHelpFormatter, *this) {
		const HelpFormatter *pHelpFormatter = *ppHelpFormatter;
		if (::strcmp(pHelpFormatter->GetFormatName(), formatName) == 0) {
			return pHelpFormatter;
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// HelpFormatterOwner
//-----------------------------------------------------------------------------
HelpFormatterOwner::~HelpFormatterOwner()
{
	Clear();
}

void HelpFormatterOwner::Clear()
{
	foreach (HelpFormatterOwner, ppHelpFormatter, *this) {
		delete *ppHelpFormatter;
	}
	clear();
}

}
