#ifndef __MMLPARSER_H__
#define __MMLPARSER_H__

class MmlParser {
public:
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
public:
	MmlParser();
	void Reset();
	bool Parse(const char *mml);
	bool FeedChar(int ch);
private:
	inline static bool IsEOD(int ch) { return ch == '\0' || ch < 0; }
	inline static bool IsWhite(int ch) { return ch == ' ' || ch == '\t'; }
	inline static bool IsDigit(int ch) { return '0' <= ch && ch <= '9'; }
	virtual void OnMmlNote(unsigned char note, int length) = 0;
	virtual void OnMmlRest(int length) = 0;
	virtual void OnMmlVolume(int volume) = 0;
	virtual void OnMmlTone(int tone) = 0;
	virtual void OnMmlTempo(int tempo) = 0;
	static int CalcLength(int numDisp, int cntDot, int lengthDefault);
};

#endif
