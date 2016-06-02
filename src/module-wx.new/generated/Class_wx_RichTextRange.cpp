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
Gura_DeclareMethod(wx_RichTextRange, wxRichTextRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, wxRichTextRange)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, wxRichTextRange_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, wxRichTextRange_1)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, wxRichTextRange_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, wxRichTextRange_2)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, operator ==)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, operator ==)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->operator ==();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, operator !=)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, operator !=)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->operator !=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, operator -)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, operator -)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->operator -();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, operator +)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, operator +)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->operator +();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, SetRange)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, SetStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, SetStart)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//pThis->GetEntity()->SetStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, GetStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, GetStart)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, SetEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, SetEnd)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int end = arg.GetNumber(0)
	//pThis->GetEntity()->SetEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, GetEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, GetEnd)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, IsOutside)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, IsOutside)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->IsOutside();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, IsWithin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, IsWithin)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->IsWithin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, Contains)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, LimitTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, LimitTo)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->LimitTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, GetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, GetLength)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, Swap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, Swap)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Swap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, ToInternal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, ToInternal)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToInternal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextRange, FromInternal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, FromInternal)
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
	Gura_AssignMethod(wx_RichTextRange, wxRichTextRange);
	Gura_AssignMethod(wx_RichTextRange, wxRichTextRange_1);
	Gura_AssignMethod(wx_RichTextRange, wxRichTextRange_2);
	Gura_AssignMethod(wx_RichTextRange, operator ==);
	Gura_AssignMethod(wx_RichTextRange, operator !=);
	Gura_AssignMethod(wx_RichTextRange, operator -);
	Gura_AssignMethod(wx_RichTextRange, operator +);
	Gura_AssignMethod(wx_RichTextRange, SetRange);
	Gura_AssignMethod(wx_RichTextRange, SetStart);
	Gura_AssignMethod(wx_RichTextRange, GetStart);
	Gura_AssignMethod(wx_RichTextRange, SetEnd);
	Gura_AssignMethod(wx_RichTextRange, GetEnd);
	Gura_AssignMethod(wx_RichTextRange, IsOutside);
	Gura_AssignMethod(wx_RichTextRange, IsWithin);
	Gura_AssignMethod(wx_RichTextRange, Contains);
	Gura_AssignMethod(wx_RichTextRange, LimitTo);
	Gura_AssignMethod(wx_RichTextRange, GetLength);
	Gura_AssignMethod(wx_RichTextRange, Swap);
	Gura_AssignMethod(wx_RichTextRange, ToInternal);
	Gura_AssignMethod(wx_RichTextRange, FromInternal);
}

Gura_ImplementDescendantCreator(wx_RichTextRange)
{
	return new Object_wx_RichTextRange((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
