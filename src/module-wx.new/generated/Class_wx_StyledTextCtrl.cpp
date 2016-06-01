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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxStyledTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ~wxStyledTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ~wxStyledTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxStyledTextCtrl();
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_StyledTextCtrl, AddText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AddText)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearDocumentStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetAnchor)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetSavePoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetSavePoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUndoCollection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetViewWhiteSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetViewWhiteSpace)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWordChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BeginUndoAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BeginUndoAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BeginUndoAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EndUndoAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EndUndoAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMaxLineState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretLineVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretLineVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AutoCompCancel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AutoCompActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompPosStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompPosStart)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AutoCompPosStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompComplete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompComplete)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearRegisteredImages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetTypeSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetTypeSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCodePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretForeground)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetReadOnly)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMarginRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetModify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetModify)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetModify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectedText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectedText)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CanUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EmptyUndoBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EmptyUndoBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EmptyUndoBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Undo)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Cut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Cut)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Paste)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetTextLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetTextLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CallTipCancel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CallTipActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CallTipPosAtStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CallTipPosAtStart)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->TargetFromSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LinesJoin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LinesJoin)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineDownExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineDownExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineDownExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineUpExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineUpExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineUpExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CharLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharLeftExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharLeftExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CharLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CharRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharRightExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharRightExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CharRightExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordLeftExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordLeftExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordRightExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordRightExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordRightExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Home)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Home)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Home();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HomeExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineEndExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocumentStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocumentStart)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DocumentStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocumentStartExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocumentStartExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DocumentStartExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocumentEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocumentEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DocumentEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DocumentEndExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DocumentEndExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DocumentEndExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageUpExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageUpExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageUpExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageDownExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageDownExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageDownExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, EditToggleOvertype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, EditToggleOvertype)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->EditToggleOvertype();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Cancel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Cancel)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Cancel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DeleteBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DeleteBack)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, Tab)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, Tab)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Tab();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, BackTab)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, BackTab)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->BackTab();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, NewLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, NewLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->NewLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, FormFeed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, FormFeed)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FormFeed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHome)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHome)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->VCHome();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->VCHomeExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ZoomIn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ZoomIn)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ZoomIn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ZoomOut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ZoomOut)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ZoomOut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelWordLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelWordLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DelWordLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelWordRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelWordRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DelWordRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelWordRightEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelWordRightEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DelWordRightEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineCut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineCut)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineCut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineDelete)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineDelete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineTranspose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineTranspose)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineTranspose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineDuplicate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineDuplicate)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineDuplicate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LowerCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LowerCase)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LowerCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, UpperCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, UpperCase)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UpperCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineScrollDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineScrollDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineScrollDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineScrollUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineScrollUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineScrollUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DeleteBackNotLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DeleteBackNotLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteBackNotLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeDisplay)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HomeDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeDisplayExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeDisplayExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HomeDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndDisplay)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineEndDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndDisplayExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndDisplayExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineEndDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeWrap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeWrap)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HomeWrap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeWrapExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeWrapExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HomeWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndWrap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndWrap)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineEndWrap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndWrapExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndWrapExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineEndWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeWrap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeWrap)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->VCHomeWrap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeWrapExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeWrapExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->VCHomeWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineCopy)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineCopy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MoveCaretInsideView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MoveCaretInsideView)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetZoom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CreateDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CreateDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetControlCharSymbol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordPartLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordPartLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordPartLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordPartLeftExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordPartLeftExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordPartLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordPartRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordPartRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordPartRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordPartRightExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordPartRightExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DelLineLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DelLineRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DelLineRight)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetXOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ChooseCaretX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ChooseCaretX)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotSingleLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ParaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ParaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ParaDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ParaDownExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ParaDownExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ParaDownExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ParaUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ParaUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ParaUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ParaUpExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ParaUpExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineDownRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineUpRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineUpRectExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineUpRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharLeftRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharLeftRectExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CharLeftRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CharRightRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CharRightRectExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CharRightRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, HomeRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, HomeRectExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HomeRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeRectExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->VCHomeRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, LineEndRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, LineEndRectExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineEndRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageUpRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageUpRectExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageUpRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, PageDownRectExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, PageDownRectExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageDownRectExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StutteredPageUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StutteredPageUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StutteredPageUpExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StutteredPageUpExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageUpExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StutteredPageDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StutteredPageDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StutteredPageDownExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StutteredPageDownExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageDownExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordLeftEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordLeftEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordLeftEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordLeftEndExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordLeftEndExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordLeftEndExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordRightEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordRightEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WordRightEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, WordRightEndExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, WordRightEndExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPunctuationChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SetCharsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SetCharsDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetCharsDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, AutoCompGetCurrent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, AutoCompGetCurrent)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPasteConvertEndings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SelectionDuplicate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SelectionDuplicate)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPositionCacheSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, CopyAllowLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, CopyAllowLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CopyAllowLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCharacterPointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCharacterPointer)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AnnotationGetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ReleaseAllExtendedStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ReleaseAllExtendedStyles)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalCaretsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSelectionEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSelectionEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ClearSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ClearSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, RotateSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, RotateSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RotateSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, SwapMainAnchorCaret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, SwapMainAnchorCaret)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->VerticalCentreCaret();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MoveSelectedLinesUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MoveSelectedLinesUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MoveSelectedLinesUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MoveSelectedLinesDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MoveSelectedLinesDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ScrollToStart();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, ScrollToEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, ScrollToEnd)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->VCHomeDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, VCHomeDisplayExtend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, VCHomeDisplayExtend)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->VCHomeDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCaretLineVisibleAlways)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCaretLineVisibleAlways)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLineEndTypesAllowed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineEndTypesActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineEndTypesActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->StartRecord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, StopRecord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, StopRecord)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DescribeKeyWordSets();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLineEndTypesSupported)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLineEndTypesSupported)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DistanceToSecondaryStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetSubStyleBases)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetSubStyleBases)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSubStyleBases();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetCurrentLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetCurrentLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, GetLastPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, GetLastPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNumberOfLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, IsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, IsModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, MarkDirty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, MarkDirty)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MarkDirty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StyledTextCtrl, DiscardEdits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, DiscardEdits)
{
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_StyledTextCtrl, ~wxStyledTextCtrl);
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
