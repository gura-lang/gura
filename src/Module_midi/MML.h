#ifndef __MML_H__
#define __MML_H__
#include <gura.h>
#include "Event.h"

Gura_BeginModule(midi)

class Track;
class Sequence;

class MML {
public:
	enum {
		MAX_OCTAVE		= 9,
		MAX_GATE		= 8,
		MAX_PROGRAM		= 127,
	};
	enum Result {
		RSLT_None, RSLT_Error, RSLT_NewTrack,
	};
private:
	enum Stat {
		STAT_Begin,
		STAT_RepeatBlock1st, STAT_RepeatBlock1stSlash,
		STAT_RepeatBlock2nd, STAT_RepeatBlock2ndSlash,
		STAT_RepeatNumPre, STAT_RepeatNum, STAT_RepeatNumFix,
		STAT_Note,
		STAT_NoteLengthPre, STAT_NoteLength, STAT_NoteLengthDot,
		STAT_NoteGatePre, STAT_NoteGate,
		STAT_NoteVelocityPre, STAT_NoteVelocity,
		STAT_NoteFix, STAT_NotePost,
		STAT_ChannelMaybe, STAT_ChannelPre, STAT_Channel, STAT_ChannelFix,
		STAT_RestLengthPre, STAT_RestLength, STAT_RestLengthDot, STAT_RestFix,
		STAT_OctavePre, STAT_Octave, STAT_OctaveFix,
		STAT_GatePre, STAT_Gate, STAT_GateFix,
		STAT_LengthPre, STAT_Length, STAT_LengthDot, STAT_LengthFix,
		STAT_VelocityPre, STAT_Velocity, STAT_VelocityFix,
		STAT_ProgramPre, STAT_Program, STAT_ProgramName, STAT_ProgramFix,
		STAT_TempoPre, STAT_Tempo, STAT_TempoFix,
		STAT_GroupLengthPre, STAT_GroupLength, STAT_GroupLengthDot, STAT_GroupFix,
		STAT_Slash, STAT_LineComment,
		STAT_BlockComment, STAT_BlockCommentSlash, STAT_BlockCommentEnd,
	};
	class StateMachine {
	private:
		Stat _stat;
		Stat _statToReturn;
		int _blockLevel;
		int _commentLevel;
		String _strBlock1st;
		String _strBlock2nd;
	public:
		inline StateMachine() : _stat(STAT_Begin), _statToReturn(STAT_Begin),
											_blockLevel(0), _commentLevel(0) {}
		inline Stat GetStat() const { return _stat; }
		inline void SetStat(Stat stat) { _stat = stat; }
		inline Stat GetStatToReturn() const { return _statToReturn; }
		inline void SetStatToReturn(Stat statToReturn) { _statToReturn = statToReturn; }
		inline int GetBlockLevel() const { return _blockLevel; }
		inline void IncBlockLevel() { _blockLevel++; }
		inline int DecBlockLevel() { --_blockLevel; return _blockLevel; }
		inline void IncCommentLevel() { _commentLevel++; }
		inline int DecCommentLevel() { --_commentLevel; return _commentLevel; }
		inline String &GetStrBlock1st() { return _strBlock1st; }
		inline String &GetStrBlock2nd() { return _strBlock2nd; }
	};
	class StateMachineStack : public std::vector<StateMachine *> {
	public:
		~StateMachineStack();
		void Clear();
	};
private:
	int _octave;
	int _octaveOffset;
	int _lengthDefault;
	int _length;
	int _gateDefault;
	int _gate;
	int _velocityMax;
	int _velocityDefault;
	int _velocity;
	int _operator;
	int _operatorSub;
	int _numAccum;
	int _cntDot;
	int _commentNestLevel;
	bool _colonFlag;
	bool _joinFlag;
	long _offsetGroup;
	unsigned long _timeStampHead;
	unsigned long _timeStampTail;
	char _chOctaveUp;
	char _chOctaveDown;
	String _token;
	MIDIEvent_NoteOn *_pMIDIEventLast;
	StateMachineStack _stateMachineStack;
public:
	MML(int velocityMax);
	void Reset();
	void UpdateTimeStamp(Track *pTrack);
	bool ParseStream(Signal sig, Sequence &sequence, SimpleStream &stream);
	bool ParseString(Signal sig, Sequence &sequence, const char *str);
	Result ParseStream(Signal sig, Track *pTrack, SimpleStream &stream);
	Result ParseString(Signal sig, Track *pTrack, const char *str);
private:
	Result FeedChar(Signal sig, Track *pTrack, int ch);
private:
	inline static bool IsEOD(int ch) { return ch == '\0' || ch < 0; }
	inline static bool IsWhite(int ch) { return ch == ' ' || ch == '\t'; }
	inline static bool IsDigit(int ch) { return '0' <= ch && ch <= '9'; }
	int CalcDeltaTime(const Track *pTrack, int length, int cntDot) const;
};

}}

#endif
