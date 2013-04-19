#ifndef __GURA_OBJECT_AUDIO_H__
#define __GURA_OBJECT_AUDIO_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_audio
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_audio : public Class {
public:
	Class_audio(Environment *pEnvOuter);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_audio
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_audio : public Object {
public:
	enum Format {
		FORMAT_None,
		FORMAT_U8, FORMAT_S8,
		FORMAT_U16LE, FORMAT_S16LE, FORMAT_U16BE, FORMAT_S16BE,
	};
public:
	Gura_DeclareObjectAccessor(audio)
private:
	Format _format;
	size_t _nChannels;
	size_t _len;
	unsigned char *_buff;
	AutoPtr<OAL::Memory> _pMemory;
public:
	inline Object_audio(Environment &env, Format format, size_t nChannels) :
				Object(env.LookupClass(VTYPE_audio)), _format(format), _nChannels(nChannels),
				_len(0), _buff(NULL) {}
	inline Object_audio(Class *pClass, Format format, size_t nChannels) :
				Object(pClass), _format(format), _nChannels(nChannels),
				_len(0), _buff(NULL) {}
	virtual ~Object_audio();
	virtual Object *Clone() const;
	inline bool IsValid() const { return _buff != NULL; }
	inline Format GetFormat() const { return _format; }
	inline size_t GetChannels() const { return _nChannels; }
	inline size_t GetLength() const { return _len; }
	inline unsigned char *GetBuffer() { return _buff; }
	inline size_t GetBytesPerData() const {
		return (_format == FORMAT_U8 || _format == FORMAT_S8)? 1 : 2;
	}
	inline void StoreData(unsigned char *buffp, int data) {
		if (_format == FORMAT_U8) {
			*buffp = static_cast<unsigned char>((data + 0x80) & 0xff);
		} else if (_format == FORMAT_S8) {
			*buffp = static_cast<unsigned char>(static_cast<char>(data & 0xff));
		} else if (_format == FORMAT_U16LE) {
			unsigned short num = static_cast<unsigned short>((data + 0x8000) & 0xffff);
			*(buffp + 0) = static_cast<unsigned char>(num);
			*(buffp + 1) = static_cast<unsigned char>(num >> 8);
		} else if (_format == FORMAT_S16LE) {
			unsigned short num = static_cast<unsigned short>(static_cast<short>(data & 0xffff));
			*(buffp + 0) = static_cast<unsigned char>(num);
			*(buffp + 1) = static_cast<unsigned char>(num >> 8);
		} else if (_format == FORMAT_U16BE) {
			unsigned short num = static_cast<unsigned short>((data + 0x8000) & 0xffff);
			*(buffp + 0) = static_cast<unsigned char>(num >> 8);
			*(buffp + 1) = static_cast<unsigned char>(num);
		} else if (_format == FORMAT_S16BE) {
			unsigned short num = static_cast<unsigned short>(static_cast<short>(data & 0xffff));
			*(buffp + 0) = static_cast<unsigned char>(num >> 8);
			*(buffp + 1) = static_cast<unsigned char>(num);
		}
	}
	bool AllocBuffer(Signal sig, size_t len);
	void FreeBuffer();
	bool SetSineWave(Signal sig, size_t iChannel,
			size_t pitch, int phase, int amplitude, size_t offset, size_t len);
	static Format SymbolToFormat(Signal sig, const Symbol *pSymbol);
	static const Symbol *FormatToSymbol(Format format);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// AudioStreamer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE AudioStreamer {
public:
	typedef std::vector<AudioStreamer *> List;
private:
	const char *_audioType;
	static List *_pList;
public:
	inline AudioStreamer(const char *audioType) : _audioType(audioType) {}
	inline const char *GetAudioType() const { return _audioType; }
	virtual bool IsResponsible(Signal sig, Stream &stream) = 0;
	virtual bool Read(Environment &env, Signal sig, Object_audio *pObjAudio, Stream &stream) = 0;
	virtual bool Write(Environment &env, Signal sig, Object_audio *pObjAudio, Stream &stream) = 0;
public:
	static void Register(AudioStreamer *pAudioStreamer);
	static AudioStreamer *FindResponsible(Signal sig, Stream &stream, const char *audioType);
	static AudioStreamer *FindByAudioType(const char *audioType);
};

}

#endif
