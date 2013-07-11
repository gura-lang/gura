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

struct sfVersionTag {	// iver-rec
	enum { Size = 4 };
	Gura_PackedUShort_LE(wMajor);
	Gura_PackedUShort_LE(wMinor);
	inline void Print() const {
		::printf("wMajor=%d wMinor=%d\n",
					Gura_UnpackUShort(wMajor),
					Gura_UnpackUShort(wMinor));
	}
};

struct sfPresetHeader {	// phdr-rec
	enum { Size = 38 };
	char achPresetName[20];
	Gura_PackedUShort_LE(wPreset);
	Gura_PackedUShort_LE(wBank);
	Gura_PackedUShort_LE(wPresetBagNdx);
	Gura_PackedULong_LE(dwLibrary);
	Gura_PackedULong_LE(dwGenre);
	Gura_PackedULong_LE(dwMorphology);
	inline void Print() const {
		::printf("achPresetName=\"%s\" wPreset=%d wBank=%d wPresetBagNdx=%d dwLibrary=%d dwGenre=%d dwMorphology=%d\n",
					achPresetName,
					Gura_UnpackUShort(wPreset),
					Gura_UnpackUShort(wBank),
					Gura_UnpackUShort(wPresetBagNdx),
					Gura_UnpackULong(dwLibrary),
					Gura_UnpackULong(dwGenre),
					Gura_UnpackULong(dwMorphology));
	}
};

struct sfPresetBag {	// pbag-rec
	enum { Size = 4 };
	Gura_PackedUShort_LE(wGenNdx);
	Gura_PackedUShort_LE(wModNdx);
	inline void Print() const {
		::printf("wGenNdx=%d wModNdx=%d\n",
					Gura_UnpackUShort(wGenNdx),
					Gura_UnpackUShort(wModNdx));
	}
};

struct sfMod {			// pmod-rec
	enum { Size = 10 };
	Gura_PackedUShort_LE(sfModSrcOper);
	Gura_PackedUShort_LE(sfModDestOper);
	Gura_PackedUShort_LE(modAmount);
	Gura_PackedUShort_LE(sfModAmtSrcOper);
	Gura_PackedUShort_LE(sfModTransOper);
	inline void Print() const {
		::printf("sfModSrcOper=%d sfModDestOper=%d modAmount=0x%04x sfModAmtSrcOper=%d sfModTransOper=%d\n",
					Gura_UnpackUShort(sfModSrcOper),
					Gura_UnpackUShort(sfModDestOper),
					Gura_UnpackUShort(modAmount),
					Gura_UnpackUShort(sfModAmtSrcOper),
					Gura_UnpackUShort(sfModTransOper));
	}
};

struct sfGen {			// pgen-rec
	enum { Size = 4 };
	Gura_PackedUShort_LE(sfGenOper);
	Gura_PackedUShort_LE(genAmount);
	inline void Print() const {
		::printf("sfGenOper=%d genAmount=0x%04x\n",
					Gura_UnpackUShort(sfGenOper),
					Gura_UnpackUShort(genAmount));
	}
};

struct sfInst {			// inst-rec
	enum { Size = 22 };
	char achInstName[20];
	Gura_PackedUShort_LE(wInstBagNdx);
	inline void Print() const {
		::printf("achInstName=\"%s\" wInstBagNdx=%d\n",
					achInstName,
					Gura_UnpackUShort(wInstBagNdx));
	}
};

struct sfInstBag {		// ibag-rec
	enum { Size = 4 };
	Gura_PackedUShort_LE(wInstGenNdx);
	Gura_PackedUShort_LE(wInstModNdx);
	inline void Print() const {
		::printf("wInstGenNdx=%d wInstModNdx=%d\n",
					Gura_UnpackUShort(wInstGenNdx),
					Gura_UnpackUShort(wInstModNdx));
	}
};

struct sfInstMod {		// imod-rec
	enum { Size = 10 };
	Gura_PackedUShort_LE(sfModSrcOper);
	Gura_PackedUShort_LE(sfModDestOper);
	Gura_PackedUShort_LE(modAmount);
	Gura_PackedUShort_LE(sfModAmtSrcOper);
	Gura_PackedUShort_LE(sfModTransOper);
	inline void Print() const {
		::printf("sfModSrcOper=%d sfModDestOper=%d modAmount=0x%04x sfModAmtSrcOper=%d sfModTransOper=%d\n",
					Gura_UnpackUShort(sfModSrcOper),
					Gura_UnpackUShort(sfModDestOper),
					Gura_UnpackUShort(modAmount),
					Gura_UnpackUShort(sfModAmtSrcOper),
					Gura_UnpackUShort(sfModTransOper));
	}
};

struct sfInstGen {		// igen-rec
	enum { Size = 4 };
	Gura_PackedUShort_LE(sfGenOper);
	Gura_PackedUShort_LE(genAmount);
	inline void Print() const {
		::printf("sfGenOper=%d genAmount=0x%04x\n",
					Gura_UnpackUShort(sfGenOper),
					Gura_UnpackUShort(genAmount));
	}
};

struct sfSample {		// shdr-rec
	enum { Size = 46 };
	char achSampleName[20];
	Gura_PackedULong_LE(dwStart);
	Gura_PackedULong_LE(dwEnd);
	Gura_PackedULong_LE(dwStartloop);
	Gura_PackedULong_LE(dwEndloop);
	Gura_PackedULong_LE(dwSampleRate);
	unsigned char byOriginalKey;
	char chCorrection;
	Gura_PackedUShort_LE(wSampleLink);
	Gura_PackedUShort_LE(sfSampleType);
	inline void Print() const {
		::printf("achSampleName=\"%s\" dwStart=%d dwEnd=%d dwStartloop=%d dwEndloop=%d dwSampleRate=%d byOriginalKey=%d chCorrection=%d wSampleLink=%d sfSampleType=%d\n",
					achSampleName,
					Gura_UnpackULong(dwStart),
					Gura_UnpackULong(dwEnd),
					Gura_UnpackULong(dwStartloop),
					Gura_UnpackULong(dwEndloop),
					Gura_UnpackULong(dwSampleRate),
					byOriginalKey,
					chCorrection,
					Gura_UnpackUShort(wSampleLink),
					Gura_UnpackUShort(sfSampleType));
	}
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

bool ReadStruct(Environment &env, Signal sig, Stream &stream,
						void *data, size_t ckSizeExpect, size_t ckSizeActual)
{
	if (ckSizeExpect > ckSizeActual) {
		sig.SetError(ERR_FormatError, "unexpected size of chunk");
		return false;
	}
	size_t bytesRead = stream.Read(sig, data, ckSizeExpect);
	if (bytesRead != ckSizeExpect) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	return true;
}

bool ReadString(Environment &env, Signal sig, Stream &stream,
						char *str, size_t ckSizeMax, size_t ckSizeActual)
{
	size_t ckSizeAlign = (ckSizeActual + 1) / 2 * 2;
	if (ckSizeMax < ckSizeAlign) {
		sig.SetError(ERR_FormatError, "string data is too long");
		return false;
	}
	size_t bytesRead = stream.Read(sig, str, ckSizeAlign);
	if (bytesRead != ckSizeAlign) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	return true;
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
			sig.SetError(ERR_FormatError, "invalid SF2 format");
			return false;
		}
		bytesRest -= bytesRead;
		unsigned long ckID = Gura_UnpackULong(chunkHdr.ckID);
		unsigned long ckSize = Gura_UnpackULong(chunkHdr.ckSize);
		unsigned long ckSizeAlign = (ckSize + 1) / 2 * 2;
		if (ckID != CKID_LIST) chunkHdr.Print();
		switch (ckID) {
		case CKID_LIST: {
			char listHdr[4];
			size_t bytesRead = stream.Read(sig, listHdr,
								ChooseMin(bytesRest, static_cast<size_t>(4)));
			if (bytesRead != 4) {
				sig.SetError(ERR_FormatError, "invalid SF2 format");
				return false;
			}
			::printf("LIST('%c%c%c%c') %dbytes\n",
						listHdr[0], listHdr[1], listHdr[2], listHdr[3], ckSize);
			ckSize -= 4;
			if (!ReadSubChunk(env, sig, stream, static_cast<size_t>(ckSize))) return false;
			break;
		}
		// 5 The INFO-list Chunk
		case CKID_ifil: {	// 5.1
			sfVersionTag data;
			if (!ReadStruct(env, sig, stream, &data, data.Size, ckSize)) return false;
			data.Print();
			break;
		}
		case CKID_isng: {	// 5.2
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		case CKID_INAM: {	// 5.3
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		case CKID_irom: {	// 5.4
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		case CKID_iver: {	// 5.5
			sfVersionTag data;
			if (!ReadStruct(env, sig, stream, &data, data.Size, ckSize)) return false;
			data.Print();
			break;
		}
		case CKID_ICRD: {	// 5.6
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		case CKID_IENG: {	// 5.7
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		case CKID_IPRD: {	// 5.8
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		case CKID_ICOP: {	// 5.9
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		case CKID_ICMT: {	// 5.10
			char str[65536];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		case CKID_ISFT: {	// 5.11
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			break;
		}
		// 6 The sdta-list Chunk
		case CKID_smpl: {	// 6.1 Sample Data Format in the smpl Sub-Chunk
			// 16-bits, signed, little endian words
			stream.Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		// 7 The pdta-list Chunk
		case CKID_phdr: {	// 7.2
			sfPresetHeader data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		case CKID_pbag: {	// 7.3
			sfPresetBag data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		case CKID_pmod: {	// 7.4
			sfMod data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		case CKID_pgen: {	// 7.5
			sfGen data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		case CKID_inst: {	// 7.6
			sfInst data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		case CKID_ibag: {	// 7.7
			sfInstBag data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		case CKID_imod: {	// 7.8
			sfMod data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		case CKID_igen: {	// 7.9
			sfInstGen data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				//data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		case CKID_shdr: {	// 7.10
			sfSample data;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &data, data.Size, ckSizeRest)) return false;
				data.Print();
				ckSizeRest -= data.Size;
			}
			break;
		}
		default: {
			::printf("****\n");
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
