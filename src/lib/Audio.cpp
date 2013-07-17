// Audio

#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Audio
//-----------------------------------------------------------------------------
Audio::Audio(Format format, size_t nChannels, size_t nSamplesPerSec) : _cntRef(1),
	_format(format), _nChannels(nChannels), _nSamplesPerSec(nSamplesPerSec),
	_pBufferLast(NULL)
{
}

Audio::~Audio()
{
	FreeBuffer();
}

UChar *Audio::AllocBuffer(Signal sig, size_t nSamples)
{
	Buffer *pBuffer = new Buffer(_format, _nChannels, _nSamplesPerSec);
	pBuffer->SetMemory(new MemoryHeap(CalcBytes(_format, _nChannels, nSamples)));
	UChar *buff = pBuffer->GetPointer();
	if (_pBufferLast == NULL) {
		_pBuffer.reset(pBuffer);
	} else {
		_pBufferLast->SetNext(pBuffer);
	}
	_pBufferLast = pBuffer;
	return buff;
}

void Audio::FreeBuffer()
{
	_pBuffer.reset(NULL);
	_pBufferLast = NULL;
}

size_t Audio::GetSamples() const
{
	size_t nSamples = 0;
	for (Buffer *pBuffer = _pBuffer.get(); pBuffer != NULL; pBuffer = pBuffer->GetNext()) {
		nSamples += pBuffer->GetSamples();
	}
	return nSamples;
}

size_t Audio::GetBytes() const
{
	size_t bytes = 0;
	for (Buffer *pBuffer = _pBuffer.get(); pBuffer != NULL; pBuffer = pBuffer->GetNext()) {
		bytes += pBuffer->GetBytes();
	}
	return bytes;
}

bool Audio::Read(Environment &env, Signal sig, Stream &stream, const char *audioType)
{
	AudioStreamer *pAudioStreamer = NULL;
	pAudioStreamer = AudioStreamer::FindResponsible(sig, stream, audioType);
	if (sig.IsSignalled()) return false;
	if (pAudioStreamer == NULL) {
		sig.SetError(ERR_FormatError, "unsupported audio type");
		return false;
	}
	return pAudioStreamer->Read(env, sig, this, stream);
}

bool Audio::Write(Environment &env, Signal sig, Stream &stream, const char *audioType)
{
	AudioStreamer *pAudioStreamer = NULL;
	pAudioStreamer = AudioStreamer::FindResponsible(sig, stream, audioType);
	if (sig.IsSignalled()) return false;
	if (pAudioStreamer == NULL) {
		sig.SetError(ERR_FormatError, "unsupported audio type");
		return false;
	}
	return pAudioStreamer->Write(env, sig, this, stream);
}

bool Audio::AddSineWave(Signal sig, size_t iChannel,
							size_t pitch, size_t nSamples, int amplitude)
{
	const double PI2 = Math_PI * 2;
	int amplitudeMax = GetAmplitudeMax(_format);
	if (iChannel >= _nChannels) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return false;
	}
	if (amplitude < 0) {
		amplitude = amplitudeMax;
	} else if (amplitude > amplitudeMax) {
		sig.SetError(ERR_ValueError, "amplitude is out of range");
		return false;
	}
	UChar *buff = AllocBuffer(sig, nSamples);
	UChar *buffp = buff;
	size_t bytesPerUnit = GetBytesPerSample() * _nChannels;
	for (size_t i = 0; i < nSamples; i++) {
		int data = static_cast<int>(::sin(PI2 * i / pitch) * amplitude);
		StoreData(buffp, data);
		buffp += bytesPerUnit;
	}
	return true;
}

Audio::Format Audio::SymbolToFormat(Signal sig, const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_Symbol(u8))) {
		return FORMAT_U8;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s8))) {
		return FORMAT_S8;
	} else if (pSymbol->IsIdentical(Gura_Symbol(u16le))) {
		return FORMAT_U16LE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s16le))) {
		return FORMAT_S16LE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(u16be))) {
		return FORMAT_U16BE;
	} else if (pSymbol->IsIdentical(Gura_Symbol(s16be))) {
		return FORMAT_S16BE;
	} else {
		sig.SetError(ERR_ValueError, "unsupported audio format '%s'", pSymbol->GetName());
		return FORMAT_None;
	}
}

const Symbol *Audio::FormatToSymbol(Format format)
{
	if (format == FORMAT_U8) {
		return Gura_Symbol(u8);
	} else if (format == FORMAT_S8) {
		return Gura_Symbol(s8);
	} else if (format == FORMAT_U16LE) {
		return Gura_Symbol(u16le);
	} else if (format == FORMAT_S16LE) {
		return Gura_Symbol(s16le);
	} else if (format == FORMAT_U16BE) {
		return Gura_Symbol(u16be);
	} else if (format == FORMAT_S16BE) {
		return Gura_Symbol(s16be);
	} else {
		return Gura_Symbol(nil);
	}
}

//-----------------------------------------------------------------------------
// Audio::Buffer
//-----------------------------------------------------------------------------
Audio::Buffer::Buffer(Format format, size_t nChannels, size_t nSamplesPerSec) : _cntRef(1),
		_format(format), _nChannels(nChannels), _nSamplesPerSec(nSamplesPerSec)
{
}

//-----------------------------------------------------------------------------
// AudioStreamer
//-----------------------------------------------------------------------------
AudioStreamer::List *AudioStreamer::_pList = NULL;
void AudioStreamer::Register(AudioStreamer *pAudioStreamer)
{
	if (_pList == NULL) _pList = new List();
	_pList->push_back(pAudioStreamer);
}

AudioStreamer *AudioStreamer::FindResponsible(Signal sig, Stream &stream, const char *audioType)
{
	if (_pList == NULL) return NULL;
	if (audioType != NULL) return FindByAudioType(audioType);
	foreach (List, ppAudioStreamer, *_pList) {
		AudioStreamer *pAudioStreamer = *ppAudioStreamer;
		if (pAudioStreamer->IsResponsible(sig, stream)) return pAudioStreamer;
		if (sig.IsSignalled()) break;
	}
	return NULL;
}

AudioStreamer *AudioStreamer::FindByAudioType(const char *audioType)
{
	if (_pList == NULL) return NULL;
	foreach (List, ppAudioStreamer, *_pList) {
		AudioStreamer *pAudioStreamer = *ppAudioStreamer;
		if (::strcasecmp(pAudioStreamer->GetAudioType(), audioType) == 0) {
			return pAudioStreamer;
		}
	}
	return NULL;
}

}
