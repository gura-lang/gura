#ifndef __JPEG_OBJECT_EXIF_H__
#define __JPEG_OBJECT_EXIF_H__
#include <gura.h>

Gura_BeginModule(jpeg)

//-----------------------------------------------------------------------------
// Object_exif declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(exif);

class Object_exif : public Object {
public:
	Gura_DeclareObjectAccessor(exif)
public:
	inline Object_exif() : Object(Gura_UserClass(exif)) {}
	virtual ~Object_exif();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	bool ReadStream(Signal sig, Stream &stream);
};

}}

#endif
