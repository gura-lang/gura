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
class CodecDecoder_ISO8859 : public CodecDecoder_UTF {
private:
	const unsigned short *_codeTbl;
public:
	inline CodecDecoder_ISO8859(bool delcrFlag, const unsigned short *codeTbl) :
					CodecDecoder_UTF(delcrFlag), _codeTbl(codeTbl) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// CodecEncoder_ISO8859
//-----------------------------------------------------------------------------
class CodecEncoder_ISO8859 : public CodecEncoder_UTF {
private:
	const unsigned short *_codeTbl;
	Map *&_pMap;
public:
	inline CodecEncoder_ISO8859(bool addcrFlag, const unsigned short *codeTbl, Map *&pMap) :
					CodecEncoder_UTF(addcrFlag), _codeTbl(codeTbl), _pMap(pMap) {}
	virtual Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

//-----------------------------------------------------------------------------
// ISO8859-1
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_1 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_1(bool delcrFlag);
};

class CodecEncoder_ISO8859_1 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_1(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-2
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_2 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_2(bool delcrFlag);
};

class CodecEncoder_ISO8859_2 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_2(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-3
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_3 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_3(bool delcrFlag);
};

class CodecEncoder_ISO8859_3 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_3(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-4
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_4 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_4(bool delcrFlag);
};

class CodecEncoder_ISO8859_4 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_4(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-5
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_5 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_5(bool delcrFlag);
};

class CodecEncoder_ISO8859_5 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_5(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-6
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_6 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_6(bool delcrFlag);
};

class CodecEncoder_ISO8859_6 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_6(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-7
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_7 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_7(bool delcrFlag);
};

class CodecEncoder_ISO8859_7 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_7(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-8
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_8 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_8(bool delcrFlag);
};

class CodecEncoder_ISO8859_8 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_8(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-9
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_9 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_9(bool delcrFlag);
};

class CodecEncoder_ISO8859_9 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_9(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-10
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_10 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_10(bool delcrFlag);
};

class CodecEncoder_ISO8859_10 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_10(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-11
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_11 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_11(bool delcrFlag);
};

class CodecEncoder_ISO8859_11 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_11(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-13
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_13 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_13(bool delcrFlag);
};

class CodecEncoder_ISO8859_13 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_13(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-14
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_14 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_14(bool delcrFlag);
};

class CodecEncoder_ISO8859_14 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_14(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-15
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_15 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_15(bool delcrFlag);
};

class CodecEncoder_ISO8859_15 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_15(bool addcrFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-16
//-----------------------------------------------------------------------------
class CodecDecoder_ISO8859_16 : public CodecDecoder_ISO8859 {
public:
	CodecDecoder_ISO8859_16(bool delcrFlag);
};

class CodecEncoder_ISO8859_16 : public CodecEncoder_ISO8859 {
public:
	CodecEncoder_ISO8859_16(bool addcrFlag);
};

}}

#endif
