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
	//Gura::Signal *_pSig;
	Object_wx_Sound *_pObj;
public:
	inline wx_Sound() : wxSound(), _pObj(nullptr) {}
	inline wx_Sound(const wxString& fileName, bool isResource) : wxSound(fileName, isResource), _pObj(nullptr) {}
	~wx_Sound();
	inline void AssocWithGura(Object_wx_Sound *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Sound::~wx_Sound()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Sound::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSound
//----------------------------------------------------------------------------
Gura_DeclareFunction(SoundEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Sound));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SoundEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Sound *pEntity = new wx_Sound();
	Object_wx_Sound *pObj = Object_wx_Sound::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Sound(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Sound)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Sound));
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "isResource", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Sound)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString fileName = wxString::FromUTF8(args.GetString(0));
	bool isResource = false;
	if (args.IsValid(1)) isResource = args.GetBoolean(1);
	wx_Sound *pEntity = new wx_Sound(fileName, isResource);
	Object_wx_Sound *pObj = Object_wx_Sound::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Sound(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Sound, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fileName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "isResource", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sound, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString fileName = wxString::FromUTF8(args.GetString(0));
	bool isResource = false;
	if (args.IsValid(1)) isResource = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Create(fileName, isResource);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Sound, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sound, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Sound, IsPlaying)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Sound, IsPlaying)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	bool rtn = wxSound::IsPlaying();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sound, Play)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sound, Play)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sound *pThis = Object_wx_Sound::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned flags = wxSOUND_ASYNC;
	if (args.IsValid(0)) flags = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Play(flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Sound, Play_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Sound, Play_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	unsigned flags = wxSOUND_ASYNC;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = wxSound::Play(filename, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Sound, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Sound, Stop)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSound::Stop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxSound
//----------------------------------------------------------------------------
Object_wx_Sound::~Object_wx_Sound()
{
}

Object *Object_wx_Sound::Clone() const
{
	return nullptr;
}

String Object_wx_Sound::ToString(bool exprFlag)
{
	String rtn("<wx.Sound:");
	if (GetEntity() == nullptr) {
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
	return new Object_wx_Sound((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
