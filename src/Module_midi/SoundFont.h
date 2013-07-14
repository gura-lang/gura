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
	class sfVersionTagOwner;
	class sfPresetHeader;
	class sfPresetHeaderOwner;
	class sfPresetBag;
	class sfPresetBagOwner;
	class sfMod;
	class sfModOwner;
	class sfGen;
	class sfGenOwner;
	class sfInst;
	class sfInstOwner;
	class sfInstBag;
	class sfInstBagOwner;
	class sfInstMod;
	class sfInstModOwner;
	class sfInstGen;
	class sfInstGenOwner;
	class sfSample;
	class sfSampleOwner;
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
		sfVersionTag();
		sfVersionTag(const RawData &rawData);
	private:
		inline ~sfVersionTag() {}
	public:
		void Print() const;
	};
	typedef ListTemplate<sfVersionTag> sfVersionTagList;
	class sfVersionTagOwner : public OwnerTemplate<sfVersionTag, sfVersionTagList> {
	};
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
		std::auto_ptr<sfPresetBagOwner> _pPresetBagOwner;
	public:
		Gura_DeclareReferenceAccessor(sfPresetHeader);
	public:
		sfPresetHeader();
		sfPresetHeader(const RawData &rawData);
	private:
		inline ~sfPresetHeader() {}
	public:
		void Print() const;
		bool SetupReference(Signal sig, sfPresetHeader *pPresetHeaderNext,
												const sfPresetBagOwner &pbags);
		inline sfPresetBagOwner &GetPresetBagOwner() { return *_pPresetBagOwner; }
	};
	typedef ListTemplate<sfPresetHeader> sfPresetHeaderList;
	class sfPresetHeaderOwner : public OwnerTemplate<sfPresetHeader, sfPresetHeaderList> {
	};
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
		std::auto_ptr<sfGenOwner> _pGenOwner;
		std::auto_ptr<sfModOwner> _pModOwner;
	public:
		Gura_DeclareReferenceAccessor(sfPresetBag);
	public:
		sfPresetBag();
		sfPresetBag(const RawData &rawData);
	private:
		inline ~sfPresetBag() {}
	public:
		void Print() const;
		bool SetupReference(Signal sig, sfPresetBag *pPresetBagNext,
							const sfModOwner &pmods, const sfGenOwner &pgens);
		inline sfGenOwner &GetGenOwner() { return *_pGenOwner; }
		inline sfModOwner &GetModOwner() { return *_pModOwner; }
	};
	typedef ListTemplate<sfPresetBag> sfPresetBagList;
	class sfPresetBagOwner : public OwnerTemplate<sfPresetBag, sfPresetBagList> {
	};
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
		sfMod();
		sfMod(const RawData &rawData);
	private:
		inline ~sfMod() {}
	public:
		void Print() const;
	};
	typedef ListTemplate<sfMod> sfModList;
	class sfModOwner : public OwnerTemplate<sfMod, sfModList> {
	};
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
		sfGen();
		sfGen(const RawData &rawData);
	private:
		inline ~sfGen() {}
	public:
		void Print() const;
	};
	typedef ListTemplate<sfGen> sfGenList;
	class sfGenOwner : public OwnerTemplate<sfGen, sfGenList> {
	};
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
		std::auto_ptr<sfInstBagOwner> _pInstBagOwner;
	public:
		Gura_DeclareReferenceAccessor(sfInst);
	public:
		sfInst();
		sfInst(const RawData &rawData);
	private:
		inline ~sfInst() {}
	public:
		inline sfInstBagOwner &GetInstBagOwner() { return *_pInstBagOwner; }
		void Print() const;
		bool SetupReference(Signal sig, sfInst *pInstNext,
										const sfInstBagOwner &ibags);
	};
	typedef ListTemplate<sfInst> sfInstList;
	class sfInstOwner : public OwnerTemplate<sfInst, sfInstList> {
	};
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
		std::auto_ptr<sfInstGenOwner> _pInstGenOwner;
		std::auto_ptr<sfInstModOwner> _pInstModOwner;
	public:
		Gura_DeclareReferenceAccessor(sfInstBag);
	public:
		sfInstBag();
		sfInstBag(const RawData &rawData);
	private:
		inline ~sfInstBag() {}
	public:
		inline sfInstGenOwner &GetInstGenOwner() { return *_pInstGenOwner; }
		inline sfInstModOwner &GetInstModOwner() { return *_pInstModOwner; }
		void Print() const;
		bool SetupReference(Signal sig, sfInstBag *pInstBagNext,
						const sfInstModOwner &imods, const sfInstGenOwner &igens);
	};
	typedef ListTemplate<sfInstBag> sfInstBagList;
	class sfInstBagOwner : public OwnerTemplate<sfInstBag, sfInstBagList> {
	};
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
		sfInstMod();
		sfInstMod(const RawData &rawData);
	private:
		inline ~sfInstMod() {}
	public:
		void Print() const;
	};
	typedef ListTemplate<sfInstMod> sfInstModList;
	class sfInstModOwner : public OwnerTemplate<sfInstMod, sfInstModList> {
	};
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
		sfInstGen();
		sfInstGen(const RawData &rawData);
	private:
		inline ~sfInstGen() {}
	public:
		void Print() const;
	};
	typedef ListTemplate<sfInstGen> sfInstGenList;
	class sfInstGenOwner : public OwnerTemplate<sfInstGen, sfInstGenList> {
	};
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
		sfSample();
		sfSample(const RawData &rawData);
	private:
		inline ~sfSample() {}
	public:
		void Print() const;
	};
	typedef ListTemplate<sfSample> sfSampleList;
	class sfSampleOwner : public OwnerTemplate<sfSample, sfSampleList> {
	};
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
		sfInstModOwner			imods;
		sfInstGenOwner			igens;
		sfSampleOwner			shdrs;
	};
private:
	INFO_t _INFO;
	pdta_t _pdta;
	static const char *_generatorNames[];
public:
	void Clear();
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
