//=============================================================================
// Help
//=============================================================================
#ifndef __GURA_HELP_H__
#define __GURA_HELP_H__

#include "Common.h"

#define GURA_HELPTEXT_ITERATOR_en() \
"In default, this returns an iterator as its result value.\n" \
"Specifying the following attributes would customize the returned value:\n" \
"\n" \
"- `:iter` .. An iterator. This is the default behavior.\n" \
"- `:xiter` .. An iterator that eliminates `nil` from its elements.\n" \
"- `:list` .. A list.\n" \
"- `:xlist` .. A list that eliminates `nil` from its elements.\n" \
"- `:set` ..  A list that eliminates duplicated values from its elements.\n" \
"- `:xset` .. A list that eliminates duplicated values and `nil` from its elements.\n" \
"\n" \
"See the chapter of Mapping Process in Gura Language Manual for the detail.\n" \
"\n" \
"If a block is specified, it would be evaluated repeatingly\n" \
"with block parameters `|value, idx:number|` where `value` is the iterated value\n" \
"and `idx` the loop index starting from zero.\n" \
"In this case, the last evaluated value of the block would be the result value.\n" \
"If one of the attributes listed above is specified,\n" \
"an iterator or a list of the evaluated value would be returned.\n" 

// revise implementation of help.gettext_block_en in Class_help.cpp
// after this text is modified.
#define GURA_HELPTEXT_BLOCK_en(var, type) \
"If `block` is specified, it would be evaluated with a block parameter `|" var ":" type "|`,\n" \
"where `" var "` is the created instance.\n" \
"In this case, the block's result would become the function's returned value.\n"

namespace Gura {

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Help {
private:
	int _cntRef;
	String _title;
	const Symbol *_pSymbolLangCode;
	String _formatName;
	String _text;
public:
	static const String FMT_markdown;
public:
	Gura_DeclareReferenceAccessor(Help);
public:
	Help(const String &title);
	Help(const Symbol *pSymbolLangCode, const String &formatName, const String &text);
	Help(const String &title, const Symbol *pSymbolLangCode,
		 const String &formatName, const String &text);
private:
	inline ~Help() {}
public:
	inline void SetTitle(const String &title) { _title = title; }
	inline const char *GetTitle() const { return _title.c_str(); }
	inline const String &GetTitleSTL() const { return _title; }
	inline const Symbol *GetLangCode() const { return _pSymbolLangCode; }
	inline const char *GetFormatName() const { return _formatName.c_str(); }
	inline const String &GetFormatNameSTL() const { return _formatName; }
	inline const char *GetText() const { return _text.c_str(); }
	inline const String &GetTextSTL() const { return _text; }
	bool Present(Environment &env) const;
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
	virtual bool DoPresent(Environment &env, const Help *pHelp) const = 0;
public:
	static void Register(Environment &env, HelpPresenter *pHelpPresenter);
};

//-----------------------------------------------------------------------------
// HelpPresenterCustom
//-----------------------------------------------------------------------------
class HelpPresenterCustom : public HelpPresenter {
private:
	AutoPtr<Function> _pFunc;
public:
	inline HelpPresenterCustom(const String &formatName, Function *pFunc) :
								HelpPresenter(formatName), _pFunc(pFunc) {}
	virtual bool DoPresent(Environment &env, const Help *pHelp) const;
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
