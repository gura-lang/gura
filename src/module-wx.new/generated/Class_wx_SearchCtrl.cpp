//----------------------------------------------------------------------------
// wxSearchCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSearchCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSearchCtrl
//----------------------------------------------------------------------------
Object_wx_SearchCtrl::~Object_wx_SearchCtrl()
{
}

Object *Object_wx_SearchCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_SearchCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.SearchCtrl:");
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
Gura_DeclareFunctionAlias(__wxSearchCtrl, "wxSearchCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxSearchCtrl)
{
	//wxSearchCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxSearchCtrl_1, "wxSearchCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxSearchCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//wxSearchCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SearchCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SearchCtrl, __Create)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SearchCtrl, __GetMenu, "GetMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SearchCtrl, __GetMenu)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SearchCtrl, __IsSearchButtonVisible, "IsSearchButtonVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SearchCtrl, __IsSearchButtonVisible)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSearchButtonVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SearchCtrl, __IsCancelButtonVisible, "IsCancelButtonVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SearchCtrl, __IsCancelButtonVisible)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCancelButtonVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SearchCtrl, __SetMenu, "SetMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SearchCtrl, __SetMenu)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SearchCtrl, __ShowCancelButton, "ShowCancelButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SearchCtrl, __ShowCancelButton)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowCancelButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SearchCtrl, __ShowSearchButton, "ShowSearchButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SearchCtrl, __ShowSearchButton)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowSearchButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SearchCtrl, __SetDescriptiveText, "SetDescriptiveText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SearchCtrl, __SetDescriptiveText)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescriptiveText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SearchCtrl, __GetDescriptiveText, "GetDescriptiveText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SearchCtrl, __GetDescriptiveText)
{
	Object_wx_SearchCtrl *pThis = Object_wx_SearchCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescriptiveText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSearchCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SearchCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__wxSearchCtrl);
	Gura_AssignFunction(__wxSearchCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_SearchCtrl, __Create);
	Gura_AssignMethod(wx_SearchCtrl, __GetMenu);
	Gura_AssignMethod(wx_SearchCtrl, __IsSearchButtonVisible);
	Gura_AssignMethod(wx_SearchCtrl, __IsCancelButtonVisible);
	Gura_AssignMethod(wx_SearchCtrl, __SetMenu);
	Gura_AssignMethod(wx_SearchCtrl, __ShowCancelButton);
	Gura_AssignMethod(wx_SearchCtrl, __ShowSearchButton);
	Gura_AssignMethod(wx_SearchCtrl, __SetDescriptiveText);
	Gura_AssignMethod(wx_SearchCtrl, __GetDescriptiveText);
}

Gura_ImplementDescendantCreator(wx_SearchCtrl)
{
	return new Object_wx_SearchCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
