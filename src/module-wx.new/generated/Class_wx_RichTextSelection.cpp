//----------------------------------------------------------------------------
// wxRichTextSelection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextSelection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextSelection
//----------------------------------------------------------------------------
Object_wx_RichTextSelection::~Object_wx_RichTextSelection()
{
}

Object *Object_wx_RichTextSelection::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextSelection::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextSelection:");
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
Gura_DeclareFunctionAlias(__wxRichTextSelection, "wxRichTextSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRichTextSelection)
{
	//int sel = arg.GetNumber(0)
	//wxRichTextSelection();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextSelection_1, "wxRichTextSelection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRichTextSelection_1)
{
	//int range = arg.GetNumber(0)
	//int container = arg.GetNumber(1)
	//wxRichTextSelection();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextSelection_2, "wxRichTextSelection_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxRichTextSelection_2)
{
	//wxRichTextSelection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextSelection, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __Reset)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __Set)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int container = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __Add)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __Set_1, "Set_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __Set_1)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ranges = arg.GetNumber(0)
	//int container = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __Copy)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetRanges, "GetRanges")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetRanges)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRanges();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetRanges_1, "GetRanges_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetRanges_1)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRanges();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __SetRanges, "SetRanges")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __SetRanges)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ranges = arg.GetNumber(0)
	//pThis->GetEntity()->SetRanges();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetCount)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetRange)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetRange_1, "GetRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetRange_1)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __SetRange)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetContainer, "GetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetContainer)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __SetContainer, "SetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __SetContainer)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __IsValid)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetSelectionForObject, "GetSelectionForObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetSelectionForObject)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionForObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __WithinSelection, "WithinSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __WithinSelection)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->WithinSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __WithinSelection_1, "WithinSelection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __WithinSelection_1)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->WithinSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __WithinSelection_2, "WithinSelection_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __WithinSelection_2)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int ranges = arg.GetNumber(1)
	//pThis->GetEntity()->WithinSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __WithinSelection_3, "WithinSelection_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __WithinSelection_3)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int ranges = arg.GetNumber(1)
	//pThis->GetEntity()->WithinSelection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextSelection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextSelection)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextSelection);
	Gura_AssignFunction(__wxRichTextSelection_1);
	Gura_AssignFunction(__wxRichTextSelection_2);
	// Method assignment
	Gura_AssignMethod(wx_RichTextSelection, __Reset);
	Gura_AssignMethod(wx_RichTextSelection, __Set);
	Gura_AssignMethod(wx_RichTextSelection, __Add);
	Gura_AssignMethod(wx_RichTextSelection, __Set_1);
	Gura_AssignMethod(wx_RichTextSelection, __Copy);
	Gura_AssignMethod(wx_RichTextSelection, __GetRanges);
	Gura_AssignMethod(wx_RichTextSelection, __GetRanges_1);
	Gura_AssignMethod(wx_RichTextSelection, __SetRanges);
	Gura_AssignMethod(wx_RichTextSelection, __GetCount);
	Gura_AssignMethod(wx_RichTextSelection, __GetRange);
	Gura_AssignMethod(wx_RichTextSelection, __GetRange_1);
	Gura_AssignMethod(wx_RichTextSelection, __SetRange);
	Gura_AssignMethod(wx_RichTextSelection, __GetContainer);
	Gura_AssignMethod(wx_RichTextSelection, __SetContainer);
	Gura_AssignMethod(wx_RichTextSelection, __IsValid);
	Gura_AssignMethod(wx_RichTextSelection, __GetSelectionForObject);
	Gura_AssignMethod(wx_RichTextSelection, __WithinSelection);
	Gura_AssignMethod(wx_RichTextSelection, __WithinSelection_1);
	Gura_AssignMethod(wx_RichTextSelection, __WithinSelection_2);
	Gura_AssignMethod(wx_RichTextSelection, __WithinSelection_3);
}

Gura_ImplementDescendantCreator(wx_RichTextSelection)
{
	return new Object_wx_RichTextSelection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
