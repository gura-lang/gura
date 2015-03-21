//=============================================================================
// Help
//=============================================================================
#ifndef __GURA_HELP_H__
#define __GURA_HELP_H__

#include "Common.h"

#define GURA_ITERATOR_HELP \
"In default, this returns an iterator as its result value.\n" \
"Specifying the following attributes would convert it into other formats:\n" \
"\n" \
"- `:iter` .. An iterator. This is the default behavior.\n" \
"- `:xiter` .. An iterator that eliminates `nil` from its elements.\n" \
"- `:list` .. A list.\n" \
"- `:xlist` .. A list that eliminates `nil` from its elements.\n" \
"- `:set` ..  A list that eliminates duplicated values from its elements.\n" \
"- `:xset` .. A list that eliminates duplicated values and `nil` from its elements.\n" \
"\n" \
"If a block is specified, it would be evaluated repeatingly\n" \
"with block parameters `|value, idx:number|` where `value` is the iterated value\n" \
"and `idx` the loop index starting from zero.\n" \
"In this case, the last evaluated value of the block would be the result value.\n" \
"If one of the attributes listed above is specified,\n" \
"an iterator or a list of the evaluated value would be returned.\n" 

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
	virtual ~HelpPresenter();
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
