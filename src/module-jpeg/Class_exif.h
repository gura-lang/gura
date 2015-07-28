#ifndef __JPEG_CLASS_EXIF_H__
#define __JPEG_CLASS_EXIF_H__
#include <gura.h>
#include "module-jpeg.h"
#include "Class_ifd.h"

Gura_BeginModuleScope(jpeg)

//-----------------------------------------------------------------------------
// Object_exif declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(exif);

class Object_exif : public Object {
private:
	bool _bigendianFlag;
	AutoPtr<Object_ifd> _pObj0thIFD;
	AutoPtr<Object_ifd> _pObj1stIFD;				// this may be nullptr
	AutoPtr<Object_binary> _pObjBinaryThumbnail;	// this may be nullptr
	AutoPtr<Object_image> _pObjImageThumbnail;		// this may be nullptr
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
	virtual String ToString(bool exprFlag);
	virtual Value IndexGet(Environment &env, Signal &__to_delete__, const Value &valueIdx);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline Object_ifd *GetObj0thIFD() { return _pObj0thIFD.get(); }
	inline Object_ifd *GetObj1stIFD() { return _pObj1stIFD.get(); }
	static Object_exif *ReadStream(Environment &env, Signal &sig, Stream &stream);
};

Gura_EndModuleScope(jpeg)

#endif
