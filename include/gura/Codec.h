//=============================================================================
// Codec
//=============================================================================
#ifndef __GURA_CODEC_H__
#define __GURA_CODEC_H__
#include "Common.h"
#include "Signal.h"

namespace Gura {

class Binary;
class Codec;

//-----------------------------------------------------------------------------
// CodecFactory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecFactory {
public:
	typedef std::vector<CodecFactory *> List;
private:
	String _encoding;
	static List *_pList;
public:
	CodecFactory(const char *encoding);
	inline const char *GetEncoding() const { return _encoding.c_str(); }
	virtual Codec *CreateCodec(bool delcrFlag, bool addcrFlag) = 0;
	static void Register(CodecFactory *pFactory);
	static CodecFactory *Lookup(const char *name);
	static inline const List *GetList() { return _pList; }
};

//-----------------------------------------------------------------------------
// Codec
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec {
public:
	enum Result {
		RESULT_None,
		RESULT_Complete,
		RESULT_Error,
	};
	enum WidthProp {
		WIDTHPROP_N,
		WIDTHPROP_A,
		WIDTHPROP_H,
		WIDTHPROP_W,
		WIDTHPROP_F,
		WIDTHPROP_Na,
	};
	typedef std::map<UShort, UShort> Map;
	struct CodeRow {
		int nCols;
		const UShort *row;
	};
	struct WidthInfo {
		ULong codeUTF32Ceil;
		WidthProp widthProp;
	};
public:
	class GURA_DLLDECLARE DecEncBase {
	protected:
		int _idxBuff;
		char _buffOut[8];
	public:
		inline DecEncBase() : _idxBuff(0) {}
		bool FollowChar(char &chConv);
		virtual Result FeedChar(char ch, char &chConv) = 0;
		virtual Result Flush(char &chConv);
	protected:
		inline void StoreChar(char ch) { _buffOut[_idxBuff++] = ch; }
	};
	class GURA_DLLDECLARE Decoder : public DecEncBase {
	private:
		bool _delcrFlag;
	public:
		inline Decoder(bool delcrFlag) : _delcrFlag(delcrFlag) {}
		inline void SetDelcrFlag(bool delcrFlag) { _delcrFlag = delcrFlag; }
		inline bool GetDelcrFlag() const { return _delcrFlag; }
		bool Decode(Signal sig, String &dst, const char *buff, size_t bytes);
		bool Decode(Signal sig, String &dst, const Binary &src);
		Decoder *Duplicate() const;
	};
	class GURA_DLLDECLARE Encoder : public DecEncBase {
	private:
		bool _addcrFlag;
	public:
		inline Encoder(bool addcrFlag) : _addcrFlag(addcrFlag) {}
		bool Encode(Signal sig, Binary &dst, const char *str);
		inline void SetAddcrFlag(bool addcrFlag) { _addcrFlag = addcrFlag; }
		inline bool GetAddcrFlag() const { return _addcrFlag; }
		inline bool Encode(Signal sig, Binary &dst, const String &src) {
			return Encode(sig, dst, src.c_str());
		}
		Encoder *Duplicate() const;
	};
private:
	int _cntRef;
	CodecFactory *_pFactory;
	std::auto_ptr<Decoder> _pDecoder;
	std::auto_ptr<Encoder> _pEncoder;
	static CodecFactory *_pFactory_None;
	static const WidthInfo _widthInfoTbl[];
public:
	static const char *BOM_UTF8;
	static const char *BOM_UTF16BE;
	static const char *BOM_UTF16LE;
	static const char *BOM_UTF32BE;
	static const char *BOM_UTF32LE;
public:
	Gura_DeclareReferenceAccessor(Codec);
public:
	Codec(CodecFactory *pFactory, Decoder *pDecoder, Encoder *pEncoder);
private:
	inline Codec(const Codec &codec) {}
public:
	inline const char *GetEncoding() const { return _pFactory->GetEncoding(); }
	inline CodecFactory *GetFactory() { return _pFactory; }
	inline const CodecFactory *GetFactory() const { return _pFactory; }
	inline Decoder *GetDecoder() { return _pDecoder.get(); }
	inline Encoder *GetEncoder() { return _pEncoder.get(); }
	Codec *Duplicate() const;
	static Codec *CreateCodecNone(bool delcrFlag, bool addcrFlag);
	static Codec *CreateCodec(Signal sig, const char *encoding, bool delcrFlag, bool addcrFlag);
	static void Initialize();
	static UShort DBCSToUTF16(const CodeRow codeRows[], int nCodeRows, UShort codeDBCS);
	static UShort UTF16ToDBCS(const CodeRow codeRows[], int nCodeRows, UShort codeUTF16, Map **ppMap);
	static WidthProp GetWidthProp(ULong codeUTF32);
public:
	static const char *EncodingFromLANG();
};

//-----------------------------------------------------------------------------
// CodecFactoryTmpl
//-----------------------------------------------------------------------------
template<typename T>
class CodecFactoryTmpl : public CodecFactory {
public:
	inline CodecFactoryTmpl(const char *encoding) : CodecFactory(encoding) {}
	virtual Codec *CreateCodec(bool delcrFlag, bool addcrFlag) {
		return new Codec(this, new typename T::Decoder(delcrFlag),
								new typename T::Encoder(addcrFlag));
	}
};

//-----------------------------------------------------------------------------
// Codec_None
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_None : public Codec {
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
// Codec_UTF
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_UTF : public Codec {
public:
	class GURA_DLLDECLARE Decoder : public Codec::Decoder {
	public:
		inline Decoder(bool delcrFlag) : Codec::Decoder(delcrFlag) {}
		Result FeedUTF32(ULong codeUTF32, char &chConv);
	};
	class GURA_DLLDECLARE Encoder : public Codec::Encoder {
	protected:
		int _cntChars;
		ULong _codeUTF32;
	public:
		inline Encoder(bool addcrFlag) :
				Codec::Encoder(addcrFlag), _cntChars(0), _codeUTF32(0x00000000) {}
		inline ULong GetUTF32() const { return _codeUTF32; }
		virtual Result FeedChar(char ch, char &chConv);
		virtual Result FeedUTF32(ULong codeUTF32, char &chConv) = 0;
	};
};

//-----------------------------------------------------------------------------
// Codec_SBCS
//-----------------------------------------------------------------------------
class Codec_SBCS : public Codec_UTF {
public:
	class Decoder : public Codec_UTF::Decoder {
	private:
		const UShort *_codeTbl;
	public:
		inline Decoder(bool delcrFlag, const UShort *codeTbl) :
						Codec_UTF::Decoder(delcrFlag), _codeTbl(codeTbl) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class Encoder : public Codec_UTF::Encoder {
	private:
		const UShort *_codeTbl;
		Map *&_pMap;
	public:
		inline Encoder(bool addcrFlag, const UShort *codeTbl, Map *&pMap) :
						Codec_UTF::Encoder(addcrFlag), _codeTbl(codeTbl), _pMap(pMap) {}
		virtual Result FeedUTF32(ULong codeUTF32, char &chConv);
	};
};

//-----------------------------------------------------------------------------
// Codec_DBCS
//-----------------------------------------------------------------------------
class Codec_DBCS : public Codec_UTF {
public:
	class Decoder : public Codec_UTF::Decoder {
	private:
		UShort _codeDBCS;
	public:
		inline Decoder(bool delcrFlag) :
					Codec_UTF::Decoder(delcrFlag), _codeDBCS(0x0000) {}
		virtual Result FeedChar(char ch, char &chConv);
		virtual bool IsLeadByte(UChar ch);
		virtual UShort DBCSToUTF16(UShort codeDBCS) = 0;
	};
	class Encoder : public Codec_UTF::Encoder {
	public:
		inline Encoder(bool addcrFlag) :
					Codec_UTF::Encoder(addcrFlag) {}
		virtual Result FeedUTF32(ULong codeUTF32, char &chConv);
		virtual UShort UTF16ToDBCS(UShort codeUTF16) = 0;
	};
};

}

#endif
