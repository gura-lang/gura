//=============================================================================
// Array
//=============================================================================
#include "stdafx.h"

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
		stream.Printf(sig, fmt, *reinterpret_cast<const T_ElemCast *>(p));
		col++;
		if (col == cols) {
			stream.Printf(sig, "\n");
			col = 0;
		}
	}
	if (col != 0) stream.Printf(sig, "\n");
}

template<> void Array<char>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<char, UChar>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetSize());
}

template<> void Array<UChar>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UChar, UChar>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetSize());
}

template<> void Array<short>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<short, UShort>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetSize());
}

template<> void Array<UShort>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UShort, UShort>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetSize());
}

template<> void Array<long>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<long, ULong>(sig, stream, upperFlag? "%08lX" : "%08lx", 8, GetPointer(), GetSize());
}

template<> void Array<ULong>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<ULong, ULong>(sig, stream, upperFlag? "%08lX" : "%08lx", 8, GetPointer(), GetSize());
}

template<> void Array<int>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<int, ULong>(sig, stream, upperFlag? "%08lX" : "%08lx", 8, GetPointer(), GetSize());
}

template<> void Array<UInt>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt, ULong>(sig, stream, upperFlag? "%08lX" : "%08lx", 8, GetPointer(), GetSize());
}

template<> void Array<float>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<float, ULong>(sig, stream, upperFlag? "%08lX" : "%08lx", 8, GetPointer(), GetSize());
}

template<> void Array<double>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<double, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetSize());
}

}
