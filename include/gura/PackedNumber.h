#ifndef __GURA_PACKEDNUMBER_H__
#define __GURA_PACKEDNUMBER_H__

#define Gura_PackedUShort_LE(x) \
unsigned char x##_s_b0, x##_s_b8

#define Gura_PackedUShort_BE(x) \
unsigned char x##_s_b8, x##_s_b0

#define Gura_PackedULong_LE(x) \
unsigned char x##_l_b0, x##_l_b8, x##_l_b16, x##_l_b24

#define Gura_PackedULong_BE(x) \
unsigned char x##_l_b24, x##_l_b16, x##_l_b8, x##_l_b0

#define Gura_PackedUInt64_LE(x) \
unsigned char x##_q_b0, x##_q_b8, x##_q_b16, x##_q_b24, x##_q_b32, x##_q_b40, x##_q_b48, x##_q_b56

#define Gura_PackedUInt64_BE(x) \
unsigned char x##_q_b56, x##_q_b48, x##_q_b40, x##_q_b32, x##_q_b24, x##_q_b16, x##_q_b8, x##_q_b0

#define Gura_PackedShort_LE(x) Gura_PackedUShort_LE(x)
#define Gura_PackedShort_BE(x) Gura_PackedUShort_BE(x)

#define Gura_PackedLong_LE(x) Gura_PackedULong_LE(x)
#define Gura_PackedLong_BE(x) Gura_PackedULong_BE(x)

#define Gura_PackedInt64_LE(x) Gura_PackedUInt64_LE(x)
#define Gura_PackedInt64_BE(x) Gura_PackedUInt64_BE(x)

#define Gura_PackUShort(x, n) ( \
	x##_s_b0 = static_cast<unsigned char>((static_cast<unsigned short>(n) >> 0) & 0xff), \
	x##_s_b8 = static_cast<unsigned char>((static_cast<unsigned short>(n) >> 8) & 0xff) \
)

#define Gura_PackULong(x, n) ( \
	x##_l_b0 = static_cast<unsigned char>((static_cast<unsigned long>(n) >> 0) & 0xff), \
	x##_l_b8 = static_cast<unsigned char>((static_cast<unsigned long>(n) >> 8) & 0xff), \
	x##_l_b16 = static_cast<unsigned char>((static_cast<unsigned long>(n) >> 16) & 0xff), \
	x##_l_b24 = static_cast<unsigned char>((static_cast<unsigned long>(n) >> 24) & 0xff) \
)

#define Gura_PackUInt64(x, n) ( \
	x##_q_b0 = static_cast<unsigned char>((static_cast<uint64>(n) >> 0) & 0xff), \
	x##_q_b8 = static_cast<unsigned char>((static_cast<uint64>(n) >> 8) & 0xff), \
	x##_q_b16 = static_cast<unsigned char>((static_cast<uint64>(n) >> 16) & 0xff), \
	x##_q_b24 = static_cast<unsigned char>((static_cast<uint64>(n) >> 24) & 0xff) \
	x##_q_b32 = static_cast<unsigned char>((static_cast<uint64>(n) >> 32) & 0xff) \
	x##_q_b40 = static_cast<unsigned char>((static_cast<uint64>(n) >> 40) & 0xff) \
	x##_q_b48 = static_cast<unsigned char>((static_cast<uint64>(n) >> 48) & 0xff) \
	x##_q_b56 = static_cast<unsigned char>((static_cast<uint64>(n) >> 56) & 0xff) \
)

#define Gura_UnpackUShort(x) ( \
	(static_cast<unsigned short>(x##_s_b0) << 0) | \
	(static_cast<unsigned short>(x##_s_b8) << 8) \
)

#define Gura_UnpackULong(x) ( \
	(static_cast<unsigned long>(x##_l_b0) << 0) | \
	(static_cast<unsigned long>(x##_l_b8) << 8) | \
	(static_cast<unsigned long>(x##_l_b16) << 16) | \
	(static_cast<unsigned long>(x##_l_b24) << 24) \
)

#define Gura_UnpackUInt64(x) ( \
	(static_cast<uint64>(x##_q_b0) << 0) | \
	(static_cast<uint64>(x##_q_b8) << 8) | \
	(static_cast<uint64>(x##_q_b16) << 16) | \
	(static_cast<uint64>(x##_q_b24) << 24) \
	(static_cast<uint64>(x##_q_b32) << 32) \
	(static_cast<uint64>(x##_q_b40) << 40) \
	(static_cast<uint64>(x##_q_b48) << 48) \
	(static_cast<uint64>(x##_q_b56) << 56) \
)

#define Gura_PackShort(x, n) Gura_PackUShort(x, n)
#define Gura_PackLong(x, n) Gura_PackULong(x, n)
#define Gura_PackInt64(x, n) Gura_PackUInt64(x, n)

#define Gura_UnpackShort(x) static_cast<short>(Gura_UnpackUShort(x))
#define Gura_UnpackLong(x) static_cast<long>(Gura_UnpackULong(x))
#define Gura_UnpackInt64(x) static_cast<int64>(Gura_UnpackUInt64(x))

#endif
