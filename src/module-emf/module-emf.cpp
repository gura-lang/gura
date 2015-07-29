//-----------------------------------------------------------------------------
// Gura emf (Enhanced Metafiles in Win32) module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(emf)

//-----------------------------------------------------------------------------
// File structure
//-----------------------------------------------------------------------------
const ULong _EMR_ABORTPATH				= 68;
const ULong _EMR_ANGLEARC				= 41;
const ULong _EMR_ARC					= 45;
const ULong _EMR_ARCTO					= 55;
const ULong _EMR_BEGINPATH				= 59;
const ULong _EMR_BITBLT					= 76;
const ULong _EMR_CHORD					= 46;
const ULong _EMR_CLOSEFIGURE			= 61;
const ULong _EMR_CREATEBRUSHINDIRECT	= 39;
const ULong _EMR_CREATEDIBPATTERNBRUSHPT= 94;
const ULong _EMR_CREATEMONOBRUSH		= 93;
const ULong _EMR_CREATEPALETTE			= 49;
const ULong _EMR_CREATEPEN				= 38;
const ULong _EMR_DELETEOBJECT			= 40;
const ULong _EMR_ELLIPSE				= 42;
const ULong _EMR_ENDPATH				= 60;
const ULong _EMR_EOF					= 14;
const ULong _EMR_EXCLUDECLIPRECT		= 29;
const ULong _EMR_EXTCREATEFONTINDIRECTW	= 82;
const ULong _EMR_EXTCREATEPEN			= 95;
const ULong _EMR_EXTFLOODFILL			= 53;
const ULong _EMR_EXTSELECTCLIPRGN		= 75;
const ULong _EMR_EXTTEXTOUTA			= 83;
const ULong _EMR_EXTTEXTOUTW			= 84;
const ULong _EMR_FILLPATH				= 62;
const ULong _EMR_FILLRGN				= 71;
const ULong _EMR_FLATTENPATH			= 65;
const ULong _EMR_FRAMERGN				= 72;
const ULong _EMR_GDICOMMENT				= 70;
const ULong _EMR_HEADER					= 1;
const ULong _EMR_INTERSECTCLIPRECT		= 30;
const ULong _EMR_INVERTRGN				= 73;
const ULong _EMR_LINETO					= 54;
const ULong _EMR_MASKBLT				= 78;
const ULong _EMR_MODIFYWORLDTRANSFORM	= 36;
const ULong _EMR_MOVETOEX				= 27;
const ULong _EMR_OFFSETCLIPRGN			= 26;
const ULong _EMR_PAINTRGN				= 74;
const ULong _EMR_PIE					= 47;
const ULong _EMR_PLGBLT					= 79;
const ULong _EMR_POLYBEZIER				= 2;
const ULong _EMR_POLYBEZIER16			= 85;
const ULong _EMR_POLYBEZIERTO			= 5;
const ULong _EMR_POLYBEZIERTO16			= 88;
const ULong _EMR_POLYDRAW				= 56;
const ULong _EMR_POLYDRAW16				= 92;
const ULong _EMR_POLYGON				= 3;
const ULong _EMR_POLYGON16				= 86;
const ULong _EMR_POLYLINE				= 4;
const ULong _EMR_POLYLINE16				= 87;
const ULong _EMR_POLYLINETO				= 6;
const ULong _EMR_POLYLINETO16			= 89;
const ULong _EMR_POLYPOLYGON			= 8;
const ULong _EMR_POLYPOLYGON16			= 91;
const ULong _EMR_POLYPOLYLINE			= 7;
const ULong _EMR_POLYPOLYLINE16			= 90;
const ULong _EMR_POLYTEXTOUTA			= 96;
const ULong _EMR_POLYTEXTOUTW			= 97;
const ULong _EMR_REALIZEPALETTE			= 52;
const ULong _EMR_RECTANGLE				= 43;
const ULong _EMR_RESIZEPALETTE			= 51;
const ULong _EMR_RESTOREDC				= 34;
const ULong _EMR_ROUNDRECT				= 44;
const ULong _EMR_SAVEDC					= 33;
const ULong _EMR_SCALEVIEWPORTEXTEX		= 31;
const ULong _EMR_SCALEWINDOWEXTEX		= 32;
const ULong _EMR_SELECTCLIPPATH			= 67;
const ULong _EMR_SELECTOBJECT			= 37;
const ULong _EMR_SELECTPALETTE			= 48;
const ULong _EMR_SETARCDIRECTION		= 57;
const ULong _EMR_SETBKCOLOR				= 25;
const ULong _EMR_SETBKMODE				= 18;
const ULong _EMR_SETBRUSHORGEX			= 13;
const ULong _EMR_SETCOLORADJUSTMENT		= 23;
const ULong _EMR_SETDIBITSTODEVICE		= 80;
const ULong _EMR_SETMAPMODE				= 17;
const ULong _EMR_SETMAPPERFLAGS			= 16;
const ULong _EMR_SETMETARGN				= 28;
const ULong _EMR_SETMITERLIMIT			= 58;
const ULong _EMR_SETPALETTEENTRIES		= 50;
const ULong _EMR_SETPIXELV				= 15;
const ULong _EMR_SETPOLYFILLMODE		= 19;
const ULong _EMR_SETROP2				= 20;
const ULong _EMR_SETSTRETCHBLTMODE		= 21;
const ULong _EMR_SETTEXTALIGN			= 22;
const ULong _EMR_SETTEXTCOLOR			= 24;
const ULong _EMR_SETVIEWPORTEXTEX		= 11;
const ULong _EMR_SETVIEWPORTORGEX		= 12;
const ULong _EMR_SETWINDOWEXTEX			= 9;
const ULong _EMR_SETWINDOWORGEX			= 10;
const ULong _EMR_SETWORLDTRANSFORM		= 35;
const ULong _EMR_STRETCHBLT				= 77;
const ULong _EMR_STRETCHDIBITS			= 81;
const ULong _EMR_STROKEANDFILLPATH		= 63;
const ULong _EMR_STROKEPATH				= 64;
const ULong _EMR_WIDENPATH				= 66;

//-----------------------------------------------------------------------------
// Gura module functions: emf
//-----------------------------------------------------------------------------
// emf.test(stream:stream:r)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
}

Gura_ImplementFunction(test)
{
	Signal &sig = env.GetSignal();
	Stream &stream = args.GetStream(0);
	ULong nBytes = 0;
	ULong nRecords = 0;
	ULong nDescription = 0;
	ULong offDescription = 0;
	ULong nPalEntries = 0;
	do {
		EnhMetaHeader hdr;
		stream.Read(sig, &hdr, EnhMetaHeader::Size);
		ULong dSignature = Gura_UnpackULong(hdr.dSignature);
		if (dSignature != _ENHMETA_SIGNATURE) {
			sig.SetError(ERR_FormatError, "invalid signature of EMF file");
			return Value::Null;
		}
		nBytes			= Gura_UnpackULong(hdr.nBytes);
		nRecords		= Gura_UnpackULong(hdr.nRecords);
		nDescription	= Gura_UnpackULong(hdr.nDescription);
		offDescription	= Gura_UnpackULong(hdr.offDescription);
		nPalEntries		= Gura_UnpackULong(hdr.nPalEntries);
		ULong nSize = Gura_UnpackULong(hdr.nSize);
		if (nSize > EnhMetaHeader::Size) {
			stream.Seek(sig, nSize - EnhMetaHeader::Size, Stream::SeekCur);
		}
	} while (0);
	::printf("%d, %d, %d, %d, %d\n", nBytes, nRecords, nDescription, offDescription, nPalEntries);
	for (ULong iRecord = 0; iRecord < nRecords; iRecord++) {
		EnhMetaRecord rec;
		if (stream.Read(sig, &rec, EnhMetaRecord::Size) < EnhMetaRecord::Size) break;
		::printf("iType = %d, nSize = %d\n", Gura_UnpackULong(rec.iType), Gura_UnpackULong(rec.nSize));
		ULong nSize = Gura_UnpackULong(rec.nSize);
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
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(emf, emf)

Gura_RegisterModule(emf)
