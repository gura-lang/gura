#ifndef __MML_H__
#define __MML_H__
#include <gura.h>
#include "Event.h"

Gura_BeginModule(midi)

class Track;

class MML {
public:
	enum {
		MAX_OCTAVE		= 9,
		MAX_VELOCITY	= 127,
		MAX_PROGRAM		= 127,
	};
private:
	enum Stat {
		STAT_Begin,
		STAT_Repeat, STAT_RepeatNumPre, STAT_RepeatNum, STAT_RepeatNumFix,
		STAT_Note, STAT_NoteLengthPre, STAT_NoteLength, STAT_NoteFix, STAT_NotePost,
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
		int _blockLevel;
		String _strBlock;
	public:
		inline StateMachine() : _stat(STAT_Begin), _blockLevel(0) {}
		inline Stat GetStat() const { return _stat; }
		inline void SetStat(Stat stat) { _stat = stat; }
		inline void IncBlockLevel() { _blockLevel++; }
		inline int DecBlockLevel() { --_blockLevel; return _blockLevel; }
		inline String &GetStrBlock() { return _strBlock; }
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
	int _octaveOffset;
	int _lengthDefault;
	int _operator;
	int _operatorSub;
	int _numAccum;
	int _cntDot;
	bool _colonFlag;
	unsigned char _velocity;
	unsigned long _timeStampHead;
	unsigned long _timeStampTail;
	StateMachineStack _stateMachineStack;
public:
	MML(Track *pTrack, unsigned char channel);
	void Reset();
	void UpdateTimeStamp();
	bool ParseString(Signal sig, const char *str);
private:
	bool FeedChar(Signal sig, int ch);
private:
	inline static bool IsEOD(int ch) { return ch == '\0' || ch < 0; }
	inline static bool IsWhite(int ch) { return ch == ' ' || ch == '\t'; }
	inline static bool IsDigit(int ch) { return '0' <= ch && ch <= '9'; }
	int CalcDeltaTime(int length, int cntDot) const;
};

}}

#endif
