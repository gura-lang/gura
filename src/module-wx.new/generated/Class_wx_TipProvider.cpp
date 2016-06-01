//----------------------------------------------------------------------------
// wxTipProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTipProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTipProvider
//----------------------------------------------------------------------------
Object_wx_TipProvider::~Object_wx_TipProvider()
{
}

Object *Object_wx_TipProvider::Clone() const
{
	return nullptr;
}

String Object_wx_TipProvider::ToString(bool exprFlag)
{
	String rtn("<wx.TipProvider:");
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
Gura_DeclareMethod(wx_TipProvider, wxTipProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "currentTip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TipProvider, wxTipProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int currentTip = arg.GetNumber(0)
	//pThis->GetEntity()->wxTipProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TipProvider, ~wxTipProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TipProvider, ~wxTipProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxTipProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TipProvider, GetCurrentTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TipProvider, GetCurrentTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentTip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TipProvider, GetTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TipProvider, GetTip)
{
	Signal &sig = env.GetSignal();
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTip();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTipProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipProvider)
{
	Gura_AssignMethod(wx_TipProvider, wxTipProvider);
	Gura_AssignMethod(wx_TipProvider, ~wxTipProvider);
	Gura_AssignMethod(wx_TipProvider, GetCurrentTip);
	Gura_AssignMethod(wx_TipProvider, GetTip);
}

Gura_ImplementDescendantCreator(wx_TipProvider)
{
	return new Object_wx_TipProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
