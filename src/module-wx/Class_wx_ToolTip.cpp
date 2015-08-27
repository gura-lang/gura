//----------------------------------------------------------------------------
// wxToolTip
// extracted from tooltip.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToolTip: public wxToolTip, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ToolTip *_pObj;
public:
	inline wx_ToolTip(const wxString& tip) : wxToolTip(tip), _pObj(nullptr) {}
	~wx_ToolTip();
	inline void AssocWithGura(Object_wx_ToolTip *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolTip::~wx_ToolTip()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ToolTip::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToolTip
//----------------------------------------------------------------------------
Gura_DeclareClassMethod(wx_ToolTip, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_ToolTip, Enable)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	bool flag = args.GetBoolean(0);
	wxToolTip::Enable(flag);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_ToolTip, SetDelay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msecs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_ToolTip, SetDelay)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	long msecs = args.GetLong(0);
	wxToolTip::SetDelay(msecs);
	return Value::Nil;
}

Gura_DeclareFunction(ToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ToolTip));
	DeclareArg(env, "tip", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ToolTip)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString tip = wxString::FromUTF8(args.GetString(0));
	wx_ToolTip *pEntity = new wx_ToolTip(tip);
	Object_wx_ToolTip *pObj = Object_wx_ToolTip::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ToolTip(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_ToolTip, SetTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tip", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, SetTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString tip = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTip(tip);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, GetTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolTip, GetTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTip();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ToolTip, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ToolTip, GetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetWindow();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxToolTip
//----------------------------------------------------------------------------
Object_wx_ToolTip::~Object_wx_ToolTip()
{
}

Object *Object_wx_ToolTip::Clone() const
{
	return nullptr;
}

String Object_wx_ToolTip::ToString(bool exprFlag)
{
	String rtn("<wx.ToolTip:");
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
// Class implementation for wxToolTip
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolTip)
{
	Gura_AssignFunction(ToolTip);
	Gura_AssignMethod(wx_ToolTip, Enable);
	Gura_AssignMethod(wx_ToolTip, SetDelay);
	Gura_AssignMethod(wx_ToolTip, SetTip);
	Gura_AssignMethod(wx_ToolTip, GetTip);
	Gura_AssignMethod(wx_ToolTip, GetWindow);
}

Gura_ImplementDescendantCreator(wx_ToolTip)
{
	return new Object_wx_ToolTip((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
