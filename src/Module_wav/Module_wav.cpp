//-----------------------------------------------------------------------------
// Gura wav module
//-----------------------------------------------------------------------------
#include "Module_wav.h"

Gura_BeginModule(wav)

//-----------------------------------------------------------------------------
// Gura interfaces for Object_audio
// These methods are available after importing wav module.
//-----------------------------------------------------------------------------
// audio#wavread(stream:stream:r):reduce
Gura_DeclareMethod(audio, wavread)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), "Reads WAV audio from a stream.");
}

Gura_ImplementMethod(audio, wavread)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	if (!AudioStreamer_WAV::ReadStream(sig, pThis->GetAudio(), args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// audio#wavwrite(stream:stream:w):reduce
Gura_DeclareMethod(audio, wavwrite)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(Gura_Symbol(en), "Writes WAV audio to a stream.");
}

Gura_ImplementMethod(audio, wavwrite)
{
	Object_audio *pThis = Object_audio::GetThisObj(args);
	if (!AudioStreamer_WAV::WriteStream(sig, pThis->GetAudio(), args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: wav
//-----------------------------------------------------------------------------
// mav.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
}

Gura_ImplementFunction(test)
{
	std::auto_ptr<Wave> pWave(new Wave());
	pWave->Read(env, sig, args.GetStream(0));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	Gura_AssignMethodTo(VTYPE_audio, audio, wavread);
	Gura_AssignMethodTo(VTYPE_audio, audio, wavwrite);
	AudioStreamer::Register(new AudioStreamer_WAV());
	// function assignment
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// AudioStreamer_WAV
//-----------------------------------------------------------------------------
bool AudioStreamer_WAV::IsResponsible(Signal sig, Stream &stream)
{
	if (stream.IsReadable()) {
	}
	return stream.HasNameSuffix(".wav");
}

bool AudioStreamer_WAV::Read(Environment &env, Signal sig,
									Audio *pAudio, Stream &stream)
{
	return AudioStreamer_WAV::ReadStream(sig, pAudio, stream);
}

bool AudioStreamer_WAV::Write(Environment &env, Signal sig,
									Audio *pAudio, Stream &stream)
{
	return AudioStreamer_WAV::WriteStream(sig, pAudio, stream);
}

bool AudioStreamer_WAV::ReadStream(Signal sig, Audio *pAudio, Stream &stream)
{
	
	return false;
}

bool AudioStreamer_WAV::WriteStream(Signal sig, Audio *pAudio, Stream &stream)
{
	return false;
}

void AudioStreamer_WAV::SetError_InvalidWAVFormat(Signal sig)
{
	sig.SetError(ERR_FormatError, "invalid WAV format");
}

Gura_EndModule(wav, wav)

Gura_RegisterModule(wav)
