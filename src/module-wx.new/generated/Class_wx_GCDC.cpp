//----------------------------------------------------------------------------
// wxGCDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGCDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGCDC
//----------------------------------------------------------------------------
Object_wx_GCDC::~Object_wx_GCDC()
{
}

Object *Object_wx_GCDC::Clone() const
{
	return nullptr;
}

String Object_wx_GCDC::ToString(bool exprFlag)
{
	String rtn("<wx.GCDC:");
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
Gura_DeclareMethod(wx_GCDC, wxGCDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GCDC, wxGCDC)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int windowDC = arg.GetNumber(0)
	//pThis->GetEntity()->wxGCDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GCDC, wxGCDC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "memoryDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GCDC, wxGCDC_1)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int memoryDC = arg.GetNumber(0)
	//pThis->GetEntity()->wxGCDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GCDC, wxGCDC_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printerDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GCDC, wxGCDC_2)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int printerDC = arg.GetNumber(0)
	//pThis->GetEntity()->wxGCDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GCDC, wxGCDC_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GCDC, wxGCDC_3)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//pThis->GetEntity()->wxGCDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GCDC, wxGCDC_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "emfDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GCDC, wxGCDC_4)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int emfDC = arg.GetNumber(0)
	//pThis->GetEntity()->wxGCDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GCDC, wxGCDC_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GCDC, wxGCDC_5)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGCDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GCDC, GetGraphicsContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GCDC, GetGraphicsContext)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGraphicsContext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GCDC, SetGraphicsContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GCDC, SetGraphicsContext)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctx = arg.GetNumber(0)
	//pThis->GetEntity()->SetGraphicsContext();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGCDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GCDC)
{
	Gura_AssignMethod(wx_GCDC, wxGCDC);
	Gura_AssignMethod(wx_GCDC, wxGCDC_1);
	Gura_AssignMethod(wx_GCDC, wxGCDC_2);
	Gura_AssignMethod(wx_GCDC, wxGCDC_3);
	Gura_AssignMethod(wx_GCDC, wxGCDC_4);
	Gura_AssignMethod(wx_GCDC, wxGCDC_5);
	Gura_AssignMethod(wx_GCDC, GetGraphicsContext);
	Gura_AssignMethod(wx_GCDC, SetGraphicsContext);
}

Gura_ImplementDescendantCreator(wx_GCDC)
{
	return new Object_wx_GCDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
