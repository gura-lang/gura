#include "SoundFont.h"

Gura_BeginModule(midi)

#define FOURCC(c1, c2, c3, c4) \
	(static_cast<unsigned long>(c1) << 0) + (static_cast<unsigned long>(c2) << 8) + \
	(static_cast<unsigned long>(c3) << 16) + (static_cast<unsigned long>(c4) << 24)

const unsigned long CKID_RIFF = FOURCC('R', 'I', 'F', 'F');
const unsigned long CKID_LIST = FOURCC('L', 'I', 'S', 'T');
const unsigned long CKID_ifil = FOURCC('i', 'f', 'i', 'l');
const unsigned long CKID_isng = FOURCC('i', 's', 'n', 'g');
const unsigned long CKID_INAM = FOURCC('I', 'N', 'A', 'M');
const unsigned long CKID_irom = FOURCC('i', 'r', 'o', 'm');
const unsigned long CKID_iver = FOURCC('i', 'v', 'e', 'r');
const unsigned long CKID_ICRD = FOURCC('I', 'C', 'R', 'D');
const unsigned long CKID_IENG = FOURCC('I', 'E', 'N', 'G');
const unsigned long CKID_IPRD = FOURCC('I', 'P', 'R', 'D');
const unsigned long CKID_ICOP = FOURCC('I', 'C', 'O', 'P');
const unsigned long CKID_ICMT = FOURCC('I', 'C', 'M', 'T');
const unsigned long CKID_ISFT = FOURCC('I', 'S', 'F', 'T');
const unsigned long CKID_smpl = FOURCC('s', 'm', 'p', 'l');
const unsigned long CKID_phdr = FOURCC('p', 'h', 'd', 'r');
const unsigned long CKID_pbag = FOURCC('p', 'b', 'a', 'g');
const unsigned long CKID_pmod = FOURCC('p', 'm', 'o', 'd');
const unsigned long CKID_pgen = FOURCC('p', 'g', 'e', 'n');
const unsigned long CKID_inst = FOURCC('i', 'n', 's', 't');
const unsigned long CKID_ibag = FOURCC('i', 'b', 'a', 'g');
const unsigned long CKID_imod = FOURCC('i', 'm', 'o', 'd');
const unsigned long CKID_igen = FOURCC('i', 'g', 'e', 'n');
const unsigned long CKID_shdr = FOURCC('s', 'h', 'd', 'r');

struct ChunkHdr {
public:
	enum { Size = 8 };
	Gura_PackedULong_LE(ckID);
	Gura_PackedULong_LE(ckSize);
public:
	void Print() const;
};

struct iver_rec {
	enum { Size = 4 };
	Gura_PackedUShort_LE(wMajor);
	Gura_PackedUShort_LE(wMinor);
};

struct phdr_rec {
	enum { Size = 38 };
	char achPresetName[20];
	Gura_PackedUShort_LE(wPreset);
	Gura_PackedUShort_LE(wBank);
	Gura_PackedUShort_LE(wPresetBagNdx);
	Gura_PackedULong_LE(dwLibrary);
	Gura_PackedULong_LE(dwGenre);
	Gura_PackedULong_LE(dwMorphology);
};

struct pbag_rec {
	enum { Size = 4 };
	Gura_PackedUShort_LE(wGenNdx);
	Gura_PackedUShort_LE(wModNdx);
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
		switch (ckID) {
		case CKID_LIST: {
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
			break;
		}
		case CKID_ifil: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_isng: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_INAM: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_irom: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_iver: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_ICRD: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_IENG: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_IPRD: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_ICOP: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_ICMT: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_ISFT: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_smpl: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_phdr: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_pbag: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_pmod: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_pgen: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_inst: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_ibag: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_imod: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_igen: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		case CKID_shdr: {
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		default: {
			::printf("****\n");
			chunkHdr.Print();
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		}
		if (ckID == CKID_LIST) {
		} else {
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
