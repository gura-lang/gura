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

class HelpProvider;
class Template;

//-----------------------------------------------------------------------------
// Help
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Help {
private:
	int _cntRef;
	const HelpProvider *_pHelpProvider;
	const Symbol *_pSymbolLangCode;
	String _formatName;
	String _doc;
	AutoPtr<Template> _pTemplateDoc;
public:
	static const String FMT_markdown;
public:
	Gura_DeclareReferenceAccessor(Help);
public:
	Help(const Symbol *pSymbolLangCode, const String &formatName, const String &doc);
	Help(const Symbol *pSymbolLangCode, const String &formatName, Template *pTemplateDoc);
private:
	inline ~Help() {}
public:
	inline void SetHelpProvider(const HelpProvider *pHelpProvider) {
		_pHelpProvider = pHelpProvider;
	}
	inline const Symbol *GetLangCode() const { return _pSymbolLangCode; }
	inline const char *GetFormatName() const { return _formatName.c_str(); }
	inline const String &GetFormatNameSTL() const { return _formatName; }
	inline const char *GetDocument() const { return _doc.c_str(); }
	inline const String &GetDocumentSTL() const { return _doc; }
	inline bool HasDocument() const { return !_doc.empty(); }
	void ExtractFormatNameAndDoc(const String &doc);
	String MakeHelpTitle() const;
	bool Render(Environment &env, const char *formatNameOut, Stream &stream) const;
	bool Present(Environment &env);
	bool UpdateDocument(Environment &env);
	static Help *CreateFromExprList(Environment &env, const ExprList &exprList);
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
// HelpProvider
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpProvider {
public:
	class GURA_DLLDECLARE Handler {
	public:
		virtual String MakeHelpTitle() const = 0;
	};
protected:
	int _cntRef;
	AutoPtr<HelpProvider> _pHelpProviderLink;
	HelpOwner _helpOwner;
	Handler *_pHandler;
public:
	Gura_DeclareReferenceAccessor(HelpProvider);
public:
	inline HelpProvider(Handler *pHandler) : _cntRef(1), _pHandler(pHandler) {}
protected:
	virtual ~HelpProvider();
public:
	inline const HelpOwner &GetHelpOwner() const { return _helpOwner; }
	inline bool HasHelp() const { return !_helpOwner.empty(); }
	inline void SetHandler(Handler *pHandler) { _pHandler = pHandler; }
	inline String MakeHelpTitle() const {
		return (_pHandler == nullptr)? "" : _pHandler->MakeHelpTitle();
	};
	inline const Handler *GetHandler() const { return _pHandler; }
	void AddHelp(Help *pHelp);
	void AddHelp(const Symbol *pSymbol, const String &formatName, const String &doc);
	void LinkHelp(HelpProvider *pHelpProvider);
	Help *GetHelp(const Symbol *pSymbolLangCode, bool defaultFirstFlag);
	inline const Help *GetHelp(const Symbol *pSymbolLangCode, bool defaultFirstFlag) const {
		return const_cast<HelpProvider *>(this)->GetHelp(pSymbolLangCode, defaultFirstFlag);
	}
	void CopyHelp(const HelpProvider &helpProvider);
	static bool PresentTitle(Environment &env, const Handler *pHandler);
	static bool PresentNoHelpDocument(Environment &env);
};

//-----------------------------------------------------------------------------
// HelpRenderer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpRenderer {
private:
	String _formatName;
	String _formatNameOut;
	AutoPtr<Function> _pFunc;
public:
	HelpRenderer(const String &formatName, const String &formatNameOut, Function *pFunc);
	virtual ~HelpRenderer();
	const char *GetFormatName() const { return _formatName.c_str(); }
	const char *GetFormatNameOut() const { return _formatNameOut.c_str(); }
	bool Render(Environment &env, const Help *pHelp, Stream &stream) const;
	bool Present(Environment &env, const Help *pHelp) const;
public:
	static void Register(Environment &env, HelpRenderer *pHelpRenderer);
};

//-----------------------------------------------------------------------------
// HelpRendererList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpRendererList : public std::vector<HelpRenderer *> {
public:
	const HelpRenderer *Find(const char *formatName, const char *formatNameOut) const;
};

//-----------------------------------------------------------------------------
// HelpRendererOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE HelpRendererOwner : public HelpRendererList {
public:
	~HelpRendererOwner();
	void Clear();
};

}

#endif
