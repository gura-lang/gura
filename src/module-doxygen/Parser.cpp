//=============================================================================
// Parser.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
Parser::Parser() : _stat(STAT_Indent), _pDecomposer(new Decomposer())
{
}

bool Parser::FeedChar(Environment &env, char ch)
{
	Gura_BeginPushbackRegion();
	switch (_stat) {
	case STAT_Indent: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '\n') {
			// nothing to do
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			_stat = STAT_Source;
			Gura_Pushback();
		}
		break;
	}
	case STAT_Source: {
		if (ch == '/') {
			_stat = STAT_Slash;
		} else if (ch == '\n') {
			_stat = STAT_Indent;
		} else { // including '\0'
			// nothing to do
		}
		break;
	}
	case STAT_Slash: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/') {
			_stat = STAT_LineCommentBgn;
		} else if (ch == '*') {
			_stat = STAT_BlockCommentBgn;
		} else {
			_stat = STAT_Source;
			Gura_Pushback();
		}
		break;
	}
	case STAT_LineCommentBgn: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/' || ch == '!') {
			_stat = STAT_LineDoxygen;
		} else {
			_stat = STAT_LineComment;
		}
		break;
	}
	case STAT_LineDoxygen: {
		if (ch == '\n') {
			// a line comment ends with newline.
			_stat = STAT_Indent;
		} else { // including '\0'
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		}
		break;
	}
	case STAT_LineComment: {
		if (ch == '\n') {
			// a line comment ends with newline.
			_stat = STAT_Indent;
		} else { // including '\0'
			// nothing to do
		}
		break;
	}
	case STAT_BlockCommentBgn: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '*') {
			_stat = STAT_BlockCommentBgn_Asterisk;
		} else if (ch == '!') {
			_stat = STAT_BlockDoxygen;
		} else {
			_stat = STAT_BlockComment;
		}
		break;
	}
	case STAT_BlockCommentBgn_Asterisk: {
		if (ch == '/') {
			_stat = STAT_Source;
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockDoxygen: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '*') {
			_stat = STAT_BlockDoxygen_Asterisk;
		} else if (ch == '\n') {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
			_stat = STAT_BlockDoxygen_Indent;
		} else {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		}
		break;
	}
	case STAT_BlockDoxygen_Asterisk: {
		if (ch == '/') {
			_stat = STAT_Source;
		} else { // including '\0'
			if (!_pDecomposer->FeedChar(env, '*')) return false;
			if (!_pDecomposer->FeedChar(env, ch)) return false;
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockDoxygen_Indent: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '\n') {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '*') {
			_stat = STAT_BlockDoxygen_IndentAsterisk;
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockDoxygen_IndentAsterisk: {
		if (ch == '/') {
			_stat = STAT_Source;
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen_IndentAfterAsterisk;
		}
		break;
	}
	case STAT_BlockDoxygen_IndentAfterAsterisk: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '\n') {
			// nothing to do
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockComment: {
		if (ch == '*') {
			_stat = STAT_BlockComment_Asterisk;
		} else { // including '\0'
			// nothing to do
		}
		break;
	}
	case STAT_BlockComment_Asterisk: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/') {
			_stat = STAT_Source;
		} else {
			_stat = STAT_BlockComment;
		}
		break;
	}
	}
	Gura_EndPushbackRegion();
	return true;
}

//-----------------------------------------------------------------------------
// Decomposer
//-----------------------------------------------------------------------------
Decomposer::Decomposer() : _stat(STAT_Text)
{
}

bool Decomposer::FeedChar(Environment &env, char ch)
{
	Gura_BeginPushbackRegion();
	switch (_stat) {
	case STAT_Text: {
		if (ch == '\0') {
			if (_str.empty()) {
				//new Elem_Text(_str);
			}
		} else if (ch == '@' || ch == '\\') {
			if (_str.empty()) {
				//new Elem_Text(_str);
			}
			_str.clear();
			_stat = STAT_Command;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_Command: {
		if (ch == '\0' || ch == ' ' || ch == '\t' || ch == '\n') {
			if (_str.empty()) {
				env.SetError(ERR_SyntaxError, "empty name for command");
				return false;
			}
			::printf("%s\n", _str.c_str());
			//Elem_Command();
			_str.clear();
			_stat = STAT_Text;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_Word: {
		break;
	}
	case STAT_Bracket: {
		break;
	}
	case STAT_Line: {
		break;
	}
	case STAT_Para: {
		break;
	}
	}
	Gura_EndPushbackRegion();
	return true;
}

Gura_EndModuleScope(doxygen)
