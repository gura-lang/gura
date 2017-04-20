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
public:
	struct Strip {
		bool validFlag;
		size_t width, height;
	};
private:
	bool _bigendianFlag;
	AutoPtr<Object_ifd> _pObj0thIFD;
	AutoPtr<Object_ifd> _pObj1stIFD;				// this may be nullptr
	AutoPtr<Object_binary> _pObjBinaryThumbnail;	// this may be nullptr
	AutoPtr<Object_image> _pObjImageThumbnail;		// this may be nullptr
	Strip _strip;
public:
	Gura_DeclareObjectAccessor(exif)
public:
	Object_exif();
	virtual ~Object_exif();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
#if NEW_INDEXING
	virtual Value IndexGet(Environment &env, const ValueList &valListIdx);
#else
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
#endif
	inline const Strip &GetStrip() const { return _strip; }
	inline bool GetBigendianFlag() const { return _bigendianFlag; }
	inline Object_ifd *GetObj0thIFD() { return _pObj0thIFD.get(); }
	inline Object_ifd *GetObj1stIFD() { return _pObj1stIFD.get(); }
	inline Object_binary *GetObjBinaryThumbnail() { return _pObjBinaryThumbnail.get(); }
	inline Object_image *GetObjImageThumbnail() { return _pObjImageThumbnail.get(); }
	inline void SetObjImageThumbnail(Object_image *pObjImageThumbnail) {
		_pObjImageThumbnail.reset(pObjImageThumbnail);
	}
	static Object_exif *ReadStream(Environment &env, Stream &stream);
};

Gura_EndModuleScope(jpeg)

#endif
