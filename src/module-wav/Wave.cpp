#include "Wave.h"

Gura_BeginModuleScope(wav)

//-----------------------------------------------------------------------------
// Wave
//-----------------------------------------------------------------------------
Wave::Wave()
{
}

void Wave::Clear()
{
}

bool Wave::SetAudio(Signal &sig, const Audio *pAudio)
{
	UInt16 wFormatTag = FORMAT_PCM;
	UInt16 nChannels = pAudio->GetChannels();
	UInt32 nSamplesPerSec = pAudio->GetSamplesPerSec();
	UInt32 nAvgBytesPerSec = 0;
	UInt16 nBlockAlign = 4;
	UInt16 wBitsPerSample = 0;
	switch (pAudio->GetFormat()) {
	case Audio::FORMAT_U8:
		_pAudio.reset(pAudio->ConvertFormat(Audio::FORMAT_S8));
		nAvgBytesPerSec = nSamplesPerSec * nChannels;
		wBitsPerSample = 8;
		break;
	case Audio::FORMAT_S8:
		_pAudio.reset(pAudio->Reference());
		nAvgBytesPerSec = nSamplesPerSec * nChannels;
		wBitsPerSample = 8;
		break;
	case Audio::FORMAT_U16LE:
		_pAudio.reset(pAudio->ConvertFormat(Audio::FORMAT_S16LE));
		nAvgBytesPerSec = nSamplesPerSec * nChannels * 2;
		wBitsPerSample = 16;
		break;
	case Audio::FORMAT_S16LE:
		_pAudio.reset(pAudio->Reference());
		nAvgBytesPerSec = nSamplesPerSec * nChannels * 2;
		wBitsPerSample = 16;
		break;
	case Audio::FORMAT_U16BE:
		_pAudio.reset(pAudio->ConvertFormat(Audio::FORMAT_S16LE));
		nAvgBytesPerSec = nSamplesPerSec * nChannels * 2;
		wBitsPerSample = 16;
		break;
	case Audio::FORMAT_S16BE:
		_pAudio.reset(pAudio->ConvertFormat(Audio::FORMAT_S16LE));
		nAvgBytesPerSec = nSamplesPerSec * nChannels * 2;
		wBitsPerSample = 16;
		break;
	}
	_pFormat.reset(new Format(wFormatTag, nChannels, nSamplesPerSec,
							nAvgBytesPerSec, nBlockAlign, wBitsPerSample));
	return true;
}

bool Wave::Read(Signal &sig, Stream &stream)
{
	ChunkHdr chunkHdr;
	size_t bytesRead = stream.Read(sig, &chunkHdr, ChunkHdr::Size);
	if (bytesRead != ChunkHdr::Size) {
		sig.SetError(ERR_FormatError, "invalid WAVE format");
		return false;
	}
	UInt32 ckID = Gura_UnpackUInt32(chunkHdr.ckID);
	UInt32 ckSize = Gura_UnpackUInt32(chunkHdr.ckSize);
	if (ckID != CKID_RIFF) {
		sig.SetError(ERR_FormatError, "can't find RIFF chunk");
		return false;
	}
	char formHdr[4];
	bytesRead = stream.Read(sig, formHdr, 4);
	if (bytesRead != 4) {
		sig.SetError(ERR_FormatError, "invalid WAVE format");
		return false;
	}
	if (::memcmp(formHdr, "WAVE", 4) != 0) {
		sig.SetError(ERR_FormatError, "invalid WAVE format");
		return false;
	}
	ckSize -= 4;
	if (!ReadSubChunk(sig, stream, static_cast<size_t>(ckSize))) return false;
	return true;
}

bool Wave::Write(Signal &sig, Stream &stream)
{
	size_t bytesData = _pAudio->GetBytes();
	size_t bytesChunk = 4;
	bytesChunk += ChunkHdr::Size + Format::RawData::Size;
	bytesChunk += ChunkHdr::Size + bytesData;
	do {
		ChunkHdr chunkHdr;
		Gura_PackUInt32(chunkHdr.ckID, CKID_RIFF);
		Gura_PackUInt32(chunkHdr.ckSize, static_cast<UInt32>(bytesChunk));
		if (stream.Write(sig, &chunkHdr, ChunkHdr::Size) != ChunkHdr::Size) return false;
		const char formHdr[] = "WAVE";
		if (stream.Write(sig, formHdr, 4) != 4) return false;
	} while (0);
	if (!_pFormat->Write(sig, stream)) return false;
	do {
		ChunkHdr chunkHdr;
		Gura_PackUInt32(chunkHdr.ckID, CKID_data);
		Gura_PackUInt32(chunkHdr.ckSize, static_cast<UInt32>(bytesData));
		if (stream.Write(sig, &chunkHdr, ChunkHdr::Size) != ChunkHdr::Size) return false;
		for (Audio::Chain *pChain = _pAudio->GetChainTop();
							pChain != nullptr; pChain = pChain->GetNext()) {
			if (stream.Write(sig, pChain->GetPointer(),
						pChain->GetBytes()) != pChain->GetBytes()) return false;
		}
	} while (0);
	return true;
}

void Wave::Print() const
{
	_pFormat->Print();
}

bool Wave::ReadSubChunk(Signal &sig, Stream &stream, size_t bytes)
{
	size_t bytesRest = (bytes + 1) / 2 * 2;
	while (bytesRest > 0) {
		ChunkHdr chunkHdr;
		//::printf("bytesRest = %d\n", bytesRest);
		size_t bytesRead = stream.Read(sig, &chunkHdr,
						ChooseMin(bytesRest, static_cast<size_t>(ChunkHdr::Size)));
		if (bytesRead != ChunkHdr::Size) {
			sig.SetError(ERR_FormatError, "invalid WAVE format");
			return false;
		}
		bytesRest -= bytesRead;
		UInt32 ckID = Gura_UnpackUInt32(chunkHdr.ckID);
		UInt32 ckSize = Gura_UnpackUInt32(chunkHdr.ckSize);
		UInt32 ckSizeAlign = (ckSize + 1) / 2 * 2;
		switch (ckID) {
		case CKID_fmt: {
			Format::RawData rawData;
			if (!ReadStruct(sig, stream, &rawData, Format::RawData::Size, ckSize)) return false;
			_pFormat.reset(new Format(rawData));
			break;
		}
		case CKID_data: {
			if (_pFormat.IsNull()) {
				sig.SetError(ERR_FormatError, "fmt chunk doesn't exist");
				return false;
			}
			_pAudio.reset(_pFormat->ReadAudio(sig, stream, ckSize));
			if (_pAudio.get() == nullptr) return false;
			break;
		}
		default: {
			::printf("****\n");
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		}
		bytesRest -= ckSizeAlign;
	}
	if (_pAudio.IsNull()) {
		sig.SetError(ERR_FormatError, "data chunk doesn't exist");
		return false;
	}
	return true;
}

bool Wave::ReadStruct(Signal &sig, Stream &stream,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual)
{
	if (ckSizeExpect > ckSizeActual) {
		sig.SetError(ERR_FormatError, "unexpected size of chunk");
		return false;
	}
	size_t bytesRead = stream.Read(sig, rawData, ckSizeExpect);
	if (bytesRead != ckSizeExpect) {
		sig.SetError(ERR_FormatError, "invalid WAVE format");
		return false;
	}
	return true;
}

bool Wave::ReadString(Signal &sig, Stream &stream,
						char *str, size_t ckSizeMax, size_t ckSizeActual)
{
	size_t ckSizeAlign = (ckSizeActual + 1) / 2 * 2;
	if (ckSizeMax < ckSizeAlign) {
		sig.SetError(ERR_FormatError, "string data is too long");
		return false;
	}
	size_t bytesRead = stream.Read(sig, str, ckSizeAlign);
	if (bytesRead != ckSizeAlign) {
		sig.SetError(ERR_FormatError, "invalid WAVE format");
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Wave
//-----------------------------------------------------------------------------
Wave::Format::Format() : _cntRef(1),
		_wFormatTag(0),
		_nChannels(0),
		_nSamplesPerSec(0),
		_nAvgBytesPerSec(0),
		_nBlockAlign(0),
		_wBitsPerSample(0)
{
}

Wave::Format::Format(const RawData &rawData) : _cntRef(1),
		_wFormatTag(Gura_UnpackUInt16(rawData.wFormatTag)),
		_nChannels(Gura_UnpackUInt16(rawData.nChannels)),
		_nSamplesPerSec(Gura_UnpackUInt32(rawData.nSamplesPerSec)),
		_nAvgBytesPerSec(Gura_UnpackUInt32(rawData.nAvgBytesPerSec)),
		_nBlockAlign(Gura_UnpackUInt16(rawData.nBlockAlign)),
		_wBitsPerSample(Gura_UnpackUInt16(rawData.wBitsPerSample))
{
}

Wave::Format::Format(UInt16 wFormatTag, UInt16 nChannels, UInt32 nSamplesPerSec,
		UInt32 nAvgBytesPerSec, UInt16 nBlockAlign, UInt16 wBitsPerSample) : _cntRef(1),
		_wFormatTag(wFormatTag),
		_nChannels(nChannels),
		_nSamplesPerSec(nSamplesPerSec),
		_nAvgBytesPerSec(nAvgBytesPerSec),
		_nBlockAlign(nBlockAlign),
		_wBitsPerSample(wBitsPerSample)
{
}

void Wave::Format::Print() const
{
	::printf("wFormatTag=%d nChannels=%d nSamplesPerSec=%d nAvgBytesPerSec=%d nBlockAlign=%d wBitsPerSample=%d\n",
		_wFormatTag,
		_nChannels,
		_nSamplesPerSec,
		_nAvgBytesPerSec,
		_nBlockAlign,
		_wBitsPerSample);
}

bool Wave::Format::Write(Signal &sig, Stream &stream) const
{
	ChunkHdr chunkHdr;
	RawData rawData;
	Gura_PackUInt32(chunkHdr.ckID, CKID_fmt);
	Gura_PackUInt32(chunkHdr.ckSize, RawData::Size);
	if (stream.Write(sig, &chunkHdr, ChunkHdr::Size) != ChunkHdr::Size) return false;
	Gura_PackUInt16(rawData.wFormatTag, _wFormatTag);
	Gura_PackUInt16(rawData.nChannels, _nChannels);
	Gura_PackUInt32(rawData.nSamplesPerSec, _nSamplesPerSec);
	Gura_PackUInt32(rawData.nAvgBytesPerSec, _nAvgBytesPerSec);
	Gura_PackUInt16(rawData.nBlockAlign, _nBlockAlign);
	Gura_PackUInt16(rawData.wBitsPerSample, _wBitsPerSample);
	return stream.Write(sig, &rawData, RawData::Size) == RawData::Size;
}

Audio *Wave::Format::ReadAudio(Signal &sig, Stream &stream, size_t ckSize) const
{
	if (_nChannels != 1 && _nChannels != 2) {
		sig.SetError(ERR_FormatError, "nChannels must be one or two");
		return nullptr;
	}
	Audio::Format format = Audio::FORMAT_None;
	size_t nSamples = 0;
	size_t bytesToRead = ckSize;
	if (_wBitsPerSample == 8) {
		format = Audio::FORMAT_S8;
		nSamples = ckSize / _nChannels;
		bytesToRead = nSamples * _nChannels;
	} else if (_wBitsPerSample == 16) {
		format = Audio::FORMAT_S16LE;
		nSamples = ckSize / _nChannels / 2;
		bytesToRead = nSamples * _nChannels * 2;
	} else {
		sig.SetError(ERR_FormatError, "wBitsPerSample must be 8 or 16");
		return nullptr;
	}
	AutoPtr<Audio> pAudio(new Audio(format, _nChannels, _nSamplesPerSec));
	Audio::Chain *pChain = pAudio->AllocChain(nSamples);
	if (pChain == nullptr) return nullptr;
	if (stream.Read(sig, pChain->GetPointer(), bytesToRead) == 0) return nullptr;
	if (bytesToRead < ckSize) {
		if (!stream.Seek(sig, ckSize - bytesToRead, Stream::SeekCur)) return nullptr;
	}
	return pAudio.release();
}

Gura_EndModuleScope(wav)
