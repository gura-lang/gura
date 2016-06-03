//----------------------------------------------------------------------------
// wxRibbonPanel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonPanel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonPanel
//----------------------------------------------------------------------------
Object_wx_RibbonPanel::~Object_wx_RibbonPanel()
{
}

Object *Object_wx_RibbonPanel::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonPanel::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonPanel:");
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
Gura_DeclareFunctionAlias(__wxRibbonPanel, "wxRibbonPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RibbonPanel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRibbonPanel)
{
	//wxRibbonPanel();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRibbonPanel_1, "wxRibbonPanel_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minimised_icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonPanel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRibbonPanel_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int minimised_icon = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//wxRibbonPanel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonPanel, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanel, __Create)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __GetMinimisedIcon, "GetMinimisedIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __GetMinimisedIcon)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinimisedIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __GetMinimisedIcon_1, "GetMinimisedIcon_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __GetMinimisedIcon_1)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinimisedIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __HasExtButton, "HasExtButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __HasExtButton)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasExtButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __IsMinimised, "IsMinimised")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __IsMinimised)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMinimised();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __IsMinimised_1, "IsMinimised_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "at_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanel, __IsMinimised_1)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int at_size = arg.GetNumber(0)
	//pThis->GetEntity()->IsMinimised();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __IsHovered, "IsHovered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __IsHovered)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsHovered();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __IsExtButtonHovered, "IsExtButtonHovered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __IsExtButtonHovered)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsExtButtonHovered();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __CanAutoMinimise, "CanAutoMinimise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __CanAutoMinimise)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanAutoMinimise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __ShowExpanded, "ShowExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __ShowExpanded)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __HideExpanded, "HideExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __HideExpanded)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HideExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __SetArtProvider, "SetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanel, __SetArtProvider)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __Realize)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __GetExpandedDummy, "GetExpandedDummy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __GetExpandedDummy)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExpandedDummy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __GetExpandedPanel, "GetExpandedPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __GetExpandedPanel)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExpandedPanel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPanel)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRibbonPanel);
	Gura_AssignFunction(__wxRibbonPanel_1);
	// Method assignment
	Gura_AssignMethod(wx_RibbonPanel, __Create);
	Gura_AssignMethod(wx_RibbonPanel, __GetMinimisedIcon);
	Gura_AssignMethod(wx_RibbonPanel, __GetMinimisedIcon_1);
	Gura_AssignMethod(wx_RibbonPanel, __HasExtButton);
	Gura_AssignMethod(wx_RibbonPanel, __IsMinimised);
	Gura_AssignMethod(wx_RibbonPanel, __IsMinimised_1);
	Gura_AssignMethod(wx_RibbonPanel, __IsHovered);
	Gura_AssignMethod(wx_RibbonPanel, __IsExtButtonHovered);
	Gura_AssignMethod(wx_RibbonPanel, __CanAutoMinimise);
	Gura_AssignMethod(wx_RibbonPanel, __ShowExpanded);
	Gura_AssignMethod(wx_RibbonPanel, __HideExpanded);
	Gura_AssignMethod(wx_RibbonPanel, __SetArtProvider);
	Gura_AssignMethod(wx_RibbonPanel, __Realize);
	Gura_AssignMethod(wx_RibbonPanel, __GetExpandedDummy);
	Gura_AssignMethod(wx_RibbonPanel, __GetExpandedPanel);
}

Gura_ImplementDescendantCreator(wx_RibbonPanel)
{
	return new Object_wx_RibbonPanel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
