//=============================================================================
// Configuration.h
//=============================================================================
#ifndef __GURA_DOXYGEN_CONFIGURATION_H__
#define __GURA_DOXYGEN_CONFIGURATION_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Configuration
//-----------------------------------------------------------------------------
class Configuration {
private:
	enum Stat {
		STAT_Init,
		STAT_Name,
		STAT_Assign,
		STAT_PlusAssign,
		STAT_ValueBegin,
		STAT_Value,
		STAT_Value_Escape,
		STAT_QuotedValue,
		STAT_QuotedValue_Escape,
		STAT_SkipToLineEnd,
	};
private:
	Stat _stat;
	String _name;
	String _value;
public:
	Configuration();
	bool FeedChar(Environment &env, char ch);
	bool ReadStream(Environment &env, Stream &stream);
};

Gura_EndModuleScope(doxygen)

#endif
