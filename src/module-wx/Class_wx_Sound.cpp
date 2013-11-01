//----------------------------------------------------------------------------
// wxSound
// extracted from sound.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Sound: public wxSound, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Sound *_pObj;
public:
	inline wx_Sound() : wxSound(), _sig(NULL), _pObj(NULL) {}
	inline wx_Sound(const wxString& fileName, bool isResource) : wxSound(fileName, isResource), _sig(NULL), _pObj(NULL) {}
	~wx_Sound();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Sound *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Sound::~wx_Sound()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Sound::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSound
//----------------------------------------------------------------------------
Gura_DeclareFunction(SoundEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Sound));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SoundEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Sound *pEntity = new wx_Sound();
	Object_wx_Sound *pObj = Object_wx_Sound::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Sound(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Sound)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Sound));
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "isResource", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Sound)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString fileName = wxString::FromUTF8(args.GetString(0));
	bool isResource = false;
	if (args.IsValid(1)) isResource = args.GetBoolean(1);
	wx_Sound *pEntity = new wx_Sound(fileName, isResource);
	Object_wx_Sound *pObj = Object_wx_Sound::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Sound(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Sound, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "isResource", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sound, Create)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString fileName = wxString::FromUTF8(args.GetString(0));
	bool isResource = false;
	if (args.IsValid(1)) isResource = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Create(fileName, isResource);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Sound, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sound, IsOk)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Sound, IsPlaying)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Sound, IsPlaying)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	bool rtn = wxSound::IsPlaying();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Sound, Play)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sound, Play)
{
	Object_wx_Sound *pThis = Object_wx_Sound::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned flags = wxSOUND_ASYNC;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Play(flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Sound, Play_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Sound, Play_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	unsigned flags = wxSOUND_ASYNC;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = wxSound::Play(filename, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Sound, Stop)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Sound, Stop)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSound::Stop();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSound
//----------------------------------------------------------------------------
Object_wx_Sound::~Object_wx_Sound()
{
}

Object *Object_wx_Sound::Clone() const
{
	return NULL;
}

String Object_wx_Sound::ToString(bool exprFlag)
{
	String rtn("<wx.Sound:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxSound
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Sound)
{
	Gura_AssignFunction(SoundEmpty);
	Gura_AssignFunction(Sound);
	Gura_AssignMethod(wx_Sound, Create);
	Gura_AssignMethod(wx_Sound, IsOk);
	Gura_AssignMethod(wx_Sound, IsPlaying);
	Gura_AssignMethod(wx_Sound, Play);
	Gura_AssignMethod(wx_Sound, Play_1);
	Gura_AssignMethod(wx_Sound, Stop);
}

Gura_ImplementDescendantCreator(wx_Sound)
{
	return new Object_wx_Sound((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
