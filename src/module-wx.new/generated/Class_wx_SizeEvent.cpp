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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SizeEvent, "SizeEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SizeEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SizeEvent)
{
	//int sz = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxSizeEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SizeEvent, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizeEvent, __GetSize)
{
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizeEvent, __SetSize, "SetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizeEvent, __SetSize)
{
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizeEvent, __GetRect, "GetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizeEvent, __GetRect)
{
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizeEvent, __SetRect, "SetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizeEvent, __SetRect)
{
	Object_wx_SizeEvent *pThis = Object_wx_SizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetRect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizeEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__SizeEvent);
	// Method assignment
	Gura_AssignMethod(wx_SizeEvent, __GetSize);
	Gura_AssignMethod(wx_SizeEvent, __SetSize);
	Gura_AssignMethod(wx_SizeEvent, __GetRect);
	Gura_AssignMethod(wx_SizeEvent, __SetRect);
}

Gura_ImplementDescendantCreator(wx_SizeEvent)
{
	return new Object_wx_SizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
