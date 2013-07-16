#ifndef __GURA_OBJECT_AUDIO_H__
#define __GURA_OBJECT_AUDIO_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_audio
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_audio : public Class {
public:
	Class_audio(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_audio
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_audio : public Object {
public:
	Gura_DeclareObjectAccessor(audio)
private:
	AutoPtr<Audio> _pAudio;
public:
	inline Object_audio(Environment &env, Audio *pAudio) :
				Object(env.LookupClass(VTYPE_audio)), _pAudio(pAudio) {}
	inline Object_audio(Class *pClass, Audio *pAudio) :
				Object(pClass), _pAudio(pAudio) {}
	inline Audio *GetAudio() { return _pAudio.get(); }
	inline const Audio *GetAudio() const { return _pAudio.get(); }
	virtual ~Object_audio();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
