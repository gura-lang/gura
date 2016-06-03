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
Gura_DeclareMethodAlias(wx_TextEntry, __AppendText, "AppendText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __AppendText)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AppendText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __AutoComplete, "AutoComplete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __AutoComplete)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int choices = arg.GetNumber(0)
	//pThis->GetEntity()->AutoComplete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __AutoComplete_1, "AutoComplete_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "completer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __AutoComplete_1)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int completer = arg.GetNumber(0)
	//pThis->GetEntity()->AutoComplete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __AutoCompleteFileNames, "AutoCompleteFileNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __AutoCompleteFileNames)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompleteFileNames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __AutoCompleteDirectories, "AutoCompleteDirectories")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __AutoCompleteDirectories)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompleteDirectories();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __CanCopy, "CanCopy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __CanCopy)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCopy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __CanCut, "CanCut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __CanCut)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __CanPaste, "CanPaste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __CanPaste)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __CanRedo, "CanRedo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __CanRedo)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __CanUndo, "CanUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __CanUndo)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __ChangeValue, "ChangeValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __ChangeValue)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __Clear)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __Copy)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __Cut, "Cut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __Cut)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __ForceUpper, "ForceUpper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __ForceUpper)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ForceUpper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __GetInsertionPoint, "GetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __GetInsertionPoint)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __GetLastPosition, "GetLastPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __GetLastPosition)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __GetRange)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __GetSelection)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __GetStringSelection, "GetStringSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __GetStringSelection)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __GetValue)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __IsEditable, "IsEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __IsEditable)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __IsEmpty)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __Paste, "Paste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __Paste)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __Redo, "Redo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __Redo)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __Remove)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __Replace)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetEditable, "SetEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __SetEditable)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int editable = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetInsertionPoint, "SetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __SetInsertionPoint)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetInsertionPointEnd, "SetInsertionPointEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __SetInsertionPointEnd)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetMaxLength, "SetMaxLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __SetMaxLength)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __SetSelection)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __SelectAll)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SelectNone, "SelectNone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __SelectNone)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectNone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetHint, "SetHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __SetHint)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hint = arg.GetNumber(0)
	//pThis->GetEntity()->SetHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __GetHint, "GetHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __GetHint)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __SetMargins)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetMargins_1, "SetMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __SetMargins_1)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int top = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __GetMargins, "GetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __GetMargins)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __SetValue)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __Undo, "Undo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntry, __Undo)
{
	Object_wx_TextEntry *pThis = Object_wx_TextEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntry, __WriteText, "WriteText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntry, __WriteText)
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
	// Class assignment
	Gura_AssignValueEx("TextEntry", Reference());
	// Method assignment
	Gura_AssignMethod(wx_TextEntry, __AppendText);
	Gura_AssignMethod(wx_TextEntry, __AutoComplete);
	Gura_AssignMethod(wx_TextEntry, __AutoComplete_1);
	Gura_AssignMethod(wx_TextEntry, __AutoCompleteFileNames);
	Gura_AssignMethod(wx_TextEntry, __AutoCompleteDirectories);
	Gura_AssignMethod(wx_TextEntry, __CanCopy);
	Gura_AssignMethod(wx_TextEntry, __CanCut);
	Gura_AssignMethod(wx_TextEntry, __CanPaste);
	Gura_AssignMethod(wx_TextEntry, __CanRedo);
	Gura_AssignMethod(wx_TextEntry, __CanUndo);
	Gura_AssignMethod(wx_TextEntry, __ChangeValue);
	Gura_AssignMethod(wx_TextEntry, __Clear);
	Gura_AssignMethod(wx_TextEntry, __Copy);
	Gura_AssignMethod(wx_TextEntry, __Cut);
	Gura_AssignMethod(wx_TextEntry, __ForceUpper);
	Gura_AssignMethod(wx_TextEntry, __GetInsertionPoint);
	Gura_AssignMethod(wx_TextEntry, __GetLastPosition);
	Gura_AssignMethod(wx_TextEntry, __GetRange);
	Gura_AssignMethod(wx_TextEntry, __GetSelection);
	Gura_AssignMethod(wx_TextEntry, __GetStringSelection);
	Gura_AssignMethod(wx_TextEntry, __GetValue);
	Gura_AssignMethod(wx_TextEntry, __IsEditable);
	Gura_AssignMethod(wx_TextEntry, __IsEmpty);
	Gura_AssignMethod(wx_TextEntry, __Paste);
	Gura_AssignMethod(wx_TextEntry, __Redo);
	Gura_AssignMethod(wx_TextEntry, __Remove);
	Gura_AssignMethod(wx_TextEntry, __Replace);
	Gura_AssignMethod(wx_TextEntry, __SetEditable);
	Gura_AssignMethod(wx_TextEntry, __SetInsertionPoint);
	Gura_AssignMethod(wx_TextEntry, __SetInsertionPointEnd);
	Gura_AssignMethod(wx_TextEntry, __SetMaxLength);
	Gura_AssignMethod(wx_TextEntry, __SetSelection);
	Gura_AssignMethod(wx_TextEntry, __SelectAll);
	Gura_AssignMethod(wx_TextEntry, __SelectNone);
	Gura_AssignMethod(wx_TextEntry, __SetHint);
	Gura_AssignMethod(wx_TextEntry, __GetHint);
	Gura_AssignMethod(wx_TextEntry, __SetMargins);
	Gura_AssignMethod(wx_TextEntry, __SetMargins_1);
	Gura_AssignMethod(wx_TextEntry, __GetMargins);
	Gura_AssignMethod(wx_TextEntry, __SetValue);
	Gura_AssignMethod(wx_TextEntry, __Undo);
	Gura_AssignMethod(wx_TextEntry, __WriteText);
}

Gura_ImplementDescendantCreator(wx_TextEntry)
{
	return new Object_wx_TextEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
