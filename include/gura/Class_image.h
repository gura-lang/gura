#ifndef __GURA_OBJECT_IMAGE_H__
#define __GURA_OBJECT_IMAGE_H__

#include "Object.h"
#include "Class_palette.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_image
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_image : public Class {
public:
	Class_image(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
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
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Image *GetImage() { return _pImage.get(); }
	inline const Image *GetImage() const { return _pImage.get(); }
};

}

#endif
