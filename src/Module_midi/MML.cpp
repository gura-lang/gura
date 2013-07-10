#include "Module_midi.h"
#include "MML.h"
#include "Track.h"

Gura_BeginModule(midi)

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
	_octave				= 4;				// 1-9
	_octaveOffset		= 0;
	_lengthDefault		= 4;
	_operator			= '\0';
	_operatorSub		= '\0';
	_numAccum			= 0;
	_cntDot				= 0;
	_commentNestLevel	= 0;
	_colonFlag			= false;
	_velocity			= 100;
	_timeStampHead 		= 0;
	_timeStampTail		= 0;
	_stateMachineStack.Clear();
}

void MML::UpdateTimeStamp()
{
	unsigned long timeStamp = _pTrack->GetPrevTimeStamp();
	if (_timeStampHead < timeStamp) {
		_timeStampHead = _timeStampTail = timeStamp;
	}
}

bool MML::ParseString(Signal sig, const char *str)
{
	UpdateTimeStamp();
	unsigned long timeStampBegin = _timeStampHead;
	for (const char *p = str; ; p++) {
		char ch = *p;
		if (!FeedChar(sig, ch)) return false;
		if (ch == '\0') break;
	}
	unsigned long deltaTime = _timeStampTail - timeStampBegin;
	_pTrack->AdjustFollowingTimeStamp(deltaTime);
	return true;
}

bool MML::FeedChar(Signal sig, int ch)
{
	if (_stateMachineStack.empty()) {
		_stateMachineStack.push_back(new StateMachine());
	}
	StateMachine *pStateMachine = _stateMachineStack.back();
	bool continueFlag;
	int chRaw = ch;
	if ('a' <= ch && ch <= 'z') ch = ch - 'a' + 'A';
	do {
		continueFlag = false;
		switch (pStateMachine->GetStat()) {
		case STAT_Begin: {
			if (IsEOD(ch)) {
				if (_stateMachineStack.size() > 1) {
					delete pStateMachine;
					_stateMachineStack.pop_back();
				}
			} else if (ch == ':') {
				_colonFlag = true;
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
			} else if (ch == '(') {
				// nothing to do
			} else if (ch == ')') {
				// nothing to do
			} else if (ch == '~') {
				_octaveOffset++;
			} else if (ch == '_') {
				_octaveOffset--;
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
			} else if (ch == '\r') {
				// nothing to do
			} else if (ch == '\n') {
				// nothing to do
			} else {
				sig.SetError(ERR_FormatError, "invalid character for MML: %c", ch);
				return false;
			}
			break;
		}
		case STAT_RepeatBlock1st: {
			if (ch == '[') {
				pStateMachine->GetStrBlock1st().push_back(chRaw);
				pStateMachine->IncBlockLevel();
			} else if (ch == '/') {
				if (pStateMachine->GetBlockLevel() == 1) {
					pStateMachine->SetStat(STAT_RepeatBlock2nd);
				} else {
					pStateMachine->GetStrBlock1st().push_back(chRaw);
				}
			} else if (ch == ']') {
				if (pStateMachine->DecBlockLevel() == 0) {
					_numAccum = 0;
					pStateMachine->SetStat(STAT_RepeatNumPre);
				} else {
					pStateMachine->GetStrBlock1st().push_back(chRaw);
				}
			} else if (IsEOD(ch)) {
				sig.SetError(ERR_FormatError, "unmatched block brackets");
				return false;
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
				if (pStateMachine->GetBlockLevel() == 1) {
					sig.SetError(ERR_FormatError, "slash can only appear once in a repeat block");
					return false;
				} else {
					pStateMachine->GetStrBlock2nd().push_back(chRaw);
				}
			} else if (ch == ']') {
				if (pStateMachine->DecBlockLevel() == 0) {
					_numAccum = 0;
					pStateMachine->SetStat(STAT_RepeatNumPre);
				} else {
					pStateMachine->GetStrBlock2nd().push_back(chRaw);
				}
			} else if (IsEOD(ch)) {
				sig.SetError(ERR_FormatError, "unmatched block brackets");
				return false;
			} else {
				pStateMachine->GetStrBlock2nd().push_back(chRaw);
			}
			break;
		}
		case STAT_RepeatNumPre: {
			if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_RepeatNum);
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_RepeatNumFix);
			}
			break;
		}
		case STAT_RepeatNum: {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_RepeatNumFix);
			}
			break;
		}
		case STAT_RepeatNumFix: {
			for (int cnt = static_cast<int>(_numAccum); cnt > 0; cnt--) {
				_stateMachineStack.push_back(new StateMachine());
				if (!ParseString(sig, pStateMachine->GetStrBlock1st().c_str())) {
					return false;
				}
				if (cnt > 1) {
					_stateMachineStack.push_back(new StateMachine());
					if (!ParseString(sig, pStateMachine->GetStrBlock2nd().c_str())) {
						return false;
					}
				}
			}
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		case STAT_Note: {		// -------- Note --------
			if (ch == '#' || ch == '+' || ch == '-') {
				_operatorSub = ch;
				pStateMachine->SetStat(STAT_NoteLengthPre);
			} else if (IsDigit(ch)) {
				continueFlag = true;
				pStateMachine->SetStat(STAT_NoteLength);
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_NoteLengthDot);
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
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_NoteLengthDot);
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
				_cntDot = 1;
				pStateMachine->SetStat(STAT_NoteLengthDot);
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_NoteFix);
			}
			break;
		}
		case STAT_NoteLengthDot: {
			if (ch == '.') {
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
			int octave = _octave + _octaveOffset;
			_octaveOffset = 0;
			if (octave < 0 || octave > MAX_OCTAVE) {
				sig.SetError(ERR_FormatError, "octave is out of range");
				return false;
			}
			unsigned char note = noteTbl[_operator - 'A'] + octave * 12;
			if (_operatorSub == '#' || _operatorSub == '+') {
				if (note < 127) note++;
			} else if (_operatorSub == '-') {
				if (note > 0) note--;
			} else {
				// nothing to do
			}
			if (!_colonFlag) _timeStampHead = _timeStampTail;
			_colonFlag = false;
			int deltaTime = CalcDeltaTime(_numAccum, _cntDot);
			_pTrack->AddEvent(new MIDIEvent_NoteOn(
							_timeStampHead, _channel, note, _velocity));
			unsigned long timeStampTail = _timeStampHead + deltaTime;
			_pTrack->AddEvent(new MIDIEvent_NoteOn(
							timeStampTail, _channel, note, 0));
			if (_timeStampTail < timeStampTail) _timeStampTail = timeStampTail;
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
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_RestLengthDot);
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
				_cntDot = 1;
				pStateMachine->SetStat(STAT_RestLengthDot);
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_RestFix);
			}
			break;
		}
		case STAT_RestLengthDot: {
			if (ch == '.') {
				_cntDot++;
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_RestFix);
			}
		}
		case STAT_RestFix: {
			if (!_colonFlag) _timeStampHead = _timeStampTail;
			_colonFlag = false;
			int deltaTime = CalcDeltaTime(_numAccum, _cntDot);
			unsigned long timeStampTail = _timeStampHead + deltaTime;
			if (_timeStampTail < timeStampTail) _timeStampTail = timeStampTail;
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
			} else if (ch == '.') {
				_cntDot = 1;
				pStateMachine->SetStat(STAT_LengthDot);
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
				pStateMachine->SetStat(STAT_LengthDot);
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_LengthFix);
			}
			break;
		}
		case STAT_LengthDot: {
			if (ch == '.') {
				_cntDot++;
			} else {
				continueFlag = true;
				pStateMachine->SetStat(STAT_LengthFix);
			}
		}
		case STAT_LengthFix: {
			_lengthDefault = static_cast<int>(_numAccum);
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
			} else if (ch == '{') {
				_token.clear();
				pStateMachine->SetStat(STAT_ProgramName);
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
		case STAT_ProgramName: {
			if (ch == '}') {
				int program = ProgramIdByName(Strip(_token.c_str()).c_str());
				if (program < 0) {
					sig.SetError(ERR_FormatError, "unknown program %s", _token.c_str());
					return false;
				}
				_numAccum = static_cast<unsigned long>(program);
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
				return false;
			}
			unsigned char program = static_cast<unsigned char>(_numAccum);
			_pTrack->AddEvent(new MIDIEvent_ProgramChange(
									_timeStampHead, _channel, program));
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
			_pTrack->AddEvent(new MetaEvent_TempoSetting(_timeStampHead, mpqn));
			continueFlag = true;
			pStateMachine->SetStat(STAT_Begin);
			break;
		}
		}
	} while (continueFlag);
	return true;
}

int MML::CalcDeltaTime(int length, int cntDot) const
{
	if (length <= 0) length = _lengthDefault;
	int deltaTime = _pTrack->GetProperty()->GetDivision() * 4 / length;
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

}}
