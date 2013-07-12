#ifndef __SOUNDFONT_H__
#define __SOUNDFONT_H__
#include <gura.h>

Gura_BeginModule(midi)

template<typename T_Elem, typename T_List>
class OwnerTemplate : public T_List {
public:
	virtual ~OwnerTemplate() {
		Clear();
	}
	void Clear() {
		foreach (OwnerTemplate, ppElem, *this) {
			T_Elem *pElem = *ppElem;
			delete pElem;
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
		unsigned short _wMajor;
		unsigned short _wMinor;
	public:
		inline sfVersionTag() :
				_wMajor(0),
				_wMinor(0) {}
		inline sfVersionTag(const RawData &rawData) :
				_wMajor(Gura_UnpackUShort(rawData.wMajor)),
				_wMinor(Gura_UnpackUShort(rawData.wMinor)) {}
		inline void Print() const {
			::printf("wMajor=%d wMinor=%d\n",
				_wMajor,
				_wMinor);
			}
	};
	typedef std::vector<sfVersionTag *> sfVersionTagList;
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
		char _achPresetName[20];
		unsigned short _wPreset;
		unsigned short _wBank;
		unsigned short _wPresetBagNdx;
		unsigned long _dwLibrary;
		unsigned long _dwGenre;
		unsigned long _dwMorphology;
	public:
		inline sfPresetHeader() :
				_wPreset(0),
				_wBank(0),
				_wPresetBagNdx(0),
				_dwLibrary(0),
				_dwGenre(0),
				_dwMorphology(0) {
			::memset(_achPresetName, 0x00, sizeof(_achPresetName));
		}
		inline sfPresetHeader(const RawData &rawData) :
				_wPreset(Gura_UnpackUShort(rawData.wPreset)),
				_wBank(Gura_UnpackUShort(rawData.wBank)),
				_wPresetBagNdx(Gura_UnpackUShort(rawData.wPresetBagNdx)),
				_dwLibrary(Gura_UnpackULong(rawData.dwLibrary)),
				_dwGenre(Gura_UnpackULong(rawData.dwGenre)),
				_dwMorphology(Gura_UnpackULong(rawData.dwMorphology)) {
			::memcpy(_achPresetName, rawData.achPresetName, sizeof(_achPresetName));
		}
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
	};
	typedef std::vector<sfPresetHeader *> sfPresetHeaderList;
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
		unsigned short _wGenNdx;
		unsigned short _wModNdx;
	public:
		inline sfPresetBag() :
				_wGenNdx(0),
				_wModNdx(0) {}
		inline sfPresetBag(const RawData &rawData) :
				_wGenNdx(Gura_UnpackUShort(rawData.wGenNdx)),
				_wModNdx(Gura_UnpackUShort(rawData.wModNdx)) {}
		inline void Print() const {
			::printf("wGenNdx=%d wModNdx=%d\n",
				_wGenNdx,
				_wModNdx);
		}
	};
	typedef std::vector<sfPresetBag *> sfPresetBagList;
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
		unsigned short _sfModSrcOper;
		unsigned short _sfModDestOper;
		unsigned short _modAmount;
		unsigned short _sfModAmtSrcOper;
		unsigned short _sfModTransOper;
	public:
		inline sfMod() :
				_sfModSrcOper(0),
				_sfModDestOper(0),
				_modAmount(0),
				_sfModAmtSrcOper(0),
				_sfModTransOper(0) {}
		inline sfMod(const RawData &rawData) :
				_sfModSrcOper(Gura_UnpackUShort(rawData.sfModSrcOper)),
				_sfModDestOper(Gura_UnpackUShort(rawData.sfModDestOper)),
				_modAmount(Gura_UnpackUShort(rawData.modAmount)),
				_sfModAmtSrcOper(Gura_UnpackUShort(rawData.sfModAmtSrcOper)),
				_sfModTransOper(Gura_UnpackUShort(rawData.sfModTransOper)) {}
		inline void Print() const {
			::printf("sfModSrcOper=%d sfModDestOper=%d modAmount=0x%04x sfModAmtSrcOper=%d sfModTransOper=%d\n",
				_sfModSrcOper,
				_sfModDestOper,
				_modAmount,
				_sfModAmtSrcOper,
				_sfModTransOper);
		}
	};
	typedef std::vector<sfMod *> sfModList;
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
		unsigned short _sfGenOper;
		unsigned short _genAmount;
	public:
		inline sfGen() :
				_sfGenOper(0),
				_genAmount(0) {}
		inline sfGen(const RawData &rawData) :
				_sfGenOper(Gura_UnpackUShort(rawData.sfGenOper)),
				_genAmount(Gura_UnpackUShort(rawData.genAmount)) {}
		inline void Print() const {
			::printf("sfGenOper=%d genAmount=0x%04x\n",
				_sfGenOper,
				_genAmount);
		}
	};
	typedef std::vector<sfGen *> sfGenList;
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
		char _achInstName[20];
		unsigned short _wInstBagNdx;
	public:
		inline sfInst() :
				_wInstBagNdx(0) {
			::memset(_achInstName, 0x00, sizeof(_achInstName));
		}
		inline sfInst(const RawData &rawData) :
				_wInstBagNdx(Gura_UnpackUShort(rawData.wInstBagNdx)) {
			::memcpy(_achInstName, rawData.achInstName, sizeof(_achInstName));
		}
		inline void Print() const {
			::printf("achInstName=\"%s\" wInstBagNdx=%d\n",
				_achInstName,
				_wInstBagNdx);
		}
	};
	typedef std::vector<sfInst *> sfInstList;
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
		unsigned short _wInstGenNdx;
		unsigned short _wInstModNdx;
	public:
		inline sfInstBag() :
				_wInstGenNdx(0),
				_wInstModNdx(0) {}
		inline sfInstBag(const RawData &rawData) :
				_wInstGenNdx(Gura_UnpackUShort(rawData.wInstGenNdx)),
				_wInstModNdx(Gura_UnpackUShort(rawData.wInstModNdx)) {}
		inline void Print() const {
			::printf("wInstGenNdx=%d wInstModNdx=%d\n",
				_wInstGenNdx,
				_wInstModNdx);
		}
	};
	typedef std::vector<sfInstBag *> sfInstBagList;
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
		unsigned short _sfModSrcOper;
		unsigned short _sfModDestOper;
		unsigned short _modAmount;
		unsigned short _sfModAmtSrcOper;
		unsigned short _sfModTransOper;
	public:
		inline sfInstMod() :
				_sfModSrcOper(0),
				_sfModDestOper(0),
				_modAmount(0),
				_sfModAmtSrcOper(0),
				_sfModTransOper(0) {}
		inline sfInstMod(const RawData &rawData) :
				_sfModSrcOper(Gura_UnpackUShort(rawData.sfModSrcOper)),
				_sfModDestOper(Gura_UnpackUShort(rawData.sfModDestOper)),
				_modAmount(Gura_UnpackUShort(rawData.modAmount)),
				_sfModAmtSrcOper(Gura_UnpackUShort(rawData.sfModAmtSrcOper)),
				_sfModTransOper(Gura_UnpackUShort(rawData.sfModTransOper)) {}
		inline void Print() const {
			::printf("sfModSrcOper=%d sfModDestOper=%d modAmount=0x%04x sfModAmtSrcOper=%d sfModTransOper=%d\n",
				_sfModSrcOper,
				_sfModDestOper,
				_modAmount,
				_sfModAmtSrcOper,
				_sfModTransOper);
		}
	};
	typedef std::vector<sfInstMod *> sfInstModList;
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
		unsigned short _sfGenOper;
		unsigned short _genAmount;
	public:
		inline sfInstGen() :
				_sfGenOper(0),
				_genAmount(0) {}
		inline sfInstGen(const RawData &rawData) :
				_sfGenOper(Gura_UnpackUShort(rawData.sfGenOper)),
				_genAmount(Gura_UnpackUShort(rawData.genAmount)) {}
		inline void Print() const {
			::printf("sfGenOper=%d genAmount=0x%04x\n",
				_sfGenOper,
				_genAmount);
		}
	};
	typedef std::vector<sfInstGen *> sfInstGenList;
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
		char _achSampleName[20];
		unsigned long _dwStart;
		unsigned long _dwEnd;
		unsigned long _dwStartloop;
		unsigned long _dwEndloop;
		unsigned long _dwSampleRate;
		unsigned char _byOriginalKey;
		char _chCorrection;
		unsigned short _wSampleLink;
		unsigned short _sfSampleType;
	public:
		inline sfSample() :
				_dwStart(0),
				_dwEnd(0),
				_dwStartloop(0),
				_dwEndloop(0),
				_dwSampleRate(0),
				_byOriginalKey(0),
				_chCorrection(0),
				_wSampleLink(0),
				_sfSampleType(0) {}
		inline sfSample(const RawData &rawData) :
				_dwStart(Gura_UnpackULong(rawData.dwStart)),
				_dwEnd(Gura_UnpackULong(rawData.dwEnd)),
				_dwStartloop(Gura_UnpackULong(rawData.dwStartloop)),
				_dwEndloop(Gura_UnpackULong(rawData.dwEndloop)),
				_dwSampleRate(Gura_UnpackULong(rawData.dwSampleRate)),
				_byOriginalKey(rawData.byOriginalKey),
				_chCorrection(rawData.chCorrection),
				_wSampleLink(Gura_UnpackUShort(rawData.wSampleLink)),
				_sfSampleType(Gura_UnpackUShort(rawData.sfSampleType)) {}
		inline void Print() const {
			::printf("achSampleName=\"%s\" dwStart=%d dwEnd=%d dwStartloop=%d dwEndloop=%d dwSampleRate=%d byOriginalKey=%d chCorrection=%d wSampleLink=%d sfSampleType=%d\n",
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
	typedef std::vector<sfSample *> sfSampleList;
	typedef OwnerTemplate<sfSample, sfSampleList> sfSampleOwner;
public:
	struct INFO_t {
		std::auto_ptr<sfVersionTag>	p_ifil;	// mandatory
		std::auto_ptr<String>		p_isng;	// mandatory
		std::auto_ptr<String>		p_INAM;	// mandatory
		std::auto_ptr<String>		p_irom;	// optional
		std::auto_ptr<sfVersionTag> p_iver;	// optional
		std::auto_ptr<String>		p_ICRD;	// optional
		std::auto_ptr<String>		p_IENG;	// optional
		std::auto_ptr<String>		p_IPRD;	// optional
		std::auto_ptr<String>		p_ICOP;	// optional
		std::auto_ptr<String>		p_ICMT;	// optional
		std::auto_ptr<String>		p_ISFT;	// optional
	};
	struct pdta_t {
		sfPresetHeaderOwner			phdrs;
		sfPresetBagOwner			pbags;
		sfModOwner					pmods;
		sfGenOwner					pgens;
		sfInstOwner					insts;
		sfInstBagOwner				ibags;
		sfModOwner					imods;
		sfInstGenOwner				igens;
		sfSampleOwner				shdrs;
	};
private:
	INFO_t _INFO;
	pdta_t _pdta;
public:
	bool Read(Environment &env, Signal sig, Stream &stream);
private:
	bool ReadSubChunk(Environment &env, Signal sig, Stream &stream, size_t bytes);
	static bool ReadStruct(Environment &env, Signal sig, Stream &stream,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual);
	static bool ReadString(Environment &env, Signal sig, Stream &stream,
						char *str, size_t ckSizeMax, size_t ckSizeActual);
};

}}

#endif
