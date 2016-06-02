//----------------------------------------------------------------------------
// wxActiveXEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxActiveXEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxActiveXEvent
//----------------------------------------------------------------------------
Object_wx_ActiveXEvent::~Object_wx_ActiveXEvent()
{
}

Object *Object_wx_ActiveXEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ActiveXEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ActiveXEvent:");
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
Gura_DeclareMethod(wx_ActiveXEvent, GetDispatchId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXEvent, GetDispatchId)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetDispatchId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActiveXEvent, ParamCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActiveXEvent, ParamCount)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParamCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActiveXEvent, ParamName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXEvent, ParamName)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->ParamName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActiveXEvent, ParamType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXEvent, ParamType)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->ParamType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActiveXEvent, GetNativeParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActiveXEvent, GetNativeParameters)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNativeParameters();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxActiveXEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActiveXEvent)
{
	Gura_AssignMethod(wx_ActiveXEvent, GetDispatchId);
	Gura_AssignMethod(wx_ActiveXEvent, ParamCount);
	Gura_AssignMethod(wx_ActiveXEvent, ParamName);
	Gura_AssignMethod(wx_ActiveXEvent, ParamType);
	Gura_AssignMethod(wx_ActiveXEvent, GetNativeParameters);
}

Gura_ImplementDescendantCreator(wx_ActiveXEvent)
{
	return new Object_wx_ActiveXEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
