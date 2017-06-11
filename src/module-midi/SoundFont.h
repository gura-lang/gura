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
		inline RangesType(UInt16 genAmount) :
				byLo(static_cast<UChar>(genAmount >> 0)),
				byHi(static_cast<UChar>(genAmount >> 8)) {}
		inline bool IsMatched(UChar value) const {
			return byLo <= value && value <= byHi;
		}
	};
	typedef UInt16 SFModulator;
	enum SFTransform {
		TRANS_Linear					= 0,
	};
public:
	struct ChunkHdr {
	public:
		enum { Size = 8 };
		Gura_PackedUInt32_LE(ckID);
		Gura_PackedUInt32_LE(ckSize);
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
			Gura_PackedUInt16_LE(wMajor);
			Gura_PackedUInt16_LE(wMinor);
		};
	private:
		int _cntRef;
		UInt16 _wMajor;
		UInt16 _wMinor;
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
			Gura_PackedUInt16_LE(wPreset);
			Gura_PackedUInt16_LE(wBank);
			Gura_PackedUInt16_LE(wPresetBagNdx);
			Gura_PackedUInt32_LE(dwLibrary);			// (reserved)
			Gura_PackedUInt32_LE(dwGenre);			// (reserved)
			Gura_PackedUInt32_LE(dwMorphology);		// (reserved)
		};
	private:
		int _cntRef;
		char _achPresetName[20];
		UInt16 _wPreset;
		UInt16 _wBank;
		UInt16 _wPresetBagNdx;
		UInt32 _dwLibrary;
		UInt32 _dwGenre;
		UInt32 _dwMorphology;
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
		inline bool IsMatched(UInt16 wPreset, UInt16 wBank) const {
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
			Gura_PackedUInt16_LE(wGenNdx);
			Gura_PackedUInt16_LE(wModNdx);
		};
	private:
		int _cntRef;
		UInt16 _wGenNdx;
		UInt16 _wModNdx;
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
			Gura_PackedUInt16_LE(sfModSrcOper);
			Gura_PackedUInt16_LE(sfModDestOper);
			Gura_PackedUInt16_LE(modAmount);
			Gura_PackedUInt16_LE(sfModAmtSrcOper);
			Gura_PackedUInt16_LE(sfModTransOper);
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
			Gura_PackedUInt16_LE(sfGenOper);
			Gura_PackedUInt16_LE(genAmount);
		};
	private:
		int _cntRef;
		SFGenerator _sfGenOper;
		UInt16 _genAmount;
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
		inline UInt16 GetGenAmount() const { return _genAmount; }
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
			Gura_PackedUInt16_LE(wInstBagNdx);
		};
	private:
		int _cntRef;
		char _achInstName[20];
		UInt16 _wInstBagNdx;
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
			Gura_PackedUInt16_LE(wInstGenNdx);
			Gura_PackedUInt16_LE(wInstModNdx);
		};
	private:
		int _cntRef;
		UInt16 _wInstGenNdx;
		UInt16 _wInstModNdx;
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
			Gura_PackedUInt32_LE(dwStart);
			Gura_PackedUInt32_LE(dwEnd);
			Gura_PackedUInt32_LE(dwStartloop);
			Gura_PackedUInt32_LE(dwEndloop);
			Gura_PackedUInt32_LE(dwSampleRate);
			UChar byOriginalKey;
			char chCorrection;
			Gura_PackedUInt16_LE(wSampleLink);
			Gura_PackedUInt16_LE(sfSampleType);
		};
	private:
		int _cntRef;
		char _achSampleName[20];
		UInt32 _dwStart;
		UInt32 _dwEnd;
		UInt32 _dwStartloop;
		UInt32 _dwEndloop;
		UInt32 _dwSampleRate;
		UChar _byOriginalKey;
		char _chCorrection;
		UInt16 _wSampleLink;
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
			UInt16 startAddrsOffset;			// 0
			UInt16 endAddrsOffset;				// 1
			UInt16 startloopAddrsOffset;		// 2
			UInt16 endloopAddrsOffset;			// 3
			UInt16 startAddrsCoarseOffset;		// 4
			Int16 modLfoToPitch;				// 5
			Int16 vibLfoToPitch;				// 6
			Int16 modEnvToPitch;				// 7
			Int16 initialFilterFc;				// 8
			Int16 initiflFilterQ;				// 9
			Int16 modLfoToFilterFc;				// 10
			Int16 modEnvToFilterFc;				// 11
			UInt16 endAddrsCoarseOffset;		// 12
			Int16 modLfoToVolume;				// 13
			UInt16 unnsed1;						// 14
			UInt16 chorusEffectsSend;			// 15
			UInt16 reverbEffectsSend;			// 16
			Int16 pan;							// 17
			UInt16 unused2;						// 18
			UInt16 unused3;						// 19
			UInt16 unused4;						// 20
			Int16 delayModLFO;					// 21
			Int16 freqModLFO;					// 22
			Int16 delayVibLFO;					// 23
			Int16 freqVibLFO;					// 24
			Int16 delayModEnv;					// 25
			Int16 attackModEnv;					// 26
			Int16 holdModEnv;					// 27
			Int16 decayModEnv;					// 28
			Int16 sustainModEnv;				// 29
			Int16 releaseModEnv;				// 30
			Int16 keynumToModEnvHold;			// 31
			Int16 keynumToModEnvDecay;			// 32
			Int16 delayVolEnv;					// 33
			Int16 attackVolEnv;					// 34
			Int16 holdVolEnv;					// 35
			Int16 decayVolEnv;					// 36
			Int16 sustainVolEnv;				// 37
			Int16 releaseVolEnv;				// 38
			Int16 keynumToVolEnvHold;			// 39
			Int16 keynumToVolEnvDecay;			// 40
			UInt16 instrument;					// 41
			UInt16 reserved1;					// 42
			RangesType keyRange;				// 43
			RangesType velRange;				// 44
			UInt16 startloopAddrsCoarseOffset;	// 45
			UInt16 keynum;						// 46
			UInt16 velocity;					// 47
			UInt16 initialAttenuation;			// 48
			UInt16 reserved2;					// 49
			UInt16 endloopAddrsCoarseOffset;	// 50
			Int16 coarseTune;					// 51
			Int16 fineTune;						// 52
			UInt16 sampleID;					// 53
			UInt16 sampleModes;					// 54
			UInt16 reserved3;					// 55
			UInt16 scaleTuning;					// 56
			UInt16 exclusiveClass;				// 57
			UInt16 overridingRootKey;			// 58
			UInt16 unused5;						// 59
			UInt16 endOper;						// 60
			void Reset();
			bool Update(SFGenerator sfGenOper, UInt16 genAmount);
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
	const sfPresetHeader *LookupPresetHeader(UInt16 wPreset, UInt16 wBank) const;
	Synthesizer *CreateSynthesizer(Signal &sig, UInt16 wPreset, UInt16 wBank, UChar key, UChar velocity) const;
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
