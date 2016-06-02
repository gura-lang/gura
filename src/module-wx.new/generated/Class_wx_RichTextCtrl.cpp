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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextCtrl, wxRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, wxRichTextCtrl)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, wxRichTextCtrl_1)
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

Gura_ImplementMethod(wx_RichTextCtrl, wxRichTextCtrl_1)
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
	//pThis->GetEntity()->wxRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Create)
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

Gura_ImplementMethod(wx_RichTextCtrl, Create)
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

Gura_DeclareMethod(wx_RichTextCtrl, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Init)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetLineLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetLineLength)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineNo = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetLineText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetLineText)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineNo = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetNumberOfLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetNumberOfLines)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberOfLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsModified)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsEditable)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSingleLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSingleLine)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSingleLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsMultiLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsMultiLine)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMultiLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetSelection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetSelection_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetSelection_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetSelection_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStringSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFilename)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFilename)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDelayedLayoutThreshold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDelayedLayoutThreshold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int threshold = arg.GetNumber(0)
	//pThis->GetEntity()->SetDelayedLayoutThreshold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDelayedLayoutThreshold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDelayedLayoutThreshold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedLayoutThreshold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFullLayoutRequired)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFullLayoutRequired)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFullLayoutRequired();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFullLayoutRequired)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFullLayoutRequired)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetFullLayoutRequired();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFullLayoutTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFullLayoutTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFullLayoutTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFullLayoutTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFullLayoutTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->SetFullLayoutTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFullLayoutSavedPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFullLayoutSavedPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFullLayoutSavedPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFullLayoutSavedPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFullLayoutSavedPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetFullLayoutSavedPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ForceDelayedLayout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, ForceDelayedLayout)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ForceDelayedLayout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetTextCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetTextCursor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetTextCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetTextCursor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetURLCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetURLCursor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//pThis->GetEntity()->SetURLCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetURLCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetURLCursor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetURLCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetCaretAtLineStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetCaretAtLineStart)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretAtLineStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetCaretAtLineStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "atStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetCaretAtLineStart)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int atStart = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretAtLineStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDragging)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDragging)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragging();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDragging)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dragging", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDragging)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dragging = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragging();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetPreDrag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetPreDrag)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPreDrag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetPreDrag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetPreDrag)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pd = arg.GetNumber(0)
	//pThis->GetEntity()->SetPreDrag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDragStartPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDragStartPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragStartPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDragStartPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDragStartPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sp = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragStartPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDragStartTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDragStartTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDragStartTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDragStartTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "st", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDragStartTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int st = arg.GetNumber(0)
	//pThis->GetEntity()->SetDragStartTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetBufferBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetBufferBitmap)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBufferBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetBufferBitmap_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetBufferBitmap_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBufferBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetContextMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContextMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetContextMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetContextMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetSelectionAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetSelectionAnchor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetSelectionAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetSelectionAnchor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int anchor = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetSelectionAnchorObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetSelectionAnchorObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionAnchorObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetSelectionAnchorObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetSelectionAnchorObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int anchor = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionAnchorObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetContextMenuPropertiesInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetContextMenuPropertiesInfo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContextMenuPropertiesInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetContextMenuPropertiesInfo_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetContextMenuPropertiesInfo_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContextMenuPropertiesInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFocusObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFocusObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFocusObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, StoreFocusObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, StoreFocusObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->StoreFocusObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFocusObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "setCaretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFocusObject)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int setCaretPosition = arg.GetNumber(1)
	//pThis->GetEntity()->SetFocusObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Invalidate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Invalidate)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Invalidate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Clear)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, Replace)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, Remove)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, LoadFile)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoLoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoLoadFile)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int fileType = arg.GetNumber(1)
	//pThis->GetEntity()->DoLoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SaveFile)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoSaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoSaveFile)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int fileType = arg.GetNumber(1)
	//pThis->GetEntity()->DoSaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetHandlerFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetHandlerFlags)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetHandlerFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetHandlerFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetHandlerFlags)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHandlerFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MarkDirty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, MarkDirty)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarkDirty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DiscardEdits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, DiscardEdits)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DiscardEdits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetModified)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int modified = arg.GetNumber(0)
	//pThis->GetEntity()->SetModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetMaxLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetMaxLength)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteText)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->WriteText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, AppendText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, AppendText)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AppendText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyle_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyle_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyle_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyle_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyle_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyle_3)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyle_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyle_4)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int textAttr = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyleForRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyleForRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyleForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyleForRange_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyleForRange_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyleForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyleForRange_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyleForRange_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->GetStyleForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyleEx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyleEx)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyleEx();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetUncombinedStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetUncombinedStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetUncombinedStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetUncombinedStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetUncombinedStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->GetUncombinedStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDefaultStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDefaultStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDefaultStyle_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDefaultStyleEx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDefaultStyleEx)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultStyleEx();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetListStyle)
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

Gura_DeclareMethod(wx_RichTextCtrl, SetListStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetListStyle_1)
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

Gura_DeclareMethod(wx_RichTextCtrl, ClearListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ClearListStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->ClearListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, NumberList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, NumberList)
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

Gura_DeclareMethod(wx_RichTextCtrl, NumberList_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, NumberList_1)
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

Gura_DeclareMethod(wx_RichTextCtrl, PromoteList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PromoteList)
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

Gura_DeclareMethod(wx_RichTextCtrl, PromoteList_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "promoteBy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "specifiedLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PromoteList_1)
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

Gura_DeclareMethod(wx_RichTextCtrl, SetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int properties = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, Delete)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, XYToPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, XYToPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->XYToPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PositionToXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PositionToXY)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->PositionToXY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ShowPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ShowPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, HitTest)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, HitTest_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, HitTest_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int row = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, FindContainerAtPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hit", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hitObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, FindContainerAtPoint)
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

Gura_DeclareMethod(wx_RichTextCtrl, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Copy)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Cut)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Paste)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DeleteSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, DeleteSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanCopy)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCopy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanCut)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanCut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanPaste)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanDeleteSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanDeleteSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanDeleteSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Undo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Redo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Redo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanRedo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetInsertionPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetInsertionPointEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetInsertionPointEnd)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetInsertionPointEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetInsertionPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetLastPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetLastPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetSelection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetSelection_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sel = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, SelectAll)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetEditable)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int editable = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, HasSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, HasUnfocusedSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasUnfocusedSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasUnfocusedSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteImage)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int bitmapType = arg.GetNumber(1)
	//int textAttr = arg.GetNumber(2)
	//pThis->GetEntity()->WriteImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteImage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteImage_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int bitmapType = arg.GetNumber(1)
	//int textAttr = arg.GetNumber(2)
	//pThis->GetEntity()->WriteImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteImage_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteImage_2)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int bitmapType = arg.GetNumber(1)
	//int textAttr = arg.GetNumber(2)
	//pThis->GetEntity()->WriteImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteImage_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imageBlock", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteImage_3)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imageBlock = arg.GetNumber(0)
	//int textAttr = arg.GetNumber(1)
	//pThis->GetEntity()->WriteImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteTextBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteTextBox)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int textAttr = arg.GetNumber(0)
	//pThis->GetEntity()->WriteTextBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteField)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "properties", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteField)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//int properties = arg.GetNumber(1)
	//int textAttr = arg.GetNumber(2)
	//pThis->GetEntity()->WriteField();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WriteTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tableAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cellAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WriteTable)
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

Gura_DeclareMethod(wx_RichTextCtrl, Newline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, Newline)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Newline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, LineBreak)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, LineBreak)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineBreak();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetBasicStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetBasicStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetBasicStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetBasicStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetBasicStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBasicStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->BeginStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndAllStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndAllStyles)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndAllStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginBold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndBold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginItalic)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndItalic)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginUnderline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginUnderline)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginUnderline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndUnderline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndUnderline)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndUnderline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginFontSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->BeginFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndFontSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginFont)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->BeginFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndFont)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginTextColour)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->BeginTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndTextColour)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginAlignment)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->BeginAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndAlignment)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginLeftIndent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int leftIndent = arg.GetNumber(0)
	//int leftSubIndent = arg.GetNumber(1)
	//pThis->GetEntity()->BeginLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndLeftIndent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rightIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginRightIndent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rightIndent = arg.GetNumber(0)
	//pThis->GetEntity()->BeginRightIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndRightIndent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndRightIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginParagraphSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "after", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginParagraphSpacing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//int after = arg.GetNumber(1)
	//pThis->GetEntity()->BeginParagraphSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndParagraphSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndParagraphSpacing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndParagraphSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineSpacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginLineSpacing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineSpacing = arg.GetNumber(0)
	//pThis->GetEntity()->BeginLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndLineSpacing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginNumberedBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginNumberedBullet)
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

Gura_DeclareMethod(wx_RichTextCtrl, EndNumberedBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndNumberedBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndNumberedBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginSymbolBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginSymbolBullet)
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

Gura_DeclareMethod(wx_RichTextCtrl, EndSymbolBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndSymbolBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndSymbolBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginStandardBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bulletName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "leftSubIndent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bulletStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginStandardBullet)
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

Gura_DeclareMethod(wx_RichTextCtrl, EndStandardBullet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndStandardBullet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndStandardBullet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginCharacterStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characterStyle = arg.GetNumber(0)
	//pThis->GetEntity()->BeginCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndCharacterStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paragraphStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginParagraphStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paragraphStyle = arg.GetNumber(0)
	//pThis->GetEntity()->BeginParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndParagraphStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginListStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int listStyle = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int number = arg.GetNumber(2)
	//pThis->GetEntity()->BeginListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndListStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "characterStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginURL)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//int characterStyle = arg.GetNumber(1)
	//pThis->GetEntity()->BeginURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndURL)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDefaultStyleToCursorStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDefaultStyleToCursorStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetDefaultStyleToCursorStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SelectNone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, SelectNone)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectNone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SelectWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SelectWord)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->SelectWord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetSelectionRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetSelectionRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetSelectionRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetSelectionRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetInternalSelectionRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetInternalSelectionRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalSelectionRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetInternalSelectionRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetInternalSelectionRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetInternalSelectionRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, AddParagraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, AddParagraph)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AddParagraph();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, AddImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, AddImage)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->AddImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, LayoutContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "onlyVisibleRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, LayoutContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int onlyVisibleRect = arg.GetNumber(0)
	//pThis->GetEntity()->LayoutContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoLayoutBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoLayoutBuffer)
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

Gura_DeclareMethod(wx_RichTextCtrl, MoveCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showAtLineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveCaret)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int showAtLineStart = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->MoveCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveRight)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPositions = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->MoveRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveLeft)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPositions = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->MoveLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noLines", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveUp)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noLines = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->MoveUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noLines", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveDown)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noLines = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->MoveDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveToLineEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveToLineEnd)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToLineEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveToLineStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveToLineStart)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToLineStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveToParagraphEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveToParagraphEnd)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToParagraphEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveToParagraphStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveToParagraphStart)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToParagraphStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveHome)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveHome)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveHome();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveEnd)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->MoveEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PageUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PageUp)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPages = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->PageUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PageDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PageDown)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPages = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->PageDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WordLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WordLeft)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPages = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->WordLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, WordRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noPages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, WordRight)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noPages = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->WordRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetBuffer)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetBuffer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetBuffer_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginBatchUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmdName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginBatchUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmdName = arg.GetNumber(0)
	//pThis->GetEntity()->BeginBatchUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndBatchUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndBatchUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndBatchUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BatchingUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, BatchingUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BatchingUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, BeginSuppressUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, BeginSuppressUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginSuppressUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EndSuppressUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, EndSuppressUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndSuppressUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SuppressingUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, SuppressingUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SuppressingUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, HasCharacterAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasCharacterAttributes)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->HasCharacterAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, HasParagraphAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, HasParagraphAttributes)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->HasParagraphAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSelectionBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSelectionBold)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSelectionBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSelectionItalics)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSelectionItalics)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSelectionItalics();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSelectionUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSelectionUnderlined)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSelectionUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoesSelectionHaveTextEffectFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoesSelectionHaveTextEffectFlag)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->DoesSelectionHaveTextEffectFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsSelectionAligned)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsSelectionAligned)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelectionAligned();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyBoldToSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyBoldToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ApplyBoldToSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyItalicToSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyItalicToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ApplyItalicToSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyUnderlineToSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyUnderlineToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ApplyUnderlineToSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyTextEffectToSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyTextEffectToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyTextEffectToSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyAlignmentToSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyAlignmentToSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyAlignmentToSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PushStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PushStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->PushStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PopStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, PopStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PopStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ApplyStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ApplyStyleSheet)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleSheet = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ShowContextMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "addPropertyCommands", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ShowContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int addPropertyCommands = arg.GetNumber(2)
	//pThis->GetEntity()->ShowContextMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PrepareContextMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "addPropertyCommands", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PrepareContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int addPropertyCommands = arg.GetNumber(2)
	//pThis->GetEntity()->PrepareContextMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanEditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanEditProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, EditProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetPropertiesMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetPropertiesMenuLabel)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PrepareContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PrepareContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->PrepareContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanDeleteRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanDeleteRange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//pThis->GetEntity()->CanDeleteRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, CanInsertContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, CanInsertContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->CanInsertContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EnableVerticalScrollbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, EnableVerticalScrollbar)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableVerticalScrollbar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetVerticalScrollbarEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetVerticalScrollbarEnabled)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVerticalScrollbarEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFontScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFontScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fontScale = arg.GetNumber(0)
	//int refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetFontScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFontScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFontScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDimensionScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dimScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDimensionScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dimScale = arg.GetNumber(0)
	//int refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetDimensionScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDimensionScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDimensionScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDimensionScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int scale = arg.GetNumber(0)
	//int refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetScale)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetUnscaledPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetUnscaledPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetUnscaledPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetScaledPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetScaledPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetScaledPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetUnscaledSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetUnscaledSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->GetUnscaledSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetScaledSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetScaledSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->GetScaledSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetUnscaledRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetUnscaledRect)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->GetUnscaledRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetScaledRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetScaledRect)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->GetScaledRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetVirtualAttributesEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetVirtualAttributesEnabled)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVirtualAttributesEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EnableVirtualAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, EnableVirtualAttributes)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableVirtualAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, Command)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, Command)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->Command();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnDropFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnDropFiles)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnDropFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnCaptureLost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnCaptureLost)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCaptureLost();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnSysColourChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnSysColourChanged)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSysColourChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnCut)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnCopy)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCopy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnPaste)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnPaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnRedo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnRedo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnSelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnSelectAll)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnClear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnClear)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnClear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateCut)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateCut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateCopy)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateCopy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdatePaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdatePaste)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdatePaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateUndo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateRedo)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateRedo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateSelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateSelectAll)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateSelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateProperties)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnUpdateClear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnUpdateClear)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnUpdateClear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnContextMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnContextMenu)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnContextMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnPaint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnPaint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnPaint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnEraseBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnEraseBackground)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnEraseBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnLeftClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnLeftClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnLeftClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnLeftUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnLeftUp)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnLeftUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnMoveMouse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnMoveMouse)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnMoveMouse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnLeftDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnLeftDClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnLeftDClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnMiddleClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnMiddleClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnMiddleClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnRightClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnRightClick)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnRightClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnChar)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnSetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnSetFocus)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSetFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnKillFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnKillFocus)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnKillFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnIdle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnIdle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnIdle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnScroll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnScroll)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnScroll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetFont)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetupScrollbars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "atTop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetupScrollbars)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int atTop = arg.GetNumber(0)
	//pThis->GetEntity()->SetupScrollbars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, KeyboardNavigate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, KeyboardNavigate)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keyCode = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->KeyboardNavigate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PaintBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PaintBackground)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->PaintBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PaintAboveContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, PaintAboveContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PaintAboveContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, RecreateBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, RecreateBuffer)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->RecreateBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoWriteText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoWriteText)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->DoWriteText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ShouldInheritColours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, ShouldInheritColours)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShouldInheritColours();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, PositionCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, PositionCaret)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//pThis->GetEntity()->PositionCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ExtendSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ExtendSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldPosition = arg.GetNumber(0)
	//int newPosition = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->ExtendSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ExtendCellSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noRowSteps", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noColSteps", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ExtendCellSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//int noRowSteps = arg.GetNumber(1)
	//int noColSteps = arg.GetNumber(2)
	//pThis->GetEntity()->ExtendCellSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, StartCellSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newCell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, StartCellSelection)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//int newCell = arg.GetNumber(1)
	//pThis->GetEntity()->StartCellSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ScrollIntoView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ScrollIntoView)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int keyCode = arg.GetNumber(1)
	//pThis->GetEntity()->ScrollIntoView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, RefreshForSelectionChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldSelection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, RefreshForSelectionChange)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldSelection = arg.GetNumber(0)
	//int newSelection = arg.GetNumber(1)
	//pThis->GetEntity()->RefreshForSelectionChange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetCaretPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showAtLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetCaretPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int showAtLineStart = arg.GetNumber(1)
	//pThis->GetEntity()->SetCaretPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetCaretPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetCaretPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetAdjustedCaretPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetAdjustedCaretPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPos = arg.GetNumber(0)
	//pThis->GetEntity()->GetAdjustedCaretPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveCaretForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveCaretForward)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldPosition = arg.GetNumber(0)
	//pThis->GetEntity()->MoveCaretForward();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, MoveCaretBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, MoveCaretBack)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldPosition = arg.GetNumber(0)
	//pThis->GetEntity()->MoveCaretBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetCaretPositionForIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetCaretPositionForIndex)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int container = arg.GetNumber(2)
	//pThis->GetEntity()->GetCaretPositionForIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetVisibleLineForCaretPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetVisibleLineForCaretPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPosition = arg.GetNumber(0)
	//pThis->GetEntity()->GetVisibleLineForCaretPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetCommandProcessor)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DeleteSelectedContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, DeleteSelectedContent)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newPos = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteSelectedContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetPhysicalPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptLogical", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetPhysicalPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptLogical = arg.GetNumber(0)
	//pThis->GetEntity()->GetPhysicalPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetLogicalPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptPhysical", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetLogicalPoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptPhysical = arg.GetNumber(0)
	//pThis->GetEntity()->GetLogicalPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, FindNextWordPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, FindNextWordPosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->FindNextWordPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsPositionVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsPositionVisible)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->IsPositionVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFirstVisiblePosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFirstVisiblePosition)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstVisiblePosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EnableImages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, EnableImages)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableImages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetImagesEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetImagesEnabled)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImagesEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, EnableDelayedImageLoading)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, EnableDelayedImageLoading)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->EnableDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDelayedImageLoading)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDelayedImageLoading)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDelayedImageProcessingRequired)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDelayedImageProcessingRequired)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedImageProcessingRequired();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDelayedImageProcessingRequired)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDelayedImageProcessingRequired)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetDelayedImageProcessingRequired();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetDelayedImageProcessingTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetDelayedImageProcessingTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDelayedImageProcessingTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetDelayedImageProcessingTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "t", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetDelayedImageProcessingTime)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int t = arg.GetNumber(0)
	//pThis->GetEntity()->SetDelayedImageProcessingTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetCaretPositionForDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetCaretPositionForDefaultStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretPositionForDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetCaretPositionForDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetCaretPositionForDefaultStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretPositionForDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, IsDefaultStyleShowing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, IsDefaultStyleShowing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDefaultStyleShowing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetAndShowDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetAndShowDefaultStyle)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetAndShowDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetFirstVisiblePoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetFirstVisiblePoint)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstVisiblePoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetValue)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetValue)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ProcessBackKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ProcessBackKey)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->ProcessBackKey();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, FindRangeForList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isNumberedList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, FindRangeForList)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int isNumberedList = arg.GetNumber(1)
	//pThis->GetEntity()->FindRangeForList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, SetCaretPositionAfterClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hitTestFlags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "extendSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, SetCaretPositionAfterClick)
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

Gura_DeclareMethod(wx_RichTextCtrl, FindCaretPositionForCharacterPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hitTestFlags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, FindCaretPositionForCharacterPosition)
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

Gura_DeclareMethod(wx_RichTextCtrl, ProcessMouseMovement)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ProcessMouseMovement)
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

Gura_DeclareMethod(wx_RichTextCtrl, GetAvailableFontNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetAvailableFontNames)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAvailableFontNames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ClearAvailableFontNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, ClearAvailableFontNames)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearAvailableFontNames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoGetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoGetValue)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ProcessDelayedImageLoading)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ProcessDelayedImageLoading)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int refresh = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, ProcessDelayedImageLoading_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "screenRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "box", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "loadCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, ProcessDelayedImageLoading_1)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int screenRect = arg.GetNumber(0)
	//int box = arg.GetNumber(1)
	//int loadCount = arg.GetNumber(2)
	//pThis->GetEntity()->ProcessDelayedImageLoading();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, RequestDelayedImageProcessing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, RequestDelayedImageProcessing)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RequestDelayedImageProcessing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, OnTimer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, OnTimer)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnTimer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, GetEditableWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, GetEditableWindow)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEditableWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoSetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoSetMargins)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->DoSetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoGetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoGetMargins)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoGetBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoGetBestSize)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoGetBestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoSetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoSetValue)
{
	Object_wx_RichTextCtrl *pThis = Object_wx_RichTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->DoSetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCtrl, DoThaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCtrl, DoThaw)
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
	Gura_AssignMethod(wx_RichTextCtrl, wxRichTextCtrl);
	Gura_AssignMethod(wx_RichTextCtrl, wxRichTextCtrl_1);
	Gura_AssignMethod(wx_RichTextCtrl, Create);
	Gura_AssignMethod(wx_RichTextCtrl, Init);
	Gura_AssignMethod(wx_RichTextCtrl, GetRange);
	Gura_AssignMethod(wx_RichTextCtrl, GetLineLength);
	Gura_AssignMethod(wx_RichTextCtrl, GetLineText);
	Gura_AssignMethod(wx_RichTextCtrl, GetNumberOfLines);
	Gura_AssignMethod(wx_RichTextCtrl, IsModified);
	Gura_AssignMethod(wx_RichTextCtrl, IsEditable);
	Gura_AssignMethod(wx_RichTextCtrl, IsSingleLine);
	Gura_AssignMethod(wx_RichTextCtrl, IsMultiLine);
	Gura_AssignMethod(wx_RichTextCtrl, GetSelection);
	Gura_AssignMethod(wx_RichTextCtrl, GetSelection_1);
	Gura_AssignMethod(wx_RichTextCtrl, GetSelection_2);
	Gura_AssignMethod(wx_RichTextCtrl, GetStringSelection);
	Gura_AssignMethod(wx_RichTextCtrl, GetFilename);
	Gura_AssignMethod(wx_RichTextCtrl, SetFilename);
	Gura_AssignMethod(wx_RichTextCtrl, SetDelayedLayoutThreshold);
	Gura_AssignMethod(wx_RichTextCtrl, GetDelayedLayoutThreshold);
	Gura_AssignMethod(wx_RichTextCtrl, GetFullLayoutRequired);
	Gura_AssignMethod(wx_RichTextCtrl, SetFullLayoutRequired);
	Gura_AssignMethod(wx_RichTextCtrl, GetFullLayoutTime);
	Gura_AssignMethod(wx_RichTextCtrl, SetFullLayoutTime);
	Gura_AssignMethod(wx_RichTextCtrl, GetFullLayoutSavedPosition);
	Gura_AssignMethod(wx_RichTextCtrl, SetFullLayoutSavedPosition);
	Gura_AssignMethod(wx_RichTextCtrl, ForceDelayedLayout);
	Gura_AssignMethod(wx_RichTextCtrl, SetTextCursor);
	Gura_AssignMethod(wx_RichTextCtrl, GetTextCursor);
	Gura_AssignMethod(wx_RichTextCtrl, SetURLCursor);
	Gura_AssignMethod(wx_RichTextCtrl, GetURLCursor);
	Gura_AssignMethod(wx_RichTextCtrl, GetCaretAtLineStart);
	Gura_AssignMethod(wx_RichTextCtrl, SetCaretAtLineStart);
	Gura_AssignMethod(wx_RichTextCtrl, GetDragging);
	Gura_AssignMethod(wx_RichTextCtrl, SetDragging);
	Gura_AssignMethod(wx_RichTextCtrl, GetPreDrag);
	Gura_AssignMethod(wx_RichTextCtrl, SetPreDrag);
	Gura_AssignMethod(wx_RichTextCtrl, GetDragStartPoint);
	Gura_AssignMethod(wx_RichTextCtrl, SetDragStartPoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetDragStartTime);
	Gura_AssignMethod(wx_RichTextCtrl, SetDragStartTime);
	Gura_AssignMethod(wx_RichTextCtrl, GetBufferBitmap);
	Gura_AssignMethod(wx_RichTextCtrl, GetBufferBitmap_1);
	Gura_AssignMethod(wx_RichTextCtrl, GetContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, SetContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, GetSelectionAnchor);
	Gura_AssignMethod(wx_RichTextCtrl, SetSelectionAnchor);
	Gura_AssignMethod(wx_RichTextCtrl, GetSelectionAnchorObject);
	Gura_AssignMethod(wx_RichTextCtrl, SetSelectionAnchorObject);
	Gura_AssignMethod(wx_RichTextCtrl, GetContextMenuPropertiesInfo);
	Gura_AssignMethod(wx_RichTextCtrl, GetContextMenuPropertiesInfo_1);
	Gura_AssignMethod(wx_RichTextCtrl, GetFocusObject);
	Gura_AssignMethod(wx_RichTextCtrl, StoreFocusObject);
	Gura_AssignMethod(wx_RichTextCtrl, SetFocusObject);
	Gura_AssignMethod(wx_RichTextCtrl, Invalidate);
	Gura_AssignMethod(wx_RichTextCtrl, Clear);
	Gura_AssignMethod(wx_RichTextCtrl, Replace);
	Gura_AssignMethod(wx_RichTextCtrl, Remove);
	Gura_AssignMethod(wx_RichTextCtrl, LoadFile);
	Gura_AssignMethod(wx_RichTextCtrl, DoLoadFile);
	Gura_AssignMethod(wx_RichTextCtrl, SaveFile);
	Gura_AssignMethod(wx_RichTextCtrl, DoSaveFile);
	Gura_AssignMethod(wx_RichTextCtrl, SetHandlerFlags);
	Gura_AssignMethod(wx_RichTextCtrl, GetHandlerFlags);
	Gura_AssignMethod(wx_RichTextCtrl, MarkDirty);
	Gura_AssignMethod(wx_RichTextCtrl, DiscardEdits);
	Gura_AssignMethod(wx_RichTextCtrl, SetModified);
	Gura_AssignMethod(wx_RichTextCtrl, SetMaxLength);
	Gura_AssignMethod(wx_RichTextCtrl, WriteText);
	Gura_AssignMethod(wx_RichTextCtrl, AppendText);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyle);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyle_2);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyle_2);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyle_3);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyle_4);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyleForRange);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyleForRange_1);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyleForRange_2);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyleEx);
	Gura_AssignMethod(wx_RichTextCtrl, GetUncombinedStyle);
	Gura_AssignMethod(wx_RichTextCtrl, GetUncombinedStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, SetDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetDefaultStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, GetDefaultStyleEx);
	Gura_AssignMethod(wx_RichTextCtrl, SetListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetListStyle_1);
	Gura_AssignMethod(wx_RichTextCtrl, ClearListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, NumberList);
	Gura_AssignMethod(wx_RichTextCtrl, NumberList_1);
	Gura_AssignMethod(wx_RichTextCtrl, PromoteList);
	Gura_AssignMethod(wx_RichTextCtrl, PromoteList_1);
	Gura_AssignMethod(wx_RichTextCtrl, SetProperties);
	Gura_AssignMethod(wx_RichTextCtrl, Delete);
	Gura_AssignMethod(wx_RichTextCtrl, XYToPosition);
	Gura_AssignMethod(wx_RichTextCtrl, PositionToXY);
	Gura_AssignMethod(wx_RichTextCtrl, ShowPosition);
	Gura_AssignMethod(wx_RichTextCtrl, HitTest);
	Gura_AssignMethod(wx_RichTextCtrl, HitTest_1);
	Gura_AssignMethod(wx_RichTextCtrl, FindContainerAtPoint);
	Gura_AssignMethod(wx_RichTextCtrl, Copy);
	Gura_AssignMethod(wx_RichTextCtrl, Cut);
	Gura_AssignMethod(wx_RichTextCtrl, Paste);
	Gura_AssignMethod(wx_RichTextCtrl, DeleteSelection);
	Gura_AssignMethod(wx_RichTextCtrl, CanCopy);
	Gura_AssignMethod(wx_RichTextCtrl, CanCut);
	Gura_AssignMethod(wx_RichTextCtrl, CanPaste);
	Gura_AssignMethod(wx_RichTextCtrl, CanDeleteSelection);
	Gura_AssignMethod(wx_RichTextCtrl, Undo);
	Gura_AssignMethod(wx_RichTextCtrl, Redo);
	Gura_AssignMethod(wx_RichTextCtrl, CanUndo);
	Gura_AssignMethod(wx_RichTextCtrl, CanRedo);
	Gura_AssignMethod(wx_RichTextCtrl, SetInsertionPoint);
	Gura_AssignMethod(wx_RichTextCtrl, SetInsertionPointEnd);
	Gura_AssignMethod(wx_RichTextCtrl, GetInsertionPoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetLastPosition);
	Gura_AssignMethod(wx_RichTextCtrl, SetSelection);
	Gura_AssignMethod(wx_RichTextCtrl, SetSelection_1);
	Gura_AssignMethod(wx_RichTextCtrl, SelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, SetEditable);
	Gura_AssignMethod(wx_RichTextCtrl, HasSelection);
	Gura_AssignMethod(wx_RichTextCtrl, HasUnfocusedSelection);
	Gura_AssignMethod(wx_RichTextCtrl, WriteImage);
	Gura_AssignMethod(wx_RichTextCtrl, WriteImage_1);
	Gura_AssignMethod(wx_RichTextCtrl, WriteImage_2);
	Gura_AssignMethod(wx_RichTextCtrl, WriteImage_3);
	Gura_AssignMethod(wx_RichTextCtrl, WriteTextBox);
	Gura_AssignMethod(wx_RichTextCtrl, WriteField);
	Gura_AssignMethod(wx_RichTextCtrl, WriteTable);
	Gura_AssignMethod(wx_RichTextCtrl, Newline);
	Gura_AssignMethod(wx_RichTextCtrl, LineBreak);
	Gura_AssignMethod(wx_RichTextCtrl, SetBasicStyle);
	Gura_AssignMethod(wx_RichTextCtrl, GetBasicStyle);
	Gura_AssignMethod(wx_RichTextCtrl, BeginStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndAllStyles);
	Gura_AssignMethod(wx_RichTextCtrl, BeginBold);
	Gura_AssignMethod(wx_RichTextCtrl, EndBold);
	Gura_AssignMethod(wx_RichTextCtrl, BeginItalic);
	Gura_AssignMethod(wx_RichTextCtrl, EndItalic);
	Gura_AssignMethod(wx_RichTextCtrl, BeginUnderline);
	Gura_AssignMethod(wx_RichTextCtrl, EndUnderline);
	Gura_AssignMethod(wx_RichTextCtrl, BeginFontSize);
	Gura_AssignMethod(wx_RichTextCtrl, EndFontSize);
	Gura_AssignMethod(wx_RichTextCtrl, BeginFont);
	Gura_AssignMethod(wx_RichTextCtrl, EndFont);
	Gura_AssignMethod(wx_RichTextCtrl, BeginTextColour);
	Gura_AssignMethod(wx_RichTextCtrl, EndTextColour);
	Gura_AssignMethod(wx_RichTextCtrl, BeginAlignment);
	Gura_AssignMethod(wx_RichTextCtrl, EndAlignment);
	Gura_AssignMethod(wx_RichTextCtrl, BeginLeftIndent);
	Gura_AssignMethod(wx_RichTextCtrl, EndLeftIndent);
	Gura_AssignMethod(wx_RichTextCtrl, BeginRightIndent);
	Gura_AssignMethod(wx_RichTextCtrl, EndRightIndent);
	Gura_AssignMethod(wx_RichTextCtrl, BeginParagraphSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, EndParagraphSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, BeginLineSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, EndLineSpacing);
	Gura_AssignMethod(wx_RichTextCtrl, BeginNumberedBullet);
	Gura_AssignMethod(wx_RichTextCtrl, EndNumberedBullet);
	Gura_AssignMethod(wx_RichTextCtrl, BeginSymbolBullet);
	Gura_AssignMethod(wx_RichTextCtrl, EndSymbolBullet);
	Gura_AssignMethod(wx_RichTextCtrl, BeginStandardBullet);
	Gura_AssignMethod(wx_RichTextCtrl, EndStandardBullet);
	Gura_AssignMethod(wx_RichTextCtrl, BeginCharacterStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndCharacterStyle);
	Gura_AssignMethod(wx_RichTextCtrl, BeginParagraphStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndParagraphStyle);
	Gura_AssignMethod(wx_RichTextCtrl, BeginListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, EndListStyle);
	Gura_AssignMethod(wx_RichTextCtrl, BeginURL);
	Gura_AssignMethod(wx_RichTextCtrl, EndURL);
	Gura_AssignMethod(wx_RichTextCtrl, SetDefaultStyleToCursorStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SelectNone);
	Gura_AssignMethod(wx_RichTextCtrl, SelectWord);
	Gura_AssignMethod(wx_RichTextCtrl, GetSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, SetSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, GetInternalSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, SetInternalSelectionRange);
	Gura_AssignMethod(wx_RichTextCtrl, AddParagraph);
	Gura_AssignMethod(wx_RichTextCtrl, AddImage);
	Gura_AssignMethod(wx_RichTextCtrl, LayoutContent);
	Gura_AssignMethod(wx_RichTextCtrl, DoLayoutBuffer);
	Gura_AssignMethod(wx_RichTextCtrl, MoveCaret);
	Gura_AssignMethod(wx_RichTextCtrl, MoveRight);
	Gura_AssignMethod(wx_RichTextCtrl, MoveLeft);
	Gura_AssignMethod(wx_RichTextCtrl, MoveUp);
	Gura_AssignMethod(wx_RichTextCtrl, MoveDown);
	Gura_AssignMethod(wx_RichTextCtrl, MoveToLineEnd);
	Gura_AssignMethod(wx_RichTextCtrl, MoveToLineStart);
	Gura_AssignMethod(wx_RichTextCtrl, MoveToParagraphEnd);
	Gura_AssignMethod(wx_RichTextCtrl, MoveToParagraphStart);
	Gura_AssignMethod(wx_RichTextCtrl, MoveHome);
	Gura_AssignMethod(wx_RichTextCtrl, MoveEnd);
	Gura_AssignMethod(wx_RichTextCtrl, PageUp);
	Gura_AssignMethod(wx_RichTextCtrl, PageDown);
	Gura_AssignMethod(wx_RichTextCtrl, WordLeft);
	Gura_AssignMethod(wx_RichTextCtrl, WordRight);
	Gura_AssignMethod(wx_RichTextCtrl, GetBuffer);
	Gura_AssignMethod(wx_RichTextCtrl, GetBuffer_1);
	Gura_AssignMethod(wx_RichTextCtrl, BeginBatchUndo);
	Gura_AssignMethod(wx_RichTextCtrl, EndBatchUndo);
	Gura_AssignMethod(wx_RichTextCtrl, BatchingUndo);
	Gura_AssignMethod(wx_RichTextCtrl, BeginSuppressUndo);
	Gura_AssignMethod(wx_RichTextCtrl, EndSuppressUndo);
	Gura_AssignMethod(wx_RichTextCtrl, SuppressingUndo);
	Gura_AssignMethod(wx_RichTextCtrl, HasCharacterAttributes);
	Gura_AssignMethod(wx_RichTextCtrl, HasParagraphAttributes);
	Gura_AssignMethod(wx_RichTextCtrl, IsSelectionBold);
	Gura_AssignMethod(wx_RichTextCtrl, IsSelectionItalics);
	Gura_AssignMethod(wx_RichTextCtrl, IsSelectionUnderlined);
	Gura_AssignMethod(wx_RichTextCtrl, DoesSelectionHaveTextEffectFlag);
	Gura_AssignMethod(wx_RichTextCtrl, IsSelectionAligned);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyBoldToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyItalicToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyUnderlineToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyTextEffectToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyAlignmentToSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, PushStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, PopStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, ApplyStyleSheet);
	Gura_AssignMethod(wx_RichTextCtrl, ShowContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, PrepareContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, CanEditProperties);
	Gura_AssignMethod(wx_RichTextCtrl, EditProperties);
	Gura_AssignMethod(wx_RichTextCtrl, GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextCtrl, PrepareContent);
	Gura_AssignMethod(wx_RichTextCtrl, CanDeleteRange);
	Gura_AssignMethod(wx_RichTextCtrl, CanInsertContent);
	Gura_AssignMethod(wx_RichTextCtrl, EnableVerticalScrollbar);
	Gura_AssignMethod(wx_RichTextCtrl, GetVerticalScrollbarEnabled);
	Gura_AssignMethod(wx_RichTextCtrl, SetFontScale);
	Gura_AssignMethod(wx_RichTextCtrl, GetFontScale);
	Gura_AssignMethod(wx_RichTextCtrl, SetDimensionScale);
	Gura_AssignMethod(wx_RichTextCtrl, GetDimensionScale);
	Gura_AssignMethod(wx_RichTextCtrl, SetScale);
	Gura_AssignMethod(wx_RichTextCtrl, GetScale);
	Gura_AssignMethod(wx_RichTextCtrl, GetUnscaledPoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetScaledPoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetUnscaledSize);
	Gura_AssignMethod(wx_RichTextCtrl, GetScaledSize);
	Gura_AssignMethod(wx_RichTextCtrl, GetUnscaledRect);
	Gura_AssignMethod(wx_RichTextCtrl, GetScaledRect);
	Gura_AssignMethod(wx_RichTextCtrl, GetVirtualAttributesEnabled);
	Gura_AssignMethod(wx_RichTextCtrl, EnableVirtualAttributes);
	Gura_AssignMethod(wx_RichTextCtrl, Command);
	Gura_AssignMethod(wx_RichTextCtrl, OnDropFiles);
	Gura_AssignMethod(wx_RichTextCtrl, OnCaptureLost);
	Gura_AssignMethod(wx_RichTextCtrl, OnSysColourChanged);
	Gura_AssignMethod(wx_RichTextCtrl, OnCut);
	Gura_AssignMethod(wx_RichTextCtrl, OnCopy);
	Gura_AssignMethod(wx_RichTextCtrl, OnPaste);
	Gura_AssignMethod(wx_RichTextCtrl, OnUndo);
	Gura_AssignMethod(wx_RichTextCtrl, OnRedo);
	Gura_AssignMethod(wx_RichTextCtrl, OnSelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, OnProperties);
	Gura_AssignMethod(wx_RichTextCtrl, OnClear);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateCut);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateCopy);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdatePaste);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateUndo);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateRedo);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateSelectAll);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateProperties);
	Gura_AssignMethod(wx_RichTextCtrl, OnUpdateClear);
	Gura_AssignMethod(wx_RichTextCtrl, OnContextMenu);
	Gura_AssignMethod(wx_RichTextCtrl, OnPaint);
	Gura_AssignMethod(wx_RichTextCtrl, OnEraseBackground);
	Gura_AssignMethod(wx_RichTextCtrl, OnLeftClick);
	Gura_AssignMethod(wx_RichTextCtrl, OnLeftUp);
	Gura_AssignMethod(wx_RichTextCtrl, OnMoveMouse);
	Gura_AssignMethod(wx_RichTextCtrl, OnLeftDClick);
	Gura_AssignMethod(wx_RichTextCtrl, OnMiddleClick);
	Gura_AssignMethod(wx_RichTextCtrl, OnRightClick);
	Gura_AssignMethod(wx_RichTextCtrl, OnChar);
	Gura_AssignMethod(wx_RichTextCtrl, OnSize);
	Gura_AssignMethod(wx_RichTextCtrl, OnSetFocus);
	Gura_AssignMethod(wx_RichTextCtrl, OnKillFocus);
	Gura_AssignMethod(wx_RichTextCtrl, OnIdle);
	Gura_AssignMethod(wx_RichTextCtrl, OnScroll);
	Gura_AssignMethod(wx_RichTextCtrl, SetFont);
	Gura_AssignMethod(wx_RichTextCtrl, SetupScrollbars);
	Gura_AssignMethod(wx_RichTextCtrl, KeyboardNavigate);
	Gura_AssignMethod(wx_RichTextCtrl, PaintBackground);
	Gura_AssignMethod(wx_RichTextCtrl, PaintAboveContent);
	Gura_AssignMethod(wx_RichTextCtrl, RecreateBuffer);
	Gura_AssignMethod(wx_RichTextCtrl, DoWriteText);
	Gura_AssignMethod(wx_RichTextCtrl, ShouldInheritColours);
	Gura_AssignMethod(wx_RichTextCtrl, PositionCaret);
	Gura_AssignMethod(wx_RichTextCtrl, ExtendSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ExtendCellSelection);
	Gura_AssignMethod(wx_RichTextCtrl, StartCellSelection);
	Gura_AssignMethod(wx_RichTextCtrl, ScrollIntoView);
	Gura_AssignMethod(wx_RichTextCtrl, RefreshForSelectionChange);
	Gura_AssignMethod(wx_RichTextCtrl, SetCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, GetCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, GetAdjustedCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, MoveCaretForward);
	Gura_AssignMethod(wx_RichTextCtrl, MoveCaretBack);
	Gura_AssignMethod(wx_RichTextCtrl, GetCaretPositionForIndex);
	Gura_AssignMethod(wx_RichTextCtrl, GetVisibleLineForCaretPosition);
	Gura_AssignMethod(wx_RichTextCtrl, GetCommandProcessor);
	Gura_AssignMethod(wx_RichTextCtrl, DeleteSelectedContent);
	Gura_AssignMethod(wx_RichTextCtrl, GetPhysicalPoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetLogicalPoint);
	Gura_AssignMethod(wx_RichTextCtrl, FindNextWordPosition);
	Gura_AssignMethod(wx_RichTextCtrl, IsPositionVisible);
	Gura_AssignMethod(wx_RichTextCtrl, GetFirstVisiblePosition);
	Gura_AssignMethod(wx_RichTextCtrl, EnableImages);
	Gura_AssignMethod(wx_RichTextCtrl, GetImagesEnabled);
	Gura_AssignMethod(wx_RichTextCtrl, EnableDelayedImageLoading);
	Gura_AssignMethod(wx_RichTextCtrl, GetDelayedImageLoading);
	Gura_AssignMethod(wx_RichTextCtrl, GetDelayedImageProcessingRequired);
	Gura_AssignMethod(wx_RichTextCtrl, SetDelayedImageProcessingRequired);
	Gura_AssignMethod(wx_RichTextCtrl, GetDelayedImageProcessingTime);
	Gura_AssignMethod(wx_RichTextCtrl, SetDelayedImageProcessingTime);
	Gura_AssignMethod(wx_RichTextCtrl, GetCaretPositionForDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, SetCaretPositionForDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, IsDefaultStyleShowing);
	Gura_AssignMethod(wx_RichTextCtrl, SetAndShowDefaultStyle);
	Gura_AssignMethod(wx_RichTextCtrl, GetFirstVisiblePoint);
	Gura_AssignMethod(wx_RichTextCtrl, GetValue);
	Gura_AssignMethod(wx_RichTextCtrl, SetValue);
	Gura_AssignMethod(wx_RichTextCtrl, ProcessBackKey);
	Gura_AssignMethod(wx_RichTextCtrl, FindRangeForList);
	Gura_AssignMethod(wx_RichTextCtrl, SetCaretPositionAfterClick);
	Gura_AssignMethod(wx_RichTextCtrl, FindCaretPositionForCharacterPosition);
	Gura_AssignMethod(wx_RichTextCtrl, ProcessMouseMovement);
	Gura_AssignMethod(wx_RichTextCtrl, GetAvailableFontNames);
	Gura_AssignMethod(wx_RichTextCtrl, ClearAvailableFontNames);
	Gura_AssignMethod(wx_RichTextCtrl, DoGetValue);
	Gura_AssignMethod(wx_RichTextCtrl, ProcessDelayedImageLoading);
	Gura_AssignMethod(wx_RichTextCtrl, ProcessDelayedImageLoading_1);
	Gura_AssignMethod(wx_RichTextCtrl, RequestDelayedImageProcessing);
	Gura_AssignMethod(wx_RichTextCtrl, OnTimer);
	Gura_AssignMethod(wx_RichTextCtrl, GetEditableWindow);
	Gura_AssignMethod(wx_RichTextCtrl, DoSetMargins);
	Gura_AssignMethod(wx_RichTextCtrl, DoGetMargins);
	Gura_AssignMethod(wx_RichTextCtrl, DoGetBestSize);
	Gura_AssignMethod(wx_RichTextCtrl, DoSetValue);
	Gura_AssignMethod(wx_RichTextCtrl, DoThaw);
}

Gura_ImplementDescendantCreator(wx_RichTextCtrl)
{
	return new Object_wx_RichTextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
