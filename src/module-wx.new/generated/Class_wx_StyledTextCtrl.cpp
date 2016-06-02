//----------------------------------------------------------------------------
// wxStyledTextCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStyledTextCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStyledTextCtrl
//----------------------------------------------------------------------------
Object_wx_StyledTextCtrl::~Object_wx_StyledTextCtrl()
{
}

Object *Object_wx_StyledTextCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_StyledTextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.StyledTextCtrl:");
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
Gura_DeclareMethod(wx_StyledTextCtrl, wxStyledTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, wxStyledTextCtrl)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxStyledTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, wxStyledTextCtrl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, wxStyledTextCtrl_1)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStyledTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Create)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AddText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AddText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AddText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AddStyledText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AddStyledText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->AddStyledText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, InsertText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, InsertText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->InsertText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ChangeInsertion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ChangeInsertion)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->ChangeInsertion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ClearAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DeleteRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DeleteRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int deleteLength = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ClearDocumentStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ClearDocumentStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearDocumentStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCharAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCharAt)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetCharAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCurrentPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCurrentPos)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetStyleAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetStyleAt)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetStyleAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Redo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Redo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetUndoCollection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collectUndo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetUndoCollection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int collectUndo = arg.GetNumber(0)
	//pThis->GetEntity()->SetUndoCollection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SelectAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSavePoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSavePoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetSavePoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetStyledText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetStyledText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyledText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CanRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CanRedo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerLineFromHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerLineFromHandle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handle = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerLineFromHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerDeleteHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerDeleteHandle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handle = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerDeleteHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetUndoCollection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetUndoCollection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUndoCollection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetViewWhiteSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetViewWhiteSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewWhiteSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetViewWhiteSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewWS", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetViewWhiteSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int viewWS = arg.GetNumber(0)
	//pThis->GetEntity()->SetViewWhiteSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PositionFromPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PositionFromPoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->PositionFromPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PositionFromPointClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PositionFromPointClose)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->PositionFromPointClose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GotoLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GotoLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GotoLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GotoPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GotoPos)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GotoPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "posAnchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int posAnchor = arg.GetNumber(0)
	//pThis->GetEntity()->SetAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCurLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "linePos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCurLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int linePos = arg.GetNumber(0)
	//pThis->GetEntity()->GetCurLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetEndStyled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetEndStyled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndStyled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ConvertEOLs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eolMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ConvertEOLs)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eolMode = arg.GetNumber(0)
	//pThis->GetEntity()->ConvertEOLs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetEOLMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetEOLMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEOLMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetEOLMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eolMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetEOLMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eolMode = arg.GetNumber(0)
	//pThis->GetEntity()->SetEOLMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StartStyling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StartStyling)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mask = arg.GetNumber(1)
	//pThis->GetEntity()->StartStyling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetStyling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetStyling)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->SetStyling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetBufferedDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetBufferedDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBufferedDraw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetBufferedDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffered", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetBufferedDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffered = arg.GetNumber(0)
	//pThis->GetEntity()->SetBufferedDraw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetTabWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetTabWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTabWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTabWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTabWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ClearTabStops)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ClearTabStops)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->ClearTabStops();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AddTabStop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AddTabStop)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//pThis->GetEntity()->AddTabStop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetNextTabStop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetNextTabStop)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextTabStop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCodePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "codePage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCodePage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int codePage = arg.GetNumber(0)
	//pThis->GetEntity()->SetCodePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetIMEInteraction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetIMEInteraction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIMEInteraction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetIMEInteraction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imeInteraction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetIMEInteraction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imeInteraction = arg.GetNumber(0)
	//pThis->GetEntity()->SetIMEInteraction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerDefine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerSymbol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "foreground", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "background", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerDefine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int markerSymbol = arg.GetNumber(1)
	//int foreground = arg.GetNumber(2)
	//int background = arg.GetNumber(3)
	//pThis->GetEntity()->MarkerDefine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerSetForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerSetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int fore = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerSetForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerSetBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerSetBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int back = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerSetBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerSetBackgroundSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerSetBackgroundSelected)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int back = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerSetBackgroundSelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerEnableHighlight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enabled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerEnableHighlight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enabled = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerEnableHighlight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerAdd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerAdd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int markerNumber = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerAdd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerDelete)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int markerNumber = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerDelete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerDeleteAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerDeleteAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerDeleteAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerGet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerGet)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerGet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerNext)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//int markerMask = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerPrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerPrevious)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//int markerMask = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerPrevious();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerDefineBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerDefineBitmap)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int bmp = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerDefineBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerAddSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerAddSet)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int set = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerAddSet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerSetAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerSetAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int alpha = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerSetAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMarginType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "marginType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMarginType)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int marginType = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarginType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarginType)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMarginWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMarginWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int pixelWidth = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarginWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarginWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMarginMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMarginMask)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int mask = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarginMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarginMask)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMarginSensitive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sensitive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMarginSensitive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int sensitive = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginSensitive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarginSensitive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarginSensitive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginSensitive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMarginCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMarginCursor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarginCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarginCursor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleClearAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StyleClearAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int fore = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int back = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetBold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int bold = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "italic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetItalic)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int italic = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizePoints", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int sizePoints = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fontName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetFaceName)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int fontName = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetEOLFilled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetEOLFilled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int filled = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetEOLFilled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleResetDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleResetDefault)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StyleResetDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetUnderline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetUnderline)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int underline = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetUnderline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetBold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetItalic)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetFaceName)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetEOLFilled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetEOLFilled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetEOLFilled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetUnderline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetUnderline)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetUnderline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetCharacterSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetCharacterSet)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetCharacterSet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetChangeable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetChangeable)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetChangeable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetHotSpot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetHotSpot)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetHotSpot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseForce", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int caseForce = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetSizeFractional)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseForce", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetSizeFractional)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int caseForce = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetSizeFractional();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetSizeFractional)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetSizeFractional)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetSizeFractional();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetWeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int weight = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetWeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetHotSpot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotspot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetHotSpot)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int hotspot = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetHotSpot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useSetting = arg.GetNumber(0)
	//int fore = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useSetting = arg.GetNumber(0)
	//int back = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alpha = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelEOLFilled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelEOLFilled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelEOLFilled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelEOLFilled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelEOLFilled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filled = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelEOLFilled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fore = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CmdKeyAssign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CmdKeyAssign)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int modifiers = arg.GetNumber(1)
	//int cmd = arg.GetNumber(2)
	//pThis->GetEntity()->CmdKeyAssign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CmdKeyClear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CmdKeyClear)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int modifiers = arg.GetNumber(1)
	//pThis->GetEntity()->CmdKeyClear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CmdKeyClearAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CmdKeyClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CmdKeyClearAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetStyleBytes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styleBytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetStyleBytes)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//int styleBytes = arg.GetNumber(1)
	//pThis->GetEntity()->SetStyleBytes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int visible = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretPeriod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretPeriod)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretPeriod();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretPeriod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "periodMilliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretPeriod)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int periodMilliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretPeriod();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWordChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWordChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characters = arg.GetNumber(0)
	//pThis->GetEntity()->SetWordChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetWordChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetWordChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWordChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BeginUndoAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BeginUndoAction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginUndoAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EndUndoAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EndUndoAction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndUndoAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorSetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorSetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorGetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorGetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorSetForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorSetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int fore = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorGetForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorGetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorSetUnder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "under", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorSetUnder)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int under = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetUnder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorGetUnder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorGetUnder)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetUnder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorSetHoverStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorSetHoverStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetHoverStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorGetHoverStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorGetHoverStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetHoverStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorSetHoverForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorSetHoverForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int fore = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetHoverForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorGetHoverForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorGetHoverForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetHoverForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorSetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorSetFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorGetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorGetFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWhitespaceForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWhitespaceForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useSetting = arg.GetNumber(0)
	//int fore = arg.GetNumber(1)
	//pThis->GetEntity()->SetWhitespaceForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWhitespaceBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWhitespaceBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useSetting = arg.GetNumber(0)
	//int back = arg.GetNumber(1)
	//pThis->GetEntity()->SetWhitespaceBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWhitespaceSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWhitespaceSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetWhitespaceSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetWhitespaceSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetWhitespaceSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWhitespaceSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetStyleBits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetStyleBits)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bits = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleBits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetStyleBits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetStyleBits)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleBits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetLineState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetLineState)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->SetLineState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineState)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMaxLineState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMaxLineState)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxLineState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretLineVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretLineVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretLineVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretLineVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretLineVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretLineVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretLineBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretLineBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretLineBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretLineBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretLineBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int back = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretLineBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetChangeable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "changeable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetChangeable)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int changeable = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetChangeable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompShow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lenEntered", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompShow)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lenEntered = arg.GetNumber(0)
	//int itemList = arg.GetNumber(1)
	//pThis->GetEntity()->AutoCompShow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompCancel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompCancel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompCancel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompActive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompPosStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompPosStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompPosStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompComplete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompComplete)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompComplete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompStops)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompStops)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characterSet = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompStops();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "separatorCharacter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetSeparator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int separatorCharacter = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetSeparator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSelect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSelect)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSelect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetCancelAtStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cancel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetCancelAtStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cancel = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetCancelAtStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetCancelAtStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetCancelAtStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetCancelAtStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetFillUps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetFillUps)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characterSet = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetFillUps();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetChooseSingle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "chooseSingle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetChooseSingle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int chooseSingle = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetChooseSingle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetChooseSingle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetChooseSingle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetChooseSingle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetIgnoreCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ignoreCase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetIgnoreCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ignoreCase = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetIgnoreCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetIgnoreCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetIgnoreCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetIgnoreCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, UserListShow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, UserListShow)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int listType = arg.GetNumber(0)
	//int itemList = arg.GetNumber(1)
	//pThis->GetEntity()->UserListShow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetAutoHide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "autoHide", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetAutoHide)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int autoHide = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetAutoHide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetAutoHide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetAutoHide)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetAutoHide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetDropRestOfWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dropRestOfWord", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetDropRestOfWord)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dropRestOfWord = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetDropRestOfWord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetDropRestOfWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetDropRestOfWord)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetDropRestOfWord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, RegisterImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, RegisterImage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int bmp = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ClearRegisteredImages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ClearRegisteredImages)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearRegisteredImages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetTypeSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetTypeSeparator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetTypeSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetTypeSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "separatorCharacter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetTypeSeparator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int separatorCharacter = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetTypeSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetMaxWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetMaxWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characterCount = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetMaxWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetMaxWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetMaxWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetMaxWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetMaxHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetMaxHeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowCount = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetMaxHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetMaxHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetMaxHeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetMaxHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetIndent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indentSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetIndent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetUseTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useTabs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetUseTabs)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useTabs = arg.GetNumber(0)
	//pThis->GetEntity()->SetUseTabs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetUseTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetUseTabs)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUseTabs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetLineIndentation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetLineIndentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int indentSize = arg.GetNumber(1)
	//pThis->GetEntity()->SetLineIndentation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineIndentation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineIndentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineIndentation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineIndentPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineIndentPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineIndentPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CountCharacters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CountCharacters)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->CountCharacters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetUseHorizontalScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetUseHorizontalScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetUseHorizontalScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetUseHorizontalScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetUseHorizontalScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUseHorizontalScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetIndentationGuides)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indentView", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetIndentationGuides)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indentView = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndentationGuides();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetIndentationGuides)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetIndentationGuides)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndentationGuides();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetHighlightGuide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetHighlightGuide)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->SetHighlightGuide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetHighlightGuide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetHighlightGuide)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHighlightGuide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineEndPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineEndPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineEndPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCodePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCodePage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCodePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetReadOnly)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetReadOnly();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCurrentPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCurrentPos)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrentPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetEmptySelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetEmptySelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetEmptySelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetPrintMagnification)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "magnification", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetPrintMagnification)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int magnification = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintMagnification();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPrintMagnification)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPrintMagnification)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintMagnification();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetPrintColourMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetPrintColourMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintColourMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPrintColourMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPrintColourMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintColourMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FindText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FindText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minPos = arg.GetNumber(0)
	//int maxPos = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->FindText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FormatRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doDraw", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "draw", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "target", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "renderRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FormatRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doDraw = arg.GetNumber(0)
	//int startPos = arg.GetNumber(1)
	//int endPos = arg.GetNumber(2)
	//int draw = arg.GetNumber(3)
	//int target = arg.GetNumber(4)
	//int renderRect = arg.GetNumber(5)
	//int pageRect = arg.GetNumber(6)
	//pThis->GetEntity()->FormatRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetFirstVisibleLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetFirstVisibleLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstVisibleLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineCount)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMarginLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMarginLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarginLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarginLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMarginRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMarginRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarginRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarginRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetModify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetModify)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectedText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectedText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTextRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTextRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetTextRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HideSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HideSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int normal = arg.GetNumber(0)
	//pThis->GetEntity()->HideSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineFromPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineFromPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->LineFromPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PositionFromLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PositionFromLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->PositionFromLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineScroll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "columns", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineScroll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int columns = arg.GetNumber(0)
	//int lines = arg.GetNumber(1)
	//pThis->GetEntity()->LineScroll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EnsureCaretVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EnsureCaretVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EnsureCaretVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ScrollRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "secondary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "primary", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ScrollRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int secondary = arg.GetNumber(0)
	//int primary = arg.GetNumber(1)
	//pThis->GetEntity()->ScrollRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ReplaceSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ReplaceSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->ReplaceSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "readOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetReadOnly)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int readOnly = arg.GetNumber(0)
	//pThis->GetEntity()->SetReadOnly();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CanPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CanPaste)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CanUndo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EmptyUndoBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EmptyUndoBuffer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EmptyUndoBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Undo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Cut)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Copy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Paste)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Clear)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTextLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTextLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetOvertype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "overtype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetOvertype)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int overtype = arg.GetNumber(0)
	//pThis->GetEntity()->SetOvertype();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetOvertype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetOvertype)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOvertype();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetTargetStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetTargetStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTargetStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTargetStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetTargetEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetTargetEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTargetEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTargetEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetTargetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetTargetRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->SetTargetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTargetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTargetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ReplaceTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ReplaceTarget)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->ReplaceTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ReplaceTargetRE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ReplaceTargetRE)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->ReplaceTargetRE();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SearchInTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SearchInTarget)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SearchInTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSearchFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSearchFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetSearchFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSearchFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSearchFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSearchFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipShow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "definition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipShow)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int definition = arg.GetNumber(1)
	//pThis->GetEntity()->CallTipShow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipCancel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipCancel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CallTipCancel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipActive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CallTipActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipPosAtStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipPosAtStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CallTipPosAtStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipSetPosAtStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "posStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipSetPosAtStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int posStart = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetPosAtStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipSetHighlight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipSetHighlight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CallTipSetHighlight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipSetBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipSetBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int back = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipSetForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipSetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fore = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipSetForegroundHighlight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipSetForegroundHighlight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fore = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetForegroundHighlight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipUseStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipUseStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabSize = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipUseStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipSetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "above", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipSetPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int above = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VisibleFromDocLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VisibleFromDocLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->VisibleFromDocLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocLineFromVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineDisplay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocLineFromVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineDisplay = arg.GetNumber(0)
	//pThis->GetEntity()->DocLineFromVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WrapCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WrapCount)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->WrapCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetFoldLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetFoldLevel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//pThis->GetEntity()->SetFoldLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetFoldLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetFoldLevel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetFoldLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLastChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLastChild)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//pThis->GetEntity()->GetLastChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetFoldParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetFoldParent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetFoldParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ShowLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ShowLines)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//int lineEnd = arg.GetNumber(1)
	//pThis->GetEntity()->ShowLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HideLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HideLines)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//int lineEnd = arg.GetNumber(1)
	//pThis->GetEntity()->HideLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAllLinesVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAllLinesVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAllLinesVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetFoldExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetFoldExpanded)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int expanded = arg.GetNumber(1)
	//pThis->GetEntity()->SetFoldExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetFoldExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetFoldExpanded)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetFoldExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ToggleFold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ToggleFold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->ToggleFold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FoldLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FoldLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int action = arg.GetNumber(1)
	//pThis->GetEntity()->FoldLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FoldChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FoldChildren)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int action = arg.GetNumber(1)
	//pThis->GetEntity()->FoldChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ExpandChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ExpandChildren)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//pThis->GetEntity()->ExpandChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FoldAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FoldAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->FoldAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EnsureVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAutomaticFold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "automaticFold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAutomaticFold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int automaticFold = arg.GetNumber(0)
	//pThis->GetEntity()->SetAutomaticFold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAutomaticFold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAutomaticFold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAutomaticFold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetFoldFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetFoldFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFoldFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EnsureVisibleEnforcePolicy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EnsureVisibleEnforcePolicy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisibleEnforcePolicy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetTabIndents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabIndents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetTabIndents)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabIndents = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabIndents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTabIndents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTabIndents)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTabIndents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetBackSpaceUnIndents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bsUnIndents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetBackSpaceUnIndents)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bsUnIndents = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackSpaceUnIndents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetBackSpaceUnIndents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetBackSpaceUnIndents)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackSpaceUnIndents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMouseDwellTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "periodMilliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMouseDwellTime)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int periodMilliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->SetMouseDwellTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMouseDwellTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMouseDwellTime)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMouseDwellTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordStartPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "onlyWordCharacters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordStartPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int onlyWordCharacters = arg.GetNumber(1)
	//pThis->GetEntity()->WordStartPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordEndPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "onlyWordCharacters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordEndPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int onlyWordCharacters = arg.GetNumber(1)
	//pThis->GetEntity()->WordEndPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWrapMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWrapMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetWrapMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetWrapMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWrapVisualFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wrapVisualFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWrapVisualFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wrapVisualFlags = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapVisualFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetWrapVisualFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetWrapVisualFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapVisualFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWrapVisualFlagsLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wrapVisualFlagsLocation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWrapVisualFlagsLocation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wrapVisualFlagsLocation = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapVisualFlagsLocation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetWrapVisualFlagsLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetWrapVisualFlagsLocation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapVisualFlagsLocation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWrapStartIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWrapStartIndent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapStartIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetWrapStartIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetWrapStartIndent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapStartIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWrapIndentMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWrapIndentMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapIndentMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetWrapIndentMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetWrapIndentMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapIndentMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetLayoutCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetLayoutCache)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutCache();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLayoutCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLayoutCache)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutCache();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetScrollWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetScrollWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetScrollWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetScrollWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetScrollWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScrollWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetScrollWidthTracking)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tracking", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetScrollWidthTracking)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tracking = arg.GetNumber(0)
	//pThis->GetEntity()->SetScrollWidthTracking();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetScrollWidthTracking)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetScrollWidthTracking)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScrollWidthTracking();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, TextWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, TextWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->TextWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetEndAtLastLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "endAtLastLine", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetEndAtLastLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int endAtLastLine = arg.GetNumber(0)
	//pThis->GetEntity()->SetEndAtLastLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetEndAtLastLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetEndAtLastLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndAtLastLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, TextHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, TextHeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->TextHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetUseVerticalScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetUseVerticalScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetUseVerticalScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetUseVerticalScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetUseVerticalScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUseVerticalScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AppendText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AppendText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AppendText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTwoPhaseDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTwoPhaseDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTwoPhaseDraw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetTwoPhaseDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "twoPhase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetTwoPhaseDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int twoPhase = arg.GetNumber(0)
	//pThis->GetEntity()->SetTwoPhaseDraw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPhasesDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPhasesDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPhasesDraw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetPhasesDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "phases", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetPhasesDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int phases = arg.GetNumber(0)
	//pThis->GetEntity()->SetPhasesDraw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetFirstVisibleLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineDisplay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetFirstVisibleLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineDisplay = arg.GetNumber(0)
	//pThis->GetEntity()->SetFirstVisibleLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMultiPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "multiPaste", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMultiPaste)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int multiPaste = arg.GetNumber(0)
	//pThis->GetEntity()->SetMultiPaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMultiPaste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMultiPaste)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMultiPaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tagNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTag)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tagNumber = arg.GetNumber(0)
	//pThis->GetEntity()->GetTag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, TargetFromSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, TargetFromSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TargetFromSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LinesJoin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LinesJoin)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LinesJoin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LinesSplit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LinesSplit)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->LinesSplit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetFoldMarginColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetFoldMarginColour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useSetting = arg.GetNumber(0)
	//int back = arg.GetNumber(1)
	//pThis->GetEntity()->SetFoldMarginColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetFoldMarginHiColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetFoldMarginHiColour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useSetting = arg.GetNumber(0)
	//int fore = arg.GetNumber(1)
	//pThis->GetEntity()->SetFoldMarginHiColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineDownExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineDownExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDownExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineUpExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineUpExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineUpExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharLeftExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharLeftExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharRightExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharRightExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharRightExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordLeftExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordLeftExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordRightExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordRightExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordRightExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Home)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Home)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Home();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocumentStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocumentStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DocumentStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocumentStartExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocumentStartExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DocumentStartExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocumentEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocumentEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DocumentEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocumentEndExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocumentEndExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DocumentEndExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageUpExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageUpExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageUpExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageDownExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageDownExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageDownExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EditToggleOvertype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EditToggleOvertype)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EditToggleOvertype();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Cancel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Cancel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cancel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DeleteBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DeleteBack)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Tab)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Tab)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Tab();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BackTab)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BackTab)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BackTab();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, NewLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, NewLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->NewLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FormFeed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FormFeed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FormFeed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHome)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHome)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHome();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ZoomIn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ZoomIn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ZoomIn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ZoomOut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ZoomOut)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ZoomOut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelWordLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelWordLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelWordLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelWordRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelWordRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelWordRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelWordRightEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelWordRightEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelWordRightEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineCut)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineCut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineDelete)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDelete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineTranspose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineTranspose)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineTranspose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineDuplicate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineDuplicate)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDuplicate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LowerCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LowerCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LowerCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, UpperCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, UpperCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpperCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineScrollDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineScrollDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineScrollDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineScrollUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineScrollUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineScrollUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DeleteBackNotLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DeleteBackNotLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteBackNotLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeDisplay)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeDisplayExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeDisplayExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndDisplay)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndDisplayExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndDisplayExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeWrap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeWrap)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeWrap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeWrapExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeWrapExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndWrap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndWrap)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndWrap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndWrapExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndWrapExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeWrap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeWrap)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeWrap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeWrapExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeWrapExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineCopy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineCopy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MoveCaretInsideView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MoveCaretInsideView)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoveCaretInsideView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->LineLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BraceHighlight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BraceHighlight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos1 = arg.GetNumber(0)
	//int pos2 = arg.GetNumber(1)
	//pThis->GetEntity()->BraceHighlight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BraceHighlightIndicator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useBraceHighlightIndicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BraceHighlightIndicator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useBraceHighlightIndicator = arg.GetNumber(0)
	//int indicator = arg.GetNumber(1)
	//pThis->GetEntity()->BraceHighlightIndicator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BraceBadLight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BraceBadLight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->BraceBadLight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BraceBadLightIndicator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useBraceBadLightIndicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BraceBadLightIndicator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useBraceBadLightIndicator = arg.GetNumber(0)
	//int indicator = arg.GetNumber(1)
	//pThis->GetEntity()->BraceBadLightIndicator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BraceMatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BraceMatch)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->BraceMatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetViewEOL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetViewEOL)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewEOL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetViewEOL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetViewEOL)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->SetViewEOL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetDocPointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetDocPointer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocPointer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetDocPointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "docPointer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetDocPointer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int docPointer = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocPointer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetModEventMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetModEventMask)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mask = arg.GetNumber(0)
	//pThis->GetEntity()->SetModEventMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetEdgeColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetEdgeColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEdgeColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetEdgeColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetEdgeColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdgeColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetEdgeMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetEdgeMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEdgeMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetEdgeMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetEdgeMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdgeMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetEdgeColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetEdgeColour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEdgeColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetEdgeColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edgeColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetEdgeColour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int edgeColour = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdgeColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SearchAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SearchAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SearchAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SearchNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SearchNext)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SearchNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SearchPrev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SearchPrev)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SearchPrev();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LinesOnScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LinesOnScreen)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LinesOnScreen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, UsePopUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "allowPopUp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, UsePopUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int allowPopUp = arg.GetNumber(0)
	//pThis->GetEntity()->UsePopUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SelectionIsRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SelectionIsRectangle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectionIsRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetZoom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "zoom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetZoom)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int zoom = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetZoom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetZoom)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetZoom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CreateDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CreateDocument)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AddRefDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "docPointer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AddRefDocument)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int docPointer = arg.GetNumber(0)
	//pThis->GetEntity()->AddRefDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ReleaseDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "docPointer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ReleaseDocument)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int docPointer = arg.GetNumber(0)
	//pThis->GetEntity()->ReleaseDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetModEventMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetModEventMask)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModEventMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSTCFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSTCFocus)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int focus = arg.GetNumber(0)
	//pThis->GetEntity()->SetSTCFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSTCFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSTCFocus)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSTCFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "statusCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetStatus)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int statusCode = arg.GetNumber(0)
	//pThis->GetEntity()->SetStatus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetStatus)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStatus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMouseDownCaptures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "captures", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMouseDownCaptures)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int captures = arg.GetNumber(0)
	//pThis->GetEntity()->SetMouseDownCaptures();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMouseDownCaptures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMouseDownCaptures)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMouseDownCaptures();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSTCCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursorType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSTCCursor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursorType = arg.GetNumber(0)
	//pThis->GetEntity()->SetSTCCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSTCCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSTCCursor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSTCCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetControlCharSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetControlCharSymbol)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int symbol = arg.GetNumber(0)
	//pThis->GetEntity()->SetControlCharSymbol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetControlCharSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetControlCharSymbol)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetControlCharSymbol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordPartLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordPartLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordPartLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordPartLeftExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordPartLeftExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordPartLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordPartRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordPartRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordPartRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordPartRightExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordPartRightExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordPartRightExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetVisiblePolicy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visiblePolicy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "visibleSlop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetVisiblePolicy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visiblePolicy = arg.GetNumber(0)
	//int visibleSlop = arg.GetNumber(1)
	//pThis->GetEntity()->SetVisiblePolicy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelLineLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelLineLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelLineLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelLineRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelLineRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelLineRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetXOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newOffset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetXOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newOffset = arg.GetNumber(0)
	//pThis->GetEntity()->SetXOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetXOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetXOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ChooseCaretX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ChooseCaretX)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ChooseCaretX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetXCaretPolicy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPolicy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretSlop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetXCaretPolicy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPolicy = arg.GetNumber(0)
	//int caretSlop = arg.GetNumber(1)
	//pThis->GetEntity()->SetXCaretPolicy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetYCaretPolicy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPolicy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretSlop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetYCaretPolicy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPolicy = arg.GetNumber(0)
	//int caretSlop = arg.GetNumber(1)
	//pThis->GetEntity()->SetYCaretPolicy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetPrintWrapMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetPrintWrapMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintWrapMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPrintWrapMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPrintWrapMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintWrapMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetHotspotActiveForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetHotspotActiveForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useSetting = arg.GetNumber(0)
	//int fore = arg.GetNumber(1)
	//pThis->GetEntity()->SetHotspotActiveForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetHotspotActiveForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetHotspotActiveForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotActiveForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetHotspotActiveBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetHotspotActiveBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useSetting = arg.GetNumber(0)
	//int back = arg.GetNumber(1)
	//pThis->GetEntity()->SetHotspotActiveBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetHotspotActiveBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetHotspotActiveBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotActiveBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetHotspotActiveUnderline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetHotspotActiveUnderline)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int underline = arg.GetNumber(0)
	//pThis->GetEntity()->SetHotspotActiveUnderline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetHotspotActiveUnderline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetHotspotActiveUnderline)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotActiveUnderline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetHotspotSingleLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "singleLine", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetHotspotSingleLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int singleLine = arg.GetNumber(0)
	//pThis->GetEntity()->SetHotspotSingleLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetHotspotSingleLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetHotspotSingleLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotSingleLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ParaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ParaDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParaDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ParaDownExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ParaDownExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParaDownExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ParaUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ParaUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParaUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ParaUpExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ParaUpExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParaUpExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PositionBefore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PositionBefore)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->PositionBefore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PositionAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PositionAfter)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->PositionAfter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PositionRelative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PositionRelative)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int relative = arg.GetNumber(1)
	//pThis->GetEntity()->PositionRelative();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CopyRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CopyRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CopyRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CopyText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CopyText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->CopyText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineSelStartPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineSelStartPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineSelStartPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineSelEndPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineSelEndPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineSelEndPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineDownRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineDownRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDownRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineUpRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineUpRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineUpRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharLeftRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharLeftRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharLeftRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharRightRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharRightRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharRightRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageUpRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageUpRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageUpRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageDownRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageDownRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageDownRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StutteredPageUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StutteredPageUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StutteredPageUpExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StutteredPageUpExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageUpExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StutteredPageDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StutteredPageDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StutteredPageDownExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StutteredPageDownExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageDownExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordLeftEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordLeftEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordLeftEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordLeftEndExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordLeftEndExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordLeftEndExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordRightEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordRightEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordRightEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordRightEndExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordRightEndExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordRightEndExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetWhitespaceChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetWhitespaceChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characters = arg.GetNumber(0)
	//pThis->GetEntity()->SetWhitespaceChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetWhitespaceChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetWhitespaceChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWhitespaceChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetPunctuationChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetPunctuationChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characters = arg.GetNumber(0)
	//pThis->GetEntity()->SetPunctuationChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPunctuationChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPunctuationChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPunctuationChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCharsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCharsDefault)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetCharsDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetCurrent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetCaseInsensitiveBehaviour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "behaviour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetCaseInsensitiveBehaviour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int behaviour = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetCaseInsensitiveBehaviour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetCaseInsensitiveBehaviour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetCaseInsensitiveBehaviour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetCaseInsensitiveBehaviour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetMulti)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "multi", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetMulti)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int multi = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetMulti();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetMulti)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetMulti)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetMulti();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompSetOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompSetOrder)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int order = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetOrder)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Allocate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Allocate)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bytes = arg.GetNumber(0)
	//pThis->GetEntity()->Allocate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FindColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FindColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->FindColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretSticky)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretSticky)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretSticky();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretSticky)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useCaretStickyBehaviour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretSticky)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useCaretStickyBehaviour = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretSticky();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ToggleCaretSticky)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ToggleCaretSticky)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToggleCaretSticky();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetPasteConvertEndings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "convert", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetPasteConvertEndings)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int convert = arg.GetNumber(0)
	//pThis->GetEntity()->SetPasteConvertEndings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPasteConvertEndings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPasteConvertEndings)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPasteConvertEndings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SelectionDuplicate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SelectionDuplicate)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectionDuplicate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretLineBackAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretLineBackAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alpha = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretLineBackAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretLineBackAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretLineBackAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretLineBackAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretStyle = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetIndicatorCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetIndicatorCurrent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndicatorCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetIndicatorCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetIndicatorCurrent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndicatorCurrent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetIndicatorValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetIndicatorValue)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndicatorValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetIndicatorValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetIndicatorValue)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndicatorValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorFillRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorFillRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int fillLength = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorFillRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorClearRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clearLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorClearRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int clearLength = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorClearRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorAllOnFor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorAllOnFor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorAllOnFor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorValueAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorValueAt)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorValueAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetPositionCacheSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetPositionCacheSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetPositionCacheSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPositionCacheSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPositionCacheSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPositionCacheSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CopyAllowLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CopyAllowLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CopyAllowLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCharacterPointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCharacterPointer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCharacterPointer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetRangePointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rangeLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetRangePointer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int rangeLength = arg.GetNumber(1)
	//pThis->GetEntity()->GetRangePointer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetGapPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetGapPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGapPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorSetAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorSetAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int alpha = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorGetAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorGetAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorSetOutlineAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorSetOutlineAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int alpha = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetOutlineAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IndicatorGetOutlineAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IndicatorGetOutlineAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetOutlineAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetExtraAscent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extraAscent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetExtraAscent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extraAscent = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraAscent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetExtraAscent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetExtraAscent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraAscent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetExtraDescent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extraDescent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetExtraDescent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extraDescent = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraDescent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetExtraDescent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetExtraDescent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraDescent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarkerSymbolDefined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarkerSymbolDefined)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarkerSymbolDefined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginSetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginSetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->MarginSetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginGetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginGetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->MarginGetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginSetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginSetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->MarginSetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginGetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginGetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->MarginGetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginSetStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginSetStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int styles = arg.GetNumber(1)
	//pThis->GetEntity()->MarginSetStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginGetStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginGetStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->MarginGetStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginTextClearAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginTextClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarginTextClearAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginSetStyleOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginSetStyleOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->MarginSetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarginGetStyleOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarginGetStyleOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarginGetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMarginOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "marginOptions", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMarginOptions)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int marginOptions = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginOptions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMarginOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMarginOptions)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginOptions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationSetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationSetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->AnnotationSetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationGetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationGetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationGetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationSetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationSetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->AnnotationSetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationGetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationGetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationGetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationSetStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationSetStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int styles = arg.GetNumber(1)
	//pThis->GetEntity()->AnnotationSetStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationGetStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationGetStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationGetStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationGetLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationGetLines)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationGetLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationClearAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AnnotationClearAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationSetVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationSetVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationSetVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationGetVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationGetVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AnnotationGetVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationSetStyleOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationSetStyleOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationSetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationGetStyleOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationGetStyleOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AnnotationGetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ReleaseAllExtendedStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ReleaseAllExtendedStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReleaseAllExtendedStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AllocateExtendedStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numberStyles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AllocateExtendedStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numberStyles = arg.GetNumber(0)
	//pThis->GetEntity()->AllocateExtendedStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AddUndoAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "token", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AddUndoAction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int token = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->AddUndoAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharPositionFromPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharPositionFromPoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->CharPositionFromPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharPositionFromPointClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharPositionFromPointClose)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->CharPositionFromPointClose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMouseSelectionRectangularSwitch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mouseSelectionRectangularSwitch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMouseSelectionRectangularSwitch)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mouseSelectionRectangularSwitch = arg.GetNumber(0)
	//pThis->GetEntity()->SetMouseSelectionRectangularSwitch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMouseSelectionRectangularSwitch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMouseSelectionRectangularSwitch)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMouseSelectionRectangularSwitch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMultipleSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "multipleSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMultipleSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int multipleSelection = arg.GetNumber(0)
	//pThis->GetEntity()->SetMultipleSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMultipleSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMultipleSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMultipleSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAdditionalSelectionTyping)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "additionalSelectionTyping", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAdditionalSelectionTyping)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int additionalSelectionTyping = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalSelectionTyping();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAdditionalSelectionTyping)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAdditionalSelectionTyping)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalSelectionTyping();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAdditionalCaretsBlink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "additionalCaretsBlink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAdditionalCaretsBlink)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int additionalCaretsBlink = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalCaretsBlink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAdditionalCaretsBlink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAdditionalCaretsBlink)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalCaretsBlink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAdditionalCaretsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "additionalCaretsBlink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAdditionalCaretsVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int additionalCaretsBlink = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalCaretsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAdditionalCaretsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAdditionalCaretsVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalCaretsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelections)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionEmpty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ClearSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ClearSelections)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AddSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caret", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AddSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caret = arg.GetNumber(0)
	//int anchor = arg.GetNumber(1)
	//pThis->GetEntity()->AddSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DropSelectionN)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DropSelectionN)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->DropSelectionN();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMainSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMainSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->SetMainSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetMainSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetMainSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMainSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionNCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionNCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionNCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionNCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionNAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "posAnchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionNAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int posAnchor = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionNAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionNAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionNCaretVirtualSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "space", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionNCaretVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int space = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNCaretVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionNCaretVirtualSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionNCaretVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNCaretVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionNAnchorVirtualSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "space", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionNAnchorVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int space = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNAnchorVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionNAnchorVirtualSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionNAnchorVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNAnchorVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionNStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionNStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionNStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionNStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelectionNEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelectionNEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionNEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionNEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetRectangularSelectionCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetRectangularSelectionCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetRectangularSelectionCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetRectangularSelectionCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetRectangularSelectionAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "posAnchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetRectangularSelectionAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int posAnchor = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetRectangularSelectionAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetRectangularSelectionAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetRectangularSelectionCaretVirtualSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "space", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetRectangularSelectionCaretVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int space = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionCaretVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetRectangularSelectionCaretVirtualSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetRectangularSelectionCaretVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionCaretVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetRectangularSelectionAnchorVirtualSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "space", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetRectangularSelectionAnchorVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int space = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionAnchorVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetRectangularSelectionAnchorVirtualSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetRectangularSelectionAnchorVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionAnchorVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetVirtualSpaceOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "virtualSpaceOptions", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetVirtualSpaceOptions)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int virtualSpaceOptions = arg.GetNumber(0)
	//pThis->GetEntity()->SetVirtualSpaceOptions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetVirtualSpaceOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetVirtualSpaceOptions)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVirtualSpaceOptions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetRectangularSelectionModifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetRectangularSelectionModifier)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int modifier = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionModifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetRectangularSelectionModifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetRectangularSelectionModifier)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionModifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAdditionalSelForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAdditionalSelForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fore = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalSelForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAdditionalSelBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAdditionalSelBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int back = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalSelBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAdditionalSelAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAdditionalSelAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alpha = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalSelAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAdditionalSelAlpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAdditionalSelAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalSelAlpha();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetAdditionalCaretForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetAdditionalCaretForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fore = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAdditionalCaretForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAdditionalCaretForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, RotateSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, RotateSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RotateSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SwapMainAnchorCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SwapMainAnchorCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SwapMainAnchorCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ChangeLexerState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ChangeLexerState)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->ChangeLexerState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ContractedFoldNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ContractedFoldNext)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//pThis->GetEntity()->ContractedFoldNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VerticalCentreCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VerticalCentreCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VerticalCentreCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MoveSelectedLinesUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MoveSelectedLinesUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoveSelectedLinesUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MoveSelectedLinesDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MoveSelectedLinesDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoveSelectedLinesDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetIdentifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "identifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetIdentifier)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int identifier = arg.GetNumber(0)
	//pThis->GetEntity()->SetIdentifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetIdentifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetIdentifier)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIdentifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, RGBAImageSetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, RGBAImageSetWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->RGBAImageSetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, RGBAImageSetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, RGBAImageSetHeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->RGBAImageSetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, RGBAImageSetScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scalePercent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, RGBAImageSetScale)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int scalePercent = arg.GetNumber(0)
	//pThis->GetEntity()->RGBAImageSetScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkerDefineRGBAImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkerDefineRGBAImage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int pixels = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerDefineRGBAImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, RegisterRGBAImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, RegisterRGBAImage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int pixels = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterRGBAImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ScrollToStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ScrollToStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ScrollToStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ScrollToEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ScrollToEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ScrollToEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetTechnology)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "technology", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetTechnology)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int technology = arg.GetNumber(0)
	//pThis->GetEntity()->SetTechnology();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTechnology)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTechnology)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTechnology();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CreateLoader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CreateLoader)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bytes = arg.GetNumber(0)
	//pThis->GetEntity()->CreateLoader();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeDisplay)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeDisplayExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeDisplayExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretLineVisibleAlways)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretLineVisibleAlways)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretLineVisibleAlways();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCaretLineVisibleAlways)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alwaysVisible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCaretLineVisibleAlways)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alwaysVisible = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretLineVisibleAlways();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetLineEndTypesAllowed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineEndBitSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetLineEndTypesAllowed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineEndBitSet = arg.GetNumber(0)
	//pThis->GetEntity()->SetLineEndTypesAllowed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineEndTypesAllowed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineEndTypesAllowed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineEndTypesAllowed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineEndTypesActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineEndTypesActive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineEndTypesActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetRepresentation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encodedCharacter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "representation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetRepresentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encodedCharacter = arg.GetNumber(0)
	//int representation = arg.GetNumber(1)
	//pThis->GetEntity()->SetRepresentation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetRepresentation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encodedCharacter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetRepresentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encodedCharacter = arg.GetNumber(0)
	//pThis->GetEntity()->GetRepresentation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ClearRepresentation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encodedCharacter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ClearRepresentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encodedCharacter = arg.GetNumber(0)
	//pThis->GetEntity()->ClearRepresentation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StartRecord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StartRecord)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StartRecord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StopRecord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StopRecord)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StopRecord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetLexer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lexer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetLexer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lexer = arg.GetNumber(0)
	//pThis->GetEntity()->SetLexer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLexer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLexer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLexer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Colourise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Colourise)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->Colourise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetProperty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetKeyWords)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keywordSet", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keyWords", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetKeyWords)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keywordSet = arg.GetNumber(0)
	//int keyWords = arg.GetNumber(1)
	//pThis->GetEntity()->SetKeyWords();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetLexerLanguage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "language", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetLexerLanguage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int language = arg.GetNumber(0)
	//pThis->GetEntity()->SetLexerLanguage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetProperty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPropertyExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPropertyExpanded)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPropertyInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPropertyInt)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetStyleBitsNeeded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetStyleBitsNeeded)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleBitsNeeded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PrivateLexerCall)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "operation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pointer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PrivateLexerCall)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int operation = arg.GetNumber(0)
	//int pointer = arg.GetNumber(1)
	//pThis->GetEntity()->PrivateLexerCall();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PropertyNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PropertyNames)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PropertyNames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PropertyType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PropertyType)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->PropertyType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DescribeProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DescribeProperty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->DescribeProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DescribeKeyWordSets)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DescribeKeyWordSets)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DescribeKeyWordSets();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineEndTypesSupported)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineEndTypesSupported)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineEndTypesSupported();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AllocateSubStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleBase", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numberStyles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AllocateSubStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleBase = arg.GetNumber(0)
	//int numberStyles = arg.GetNumber(1)
	//pThis->GetEntity()->AllocateSubStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSubStylesStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleBase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSubStylesStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleBase = arg.GetNumber(0)
	//pThis->GetEntity()->GetSubStylesStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSubStylesLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleBase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSubStylesLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleBase = arg.GetNumber(0)
	//pThis->GetEntity()->GetSubStylesLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetStyleFromSubStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "subStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetStyleFromSubStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int subStyle = arg.GetNumber(0)
	//pThis->GetEntity()->GetStyleFromSubStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetPrimaryStyleFromStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetPrimaryStyleFromStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->GetPrimaryStyleFromStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FreeSubStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FreeSubStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FreeSubStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetIdentifiers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "identifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetIdentifiers)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int identifiers = arg.GetNumber(1)
	//pThis->GetEntity()->SetIdentifiers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DistanceToSecondaryStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DistanceToSecondaryStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DistanceToSecondaryStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSubStyleBases)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSubStyleBases)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSubStyleBases();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCurrentLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCurrentLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetSpec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleNum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "spec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetSpec)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleNum = arg.GetNumber(0)
	//int spec = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetSpec();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleGetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleGetFont)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleNum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetFont)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleNum = arg.GetNumber(0)
	//int font = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetFontAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleNum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bold", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "italic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetFontAttr)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleNum = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int faceName = arg.GetNumber(2)
	//int bold = arg.GetNumber(3)
	//int italic = arg.GetNumber(4)
	//int underline = arg.GetNumber(5)
	//int encoding = arg.GetNumber(6)
	//pThis->GetEntity()->StyleSetFontAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetCharacterSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "characterSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetCharacterSet)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int characterSet = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetCharacterSet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StyleSetFontEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StyleSetFontEncoding)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetFontEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CmdKeyExecute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CmdKeyExecute)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmd = arg.GetNumber(0)
	//pThis->GetEntity()->CmdKeyExecute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetMargins)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int right = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PointFromPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PointFromPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->PointFromPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ScrollToLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ScrollToLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollToLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ScrollToColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ScrollToColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollToColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SendMsg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SendMsg)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//int wp = arg.GetNumber(1)
	//int lp = arg.GetNumber(2)
	//pThis->GetEntity()->SendMsg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetVScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetVScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bar = arg.GetNumber(0)
	//pThis->GetEntity()->SetVScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetHScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetHScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bar = arg.GetNumber(0)
	//pThis->GetEntity()->SetHScrollBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLastKeydownProcessed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLastKeydownProcessed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastKeydownProcessed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetLastKeydownProcessed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetLastKeydownProcessed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->SetLastKeydownProcessed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SaveFile)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LoadFile)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DoDragEnter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultRes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DoDragEnter)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int defaultRes = arg.GetNumber(2)
	//pThis->GetEntity()->DoDragEnter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DoDragOver)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultRes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DoDragOver)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int defaultRes = arg.GetNumber(2)
	//pThis->GetEntity()->DoDragOver();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DoDragLeave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DoDragLeave)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoDragLeave();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DoDropText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DoDropText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//pThis->GetEntity()->DoDropText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AnnotationClearLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AnnotationClearLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationClearLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AddTextRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AddTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int length = arg.GetNumber(1)
	//pThis->GetEntity()->AddTextRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, InsertTextRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, InsertTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->InsertTextRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCurLineRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "linePos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCurLineRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int linePos = arg.GetNumber(0)
	//pThis->GetEntity()->GetCurLineRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectedTextRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectedTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedTextRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTextRangeRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTextRangeRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetTextRangeRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetTextRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTextRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AppendTextRaw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AppendTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int length = arg.GetNumber(1)
	//pThis->GetEntity()->AppendTextRaw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLibraryVersionInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLibraryVersionInfo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLibraryVersionInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WriteText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WriteText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->WriteText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Remove)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Replace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetInsertionPoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetInsertionPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetInsertionPoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLastPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLastPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SelectNone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SelectNone)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectNone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IsEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IsEditable)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetEditable)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int editable = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetNumberOfLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetNumberOfLines)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberOfLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IsModified)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkDirty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkDirty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarkDirty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DiscardEdits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DiscardEdits)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DiscardEdits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetDefaultStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, XYToPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, XYToPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->XYToPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PositionToXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PositionToXY)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->PositionToXY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ShowPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ShowPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HitTest)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HitTest_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HitTest_1)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int row = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStyledTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StyledTextCtrl)
{
	Gura_AssignMethod(wx_StyledTextCtrl, wxStyledTextCtrl);
	Gura_AssignMethod(wx_StyledTextCtrl, wxStyledTextCtrl_1);
	Gura_AssignMethod(wx_StyledTextCtrl, Create);
	Gura_AssignMethod(wx_StyledTextCtrl, AddText);
	Gura_AssignMethod(wx_StyledTextCtrl, AddStyledText);
	Gura_AssignMethod(wx_StyledTextCtrl, InsertText);
	Gura_AssignMethod(wx_StyledTextCtrl, ChangeInsertion);
	Gura_AssignMethod(wx_StyledTextCtrl, ClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, DeleteRange);
	Gura_AssignMethod(wx_StyledTextCtrl, ClearDocumentStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLength);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCharAt);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCurrentPos);
	Gura_AssignMethod(wx_StyledTextCtrl, GetAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, GetStyleAt);
	Gura_AssignMethod(wx_StyledTextCtrl, Redo);
	Gura_AssignMethod(wx_StyledTextCtrl, SetUndoCollection);
	Gura_AssignMethod(wx_StyledTextCtrl, SelectAll);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSavePoint);
	Gura_AssignMethod(wx_StyledTextCtrl, GetStyledText);
	Gura_AssignMethod(wx_StyledTextCtrl, CanRedo);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerLineFromHandle);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerDeleteHandle);
	Gura_AssignMethod(wx_StyledTextCtrl, GetUndoCollection);
	Gura_AssignMethod(wx_StyledTextCtrl, GetViewWhiteSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, SetViewWhiteSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, PositionFromPoint);
	Gura_AssignMethod(wx_StyledTextCtrl, PositionFromPointClose);
	Gura_AssignMethod(wx_StyledTextCtrl, GotoLine);
	Gura_AssignMethod(wx_StyledTextCtrl, GotoPos);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCurLine);
	Gura_AssignMethod(wx_StyledTextCtrl, GetEndStyled);
	Gura_AssignMethod(wx_StyledTextCtrl, ConvertEOLs);
	Gura_AssignMethod(wx_StyledTextCtrl, GetEOLMode);
	Gura_AssignMethod(wx_StyledTextCtrl, SetEOLMode);
	Gura_AssignMethod(wx_StyledTextCtrl, StartStyling);
	Gura_AssignMethod(wx_StyledTextCtrl, SetStyling);
	Gura_AssignMethod(wx_StyledTextCtrl, GetBufferedDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, SetBufferedDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, SetTabWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTabWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, ClearTabStops);
	Gura_AssignMethod(wx_StyledTextCtrl, AddTabStop);
	Gura_AssignMethod(wx_StyledTextCtrl, GetNextTabStop);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCodePage);
	Gura_AssignMethod(wx_StyledTextCtrl, GetIMEInteraction);
	Gura_AssignMethod(wx_StyledTextCtrl, SetIMEInteraction);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerDefine);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerSetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerSetBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerSetBackgroundSelected);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerEnableHighlight);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerAdd);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerDelete);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerDeleteAll);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerGet);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerNext);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerPrevious);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerDefineBitmap);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerAddSet);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerSetAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMarginType);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarginType);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMarginWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarginWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMarginMask);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarginMask);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMarginSensitive);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarginSensitive);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMarginCursor);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarginCursor);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetBold);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetItalic);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetSize);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetFaceName);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetEOLFilled);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleResetDefault);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetUnderline);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetBold);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetItalic);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetSize);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetFaceName);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetEOLFilled);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetUnderline);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetCase);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetCharacterSet);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetChangeable);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetHotSpot);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetCase);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetSizeFractional);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetSizeFractional);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetWeight);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetWeight);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetHotSpot);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelEOLFilled);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelEOLFilled);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, CmdKeyAssign);
	Gura_AssignMethod(wx_StyledTextCtrl, CmdKeyClear);
	Gura_AssignMethod(wx_StyledTextCtrl, CmdKeyClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, SetStyleBytes);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretPeriod);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretPeriod);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWordChars);
	Gura_AssignMethod(wx_StyledTextCtrl, GetWordChars);
	Gura_AssignMethod(wx_StyledTextCtrl, BeginUndoAction);
	Gura_AssignMethod(wx_StyledTextCtrl, EndUndoAction);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorSetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorGetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorSetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorGetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorSetUnder);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorGetUnder);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorSetHoverStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorGetHoverStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorSetHoverForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorGetHoverForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorSetFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorGetFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWhitespaceForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWhitespaceBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWhitespaceSize);
	Gura_AssignMethod(wx_StyledTextCtrl, GetWhitespaceSize);
	Gura_AssignMethod(wx_StyledTextCtrl, SetStyleBits);
	Gura_AssignMethod(wx_StyledTextCtrl, GetStyleBits);
	Gura_AssignMethod(wx_StyledTextCtrl, SetLineState);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineState);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMaxLineState);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretLineVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretLineVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretLineBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretLineBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetChangeable);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompShow);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompCancel);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompActive);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompPosStart);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompComplete);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompStops);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetSeparator);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetSeparator);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSelect);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetCancelAtStart);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetCancelAtStart);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetFillUps);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetChooseSingle);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetChooseSingle);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetIgnoreCase);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetIgnoreCase);
	Gura_AssignMethod(wx_StyledTextCtrl, UserListShow);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetAutoHide);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetAutoHide);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetDropRestOfWord);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetDropRestOfWord);
	Gura_AssignMethod(wx_StyledTextCtrl, RegisterImage);
	Gura_AssignMethod(wx_StyledTextCtrl, ClearRegisteredImages);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetTypeSeparator);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetTypeSeparator);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetMaxWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetMaxWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetMaxHeight);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetMaxHeight);
	Gura_AssignMethod(wx_StyledTextCtrl, SetIndent);
	Gura_AssignMethod(wx_StyledTextCtrl, GetIndent);
	Gura_AssignMethod(wx_StyledTextCtrl, SetUseTabs);
	Gura_AssignMethod(wx_StyledTextCtrl, GetUseTabs);
	Gura_AssignMethod(wx_StyledTextCtrl, SetLineIndentation);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineIndentation);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineIndentPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, GetColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, CountCharacters);
	Gura_AssignMethod(wx_StyledTextCtrl, SetUseHorizontalScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, GetUseHorizontalScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, SetIndentationGuides);
	Gura_AssignMethod(wx_StyledTextCtrl, GetIndentationGuides);
	Gura_AssignMethod(wx_StyledTextCtrl, SetHighlightGuide);
	Gura_AssignMethod(wx_StyledTextCtrl, GetHighlightGuide);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineEndPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCodePage);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, GetReadOnly);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCurrentPos);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionStart);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionStart);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, SetEmptySelection);
	Gura_AssignMethod(wx_StyledTextCtrl, SetPrintMagnification);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPrintMagnification);
	Gura_AssignMethod(wx_StyledTextCtrl, SetPrintColourMode);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPrintColourMode);
	Gura_AssignMethod(wx_StyledTextCtrl, FindText);
	Gura_AssignMethod(wx_StyledTextCtrl, FormatRange);
	Gura_AssignMethod(wx_StyledTextCtrl, GetFirstVisibleLine);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLine);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineCount);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMarginLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarginLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMarginRight);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarginRight);
	Gura_AssignMethod(wx_StyledTextCtrl, GetModify);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectedText);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTextRange);
	Gura_AssignMethod(wx_StyledTextCtrl, HideSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, LineFromPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, PositionFromLine);
	Gura_AssignMethod(wx_StyledTextCtrl, LineScroll);
	Gura_AssignMethod(wx_StyledTextCtrl, EnsureCaretVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, ScrollRange);
	Gura_AssignMethod(wx_StyledTextCtrl, ReplaceSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, SetReadOnly);
	Gura_AssignMethod(wx_StyledTextCtrl, CanPaste);
	Gura_AssignMethod(wx_StyledTextCtrl, CanUndo);
	Gura_AssignMethod(wx_StyledTextCtrl, EmptyUndoBuffer);
	Gura_AssignMethod(wx_StyledTextCtrl, Undo);
	Gura_AssignMethod(wx_StyledTextCtrl, Cut);
	Gura_AssignMethod(wx_StyledTextCtrl, Copy);
	Gura_AssignMethod(wx_StyledTextCtrl, Paste);
	Gura_AssignMethod(wx_StyledTextCtrl, Clear);
	Gura_AssignMethod(wx_StyledTextCtrl, SetText);
	Gura_AssignMethod(wx_StyledTextCtrl, GetText);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTextLength);
	Gura_AssignMethod(wx_StyledTextCtrl, SetOvertype);
	Gura_AssignMethod(wx_StyledTextCtrl, GetOvertype);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, SetTargetStart);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTargetStart);
	Gura_AssignMethod(wx_StyledTextCtrl, SetTargetEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTargetEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, SetTargetRange);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTargetText);
	Gura_AssignMethod(wx_StyledTextCtrl, ReplaceTarget);
	Gura_AssignMethod(wx_StyledTextCtrl, ReplaceTargetRE);
	Gura_AssignMethod(wx_StyledTextCtrl, SearchInTarget);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSearchFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSearchFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipShow);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipCancel);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipActive);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipPosAtStart);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipSetPosAtStart);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipSetHighlight);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipSetBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipSetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipSetForegroundHighlight);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipUseStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, CallTipSetPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, VisibleFromDocLine);
	Gura_AssignMethod(wx_StyledTextCtrl, DocLineFromVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, WrapCount);
	Gura_AssignMethod(wx_StyledTextCtrl, SetFoldLevel);
	Gura_AssignMethod(wx_StyledTextCtrl, GetFoldLevel);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLastChild);
	Gura_AssignMethod(wx_StyledTextCtrl, GetFoldParent);
	Gura_AssignMethod(wx_StyledTextCtrl, ShowLines);
	Gura_AssignMethod(wx_StyledTextCtrl, HideLines);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, GetAllLinesVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, SetFoldExpanded);
	Gura_AssignMethod(wx_StyledTextCtrl, GetFoldExpanded);
	Gura_AssignMethod(wx_StyledTextCtrl, ToggleFold);
	Gura_AssignMethod(wx_StyledTextCtrl, FoldLine);
	Gura_AssignMethod(wx_StyledTextCtrl, FoldChildren);
	Gura_AssignMethod(wx_StyledTextCtrl, ExpandChildren);
	Gura_AssignMethod(wx_StyledTextCtrl, FoldAll);
	Gura_AssignMethod(wx_StyledTextCtrl, EnsureVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAutomaticFold);
	Gura_AssignMethod(wx_StyledTextCtrl, GetAutomaticFold);
	Gura_AssignMethod(wx_StyledTextCtrl, SetFoldFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, EnsureVisibleEnforcePolicy);
	Gura_AssignMethod(wx_StyledTextCtrl, SetTabIndents);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTabIndents);
	Gura_AssignMethod(wx_StyledTextCtrl, SetBackSpaceUnIndents);
	Gura_AssignMethod(wx_StyledTextCtrl, GetBackSpaceUnIndents);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMouseDwellTime);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMouseDwellTime);
	Gura_AssignMethod(wx_StyledTextCtrl, WordStartPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, WordEndPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWrapMode);
	Gura_AssignMethod(wx_StyledTextCtrl, GetWrapMode);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWrapVisualFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, GetWrapVisualFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWrapVisualFlagsLocation);
	Gura_AssignMethod(wx_StyledTextCtrl, GetWrapVisualFlagsLocation);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWrapStartIndent);
	Gura_AssignMethod(wx_StyledTextCtrl, GetWrapStartIndent);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWrapIndentMode);
	Gura_AssignMethod(wx_StyledTextCtrl, GetWrapIndentMode);
	Gura_AssignMethod(wx_StyledTextCtrl, SetLayoutCache);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLayoutCache);
	Gura_AssignMethod(wx_StyledTextCtrl, SetScrollWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, GetScrollWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, SetScrollWidthTracking);
	Gura_AssignMethod(wx_StyledTextCtrl, GetScrollWidthTracking);
	Gura_AssignMethod(wx_StyledTextCtrl, TextWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, SetEndAtLastLine);
	Gura_AssignMethod(wx_StyledTextCtrl, GetEndAtLastLine);
	Gura_AssignMethod(wx_StyledTextCtrl, TextHeight);
	Gura_AssignMethod(wx_StyledTextCtrl, SetUseVerticalScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, GetUseVerticalScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, AppendText);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTwoPhaseDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, SetTwoPhaseDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPhasesDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, SetPhasesDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, SetFirstVisibleLine);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMultiPaste);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMultiPaste);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTag);
	Gura_AssignMethod(wx_StyledTextCtrl, TargetFromSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, LinesJoin);
	Gura_AssignMethod(wx_StyledTextCtrl, LinesSplit);
	Gura_AssignMethod(wx_StyledTextCtrl, SetFoldMarginColour);
	Gura_AssignMethod(wx_StyledTextCtrl, SetFoldMarginHiColour);
	Gura_AssignMethod(wx_StyledTextCtrl, LineDown);
	Gura_AssignMethod(wx_StyledTextCtrl, LineDownExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, LineUp);
	Gura_AssignMethod(wx_StyledTextCtrl, LineUpExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, CharLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, CharLeftExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, CharRight);
	Gura_AssignMethod(wx_StyledTextCtrl, CharRightExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, WordLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, WordLeftExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, WordRight);
	Gura_AssignMethod(wx_StyledTextCtrl, WordRightExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, Home);
	Gura_AssignMethod(wx_StyledTextCtrl, HomeExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, LineEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, LineEndExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, DocumentStart);
	Gura_AssignMethod(wx_StyledTextCtrl, DocumentStartExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, DocumentEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, DocumentEndExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, PageUp);
	Gura_AssignMethod(wx_StyledTextCtrl, PageUpExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, PageDown);
	Gura_AssignMethod(wx_StyledTextCtrl, PageDownExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, EditToggleOvertype);
	Gura_AssignMethod(wx_StyledTextCtrl, Cancel);
	Gura_AssignMethod(wx_StyledTextCtrl, DeleteBack);
	Gura_AssignMethod(wx_StyledTextCtrl, Tab);
	Gura_AssignMethod(wx_StyledTextCtrl, BackTab);
	Gura_AssignMethod(wx_StyledTextCtrl, NewLine);
	Gura_AssignMethod(wx_StyledTextCtrl, FormFeed);
	Gura_AssignMethod(wx_StyledTextCtrl, VCHome);
	Gura_AssignMethod(wx_StyledTextCtrl, VCHomeExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, ZoomIn);
	Gura_AssignMethod(wx_StyledTextCtrl, ZoomOut);
	Gura_AssignMethod(wx_StyledTextCtrl, DelWordLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, DelWordRight);
	Gura_AssignMethod(wx_StyledTextCtrl, DelWordRightEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, LineCut);
	Gura_AssignMethod(wx_StyledTextCtrl, LineDelete);
	Gura_AssignMethod(wx_StyledTextCtrl, LineTranspose);
	Gura_AssignMethod(wx_StyledTextCtrl, LineDuplicate);
	Gura_AssignMethod(wx_StyledTextCtrl, LowerCase);
	Gura_AssignMethod(wx_StyledTextCtrl, UpperCase);
	Gura_AssignMethod(wx_StyledTextCtrl, LineScrollDown);
	Gura_AssignMethod(wx_StyledTextCtrl, LineScrollUp);
	Gura_AssignMethod(wx_StyledTextCtrl, DeleteBackNotLine);
	Gura_AssignMethod(wx_StyledTextCtrl, HomeDisplay);
	Gura_AssignMethod(wx_StyledTextCtrl, HomeDisplayExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, LineEndDisplay);
	Gura_AssignMethod(wx_StyledTextCtrl, LineEndDisplayExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, HomeWrap);
	Gura_AssignMethod(wx_StyledTextCtrl, HomeWrapExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, LineEndWrap);
	Gura_AssignMethod(wx_StyledTextCtrl, LineEndWrapExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, VCHomeWrap);
	Gura_AssignMethod(wx_StyledTextCtrl, VCHomeWrapExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, LineCopy);
	Gura_AssignMethod(wx_StyledTextCtrl, MoveCaretInsideView);
	Gura_AssignMethod(wx_StyledTextCtrl, LineLength);
	Gura_AssignMethod(wx_StyledTextCtrl, BraceHighlight);
	Gura_AssignMethod(wx_StyledTextCtrl, BraceHighlightIndicator);
	Gura_AssignMethod(wx_StyledTextCtrl, BraceBadLight);
	Gura_AssignMethod(wx_StyledTextCtrl, BraceBadLightIndicator);
	Gura_AssignMethod(wx_StyledTextCtrl, BraceMatch);
	Gura_AssignMethod(wx_StyledTextCtrl, GetViewEOL);
	Gura_AssignMethod(wx_StyledTextCtrl, SetViewEOL);
	Gura_AssignMethod(wx_StyledTextCtrl, GetDocPointer);
	Gura_AssignMethod(wx_StyledTextCtrl, SetDocPointer);
	Gura_AssignMethod(wx_StyledTextCtrl, SetModEventMask);
	Gura_AssignMethod(wx_StyledTextCtrl, GetEdgeColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, SetEdgeColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, GetEdgeMode);
	Gura_AssignMethod(wx_StyledTextCtrl, SetEdgeMode);
	Gura_AssignMethod(wx_StyledTextCtrl, GetEdgeColour);
	Gura_AssignMethod(wx_StyledTextCtrl, SetEdgeColour);
	Gura_AssignMethod(wx_StyledTextCtrl, SearchAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, SearchNext);
	Gura_AssignMethod(wx_StyledTextCtrl, SearchPrev);
	Gura_AssignMethod(wx_StyledTextCtrl, LinesOnScreen);
	Gura_AssignMethod(wx_StyledTextCtrl, UsePopUp);
	Gura_AssignMethod(wx_StyledTextCtrl, SelectionIsRectangle);
	Gura_AssignMethod(wx_StyledTextCtrl, SetZoom);
	Gura_AssignMethod(wx_StyledTextCtrl, GetZoom);
	Gura_AssignMethod(wx_StyledTextCtrl, CreateDocument);
	Gura_AssignMethod(wx_StyledTextCtrl, AddRefDocument);
	Gura_AssignMethod(wx_StyledTextCtrl, ReleaseDocument);
	Gura_AssignMethod(wx_StyledTextCtrl, GetModEventMask);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSTCFocus);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSTCFocus);
	Gura_AssignMethod(wx_StyledTextCtrl, SetStatus);
	Gura_AssignMethod(wx_StyledTextCtrl, GetStatus);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMouseDownCaptures);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMouseDownCaptures);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSTCCursor);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSTCCursor);
	Gura_AssignMethod(wx_StyledTextCtrl, SetControlCharSymbol);
	Gura_AssignMethod(wx_StyledTextCtrl, GetControlCharSymbol);
	Gura_AssignMethod(wx_StyledTextCtrl, WordPartLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, WordPartLeftExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, WordPartRight);
	Gura_AssignMethod(wx_StyledTextCtrl, WordPartRightExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, SetVisiblePolicy);
	Gura_AssignMethod(wx_StyledTextCtrl, DelLineLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, DelLineRight);
	Gura_AssignMethod(wx_StyledTextCtrl, SetXOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, GetXOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, ChooseCaretX);
	Gura_AssignMethod(wx_StyledTextCtrl, SetXCaretPolicy);
	Gura_AssignMethod(wx_StyledTextCtrl, SetYCaretPolicy);
	Gura_AssignMethod(wx_StyledTextCtrl, SetPrintWrapMode);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPrintWrapMode);
	Gura_AssignMethod(wx_StyledTextCtrl, SetHotspotActiveForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, GetHotspotActiveForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, SetHotspotActiveBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, GetHotspotActiveBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, SetHotspotActiveUnderline);
	Gura_AssignMethod(wx_StyledTextCtrl, GetHotspotActiveUnderline);
	Gura_AssignMethod(wx_StyledTextCtrl, SetHotspotSingleLine);
	Gura_AssignMethod(wx_StyledTextCtrl, GetHotspotSingleLine);
	Gura_AssignMethod(wx_StyledTextCtrl, ParaDown);
	Gura_AssignMethod(wx_StyledTextCtrl, ParaDownExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, ParaUp);
	Gura_AssignMethod(wx_StyledTextCtrl, ParaUpExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, PositionBefore);
	Gura_AssignMethod(wx_StyledTextCtrl, PositionAfter);
	Gura_AssignMethod(wx_StyledTextCtrl, PositionRelative);
	Gura_AssignMethod(wx_StyledTextCtrl, CopyRange);
	Gura_AssignMethod(wx_StyledTextCtrl, CopyText);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionMode);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionMode);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineSelStartPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineSelEndPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, LineDownRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, LineUpRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, CharLeftRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, CharRightRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, HomeRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, VCHomeRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, LineEndRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, PageUpRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, PageDownRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, StutteredPageUp);
	Gura_AssignMethod(wx_StyledTextCtrl, StutteredPageUpExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, StutteredPageDown);
	Gura_AssignMethod(wx_StyledTextCtrl, StutteredPageDownExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, WordLeftEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, WordLeftEndExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, WordRightEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, WordRightEndExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, SetWhitespaceChars);
	Gura_AssignMethod(wx_StyledTextCtrl, GetWhitespaceChars);
	Gura_AssignMethod(wx_StyledTextCtrl, SetPunctuationChars);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPunctuationChars);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCharsDefault);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetCurrent);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetCaseInsensitiveBehaviour);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetCaseInsensitiveBehaviour);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetMulti);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetMulti);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompSetOrder);
	Gura_AssignMethod(wx_StyledTextCtrl, AutoCompGetOrder);
	Gura_AssignMethod(wx_StyledTextCtrl, Allocate);
	Gura_AssignMethod(wx_StyledTextCtrl, FindColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretSticky);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretSticky);
	Gura_AssignMethod(wx_StyledTextCtrl, ToggleCaretSticky);
	Gura_AssignMethod(wx_StyledTextCtrl, SetPasteConvertEndings);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPasteConvertEndings);
	Gura_AssignMethod(wx_StyledTextCtrl, SelectionDuplicate);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretLineBackAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretLineBackAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, SetIndicatorCurrent);
	Gura_AssignMethod(wx_StyledTextCtrl, GetIndicatorCurrent);
	Gura_AssignMethod(wx_StyledTextCtrl, SetIndicatorValue);
	Gura_AssignMethod(wx_StyledTextCtrl, GetIndicatorValue);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorFillRange);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorClearRange);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorAllOnFor);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorValueAt);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorStart);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, SetPositionCacheSize);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPositionCacheSize);
	Gura_AssignMethod(wx_StyledTextCtrl, CopyAllowLine);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCharacterPointer);
	Gura_AssignMethod(wx_StyledTextCtrl, GetRangePointer);
	Gura_AssignMethod(wx_StyledTextCtrl, GetGapPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorSetAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorGetAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorSetOutlineAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, IndicatorGetOutlineAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, SetExtraAscent);
	Gura_AssignMethod(wx_StyledTextCtrl, GetExtraAscent);
	Gura_AssignMethod(wx_StyledTextCtrl, SetExtraDescent);
	Gura_AssignMethod(wx_StyledTextCtrl, GetExtraDescent);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarkerSymbolDefined);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginSetText);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginGetText);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginSetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginGetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginSetStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginGetStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginTextClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginSetStyleOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, MarginGetStyleOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMarginOptions);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMarginOptions);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationSetText);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationGetText);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationSetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationGetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationSetStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationGetStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationGetLines);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationSetVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationGetVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationSetStyleOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationGetStyleOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, ReleaseAllExtendedStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, AllocateExtendedStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, AddUndoAction);
	Gura_AssignMethod(wx_StyledTextCtrl, CharPositionFromPoint);
	Gura_AssignMethod(wx_StyledTextCtrl, CharPositionFromPointClose);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMouseSelectionRectangularSwitch);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMouseSelectionRectangularSwitch);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMultipleSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMultipleSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAdditionalSelectionTyping);
	Gura_AssignMethod(wx_StyledTextCtrl, GetAdditionalSelectionTyping);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAdditionalCaretsBlink);
	Gura_AssignMethod(wx_StyledTextCtrl, GetAdditionalCaretsBlink);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAdditionalCaretsVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, GetAdditionalCaretsVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelections);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionEmpty);
	Gura_AssignMethod(wx_StyledTextCtrl, ClearSelections);
	Gura_AssignMethod(wx_StyledTextCtrl, AddSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, DropSelectionN);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMainSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, GetMainSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionNCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionNCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionNAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionNAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionNCaretVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionNCaretVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionNAnchorVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionNAnchorVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionNStart);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionNStart);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelectionNEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectionNEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, SetRectangularSelectionCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, GetRectangularSelectionCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, SetRectangularSelectionAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, GetRectangularSelectionAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, SetRectangularSelectionCaretVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, GetRectangularSelectionCaretVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, SetRectangularSelectionAnchorVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, GetRectangularSelectionAnchorVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, SetVirtualSpaceOptions);
	Gura_AssignMethod(wx_StyledTextCtrl, GetVirtualSpaceOptions);
	Gura_AssignMethod(wx_StyledTextCtrl, SetRectangularSelectionModifier);
	Gura_AssignMethod(wx_StyledTextCtrl, GetRectangularSelectionModifier);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAdditionalSelForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAdditionalSelBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAdditionalSelAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, GetAdditionalSelAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, SetAdditionalCaretForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, GetAdditionalCaretForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, RotateSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, SwapMainAnchorCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, ChangeLexerState);
	Gura_AssignMethod(wx_StyledTextCtrl, ContractedFoldNext);
	Gura_AssignMethod(wx_StyledTextCtrl, VerticalCentreCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, MoveSelectedLinesUp);
	Gura_AssignMethod(wx_StyledTextCtrl, MoveSelectedLinesDown);
	Gura_AssignMethod(wx_StyledTextCtrl, SetIdentifier);
	Gura_AssignMethod(wx_StyledTextCtrl, GetIdentifier);
	Gura_AssignMethod(wx_StyledTextCtrl, RGBAImageSetWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, RGBAImageSetHeight);
	Gura_AssignMethod(wx_StyledTextCtrl, RGBAImageSetScale);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkerDefineRGBAImage);
	Gura_AssignMethod(wx_StyledTextCtrl, RegisterRGBAImage);
	Gura_AssignMethod(wx_StyledTextCtrl, ScrollToStart);
	Gura_AssignMethod(wx_StyledTextCtrl, ScrollToEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, SetTechnology);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTechnology);
	Gura_AssignMethod(wx_StyledTextCtrl, CreateLoader);
	Gura_AssignMethod(wx_StyledTextCtrl, VCHomeDisplay);
	Gura_AssignMethod(wx_StyledTextCtrl, VCHomeDisplayExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCaretLineVisibleAlways);
	Gura_AssignMethod(wx_StyledTextCtrl, SetCaretLineVisibleAlways);
	Gura_AssignMethod(wx_StyledTextCtrl, SetLineEndTypesAllowed);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineEndTypesAllowed);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineEndTypesActive);
	Gura_AssignMethod(wx_StyledTextCtrl, SetRepresentation);
	Gura_AssignMethod(wx_StyledTextCtrl, GetRepresentation);
	Gura_AssignMethod(wx_StyledTextCtrl, ClearRepresentation);
	Gura_AssignMethod(wx_StyledTextCtrl, StartRecord);
	Gura_AssignMethod(wx_StyledTextCtrl, StopRecord);
	Gura_AssignMethod(wx_StyledTextCtrl, SetLexer);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLexer);
	Gura_AssignMethod(wx_StyledTextCtrl, Colourise);
	Gura_AssignMethod(wx_StyledTextCtrl, SetProperty);
	Gura_AssignMethod(wx_StyledTextCtrl, SetKeyWords);
	Gura_AssignMethod(wx_StyledTextCtrl, SetLexerLanguage);
	Gura_AssignMethod(wx_StyledTextCtrl, GetProperty);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPropertyExpanded);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPropertyInt);
	Gura_AssignMethod(wx_StyledTextCtrl, GetStyleBitsNeeded);
	Gura_AssignMethod(wx_StyledTextCtrl, PrivateLexerCall);
	Gura_AssignMethod(wx_StyledTextCtrl, PropertyNames);
	Gura_AssignMethod(wx_StyledTextCtrl, PropertyType);
	Gura_AssignMethod(wx_StyledTextCtrl, DescribeProperty);
	Gura_AssignMethod(wx_StyledTextCtrl, DescribeKeyWordSets);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineEndTypesSupported);
	Gura_AssignMethod(wx_StyledTextCtrl, AllocateSubStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSubStylesStart);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSubStylesLength);
	Gura_AssignMethod(wx_StyledTextCtrl, GetStyleFromSubStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, GetPrimaryStyleFromStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, FreeSubStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, SetIdentifiers);
	Gura_AssignMethod(wx_StyledTextCtrl, DistanceToSecondaryStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSubStyleBases);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCurrentLine);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetSpec);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleGetFont);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetFont);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetFontAttr);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetCharacterSet);
	Gura_AssignMethod(wx_StyledTextCtrl, StyleSetFontEncoding);
	Gura_AssignMethod(wx_StyledTextCtrl, CmdKeyExecute);
	Gura_AssignMethod(wx_StyledTextCtrl, SetMargins);
	Gura_AssignMethod(wx_StyledTextCtrl, PointFromPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, ScrollToLine);
	Gura_AssignMethod(wx_StyledTextCtrl, ScrollToColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, SendMsg);
	Gura_AssignMethod(wx_StyledTextCtrl, SetVScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, SetHScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLastKeydownProcessed);
	Gura_AssignMethod(wx_StyledTextCtrl, SetLastKeydownProcessed);
	Gura_AssignMethod(wx_StyledTextCtrl, SaveFile);
	Gura_AssignMethod(wx_StyledTextCtrl, LoadFile);
	Gura_AssignMethod(wx_StyledTextCtrl, DoDragEnter);
	Gura_AssignMethod(wx_StyledTextCtrl, DoDragOver);
	Gura_AssignMethod(wx_StyledTextCtrl, DoDragLeave);
	Gura_AssignMethod(wx_StyledTextCtrl, DoDropText);
	Gura_AssignMethod(wx_StyledTextCtrl, AnnotationClearLine);
	Gura_AssignMethod(wx_StyledTextCtrl, AddTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, InsertTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, GetCurLineRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelectedTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTextRangeRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, SetTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, GetTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, AppendTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLibraryVersionInfo);
	Gura_AssignMethod(wx_StyledTextCtrl, WriteText);
	Gura_AssignMethod(wx_StyledTextCtrl, Remove);
	Gura_AssignMethod(wx_StyledTextCtrl, Replace);
	Gura_AssignMethod(wx_StyledTextCtrl, SetInsertionPoint);
	Gura_AssignMethod(wx_StyledTextCtrl, GetInsertionPoint);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLastPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, SetSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, SelectNone);
	Gura_AssignMethod(wx_StyledTextCtrl, GetSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, IsEditable);
	Gura_AssignMethod(wx_StyledTextCtrl, SetEditable);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineLength);
	Gura_AssignMethod(wx_StyledTextCtrl, GetLineText);
	Gura_AssignMethod(wx_StyledTextCtrl, GetNumberOfLines);
	Gura_AssignMethod(wx_StyledTextCtrl, IsModified);
	Gura_AssignMethod(wx_StyledTextCtrl, MarkDirty);
	Gura_AssignMethod(wx_StyledTextCtrl, DiscardEdits);
	Gura_AssignMethod(wx_StyledTextCtrl, SetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, GetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, SetDefaultStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, XYToPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, PositionToXY);
	Gura_AssignMethod(wx_StyledTextCtrl, ShowPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, HitTest);
	Gura_AssignMethod(wx_StyledTextCtrl, HitTest_1);
}

Gura_ImplementDescendantCreator(wx_StyledTextCtrl)
{
	return new Object_wx_StyledTextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
