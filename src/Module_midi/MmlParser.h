#ifndef __MMLPARSER_H__
#define __MMLPARSER_H__
#include <gura.h>
#include "Event.h"

Gura_BeginModule(midi)

class MmlParser {
public:
	enum { NUM_CHANNELS = 16 };
	enum { LENGTH_MAX = 256 };
private:
	enum Stat {
		STAT_Begin,
		STAT_Note, STAT_NoteLengthPre, STAT_NoteLength, STAT_NoteFix,
		STAT_RestLengthPre, STAT_RestLength, STAT_RestFix,
		STAT_OctavePre, STAT_Octave, STAT_OctaveFix,
		STAT_LengthPre, STAT_Length, STAT_LengthFix,
		STAT_VolumePre, STAT_Volume, STAT_VolumeFix,
		STAT_TonePre, STAT_Tone, STAT_ToneFix,
		STAT_TempoPre, STAT_Tempo, STAT_TempoFix,
	};
private:
	Stat _stat;
	int _octave;
	int _lengthDefault;
	int _operator;
	int _operatorSub;
	int _numAccum;
	int _cntDot;
	unsigned long _timeStampTbl[NUM_CHANNELS];
public:
	MmlParser();
	void Reset();
	bool Parse(Signal sig, EventOwner &eventOwner, unsigned char channel, const char *mml);
private:
	bool FeedChar(Signal sig, EventOwner &eventOwner, unsigned char channel, int ch);
private:
	inline static bool IsEOD(int ch) { return ch == '\0' || ch < 0; }
	inline static bool IsWhite(int ch) { return ch == ' ' || ch == '\t'; }
	inline static bool IsDigit(int ch) { return '0' <= ch && ch <= '9'; }
	static int CalcLength(int numDisp, int cntDot, int lengthDefault);
};

}}

#endif
