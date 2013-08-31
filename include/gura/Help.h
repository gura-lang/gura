#ifndef __GURA_HELP_H__
#define __GURA_HELP_H__

#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Help {
private:
	int _cntRef;
	const Symbol *_pSymbol;
	String _formatName;
	String _text;
public:
	static const String FMT_markdown;
public:
	Gura_DeclareReferenceAccessor(Help);
public:
	Help(const Symbol *pSymbol, const String &formatName, const String &text);
private:
	inline ~Help() {}
public:
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetFormatName() const { return _formatName.c_str(); }
	inline const String &GetFormatNameSTL() const { return _formatName; }
	inline const char *GetText() const { return _text.c_str(); }
	inline const String &GetTextSTL() const { return _text; }
};

//-----------------------------------------------------------------------------
// HelpList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpList : public std::vector<Help *> {
};

//-----------------------------------------------------------------------------
// HelpOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpOwner : public HelpList {
public:
	~HelpOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// HelpPresenter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpPresenter {
private:
	String _formatName;
public:
	HelpPresenter(const String &formatName);
	const char *GetFormatName() const { return _formatName.c_str(); }
	virtual bool DoPresent(Environment &env, Signal sig, const char *title, const Help *pHelp) const = 0;
public:
	static void Register(Environment &env, HelpPresenter *pHelpPresenter);
	static bool Present(Environment &env, Signal sig, const char *title, const Help *pHelp);
};

//-----------------------------------------------------------------------------
// HelpPresenterList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpPresenterList : public std::vector<HelpPresenter *> {
public:
	const HelpPresenter *FindByFormatName(const char *formatName) const;
};

//-----------------------------------------------------------------------------
// HelpPresenterOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpPresenterOwner : public HelpPresenterList {
public:
	~HelpPresenterOwner();
	void Clear();
};

}

#endif
