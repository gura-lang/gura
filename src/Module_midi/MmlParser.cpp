#include "MmlParser.h"

//-----------------------------------------------------------------------------
// MmlParser
// see http://ja.wikipedia.org/wiki/Music_Macro_Language for MML syntax
//-----------------------------------------------------------------------------
MmlParser::MmlParser()
{
	Reset();
}

void MmlParser::Reset()
{
	_stat			= STAT_Begin;
	_octave			= 4;				// 1-9
	_lengthDefault	= LENGTH_MAX / 4;	// 1-LENGTH_MAX
	_operator		= '\0';
	_operatorSub	= '\0';
	_numAccum		= 0;
}

bool MmlParser::Parse(const char *mml)
{
	for (const char *p = mml; ; p++) {
		char ch = *p;
		if (!FeedChar(ch)) return false;
		if (ch == '\0') break;
	}
	return true;
}

bool MmlParser::FeedChar(int ch)
{
	bool continueFlag;
	if ('a' <= ch && ch <= 'z') ch = ch - 'a' + 'A';
	do {
		continueFlag = false;
		if (_stat == STAT_Begin) {
			if (IsEOD(ch)) {
				// nothing to do
			} else if ('A' <= ch && ch <= 'G') {
				_operator = ch;
				_operatorSub = '\0';
				_numAccum = 0;
				_cntDot = 0;
				_stat = STAT_Note;
			} else if (ch == 'R') {
				_operator = ch;
				_numAccum = 0;
				_cntDot = 0;
				_stat = STAT_RestLengthPre;
			} else if (ch == '&') {
				_operator = ch;
			} else if (ch == 'O') {
				_operator = ch;
				_numAccum = 0;
				_stat = STAT_OctavePre;
			} else if (ch == '>') {
				_operator = ch;
				if (_octave < 255) _octave++;
			} else if (ch == '<') {
				_operator = ch;
				if (_octave > 0) _octave--;
			} else if (ch == 'L') {
				_operator = ch;
				_numAccum = 0;
				_cntDot = 0;
				_stat = STAT_LengthPre;
			} else if (ch == 'V') {
				_operator = ch;
				_numAccum = 0;
				_stat = STAT_VolumePre;
			} else if (ch == '@') {
				_operator = ch;
				_numAccum = 0;
				_stat = STAT_TonePre;
			} else if (ch == 'T') {
				_operator = ch;
				_numAccum = 0;
				_stat = STAT_TempoPre;
			} else {
				// nothing to do
			}
		} else if (_stat == STAT_Note) {		// -------- Note --------
			if (ch == '#' || ch == '+' || ch == '-') {
				_operatorSub = ch;
				_stat = STAT_NoteLengthPre;
			} else if (IsDigit(ch)) {
				continueFlag = true;
				_stat = STAT_NoteLength;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				_stat = STAT_NoteFix;
			}
		} else if (_stat == STAT_NoteLengthPre) {
			if (IsDigit(ch)) {
				continueFlag = true;
				_stat = STAT_NoteLength;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				_stat = STAT_NoteFix;
			}
		} else if (_stat == STAT_NoteLength) {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_cntDot++;
			} else {
				continueFlag = true;
				_stat = STAT_NoteFix;
			}
		} else if (_stat == STAT_NoteFix) {
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
			int length = CalcLength(_numAccum, _cntDot, _lengthDefault);
			OnMmlNote(note, length);
			continueFlag = true;
			_stat = STAT_Begin;
		} else if (_stat == STAT_RestLengthPre) {// -------- Rest --------
			if (IsDigit(ch)) {
				continueFlag = true;
				_stat = STAT_RestLength;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				_stat = STAT_RestFix;
			}
		} else if (_stat == STAT_RestLength) {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_cntDot++;
			} else {
				continueFlag = true;
				_stat = STAT_RestFix;
			}
		} else if (_stat == STAT_RestFix) {
			int length = CalcLength(_numAccum, _cntDot, _lengthDefault);
			OnMmlRest(length);
			continueFlag = true;
			_stat = STAT_Begin;
		} else if (_stat == STAT_OctavePre) {	// -------- Octave --------
			if (IsDigit(ch)) {
				continueFlag = true;
				_stat = STAT_Octave;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				_stat = STAT_OctaveFix;
			}
		} else if (_stat == STAT_Octave) {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				_stat = STAT_OctaveFix;
			}
		} else if (_stat == STAT_OctaveFix) {
			_octave = _numAccum;
			continueFlag = true;
			_stat = STAT_Begin;
		} else if (_stat == STAT_LengthPre) {	// -------- Length --------
			if (IsDigit(ch)) {
				continueFlag = true;
				_stat = STAT_Length;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				_stat = STAT_LengthFix;
			}
		} else if (_stat == STAT_Length) {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else if (ch == '.') {
				_cntDot++;
			} else {
				continueFlag = true;
				_stat = STAT_LengthFix;
			}
		} else if (_stat == STAT_LengthFix) {
			_lengthDefault = CalcLength(_numAccum, _cntDot, _lengthDefault);
			continueFlag = true;
			_stat = STAT_Begin;
		} else if (_stat == STAT_VolumePre) {	// -------- Volume --------
			if (IsDigit(ch)) {
				continueFlag = true;
				_stat = STAT_Volume;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				_stat = STAT_VolumeFix;
			}
		} else if (_stat == STAT_Volume) {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				_stat = STAT_VolumeFix;
			}
		} else if (_stat == STAT_VolumeFix) {
			OnMmlVolume(_numAccum);
			continueFlag = true;
			_stat = STAT_Begin;
		} else if (_stat == STAT_TonePre) {		// ------- Tone --------
			if (IsDigit(ch)) {
				continueFlag = true;
				_stat = STAT_Tone;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				_stat = STAT_ToneFix;
			}
		} else if (_stat == STAT_Tone) {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				_stat = STAT_ToneFix;
			}
		} else if (_stat == STAT_ToneFix) {
			OnMmlTone(_numAccum);
			continueFlag = true;
			_stat = STAT_Begin;
		} else if (_stat == STAT_TempoPre) {	// -------- Tempo --------
			if (IsDigit(ch)) {
				continueFlag = true;
				_stat = STAT_Tempo;
			} else if (IsWhite(ch)) {
				// nothing to do
			} else {
				continueFlag = true;
				_stat = STAT_TempoFix;
			}
		} else if (_stat == STAT_Tempo) {
			if (IsDigit(ch)) {
				_numAccum = _numAccum * 10 + (ch - '0');
			} else {
				continueFlag = true;
				_stat = STAT_TempoFix;
			}
		} else if (_stat == STAT_TempoFix) {
			OnMmlTempo(_numAccum);
			continueFlag = true;
			_stat = STAT_Begin;
		}
	} while (continueFlag);
	return true;
}

int MmlParser::CalcLength(int numDisp, int cntDot, int lengthDefault)
{
	if (numDisp <= 0) return lengthDefault;
	int length = LENGTH_MAX / numDisp;
	for (int lengthDiv = length / 2; lengthDiv > 0 && cntDot > 0;
											lengthDiv /= 2, cntDot--) {
		length += lengthDiv;
	}
	return length;
}

#if 0
void Player::Channel::OnMmlNote(unsigned char note, int length)
{
	_pPort->RawWrite(0x90 + GetChannel(), note, 0x7f);
	OAL::Sleep(.01 * length);
	_pPort->RawWrite(0x90 + GetChannel(), note, 0x00);
}

void Player::Channel::OnMmlRest(int length)
{
	OAL::Sleep(.01 * length);
}

void Player::Channel::OnMmlVolume(int volume)
{
}

void Player::Channel::OnMmlTone(int tone)
{
	_pPort->RawWrite(0xc0 + GetChannel(), static_cast<unsigned char>(tone));
}

void Player::Channel::OnMmlTempo(int tempo)
{
}
#endif
