//-----------------------------------------------------------------------------
// Gura jpeg module
//-----------------------------------------------------------------------------
#ifndef __MODULE_JPEG_H__
#define __MODULE_JPEG_H__
#include <gura.h>
extern "C" {
#include <jpeglib.h>
#include <jerror.h>
#include <setjmp.h>
}

Gura_BeginModule(jpeg)

Gura_DeclareUserSymbol(id);
Gura_DeclareUserSymbol(name);
Gura_DeclareUserSymbol(symbol);
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(value);
Gura_DeclareUserSymbol(ifd);
Gura_DeclareUserSymbol(ifd0);
Gura_DeclareUserSymbol(ifd1);
Gura_DeclareUserSymbol(Exif);
Gura_DeclareUserSymbol(Interoperability);
Gura_DeclareUserSymbol(GPSInfo);

//-----------------------------------------------------------------------------
// data types
//-----------------------------------------------------------------------------
enum {
	SIZE_IFDHeader	= 2,
	SIZE_TagRaw		= 12,
};

enum {
	MARKER_SOI	= 0xffd8,
	MARKER_APP1	= 0xffe1,
};

enum {
	TYPE_BYTE		= 1,
	TYPE_ASCII		= 2,
	TYPE_SHORT		= 3,
	TYPE_LONG		= 4,
	TYPE_RATIONAL	= 5,
	TYPE_UNDEFINED	= 7,
	TYPE_SLONG		= 9,
	TYPE_SRATIONAL	= 10,
};

enum {
	UNITSIZE_BYTE		= 1,
	UNITSIZE_ASCII		= 1,
	UNITSIZE_SHORT		= 2,
	UNITSIZE_LONG		= 4,
	UNITSIZE_RATIONAL	= 8,
	UNITSIZE_UNDEFINED	= 0,
	UNITSIZE_SLONG		= 4,
	UNITSIZE_SRATIONAL	= 8,
};

enum {
	TAG_invalid						= -1,
};

// 4.6.4 TIFF Rev.6.0 Attribute Information
enum {
	// A. Tags relating to image data structure
	TAG_ImageWidth					= 0x0100,
	TAG_ImageLength					= 0x0101,
	TAG_BitsPerSample				= 0x0102,
	TAG_Compression					= 0x0103,
	TAG_PhotometricInterpretation	= 0x0106,
	TAG_Orientation					= 0x0112,
	TAG_SamplesPerPixel				= 0x0115,
	TAG_PlanarConfiguration			= 0x011c,
	TAG_YCbCrSubSampling			= 0x0212,
	TAG_YCbCrPositioning			= 0x0213,
	TAG_XResolution					= 0x011a,
	TAG_YResolution					= 0x011b,
	TAG_ResolutionUnit				= 0x0128,
	// B. Tags relating to recording offset
	TAG_StripOffsets				= 0x0111,
	TAG_RowsPerStrip				= 0x0116,
	TAG_StripByteCounts				= 0x0117,
	TAG_JPEGInterchangeFormat		= 0x0201,
	TAG_JPEGInterchangeFormatLength	= 0x0202,
	// C. Tags relating to image data characteristics
	TAG_TransferFunction			= 0x012d,
	TAG_WhitePoint					= 0x013e,
	TAG_PrimaryChromaticities		= 0x013f,
	TAG_YCbCrCoefficients			= 0x0211,
	TAG_ReferenceBlackWhite			= 0x0214,
	// D. Other tags
	TAG_DateTime					= 0x0132,
	TAG_ImageDescription			= 0x010e,
	TAG_Make						= 0x010f,
	TAG_Model						= 0x0110,
	TAG_Software					= 0x0131,
	TAG_Artist						= 0x013b,
	TAG_Copyright					= 0x8298,
	// Pointers
	TAG_ExifIFDPointer				= 0x8769,
	TAG_GPSInfoIFDPointer			= 0x8825,
	TAG_InteroperabilityIFDPointer	= 0xa005,
};

// 4.6.5 Exif IFD Attribute Information
enum {
	// A. Tags Relating to Version
	TAG_ExifVersion					= 0x9000,
	TAG_FlashPixVersion				= 0xa000,
	// B. Tag Relating to Image Data Characteristics
	TAG_ColorSpace					= 0xa001,
	// C. Tags Relating to Image Configuration
	TAG_ComponentsConfiguration		= 0x9101,
	TAG_CompressedBitsPerPixel		= 0x9102,
	TAG_PixelXDimension				= 0xa002,
	TAG_PixelYDimension				= 0xa003,
	// D. Tags Relating to User Information
	TAG_MakerNote					= 0x927c,
	TAG_UserComment					= 0x9286,
	// E. Tags Relating to Related File Information
	TAG_RelatedSoundFile			= 0xa004,
	// F. Tags Relating to Date and Time
	TAG_DateTimeOriginal			= 0x9003,
	TAG_DateTimeDigitized			= 0x9004,
	TAG_SubSecTime					= 0x9290,
	TAG_SubSecTimeOriginal			= 0x9291,
	TAG_SubSecTimeDigitized			= 0x9292,
	// G. Tags Relating to Picture-Taking Conditions
	TAG_ExposureTime				= 0x829a,
	TAG_FNumber						= 0x829d,
	TAG_ExposureProgram				= 0x8822,
	TAG_SpectralSensitivity			= 0x8824,
	TAG_ISOSpeedRatings				= 0x8827,
	TAG_OECF						= 0x8828,
	TAG_ShutterSpeedValue			= 0x9201,
	TAG_ApertureValue				= 0x9202,
	TAG_BrightnessValue				= 0x9203,
	TAG_ExposureBiasValue			= 0x9204,
	TAG_MaxApertureValue			= 0x9205,
	TAG_SubjectDistance				= 0x9206,
	TAG_MeteringMode				= 0x9207,
	TAG_LightSource					= 0x9208,
	TAG_Flash						= 0x9209,
	TAG_FocalLength					= 0x920a,
	TAG_SubjectArea					= 0x9214,
	TAG_FlashEnergy					= 0xa20b,
	TAG_SpatialFrequencyResponse	= 0xa20c,
	TAG_FocalPlaneXResolution		= 0xa20e,
	TAG_FocalPlaneYResolution		= 0xa20f,
	TAG_FocalPlaneResolutionUnit	= 0xa210,
	TAG_SubjectLocation				= 0xa214,
	TAG_ExposureIndex				= 0xa215,
	TAG_SensingMethod				= 0xa217,
	TAG_FileSource					= 0xa300,
	TAG_SceneType					= 0xa301,
	TAG_CFAPattern					= 0xa302,
	TAG_CustomRendered				= 0xa401,
	TAG_ExposureMode				= 0xa402,
	TAG_WhiteBalance				= 0xa403,
	TAG_DigitalZoomRatio			= 0xa404,
	TAG_FocalLengthIn35mmFilm		= 0xa405,
	TAG_SceneCaptureType 			= 0xa406,
	TAG_GainControl					= 0xa407,
	TAG_Contrast					= 0xa408,
	TAG_Saturation					= 0xa409,
	TAG_Sharpness					= 0xa40a,
	TAG_DeviceSettingDescription	= 0xa40b,
	TAG_SubjectDistanceRange		= 0xa40c,
	// H. Other Tags
	TAG_ImageUniqueID				= 0xa420,
};

// 4.6.6 GPS Attribute Information
enum {
	// A. Tags Relating to GPS
	TAG_GPSVersionID				= 0x0000,
	TAG_GPSLatitudeRef				= 0x0001,
	TAG_GPSLatitude					= 0x0002,
	TAG_GPSLongitudeRef				= 0x0003,
	TAG_GPSLongitude				= 0x0004,
	TAG_GPSAltitudeRef				= 0x0005,
	TAG_GPSAltitude					= 0x0006,
	TAG_GPSTimeStamp				= 0x0007,
	TAG_GPSSatellites				= 0x0008,
	TAG_GPSStatus					= 0x0009,
	TAG_GPSMeasureMode				= 0x000a,
	TAG_GPSDOP						= 0x000b,
	TAG_GPSSpeedRef					= 0x000c,
	TAG_GPSSpeed					= 0x000d,
	TAG_GPSTrackRef					= 0x000e,
	TAG_GPSTrack					= 0x000f,
	TAG_GPSImgDirectionRef			= 0x0010,
	TAG_GPSImgDirection				= 0x0011,
	TAG_GPSMapDatum					= 0x0012,
	TAG_GPSDestLatitudeRef			= 0x0013,
	TAG_GPSDestLatitude				= 0x0014,
	TAG_GPSDestLongitudeRef			= 0x0015,
	TAG_GPSDestLongitude			= 0x0016,
	TAG_GPSBearingRef				= 0x0017,
	TAG_GPSBearing					= 0x0018,
	TAG_GPSDestDistanceRef			= 0x0019,
	TAG_GPSDestDistance				= 0x001a,
	TAG_GPSProcessingMethod			= 0x001b,
	TAG_GPSAreaInformation			= 0x001c,
	TAG_GPSDateStamp				= 0x001d,
	TAG_GPSDifferential				= 0x001e,
};

// Tags declared in an IFD pointed by InteroperabilityIFDPointer
enum {
	TAG_InteroperabilityIndex		= 0x0001,
	TAG_InteroperabilityVersion		= 0x0002,
	TAG_RelatedImageWidth			= 0x1001,
	TAG_RelatedImageHeight			= 0x1002,
};

struct Header {
	XPackedUShort_BE(SOI);
	XPackedUShort_BE(APP1);
	XPackedUShort_BE(Size);
	char ExifCode[6];
};

struct TIFF_BE {
	XPackedUShort_BE(Code);
	XPackedULong_BE(Offset0thIFD);
};

struct TIFF_LE {
	XPackedUShort_LE(Code);
	XPackedULong_LE(Offset0thIFD);
};

struct IFDHeader_BE {
	XPackedUShort_BE(TagCount);
};

struct IFDHeader_LE {
	XPackedUShort_LE(TagCount);
};

struct RATIONAL_BE {
	XPackedULong_BE(numerator);
	XPackedULong_BE(denominator);
};

struct RATIONAL_LE {
	XPackedULong_LE(numerator);
	XPackedULong_LE(denominator);
};

struct SRATIONAL_BE {
	XPackedULong_BE(numerator);
	XPackedULong_BE(denominator);
};

struct SRATIONAL_LE {
	XPackedULong_LE(numerator);
	XPackedULong_LE(denominator);
};

struct SHORT_BE {
	XPackedUShort_BE(num);
};

struct SHORT_LE {
	XPackedUShort_LE(num);
};

struct LONG_BE {
	XPackedULong_BE(num);
};

struct LONG_LE {
	XPackedULong_LE(num);
};

struct SLONG_BE {
	XPackedULong_BE(num);
};

struct SLONG_LE {
	XPackedULong_LE(num);
};

union ValueRaw_BE {
	char BYTE[4];
	char ASCII[4];
	struct {
		XPackedUShort_BE(num);
		XPackedUShort_BE(second);
	} SHORT;
	struct {
		XPackedULong_BE(num);
	} LONG;
	struct {
		XPackedULong_BE(num);
	} SLONG;
};

struct TagRaw_BE {
	XPackedUShort_BE(Id);
	XPackedUShort_BE(Type);
	XPackedULong_BE(Count);
	unsigned char ValueRaw;
};

union ValueRaw_LE {
	char BYTE[4];
	char ASCII[4];
	struct {
		XPackedUShort_LE(num);
		XPackedUShort_LE(second);
	} SHORT;
	struct {
		XPackedULong_LE(num);
	} LONG;
	struct {
		XPackedULong_LE(num);
	} SLONG;
};

struct TagRaw_LE {
	XPackedUShort_LE(Id);
	XPackedUShort_LE(Type);
	XPackedULong_LE(Count);
	unsigned char ValueRaw;
};

struct TagInfo {
	unsigned short id;
	const char *name;
	unsigned short type;
	const char *nameForIFD;
};

struct TypeInfo {
	unsigned short type;
	const char *name;
	size_t unitSize;
};

//-----------------------------------------------------------------------------
// ImageStreamer_JPEG
//-----------------------------------------------------------------------------
class ImageStreamer_JPEG : public ImageStreamer {
public:
	inline ImageStreamer_JPEG() : ImageStreamer("jpeg") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
public:
	static bool ReadStream(Signal sig, Object_image *pObjImage, Stream &stream);
	static bool WriteStream(Signal sig,
						Object_image *pObjImage, Stream &stream, int quality);
};

//-----------------------------------------------------------------------------
// ErrorMgr
//-----------------------------------------------------------------------------
struct ErrorMgr {
	jpeg_error_mgr pub;
	jmp_buf jmpenv;
	Signal &_sig;
	inline ErrorMgr(Signal &sig) : _sig(sig) {}
	static void error_exit(j_common_ptr cinfo);
};

//-----------------------------------------------------------------------------
// SourceMgr
//-----------------------------------------------------------------------------
struct SourceMgr {
	jpeg_source_mgr pub;
	Signal *pSig;
	Stream *pStream;
	JOCTET *buff;
	bool firstFlag;
	enum { BuffSize = 4096 };
	static void Setup(j_decompress_ptr cinfo, Signal *pSig, Stream *pStream);
	static void init_source(j_decompress_ptr cinfo);
	static boolean fill_input_buffer(j_decompress_ptr cinfo);
	static void skip_input_data(j_decompress_ptr cinfo, long num_bytes);
	static void term_source(j_decompress_ptr cinfo);
};

//-----------------------------------------------------------------------------
// DestinationMgr
//-----------------------------------------------------------------------------
struct DestinationMgr {
	jpeg_destination_mgr pub;
	Signal *pSig;
	Stream *pStream;
	JOCTET *buffer;
	enum { BuffSize = 4096 };
	static void Setup(j_compress_ptr cinfo, Signal *pSig, Stream *pStream);
	static void init_destination(j_compress_ptr cinfo);
	static boolean empty_output_buffer(j_compress_ptr cinfo);
	static void term_destination(j_compress_ptr cinfo);
};

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
void SetError_InvalidFormat(Signal &sig);
bool ReadBuff(Signal sig, Stream &stream, void *buff, size_t bytes);
const TagInfo *TagIdToInfo(const Symbol *pSymbolOfIFD, unsigned short id);
const TypeInfo *TypeToInfo(unsigned short type);

}}

#endif
