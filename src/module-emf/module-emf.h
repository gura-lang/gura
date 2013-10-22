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
	Gura_PackedUShort_LE(mtType);
	Gura_PackedUShort_LE(mtHeaderSize);
	Gura_PackedUShort_LE(mtVersion);
	Gura_PackedULong_LE(mtSize);
	Gura_PackedUShort_LE(mtNoObjects);
	Gura_PackedULong_LE(mtMaxRecord);
	Gura_PackedUShort_LE(mtNoParameters);
};

ULong _ENHMETA_SIGNATURE = 0x464d4520;

struct EnhMetaHeader {
	enum { Size = 88 };
	Gura_PackedULong_LE(iType);				// Record type EMR_HEADER.
	Gura_PackedULong_LE(nSize);				// Record size in bytes. This may be greater
										// than the sizeof(ENHMETAHEADER).
	Gura_PackedLong_LE(rclBounds_left);		// Inclusive-inclusive bounds in device units.
	Gura_PackedLong_LE(rclBounds_top);
	Gura_PackedLong_LE(rclBounds_right);
	Gura_PackedLong_LE(rclBounds_bottom);
	Gura_PackedLong_LE(rclFrame_left);		// Inclusive-inclusive Picture Frame of 
	Gura_PackedLong_LE(rclFrame_top);		// metafile in .01 mm units. 
	Gura_PackedLong_LE(rclFrame_right);
	Gura_PackedLong_LE(rclFrame_bottom);
	Gura_PackedULong_LE(dSignature);		// Signature.  Must be ENHMETA_SIGNATURE.
	Gura_PackedULong_LE(nVersion);			// Version number.
	Gura_PackedULong_LE(nBytes);			// Size of the metafile in bytes.
	Gura_PackedULong_LE(nRecords);			// Number of records in the metafile.
	Gura_PackedUShort_LE(nHandles);			// Number of handles in the handle table.
										// Handle index zero is reserved.
	Gura_PackedUShort_LE(sReserved);		// Reserved.  Must be zero.
	Gura_PackedULong_LE(nDescription);		// Number of chars in the unicode description string.
										// This is 0 if there is no description string.
	Gura_PackedULong_LE(offDescription);	// Offset to the metafile description record.
										// This is 0 if there is no description string.
	Gura_PackedULong_LE(nPalEntries);		// Number of entries in the metafile palette.
	Gura_PackedLong_LE(szlDevice_cx);		// Size of the reference device in pixels. 
	Gura_PackedLong_LE(szlDevice_cy);
	Gura_PackedLong_LE(szlMillimeters_cx);	// Size of the reference device in millimeters.
	Gura_PackedLong_LE(szlMillimeters_cy);
};

struct MetaRecord {
	enum { Size = 6 };
	Gura_PackedULong_LE(rdSize);			// Record size in bytes
	Gura_PackedUShort_LE(rdFunction);		// Record type META_XXX
	//WORD rdParm[1];					// WORD array of parameters
};

struct EnhMetaRecord {
	enum { Size = 8 };
	Gura_PackedULong_LE(iType);				// Record type EMR_XXX
	Gura_PackedULong_LE(nSize);				// Record size in bytes
	//DWORD dParm[1];					// DWORD Array of parameters
};

//-----------------------------------------------------------------------------
// Function
//-----------------------------------------------------------------------------
class EMR_basement {
protected:
	ULong _iType;
	size_t _dwordsParms;
	char *_buff;
public:
	inline EMR_basement(ULong iType, size_t dwordsParms) :
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
		Gura_PackedLong_LE(fnMapMode);
	};
public:
	inline EMR_SetMapMode() : EMR_basement(Type, 1) {}
	inline EMR_SetMapMode(int fnMapMode) : EMR_basement(Type, 1) {
		Parms &parms = *reinterpret_cast<Parms *>(_buff);
		Gura_PackLong(parms.fnMapMode, fnMapMode);
	}
};

class EMR_CreatePen : public EMR_basement {
public:
	enum { Type = 38 };
	struct Parms {
		Gura_PackedLong_LE(fnPenStyle);
		Gura_PackedLong_LE(nWidth);
		Gura_PackedULong_LE(crColor);
	};
public:
	inline EMR_CreatePen() : EMR_basement(Type, 5) {}
	inline EMR_CreatePen(int fnMapMode) : EMR_basement(Type, 5) {
		Parms &parms = *reinterpret_cast<Parms *>(_buff);
		Gura_PackLong(parms.fnMapMode, fnMapMode);
	}
};

}}

#endif
