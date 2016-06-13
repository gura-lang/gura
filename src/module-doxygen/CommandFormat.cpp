//=============================================================================
// CommandFormat.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// CommandFormat
//-----------------------------------------------------------------------------
std::unique_ptr<CommandFormatDict> CommandFormat::_pCmdFmtDict;

void CommandFormat::Initialize()
{
	_pCmdFmtDict.reset(new CommandFormatDict());
	// Structural indicators
	Register("addtogroup",
			 ArgWord("name"),
			 ArgLineOpt("title"));
	Register("callgraph");
	Register("hidecallgrph");
	Register("callergraph");
	Register("hidecallergraph");
	Register("category",
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("class",
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("def",
			 ArgWord("name"));
	Register("defgroup",
			 ArgWord("name"),
			 ArgLine("group_title"));
	Register("dir",
			 ArgWordOpt("path_fragment"));
	Register("enum",
			 ArgWord("name"));
	Register("example",
			 ArgWord("file_name"));
	Register("endinternal");
	Register("extends",
			 ArgWord("name"));
	Register("file",
			 ArgWordOpt("name"));
	Register("fn",
			 ArgLine("function_declaration"));
	Register("headerfile",
			 ArgWord("header_file"),
			 ArgWordOpt("header_name"));
	Register("hideinitializer");
	Register("idlexcept",
			 ArgWord("name"));
	Register("implements",
			 ArgWord("name"));
	Register("ingroup",
			 ArgWord("groupname"));
	Register("interface",
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("internal");
	Register("mainpage",
			 ArgLineOpt("title"));
	Register("memberof",
			 ArgWord("name"));
	Register("name",
			 ArgLineOpt("header"));
	Register("namespace",
			 ArgWord("name"));
	Register("nosubgrouping");
	Register("overload");
	Register("package");
	Register("page");
	Register("private");
	Register("privatesection");
	Register("property");
	Register("protected");
	Register("protectedsection");
	Register("protocol");
	Register("public");
	Register("publicsection");
	Register("pure");
	Register("relates");
	Register("related");
	Register("relatedalso");
	Register("showinitializer");
	Register("static");
	Register("struct");
	Register("typedef");
	Register("union");
	Register("var");
	Register("vhdlflow");
	Register("weakgroup");
	// Section indicators
	Register("attention");
	Register("author");
	Register("authors");
	Register("brief");
	Register("bug");
	Register("cond");
	Register("copyright");
	Register("date");
	Register("deprecated");
	Register("details");
	Register("else");
	Register("elseif");
	Register("endcond");
	Register("endif");
	Register("exception");
	Register("if");
	Register("ifnot");
	Register("invariant");
	Register("note");
	Register("par");
	Register("param",
			 ArgBracket("dir"),
			 ArgWord("parameter_name"),
			 ArgPara("parameter_description"));
	Register("parblock");
	Register("endparblock");
	Register("tparam");
	Register("post");
	Register("pre");
	Register("remark");
	Register("remarks");
	Register("result");
	Register("return",
			 ArgPara("description_of_the_return_value"));
	Register("returns");
	Register("retval");
	Register("sa",
			 ArgPara("references"));
	Register("see");
	Register("short");
	Register("since");
	Register("test");
	Register("throw");
	Register("throws");
	Register("todo");
	Register("version");
	Register("warning");
	Register("xrefitem");
	// Commands to create links
	Register("addindex");
	Register("anchor");
	Register("cite");
	Register("endlink");
	Register("link");
	Register("ref");
	Register("refitem");
	Register("secreflist");
	Register("endsecreflist");
	Register("subpage");
	Register("tableofcontents");
	Register("section");
	Register("subsection");
	Register("subsubsection");
	Register("paragrph");
	// Commands for displaying examples
	Register("dontinclude");
	Register("include");
	Register("includelineno");
	Register("line");
	Register("skip");
	Register("skipline");
	Register("snippet");
	Register("until");
	Register("verbinclude");
	Register("htmlinclude");
	Register("latexinclude");
	// Commands for visual enhancements
	Register("a");
	Register("arg");
	Register("b");
	Register("c");
	Register("code");
	Register("copydoc");
	Register("copybrief");
	Register("copydetails");
	Register("docbookonly");
	Register("dot");
	Register("msc");
	Register("startuml");
	Register("dotfile");
	Register("diafile");
	Register("e");
	Register("em");
	Register("endcode");
	Register("endcodebookonly");
	Register("enddot");
	Register("enduml");
	Register("endhtmlonly");
	Register("endlatexonly");
	Register("endmanonly");
	Register("endrtfonly");
	Register("endverbatim");
	Register("endxmlonly");
	Register("f$");
	Register("f[");
	Register("f]");
	Register("f}");
	Register("htmlonly");
	Register("image");
	Register("latexonly");
	Register("manonly");
	Register("li");
	Register("n");
	Register("p");
	Register("rtfonly");
	Register("verbatim");
	Register("xmlonly");
	Register("\\");
	Register("\\@");
	Register("&");
	Register("$");
	Register("#");
	Register("<");
	Register(">");
	Register("%");
	Register("\"");
	Register(".");
	Register("::");
	Register("|");
	Register("--");
	Register("---");
};
	
const CommandFormat *CommandFormat::Lookup(const char *name)
{
	CommandFormatDict::iterator iter = _pCmdFmtDict->find(name);
	return (iter == _pCmdFmtDict->end())? nullptr : iter->second;
}

//-----------------------------------------------------------------------------
// CommandFormat::ArgOwner
//-----------------------------------------------------------------------------
CommandFormat::ArgOwner::~ArgOwner()
{
	Clear();
}

void CommandFormat::ArgOwner::Clear()
{
	foreach (ArgOwner, ppArg, *this) {
		delete *ppArg;
	}
	clear();
}

Gura_EndModuleScope(doxygen)
