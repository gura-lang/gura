//----------------------------------------------------------------------------
// wxRichTextCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCtrl
//----------------------------------------------------------------------------
Object_wx_RichTextCtrl::~Object_wx_RichTextCtrl()
{
}

Object *Object_wx_RichTextCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCtrl:");
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
Gura_DeclareFunctionAlias(__RichTextCtrl, "RichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextCtrl)
{
	//wxRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextCtrl_1, "RichTextCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//wxRichTextCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Create)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Init)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetLineLength, "GetLineLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetLineLength)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineNo = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetLineText, "GetLineText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetLineText)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineNo = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetNumberOfLines, "GetNumberOfLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetNumberOfLines)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberOfLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsModified, "IsModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsModified)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsEditable, "IsEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsEditable)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsSingleLine, "IsSingleLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsSingleLine)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSingleLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsMultiLine, "IsMultiLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsMultiLine)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMultiLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetSelection_1, "GetSelection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetSelection_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetSelection_2, "GetSelection_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetSelection_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetStringSelection, "GetStringSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetStringSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetFilename, "GetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetFilename)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetFilename, "SetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetFilename)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDelayedLayoutThreshold, "SetDelayedLayoutThreshold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDelayedLayoutThreshold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int threshold = arg.GetNumber(0)
	//pThis->GetEntity()->SetDelayedLayoutThreshold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDelayedLayoutThreshold, "GetDelayedLayoutThreshold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDelayedLayoutThreshold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedLayoutThreshold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetFullLayoutRequired, "GetFullLayoutRequired")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetFullLayoutRequired)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFullLayoutRequired();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetFullLayoutRequired, "SetFullLayoutRequired")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetFullLayoutRequired)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetFullLayoutRequired();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetFullLayoutTime, "GetFullLayoutTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetFullLayoutTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFullLayoutTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetFullLayoutTime, "SetFullLayoutTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetFullLayoutTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->SetFullLayoutTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetFullLayoutSavedPosition, "GetFullLayoutSavedPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetFullLayoutSavedPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFullLayoutSavedPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetFullLayoutSavedPosition, "SetFullLayoutSavedPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetFullLayoutSavedPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetFullLayoutSavedPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ForceDelayedLayout, "ForceDelayedLayout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ForceDelayedLayout)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ForceDelayedLayout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetTextCursor, "SetTextCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetTextCursor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetTextCursor, "GetTextCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetTextCursor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetURLCursor, "SetURLCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetURLCursor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//pThis->GetEntity()->SetURLCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetURLCursor, "GetURLCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetURLCursor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURLCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetCaretAtLineStart, "GetCaretAtLineStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetCaretAtLineStart)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretAtLineStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetCaretAtLineStart, "SetCaretAtLineStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "atStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetCaretAtLineStart)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int atStart = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretAtLineStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDragging, "GetDragging")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDragging)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragging();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDragging, "SetDragging")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dragging", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDragging)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dragging = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragging();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetPreDrag, "GetPreDrag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetPreDrag)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPreDrag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetPreDrag, "SetPreDrag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetPreDrag)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pd = arg.GetNumber(0)
	//pThis->GetEntity()->SetPreDrag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDragStartPoint, "GetDragStartPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDragStartPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragStartPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDragStartPoint, "SetDragStartPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDragStartPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sp = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragStartPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDragStartTime, "GetDragStartTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDragStartTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragStartTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDragStartTime, "SetDragStartTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "st", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDragStartTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int st = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragStartTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetBufferBitmap, "GetBufferBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetBufferBitmap)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBufferBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetBufferBitmap_1, "GetBufferBitmap_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetBufferBitmap_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBufferBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetContextMenu, "GetContextMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContextMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetContextMenu, "SetContextMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetContextMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetSelectionAnchor, "GetSelectionAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetSelectionAnchor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetSelectionAnchor, "SetSelectionAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetSelectionAnchor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int anchor = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetSelectionAnchorObject, "GetSelectionAnchorObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetSelectionAnchorObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionAnchorObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetSelectionAnchorObject, "SetSelectionAnchorObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetSelectionAnchorObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int anchor = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionAnchorObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetContextMenuPropertiesInfo, "GetContextMenuPropertiesInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetContextMenuPropertiesInfo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContextMenuPropertiesInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetContextMenuPropertiesInfo_1, "GetContextMenuPropertiesInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetContextMenuPropertiesInfo_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContextMenuPropertiesInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetFocusObject, "GetFocusObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetFocusObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFocusObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __StoreFocusObject, "StoreFocusObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __StoreFocusObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->StoreFocusObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetFocusObject, "SetFocusObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "setCaretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetFocusObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int setCaretPosition = arg.GetNumber(1)
	//pThis->GetEntity()->SetFocusObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Invalidate, "Invalidate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Invalidate)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Invalidate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Clear)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Replace)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Remove)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __LoadFile)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoLoadFile, "DoLoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoLoadFile)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int fileType = arg.GetNumber(1)
	//pThis->GetEntity()->DoLoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SaveFile, "SaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SaveFile)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoSaveFile, "DoSaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoSaveFile)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int fileType = arg.GetNumber(1)
	//pThis->GetEntity()->DoSaveFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetHandlerFlags, "SetHandlerFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetHandlerFlags)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetHandlerFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetHandlerFlags, "GetHandlerFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetHandlerFlags)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHandlerFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MarkDirty, "MarkDirty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MarkDirty)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarkDirty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DiscardEdits, "DiscardEdits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DiscardEdits)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DiscardEdits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetModified, "SetModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetModified)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int modified = arg.GetNumber(0)
	//pThis->GetEntity()->SetModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetMaxLength, "SetMaxLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetMaxLength)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WriteText, "WriteText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WriteText)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->WriteText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __AppendText, "AppendText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __AppendText)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AppendText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetStyle_1, "GetStyle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetStyle_2, "GetStyle_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetStyle_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetStyle_1, "SetStyle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetStyle_2, "SetStyle_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetStyle_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetStyle_3, "SetStyle_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetStyle_3)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetStyle_4, "SetStyle_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetStyle_4)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int textAttr = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetStyleForRange, "GetStyleForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetStyleForRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyleForRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetStyleForRange_1, "GetStyleForRange_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetStyleForRange_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyleForRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetStyleForRange_2, "GetStyleForRange_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetStyleForRange_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->GetStyleForRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetStyleEx, "SetStyleEx")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetStyleEx)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyleEx();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetUncombinedStyle, "GetUncombinedStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetUncombinedStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetUncombinedStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetUncombinedStyle_1, "GetUncombinedStyle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetUncombinedStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->GetUncombinedStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDefaultStyle, "SetDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDefaultStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDefaultStyle_1, "SetDefaultStyle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDefaultStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDefaultStyleEx, "GetDefaultStyleEx")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDefaultStyleEx)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultStyleEx();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetListStyle, "SetListStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetListStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int def = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->SetListStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetListStyle_1, "SetListStyle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetListStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int defName = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->SetListStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ClearListStyle, "ClearListStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ClearListStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->ClearListStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __NumberList, "NumberList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __NumberList)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int def = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->NumberList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __NumberList_1, "NumberList_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __NumberList_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int defName = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int startFrom = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->NumberList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PromoteList, "PromoteList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PromoteList)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int promoteBy = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//int def = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->PromoteList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PromoteList_1, "PromoteList_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PromoteList_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int promoteBy = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//int defName = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int specifiedLevel = arg.GetNumber(4)
	//pThis->GetEntity()->PromoteList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetProperties, "SetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int properties = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Delete, "Delete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Delete)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __XYToPosition, "XYToPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __XYToPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->XYToPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PositionToXY, "PositionToXY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PositionToXY)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->PositionToXY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ShowPosition, "ShowPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ShowPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __HitTest)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __HitTest_1, "HitTest_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __HitTest_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int row = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __FindContainerAtPoint, "FindContainerAtPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hit", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hitObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __FindContainerAtPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//int hit = arg.GetNumber(2)
	//int hitObj = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->FindContainerAtPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Copy)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Cut, "Cut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Cut)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Paste, "Paste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Paste)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DeleteSelection, "DeleteSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DeleteSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanCopy, "CanCopy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanCopy)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCopy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanCut, "CanCut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanCut)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanPaste, "CanPaste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanPaste)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanDeleteSelection, "CanDeleteSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanDeleteSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanDeleteSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Undo, "Undo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Undo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Redo, "Redo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Redo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanUndo, "CanUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanRedo, "CanRedo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanRedo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetInsertionPoint, "SetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetInsertionPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetInsertionPointEnd, "SetInsertionPointEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetInsertionPointEnd)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetInsertionPoint, "GetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetInsertionPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetLastPosition, "GetLastPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetLastPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetSelection_1, "SetSelection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetSelection_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SelectAll)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetEditable, "SetEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetEditable)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int editable = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __HasSelection, "HasSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __HasSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __HasUnfocusedSelection, "HasUnfocusedSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __HasUnfocusedSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasUnfocusedSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WriteImage, "WriteImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WriteImage)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int bitmapType = arg.GetNumber(1)
	//int textAttr = arg.GetNumber(2)
	//pThis->GetEntity()->WriteImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WriteImage_1, "WriteImage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WriteImage_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int bitmapType = arg.GetNumber(1)
	//int textAttr = arg.GetNumber(2)
	//pThis->GetEntity()->WriteImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WriteImage_2, "WriteImage_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WriteImage_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int bitmapType = arg.GetNumber(1)
	//int textAttr = arg.GetNumber(2)
	//pThis->GetEntity()->WriteImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WriteImage_3, "WriteImage_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageBlock", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WriteImage_3)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageBlock = arg.GetNumber(0)
	//int textAttr = arg.GetNumber(1)
	//pThis->GetEntity()->WriteImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WriteTextBox, "WriteTextBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WriteTextBox)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int textAttr = arg.GetNumber(0)
	//pThis->GetEntity()->WriteTextBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WriteField, "WriteField")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WriteField)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//int properties = arg.GetNumber(1)
	//int textAttr = arg.GetNumber(2)
	//pThis->GetEntity()->WriteField();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WriteTable, "WriteTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tableAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cellAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WriteTable)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//int tableAttr = arg.GetNumber(2)
	//int cellAttr = arg.GetNumber(3)
	//pThis->GetEntity()->WriteTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Newline, "Newline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Newline)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Newline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __LineBreak, "LineBreak")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __LineBreak)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineBreak();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetBasicStyle, "SetBasicStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetBasicStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetBasicStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetBasicStyle, "GetBasicStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetBasicStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBasicStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginStyle, "BeginStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->BeginStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndStyle, "EndStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndAllStyles, "EndAllStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndAllStyles)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndAllStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginBold, "BeginBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginBold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndBold, "EndBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndBold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginItalic, "BeginItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginItalic)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndItalic, "EndItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndItalic)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginUnderline, "BeginUnderline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginUnderline)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginUnderline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndUnderline, "EndUnderline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndUnderline)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndUnderline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginFontSize, "BeginFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginFontSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->BeginFontSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndFontSize, "EndFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndFontSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndFontSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginFont, "BeginFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginFont)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->BeginFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndFont, "EndFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndFont)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginTextColour, "BeginTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginTextColour)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->BeginTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndTextColour, "EndTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndTextColour)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginAlignment, "BeginAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginAlignment)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->BeginAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndAlignment, "EndAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndAlignment)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginLeftIndent, "BeginLeftIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginLeftIndent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int leftIndent = arg.GetNumber(0)
	//int leftSubIndent = arg.GetNumber(1)
	//pThis->GetEntity()->BeginLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndLeftIndent, "EndLeftIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndLeftIndent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginRightIndent, "BeginRightIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rightIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginRightIndent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rightIndent = arg.GetNumber(0)
	//pThis->GetEntity()->BeginRightIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndRightIndent, "EndRightIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndRightIndent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndRightIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginParagraphSpacing, "BeginParagraphSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "after", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginParagraphSpacing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//int after = arg.GetNumber(1)
	//pThis->GetEntity()->BeginParagraphSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndParagraphSpacing, "EndParagraphSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndParagraphSpacing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndParagraphSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginLineSpacing, "BeginLineSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineSpacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginLineSpacing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineSpacing = arg.GetNumber(0)
	//pThis->GetEntity()->BeginLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndLineSpacing, "EndLineSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndLineSpacing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginNumberedBullet, "BeginNumberedBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginNumberedBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bulletNumber = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginNumberedBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndNumberedBullet, "EndNumberedBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndNumberedBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndNumberedBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginSymbolBullet, "BeginSymbolBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginSymbolBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int symbol = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginSymbolBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndSymbolBullet, "EndSymbolBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndSymbolBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndSymbolBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginStandardBullet, "BeginStandardBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginStandardBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bulletName = arg.GetNumber(0)
	//int leftIndent = arg.GetNumber(1)
	//int leftSubIndent = arg.GetNumber(2)
	//int bulletStyle = arg.GetNumber(3)
	//pThis->GetEntity()->BeginStandardBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndStandardBullet, "EndStandardBullet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndStandardBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndStandardBullet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginCharacterStyle, "BeginCharacterStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginCharacterStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characterStyle = arg.GetNumber(0)
	//pThis->GetEntity()->BeginCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndCharacterStyle, "EndCharacterStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndCharacterStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginParagraphStyle, "BeginParagraphStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraphStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginParagraphStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraphStyle = arg.GetNumber(0)
	//pThis->GetEntity()->BeginParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndParagraphStyle, "EndParagraphStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndParagraphStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginListStyle, "BeginListStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginListStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int listStyle = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int number = arg.GetNumber(2)
	//pThis->GetEntity()->BeginListStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndListStyle, "EndListStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndListStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndListStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginURL, "BeginURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "characterStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginURL)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//int characterStyle = arg.GetNumber(1)
	//pThis->GetEntity()->BeginURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndURL, "EndURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndURL)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDefaultStyleToCursorStyle, "SetDefaultStyleToCursorStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDefaultStyleToCursorStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetDefaultStyleToCursorStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SelectNone, "SelectNone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SelectNone)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectNone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SelectWord, "SelectWord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SelectWord)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->SelectWord();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetSelectionRange, "GetSelectionRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetSelectionRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetSelectionRange, "SetSelectionRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetSelectionRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetInternalSelectionRange, "GetInternalSelectionRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetInternalSelectionRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalSelectionRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetInternalSelectionRange, "SetInternalSelectionRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetInternalSelectionRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetInternalSelectionRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __AddParagraph, "AddParagraph")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __AddParagraph)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AddParagraph();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __AddImage, "AddImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __AddImage)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->AddImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __LayoutContent, "LayoutContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "onlyVisibleRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __LayoutContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int onlyVisibleRect = arg.GetNumber(0)
	//pThis->GetEntity()->LayoutContent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoLayoutBuffer, "DoLayoutBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoLayoutBuffer)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int context = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//int parentRect = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->DoLayoutBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveCaret, "MoveCaret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showAtLineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveCaret)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int showAtLineStart = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->MoveCaret();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveRight, "MoveRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveRight)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPositions = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->MoveRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveLeft, "MoveLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveLeft)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPositions = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->MoveLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveUp, "MoveUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noLines", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveUp)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noLines = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->MoveUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveDown, "MoveDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noLines", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveDown)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noLines = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->MoveDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveToLineEnd, "MoveToLineEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveToLineEnd)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToLineEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveToLineStart, "MoveToLineStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveToLineStart)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToLineStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveToParagraphEnd, "MoveToParagraphEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveToParagraphEnd)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToParagraphEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveToParagraphStart, "MoveToParagraphStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveToParagraphStart)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToParagraphStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveHome, "MoveHome")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveHome)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveHome();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveEnd, "MoveEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveEnd)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PageUp, "PageUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PageUp)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPages = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->PageUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PageDown, "PageDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PageDown)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPages = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->PageDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WordLeft, "WordLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WordLeft)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPages = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->WordLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __WordRight, "WordRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __WordRight)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPages = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->WordRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetBuffer, "GetBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetBuffer)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetBuffer_1, "GetBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetBuffer_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginBatchUndo, "BeginBatchUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmdName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginBatchUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmdName = arg.GetNumber(0)
	//pThis->GetEntity()->BeginBatchUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndBatchUndo, "EndBatchUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndBatchUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndBatchUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BatchingUndo, "BatchingUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BatchingUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BatchingUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __BeginSuppressUndo, "BeginSuppressUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __BeginSuppressUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginSuppressUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EndSuppressUndo, "EndSuppressUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EndSuppressUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndSuppressUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SuppressingUndo, "SuppressingUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SuppressingUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SuppressingUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __HasCharacterAttributes, "HasCharacterAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __HasCharacterAttributes)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->HasCharacterAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __HasParagraphAttributes, "HasParagraphAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __HasParagraphAttributes)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->HasParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsSelectionBold, "IsSelectionBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsSelectionBold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSelectionBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsSelectionItalics, "IsSelectionItalics")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsSelectionItalics)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSelectionItalics();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsSelectionUnderlined, "IsSelectionUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsSelectionUnderlined)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSelectionUnderlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoesSelectionHaveTextEffectFlag, "DoesSelectionHaveTextEffectFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoesSelectionHaveTextEffectFlag)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->DoesSelectionHaveTextEffectFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsSelectionAligned, "IsSelectionAligned")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsSelectionAligned)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelectionAligned();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ApplyBoldToSelection, "ApplyBoldToSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ApplyBoldToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ApplyBoldToSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ApplyItalicToSelection, "ApplyItalicToSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ApplyItalicToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ApplyItalicToSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ApplyUnderlineToSelection, "ApplyUnderlineToSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ApplyUnderlineToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ApplyUnderlineToSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ApplyTextEffectToSelection, "ApplyTextEffectToSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ApplyTextEffectToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyTextEffectToSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ApplyAlignmentToSelection, "ApplyAlignmentToSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ApplyAlignmentToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyAlignmentToSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ApplyStyle, "ApplyStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ApplyStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetStyleSheet, "SetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetStyleSheet, "GetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PushStyleSheet, "PushStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PushStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->PushStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PopStyleSheet, "PopStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PopStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PopStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ApplyStyleSheet, "ApplyStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ApplyStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ShowContextMenu, "ShowContextMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "addPropertyCommands", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ShowContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int addPropertyCommands = arg.GetNumber(2)
	//pThis->GetEntity()->ShowContextMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PrepareContextMenu, "PrepareContextMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "addPropertyCommands", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PrepareContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int addPropertyCommands = arg.GetNumber(2)
	//pThis->GetEntity()->PrepareContextMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanEditProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EditProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PrepareContent, "PrepareContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PrepareContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->PrepareContent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanDeleteRange, "CanDeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanDeleteRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//pThis->GetEntity()->CanDeleteRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __CanInsertContent, "CanInsertContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __CanInsertContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->CanInsertContent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EnableVerticalScrollbar, "EnableVerticalScrollbar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EnableVerticalScrollbar)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableVerticalScrollbar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetVerticalScrollbarEnabled, "GetVerticalScrollbarEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetVerticalScrollbarEnabled)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVerticalScrollbarEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetFontScale, "SetFontScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetFontScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fontScale = arg.GetNumber(0)
	//int refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetFontScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetFontScale, "GetFontScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetFontScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDimensionScale, "SetDimensionScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dimScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDimensionScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dimScale = arg.GetNumber(0)
	//int refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetDimensionScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDimensionScale, "GetDimensionScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDimensionScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDimensionScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetScale, "SetScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int scale = arg.GetNumber(0)
	//int refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetScale, "GetScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetUnscaledPoint, "GetUnscaledPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetUnscaledPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetUnscaledPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetScaledPoint, "GetScaledPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetScaledPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetScaledPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetUnscaledSize, "GetUnscaledSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetUnscaledSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->GetUnscaledSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetScaledSize, "GetScaledSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetScaledSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->GetScaledSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetUnscaledRect, "GetUnscaledRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetUnscaledRect)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->GetUnscaledRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetScaledRect, "GetScaledRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetScaledRect)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->GetScaledRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetVirtualAttributesEnabled, "GetVirtualAttributesEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetVirtualAttributesEnabled)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVirtualAttributesEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EnableVirtualAttributes, "EnableVirtualAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EnableVirtualAttributes)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableVirtualAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __Command, "Command")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __Command)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->Command();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnDropFiles, "OnDropFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnDropFiles)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnDropFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnCaptureLost, "OnCaptureLost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnCaptureLost)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCaptureLost();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnSysColourChanged, "OnSysColourChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnSysColourChanged)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSysColourChanged();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnCut, "OnCut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnCut)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnCopy, "OnCopy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnCopy)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCopy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnPaste, "OnPaste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnPaste)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnPaste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUndo, "OnUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnRedo, "OnRedo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnRedo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnRedo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnSelectAll, "OnSelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnSelectAll)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnProperties, "OnProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnClear, "OnClear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnClear)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnClear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUpdateCut, "OnUpdateCut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUpdateCut)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateCut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUpdateCopy, "OnUpdateCopy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUpdateCopy)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateCopy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUpdatePaste, "OnUpdatePaste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUpdatePaste)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdatePaste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUpdateUndo, "OnUpdateUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUpdateUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUpdateRedo, "OnUpdateRedo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUpdateRedo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateRedo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUpdateSelectAll, "OnUpdateSelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUpdateSelectAll)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateSelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUpdateProperties, "OnUpdateProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUpdateProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnUpdateClear, "OnUpdateClear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnUpdateClear)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateClear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnContextMenu, "OnContextMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnContextMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnPaint, "OnPaint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnPaint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnPaint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnEraseBackground, "OnEraseBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnEraseBackground)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnEraseBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnLeftClick, "OnLeftClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnLeftClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnLeftClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnLeftUp, "OnLeftUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnLeftUp)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnLeftUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnMoveMouse, "OnMoveMouse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnMoveMouse)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnMoveMouse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnLeftDClick, "OnLeftDClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnLeftDClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnLeftDClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnMiddleClick, "OnMiddleClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnMiddleClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnMiddleClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnRightClick, "OnRightClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnRightClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnRightClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnChar, "OnChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnChar)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnSize, "OnSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnSetFocus, "OnSetFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnSetFocus)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSetFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnKillFocus, "OnKillFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnKillFocus)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnKillFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnIdle, "OnIdle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnIdle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnIdle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnScroll, "OnScroll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnScroll)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnScroll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetFont)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetupScrollbars, "SetupScrollbars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "atTop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetupScrollbars)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int atTop = arg.GetNumber(0)
	//pThis->GetEntity()->SetupScrollbars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __KeyboardNavigate, "KeyboardNavigate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __KeyboardNavigate)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keyCode = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->KeyboardNavigate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PaintBackground, "PaintBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PaintBackground)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->PaintBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __RecreateBuffer, "RecreateBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __RecreateBuffer)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->RecreateBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoWriteText, "DoWriteText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoWriteText)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->DoWriteText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ShouldInheritColours, "ShouldInheritColours")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ShouldInheritColours)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShouldInheritColours();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __PositionCaret, "PositionCaret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __PositionCaret)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->PositionCaret();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ExtendSelection, "ExtendSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ExtendSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldPosition = arg.GetNumber(0)
	//int newPosition = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->ExtendSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ExtendCellSelection, "ExtendCellSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noRowSteps", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noColSteps", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ExtendCellSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//int noRowSteps = arg.GetNumber(1)
	//int noColSteps = arg.GetNumber(2)
	//pThis->GetEntity()->ExtendCellSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __StartCellSelection, "StartCellSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newCell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __StartCellSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//int newCell = arg.GetNumber(1)
	//pThis->GetEntity()->StartCellSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ScrollIntoView, "ScrollIntoView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ScrollIntoView)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int keyCode = arg.GetNumber(1)
	//pThis->GetEntity()->ScrollIntoView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __RefreshForSelectionChange, "RefreshForSelectionChange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldSelection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __RefreshForSelectionChange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldSelection = arg.GetNumber(0)
	//int newSelection = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshForSelectionChange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetCaretPosition, "SetCaretPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showAtLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetCaretPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int showAtLineStart = arg.GetNumber(1)
	//pThis->GetEntity()->SetCaretPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetCaretPosition, "GetCaretPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetCaretPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetAdjustedCaretPosition, "GetAdjustedCaretPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetAdjustedCaretPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPos = arg.GetNumber(0)
	//pThis->GetEntity()->GetAdjustedCaretPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveCaretForward, "MoveCaretForward")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveCaretForward)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldPosition = arg.GetNumber(0)
	//pThis->GetEntity()->MoveCaretForward();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __MoveCaretBack, "MoveCaretBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __MoveCaretBack)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldPosition = arg.GetNumber(0)
	//pThis->GetEntity()->MoveCaretBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetCaretPositionForIndex, "GetCaretPositionForIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetCaretPositionForIndex)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->GetCaretPositionForIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetVisibleLineForCaretPosition, "GetVisibleLineForCaretPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetVisibleLineForCaretPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPosition = arg.GetNumber(0)
	//pThis->GetEntity()->GetVisibleLineForCaretPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetCommandProcessor, "GetCommandProcessor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetCommandProcessor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DeleteSelectedContent, "DeleteSelectedContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DeleteSelectedContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newPos = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteSelectedContent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetPhysicalPoint, "GetPhysicalPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptLogical", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetPhysicalPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptLogical = arg.GetNumber(0)
	//pThis->GetEntity()->GetPhysicalPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetLogicalPoint, "GetLogicalPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptPhysical", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetLogicalPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptPhysical = arg.GetNumber(0)
	//pThis->GetEntity()->GetLogicalPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __FindNextWordPosition, "FindNextWordPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __FindNextWordPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->FindNextWordPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsPositionVisible, "IsPositionVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsPositionVisible)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->IsPositionVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetFirstVisiblePosition, "GetFirstVisiblePosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetFirstVisiblePosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstVisiblePosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EnableImages, "EnableImages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EnableImages)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableImages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetImagesEnabled, "GetImagesEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetImagesEnabled)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImagesEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __EnableDelayedImageLoading, "EnableDelayedImageLoading")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __EnableDelayedImageLoading)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDelayedImageLoading, "GetDelayedImageLoading")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDelayedImageLoading)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDelayedImageProcessingRequired, "GetDelayedImageProcessingRequired")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDelayedImageProcessingRequired)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedImageProcessingRequired();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDelayedImageProcessingRequired, "SetDelayedImageProcessingRequired")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDelayedImageProcessingRequired)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetDelayedImageProcessingRequired();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetDelayedImageProcessingTime, "GetDelayedImageProcessingTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetDelayedImageProcessingTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedImageProcessingTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetDelayedImageProcessingTime, "SetDelayedImageProcessingTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetDelayedImageProcessingTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->SetDelayedImageProcessingTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetCaretPositionForDefaultStyle, "GetCaretPositionForDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetCaretPositionForDefaultStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretPositionForDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetCaretPositionForDefaultStyle, "SetCaretPositionForDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetCaretPositionForDefaultStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretPositionForDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __IsDefaultStyleShowing, "IsDefaultStyleShowing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __IsDefaultStyleShowing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDefaultStyleShowing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetAndShowDefaultStyle, "SetAndShowDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetAndShowDefaultStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetAndShowDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetFirstVisiblePoint, "GetFirstVisiblePoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetFirstVisiblePoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstVisiblePoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetValue)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetValue)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ProcessBackKey, "ProcessBackKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ProcessBackKey)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->ProcessBackKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __FindRangeForList, "FindRangeForList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isNumberedList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __FindRangeForList)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int isNumberedList = arg.GetNumber(1)
	//pThis->GetEntity()->FindRangeForList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __SetCaretPositionAfterClick, "SetCaretPositionAfterClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hitTestFlags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "extendSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __SetCaretPositionAfterClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//int hitTestFlags = arg.GetNumber(2)
	//int extendSelection = arg.GetNumber(3)
	//pThis->GetEntity()->SetCaretPositionAfterClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __FindCaretPositionForCharacterPosition, "FindCaretPositionForCharacterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hitTestFlags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __FindCaretPositionForCharacterPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int hitTestFlags = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//int caretLineStart = arg.GetNumber(3)
	//pThis->GetEntity()->FindCaretPositionForCharacterPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ProcessMouseMovement, "ProcessMouseMovement")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ProcessMouseMovement)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//int position = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//pThis->GetEntity()->ProcessMouseMovement();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetAvailableFontNames, "GetAvailableFontNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetAvailableFontNames)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAvailableFontNames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ClearAvailableFontNames, "ClearAvailableFontNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ClearAvailableFontNames)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearAvailableFontNames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoGetValue, "DoGetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoGetValue)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ProcessDelayedImageLoading, "ProcessDelayedImageLoading")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ProcessDelayedImageLoading)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int refresh = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __ProcessDelayedImageLoading_1, "ProcessDelayedImageLoading_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "screenRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "box", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "loadCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __ProcessDelayedImageLoading_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int screenRect = arg.GetNumber(0)
	//int box = arg.GetNumber(1)
	//int loadCount = arg.GetNumber(2)
	//pThis->GetEntity()->ProcessDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __RequestDelayedImageProcessing, "RequestDelayedImageProcessing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __RequestDelayedImageProcessing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RequestDelayedImageProcessing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __OnTimer, "OnTimer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __OnTimer)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnTimer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __GetEditableWindow, "GetEditableWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __GetEditableWindow)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditableWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoSetMargins, "DoSetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoSetMargins)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->DoSetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoGetMargins, "DoGetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoGetMargins)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoGetBestSize, "DoGetBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoGetBestSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoSetValue, "DoSetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoSetValue)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->DoSetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextCtrl, __DoThaw, "DoThaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, __DoThaw)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoThaw();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextCtrl);
	Gura_AssignFunction(__RichTextCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextCtrl, __Create);
	Gura_AssignMethod(wx_RichTextCtrl, __Init);
	Gura_AssignMethod(wx_RichTextCtrl, __GetRange);
	Gura_AssignMethod(wx_RichTextCtrl, __GetLineLength);
	Gura_AssignMethod(wx_RichTextCtrl, __GetLineText);
	Gura_AssignMethod(wx_RichTextCtrl, __GetNumberOfLines);
	Gura_AssignMethod(wx_RichTextCtrl, __IsModified);
	Gura_AssignMethod(wx_RichTextCtrl, __IsEditable);
	Gura_AssignMethod(wx_RichTextCtrl, __IsSingleLine);
	Gura_AssignMethod(wx_RichTextCtrl, __IsMultiLine);
	Gura_AssignMethod(wx_RichTextCtrl, __GetSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __GetSelection_1);
	Gura_AssignMethod(wx_RichTextCtrl, __GetSelection_2);
	Gura_AssignMethod(wx_RichTextCtrl, __GetStringSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __GetFilename);
	Gura_AssignMethod(wx_RichTextCtrl, __SetFilename);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDelayedLayoutThreshold);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDelayedLayoutThreshold);
	Gura_AssignMethod(wx_RichTextCtrl, __GetFullLayoutRequired);
	Gura_AssignMethod(wx_RichTextCtrl, __SetFullLayoutRequired);
	Gura_AssignMethod(wx_RichTextCtrl, __GetFullLayoutTime);
	Gura_AssignMethod(wx_RichTextCtrl, __SetFullLayoutTime);
	Gura_AssignMethod(wx_RichTextCtrl, __GetFullLayoutSavedPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __SetFullLayoutSavedPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __ForceDelayedLayout);
	Gura_AssignMethod(wx_RichTextCtrl, __SetTextCursor);
	Gura_AssignMethod(wx_RichTextCtrl, __GetTextCursor);
	Gura_AssignMethod(wx_RichTextCtrl, __SetURLCursor);
	Gura_AssignMethod(wx_RichTextCtrl, __GetURLCursor);
	Gura_AssignMethod(wx_RichTextCtrl, __GetCaretAtLineStart);
	Gura_AssignMethod(wx_RichTextCtrl, __SetCaretAtLineStart);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDragging);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDragging);
	Gura_AssignMethod(wx_RichTextCtrl, __GetPreDrag);
	Gura_AssignMethod(wx_RichTextCtrl, __SetPreDrag);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDragStartPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDragStartPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDragStartTime);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDragStartTime);
	Gura_AssignMethod(wx_RichTextCtrl, __GetBufferBitmap);
	Gura_AssignMethod(wx_RichTextCtrl, __GetBufferBitmap_1);
	Gura_AssignMethod(wx_RichTextCtrl, __GetContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, __SetContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, __GetSelectionAnchor);
	Gura_AssignMethod(wx_RichTextCtrl, __SetSelectionAnchor);
	Gura_AssignMethod(wx_RichTextCtrl, __GetSelectionAnchorObject);
	Gura_AssignMethod(wx_RichTextCtrl, __SetSelectionAnchorObject);
	Gura_AssignMethod(wx_RichTextCtrl, __GetContextMenuPropertiesInfo);
	Gura_AssignMethod(wx_RichTextCtrl, __GetContextMenuPropertiesInfo_1);
	Gura_AssignMethod(wx_RichTextCtrl, __GetFocusObject);
	Gura_AssignMethod(wx_RichTextCtrl, __StoreFocusObject);
	Gura_AssignMethod(wx_RichTextCtrl, __SetFocusObject);
	Gura_AssignMethod(wx_RichTextCtrl, __Invalidate);
	Gura_AssignMethod(wx_RichTextCtrl, __Clear);
	Gura_AssignMethod(wx_RichTextCtrl, __Replace);
	Gura_AssignMethod(wx_RichTextCtrl, __Remove);
	Gura_AssignMethod(wx_RichTextCtrl, __LoadFile);
	Gura_AssignMethod(wx_RichTextCtrl, __DoLoadFile);
	Gura_AssignMethod(wx_RichTextCtrl, __SaveFile);
	Gura_AssignMethod(wx_RichTextCtrl, __DoSaveFile);
	Gura_AssignMethod(wx_RichTextCtrl, __SetHandlerFlags);
	Gura_AssignMethod(wx_RichTextCtrl, __GetHandlerFlags);
	Gura_AssignMethod(wx_RichTextCtrl, __MarkDirty);
	Gura_AssignMethod(wx_RichTextCtrl, __DiscardEdits);
	Gura_AssignMethod(wx_RichTextCtrl, __SetModified);
	Gura_AssignMethod(wx_RichTextCtrl, __SetMaxLength);
	Gura_AssignMethod(wx_RichTextCtrl, __WriteText);
	Gura_AssignMethod(wx_RichTextCtrl, __AppendText);
	Gura_AssignMethod(wx_RichTextCtrl, __GetStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __GetStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, __GetStyle_2);
	Gura_AssignMethod(wx_RichTextCtrl, __SetStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __SetStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, __SetStyle_2);
	Gura_AssignMethod(wx_RichTextCtrl, __SetStyle_3);
	Gura_AssignMethod(wx_RichTextCtrl, __SetStyle_4);
	Gura_AssignMethod(wx_RichTextCtrl, __GetStyleForRange);
	Gura_AssignMethod(wx_RichTextCtrl, __GetStyleForRange_1);
	Gura_AssignMethod(wx_RichTextCtrl, __GetStyleForRange_2);
	Gura_AssignMethod(wx_RichTextCtrl, __SetStyleEx);
	Gura_AssignMethod(wx_RichTextCtrl, __GetUncombinedStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __GetUncombinedStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDefaultStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDefaultStyleEx);
	Gura_AssignMethod(wx_RichTextCtrl, __SetListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __SetListStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, __ClearListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __NumberList);
	Gura_AssignMethod(wx_RichTextCtrl, __NumberList_1);
	Gura_AssignMethod(wx_RichTextCtrl, __PromoteList);
	Gura_AssignMethod(wx_RichTextCtrl, __PromoteList_1);
	Gura_AssignMethod(wx_RichTextCtrl, __SetProperties);
	Gura_AssignMethod(wx_RichTextCtrl, __Delete);
	Gura_AssignMethod(wx_RichTextCtrl, __XYToPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __PositionToXY);
	Gura_AssignMethod(wx_RichTextCtrl, __ShowPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __HitTest);
	Gura_AssignMethod(wx_RichTextCtrl, __HitTest_1);
	Gura_AssignMethod(wx_RichTextCtrl, __FindContainerAtPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __Copy);
	Gura_AssignMethod(wx_RichTextCtrl, __Cut);
	Gura_AssignMethod(wx_RichTextCtrl, __Paste);
	Gura_AssignMethod(wx_RichTextCtrl, __DeleteSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __CanCopy);
	Gura_AssignMethod(wx_RichTextCtrl, __CanCut);
	Gura_AssignMethod(wx_RichTextCtrl, __CanPaste);
	Gura_AssignMethod(wx_RichTextCtrl, __CanDeleteSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __Undo);
	Gura_AssignMethod(wx_RichTextCtrl, __Redo);
	Gura_AssignMethod(wx_RichTextCtrl, __CanUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __CanRedo);
	Gura_AssignMethod(wx_RichTextCtrl, __SetInsertionPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __SetInsertionPointEnd);
	Gura_AssignMethod(wx_RichTextCtrl, __GetInsertionPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __GetLastPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __SetSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __SetSelection_1);
	Gura_AssignMethod(wx_RichTextCtrl, __SelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, __SetEditable);
	Gura_AssignMethod(wx_RichTextCtrl, __HasSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __HasUnfocusedSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __WriteImage);
	Gura_AssignMethod(wx_RichTextCtrl, __WriteImage_1);
	Gura_AssignMethod(wx_RichTextCtrl, __WriteImage_2);
	Gura_AssignMethod(wx_RichTextCtrl, __WriteImage_3);
	Gura_AssignMethod(wx_RichTextCtrl, __WriteTextBox);
	Gura_AssignMethod(wx_RichTextCtrl, __WriteField);
	Gura_AssignMethod(wx_RichTextCtrl, __WriteTable);
	Gura_AssignMethod(wx_RichTextCtrl, __Newline);
	Gura_AssignMethod(wx_RichTextCtrl, __LineBreak);
	Gura_AssignMethod(wx_RichTextCtrl, __SetBasicStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __GetBasicStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __EndStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __EndAllStyles);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginBold);
	Gura_AssignMethod(wx_RichTextCtrl, __EndBold);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginItalic);
	Gura_AssignMethod(wx_RichTextCtrl, __EndItalic);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginUnderline);
	Gura_AssignMethod(wx_RichTextCtrl, __EndUnderline);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginFontSize);
	Gura_AssignMethod(wx_RichTextCtrl, __EndFontSize);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginFont);
	Gura_AssignMethod(wx_RichTextCtrl, __EndFont);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginTextColour);
	Gura_AssignMethod(wx_RichTextCtrl, __EndTextColour);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginAlignment);
	Gura_AssignMethod(wx_RichTextCtrl, __EndAlignment);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginLeftIndent);
	Gura_AssignMethod(wx_RichTextCtrl, __EndLeftIndent);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginRightIndent);
	Gura_AssignMethod(wx_RichTextCtrl, __EndRightIndent);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginParagraphSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, __EndParagraphSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginLineSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, __EndLineSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginNumberedBullet);
	Gura_AssignMethod(wx_RichTextCtrl, __EndNumberedBullet);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginSymbolBullet);
	Gura_AssignMethod(wx_RichTextCtrl, __EndSymbolBullet);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginStandardBullet);
	Gura_AssignMethod(wx_RichTextCtrl, __EndStandardBullet);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginCharacterStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __EndCharacterStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginParagraphStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __EndParagraphStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __EndListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginURL);
	Gura_AssignMethod(wx_RichTextCtrl, __EndURL);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDefaultStyleToCursorStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __SelectNone);
	Gura_AssignMethod(wx_RichTextCtrl, __SelectWord);
	Gura_AssignMethod(wx_RichTextCtrl, __GetSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, __SetSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, __GetInternalSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, __SetInternalSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, __AddParagraph);
	Gura_AssignMethod(wx_RichTextCtrl, __AddImage);
	Gura_AssignMethod(wx_RichTextCtrl, __LayoutContent);
	Gura_AssignMethod(wx_RichTextCtrl, __DoLayoutBuffer);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveCaret);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveRight);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveLeft);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveUp);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveDown);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveToLineEnd);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveToLineStart);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveToParagraphEnd);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveToParagraphStart);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveHome);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveEnd);
	Gura_AssignMethod(wx_RichTextCtrl, __PageUp);
	Gura_AssignMethod(wx_RichTextCtrl, __PageDown);
	Gura_AssignMethod(wx_RichTextCtrl, __WordLeft);
	Gura_AssignMethod(wx_RichTextCtrl, __WordRight);
	Gura_AssignMethod(wx_RichTextCtrl, __GetBuffer);
	Gura_AssignMethod(wx_RichTextCtrl, __GetBuffer_1);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginBatchUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __EndBatchUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __BatchingUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __BeginSuppressUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __EndSuppressUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __SuppressingUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __HasCharacterAttributes);
	Gura_AssignMethod(wx_RichTextCtrl, __HasParagraphAttributes);
	Gura_AssignMethod(wx_RichTextCtrl, __IsSelectionBold);
	Gura_AssignMethod(wx_RichTextCtrl, __IsSelectionItalics);
	Gura_AssignMethod(wx_RichTextCtrl, __IsSelectionUnderlined);
	Gura_AssignMethod(wx_RichTextCtrl, __DoesSelectionHaveTextEffectFlag);
	Gura_AssignMethod(wx_RichTextCtrl, __IsSelectionAligned);
	Gura_AssignMethod(wx_RichTextCtrl, __ApplyBoldToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __ApplyItalicToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __ApplyUnderlineToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __ApplyTextEffectToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __ApplyAlignmentToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __ApplyStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __SetStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, __GetStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, __PushStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, __PopStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, __ApplyStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, __ShowContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, __PrepareContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, __CanEditProperties);
	Gura_AssignMethod(wx_RichTextCtrl, __EditProperties);
	Gura_AssignMethod(wx_RichTextCtrl, __GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextCtrl, __PrepareContent);
	Gura_AssignMethod(wx_RichTextCtrl, __CanDeleteRange);
	Gura_AssignMethod(wx_RichTextCtrl, __CanInsertContent);
	Gura_AssignMethod(wx_RichTextCtrl, __EnableVerticalScrollbar);
	Gura_AssignMethod(wx_RichTextCtrl, __GetVerticalScrollbarEnabled);
	Gura_AssignMethod(wx_RichTextCtrl, __SetFontScale);
	Gura_AssignMethod(wx_RichTextCtrl, __GetFontScale);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDimensionScale);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDimensionScale);
	Gura_AssignMethod(wx_RichTextCtrl, __SetScale);
	Gura_AssignMethod(wx_RichTextCtrl, __GetScale);
	Gura_AssignMethod(wx_RichTextCtrl, __GetUnscaledPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __GetScaledPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __GetUnscaledSize);
	Gura_AssignMethod(wx_RichTextCtrl, __GetScaledSize);
	Gura_AssignMethod(wx_RichTextCtrl, __GetUnscaledRect);
	Gura_AssignMethod(wx_RichTextCtrl, __GetScaledRect);
	Gura_AssignMethod(wx_RichTextCtrl, __GetVirtualAttributesEnabled);
	Gura_AssignMethod(wx_RichTextCtrl, __EnableVirtualAttributes);
	Gura_AssignMethod(wx_RichTextCtrl, __Command);
	Gura_AssignMethod(wx_RichTextCtrl, __OnDropFiles);
	Gura_AssignMethod(wx_RichTextCtrl, __OnCaptureLost);
	Gura_AssignMethod(wx_RichTextCtrl, __OnSysColourChanged);
	Gura_AssignMethod(wx_RichTextCtrl, __OnCut);
	Gura_AssignMethod(wx_RichTextCtrl, __OnCopy);
	Gura_AssignMethod(wx_RichTextCtrl, __OnPaste);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __OnRedo);
	Gura_AssignMethod(wx_RichTextCtrl, __OnSelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, __OnProperties);
	Gura_AssignMethod(wx_RichTextCtrl, __OnClear);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUpdateCut);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUpdateCopy);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUpdatePaste);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUpdateUndo);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUpdateRedo);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUpdateSelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUpdateProperties);
	Gura_AssignMethod(wx_RichTextCtrl, __OnUpdateClear);
	Gura_AssignMethod(wx_RichTextCtrl, __OnContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, __OnPaint);
	Gura_AssignMethod(wx_RichTextCtrl, __OnEraseBackground);
	Gura_AssignMethod(wx_RichTextCtrl, __OnLeftClick);
	Gura_AssignMethod(wx_RichTextCtrl, __OnLeftUp);
	Gura_AssignMethod(wx_RichTextCtrl, __OnMoveMouse);
	Gura_AssignMethod(wx_RichTextCtrl, __OnLeftDClick);
	Gura_AssignMethod(wx_RichTextCtrl, __OnMiddleClick);
	Gura_AssignMethod(wx_RichTextCtrl, __OnRightClick);
	Gura_AssignMethod(wx_RichTextCtrl, __OnChar);
	Gura_AssignMethod(wx_RichTextCtrl, __OnSize);
	Gura_AssignMethod(wx_RichTextCtrl, __OnSetFocus);
	Gura_AssignMethod(wx_RichTextCtrl, __OnKillFocus);
	Gura_AssignMethod(wx_RichTextCtrl, __OnIdle);
	Gura_AssignMethod(wx_RichTextCtrl, __OnScroll);
	Gura_AssignMethod(wx_RichTextCtrl, __SetFont);
	Gura_AssignMethod(wx_RichTextCtrl, __SetupScrollbars);
	Gura_AssignMethod(wx_RichTextCtrl, __KeyboardNavigate);
	Gura_AssignMethod(wx_RichTextCtrl, __PaintBackground);
	Gura_AssignMethod(wx_RichTextCtrl, __RecreateBuffer);
	Gura_AssignMethod(wx_RichTextCtrl, __DoWriteText);
	Gura_AssignMethod(wx_RichTextCtrl, __ShouldInheritColours);
	Gura_AssignMethod(wx_RichTextCtrl, __PositionCaret);
	Gura_AssignMethod(wx_RichTextCtrl, __ExtendSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __ExtendCellSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __StartCellSelection);
	Gura_AssignMethod(wx_RichTextCtrl, __ScrollIntoView);
	Gura_AssignMethod(wx_RichTextCtrl, __RefreshForSelectionChange);
	Gura_AssignMethod(wx_RichTextCtrl, __SetCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __GetCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __GetAdjustedCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveCaretForward);
	Gura_AssignMethod(wx_RichTextCtrl, __MoveCaretBack);
	Gura_AssignMethod(wx_RichTextCtrl, __GetCaretPositionForIndex);
	Gura_AssignMethod(wx_RichTextCtrl, __GetVisibleLineForCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __GetCommandProcessor);
	Gura_AssignMethod(wx_RichTextCtrl, __DeleteSelectedContent);
	Gura_AssignMethod(wx_RichTextCtrl, __GetPhysicalPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __GetLogicalPoint);
	Gura_AssignMethod(wx_RichTextCtrl, __FindNextWordPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __IsPositionVisible);
	Gura_AssignMethod(wx_RichTextCtrl, __GetFirstVisiblePosition);
	Gura_AssignMethod(wx_RichTextCtrl, __EnableImages);
	Gura_AssignMethod(wx_RichTextCtrl, __GetImagesEnabled);
	Gura_AssignMethod(wx_RichTextCtrl, __EnableDelayedImageLoading);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDelayedImageLoading);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDelayedImageProcessingRequired);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDelayedImageProcessingRequired);
	Gura_AssignMethod(wx_RichTextCtrl, __GetDelayedImageProcessingTime);
	Gura_AssignMethod(wx_RichTextCtrl, __SetDelayedImageProcessingTime);
	Gura_AssignMethod(wx_RichTextCtrl, __GetCaretPositionForDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __SetCaretPositionForDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __IsDefaultStyleShowing);
	Gura_AssignMethod(wx_RichTextCtrl, __SetAndShowDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, __GetFirstVisiblePoint);
	Gura_AssignMethod(wx_RichTextCtrl, __GetValue);
	Gura_AssignMethod(wx_RichTextCtrl, __SetValue);
	Gura_AssignMethod(wx_RichTextCtrl, __ProcessBackKey);
	Gura_AssignMethod(wx_RichTextCtrl, __FindRangeForList);
	Gura_AssignMethod(wx_RichTextCtrl, __SetCaretPositionAfterClick);
	Gura_AssignMethod(wx_RichTextCtrl, __FindCaretPositionForCharacterPosition);
	Gura_AssignMethod(wx_RichTextCtrl, __ProcessMouseMovement);
	Gura_AssignMethod(wx_RichTextCtrl, __GetAvailableFontNames);
	Gura_AssignMethod(wx_RichTextCtrl, __ClearAvailableFontNames);
	Gura_AssignMethod(wx_RichTextCtrl, __DoGetValue);
	Gura_AssignMethod(wx_RichTextCtrl, __ProcessDelayedImageLoading);
	Gura_AssignMethod(wx_RichTextCtrl, __ProcessDelayedImageLoading_1);
	Gura_AssignMethod(wx_RichTextCtrl, __RequestDelayedImageProcessing);
	Gura_AssignMethod(wx_RichTextCtrl, __OnTimer);
	Gura_AssignMethod(wx_RichTextCtrl, __GetEditableWindow);
	Gura_AssignMethod(wx_RichTextCtrl, __DoSetMargins);
	Gura_AssignMethod(wx_RichTextCtrl, __DoGetMargins);
	Gura_AssignMethod(wx_RichTextCtrl, __DoGetBestSize);
	Gura_AssignMethod(wx_RichTextCtrl, __DoSetValue);
	Gura_AssignMethod(wx_RichTextCtrl, __DoThaw);
}

Gura_ImplementDescendantCreator(wx_RichTextCtrl)
{
	return new Object_wx_RichTextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
