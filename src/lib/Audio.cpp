// Audio

#include "stdafx.h"

namespace Gura {
//-----------------------------------------------------------------------------
// Audio
//-----------------------------------------------------------------------------
Audio::Audio(Format format, size_t nChannels, size_t nSamplesPerSec) : _cntRef(1),
	_format(format), _nChannels(nChannels), _nSamplesPerSec(nSamplesPerSec),
	_pChainLast(NULL)
{
}

Audio::~Audio()
{
	FreeChain();
}

void Audio::AddChain(Chain *pChain)
{
	if (_pChainLast == NULL) {
		_pChainTop.reset(pChain);
	} else {
		_pChainLast->SetNext(pChain);
	}
	_pChainLast = pChain;
}

Audio::Chain *Audio::AllocChain(Signal sig, size_t nSamples)
{
	Chain *pChain = new Chain(_format, _nChannels, _nSamplesPerSec);
	pChain->SetMemory(new MemoryHeap(CalcBytes(_format, _nChannels, nSamples)));
	AddChain(pChain);
	return pChain;
}

void Audio::FreeChain()
{
	_pChainTop.reset(NULL);
	_pChainLast = NULL;
}

size_t Audio::GetSamples() const
{
	size_t nSamples = 0;
	for (const Chain *pChain = GetChainTop(); pChain != NULL; pChain = pChain->GetNext()) {
		nSamples += pChain->GetSamples();
	}
	return nSamples;
}

size_t Audio::GetBytes() const
{
	size_t bytes = 0;
	for (const Chain *pChain = GetChainTop(); pChain != NULL; pChain = pChain->GetNext()) {
		bytes += pChain->GetBytes();
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
							double freq, size_t nSamples, int amplitude)
{
	if (iChannel >= _nChannels) {
		sig.SetError(ERR_ValueError, "channel is out of range");
		return false;
	}
	int amplitudeMax = GetAmplitudeMax(_format);
	if (amplitude < 0) {
		amplitude = amplitudeMax;
	} else if (amplitude > amplitudeMax) {
		sig.SetError(ERR_ValueError, "amplitude is out of range");
		return false;
	}
	Chain *pChain = AllocChain(sig, nSamples);
	UChar *buffp = pChain->GetPointer();
	size_t bytesPerUnit = GetBytesPerSample() * GetChannels();
	double coef = Math_PI * 2 * freq;
	for (size_t i = 0; i < nSamples; i++) {
		int data = static_cast<int>(::sin(coef * i / GetSamplesPerSec()) * amplitude);
		PutData(_format, buffp, data);
		buffp += bytesPerUnit;
	}
	return true;
}

Audio *Audio::ConvertFormat(Format format) const
{
	AutoPtr<Audio> pAudio(new Audio(format, _nChannels, _nSamplesPerSec));
	for (const Chain *pChain = GetChainTop(); pChain != NULL;
												pChain = pChain->GetNext()) {
		pAudio->AddChain(pChain->ConvertFormat(format));
	}
	return pAudio.release();
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
// Audio::Chain
//-----------------------------------------------------------------------------
Audio::Chain::Chain(Format format, size_t nChannels, size_t nSamplesPerSec) : _cntRef(1),
		_format(format), _nChannels(nChannels), _nSamplesPerSec(nSamplesPerSec)
{
}

void Audio::Chain::FillMute()
{
	if (_format == FORMAT_U8) {
		::memset(_pMemory->GetPointer(), 0x80, _pMemory->GetSize());
	} else if (_format == FORMAT_S8) {
		::memset(_pMemory->GetPointer(), 0x00, _pMemory->GetSize());
	} else if (_format == FORMAT_U16LE) {
		::memset(_pMemory->GetPointer(), 0x00, _pMemory->GetSize());
		UChar *p = reinterpret_cast<UChar *>(_pMemory->GetPointer()) + 1;
		for (size_t cnt = _pMemory->GetSize() / 2; cnt > 0; cnt--, p += 2) *p = 0x80;
	} else if (_format == FORMAT_S16LE) {
		::memset(_pMemory->GetPointer(), 0x00, _pMemory->GetSize());
	} else if (_format == FORMAT_U16BE) {
		::memset(_pMemory->GetPointer(), 0x00, _pMemory->GetSize());
		UChar *p = reinterpret_cast<UChar *>(_pMemory->GetPointer());
		for (size_t cnt = _pMemory->GetSize() / 2; cnt > 0; cnt--, p += 2) *p = 0x80;
	} else if (_format == FORMAT_S16BE) {
		::memset(_pMemory->GetPointer(), 0x00, _pMemory->GetSize());
	} else {
		// nothing to do
	}
}

Audio::Chain *Audio::Chain::ConvertFormat(Format format) const
{
	AutoPtr<Chain> pChain(new Chain(format, GetChannels(), GetSamplesPerSec()));
	pChain->SetMemory(new MemoryHeap(CalcBytes(format, GetChannels(), GetSamples())));
	const UChar *buffpSrc = GetPointer();
	UChar *buffpDst = pChain->GetPointer();
	int data = 0;
	for (size_t cnt = GetSamples() * GetChannels(); cnt > 0; cnt--) {
		buffpSrc = GetData(_format, buffpSrc, &data);
		buffpDst = PutData(format, buffpDst, data);
	}
	return pChain.release();
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
