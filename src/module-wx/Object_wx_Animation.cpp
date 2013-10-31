//----------------------------------------------------------------------------
// wxAnimation
// extracted from animation.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Animation: public wxAnimation, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Animation *_pObj;
public:
	inline wx_Animation() : wxAnimation(), _sig(NULL), _pObj(NULL) {}
	inline wx_Animation(const wxAnimation& anim) : wxAnimation(anim), _sig(NULL), _pObj(NULL) {}
	inline wx_Animation(const wxString& name, wxAnimationType type) : wxAnimation(name, type), _sig(NULL), _pObj(NULL) {}
	~wx_Animation();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Animation *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Animation::~wx_Animation()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Animation::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAnimation
//----------------------------------------------------------------------------
Gura_DeclareFunction(AnimationEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Animation));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AnimationEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Animation *pEntity = new wx_Animation();
	Object_wx_Animation *pObj = Object_wx_Animation::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Animation(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Animation)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Animation));
	DeclareArg(env, "anim", VTYPE_wx_Animation, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Animation)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxAnimation *anim = Object_wx_Animation::GetObject(args, 0)->GetEntity();
	wx_Animation *pEntity = new wx_Animation(*anim);
	Object_wx_Animation *pObj = Object_wx_Animation::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Animation(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Animation_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Animation));
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Animation_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxAnimationType type = wxANIMATION_TYPE_ANY;
	if (args.IsValid(1)) type = static_cast<wxAnimationType>(args.GetInt(1));
	wx_Animation *pEntity = new wx_Animation(name, type);
	Object_wx_Animation *pObj = Object_wx_Animation::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Animation(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Animation, GetDelay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Animation, GetDelay)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned i = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetDelay(i);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Animation, GetFrameCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Animation, GetFrameCount)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetFrameCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Animation, GetFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Animation, GetFrame)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned i = args.GetInt(0);
	wxImage rtn = pThis->GetEntity()->GetFrame(i);
	return ReturnValue(env, sig, args, Value(new Object_wx_Image(new wxImage(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Animation, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Animation, GetSize)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Animation, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Animation, IsOk)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Animation, Load)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Animation, Load)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxAnimationType type = wxANIMATION_TYPE_ANY;
	if (args.IsValid(1)) type = static_cast<wxAnimationType>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->Load(*stream, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Animation, LoadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Animation, LoadFile)
{
	Object_wx_Animation *pThis = Object_wx_Animation::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxAnimationType type = wxANIMATION_TYPE_ANY;
	if (args.IsValid(1)) type = static_cast<wxAnimationType>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->LoadFile(name, type);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxAnimation
//----------------------------------------------------------------------------
Object_wx_Animation::~Object_wx_Animation()
{
}

Object *Object_wx_Animation::Clone() const
{
	return NULL;
}

String Object_wx_Animation::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Animation:");
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
// Class implementation for wxAnimation
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Animation)
{
	Gura_AssignFunction(AnimationEmpty);
	Gura_AssignFunction(Animation);
	Gura_AssignFunction(Animation_1);
	Gura_AssignMethod(wx_Animation, GetDelay);
	Gura_AssignMethod(wx_Animation, GetFrameCount);
	Gura_AssignMethod(wx_Animation, GetFrame);
	Gura_AssignMethod(wx_Animation, GetSize);
	Gura_AssignMethod(wx_Animation, IsOk);
	Gura_AssignMethod(wx_Animation, Load);
	Gura_AssignMethod(wx_Animation, LoadFile);
}

Gura_ImplementDescendantCreator(wx_Animation)
{
	return new Object_wx_Animation((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
