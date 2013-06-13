#ifndef __MML_H__
#define __MML_H__
#include <gura.h>
#include "Event.h"

Gura_BeginModule(midi)

class Track;

class MML {
public:
	enum {
		MAX_LENGTH		= 256,
		MAX_OCTAVE		= 9,
		MAX_VELOCITY	= 127,
		MAX_PROGRAM		= 127,
	};
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
		STAT_Repeat,
		STAT_Note, STAT_NoteLengthPre, STAT_NoteLength, STAT_NoteFix,
		STAT_ChannelMaybe, STAT_ChannelPre, STAT_Channel, STAT_ChannelFix,
		STAT_RestLengthPre, STAT_RestLength, STAT_RestFix,
		STAT_OctavePre, STAT_Octave, STAT_OctaveFix,
		STAT_LengthPre, STAT_Length, STAT_LengthFix,
		STAT_VelocityPre, STAT_Velocity, STAT_VelocityFix,
		STAT_ProgramPre, STAT_Program, STAT_ProgramFix,
		STAT_TempoPre, STAT_Tempo, STAT_TempoFix,
	};
	class StateMachine {
	private:
		Stat _stat;
	public:
		inline StateMachine() : _stat(STAT_Begin) {}
		inline Stat GetStat() const { return _stat; }
		inline void SetStat(Stat stat) { _stat = stat; }
	};
	class StateMachineStack : public std::vector<StateMachine *> {
	public:
		~StateMachineStack();
		void Clear();
	};
private:
	Track *_pTrack;
	unsigned char _channel;
	int _octave;
	int _lengthDefault;
	int _operator;
	int _operatorSub;
	int _numAccum;
	int _cntDot;
	unsigned char _velocity;
	unsigned long _timeStamp;
	StateMachineStack _stateMachineStack;
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
	int CalcLength(int numDisp, int cntDot) const;
};

}}

#endif
