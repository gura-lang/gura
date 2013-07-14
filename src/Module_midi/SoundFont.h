#ifndef __SOUNDFONT_H__
#define __SOUNDFONT_H__
#include <gura.h>

Gura_BeginModule(midi)

template<typename T_Elem>
class ListTemplate : public std::vector<T_Elem *> {
public:
	T_Elem *Get(size_t idx) {
		return (idx < size())? (*this)[idx] : NULL;
	}
	void Print() const {
		foreach_const (ListTemplate, ppElem, *this) {
			const T_Elem *pElem = *ppElem;
			pElem->Print();
		}
	}
};

template<typename T_Elem, typename T_List>
class OwnerTemplate : public T_List {
public:
	virtual ~OwnerTemplate() {
		Clear();
	}
	void Clear() {
		foreach (OwnerTemplate, ppElem, *this) {
			T_Elem *pElem = *ppElem;
			T_Elem::Delete(pElem);
		}
		clear();
	}
};

#define FOURCC(c1, c2, c3, c4) \
	(static_cast<unsigned long>(c1) << 0) + (static_cast<unsigned long>(c2) << 8) + \
	(static_cast<unsigned long>(c3) << 16) + (static_cast<unsigned long>(c4) << 24)

class SoundFont {
public:
	enum {
		CKID_RIFF = FOURCC('R', 'I', 'F', 'F'),
		CKID_LIST = FOURCC('L', 'I', 'S', 'T'),
		CKID_ifil = FOURCC('i', 'f', 'i', 'l'),
		CKID_isng = FOURCC('i', 's', 'n', 'g'),
		CKID_INAM = FOURCC('I', 'N', 'A', 'M'),
		CKID_irom = FOURCC('i', 'r', 'o', 'm'),
		CKID_iver = FOURCC('i', 'v', 'e', 'r'),
		CKID_ICRD = FOURCC('I', 'C', 'R', 'D'),
		CKID_IENG = FOURCC('I', 'E', 'N', 'G'),
		CKID_IPRD = FOURCC('I', 'P', 'R', 'D'),
		CKID_ICOP = FOURCC('I', 'C', 'O', 'P'),
		CKID_ICMT = FOURCC('I', 'C', 'M', 'T'),
		CKID_ISFT = FOURCC('I', 'S', 'F', 'T'),
		CKID_smpl = FOURCC('s', 'm', 'p', 'l'),
		CKID_phdr = FOURCC('p', 'h', 'd', 'r'),
		CKID_pbag = FOURCC('p', 'b', 'a', 'g'),
		CKID_pmod = FOURCC('p', 'm', 'o', 'd'),
		CKID_pgen = FOURCC('p', 'g', 'e', 'n'),
		CKID_inst = FOURCC('i', 'n', 's', 't'),
		CKID_ibag = FOURCC('i', 'b', 'a', 'g'),
		CKID_imod = FOURCC('i', 'm', 'o', 'd'),
		CKID_igen = FOURCC('i', 'g', 'e', 'n'),
		CKID_shdr = FOURCC('s', 'h', 'd', 'r'),
	};
public:
	enum SFSampleLink {
		monoSample		= 1,
		rightSample		= 2,
		leftSample		= 4,
		linkedSample	= 8,
		RomMonoSample	= 0x8001,
		RomRightSample	= 0x8002,
		RomLeftSample	= 0x8004,
		RomLinkedSample	= 0x8008,
	};
	enum SFGenerator {
		startAddrsOffset			= 0,
		endAddrsOffset				= 1,
		startloopAddrsOffset		= 2,
		endloopAddrsOffset			= 3,
		startAddrsCoarseOffset		= 4,
		modLfoToPitch				= 5,
		vibLfoToPitch				= 6,
		modEnvToPitch				= 7,
		initialFilterFc				= 8,
		initiflFilterQ				= 9,
		modLfoToFilterFc			= 10,
		modEnvToFilterFc			= 11,
		endAddrsCoarseOffset		= 12,
		modLfoToVolume				= 13,
		//unnsed1					= 14,
		chorusEffectsSend			= 15,
		reverbEffectsSend			= 16,
		pan							= 17,
		//unused2					= 18,
		//unused3					= 19,
		//unused4					= 20,
		delayModLFO					= 21,
		freqModLFO					= 22,
		delayVibLFO					= 23,
		freqVibLFO					= 24,
		delayModEnv					= 25,
		attackModEnv				= 26,
		holdModEnv					= 27,
		delayModENv					= 28,
		sustainModEnv				= 29,
		releaseModEnv				= 30,
		keynumToModEnvHold			= 31,
		keynumToModEnvDecay			= 32,
		delayVolEnv					= 33,
		attackVolEnv				= 34,
		holdVolEnv					= 35,
		decayVolENv					= 36,
		sustainVolEnv				= 37,
		releaseVolEnv				= 38,
		keynumToVolEnvHold			= 39,
		keynumToVolEnvDecay			= 40,
		instrument					= 41,
		//reserved1					= 42,
		keyRange					= 43,
		velRange					= 44,
		startloopAddrsCoarseOffset	= 45,
		keynum						= 46,
		velocity					= 47,
		initialAttenuation			= 48,
		//reserved2					= 49,
		endloopAddrsCoarseOffset	= 50,
		coarseTune					= 51,
		fineTune					= 52,
		sampleID					= 53,
		sampleModes					= 54,
		//reserved3					= 55,
		scaleTuning					= 56,
		exclusiveClass				= 57,
		overridingRootKey			= 58,
		//unused5					= 59,
		endOper						= 60,
	};
	typedef unsigned short SFModulator;
	enum SFTransform {
		Linear						= 0,
	};
public:
	struct ChunkHdr {
	public:
		enum { Size = 8 };
		Gura_PackedULong_LE(ckID);
		Gura_PackedULong_LE(ckSize);
	public:
		void Print() const {
			unsigned long ckID = Gura_UnpackULong(ckID);
			unsigned long ckSize = Gura_UnpackULong(ckSize);
			::printf("<%c%c%c%c-ck> %dbytes\n",
					static_cast<unsigned char>(ckID >> 0),
					static_cast<unsigned char>(ckID >> 8),
					static_cast<unsigned char>(ckID >> 16),
					static_cast<unsigned char>(ckID >> 24), ckSize);
		}
	};
	class sfVersionTag;
	class sfPresetHeader;
	class sfPresetBag;
	class sfMod;
	class sfGen;
	class sfInst;
	class sfInstBag;
	class sfInstMod;
	class sfInstGen;
	class sfSample;
	// 5.1 The ifil Sub-chunk
	// 5.5 The iver Sub-chunk
	class sfVersionTag {
	public:
		struct RawData {
			enum { Size = 4 };
			Gura_PackedUShort_LE(wMajor);
			Gura_PackedUShort_LE(wMinor);
		};
	private:
		int _cntRef;
		unsigned short _wMajor;
		unsigned short _wMinor;
	public:
		Gura_DeclareReferenceAccessor(sfVersionTag);
	public:
		inline sfVersionTag() : _cntRef(1),
				_wMajor(0),
				_wMinor(0) {}
		inline sfVersionTag(const RawData &rawData) : _cntRef(1),
				_wMajor(Gura_UnpackUShort(rawData.wMajor)),
				_wMinor(Gura_UnpackUShort(rawData.wMinor)) {}
	private:
		inline ~sfVersionTag() {}
	public:
		inline void Print() const {
			::printf("wMajor=%d wMinor=%d\n",
				_wMajor,
				_wMinor);
			}
	};
	typedef ListTemplate<sfVersionTag> sfVersionTagList;
	typedef OwnerTemplate<sfVersionTag, sfVersionTagList> sfVersionTagOwner;
	// 7.2 The PHDR Sub-chunk
	class sfPresetHeader {
	public:
		struct RawData {
			enum { Size = 38 };
			char achPresetName[20];
			Gura_PackedUShort_LE(wPreset);
			Gura_PackedUShort_LE(wBank);
			Gura_PackedUShort_LE(wPresetBagNdx);
			Gura_PackedULong_LE(dwLibrary);
			Gura_PackedULong_LE(dwGenre);
			Gura_PackedULong_LE(dwMorphology);
		};
	private:
		int _cntRef;
		char _achPresetName[20];
		unsigned short _wPreset;
		unsigned short _wBank;
		unsigned short _wPresetBagNdx;
		unsigned long _dwLibrary;
		unsigned long _dwGenre;
		unsigned long _dwMorphology;
	public:
		Gura_DeclareReferenceAccessor(sfPresetHeader);
	public:
		inline sfPresetHeader() : _cntRef(1),
				_wPreset(0),
				_wBank(0),
				_wPresetBagNdx(0),
				_dwLibrary(0),
				_dwGenre(0),
				_dwMorphology(0) {
			::memset(_achPresetName, 0x00, sizeof(_achPresetName));
		}
		inline sfPresetHeader(const RawData &rawData) : _cntRef(1),
				_wPreset(Gura_UnpackUShort(rawData.wPreset)),
				_wBank(Gura_UnpackUShort(rawData.wBank)),
				_wPresetBagNdx(Gura_UnpackUShort(rawData.wPresetBagNdx)),
				_dwLibrary(Gura_UnpackULong(rawData.dwLibrary)),
				_dwGenre(Gura_UnpackULong(rawData.dwGenre)),
				_dwMorphology(Gura_UnpackULong(rawData.dwMorphology)) {
			::memcpy(_achPresetName, rawData.achPresetName, sizeof(_achPresetName));
		}
	private:
		inline ~sfPresetHeader() {}
	public:
		inline void Print() const {
			::printf("achPresetName=\"%s\" wPreset=%d wBank=%d wPresetBagNdx=%d dwLibrary=%d dwGenre=%d dwMorphology=%d\n",
				_achPresetName,
				_wPreset,
				_wBank,
				_wPresetBagNdx,
				_dwLibrary,
				_dwGenre,
				_dwMorphology);
		}
		sfPresetBag *GetPresetBag(SoundFont &soundFont) const;
	};
	typedef ListTemplate<sfPresetHeader> sfPresetHeaderList;
	typedef OwnerTemplate<sfPresetHeader, sfPresetHeaderList> sfPresetHeaderOwner;
	// 7.3 The PBAG Sub-chunk
	class sfPresetBag {
	public:
		struct RawData {
			enum { Size = 4 };
			Gura_PackedUShort_LE(wGenNdx);
			Gura_PackedUShort_LE(wModNdx);
		};
	private:
		int _cntRef;
		unsigned short _wGenNdx;
		unsigned short _wModNdx;
	public:
		Gura_DeclareReferenceAccessor(sfPresetBag);
	public:
		inline sfPresetBag() : _cntRef(1),
				_wGenNdx(0),
				_wModNdx(0) {}
		inline sfPresetBag(const RawData &rawData) : _cntRef(1),
				_wGenNdx(Gura_UnpackUShort(rawData.wGenNdx)),
				_wModNdx(Gura_UnpackUShort(rawData.wModNdx)) {}
	private:
		inline ~sfPresetBag() {}
	public:
		inline void Print() const {
			::printf("wGenNdx=%d wModNdx=%d\n",
				_wGenNdx,
				_wModNdx);
		}
		sfGen *GetGen(SoundFont &soundFont) const;
		sfMod *GetMod(SoundFont &soundFont) const;
	};
	typedef ListTemplate<sfPresetBag> sfPresetBagList;
	typedef OwnerTemplate<sfPresetBag, sfPresetBagList> sfPresetBagOwner;
	// 7.4 The PMOD Sub-chunk
	class sfMod {
	public:
		struct RawData {
			enum { Size = 10 };
			Gura_PackedUShort_LE(sfModSrcOper);
			Gura_PackedUShort_LE(sfModDestOper);
			Gura_PackedUShort_LE(modAmount);
			Gura_PackedUShort_LE(sfModAmtSrcOper);
			Gura_PackedUShort_LE(sfModTransOper);
		};
	private:
		int _cntRef;
		SFModulator _sfModSrcOper;
		SFGenerator _sfModDestOper;
		short _modAmount;
		SFModulator _sfModAmtSrcOper;
		SFTransform _sfModTransOper;
	public:
		Gura_DeclareReferenceAccessor(sfMod);
	public:
		inline sfMod() : _cntRef(1),
				_sfModSrcOper(static_cast<SFModulator>(0)),
				_sfModDestOper(static_cast<SFGenerator>(0)),
				_modAmount(0),
				_sfModAmtSrcOper(static_cast<SFModulator>(0)),
				_sfModTransOper(static_cast<SFTransform>(0)) {}
		inline sfMod(const RawData &rawData) : _cntRef(1),
				_sfModSrcOper(static_cast<SFModulator>(Gura_UnpackUShort(rawData.sfModSrcOper))),
				_sfModDestOper(static_cast<SFGenerator>(Gura_UnpackUShort(rawData.sfModDestOper))),
				_modAmount(static_cast<short>(Gura_UnpackUShort(rawData.modAmount))),
				_sfModAmtSrcOper(static_cast<SFModulator>(Gura_UnpackUShort(rawData.sfModAmtSrcOper))),
				_sfModTransOper(static_cast<SFTransform>(Gura_UnpackUShort(rawData.sfModTransOper))) {}
	private:
		inline ~sfMod() {}
	public:
		inline void Print() const {
			::printf("sfModSrcOper=0x%04x sfModDestOper=%s(%d) modAmount=0x%04x sfModAmtSrcOper=0x%04x sfModTransOper=%d\n",
				_sfModSrcOper,
				GeneratorToName(_sfModDestOper), _sfModDestOper,
				_modAmount,
				_sfModAmtSrcOper,
				_sfModTransOper);
		}
	};
	typedef ListTemplate<sfMod> sfModList;
	typedef OwnerTemplate<sfMod, sfModList> sfModOwner;
	// 7.5 The PGEN Sub-chunk
	class sfGen {
	public:
		struct RawData {
			enum { Size = 4 };
			Gura_PackedUShort_LE(sfGenOper);
			Gura_PackedUShort_LE(genAmount);
		};
	private:
		int _cntRef;
		SFGenerator _sfGenOper;
		unsigned short _genAmount;
	public:
		Gura_DeclareReferenceAccessor(sfGen);
	public:
		inline sfGen() : _cntRef(1),
				_sfGenOper(static_cast<SFGenerator>(0)),
				_genAmount(0) {}
		inline sfGen(const RawData &rawData) : _cntRef(1),
				_sfGenOper(static_cast<SFGenerator>(Gura_UnpackUShort(rawData.sfGenOper))),
				_genAmount(Gura_UnpackUShort(rawData.genAmount)) {}
	private:
		inline ~sfGen() {}
	public:
		inline void Print() const {
			::printf("sfGenOper=%s(%d) genAmount=0x%04x\n",
				GeneratorToName(_sfGenOper), _sfGenOper,
				_genAmount);
		}
	};
	typedef ListTemplate<sfGen> sfGenList;
	typedef OwnerTemplate<sfGen, sfGenList> sfGenOwner;
	// 7.6 The INST Sub-chunk
	class sfInst {
	public:
		struct RawData {
			enum { Size = 22 };
			char achInstName[20];
			Gura_PackedUShort_LE(wInstBagNdx);
		};
	private:
		int _cntRef;
		char _achInstName[20];
		unsigned short _wInstBagNdx;
	public:
		Gura_DeclareReferenceAccessor(sfInst);
	public:
		inline sfInst() : _cntRef(1),
				_wInstBagNdx(0) {
			::memset(_achInstName, 0x00, sizeof(_achInstName));
		}
		inline sfInst(const RawData &rawData) : _cntRef(1),
				_wInstBagNdx(Gura_UnpackUShort(rawData.wInstBagNdx)) {
			::memcpy(_achInstName, rawData.achInstName, sizeof(_achInstName));
		}
	private:
		inline ~sfInst() {}
	public:
		inline void Print() const {
			::printf("achInstName=\"%s\" wInstBagNdx=%d\n",
				_achInstName,
				_wInstBagNdx);
		}
	};
	typedef ListTemplate<sfInst> sfInstList;
	typedef OwnerTemplate<sfInst, sfInstList> sfInstOwner;
	// 7.7 The IBAG Sub-chunk
	class sfInstBag {
	public:
		struct RawData {
			enum { Size = 4 };
			Gura_PackedUShort_LE(wInstGenNdx);
			Gura_PackedUShort_LE(wInstModNdx);
		};
	private:
		int _cntRef;
		unsigned short _wInstGenNdx;
		unsigned short _wInstModNdx;
	public:
		Gura_DeclareReferenceAccessor(sfInstBag);
	public:
		inline sfInstBag() : _cntRef(1),
				_wInstGenNdx(0),
				_wInstModNdx(0) {}
		inline sfInstBag(const RawData &rawData) : _cntRef(1),
				_wInstGenNdx(Gura_UnpackUShort(rawData.wInstGenNdx)),
				_wInstModNdx(Gura_UnpackUShort(rawData.wInstModNdx)) {}
	private:
		inline ~sfInstBag() {}
	public:
		inline void Print() const {
			::printf("wInstGenNdx=%d wInstModNdx=%d\n",
				_wInstGenNdx,
				_wInstModNdx);
		}
	};
	typedef ListTemplate<sfInstBag> sfInstBagList;
	typedef OwnerTemplate<sfInstBag, sfInstBagList> sfInstBagOwner;
	// 7.8 The IMOD Sub-chunk
	class sfInstMod {
	public:
		struct RawData {
			enum { Size = 10 };
			Gura_PackedUShort_LE(sfModSrcOper);
			Gura_PackedUShort_LE(sfModDestOper);
			Gura_PackedUShort_LE(modAmount);
			Gura_PackedUShort_LE(sfModAmtSrcOper);
			Gura_PackedUShort_LE(sfModTransOper);
		};
	private:
		int _cntRef;
		SFModulator _sfModSrcOper;
		SFGenerator _sfModDestOper;
		short _modAmount;
		SFModulator _sfModAmtSrcOper;
		SFTransform _sfModTransOper;
	public:
		Gura_DeclareReferenceAccessor(sfInstMod);
	public:
		inline sfInstMod() : _cntRef(1),
				_sfModSrcOper(static_cast<SFModulator>(0)),
				_sfModDestOper(static_cast<SFGenerator>(0)),
				_modAmount(0),
				_sfModAmtSrcOper(static_cast<SFModulator>(0)),
				_sfModTransOper(static_cast<SFTransform>(0)) {}
		inline sfInstMod(const RawData &rawData) : _cntRef(1),
				_sfModSrcOper(static_cast<SFModulator>(Gura_UnpackUShort(rawData.sfModSrcOper))),
				_sfModDestOper(static_cast<SFGenerator>(Gura_UnpackUShort(rawData.sfModDestOper))),
				_modAmount(static_cast<short>(Gura_UnpackUShort(rawData.modAmount))),
				_sfModAmtSrcOper(static_cast<SFModulator>(Gura_UnpackUShort(rawData.sfModAmtSrcOper))),
				_sfModTransOper(static_cast<SFTransform>(Gura_UnpackUShort(rawData.sfModTransOper))) {}
	private:
		inline ~sfInstMod() {}
	public:
		inline void Print() const {
			::printf("sfModSrcOper=0x%04x sfModDestOper=%s(%d) modAmount=0x%04x sfModAmtSrcOper=0x%04x sfModTransOper=%d\n",
				_sfModSrcOper,
				GeneratorToName(_sfModDestOper), _sfModDestOper,
				_modAmount,
				_sfModAmtSrcOper,
				_sfModTransOper);
		}
	};
	typedef ListTemplate<sfInstMod> sfInstModList;
	typedef OwnerTemplate<sfInstMod, sfInstModList> sfInstModOwner;
	// 7.9 The IGEN Sub-chunk
	class sfInstGen {
	public:
		struct RawData {
			enum { Size = 4 };
			Gura_PackedUShort_LE(sfGenOper);
			Gura_PackedUShort_LE(genAmount);
		};
	private:
		int _cntRef;
		SFGenerator _sfGenOper;
		unsigned short _genAmount;
	public:
		Gura_DeclareReferenceAccessor(sfInstGen);
	public:
		inline sfInstGen() : _cntRef(1),
				_sfGenOper(static_cast<SFGenerator>(0)),
				_genAmount(0) {}
		inline sfInstGen(const RawData &rawData) : _cntRef(1),
				_sfGenOper(static_cast<SFGenerator>(Gura_UnpackUShort(rawData.sfGenOper))),
				_genAmount(Gura_UnpackUShort(rawData.genAmount)) {}
	private:
		inline ~sfInstGen() {}
	public:
		inline void Print() const {
			::printf("sfGenOper=%s(%d) genAmount=0x%04x\n",
				GeneratorToName(_sfGenOper), _sfGenOper,
				_genAmount);
		}
	};
	typedef ListTemplate<sfInstGen> sfInstGenList;
	typedef OwnerTemplate<sfInstGen, sfInstGenList> sfInstGenOwner;
	// 7.10 The SHDR Sub-chunk
	class sfSample {
	public:
		struct RawData {
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
		};
	private:
		int _cntRef;
		char _achSampleName[20];
		unsigned long _dwStart;
		unsigned long _dwEnd;
		unsigned long _dwStartloop;
		unsigned long _dwEndloop;
		unsigned long _dwSampleRate;
		unsigned char _byOriginalKey;
		char _chCorrection;
		unsigned short _wSampleLink;
		SFSampleLink _sfSampleType;
	public:
		Gura_DeclareReferenceAccessor(sfSample);
	public:
		inline sfSample() : _cntRef(1),
				_dwStart(0),
				_dwEnd(0),
				_dwStartloop(0),
				_dwEndloop(0),
				_dwSampleRate(0),
				_byOriginalKey(0),
				_chCorrection(0),
				_wSampleLink(0),
				_sfSampleType(static_cast<SFSampleLink>(0)) {
			::memset(_achSampleName, 0x00, sizeof(_achSampleName));
		}
		inline sfSample(const RawData &rawData) : _cntRef(1),
				_dwStart(Gura_UnpackULong(rawData.dwStart)),
				_dwEnd(Gura_UnpackULong(rawData.dwEnd)),
				_dwStartloop(Gura_UnpackULong(rawData.dwStartloop)),
				_dwEndloop(Gura_UnpackULong(rawData.dwEndloop)),
				_dwSampleRate(Gura_UnpackULong(rawData.dwSampleRate)),
				_byOriginalKey(rawData.byOriginalKey),
				_chCorrection(rawData.chCorrection),
				_wSampleLink(Gura_UnpackUShort(rawData.wSampleLink)),
				_sfSampleType(static_cast<SFSampleLink>(Gura_UnpackUShort(rawData.sfSampleType))) {
			::memcpy(_achSampleName, rawData.achSampleName, sizeof(_achSampleName));
		}
	private:
		inline ~sfSample() {}
	public:
		inline void Print() const {
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
	};
	typedef ListTemplate<sfSample> sfSampleList;
	typedef OwnerTemplate<sfSample, sfSampleList> sfSampleOwner;
public:
	struct INFO_t {
		AutoPtr<sfVersionTag>	p_ifil;	// mandatory
		std::auto_ptr<String>	p_isng;	// mandatory
		std::auto_ptr<String>	p_INAM;	// mandatory
		std::auto_ptr<String>	p_irom;	// optional
		AutoPtr<sfVersionTag> 	p_iver;	// optional
		std::auto_ptr<String>	p_ICRD;	// optional
		std::auto_ptr<String>	p_IENG;	// optional
		std::auto_ptr<String>	p_IPRD;	// optional
		std::auto_ptr<String>	p_ICOP;	// optional
		std::auto_ptr<String>	p_ICMT;	// optional
		std::auto_ptr<String>	p_ISFT;	// optional
	};
	struct pdta_t {
		sfPresetHeaderOwner		phdrs;
		sfPresetBagOwner		pbags;
		sfModOwner				pmods;
		sfGenOwner				pgens;
		sfInstOwner				insts;
		sfInstBagOwner			ibags;
		sfModOwner				imods;
		sfInstGenOwner			igens;
		sfSampleOwner			shdrs;
	};
private:
	INFO_t _INFO;
	pdta_t _pdta;
	static const char *_generatorNames[];
public:
	bool Read(Environment &env, Signal sig, Stream &stream);
	void Print() const;
	inline INFO_t &GetINFO() { return _INFO; }
	inline pdta_t &GetPdta() { return _pdta; }
public:
	static const char *GeneratorToName(SFGenerator generator);
private:
	bool ReadSubChunk(Environment &env, Signal sig, Stream &stream, size_t bytes);
	static bool ReadStruct(Environment &env, Signal sig, Stream &stream,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual);
	static bool ReadString(Environment &env, Signal sig, Stream &stream,
						char *str, size_t ckSizeMax, size_t ckSizeActual);
};

}}

#endif
