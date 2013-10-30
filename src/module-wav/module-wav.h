//-----------------------------------------------------------------------------
// Gura wav module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_WAV_H__
#define __GURA_MODULE_WAV_H__
#include <gura.h>
#include "Wave.h"

Gura_BeginModuleHeader(wav, wav)

//-----------------------------------------------------------------------------
// AudioStreamer_WAV
//-----------------------------------------------------------------------------
class AudioStreamer_WAV : public AudioStreamer {
public:
	inline AudioStreamer_WAV() : AudioStreamer("wav") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Audio *pAudio, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Audio *pAudio, Stream &stream);
public:
	static bool ReadStream(Signal sig, Audio *pAudio, Stream &stream);
	static bool WriteStream(Signal sig, Audio *pAudio, Stream &stream);
	static void SetError_InvalidWAVFormat(Signal sig);
};

Gura_EndModuleHeader(wav, wav)

#endif
