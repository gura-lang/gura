//----------------------------------------------------------------------------
// wxAppProgressIndicator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAppProgressIndicator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAppProgressIndicator
//----------------------------------------------------------------------------
Object_wx_AppProgressIndicator::~Object_wx_AppProgressIndicator()
{
}

Object *Object_wx_AppProgressIndicator::Clone() const
{
	return nullptr;
}

String Object_wx_AppProgressIndicator::ToString(bool exprFlag)
{
	String rtn("<wx.AppProgressIndicator:");
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
Gura_DeclareMethod(wx_AppProgressIndicator, wxAppProgressIndicator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppProgressIndicator, wxAppProgressIndicator)
{
	Object_wx_AppProgressIndicator *pThis = Object_wx_AppProgressIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int maxValue = arg.GetNumber(1)
	//pThis->GetEntity()->wxAppProgressIndicator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppProgressIndicator, IsAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppProgressIndicator, IsAvailable)
{
	Object_wx_AppProgressIndicator *pThis = Object_wx_AppProgressIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAvailable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppProgressIndicator, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppProgressIndicator, SetValue)
{
	Object_wx_AppProgressIndicator *pThis = Object_wx_AppProgressIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppProgressIndicator, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppProgressIndicator, SetRange)
{
	Object_wx_AppProgressIndicator *pThis = Object_wx_AppProgressIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppProgressIndicator, Pulse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppProgressIndicator, Pulse)
{
	Object_wx_AppProgressIndicator *pThis = Object_wx_AppProgressIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Pulse();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAppProgressIndicator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppProgressIndicator)
{
	Gura_AssignMethod(wx_AppProgressIndicator, wxAppProgressIndicator);
	Gura_AssignMethod(wx_AppProgressIndicator, IsAvailable);
	Gura_AssignMethod(wx_AppProgressIndicator, SetValue);
	Gura_AssignMethod(wx_AppProgressIndicator, SetRange);
	Gura_AssignMethod(wx_AppProgressIndicator, Pulse);
}

Gura_ImplementDescendantCreator(wx_AppProgressIndicator)
{
	return new Object_wx_AppProgressIndicator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
