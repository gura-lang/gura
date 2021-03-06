//=============================================================================
// Audio
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Audio
//-----------------------------------------------------------------------------
Audio::Audio(Format format, size_t nChannels, size_t nSamplesPerSec) : _cntRef(1),
	_format(format), _nChannels(nChannels), _nSamplesPerSec(nSamplesPerSec),
	_pChainLast(nullptr)
{
}

Audio::~Audio()
{
	FreeChain();
}

void Audio::AddChain(Chain *pChain)
{
	if (_pChainLast == nullptr) {
		_pChainTop.reset(pChain);
	} else {
		_pChainLast->SetNext(pChain);
	}
	_pChainLast = pChain;
}

Audio::Chain *Audio::AllocChain(size_t nSamples)
{
	Chain *pChain = new Chain(_format, _nChannels, _nSamplesPerSec);
	pChain->SetMemory(new MemoryHeap(CalcBytes(_format, _nChannels, nSamples)));
	AddChain(pChain);
	return pChain;
}

void Audio::FreeChain()
{
	_pChainTop.reset(nullptr);
	_pChainLast = nullptr;
}

size_t Audio::GetSamples() const
{
	size_t nSamples = 0;
	for (const Chain *pChain = GetChainTop(); pChain != nullptr; pChain = pChain->GetNext()) {
		nSamples += pChain->GetSamples();
	}
	return nSamples;
}

size_t Audio::GetBytes() const
{
	size_t bytes = 0;
	for (const Chain *pChain = GetChainTop(); pChain != nullptr; pChain = pChain->GetNext()) {
		bytes += pChain->GetBytes();
	}
	return bytes;
}

bool Audio::PutData(size_t iChannel, size_t offset, int data)
{
	size_t bytes = offset * GetBytesPerSample() * GetChannels();
	for (Chain *pChain = GetChainTop();
						pChain != nullptr; pChain = pChain->GetNext()) {
		if (bytes < pChain->GetBytes()) {
			UChar *buffp = pChain->GetPointer() +
								GetBytesPerSample() * iChannel + bytes;
			PutData(_format, buffp, data);
			return true;
		}
		bytes -= pChain->GetBytes();
	}
	return false;
}

bool Audio::GetData(size_t iChannel, size_t offset, int *pData)
{
	size_t bytes = offset * GetBytesPerSample() * GetChannels();
	for (const Chain *pChain = GetChainTop();
						pChain != nullptr; pChain = pChain->GetNext()) {
		if (bytes < pChain->GetBytes()) {
			const UChar *buffp = pChain->GetPointer() +
								GetBytesPerSample() * iChannel + bytes;
			GetData(_format, buffp, pData);
			return true;
		}
		bytes -= pChain->GetBytes();
	}
	return false;
}

bool Audio::StoreData(Environment &env, size_t iChannel, size_t offset, Iterator *pIterator)
{
	Signal &sig = env.GetSignal();
	size_t bytes = offset * GetBytesPerSample() * GetChannels();
	Chain *pChain = GetChainTop();
	for ( ; pChain != nullptr; pChain = pChain->GetNext()) {
		if (bytes < pChain->GetBytes()) break;
		bytes -= pChain->GetBytes();
	}
	if (pChain == nullptr) {
		sig.SetError(ERR_IndexError, "offset is out of range");
		return false;
	}
	size_t bytesPerUnit = GetBytesPerSample() * GetChannels();
	UChar *buffp = pChain->GetPointer() + GetBytesPerSample() * iChannel + bytes;
	size_t cntRest = (pChain->GetBytes() - bytes) / GetChannels() / GetBytesPerSample();
	Value value;
	while (pIterator->Next(env, value)) {
		if (!value.Is_number()) {
			sig.SetError(ERR_ValueError, "store only number values");
			return false;
		}
		if (cntRest == 0) {
			do {
				pChain = pChain->GetNext();
				if (pChain == nullptr) {
					sig.SetError(ERR_IndexError, "no enough space to store data");
					return false;
				}
				cntRest = pChain->GetSamples();
			} while (cntRest == 0);
			buffp = pChain->GetPointer() + GetBytesPerSample() * iChannel;
		}
		PutData(_format, buffp, value.GetInt());
		buffp += bytesPerUnit;
		cntRest--;
	}
	return true;
}

bool Audio::Read(Environment &env, Stream &stream, const char *audioType)
{
	Signal &sig = env.GetSignal();
	AudioStreamer *pAudioStreamer = nullptr;
	pAudioStreamer = AudioStreamer::FindResponsible(sig, stream, audioType);
	if (sig.IsSignalled()) return false;
	if (pAudioStreamer == nullptr) {
		sig.SetError(ERR_FormatError, "unsupported audio type");
		return false;
	}
	return pAudioStreamer->Read(env, this, stream);
}

bool Audio::Write(Environment &env, Stream &stream, const char *audioType)
{
	Signal &sig = env.GetSignal();
	AudioStreamer *pAudioStreamer = nullptr;
	pAudioStreamer = AudioStreamer::FindResponsible(sig, stream, audioType);
	if (sig.IsSignalled()) return false;
	if (pAudioStreamer == nullptr) {
		sig.SetError(ERR_FormatError, "unsupported audio type");
		return false;
	}
	return pAudioStreamer->Write(env, this, stream);
}

bool Audio::AddSineWave(Signal &sig, size_t iChannel,
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
	Chain *pChain = AllocChain(nSamples);
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
	for (const Chain *pChain = GetChainTop(); pChain != nullptr;
												pChain = pChain->GetNext()) {
		pAudio->AddChain(pChain->ConvertFormat(format));
	}
	return pAudio.release();
}

Audio::Format Audio::SymbolToFormat(Signal &sig, const Symbol *pSymbol)
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
// Audio::IteratorEach
//-----------------------------------------------------------------------------
Audio::IteratorEach::IteratorEach(Audio *pAudio, size_t iChannel, size_t offset) :
		Iterator(Finite), _pAudio(pAudio), _iChannel(iChannel), _offset(offset),
		_pChain(nullptr), _buffp(nullptr), _cntRest(0), _doneFlag(false)
{
}

Iterator *Audio::IteratorEach::GetSource()
{
	return nullptr;
}

bool Audio::IteratorEach::DoNext(Environment &env, Value &value)
{
	Signal &sig = env.GetSignal();
	if (_doneFlag) return false;
	if (_pChain.IsNull()) {
		size_t bytes = _offset * _pAudio->GetBytesPerSample() * _pAudio->GetChannels();
		Chain *pChain = _pAudio->GetChainTop();
		for ( ; pChain != nullptr; pChain = pChain->GetNext()) {
			if (bytes < pChain->GetBytes()) break;
			bytes -= pChain->GetBytes();
		}
		if (pChain == nullptr) {
			sig.SetError(ERR_IndexError, "offset is out of range");
			return false;
		}
		_pChain.reset(pChain->Reference());
		_buffp = pChain->GetPointer() + _pAudio->GetBytesPerSample() * _iChannel + bytes;
		_cntRest = (pChain->GetBytes() - bytes)
					/ _pAudio->GetChannels() / _pAudio->GetBytesPerSample();
	} else if (_cntRest == 0) {
		Chain *pChain = _pChain.get();
		do {
			pChain = pChain->GetNext();
			if (pChain == nullptr) {
				_doneFlag = true;
				return false;
			}
			_cntRest = pChain->GetSamples();
		} while (_cntRest == 0);
		_pChain.reset(pChain->Reference());
		_buffp = _pChain->GetPointer() + _pAudio->GetBytesPerSample() * _iChannel;
	}
	int data = 0;
	Audio::GetData(_pAudio->GetFormat(), _buffp, &data);
	_buffp += _pAudio->GetBytesPerSample() * _pAudio->GetChannels();
	_cntRest--;
	value = Value(data);
	return true;
}

String Audio::IteratorEach::ToString() const
{
	return String("audio#each");
}

void Audio::IteratorEach::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// AudioStreamer
//-----------------------------------------------------------------------------
AudioStreamer::List *AudioStreamer::_pList = nullptr;
void AudioStreamer::Register(AudioStreamer *pAudioStreamer)
{
	if (_pList == nullptr) _pList = new List();
	_pList->push_back(pAudioStreamer);
}

AudioStreamer *AudioStreamer::FindResponsible(Signal &sig, Stream &stream, const char *audioType)
{
	if (_pList == nullptr) return nullptr;
	if (audioType != nullptr) return FindByAudioType(audioType);
	foreach (List, ppAudioStreamer, *_pList) {
		AudioStreamer *pAudioStreamer = *ppAudioStreamer;
		if (pAudioStreamer->IsResponsible(sig, stream)) return pAudioStreamer;
		if (sig.IsSignalled()) break;
	}
	return nullptr;
}

AudioStreamer *AudioStreamer::FindByAudioType(const char *audioType)
{
	if (_pList == nullptr) return nullptr;
	foreach (List, ppAudioStreamer, *_pList) {
		AudioStreamer *pAudioStreamer = *ppAudioStreamer;
		if (::strcasecmp(pAudioStreamer->GetAudioType(), audioType) == 0) {
			return pAudioStreamer;
		}
	}
	return nullptr;
}

}
