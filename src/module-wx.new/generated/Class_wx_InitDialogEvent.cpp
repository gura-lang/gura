//----------------------------------------------------------------------------
// wxInitDialogEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInitDialogEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInitDialogEvent
//----------------------------------------------------------------------------
Object_wx_InitDialogEvent::~Object_wx_InitDialogEvent()
{
}

Object *Object_wx_InitDialogEvent::Clone() const
{
	return nullptr;
}

String Object_wx_InitDialogEvent::ToString(bool exprFlag)
{
	String rtn("<wx.InitDialogEvent:");
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
Gura_DeclareMethod(wx_InitDialogEvent, wxInitDialogEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InitDialogEvent, wxInitDialogEvent)
{
	Object_wx_InitDialogEvent *pThis = Object_wx_InitDialogEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->wxInitDialogEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxInitDialogEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InitDialogEvent)
{
	Gura_AssignMethod(wx_InitDialogEvent, wxInitDialogEvent);
}

Gura_ImplementDescendantCreator(wx_InitDialogEvent)
{
	return new Object_wx_InitDialogEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
