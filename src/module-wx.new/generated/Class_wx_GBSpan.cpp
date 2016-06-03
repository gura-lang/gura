//----------------------------------------------------------------------------
// wxGBSpan
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGBSpan
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGBSpan
//----------------------------------------------------------------------------
Object_wx_GBSpan::~Object_wx_GBSpan()
{
}

Object *Object_wx_GBSpan::Clone() const
{
	return nullptr;
}

String Object_wx_GBSpan::ToString(bool exprFlag)
{
	String rtn("<wx.GBSpan:");
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
Gura_DeclareFunctionAlias(__wxGBSpan, "wxGBSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxGBSpan)
{
	//wxGBSpan();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGBSpan_1, "wxGBSpan_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGBSpan_1)
{
	//int rowspan = arg.GetNumber(0)
	//int colspan = arg.GetNumber(1)
	//wxGBSpan();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GBSpan, __GetColspan, "GetColspan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBSpan, __GetColspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColspan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSpan, __GetRowspan, "GetRowspan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBSpan, __GetRowspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowspan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSpan, __SetColspan, "SetColspan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, __SetColspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colspan = arg.GetNumber(0)
	//pThis->GetEntity()->SetColspan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSpan, __SetRowspan, "SetRowspan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, __SetRowspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowspan = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowspan();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGBSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBSpan)
{
	// Constructor assignment
	Gura_AssignFunction(__wxGBSpan);
	Gura_AssignFunction(__wxGBSpan_1);
	// Method assignment
	Gura_AssignMethod(wx_GBSpan, __GetColspan);
	Gura_AssignMethod(wx_GBSpan, __GetRowspan);
	Gura_AssignMethod(wx_GBSpan, __SetColspan);
	Gura_AssignMethod(wx_GBSpan, __SetRowspan);
}

Gura_ImplementDescendantCreator(wx_GBSpan)
{
	return new Object_wx_GBSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
