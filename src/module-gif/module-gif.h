//-----------------------------------------------------------------------------
// Gura module: gif
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_GIF_H__
#define __GURA_MODULE_GIF_H__
#include <gura.h>

Gura_BeginModuleHeader(gif)

Gura_DeclareUserSymbol(noimage);

Gura_DeclareUserSymbol(images);

Gura_DeclareUserSymbol(none);
Gura_DeclareUserSymbol(keep);
Gura_DeclareUserSymbol(background);
Gura_DeclareUserSymbol(previous);

Gura_DeclareUserSymbol(gif);

Gura_DeclareUserSymbol(Header);
Gura_DeclareUserSymbol(Signature);
Gura_DeclareUserSymbol(Version);

Gura_DeclareUserSymbol(LogicalScreenDescriptor);
Gura_DeclareUserSymbol(LogicalScreenWidth);
Gura_DeclareUserSymbol(LogicalScreenHeight);
Gura_DeclareUserSymbol(GlobalColorTableFlag);
Gura_DeclareUserSymbol(ColorResolution);
Gura_DeclareUserSymbol(SortFlag);
Gura_DeclareUserSymbol(SizeOfGlobalColorTable);
Gura_DeclareUserSymbol(BackgroundColorIndex);
Gura_DeclareUserSymbol(BackgroundColor);
Gura_DeclareUserSymbol(PixelAspectRatio);

Gura_DeclareUserSymbol(CommentExtension);
Gura_DeclareUserSymbol(CommentData);

Gura_DeclareUserSymbol(PlainTextExtension);
Gura_DeclareUserSymbol(TextGridLeftPosition);
Gura_DeclareUserSymbol(TextGridTopPosition);
Gura_DeclareUserSymbol(TextGridWidth);
Gura_DeclareUserSymbol(TextGridHeight);
Gura_DeclareUserSymbol(CharacterCellWidth);
Gura_DeclareUserSymbol(CharacterCellHeight);
Gura_DeclareUserSymbol(TextForegroundColorIndex);
Gura_DeclareUserSymbol(TextBackgroundColorIndex);
Gura_DeclareUserSymbol(PlainTextData);

Gura_DeclareUserSymbol(ApplicationExtension);
Gura_DeclareUserSymbol(ApplicationIdentifier);
Gura_DeclareUserSymbol(AuthenticationCode);
Gura_DeclareUserSymbol(ApplicationData);

Gura_DeclareUserSymbol(DisposalMethod);
Gura_DeclareUserSymbol(UserInputFlag);
Gura_DeclareUserSymbol(TransparentColorFlag);
Gura_DeclareUserSymbol(DelayTime);
Gura_DeclareUserSymbol(TransparentColorIndex);

Gura_DeclareUserSymbol(ImageLeftPosition);
Gura_DeclareUserSymbol(ImageTopPosition);
Gura_DeclareUserSymbol(ImageWidth);
Gura_DeclareUserSymbol(ImageHeight);
Gura_DeclareUserSymbol(LocalColorTableFlag);
Gura_DeclareUserSymbol(InterlaceFlag);
//Gura_DeclareUserSymbol(SortFlag);
Gura_DeclareUserSymbol(SizeOfLocalColorTable);

Gura_DeclareUserSymbol(GraphicControl);
Gura_DeclareUserSymbol(ImageDescriptor);

//-----------------------------------------------------------------------------
// ImageStreamer_GIF
//-----------------------------------------------------------------------------
class ImageStreamer_GIF : public ImageStreamer {
public:
	inline ImageStreamer_GIF() : ImageStreamer("gif") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Image *pImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Image *pImage, Stream &stream);
};

//-----------------------------------------------------------------------------
// GIF
//-----------------------------------------------------------------------------
class GIF {
public:
	enum {
		SEP_ImageDescriptor		= 0x2c,
		SEP_ExtensionIntroducer	= 0x21,
		SEP_Trailer				= 0x3b,
	};
	struct Header {
		char Signature[3];
		char Version[3];
		inline Header() {
			::memcpy(Signature, "GIF", 3);
			::memcpy(Version, "89a", 3);
		}
	};
	struct LogicalScreenDescriptor {
		Gura_PackedUShort_LE(LogicalScreenWidth);
		Gura_PackedUShort_LE(LogicalScreenHeight);
		UChar PackedFields;
		UChar BackgroundColorIndex;
		UChar PixelAspectRatio;
		inline UChar GlobalColorTableFlag() const { return (PackedFields >> 7) & 1; }
		inline UChar ColorResolution() const { return (PackedFields >> 4) & 7; }
		inline UChar SortFlag() const { return (PackedFields >> 3) & 1; }
		inline size_t SizeOfGlobalColorTable() const { return (PackedFields >> 0) & 7; }
	};
	struct ImageDescriptor {
		Gura_PackedUShort_LE(ImageLeftPosition);
		Gura_PackedUShort_LE(ImageTopPosition);
		Gura_PackedUShort_LE(ImageWidth);
		Gura_PackedUShort_LE(ImageHeight);
		UChar PackedFields;
		inline ImageDescriptor() {
			Gura_PackUShort(ImageLeftPosition, 0);
			Gura_PackUShort(ImageTopPosition, 0);
			Gura_PackUShort(ImageWidth, 0);
			Gura_PackUShort(ImageHeight, 0);
			PackedFields = 0x00;
		}
		inline UChar LocalColorTableFlag() const { return (PackedFields >> 7) & 1; }
		inline UChar InterlaceFlag() const { return (PackedFields >> 6) & 1; }
		inline UChar SortFlag() const { return (PackedFields >> 5) & 1; }
		inline UChar SizeOfLocalColorTable() const { return (PackedFields >> 0) & 7; }
	};
	struct GraphicControlExtension {
		UChar BlockSize;
		UChar PackedFields;
		Gura_PackedUShort_LE(DelayTime);
		UChar TransparentColorIndex;
		enum { Label = 0xf9 };
		inline GraphicControlExtension() {
			BlockSize = 4;
			PackedFields = 0x00;
			Gura_PackUShort(DelayTime, 0);
			TransparentColorIndex = 0;
		}
		inline UChar DisposalMethod() const { return (PackedFields >> 2) & 7; }
		inline UChar UserInputFlag() const { return (PackedFields >> 1) & 1; }
		inline UChar TransparentColorFlag() const { return (PackedFields >> 0) & 1; }
	};
	struct CommentExtension {
		Binary CommentData;
		bool validFlag;
		enum { Label = 0xfe };
		inline CommentExtension() {
			validFlag = false;
		}
	};
	struct PlainTextExtension {
		UChar BlockSize;
		Gura_PackedUShort_LE(TextGridLeftPosition);
		Gura_PackedUShort_LE(TextGridTopPosition);
		Gura_PackedUShort_LE(TextGridWidth);
		Gura_PackedUShort_LE(TextGridHeight);
		UChar CharacterCellWidth;
		UChar CharacterCellHeight;
		UChar TextForegroundColorIndex;
		UChar TextBackgroundColorIndex;
		Binary PlainTextData;
		bool validFlag;
		enum { Label = 0x01 };
		inline PlainTextExtension() {
			BlockSize = 12;
			Gura_PackUShort(TextGridLeftPosition, 0);
			Gura_PackUShort(TextGridTopPosition, 0);
			Gura_PackUShort(TextGridWidth, 0);
			Gura_PackUShort(TextGridHeight, 0);
			CharacterCellWidth = 0;
			CharacterCellHeight = 0;
			TextForegroundColorIndex = 0;
			TextBackgroundColorIndex = 0;
			validFlag = false;
		}
	};
	struct ApplicationExtension {
		UChar BlockSize;
		char ApplicationIdentifier[8];
		char AuthenticationCode[3];
		Binary ApplicationData;
		bool validFlag;
		enum { Label = 0xff };
		inline ApplicationExtension() {
			BlockSize = 11;
			::memset(ApplicationIdentifier, 0x00, 8);
			::memset(AuthenticationCode, 0x00, 3);
			validFlag = false;
		}
	};
	struct Extensions {
		CommentExtension comment;
		PlainTextExtension plainText;
		ApplicationExtension application;
	};
	class ImageDataBlock {
	private:
		int _bitOffset;
		int _bitsRead;
		UChar _blockData[256];
	public:
		ImageDataBlock();
		bool ReadCode(Signal sig, Stream &stream, UShort &code, int bitsOfCode);
		bool WriteCode(Signal sig, Stream &stream, UShort code, int bitsOfCode);
		bool Flush(Signal sig, Stream &stream);
	};
	typedef std::map<Binary, UShort> TransMap;
private:
	Header _header;
	LogicalScreenDescriptor _logicalScreenDescriptor;
	AutoPtr<Palette> _pPaletteGlobal;
	Extensions _exts;
	ValueList _valList;
public:
	GIF();
	~GIF();
	bool Read(Environment &env, Signal sig, Stream &stream,
								Image *pImageTgt, Image::Format format);
	bool Write(Environment &env, Signal sig, Stream &stream,
		const Color &colorBackground, bool validBackgroundFlag, UShort loopCount);
	bool ReadColorTable(Signal sig, Stream &stream, Palette *pPalette);
	bool WriteColorTable(Signal sig, Stream &stream, const Palette *pPalette);
	bool ReadDataBlocks(Signal sig, Stream &stream, Binary &binary);
	bool WriteDataBlocks(Signal sig, Stream &stream, const Binary &binary);
	bool SkipImageDescriptor(Signal sig, Stream &stream);
	bool ReadImageDescriptor(Environment &env, Signal sig, Stream &stream,
								const GraphicControlExtension &graphicControl,
								Image *pImage, Value *pValueGIF);
	bool WriteGraphicControl(Signal sig, Stream &stream,
								const GraphicControlExtension &graphiControl);
	bool WriteImageDescriptor(Environment &env, Signal sig, Stream &stream,
		const GraphicControlExtension &graphicControl, Object_image *pObjImage);
	inline Header &GetHeader() { return _header; }
	inline LogicalScreenDescriptor &GetLogicalScreenDescriptor() {
		return _logicalScreenDescriptor;
	}
	inline Palette *GetGlobalPalette() { return _pPaletteGlobal.get(); }
	inline Extensions &GetExtensions() { return _exts; }
	inline ValueList &GetList() { return _valList; }
	void AddImage(const Value &value,
			UShort imageLeftPosition, UShort imageTopPosition,
			UShort delayTime, UChar disposalMethod);
	static bool ReadBuff(Signal sig, Stream &stream, void *buff, size_t bytes);
	static bool WriteBuff(Signal sig, Stream &stream, const void *buff, size_t bytes);
	static void Dump(UChar *data, int bytes);
	static const Symbol *DisposalMethodToSymbol(UChar disposalMethod);
	static UChar DisposalMethodFromSymbol(Signal sig, const Symbol *pSymbol);
	static ImageDescriptor *GetImageDescriptor(const Object_image *pObjImage);
	static GraphicControlExtension *GetGraphicControl(const Object_image *pObjImage);
	static int GetPlausibleBackgroundIndex(Palette *pPalette, Image *pImage);
};

//-----------------------------------------------------------------------------
// Object_content
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(content);

class Object_content : public Object {
public:
	Gura_DeclareObjectAccessor(content)
private:
	GIF _gif;
public:
	inline Object_content() : Object(Gura_UserClass(content)) {}
	virtual ~Object_content();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline GIF &GetGIF() { return _gif; }
};

//-----------------------------------------------------------------------------
// Object_Header
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Header);

class Object_Header : public Object {
private:
	AutoPtr<Object_content> _pObjContent;
public:
	inline Object_Header(const Object_Header &obj) :
				Object(Gura_UserClass(Header)),
				_pObjContent(Object_content::Reference(obj._pObjContent.get())) {}
	inline Object_Header(Object_content *pObjContent) :
				Object(Gura_UserClass(Header)), _pObjContent(pObjContent) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Object_LogicalScreenDescriptor
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(LogicalScreenDescriptor);

class Object_LogicalScreenDescriptor : public Object {
private:
	AutoPtr<Object_content> _pObjContent;
public:
	inline Object_LogicalScreenDescriptor(const Object_LogicalScreenDescriptor &obj) :
				Object(Gura_UserClass(LogicalScreenDescriptor)),
				_pObjContent(Object_content::Reference(obj._pObjContent.get())) {}
	inline Object_LogicalScreenDescriptor(Object_content *pObjContent) :
				Object(Gura_UserClass(LogicalScreenDescriptor)), _pObjContent(pObjContent) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Object_CommentExtension
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(CommentExtension);

class Object_CommentExtension : public Object {
private:
	AutoPtr<Object_content> _pObjContent;
public:
	inline Object_CommentExtension(const Object_CommentExtension &obj) :
				Object(Gura_UserClass(CommentExtension)),
				_pObjContent(Object_content::Reference(obj._pObjContent.get())) {}
	inline Object_CommentExtension(Object_content *pObjContent) :
				Object(Gura_UserClass(CommentExtension)), _pObjContent(pObjContent) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Object_PlainTextExtension
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(PlainTextExtension);

class Object_PlainTextExtension : public Object {
private:
	AutoPtr<Object_content> _pObjContent;
public:
	inline Object_PlainTextExtension(const Object_PlainTextExtension &obj) :
				Object(Gura_UserClass(PlainTextExtension)),
				_pObjContent(Object_content::Reference(obj._pObjContent.get())) {}
	inline Object_PlainTextExtension(Object_content *pObjContent) :
				Object(Gura_UserClass(PlainTextExtension)), _pObjContent(pObjContent) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Object_ApplicationExtension
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ApplicationExtension);

class Object_ApplicationExtension : public Object {
private:
	AutoPtr<Object_content> _pObjContent;
public:
	inline Object_ApplicationExtension(const Object_ApplicationExtension &obj) :
				Object(Gura_UserClass(ApplicationExtension)),
				_pObjContent(Object_content::Reference(obj._pObjContent.get())) {}
	inline Object_ApplicationExtension(Object_content *pObjContent) :
				Object(Gura_UserClass(ApplicationExtension)), _pObjContent(pObjContent) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Object_GraphicControl
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(GraphicControl);

class Object_GraphicControl : public Object {
public:
	Gura_DeclareObjectAccessor(GraphicControl)
private:
	GIF::GraphicControlExtension _gctl;
public:
	inline Object_GraphicControl(const GIF::GraphicControlExtension &gctl) :
					Object(Gura_UserClass(GraphicControl)), _gctl(gctl) {}
	virtual ~Object_GraphicControl();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline GIF::GraphicControlExtension *GetGraphicControl() { return &_gctl; }
};

//-----------------------------------------------------------------------------
// Object_ImageDescriptor
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(ImageDescriptor);

class Object_ImageDescriptor : public Object {
public:
	Gura_DeclareObjectAccessor(ImageDescriptor)
private:
	GIF::ImageDescriptor _desc;
public:
	inline Object_ImageDescriptor(const GIF::ImageDescriptor &desc) :
					Object(Gura_UserClass(ImageDescriptor)), _desc(desc) {}
	virtual ~Object_ImageDescriptor();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline GIF::ImageDescriptor *GetImageDescriptor() { return &_desc; }
};

//-----------------------------------------------------------------------------
// Object_imgprop
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(imgprop);

class Object_imgprop : public Object {
public:
	Gura_DeclareObjectAccessor(imgprop)
private:
	AutoPtr<Object_GraphicControl> _pObjGraphicControl;
	AutoPtr<Object_ImageDescriptor> _pObjImageDescriptor;
public:
	inline Object_imgprop(Object_GraphicControl *pObjGraphicControl, Object_ImageDescriptor *pObjImageDescriptor) :
				Object(Gura_UserClass(imgprop)),
				_pObjGraphicControl(pObjGraphicControl),
				_pObjImageDescriptor(pObjImageDescriptor) {}
	virtual ~Object_imgprop();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline GIF::GraphicControlExtension *GetGraphicControl() {
		return _pObjGraphicControl->GetGraphicControl();
	}
	inline GIF::ImageDescriptor *GetImageDescriptor() {
		return _pObjImageDescriptor->GetImageDescriptor();
	}
};

Gura_EndModuleHeader(gif)

#endif
