#include "MML.h"
#include "Track.h"

Gura_BeginModule(midi)

MML::StateMachineStack::~StateMachineStack()
{
	Clear();
}

void MML::StateMachineStack::Clear()
{
	foreach (StateMachineStack, ppStateMachine, *this) {
		StateMachine *pStateMachine = *ppStateMachine;
		delete pStateMachine;
	}
	clear();
}

//-----------------------------------------------------------------------------
// MML
// see http://ja.wikipedia.org/wiki/Music_Macro_Language for MML syntax
//-----------------------------------------------------------------------------
MML::MML(Track *pTrack, unsigned char channel) : _pTrack(pTrack), _channel(channel)
{
	Reset();
}

void MML::Reset()
{
	_octave			= 4;				// 1-9
	_lengthDefault	= MAX_LENGTH / 4;	// 1-MAX_LENGTH
	_operator		= '\0';
	_operatorSub	= '\0';
	_numAccum		= 0;
	_cntDot			= 0;
	_velocity		= 100;
	_timeStamp 		= 0;
	_stateMachineStack.Clear();
	_stateMachineStack.push_back(new StateMachine());
}

bool MML::Parse(Signal sig, const char *str)
{
	EventOwner &eventOwner = _pTrack->GetEventOwner();
	if (!eventOwner.empty() && _timeStamp < eventOwner.back()->GetTimeStamp()) {
		_timeStamp = eventOwner.back()->GetTimeStamp();
	}
	for (const char *p = str; ; p++) {
		char ch = *p;
		if (!FeedChar(sig, ch)) return false;
		if (ch == '\0') break;
	}
	return true;
}

bool MML::FeedChar(Signal sig, int ch)
{
	EventOwner &eventOwner = _pTrack->GetEventOwner();
	bool continueFlag;
	if ('a' <= ch && ch <= 'z') ch = ch - 'a' + 'A';
	do {
		continueFlag = false;
		StateMachine *pStateMachine = _stateMachineStack.back();
		switch (pStateMachine->GetStat()) {
		case STAT_Begin: {
			if (IsEOD(ch)) {
				// nothing to do
			} else if (ch == 'C') {
				pStateMachine->SetStat(STAT_ChannelMaybe);
			} else if ('A' <= ch && ch <= 'G') {
				_operator = ch;
				_operatorSub = '\0';
				_numAccum = 0;
				_cntDot = 0;
				pStateMachine->SetStat(STAT_Note);
			} else if (ch == 'R') {
				_operator = ch;
				_numAccum = 0;
				_cntDot = 0;
				pStateMachine->SetStat(STAT_RestLengthPre);
			} else if (ch == '&') {
				_operator = ch;
			} else if (ch == 'O') {
				_operator = ch;
				_numAccum = 0;
				pStateMachine->SetStat(STAT_OctavePre);
			} else if (ch == '>') {
				_operator = ch;
				if (_octave < MAX_OCTAVE - 1) _octave++;
			} else if (ch == '<') {
				_operator = ch;
				if (_octave > 0) _octave--;
			} else if (ch == 'L') {
				_operator = ch;
				_numAccum = 0;
				_cntDot = 0;
				pStateMachine->SetStat(STAT_LengthPre);
			} else if (ch == 'V') {
				_operator = ch;
				_numAccum = 0;
				pStateMachine->SetStat(STAT_VelocityPre);
			} else if (ch == '@') {
				_operator = ch;
				_numAccum = 0;
				pStateMachine->SetStat(STAT_ProgramPre);
			} else if (ch == 'T') {
				_operator = ch;
				_numAccum = 0;
				pStateMachine->SetStat(STAT_TempoPre);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				sig.SetError(ERR_FormatError, "invalid character for MML");
				return false;
			}
			break;
		}
		case STAT_Note: {		// -------- Note --------
			if (ch == '#' || ch == '+' || ch == '-') {
				_operatorSub = ch;
				pStateMachine->SetStat(STAT_NoteLengthPre);
			} else if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_NoteLength);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteLengthPre: {
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_NoteLength);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteLength: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_cntDot++;
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteFix: {
			static const unsigned char noteTbl[] = {
				9, 11, 0, 2, 4, 5, 7,
			};
			unsigned char note = noteTbl[_operator - 'A'] + _octave * 12;
			if (_operatorSub == '#' || _operatorSub == '+') {
				if (note < 127) note++;
			} else if (_operatorSub == '-') {
				if (note > 0) note--;
			} else {
				// nothing to do
			}
			int length = CalcLength(_numAccum, _cntDot);
			eventOwner.push_back(new MIDIEvent_NoteOn(
							_timeStamp, _channel, note, _velocity));
			_timeStamp += length;
			eventOwner.push_back(new MIDIEvent_NoteOn(
							_timeStamp, _channel, note, 0));
			
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_ChannelMaybe: {
			if (ch == 'H') {
				_numAccum = 0;
			} else {
				_operator = 'C';
				_operatorSub = '\0';
				_numAccum = 0;
				_cntDot = 0;
				pStateMachine->SetStat(STAT_Note);
				continueFlag = true;
			}
			break;
		}
		case STAT_ChannelPre: {	// -------- Channel --------
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_Channel);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				sig.SetError(ERR_FormatError, "channel number must be specified");
				return false;
			}
			break;
		}
		case STAT_Channel: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_ChannelFix);
			}
			break;
		}
		case STAT_ChannelFix: {
			if (_numAccum > 15) {
				sig.SetError(ERR_FormatError, "channel number must be less than 16");
				return false;
			}
			_channel = static_cast<unsigned char>(_numAccum);
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_RestLengthPre: {// -------- Rest --------
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_RestLength);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_RestFix);
			}
			break;
		}
		case STAT_RestLength: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_cntDot++;
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_RestFix);
			}
			break;
		}
		case STAT_RestFix: {
			int length = CalcLength(_numAccum, _cntDot);
			_timeStamp += length;
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_OctavePre: {	// -------- Octave --------
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_Octave);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_OctaveFix);
			}
			break;
		}
		case STAT_Octave: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_OctaveFix);
			}
			break;
		}
		case STAT_OctaveFix: {
			if (_numAccum > MAX_OCTAVE) {
				sig.SetError(ERR_FormatError,
							"octave number must be less than %d", MAX_OCTAVE + 1);
				return false;
			}
			_octave = _numAccum;
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_LengthPre: {	// -------- Length --------
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_Length);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_LengthFix);
			}
			break;
		}
		case STAT_Length: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_cntDot++;
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_LengthFix);
			}
			break;
		}
		case STAT_LengthFix: {
			_lengthDefault = CalcLength(_numAccum, _cntDot);
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_VelocityPre: {	// -------- Velocity --------
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_Velocity);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_VelocityFix);
			}
			break;
		}
		case STAT_Velocity: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_VelocityFix);
			}
			break;
		}
		case STAT_VelocityFix: {
			if (_numAccum > MAX_VELOCITY) {
				sig.SetError(ERR_FormatError,
							"velocity number must be less than %d", MAX_VELOCITY + 1);
				return false;
			}
			_velocity = static_cast<unsigned char>(_numAccum);
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_ProgramPre: {		// ------- Program --------
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_Program);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_ProgramFix);
			}
			break;
		}
		case STAT_Program: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_ProgramFix);
			}
			break;
		}
		case STAT_ProgramFix: {
			if (_numAccum > MAX_PROGRAM) {
				sig.SetError(ERR_FormatError,
							"program number must be less than %d", MAX_PROGRAM + 1);
				return false;
			}
			unsigned char program = static_cast<unsigned char>(_numAccum);
			eventOwner.push_back(new MIDIEvent_ProgramChange(
									_timeStamp, _channel, program));
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_TempoPre: {	// -------- Tempo --------
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_Tempo);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_TempoFix);
			}
			break;
		}
		case STAT_Tempo: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_TempoFix);
			}
			break;
		}
		case STAT_TempoFix: {
			unsigned long mpqn = static_cast<unsigned long>(60000000 / _numAccum);
			eventOwner.push_back(new MetaEvent_TempoSetting(_timeStamp, mpqn));
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		}
	} while (continueFlag);
	return true;
}

int MML::CalcLength(int numDisp, int cntDot) const
{
	if (numDisp <= 0) return _lengthDefault;
	int length = MAX_LENGTH / numDisp;
	for (int lengthDiv = length / 2; lengthDiv > 0 && cntDot > 0;
											lengthDiv /= 2, cntDot--) {
		length += lengthDiv;
	}
	return length;
}

}}
