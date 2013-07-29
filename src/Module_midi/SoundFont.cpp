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
	"delayModEnv",					// 28
	"sustainModEnv",				// 29
	"releaseModEnv",				// 30
	"keynumToModEnvHold",			// 31
	"keynumToModEnvDecay",			// 32
	"delayVolEnv",					// 33
	"attackVolEnv",					// 34
	"holdVolEnv",					// 35
	"decayVolEnv",					// 36
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

SoundFont::SoundFont(Stream *pStream) : _pStream(pStream)
{
}

void SoundFont::Clear()
{
	_INFO.p_ifil.reset(NULL);	// mandatory
	_INFO.p_isng.reset(NULL);	// mandatory
	_INFO.p_INAM.reset(NULL);	// mandatory
	_INFO.p_irom.reset(NULL);	// optional
	_INFO.p_iver.reset(NULL);	// optional
	_INFO.p_ICRD.reset(NULL);	// optional
	_INFO.p_IENG.reset(NULL);	// optional
	_INFO.p_IPRD.reset(NULL);	// optional
	_INFO.p_ICOP.reset(NULL);	// optional
	_INFO.p_ICMT.reset(NULL);	// optional
	_INFO.p_ISFT.reset(NULL);	// optional
	_offsetSdta = 0;
	_pdta.phdrs.Clear();
	_pdta.pbags.Clear();
	_pdta.pmods.Clear();
	_pdta.pgens.Clear();
	_pdta.insts.Clear();
	_pdta.ibags.Clear();
	_pdta.imods.Clear();
	_pdta.igens.Clear();
	_pdta.shdrs.Clear();
}

bool SoundFont::ReadChunks(Environment &env, Signal sig)
{
	ChunkHdr chunkHdr;
	size_t bytesRead = _pStream->Read(sig, &chunkHdr, ChunkHdr::Size);
	if (bytesRead != ChunkHdr::Size) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	ULong ckID = Gura_UnpackULong(chunkHdr.ckID);
	ULong ckSize = Gura_UnpackULong(chunkHdr.ckSize);
	if (ckID != CKID_RIFF) {
		sig.SetError(ERR_FormatError, "can't find RIFF chunk");
		return false;
	}
	char formHdr[4];
	bytesRead = _pStream->Read(sig, formHdr, 4);
	if (bytesRead != 4) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	if (::memcmp(formHdr, "sfbk", 4) != 0) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	ckSize -= 4;
	if (!ReadSubChunk(env, sig, static_cast<size_t>(ckSize))) return false;
	if (_INFO.p_ifil.get() == NULL ||
				_INFO.p_isng.get() == NULL || _INFO.p_INAM.get() == NULL) {
		sig.SetError(ERR_FormatError, "necessary chunk doesn't exist");
		return false;
	}
	// 6 The sdta-list Chunk
	if (_offsetSdta == 0) {
		sig.SetError(ERR_FormatError, "sdta-list doesn't exist");
		return false;
	}
	// 7.2 The PHDR Sub-chunk
	foreach (sfPresetHeaderOwner, ppPresetHeader, _pdta.phdrs) {
		if (ppPresetHeader + 1 == _pdta.phdrs.end()) break;
		sfPresetHeader *pPresetHeader = *ppPresetHeader;
		sfPresetHeader *pPresetHeaderNext = *(ppPresetHeader + 1);
		if (!pPresetHeader->SetupReference(sig, pPresetHeaderNext, _pdta)) return false;
	}
	// 7.3 The PBAG Sub-chunk
	foreach (sfPresetBagOwner, ppPresetBag, _pdta.pbags) {
		if (ppPresetBag + 1 == _pdta.pbags.end()) break;
		sfPresetBag *pPresetBag = *ppPresetBag;
		sfPresetBag *pPresetBagNext = *(ppPresetBag + 1);
		if (!pPresetBag->SetupReference(sig, pPresetBagNext, _pdta)) return false;
	}
	// 7.6 The INST Sub-chunk
	foreach (sfInstOwner, ppInst, _pdta.insts) {
		if (ppInst + 1 == _pdta.insts.end()) break;
		sfInst *pInst = *ppInst;
		sfInst *pInstNext = *(ppInst + 1);
		if (!pInst->SetupReference(sig, pInstNext, _pdta)) return false;
	}
	// 7.7 The IBAG Sub-chunk
	foreach (sfInstBagOwner, ppInstBag, _pdta.ibags) {
		if (ppInstBag + 1 == _pdta.ibags.end()) break;
		sfInstBag *pInstBag = *ppInstBag;
		sfInstBag *pInstBagNext = *(ppInstBag + 1);
		if (!pInstBag->SetupReference(sig, pInstBagNext,
							_pdta, *_pStream, _offsetSdta)) return false;
	}
	return true;
}

const SoundFont::sfPresetHeader *SoundFont::LookupPresetHeader(
										UShort wPreset, UShort wBank) const
{
	foreach_const (sfPresetHeaderOwner, ppPresetHeader, _pdta.phdrs) {
		const sfPresetHeader *pPresetHeader = *ppPresetHeader;
		if (pPresetHeader->IsMatched(wPreset, wBank)) return pPresetHeader;
	}
	return NULL;
}

void SoundFont::Print() const
{
	if (_INFO.p_ifil.get() != NULL) {
		::printf("ifil ");
		_INFO.p_ifil->Print(0);
	}
	if (_INFO.p_isng.get() != NULL) ::printf("isng \"%s\"\n", _INFO.p_isng->c_str());
	if (_INFO.p_INAM.get() != NULL) ::printf("INAM \"%s\"\n", _INFO.p_INAM->c_str());
	if (_INFO.p_irom.get() != NULL) ::printf("irom \"%s\"\n", _INFO.p_irom->c_str());
	if (_INFO.p_iver.get() != NULL) {
		::printf("<iver> ");
		_INFO.p_iver->Print(0);
	}
	if (_INFO.p_ICRD.get() != NULL) ::printf("ICRD \"%s\"\n", _INFO.p_ICRD->c_str());
	if (_INFO.p_IENG.get() != NULL) ::printf("IENG \"%s\"\n", _INFO.p_IENG->c_str());
	if (_INFO.p_IPRD.get() != NULL) ::printf("IPRD \"%s\"\n", _INFO.p_IPRD->c_str());
	if (_INFO.p_ICOP.get() != NULL) ::printf("ICOP \"%s\"\n", _INFO.p_ICOP->c_str());
	if (_INFO.p_ICMT.get() != NULL) ::printf("ICMT \"%s\"\n", _INFO.p_ICMT->c_str());
	if (_INFO.p_ISFT.get() != NULL) ::printf("ISFT \"%s\"\n", _INFO.p_ISFT->c_str());
	::printf("phdr[%d] : sfPresetHeader\n", _pdta.phdrs.size());
	_pdta.phdrs.Print(0);
}

const char *SoundFont::SFGeneratorToName(SFGenerator generator)
{
	if (generator <= GEN_endOper) return _generatorNames[generator];
	return "unknown";
}

bool SoundFont::ReadSubChunk(Environment &env, Signal sig, size_t bytes)
{
	size_t bytesRest = (bytes + 1) / 2 * 2;
	while (bytesRest > 0) {
		ChunkHdr chunkHdr;
		//::printf("bytesRest = %d\n", bytesRest);
		size_t bytesRead = _pStream->Read(sig, &chunkHdr,
						ChooseMin(bytesRest, static_cast<size_t>(ChunkHdr::Size)));
		if (bytesRead != ChunkHdr::Size) {
			sig.SetError(ERR_FormatError, "invalid SF2 format");
			return false;
		}
		bytesRest -= bytesRead;
		ULong ckID = Gura_UnpackULong(chunkHdr.ckID);
		ULong ckSize = Gura_UnpackULong(chunkHdr.ckSize);
		ULong ckSizeAlign = (ckSize + 1) / 2 * 2;
		switch (ckID) {
		case CKID_LIST: {
			char listHdr[4];
			size_t bytesRead = _pStream->Read(sig, listHdr,
								ChooseMin(bytesRest, static_cast<size_t>(4)));
			if (bytesRead != 4) {
				sig.SetError(ERR_FormatError, "invalid SF2 format");
				return false;
			}
			//::printf("LIST('%c%c%c%c') %dbytes\n",
			//			listHdr[0], listHdr[1], listHdr[2], listHdr[3], ckSize);
			ckSize -= 4;
			if (!ReadSubChunk(env, sig, static_cast<size_t>(ckSize))) return false;
			break;
		}
		// 5 The INFO-list Chunk
		case CKID_ifil: {	// 5.1
			sfVersionTag::RawData rawData;
			if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSize)) return false;
			_INFO.p_ifil.reset(new sfVersionTag(rawData));
			break;
		}
		case CKID_isng: {	// 5.2
			char str[256];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_isng.reset(new String(str));
			break;
		}
		case CKID_INAM: {	// 5.3
			char str[256];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_INAM.reset(new String(str));
			break;
		}
		case CKID_irom: {	// 5.4
			char str[256];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_irom.reset(new String(str));
			break;
		}
		case CKID_iver: {	// 5.5
			sfVersionTag::RawData rawData;
			if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSize)) return false;
			_INFO.p_iver.reset(new sfVersionTag(rawData));
			break;
		}
		case CKID_ICRD: {	// 5.6
			char str[256];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_ICRD.reset(new String(str));
			break;
		}
		case CKID_IENG: {	// 5.7
			char str[256];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_IENG.reset(new String(str));
			break;
		}
		case CKID_IPRD: {	// 5.8
			char str[256];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_IPRD.reset(new String(str));
			break;
		}
		case CKID_ICOP: {	// 5.9
			char str[256];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_ICOP.reset(new String(str));
			break;
		}
		case CKID_ICMT: {	// 5.10
			char str[65536];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_ICMT.reset(new String(str));
			break;
		}
		case CKID_ISFT: {	// 5.11
			char str[256];
			if (!ReadString(env, sig, str, sizeof(str), ckSize)) return false;
			_INFO.p_ISFT.reset(new String(str));
			break;
		}
		// 6 The sdta-list Chunk
		case CKID_smpl: {	// 6.1 Sample Data Format in the smpl Sub-Chunk
			// 16-bits, signed, little endian words
			_offsetSdta = _pStream->Tell();
			_pStream->Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		// 7 The pdta-list Chunk
		case CKID_phdr: {	// 7.2
			sfPresetHeader::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.phdrs.push_back(new sfPresetHeader(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pbag: {	// 7.3
			sfPresetBag::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.pbags.push_back(new sfPresetBag(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pmod: {	// 7.4
			sfMod::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.pmods.push_back(new sfMod(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_pgen: {	// 7.5
			sfGen::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.pgens.push_back(new sfGen(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_inst: {	// 7.6
			sfInst::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.insts.push_back(new sfInst(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_ibag: {	// 7.7
			sfInstBag::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.ibags.push_back(new sfInstBag(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_imod: {	// 7.8
			sfMod::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.imods.push_back(new sfMod(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_igen: {	// 7.9
			sfGen::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.igens.push_back(new sfGen(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		case CKID_shdr: {	// 7.10
			sfSample::RawData rawData;
			for (size_t ckSizeRest = ckSize; ckSizeRest > 0; ) {
				if (!ReadStruct(env, sig, &rawData, rawData.Size, ckSizeRest)) return false;
				_pdta.shdrs.push_back(new sfSample(rawData));
				ckSizeRest -= rawData.Size;
			}
			break;
		}
		default: {
			::printf("****\n");
			_pStream->Seek(sig, ckSizeAlign, Stream::SeekCur);
			break;
		}
		}
		bytesRest -= ckSizeAlign;
	}
	return true;
}

bool SoundFont::ReadStruct(Environment &env, Signal sig,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual)
{
	if (ckSizeExpect > ckSizeActual) {
		sig.SetError(ERR_FormatError, "unexpected size of chunk");
		return false;
	}
	size_t bytesRead = _pStream->Read(sig, rawData, ckSizeExpect);
	if (bytesRead != ckSizeExpect) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	return true;
}

bool SoundFont::ReadString(Environment &env, Signal sig,
						char *str, size_t ckSizeMax, size_t ckSizeActual)
{
	size_t ckSizeAlign = (ckSizeActual + 1) / 2 * 2;
	if (ckSizeMax < ckSizeAlign) {
		sig.SetError(ERR_FormatError, "string data is too long");
		return false;
	}
	size_t bytesRead = _pStream->Read(sig, str, ckSizeAlign);
	if (bytesRead != ckSizeAlign) {
		sig.SetError(ERR_FormatError, "invalid SF2 format");
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// SoundFont::ChunkHdr
//-----------------------------------------------------------------------------
void SoundFont::ChunkHdr::Print(int indentLevel) const
{
	ULong ckID = Gura_UnpackULong(ckID);
	ULong ckSize = Gura_UnpackULong(ckSize);
	::printf("%*s<%c%c%c%c-ck> %dbytes\n", indentLevel * 2, "",
			static_cast<UChar>(ckID >> 0),
			static_cast<UChar>(ckID >> 8),
			static_cast<UChar>(ckID >> 16),
			static_cast<UChar>(ckID >> 24), ckSize);
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

void SoundFont::sfVersionTag::Print(int indentLevel) const
{
	::printf("%*swMajor=%d wMinor=%d\n",
		indentLevel * 2, "",
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

void SoundFont::sfPresetHeader::Print(int indentLevel) const
{
	::printf("%*sachPresetName=\"%s\" wPreset=%d wBank=%d wPresetBagNdx=%d dwLibrary=%d dwGenre=%d dwMorphology=%d\n",
		indentLevel * 2, "",
		_achPresetName,
		_wPreset,
		_wBank,
		_wPresetBagNdx,
		_dwLibrary,
		_dwGenre,
		_dwMorphology);
	GetPresetBagOwner().Print(indentLevel + 1);
}

bool SoundFont::sfPresetHeader::SetupReference(Signal sig,
							sfPresetHeader *pPresetHeaderNext, const pdta_t &pdta)
{
	if (_wPresetBagNdx > pPresetHeaderNext->_wPresetBagNdx ||
			static_cast<size_t>(_wPresetBagNdx) > pdta.pbags.size() ||
			static_cast<size_t>(pPresetHeaderNext->_wPresetBagNdx) > pdta.pbags.size()) {
		sig.SetError(ERR_FormatError, "invalid wPresetBagNdx value in sfPresetHeader");
		return false;
	}
	sfPresetBagOwner::const_iterator ppPresetBag = pdta.pbags.begin() + _wPresetBagNdx;
	sfPresetBagOwner::const_iterator ppPresetBagEnd =
							pdta.pbags.begin() + pPresetHeaderNext->_wPresetBagNdx;
	for ( ; ppPresetBag != ppPresetBagEnd; ppPresetBag++) {
		const sfPresetBag *pPresetBag = *ppPresetBag;
		GetPresetBagOwner().push_back(sfPresetBag::Reference(pPresetBag));
	}
	return true;
}

SoundFont::Synthesizer *SoundFont::sfPresetHeader::CreateSynthesizer(UChar key, UChar velocity) const
{
	AutoPtr<Synthesizer> pSynthesizer(new Synthesizer());
	foreach_const (sfPresetBagOwner, ppPresetBag, GetPresetBagOwner()) {
		const sfPresetBag *pPresetBag = *ppPresetBag;
		if (!pPresetBag->IsMatched(key, velocity)) continue;
		foreach_const (sfGenOwner, ppGen, pPresetBag->GetGenOwner()) {
			const sfGen *pGen = *ppGen;
			pSynthesizer->GetProps().Update(pGen->GetGenOper(), pGen->GetGenAmount());
		}
		foreach_const (sfModOwner, ppMod, pPresetBag->GetModOwner()) {
			const sfMod *pMod = *ppMod;
			pSynthesizer->GetModOwner().push_back(pMod->Reference());
		}
		const sfInst *pInst = pPresetBag->GetInst();
		if (pInst == NULL) continue;
		foreach_const (sfInstBagOwner, ppInstBag, pInst->GetInstBagOwner()) {
			const sfInstBag *pInstBag = *ppInstBag;
			if (!pInstBag->IsMatched(key, velocity)) continue;
			foreach_const (sfGenOwner, ppInstGen, pInstBag->GetInstGenOwner()) {
				const sfGen *pInstGen = *ppInstGen;
				pSynthesizer->GetProps().Update(
						pInstGen->GetGenOper(), pInstGen->GetGenAmount());
			}
			foreach_const (sfModOwner, ppInstMod, pInstBag->GetInstModOwner()) {
				const sfMod *pInstMod = *ppInstMod;
				pSynthesizer->GetModOwner().push_back(pInstMod->Reference());
			}
		}
	}
	return pSynthesizer.release();
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

void SoundFont::sfPresetBag::Print(int indentLevel) const
{
	::printf("%*swGenNdx=%d wModNdx=%d\n",
		indentLevel * 2, "",
		_wGenNdx,
		_wModNdx);
	GetGenOwner().Print(indentLevel + 1);
	GetModOwner().Print(indentLevel + 1);
	if (GetInst() != NULL) GetInst()->Print(indentLevel + 1);
}

bool SoundFont::sfPresetBag::SetupReference(Signal sig, sfPresetBag *pPresetBagNext, const pdta_t &pdta)
{
	if (_wModNdx > pPresetBagNext->_wModNdx ||
			static_cast<size_t>(_wModNdx) > pdta.pmods.size() ||
			static_cast<size_t>(pPresetBagNext->_wModNdx) > pdta.pmods.size()) {
		sig.SetError(ERR_FormatError, "invalid wModNdx value in sfPresetBag");
		return false;
	}
	sfModOwner::const_iterator ppMod = pdta.pmods.begin() + _wModNdx;
	sfModOwner::const_iterator ppModEnd =
							pdta.pmods.begin() + pPresetBagNext->_wModNdx;
	for ( ; ppMod != ppModEnd; ppMod++) {
		const sfMod *pMod = *ppMod;
		GetModOwner().push_back(sfMod::Reference(pMod));
	}
	if (_wGenNdx > pPresetBagNext->_wGenNdx ||
			static_cast<size_t>(_wGenNdx) > pdta.pgens.size() ||
			static_cast<size_t>(pPresetBagNext->_wGenNdx) > pdta.pgens.size()) {
		sig.SetError(ERR_FormatError, "invalid wGenNdx value in sfPresetBag");
		return false;
	}
	sfGenOwner::const_iterator ppGen = pdta.pgens.begin() + _wGenNdx;
	sfGenOwner::const_iterator ppGenEnd =
							pdta.pgens.begin() + pPresetBagNext->_wGenNdx;
	for ( ; ppGen != ppGenEnd; ppGen++) {
		const sfGen *pGen = *ppGen;
		GetGenOwner().push_back(sfGen::Reference(pGen));
		switch (pGen->GetGenOper()) {
		case GEN_keyRange: {
			_pKeyRange.reset(new RangesType(pGen->GetGenAmount()));
			break;
		}
		case GEN_velRange: {
			_pVelRange.reset(new RangesType(pGen->GetGenAmount()));
			break;
		}
		case GEN_instrument: {
			UShort wInstNdx = pGen->GetGenAmount();
			if (static_cast<size_t>(wInstNdx) >= pdta.insts.size()) {
				sig.SetError(ERR_FormatError, "invalid index value in sfGen instrument");
				return false;
			}
			const sfInst *pInst = pdta.insts[wInstNdx];
			_pInst.reset(sfInst::Reference(pInst));
			break;
		}
		default: {
			// nothing to do
			break;
		}
		}
	}
	return true;
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

void SoundFont::sfMod::Print(int indentLevel) const
{
	::printf("%*ssfModSrcOper=0x%04x sfModDestOper=%s(%d) modAmount=0x%04x sfModAmtSrcOper=0x%04x sfModTransOper=%d\n",
		indentLevel * 2, "",
		_sfModSrcOper,
		SFGeneratorToName(_sfModDestOper), _sfModDestOper,
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

void SoundFont::sfGen::Print(int indentLevel) const
{
	::printf("%*ssfGenOper=%s(%d) genAmount=0x%04x\n",
		indentLevel * 2, "",
		SFGeneratorToName(_sfGenOper), _sfGenOper,
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

void SoundFont::sfInst::Print(int indentLevel) const
{
	::printf("%*sachInstName=\"%s\" wInstBagNdx=%d\n",
		indentLevel * 2, "",
		_achInstName,
		_wInstBagNdx);
	GetInstBagOwner().Print(indentLevel + 1);
}

bool SoundFont::sfInst::SetupReference(Signal sig, sfInst *pInstNext, const pdta_t &pdta)
{
	if (_wInstBagNdx > pInstNext->_wInstBagNdx ||
			static_cast<size_t>(_wInstBagNdx) > pdta.ibags.size() ||
			static_cast<size_t>(pInstNext->_wInstBagNdx) > pdta.ibags.size()) {
		sig.SetError(ERR_FormatError, "invalid wInstBagNdx value in sfInst");
		return false;
	}
	sfInstBagOwner::const_iterator ppInstBag = pdta.ibags.begin() + _wInstBagNdx;
	sfInstBagOwner::const_iterator ppInstBagEnd =
							pdta.ibags.begin() + pInstNext->_wInstBagNdx;
	for ( ; ppInstBag != ppInstBagEnd; ppInstBag++) {
		const sfInstBag *pInstBag = *ppInstBag;
		GetInstBagOwner().push_back(sfInstBag::Reference(pInstBag));
	}
	return true;
}

//-----------------------------------------------------------------------------
// SoundFont::sfInstBag
// 7.7 The IBAG Sub-chunk
//-----------------------------------------------------------------------------
SoundFont::sfInstBag::sfInstBag() : _cntRef(1),
		_wInstGenNdx(0),
		_wInstModNdx(0),
		_pInstGenOwner(new sfGenOwner()),
		_pInstModOwner(new sfModOwner())
{
}

SoundFont::sfInstBag::sfInstBag(const RawData &rawData) : _cntRef(1),
		_wInstGenNdx(Gura_UnpackUShort(rawData.wInstGenNdx)),
		_wInstModNdx(Gura_UnpackUShort(rawData.wInstModNdx)),
		_pInstGenOwner(new sfGenOwner()),
		_pInstModOwner(new sfModOwner())
{
}

void SoundFont::sfInstBag::Print(int indentLevel) const
{
	::printf("%*swInstGenNdx=%d wInstModNdx=%d\n",
		indentLevel * 2, "",
		_wInstGenNdx,
		_wInstModNdx);
	GetInstGenOwner().Print(indentLevel + 1);
	GetInstModOwner().Print(indentLevel + 1);
	if (GetSample() != NULL) GetSample()->Print(indentLevel + 1);
}

bool SoundFont::sfInstBag::SetupReference(Signal sig, sfInstBag *pInstBagNext,
						const pdta_t &pdta, Stream &stream, size_t offsetSdta)
{
	if (_wInstModNdx > pInstBagNext->_wInstModNdx ||
			static_cast<size_t>(_wInstModNdx) > pdta.imods.size() ||
			static_cast<size_t>(pInstBagNext->_wInstModNdx) > pdta.imods.size()) {
		sig.SetError(ERR_FormatError, "invalid wInstModNdx value in sfInstBag");
		return false;
	}
	sfModOwner::const_iterator ppInstMod = pdta.imods.begin() + _wInstModNdx;
	sfModOwner::const_iterator ppInstModEnd =
							pdta.imods.begin() + pInstBagNext->_wInstModNdx;
	for ( ; ppInstMod != ppInstModEnd; ppInstMod++) {
		const sfMod *pInstMod = *ppInstMod;
		GetInstModOwner().push_back(sfMod::Reference(pInstMod));
	}
	if (_wInstGenNdx > pInstBagNext->_wInstGenNdx ||
			static_cast<size_t>(_wInstGenNdx) > pdta.igens.size() ||
			static_cast<size_t>(pInstBagNext->_wInstGenNdx) > pdta.igens.size()) {
		sig.SetError(ERR_FormatError, "invalid wInstGenNdx value in sfInstBag");
		return false;
	}
	sfGenOwner::const_iterator ppInstGen = pdta.igens.begin() + _wInstGenNdx;
	sfGenOwner::const_iterator ppInstGenEnd =
							pdta.igens.begin() + pInstBagNext->_wInstGenNdx;
	for ( ; ppInstGen != ppInstGenEnd; ppInstGen++) {
		const sfGen *pInstGen = *ppInstGen;
		GetInstGenOwner().push_back(sfGen::Reference(pInstGen));
		switch (pInstGen->GetGenOper()) {
		case GEN_keyRange: {
			_pKeyRange.reset(new RangesType(pInstGen->GetGenAmount()));
			break;
		}
		case GEN_velRange: {
			_pVelRange.reset(new RangesType(pInstGen->GetGenAmount()));
			break;
		}
		case GEN_sampleID: {
			UShort wSampleNdx = pInstGen->GetGenAmount();
			if (static_cast<size_t>(wSampleNdx) >= pdta.shdrs.size()) {
				sig.SetError(ERR_FormatError, "invalid index value in sfGen sampleID");
				return false;
			}
			const sfSample *pSample = pdta.shdrs[wSampleNdx];
			_pSample.reset(sfSample::Reference(pSample));
			Audio *pAudio = _pSample->CreateAudio(sig, stream, offsetSdta);
			if (pAudio == NULL) return false;
			_pAudio.reset(pAudio);
			break;
		}
		default: {
			// nothing to do
			break;
		}
		}
	}
	return true;
}

//-----------------------------------------------------------------------------
// SoundFont::sfInstMod
// 7.8 The IMOD Sub-chunk
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// SoundFont::sfInstGen
// 7.9 The IGEN Sub-chunk
//-----------------------------------------------------------------------------

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

Audio *SoundFont::sfSample::CreateAudio(Signal sig,
									Stream &stream, size_t offsetSdta) const
{
	AutoPtr<Audio> pAudio(new Audio(Audio::FORMAT_S16LE, 1, _dwSampleRate));
	if (_dwStart <= _dwEnd) {
		sig.SetError(ERR_FormatError, "invalid value in sfSample");
		return NULL;
	}
	if (!stream.Seek(sig, offsetSdta + _dwStart * 2, Stream::SeekSet)) return NULL;
	size_t nSamples = _dwEnd - _dwStart;
	Audio::Chain *pChain = pAudio->AllocChain(nSamples);
	size_t bytesToRead = nSamples * 2;
	size_t bytesRead = stream.Read(sig, pChain->GetPointer(), bytesToRead);
	if (sig.IsSignalled()) return NULL;
	if (bytesRead < bytesToRead) {
		sig.SetError(ERR_FormatError, "invalid format of SoundFont");
		return NULL;
	}
	return pAudio.release();
}

void SoundFont::sfSample::Print(int indentLevel) const
{
	::printf("%*sachSampleName=\"%s\" dwStart=%d dwEnd=%d dwStartloop=%d dwEndloop=%d dwSampleRate=%d byOriginalKey=%d chCorrection=%d wSampleLink=0x%04x sfSampleType=%d\n",
		indentLevel * 2, "",
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

//-----------------------------------------------------------------------------
// SoundFont::Synthesizer
//-----------------------------------------------------------------------------
SoundFont::Synthesizer::Synthesizer() : _cntRef(1), _pModOwner(new sfModOwner())
{
	_props.Reset();
}

//-----------------------------------------------------------------------------
// SoundFont::Synthesizer::Props
//-----------------------------------------------------------------------------
void SoundFont::Synthesizer::Props::Reset()
{
	// see a table described in "8.1.3 Generator Summary"
	startAddrsOffset			= 0;		// 0
	endAddrsOffset				= 0;		// 1
	startloopAddrsOffset		= 0;		// 2
	endloopAddrsOffset			= 0;		// 3
	startAddrsCoarseOffset		= 0;		// 4
	modLfoToPitch				= 0;		// 5
	vibLfoToPitch				= 0;		// 6
	modEnvToPitch				= 0;		// 7
	initialFilterFc				= 13500;	// 8
	initiflFilterQ				= 0;		// 9
	modLfoToFilterFc			= 0;		// 10
	modEnvToFilterFc			= 0;		// 11
	endAddrsCoarseOffset		= 0;		// 12
	modLfoToVolume				= 0;		// 13
	unnsed1						= 0;		// 14
	chorusEffectsSend			= 0;		// 15
	reverbEffectsSend			= 0;		// 16
	pan							= 0;		// 17
	unused2						= 0;		// 18
	unused3						= 0;		// 19
	unused4						= 0;		// 20
	delayModLFO					= -12000;	// 21
	freqModLFO					= 0;		// 22
	delayVibLFO					= -12000;	// 23
	freqVibLFO					= 0;		// 24
	delayModEnv					= -12000;	// 25
	attackModEnv				= -12000;	// 26
	holdModEnv					= -12000;	// 27
	decayModEnv					= -12000;	// 28
	sustainModEnv				= 0;		// 29
	releaseModEnv				= -12000;	// 30
	keynumToModEnvHold			= 0;		// 31
	keynumToModEnvDecay			= 0;		// 32
	delayVolEnv					= -12000;	// 33
	attackVolEnv				= -12000;	// 34
	holdVolEnv					= -12000;	// 35
	decayVolEnv					= -12000;	// 36
	sustainVolEnv				= 0;		// 37
	releaseVolEnv				= -12000;	// 38
	keynumToVolEnvHold			= 0;		// 39
	keynumToVolEnvDecay			= 0;		// 40
	instrument					= 0;		// 41
	reserved1					= 0;		// 42
	keyRange.byLo				= 0;		// 43
	keyRange.byHi				= 127;
	velRange.byLo				= 0;		// 44
	velRange.byHi				= 127;
	startloopAddrsCoarseOffset	= 0;		// 45
	keynum						= -1;		// 46
	velocity					= -1;		// 47
	initialAttenuation			= 0;		// 48
	reserved2					= 0;		// 49
	endloopAddrsCoarseOffset	= 0;		// 50
	coarseTune					= 0;		// 51
	fineTune					= 0;		// 52
	sampleID					= 0;		// 53
	sampleModes					= 0;		// 54
	reserved3					= 0;		// 55
	scaleTuning					= 100;		// 56
	exclusiveClass				= 0;		// 57
	overridingRootKey			= -1;		// 58
	unused5						= 0;		// 59
	endOper						= 0;		// 60
}

bool SoundFont::Synthesizer::Props::Update(SFGenerator sfGenOper, UShort genAmount)
{
	switch (sfGenOper) {
	case GEN_startAddrsOffset:				// 0
		startAddrsOffset = static_cast<UShort>(genAmount);
		break;
	case GEN_endAddrsOffset:				// 1
		endAddrsOffset = static_cast<UShort>(genAmount);
		break;
	case GEN_startloopAddrsOffset:			// 2
		startloopAddrsOffset = static_cast<UShort>(genAmount);
		break;
	case GEN_endloopAddrsOffset:			// 3
		endloopAddrsOffset = static_cast<UShort>(genAmount);
		break;
	case GEN_startAddrsCoarseOffset:		// 4
		startAddrsCoarseOffset = static_cast<UShort>(genAmount);
		break;
	case GEN_modLfoToPitch:					// 5
		modLfoToPitch = static_cast<Short>(genAmount);
		break;
	case GEN_vibLfoToPitch:					// 6
		vibLfoToPitch = static_cast<Short>(genAmount);
		break;
	case GEN_modEnvToPitch:					// 7
		modEnvToPitch = static_cast<Short>(genAmount);
		break;
	case GEN_initialFilterFc:				// 8
		initialFilterFc = static_cast<Short>(genAmount);
		break;
	case GEN_initiflFilterQ:				// 9
		initiflFilterQ = static_cast<Short>(genAmount);
		break;
	case GEN_modLfoToFilterFc:				// 10
		modLfoToFilterFc = static_cast<Short>(genAmount);
		break;
	case GEN_modEnvToFilterFc:				// 11
		modEnvToFilterFc = static_cast<Short>(genAmount);
		break;
	case GEN_endAddrsCoarseOffset:			// 12
		endAddrsCoarseOffset = static_cast<UShort>(genAmount);
		break;
	case GEN_modLfoToVolume:				// 13
		modLfoToVolume = static_cast<Short>(genAmount);
		break;
	case GEN_unnsed1:						// 14
		unnsed1 = static_cast<UShort>(genAmount);
		break;
	case GEN_chorusEffectsSend:				// 15
		chorusEffectsSend = static_cast<UShort>(genAmount);
		break;
	case GEN_reverbEffectsSend:				// 16
		reverbEffectsSend = static_cast<UShort>(genAmount);
		break;
	case GEN_pan:							// 17
		pan = static_cast<Short>(genAmount);
		break;
	case GEN_unused2:						// 18
		unused2 = static_cast<UShort>(genAmount);
		break;
	case GEN_unused3:						// 19
		unused3 = static_cast<UShort>(genAmount);
		break;
	case GEN_unused4:						// 20
		unused4 = static_cast<UShort>(genAmount);
		break;
	case GEN_delayModLFO:					// 21
		delayModLFO = static_cast<Short>(genAmount);
		break;
	case GEN_freqModLFO:					// 22
		freqModLFO = static_cast<Short>(genAmount);
		break;
	case GEN_delayVibLFO:					// 23
		delayVibLFO = static_cast<Short>(genAmount);
		break;
	case GEN_freqVibLFO:					// 24
		freqVibLFO = static_cast<Short>(genAmount);
		break;
	case GEN_delayModEnv:					// 25
		delayModEnv = static_cast<Short>(genAmount);
		break;
	case GEN_attackModEnv:					// 26
		attackModEnv = static_cast<Short>(genAmount);
		break;
	case GEN_holdModEnv:					// 27
		holdModEnv = static_cast<Short>(genAmount);
		break;
	case GEN_decayModEnv:					// 28
		decayModEnv = static_cast<Short>(genAmount);
		break;
	case GEN_sustainModEnv:					// 29
		sustainModEnv = static_cast<Short>(genAmount);
		break;
	case GEN_releaseModEnv:					// 30
		releaseModEnv = static_cast<Short>(genAmount);
		break;
	case GEN_keynumToModEnvHold:			// 31
		keynumToModEnvHold = static_cast<Short>(genAmount);
		break;
	case GEN_keynumToModEnvDecay:			// 32
		keynumToModEnvDecay = static_cast<Short>(genAmount);
		break;
	case GEN_delayVolEnv:					// 33
		delayVolEnv = static_cast<Short>(genAmount);
		break;
	case GEN_attackVolEnv:					// 34
		attackVolEnv = static_cast<Short>(genAmount);
		break;
	case GEN_holdVolEnv:					// 35
		holdVolEnv = static_cast<Short>(genAmount);
		break;
	case GEN_decayVolEnv:					// 36
		decayVolEnv = static_cast<Short>(genAmount);
		break;
	case GEN_sustainVolEnv:					// 37
		sustainVolEnv = static_cast<Short>(genAmount);
		break;
	case GEN_releaseVolEnv:					// 38
		releaseVolEnv = static_cast<Short>(genAmount);
		break;
	case GEN_keynumToVolEnvHold:			// 39
		keynumToVolEnvHold = static_cast<Short>(genAmount);
		break;
	case GEN_keynumToVolEnvDecay:			// 40
		keynumToVolEnvDecay = static_cast<Short>(genAmount);
		break;
	case GEN_instrument:					// 41
		instrument = static_cast<UShort>(genAmount);
		break;
	case GEN_reserved1:						// 42
		reserved1 = static_cast<UShort>(genAmount);
		break;
	case GEN_keyRange:						// 43
		keyRange.byLo = static_cast<UChar>(genAmount >> 0);
		keyRange.byHi = static_cast<UChar>(genAmount >> 8);
		break;
	case GEN_velRange:						// 44
		velRange.byLo = static_cast<UChar>(genAmount >> 0);
		velRange.byHi = static_cast<UChar>(genAmount >> 8);
		break;
	case GEN_startloopAddrsCoarseOffset:	// 45
		startloopAddrsCoarseOffset = static_cast<UShort>(genAmount);
		break;
	case GEN_keynum:						// 46
		keynum = static_cast<UShort>(genAmount);
		break;
	case GEN_velocity:						// 47
		velocity = static_cast<UShort>(genAmount);
		break;
	case GEN_initialAttenuation:			// 48
		initialAttenuation = static_cast<UShort>(genAmount);
		break;
	case GEN_reserved2:						// 49
		reserved2 = static_cast<UShort>(genAmount);
		break;
	case GEN_endloopAddrsCoarseOffset:		// 50
		endloopAddrsCoarseOffset = static_cast<UShort>(genAmount);
		break;
	case GEN_coarseTune:					// 51
		coarseTune = static_cast<Short>(genAmount);
		break;
	case GEN_fineTune:						// 52
		fineTune = static_cast<Short>(genAmount);
		break;
	case GEN_sampleID:						// 53
		sampleID = static_cast<UShort>(genAmount);
		break;
	case GEN_sampleModes:					// 54
		sampleModes = static_cast<UShort>(genAmount);
		break;
	case GEN_reserved3:						// 55
		reserved3 = static_cast<UShort>(genAmount);
		break;
	case GEN_scaleTuning:					// 56
		scaleTuning = static_cast<UShort>(genAmount);
		break;
	case GEN_exclusiveClass:				// 57
		exclusiveClass = static_cast<UShort>(genAmount);
		break;
	case GEN_overridingRootKey:				// 58
		overridingRootKey = static_cast<UShort>(genAmount);
		break;
	case GEN_unused5:						// 59
		unused5 = static_cast<UShort>(genAmount);
		break;
	case GEN_endOper:						// 60
		endOper = static_cast<UShort>(genAmount);
		break;
	default:
		break;
	}
	return true;
}

}}
