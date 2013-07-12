#include "SoundFont.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// SoundFont
//-----------------------------------------------------------------------------
bool SoundFont::Read(Environment &env, Signal sig, Stream &stream)
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

bool SoundFont::ReadSubChunk(Environment &env, Signal sig, Stream &stream, size_t bytes)
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
			sfVersionTag::RawData rawData;
			if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSize)) return false;
			rawData.Print();
			_INFO.p_ifil.reset(new sfVersionTag(rawData));
			break;
		}
		case CKID_isng: {	// 5.2
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_isng.reset(new String(str));
			break;
		}
		case CKID_INAM: {	// 5.3
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_INAM.reset(new String(str));
			break;
		}
		case CKID_irom: {	// 5.4
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_irom.reset(new String(str));
			break;
		}
		case CKID_iver: {	// 5.5
			sfVersionTag::RawData rawData;
			if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSize)) return false;
			rawData.Print();
			_INFO.p_iver.reset(new sfVersionTag(rawData));
			break;
		}
		case CKID_ICRD: {	// 5.6
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_ICRD.reset(new String(str));
			break;
		}
		case CKID_IENG: {	// 5.7
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_IENG.reset(new String(str));
			break;
		}
		case CKID_IPRD: {	// 5.8
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_IPRD.reset(new String(str));
			break;
		}
		case CKID_ICOP: {	// 5.9
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_ICOP.reset(new String(str));
			break;
		}
		case CKID_ICMT: {	// 5.10
			char str[65536];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_ICMT.reset(new String(str));
			break;
		}
		case CKID_ISFT: {	// 5.11
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			::printf("\"%s\"\n", str);
			_INFO.p_ISFT.reset(new String(str));
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
			sfPresetHeader::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				rawData.Print();
				_pdta.phdrs.push_back(new sfPresetHeader(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pbag: {	// 7.3
			sfPresetBag::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				rawData.Print();
				_pdta.pbags.push_back(new sfPresetBag(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pmod: {	// 7.4
			sfMod::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				rawData.Print();
				_pdta.pmods.push_back(new sfMod(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pgen: {	// 7.5
			sfGen::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				rawData.Print();
				_pdta.pgens.push_back(new sfGen(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_inst: {	// 7.6
			sfInst::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				rawData.Print();
				_pdta.insts.push_back(new sfInst(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_ibag: {	// 7.7
			sfInstBag::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				rawData.Print();
				_pdta.ibags.push_back(new sfInstBag(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_imod: {	// 7.8
			sfMod::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				rawData.Print();
				_pdta.imods.push_back(new sfMod(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_igen: {	// 7.9
			sfInstGen::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				//rawData.Print();
				_pdta.igens.push_back(new sfInstGen(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_shdr: {	// 7.10
			sfSample::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				rawData.Print();
				_pdta.shdrs.push_back(new sfSample(rawData));
				ckSizeRest -= rawData.Size;
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

bool SoundFont::ReadStruct(Environment &env, Signal sig, Stream &stream,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual)
{
	if (ckSizeExpect > ckSizeActual) {
		sig.SetError(ERR_FormatError, "unexpected size of chunk");
		return false;
	}
	size_t bytesRead = stream.Read(sig, rawData, ckSizeExpect);
	if (bytesRead != ckSizeExpect) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	return true;
}

bool SoundFont::ReadString(Environment &env, Signal sig, Stream &stream,
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

}}
