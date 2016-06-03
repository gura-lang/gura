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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxGCDC, "wxGCDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "windowDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGCDC)
{
	//int windowDC = arg.GetNumber(0)
	//wxGCDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGCDC_1, "wxGCDC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "memoryDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGCDC_1)
{
	//int memoryDC = arg.GetNumber(0)
	//wxGCDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGCDC_2, "wxGCDC_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printerDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGCDC_2)
{
	//int printerDC = arg.GetNumber(0)
	//wxGCDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGCDC_3, "wxGCDC_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGCDC_3)
{
	//int context = arg.GetNumber(0)
	//wxGCDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGCDC_4, "wxGCDC_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "emfDC", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGCDC_4)
{
	//int emfDC = arg.GetNumber(0)
	//wxGCDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGCDC_5, "wxGCDC_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxGCDC_5)
{
	//wxGCDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GCDC, __GetGraphicsContext, "GetGraphicsContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GCDC, __GetGraphicsContext)
{
	Object_wx_GCDC *pThis = Object_wx_GCDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGraphicsContext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GCDC, __SetGraphicsContext, "SetGraphicsContext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GCDC, __SetGraphicsContext)
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
	// Constructor assignment
	Gura_AssignFunction(__wxGCDC);
	Gura_AssignFunction(__wxGCDC_1);
	Gura_AssignFunction(__wxGCDC_2);
	Gura_AssignFunction(__wxGCDC_3);
	Gura_AssignFunction(__wxGCDC_4);
	Gura_AssignFunction(__wxGCDC_5);
	// Method assignment
	Gura_AssignMethod(wx_GCDC, __GetGraphicsContext);
	Gura_AssignMethod(wx_GCDC, __SetGraphicsContext);
}

Gura_ImplementDescendantCreator(wx_GCDC)
{
	return new Object_wx_GCDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
