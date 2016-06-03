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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AppProgressIndicator, "AppProgressIndicator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxValue", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AppProgressIndicator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AppProgressIndicator)
{
	//int parent = arg.GetNumber(0)
	//int maxValue = arg.GetNumber(1)
	//wxAppProgressIndicator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AppProgressIndicator, __IsAvailable, "IsAvailable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppProgressIndicator, __IsAvailable)
{
	Object_wx_AppProgressIndicator *pThis = Object_wx_AppProgressIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAvailable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppProgressIndicator, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppProgressIndicator, __SetValue)
{
	Object_wx_AppProgressIndicator *pThis = Object_wx_AppProgressIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppProgressIndicator, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppProgressIndicator, __SetRange)
{
	Object_wx_AppProgressIndicator *pThis = Object_wx_AppProgressIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppProgressIndicator, __Pulse, "Pulse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppProgressIndicator, __Pulse)
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
	// Constructor assignment
	Gura_AssignFunction(__AppProgressIndicator);
	// Method assignment
	Gura_AssignMethod(wx_AppProgressIndicator, __IsAvailable);
	Gura_AssignMethod(wx_AppProgressIndicator, __SetValue);
	Gura_AssignMethod(wx_AppProgressIndicator, __SetRange);
	Gura_AssignMethod(wx_AppProgressIndicator, __Pulse);
}

Gura_ImplementDescendantCreator(wx_AppProgressIndicator)
{
	return new Object_wx_AppProgressIndicator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
