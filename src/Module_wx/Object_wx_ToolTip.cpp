//----------------------------------------------------------------------------
// wxToolTip
// extracted from tooltip.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToolTip: public wxToolTip, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ToolTip *_pObj;
public:
	inline wx_ToolTip(const wxString& tip) : wxToolTip(tip), _sig(NULL), _pObj(NULL) {}
	~wx_ToolTip();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ToolTip *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolTip::~wx_ToolTip()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ToolTip::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToolTip
//----------------------------------------------------------------------------
Gura_DeclareClassMethod(wx_ToolTip, Enable)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_ToolTip, Enable)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	wxToolTip::Enable(flag);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_ToolTip, SetDelay)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msecs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_ToolTip, SetDelay)
{
	if (!CheckWxReady(sig)) return Value::Null;
	long msecs = args.GetLong(0);
	wxToolTip::SetDelay(msecs);
	return Value::Null;
}

Gura_DeclareFunction(ToolTip)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ToolTip));
	DeclareArg(env, "tip", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ToolTip)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString tip = wxString::FromUTF8(args.GetString(0));
	wx_ToolTip *pEntity = new wx_ToolTip(tip);
	Object_wx_ToolTip *pObj = Object_wx_ToolTip::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ToolTip(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ToolTip, SetTip)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tip", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, SetTip)
{
	Object_wx_ToolTip *pSelf = Object_wx_ToolTip::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString tip = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetTip(tip);
	return Value::Null;
}

Gura_DeclareMethod(wx_ToolTip, GetTip)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolTip, GetTip)
{
	Object_wx_ToolTip *pSelf = Object_wx_ToolTip::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetTip();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ToolTip, GetWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolTip, GetWindow)
{
	Object_wx_ToolTip *pSelf = Object_wx_ToolTip::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pSelf->GetEntity()->GetWindow();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxToolTip
//----------------------------------------------------------------------------
Object_wx_ToolTip::~Object_wx_ToolTip()
{
}

Object *Object_wx_ToolTip::Clone() const
{
	return NULL;
}

String Object_wx_ToolTip::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ToolTip:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ToolTip::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ToolTip);
}

//----------------------------------------------------------------------------
// Class implementation for wxToolTip
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolTip)
{
	Gura_AssignMethod(wx_ToolTip, Enable);
	Gura_AssignMethod(wx_ToolTip, SetDelay);
	Gura_AssignMethod(wx_ToolTip, SetTip);
	Gura_AssignMethod(wx_ToolTip, GetTip);
	Gura_AssignMethod(wx_ToolTip, GetWindow);
}

Gura_ImplementDescendantCreator(wx_ToolTip)
{
	return new Object_wx_ToolTip((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
