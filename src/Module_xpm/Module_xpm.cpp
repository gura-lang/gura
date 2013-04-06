//-----------------------------------------------------------------------------
// Gura xpm module
// As fot the XPM format, see http://www.fileformat.info/format/xpm/egff.htm
//-----------------------------------------------------------------------------
#include "Module_xpm.h"

Gura_BeginModule(xpm)

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing xpm module.
//-----------------------------------------------------------------------------
#if 0
// image#xpmread(stream:stream:r):reduce
Gura_DeclareMethod(image, xpmread)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(Gura_Symbol(en), "Reads an xpm image from a stream.");
}

Gura_ImplementMethod(image, xpmread)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_xpm::ReadStream(env, sig, pThis, args.GetStream(0))) return Value::Null;
	return args.GetThis();
}
#endif

// image#xpmwrite(stream:stream:w):reduce
Gura_DeclareMethod(image, xpmwrite)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(Gura_Symbol(en), "Writes a xpm image to a stream.");
}

Gura_ImplementMethod(image, xpmwrite)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	if (!ImageStreamer_xpm::WriteStream(env, sig, pThis->GetImage(), args.GetStream(0))) return Value::Null;
	return args.GetThis();
}

// image#xpmdata(xpm[]:string):reduce
Gura_DeclareMethod(image, xpmdata)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "xpm", VTYPE_string, OCCUR_Once, FLAG_List);
	AddHelp(Gura_Symbol(en), "Read xpm data from a string list.");
}

Gura_ImplementMethod(image, xpmdata)
{
	typedef std::map<String, Color> ColorMap;
	Object_image *pThis = Object_image::GetThisObj(args);
	Image *pImage = pThis->GetImage();
	if (!pImage->CheckEmpty(sig)) return Value::Null;
	const ValueList &valList = args.GetList(0);
	ValueList::const_iterator pValue = valList.begin();
	if (pValue == valList.end()) {
		sig.SetError(ERR_FormatError, "can't find XPM header");
		return Value::Null;
	}
	int width = 0, height = 0;
	int nColors = 0, nBytes = 0;
	do {
		enum Stat {
			STAT_WidthPre, STAT_Width,
			STAT_HeightPre, STAT_Height,
			STAT_NColorsPre, STAT_NColors,
			STAT_NBytesPre, STAT_NBytes,
			STAT_Finish,
		} stat = STAT_WidthPre;
		const char *p = pValue->GetString();
		for (;;) {
			char ch = *p++;
			bool continueFlag = false;
			do {
				continueFlag = false;
				if (stat == STAT_WidthPre) {
					if (ch == ' ' || ch == '\t') {
						// nothing to do
					} else {
						stat = STAT_Width;
						continueFlag = true;
					}
				} else if (stat == STAT_Width) {
					if ('0' <= ch && ch <= '9') {
						width = width * 10 + (ch - '0');
					} else if (ch == ' ' || ch == '\t') {
						stat = STAT_HeightPre;
					} else {
						sig.SetError(ERR_FormatError, "invalid XPM header");
						return Value::Null;
					}
				} else if (stat == STAT_HeightPre) {
					if (ch == ' ' || ch == '\t') {
						// nothing to do
					} else {
						stat = STAT_Height;
						continueFlag = true;
					}
				} else if (stat == STAT_Height) {
					if ('0' <= ch && ch <= '9') {
						height = height * 10 + (ch - '0');
					} else if (ch == ' ' || ch == '\t') {
						stat = STAT_NColorsPre;
					} else {
						sig.SetError(ERR_FormatError, "invalid XPM header");
						return Value::Null;
					}
				} else if (stat == STAT_NColorsPre) {
					if (ch == ' ' || ch == '\t') {
						// nothing to do
					} else {
						stat = STAT_NColors;
						continueFlag = true;
					}
				} else if (stat == STAT_NColors) {
					if ('0' <= ch && ch <= '9') {
						nColors = nColors * 10 + (ch - '0');
					} else if (ch == ' ' || ch == '\t') {
						stat = STAT_NBytesPre;
					} else {
						sig.SetError(ERR_FormatError, "invalid XPM header");
						return Value::Null;
					}
				} else if (stat == STAT_NBytesPre) {
					if (ch == ' ' || ch == '\t') {
						// nothing to do
					} else {
						stat = STAT_NBytes;
						continueFlag = true;
					}
				} else if (stat == STAT_NBytes) {
					if ('0' <= ch && ch <= '9') {
						nBytes = nBytes * 10 + (ch - '0');
					} else if (ch == ' ' || ch == '\t' || ch == '\0') {
						stat = STAT_Finish;
					} else {
						sig.SetError(ERR_FormatError, "invalid XPM header");
						return Value::Null;
					}
				}
			} while (continueFlag);
			if (ch == '\0') break;
		}
		//::printf("%d %d %d %d\n", width, height, nColors, nBytes);
	} while (0);
	ColorMap colorMap;
	String symbolNull;
	pValue++;
	int iColor = 0;
	for ( ; iColor < nColors && pValue != valList.end(); iColor++, pValue++) {
		enum Stat {
			STAT_Category, STAT_CategoryPost,
			STAT_ValuePre, STAT_Value,
		} stat = STAT_Category;
		const char *p = pValue->GetString();
		if (::strlen(p) < nBytes) {
			sig.SetError(ERR_FormatError, "invalid XPM header");
			return Value::Null;
		}
		char chCategory = '\0';
		String symbol(p, p + nBytes);
		String value;
		p += nBytes;
		for (;;) {
			char ch = *p++;
			if (stat == STAT_Category) {
				if (ch == ' ' || ch == '\t') {
					// nothing to do
				} else if (ch == '\0') {
					sig.SetError(ERR_FormatError, "invalid XPM header");
					return Value::Null;
				} else {
					chCategory = ch;
					stat = STAT_CategoryPost;
				}
			} else if (stat == STAT_CategoryPost) {
				if (ch == ' ' || ch == '\t') {
					stat = STAT_ValuePre;
				} else {
					sig.SetError(ERR_FormatError, "invalid XPM header");
					return Value::Null;
				}
			} else if (stat == STAT_ValuePre) {
				if (ch == ' ' || ch == '\t') {
					// nothing to do
				} else if (ch == '\0') {
					sig.SetError(ERR_FormatError, "invalid XPM header");
					return Value::Null;
				} else {
					value.clear();
					value += ch;
					stat = STAT_Value;
				}
			} else if (stat == STAT_Value) {
				if (ch == ' ' || ch == '\t' || ch == '\0') {
					if (chCategory == 'c') break;
					stat = STAT_Category;
				} else {
					value += ch;
				}
			}
			if (ch == '\0') break;
		}
		if (::strcasecmp(value.c_str(), "None") == 0) {
			symbolNull = symbol;
		} else {
			AutoPtr<Object_color> pObj(
				Object_color::CreateNamedColor(env, sig, value.c_str(), 255));
			if (pObj.IsNull()) return Value::Null;
			colorMap[symbol] = pObj->GetColor();
		}
		//::printf("%s .. %s\n", symbol.c_str(), value.c_str());
	}
	if (iColor < nColors) {
		sig.SetError(ERR_FormatError, "invalid XPM header");
		return Value::Null;
	}
	if (!pImage->AllocBuffer(sig, width, height, 0xff)) return Value::Null;
	std::auto_ptr<Image::Scanner>
					pScannerDst(pImage->CreateScanner(Image::SCAN_LeftTopHorz));
	bool alphaFlag = (pImage->GetFormat() == Image::FORMAT_RGBA);
	for (int y = 0; y < height && pValue != valList.end(); y++, pValue++) {
		const char *p = pValue->GetString();
		String symbol;
		int x = 0;
		for ( ; x < width && *p != '\0'; p++) {
			char ch = *p;
			symbol += ch;
			if (symbol.size() == nBytes) {
				if (symbol == symbolNull) {
					if (alphaFlag) {
						pScannerDst->StorePixel(0, 0, 0, 0);
					} else {
						pScannerDst->StorePixel(0, 0, 0);
					}
				} else {
					ColorMap::iterator iter = colorMap.find(symbol);
					if (iter == colorMap.end()) {
						sig.SetError(ERR_FormatError, "undefined color symbol");
						return Value::Null;
					}
					const Color &color = iter->second;
					pScannerDst->StorePixel(color.GetRed(), color.GetGreen(), color.GetBlue(), 255);
				}
				pScannerDst->Next();
				x++;
				symbol.clear();
			}
		}
	}
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: xpm
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	//Gura_AssignMethodTo(VTYPE_image, image, xpmread);
	Gura_AssignMethodTo(VTYPE_image, image, xpmwrite);
	Gura_AssignMethodTo(VTYPE_image, image, xpmdata);
	ImageStreamer::Register(new ImageStreamer_xpm());
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_xpm
//-----------------------------------------------------------------------------
bool ImageStreamer_xpm::IsResponsible(Signal sig, Stream &stream)
{
	if (stream.IsReadable()) {
		return false;
	}
	return stream.HasNameSuffix(".xpm");
}

bool ImageStreamer_xpm::Read(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return ImageStreamer_xpm::ReadStream(env, sig, pImage, stream);
}

bool ImageStreamer_xpm::Write(Environment &env, Signal sig,
									Image *pImage, Stream &stream)
{
	return ImageStreamer_xpm::WriteStream(env, sig, pImage, stream);
}

bool ImageStreamer_xpm::ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	if (!pImage->CheckEmpty(sig)) return false;
	return false;
}

bool ImageStreamer_xpm::WriteStream(Environment &env, Signal sig, Image *pImage, Stream &stream)
{
	const int nCharsPerPixel = 2;
	const int xHotspot = 0, yHotspot = 0;
	static char *convTbl = NULL;
	static int nEntries = 0;
	if (convTbl == NULL) {
		const int nEntriesMax = 96 * 96;
		convTbl = new char [nEntriesMax * nCharsPerPixel];
		::memset(convTbl, 0x00, nEntriesMax * nCharsPerPixel);
		int chFirst = '!', chSecond = ' ';
		for (nEntries = 0; nEntries < nEntriesMax; nEntries++, chFirst++) {
			if (chFirst == '"' || chFirst == '\\') chFirst++;
			if (chFirst == 0x7f) {
				chFirst = '!';
				chSecond++;
				if (chSecond == '"' || chSecond == '\\') chSecond++;
				if (chSecond == 0x7f) break;
			}
			convTbl[nEntries * nCharsPerPixel] = chFirst;
			convTbl[nEntries * nCharsPerPixel + 1] = chSecond;
		}
	}
	if (!pImage->CheckValid(sig)) return false;
	String varName = "noname";
	do {
		String baseName;
		Directory::SplitFileName(stream.GetName(), NULL, &baseName);
		String str;
		foreach (String, p, baseName) {
			char ch = *p;
			if (ch == '.') break;
			str += ch;
		}
		if (!str.empty()) varName = str;
	} while (0);
	stream.Print(sig, "static const char *");
	stream.Print(sig, varName.c_str());
	stream.Println(sig, "_xpm[] = {");
	if (sig.IsSignalled()) return false;
	AutoPtr<Palette> pPalette(new Palette());
	pPalette->AllocBuff(nEntries);
	if (!pPalette->UpdateByImage(pImage, Palette::ShrinkMinimum)) {
		sig.SetError(ERR_ValueError, "too many number of colors");
		return false;
	}
	do {
		char buff[64];
		::sprintf(buff, "\"%d %d %d %d %d %d\",",
				pImage->GetWidth(), pImage->GetHeight(),
				pPalette->CountEntries() + 1, nCharsPerPixel,
				xHotspot, yHotspot);
		stream.Println(sig, buff);
	} while (0);
	do {
		stream.Println(sig, "\"   c None\",");
	} while (0);
	for (int i = 0; i < pPalette->CountEntries(); i++) {
		const unsigned char *entry = pPalette->GetEntry(i);
		char buff[64];
		buff[0] = '"';
		::memcpy(buff + 1, convTbl + i * nCharsPerPixel, nCharsPerPixel);
		::sprintf(buff + 1 + nCharsPerPixel, " c #%02x%02x%02x\",",
					entry[Palette::OffsetRed],
					entry[Palette::OffsetGreen],
					entry[Palette::OffsetBlue]);
		stream.Println(sig, buff);
	} while (0);
	if (sig.IsSignalled()) return false;
	std::auto_ptr<Image::Scanner> pScanner(pImage->CreateScanner());
	String str = "\"";
	bool hasAlphaFlag = (pImage->GetFormat() == Image::FORMAT_RGBA);
	for (;;) {
		if (hasAlphaFlag && pScanner->GetAlpha() < 128) {
			str += "  ";
		} else {
			int idx = static_cast<int>(pPalette->LookupNearest(pScanner->GetPointer()));
			str += convTbl[idx * nCharsPerPixel + 0];
			str += convTbl[idx * nCharsPerPixel + 1];
		}
		if (!pScanner->NextPixel()) {
			str += "\",";
			stream.Println(sig, str.c_str());
			if (sig.IsSignalled()) break;
			if (!pScanner->NextLine()) {
				stream.Println(sig, "};");
				break;
			}
			str = "\"";
		}
	}
	return true;
}

void ImageStreamer_xpm::SetError_InvalidFormat(Signal sig)
{
	sig.SetError(ERR_FormatError, "invalid xpm format");
}

Gura_EndModule(xpm, xpm)

Gura_RegisterModule(xpm)
