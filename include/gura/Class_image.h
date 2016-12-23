//=============================================================================
// Gura class: image
//=============================================================================
#ifndef __GURA_CLASS_IMAGE_H__
#define __GURA_CLASS_IMAGE_H__

#include "Class.h"
#include "Class_palette.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_image
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_image : public Class {
public:
	Class_image(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
};

//-----------------------------------------------------------------------------
// Object_image
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_image : public Object {
private:
	AutoPtr<Image> _pImage;
public:
	Gura_DeclareObjectAccessor(image)
public:
	Object_image(Environment &env, Image *pImage);
	Object_image(Class *pClass, Image *pImage);
	Object_image(const Object_image &obj);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Image *GetImage() { return _pImage.get(); }
	inline const Image *GetImage() const { return _pImage.get(); }
};

}

#endif
