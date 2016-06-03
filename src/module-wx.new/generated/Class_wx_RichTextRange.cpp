//----------------------------------------------------------------------------
// wxRichTextRange
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextRange
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextRange
//----------------------------------------------------------------------------
Object_wx_RichTextRange::~Object_wx_RichTextRange()
{
}

Object *Object_wx_RichTextRange::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextRange::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextRange:");
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
Gura_DeclareMethodAlias(wx_RichTextRange, __wxRichTextRange, "wxRichTextRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __wxRichTextRange)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __wxRichTextRange_1, "wxRichTextRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __wxRichTextRange_1)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __wxRichTextRange_2, "wxRichTextRange_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __wxRichTextRange_2)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __SetRange)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __SetStart, "SetStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __SetStart)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//pThis->GetEntity()->SetStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __GetStart, "GetStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __GetStart)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __SetEnd, "SetEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __SetEnd)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int end = arg.GetNumber(0)
	//pThis->GetEntity()->SetEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __GetEnd, "GetEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __GetEnd)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __IsOutside, "IsOutside")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __IsOutside)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->IsOutside();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __IsWithin, "IsWithin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __IsWithin)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->IsWithin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __Contains, "Contains")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __Contains)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __LimitTo, "LimitTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __LimitTo)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->LimitTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __GetLength, "GetLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __GetLength)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __Swap, "Swap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __Swap)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Swap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __ToInternal, "ToInternal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __ToInternal)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToInternal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __FromInternal, "FromInternal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __FromInternal)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FromInternal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextRange
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextRange)
{
	Gura_AssignMethod(wx_RichTextRange, __wxRichTextRange);
	Gura_AssignMethod(wx_RichTextRange, __wxRichTextRange_1);
	Gura_AssignMethod(wx_RichTextRange, __wxRichTextRange_2);
	Gura_AssignMethod(wx_RichTextRange, __SetRange);
	Gura_AssignMethod(wx_RichTextRange, __SetStart);
	Gura_AssignMethod(wx_RichTextRange, __GetStart);
	Gura_AssignMethod(wx_RichTextRange, __SetEnd);
	Gura_AssignMethod(wx_RichTextRange, __GetEnd);
	Gura_AssignMethod(wx_RichTextRange, __IsOutside);
	Gura_AssignMethod(wx_RichTextRange, __IsWithin);
	Gura_AssignMethod(wx_RichTextRange, __Contains);
	Gura_AssignMethod(wx_RichTextRange, __LimitTo);
	Gura_AssignMethod(wx_RichTextRange, __GetLength);
	Gura_AssignMethod(wx_RichTextRange, __Swap);
	Gura_AssignMethod(wx_RichTextRange, __ToInternal);
	Gura_AssignMethod(wx_RichTextRange, __FromInternal);
}

Gura_ImplementDescendantCreator(wx_RichTextRange)
{
	return new Object_wx_RichTextRange((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
