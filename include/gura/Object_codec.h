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
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_codec
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_codec : public Object {
public:
	Gura_DeclareObjectAccessor(codec)
private:
	String _encoding;
	std::auto_ptr<CodecEncoder> _pEncoder;
	std::auto_ptr<CodecDecoder> _pDecoder;
public:
	Object_codec(const Object_codec &obj);
	inline Object_codec(Environment &env) : Object(env.LookupClass(VTYPE_codec)) {}
	inline Object_codec(Class *pClass) : Object(pClass), _pEncoder(NULL) {}
	inline const char *GetEncoding() const { return _encoding.c_str(); }
	inline bool IsInstalled() const { return !_encoding.empty(); }
	inline CodecEncoder *GetEncoder() { return _pEncoder.get(); }
	inline CodecDecoder *GetDecoder() { return _pDecoder.get(); }
	virtual Object *Clone() const;
	bool InstallCodec(Signal sig, const char *encoding, bool processEOLFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
