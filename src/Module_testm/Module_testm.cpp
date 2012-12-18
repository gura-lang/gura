//-----------------------------------------------------------------------------
// Gura testm module
//-----------------------------------------------------------------------------
#include <gura.h>

Gura_BeginModule(testm)

class AudioSrc {
public:
	virtual ~AudioSrc();
};

class AudioDst {
public:
	virtual ~AudioDst();
};

typedef std::vector<AudioSrc *> AudioSrcList;
typedef std::vector<AudioDst *> AudioDstList;

AudioSrc::~AudioSrc()
{
}

AudioDst::~AudioDst()
{
}

//-----------------------------------------------------------------------------
// Object_audio declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Audio);

class Object_audio : public Object {
private:
	AudioSrcList _audioSrcList;
	AudioDstList _audioDstList;
public:
	Gura_DeclareObjectAccessor(audio)
public:
	inline Object_audio() : Object(Gura_UserClass(Audio)) {}
	virtual ~Object_audio();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void AddSrc(AudioSrc *pAudioSrc) { _audioSrcList.push_back(pAudioSrc); }
	inline void AddDst(AudioDst *pAudioDst) { _audioDstList.push_back(pAudioDst); }
};

//-----------------------------------------------------------------------------
// Object_audio implementation
//-----------------------------------------------------------------------------
Object_audio::~Object_audio()
{
	foreach (AudioSrcList, ppAudioSrc, _audioSrcList) {
		delete *ppAudioSrc;
	}
	foreach (AudioDstList, ppAudioDst, _audioDstList) {
		delete *ppAudioDst;
	}
}

Object *Object_audio::Clone() const
{
	return NULL;
}

String Object_audio::ToString(Signal sig, bool exprFlag)
{
	return String("<Audio>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_audio
//-----------------------------------------------------------------------------
// testm.audio#test()
Gura_DeclareMethod(audio, test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(audio, test)
{
	Object_audio *pSelf = Object_audio::GetSelfObj(args);
	return Value(env, "Audio object");
}

// implementation of class Audio
Gura_ImplementUserClass(Audio)
{
	Gura_AssignMethod(audio, test);
}

//-----------------------------------------------------------------------------
// Gura module functions: testm
//-----------------------------------------------------------------------------
// testm.audio()
Gura_DeclareFunction(audio)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(audio)
{
	Object_audio *pObjAudio = new Object_audio();
	return Value(pObjAudio);
}

// Module entry
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(Audio, "audio", env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(audio);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(testm, testm)

Gura_RegisterModule(testm)
