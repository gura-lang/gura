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
			_name.clear();
			_name += ch;
			_stat = STAT_Name;
		} else {
			env.SetError(ERR_SyntaxError, "invalid variable name");
			return false;
		}
		break;
	}
	case STAT_Name: {
		if (IsAlpha(ch) || IsDigit(ch)) {
			_name += ch;
		} else {
			_stat = STAT_Assign;
		}
		break;
	}
	case STAT_Assign: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '=') {
			_value.clear();
			_stat = STAT_ValueBegin;
		} else if (ch == '+') {
			_stat = STAT_PlusAssign;
		} else {
			env.SetError(ERR_SyntaxError, "assign operator is expected");
			return false;
		}
		break;
	}
	case STAT_PlusAssign: {
		if (ch == '=') {
			_value.clear();
			_stat = STAT_ValueBegin;
		} else {
			env.SetError(ERR_SyntaxError, "invalid assign operator");
			return false;
		}
		break;
	}
	case STAT_ValueBegin: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '\n') {
			// no value is assigned
			_stat = STAT_Init;
		} else if (ch == '"') {
			_stat = STAT_QuotedValue;
		} else {
			Gura_Pushback();
			_stat = STAT_Value;
		}
		break;
	}
	case STAT_Value: {
		if (ch == '\n') {
			
			_stat = STAT_Init;
		} else if (ch == '\\') {
			_stat = STAT_Value_Escape;
		} else {
			_value += ch;
		}
		break;
	}
	case STAT_Value_Escape: {
		_stat = STAT_Value;
		break;
	}
	case STAT_QuotedValue: {
		if (ch == '\n' || ch == '"') {
			
			_stat = STAT_Init;
		} else if (ch == '\\') {
			_stat = STAT_QuotedValue_Escape;
		} else {
			_value += ch;
		}
		break;
	}
	case STAT_QuotedValue_Escape: {
		if (ch == '\n') {
			
		}
		_stat = STAT_QuotedValue;
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
