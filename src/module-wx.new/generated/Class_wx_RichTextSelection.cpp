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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextSelection, wxRichTextSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, wxRichTextSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, wxRichTextSelection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, wxRichTextSelection_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int container = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, wxRichTextSelection_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, wxRichTextSelection_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int container = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, Set_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, Set_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ranges = arg.GetNumber(0)
	//int container = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, operator=)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, operator=)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->operator=();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, operator[])
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, operator[])
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->operator[]();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, GetRanges)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, GetRanges)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRanges();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, GetRanges_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, GetRanges_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRanges();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, SetRanges)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, SetRanges)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ranges = arg.GetNumber(0)
	//pThis->GetEntity()->SetRanges();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, GetRange_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, GetRange_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, GetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, GetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, SetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, SetContainer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextSelection, IsValid)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, GetSelectionForObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, GetSelectionForObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionForObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, WithinSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, WithinSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->WithinSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, WithinSelection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, WithinSelection_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->WithinSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, WithinSelection_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, WithinSelection_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int ranges = arg.GetNumber(1)
	//pThis->GetEntity()->WithinSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextSelection, WithinSelection_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ranges", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextSelection, WithinSelection_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextSelection *pThis = Object_wx_RichTextSelection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_RichTextSelection, wxRichTextSelection);
	Gura_AssignMethod(wx_RichTextSelection, wxRichTextSelection_1);
	Gura_AssignMethod(wx_RichTextSelection, wxRichTextSelection_2);
	Gura_AssignMethod(wx_RichTextSelection, Reset);
	Gura_AssignMethod(wx_RichTextSelection, Set);
	Gura_AssignMethod(wx_RichTextSelection, Add);
	Gura_AssignMethod(wx_RichTextSelection, Set_1);
	Gura_AssignMethod(wx_RichTextSelection, Copy);
	Gura_AssignMethod(wx_RichTextSelection, operator=);
	Gura_AssignMethod(wx_RichTextSelection, operator[]);
	Gura_AssignMethod(wx_RichTextSelection, GetRanges);
	Gura_AssignMethod(wx_RichTextSelection, GetRanges_1);
	Gura_AssignMethod(wx_RichTextSelection, SetRanges);
	Gura_AssignMethod(wx_RichTextSelection, GetCount);
	Gura_AssignMethod(wx_RichTextSelection, GetRange);
	Gura_AssignMethod(wx_RichTextSelection, GetRange_1);
	Gura_AssignMethod(wx_RichTextSelection, SetRange);
	Gura_AssignMethod(wx_RichTextSelection, GetContainer);
	Gura_AssignMethod(wx_RichTextSelection, SetContainer);
	Gura_AssignMethod(wx_RichTextSelection, IsValid);
	Gura_AssignMethod(wx_RichTextSelection, GetSelectionForObject);
	Gura_AssignMethod(wx_RichTextSelection, WithinSelection);
	Gura_AssignMethod(wx_RichTextSelection, WithinSelection_1);
	Gura_AssignMethod(wx_RichTextSelection, WithinSelection_2);
	Gura_AssignMethod(wx_RichTextSelection, WithinSelection_3);
}

Gura_ImplementDescendantCreator(wx_RichTextSelection)
{
	return new Object_wx_RichTextSelection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
