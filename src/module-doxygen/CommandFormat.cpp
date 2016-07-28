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
	str += GetName();
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
	for (const char *p = GetName(); *p != '\0'; p++) {
		if (!(IsAlpha(*p) || *p == '_')) return false;
	}
	return true;
}

void CommandFormat::Initialize()
{
	// Structural indicators
	Register("addtogroup",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgLineOpt("title"));
	Register("callgraph",		CMDTYPE_Structure, nullptr);
	Register("hidecallgrph",	CMDTYPE_Structure, nullptr);
	Register("callergraph",		CMDTYPE_Structure, nullptr);
	Register("hidecallergraph",	CMDTYPE_Structure, nullptr);
	Register("category",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("class",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("def",				CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("defgroup",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgLine("group_title"));
	Register("dir",				CMDTYPE_Structure, nullptr,
			 ArgWordOpt("path_fragment"));
	Register("enum",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("example",			CMDTYPE_Structure, nullptr,
			 ArgWord("file_name"));
	Register("endinternal",		CMDTYPE_Structure, nullptr);
	Register("extends",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("file",			CMDTYPE_Structure, nullptr,
			 ArgWordOpt("name"));
	Register("fn",				CMDTYPE_Structure, nullptr,
			 ArgLine("declaration"));
	Register("headerfile",		CMDTYPE_Structure, nullptr,
			 ArgWord("header_file"),
			 ArgWordOpt("header_name"));
	Register("hideinitializer",	CMDTYPE_Structure, nullptr);
	Register("idlexcept",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("implements",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("ingroup",			CMDTYPE_Structure, nullptr,
			 ArgWord("groupname"));
	Register("interface",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("internal",		CMDTYPE_Structure, End("endinternal"));
	Register("mainpage",		CMDTYPE_Structure, nullptr,
			 ArgLineOpt("title"));
	Register("memberof",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("name",			CMDTYPE_Structure, nullptr,
			 ArgLineOpt("header"));
	Register("namespace",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("nosubgrouping",	CMDTYPE_Structure, nullptr);
	Register("overload",		CMDTYPE_Structure, nullptr,
			 ArgLineOpt("declaration"));
	Register("package",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("page",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgLine("title"));
	Register("private",			CMDTYPE_Structure, nullptr);
	Register("privatesection",	CMDTYPE_Structure, nullptr);
	Register("property",		CMDTYPE_Structure, nullptr,
			 ArgLine("name"));
	Register("protected",		CMDTYPE_Structure, nullptr);
	Register("protectedsection",CMDTYPE_Structure, nullptr);
	Register("protocol",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("public",			CMDTYPE_Structure, nullptr);
	Register("publicsection",	CMDTYPE_Structure, nullptr);
	Register("pure",			CMDTYPE_Structure, nullptr);
	Register("relates",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("related",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("relatesalso",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("relatedalso",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"));
	Register("showinitializer",	CMDTYPE_Structure, nullptr);
	Register("static",			CMDTYPE_Structure, nullptr);
	Register("struct",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("typedef",			CMDTYPE_Structure, nullptr,
			 ArgLine("declaration"));
	Register("union",			CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgWordOpt("header_file"),
			 ArgWordOpt("header_name"));
	Register("var",				CMDTYPE_Structure, nullptr,
			 ArgLine("declaration"));
	Register("vhdlflow",		CMDTYPE_Structure, nullptr,
			 ArgLineOpt("title_for_the_flow_chart"));
	Register("weakgroup",		CMDTYPE_Structure, nullptr,
			 ArgWord("name"),
			 ArgLineOpt("title"));
	// Section indicators
	Register("attention",		CMDTYPE_Section, nullptr,
			 ArgPara("text"));
	Register("author",			CMDTYPE_Section, nullptr,
			 ArgPara("list_of_authors"));
	Register("authors",			CMDTYPE_Section, nullptr,
			 ArgPara("list_of_authors"));
	Register("brief",			CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("bug",				CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("cond",			CMDTYPE_Section, End("endcode"),
			 ArgLineOpt("section_label"));
	Register("copyright",		CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("date",			CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("deprecated",		CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("details",			CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("else",			CMDTYPE_Section, End("endif"));
	Register("elseif",			CMDTYPE_Section, End("else", "elseif", "endif"),
			 ArgLine("section_label"));
	Register("endcond",			CMDTYPE_Section, nullptr);
	Register("endif",			CMDTYPE_Section, nullptr);
	Register("exception",		CMDTYPE_Section, nullptr,
			 ArgWord("exception_object"),
			 ArgPara("description"));
	Register("if",				CMDTYPE_Section, End("else", "elseif", "endif"),
			 ArgLine("section_label"));
	Register("ifnot",			CMDTYPE_Section, End("else", "elseif", "endif"),
			 ArgLine("section_label"));
	Register("invariant",		CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("note",			CMDTYPE_Section, nullptr,
			 ArgPara("text"));
	Register("par",				CMDTYPE_Section, nullptr,
			 ArgLineOpt("paragraph_title"),
			 ArgPara("paragraph"));
	Register("param",			CMDTYPE_Section, nullptr,
			 ArgBracket("dir"),
			 ArgWord("name"),
			 ArgPara("description"));
	Register("parblock",		CMDTYPE_Section, End("endparblock"));
	Register("endparblock",		CMDTYPE_Section, nullptr);
	Register("tparam",			CMDTYPE_Section, nullptr,
			 ArgWord("name"),
			 ArgPara("description"));
	Register("post",			CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("pre",				CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("remark",			CMDTYPE_Section, nullptr,
			 ArgPara("text"));
	Register("remarks",			CMDTYPE_Section, nullptr,
			 ArgPara("text"));
	Register("result",			CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("return",			CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("returns",			CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("retval",			CMDTYPE_Section, nullptr,
			 ArgWord("return_value"),
			 ArgPara("description"));
	Register("sa",				CMDTYPE_Section, nullptr,
			 ArgPara("references"));
	Register("see",				CMDTYPE_Section, nullptr,
			 ArgPara("references"));
	Register("short",			CMDTYPE_Section, nullptr,
			 ArgPara("description"));
	Register("since",			CMDTYPE_Section, nullptr,
			 ArgPara("text"));
	Register("test",			CMDTYPE_Section, nullptr,
			 ArgPara("paragraph"));
	Register("throw",			CMDTYPE_Section, nullptr,
			 ArgWord("exception_object"),
			 ArgPara("description"));
	Register("throws",			CMDTYPE_Section, nullptr,
			 ArgWord("exception_object"),
			 ArgPara("description"));
	Register("todo",			CMDTYPE_Section, nullptr,
			 ArgPara("paragraph"));
	Register("version",			CMDTYPE_Section, nullptr,
			 ArgPara("version_number"));
	Register("warning",			CMDTYPE_Section, nullptr,
			 ArgPara("message"));
	Register("xrefitem",		CMDTYPE_Section, nullptr,
			 ArgWord("key"),
			 ArgQuote("heading"),
			 ArgQuote("list_title"),
			 ArgPara("text"));
	// Commands to create links
	Register("addindex",		CMDTYPE_Link, nullptr,
			 ArgLine("text"));
	Register("anchor",			CMDTYPE_Link, nullptr,
			 ArgWord("word"));
	Register("cite",			CMDTYPE_Link, nullptr,
			 ArgWord("label"));
	Register("endlink",			CMDTYPE_Link, nullptr);
	Register("link",			CMDTYPE_Link, End("endlink"),
			 ArgWord("line_object"));
	Register("ref",				CMDTYPE_Link, nullptr,
			 ArgWord("name"),
			 ArgQuoteOpt("text"));
	Register("refitem",			CMDTYPE_Link, nullptr,
			 ArgWord("name"));
	Register("secreflist",		CMDTYPE_Link, End("endsecreflist"));
	Register("endsecreflist",	CMDTYPE_Link, nullptr);
	Register("subpage",			CMDTYPE_Link, nullptr,
			 ArgWord("name"),
			 ArgQuoteOpt("text"));
	Register("tableofcontents",	CMDTYPE_Link, nullptr);
	Register("section",			CMDTYPE_Link, nullptr,
			 ArgWord("name"),
			 ArgLine("title"));
	Register("subsection",		CMDTYPE_Link, nullptr,
			 ArgWord("name"),
			 ArgLine("title"));
	Register("subsubsection",	CMDTYPE_Link, nullptr,
			 ArgWord("name"),
			 ArgLine("title"));
	Register("paragrph",		CMDTYPE_Link, nullptr,
			 ArgWord("name"),
			 ArgLine("title"));
	// Commands for displaying examples
	Register("dontinclude",		CMDTYPE_Example, nullptr,
			 ArgWord("file_name"));
	Register("include",			CMDTYPE_Example, nullptr,
			 ArgWord("file_name"));
	Register("includelineno",	CMDTYPE_Example, nullptr,
			 ArgWord("file_name"));
	Register("line",			CMDTYPE_Example, nullptr,
			 ArgLine("pattern"));
	Register("skip",			CMDTYPE_Example, nullptr,
			 ArgLine("pattern"));
	Register("skipline",		CMDTYPE_Example, nullptr,
			 ArgLine("pattern"));
	Register("snippet",			CMDTYPE_Example, nullptr,
			 ArgWord("file_name"),
			 ArgLine("block_id"));
	Register("until",			CMDTYPE_Example, nullptr,
			 ArgLine("pattern"));
	Register("verbinclude",		CMDTYPE_Example, nullptr,
			 ArgWord("file_name"));
	Register("htmlinclude",		CMDTYPE_Example, nullptr,
			 ArgWord("file_name"));
	Register("latexinclude",	CMDTYPE_Example, nullptr,
			 ArgWord("file_name"));
	// Commands for visual enhancements
	Register("a",				CMDTYPE_Visual, nullptr,
			 ArgWord("word"));
	Register("arg",				CMDTYPE_Visual, nullptr,
			 ArgPara("description"));
	Register("b",				CMDTYPE_Visual, nullptr,
			 ArgWord("word"));
	Register("c",				CMDTYPE_Visual, nullptr,
			 ArgWord("word"));
	Register("code",			CMDTYPE_Visual, End("endcode"),
			 ArgBraceOpt("word"));
	Register("copydoc",			CMDTYPE_Visual, nullptr,
			 ArgWord("link_object"));
	Register("copybrief",		CMDTYPE_Visual, nullptr,
			 ArgWord("link_object"));
	Register("copydetails",		CMDTYPE_Visual, nullptr,
			 ArgWord("link_object"));
	Register("docbookonly",		CMDTYPE_Visual, nullptr);
	Register("dot",				CMDTYPE_Visual, End("enddot"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("msc",				CMDTYPE_Visual, nullptr,
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("startuml",		CMDTYPE_Visual, nullptr,
			 ArgBraceOpt("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("dotfile",			CMDTYPE_Visual, nullptr,
			 ArgWord("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("mscfile",			CMDTYPE_Visual, nullptr,
			 ArgWord("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("diafile",			CMDTYPE_Visual, nullptr,
			 ArgWord("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("e",				CMDTYPE_Visual, nullptr,
			 ArgWord("word"));
	Register("em",				CMDTYPE_Visual, nullptr,
			 ArgWord("word"));
	Register("endcode",			CMDTYPE_Visual, nullptr);
	Register("endcodebookonly",	CMDTYPE_Visual, nullptr);
	Register("enddot",			CMDTYPE_Visual, nullptr);
	Register("enduml",			CMDTYPE_Visual, nullptr);
	Register("endhtmlonly",		CMDTYPE_Visual, nullptr);
	Register("endlatexonly",	CMDTYPE_Visual, nullptr);
	Register("endmanonly",		CMDTYPE_Visual, nullptr);
	Register("endrtfonly",		CMDTYPE_Visual, nullptr);
	Register("endverbatim",		CMDTYPE_Visual, nullptr);
	Register("endxmlonly",		CMDTYPE_Visual, nullptr);
	Register("f$",				CMDTYPE_Visual, nullptr);
	Register("f[",				CMDTYPE_Visual, nullptr);
	Register("f]",				CMDTYPE_Visual, nullptr);
	Register("f}",				CMDTYPE_Visual, nullptr);
	Register("htmlonly",		CMDTYPE_Visual, End("endhtmlonly"),
			 ArgQuoteOpt("block"));
	Register("image",			CMDTYPE_Visual, nullptr,
			 ArgWord("format"),
			 ArgWord("file"),
			 ArgQuoteOpt("caption"),
			 ArgLineOpt("size"));
	Register("latexonly",		CMDTYPE_Visual, End("endlatexonly"));
	Register("manonly",			CMDTYPE_Visual, End("endmanonly"));
	Register("li",				CMDTYPE_Visual, nullptr,
			 ArgPara("description"));
	Register("n",				CMDTYPE_Visual, nullptr);
	Register("p",				CMDTYPE_Visual, nullptr,
			 ArgWord("word"));
	Register("rtfonly",			CMDTYPE_Visual, End("endrtfonly"));
	Register("verbatim",		CMDTYPE_Visual, End("endverbatime"));
	Register("xmlonly",			CMDTYPE_Visual, End("endxmlonly"));
	Register("\\",				CMDTYPE_Visual, nullptr);
	Register("@",				CMDTYPE_Visual, nullptr);
	Register("~",				CMDTYPE_Visual, nullptr,
			 ArgLine("language_id"));
	Register("&",				CMDTYPE_Visual, nullptr);
	Register("$",				CMDTYPE_Visual, nullptr);
	Register("#",				CMDTYPE_Visual, nullptr);
	Register("<",				CMDTYPE_Visual, nullptr);
	Register(">",				CMDTYPE_Visual, nullptr);
	Register("%",				CMDTYPE_Visual, nullptr);
	Register("\"",				CMDTYPE_Visual, nullptr);
	Register(".",				CMDTYPE_Visual, nullptr);
	Register("::",				CMDTYPE_Visual, nullptr);
	Register("|",				CMDTYPE_Visual, nullptr);
	Register("--",				CMDTYPE_Visual, nullptr);
	Register("---",				CMDTYPE_Visual, nullptr);
	// Grouping
	Register("{",				CMDTYPE_Group, nullptr);
	Register("}",				CMDTYPE_Group, nullptr);
};
	
const CommandFormat *CommandFormat::Lookup(const char *name)
{
	CommandFormatDict::iterator iter = _cmdFmtDict.find(name);
	return (iter == _cmdFmtDict.end())? nullptr : iter->second;
}

void CommandFormat::MakeScript(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	const CommandFormatList &cmdFmtList = GetCommandFormatList();
	stream.Printf(sig, "Renderer = class(doxygen.renderer) {\n");
	if (sig.IsSignalled()) return;
	CmdType cmdTypePrev = CMDTYPE_None;
	foreach_const (CommandFormatList, ppCmdFmt, cmdFmtList) {
		const CommandFormat *pCmdFmt = *ppCmdFmt;
		CmdType cmdType = pCmdFmt->GetType();
		if (cmdTypePrev != cmdType) {
			cmdTypePrev = cmdType;
			const char *label = "(unknown)";
			if (cmdType == CMDTYPE_Structure) {
				label = "Structural indicators";
			} else if (cmdType == CMDTYPE_Section) {
				label = "Section indicators";
			} else if (cmdType == CMDTYPE_Link) {
				label = "Commands to create links";
			} else if (cmdType == CMDTYPE_Example) {
				label = "Commands for displaying examples";
			} else if (cmdType == CMDTYPE_Visual) {
				label = "Commands for visual enhancements";
			} else if (cmdType == CMDTYPE_Group) {
				label = "Grouping";
			}
			stream.Println(sig, "\t//------------------------------------------------------------");
			stream.Printf(sig, "\t// %s\n", label);
			stream.Println(sig, "\t//------------------------------------------------------------");
		}
		if (pCmdFmt->HasNormalCommandName()) {
			String str;
			str += "\t";
			str += pCmdFmt->MakeHandlerDeclaration();
			str += " = '@";
			str += pCmdFmt->GetName();
			str += "{'";
			size_t iArg = 0;
			foreach_const (ArgOwner, ppArg, pCmdFmt->GetArgOwner()) {
				const Arg *pArg = *ppArg;
				str += " + ";
				str += (iArg == 0)? "'" : "',";
				str += pArg->GetName();
				str += ":' + ";
				str += pArg->GetName();
				str += ".escape():surround";
				iArg++;
			}
			str += (pCmdFmt->IsSectionIndicator() || pCmdFmt->IsLineIndicator())?
				" + '}\\n'" : " + '}'";
			stream.Println(sig, str.c_str());
		} else {
			stream.Printf(sig, "\t// %s = ''\n", pCmdFmt->MakeHandlerDeclaration().c_str());
		}
		if (sig.IsSignalled()) return;
	}
	stream.Printf(sig, "}\n");
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

//-----------------------------------------------------------------------------
// CommandFormat::EndDetector
//-----------------------------------------------------------------------------
bool CommandFormat::EndDetector::IsEndCommand(const char *name) const
{
	return _namesEnd.find(name) != _namesEnd.end();
}

Gura_EndModuleScope(doxygen)
