//----------------------------------------------------------------------------
// wxSpinEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinEvent
//----------------------------------------------------------------------------
Object_wx_SpinEvent::~Object_wx_SpinEvent()
{
}

Object *Object_wx_SpinEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SpinEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SpinEvent:");
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
Gura_DeclareMethod(wx_SpinEvent, wxSpinEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinEvent, wxSpinEvent)
{
	Object_wx_SpinEvent *pThis = Object_wx_SpinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxSpinEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinEvent, GetPosition)
{
	Object_wx_SpinEvent *pThis = Object_wx_SpinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinEvent, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinEvent, SetPosition)
{
	Object_wx_SpinEvent *pThis = Object_wx_SpinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinEvent)
{
	Gura_AssignMethod(wx_SpinEvent, wxSpinEvent);
	Gura_AssignMethod(wx_SpinEvent, GetPosition);
	Gura_AssignMethod(wx_SpinEvent, SetPosition);
}

Gura_ImplementDescendantCreator(wx_SpinEvent)
{
	return new Object_wx_SpinEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
