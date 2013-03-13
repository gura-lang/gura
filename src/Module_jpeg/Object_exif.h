#ifndef __JPEG_OBJECT_EXIF_H__
#define __JPEG_OBJECT_EXIF_H__
#include <gura.h>
#include "Module_jpeg.h"
#include "Object_ifd.h"

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Object_exif declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(exif);

class Object_exif : public Object {
private:
	bool _bigendianFlag;
	AutoPtr<Object_ifd> _pObj0thIFD;
	AutoPtr<Object_ifd> _pObj1stIFD;				// this may be NULL
	AutoPtr<Object_binary> _pObjBinaryThumbnail;	// this may be NULL
	AutoPtr<Object_image> _pObjImageThumbnail;		// this may be NULL
	struct {
		bool validFlag;
		size_t width, height;
	} _strip;
public:
	Gura_DeclareObjectAccessor(exif)
public:
	Object_exif();
	virtual ~Object_exif();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline Object_ifd *GetObj0thIFD() { return _pObj0thIFD.get(); }
	inline Object_ifd *GetObj1stIFD() { return _pObj1stIFD.get(); }
	static Object_exif *ReadStream(Environment &env, Signal sig, Stream &stream);
};

}}

#endif
