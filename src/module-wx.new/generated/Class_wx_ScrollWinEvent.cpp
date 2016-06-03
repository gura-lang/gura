//----------------------------------------------------------------------------
// wxScrollWinEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScrollWinEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScrollWinEvent
//----------------------------------------------------------------------------
Object_wx_ScrollWinEvent::~Object_wx_ScrollWinEvent()
{
}

Object *Object_wx_ScrollWinEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ScrollWinEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ScrollWinEvent:");
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
Gura_DeclareMethodAlias(wx_ScrollWinEvent, __wxScrollWinEvent, "wxScrollWinEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollWinEvent, __wxScrollWinEvent)
{
	Object_wx_ScrollWinEvent *pThis = Object_wx_ScrollWinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int orientation = arg.GetNumber(2)
	//pThis->GetEntity()->wxScrollWinEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollWinEvent, __GetOrientation, "GetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollWinEvent, __GetOrientation)
{
	Object_wx_ScrollWinEvent *pThis = Object_wx_ScrollWinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollWinEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollWinEvent, __GetPosition)
{
	Object_wx_ScrollWinEvent *pThis = Object_wx_ScrollWinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollWinEvent, __SetOrientation, "SetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollWinEvent, __SetOrientation)
{
	Object_wx_ScrollWinEvent *pThis = Object_wx_ScrollWinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollWinEvent, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollWinEvent, __SetPosition)
{
	Object_wx_ScrollWinEvent *pThis = Object_wx_ScrollWinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScrollWinEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollWinEvent)
{
	Gura_AssignMethod(wx_ScrollWinEvent, __wxScrollWinEvent);
	Gura_AssignMethod(wx_ScrollWinEvent, __GetOrientation);
	Gura_AssignMethod(wx_ScrollWinEvent, __GetPosition);
	Gura_AssignMethod(wx_ScrollWinEvent, __SetOrientation);
	Gura_AssignMethod(wx_ScrollWinEvent, __SetPosition);
}

Gura_ImplementDescendantCreator(wx_ScrollWinEvent)
{
	return new Object_wx_ScrollWinEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
