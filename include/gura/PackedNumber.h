//=============================================================================
// PackedNumber
//=============================================================================
#ifndef __GURA_PACKEDNUMBER_H__
#define __GURA_PACKEDNUMBER_H__

#define Gura_PackedUInt16_LE(x) \
UChar x##_s_b0, x##_s_b8

#define Gura_PackedUInt16_BE(x) \
UChar x##_s_b8, x##_s_b0

#define Gura_PackedUInt32_LE(x) \
UChar x##_l_b0, x##_l_b8, x##_l_b16, x##_l_b24

#define Gura_PackedUInt32_BE(x) \
UChar x##_l_b24, x##_l_b16, x##_l_b8, x##_l_b0

#define Gura_PackedUInt64_LE(x) \
UChar x##_q_b0, x##_q_b8, x##_q_b16, x##_q_b24, x##_q_b32, x##_q_b40, x##_q_b48, x##_q_b56

#define Gura_PackedUInt64_BE(x) \
UChar x##_q_b56, x##_q_b48, x##_q_b40, x##_q_b32, x##_q_b24, x##_q_b16, x##_q_b8, x##_q_b0

#define Gura_PackedInt16_LE(x) Gura_PackedUInt16_LE(x)
#define Gura_PackedInt16_BE(x) Gura_PackedUInt16_BE(x)

#define Gura_PackedInt32_LE(x) Gura_PackedUInt32_LE(x)
#define Gura_PackedInt32_BE(x) Gura_PackedUInt32_BE(x)

#define Gura_PackedInt64_LE(x) Gura_PackedUInt64_LE(x)
#define Gura_PackedInt64_BE(x) Gura_PackedUInt64_BE(x)

#define Gura_PackUInt16(x, n) ( \
	x##_s_b0 = static_cast<UChar>((static_cast<UInt16>(n) >> 0) & 0xff), \
	x##_s_b8 = static_cast<UChar>((static_cast<UInt16>(n) >> 8) & 0xff) \
)

#define Gura_PackUInt32(x, n) ( \
	x##_l_b0 = static_cast<UChar>((static_cast<UInt32>(n) >> 0) & 0xff), \
	x##_l_b8 = static_cast<UChar>((static_cast<UInt32>(n) >> 8) & 0xff), \
	x##_l_b16 = static_cast<UChar>((static_cast<UInt32>(n) >> 16) & 0xff), \
	x##_l_b24 = static_cast<UChar>((static_cast<UInt32>(n) >> 24) & 0xff) \
)

#define Gura_PackUInt64(x, n) ( \
	x##_q_b0 = static_cast<UChar>((static_cast<UInt64>(n) >> 0) & 0xff), \
	x##_q_b8 = static_cast<UChar>((static_cast<UInt64>(n) >> 8) & 0xff), \
	x##_q_b16 = static_cast<UChar>((static_cast<UInt64>(n) >> 16) & 0xff), \
	x##_q_b24 = static_cast<UChar>((static_cast<UInt64>(n) >> 24) & 0xff) \
	x##_q_b32 = static_cast<UChar>((static_cast<UInt64>(n) >> 32) & 0xff) \
	x##_q_b40 = static_cast<UChar>((static_cast<UInt64>(n) >> 40) & 0xff) \
	x##_q_b48 = static_cast<UChar>((static_cast<UInt64>(n) >> 48) & 0xff) \
	x##_q_b56 = static_cast<UChar>((static_cast<UInt64>(n) >> 56) & 0xff) \
)

#define Gura_UnpackUInt16(x) ( \
	(static_cast<UInt16>(x##_s_b0) << 0) | \
	(static_cast<UInt16>(x##_s_b8) << 8) \
)

#define Gura_UnpackUInt32(x) ( \
	(static_cast<UInt32>(x##_l_b0) << 0) | \
	(static_cast<UInt32>(x##_l_b8) << 8) | \
	(static_cast<UInt32>(x##_l_b16) << 16) | \
	(static_cast<UInt32>(x##_l_b24) << 24) \
)

#define Gura_UnpackUInt64(x) ( \
	(static_cast<UInt64>(x##_q_b0) << 0) | \
	(static_cast<UInt64>(x##_q_b8) << 8) | \
	(static_cast<UInt64>(x##_q_b16) << 16) | \
	(static_cast<UInt64>(x##_q_b24) << 24) \
	(static_cast<UInt64>(x##_q_b32) << 32) \
	(static_cast<UInt64>(x##_q_b40) << 40) \
	(static_cast<UInt64>(x##_q_b48) << 48) \
	(static_cast<UInt64>(x##_q_b56) << 56) \
)

#define Gura_PackInt16(x, n) Gura_PackUInt16(x, n)
#define Gura_PackInt32(x, n) Gura_PackUInt32(x, n)
#define Gura_PackInt64(x, n) Gura_PackUInt64(x, n)

#define Gura_UnpackInt16(x) static_cast<Int16>(Gura_UnpackUInt16(x))
#define Gura_UnpackInt32(x) static_cast<Int32>(Gura_UnpackUInt32(x))
#define Gura_UnpackInt64(x) static_cast<int64>(Gura_UnpackUInt64(x))

#endif
