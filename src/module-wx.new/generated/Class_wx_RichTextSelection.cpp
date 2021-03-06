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
Gura_DeclareFunctionAlias(__RichTextSelection, "RichTextSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextSelection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextSelection)
{
	//const wxRichTextSelection& sel = arg.GetNumber(0)
	//wxRichTextSelection(sel);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextSelection_1, "RichTextSelection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextSelection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextSelection_1)
{
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxRichTextParagraphLayoutBox* container = arg.GetNumber(1)
	//wxRichTextSelection(range, container);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextSelection_2, "RichTextSelection_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextSelection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextSelection_2)
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
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxRichTextParagraphLayoutBox* container = arg.GetNumber(1)
	//pThis->GetEntity()->Set(range, container);
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
	//const wxRichTextRange& range = arg.GetNumber(0)
	//pThis->GetEntity()->Add(range);
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
	//const wxRichTextRangeArray& ranges = arg.GetNumber(0)
	//wxRichTextParagraphLayoutBox* container = arg.GetNumber(1)
	//pThis->GetEntity()->Set(ranges, container);
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
	//const wxRichTextSelection& sel = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(sel);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetRanges, "GetRanges")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetRanges)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextRangeArray& _rtn = pThis->GetEntity()->GetRanges();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetRanges_1, "GetRanges_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetRanges_1)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRangeArray& _rtn = pThis->GetEntity()->GetRanges();
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
	//const wxRichTextRangeArray& ranges = arg.GetNumber(0)
	//pThis->GetEntity()->SetRanges(ranges);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetCount)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetRange)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t i = arg.GetNumber(0)
	//wxRichTextRange _rtn = pThis->GetEntity()->GetRange(i);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetRange_1, "GetRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetRange_1)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextRange _rtn = pThis->GetEntity()->GetRange();
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
	//const wxRichTextRange& range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange(range);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetContainer, "GetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetContainer)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextParagraphLayoutBox* _rtn = pThis->GetEntity()->GetContainer();
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
	//wxRichTextParagraphLayoutBox* container = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainer(container);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, __IsValid)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __GetSelectionForObject, "GetSelectionForObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __GetSelectionForObject)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextObject* obj = arg.GetNumber(0)
	//wxRichTextRangeArray _rtn = pThis->GetEntity()->GetSelectionForObject(obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __WithinSelection, "WithinSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __WithinSelection)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//wxRichTextObject* obj = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->WithinSelection(pos, obj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __WithinSelection_1, "WithinSelection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __WithinSelection_1)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->WithinSelection(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __WithinSelection_2, "WithinSelection_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __WithinSelection_2)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//const wxRichTextRangeArray& ranges = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->WithinSelection(pos, ranges);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextSelection, __WithinSelection_3, "WithinSelection_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, __WithinSelection_3)
{
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//const wxRichTextRangeArray& ranges = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->WithinSelection(range, ranges);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextSelection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextSelection)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextSelection);
	Gura_AssignFunction(__RichTextSelection_1);
	Gura_AssignFunction(__RichTextSelection_2);
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
