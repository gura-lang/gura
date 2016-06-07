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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SpinEvent, "SpinEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SpinEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SpinEvent)
{
	//wxEventType commandType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxSpinEvent(commandType, id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SpinEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SpinEvent, __GetPosition)
{
	Object_wx_SpinEvent *pThis = Object_wx_SpinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinEvent, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinEvent, __SetPosition)
{
	Object_wx_SpinEvent *pThis = Object_wx_SpinEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition(pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__SpinEvent);
	// Method assignment
	Gura_AssignMethod(wx_SpinEvent, __GetPosition);
	Gura_AssignMethod(wx_SpinEvent, __SetPosition);
}

Gura_ImplementDescendantCreator(wx_SpinEvent)
{
	return new Object_wx_SpinEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
