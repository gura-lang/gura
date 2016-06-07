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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PreferencesPage, "PreferencesPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PreferencesPage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PreferencesPage)
{
	//wxPreferencesPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PreferencesPage, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PreferencesPage, __GetName)
{
	Object_wx_PreferencesPage *pThis = Object_wx_PreferencesPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreferencesPage, __GetLargeIcon, "GetLargeIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PreferencesPage, __GetLargeIcon)
{
	Object_wx_PreferencesPage *pThis = Object_wx_PreferencesPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmap _rtn = pThis->GetEntity()->GetLargeIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PreferencesPage, __CreateWindow, "CreateWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreferencesPage, __CreateWindow)
{
	Object_wx_PreferencesPage *pThis = Object_wx_PreferencesPage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindow* _rtn = pThis->GetEntity()->CreateWindow(parent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPreferencesPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreferencesPage)
{
	// Constructor assignment
	Gura_AssignFunction(__PreferencesPage);
	// Method assignment
	Gura_AssignMethod(wx_PreferencesPage, __GetName);
	Gura_AssignMethod(wx_PreferencesPage, __GetLargeIcon);
	Gura_AssignMethod(wx_PreferencesPage, __CreateWindow);
}

Gura_ImplementDescendantCreator(wx_PreferencesPage)
{
	return new Object_wx_PreferencesPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
