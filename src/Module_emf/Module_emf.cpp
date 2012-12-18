//-----------------------------------------------------------------------------
// Gura emf (Enhanced Metafiles in Win32) module
//-----------------------------------------------------------------------------
#include "Module_emf.h"

Gura_BeginModule(emf)

//-----------------------------------------------------------------------------
// File structure
//-----------------------------------------------------------------------------
const unsigned long _EMR_ABORTPATH				= 68;
const unsigned long _EMR_ANGLEARC				= 41;
const unsigned long _EMR_ARC					= 45;
const unsigned long _EMR_ARCTO					= 55;
const unsigned long _EMR_BEGINPATH				= 59;
const unsigned long _EMR_BITBLT					= 76;
const unsigned long _EMR_CHORD					= 46;
const unsigned long _EMR_CLOSEFIGURE			= 61;
const unsigned long _EMR_CREATEBRUSHINDIRECT	= 39;
const unsigned long _EMR_CREATEDIBPATTERNBRUSHPT= 94;
const unsigned long _EMR_CREATEMONOBRUSH		= 93;
const unsigned long _EMR_CREATEPALETTE			= 49;
const unsigned long _EMR_CREATEPEN				= 38;
const unsigned long _EMR_DELETEOBJECT			= 40;
const unsigned long _EMR_ELLIPSE				= 42;
const unsigned long _EMR_ENDPATH				= 60;
const unsigned long _EMR_EOF					= 14;
const unsigned long _EMR_EXCLUDECLIPRECT		= 29;
const unsigned long _EMR_EXTCREATEFONTINDIRECTW	= 82;
const unsigned long _EMR_EXTCREATEPEN			= 95;
const unsigned long _EMR_EXTFLOODFILL			= 53;
const unsigned long _EMR_EXTSELECTCLIPRGN		= 75;
const unsigned long _EMR_EXTTEXTOUTA			= 83;
const unsigned long _EMR_EXTTEXTOUTW			= 84;
const unsigned long _EMR_FILLPATH				= 62;
const unsigned long _EMR_FILLRGN				= 71;
const unsigned long _EMR_FLATTENPATH			= 65;
const unsigned long _EMR_FRAMERGN				= 72;
const unsigned long _EMR_GDICOMMENT				= 70;
const unsigned long _EMR_HEADER					= 1;
const unsigned long _EMR_INTERSECTCLIPRECT		= 30;
const unsigned long _EMR_INVERTRGN				= 73;
const unsigned long _EMR_LINETO					= 54;
const unsigned long _EMR_MASKBLT				= 78;
const unsigned long _EMR_MODIFYWORLDTRANSFORM	= 36;
const unsigned long _EMR_MOVETOEX				= 27;
const unsigned long _EMR_OFFSETCLIPRGN			= 26;
const unsigned long _EMR_PAINTRGN				= 74;
const unsigned long _EMR_PIE					= 47;
const unsigned long _EMR_PLGBLT					= 79;
const unsigned long _EMR_POLYBEZIER				= 2;
const unsigned long _EMR_POLYBEZIER16			= 85;
const unsigned long _EMR_POLYBEZIERTO			= 5;
const unsigned long _EMR_POLYBEZIERTO16			= 88;
const unsigned long _EMR_POLYDRAW				= 56;
const unsigned long _EMR_POLYDRAW16				= 92;
const unsigned long _EMR_POLYGON				= 3;
const unsigned long _EMR_POLYGON16				= 86;
const unsigned long _EMR_POLYLINE				= 4;
const unsigned long _EMR_POLYLINE16				= 87;
const unsigned long _EMR_POLYLINETO				= 6;
const unsigned long _EMR_POLYLINETO16			= 89;
const unsigned long _EMR_POLYPOLYGON			= 8;
const unsigned long _EMR_POLYPOLYGON16			= 91;
const unsigned long _EMR_POLYPOLYLINE			= 7;
const unsigned long _EMR_POLYPOLYLINE16			= 90;
const unsigned long _EMR_POLYTEXTOUTA			= 96;
const unsigned long _EMR_POLYTEXTOUTW			= 97;
const unsigned long _EMR_REALIZEPALETTE			= 52;
const unsigned long _EMR_RECTANGLE				= 43;
const unsigned long _EMR_RESIZEPALETTE			= 51;
const unsigned long _EMR_RESTOREDC				= 34;
const unsigned long _EMR_ROUNDRECT				= 44;
const unsigned long _EMR_SAVEDC					= 33;
const unsigned long _EMR_SCALEVIEWPORTEXTEX		= 31;
const unsigned long _EMR_SCALEWINDOWEXTEX		= 32;
const unsigned long _EMR_SELECTCLIPPATH			= 67;
const unsigned long _EMR_SELECTOBJECT			= 37;
const unsigned long _EMR_SELECTPALETTE			= 48;
const unsigned long _EMR_SETARCDIRECTION		= 57;
const unsigned long _EMR_SETBKCOLOR				= 25;
const unsigned long _EMR_SETBKMODE				= 18;
const unsigned long _EMR_SETBRUSHORGEX			= 13;
const unsigned long _EMR_SETCOLORADJUSTMENT		= 23;
const unsigned long _EMR_SETDIBITSTODEVICE		= 80;
const unsigned long _EMR_SETMAPMODE				= 17;
const unsigned long _EMR_SETMAPPERFLAGS			= 16;
const unsigned long _EMR_SETMETARGN				= 28;
const unsigned long _EMR_SETMITERLIMIT			= 58;
const unsigned long _EMR_SETPALETTEENTRIES		= 50;
const unsigned long _EMR_SETPIXELV				= 15;
const unsigned long _EMR_SETPOLYFILLMODE		= 19;
const unsigned long _EMR_SETROP2				= 20;
const unsigned long _EMR_SETSTRETCHBLTMODE		= 21;
const unsigned long _EMR_SETTEXTALIGN			= 22;
const unsigned long _EMR_SETTEXTCOLOR			= 24;
const unsigned long _EMR_SETVIEWPORTEXTEX		= 11;
const unsigned long _EMR_SETVIEWPORTORGEX		= 12;
const unsigned long _EMR_SETWINDOWEXTEX			= 9;
const unsigned long _EMR_SETWINDOWORGEX			= 10;
const unsigned long _EMR_SETWORLDTRANSFORM		= 35;
const unsigned long _EMR_STRETCHBLT				= 77;
const unsigned long _EMR_STRETCHDIBITS			= 81;
const unsigned long _EMR_STROKEANDFILLPATH		= 63;
const unsigned long _EMR_STROKEPATH				= 64;
const unsigned long _EMR_WIDENPATH				= 66;

//-----------------------------------------------------------------------------
// Gura module functions: emf
//-----------------------------------------------------------------------------
// emf.test(stream:stream:r)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementFunction(test)
{
	Stream &stream = args.GetStream(0);
	unsigned long nBytes = 0;
	unsigned long nRecords = 0;
	unsigned long nDescription = 0;
	unsigned long offDescription = 0;
	unsigned long nPalEntries = 0;
	do {
		EnhMetaHeader hdr;
		stream.Read(sig, &hdr, EnhMetaHeader::Size);
		unsigned long dSignature = XUnpackULong(hdr.dSignature);
		if (dSignature != _ENHMETA_SIGNATURE) {
			sig.SetError(ERR_FormatError, "invalid signature of EMF file");
			return Value::Null;
		}
		nBytes			= XUnpackULong(hdr.nBytes);
		nRecords		= XUnpackULong(hdr.nRecords);
		nDescription	= XUnpackULong(hdr.nDescription);
		offDescription	= XUnpackULong(hdr.offDescription);
		nPalEntries		= XUnpackULong(hdr.nPalEntries);
		unsigned long nSize = XUnpackULong(hdr.nSize);
		if (nSize > EnhMetaHeader::Size) {
			stream.Seek(sig, nSize - EnhMetaHeader::Size, Stream::SeekCur);
		}
	} while (0);
	::printf("%d, %d, %d, %d, %d\n", nBytes, nRecords, nDescription, offDescription, nPalEntries);
	for (unsigned long iRecord = 0; iRecord < nRecords; iRecord++) {
		EnhMetaRecord rec;
		if (stream.Read(sig, &rec, EnhMetaRecord::Size) < EnhMetaRecord::Size) break;
		::printf("iType = %d, nSize = %d\n", XUnpackULong(rec.iType), XUnpackULong(rec.nSize));
		unsigned long nSize = XUnpackULong(rec.nSize);
		if (nSize > EnhMetaRecord::Size) {
			stream.Seek(sig, nSize - EnhMetaRecord::Size, Stream::SeekCur);
		}
		
	}
	return Value::Null;
}

// Module entry
Gura_ModuleEntry()
{
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(emf, emf)

Gura_RegisterModule(emf)
