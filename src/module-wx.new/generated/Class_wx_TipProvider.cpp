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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TipProvider, "TipProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "currentTip", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TipProvider));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TipProvider)
{
	//size_t currentTip = arg.GetNumber(0)
	//wxTipProvider(currentTip);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TipProvider, __GetCurrentTip, "GetCurrentTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TipProvider, __GetCurrentTip)
{
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentTip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TipProvider, __GetTip, "GetTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TipProvider, __GetTip)
{
	Object_wx_TipProvider *pThis = Object_wx_TipProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTip();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTipProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipProvider)
{
	// Constructor assignment
	Gura_AssignFunction(__TipProvider);
	// Method assignment
	Gura_AssignMethod(wx_TipProvider, __GetCurrentTip);
	Gura_AssignMethod(wx_TipProvider, __GetTip);
}

Gura_ImplementDescendantCreator(wx_TipProvider)
{
	return new Object_wx_TipProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
