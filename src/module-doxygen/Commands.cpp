//=============================================================================
// Commands.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

const bool Optional = true;

class Argument {
protected:
	String _name;
	bool _optionalFlag;
public:
	inline Argument(const char *name, bool optionalFlag) :
		_name(name), _optionalFlag(optionalFlag) {}
	
};

class ArgWord : public Argument {
public:
	inline ArgWord(const char *name, bool optionalFlag = false) : Argument(name, optionalFlag) {}
};

class ArgLine : public Argument {
public:
	inline ArgLine(const char *name, bool optionalFlag = false) : Argument(name, optionalFlag) {}
};

class ArgPara : public Argument {
public:
	inline ArgPara(const char *name, bool optionalFlag = false) : Argument(name, optionalFlag) {}
};

class ArgumentList : public std::vector<Argument *> {
};

class ArgumentOwner : public ArgumentList {
public:
	~ArgumentOwner();
	void Clear();
};

class Command {
protected:
	ArgumentOwner _argOwner;
public:
	inline Command(const char *name) {}
	inline Command(const char *name, Argument *pArg1) {
		_argOwner.reserve(1);
		_argOwner.push_back(pArg1);
	}
	inline Command(const char *name, Argument *pArg1, Argument *pArg2) {
		_argOwner.reserve(2);
		_argOwner.push_back(pArg1);
		_argOwner.push_back(pArg2);
	}
	inline Command(const char *name, Argument *pArg1, Argument *pArg2, Argument *pArg3) {
		_argOwner.reserve(3);
		_argOwner.push_back(pArg1);
		_argOwner.push_back(pArg2);
		_argOwner.push_back(pArg3);
	}
	inline Command(const char *name, Argument *pArg1, Argument *pArg2, Argument *pArg3, Argument *pArg4) {
		_argOwner.reserve(4);
		_argOwner.push_back(pArg1);
		_argOwner.push_back(pArg2);
		_argOwner.push_back(pArg3);
		_argOwner.push_back(pArg4);
	}
	inline Command(const char *name, Argument *pArg1, Argument *pArg2, Argument *pArg3, Argument *pArg4, Argument *pArg5) {
		_argOwner.reserve(5);
		_argOwner.push_back(pArg1);
		_argOwner.push_back(pArg2);
		_argOwner.push_back(pArg3);
		_argOwner.push_back(pArg4);
		_argOwner.push_back(pArg5);
	}
};

ArgumentOwner::~ArgumentOwner()
{
	Clear();
}

void ArgumentOwner::Clear()
{
	foreach (ArgumentOwner, ppArg, *this) {
		delete *ppArg;
	}
	clear();
}

void InitCommands()
{
	static const Command *commands[] = {
		// Structural indicators
		new Command("addtogroup", new ArgWord("name"), new ArgLine("title", Optional)),
		new Command("callgraph"),
		new Command("hidecallgrph"),
		new Command("callergraph"),
		new Command("hidecallergraph"),
		new Command("category"),
		new Command("class"),
		new Command("def"),
		new Command("defgroup"),
		new Command("dir"),
		new Command("enum"),
		new Command("example"),
		new Command("endinternal"),
		new Command("extends"),
		new Command("file"),
		new Command("fn"),
		new Command("headerfile"),
		new Command("hideinitializer"),
		new Command("idlexcept"),
		new Command("implements"),
		new Command("ingroup"),
		new Command("interface"),
		new Command("internal"),
		new Command("mainpage"),
		new Command("memberof"),
		new Command("name"),
		new Command("namespace"),
		new Command("nosubgrouping"),
		new Command("overload"),
		new Command("package"),
		new Command("page"),
		new Command("private"),
		new Command("privatesection"),
		new Command("property"),
		new Command("protected"),
		new Command("protectedsection"),
		new Command("protocol"),
		new Command("public"),
		new Command("publicsection"),
		new Command("pure"),
		new Command("relates"),
		new Command("related"),
		new Command("relatedalso"),
		new Command("showinitializer"),
		new Command("static"),
		new Command("struct"),
		new Command("typedef"),
		new Command("union"),
		new Command("var"),
		new Command("vhdlflow"),
		new Command("weakgroup"),
		// Section indicators
		new Command("attention"),
		new Command("author"),
		new Command("authors"),
		new Command("brief"),
		new Command("bug"),
		new Command("cond"),
		new Command("copyright"),
		new Command("date"),
		new Command("deprecated"),
		new Command("details"),
		new Command("else"),
		new Command("elseif"),
		new Command("endcond"),
		new Command("endif"),
		new Command("exception"),
		new Command("if"),
		new Command("ifnot"),
		new Command("invariant"),
		new Command("note"),
		new Command("par"),
		new Command("param"),
		new Command("parblock"),
		new Command("endparblock"),
		new Command("tparam"),
		new Command("post"),
		new Command("pre"),
		new Command("remark"),
		new Command("remarks"),
		new Command("result"),
		new Command("return"),
		new Command("returns"),
		new Command("retval"),
		new Command("sa"),
		new Command("see"),
		new Command("short"),
		new Command("since"),
		new Command("test"),
		new Command("throw"),
		new Command("throws"),
		new Command("todo"),
		new Command("version"),
		new Command("warning"),
		new Command("xrefitem"),
		// Commands to create links
		new Command("addindex"),
		new Command("anchor"),
		new Command("cite"),
		new Command("endlink"),
		new Command("link"),
		new Command("ref"),
		new Command("refitem"),
		new Command("secreflist"),
		new Command("endsecreflist"),
		new Command("subpage"),
		new Command("tableofcontents"),
		new Command("section"),
		new Command("subsection"),
		new Command("subsubsection"),
		new Command("paragrph"),
		// Commands for displaying examples
		new Command("dontinclude"),
		new Command("include"),
		new Command("includelineno"),
		new Command("line"),
		new Command("skip"),
		new Command("skipline"),
		new Command("snippet"),
		new Command("until"),
		new Command("verbinclude"),
		new Command("htmlinclude"),
		new Command("latexinclude"),
		// Commands for visual enhancements
		new Command("a"),
		new Command("arg"),
		new Command("b"),
		new Command("c"),
		new Command("code"),
		new Command("copydoc"),
		new Command("copybrief"),
		new Command("copydetails"),
		new Command("docbookonly"),
		new Command("dot"),
		new Command("msc"),
		new Command("startuml"),
		new Command("dotfile"),
		new Command("diafile"),
		new Command("e"),
		new Command("em"),
		new Command("endcode"),
		new Command("endcodebookonly"),
		new Command("enddot"),
		new Command("enduml"),
		new Command("endhtmlonly"),
		new Command("endlatexonly"),
		new Command("endmanonly"),
		new Command("endrtfonly"),
		new Command("endverbatim"),
		new Command("endxmlonly"),
		new Command("f$"),
		new Command("f["),
		new Command("f]"),
		new Command("f}"),
		new Command("htmlonly"),
		new Command("image"),
		new Command("latexonly"),
		new Command("manonly"),
		new Command("li"),
		new Command("n"),
		new Command("p"),
		new Command("rtfonly"),
		new Command("verbatim"),
		new Command("xmlonly"),
		new Command("\\"),
		new Command("\\@"),
		new Command("&"),
		new Command("$"),
		new Command("#"),
		new Command("<"),
		new Command(">"),
		new Command("%"),
		new Command("\""),
		new Command("."),
		new Command("::"),
		new Command("|"),
		new Command("--"),
		new Command("---"),
	};
};
	
Gura_EndModuleScope(doxygen)
