//----------------------------------------------------------------------------
// wxDialogLayoutAdapter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialogLayoutAdapter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDialogLayoutAdapter
//----------------------------------------------------------------------------
Object_wx_DialogLayoutAdapter::~Object_wx_DialogLayoutAdapter()
{
}

Object *Object_wx_DialogLayoutAdapter::Clone() const
{
	return nullptr;
}

String Object_wx_DialogLayoutAdapter::ToString(bool exprFlag)
{
	String rtn("<wx.DialogLayoutAdapter:");
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
Gura_DeclareMethod(wx_DialogLayoutAdapter, wxDialogLayoutAdapter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialogLayoutAdapter, wxDialogLayoutAdapter)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialogLayoutAdapter *pThis = Object_wx_DialogLayoutAdapter::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDialogLayoutAdapter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialogLayoutAdapter, CanDoLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialogLayoutAdapter, CanDoLayoutAdaptation)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialogLayoutAdapter *pThis = Object_wx_DialogLayoutAdapter::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dialog = arg.GetNumber(0)
	//pThis->GetEntity()->CanDoLayoutAdaptation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialogLayoutAdapter, DoLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialogLayoutAdapter, DoLayoutAdaptation)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialogLayoutAdapter *pThis = Object_wx_DialogLayoutAdapter::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dialog = arg.GetNumber(0)
	//pThis->GetEntity()->DoLayoutAdaptation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDialogLayoutAdapter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialogLayoutAdapter)
{
	Gura_AssignMethod(wx_DialogLayoutAdapter, wxDialogLayoutAdapter);
	Gura_AssignMethod(wx_DialogLayoutAdapter, CanDoLayoutAdaptation);
	Gura_AssignMethod(wx_DialogLayoutAdapter, DoLayoutAdaptation);
}

Gura_ImplementDescendantCreator(wx_DialogLayoutAdapter)
{
	return new Object_wx_DialogLayoutAdapter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
