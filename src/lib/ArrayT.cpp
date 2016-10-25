//=============================================================================
// ArrayT
//=============================================================================
#include "stdafx.h"
#include "gura/ArrayT.h"

namespace Gura {

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

template<> void ArrayT<Char>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Char, UChar>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetSize());
}

template<> void ArrayT<UChar>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UChar, UChar>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetSize());
}

template<> void ArrayT<Short>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Short, UShort>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetSize());
}

template<> void ArrayT<UShort>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UShort, UShort>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetSize());
}

template<> void ArrayT<Int32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int32, UInt32>(sig, stream, upperFlag? "%08X" : "%08x", 8, GetPointer(), GetSize());
}

template<> void ArrayT<UInt32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt32, UInt32>(sig, stream, upperFlag? "%08X" : "%08x", 8, GetPointer(), GetSize());
}

template<> void ArrayT<Int64>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int64, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetSize());
}

template<> void ArrayT<UInt64>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt64, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetSize());
}

template<> void ArrayT<float>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<float, ULong>(sig, stream, upperFlag? "%08lX" : "%08lx", 8, GetPointer(), GetSize());
}

template<> void ArrayT<double>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<double, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetSize());
}

}
