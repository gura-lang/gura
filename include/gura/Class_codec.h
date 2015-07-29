//=============================================================================
// Gura class: codec
//=============================================================================
#ifndef __GURA_CLASS_CODEC_H__
#define __GURA_CLASS_CODEC_H__

#include "Class.h"
#include "Codec.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_codec
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_codec : public Class {
public:
	Class_codec(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_codec
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_codec : public Object {
private:
	AutoPtr<Codec> _pCodec;
public:
	Gura_DeclareObjectAccessor(codec)
public:
	Object_codec(const Object_codec &obj);
	inline Object_codec(Environment &env, Codec *pCodec) :
						Object(env.LookupClass(VTYPE_codec)), _pCodec(pCodec) {}
	inline Object_codec(Class *pClass, Codec *pCodec) :
						Object(pClass), _pCodec(pCodec) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Codec *GetCodec() { return _pCodec.get(); }
	inline const Codec *GetCodec() const { return _pCodec.get(); }
};

}

#endif
