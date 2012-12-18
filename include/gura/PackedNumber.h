#ifndef __PACKEDNUMBER__
#define __PACKEDNUMBER__

#define XPackedUShort_LE(x) \
unsigned char x##_s_b0, x##_s_b8

#define XPackedUShort_BE(x) \
unsigned char x##_s_b8, x##_s_b0

#define XPackedULong_LE(x) \
unsigned char x##_l_b0, x##_l_b8, x##_l_b16, x##_l_b24

#define XPackedULong_BE(x) \
unsigned char x##_l_b24, x##_l_b16, x##_l_b8, x##_l_b0

#define XPackedUInt64_LE(x) \
unsigned char x##_q_b0, x##_q_b8, x##_q_b16, x##_q_b24, x##_q_b32, x##_q_b40, x##_q_b48, x##_q_b56

#define XPackedUInt64_BE(x) \
unsigned char x##_q_b56, x##_q_b48, x##_q_b40, x##_q_b32, x##_q_b24, x##_q_b16, x##_q_b8, x##_q_b0

#define XPackedShort_LE(x) XPackedUShort_LE(x)
#define XPackedShort_BE(x) XPackedUShort_BE(x)

#define XPackedLong_LE(x) XPackedULong_LE(x)
#define XPackedLong_BE(x) XPackedULong_BE(x)

#define XPackedInt64_LE(x) XPackedUInt64_LE(x)
#define XPackedInt64_BE(x) XPackedUInt64_BE(x)

#define XPackUShort(x, n) ( \
	x##_s_b0 = static_cast<unsigned char>((static_cast<unsigned short>(n) >> 0) & 0xff), \
	x##_s_b8 = static_cast<unsigned char>((static_cast<unsigned short>(n) >> 8) & 0xff) \
)

#define XPackULong(x, n) ( \
	x##_l_b0 = static_cast<unsigned char>((static_cast<unsigned long>(n) >> 0) & 0xff), \
	x##_l_b8 = static_cast<unsigned char>((static_cast<unsigned long>(n) >> 8) & 0xff), \
	x##_l_b16 = static_cast<unsigned char>((static_cast<unsigned long>(n) >> 16) & 0xff), \
	x##_l_b24 = static_cast<unsigned char>((static_cast<unsigned long>(n) >> 24) & 0xff) \
)

#define XPackUInt64(x, n) ( \
	x##_q_b0 = static_cast<unsigned char>((static_cast<uint64>(n) >> 0) & 0xff), \
	x##_q_b8 = static_cast<unsigned char>((static_cast<uint64>(n) >> 8) & 0xff), \
	x##_q_b16 = static_cast<unsigned char>((static_cast<uint64>(n) >> 16) & 0xff), \
	x##_q_b24 = static_cast<unsigned char>((static_cast<uint64>(n) >> 24) & 0xff) \
	x##_q_b32 = static_cast<unsigned char>((static_cast<uint64>(n) >> 32) & 0xff) \
	x##_q_b40 = static_cast<unsigned char>((static_cast<uint64>(n) >> 40) & 0xff) \
	x##_q_b48 = static_cast<unsigned char>((static_cast<uint64>(n) >> 48) & 0xff) \
	x##_q_b56 = static_cast<unsigned char>((static_cast<uint64>(n) >> 56) & 0xff) \
)

#define XUnpackUShort(x) ( \
	(static_cast<unsigned short>(x##_s_b0) << 0) | \
	(static_cast<unsigned short>(x##_s_b8) << 8) \
)

#define XUnpackULong(x) ( \
	(static_cast<unsigned long>(x##_l_b0) << 0) | \
	(static_cast<unsigned long>(x##_l_b8) << 8) | \
	(static_cast<unsigned long>(x##_l_b16) << 16) | \
	(static_cast<unsigned long>(x##_l_b24) << 24) \
)

#define XUnpackUInt64(x) ( \
	(static_cast<uint64>(x##_q_b0) << 0) | \
	(static_cast<uint64>(x##_q_b8) << 8) | \
	(static_cast<uint64>(x##_q_b16) << 16) | \
	(static_cast<uint64>(x##_q_b24) << 24) \
	(static_cast<uint64>(x##_q_b32) << 32) \
	(static_cast<uint64>(x##_q_b40) << 40) \
	(static_cast<uint64>(x##_q_b48) << 48) \
	(static_cast<uint64>(x##_q_b56) << 56) \
)

#define XPackShort(x, n) XPackUShort(x, n)
#define XPackLong(x, n) XPackULong(x, n)
#define XPackInt64(x, n) XPackUInt64(x, n)

#define XUnpackShort(x) static_cast<short>(XUnpackUShort(x))
#define XUnpackLong(x) static_cast<long>(XUnpackULong(x))
#define XUnpackInt64(x) static_cast<int64>(XUnpackUInt64(x))

#endif
