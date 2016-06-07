//----------------------------------------------------------------------------
// wxRibbonPanelEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonPanelEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonPanelEvent
//----------------------------------------------------------------------------
Object_wx_RibbonPanelEvent::~Object_wx_RibbonPanelEvent()
{
}

Object *Object_wx_RibbonPanelEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonPanelEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonPanelEvent:");
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
Gura_DeclareFunctionAlias(__RibbonPanelEvent, "RibbonPanelEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "panel", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonPanelEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonPanelEvent)
{
	//wxEventType command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//wxRibbonPanel* panel = arg.GetNumber(2)
	//wxRibbonPanelEvent(command_type, win_id, panel);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonPanelEvent, __SetPanel, "SetPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanelEvent, __SetPanel)
{
	Object_wx_RibbonPanelEvent *pThis = Object_wx_RibbonPanelEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonPanel* page = arg.GetNumber(0)
	//pThis->GetEntity()->SetPanel(page);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonPanelEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPanelEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonPanelEvent);
	// Method assignment
	Gura_AssignMethod(wx_RibbonPanelEvent, __SetPanel);
}

Gura_ImplementDescendantCreator(wx_RibbonPanelEvent)
{
	return new Object_wx_RibbonPanelEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
