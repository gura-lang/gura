//----------------------------------------------------------------------------
// wxEraseEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEraseEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEraseEvent
//----------------------------------------------------------------------------
Object_wx_EraseEvent::~Object_wx_EraseEvent()
{
}

Object *Object_wx_EraseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_EraseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.EraseEvent:");
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
Gura_DeclareMethod(wx_EraseEvent, wxEraseEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EraseEvent, wxEraseEvent)
{
	Object_wx_EraseEvent *pThis = Object_wx_EraseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//pThis->GetEntity()->wxEraseEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EraseEvent, GetDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EraseEvent, GetDC)
{
	Object_wx_EraseEvent *pThis = Object_wx_EraseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEraseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EraseEvent)
{
	Gura_AssignMethod(wx_EraseEvent, wxEraseEvent);
	Gura_AssignMethod(wx_EraseEvent, GetDC);
}

Gura_ImplementDescendantCreator(wx_EraseEvent)
{
	return new Object_wx_EraseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
