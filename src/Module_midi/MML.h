#ifndef __MML_H__
#define __MML_H__
#include <gura.h>
#include "Event.h"

Gura_BeginModule(midi)

class Track;

class MML {
public:
	enum { LENGTH_MAX = 256 };
public:
	class ChannelMapper {
	private:
		int _cntRef;
		unsigned char _channelNext;
	public:
		Gura_DeclareReferenceAccessor(ChannelMapper);
	public:
		inline ChannelMapper() : _cntRef(1), _channelNext(0) {}
	private:
		inline ~ChannelMapper() {}
	public:
		inline unsigned char GetChannelNext() {
			unsigned char rtn = _channelNext;
			if (_channelNext < 15) _channelNext++;
			return rtn;
		}
	};
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
	Track *_pTrack;
	unsigned char _channel;
	Stat _stat;
	int _octave;
	int _lengthDefault;
	int _operator;
	int _operatorSub;
	int _numAccum;
	int _cntDot;
	unsigned long _timeStamp;
public:
	MML(Track *pTrack, unsigned char channel);
	void Reset();
	bool Parse(Signal sig, const char *str);
private:
	bool FeedChar(Signal sig, int ch);
private:
	inline static bool IsEOD(int ch) { return ch == '\0' || ch < 0; }
	inline static bool IsWhite(int ch) { return ch == ' ' || ch == '\t'; }
	inline static bool IsDigit(int ch) { return '0' <= ch && ch <= '9'; }
	static int CalcLength(int numDisp, int cntDot, int lengthDefault);
};

}}

#endif
