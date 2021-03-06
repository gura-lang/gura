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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextRange, "RichTextRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextRange));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextRange)
{
	//wxRichTextRange();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextRange_1, "RichTextRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextRange));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextRange_1)
{
	//long start = arg.GetNumber(0)
	//long end = arg.GetNumber(1)
	//wxRichTextRange(start, end);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextRange_2, "RichTextRange_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextRange));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextRange_2)
{
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxRichTextRange(range);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	//long start = arg.GetNumber(0)
	//long end = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange(start, end);
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
	//long start = arg.GetNumber(0)
	//pThis->GetEntity()->SetStart(start);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __GetStart, "GetStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __GetStart)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetStart();
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
	//long end = arg.GetNumber(0)
	//pThis->GetEntity()->SetEnd(end);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __GetEnd, "GetEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __GetEnd)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __IsOutside, "IsOutside")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __IsOutside)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsOutside(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __IsWithin, "IsWithin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __IsWithin)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsWithin(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __Contains, "Contains")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __Contains)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Contains(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __LimitTo, "LimitTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextRange, __LimitTo)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->LimitTo(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __GetLength, "GetLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __GetLength)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetLength();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __ToInternal)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextRange _rtn = pThis->GetEntity()->ToInternal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextRange, __FromInternal, "FromInternal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextRange, __FromInternal)
{
	Object_wx_RichTextRange *pThis = Object_wx_RichTextRange::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextRange _rtn = pThis->GetEntity()->FromInternal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextRange
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextRange)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextRange);
	Gura_AssignFunction(__RichTextRange_1);
	Gura_AssignFunction(__RichTextRange_2);
	// Method assignment
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
