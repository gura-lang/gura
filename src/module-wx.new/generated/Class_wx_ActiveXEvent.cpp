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
Gura_DeclareMethodAlias(wx_ActiveXEvent, __GetDispatchId, "GetDispatchId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXEvent, __GetDispatchId)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetDispatchId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ActiveXEvent, __ParamCount, "ParamCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActiveXEvent, __ParamCount)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParamCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ActiveXEvent, __ParamName, "ParamName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXEvent, __ParamName)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->ParamName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ActiveXEvent, __ParamType, "ParamType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActiveXEvent, __ParamType)
{
	Object_wx_ActiveXEvent *pThis = Object_wx_ActiveXEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->ParamType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ActiveXEvent, __GetNativeParameters, "GetNativeParameters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActiveXEvent, __GetNativeParameters)
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
	Gura_AssignMethod(wx_ActiveXEvent, __GetDispatchId);
	Gura_AssignMethod(wx_ActiveXEvent, __ParamCount);
	Gura_AssignMethod(wx_ActiveXEvent, __ParamName);
	Gura_AssignMethod(wx_ActiveXEvent, __ParamType);
	Gura_AssignMethod(wx_ActiveXEvent, __GetNativeParameters);
}

Gura_ImplementDescendantCreator(wx_ActiveXEvent)
{
	return new Object_wx_ActiveXEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
