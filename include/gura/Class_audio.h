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
class GURA_DLLDECLARE Class_audio : public Class {
public:
	Class_audio(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl);
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
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
