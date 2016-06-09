//=============================================================================
// Gura module: doxygen
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(doxygen)

enum Stat {
	STAT_LineTop,
	STAT_Line,
	STAT_LineCommentBgn,
	STAT_LineCommentDoxy,
	STAT_LineComment,
	STAT_BlockCommentBgn,
	STAT_BlockCommentDoxy,
	STAT_BlockCommentDoxyEnd,
	STAT_BlockComment,
	STAT_BlockCommentEnd,
	STAT_Slash,
};

bool ParseStream(Signal &sig, SimpleStream &stream)
{
	Stat stat = STAT_LineTop;
	for (;;) {
		int chRaw;
		if ((chRaw = stream.GetChar(sig)) < 0) chRaw = 0;
		char ch = static_cast<char>(static_cast<UChar>(chRaw));
		::printf("%c", ch);
		Gura_BeginPushbackRegionEx(char, 16, ch);
		switch (stat) {
		case STAT_LineTop: {
			if (ch == '/') {
				stat = STAT_Slash;
			} else {
				stat = STAT_Line;
				Gura_PushbackEx(ch);
			}
			break;
		}
		case STAT_Line: {
			
			break;
		}
		case STAT_Slash: {
			if (ch == '/') {
				stat = STAT_LineCommentBgn;
			} else if (ch == '*') {
				stat = STAT_BlockCommentBgn;
			} else {
				stat = STAT_Line;
				Gura_PushbackEx(ch);
			}
			break;
		}
		case STAT_LineCommentBgn: {
			if (ch == '/' || ch == '!') {
				stat = STAT_LineCommentDoxy;
			} else {
				stat = STAT_LineComment;
			}
		}
		case STAT_LineCommentDoxy: {
			if (ch == '\n') {
				stat = STAT_LineTop;
			}
			break;
		}
		case STAT_LineComment: {
			if (ch == '\n') {
				stat = STAT_LineTop;
			}
			break;
		}
		case STAT_BlockCommentBgn: {
			if (ch == '*' || ch == '!') {
				stat = STAT_BlockCommentDoxy;
			} else {
				stat = STAT_BlockComment;
			}
		}
		case STAT_BlockCommentDoxy: {
			if (ch == '*') {
				stat = STAT_BlockCommentDoxyEnd;
			}
			break;
		}
		case STAT_BlockComment: {
			if (ch == '*') {
				stat = STAT_BlockCommentEnd;
			}
			break;
		}
		case STAT_BlockCommentDoxyEnd: {
			if (ch == '/') {
				stat = STAT_Line;
			} else {
				Gura_PushbackEx(ch);
				Gura_PushbackEx('*');
				stat = STAT_BlockCommentDoxy;
			}
			break;
		}
		case STAT_BlockCommentEnd: {
			if (ch == '/') {
				stat = STAT_Line;
			} else {
				Gura_PushbackEx(ch);
				Gura_PushbackEx('*');
				stat = STAT_BlockComment;
			}
			break;
		}
		}
		Gura_EndPushbackRegionEx();
		if (ch == '\0') break;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// doxygen.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(test)
{
	Signal &sig = env.GetSignal();
	ParseStream(sig, arg.GetStream(0));
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(doxygen, doxygen)

Gura_RegisterModule(doxygen)
