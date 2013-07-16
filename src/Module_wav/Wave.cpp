#include "Wave.h"

Gura_BeginModule(wav)

//-----------------------------------------------------------------------------
// Wave
//-----------------------------------------------------------------------------
Wave::Wave()
{
}

void Wave::Clear()
{
}

bool Wave::Read(Environment &env, Signal sig, Stream &stream)
{
	ChunkHdr chunkHdr;
	size_t bytesRead = stream.Read(sig, &chunkHdr, ChunkHdr::Size);
	if (bytesRead != ChunkHdr::Size) {
		sig.SetError(ERR_FormatError, "invalid WAVE format");
		return false;
	}
	unsigned long ckID = Gura_UnpackULong(chunkHdr.ckID);
	unsigned long ckSize = Gura_UnpackULong(chunkHdr.ckSize);
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
	if (!ReadSubChunk(env, sig, stream, static_cast<size_t>(ckSize))) return false;
	return true;
}

void Wave::Print() const
{
}

bool Wave::ReadSubChunk(Environment &env, Signal sig, Stream &stream, size_t bytes)
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
		unsigned long ckID = Gura_UnpackULong(chunkHdr.ckID);
		unsigned long ckSize = Gura_UnpackULong(chunkHdr.ckSize);
		unsigned long ckSizeAlign = (ckSize + 1) / 2 * 2;
		switch (ckID) {
		case CKID_fmt:
			WAVEFORMAT::RawData rawData;
			if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSize)) return false;
			break;
		case CKID_data:
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		default: {
			::printf("****\n");
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		}
		bytesRest -= ckSizeAlign;
	}
	return true;
}

bool Wave::ReadStruct(Environment &env, Signal sig, Stream &stream,
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

bool Wave::ReadString(Environment &env, Signal sig, Stream &stream,
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

}}
