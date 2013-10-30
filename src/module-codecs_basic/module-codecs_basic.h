//-----------------------------------------------------------------------------
// Gura codecs.basoc module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CODECS_BASIC_H__
#define __GURA_MODULE_CODECS_BASIC_H__

#include <gura.h>

Gura_BeginModuleHeader(codecs_basic, basic)

//-----------------------------------------------------------------------------
// Codec_USASCII
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_USASCII : public Codec {
public:
	class GURA_DLLDECLARE Decoder : public Codec::Decoder {
	public:
		inline Decoder(bool delcrFlag) : Codec::Decoder(delcrFlag) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class GURA_DLLDECLARE Encoder : public Codec::Encoder {
	public:
		inline Encoder(bool addcrFlag) : Codec::Encoder(addcrFlag) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
};

//-----------------------------------------------------------------------------
// Codec_UTF8
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_UTF8 : public Codec {
public:
	class GURA_DLLDECLARE Decoder : public Codec::Decoder {
	private:
		int _cntTrails;
	public:
		inline Decoder(bool delcrFlag) : Codec::Decoder(delcrFlag), _cntTrails(0) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class GURA_DLLDECLARE Encoder : public Codec::Encoder {
	private:
		int _cntTrails;
	public:
		inline Encoder(bool addcrFlag) : Codec::Encoder(addcrFlag), _cntTrails(0) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
};

//-----------------------------------------------------------------------------
// Codec_UTF16
//-----------------------------------------------------------------------------
template<int shiftFirst, int shiftSecond>
class GURA_DLLDECLARE Codec_UTF16 : public Codec_UTF {
public:
	class GURA_DLLDECLARE Decoder : public Codec_UTF::Decoder {
	public:
		enum Stat {
			STAT_First, STAT_Second, STAT_LowerFirst, STAT_LowerSecond,
		};
	private:
		Stat _stat;
		ULong _code;
		ULong _codeLower;
	public:
		inline Decoder(bool delcrFlag) : Codec_UTF::Decoder(delcrFlag),
				_stat(STAT_First), _code(0), _codeLower(0) {}
		virtual Result FeedChar(char ch, char &chConv) {
			ULong chCasted = static_cast<ULong>(static_cast<UChar>(ch));
			if (_stat == STAT_First) {
				_code = (chCasted << shiftFirst);
				_stat = STAT_Second;
			} else if (_stat == STAT_Second) {
				_code |= (chCasted << shiftSecond);
				if (GetDelcrFlag() && _code == '\r') {
					_stat = STAT_First;
				} else if (0xd800 <= _code && _code <= 0xdbff) {
					// surrogate pair
					_stat = STAT_LowerFirst;
				} else {
					_stat = STAT_First;
					return FeedUTF32(_code, chConv);
				}
			} else if (_stat == STAT_LowerFirst) {
				_codeLower = (chCasted << shiftFirst);
				_stat = STAT_LowerSecond;
			} else if (_stat == STAT_LowerSecond) {
				_codeLower |= (chCasted << shiftSecond);
				if (0xdc00 <= _codeLower && _codeLower <= 0xdfff) {
					ULong codeUTF32 = 0x10000 +
								((_code - 0xd800) << 10) + (_codeLower - 0xdc00);
					return FeedUTF32(codeUTF32, chConv);
				} else {
					// just ignore illegal codes
				}
				_stat = STAT_First;
			}
			return RESULT_None;
		}
	};
	class GURA_DLLDECLARE Encoder : public Codec_UTF::Encoder {
	public:
		inline Encoder(bool addcrFlag) : Codec_UTF::Encoder(addcrFlag) {}
		virtual Result FeedUTF32(ULong codeUTF32, char &chConv) {
			const ULong codeLF = '\n', codeCR = '\r';
			if (GetAddcrFlag() && codeUTF32 == '\n') {
				StoreChar(static_cast<char>((codeLF >> shiftSecond) & 0xff));
				StoreChar(static_cast<char>((codeLF >> shiftFirst) & 0xff));
				StoreChar(static_cast<char>((codeCR >> shiftSecond) & 0xff));
				chConv = static_cast<char>((codeCR >> shiftFirst) & 0xff);
			} else if (codeUTF32 < 0x10000) {
				StoreChar(static_cast<char>((codeUTF32 >> shiftSecond) & 0xff));
				chConv = static_cast<char>((codeUTF32 >> shiftFirst) & 0xff);
			} else {
				// surrogate pair
				ULong code = (codeUTF32 - 0x10000) & 0xfffff;
				ULong codeUpper = (code >> 12) + 0xd800;
				ULong codeLower = (code & 0x3ff) + 0xdc00;
				StoreChar(static_cast<char>((codeLower >> shiftSecond) & 0xff));
				StoreChar(static_cast<char>((codeLower >> shiftFirst) & 0xff));
				StoreChar(static_cast<char>((codeUpper >> shiftSecond) & 0xff));
				chConv = static_cast<char>((codeUpper >> shiftFirst) & 0xff);
			}
			return RESULT_Complete;
		}
	};
};

Gura_EndModuleHeader(codecs_basic, basic)

#endif
