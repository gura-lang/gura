#ifndef __GURA_OBJECT_CODEC_H__
#define __GURA_OBJECT_CODEC_H__

#include "Object.h"
#include "Codec.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_codec
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_codec : public Class {
public:
	Class_codec(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void DoAssignConstructor(Environment &env, Signal sig);
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
	virtual String ToString(Signal sig, bool exprFlag);
	inline Codec *GetCodec() { return _pCodec.get(); }
	inline const Codec *GetCodec() const { return _pCodec.get(); }
};

}

#endif
