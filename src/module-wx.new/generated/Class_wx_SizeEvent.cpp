//----------------------------------------------------------------------------
// wxSizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizeEvent
//----------------------------------------------------------------------------
Object_wx_SizeEvent::~Object_wx_SizeEvent()
{
}

Object *Object_wx_SizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SizeEvent:");
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
Gura_DeclareMethod(wx_SizeEvent, wxSizeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizeEvent, wxSizeEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxSizeEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizeEvent, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizeEvent, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizeEvent, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizeEvent, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizeEvent, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizeEvent, GetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizeEvent, SetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizeEvent, SetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetRect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizeEvent)
{
	Gura_AssignMethod(wx_SizeEvent, wxSizeEvent);
	Gura_AssignMethod(wx_SizeEvent, GetSize);
	Gura_AssignMethod(wx_SizeEvent, SetSize);
	Gura_AssignMethod(wx_SizeEvent, GetRect);
	Gura_AssignMethod(wx_SizeEvent, SetRect);
}

Gura_ImplementDescendantCreator(wx_SizeEvent)
{
	return new Object_wx_SizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
