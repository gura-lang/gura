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
Gura_DeclareFunctionAlias(__RibbonPanel, "RibbonPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RibbonPanel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonPanel)
{
	//wxRibbonPanel();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RibbonPanel_1, "RibbonPanel_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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

Gura_ImplementFunction(__RibbonPanel_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxBitmap& minimised_icon = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//wxRibbonPanel(parent, id, label, minimised_icon, pos, size, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonPanel, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxBitmap& icon = arg.GetNumber(3)
	//const wxPoint& pos = arg.GetNumber(4)
	//const wxSize& size = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, label, icon, pos, size, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __GetMinimisedIcon, "GetMinimisedIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __GetMinimisedIcon)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxBitmap& _rtn = pThis->GetEntity()->GetMinimisedIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __GetMinimisedIcon_1, "GetMinimisedIcon_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __GetMinimisedIcon_1)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& _rtn = pThis->GetEntity()->GetMinimisedIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __HasExtButton, "HasExtButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __HasExtButton)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasExtButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __IsMinimised, "IsMinimised")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __IsMinimised)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsMinimised();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __IsMinimised_1, "IsMinimised_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "at_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanel, __IsMinimised_1)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize at_size = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsMinimised(at_size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __IsHovered, "IsHovered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __IsHovered)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsHovered();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __IsExtButtonHovered, "IsExtButtonHovered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __IsExtButtonHovered)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsExtButtonHovered();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __CanAutoMinimise, "CanAutoMinimise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __CanAutoMinimise)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanAutoMinimise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __ShowExpanded, "ShowExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __ShowExpanded)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->ShowExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __HideExpanded, "HideExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __HideExpanded)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HideExpanded();
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
	//wxRibbonArtProvider* art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider(art);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __Realize)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __GetExpandedDummy, "GetExpandedDummy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __GetExpandedDummy)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonPanel* _rtn = pThis->GetEntity()->GetExpandedDummy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonPanel, __GetExpandedPanel, "GetExpandedPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, __GetExpandedPanel)
{
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonPanel* _rtn = pThis->GetEntity()->GetExpandedPanel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPanel)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonPanel);
	Gura_AssignFunction(__RibbonPanel_1);
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
