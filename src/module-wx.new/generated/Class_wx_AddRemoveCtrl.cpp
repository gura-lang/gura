//----------------------------------------------------------------------------
// wxAddRemoveCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAddRemoveCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Object_wx_AddRemoveCtrl::~Object_wx_AddRemoveCtrl()
{
}

Object *Object_wx_AddRemoveCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_AddRemoveCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.AddRemoveCtrl:");
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
// Method implementation
//----------------------------------------------------------------------------

Gura_DeclareMethod(wx_AddRemoveCtrl, wxAddRemoveCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, wxAddRemoveCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAddRemoveCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveCtrl, wxAddRemoveCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, wxAddRemoveCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAddRemoveCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveCtrl, SetAdaptor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, SetAdaptor)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetAdaptor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveCtrl, SetButtonsToolTips)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveCtrl, SetButtonsToolTips)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveCtrl *pThis = Object_wx_AddRemoveCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetButtonsToolTips();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AddRemoveCtrl)
{
}

Gura_ImplementDescendantCreator(wx_AddRemoveCtrl)
{
	return new Object_wx_AddRemoveCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
