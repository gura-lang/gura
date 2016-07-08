//=============================================================================
// Parser.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Configuration
//-----------------------------------------------------------------------------
Configuration::Configuration() : _stat(STAT_Init)
{
}

bool Configuration::FeedChar(Environment &env, char ch)
{
	Gura_BeginPushbackRegion();
	switch (_stat) {
	case STAT_Init: {
		if (ch == '#') {
			_stat = STAT_SkipToLineEnd;
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (IsAlpha(ch)) {
			_varName.clear();
			_varName += ch;
			_stat = STAT_VarName;
		} else {
			env.SetError(ERR_SyntaxError, "invalid variable name");
			return false;
		}
		break;
	}
	case STAT_VarName: {
		if (IsAlpha(ch) || IsDigit(ch)) {
			_varName += ch;
		} else {
			_stat = STAT_AssignOp;
		}
		break;
	}
	case STAT_AssignOp: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '=') {
			_varValue.clear();
			_stat = STAT_VarValueBegin;
		} else if (ch == '+') {
			_stat = STAT_Plus;
		} else {
			env.SetError(ERR_SyntaxError, "assign operator is expected");
			return false;
		}
		break;
	}
	case STAT_Plus: {
		if (ch == '=') {
			_varValue.clear();
			_stat = STAT_VarValueBegin;
		} else {
			env.SetError(ERR_SyntaxError, "invalid assign operator");
			return false;
		}
		break;
	}
	case STAT_VarValueBegin: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '\n') {
			// no value is assigned
			_stat = STAT_Init;
		} else if (ch == '"') {
			_stat = STAT_VarValueQuoted;
		} else {
			Gura_Pushback();
			_stat = STAT_VarValue;
		}
		break;
	}
	case STAT_VarValue: {
		if (ch == '\n') {
			
			_stat = STAT_Init;
		} else if (ch == '\\') {
			_stat = STAT_VarValue_Escape;
		} else {
			_varValue += ch;
		}
		break;
	}
	case STAT_VarValue_Escape: {
		_stat = STAT_VarValue;
		break;
	}
	case STAT_VarValueQuoted: {
		if (ch == '\n' || ch == '"') {
			
			_stat = STAT_Init;
		} else if (ch == '\\') {
			_stat = STAT_VarValueQuoted_Escape;
		} else {
			_varValue += ch;
		}
		break;
	}
	case STAT_VarValueQuoted_Escape: {
		if (ch == '\n') {
			
		}
		_stat = STAT_VarValueQuoted;
		break;
	}
	case STAT_SkipToLineEnd: {
		if (ch == '\n') {
			_stat = STAT_Init;
		} else {
			// nothing to do
		}
		break;
	}
	}
	Gura_EndPushbackRegion();
	return true;
}

bool Configuration::ReadStream(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	for (;;) {
		int chRaw;
		if ((chRaw = stream.GetChar(sig)) < 0) chRaw = 0;
		char ch = static_cast<char>(static_cast<UChar>(chRaw));
		if (!FeedChar(env, ch)) return false;
		if (ch == '\0') break;
	}
	return true;
}

Gura_EndModuleScope(doxygen)
