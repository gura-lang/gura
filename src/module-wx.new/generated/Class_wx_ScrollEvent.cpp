//----------------------------------------------------------------------------
// wxScrollEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScrollEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScrollEvent
//----------------------------------------------------------------------------
Object_wx_ScrollEvent::~Object_wx_ScrollEvent()
{
}

Object *Object_wx_ScrollEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ScrollEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ScrollEvent:");
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
Gura_DeclareFunctionAlias(__wxScrollEvent, "wxScrollEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxScrollEvent)
{
	//int commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int orientation = arg.GetNumber(3)
	//wxScrollEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ScrollEvent, __GetOrientation, "GetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollEvent, __GetOrientation)
{
	Object_wx_ScrollEvent *pThis = Object_wx_ScrollEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScrollEvent, __GetPosition)
{
	Object_wx_ScrollEvent *pThis = Object_wx_ScrollEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollEvent, __SetOrientation, "SetOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollEvent, __SetOrientation)
{
	Object_wx_ScrollEvent *pThis = Object_wx_ScrollEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScrollEvent, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollEvent, __SetPosition)
{
	Object_wx_ScrollEvent *pThis = Object_wx_ScrollEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScrollEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxScrollEvent);
	// Method assignment
	Gura_AssignMethod(wx_ScrollEvent, __GetOrientation);
	Gura_AssignMethod(wx_ScrollEvent, __GetPosition);
	Gura_AssignMethod(wx_ScrollEvent, __SetOrientation);
	Gura_AssignMethod(wx_ScrollEvent, __SetPosition);
}

Gura_ImplementDescendantCreator(wx_ScrollEvent)
{
	return new Object_wx_ScrollEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
