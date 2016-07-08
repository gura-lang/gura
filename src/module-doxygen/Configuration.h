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
		STAT_VarName,
		STAT_AssignOp,
		STAT_Plus,
		STAT_VarValueBegin,
		STAT_VarValue,
		STAT_VarValue_Escape,
		STAT_VarValueQuoted,
		STAT_VarValueQuoted_Escape,
		STAT_SkipToLineEnd,
	};
private:
	Stat _stat;
	String _varName;
	String _varValue;
public:
	Configuration();
	bool FeedChar(Environment &env, char ch);
	bool ReadStream(Environment &env, Stream &stream);
};

Gura_EndModuleScope(doxygen)

#endif
