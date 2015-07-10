#ifndef __SOUNDFONT_H__
#define __SOUNDFONT_H__
#include <gura.h>

Gura_BeginModuleScope(midi)

template<typename T_Elem>
class ListTemplate : public std::vector<T_Elem *> {
public:
	T_Elem *Get(size_t idx) {
		return (idx < this->size())? (*this)[idx] : nullptr;
	}
	void Print(int indentLevel) const {
		for (typename ListTemplate::const_iterator ppElem = this->begin();
										ppElem != this->end(); ppElem++) {
			const T_Elem *pElem = *ppElem;
			pElem->Print(indentLevel);
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
		for (typename OwnerTemplate::iterator ppElem = this->begin();
			 							ppElem != this->end(); ppElem++) {
			T_Elem *pElem = *ppElem;
			T_Elem::Delete(pElem);
		}
		this->clear();
	}
};

#define FOURCC(c1, c2, c3, c4) \
	(static_cast<ULong>(c1) << 0) + (static_cast<ULong>(c2) << 8) + \
	(static_cast<ULong>(c3) << 16) + (static_cast<ULong>(c4) << 24)

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
		SMPL_monoSample					= 1,
		SMPL_rightSample				= 2,
		SMPL_leftSample					= 4,
		SMPL_linkedSample				= 8,
		SMPL_RomMonoSample				= 0x8001,
		SMPL_RomRightSample				= 0x8002,
		SMPL_RomLeftSample				= 0x8004,
		SMPL_RomLinkedSample			= 0x8008,
	};
	enum SFGenerator {
		GEN_startAddrsOffset			= 0,	// Sample Generator (undefined)
		GEN_endAddrsOffset				= 1,	// Sample Generator (undefined)
		GEN_startloopAddrsOffset		= 2,	// Sample Generator (undefined)
		GEN_endloopAddrsOffset			= 3,	// Sample Generator (undefined)
		GEN_startAddrsCoarseOffset		= 4,	// Sample Generator (undefined)
		GEN_modLfoToPitch				= 5,
		GEN_vibLfoToPitch				= 6,
		GEN_modEnvToPitch				= 7,
		GEN_initialFilterFc				= 8,
		GEN_initiflFilterQ				= 9,
		GEN_modLfoToFilterFc			= 10,
		GEN_modEnvToFilterFc			= 11,
		GEN_endAddrsCoarseOffset		= 12,	// Sample Generator (undefined)
		GEN_modLfoToVolume				= 13,
		GEN_unnsed1						= 14,
		GEN_chorusEffectsSend			= 15,
		GEN_reverbEffectsSend			= 16,
		GEN_pan							= 17,
		GEN_unused2						= 18,
		GEN_unused3						= 19,
		GEN_unused4						= 20,
		GEN_delayModLFO					= 21,
		GEN_freqModLFO					= 22,
		GEN_delayVibLFO					= 23,
		GEN_freqVibLFO					= 24,
		GEN_delayModEnv					= 25,
		GEN_attackModEnv				= 26,
		GEN_holdModEnv					= 27,
		GEN_decayModEnv					= 28,
		GEN_sustainModEnv				= 29,
		GEN_releaseModEnv				= 30,
		GEN_keynumToModEnvHold			= 31,
		GEN_keynumToModEnvDecay			= 32,
		GEN_delayVolEnv					= 33,
		GEN_attackVolEnv				= 34,
		GEN_holdVolEnv					= 35,
		GEN_decayVolEnv					= 36,
		GEN_sustainVolEnv				= 37,
		GEN_releaseVolEnv				= 38,
		GEN_keynumToVolEnvHold			= 39,
		GEN_keynumToVolEnvDecay			= 40,
		GEN_instrument					= 41,	// Index Generator
		GEN_reserved1					= 42,
		GEN_keyRange					= 43,	// Range Generator
		GEN_velRange					= 44,	// Range Generator
		GEN_startloopAddrsCoarseOffset	= 45,	// Sample Generator (undefined)
		GEN_keynum						= 46,
		GEN_velocity					= 47,
		GEN_initialAttenuation			= 48,
		GEN_reserved2					= 49,
		GEN_endloopAddrsCoarseOffset	= 50,	// Sample Generator (undefined)
		GEN_coarseTune					= 51,
		GEN_fineTune					= 52,
		GEN_sampleID					= 53,	// Index Generator
		GEN_sampleModes					= 54,	// Sample Generator (undefined)
		GEN_reserved3					= 55,
		GEN_scaleTuning					= 56,
		GEN_exclusiveClass				= 57,	// Sample Generator (undefined)
		GEN_overridingRootKey			= 58,	// Sample Generator (undefined)
		GEN_unused5						= 59,
		GEN_endOper						= 60,
	};
	struct RangesType {
		UChar byLo;
		UChar byHi;
		inline RangesType() : byLo(0), byHi(0) {}
		inline RangesType(UShort genAmount) :
				byLo(static_cast<UChar>(genAmount >> 0)),
				byHi(static_cast<UChar>(genAmount >> 8)) {}
		inline bool IsMatched(UChar value) const {
			return byLo <= value && value <= byHi;
		}
	};
	typedef UShort SFModulator;
	enum SFTransform {
		TRANS_Linear					= 0,
	};
public:
	struct ChunkHdr {
	public:
		enum { Size = 8 };
		Gura_PackedULong_LE(ckID);
		Gura_PackedULong_LE(ckSize);
	public:
		void Print(int indentLevel) const;
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
	class sfSample;
	class sfSampleOwner;
	class Synthesizer;
	struct INFO_t;
	struct pdta_t;
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
		UShort _wMajor;
		UShort _wMinor;
	public:
		Gura_DeclareReferenceAccessor(sfVersionTag);
	public:
		sfVersionTag();
		sfVersionTag(const RawData &rawData);
	private:
		inline ~sfVersionTag() {}
	public:
		void Print(int indentLevel) const;
	};
	typedef ListTemplate<sfVersionTag> sfVersionTagList;
	class sfVersionTagOwner : public OwnerTemplate<sfVersionTag, sfVersionTagList> {
	};
	// [Relationship between sf-classes]
	//                  +--------------------+
	//                  | 7.2 sfPresetHeader |
	//                  +----------*---------+
	//                             |1..
	// +---------------------------+-----------------------------+
	// |                    7.3 sfPresetBag                      |
	// +--------*-------------------*-------------------*--------+
	//          |0..                |1..                |0..1
	// +--------+--------+ +--------+--------+ +--------+--------+
	// |   7.4 sfMod     | |   7.5 sfGen     | |    7.6 sfInst   |
	// +-----------------+ +-----------------+ +--------*--------+
	//                                                  |1..
	// +------------------------------------------------+--------+
	// |                     7.7 sfInstBag                       |
	// +--------*-------------------*-------------------*--------+
	//          |0..                |0..                |0..1
	// +--------+--------+ +--------+--------+ +--------+--------+
	// |   7.8 sfMod     | |    7.9 sfMod    | |  7.10 sfSample  |
	// +-----------------+ +-----------------+ +-----------------+
	// 7.2 The PHDR Sub-chunk
	class sfPresetHeader {
	public:
		struct RawData {
			enum { Size = 38 };
			char achPresetName[20];
			Gura_PackedUShort_LE(wPreset);
			Gura_PackedUShort_LE(wBank);
			Gura_PackedUShort_LE(wPresetBagNdx);
			Gura_PackedULong_LE(dwLibrary);			// (reserved)
			Gura_PackedULong_LE(dwGenre);			// (reserved)
			Gura_PackedULong_LE(dwMorphology);		// (reserved)
		};
	private:
		int _cntRef;
		char _achPresetName[20];
		UShort _wPreset;
		UShort _wBank;
		UShort _wPresetBagNdx;
		ULong _dwLibrary;
		ULong _dwGenre;
		ULong _dwMorphology;
		std::unique_ptr<sfPresetBagOwner> _pPresetBagOwner;
	public:
		Gura_DeclareReferenceAccessor(sfPresetHeader);
	public:
		sfPresetHeader();
		sfPresetHeader(const RawData &rawData);
	private:
		inline ~sfPresetHeader() {}
	public:
		void Print(int indentLevel) const;
		bool SetupReference(Signal &sig, sfPresetHeader *pPresetHeaderNext, const pdta_t &pdta);
		inline bool IsMatched(UShort wPreset, UShort wBank) const {
			return wPreset == _wPreset && wBank == _wBank;
		}
		inline sfPresetBagOwner &GetPresetBagOwner() { return *_pPresetBagOwner; }
		inline const sfPresetBagOwner &GetPresetBagOwner() const { return *_pPresetBagOwner; }
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
		UShort _wGenNdx;
		UShort _wModNdx;
		std::unique_ptr<sfGenOwner> _pGenOwner;
		std::unique_ptr<sfModOwner> _pModOwner;
		AutoPtr<sfInst> _pInst; 				// valid only when instrument generator exists in sfGenOwner
	public:
		Gura_DeclareReferenceAccessor(sfPresetBag);
	public:
		sfPresetBag();
		sfPresetBag(const RawData &rawData);
	private:
		inline ~sfPresetBag() {}
	public:
		void Print(int indentLevel) const;
		bool SetupReference(Signal &sig, sfPresetBag *pPresetBagNext, const pdta_t &pdta);
		inline sfGenOwner &GetGenOwner() { return *_pGenOwner; }
		inline sfModOwner &GetModOwner() { return *_pModOwner; }
		inline const sfGenOwner &GetGenOwner() const { return *_pGenOwner; }
		inline const sfModOwner &GetModOwner() const { return *_pModOwner; }
		inline sfInst *GetInst() { return _pInst.get(); }
		inline const sfInst *GetInst() const { return _pInst.get(); }
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
		void Print(int indentLevel) const;
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
		UShort _genAmount;
	public:
		Gura_DeclareReferenceAccessor(sfGen);
	public:
		sfGen();
		sfGen(const RawData &rawData);
	private:
		inline ~sfGen() {}
	public:
		void Print(int indentLevel) const;
		inline SFGenerator GetGenOper() const { return _sfGenOper; }
		inline UShort GetGenAmount() const { return _genAmount; }
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
		UShort _wInstBagNdx;
		std::unique_ptr<sfInstBagOwner> _pInstBagOwner;
	public:
		Gura_DeclareReferenceAccessor(sfInst);
	public:
		sfInst();
		sfInst(const RawData &rawData);
	private:
		inline ~sfInst() {}
	public:
		inline sfInstBagOwner &GetInstBagOwner() { return *_pInstBagOwner; }
		inline const sfInstBagOwner &GetInstBagOwner() const { return *_pInstBagOwner; }
		void Print(int indentLevel) const;
		bool SetupReference(Signal &sig, sfInst *pInstNext, const pdta_t &pdta);
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
		UShort _wInstGenNdx;
		UShort _wInstModNdx;
		std::unique_ptr<sfGenOwner> _pInstGenOwner;
		std::unique_ptr<sfModOwner> _pInstModOwner;
		std::unique_ptr<RangesType> _pKeyRange;	// valid only when keyRange generator exists in sfGenOwner
		std::unique_ptr<RangesType> _pVelRange;	// valid only when velRange generator exists in sfGenOwner
	public:
		Gura_DeclareReferenceAccessor(sfInstBag);
	public:
		sfInstBag();
		sfInstBag(const RawData &rawData);
	private:
		inline ~sfInstBag() {}
	public:
		inline bool IsMatched(UChar key, UChar velocity) const {
			return
				(_pKeyRange.get() == nullptr || _pKeyRange->IsMatched(key)) &&
				(_pVelRange.get() == nullptr || _pVelRange->IsMatched(velocity));
		}
		inline sfGenOwner &GetInstGenOwner() { return *_pInstGenOwner; }
		inline sfModOwner &GetInstModOwner() { return *_pInstModOwner; }
		inline const sfGenOwner &GetInstGenOwner() const { return *_pInstGenOwner; }
		inline const sfModOwner &GetInstModOwner() const { return *_pInstModOwner; }
		inline RangesType *GetKeyRange() { return _pKeyRange.get(); }
		inline const RangesType *GetKeyRange() const { return _pKeyRange.get(); }
		inline RangesType *GetVelRange() { return _pVelRange.get(); }
		inline const RangesType *GetVelRange() const { return _pVelRange.get(); }
		void Print(int indentLevel) const;
		bool SetupReference(Signal &sig, sfInstBag *pInstBagNext, const pdta_t &pdta);
	};
	typedef ListTemplate<sfInstBag> sfInstBagList;
	class sfInstBagOwner : public OwnerTemplate<sfInstBag, sfInstBagList> {
	};
	// 7.8 The IMOD Sub-chunk
	// 7.9 The IGEN Sub-chunk
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
			UChar byOriginalKey;
			char chCorrection;
			Gura_PackedUShort_LE(wSampleLink);
			Gura_PackedUShort_LE(sfSampleType);
		};
	private:
		int _cntRef;
		char _achSampleName[20];
		ULong _dwStart;
		ULong _dwEnd;
		ULong _dwStartloop;
		ULong _dwEndloop;
		ULong _dwSampleRate;
		UChar _byOriginalKey;
		char _chCorrection;
		UShort _wSampleLink;
		SFSampleLink _sfSampleType;
		AutoPtr<Audio> _pAudio;
	public:
		Gura_DeclareReferenceAccessor(sfSample);
	public:
		sfSample();
		sfSample(const RawData &rawData);
	private:
		inline ~sfSample() {}
	public:
		bool CreateAudio(Signal &sig, Stream &stream, size_t offsetSdta);
		inline const Audio *GetAudio() const { return _pAudio.get(); }
		void Print(int indentLevel) const;
	};
	typedef ListTemplate<sfSample> sfSampleList;
	class sfSampleOwner : public OwnerTemplate<sfSample, sfSampleList> {
	};
public:
	class Synthesizer {
	public:
		struct Props {
			UShort startAddrsOffset;			// 0
			UShort endAddrsOffset;				// 1
			UShort startloopAddrsOffset;		// 2
			UShort endloopAddrsOffset;			// 3
			UShort startAddrsCoarseOffset;		// 4
			Short modLfoToPitch;				// 5
			Short vibLfoToPitch;				// 6
			Short modEnvToPitch;				// 7
			Short initialFilterFc;				// 8
			Short initiflFilterQ;				// 9
			Short modLfoToFilterFc;				// 10
			Short modEnvToFilterFc;				// 11
			UShort endAddrsCoarseOffset;		// 12
			Short modLfoToVolume;				// 13
			UShort unnsed1;						// 14
			UShort chorusEffectsSend;			// 15
			UShort reverbEffectsSend;			// 16
			Short pan;							// 17
			UShort unused2;						// 18
			UShort unused3;						// 19
			UShort unused4;						// 20
			Short delayModLFO;					// 21
			Short freqModLFO;					// 22
			Short delayVibLFO;					// 23
			Short freqVibLFO;					// 24
			Short delayModEnv;					// 25
			Short attackModEnv;					// 26
			Short holdModEnv;					// 27
			Short decayModEnv;					// 28
			Short sustainModEnv;				// 29
			Short releaseModEnv;				// 30
			Short keynumToModEnvHold;			// 31
			Short keynumToModEnvDecay;			// 32
			Short delayVolEnv;					// 33
			Short attackVolEnv;					// 34
			Short holdVolEnv;					// 35
			Short decayVolEnv;					// 36
			Short sustainVolEnv;				// 37
			Short releaseVolEnv;				// 38
			Short keynumToVolEnvHold;			// 39
			Short keynumToVolEnvDecay;			// 40
			UShort instrument;					// 41
			UShort reserved1;					// 42
			RangesType keyRange;				// 43
			RangesType velRange;				// 44
			UShort startloopAddrsCoarseOffset;	// 45
			UShort keynum;						// 46
			UShort velocity;					// 47
			UShort initialAttenuation;			// 48
			UShort reserved2;					// 49
			UShort endloopAddrsCoarseOffset;	// 50
			Short coarseTune;					// 51
			Short fineTune;						// 52
			UShort sampleID;					// 53
			UShort sampleModes;					// 54
			UShort reserved3;					// 55
			UShort scaleTuning;					// 56
			UShort exclusiveClass;				// 57
			UShort overridingRootKey;			// 58
			UShort unused5;						// 59
			UShort endOper;						// 60
			void Reset();
			bool Update(SFGenerator sfGenOper, UShort genAmount);
		};
	private:
		int _cntRef;
		Props _props;
		std::unique_ptr<sfModOwner> _pModOwner;
		AutoPtr<sfSample> _pSample;
	public:
		Gura_DeclareReferenceAccessor(Synthesizer);
	public:
		Synthesizer();
		inline Props &GetProps() { return _props; }
		inline const Props &GetProps() const { return _props; }
		inline sfModOwner &GetModOwner() { return *_pModOwner; }
		inline const sfModOwner &GetModOwner() const { return *_pModOwner; }
		inline void SetSample(sfSample *pSample) { _pSample.reset(pSample); }
		inline sfSample *GetSample() const { return _pSample.get(); }
	};
public:
	struct INFO_t {
		AutoPtr<sfVersionTag>	p_ifil;	// mandatory
		std::unique_ptr<String>	p_isng;	// mandatory
		std::unique_ptr<String>	p_INAM;	// mandatory
		std::unique_ptr<String>	p_irom;	// optional
		AutoPtr<sfVersionTag> 	p_iver;	// optional
		std::unique_ptr<String>	p_ICRD;	// optional
		std::unique_ptr<String>	p_IENG;	// optional
		std::unique_ptr<String>	p_IPRD;	// optional
		std::unique_ptr<String>	p_ICOP;	// optional
		std::unique_ptr<String>	p_ICMT;	// optional
		std::unique_ptr<String>	p_ISFT;	// optional
	};
	struct pdta_t {
		sfPresetHeaderOwner		phdrs;
		sfPresetBagOwner		pbags;
		sfModOwner				pmods;
		sfGenOwner				pgens;
		sfInstOwner				insts;
		sfInstBagOwner			ibags;
		sfModOwner				imods;
		sfGenOwner				igens;
		sfSampleOwner			shdrs;
	};
private:
	AutoPtr<Stream> _pStream;
	INFO_t _INFO;
	size_t _offsetSdta;
	pdta_t _pdta;
	static const char *_generatorNames[];
public:
	SoundFont(Stream *pStream);
	void Clear();
	bool ReadChunks(Environment &env, Signal &sig);
	const sfPresetHeader *LookupPresetHeader(UShort wPreset, UShort wBank) const;
	Synthesizer *CreateSynthesizer(Signal &sig, UShort wPreset, UShort wBank, UChar key, UChar velocity) const;
	void Print() const;
	inline INFO_t &GetINFO() { return _INFO; }
	inline pdta_t &GetPdta() { return _pdta; }
	inline const INFO_t &GetINFO() const { return _INFO; }
	inline const pdta_t &GetPdta() const { return _pdta; }
public:
	static const char *SFGeneratorToName(SFGenerator generator);
private:
	bool ReadSubChunk(Environment &env, Signal &sig, size_t bytes);
	bool ReadStruct(Environment &env, Signal &sig,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual);
	bool ReadString(Environment &env, Signal &sig,
						char *str, size_t ckSizeMax, size_t ckSizeActual);
};

Gura_EndModuleScope(midi)

#endif
