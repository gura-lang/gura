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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GBSpan, wxGBSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBSpan, wxGBSpan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGBSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSpan, wxGBSpan_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, wxGBSpan_1)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowspan = arg.GetNumber(0)
	//int colspan = arg.GetNumber(1)
	//pThis->GetEntity()->wxGBSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSpan, GetColspan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBSpan, GetColspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColspan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSpan, GetRowspan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBSpan, GetRowspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowspan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSpan, SetColspan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, SetColspan)
{
	Object_wx_GBSpan *pThis = Object_wx_GBSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colspan = arg.GetNumber(0)
	//pThis->GetEntity()->SetColspan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSpan, SetRowspan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSpan, SetRowspan)
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
	Gura_AssignMethod(wx_GBSpan, wxGBSpan);
	Gura_AssignMethod(wx_GBSpan, wxGBSpan_1);
	Gura_AssignMethod(wx_GBSpan, GetColspan);
	Gura_AssignMethod(wx_GBSpan, GetRowspan);
	Gura_AssignMethod(wx_GBSpan, SetColspan);
	Gura_AssignMethod(wx_GBSpan, SetRowspan);
}

Gura_ImplementDescendantCreator(wx_GBSpan)
{
	return new Object_wx_GBSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
