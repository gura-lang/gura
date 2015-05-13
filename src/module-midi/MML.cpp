#include "stdafx.h"
#include "MML.h"
#include "Track.h"

Gura_BeginModuleScope(midi)

//-----------------------------------------------------------------------------
// MML
// see http://ja.wikipedia.org/wiki/Music_Macro_Language for MML syntax
//-----------------------------------------------------------------------------
MML::MML(int velocityMax) : _pos(0), _velocityMax(velocityMax)
{
	Reset();
}

void MML::Reset()
{
	_octave				= 4;					// 1 - 9
	_octaveOffset		= 0;
	_lengthDefault		= 4;					// 1 - 128
	_length				= _lengthDefault;
	_gateDefault		= 8;					// 0 - 8
	_gate				= _gateDefault;
	_velocityDefault	= _velocityMax * 8 / 10;
	_velocity			= _velocityDefault;
	_operator			= '\0';
	_operatorSub		= '\0';
	_numAccum			= 0;
	_cntDot				= 0;
	_commentNestLevel	= 0;
	_colonFlag			= false;
	_joinFlag			= false;
	_offsetGroup		= -1;
	_timeStampHead 		= 0;
	_timeStampTail		= 0;
	_chOctaveUp			= '<';
	_chOctaveDown		= '>';
	_pMIDIEventLast		= NULL;
}

void MML::UpdateTimeStamp(Track *pTrack)
{
	ULong timeStamp = pTrack->GetPrevTimeStamp();
	if (_timeStampHead < timeStamp) {
		_timeStampHead = _timeStampTail = timeStamp;
	}
}

bool MML::ParseStream(Signal sig, Sequence &sequence, SimpleStream &stream)
{
	bool rtn = true;
	TrackOwner &trackOwner = sequence.GetTrackOwner();
	for (size_t iTrack = 0; ; iTrack++) {
		Track *pTrack = NULL;
		if (iTrack < trackOwner.size()) {
			pTrack = trackOwner[iTrack];
		} else {
			pTrack = new Track(sequence.GetProperty()->Reference());
			trackOwner.push_back(pTrack);
		}
		Result result = ParseStream(sig, pTrack, stream);
		if (result == RSLT_None) {
			break;
		} else if (result == RSLT_Error) {
			rtn = false;
			break;
		} else if (result == RSLT_NewTrack) {
			// nothing to do
		}
		Reset();
	}
	return rtn;
}

bool MML::ParseString(Signal sig, Sequence &sequence, const char *str)
{
	SimpleStream_CStringReader stream(str);
	return ParseStream(sig, sequence, stream);
}

MML::Result MML::ParseStream(Signal sig, Track *pTrack, SimpleStream &stream)
{
	Result result = RSLT_None;
	pTrack->RequestEndOfTrack();
	UpdateTimeStamp(pTrack);
	ULong timeStampBegin = _timeStampHead;
	for (;;) {
		int chRaw = stream.GetChar(sig);
		char ch = (chRaw < 0)? '\0' : static_cast<char>(chRaw);
		result = FeedChar(sig, pTrack, ch);
		if (result != RSLT_None || ch == '\0') break;
	}
	ULong deltaTime = _timeStampTail - timeStampBegin;
	pTrack->AdjustFollowingTimeStamp(deltaTime);
	return result;
}

MML::Result MML::ParseString(Signal sig, Track *pTrack, const char *str)
{
	SimpleStream_CStringReader stream(str);
	return ParseStream(sig, pTrack, stream);
}

MML::Result MML::FeedChar(Signal sig, Track *pTrack, int ch)
{
	Result result = RSLT_None;
	if (_stateMachineStack.empty()) {
		_stateMachineStack.push_back(new StateMachine());
	}
	StateMachine *pStateMachine = _stateMachineStack.back();
	bool pushbackFlag;
	int chRaw = ch;
	if ('a' <= ch && ch <= 'z') ch = ch - 'a' + 'A';
	do {
		pushbackFlag = false;
		switch (pStateMachine->GetStat()) {
		case STAT_Begin: {
			if (IsEOD(ch) || ch == ';') {
				if (_stateMachineStack.size() > 1) {
					delete pStateMachine;
					_stateMachineStack.pop_back();
				}
				if (ch == ';') result = RSLT_NewTrack;
			} else if (ch == '[') {
				pStateMachine->GetStrBlock1st().clear();
				pStateMachine->GetStrBlock2nd().clear();
				pStateMachine->IncBlockLevel();
				pStateMachine->SetStat(STAT_RepeatBlock1st);
			} else if (ch == 'C') {
				pStateMachine->SetStat(STAT_ChannelMaybe);
			} else if ('A' <= ch && ch <= 'G') {
				_operator = ch;
				_operatorSub = '\0';
				_length = _lengthDefault;
				_gate = _gateDefault;
				_velocity = _velocityDefault;
				_numAccum = 0;
				_cntDot = 0;
				pStateMachine->SetStat(STAT_Note);
			} else if (ch == 'R') {
				_operator = ch;
				_length = _lengthDefault;
				_numAccum = 0;
				_cntDot = 0;
				pStateMachine->SetStat(STAT_RestLengthPre);
			} else if (ch == ':') {
				_colonFlag = true;
			} else if (ch == '&') {
				_joinFlag = true;
			} else if (ch == 'O') {
				_operator = ch;
				_numAccum = 0;
				pStateMachine->SetStat(STAT_OctavePre);
			} else if (ch == 'Q') {
				_operator = ch;
				_numAccum = 0;
				pStateMachine->SetStat(STAT_GatePre);
			} else if (ch == _chOctaveUp) {
				_operator = ch;
				if (_octave < MAX_OCTAVE - 1) _octave++;
			} else if (ch == _chOctaveDown) {
				_operator = ch;
				if (_octave > 0) _octave--;
			} else if (ch == '(') {
				if (_offsetGroup >= 0) {
					sig.SetError(ERR_FormatError, "group cannot be nested");
					return RSLT_Error;
				}
				_offsetGroup = pTrack->Tell();
			} else if (ch == ')') {
				if (_offsetGroup < 0) {
					sig.SetError(ERR_FormatError, "unmatched group parenthesis");
					return RSLT_Error;
				}
				_length = _lengthDefault;
				_numAccum = 0;
				_cntDot = 0;
				pStateMachine->SetStat(STAT_GroupLengthPre);
			} else if (ch == '~') {
				_octaveOffset++;
			} else if (ch == '_') {
				_octaveOffset--;
			} else if (ch == 'L') {
				_operator = ch;
				_length = _lengthDefault;
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
			} else if (ch == '\r') {
				// nothing to do
			} else if (ch == '\n') {
				// nothing to do
			} else if (ch == '/') {
				pStateMachine->SetStatToReturn(STAT_Begin);
				pStateMachine->SetStat(STAT_Slash);
			} else {
				sig.SetError(ERR_FormatError, "invalid character for MML: %c", ch);
				return RSLT_Error;
			}
			break;
		}
		case STAT_RepeatBlock1st: {
			if (ch == '[') {
				pStateMachine->GetStrBlock1st().push_back(chRaw);
				pStateMachine->IncBlockLevel();
			} else if (ch == '/') {
				pStateMachine->SetStatToReturn(STAT_RepeatBlock1st);
				pStateMachine->SetStat(STAT_Slash);
			} else if (ch == '|') {
				if (pStateMachine->GetBlockLevel() == 1) {
					pStateMachine->SetStat(STAT_RepeatBlock2nd);
				} else {
					pStateMachine->GetStrBlock1st().push_back(chRaw);
				}
			} else if (ch == ']') {
				if (pStateMachine->DecBlockLevel() == 0) {
					pStateMachine->SetStat(STAT_RepeatNumPre);
				} else {
					pStateMachine->GetStrBlock1st().push_back(chRaw);
				}
			} else if (IsEOD(ch) || ch == ';') {
				sig.SetError(ERR_FormatError, "unmatched block brackets");
				return RSLT_Error;
			} else {
				pStateMachine->GetStrBlock1st().push_back(chRaw);
			}
			break;
		}
		case STAT_RepeatBlock2nd: {
			if (ch == '[') {
				pStateMachine->GetStrBlock2nd().push_back(chRaw);
				pStateMachine->IncBlockLevel();
			} else if (ch == '/') {
				pStateMachine->SetStatToReturn(STAT_RepeatBlock2nd);
				pStateMachine->SetStat(STAT_Slash);
			} else if (ch == '|') {
				if (pStateMachine->GetBlockLevel() == 1) {
					sig.SetError(ERR_FormatError, "second part already exists");
					return RSLT_Error;
				} else {
					pStateMachine->GetStrBlock2nd().push_back(chRaw);
				}
			} else if (ch == ']') {
				if (pStateMachine->DecBlockLevel() == 0) {
					pStateMachine->SetStat(STAT_RepeatNumPre);
				} else {
					pStateMachine->GetStrBlock2nd().push_back(chRaw);
				}
			} else if (IsEOD(ch) || ch == ';') {
				sig.SetError(ERR_FormatError, "unmatched block brackets");
				return RSLT_Error;
			} else {
				pStateMachine->GetStrBlock2nd().push_back(chRaw);
			}
			break;
		}
		case STAT_RepeatNumPre: {
			if (IsDigit(ch)) {
				_numAccum = 0;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_RepeatNum);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				_numAccum = 2;	// default repeat count
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_RepeatNumFix);
			}
			break;
		}
		case STAT_RepeatNum: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_RepeatNumFix);
			}
			break;
		}
		case STAT_RepeatNumFix: {
			for (int cnt = static_cast<int>(_numAccum); cnt > 0; cnt--) {
				_stateMachineStack.push_back(new StateMachine());
				Result result = ParseString(sig, pTrack,
									pStateMachine->GetStrBlock1st().c_str());
				if (result != RSLT_None) return result;
				if (cnt > 1) {
					_stateMachineStack.push_back(new StateMachine());
					Result result = ParseString(sig, pTrack,
									pStateMachine->GetStrBlock2nd().c_str());
					if (result != RSLT_None) return result;
				}
			}
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_Note: {		// -------- Note --------
			if (ch == '#' || ch == '+' || ch == '-') {
				_operatorSub = ch;
				pStateMachine->SetStat(STAT_NoteLengthPre);
			} else if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteLength);
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_NoteLengthDot);
			} else if (ch == ',') {
				pStateMachine->SetStat(STAT_NoteGatePre);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteLengthPre: {
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteLength);
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_NoteLengthDot);
			} else if (ch == ',') {
				pStateMachine->SetStat(STAT_NoteGatePre);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteLength: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_length = _numAccum;
				_cntDot = 1;
				pStateMachine->SetStat(STAT_NoteLengthDot);
			} else if (ch == ',') {
				_length = _numAccum;
				pStateMachine->SetStat(STAT_NoteGatePre);
			} else {
				_length = _numAccum;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteLengthDot: {
			if (ch == '.') {
				_cntDot++;
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteGatePre: {
			if (IsDigit(ch)) {
				_numAccum = 0;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteGate);
			} else if (ch == ',') {
				pStateMachine->SetStat(STAT_NoteVelocityPre);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteGate: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == ',') {
				_gate = _numAccum;
				pStateMachine->SetStat(STAT_NoteVelocityPre);
			} else {
				_gate = _numAccum;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteVelocityPre: {
			if (IsDigit(ch)) {
				_numAccum = 0;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteVelocity);
			} else if (ch == ',') {
				sig.SetError(ERR_FormatError, "too many note parameters");
				return RSLT_Error;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteVelocity: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == ',') {
				sig.SetError(ERR_FormatError, "too many note parameters");
				return RSLT_Error;
			} else {
				if (_numAccum > _velocityMax) {
					sig.SetError(ERR_FormatError,
						"velocity number must be less than %d", _velocityMax + 1);
					return RSLT_Error;
				}
				_velocity = _numAccum;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteFix: {
			static const UChar noteTbl[] = {
				9, 11, 0, 2, 4, 5, 7,
			};
			int octave = _octave + _octaveOffset;
			_octaveOffset = 0;
			if (octave < 0 || octave > MAX_OCTAVE) {
				sig.SetError(ERR_FormatError, "octave is out of range");
				return RSLT_Error;
			}
			UChar note = noteTbl[_operator - 'A'] + octave * 12;
			if (_operatorSub == '#' || _operatorSub == '+') {
				if (note < 127) note++;
			} else if (_operatorSub == '-') {
				if (note > 0) note--;
			} else {
				// nothing to do
			}
			if (!_colonFlag) _timeStampHead = _timeStampTail;
			_colonFlag = false;
			int deltaTime = CalcDeltaTime(pTrack, _length, _cntDot);
			ULong timeStampTail = _timeStampHead + deltaTime;
			ULong timeStampGate = _timeStampHead + deltaTime * _gate / MAX_GATE;
			bool joinedFlag = false;
			if (_joinFlag && _pMIDIEventLast != NULL) {
				if (_pMIDIEventLast->GetNote() == note) {
					joinedFlag = true;
					_pMIDIEventLast->SetTimeStamp(timeStampGate);
				} else {
					_pMIDIEventLast->SetTimeStamp(_timeStampHead + deltaTime / 2);
				}
			}
			_joinFlag = false;
			if (!joinedFlag) {
				UChar channel = pTrack->GetChannel();
				UChar velocity = static_cast<UChar>(
												_velocity * 127 / _velocityMax);
				pTrack->AddEvent(new MIDIEvent_NoteOn(
								_timeStampHead, channel, note, velocity));
				MIDIEvent_NoteOn *pMIDIEvent = new MIDIEvent_NoteOn(
								timeStampGate, channel, note, 0);
				pTrack->AddEvent(pMIDIEvent);
				_pMIDIEventLast = pMIDIEvent;
			}
			if (_timeStampTail < timeStampTail) _timeStampTail = timeStampTail;
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_ChannelMaybe: {
			if (ch == 'H') {
				pStateMachine->SetStat(STAT_ChannelPre);
			} else {
				_operator = 'C';
				_operatorSub = '\0';
				_length = _lengthDefault;
				_gate = _gateDefault;
				_velocity = _velocityDefault;
				_numAccum = 0;
				_cntDot = 0;
				pStateMachine->SetStat(STAT_Note);
				pushbackFlag = true;
			}
			break;
		}
		case STAT_ChannelPre: {	// -------- Channel --------
			if (IsDigit(ch)) {
				_numAccum = 0;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_Channel);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				sig.SetError(ERR_FormatError, "channel number must be specified");
				return RSLT_Error;
			}
			break;
		}
		case STAT_Channel: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_ChannelFix);
			}
			break;
		}
		case STAT_ChannelFix: {
			if (_numAccum > 15) {
				sig.SetError(ERR_FormatError, "channel number must be less than 16");
				return RSLT_Error;
			}
			pTrack->SetChannel(_numAccum);
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_RestLengthPre: {// -------- Rest --------
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_RestLength);
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_RestLengthDot);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_RestFix);
			}
			break;
		}
		case STAT_RestLength: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_length = _numAccum;
				_cntDot = 1;
				pStateMachine->SetStat(STAT_RestLengthDot);
			} else {
				_length = _numAccum;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_RestFix);
			}
			break;
		}
		case STAT_RestLengthDot: {
			if (ch == '.') {
				_cntDot++;
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_RestFix);
			}
		}
		case STAT_RestFix: {
			if (!_colonFlag) _timeStampHead = _timeStampTail;
			_colonFlag = false;
			_joinFlag = false;
			int deltaTime = CalcDeltaTime(pTrack, _length, _cntDot);
			ULong timeStampTail = _timeStampHead + deltaTime;
			if (_timeStampTail < timeStampTail) _timeStampTail = timeStampTail;
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_OctavePre: {	// -------- Octave --------
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_Octave);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_OctaveFix);
			}
			break;
		}
		case STAT_Octave: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_OctaveFix);
			}
			break;
		}
		case STAT_OctaveFix: {
			if (_numAccum > MAX_OCTAVE) {
				sig.SetError(ERR_FormatError,
							"octave number must be less than %d", MAX_OCTAVE + 1);
				return RSLT_Error;
			}
			_octave = _numAccum;
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_GatePre: {	// -------- Gate --------
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_Gate);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_GateFix);
			}
			break;
		}
		case STAT_Gate: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_GateFix);
			}
			break;
		}
		case STAT_GateFix: {
			if (_numAccum > MAX_GATE) {
				sig.SetError(ERR_FormatError,
							"gate number must be less than %d", MAX_GATE + 1);
				return RSLT_Error;
			}
			_gateDefault = _numAccum;
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_LengthPre: {	// -------- Length --------
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_Length);
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_LengthDot);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_LengthFix);
			}
			break;
		}
		case STAT_Length: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_cntDot++;
				pStateMachine->SetStat(STAT_LengthDot);
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_LengthFix);
			}
			break;
		}
		case STAT_LengthDot: {
			if (ch == '.') {
				_cntDot++;
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_LengthFix);
			}
			break;
		}
		case STAT_LengthFix: {
			_lengthDefault = static_cast<int>(_numAccum);
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_VelocityPre: {	// -------- Velocity --------
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_Velocity);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_VelocityFix);
			}
			break;
		}
		case STAT_Velocity: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_VelocityFix);
			}
			break;
		}
		case STAT_VelocityFix: {
			if (_numAccum > _velocityMax) {
				sig.SetError(ERR_FormatError,
					"velocity number must be less than %d", _velocityMax + 1);
				return RSLT_Error;
			}
			_velocityDefault = static_cast<UChar>(_numAccum);
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_ProgramPre: {		// ------- Program --------
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_Program);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else if (ch == '{') {
				_token.clear();
				pStateMachine->SetStat(STAT_ProgramName);
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_ProgramFix);
			}
			break;
		}
		case STAT_Program: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_ProgramFix);
			}
			break;
		}
		case STAT_ProgramName: {
			if (ch == '}') {
				int program = ProgramIdByName(Strip(_token.c_str()).c_str());
				if (program < 0) {
					sig.SetError(ERR_FormatError, "unknown program %s", _token.c_str());
					return RSLT_Error;
				}
				_numAccum = static_cast<ULong>(program);
				pStateMachine->SetStat(STAT_ProgramFix);
			} else {
				_token.push_back(chRaw);
			}
			break;
		}
		case STAT_ProgramFix: {
			if (_numAccum > MAX_PROGRAM) {
				sig.SetError(ERR_FormatError,
							"program number must be less than %d", MAX_PROGRAM + 1);
				return RSLT_Error;
			}
			UChar channel = pTrack->GetChannel();
			UChar program = static_cast<UChar>(_numAccum);
			pTrack->AddEvent(new MIDIEvent_ProgramChange(
									_timeStampHead, channel, program));
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_TempoPre: {	// -------- Tempo --------
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_Tempo);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_TempoFix);
			}
			break;
		}
		case STAT_Tempo: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_TempoFix);
			}
			break;
		}
		case STAT_TempoFix: {
			ULong mpqn = static_cast<ULong>(60000000 / _numAccum);
			pTrack->AddEvent(new MetaEvent_TempoSetting(_timeStampHead, mpqn));
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_GroupLengthPre: {
			if (IsDigit(ch)) {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_GroupLength);
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_GroupLengthDot);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				_offsetGroup = -1;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_Begin);
			}
			break;
		}
		case STAT_GroupLength: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_length = _numAccum;
				_cntDot++;
				pStateMachine->SetStat(STAT_GroupLengthDot);
			} else {
				_length = _numAccum;
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_GroupFix);
			}
			break;
		}
		case STAT_GroupLengthDot: {
			if (ch == '.') {
				_cntDot++;
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_GroupFix);
			}
			break;
		}
		case STAT_GroupFix: {
			const EventOwner &eventOwner = pTrack->GetEventOwner();
			EventOwner::const_iterator ppEvent = eventOwner.begin() + _offsetGroup;
			ULong timeStampHead = (*ppEvent)->GetTimeStamp();
			int deltaTimeOrg = _timeStampTail - timeStampHead;
			if (deltaTimeOrg != 0) {
				int deltaTime = CalcDeltaTime(pTrack, _length, _cntDot);
				for ( ; ppEvent != eventOwner.end(); ppEvent++) {
					Event *pEvent = *ppEvent;
					pEvent->SetTimeStamp((pEvent->GetTimeStamp() - timeStampHead) *
										deltaTime / deltaTimeOrg + timeStampHead);
				}
				_timeStampTail = timeStampHead + deltaTime;
			}
			_offsetGroup = -1;
			pushbackFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_Slash: {
			if (ch == '/') {
				pStateMachine->SetStat(STAT_LineComment);
			} else if (ch == '*') {
				pStateMachine->IncCommentLevel();
				pStateMachine->SetStat(STAT_BlockComment);
			} else {
				sig.SetError(ERR_FormatError, "invalid character for MML: /");
				return RSLT_Error;
			}
			break;
		}
		case STAT_LineComment: {
			if (ch == '\n' || IsEOD(ch)) {
				pStateMachine->SetStat(pStateMachine->GetStatToReturn());
			} else {
				// nothing to do
			}
			break;
		}
		case STAT_BlockComment: {
			if (ch == '/') {
				pStateMachine->SetStat(STAT_BlockCommentSlash);
			} else if (ch == '*') {
				pStateMachine->SetStat(STAT_BlockCommentEnd);
			} else if (IsEOD(ch)) {
				sig.SetError(ERR_FormatError, "block comment is not terminated correctly");
				return RSLT_Error;
			} else {
				// nothing to do
			}
			break;
		}
		case STAT_BlockCommentSlash: {
			if (ch == '*') {
				pStateMachine->IncCommentLevel();
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_BlockComment);
			}
			break;
		}
		case STAT_BlockCommentEnd: {
			if (ch == '/') {
				if (pStateMachine->DecCommentLevel() > 0) {
					pStateMachine->SetStat(STAT_BlockComment);
				} else {
					pStateMachine->SetStat(pStateMachine->GetStatToReturn());
				}
			} else {
				pushbackFlag = true;
				pStateMachine->SetStat(STAT_BlockComment);
			}
			break;
		}
		}
	} while (pushbackFlag);
	_pos++;
	return result;
}

int MML::CalcDeltaTime(const Track *pTrack, int length, int cntDot) const
{
	if (length <= 0) length = _lengthDefault;
	int deltaTime = pTrack->GetProperty()->GetDivision() * 4 / length;
	for (int deltaTimeDiv = deltaTime / 2; deltaTimeDiv > 0 && cntDot > 0;
											deltaTimeDiv /= 2, cntDot--) {
		deltaTime += deltaTimeDiv;
	}
	return deltaTime;
}

//-----------------------------------------------------------------------------
// MML::StateMachineStack
//-----------------------------------------------------------------------------
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

Gura_EndModuleScope(midi)
