//----------------------------------------------------------------------------
// wxAnimationCtrl
// extracted from animatctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AnimationCtrl: public wxAnimationCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AnimationCtrl *_pObj;
public:
	inline wx_AnimationCtrl(wxWindow * parent, wxWindowID id, const wxAnimation& anim, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxAnimationCtrl(parent, id, anim, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_AnimationCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AnimationCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AnimationCtrl::~wx_AnimationCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AnimationCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAnimationCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(AnimationCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_AnimationCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "anim", VTYPE_wx_Animation, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(AnimationCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxAnimation *anim = Object_wx_Animation::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxAC_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("animationctrl");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_AnimationCtrl *pEntity = new wx_AnimationCtrl(parent, id, *anim, *pos, *size, style, name);
	Object_wx_AnimationCtrl *pObj = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AnimationCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_AnimationCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "anim", VTYPE_wx_Animation, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AnimationCtrl, Create)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxAnimation *anim = Object_wx_Animation::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxAC_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("animationctrl");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, *anim, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AnimationCtrl, GetAnimation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AnimationCtrl, GetAnimation)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAnimation rtn = pThis->GetEntity()->GetAnimation();
	return ReturnValue(env, sig, args, Value(new Object_wx_Animation(new wxAnimation(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AnimationCtrl, GetInactiveBitmap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AnimationCtrl, GetInactiveBitmap)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap rtn = pThis->GetEntity()->GetInactiveBitmap();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AnimationCtrl, IsPlaying)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AnimationCtrl, IsPlaying)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPlaying();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AnimationCtrl, LoadFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "animType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AnimationCtrl, LoadFile)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	wxAnimationType animType = wxANIMATION_TYPE_ANY;
	if (args.IsValid(1)) animType = static_cast<wxAnimationType>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->LoadFile(file, animType);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AnimationCtrl, Play)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AnimationCtrl, Play)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Play();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AnimationCtrl, SetAnimation)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "anim", VTYPE_wx_Animation, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, SetAnimation)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAnimation *anim = Object_wx_Animation::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetAnimation(*anim);
	return Value::Null;
}

Gura_DeclareMethod(wx_AnimationCtrl, SetInactiveBitmap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnimationCtrl, SetInactiveBitmap)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetInactiveBitmap(*bmp);
	return Value::Null;
}

Gura_DeclareMethod(wx_AnimationCtrl, Stop)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AnimationCtrl, Stop)
{
	Object_wx_AnimationCtrl *pThis = Object_wx_AnimationCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Stop();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAnimationCtrl
//----------------------------------------------------------------------------
Object_wx_AnimationCtrl::~Object_wx_AnimationCtrl()
{
}

Object *Object_wx_AnimationCtrl::Clone() const
{
	return NULL;
}

String Object_wx_AnimationCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AnimationCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_AnimationCtrl::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(AnimationCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxAnimationCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnimationCtrl)
{
	Gura_AssignMethod(wx_AnimationCtrl, Create);
	Gura_AssignMethod(wx_AnimationCtrl, GetAnimation);
	Gura_AssignMethod(wx_AnimationCtrl, GetInactiveBitmap);
	Gura_AssignMethod(wx_AnimationCtrl, IsPlaying);
	Gura_AssignMethod(wx_AnimationCtrl, LoadFile);
	Gura_AssignMethod(wx_AnimationCtrl, Play);
	Gura_AssignMethod(wx_AnimationCtrl, SetAnimation);
	Gura_AssignMethod(wx_AnimationCtrl, SetInactiveBitmap);
	Gura_AssignMethod(wx_AnimationCtrl, Stop);
}

Gura_ImplementDescendantCreator(wx_AnimationCtrl)
{
	return new Object_wx_AnimationCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
