//-----------------------------------------------------------------------------
// Gura msicon module
//-----------------------------------------------------------------------------
#ifndef __MODULE_MSICO_H__
#define __MODULE_MSICO_H__
#include <gura.h>

Gura_BeginModuleHeader(msico, msico)

Gura_DeclareUserSymbol(images);

//-----------------------------------------------------------------------------
// Data structure for Windows ICO format
// http://msdn.microsoft.com/en-us/library/ms997538.aspx
//-----------------------------------------------------------------------------
struct IconDir {
	enum { Size = 6 };
	Gura_PackedUShort_LE(idReserved);
	Gura_PackedUShort_LE(idType);
	Gura_PackedUShort_LE(idCount);
};

struct IconDirEntry {
	enum { Size = 16 };
	UChar bWidth;
	UChar bHeight;
	UChar bColorCount;
	UChar bReserved;
	Gura_PackedUShort_LE(wPlanes);
	Gura_PackedUShort_LE(wBitCount);
	Gura_PackedULong_LE(dwBytesInRes);
	Gura_PackedULong_LE(dwImageOffset);
};

//-----------------------------------------------------------------------------
// Object_content
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(content);

class Object_content : public Object {
public:
	Gura_DeclareObjectAccessor(content)
private:
	ValueList _valList;
public:
	inline Object_content() : Object(Gura_UserClass(content)) {}
	inline Object_content(const Object_content &obj) : Object(obj) {}
	virtual ~Object_content();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	bool Read(Environment &env, Signal sig, Stream &stream, Image::Format format);
	bool Write(Environment &env, Signal sig, Stream &stream);
	void AddImage(const Value &value);
};

//-----------------------------------------------------------------------------
// ImageStreamer_ICO
//-----------------------------------------------------------------------------
class ImageStreamer_ICO : public ImageStreamer {
public:
	inline ImageStreamer_ICO() : ImageStreamer("msico") {}
	virtual bool IsResponsible(Signal sig, Stream &stream);
	virtual bool Read(Environment &env, Signal sig, Image *pImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Image *pImage, Stream &stream);
public:
	static bool ReadStream(Environment &env, Signal sig, Image *pImage, Stream &stream, int idx);
};

Gura_EndModuleHeader(msico, msico)

#endif
