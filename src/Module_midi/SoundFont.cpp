#include "SoundFont.h"

Gura_BeginModule(midi)

#define FOURCC(c1, c2, c3, c4) \
	(static_cast<unsigned long>(c1) << 0) + (static_cast<unsigned long>(c2) << 8) + \
	(static_cast<unsigned long>(c3) << 16) + (static_cast<unsigned long>(c4) << 24)

unsigned long CKID_RIFF = FOURCC('R', 'I', 'F', 'F');
unsigned long CKID_LIST = FOURCC('L', 'I', 'S', 'T');

struct ChunkHdr {
public:
	enum { Size = 8 };
	Gura_PackedULong_LE(ckID);
	Gura_PackedULong_LE(ckSize);
public:
	void Print() const;
};

void ChunkHdr::Print() const
{
	unsigned long ckID = Gura_UnpackULong(ckID);
	unsigned long ckSize = Gura_UnpackULong(ckSize);
	::printf("<%c%c%c%c-ck> %dbytes\n",
			static_cast<unsigned char>(ckID >> 0),
			static_cast<unsigned char>(ckID >> 8),
			static_cast<unsigned char>(ckID >> 16),
			static_cast<unsigned char>(ckID >> 24), ckSize);
}

bool ReadSubChunk(Environment &env, Signal sig, Stream &stream, size_t bytes)
{
	size_t bytesRest = (bytes + 1) / 2 * 2;
	while (bytesRest > 0) {
		ChunkHdr chunkHdr;
		//::printf("bytesRest = %d\n", bytesRest);
		size_t bytesRead = stream.Read(sig, &chunkHdr,
						ChooseMin(bytesRest, static_cast<size_t>(ChunkHdr::Size)));
		if (bytesRead != ChunkHdr::Size) {
			sig.SetError(ERR_FormatError, "invalid SF2 format 1");
			return false;
		}
		bytesRest -= bytesRead;
		unsigned long ckID = Gura_UnpackULong(chunkHdr.ckID);
		unsigned long ckSize = Gura_UnpackULong(chunkHdr.ckSize);
		unsigned long ckSizeAlign = (ckSize + 1) / 2 * 2;
		if (ckID == CKID_LIST) {
			char listHdr[4];
			size_t bytesRead = stream.Read(sig, listHdr,
								ChooseMin(bytesRest, static_cast<size_t>(4)));
			if (bytesRead != 4) {
				sig.SetError(ERR_FormatError, "invalid SF2 format 2");
				return false;
			}
			::printf("LIST('%c%c%c%c') %dbytes\n",
						listHdr[0], listHdr[1], listHdr[2], listHdr[3], ckSize);
			ckSize -= 4;
			if (!ReadSubChunk(env, sig, stream, static_cast<size_t>(ckSize))) return false;
		} else {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
		}
		bytesRest -= ckSizeAlign;
	}
	return true;
}

bool ReadSF2(Environment &env, Signal sig, Stream &stream)
{
	ChunkHdr chunkHdr;
	size_t bytesRead = stream.Read(sig, &chunkHdr, ChunkHdr::Size);
	if (bytesRead != ChunkHdr::Size) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	unsigned long ckID = Gura_UnpackULong(chunkHdr.ckID);
	unsigned long ckSize = Gura_UnpackULong(chunkHdr.ckSize);
	if (ckID == CKID_RIFF) {
		char formHdr[4];
		size_t bytesRead = stream.Read(sig, formHdr, 4);
		if (bytesRead != 4) {
			sig.SetError(ERR_FormatError, "invalid SF2 format");
			return false;
		}
		if (::memcmp(formHdr, "sfbk", 4) != 0) {
			sig.SetError(ERR_FormatError, "invalid SF2 format");
			return false;
		}
		::printf("RIFF('%c%c%c%c') %dbytes\n",
					formHdr[0], formHdr[1], formHdr[2], formHdr[3], ckSize);
		ckSize -= 4;
		if (!ReadSubChunk(env, sig, stream, static_cast<size_t>(ckSize))) return false;
	}
	return true;
}

}}
