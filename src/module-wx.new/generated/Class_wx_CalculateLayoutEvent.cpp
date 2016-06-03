//----------------------------------------------------------------------------
// wxCalculateLayoutEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCalculateLayoutEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Object_wx_CalculateLayoutEvent::~Object_wx_CalculateLayoutEvent()
{
}

Object *Object_wx_CalculateLayoutEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CalculateLayoutEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CalculateLayoutEvent:");
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
Gura_DeclareFunctionAlias(__CalculateLayoutEvent, "CalculateLayoutEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CalculateLayoutEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CalculateLayoutEvent)
{
	//wxWindowID id = arg.GetNumber(0)
	//wxCalculateLayoutEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CalculateLayoutEvent, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, __GetFlags)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalculateLayoutEvent, __GetRect, "GetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, __GetRect)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalculateLayoutEvent, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, __SetFlags)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CalculateLayoutEvent, __SetRect, "SetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CalculateLayoutEvent, __SetRect)
{
	Object_wx_CalculateLayoutEvent *pThis = Object_wx_CalculateLayoutEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetRect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalculateLayoutEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__CalculateLayoutEvent);
	// Method assignment
	Gura_AssignMethod(wx_CalculateLayoutEvent, __GetFlags);
	Gura_AssignMethod(wx_CalculateLayoutEvent, __GetRect);
	Gura_AssignMethod(wx_CalculateLayoutEvent, __SetFlags);
	Gura_AssignMethod(wx_CalculateLayoutEvent, __SetRect);
}

Gura_ImplementDescendantCreator(wx_CalculateLayoutEvent)
{
	return new Object_wx_CalculateLayoutEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
