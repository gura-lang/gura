//----------------------------------------------------------------------------
// wxRibbonBarEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonBarEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonBarEvent
//----------------------------------------------------------------------------
Object_wx_RibbonBarEvent::~Object_wx_RibbonBarEvent()
{
}

Object *Object_wx_RibbonBarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonBarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonBarEvent:");
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
Gura_DeclareFunctionAlias(__RibbonBarEvent, "RibbonBarEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonBarEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonBarEvent)
{
	//int command_type = arg.GetNumber(0)
	//int win_id = arg.GetNumber(1)
	//int page = arg.GetNumber(2)
	//wxRibbonBarEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonBarEvent, __GetPage, "GetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonBarEvent, __GetPage)
{
	Object_wx_RibbonBarEvent *pThis = Object_wx_RibbonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonBarEvent, __SetPage, "SetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonBarEvent, __SetPage)
{
	Object_wx_RibbonBarEvent *pThis = Object_wx_RibbonBarEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonBarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonBarEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonBarEvent);
	// Method assignment
	Gura_AssignMethod(wx_RibbonBarEvent, __GetPage);
	Gura_AssignMethod(wx_RibbonBarEvent, __SetPage);
}

Gura_ImplementDescendantCreator(wx_RibbonBarEvent)
{
	return new Object_wx_RibbonBarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
