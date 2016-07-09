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
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '#') {
			_stat = STAT_SkipToLineEnd;
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '\n') {
			// nothing to do
		} else if (IsNameCharBegin(ch)) {
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
		if (IsNameChar(ch)) {
			_name += ch;
		} else { // including '\0'
			Gura_Pushback();
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
		} else { // including '\0'
			env.SetError(ERR_SyntaxError, "assign operator is expected");
			return false;
		}
		break;
	}
	case STAT_PlusAssign: {
		if (ch == '=') {
			_value.clear();
			_stat = STAT_ValueBegin;
		} else { // including '\0'
			env.SetError(ERR_SyntaxError, "invalid assign operator");
			return false;
		}
		break;
	}
	case STAT_ValueBegin: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '\n' || ch == '\0') {
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
		if (ch == '\n' || ch == '\0' || ch == '#') {
			String value = Strip(_value.c_str());
			::printf("%s = '%s'\n", _name.c_str(), value.c_str());
			_stat = (ch == '#')? STAT_SkipToLineEnd : STAT_Init;
		} else if (ch == '\\') {
			_stat = STAT_Value_Escape;
		} else {
			_value += ch;
		}
		break;
	}
	case STAT_Value_Escape: {
		if (ch == '\n' || ch == '\0') {
			_stat = STAT_ValueBegin;
		} else {
			_value += ch;
			_stat = STAT_Value;
		}
		break;
	}
	case STAT_QuotedValue: {
		if (ch == '\n' || ch == '\0') {
			::printf("%s = %s\n", _name.c_str(), _value.c_str());
			_stat = STAT_Init;
		} else if (ch == '"') {
			_stat = STAT_QuotedValueEnd;
		} else if (ch == '\\') {
			_stat = STAT_QuotedValue_Escape;
		} else {
			_value += ch;
		}
		break;
	}
	case STAT_QuotedValueEnd: {
		if (ch == '\n' || ch == '\0') {
			::printf("%s = %s\n", _name.c_str(), _value.c_str());
			_stat = STAT_Init;
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '"') {
			_stat = STAT_QuotedValue;
		} else {
			Gura_Pushback();
			_stat = STAT_Value;
		}
		break;
	}
	case STAT_QuotedValue_Escape: {
		if (ch == '\n' || ch == '\0') {
			
			_stat = STAT_ValueBegin;
		} else {
			_value += ch;
			_stat = STAT_QuotedValue;
		}
		break;
	}
	case STAT_SkipToLineEnd: {
		if (ch == '\n' || ch == '\0') {
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
