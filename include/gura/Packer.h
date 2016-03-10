//=============================================================================
// Packer
//=============================================================================
#ifndef __GURA_PACKER_H__
#define __GURA_PACKER_H__

#include "Common.h"
#include "Value.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Packer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Packer {
protected:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Packer)
public:
	class GURA_DLLDECLARE IteratorUnpack : public Iterator {
	private:
		AutoPtr<Packer> _pPacker;
		String _format;
		ValueList _valListArg;
	public:
		IteratorUnpack(Packer *pPacker, const char *format, const ValueList &valListArg);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	template<typename T> class GURA_DLLDECLARE IteratorEach : public Iterator {
	private:
		AutoPtr<Packer> _pPacker;
		bool _bigEndianFlag;
	public:
		IteratorEach(Packer *pPacker, bool bigEndianFlag) : Iterator(false),
							_pPacker(pPacker), _bigEndianFlag(bigEndianFlag) {
		}
		virtual Iterator *GetSource() {
			return nullptr;
		}
		virtual bool DoNext(Environment &env, Value &value) {
			T num;
			if (!_pPacker->Get(env, &num, _bigEndianFlag, false)) return false;
			value = Value(num);
			return true;
		}
		virtual String ToString() const {
			return String("packer.each");
		}
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet) {
		}
	};
public:
	Packer();
protected:
	virtual ~Packer();
public:
	bool Pack(Environment &env, const char *format, const ValueList &valListArg);
	Value Unpack(Environment &env, const char *format,
				 const ValueList &valListArg, bool exceedErrorFlag);
	template<typename T> bool Put(Environment &env, T num, bool bigEndianFlag) {
		if (!StorePrepare(env, sizeof(T))) return false;
		Store<T>(num, bigEndianFlag);
		return true;
	}
	template<typename T> bool Get(Environment &env, T *pNum, bool bigEndianFlag, bool exceedErrorFlag) {
		const UChar *pByte = ExtractPrepare(env, sizeof(T), exceedErrorFlag);
		if (pByte == nullptr) return false;
		*pNum = Extract<T>(pByte, bigEndianFlag);
		return true;
	}
	bool PutBuffer(Environment &env, const void *buff, size_t bytes);
public:
	virtual bool StorePrepare(Environment &env, size_t bytes) = 0;
	virtual void StoreBuffer(const void *buff, size_t bytes) = 0;
	virtual const UChar *ExtractPrepare(Environment &env, size_t bytes, bool exceedErrorFlag) = 0;
private:
	template<typename T> void Store(T num, bool bigEndianFlag);
	template<typename T> T Extract(const UChar *pByte, bool bigEndianFlag);
private:
	static bool CheckString(Environment &env,
							const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Environment &env,
							const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Environment &env, const ValueList &valList,
							ValueList::const_iterator pValue, Number numMin, Number numMax);
};

template<> inline void Packer::Store<UChar>(UChar num, bool bigEndianFlag)
{
	StoreBuffer(&num, sizeof(UChar));
}

template<> void Packer::Store<UShort>(UShort num, bool bigEndianFlag);
template<> void Packer::Store<UInt32>(UInt32 num, bool bigEndianFlag);
template<> void Packer::Store<UInt64>(UInt64 num, bool bigEndianFlag);

template<> inline void Packer::Store<Char>(Char num, bool bigEndianFlag)
{
	Store<UChar>(static_cast<UChar>(num), bigEndianFlag);
}

template<> inline void Packer::Store<Short>(Short num, bool bigEndianFlag)
{
	Store<UShort>(static_cast<UShort>(num), bigEndianFlag);
}

template<> inline void Packer::Store<Int32>(Int32 num, bool bigEndianFlag)
{
	Store<UInt32>(static_cast<UInt32>(num), bigEndianFlag);
}

template<> inline void Packer::Store<Int64>(Int64 num, bool bigEndianFlag)
{
	Store<UInt64>(static_cast<UInt64>(num), bigEndianFlag);
}

template<> inline void Packer::Store<Float>(Float num, bool bigEndianFlag)
{
	Store<UInt32>(*reinterpret_cast<UInt32 *>(&num), bigEndianFlag);
}

template<> inline void Packer::Store<Double>(Double num, bool bigEndianFlag)
{
	Store<UInt64>(*reinterpret_cast<UInt64 *>(&num), bigEndianFlag);
}

template<> inline UChar Packer::Extract<UChar>(const UChar *pByte, bool bigEndianFlag)
{
	return *pByte;
}

template<> UShort Packer::Extract<UShort>(const UChar *pByte, bool bigEndianFlag);
template<> UInt32 Packer::Extract<UInt32>(const UChar *pByte, bool bigEndianFlag);
template<> UInt64 Packer::Extract<UInt64>(const UChar *pByte, bool bigEndianFlag);

template<> inline Char Packer::Extract<Char>(const UChar *pByte, bool bigEndianFlag)
{
	return static_cast<Char>(Extract<UChar>(pByte, bigEndianFlag));
}

template<> inline Short Packer::Extract<Short>(const UChar *pByte, bool bigEndianFlag)
{
	return static_cast<Short>(Extract<UShort>(pByte, bigEndianFlag));
}

template<> inline Int32 Packer::Extract<Int32>(const UChar *pByte, bool bigEndianFlag)
{
	return static_cast<Int32>(Extract<UInt32>(pByte, bigEndianFlag));
}

template<> inline Int64 Packer::Extract<Int64>(const UChar *pByte, bool bigEndianFlag)
{
	return static_cast<Int64>(Extract<UInt64>(pByte, bigEndianFlag));
}

template<> inline Float Packer::Extract<Float>(const UChar *pByte, bool bigEndianFlag)
{
	UInt32 num = Extract<UInt32>(pByte, bigEndianFlag);
	return *reinterpret_cast<Float *>(&num);
}

template<> inline Double Packer::Extract<Double>(const UChar *pByte, bool bigEndianFlag)
{
	UInt64 num = Extract<UInt64>(pByte, bigEndianFlag);
	return *reinterpret_cast<Double *>(&num);
}

}

#endif
