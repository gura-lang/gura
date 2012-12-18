//-----------------------------------------------------------------------------
// Gura emf (Enhanced Metafiles in Win32) module
//-----------------------------------------------------------------------------
#ifndef __MODULE_EMF_H__
#define __MODULE_EMF_H__
#include <gura.h>

Gura_BeginModule(emf)

//-----------------------------------------------------------------------------
// File structure
//-----------------------------------------------------------------------------
struct MetaHeader {
	enum { Size = 18 };
	XPackedUShort_LE(mtType);
	XPackedUShort_LE(mtHeaderSize);
	XPackedUShort_LE(mtVersion);
	XPackedULong_LE(mtSize);
	XPackedUShort_LE(mtNoObjects);
	XPackedULong_LE(mtMaxRecord);
	XPackedUShort_LE(mtNoParameters);
};

unsigned long _ENHMETA_SIGNATURE = 0x464d4520;

struct EnhMetaHeader {
	enum { Size = 88 };
	XPackedULong_LE(iType);				// Record type EMR_HEADER.
	XPackedULong_LE(nSize);				// Record size in bytes. This may be greater
										// than the sizeof(ENHMETAHEADER).
	XPackedLong_LE(rclBounds_left);		// Inclusive-inclusive bounds in device units.
	XPackedLong_LE(rclBounds_top);
	XPackedLong_LE(rclBounds_right);
	XPackedLong_LE(rclBounds_bottom);
	XPackedLong_LE(rclFrame_left);		// Inclusive-inclusive Picture Frame of 
	XPackedLong_LE(rclFrame_top);		// metafile in .01 mm units. 
	XPackedLong_LE(rclFrame_right);
	XPackedLong_LE(rclFrame_bottom);
	XPackedULong_LE(dSignature);		// Signature.  Must be ENHMETA_SIGNATURE.
	XPackedULong_LE(nVersion);			// Version number.
	XPackedULong_LE(nBytes);			// Size of the metafile in bytes.
	XPackedULong_LE(nRecords);			// Number of records in the metafile.
	XPackedUShort_LE(nHandles);			// Number of handles in the handle table.
										// Handle index zero is reserved.
	XPackedUShort_LE(sReserved);		// Reserved.  Must be zero.
	XPackedULong_LE(nDescription);		// Number of chars in the unicode description string.
										// This is 0 if there is no description string.
	XPackedULong_LE(offDescription);	// Offset to the metafile description record.
										// This is 0 if there is no description string.
	XPackedULong_LE(nPalEntries);		// Number of entries in the metafile palette.
	XPackedLong_LE(szlDevice_cx);		// Size of the reference device in pixels. 
	XPackedLong_LE(szlDevice_cy);
	XPackedLong_LE(szlMillimeters_cx);	// Size of the reference device in millimeters.
	XPackedLong_LE(szlMillimeters_cy);
};

struct MetaRecord {
	enum { Size = 6 };
	XPackedULong_LE(rdSize);			// Record size in bytes
	XPackedUShort_LE(rdFunction);		// Record type META_XXX
	//WORD rdParm[1];					// WORD array of parameters
};

struct EnhMetaRecord {
	enum { Size = 8 };
	XPackedULong_LE(iType);				// Record type EMR_XXX
	XPackedULong_LE(nSize);				// Record size in bytes
	//DWORD dParm[1];					// DWORD Array of parameters
};

//-----------------------------------------------------------------------------
// Function
//-----------------------------------------------------------------------------
class EMR_basement {
protected:
	unsigned long _iType;
	size_t _dwordsParms;
	char *_buff;
public:
	inline EMR_basement(unsigned long iType, size_t dwordsParms) :
					_iType(iType), _dwordsParms(dwordsParms), _buff(NULL) {
		size_t bytes = _dwordsParms * 4;
		if (bytes > 0) {
			_buff = new char [bytes];
			::memset(_buff, 0x00, bytes);
		}
	}
	virtual ~EMR_basement() {
		delete[] _buff;
	}
	bool Read(Signal sig, Stream &stream) {
		size_t bytes = _dwordsParms * 4;
		size_t bytesRead = stream.Read(sig, _buff, bytes);
		if (sig.IsSignalled()) return false;
		if (bytesRead < bytes) {
			sig.SetError(ERR_FormatError, "failed to read a record");
			return false;
		}
		return true;
	}
};

class EMR_SetMapMode : public EMR_basement {
public:
	enum { Type = 17 };
	struct Parms {
		XPackedLong_LE(fnMapMode);
	};
public:
	inline EMR_SetMapMode() : EMR_basement(Type, 1) {}
	inline EMR_SetMapMode(int fnMapMode) : EMR_basement(Type, 1) {
		Parms &parms = *reinterpret_cast<Parms *>(_buff);
		XPackLong(parms.fnMapMode, fnMapMode);
	}
};

class EMR_CreatePen : public EMR_basement {
public:
	enum { Type = 38 };
	struct Parms {
		XPackedLong_LE(fnPenStyle);
		XPackedLong_LE(nWidth);
		XPackedULong_LE(crColor);
	};
public:
	inline EMR_CreatePen() : EMR_basement(Type, 5) {}
	inline EMR_CreatePen(int fnMapMode) : EMR_basement(Type, 5) {
		Parms &parms = *reinterpret_cast<Parms *>(_buff);
		XPackLong(parms.fnMapMode, fnMapMode);
	}
};

}}

#endif
