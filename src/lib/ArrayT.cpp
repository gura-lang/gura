//=============================================================================
// ArrayT
//=============================================================================
#include "stdafx.h"

//------------------------------------------------------------------------------
// Macros
//------------------------------------------------------------------------------
#define ImplementArrayT(T_Elem) \
template<> \
ArrayT<T_Elem>::ArrayT() : Array(ETYPE_##T_Elem) \
{} \
template<> \
ArrayT<T_Elem>::ArrayT(const ArrayT &src) : Array(ETYPE_##T_Elem, src) \
{} \
template<> \
ArrayT<T_Elem>::ArrayT(Memory *pMemory, size_t offsetBase) : Array(ETYPE_##T_Elem, pMemory, offsetBase) \
{} \
template<> \
ArrayT<T_Elem>::ArrayT(size_t size) : Array(ETYPE_##T_Elem) \
{ \
	SetDimension(Dimension(size)); \
	AllocMemory(); \
} \
template<> \
ArrayT<T_Elem>::ArrayT(size_t sizeRow, size_t sizeCol) : Array(ETYPE_##T_Elem) \
{ \
	SetDimensions(Dimension(sizeRow), Dimension(sizeCol)); \
	AllocMemory(); \
} \
template class ArrayT<T_Elem>;

namespace Gura {

//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------
template<typename T_Elem, typename T_ElemCast>
void DumpInteger(Signal &sig, Stream &stream, const char *fmt, size_t cols, const T_Elem *p, size_t n)
{
	size_t col = 0;
	for (size_t i = 0; i < n; i++, p++) {
		if (col != 0) {
			stream.Printf(sig, " ");
		}
		stream.Printf(sig, fmt, static_cast<T_ElemCast>(*p));
		col++;
		if (col == cols) {
			stream.Printf(sig, "\n");
			col = 0;
		}
	}
	if (col != 0) stream.Printf(sig, "\n");
}

template<typename T_Elem, typename T_ElemCast>
void DumpFloat(Signal &sig, Stream &stream, const char *fmt, size_t cols, const T_Elem *p, size_t n)
{
	size_t col = 0;
	for (size_t i = 0; i < n; i++, p++) {
		if (col != 0) {
			stream.Printf(sig, " ");
		}
		T_ElemCast num = *reinterpret_cast<const T_ElemCast *>(p);
		stream.Printf(sig, "%llx", num);
		stream.Printf(sig, fmt, num);
		col++;
		if (col == cols) {
			stream.Printf(sig, "\n");
			col = 0;
		}
	}
	if (col != 0) stream.Printf(sig, "\n");
}

template<typename T_Elem> void FormatElem(char *buff, int wdPad, T_Elem x);

template<> void FormatElem(char *buff, int wdPad, Int8 x)
{ ::sprintf(buff, "%*d", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, UInt8 x)
{ ::sprintf(buff, "%*u", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, Int16 x)
{ ::sprintf(buff, "%*d", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, UInt16 x)
{ ::sprintf(buff, "%*u", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, Int32 x)
{ ::sprintf(buff, "%*d", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, UInt32 x)
{ ::sprintf(buff, "%*u", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, Int64 x)
{ ::sprintf(buff, "%*lld", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, UInt64 x)
{ ::sprintf(buff, "%*llu", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, Float x)
{ ::sprintf(buff, "%*g", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, Double x)
{ ::sprintf(buff, "%*g", wdPad, x); }
template<> void FormatElem(char *buff, int wdPad, Complex x)
{ ::sprintf(buff, "%g,%g", x.real(), x.imag()); }

//------------------------------------------------------------------------------
// ArrayT
//------------------------------------------------------------------------------
template<typename T_Elem>
void ToString_Sub(String &rtn, size_t colTop, int wdPad, const Array::Dimensions &dims,
				  Array::Dimensions::const_iterator pDim, const T_Elem *&p)
{
	char buff[128];
	size_t nestLevel = std::distance(dims.begin(), pDim);
	if (pDim + 1 == dims.end()) {
		rtn += "[";
		for (size_t i = 0; i < pDim->GetSize(); i++, p++) {
			if (i > 0) rtn += ", ";
			FormatElem(buff, wdPad, *p);
			rtn += buff;
		}
		rtn += "]";
	} else {
		rtn += "[";
		for (size_t i = 0; i < pDim->GetSize(); i++) {
			if (i > 0) {
				rtn += ',';
				rtn += '\n';
				for (size_t j = 0; j < dims.size() - nestLevel - 2; j++) rtn += '\n';
				for (size_t j = 0; j < nestLevel + colTop + 1; j++) rtn += ' ';
			}
			ToString_Sub(rtn, colTop, wdPad, dims, pDim + 1, p);
		}
		rtn += "]";
	}
}

template<typename T_Elem>
String ArrayT<T_Elem>::ToString(bool exprFlag) const
{
	char buff[128];
	const T_Elem *p = GetPointer();
	int wdPad = 0;
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		FormatElem(buff, wdPad, *p);
		int wdElem = ::strlen(buff);
		if (wdPad < wdElem) wdPad = wdElem;
	}
	p = GetPointer();
	String rtn;
	if (exprFlag) {
		rtn += ConstructorName;
		rtn += "(";
		ToString_Sub(rtn, rtn.size(), wdPad, _dims, _dims.begin(), p);
		rtn += ")";
	} else {
		ToString_Sub(rtn, 0, wdPad, _dims, _dims.begin(), p);
	}
	return rtn;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::DoesContainZero() const
{
	const T_Elem *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		if (*p == 0) return true;
	}
	return false;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::DoesContainMinus() const
{
	const T_Elem *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		if (*p < 0) return true;
	}
	return false;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::DoesContainZeroOrMinus() const
{
	const T_Elem *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		if (*p <= 0) return true;
	}
	return false;
}

template<>
bool ArrayT<Complex>::DoesContainZero() const
{
	const Complex *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		if (p->real() == 0 && p->imag() == 0) return true;
	}
	return false;
}

template<>
bool ArrayT<Complex>::DoesContainMinus() const
{
	return false;
}

template<>
bool ArrayT<Complex>::DoesContainZeroOrMinus() const
{
	return DoesContainZero();
}

template<> Array::ElemType ArrayT<Int8>::ElemTypeThis		= ETYPE_Int8;
template<> Array::ElemType ArrayT<UInt8>::ElemTypeThis		= ETYPE_UInt8;
template<> Array::ElemType ArrayT<Int16>::ElemTypeThis		= ETYPE_Int16;
template<> Array::ElemType ArrayT<UInt16>::ElemTypeThis		= ETYPE_UInt16;
template<> Array::ElemType ArrayT<Int32>::ElemTypeThis		= ETYPE_Int32;
template<> Array::ElemType ArrayT<UInt32>::ElemTypeThis		= ETYPE_UInt32;
template<> Array::ElemType ArrayT<Int64>::ElemTypeThis		= ETYPE_Int64;
template<> Array::ElemType ArrayT<UInt64>::ElemTypeThis		= ETYPE_UInt64;
template<> Array::ElemType ArrayT<Float>::ElemTypeThis		= ETYPE_Float;
template<> Array::ElemType ArrayT<Double>::ElemTypeThis		= ETYPE_Double;
template<> Array::ElemType ArrayT<Complex>::ElemTypeThis	= ETYPE_Complex;

template<> size_t ArrayT<Int8>::ElemBytes					= 1;
template<> size_t ArrayT<UInt8>::ElemBytes					= 1;
template<> size_t ArrayT<Int16>::ElemBytes					= 2;
template<> size_t ArrayT<UInt16>::ElemBytes					= 2;
template<> size_t ArrayT<Int32>::ElemBytes					= 4;
template<> size_t ArrayT<UInt32>::ElemBytes					= 4;
template<> size_t ArrayT<Int64>::ElemBytes					= 8;
template<> size_t ArrayT<UInt64>::ElemBytes					= 8;
template<> size_t ArrayT<Float>::ElemBytes					= 4;
template<> size_t ArrayT<Double>::ElemBytes					= 8;
template<> size_t ArrayT<Complex>::ElemBytes				= 16;

template<> const char *ArrayT<Int8>::ElemTypeName			= "int8";
template<> const char *ArrayT<UInt8>::ElemTypeName			= "uint8";
template<> const char *ArrayT<Int16>::ElemTypeName			= "int16";
template<> const char *ArrayT<UInt16>::ElemTypeName			= "uint16";
template<> const char *ArrayT<Int32>::ElemTypeName			= "int32";
template<> const char *ArrayT<UInt32>::ElemTypeName			= "uint32";
template<> const char *ArrayT<Int64>::ElemTypeName			= "int64";
template<> const char *ArrayT<UInt64>::ElemTypeName			= "uint64";
template<> const char *ArrayT<Float>::ElemTypeName			= "float";
template<> const char *ArrayT<Double>::ElemTypeName			= "double";
template<> const char *ArrayT<Complex>::ElemTypeName		= "complex";

template<> const char *ArrayT<Int8>::ConstructorName		= "array@int8";
template<> const char *ArrayT<UInt8>::ConstructorName		= "array@uint8";
template<> const char *ArrayT<Int16>::ConstructorName		= "array@int16";
template<> const char *ArrayT<UInt16>::ConstructorName		= "array@uint16";
template<> const char *ArrayT<Int32>::ConstructorName		= "array@int32";
template<> const char *ArrayT<UInt32>::ConstructorName		= "array@uint32";
template<> const char *ArrayT<Int64>::ConstructorName		= "array@int64";
template<> const char *ArrayT<UInt64>::ConstructorName		= "array@uint64";
template<> const char *ArrayT<Float>::ConstructorName		= "array@float";
template<> const char *ArrayT<Double>::ConstructorName		= "array@double";
template<> const char *ArrayT<Complex>::ConstructorName 	= "array@complex";

template<typename T_Elem>
void ArrayT<T_Elem>::Fill(const T_Elem &num)
{
	T_Elem *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		*p = num;
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::FillZero()
{
	::memset(GetPointer(), 0x00, sizeof(T_Elem) * GetElemNum());
}

template<typename T_Elem>
void ArrayT<T_Elem>::FillRand(UInt range)
{
	T_Elem *p = GetPointer();
	if (range == 0) {
		for (size_t i = 0; i < GetElemNum(); i++, p++) {
			*p = static_cast<T_Elem>(Random::Uniform_CloseOpen());
		}
	} else {
		for (size_t i = 0; i < GetElemNum(); i++, p++) {
			*p = static_cast<T_Elem>(static_cast<UInt>(
										 Random::Uniform_CloseOpen() * range));
		}
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::FillRandNormal(double mu, double sigma)
{
	T_Elem *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		*p = static_cast<T_Elem>(mu + Random::Normal() * sigma);
	}
}

template<typename T_Elem>
bool ArrayT<T_Elem>::Paste(Signal &sig, size_t offset, const ArrayT *pArrayTSrc)
{
	if (GetElemNum() < offset + pArrayTSrc->GetElemNum()) {
		sig.SetError(ERR_OutOfRangeError, "out of range");
		return false;
	}
	::memcpy(GetPointer() + offset, pArrayTSrc->GetPointer(),
			 sizeof(T_Elem) * pArrayTSrc->GetElemNum());
	return true;
}

template<>
void ArrayT<Int8>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int8, UInt8>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetElemNum());
}

template<>
void ArrayT<UInt8>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt8, UInt8>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Int16>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int16, UInt16>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetElemNum());
}

template<>
void ArrayT<UInt16>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt16, UInt16>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Int32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int32, UInt32>(sig, stream, upperFlag? "%08X" : "%08x", 8, GetPointer(), GetElemNum());
}

template<> void ArrayT<UInt32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt32, UInt32>(sig, stream, upperFlag? "%08X" : "%08x", 8, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Int64>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int64, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum());
}

template<>
void ArrayT<UInt64>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt64, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum());
}

template<>
void ArrayT<float>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<float, ULong>(sig, stream, upperFlag? "%08lX" : "%08lx", 8, GetPointer(), GetElemNum());
}

template<>
void ArrayT<double>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<double, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Complex>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<Complex, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum() * 2);
}

template<typename T_Elem>
void ArrayT<T_Elem>::CopyToList(ValueList &valList) const
{
	if (valList.empty()) valList.reserve(GetElemNum());
	const T_Elem *p = GetPointer();
	for (size_t nElems = GetElemNum(); nElems > 0; nElems--, p++) {
		valList.push_back(Value(*p));
	}
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Flatten() const
{
	AutoPtr<ArrayT> pArrayRtn(new ArrayT(GetMemory().Reference(), GetOffsetBase()));
	pArrayRtn->SetDimension(Dimension(GetElemNum()));
	return pArrayRtn.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Reshape(Signal &sig, const ValueList &valList) const
{
	bool unfixedFlag = false;
	size_t nElems = 1;
	foreach_const (ValueList, pValue, valList) {
		if (pValue->Is_number() && pValue->GetNumber() >= 0) {
			nElems *= pValue->GetSizeT();
		} else if (unfixedFlag) {
			sig.SetError(ERR_ValueError, "only one dimension can be specified as an unfixed");
			return nullptr;
		} else {
			unfixedFlag = true;
		}
	}
	if ((unfixedFlag && (GetElemNum() % nElems != 0)) ||
		(!unfixedFlag && (nElems != GetElemNum()))) {
		sig.SetError(ERR_ValueError, "incorrect shape specified");
		return nullptr;
	}
	AutoPtr<ArrayT> pArrayTRtn(new ArrayT(GetMemory().Reference(), GetOffsetBase()));
	Dimensions &dims = pArrayTRtn->GetDimensions();
	dims.reserve(valList.size());
	foreach_const (ValueList, pValue, valList) {
		if (pValue->Is_number() && pValue->GetNumber() >= 0) {
			dims.push_back(Dimension(pValue->GetSizeT()));
		} else {
			dims.push_back(Dimension(GetElemNum() / nElems));
		}
	}	
	pArrayTRtn->UpdateMetrics();
	return pArrayTRtn.release();
}

template<typename T_Elem>
void TransposeSub(T_Elem *&pDst, const T_Elem *pSrc, const Array::Dimensions &dimsSrc,
				  SizeTList::const_iterator pAxis, SizeTList::const_iterator pAxisEnd)
{
	const Array::Dimension &dimSrc = dimsSrc[*pAxis];
	if (pAxis + 1 == pAxisEnd) {
		for (size_t i = 0; i < dimSrc.GetSize(); i++, pSrc += dimSrc.GetStride(), pDst++) {
			*pDst = *pSrc;
		}
	} else {
		for (size_t i = 0; i < dimSrc.GetSize(); i++, pSrc += dimSrc.GetStride()) {
			TransposeSub(pDst, pSrc, dimsSrc, pAxis + 1, pAxisEnd);
		}
	}
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Transpose(Signal &sig, const ValueList &valList) const
{
	if (GetDimensions().size() != valList.size()) {
		sig.SetError(ERR_ValueError, "mismatched number of axes to transpose");
		return nullptr;
	}
	SizeTList axes;
	foreach_const (ValueList, pValue, valList) {
		size_t axis = pValue->GetSizeT();
		if (std::find(axes.begin(), axes.end(), axis) != axes.end()) {
			sig.SetError(ERR_ValueError, "duplicated axis is specified");
			return nullptr;
		}
		if (axis >= GetDimensions().size()) {
			sig.SetError(ERR_ValueError, "specified axis is out of range");
			return nullptr;
		}
		axes.push_back(axis);
	}
	return Transpose(axes);
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Transpose(const SizeTList &axes) const
{
	AutoPtr<ArrayT> pArrayTRtn(new ArrayT());
	//::printf("%d %d\n", axes[0], axes[1]);
	do {
		Dimensions &dimsDst = pArrayTRtn->GetDimensions();
		dimsDst.reserve(GetDimensions().size());
		foreach_const (SizeTList, pAxis, axes) {
			const Dimension &dimSrc = GetDimensions()[*pAxis];
			dimsDst.push_back(Dimension(dimSrc.GetSize()));
		}
		pArrayTRtn->UpdateMetrics();
		pArrayTRtn->AllocMemory();
		T_Elem *pDst = pArrayTRtn->GetPointer();
		TransposeSub(pDst, GetPointer(), GetDimensions(), axes.begin(), axes.end());
	} while (0);
	return pArrayTRtn.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Transpose() const
{
	size_t nAxes = GetDimensions().size();
	if (nAxes < 2) return new ArrayT<T_Elem>(*this);
	SizeTList axes;
	axes.reserve(nAxes);
	size_t axis = 0;
	for ( ; axis < nAxes - 2; axis++) axes.push_back(axis);
	axes.push_back(axis + 1), axes.push_back(axis);
	return Transpose(axes);
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Head(Signal &sig, size_t n) const
{
	const Dimension &dimFirst = GetDimensions().front();
	if (n > dimFirst.GetSize()) {
		sig.SetError(ERR_OutOfRangeError, "specified size is out of range");
		return nullptr;
	}
	size_t offsetBase = GetOffsetBase();
	AutoPtr<ArrayT> pArrayTRtn(new ArrayT(GetMemory().Reference(), offsetBase));
	pArrayTRtn->SetDimensions(Dimension(n), GetDimensions().begin() + 1, GetDimensions().end());
	return pArrayTRtn.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Tail(Signal &sig, size_t n) const
{
	const Dimension &dimFirst = GetDimensions().front();
	if (n > dimFirst.GetSize()) {
		sig.SetError(ERR_OutOfRangeError, "specified size is out of range");
		return nullptr;
	}
	size_t offsetBase = GetOffsetBase() + dimFirst.GetStride() * (dimFirst.GetSize() - n);
	AutoPtr<ArrayT> pArrayTRtn(new ArrayT(GetMemory().Reference(), offsetBase));
	pArrayTRtn->SetDimensions(Dimension(n),
							  GetDimensions().begin() + 1, GetDimensions().end());
	return pArrayTRtn.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Offset(Signal &sig, size_t n) const
{
	const Dimension &dimFirst = GetDimensions().front();
	if (n > dimFirst.GetSize()) {
		sig.SetError(ERR_OutOfRangeError, "offset is out of range");
		return nullptr;
	}
	size_t nElems = dimFirst.GetSize() - n;
	size_t offsetBase = GetOffsetBase() + dimFirst.GetStride() * n;
	AutoPtr<ArrayT> pArrayTRtn(new ArrayT(GetMemory().Reference(), offsetBase));
	pArrayTRtn->SetDimensions(Dimension(nElems),
							  GetDimensions().begin() + 1, GetDimensions().end());
	return pArrayTRtn.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::RoundOff(double threshold) const
{
	AutoPtr<ArrayT> pArrayResult(ArrayT::Create(GetDimensions()));
	T_Elem *pDst = pArrayResult->GetPointer();
	const T_Elem *pSrc = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pSrc++, pDst++) {
		*pDst = (*pSrc > threshold)? *pSrc : 0;
	}
	return pArrayResult.release();
}

template<>
ArrayT<Complex> *ArrayT<Complex>::RoundOff(double threshold) const
{
	AutoPtr<ArrayT> pArrayResult(ArrayT::Create(GetDimensions()));
	Complex *pDst = pArrayResult->GetPointer();
	const Complex *pSrc = GetPointer();
	double threshold2 = threshold * threshold;
	for (size_t i = 0; i < GetElemNum(); i++, pSrc++, pDst++) {
		*pDst = (std::norm(*pSrc) > threshold2)? *pSrc : 0;
	}
	return pArrayResult.release();
}

/// functions to create an ArrayT instance
template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(const Dimension &dim)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimension(dim);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(const Array::Dimensions &dims)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(dims);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(Dimensions::const_iterator pDim,
									   Dimensions::const_iterator pDimEnd)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(pDim, pDimEnd);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(Dimensions::const_iterator pDim,
									   Dimensions::const_iterator pDimEnd, const Dimension &dim)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(pDim, pDimEnd, dim);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(
	Dimensions::const_iterator pDim1, Dimensions::const_iterator pDim1End,
	Dimensions::const_iterator pDim2, Dimensions::const_iterator pDim2End)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(pDim1, pDim1End, pDim2, pDim2End);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromValue(Environment &env, const Value &value)
{
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	Signal &sig = env.GetSignal();
	if (value.Is_list()) {
		const ValueList &valList = value.GetList();
		pArrayT.reset(ArrayT<T_Elem>::CreateFromList(sig, valList));
		if (pArrayT.IsNull()) return nullptr;
	} else if (value.Is_iterator()) {
		Iterator *pIterator = value.GetIterator();
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return nullptr;
		}
		pArrayT.reset(ArrayT<T_Elem>::CreateFromIterator(env, pIterator));
		if (pArrayT.IsNull()) return nullptr;
	} else {
		Declaration::SetError_InvalidArgument(env);
		return nullptr;
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromList(const ValueList &valList)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(valList.size()));
	T_Elem *p = pArrayT->GetPointer();
	foreach_const (ValueList, pValue, valList) {
		*p++ = static_cast<T_Elem>(pValue->GetNumber());
	}
	return pArrayT.release();
}

template<typename T_Elem>
bool CreateFromList_Sub(Signal &sig, Array::Dimensions &dims,
						Array::Dimensions::const_iterator pDim,
						T_Elem *&p, const ValueList &valList)
{
	if (pDim->GetSize() != valList.size()) {
		sig.SetError(ERR_ValueError, "incorrect number of elements");
		return false;
	}
	if (pDim + 1 == dims.end()) {
		foreach_const (ValueList, pValue, valList) {
			bool successFlag = false;
			Number num = pValue->ToNumber(false, successFlag);
			if (!successFlag) {
				sig.SetError(ERR_ValueError, "failed to convert to a number value");
				return nullptr;
			}
			*p++ = static_cast<T_Elem>(num);
			//*p++ = static_cast<T_Elem>(pValue->GetNumber());
		}
	} else {
		if (valList.GetValueTypeOfElements() != VTYPE_list) {
			sig.SetError(ERR_ValueError, "invalid format of array initializer");
			return false;
		}
		foreach_const (ValueList, pValue, valList) {
			if (!CreateFromList_Sub(sig, dims, pDim + 1, p, pValue->GetList())) return false;
		}
	}
	return true;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromList(Signal &sig, const ValueList &valList)
{
	Array::Dimensions dims;
	for (const ValueList *pValList = &valList; ; ) {
		dims.push_back(Array::Dimension(pValList->size()));
		if (pValList->empty() || !pValList->front().Is_list()) break;
		pValList = &pValList->front().GetList();
	}
	AutoPtr<ArrayT> pArrayT(ArrayT::Create(dims));
	T_Elem *p = pArrayT->GetPointer();
	if (!CreateFromList_Sub(sig, dims, dims.begin(), p, valList)) return nullptr;
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromIterator(Environment &env, Iterator *pIterator)
{
	size_t len = pIterator->GetLengthEx(env);
	if (env.IsSignalled()) return nullptr;
	AutoPtr<ArrayT> pArrayT(new ArrayT(len));
	AutoPtr<Iterator> pIteratorWork(pIterator->Clone());
	T_Elem *p = pArrayT->GetPointer();
	Value value;
	while (pIteratorWork->Next(env, value)) {
		bool successFlag = false;
		Number num = value.ToNumber(false, successFlag);
		if (!successFlag) {
			env.SetError(ERR_ValueError, "failed to convert to a number value");
			return nullptr;
		}
		*p++ = static_cast<T_Elem>(num);
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromExpr(Environment &env, const Expr *pExpr)
{
	AutoPtr<Environment> pEnvLister(env.Derive(ENVTYPE_lister));
	Value result = pExpr->Exec(*pEnvLister, nullptr);
	if (!result.Is_list()) return nullptr;
	return ArrayT<T_Elem>::CreateFromList(env.GetSignal(), result.GetList());
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateIdentity(size_t n)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(n, n));
	pArrayT->FillZero();
	T_Elem *p = pArrayT->GetPointer();
	size_t stride = n + 1;
	for (size_t i = 0; i < n; i++, p += stride) *p = 1;
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateRange(Double numBegin, Double numEnd, Double numStep)
{
	int numSamples = 0;
	if (numEnd > numBegin) {
		Double numRange = numEnd - numBegin;
		numSamples = static_cast<int>((numRange - 1) / numStep) + 1;
	} else {
		Double numRange = numBegin - numEnd;
		numSamples = static_cast<int>(-(numRange - 1) / numStep) + 1;
	}
	if (numSamples < 0) numSamples = 0;
	AutoPtr<ArrayT> pArrayT(new ArrayT(numSamples));
	T_Elem *p = pArrayT->GetPointer();
	for (size_t i = 0; i < numSamples; i++) {
		p[i] = static_cast<T_Elem>(numBegin + numStep * i);
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateInterval(
	Double numBegin, Double numEnd, int numSamples, Double numDenom, int iFactor)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(numSamples));
	T_Elem *p = pArrayT->GetPointer();
	for (int i = 0; i < numSamples; i++, iFactor++) {
		p[i] = static_cast<T_Elem>((numEnd - numBegin) * iFactor / numDenom + numBegin);
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateOnes(const ValueList &valList)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(valList);
	pArrayT->AllocMemory();
	pArrayT->Fill(1);
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateZeros(const ValueList &valList)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(valList);
	pArrayT->AllocMemory();
	pArrayT->FillZero();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateRands(const ValueList &valList, UInt range)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(valList);
	pArrayT->AllocMemory();
	pArrayT->FillRand(range);
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateRandsNormal(const ValueList &valList, double mu, double sigma)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(valList);
	pArrayT->AllocMemory();
	pArrayT->FillRandNormal(mu, sigma);
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateRotation(double rad, bool transFlag, double xTrans, double yTrans)
{
#if 0
	int sizeMat = transFlag? 3 : 2;
	Number numCos = ::cos(rad), numSin = ::sin(rad);
	AutoPtr<Matrix> pMat(new Matrix(sizeMat, sizeMat));
	Elements &elements = pMat->GetElements();
	// row-1
	elements.push_back(Value(numCos));
	elements.push_back(Value(-numSin));
	if (transFlag) {
		elements.push_back(Value(xTrans));
	}
	// row-2
	elements.push_back(Value(numSin));
	elements.push_back(Value(numCos));
	if (transFlag) {
		elements.push_back(Value(yTrans));
		// row-3
		elements.push_back(Value::Zero);
		elements.push_back(Value::Zero);
		elements.push_back(Value::One);
	}
	return pMat.release();
#endif
	return nullptr;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateRotationX(double rad, bool transFlag, double xTrans, double yTrans, double zTrans)
{
#if 0
	int sizeMat = transFlag? 4 : 3;
	Number numCos = ::cos(rad), numSin = ::sin(rad);
	AutoPtr<Matrix> pMat(new Matrix(sizeMat, sizeMat));
	Elements &elements = pMat->GetElements();
	// row-1
	elements.push_back(Value::One);
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	if (transFlag) {
		elements.push_back(Value(xTrans));
	}
	// row-2
	elements.push_back(Value::Zero);
	elements.push_back(Value(numCos));
	elements.push_back(Value(-numSin));
	if (transFlag) {
		elements.push_back(Value(yTrans));
	}
	// row-3
	elements.push_back(Value::Zero);
	elements.push_back(Value(numSin));
	elements.push_back(Value(numCos));
	if (transFlag) {
		elements.push_back(Value(zTrans));
		// row-4
		elements.push_back(Value::Zero);
		elements.push_back(Value::Zero);
		elements.push_back(Value::Zero);
		elements.push_back(Value::One);
	}
	return pMat.release();
#endif
	return nullptr;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateRotationY(double rad, bool transFlag, double xTrans, double yTrans, double zTrans)
{
#if 0
	int sizeMat = transFlag? 4 : 3;
	Number numCos = ::cos(rad), numSin = ::sin(rad);
	AutoPtr<Matrix> pMat(new Matrix(sizeMat, sizeMat));
	Elements &elements = pMat->GetElements();
	// row-1
	elements.push_back(Value(numCos));
	elements.push_back(Value::Zero);
	elements.push_back(Value(numSin));
	if (transFlag) {
		elements.push_back(Value(xTrans));
	}
	// row-2
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	elements.push_back(Value::Zero);
	if (transFlag) {
		elements.push_back(Value(yTrans));
	}
	// row-3
	elements.push_back(Value(-numSin));
	elements.push_back(Value::Zero);
	elements.push_back(Value(numCos));
	if (transFlag) {
		elements.push_back(Value(zTrans));
		// row-4
		elements.push_back(Value::Zero);
		elements.push_back(Value::Zero);
		elements.push_back(Value::Zero);
		elements.push_back(Value::One);
	}
	return pMat.release();
#endif
	return nullptr;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateRotationZ(double rad, bool transFlag, double xTrans, double yTrans, double zTrans)
{
#if 0
	int sizeMat = transFlag? 4 : 3;
	Number numCos = ::cos(rad), numSin = ::sin(rad);
	AutoPtr<Matrix> pMat(new Matrix(sizeMat, sizeMat));
	Elements &elements = pMat->GetElements();
	// row-1
	elements.push_back(Value(numCos));
	elements.push_back(Value(-numSin));
	elements.push_back(Value::Zero);
	if (transFlag) {
		elements.push_back(Value(xTrans));
	}
	// row-2
	elements.push_back(Value(numSin));
	elements.push_back(Value(numCos));
	elements.push_back(Value::Zero);
	if (transFlag) {
		elements.push_back(Value(yTrans));
	}
	// row-3
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	if (transFlag) {
		elements.push_back(Value(zTrans));
		// row-4
		elements.push_back(Value::Zero);
		elements.push_back(Value::Zero);
		elements.push_back(Value::Zero);
		elements.push_back(Value::One);
	}
	return pMat.release();
#endif
	return nullptr;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateScale2D(double xScale, double yScale)
{
#if 0
	AutoPtr<Matrix> pMat(new Matrix(3, 3));
	Elements &elements = pMat->GetElements();
	// row-1
	elements.push_back(Value(xScale));
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	// row-2
	elements.push_back(Value::Zero);
	elements.push_back(Value(yScale));
	elements.push_back(Value::Zero);
	// row-3
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	return pMat.release();
#endif
	return nullptr;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateScale3D(double xScale, double yScale, double zScale)
{
#if 0
	AutoPtr<Matrix> pMat(new Matrix(4, 4));
	Elements &elements = pMat->GetElements();
	// row-1
	elements.push_back(Value(xScale));
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	// row-2
	elements.push_back(Value::Zero);
	elements.push_back(Value(yScale));
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	// row-3
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value(zScale));
	elements.push_back(Value::Zero);
	// row-4
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	return pMat.release();
#endif
	return nullptr;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateTranslate2D(double xTrans, double yTrans)
{
#if 0
	AutoPtr<Matrix> pMat(new Matrix(3, 3));
	Elements &elements = pMat->GetElements();
	// row-1
	elements.push_back(Value::One);
	elements.push_back(Value::Zero);
	elements.push_back(Value(xTrans));
	// row-2
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	elements.push_back(Value(yTrans));
	// row-3
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	return pMat.release();
#endif
	return nullptr;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateTranslate3D(double xTrans, double yTrans, double zTrans)
{
#if 0
	AutoPtr<Matrix> pMat(new Matrix(4, 4));
	Elements &elements = pMat->GetElements();
	// row-1
	elements.push_back(Value::One);
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value(xTrans));
	// row-2
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	elements.push_back(Value::Zero);
	elements.push_back(Value(yTrans));
	// row-3
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	elements.push_back(Value(zTrans));
	// row-4
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::Zero);
	elements.push_back(Value::One);
	return pMat.release();
#endif
	return nullptr;
}

//-----------------------------------------------------------------------------
// Iterator_ArrayT_Each
//-----------------------------------------------------------------------------
template<typename T_Elem>
size_t Iterator_ArrayT_Each<T_Elem>::GetLength() const
{
	return _flatFlag? _pArrayT->GetElemNum() : _pArrayT->GetDimensions().front().GetSize();
}

template<typename T_Elem>
Iterator *Iterator_ArrayT_Each<T_Elem>::GetSource()
{
	return nullptr;
}

template<typename T_Elem>
bool Iterator_ArrayT_Each<T_Elem>::DoNext(Environment &env, Value &value)
{
	if (_flatFlag) {
		if (_idx >= _pArrayT->GetElemNum()) return false;
		value = Value(_pArrayT->GetPointer()[_idx]);
	} else {
		const Array::Dimensions &dims = _pArrayT->GetDimensions();
		Array::Dimensions::const_iterator pDim = dims.begin();
		if (_idx >= pDim->GetSize()) return false;
		if (pDim + 1 == dims.end()) {
			value = Value(_pArrayT->GetPointer()[_idx]);
		} else {
			size_t offsetBase = _pArrayT->GetOffsetBase() + pDim->GetStride() * _idx;
			AutoPtr<ArrayT<T_Elem> > pArrayRtn(
				new ArrayT<T_Elem>(_pArrayT->GetMemory().Reference(), offsetBase));
			pArrayRtn->SetDimensions(pDim + 1, dims.end());
			value = Value(new Object_array(env, pArrayRtn.release()));
		}
	}
	_idx++;
	return true;
}

template<typename T_Elem>
String Iterator_ArrayT_Each<T_Elem>::ToString() const
{
	String rtn;
	rtn = "array";
	return rtn;
}

template<typename T_Elem>
void Iterator_ArrayT_Each<T_Elem>::GatherFollower(
	Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//------------------------------------------------------------------------------
// Realization of ArrayT
//------------------------------------------------------------------------------
ImplementArrayT(Int8)
ImplementArrayT(UInt8)
ImplementArrayT(Int16)
ImplementArrayT(UInt16)
ImplementArrayT(Int32)
ImplementArrayT(UInt32)
ImplementArrayT(Int64)
ImplementArrayT(UInt64)
ImplementArrayT(Float)
ImplementArrayT(Double)
ImplementArrayT(Complex)

//------------------------------------------------------------------------------
// Realization of Iterator_ArrayT_Each
//------------------------------------------------------------------------------
template class Iterator_ArrayT_Each<Int8>;
template class Iterator_ArrayT_Each<UInt8>;
template class Iterator_ArrayT_Each<Int16>;
template class Iterator_ArrayT_Each<UInt16>;
template class Iterator_ArrayT_Each<Int32>;
template class Iterator_ArrayT_Each<UInt32>;
template class Iterator_ArrayT_Each<Int64>;
template class Iterator_ArrayT_Each<UInt64>;
template class Iterator_ArrayT_Each<Float>;
template class Iterator_ArrayT_Each<Double>;

}
