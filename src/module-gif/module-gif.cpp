//-----------------------------------------------------------------------------
// Gura module: gif
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(gif)

//-----------------------------------------------------------------------------
// Object_Header
//-----------------------------------------------------------------------------
Object *Object_Header::Clone() const
{
	return new Object_Header(*this);
}

bool Object_Header::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(Signature));
	symbols.insert(Gura_UserSymbol(Version));
	return true;
}

Value Object_Header::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	GIF &gif = _pObjContent->GetGIF();
	evaluatedFlag = true;
	GIF::Header &hdr = gif.GetHeader();
	if (pSymbol->IsIdentical(Gura_UserSymbol(Signature))) {
		return Value(new Object_binary(env, hdr.Signature, sizeof(hdr.Signature), true));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Version))) {
		return Value(new Object_binary(env, hdr.Version, sizeof(hdr.Version), true));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_Header::ToString(bool exprFlag)
{
	return String("<gif.Header>");
}

Gura_ImplementUserClass(Header)
{
}

//-----------------------------------------------------------------------------
// Object_LogicalScreenDescriptor
//-----------------------------------------------------------------------------
Object *Object_LogicalScreenDescriptor::Clone() const
{
	return new Object_LogicalScreenDescriptor(*this);
}

bool Object_LogicalScreenDescriptor::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(LogicalScreenWidth));
	symbols.insert(Gura_UserSymbol(LogicalScreenHeight));
	symbols.insert(Gura_UserSymbol(GlobalColorTableFlag));
	symbols.insert(Gura_UserSymbol(ColorResolution));
	symbols.insert(Gura_UserSymbol(SortFlag));
	symbols.insert(Gura_UserSymbol(SizeOfGlobalColorTable));
	symbols.insert(Gura_UserSymbol(BackgroundColorIndex));
	symbols.insert(Gura_UserSymbol(BackgroundColor));
	symbols.insert(Gura_UserSymbol(PixelAspectRatio));
	return true;
}

Value Object_LogicalScreenDescriptor::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	GIF &gif = _pObjContent->GetGIF();
	evaluatedFlag = true;
	GIF::LogicalScreenDescriptor &lsd = gif.GetLogicalScreenDescriptor();
	if (pSymbol->IsIdentical(Gura_UserSymbol(LogicalScreenWidth))) {
		return Value(Gura_UnpackUShort(lsd.LogicalScreenWidth));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(LogicalScreenHeight))) {
		return Value(Gura_UnpackUShort(lsd.LogicalScreenHeight));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(GlobalColorTableFlag))) {
		return Value(lsd.GlobalColorTableFlag());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ColorResolution))) {
		return Value(lsd.ColorResolution());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(SortFlag))) {
		return Value(lsd.SortFlag());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(SizeOfGlobalColorTable))) {
		return Value(static_cast<UInt>(lsd.SizeOfGlobalColorTable()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(BackgroundColorIndex))) {
		return Value(lsd.BackgroundColorIndex);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(BackgroundColor))) {
		size_t idx = lsd.BackgroundColorIndex;
		Palette *pPalette = gif.GetGlobalPalette();
		if (pPalette == NULL || pPalette->CountEntries() < idx) {
			return Value::Null;
		}
		return pPalette->GetColorValue(env, idx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(PixelAspectRatio))) {
		return Value(lsd.PixelAspectRatio);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_LogicalScreenDescriptor::ToString(bool exprFlag)
{
	return String("<gif.LogicalScreenDescriptor>");
}

Gura_ImplementUserClass(LogicalScreenDescriptor)
{
}

//-----------------------------------------------------------------------------
// Object_CommentExtension
//-----------------------------------------------------------------------------
Object *Object_CommentExtension::Clone() const
{
	return new Object_CommentExtension(*this);
}

bool Object_CommentExtension::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(CommentData));
	return true;
}

Value Object_CommentExtension::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	GIF &gif = _pObjContent->GetGIF();
	evaluatedFlag = true;
	GIF::Extensions &exts = gif.GetExtensions();
	if (!exts.comment.validFlag) return Value::Null;
	GIF::CommentExtension &cmnt = exts.comment;
	if (pSymbol->IsIdentical(Gura_UserSymbol(CommentData))) {
		return Value(new Object_binary(env, cmnt.CommentData, true));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_CommentExtension::ToString(bool exprFlag)
{
	return String("<gif.CommentExtension>");
}

Gura_ImplementUserClass(CommentExtension)
{
}

//-----------------------------------------------------------------------------
// Object_PlainTextExtension
//-----------------------------------------------------------------------------
Object *Object_PlainTextExtension::Clone() const
{
	return new Object_PlainTextExtension(*this);
}

bool Object_PlainTextExtension::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(TextGridLeftPosition));
	symbols.insert(Gura_UserSymbol(TextGridTopPosition));
	symbols.insert(Gura_UserSymbol(TextGridWidth));
	symbols.insert(Gura_UserSymbol(TextGridHeight));
	symbols.insert(Gura_UserSymbol(CharacterCellWidth));
	symbols.insert(Gura_UserSymbol(CharacterCellHeight));
	symbols.insert(Gura_UserSymbol(TextForegroundColorIndex));
	symbols.insert(Gura_UserSymbol(TextBackgroundColorIndex));
	symbols.insert(Gura_UserSymbol(PlainTextData));
	return true;
}

Value Object_PlainTextExtension::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	GIF &gif = _pObjContent->GetGIF();
	evaluatedFlag = true;
	GIF::Extensions &exts = gif.GetExtensions();
	if (!exts.plainText.validFlag) return Value::Null;
	GIF::PlainTextExtension &pltxt = exts.plainText;
	if (pSymbol->IsIdentical(Gura_UserSymbol(TextGridLeftPosition))) {
		return Value(Gura_UnpackUShort(pltxt.TextGridLeftPosition));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(TextGridTopPosition))) {
		return Value(Gura_UnpackUShort(pltxt.TextGridTopPosition));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(TextGridWidth))) {
		return Value(Gura_UnpackUShort(pltxt.TextGridWidth));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(TextGridHeight))) {
		return Value(Gura_UnpackUShort(pltxt.TextGridHeight));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(CharacterCellWidth))) {
		return Value(pltxt.CharacterCellWidth);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(CharacterCellHeight))) {
		return Value(pltxt.CharacterCellHeight);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(TextForegroundColorIndex))) {
		return Value(pltxt.TextForegroundColorIndex);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(TextBackgroundColorIndex))) {
		return Value(pltxt.TextBackgroundColorIndex);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(PlainTextData))) {
		return Value(new Object_binary(env, pltxt.PlainTextData, true));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_PlainTextExtension::ToString(bool exprFlag)
{
	return String("<gif.PlainTextExtension>");
}

Gura_ImplementUserClass(PlainTextExtension)
{
}

//-----------------------------------------------------------------------------
// Object_ApplicationExtension
//-----------------------------------------------------------------------------
Object *Object_ApplicationExtension::Clone() const
{
	return new Object_ApplicationExtension(*this);
}

bool Object_ApplicationExtension::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(ApplicationIdentifier));
	symbols.insert(Gura_UserSymbol(AuthenticationCode));
	symbols.insert(Gura_UserSymbol(ApplicationData));
	return true;
}

Value Object_ApplicationExtension::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	GIF &gif = _pObjContent->GetGIF();
	evaluatedFlag = true;
	GIF::Extensions &exts = gif.GetExtensions();
	if (!exts.application.validFlag) return Value::Null;
	GIF::ApplicationExtension &app = exts.application;
	if (pSymbol->IsIdentical(Gura_UserSymbol(ApplicationIdentifier))) {
		return Value(new Object_binary(env, app.ApplicationIdentifier, sizeof(app.ApplicationIdentifier), true));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(AuthenticationCode))) {
		return Value(new Object_binary(env, app.AuthenticationCode, sizeof(app.AuthenticationCode), true));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ApplicationData))) {
		return Value(new Object_binary(env, app.ApplicationData, true));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_ApplicationExtension::ToString(bool exprFlag)
{
	return String("<gif.ApplicationExtension>");
}

Gura_ImplementUserClass(ApplicationExtension)
{
}

//-----------------------------------------------------------------------------
// GIF
//-----------------------------------------------------------------------------
GIF::GIF()
{
}

GIF::~GIF()
{
}

bool GIF::Read(Environment &env, Signal sig, Stream &stream,
								Image *pImageTgt, Image::Format format)
{
	if (!ReadBuff(sig, stream, &_header, 6)) return false;
	if (::memcmp(_header.Signature, "GIF", 3) != 0) {
		sig.SetError(ERR_FormatError, "Not a GIF file");
		return false;
	}
	if (::memcmp(_header.Version, "87a", 3) != 0 &&
							::memcmp(_header.Version, "89a", 3) != 0) {
		sig.SetError(ERR_FormatError, "unsupported version of GIF file");
		return false;
	}
	if (!ReadBuff(sig, stream, &_logicalScreenDescriptor, 7)) return false;
	if (_logicalScreenDescriptor.GlobalColorTableFlag()) {
		int nEntries = 1 << (_logicalScreenDescriptor.SizeOfGlobalColorTable() + 1);
		_pPaletteGlobal.reset(new Palette());
		_pPaletteGlobal->AllocBuff(nEntries);
		if (!ReadColorTable(sig, stream, _pPaletteGlobal.get())) return false;
	}
	GetList().clear();
	GraphicControlExtension graphicControl;
	do {
		// set default values
		graphicControl.BlockSize = 4;
		graphicControl.PackedFields = (1 << 2) | (0 << 1) | (0 << 0);
		Gura_PackUShort(graphicControl.DelayTime, 0);
		graphicControl.TransparentColorIndex = 0;
	} while (0);
	for (;;) {
		UChar imageSeparator;
		size_t bytesRead = stream.Read(sig, &imageSeparator, 1);
		if (bytesRead < 1) break;
		//::printf("%02x\n", imageSeparator);
		if (imageSeparator == SEP_ImageDescriptor) {
			if (pImageTgt != NULL) {
				ReadImageDescriptor(env, sig, stream, graphicControl, pImageTgt, NULL);
				break;
			} else if (format == Image::FORMAT_None) {
				if (!SkipImageDescriptor(sig, stream)) break;
			} else {
				AutoPtr<Object_image> pObjImage(new Object_image(env, new Image(format)));
				Value valueGIF;
				if (!ReadImageDescriptor(env, sig, stream,
						graphicControl, pObjImage->GetImage(), &valueGIF)) break;
				pObjImage->AssignValue(Gura_UserSymbol(gif), valueGIF, EXTRA_Public);
				GetList().push_back(Value(pObjImage.release()));
			}
		} else if (imageSeparator == SEP_ExtensionIntroducer) {
			UChar label;
			if (!ReadBuff(sig, stream, &label, 1)) break;
			//::printf("%02x - %02x\n", imageSeparator, label);
			if (label == GraphicControlExtension::Label) {
				if (!ReadBuff(sig, stream, &graphicControl, 5)) break;
				UChar blockTerminator;
				if (!ReadBuff(sig, stream, &blockTerminator, 1)) break;
			} else if (label == CommentExtension::Label) {
				_exts.comment.validFlag = true;
				if (!ReadDataBlocks(sig, stream, _exts.comment.CommentData)) break;
			} else if (label == PlainTextExtension::Label) {
				_exts.plainText.validFlag = true;
				if (!ReadBuff(sig, stream, &_exts.plainText, 13)) break;
				if (!ReadDataBlocks(sig, stream, _exts.plainText.PlainTextData)) break;
			} else if (label == ApplicationExtension::Label) {
				_exts.application.validFlag = true;
				if (!ReadBuff(sig, stream, &_exts.application, 12)) break;
				if (!ReadDataBlocks(sig, stream, _exts.application.ApplicationData)) break;
			}
			if (sig.IsSignalled()) break;
		} else if (imageSeparator == SEP_Trailer) {
			//::printf("%02x\n", imageSeparator);
			break;
		} else {
			sig.SetError(ERR_FormatError, "unknown separator %02x", imageSeparator);
			break;
		}
	}
	return !sig.IsSignalled();
}

bool GIF::Write(Environment &env, Signal sig, Stream &stream,
	const Color &colorBackground, bool validBackgroundFlag, UShort loopCount)
{
	if (GetList().empty()) {
		sig.SetError(ERR_ValueError, "no image to write");
		return false;
	}
	_pPaletteGlobal.reset(new Palette());
	_pPaletteGlobal->AllocBuff(256);
	size_t logicalScreenWidth = 0, logicalScreenHeight = 0;
	ValueList &valList = GetList();
	foreach (ValueList, pValue, valList) {
		if (!pValue->Is_image()) continue;
		const Object_image *pObjImage = Object_image::GetObject(*pValue);
		const Image *pImage = pObjImage->GetImage();
		const Palette *pPalette = pImage->GetPalette();
		if (pPalette != NULL && pPalette->CountEntries() <= 256) {
			if (_pPaletteGlobal->UpdateByPalette(pPalette, Palette::ShrinkNone)) {
				// nothing to do
			} else if (_pPaletteGlobal->Prepare(sig, Gura_Symbol(websafe))) {
				break;
			} else {
				return false;
			}
		} else if (_pPaletteGlobal->UpdateByImage(pImage, Palette::ShrinkNone)) {
			// nothing to do
		} else if (_pPaletteGlobal->Prepare(sig, Gura_Symbol(websafe))) {
			break;
		} else {
			return false;
		}
	}
	int backgroundColorIndex = -1;
	UChar transparentColorIndex = 0;
	UChar transparentColorFlag = 0;
	do {
		size_t idxBlank = _pPaletteGlobal->NextBlankIndex();
		if (idxBlank < _pPaletteGlobal->CountEntries()) {
			// add an entry for transparent color
			_pPaletteGlobal->SetEntry(idxBlank, 128, 128, 128, 0);
			transparentColorIndex = static_cast<UChar>(idxBlank);
			transparentColorFlag = 1;
			idxBlank++;
		}
		_pPaletteGlobal->Shrink(idxBlank, true);
	} while (0);
	if (validBackgroundFlag) {
		backgroundColorIndex = static_cast<int>(
				_pPaletteGlobal->LookupNearest(colorBackground));
	}
	foreach (ValueList, pValue, valList) {
		if (!pValue->Is_image()) continue;
		Object_image *pObjImage = Object_image::GetObject(*pValue);
		Image *pImage = pObjImage->GetImage();
		if (!pImage->CheckValid(sig)) return false;
		pImage->SetPalette(Palette::Reference(_pPaletteGlobal.get()));
		ImageDescriptor *pImageDescriptor = GetImageDescriptor(pObjImage);
		size_t width = pImage->GetWidth() +
						Gura_UnpackUShort(pImageDescriptor->ImageLeftPosition);
		size_t height = pImage->GetHeight() +
						Gura_UnpackUShort(pImageDescriptor->ImageTopPosition);
		if (logicalScreenWidth < width) logicalScreenWidth = width;
		if (logicalScreenHeight < height) logicalScreenHeight = height;
		GraphicControlExtension *pGraphicControl = GetGraphicControl(pObjImage);
		pGraphicControl->TransparentColorIndex = transparentColorIndex;
		pGraphicControl->PackedFields |= transparentColorFlag;
		if (backgroundColorIndex < 0) {
			backgroundColorIndex = GetPlausibleBackgroundIndex(
											_pPaletteGlobal.get(), pImage);
		}
	}
	if (backgroundColorIndex < 0) backgroundColorIndex = 0;
	do {
		UChar globalColorTableFlag = 1;
		UChar colorResolution = 7;
		UChar sortFlag = 0;
		UChar sizeOfGlobalColorTable = 0;
		int nEntries = static_cast<int>(_pPaletteGlobal->CountEntries());
		for ( ; nEntries > (1 << sizeOfGlobalColorTable); sizeOfGlobalColorTable++) ;
		sizeOfGlobalColorTable--;
		Gura_PackUShort(_logicalScreenDescriptor.LogicalScreenWidth,
						static_cast<UShort>(logicalScreenWidth));
		Gura_PackUShort(_logicalScreenDescriptor.LogicalScreenHeight,
						static_cast<UShort>(logicalScreenHeight));
		_logicalScreenDescriptor.PackedFields =
				(globalColorTableFlag << 7) | (colorResolution << 4) |
				(sortFlag << 3) | (sizeOfGlobalColorTable << 0);
		_logicalScreenDescriptor.BackgroundColorIndex =
						static_cast<UChar>(backgroundColorIndex);
		_logicalScreenDescriptor.PixelAspectRatio = 0;
	} while (0);
	do {
		_exts.application.validFlag = true;
		_exts.application.BlockSize = 11;
		::memcpy(_exts.application.ApplicationIdentifier, "NETSCAPE", 8);
		::memcpy(_exts.application.AuthenticationCode, "2.0", 3);
		UChar applicationData[3];
		applicationData[0] = 0x01;
		applicationData[1] = static_cast<UChar>(loopCount & 0xff);
		applicationData[2] = static_cast<UChar>((loopCount >> 8) & 0xff);
		_exts.application.ApplicationData =
						Binary(reinterpret_cast<char *>(applicationData), 3);
	} while (0);
	// Header
	if (!WriteBuff(sig, stream, &_header, 6)) return false;
	// Logical Screen Descriptor
	if (!WriteBuff(sig, stream, &_logicalScreenDescriptor, 7)) return false;
	// Global Color Table
	if (_logicalScreenDescriptor.GlobalColorTableFlag()) {
		if (!WriteColorTable(sig, stream, _pPaletteGlobal.get())) return false;
	}
	if (_exts.application.validFlag) {
		// Application
		const UChar buff[] = {
			SEP_ExtensionIntroducer, ApplicationExtension::Label
		};
		if (!WriteBuff(sig, stream, &buff, 2)) return false;
		if (!WriteBuff(sig, stream, &_exts.application, 12)) return false;
		if (!WriteDataBlocks(sig, stream, _exts.application.ApplicationData)) return false;
	}
	foreach (ValueList, pValue, GetList()) {
		if (!pValue->Is_image()) continue;
		Object_image *pObjImage = Object_image::GetObject(*pValue);
		Image *pImage = pObjImage->GetImage();
		GraphicControlExtension *pGraphicControl = GetGraphicControl(pObjImage);
		if (pGraphicControl == NULL) continue;
		if (!WriteGraphicControl(sig, stream, *pGraphicControl)) return false;
		if (!WriteImageDescriptor(env, sig, stream, *pGraphicControl, pObjImage)) return false;
	}
	do {
		// Trailer
		const UChar buff[] = { SEP_Trailer };
		if (!WriteBuff(sig, stream, buff, 1)) return false;
	} while (0);
	return false;
}

bool GIF::ReadDataBlocks(Signal sig, Stream &stream, Binary &binary)
{
	for (;;) {
		UChar blockSize;
		if (!ReadBuff(sig, stream, &blockSize, 1)) return false;
		if (blockSize == 0) break;
		char buff[256];
		if (!ReadBuff(sig, stream, buff, blockSize)) return false;
		binary.append(buff, blockSize);
	}
	return true;
}

bool GIF::WriteDataBlocks(Signal sig, Stream &stream, const Binary &binary)
{
	size_t size = binary.size();
	for (size_t offset = 0; offset < size; ) {
		UChar blockSize =
			static_cast<UChar>((size - offset <= 255)? size - offset : 255);
		if (!WriteBuff(sig, stream, &blockSize, 1)) return false;
		if (!WriteBuff(sig, stream, binary.data() + offset, blockSize)) return false;
		offset += blockSize;
	}
	do {
		UChar blockSize = 0x00;
		if (!WriteBuff(sig, stream, &blockSize, 1)) return false;
	} while (0);
	return true;
}

bool GIF::SkipImageDescriptor(Signal sig, Stream &stream)
{
	ImageDescriptor imageDescriptor;
	if (!ReadBuff(sig, stream, &imageDescriptor, 9)) return false;
	if (imageDescriptor.LocalColorTableFlag()) {
		int nEntries = 1 << (imageDescriptor.SizeOfLocalColorTable() + 1);
		stream.Seek(sig, nEntries * 3, Stream::SeekCur);
	}
	UChar mininumBitsOfCode;
	if (!ReadBuff(sig, stream, &mininumBitsOfCode, 1)) return false;
	for (;;) {
		UChar blockSize;
		if (!ReadBuff(sig, stream, &blockSize, 1)) return false;
		if (blockSize == 0) break;
		if (!stream.Seek(sig, blockSize, Stream::SeekCur)) return false;
	}
	return true;
}

bool GIF::ReadImageDescriptor(Environment &env, Signal sig, Stream &stream,
	const GraphicControlExtension &graphicControl, Image *pImage, Value *pValueGIF)
{
	ImageDescriptor imageDescriptor;
	if (!ReadBuff(sig, stream, &imageDescriptor, 9)) return false;
	size_t imageWidth = Gura_UnpackUShort(imageDescriptor.ImageWidth);
	size_t imageHeight = Gura_UnpackUShort(imageDescriptor.ImageHeight);
	if (!pImage->AllocBuffer(sig, imageWidth, imageHeight, 0xff)) return false;
	Palette *pPalette = NULL;
	if (imageDescriptor.LocalColorTableFlag()) {
		size_t nEntries = 1 << (imageDescriptor.SizeOfLocalColorTable() + 1);
		pPalette = pImage->CreateEmptyPalette(env, nEntries);
		if (!ReadColorTable(sig, stream, pPalette)) return false;
	} else {
		pPalette = Palette::Reference(_pPaletteGlobal.get());
		pImage->SetPalette(pPalette);
	}
	if (pValueGIF != NULL) {
		AutoPtr<Object_GraphicControl> pObjGraphicControl(
								new Object_GraphicControl(graphicControl));
		AutoPtr<Object_ImageDescriptor> pObjImageDescriptor(
								new Object_ImageDescriptor(imageDescriptor));
		*pValueGIF = Value(new Object_imgprop(pObjGraphicControl.release(), pObjImageDescriptor.release()));
	}
	short transparentColorIndex = graphicControl.TransparentColorIndex;
	if (!graphicControl.TransparentColorFlag() ||
					pImage->GetFormat() != Image::FORMAT_RGBA) {
		transparentColorIndex = -1;
	}
	const int maximumBitsOfCode = 12;
	UChar mininumBitsOfCode;
	if (!ReadBuff(sig, stream, &mininumBitsOfCode, 1)) return false;
	int bitsOfCode = mininumBitsOfCode + 1;
	if (bitsOfCode > maximumBitsOfCode) {
		sig.SetError(ERR_FormatError, "illegal code size");
		return false;
	}
	bool interlaceFlag = (imageDescriptor.InterlaceFlag() != 0);
	const UShort codeInvalid = 0xffff;
	UShort codeMaxCeiling = 1 << maximumBitsOfCode;
	UShort codeBoundary = 1 << mininumBitsOfCode;
	UShort codeClear = codeBoundary;
	UShort codeEnd = codeBoundary + 1;
	UShort codeMax = codeBoundary + 2;
	UShort codeFirst = codeInvalid, codeOld = codeInvalid;
	const size_t bytesCodeTable = codeMaxCeiling * 2;
	const size_t bytesCodeStack = codeMaxCeiling * 2;
	UShort *codeTable = new UShort [bytesCodeTable];
	UShort *codeStack = new UShort [bytesCodeStack];
	UShort *pCodeStack = codeStack;
	do {
		::memset(codeTable, 0x00, bytesCodeTable);
		for (UShort code = 0; code < codeBoundary; code++) {
			codeTable[code * 2 + 1] = code;
		}
	} while (0);
	ImageDataBlock imageDataBlock;
	size_t x = 0, y = 0;
	int iPass = 0;
	UChar *dstp = pImage->GetPointer(0);
	for (;;) {
		UShort code = 0;
		if (pCodeStack > codeStack) {
			pCodeStack--;
			code = *pCodeStack;
		} else {
			if (!imageDataBlock.ReadCode(sig, stream, code, bitsOfCode)) break;
			// LZW (Lempel-Ziv-Welch) decompression algorithm
			if (code == codeClear) {
				//::printf("clear\n");
				UShort code = 0;
				::memset(codeTable, 0x00, bytesCodeTable);
				for (UShort code = 0; code < codeBoundary; code++) {
					codeTable[code * 2 + 1] = code;
				}
				pCodeStack = codeStack;
				bitsOfCode = mininumBitsOfCode + 1;
				codeMax = codeBoundary + 2;
				codeFirst = codeOld = codeInvalid;
				continue;
			} else if (code == codeEnd) {
				// skip trailing blocks
				for (;;) {
					UChar blockSize;
					if (!ReadBuff(sig, stream, &blockSize, 1)) break;
					if (blockSize == 0) break;
					if (!stream.Seek(sig, blockSize, Stream::SeekCur)) break;
				}
				break;
			} else if (codeFirst == codeInvalid) {
				codeFirst = codeOld = code;
			} else {
				UShort codeIn = code;
				if (code >= codeMax) {
					*pCodeStack++ = codeFirst;
					code = codeOld;
				}
				while (code >= codeBoundary) {
					*pCodeStack++ = codeTable[code * 2 + 1];
					if (code == codeTable[code * 2 + 0]) {
						sig.SetError(ERR_FormatError, "invalid GIF format");
						goto done;
					}
					code = codeTable[code * 2 + 0];
				}
				codeFirst = codeTable[code * 2 + 1];
				*pCodeStack++ = codeFirst;
				if (codeMax < codeMaxCeiling) {
					codeTable[codeMax * 2 + 0] = codeOld;
					codeTable[codeMax * 2 + 1] = codeFirst;
					codeMax++;
					if (codeMax >= (1 << bitsOfCode) &&
											(1 << bitsOfCode) < codeMaxCeiling) {
						bitsOfCode++;
					}
				}
				codeOld = codeIn;
				if (pCodeStack > codeStack) {
					pCodeStack--;
					code = *pCodeStack;
				}
			}
		}
		const UChar *srcp = pPalette->GetEntry(code);
		if (x >= imageWidth) {
			x = 0;
			if (interlaceFlag) {
				static const int yStepTbl[] = { 8, 8, 4, 2, };
				y += yStepTbl[iPass];
				if (y >= imageHeight) {
					static const int yTbl[] = { 4, 2, 1, };
					if (iPass >= 3) break;
					y = yTbl[iPass++];
				}
			} else {
				y++;
				if (y >= imageHeight) break;
			}
			dstp = pImage->GetPointer(y);
		}
		//::printf("+ %3d,%3d code = %03x\n", x, y, code);
		*(dstp + 0) = *srcp++;
		*(dstp + 1) = *srcp++;
		*(dstp + 2) = *srcp++;
		if (code == transparentColorIndex) *(dstp + 3) = 0x00;
		dstp += pImage->GetBytesPerPixel();
		x++;
	}
done:
	delete[] codeTable;
	delete[] codeStack;
	return !sig.IsSignalled();
}

bool GIF::WriteGraphicControl(Signal sig, Stream &stream,
								const GraphicControlExtension &graphicControl)
{
	const UChar buff[] = {
		SEP_ExtensionIntroducer, GraphicControlExtension::Label
	};
	if (!WriteBuff(sig, stream, &buff, 2)) return false;
	if (!WriteBuff(sig, stream, &graphicControl, 5)) return false;
	UChar blockTerminator = 0x00;
	if (!WriteBuff(sig, stream, &blockTerminator, 1)) return false;
	return true;
}

bool GIF::WriteImageDescriptor(Environment &env, Signal sig, Stream &stream,
				const GraphicControlExtension &graphicControl, Object_image *pObjImage)
{
	Image *pImage = pObjImage->GetImage();
	do {
		const UChar buff[] = { SEP_ImageDescriptor };
		if (!WriteBuff(sig, stream, buff, 1)) return false;
	} while (0);
	const Palette *pPalette = _pPaletteGlobal.get();
	ImageDescriptor *pImageDescriptor = GetImageDescriptor(pObjImage);
	if (pImageDescriptor == NULL) {
		return false;
	}
	if (!WriteBuff(sig, stream, pImageDescriptor, 9)) return false;
	if (pImageDescriptor->LocalColorTableFlag()) {
		if (!WriteColorTable(sig, stream, pPalette)) return false;
	}
	UChar transparentColorIndex = graphicControl.TransparentColorIndex;
	bool transparentColorFlag = (pImage->GetFormat() == Image::FORMAT_RGBA) &&
					(graphicControl.TransparentColorFlag() != 0);
	const int maximumBitsOfCode = 12;
	UChar minimumBitsOfCode = 8;
	if (!WriteBuff(sig, stream, &minimumBitsOfCode, 1)) return false;
	Binary word;
	int bitsOfCode = minimumBitsOfCode + 1;
	UShort code = 0x0000;
	UShort codeBoundary = 1 << minimumBitsOfCode;
	UShort codeClear = codeBoundary;
	UShort codeEnd = codeBoundary + 1;
	UShort codeMax = codeBoundary + 2;
	UShort codeMaxCeiling = 1 << maximumBitsOfCode;
	TransMap transMap;
	ImageDataBlock imageDataBlock;
	if (!imageDataBlock.WriteCode(sig, stream, codeClear, bitsOfCode)) return false;
	for (size_t y = 0; y < pImage->GetHeight(); y++) {
		const UChar *pPixel = pImage->GetPointer(y);
		for (size_t x = 0; x < pImage->GetWidth();
							x++, pPixel += pImage->GetBytesPerPixel()) {
			// LZW (Lempel-Ziv-Welch) compression algorithm
			UChar k;
			if (transparentColorFlag && Image::GetPixelA(pPixel) < 128) {
				k = transparentColorIndex;
			} else {
				k = static_cast<UChar>(pPalette->LookupNearest(pPixel));
			}
			//::printf("- %3d,%3d code = %03x\n", x, y, k);
			if (word.empty()) {
				word += k;
				code = k;
				continue;
			}
			Binary wordK = word + static_cast<char>(k);
			TransMap::iterator iter = transMap.find(wordK);
			if (iter != transMap.end()) {
				word = wordK;
				code = iter->second;
				continue;
			}
			if (!imageDataBlock.WriteCode(sig, stream, code, bitsOfCode)) return false;
			transMap[wordK] = codeMax;
			if (codeMax < (1 << bitsOfCode)) {
				codeMax++;
			} else if ((1 << bitsOfCode) < codeMaxCeiling) {
				codeMax++;
				bitsOfCode++;
			} else {
				if (!imageDataBlock.WriteCode(sig, stream,
										codeClear, bitsOfCode)) return false;
				//::printf("clear\n");
				transMap.clear();
				codeMax = codeBoundary + 2;
				bitsOfCode = minimumBitsOfCode + 1;
			}
			word.clear();
			word += k;
			code = k;
		}
	}
	if (!imageDataBlock.WriteCode(sig, stream, code, bitsOfCode)) return false;
	if (!imageDataBlock.WriteCode(sig, stream, codeEnd, bitsOfCode)) return false;
	if (!imageDataBlock.Flush(sig, stream)) return false;
	return true;
}

bool GIF::ReadBuff(Signal sig, Stream &stream, void *buff, size_t bytes)
{
	size_t bytesRead = stream.Read(sig, buff, bytes);
	if (sig.IsSignalled()) return false;
	if (bytesRead < bytes) {
		sig.SetError(ERR_FormatError, "invalid GIF format");
		return false;
	}
	return true;
}

bool GIF::WriteBuff(Signal sig, Stream &stream, const void *buff, size_t bytes)
{
	size_t bytesWritten = stream.Write(sig, buff, bytes);
	return !sig.IsSignalled();
}

bool GIF::ReadColorTable(Signal sig, Stream &stream, Palette *pPalette)
{
	UChar buff[3];
	size_t nEntries = pPalette->CountEntries();
	for (size_t idx = 0; idx < nEntries; idx++) {
		if (!GIF::ReadBuff(sig, stream, buff, 3)) return false;
		pPalette->SetEntry(idx, buff[0], buff[1], buff[2]);
	}
	return true;
}

bool GIF::WriteColorTable(Signal sig, Stream &stream, const Palette *pPalette)
{
	UChar buff[3];
	int nEntries = static_cast<int>(pPalette->CountEntries());
	int idx = 0;
	for ( ; idx < nEntries; idx++) {
		const UChar *pEntry = pPalette->GetEntry(idx);
		buff[0] = *(pEntry + Image::OffsetR);
		buff[1] = *(pEntry + Image::OffsetG);
		buff[2] = *(pEntry + Image::OffsetB);
		if (!GIF::WriteBuff(sig, stream, buff, 3)) return false;
	}
	int nBits = 0;
	for ( ; nEntries > (1 << nBits); nBits++) ;
	::memset(buff, 0x00, 3);
	for ( ; idx < (1 << nBits); idx++) {
		if (!GIF::WriteBuff(sig, stream, buff, 3)) return false;
	}
	return true;
}

void GIF::AddImage(const Value &value, UShort delayTime,
		UShort imageLeftPosition, UShort imageTopPosition,
		UChar disposalMethod)
{
	Object_image *pObjImage = dynamic_cast<Object_image *>(value.GetObject());
	Image *pImage = pObjImage->GetImage();
	AutoPtr<Object_GraphicControl> pObjGraphicControl;
	AutoPtr<Object_ImageDescriptor> pObjImageDescriptor;
	do {
		GIF::GraphicControlExtension graphicControl;
		GIF::GraphicControlExtension graphicControlOrg;
		GIF::GraphicControlExtension *pGraphicControl = GetGraphicControl(pObjImage);
		if (pGraphicControl != NULL) {
			graphicControlOrg = *pGraphicControl;
		}
		graphicControl.PackedFields =
			(disposalMethod << 2) |
			(graphicControlOrg.UserInputFlag() << 1) |
			(graphicControlOrg.TransparentColorFlag() << 0);
		Gura_PackUShort(graphicControl.DelayTime, delayTime);
		graphicControl.TransparentColorIndex = graphicControlOrg.TransparentColorIndex;
		pObjGraphicControl.reset(new Object_GraphicControl(graphicControl));
	} while (0);
	do {
		GIF::ImageDescriptor imageDescriptor;
		GIF::ImageDescriptor imageDescriptorOrg;
		GIF::ImageDescriptor *pImageDescriptor = GetImageDescriptor(pObjImage);
		if (pImageDescriptor != NULL) {
			imageDescriptorOrg = *pImageDescriptor;
		}
		Gura_PackUShort(imageDescriptor.ImageLeftPosition, imageLeftPosition);
		Gura_PackUShort(imageDescriptor.ImageTopPosition, imageTopPosition);
		Gura_PackUShort(imageDescriptor.ImageWidth,
					static_cast<UShort>(pImage->GetWidth()));
		Gura_PackUShort(imageDescriptor.ImageHeight,
					static_cast<UShort>(pImage->GetHeight()));
		imageDescriptor.PackedFields =
			(imageDescriptorOrg.LocalColorTableFlag() << 7) |
			(imageDescriptorOrg.InterlaceFlag() << 6) |
			(imageDescriptorOrg.SortFlag() << 5) |
			(imageDescriptorOrg.SizeOfLocalColorTable() << 0);
		pObjImageDescriptor.reset(new Object_ImageDescriptor(imageDescriptor));
	} while (0);
	pObjImage->AssignValue(Gura_UserSymbol(gif), Value(new Object_imgprop(
		pObjGraphicControl.release(), pObjImageDescriptor.release())), EXTRA_Public);
	GetList().push_back(value);
}

void GIF::Dump(UChar *data, int bytes)
{
	for (int i = 0; i < bytes; i++) {
		int iCol = i % 16;
		::printf((iCol == 0)? "%02x" :
					(iCol == 15)? " %02x\n" : " %02x", data[i]);
	}
	if (bytes % 16 != 0) ::printf("\n");
}

const Symbol *GIF::DisposalMethodToSymbol(UChar disposalMethod)
{
	if (disposalMethod == 0) {
		return Gura_UserSymbol(none);
	} else if (disposalMethod == 1) {
		return Gura_UserSymbol(keep);
	} else if (disposalMethod == 2) {
		return Gura_UserSymbol(background);
	} else if (disposalMethod == 3) {
		return Gura_UserSymbol(previous);
	} else {
		return Gura_UserSymbol(none);
	}
}

UChar GIF::DisposalMethodFromSymbol(Signal sig, const Symbol *pSymbol)
{
	UChar disposalMethod;
	if (pSymbol->IsIdentical(Gura_UserSymbol(none))) {
		disposalMethod = 0;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(keep))) {
		disposalMethod = 1;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(background))) {
		disposalMethod = 2;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(previous))) {
		disposalMethod = 3;
	} else {
		sig.SetError(ERR_ValueError, "invalid symbol for disposal method: %s",
															pSymbol->GetName());
		return 0;
	}
	return disposalMethod;
}

GIF::GraphicControlExtension *GIF::GetGraphicControl(const Object_image *pObjImage)
{
	const Value *pValue = pObjImage->LookupValue(Gura_UserSymbol(gif), ENVREF_NoEscalate);
	if (pValue == NULL || !pValue->IsType(VTYPE_imgprop)) return NULL;
	return dynamic_cast<Object_imgprop *>(pValue->GetObject())->GetGraphicControl();
}

GIF::ImageDescriptor *GIF::GetImageDescriptor(const Object_image *pObjImage)
{
	const Value *pValue = pObjImage->LookupValue(Gura_UserSymbol(gif), ENVREF_NoEscalate);
	if (pValue == NULL || !pValue->IsType(VTYPE_imgprop)) return NULL;
	return dynamic_cast<Object_imgprop *>(pValue->GetObject())->GetImageDescriptor();
}

int GIF::GetPlausibleBackgroundIndex(Palette *pPalette, Image *pImage)
{
	int histTbl[256];
	::memset(histTbl, 0x00, sizeof(histTbl));
	std::auto_ptr<Image::Scanner> pScanner(pImage->CreateScanner());
	size_t iPixelEnd = pScanner->CountPixels() - 1;
	size_t iLineEnd = pScanner->CountLines() - 1;
	for (;;) {
		int idx = static_cast<int>(pPalette->LookupNearest(pScanner->GetPointer()));
		histTbl[idx]++;
		if (pScanner->GetPixelIdx() >= iPixelEnd) break;
		pScanner->FwdPixel();
	}
	for (;;) {
		int idx = static_cast<int>(pPalette->LookupNearest(pScanner->GetPointer()));
		histTbl[idx]++;
		if (pScanner->GetLineIdx() >= iLineEnd) break;
		pScanner->FwdLine();
	}
	for (;;) {
		int idx = static_cast<int>(pPalette->LookupNearest(pScanner->GetPointer()));
		histTbl[idx]++;
		if (pScanner->GetPixelIdx() == 0) break;
		pScanner->BwdPixel();
	}
	for (;;) {
		int idx = static_cast<int>(pPalette->LookupNearest(pScanner->GetPointer()));
		histTbl[idx]++;
		if (pScanner->GetLineIdx() == 0) break;
		pScanner->BwdLine();
	}
	int idxMax = 0;
	int histMax = histTbl[0];
	for (int idx = 1; idx < ArraySizeOf(histTbl); idx++) {
		if (histMax < histTbl[idx]) {
			idxMax = idx;
			histMax = histTbl[idx];
		}
	}
	return idxMax;
}

//-----------------------------------------------------------------------------
// GIF::ImageDataBlock
//-----------------------------------------------------------------------------
GIF::ImageDataBlock::ImageDataBlock() : _bitOffset(0), _bitsRead(0)
{
	::memset(_blockData, 0x00, 256);
}

bool GIF::ImageDataBlock::ReadCode(Signal sig, Stream &stream,
										UShort &code, int bitsOfCode)
{
	for (int bitsAccum = 0; bitsAccum < bitsOfCode; ) {
		int bitsRest = bitsOfCode - bitsAccum;
		if (_bitOffset >= _bitsRead) {
			UChar blockSize;
			if (!ReadBuff(sig, stream, &blockSize, 1)) return false;
			if (blockSize == 0) return false;
			if (!ReadBuff(sig, stream, _blockData, blockSize)) return false;
			_bitsRead = blockSize * 8;
			_bitOffset = 0;
		}
		UShort ch = static_cast<UShort>(_blockData[_bitOffset >> 3]);
		int bitsRight = _bitOffset & 7;
		int bitsLeft = 8 - bitsRight;
		if (bitsRest < bitsLeft) {
			code |= ((ch >> bitsRight) & ((1 << bitsRest) - 1)) << bitsAccum;
			_bitOffset += bitsRest;
			break;
		} else {
			code |= (ch >> bitsRight) << bitsAccum;
			bitsAccum += bitsLeft;
			_bitOffset += bitsLeft;
		}
	}
	return true;
}

bool GIF::ImageDataBlock::WriteCode(Signal sig, Stream &stream,
										UShort code, int bitsOfCode)
{
	const int bitsFull = 8 * 255;
	for (int bitsAccum = 0; bitsAccum < bitsOfCode; ) {
		int bitsRest = bitsOfCode - bitsAccum;
		if (_bitOffset >= bitsFull) {
			UChar blockSize = 255;
			if (!GIF::WriteBuff(sig, stream, &blockSize, 1)) return false;
			if (!GIF::WriteBuff(sig, stream, _blockData, blockSize)) return false;
			::memset(_blockData, 0x00, 256);
			_bitOffset -= bitsFull;
		}
		int bitsRight = _bitOffset & 7;
		int bitsLeft = 8 - bitsRight;
		_blockData[_bitOffset >> 3] |= static_cast<UChar>(code << bitsRight);
		if (bitsRest < bitsLeft) {
			_bitOffset += bitsRest;
			break;
		} else {
			code >>= bitsLeft;
			bitsAccum += bitsLeft;
			_bitOffset += bitsLeft;
		}
	}
	return true;
}

bool GIF::ImageDataBlock::Flush(Signal sig, Stream &stream)
{
	if (_bitOffset > 0) {
		UChar blockSize = static_cast<UChar>((_bitOffset + 7) / 8);
		if (!GIF::WriteBuff(sig, stream, &blockSize, 1)) return false;
		if (!GIF::WriteBuff(sig, stream, _blockData, blockSize)) return false;
	}
	do {
		UChar blockSize = 0x00;
		if (!WriteBuff(sig, stream, &blockSize, 1)) return false;
	} while (0);
	return true;
}

//-----------------------------------------------------------------------------
// Object_content
//-----------------------------------------------------------------------------
Object_content::~Object_content()
{
}

Object *Object_content::Clone() const
{
	return NULL;
}

bool Object_content::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(images));
	symbols.insert(Gura_UserSymbol(Header));
	symbols.insert(Gura_UserSymbol(LogicalScreenDescriptor));
	symbols.insert(Gura_UserSymbol(CommentExtension));
	symbols.insert(Gura_UserSymbol(PlainTextExtension));
	symbols.insert(Gura_UserSymbol(ApplicationExtension));
	return true;
}

Value Object_content::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	GIF::Extensions &exts = _gif.GetExtensions();
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(images))) {
		return Value(new Object_list(env, _gif.GetList()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Header))) {
		return Value(new Object_Header(Object_content::Reference(this)));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(LogicalScreenDescriptor))) {
		return Value(new Object_LogicalScreenDescriptor(Object_content::Reference(this)));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(CommentExtension))) {
		if (!exts.comment.validFlag) return Value::Null;
		return Value(new Object_CommentExtension(Object_content::Reference(this)));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(PlainTextExtension))) {
		if (!exts.plainText.validFlag) return Value::Null;
		return Value(new Object_PlainTextExtension(Object_content::Reference(this)));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ApplicationExtension))) {
		if (!exts.application.validFlag) return Value::Null;
		return Value(new Object_ApplicationExtension(Object_content::Reference(this)));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_content::ToString(bool exprFlag)
{
	String str = "<gif.content:";
	do {
		char buff[32];
		const ValueList &valList = _gif.GetList();
		::sprintf(buff, "%dimages", valList.size());
		str += buff;
	} while (0);
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_content
//-----------------------------------------------------------------------------
// gif.content#write(stream:stream:w):reduce
Gura_DeclareMethod(content, write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Writes a GIF image to a stream.");
}

Gura_ImplementMethod(content, write)
{
	GIF &gif = Object_content::GetThisObj(args)->GetGIF();
	Stream &stream = args.GetStream(0);
	UShort loopCount = 0;
	if (!gif.Write(env, sig, stream, Color::zero, false, loopCount)) {
		return Value::Null;
	}
	return args.GetThis();
}

// gif.content#addimage(image:image, delayTime:number => 0, 
//	leftPos:number => 0, topPos:number => 0, disposalMethod:symbol => `none):map:reduce
Gura_DeclareMethod(content, addimage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "image", VTYPE_image);
	DeclareArg(env, "delayTime", VTYPE_number, OCCUR_Once,
						FLAG_None, new Expr_Value(10));
	DeclareArg(env, "leftPos", VTYPE_number, OCCUR_Once,
						FLAG_None, new Expr_Value(0));
	DeclareArg(env, "topPos", VTYPE_number, OCCUR_Once,
						FLAG_None, new Expr_Value(0));
	DeclareArg(env, "disposalMethod", VTYPE_symbol, OCCUR_Once,
						FLAG_None, new Expr_Value(Gura_UserSymbol(none)));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Adds an image to GIF information. If you add multiple images, they are to be\n"
		"rendered in sequence like an animation. You can specify the delay time to\n"
		"switch to the next image by delayTime argument in 10 msec step.\n"
		"The offset for rendering is specified by leftPost and topPos.\n"
		"Parameter disposalMethod determine how the image should be treated after\n"
		"the time expires, and it takes one of `none, `keep, `background and `previous.\n");
}

Gura_ImplementMethod(content, addimage)
{
	GIF &gif = Object_content::GetThisObj(args)->GetGIF();
	UChar disposalMethod = GIF::DisposalMethodFromSymbol(sig, args.GetSymbol(4));
	if (sig.IsSignalled()) return Value::Null;
	gif.AddImage(args.GetValue(0), args.GetUShort(1),
					args.GetUShort(2), args.GetUShort(3), disposalMethod);
	return args.GetThis();
}

// implementation of class GIF
Gura_ImplementUserClass(content)
{
	Gura_AssignMethod(content, addimage);
	Gura_AssignMethod(content, write);
}

//-----------------------------------------------------------------------------
// Object_GraphicControl
//-----------------------------------------------------------------------------
Object_GraphicControl::~Object_GraphicControl()
{
}

Object *Object_GraphicControl::Clone() const
{
	return NULL;
}

bool Object_GraphicControl::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(DisposalMethod));
	symbols.insert(Gura_UserSymbol(UserInputFlag));
	symbols.insert(Gura_UserSymbol(TransparentColorFlag));
	symbols.insert(Gura_UserSymbol(DelayTime));
	symbols.insert(Gura_UserSymbol(TransparentColorIndex));
	return true;
}

Value Object_GraphicControl::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(DisposalMethod))) {
		return Value(GIF::DisposalMethodToSymbol(_gctl.DisposalMethod()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(UserInputFlag))) {
		return Value(_gctl.UserInputFlag()? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(TransparentColorFlag))) {
		return Value(_gctl.TransparentColorFlag()? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(DelayTime))) {
		return Value(Gura_UnpackUShort(_gctl.DelayTime));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(TransparentColorIndex))) {
		return Value(_gctl.TransparentColorIndex);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_GraphicControl::ToString(bool exprFlag)
{
	return String("<gif.GraphicControl>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_GraphicControl
//-----------------------------------------------------------------------------
// implementation of class GraphicControl
Gura_ImplementUserClass(GraphicControl)
{
}

//-----------------------------------------------------------------------------
// Object_ImageDescriptor
//-----------------------------------------------------------------------------
Object_ImageDescriptor::~Object_ImageDescriptor()
{
}

Object *Object_ImageDescriptor::Clone() const
{
	return NULL;
}

bool Object_ImageDescriptor::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(ImageLeftPosition));
	symbols.insert(Gura_UserSymbol(ImageTopPosition));
	symbols.insert(Gura_UserSymbol(ImageWidth));
	symbols.insert(Gura_UserSymbol(ImageHeight));
	symbols.insert(Gura_UserSymbol(LocalColorTableFlag));
	symbols.insert(Gura_UserSymbol(InterlaceFlag));
	symbols.insert(Gura_UserSymbol(SortFlag));
	symbols.insert(Gura_UserSymbol(SizeOfLocalColorTable));
	return true;
}

Value Object_ImageDescriptor::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(ImageLeftPosition))) {
		return Value(Gura_UnpackUShort(_desc.ImageLeftPosition));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ImageTopPosition))) {
		return Value(Gura_UnpackUShort(_desc.ImageTopPosition));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ImageWidth))) {
		return Value(Gura_UnpackUShort(_desc.ImageWidth));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ImageHeight))) {
		return Value(Gura_UnpackUShort(_desc.ImageHeight));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(LocalColorTableFlag))) {
		return Value(_desc.LocalColorTableFlag()? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(InterlaceFlag))) {
		return Value(_desc.InterlaceFlag()? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(SortFlag))) {
		return Value(_desc.SortFlag()? true : false);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(SizeOfLocalColorTable))) {
		return Value(static_cast<UInt>(_desc.SizeOfLocalColorTable()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_ImageDescriptor::ToString(bool exprFlag)
{
	return String("<gif.ImageDescriptor>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_ImageDescriptor
//-----------------------------------------------------------------------------
// implementation of class ImageDescriptor
Gura_ImplementUserClass(ImageDescriptor)
{
}

//-----------------------------------------------------------------------------
// Object_imgprop
//-----------------------------------------------------------------------------
Object_imgprop::~Object_imgprop()
{
}

Object *Object_imgprop::Clone() const
{
	return NULL;
}

bool Object_imgprop::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(GraphicControl));
	symbols.insert(Gura_UserSymbol(ImageDescriptor));
	return true;
}

Value Object_imgprop::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(GraphicControl))) {
		return Value(Object_GraphicControl::Reference(_pObjGraphicControl.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(ImageDescriptor))) {
		return Value(Object_ImageDescriptor::Reference(_pObjImageDescriptor.get()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_imgprop::ToString(bool exprFlag)
{
	return String("<gif.imgprop>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_imgprop
//-----------------------------------------------------------------------------
// implementation of class imgprop
Gura_ImplementUserClass(imgprop)
{
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_image
// These methods are available after importing gif module.
//-----------------------------------------------------------------------------
// image#read@gif(stream:stream:r):reduce
Gura_DeclareMethodAlias(image, read_gif, "read@gif")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads a GIF image from a stream.");
}

Gura_ImplementMethod(image, read_gif)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	Image *pImage = pThis->GetImage();
	if (!pImage->CheckEmpty(sig)) return Value::Null;
	Stream &stream = args.GetStream(0);
	if (!GIF().Read(env, sig, stream, pImage, pImage->GetFormat())) {
		return Value::Null;
	}
	return args.GetThis();
}

// image#write@gif(stream:stream:w):reduce
Gura_DeclareMethodAlias(image, write_gif, "write@gif")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Writes a GIF image to a stream.");
}

Gura_ImplementMethod(image, write_gif)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	Image *pImage = pThis->GetImage();
	if (!pImage->CheckValid(sig)) return Value::Null;
	Stream &stream = args.GetStream(0);
	GIF gif;
	gif.AddImage(args.GetThis(), 0, 0, 0, 1);
	UShort loopCount = 0;
	if (!gif.Write(env, sig, stream, Color::zero, false, loopCount)) {
		return Value::Null;
	}
	return args.GetThis();
}

//-----------------------------------------------------------------------------
// Gura module functions: content
//-----------------------------------------------------------------------------
// gif.content(stream?:stream:r, format.symbol => `rgba) {block?}
Gura_DeclareFunction(content)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_Once,
						FLAG_None, new Expr_Value(Gura_Symbol(rgba)));
	SetClassToConstruct(Gura_UserClass(content));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Reads a GIF data from a stream and returns an object that contains\n"
		"GIF related information and images of a specified format. format is\n"
		"is `rgb, `rgba or `noimage. If `noimage is specified, only the\n"
		"information data is read");
}

Gura_ImplementFunction(content)
{
	Object_content *pObjContent = new Object_content();
	if (args.Is_stream(0)) {
		Stream &stream = args.GetStream(0);
		const Symbol *pSymbol = args.GetSymbol(1);
		Image::Format format = Image::FORMAT_None;
		if (!pSymbol->IsIdentical(Gura_UserSymbol(noimage))) {
			format = Image::SymbolToFormat(sig, pSymbol);
			if (sig.IsSignalled()) return Value::Null;
		}
		if (!pObjContent->GetGIF().Read(env, sig, stream, NULL, format)) {
			return Value::Null;
		}
	}
	return ReturnValue(env, sig, args, Value(pObjContent));
}

// Module entry
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(noimage);
	Gura_RealizeUserSymbol(images);
	Gura_RealizeUserSymbol(none);
	Gura_RealizeUserSymbol(keep);
	Gura_RealizeUserSymbol(background);
	Gura_RealizeUserSymbol(previous);
	Gura_RealizeUserSymbol(gif);
	Gura_RealizeUserSymbol(Header);
	Gura_RealizeUserSymbol(Signature);
	Gura_RealizeUserSymbol(Version);
	Gura_RealizeUserSymbol(LogicalScreenDescriptor);
	Gura_RealizeUserSymbol(LogicalScreenWidth);
	Gura_RealizeUserSymbol(LogicalScreenHeight);
	Gura_RealizeUserSymbol(GlobalColorTableFlag);
	Gura_RealizeUserSymbol(ColorResolution);
	Gura_RealizeUserSymbol(SortFlag);
	Gura_RealizeUserSymbol(SizeOfGlobalColorTable);
	Gura_RealizeUserSymbol(BackgroundColorIndex);
	Gura_RealizeUserSymbol(BackgroundColor);
	Gura_RealizeUserSymbol(PixelAspectRatio);
	Gura_RealizeUserSymbol(CommentExtension);
	Gura_RealizeUserSymbol(CommentData);
	Gura_RealizeUserSymbol(PlainTextExtension);
	Gura_RealizeUserSymbol(TextGridLeftPosition);
	Gura_RealizeUserSymbol(TextGridTopPosition);
	Gura_RealizeUserSymbol(TextGridWidth);
	Gura_RealizeUserSymbol(TextGridHeight);
	Gura_RealizeUserSymbol(CharacterCellWidth);
	Gura_RealizeUserSymbol(CharacterCellHeight);
	Gura_RealizeUserSymbol(TextForegroundColorIndex);
	Gura_RealizeUserSymbol(TextBackgroundColorIndex);
	Gura_RealizeUserSymbol(PlainTextData);
	Gura_RealizeUserSymbol(ApplicationExtension);
	Gura_RealizeUserSymbol(ApplicationIdentifier);
	Gura_RealizeUserSymbol(AuthenticationCode);
	Gura_RealizeUserSymbol(ApplicationData);
	Gura_RealizeUserSymbol(DisposalMethod);
	Gura_RealizeUserSymbol(UserInputFlag);
	Gura_RealizeUserSymbol(TransparentColorFlag);
	Gura_RealizeUserSymbol(DelayTime);
	Gura_RealizeUserSymbol(TransparentColorIndex);
	Gura_RealizeUserSymbol(ImageLeftPosition);
	Gura_RealizeUserSymbol(ImageTopPosition);
	Gura_RealizeUserSymbol(ImageWidth);
	Gura_RealizeUserSymbol(ImageHeight);
	Gura_RealizeUserSymbol(LocalColorTableFlag);
	Gura_RealizeUserSymbol(InterlaceFlag);
	//Gura_RealizeUserSymbol(SortFlag);
	Gura_RealizeUserSymbol(SizeOfLocalColorTable);
	Gura_RealizeUserSymbol(GraphicControl);
	Gura_RealizeUserSymbol(ImageDescriptor);
	Gura_RealizeUserClass(content, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(Header, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(LogicalScreenDescriptor, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(CommentExtension, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(PlainTextExtension, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(ApplicationExtension, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(GraphicControl, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(ImageDescriptor, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(imgprop, env.LookupClass(VTYPE_object));
	// method assignment to image class
	Gura_AssignMethodTo(VTYPE_image, image, read_gif);
	Gura_AssignMethodTo(VTYPE_image, image, write_gif);
	// function assignment
	Gura_AssignFunction(content);
	// image streamer registration
	ImageStreamer::Register(new ImageStreamer_GIF());
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// ImageStreamer_GIF
//-----------------------------------------------------------------------------
bool ImageStreamer_GIF::IsResponsible(Signal sig, Stream &stream)
{
	if (stream.IsReadable()) {
		char buff[6];
		size_t bytesPeeked = stream.Peek(sig, buff, 6);
		if (sig.IsSignalled()) return false;
		return bytesPeeked == 6 &&
			(::memcmp(buff, "GIF87a", 6) == 0 || ::memcmp(buff, "GIF89a", 6) == 0);
	}
	return stream.HasNameSuffix(".gif");
}

bool ImageStreamer_GIF::Read(Environment &env, Signal sig,
										Image *pImage, Stream &stream)
{
	if (!pImage->CheckEmpty(sig)) return false;
	return GIF().Read(env, sig, stream, pImage, pImage->GetFormat());
}

bool ImageStreamer_GIF::Write(Environment &env, Signal sig,
										Image *pImage, Stream &stream)
{
	if (!pImage->CheckValid(sig)) return false;
	GIF gif;
	Value value(new Object_image(env, Image::Reference(pImage)));
	gif.AddImage(value, 0, 0, 0, 1);
	UShort loopCount = 0;
	return gif.Write(env, sig, stream, Color::zero, false, loopCount);
}

Gura_EndModuleBody(gif, gif)

Gura_RegisterModule(gif)
