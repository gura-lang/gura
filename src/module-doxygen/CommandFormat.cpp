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
	Register("addtogroup",		CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgLineOpt("title"));
	Register("callgraph",		CMDTYPE_Structure);
	Register("hidecallgrph",	CMDTYPE_Structure);
	Register("callergraph",		CMDTYPE_Structure);
	Register("hidecallergraph",	CMDTYPE_Structure);
	Register("category",		CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("class",			CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("def",				CMDTYPE_Structure,
			 ArgWord("name"));
	Register("defgroup",		CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgLine("group_title"));
	Register("dir",				CMDTYPE_Structure,
			 ArgWordOpt("path_fragment"));
	Register("enum",			CMDTYPE_Structure,
			 ArgWord("name"));
	Register("example",			CMDTYPE_Structure,
			 ArgWord("file_name"));
	Register("endinternal",		CMDTYPE_Structure);
	Register("extends",			CMDTYPE_Structure,
			 ArgWord("name"));
	Register("file",			CMDTYPE_Structure,
			 ArgWordOpt("name"));
	Register("fn",				CMDTYPE_Structure,
			 ArgLine("function_declaration"));
	Register("headerfile",		CMDTYPE_Structure,
			 ArgWord("header_file"),
			 ArgWordOpt("header_name"));
	Register("hideinitializer",	CMDTYPE_Structure);
	Register("idlexcept",		CMDTYPE_Structure,
			 ArgWord("name"));
	Register("implements",		CMDTYPE_Structure,
			 ArgWord("name"));
	Register("ingroup",			CMDTYPE_Structure,
			 ArgWord("groupname"));
	Register("interface",		CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("internal",		CMDTYPE_Structure);
	Register("mainpage",		CMDTYPE_Structure,
			 ArgLineOpt("title"));
	Register("memberof",		CMDTYPE_Structure,
			 ArgWord("name"));
	Register("name",			CMDTYPE_Structure,
			 ArgLineOpt("header"));
	Register("namespace",		CMDTYPE_Structure,
			 ArgWord("name"));
	Register("nosubgrouping",	CMDTYPE_Structure);
	Register("overload",		CMDTYPE_Structure);
	Register("package",			CMDTYPE_Structure);
	Register("page",			CMDTYPE_Structure);
	Register("private",			CMDTYPE_Structure);
	Register("privatesection",	CMDTYPE_Structure);
	Register("property",		CMDTYPE_Structure);
	Register("protected",		CMDTYPE_Structure);
	Register("protectedsection",CMDTYPE_Structure);
	Register("protocol",		CMDTYPE_Structure);
	Register("public",			CMDTYPE_Structure);
	Register("publicsection",	CMDTYPE_Structure);
	Register("pure",			CMDTYPE_Structure);
	Register("relates",			CMDTYPE_Structure);
	Register("related",			CMDTYPE_Structure);
	Register("relatedalso",		CMDTYPE_Structure);
	Register("showinitializer",	CMDTYPE_Structure);
	Register("static",			CMDTYPE_Structure);
	Register("struct",			CMDTYPE_Structure);
	Register("typedef",			CMDTYPE_Structure);
	Register("union",			CMDTYPE_Structure);
	Register("var",				CMDTYPE_Structure);
	Register("vhdlflow",		CMDTYPE_Structure);
	Register("weakgroup",		CMDTYPE_Structure);
	// Section indicators
	Register("attention",		CMDTYPE_Section);
	Register("author",			CMDTYPE_Section);
	Register("authors",			CMDTYPE_Section);
	Register("brief",			CMDTYPE_Section);
	Register("bug",				CMDTYPE_Section);
	Register("cond",			CMDTYPE_Section);
	Register("copyright",		CMDTYPE_Section);
	Register("date",			CMDTYPE_Section);
	Register("deprecated",		CMDTYPE_Section);
	Register("details",			CMDTYPE_Section);
	Register("else",			CMDTYPE_Section);
	Register("elseif",			CMDTYPE_Section);
	Register("endcond",			CMDTYPE_Section);
	Register("endif",			CMDTYPE_Section);
	Register("exception",		CMDTYPE_Section);
	Register("if",				CMDTYPE_Section);
	Register("ifnot",			CMDTYPE_Section);
	Register("invariant",		CMDTYPE_Section);
	Register("note",			CMDTYPE_Section);
	Register("par",				CMDTYPE_Section);
	Register("param",			CMDTYPE_Section,
			 ArgBracket("dir"),
			 ArgWord("parameter_name"),
			 ArgPara("parameter_description"));
	Register("parblock",		CMDTYPE_Section);
	Register("endparblock",		CMDTYPE_Section);
	Register("tparam",			CMDTYPE_Section);
	Register("post",			CMDTYPE_Section);
	Register("pre",				CMDTYPE_Section);
	Register("remark",			CMDTYPE_Section);
	Register("remarks",			CMDTYPE_Section);
	Register("result",			CMDTYPE_Section);
	Register("return",			CMDTYPE_Section,
			 ArgPara("description_of_the_return_value"));
	Register("returns",			CMDTYPE_Section);
	Register("retval",			CMDTYPE_Section);
	Register("sa",				CMDTYPE_Section,
			 ArgPara("references"));
	Register("see",				CMDTYPE_Section);
	Register("short",			CMDTYPE_Section);
	Register("since",			CMDTYPE_Section);
	Register("test",			CMDTYPE_Section);
	Register("throw",			CMDTYPE_Section);
	Register("throws",			CMDTYPE_Section);
	Register("todo",			CMDTYPE_Section);
	Register("version",			CMDTYPE_Section);
	Register("warning",			CMDTYPE_Section);
	Register("xrefitem",		CMDTYPE_Section);
	// Commands to create links
	Register("addindex",		CMDTYPE_Link);
	Register("anchor",			CMDTYPE_Link);
	Register("cite",			CMDTYPE_Link);
	Register("endlink",			CMDTYPE_Link);
	Register("link",			CMDTYPE_Link);
	Register("ref",				CMDTYPE_Link);
	Register("refitem",			CMDTYPE_Link);
	Register("secreflist",		CMDTYPE_Link);
	Register("endsecreflist",	CMDTYPE_Link);
	Register("subpage",			CMDTYPE_Link);
	Register("tableofcontents",	CMDTYPE_Link);
	Register("section",			CMDTYPE_Link);
	Register("subsection",		CMDTYPE_Link);
	Register("subsubsection",	CMDTYPE_Link);
	Register("paragrph",		CMDTYPE_Link);
	// Commands for displaying examples
	Register("dontinclude",		CMDTYPE_Example);
	Register("include",			CMDTYPE_Example);
	Register("includelineno",	CMDTYPE_Example);
	Register("line",			CMDTYPE_Example);
	Register("skip",			CMDTYPE_Example);
	Register("skipline",		CMDTYPE_Example);
	Register("snippet",			CMDTYPE_Example);
	Register("until",			CMDTYPE_Example);
	Register("verbinclude",		CMDTYPE_Example);
	Register("htmlinclude",		CMDTYPE_Example);
	Register("latexinclude",	CMDTYPE_Example);
	// Commands for visual enhancements
	Register("a",				CMDTYPE_Visual);
	Register("arg",				CMDTYPE_Visual);
	Register("b",				CMDTYPE_Visual);
	Register("c",				CMDTYPE_Visual);
	Register("code",			CMDTYPE_Visual);
	Register("copydoc",			CMDTYPE_Visual);
	Register("copybrief",		CMDTYPE_Visual);
	Register("copydetails",		CMDTYPE_Visual);
	Register("docbookonly",		CMDTYPE_Visual);
	Register("dot",				CMDTYPE_Visual);
	Register("msc",				CMDTYPE_Visual);
	Register("startuml",		CMDTYPE_Visual);
	Register("dotfile",			CMDTYPE_Visual);
	Register("diafile",			CMDTYPE_Visual);
	Register("e",				CMDTYPE_Visual);
	Register("em",				CMDTYPE_Visual);
	Register("endcode",			CMDTYPE_Visual);
	Register("endcodebookonly",	CMDTYPE_Visual);
	Register("enddot",			CMDTYPE_Visual);
	Register("enduml",			CMDTYPE_Visual);
	Register("endhtmlonly",		CMDTYPE_Visual);
	Register("endlatexonly",	CMDTYPE_Visual);
	Register("endmanonly",		CMDTYPE_Visual);
	Register("endrtfonly",		CMDTYPE_Visual);
	Register("endverbatim",		CMDTYPE_Visual);
	Register("endxmlonly",		CMDTYPE_Visual);
	Register("f$",				CMDTYPE_Visual);
	Register("f[",				CMDTYPE_Visual);
	Register("f]",				CMDTYPE_Visual);
	Register("f}",				CMDTYPE_Visual);
	Register("htmlonly",		CMDTYPE_Visual);
	Register("image",			CMDTYPE_Visual);
	Register("latexonly",		CMDTYPE_Visual);
	Register("manonly",			CMDTYPE_Visual);
	Register("li",				CMDTYPE_Visual);
	Register("n",				CMDTYPE_Visual);
	Register("p",				CMDTYPE_Visual);
	Register("rtfonly",			CMDTYPE_Visual);
	Register("verbatim",		CMDTYPE_Visual);
	Register("xmlonly",			CMDTYPE_Visual);
	Register("\\",				CMDTYPE_Visual);
	Register("\\@",				CMDTYPE_Visual);
	Register("&",				CMDTYPE_Visual);
	Register("$",				CMDTYPE_Visual);
	Register("#",				CMDTYPE_Visual);
	Register("<",				CMDTYPE_Visual);
	Register(">",				CMDTYPE_Visual);
	Register("%",				CMDTYPE_Visual);
	Register("\"",				CMDTYPE_Visual);
	Register(".",				CMDTYPE_Visual);
	Register("::",				CMDTYPE_Visual);
	Register("|",				CMDTYPE_Visual);
	Register("--",				CMDTYPE_Visual);
	Register("---",				CMDTYPE_Visual);
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