//----------------------------------------------------------------------------
// wxVListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVListBox
//----------------------------------------------------------------------------
Object_wx_VListBox::~Object_wx_VListBox()
{
}

Object *Object_wx_VListBox::Clone() const
{
	return nullptr;
}

String Object_wx_VListBox::ToString(bool exprFlag)
{
	String rtn("<wx.VListBox:");
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
Gura_DeclareMethod(wx_VListBox, wxVListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, wxVListBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxVListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, wxVListBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, wxVListBox_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxVListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, ~wxVListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, ~wxVListBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxVListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, DeselectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, DeselectAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeselectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, GetFirstSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, GetFirstSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cookie = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, GetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, GetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, GetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, GetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, GetItemRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, GetItemRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, GetNextSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, GetNextSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cookie = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, GetSelectedCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, GetSelectedCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, GetSelectionBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, GetSelectionBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, HasMultipleSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, HasMultipleSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasMultipleSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, IsCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, IsCurrent)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, IsSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int select = arg.GetNumber(1)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, SelectAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SelectRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SelectRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SelectRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetMargins_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, SetSelectionBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, SetSelectionBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, Toggle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, Toggle)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Toggle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, OnDrawItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, OnDrawItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, OnDrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, OnDrawBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, OnDrawSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, OnDrawSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VListBox, OnMeasureItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, OnMeasureItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->OnMeasureItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VListBox)
{
	Gura_AssignMethod(wx_VListBox, wxVListBox);
	Gura_AssignMethod(wx_VListBox, wxVListBox_1);
	Gura_AssignMethod(wx_VListBox, ~wxVListBox);
	Gura_AssignMethod(wx_VListBox, Clear);
	Gura_AssignMethod(wx_VListBox, Create);
	Gura_AssignMethod(wx_VListBox, DeselectAll);
	Gura_AssignMethod(wx_VListBox, GetFirstSelected);
	Gura_AssignMethod(wx_VListBox, GetItemCount);
	Gura_AssignMethod(wx_VListBox, GetMargins);
	Gura_AssignMethod(wx_VListBox, GetItemRect);
	Gura_AssignMethod(wx_VListBox, GetNextSelected);
	Gura_AssignMethod(wx_VListBox, GetSelectedCount);
	Gura_AssignMethod(wx_VListBox, GetSelection);
	Gura_AssignMethod(wx_VListBox, GetSelectionBackground);
	Gura_AssignMethod(wx_VListBox, HasMultipleSelection);
	Gura_AssignMethod(wx_VListBox, IsCurrent);
	Gura_AssignMethod(wx_VListBox, IsSelected);
	Gura_AssignMethod(wx_VListBox, Select);
	Gura_AssignMethod(wx_VListBox, SelectAll);
	Gura_AssignMethod(wx_VListBox, SelectRange);
	Gura_AssignMethod(wx_VListBox, SetItemCount);
	Gura_AssignMethod(wx_VListBox, SetMargins);
	Gura_AssignMethod(wx_VListBox, SetMargins_1);
	Gura_AssignMethod(wx_VListBox, SetSelection);
	Gura_AssignMethod(wx_VListBox, SetSelectionBackground);
	Gura_AssignMethod(wx_VListBox, Toggle);
	Gura_AssignMethod(wx_VListBox, OnDrawItem);
	Gura_AssignMethod(wx_VListBox, OnDrawBackground);
	Gura_AssignMethod(wx_VListBox, OnDrawSeparator);
	Gura_AssignMethod(wx_VListBox, OnMeasureItem);
}

Gura_ImplementDescendantCreator(wx_VListBox)
{
	return new Object_wx_VListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
