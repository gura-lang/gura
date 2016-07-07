//=============================================================================
// CommandFormat.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// CommandFormat
//-----------------------------------------------------------------------------
CommandFormatList CommandFormat::_cmdFmtList;
CommandFormatDict CommandFormat::_cmdFmtDict;

String CommandFormat::MakeHandlerDeclaration() const
{
	String str;
	str += "@";
	str += _name;
	str += "(";
	size_t iArg = 0;
	foreach_const (ArgOwner, ppArg, _argOwner) {
		const Arg *pArg = *ppArg;
		if (iArg > 0) str += ", ";
		str += pArg->GetName();
		str += ":string";
		iArg++;
	}
	str += ")";
	return str;
}

bool CommandFormat::HasNormalCommandName() const
{
	foreach_const (String, p, _name) {
		if (!(IsAlpha(*p) || *p == '_')) return false;
	}
	return true;
}

void CommandFormat::Initialize()
{
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
			 ArgLine("declaration"));
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
	Register("overload",		CMDTYPE_Structure,
			 ArgLineOpt("declaration"));
	Register("package",			CMDTYPE_Structure,
			 ArgWord("name"));
	Register("page",			CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgLine("title"));
	Register("private",			CMDTYPE_Structure);
	Register("privatesection",	CMDTYPE_Structure);
	Register("property",		CMDTYPE_Structure,
			 ArgLine("name"));
	Register("protected",		CMDTYPE_Structure);
	Register("protectedsection",CMDTYPE_Structure);
	Register("protocol",		CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("public",			CMDTYPE_Structure);
	Register("publicsection",	CMDTYPE_Structure);
	Register("pure",			CMDTYPE_Structure);
	Register("relates",			CMDTYPE_Structure,
			 ArgWord("name"));
	Register("related",			CMDTYPE_Structure,
			 ArgWord("name"));
	Register("relatesalso",		CMDTYPE_Structure,
			 ArgWord("name"));
	Register("relatedalso",		CMDTYPE_Structure,
			 ArgWord("name"));
	Register("showinitializer",	CMDTYPE_Structure);
	Register("static",			CMDTYPE_Structure);
	Register("struct",			CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("typedef",			CMDTYPE_Structure,
			 ArgLine("declaration"));
	Register("union",			CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("var",				CMDTYPE_Structure,
			 ArgLine("declaration"));
	Register("vhdlflow",		CMDTYPE_Structure,
			 ArgLineOpt("title_for_the_flow_chart"));
	Register("weakgroup",		CMDTYPE_Structure,
			 ArgWord("name"),
			 ArgLineOpt("title"));
	// Section indicators
	Register("attention",		CMDTYPE_Section,
			 ArgPara("text"));
	Register("author",			CMDTYPE_Section,
			 ArgPara("list_of_authors"));
	Register("authors",			CMDTYPE_Section,
			 ArgPara("list_of_authors"));
	Register("brief",			CMDTYPE_Section,
			 ArgPara("description"));
	Register("bug",				CMDTYPE_Section,
			 ArgPara("description"));
	Register("cond",			CMDTYPE_Section,
			 ArgLineOpt("section_label"));
	Register("copyright",		CMDTYPE_Section,
			 ArgPara("description"));
	Register("date",			CMDTYPE_Section,
			 ArgPara("description"));
	Register("deprecated",		CMDTYPE_Section,
			 ArgPara("description"));
	Register("details",			CMDTYPE_Section,
			 ArgPara("description"));
	Register("else",			CMDTYPE_Section);
	Register("elseif",			CMDTYPE_Section,
			 ArgLine("section_label"));
	Register("endcond",			CMDTYPE_Section);
	Register("endif",			CMDTYPE_Section);
	Register("exception",		CMDTYPE_Section,
			 ArgWord("exception_object"),
			 ArgPara("description"));
	Register("if",				CMDTYPE_Section,
			 ArgLine("section_label"));
	Register("ifnot",			CMDTYPE_Section,
			 ArgLine("section_label"));
	Register("invariant",		CMDTYPE_Section,
			 ArgPara("description"));
	Register("note",			CMDTYPE_Section,
			 ArgPara("text"));
	Register("par",				CMDTYPE_Section,
			 ArgLineOpt("paragraph_title"),
			 ArgPara("paragraph"));
	Register("param",			CMDTYPE_Section,
			 ArgBracket("dir"),
			 ArgWord("name"),
			 ArgPara("description"));
	Register("parblock",		CMDTYPE_Section);
	Register("endparblock",		CMDTYPE_Section);
	Register("tparam",			CMDTYPE_Section,
			 ArgWord("name"),
			 ArgPara("description"));
	Register("post",			CMDTYPE_Section,
			 ArgPara("description"));
	Register("pre",				CMDTYPE_Section,
			 ArgPara("description"));
	Register("remark",			CMDTYPE_Section,
			 ArgPara("text"));
	Register("remarks",			CMDTYPE_Section,
			 ArgPara("text"));
	Register("result",			CMDTYPE_Section,
			 ArgPara("description"));
	Register("return",			CMDTYPE_Section,
			 ArgPara("description"));
	Register("returns",			CMDTYPE_Section,
			 ArgPara("description"));
	Register("retval",			CMDTYPE_Section,
			 ArgWord("return_value"),
			 ArgPara("description"));
	Register("sa",				CMDTYPE_Section,
			 ArgPara("references"));
	Register("see",				CMDTYPE_Section,
			 ArgPara("references"));
	Register("short",			CMDTYPE_Section,
			 ArgPara("description"));
	Register("since",			CMDTYPE_Section,
			 ArgPara("text"));
	Register("test",			CMDTYPE_Section,
			 ArgPara("paragraph"));
	Register("throw",			CMDTYPE_Section,
			 ArgWord("exception_object"),
			 ArgPara("description"));
	Register("throws",			CMDTYPE_Section,
			 ArgWord("exception_object"),
			 ArgPara("description"));
	Register("todo",			CMDTYPE_Section,
			 ArgPara("paragraph"));
	Register("version",			CMDTYPE_Section,
			 ArgPara("version_number"));
	Register("warning",			CMDTYPE_Section,
			 ArgPara("message"));
	Register("xrefitem",		CMDTYPE_Section,
			 ArgWord("key"),
			 ArgQuote("heading"),
			 ArgQuote("list_title"),
			 ArgPara("text"));
	// Commands to create links
	Register("addindex",		CMDTYPE_Link,
			 ArgLine("text"));
	Register("anchor",			CMDTYPE_Link,
			 ArgWord("word"));
	Register("cite",			CMDTYPE_Link,
			 ArgWord("label"));
	Register("endlink",			CMDTYPE_Link);
	Register("link",			CMDTYPE_Link,
			 ArgWord("line_object"));
	Register("ref",				CMDTYPE_Link,
			 ArgWord("name"),
			 ArgQuoteOpt("text"));
	Register("refitem",			CMDTYPE_Link,
			 ArgWord("name"));
	Register("secreflist",		CMDTYPE_Link);
	Register("endsecreflist",	CMDTYPE_Link);
	Register("subpage",			CMDTYPE_Link,
			 ArgWord("name"),
			 ArgQuoteOpt("text"));
	Register("tableofcontents",	CMDTYPE_Link);
	Register("section",			CMDTYPE_Link,
			 ArgWord("name"),
			 ArgLine("title"));
	Register("subsection",		CMDTYPE_Link,
			 ArgWord("name"),
			 ArgLine("title"));
	Register("subsubsection",	CMDTYPE_Link,
			 ArgWord("name"),
			 ArgLine("title"));
	Register("paragrph",		CMDTYPE_Link,
			 ArgWord("name"),
			 ArgLine("title"));
	// Commands for displaying examples
	Register("dontinclude",		CMDTYPE_Example,
			 ArgWord("file_name"));
	Register("include",			CMDTYPE_Example,
			 ArgWord("file_name"));
	Register("includelineno",	CMDTYPE_Example,
			 ArgWord("file_name"));
	Register("line",			CMDTYPE_Example,
			 ArgLine("pattern"));
	Register("skip",			CMDTYPE_Example,
			 ArgLine("pattern"));
	Register("skipline",		CMDTYPE_Example,
			 ArgLine("pattern"));
	Register("snippet",			CMDTYPE_Example,
			 ArgWord("file_name"),
			 ArgLine("block_id"));
	Register("until",			CMDTYPE_Example,
			 ArgLine("pattern"));
	Register("verbinclude",		CMDTYPE_Example,
			 ArgWord("file_name"));
	Register("htmlinclude",		CMDTYPE_Example,
			 ArgWord("file_name"));
	Register("latexinclude",	CMDTYPE_Example,
			 ArgWord("file_name"));
	// Commands for visual enhancements
	Register("a",				CMDTYPE_Visual,
			 ArgWord("word"));
	Register("arg",				CMDTYPE_Visual,
			 ArgPara("description"));
	Register("b",				CMDTYPE_Visual,
			 ArgWord("word"));
	Register("c",				CMDTYPE_Visual,
			 ArgWord("word"));
	Register("code",			CMDTYPE_Visual,
			 ArgBraceOpt("word"));
	Register("copydoc",			CMDTYPE_Visual,
			 ArgWord("link_object"));
	Register("copybrief",		CMDTYPE_Visual,
			 ArgWord("link_object"));
	Register("copydetails",		CMDTYPE_Visual,
			 ArgWord("link_object"));
	Register("docbookonly",		CMDTYPE_Visual);
	Register("dot",				CMDTYPE_Visual,
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("msc",				CMDTYPE_Visual,
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("startuml",		CMDTYPE_Visual,
			 ArgBraceOpt("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("dotfile",			CMDTYPE_Visual,
			 ArgWord("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("mscfile",			CMDTYPE_Visual,
			 ArgWord("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("diafile",			CMDTYPE_Visual,
			 ArgWord("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("e",				CMDTYPE_Visual,
			 ArgWord("word"));
	Register("em",				CMDTYPE_Visual,
			 ArgWord("word"));
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
	Register("htmlonly",		CMDTYPE_Visual,
			 ArgQuoteOpt("block"));
	Register("image",			CMDTYPE_Visual,
			 ArgWord("format"),
			 ArgWord("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("latexonly",		CMDTYPE_Visual);
	Register("manonly",			CMDTYPE_Visual);
	Register("li",				CMDTYPE_Visual,
			 ArgPara("description"));
	Register("n",				CMDTYPE_Visual);
	Register("p",				CMDTYPE_Visual,
			 ArgWord("word"));
	Register("rtfonly",			CMDTYPE_Visual);
	Register("verbatim",		CMDTYPE_Visual);
	Register("xmlonly",			CMDTYPE_Visual);
	Register("\\",				CMDTYPE_Visual);
	Register("@",				CMDTYPE_Visual);
	Register("~",				CMDTYPE_Visual,
			 ArgLine("language_id"));
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
	// Grouping
	Register("{",				CMDTYPE_Group);
	Register("}",				CMDTYPE_Group);
};
	
const CommandFormat *CommandFormat::Lookup(const char *name)
{
	CommandFormatDict::iterator iter = _cmdFmtDict.find(name);
	return (iter == _cmdFmtDict.end())? nullptr : iter->second;
}

const char *CommandFormat::ArgTypeToName(ArgType argType)
{
	static const struct {
		ArgType argType;
		const char *name;
	} tbl[] = {
		{ ARGTYPE_Word,		"word"		},
		{ ARGTYPE_WordOpt,	"word?"		},
		{ ARGTYPE_Bracket,	"bracket"	},
		{ ARGTYPE_Line,		"line"		},
		{ ARGTYPE_LineOpt,	"line?"		},
		{ ARGTYPE_Quote,	"quote"		},
		{ ARGTYPE_QuoteOpt,	"quote?"	},
		{ ARGTYPE_Brace,	"brace"		},
		{ ARGTYPE_BraceOpt,	"brace?"	},
		{ ARGTYPE_Para,		"para"		},
	};
	for (int i = 0; i < ArraySizeOf(tbl); i++) {
		if (tbl[i].argType == argType) return tbl[i].name;
	}
	return "";
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
