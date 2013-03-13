//-----------------------------------------------------------------------------
// Gura msicon module
//-----------------------------------------------------------------------------
#ifndef __MODULE_MSICO_H__
#define __MODULE_MSICO_H__
#include <gura.h>

Gura_BeginModule(msico)

Gura_DeclareUserSymbol(images);

//-----------------------------------------------------------------------------
// Data structure for Windows ICO format
// http://msdn.microsoft.com/en-us/library/ms997538.aspx
//-----------------------------------------------------------------------------
struct IconDir {
	enum { Size = 6 };
	XPackedUShort_LE(idReserved);
	XPackedUShort_LE(idType);
	XPackedUShort_LE(idCount);
};

struct IconDirEntry {
	enum { Size = 16 };
	unsigned char bWidth;
	unsigned char bHeight;
	unsigned char bColorCount;
	unsigned char bReserved;
	XPackedUShort_LE(wPlanes);
	XPackedUShort_LE(wBitCount);
	XPackedULong_LE(dwBytesInRes);
	XPackedULong_LE(dwImageOffset);
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
	virtual bool Read(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
	virtual bool Write(Environment &env, Signal sig, Object_image *pObjImage, Stream &stream);
public:
	static bool ReadStream(Signal sig, Object_image *pObjImage, Stream &stream, int idx);
};

}}

#endif
