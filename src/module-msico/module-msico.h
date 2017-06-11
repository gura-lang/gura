//-----------------------------------------------------------------------------
// Gura module: msicon
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_MSICO_H__
#define __GURA_MODULE_MSICO_H__
#include <gura.h>

Gura_BeginModuleHeader(msico)

Gura_DeclareUserSymbol(images);

//-----------------------------------------------------------------------------
// Data structure for Windows ICO format
// http://msdn.microsoft.com/en-us/library/ms997538.aspx
//-----------------------------------------------------------------------------
struct IconDir {
	enum { Size = 6 };
	Gura_PackedUInt16_LE(idReserved);
	Gura_PackedUInt16_LE(idType);
	Gura_PackedUInt16_LE(idCount);
};

struct IconDirEntry {
	enum { Size = 16 };
	UChar bWidth;
	UChar bHeight;
	UChar bColorCount;
	UChar bReserved;
	Gura_PackedUInt16_LE(wPlanes);
	Gura_PackedUInt16_LE(wBitCount);
	Gura_PackedUInt32_LE(dwBytesInRes);
	Gura_PackedUInt32_LE(dwImageOffset);
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
	virtual String ToString(bool exprFlag);
	bool Read(Environment &env, Stream &stream, Image::Format format);
	bool Write(Environment &env, Stream &stream);
	void AddImage(const Value &value);
	const ValueList &GetValueList() const { return _valList; }
};

//-----------------------------------------------------------------------------
// ImageStreamer_ICO
//-----------------------------------------------------------------------------
class ImageStreamer_ICO : public ImageStreamer {
public:
	inline ImageStreamer_ICO() : ImageStreamer("msico") {}
	virtual bool IsResponsible(Signal &sig, Stream &stream);
	virtual bool Read(Environment &env, Image *pImage, Stream &stream);
	virtual bool Write(Environment &env, Image *pImage, Stream &stream);
public:
	static bool ReadStream(Environment &env, Image *pImage, Stream &stream, int idx);
};

Gura_EndModuleHeader(msico)

#endif
