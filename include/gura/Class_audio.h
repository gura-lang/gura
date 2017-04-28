//=============================================================================
// Gura class: audio
//=============================================================================
#ifndef __GURA_CLASS_AUDIO_H__
#define __GURA_CLASS_AUDIO_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_audio
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_audio : public ClassFundamental {
public:
	Class_audio(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
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
	Object_audio(Environment &env, Audio *pAudio);
	Object_audio(Class *pClass, Audio *pAudio);
	inline Audio *GetAudio() { return _pAudio.get(); }
	inline const Audio *GetAudio() const { return _pAudio.get(); }
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
};

}

#endif
