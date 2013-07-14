#include "SoundFont.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// SoundFont
//-----------------------------------------------------------------------------
const char *SoundFont::_generatorNames[] = {
	"startAddrsOffset",				// 0
	"endAddrsOffset",				// 1
	"startloopAddrsOffset",			// 2
	"endloopAddrsOffset",			// 3
	"startAddrsCoarseOffset",		// 4
	"modLfoToPitch",				// 5
	"vibLfoToPitch",				// 6
	"modEnvToPitch",				// 7
	"initialFilterFc",				// 8
	"initiflFilterQ",				// 9
	"modLfoToFilterFc",				// 10
	"modEnvToFilterFc",				// 11
	"endAddrsCoarseOffset",			// 12
	"modLfoToVolume",				// 13
	"unnsed1",						// 14
	"chorusEffectsSend",			// 15
	"reverbEffectsSend",			// 16
	"pan",							// 17
	"unused2",						// 18
	"unused3",						// 19
	"unused4",						// 20
	"delayModLFO",					// 21
	"freqModLFO",					// 22
	"delayVibLFO",					// 23
	"freqVibLFO",					// 24
	"delayModEnv",					// 25
	"attackModEnv",					// 26
	"holdModEnv",					// 27
	"delayModENv",					// 28
	"sustainModEnv",				// 29
	"releaseModEnv",				// 30
	"keynumToModEnvHold",			// 31
	"keynumToModEnvDecay",			// 32
	"delayVolEnv",					// 33
	"attackVolEnv",					// 34
	"holdVolEnv",					// 35
	"decayVolENv",					// 36
	"sustainVolEnv",				// 37
	"releaseVolEnv",				// 38
	"keynumToVolEnvHold",			// 39
	"keynumToVolEnvDecay",			// 40
	"instrument",					// 41
	"reserved1",					// 42
	"keyRange",						// 43
	"velRange",						// 44
	"startloopAddrsCoarseOffset",	// 45
	"keynum",						// 46
	"velocity",						// 47
	"initialAttenuation",			// 48
	"reserved2",					// 49
	"endloopAddrsCoarseOffset",		// 50
	"coarseTune",					// 51
	"fineTune",						// 52
	"sampleID",						// 53
	"sampleModes",					// 54
	"reserved3",					// 55
	"scaleTuning",					// 56
	"exclusiveClass",				// 57
	"overridingRootKey",			// 58
	"unused5",						// 59
	"endOper",						// 60
};

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
		//::printf("RIFF('%c%c%c%c') %dbytes\n",
		//			formHdr[0], formHdr[1], formHdr[2], formHdr[3], ckSize);
		ckSize -= 4;
		if (!ReadSubChunk(env, sig, stream, static_cast<size_t>(ckSize))) return false;
	}
	return true;
}

void SoundFont::Print() const
{
	if (_INFO.p_ifil.get() != NULL) {
		::printf("ifil ");
		_INFO.p_ifil->Print();
	}
	if (_INFO.p_isng.get() != NULL) ::printf("isng \"%s\"\n", _INFO.p_isng->c_str());
	if (_INFO.p_INAM.get() != NULL) ::printf("INAM \"%s\"\n", _INFO.p_INAM->c_str());
	if (_INFO.p_irom.get() != NULL) ::printf("irom \"%s\"\n", _INFO.p_irom->c_str());
	if (_INFO.p_iver.get() != NULL) {
		::printf("<iver> ");
		_INFO.p_iver->Print();
	}
	if (_INFO.p_ICRD.get() != NULL) ::printf("ICRD \"%s\"\n", _INFO.p_ICRD->c_str());
	if (_INFO.p_IENG.get() != NULL) ::printf("IENG \"%s\"\n", _INFO.p_IENG->c_str());
	if (_INFO.p_IPRD.get() != NULL) ::printf("IPRD \"%s\"\n", _INFO.p_IPRD->c_str());
	if (_INFO.p_ICOP.get() != NULL) ::printf("ICOP \"%s\"\n", _INFO.p_ICOP->c_str());
	if (_INFO.p_ICMT.get() != NULL) ::printf("ICMT \"%s\"\n", _INFO.p_ICMT->c_str());
	if (_INFO.p_ISFT.get() != NULL) ::printf("ISFT \"%s\"\n", _INFO.p_ISFT->c_str());
	::printf("phdr[%d] : sfPresetHeader\n", _pdta.phdrs.size());
	_pdta.phdrs.Print();
	::printf("pbag[%d] : sfPresetBag\n", _pdta.pbags.size());
	_pdta.pbags.Print();
	::printf("pmod[%d] : sfMod\n", _pdta.pmods.size());
	_pdta.pmods.Print();
	::printf("pgen[%d] : sfGen\n", _pdta.pgens.size());
	_pdta.pgens.Print();
	::printf("inst[%d] : sfInst\n", _pdta.insts.size());
	_pdta.insts.Print();
	::printf("ibag[%d] : sfInstBag\n", _pdta.ibags.size());
	_pdta.ibags.Print();
	::printf("imod[%d] : sfInstMod\n", _pdta.imods.size());
	_pdta.imods.Print();
	::printf("igen[%d] : sfInstGen\n", _pdta.igens.size());
	_pdta.igens.Print();
	::printf("sndr[%d] : sfSample\n", _pdta.shdrs.size());
	_pdta.shdrs.Print();
}

const char *SoundFont::GeneratorToName(SFGenerator generator)
{
	if (generator <= endOper) return _generatorNames[generator];
	return "unknown";
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
		switch (ckID) {
		case CKID_LIST: {
			char listHdr[4];
			size_t bytesRead = stream.Read(sig, listHdr,
								ChooseMin(bytesRest, static_cast<size_t>(4)));
			if (bytesRead != 4) {
				sig.SetError(ERR_FormatError, "invalid SF2 format");
				return false;
			}
			//::printf("LIST('%c%c%c%c') %dbytes\n",
			//			listHdr[0], listHdr[1], listHdr[2], listHdr[3], ckSize);
			ckSize -= 4;
			if (!ReadSubChunk(env, sig, stream, static_cast<size_t>(ckSize))) return false;
			break;
		}
		// 5 The INFO-list Chunk
		case CKID_ifil: {	// 5.1
			sfVersionTag::RawData rawData;
			if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSize)) return false;
			_INFO.p_ifil.reset(new sfVersionTag(rawData));
			break;
		}
		case CKID_isng: {	// 5.2
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			_INFO.p_isng.reset(new String(str));
			break;
		}
		case CKID_INAM: {	// 5.3
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			_INFO.p_INAM.reset(new String(str));
			break;
		}
		case CKID_irom: {	// 5.4
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			_INFO.p_irom.reset(new String(str));
			break;
		}
		case CKID_iver: {	// 5.5
			sfVersionTag::RawData rawData;
			if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSize)) return false;
			_INFO.p_iver.reset(new sfVersionTag(rawData));
			break;
		}
		case CKID_ICRD: {	// 5.6
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			_INFO.p_ICRD.reset(new String(str));
			break;
		}
		case CKID_IENG: {	// 5.7
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			_INFO.p_IENG.reset(new String(str));
			break;
		}
		case CKID_IPRD: {	// 5.8
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			_INFO.p_IPRD.reset(new String(str));
			break;
		}
		case CKID_ICOP: {	// 5.9
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			_INFO.p_ICOP.reset(new String(str));
			break;
		}
		case CKID_ICMT: {	// 5.10
			char str[65536];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
			_INFO.p_ICMT.reset(new String(str));
			break;
		}
		case CKID_ISFT: {	// 5.11
			char str[256];
			if (!ReadString(env, sig, stream, str, sizeof(str), ckSize)) return false;
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
				_pdta.phdrs.push_back(new sfPresetHeader(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pbag: {	// 7.3
			sfPresetBag::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.pbags.push_back(new sfPresetBag(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pmod: {	// 7.4
			sfMod::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.pmods.push_back(new sfMod(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pgen: {	// 7.5
			sfGen::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.pgens.push_back(new sfGen(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_inst: {	// 7.6
			sfInst::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.insts.push_back(new sfInst(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_ibag: {	// 7.7
			sfInstBag::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.ibags.push_back(new sfInstBag(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_imod: {	// 7.8
			sfMod::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.imods.push_back(new sfMod(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_igen: {	// 7.9
			sfInstGen::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.igens.push_back(new sfInstGen(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_shdr: {	// 7.10
			sfSample::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, stream, &rawData, rawData.Size, ckSizeRest)) return false;
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

//-----------------------------------------------------------------------------
// SoundFont::sfVersionTag
// 5.1 The ifil Sub-chunk
// 5.5 The iver Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfVersionTag::sfVersionTag() : _cntRef(1),
		_wMajor(0),
		_wMinor(0)
{
}

SoundFont::sfVersionTag::sfVersionTag(const RawData &rawData) : _cntRef(1),
		_wMajor(Gura_UnpackUShort(rawData.wMajor)),
		_wMinor(Gura_UnpackUShort(rawData.wMinor))
{
}

void SoundFont::sfVersionTag::Print() const
{
	::printf("wMajor=%d wMinor=%d\n",
		_wMajor,
		_wMinor);
	}

//-----------------------------------------------------------------------------
// SoundFont::sfPresetHeader
// 7.2 The PHDR Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfPresetHeader::sfPresetHeader() : _cntRef(1),
		_wPreset(0),
		_wBank(0),
		_wPresetBagNdx(0),
		_dwLibrary(0),
		_dwGenre(0),
		_dwMorphology(0),
		_pPresetBagOwner(new sfPresetBagOwner())
{
	::memset(_achPresetName, 0x00, sizeof(_achPresetName));
}

SoundFont::sfPresetHeader::sfPresetHeader(const RawData &rawData) : _cntRef(1),
		_wPreset(Gura_UnpackUShort(rawData.wPreset)),
		_wBank(Gura_UnpackUShort(rawData.wBank)),
		_wPresetBagNdx(Gura_UnpackUShort(rawData.wPresetBagNdx)),
		_dwLibrary(Gura_UnpackULong(rawData.dwLibrary)),
		_dwGenre(Gura_UnpackULong(rawData.dwGenre)),
		_dwMorphology(Gura_UnpackULong(rawData.dwMorphology)),
		_pPresetBagOwner(new sfPresetBagOwner())
{
	::memcpy(_achPresetName, rawData.achPresetName, sizeof(_achPresetName));
}

void SoundFont::sfPresetHeader::Print() const
{
	::printf("achPresetName=\"%s\" wPreset=%d wBank=%d wPresetBagNdx=%d dwLibrary=%d dwGenre=%d dwMorphology=%d\n",
		_achPresetName,
		_wPreset,
		_wBank,
		_wPresetBagNdx,
		_dwLibrary,
		_dwGenre,
		_dwMorphology);
}

//-----------------------------------------------------------------------------
// SoundFont::sfPresetBag
// 7.3 The PBAG Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfPresetBag::sfPresetBag() : _cntRef(1),
		_wGenNdx(0),
		_wModNdx(0),
		_pGenOwner(new sfGenOwner()),
		_pModOwner(new sfModOwner())
{
}

SoundFont::sfPresetBag::sfPresetBag(const RawData &rawData) : _cntRef(1),
		_wGenNdx(Gura_UnpackUShort(rawData.wGenNdx)),
		_wModNdx(Gura_UnpackUShort(rawData.wModNdx)),
		_pGenOwner(new sfGenOwner()),
		_pModOwner(new sfModOwner())
{
}

void SoundFont::sfPresetBag::Print() const
{
	::printf("wGenNdx=%d wModNdx=%d\n",
		_wGenNdx,
		_wModNdx);
}

//-----------------------------------------------------------------------------
// SoundFont::sfMod
// 7.4 The PMOD Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfMod::sfMod() : _cntRef(1),
		_sfModSrcOper(static_cast<SFModulator>(0)),
		_sfModDestOper(static_cast<SFGenerator>(0)),
		_modAmount(0),
		_sfModAmtSrcOper(static_cast<SFModulator>(0)),
		_sfModTransOper(static_cast<SFTransform>(0))
{
}

SoundFont::sfMod::sfMod(const RawData &rawData) : _cntRef(1),
		_sfModSrcOper(static_cast<SFModulator>(Gura_UnpackUShort(rawData.sfModSrcOper))),
		_sfModDestOper(static_cast<SFGenerator>(Gura_UnpackUShort(rawData.sfModDestOper))),
		_modAmount(static_cast<short>(Gura_UnpackUShort(rawData.modAmount))),
		_sfModAmtSrcOper(static_cast<SFModulator>(Gura_UnpackUShort(rawData.sfModAmtSrcOper))),
		_sfModTransOper(static_cast<SFTransform>(Gura_UnpackUShort(rawData.sfModTransOper)))
{
}

void SoundFont::sfMod::Print() const
{
	::printf("sfModSrcOper=0x%04x sfModDestOper=%s(%d) modAmount=0x%04x sfModAmtSrcOper=0x%04x sfModTransOper=%d\n",
		_sfModSrcOper,
		GeneratorToName(_sfModDestOper), _sfModDestOper,
		_modAmount,
		_sfModAmtSrcOper,
		_sfModTransOper);
}

//-----------------------------------------------------------------------------
// SoundFont::sfGen
// 7.5 The PGEN Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfGen::sfGen() : _cntRef(1),
		_sfGenOper(static_cast<SFGenerator>(0)),
		_genAmount(0)
{
}

SoundFont::sfGen::sfGen(const RawData &rawData) : _cntRef(1),
		_sfGenOper(static_cast<SFGenerator>(Gura_UnpackUShort(rawData.sfGenOper))),
		_genAmount(Gura_UnpackUShort(rawData.genAmount))
{
}

void SoundFont::sfGen::Print() const
{
	::printf("sfGenOper=%s(%d) genAmount=0x%04x\n",
		GeneratorToName(_sfGenOper), _sfGenOper,
		_genAmount);
}

//-----------------------------------------------------------------------------
// SoundFont::sfInst
// 7.6 The INST Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfInst::sfInst() : _cntRef(1),
		_wInstBagNdx(0),
		_pInstBagOwner(new sfInstBagOwner())
{
	::memset(_achInstName, 0x00, sizeof(_achInstName));
}

SoundFont::sfInst::sfInst(const RawData &rawData) : _cntRef(1),
		_wInstBagNdx(Gura_UnpackUShort(rawData.wInstBagNdx)),
		_pInstBagOwner(new sfInstBagOwner())
{
	::memcpy(_achInstName, rawData.achInstName, sizeof(_achInstName));
}

void SoundFont::sfInst::Print() const
{
	::printf("achInstName=\"%s\" wInstBagNdx=%d\n",
		_achInstName,
		_wInstBagNdx);
}

//-----------------------------------------------------------------------------
// SoundFont::sfInstBag
// 7.7 The IBAG Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfInstBag::sfInstBag() : _cntRef(1),
		_wInstGenNdx(0),
		_wInstModNdx(0),
		_pInstGenOwner(new sfInstGenOwner()),
		_pInstModOwner(new sfInstModOwner())
{
}

SoundFont::sfInstBag::sfInstBag(const RawData &rawData) : _cntRef(1),
		_wInstGenNdx(Gura_UnpackUShort(rawData.wInstGenNdx)),
		_wInstModNdx(Gura_UnpackUShort(rawData.wInstModNdx)),
		_pInstGenOwner(new sfInstGenOwner()),
		_pInstModOwner(new sfInstModOwner())
{
}

void SoundFont::sfInstBag::Print() const
{
	::printf("wInstGenNdx=%d wInstModNdx=%d\n",
		_wInstGenNdx,
		_wInstModNdx);
}

//-----------------------------------------------------------------------------
// SoundFont::sfInstMod
// 7.8 The IMOD Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfInstMod::sfInstMod() : _cntRef(1),
		_sfModSrcOper(static_cast<SFModulator>(0)),
		_sfModDestOper(static_cast<SFGenerator>(0)),
		_modAmount(0),
		_sfModAmtSrcOper(static_cast<SFModulator>(0)),
		_sfModTransOper(static_cast<SFTransform>(0))
{
}

SoundFont::sfInstMod::sfInstMod(const RawData &rawData) : _cntRef(1),
		_sfModSrcOper(static_cast<SFModulator>(Gura_UnpackUShort(rawData.sfModSrcOper))),
		_sfModDestOper(static_cast<SFGenerator>(Gura_UnpackUShort(rawData.sfModDestOper))),
		_modAmount(static_cast<short>(Gura_UnpackUShort(rawData.modAmount))),
		_sfModAmtSrcOper(static_cast<SFModulator>(Gura_UnpackUShort(rawData.sfModAmtSrcOper))),
		_sfModTransOper(static_cast<SFTransform>(Gura_UnpackUShort(rawData.sfModTransOper)))
{
}

void SoundFont::sfInstMod::Print() const
{
	::printf("sfModSrcOper=0x%04x sfModDestOper=%s(%d) modAmount=0x%04x sfModAmtSrcOper=0x%04x sfModTransOper=%d\n",
		_sfModSrcOper,
		GeneratorToName(_sfModDestOper), _sfModDestOper,
		_modAmount,
		_sfModAmtSrcOper,
		_sfModTransOper);
}

//-----------------------------------------------------------------------------
// SoundFont::sfInstGen
// 7.9 The IGEN Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfInstGen::sfInstGen() : _cntRef(1),
		_sfGenOper(static_cast<SFGenerator>(0)),
		_genAmount(0)
{
}

SoundFont::sfInstGen::sfInstGen(const RawData &rawData) : _cntRef(1),
		_sfGenOper(static_cast<SFGenerator>(Gura_UnpackUShort(rawData.sfGenOper))),
		_genAmount(Gura_UnpackUShort(rawData.genAmount))
{
}

void SoundFont::sfInstGen::Print() const
{
	::printf("sfGenOper=%s(%d) genAmount=0x%04x\n",
		GeneratorToName(_sfGenOper), _sfGenOper,
		_genAmount);
}

//-----------------------------------------------------------------------------
// SoundFont::sfSample
// 7.10 The SHDR Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfSample::sfSample() : _cntRef(1),
		_dwStart(0),
		_dwEnd(0),
		_dwStartloop(0),
		_dwEndloop(0),
		_dwSampleRate(0),
		_byOriginalKey(0),
		_chCorrection(0),
		_wSampleLink(0),
		_sfSampleType(static_cast<SFSampleLink>(0))
{
	::memset(_achSampleName, 0x00, sizeof(_achSampleName));
}

SoundFont::sfSample::sfSample(const RawData &rawData) : _cntRef(1),
		_dwStart(Gura_UnpackULong(rawData.dwStart)),
		_dwEnd(Gura_UnpackULong(rawData.dwEnd)),
		_dwStartloop(Gura_UnpackULong(rawData.dwStartloop)),
		_dwEndloop(Gura_UnpackULong(rawData.dwEndloop)),
		_dwSampleRate(Gura_UnpackULong(rawData.dwSampleRate)),
		_byOriginalKey(rawData.byOriginalKey),
		_chCorrection(rawData.chCorrection),
		_wSampleLink(Gura_UnpackUShort(rawData.wSampleLink)),
		_sfSampleType(static_cast<SFSampleLink>(Gura_UnpackUShort(rawData.sfSampleType)))
{
	::memcpy(_achSampleName, rawData.achSampleName, sizeof(_achSampleName));
}

void SoundFont::sfSample::Print() const
{
	::printf("achSampleName=\"%s\" dwStart=%d dwEnd=%d dwStartloop=%d dwEndloop=%d dwSampleRate=%d byOriginalKey=%d chCorrection=%d wSampleLink=0x%04x sfSampleType=%d\n",
		_achSampleName,
		_dwStart,
		_dwEnd,
		_dwStartloop,
		_dwEndloop,
		_dwSampleRate,
		_byOriginalKey,
		_chCorrection,
		_wSampleLink,
		_sfSampleType);
}

}}
