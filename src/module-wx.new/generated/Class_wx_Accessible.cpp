//----------------------------------------------------------------------------
// wxAccessible
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAccessible
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAccessible
//----------------------------------------------------------------------------
Object_wx_Accessible::~Object_wx_Accessible()
{
}

Object *Object_wx_Accessible::Clone() const
{
	return nullptr;
}

String Object_wx_Accessible::ToString(bool exprFlag)
{
	String rtn("<wx.Accessible:");
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

Gura_DeclareMethod(wx_Accessible, wxAccessible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, wxAccessible)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAccessible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, ~wxAccessible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, ~wxAccessible)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->~wxAccessible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, DoDefaultAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, DoDefaultAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->DoDefaultAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetChildCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetChildCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetDefaultAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetDefaultAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetDefaultAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetHelpText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetHelpText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetKeyboardShortcut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetKeyboardShortcut)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetKeyboardShortcut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetLocation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetLocation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetRole)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetRole)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetRole();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetState)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, Navigate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, Navigate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Navigate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, NotifyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, NotifyEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->NotifyEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, SetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, SetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAccessible
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Accessible)
{
}

Gura_ImplementDescendantCreator(wx_Accessible)
{
	return new Object_wx_Accessible((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
