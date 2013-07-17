// Audio

#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Audio
//-----------------------------------------------------------------------------
Audio::Audio(Format format, size_t nChannels) : _cntRef(1),
	_format(format), _nChannels(nChannels), _nSamples(0), _nSamplesPerSec(0),
	_buff(NULL)
{
}

Audio::~Audio()
{
	FreeBuffer();
}

bool Audio::AllocBuffer(Signal sig, size_t nSamples)
{
	FreeBuffer();
	_pMemory.reset(new MemoryHeap(_nChannels * nSamples * GetBytesPerSample()));
	_buff = reinterpret_cast<UChar *>(_pMemory->GetPointer());
	_nSamples = nSamples;
	return true;
}

void Audio::FreeBuffer()
{
	_pMemory.reset(NULL);
	_buff = NULL;
	_nSamples = 0;
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

bool Audio::SetSineWave(Signal sig, size_t iChannel,
		size_t pitch, int phase, int amplitude, size_t offset, size_t nSamples)
{
	const double PI2 = Math_PI * 2;
	int amplitudeMax =
		(_format == FORMAT_U8 || _format == FORMAT_S8)? 0x7f :
		(_format == FORMAT_U16LE || _format == FORMAT_S16LE ||
		 _format == FORMAT_U16BE || _format == FORMAT_S16BE)? 0x7fff : 0;
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
	if (nSamples > _nSamples) nSamples = _nSamples;
	if (offset >= _nSamples) return true;
	if (offset + nSamples > _nSamples) nSamples = _nSamples - offset;
	UChar *buffp = _buff + (offset * _nChannels + iChannel) * GetBytesPerSample();
	size_t bytesPerUnit = GetBytesPerSample() * _nChannels;
	for (size_t i = 0; i < nSamples; i++) {
		int data = static_cast<int>(::sin(PI2 * (i + phase) / pitch) * amplitude);
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
