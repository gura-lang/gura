//----------------------------------------------------------------------------
// wxMaximizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMaximizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Object_wx_MaximizeEvent::~Object_wx_MaximizeEvent()
{
}

Object *Object_wx_MaximizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MaximizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MaximizeEvent:");
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
Gura_DeclareMethod(wx_MaximizeEvent, wxMaximizeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MaximizeEvent, wxMaximizeEvent)
{
	Object_wx_MaximizeEvent *pThis = Object_wx_MaximizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->wxMaximizeEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MaximizeEvent)
{
	Gura_AssignMethod(wx_MaximizeEvent, wxMaximizeEvent);
}

Gura_ImplementDescendantCreator(wx_MaximizeEvent)
{
	return new Object_wx_MaximizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
