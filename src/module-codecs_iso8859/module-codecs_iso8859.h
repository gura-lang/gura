//-----------------------------------------------------------------------------
// Gura codecs.iso8859 module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CODECS_ISO8859_H__
#define __GURA_MODULE_CODECS_ISO8859_H__

#include <gura.h>

Gura_BeginModuleHeader(codecs_iso8859)

//-----------------------------------------------------------------------------
// Codec_ISO8859_1
//-----------------------------------------------------------------------------
class Codec_ISO8859_1 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_2
//-----------------------------------------------------------------------------
class Codec_ISO8859_2 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_3
//-----------------------------------------------------------------------------
class Codec_ISO8859_3 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_4
//-----------------------------------------------------------------------------
class Codec_ISO8859_4 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_5
//-----------------------------------------------------------------------------
class Codec_ISO8859_5 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_6
//-----------------------------------------------------------------------------
class Codec_ISO8859_6 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_7
//-----------------------------------------------------------------------------
class Codec_ISO8859_7 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_8
//-----------------------------------------------------------------------------
class Codec_ISO8859_8 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_9
//-----------------------------------------------------------------------------
class Codec_ISO8859_9 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_10
//-----------------------------------------------------------------------------
class Codec_ISO8859_10 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_11
//-----------------------------------------------------------------------------
class Codec_ISO8859_11 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_13
//-----------------------------------------------------------------------------
class Codec_ISO8859_13 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_14
//-----------------------------------------------------------------------------
class Codec_ISO8859_14 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_15
//-----------------------------------------------------------------------------
class Codec_ISO8859_15 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

//-----------------------------------------------------------------------------
// Codec_ISO8859_16
//-----------------------------------------------------------------------------
class Codec_ISO8859_16 : public Codec_SBCS {
public:
	class Decoder : public Codec_SBCS::Decoder {
	public:
		Decoder(bool delcrFlag);
	};
	class Encoder : public Codec_SBCS::Encoder {
	private:
		static Map *_pMapShared;
	public:
		Encoder(bool addcrFlag);
	};
};

Gura_EndModuleHeader(codecs_iso8859)

#endif
