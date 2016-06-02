//----------------------------------------------------------------------------
// wxTextEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextEntry
//----------------------------------------------------------------------------
Object_wx_TextEntry::~Object_wx_TextEntry()
{
}

Object *Object_wx_TextEntry::Clone() const
{
	return nullptr;
}

String Object_wx_TextEntry::ToString(bool exprFlag)
{
	String rtn("<wx.TextEntry:");
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
Gura_DeclareMethod(wx_TextEntry, AppendText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, AppendText)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AppendText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, AutoComplete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, AutoComplete)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int choices = arg.GetNumber(0)
	//pThis->GetEntity()->AutoComplete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, AutoComplete_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "completer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, AutoComplete_1)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int completer = arg.GetNumber(0)
	//pThis->GetEntity()->AutoComplete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, AutoCompleteFileNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, AutoCompleteFileNames)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompleteFileNames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, AutoCompleteDirectories)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, AutoCompleteDirectories)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompleteDirectories();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, CanCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, CanCopy)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCopy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, CanCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, CanCut)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, CanPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, CanPaste)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, CanRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, CanRedo)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, CanUndo)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, ChangeValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, ChangeValue)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, Clear)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, Copy)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, Cut)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, ForceUpper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, ForceUpper)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ForceUpper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, GetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, GetInsertionPoint)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, GetLastPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, GetLastPosition)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, GetRange)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, GetSelection)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, GetStringSelection)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, GetValue)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, IsEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, IsEditable)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, IsEmpty)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, Paste)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, Redo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, Redo)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, Remove)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, Replace)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, SetEditable)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int editable = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, SetInsertionPoint)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetInsertionPointEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, SetInsertionPointEnd)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetMaxLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, SetMaxLength)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, SetSelection)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, SelectAll)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SelectNone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, SelectNone)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectNone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, SetHint)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hint = arg.GetNumber(0)
	//pThis->GetEntity()->SetHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, GetHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, GetHint)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, SetMargins)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, SetMargins_1)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int top = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, GetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, GetMargins)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, SetValue)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, Undo)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntry, WriteText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, WriteText)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->WriteText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextEntry)
{
	Gura_AssignMethod(wx_TextEntry, AppendText);
	Gura_AssignMethod(wx_TextEntry, AutoComplete);
	Gura_AssignMethod(wx_TextEntry, AutoComplete_1);
	Gura_AssignMethod(wx_TextEntry, AutoCompleteFileNames);
	Gura_AssignMethod(wx_TextEntry, AutoCompleteDirectories);
	Gura_AssignMethod(wx_TextEntry, CanCopy);
	Gura_AssignMethod(wx_TextEntry, CanCut);
	Gura_AssignMethod(wx_TextEntry, CanPaste);
	Gura_AssignMethod(wx_TextEntry, CanRedo);
	Gura_AssignMethod(wx_TextEntry, CanUndo);
	Gura_AssignMethod(wx_TextEntry, ChangeValue);
	Gura_AssignMethod(wx_TextEntry, Clear);
	Gura_AssignMethod(wx_TextEntry, Copy);
	Gura_AssignMethod(wx_TextEntry, Cut);
	Gura_AssignMethod(wx_TextEntry, ForceUpper);
	Gura_AssignMethod(wx_TextEntry, GetInsertionPoint);
	Gura_AssignMethod(wx_TextEntry, GetLastPosition);
	Gura_AssignMethod(wx_TextEntry, GetRange);
	Gura_AssignMethod(wx_TextEntry, GetSelection);
	Gura_AssignMethod(wx_TextEntry, GetStringSelection);
	Gura_AssignMethod(wx_TextEntry, GetValue);
	Gura_AssignMethod(wx_TextEntry, IsEditable);
	Gura_AssignMethod(wx_TextEntry, IsEmpty);
	Gura_AssignMethod(wx_TextEntry, Paste);
	Gura_AssignMethod(wx_TextEntry, Redo);
	Gura_AssignMethod(wx_TextEntry, Remove);
	Gura_AssignMethod(wx_TextEntry, Replace);
	Gura_AssignMethod(wx_TextEntry, SetEditable);
	Gura_AssignMethod(wx_TextEntry, SetInsertionPoint);
	Gura_AssignMethod(wx_TextEntry, SetInsertionPointEnd);
	Gura_AssignMethod(wx_TextEntry, SetMaxLength);
	Gura_AssignMethod(wx_TextEntry, SetSelection);
	Gura_AssignMethod(wx_TextEntry, SelectAll);
	Gura_AssignMethod(wx_TextEntry, SelectNone);
	Gura_AssignMethod(wx_TextEntry, SetHint);
	Gura_AssignMethod(wx_TextEntry, GetHint);
	Gura_AssignMethod(wx_TextEntry, SetMargins);
	Gura_AssignMethod(wx_TextEntry, SetMargins_1);
	Gura_AssignMethod(wx_TextEntry, GetMargins);
	Gura_AssignMethod(wx_TextEntry, SetValue);
	Gura_AssignMethod(wx_TextEntry, Undo);
	Gura_AssignMethod(wx_TextEntry, WriteText);
}

Gura_ImplementDescendantCreator(wx_TextEntry)
{
	return new Object_wx_TextEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
