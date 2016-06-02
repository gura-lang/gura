//----------------------------------------------------------------------------
// wxPreferencesPage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPreferencesPage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPreferencesPage
//----------------------------------------------------------------------------
Object_wx_PreferencesPage::~Object_wx_PreferencesPage()
{
}

Object *Object_wx_PreferencesPage::Clone() const
{
	return nullptr;
}

String Object_wx_PreferencesPage::ToString(bool exprFlag)
{
	String rtn("<wx.PreferencesPage:");
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
Gura_DeclareMethod(wx_PreferencesPage, wxPreferencesPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreferencesPage, wxPreferencesPage)
{
	Object_wx_PreferencesPage *pThis = Object_wx_PreferencesPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPreferencesPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreferencesPage, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreferencesPage, GetName)
{
	Object_wx_PreferencesPage *pThis = Object_wx_PreferencesPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreferencesPage, GetLargeIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreferencesPage, GetLargeIcon)
{
	Object_wx_PreferencesPage *pThis = Object_wx_PreferencesPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLargeIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreferencesPage, CreateWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreferencesPage, CreateWindow)
{
	Object_wx_PreferencesPage *pThis = Object_wx_PreferencesPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->CreateWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPreferencesPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreferencesPage)
{
	Gura_AssignMethod(wx_PreferencesPage, wxPreferencesPage);
	Gura_AssignMethod(wx_PreferencesPage, GetName);
	Gura_AssignMethod(wx_PreferencesPage, GetLargeIcon);
	Gura_AssignMethod(wx_PreferencesPage, CreateWindow);
}

Gura_ImplementDescendantCreator(wx_PreferencesPage)
{
	return new Object_wx_PreferencesPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
