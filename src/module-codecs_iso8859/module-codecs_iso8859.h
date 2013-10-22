//-----------------------------------------------------------------------------
// Gura codecs.iso8859 module
//-----------------------------------------------------------------------------
#ifndef __MODULE_CODECS_ISO8859_H__
#define __MODULE_CODECS_ISO8859_H__

#include <gura.h>

Gura_BeginModule(codecs_iso8859)

//-----------------------------------------------------------------------------
// CodecDecoder_ISO8859
//-----------------------------------------------------------------------------
class Codec_ISO8859 : public Codec_UTF {
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
// Codec_ISO8859_1
//-----------------------------------------------------------------------------
class Codec_ISO8859_1 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_2
//-----------------------------------------------------------------------------
class Codec_ISO8859_2 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_3
//-----------------------------------------------------------------------------
class Codec_ISO8859_3 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_4
//-----------------------------------------------------------------------------
class Codec_ISO8859_4 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_5
//-----------------------------------------------------------------------------
class Codec_ISO8859_5 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_6
//-----------------------------------------------------------------------------
class Codec_ISO8859_6 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_7
//-----------------------------------------------------------------------------
class Codec_ISO8859_7 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_8
//-----------------------------------------------------------------------------
class Codec_ISO8859_8 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_9
//-----------------------------------------------------------------------------
class Codec_ISO8859_9 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_10
//-----------------------------------------------------------------------------
class Codec_ISO8859_10 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_11
//-----------------------------------------------------------------------------
class Codec_ISO8859_11 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_13
//-----------------------------------------------------------------------------
class Codec_ISO8859_13 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_14
//-----------------------------------------------------------------------------
class Codec_ISO8859_14 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_15
//-----------------------------------------------------------------------------
class Codec_ISO8859_15 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_16
//-----------------------------------------------------------------------------
class Codec_ISO8859_16 : public Codec_ISO8859 {
public:
	class Decoder : public Codec_ISO8859::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_ISO8859::Encoder {
	public:
		Encoder(bool addcrFlag);
	};
};

}}

#endif
