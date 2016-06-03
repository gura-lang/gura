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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__StyledTextCtrl, "StyledTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StyledTextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StyledTextCtrl)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxStyledTextCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__StyledTextCtrl_1, "StyledTextCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StyledTextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StyledTextCtrl_1)
{
	//wxStyledTextCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Create)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AddText, "AddText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AddText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->AddText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AddStyledText, "AddStyledText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AddStyledText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxMemoryBuffer& data = arg.GetNumber(0)
	//pThis->GetEntity()->AddStyledText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __InsertText, "InsertText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __InsertText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->InsertText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ChangeInsertion, "ChangeInsertion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ChangeInsertion)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->ChangeInsertion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ClearAll, "ClearAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DeleteRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int deleteLength = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ClearDocumentStyle, "ClearDocumentStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ClearDocumentStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearDocumentStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLength, "GetLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCharAt, "GetCharAt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCharAt)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetCharAt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCurrentPos, "GetCurrentPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCurrentPos)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetAnchor, "GetAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetStyleAt, "GetStyleAt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetStyleAt)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetStyleAt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Redo, "Redo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Redo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetUndoCollection, "SetUndoCollection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collectUndo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetUndoCollection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool collectUndo = arg.GetNumber(0)
	//pThis->GetEntity()->SetUndoCollection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SelectAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSavePoint, "SetSavePoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSavePoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetSavePoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetStyledText, "GetStyledText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetStyledText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyledText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CanRedo, "CanRedo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CanRedo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerLineFromHandle, "MarkerLineFromHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerLineFromHandle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handle = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerLineFromHandle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerDeleteHandle, "MarkerDeleteHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerDeleteHandle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handle = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerDeleteHandle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetUndoCollection, "GetUndoCollection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetUndoCollection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUndoCollection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetViewWhiteSpace, "GetViewWhiteSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetViewWhiteSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewWhiteSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetViewWhiteSpace, "SetViewWhiteSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "viewWS", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetViewWhiteSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int viewWS = arg.GetNumber(0)
	//pThis->GetEntity()->SetViewWhiteSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PositionFromPoint, "PositionFromPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PositionFromPoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint pt = arg.GetNumber(0)
	//pThis->GetEntity()->PositionFromPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PositionFromPointClose, "PositionFromPointClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PositionFromPointClose)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->PositionFromPointClose();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GotoLine, "GotoLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GotoLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GotoLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GotoPos, "GotoPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GotoPos)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GotoPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAnchor, "SetAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "posAnchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int posAnchor = arg.GetNumber(0)
	//pThis->GetEntity()->SetAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCurLine, "GetCurLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "linePos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCurLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* linePos = arg.GetNumber(0)
	//pThis->GetEntity()->GetCurLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetEndStyled, "GetEndStyled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetEndStyled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndStyled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ConvertEOLs, "ConvertEOLs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eolMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ConvertEOLs)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eolMode = arg.GetNumber(0)
	//pThis->GetEntity()->ConvertEOLs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetEOLMode, "GetEOLMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetEOLMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEOLMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetEOLMode, "SetEOLMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eolMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetEOLMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eolMode = arg.GetNumber(0)
	//pThis->GetEntity()->SetEOLMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StartStyling, "StartStyling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StartStyling)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int mask = arg.GetNumber(1)
	//pThis->GetEntity()->StartStyling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetStyling, "SetStyling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetStyling)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->SetStyling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetBufferedDraw, "GetBufferedDraw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetBufferedDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBufferedDraw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetBufferedDraw, "SetBufferedDraw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffered", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetBufferedDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool buffered = arg.GetNumber(0)
	//pThis->GetEntity()->SetBufferedDraw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetTabWidth, "SetTabWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetTabWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTabWidth, "GetTabWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTabWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTabWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ClearTabStops, "ClearTabStops")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ClearTabStops)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->ClearTabStops();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AddTabStop, "AddTabStop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AddTabStop)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//pThis->GetEntity()->AddTabStop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetNextTabStop, "GetNextTabStop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetNextTabStop)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//pThis->GetEntity()->GetNextTabStop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCodePage, "SetCodePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "codePage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCodePage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int codePage = arg.GetNumber(0)
	//pThis->GetEntity()->SetCodePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetIMEInteraction, "GetIMEInteraction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetIMEInteraction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIMEInteraction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetIMEInteraction, "SetIMEInteraction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "imeInteraction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetIMEInteraction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int imeInteraction = arg.GetNumber(0)
	//pThis->GetEntity()->SetIMEInteraction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerDefine, "MarkerDefine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerSymbol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "foreground", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "background", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerDefine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int markerSymbol = arg.GetNumber(1)
	//const wxColour& foreground = arg.GetNumber(2)
	//const wxColour& background = arg.GetNumber(3)
	//pThis->GetEntity()->MarkerDefine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerSetForeground, "MarkerSetForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerSetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//const wxColour& fore = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerSetForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerSetBackground, "MarkerSetBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerSetBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//const wxColour& back = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerSetBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerSetBackgroundSelected, "MarkerSetBackgroundSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerSetBackgroundSelected)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//const wxColour& back = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerSetBackgroundSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerEnableHighlight, "MarkerEnableHighlight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enabled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerEnableHighlight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enabled = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerEnableHighlight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerAdd, "MarkerAdd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerAdd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int markerNumber = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerAdd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerDelete, "MarkerDelete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerDelete)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int markerNumber = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerDelete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerDeleteAll, "MarkerDeleteAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerDeleteAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerDeleteAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerGet, "MarkerGet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerGet)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->MarkerGet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerNext, "MarkerNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerNext)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//int markerMask = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerPrevious, "MarkerPrevious")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "markerMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerPrevious)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//int markerMask = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerPrevious();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerDefineBitmap, "MarkerDefineBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerDefineBitmap)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//const wxBitmap& bmp = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerDefineBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerAddSet, "MarkerAddSet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerAddSet)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int set = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerAddSet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerSetAlpha, "MarkerSetAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerSetAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//int alpha = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerSetAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMarginType, "SetMarginType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "marginType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMarginType)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int marginType = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarginType, "GetMarginType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarginType)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMarginWidth, "SetMarginWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMarginWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int pixelWidth = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarginWidth, "GetMarginWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarginWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMarginMask, "SetMarginMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMarginMask)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int mask = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarginMask, "GetMarginMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarginMask)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMarginSensitive, "SetMarginSensitive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sensitive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMarginSensitive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//bool sensitive = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginSensitive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarginSensitive, "GetMarginSensitive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarginSensitive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginSensitive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMarginCursor, "SetMarginCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMarginCursor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->SetMarginCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarginCursor, "GetMarginCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "margin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarginCursor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int margin = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarginCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleClearAll, "StyleClearAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StyleClearAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetForeground, "StyleSetForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//const wxColour& fore = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetBackground, "StyleSetBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//const wxColour& back = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetBold, "StyleSetBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetBold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//bool bold = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetItalic, "StyleSetItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "italic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetItalic)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//bool italic = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetSize, "StyleSetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizePoints", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int sizePoints = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetFaceName, "StyleSetFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fontName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetFaceName)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//const wxString& fontName = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetFaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetEOLFilled, "StyleSetEOLFilled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetEOLFilled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//bool filled = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetEOLFilled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleResetDefault, "StyleResetDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleResetDefault)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StyleResetDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetUnderline, "StyleSetUnderline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetUnderline)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//bool underline = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetUnderline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetForeground, "StyleGetForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetBackground, "StyleGetBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetBold, "StyleGetBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetBold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetItalic, "StyleGetItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetItalic)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetSize, "StyleGetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetFaceName, "StyleGetFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetFaceName)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetFaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetEOLFilled, "StyleGetEOLFilled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetEOLFilled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetEOLFilled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetUnderline, "StyleGetUnderline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetUnderline)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetUnderline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetCase, "StyleGetCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetCase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetCharacterSet, "StyleGetCharacterSet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetCharacterSet)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetCharacterSet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetVisible, "StyleGetVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetChangeable, "StyleGetChangeable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetChangeable)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetChangeable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetHotSpot, "StyleGetHotSpot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetHotSpot)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetHotSpot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetCase, "StyleSetCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseForce", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int caseForce = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetCase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetSizeFractional, "StyleSetSizeFractional")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseForce", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetSizeFractional)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int caseForce = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetSizeFractional();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetSizeFractional, "StyleGetSizeFractional")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetSizeFractional)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetSizeFractional();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetWeight, "StyleSetWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetWeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int weight = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetWeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetWeight, "StyleGetWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetWeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetWeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetHotSpot, "StyleSetHotSpot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hotspot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetHotSpot)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//bool hotspot = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetHotSpot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelForeground, "SetSelForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useSetting = arg.GetNumber(0)
	//const wxColour& fore = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelBackground, "SetSelBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useSetting = arg.GetNumber(0)
	//const wxColour& back = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelAlpha, "GetSelAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelAlpha, "SetSelAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alpha = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelEOLFilled, "GetSelEOLFilled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelEOLFilled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelEOLFilled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelEOLFilled, "SetSelEOLFilled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filled", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelEOLFilled)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool filled = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelEOLFilled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretForeground, "SetCaretForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& fore = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CmdKeyAssign, "CmdKeyAssign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CmdKeyAssign)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int modifiers = arg.GetNumber(1)
	//int cmd = arg.GetNumber(2)
	//pThis->GetEntity()->CmdKeyAssign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CmdKeyClear, "CmdKeyClear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CmdKeyClear)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int modifiers = arg.GetNumber(1)
	//pThis->GetEntity()->CmdKeyClear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CmdKeyClearAll, "CmdKeyClearAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CmdKeyClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CmdKeyClearAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetStyleBytes, "SetStyleBytes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styleBytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetStyleBytes)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//char* styleBytes = arg.GetNumber(1)
	//pThis->GetEntity()->SetStyleBytes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetVisible, "StyleSetVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//bool visible = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretPeriod, "GetCaretPeriod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretPeriod)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretPeriod();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretPeriod, "SetCaretPeriod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "periodMilliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretPeriod)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int periodMilliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretPeriod();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWordChars, "SetWordChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWordChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& characters = arg.GetNumber(0)
	//pThis->GetEntity()->SetWordChars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetWordChars, "GetWordChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetWordChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWordChars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __BeginUndoAction, "BeginUndoAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __BeginUndoAction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginUndoAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __EndUndoAction, "EndUndoAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __EndUndoAction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndUndoAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorSetStyle, "IndicatorSetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorSetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorGetStyle, "IndicatorGetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorGetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorSetForeground, "IndicatorSetForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorSetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//const wxColour& fore = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorGetForeground, "IndicatorGetForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorGetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorSetUnder, "IndicatorSetUnder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "under", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorSetUnder)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//bool under = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetUnder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorGetUnder, "IndicatorGetUnder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorGetUnder)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetUnder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorSetHoverStyle, "IndicatorSetHoverStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorSetHoverStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetHoverStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorGetHoverStyle, "IndicatorGetHoverStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorGetHoverStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetHoverStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorSetHoverForeground, "IndicatorSetHoverForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorSetHoverForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//const wxColour& fore = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetHoverForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorGetHoverForeground, "IndicatorGetHoverForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorGetHoverForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetHoverForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorSetFlags, "IndicatorSetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorSetFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorGetFlags, "IndicatorGetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorGetFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indic = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWhitespaceForeground, "SetWhitespaceForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWhitespaceForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useSetting = arg.GetNumber(0)
	//const wxColour& fore = arg.GetNumber(1)
	//pThis->GetEntity()->SetWhitespaceForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWhitespaceBackground, "SetWhitespaceBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWhitespaceBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useSetting = arg.GetNumber(0)
	//const wxColour& back = arg.GetNumber(1)
	//pThis->GetEntity()->SetWhitespaceBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWhitespaceSize, "SetWhitespaceSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWhitespaceSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetWhitespaceSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetWhitespaceSize, "GetWhitespaceSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetWhitespaceSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWhitespaceSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetStyleBits, "SetStyleBits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bits", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetStyleBits)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bits = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleBits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetStyleBits, "GetStyleBits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetStyleBits)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleBits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetLineState, "SetLineState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetLineState)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->SetLineState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineState, "GetLineState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineState)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMaxLineState, "GetMaxLineState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMaxLineState)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxLineState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretLineVisible, "GetCaretLineVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretLineVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretLineVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretLineVisible, "SetCaretLineVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretLineVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretLineVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretLineBackground, "GetCaretLineBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretLineBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretLineBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretLineBackground, "SetCaretLineBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretLineBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& back = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretLineBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetChangeable, "StyleSetChangeable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "changeable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetChangeable)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//bool changeable = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetChangeable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompShow, "AutoCompShow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lenEntered", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompShow)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lenEntered = arg.GetNumber(0)
	//const wxString& itemList = arg.GetNumber(1)
	//pThis->GetEntity()->AutoCompShow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompCancel, "AutoCompCancel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompCancel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompCancel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompActive, "AutoCompActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompActive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompActive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompPosStart, "AutoCompPosStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompPosStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompPosStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompComplete, "AutoCompComplete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompComplete)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompComplete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompStops, "AutoCompStops")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompStops)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& characterSet = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompStops();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetSeparator, "AutoCompSetSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "separatorCharacter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetSeparator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int separatorCharacter = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetSeparator, "AutoCompGetSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetSeparator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSelect, "AutoCompSelect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSelect)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSelect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetCancelAtStart, "AutoCompSetCancelAtStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cancel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetCancelAtStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool cancel = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetCancelAtStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetCancelAtStart, "AutoCompGetCancelAtStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetCancelAtStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetCancelAtStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetFillUps, "AutoCompSetFillUps")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetFillUps)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& characterSet = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetFillUps();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetChooseSingle, "AutoCompSetChooseSingle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "chooseSingle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetChooseSingle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool chooseSingle = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetChooseSingle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetChooseSingle, "AutoCompGetChooseSingle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetChooseSingle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetChooseSingle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetIgnoreCase, "AutoCompSetIgnoreCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ignoreCase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetIgnoreCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool ignoreCase = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetIgnoreCase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetIgnoreCase, "AutoCompGetIgnoreCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetIgnoreCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetIgnoreCase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __UserListShow, "UserListShow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "listType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "itemList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __UserListShow)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int listType = arg.GetNumber(0)
	//const wxString& itemList = arg.GetNumber(1)
	//pThis->GetEntity()->UserListShow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetAutoHide, "AutoCompSetAutoHide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "autoHide", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetAutoHide)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool autoHide = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetAutoHide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetAutoHide, "AutoCompGetAutoHide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetAutoHide)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetAutoHide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetDropRestOfWord, "AutoCompSetDropRestOfWord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dropRestOfWord", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetDropRestOfWord)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool dropRestOfWord = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetDropRestOfWord();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetDropRestOfWord, "AutoCompGetDropRestOfWord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetDropRestOfWord)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetDropRestOfWord();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __RegisterImage, "RegisterImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __RegisterImage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//const wxBitmap& bmp = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ClearRegisteredImages, "ClearRegisteredImages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ClearRegisteredImages)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearRegisteredImages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetTypeSeparator, "AutoCompGetTypeSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetTypeSeparator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetTypeSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetTypeSeparator, "AutoCompSetTypeSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "separatorCharacter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetTypeSeparator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int separatorCharacter = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetTypeSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetMaxWidth, "AutoCompSetMaxWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characterCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetMaxWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int characterCount = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetMaxWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetMaxWidth, "AutoCompGetMaxWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetMaxWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetMaxWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetMaxHeight, "AutoCompSetMaxHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetMaxHeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowCount = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetMaxHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetMaxHeight, "AutoCompGetMaxHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetMaxHeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetMaxHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetIndent, "SetIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetIndent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indentSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetIndent, "GetIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetIndent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetUseTabs, "SetUseTabs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useTabs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetUseTabs)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useTabs = arg.GetNumber(0)
	//pThis->GetEntity()->SetUseTabs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetUseTabs, "GetUseTabs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetUseTabs)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUseTabs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetLineIndentation, "SetLineIndentation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indentSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetLineIndentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int indentSize = arg.GetNumber(1)
	//pThis->GetEntity()->SetLineIndentation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineIndentation, "GetLineIndentation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineIndentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineIndentation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineIndentPosition, "GetLineIndentPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineIndentPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineIndentPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CountCharacters, "CountCharacters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CountCharacters)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->CountCharacters();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetUseHorizontalScrollBar, "SetUseHorizontalScrollBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetUseHorizontalScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->SetUseHorizontalScrollBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetUseHorizontalScrollBar, "GetUseHorizontalScrollBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetUseHorizontalScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUseHorizontalScrollBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetIndentationGuides, "SetIndentationGuides")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indentView", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetIndentationGuides)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indentView = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndentationGuides();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetIndentationGuides, "GetIndentationGuides")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetIndentationGuides)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndentationGuides();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetHighlightGuide, "SetHighlightGuide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetHighlightGuide)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->SetHighlightGuide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetHighlightGuide, "GetHighlightGuide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetHighlightGuide)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHighlightGuide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineEndPosition, "GetLineEndPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineEndPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineEndPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCodePage, "GetCodePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCodePage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCodePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretForeground, "GetCaretForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetReadOnly, "GetReadOnly")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetReadOnly)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetReadOnly();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCurrentPos, "SetCurrentPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCurrentPos)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetCurrentPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionStart, "SetSelectionStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionStart, "GetSelectionStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionEnd, "SetSelectionEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionEnd, "GetSelectionEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetEmptySelection, "SetEmptySelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetEmptySelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetEmptySelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetPrintMagnification, "SetPrintMagnification")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "magnification", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetPrintMagnification)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int magnification = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintMagnification();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPrintMagnification, "GetPrintMagnification")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPrintMagnification)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintMagnification();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetPrintColourMode, "SetPrintColourMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetPrintColourMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintColourMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPrintColourMode, "GetPrintColourMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPrintColourMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintColourMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __FindText, "FindText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __FindText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minPos = arg.GetNumber(0)
	//int maxPos = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->FindText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __FormatRange, "FormatRange")
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

Gura_ImplementMethod(wx_StyledTextCtrl, __FormatRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool doDraw = arg.GetNumber(0)
	//int startPos = arg.GetNumber(1)
	//int endPos = arg.GetNumber(2)
	//wxDC* draw = arg.GetNumber(3)
	//wxDC* target = arg.GetNumber(4)
	//wxRect renderRect = arg.GetNumber(5)
	//wxRect pageRect = arg.GetNumber(6)
	//pThis->GetEntity()->FormatRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetFirstVisibleLine, "GetFirstVisibleLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetFirstVisibleLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstVisibleLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLine, "GetLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineCount, "GetLineCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineCount)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMarginLeft, "SetMarginLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMarginLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarginLeft, "GetMarginLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarginLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMarginRight, "SetMarginRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMarginRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarginRight, "GetMarginRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarginRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetModify, "GetModify")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetModify)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModify();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectedText, "GetSelectedText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectedText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTextRange, "GetTextRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTextRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetTextRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HideSelection, "HideSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HideSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool normal = arg.GetNumber(0)
	//pThis->GetEntity()->HideSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineFromPosition, "LineFromPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineFromPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->LineFromPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PositionFromLine, "PositionFromLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PositionFromLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->PositionFromLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineScroll, "LineScroll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "columns", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineScroll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int columns = arg.GetNumber(0)
	//int lines = arg.GetNumber(1)
	//pThis->GetEntity()->LineScroll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __EnsureCaretVisible, "EnsureCaretVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __EnsureCaretVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EnsureCaretVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ScrollRange, "ScrollRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "secondary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "primary", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ScrollRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int secondary = arg.GetNumber(0)
	//int primary = arg.GetNumber(1)
	//pThis->GetEntity()->ScrollRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ReplaceSelection, "ReplaceSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ReplaceSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->ReplaceSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetReadOnly, "SetReadOnly")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "readOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetReadOnly)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool readOnly = arg.GetNumber(0)
	//pThis->GetEntity()->SetReadOnly();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CanPaste, "CanPaste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CanPaste)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanPaste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CanUndo, "CanUndo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CanUndo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __EmptyUndoBuffer, "EmptyUndoBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __EmptyUndoBuffer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EmptyUndoBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Undo, "Undo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Undo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Cut, "Cut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Cut)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Copy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Paste, "Paste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Paste)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Paste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Clear)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTextLength, "GetTextLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTextLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetOvertype, "SetOvertype")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "overtype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetOvertype)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool overtype = arg.GetNumber(0)
	//pThis->GetEntity()->SetOvertype();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetOvertype, "GetOvertype")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetOvertype)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOvertype();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretWidth, "SetCaretWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretWidth, "GetCaretWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetTargetStart, "SetTargetStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetTargetStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTargetStart, "GetTargetStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTargetStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetTargetEnd, "SetTargetEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetTargetEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetTargetEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTargetEnd, "GetTargetEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTargetEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetTargetRange, "SetTargetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetTargetRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->SetTargetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTargetText, "GetTargetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTargetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTargetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ReplaceTarget, "ReplaceTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ReplaceTarget)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->ReplaceTarget();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ReplaceTargetRE, "ReplaceTargetRE")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ReplaceTargetRE)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->ReplaceTargetRE();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SearchInTarget, "SearchInTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SearchInTarget)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SearchInTarget();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSearchFlags, "SetSearchFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSearchFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetSearchFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSearchFlags, "GetSearchFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSearchFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSearchFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipShow, "CallTipShow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "definition", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipShow)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//const wxString& definition = arg.GetNumber(1)
	//pThis->GetEntity()->CallTipShow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipCancel, "CallTipCancel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipCancel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CallTipCancel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipActive, "CallTipActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipActive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CallTipActive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipPosAtStart, "CallTipPosAtStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipPosAtStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CallTipPosAtStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipSetPosAtStart, "CallTipSetPosAtStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "posStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipSetPosAtStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int posStart = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetPosAtStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipSetHighlight, "CallTipSetHighlight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipSetHighlight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CallTipSetHighlight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipSetBackground, "CallTipSetBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipSetBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& back = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipSetForeground, "CallTipSetForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipSetForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& fore = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipSetForegroundHighlight, "CallTipSetForegroundHighlight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipSetForegroundHighlight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& fore = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetForegroundHighlight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipUseStyle, "CallTipUseStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipUseStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabSize = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipUseStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CallTipSetPosition, "CallTipSetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "above", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CallTipSetPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool above = arg.GetNumber(0)
	//pThis->GetEntity()->CallTipSetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VisibleFromDocLine, "VisibleFromDocLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VisibleFromDocLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->VisibleFromDocLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DocLineFromVisible, "DocLineFromVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineDisplay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DocLineFromVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineDisplay = arg.GetNumber(0)
	//pThis->GetEntity()->DocLineFromVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WrapCount, "WrapCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WrapCount)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->WrapCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetFoldLevel, "SetFoldLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetFoldLevel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//pThis->GetEntity()->SetFoldLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetFoldLevel, "GetFoldLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetFoldLevel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetFoldLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLastChild, "GetLastChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLastChild)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//pThis->GetEntity()->GetLastChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetFoldParent, "GetFoldParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetFoldParent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetFoldParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ShowLines, "ShowLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ShowLines)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//int lineEnd = arg.GetNumber(1)
	//pThis->GetEntity()->ShowLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HideLines, "HideLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HideLines)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//int lineEnd = arg.GetNumber(1)
	//pThis->GetEntity()->HideLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineVisible, "GetLineVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetAllLinesVisible, "GetAllLinesVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetAllLinesVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAllLinesVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetFoldExpanded, "SetFoldExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expanded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetFoldExpanded)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//bool expanded = arg.GetNumber(1)
	//pThis->GetEntity()->SetFoldExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetFoldExpanded, "GetFoldExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetFoldExpanded)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetFoldExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ToggleFold, "ToggleFold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ToggleFold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->ToggleFold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __FoldLine, "FoldLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __FoldLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int action = arg.GetNumber(1)
	//pThis->GetEntity()->FoldLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __FoldChildren, "FoldChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __FoldChildren)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int action = arg.GetNumber(1)
	//pThis->GetEntity()->FoldChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ExpandChildren, "ExpandChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ExpandChildren)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//pThis->GetEntity()->ExpandChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __FoldAll, "FoldAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __FoldAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int action = arg.GetNumber(0)
	//pThis->GetEntity()->FoldAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __EnsureVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAutomaticFold, "SetAutomaticFold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "automaticFold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAutomaticFold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int automaticFold = arg.GetNumber(0)
	//pThis->GetEntity()->SetAutomaticFold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetAutomaticFold, "GetAutomaticFold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetAutomaticFold)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAutomaticFold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetFoldFlags, "SetFoldFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetFoldFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFoldFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __EnsureVisibleEnforcePolicy, "EnsureVisibleEnforcePolicy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __EnsureVisibleEnforcePolicy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisibleEnforcePolicy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetTabIndents, "SetTabIndents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabIndents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetTabIndents)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool tabIndents = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabIndents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTabIndents, "GetTabIndents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTabIndents)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTabIndents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetBackSpaceUnIndents, "SetBackSpaceUnIndents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bsUnIndents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetBackSpaceUnIndents)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool bsUnIndents = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackSpaceUnIndents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetBackSpaceUnIndents, "GetBackSpaceUnIndents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetBackSpaceUnIndents)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackSpaceUnIndents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMouseDwellTime, "SetMouseDwellTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "periodMilliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMouseDwellTime)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int periodMilliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->SetMouseDwellTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMouseDwellTime, "GetMouseDwellTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMouseDwellTime)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMouseDwellTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordStartPosition, "WordStartPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "onlyWordCharacters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordStartPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//bool onlyWordCharacters = arg.GetNumber(1)
	//pThis->GetEntity()->WordStartPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordEndPosition, "WordEndPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "onlyWordCharacters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordEndPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//bool onlyWordCharacters = arg.GetNumber(1)
	//pThis->GetEntity()->WordEndPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWrapMode, "SetWrapMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWrapMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetWrapMode, "GetWrapMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetWrapMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWrapVisualFlags, "SetWrapVisualFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wrapVisualFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWrapVisualFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wrapVisualFlags = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapVisualFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetWrapVisualFlags, "GetWrapVisualFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetWrapVisualFlags)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapVisualFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWrapVisualFlagsLocation, "SetWrapVisualFlagsLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wrapVisualFlagsLocation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWrapVisualFlagsLocation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wrapVisualFlagsLocation = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapVisualFlagsLocation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetWrapVisualFlagsLocation, "GetWrapVisualFlagsLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetWrapVisualFlagsLocation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapVisualFlagsLocation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWrapStartIndent, "SetWrapStartIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWrapStartIndent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapStartIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetWrapStartIndent, "GetWrapStartIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetWrapStartIndent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapStartIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWrapIndentMode, "SetWrapIndentMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWrapIndentMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetWrapIndentMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetWrapIndentMode, "GetWrapIndentMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetWrapIndentMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWrapIndentMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetLayoutCache, "SetLayoutCache")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetLayoutCache)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutCache();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLayoutCache, "GetLayoutCache")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLayoutCache)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutCache();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetScrollWidth, "SetScrollWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetScrollWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetScrollWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetScrollWidth, "GetScrollWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetScrollWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScrollWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetScrollWidthTracking, "SetScrollWidthTracking")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tracking", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetScrollWidthTracking)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool tracking = arg.GetNumber(0)
	//pThis->GetEntity()->SetScrollWidthTracking();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetScrollWidthTracking, "GetScrollWidthTracking")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetScrollWidthTracking)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScrollWidthTracking();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __TextWidth, "TextWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __TextWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->TextWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetEndAtLastLine, "SetEndAtLastLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "endAtLastLine", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetEndAtLastLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool endAtLastLine = arg.GetNumber(0)
	//pThis->GetEntity()->SetEndAtLastLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetEndAtLastLine, "GetEndAtLastLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetEndAtLastLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndAtLastLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __TextHeight, "TextHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __TextHeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->TextHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetUseVerticalScrollBar, "SetUseVerticalScrollBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetUseVerticalScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->SetUseVerticalScrollBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetUseVerticalScrollBar, "GetUseVerticalScrollBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetUseVerticalScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUseVerticalScrollBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AppendText, "AppendText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AppendText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->AppendText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTwoPhaseDraw, "GetTwoPhaseDraw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTwoPhaseDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTwoPhaseDraw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetTwoPhaseDraw, "SetTwoPhaseDraw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "twoPhase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetTwoPhaseDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool twoPhase = arg.GetNumber(0)
	//pThis->GetEntity()->SetTwoPhaseDraw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPhasesDraw, "GetPhasesDraw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPhasesDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPhasesDraw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetPhasesDraw, "SetPhasesDraw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "phases", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetPhasesDraw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int phases = arg.GetNumber(0)
	//pThis->GetEntity()->SetPhasesDraw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetFirstVisibleLine, "SetFirstVisibleLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineDisplay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetFirstVisibleLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineDisplay = arg.GetNumber(0)
	//pThis->GetEntity()->SetFirstVisibleLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMultiPaste, "SetMultiPaste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "multiPaste", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMultiPaste)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int multiPaste = arg.GetNumber(0)
	//pThis->GetEntity()->SetMultiPaste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMultiPaste, "GetMultiPaste")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMultiPaste)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMultiPaste();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTag, "GetTag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tagNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTag)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tagNumber = arg.GetNumber(0)
	//pThis->GetEntity()->GetTag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __TargetFromSelection, "TargetFromSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __TargetFromSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TargetFromSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LinesJoin, "LinesJoin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LinesJoin)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LinesJoin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LinesSplit, "LinesSplit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LinesSplit)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelWidth = arg.GetNumber(0)
	//pThis->GetEntity()->LinesSplit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetFoldMarginColour, "SetFoldMarginColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetFoldMarginColour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useSetting = arg.GetNumber(0)
	//const wxColour& back = arg.GetNumber(1)
	//pThis->GetEntity()->SetFoldMarginColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetFoldMarginHiColour, "SetFoldMarginHiColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetFoldMarginHiColour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useSetting = arg.GetNumber(0)
	//const wxColour& fore = arg.GetNumber(1)
	//pThis->GetEntity()->SetFoldMarginHiColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineDown, "LineDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineDownExtend, "LineDownExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineDownExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDownExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineUp, "LineUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineUpExtend, "LineUpExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineUpExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineUpExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CharLeft, "CharLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CharLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CharLeftExtend, "CharLeftExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CharLeftExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CharRight, "CharRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CharRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CharRightExtend, "CharRightExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CharRightExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharRightExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordLeft, "WordLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordLeftExtend, "WordLeftExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordLeftExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordRight, "WordRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordRightExtend, "WordRightExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordRightExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordRightExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Home, "Home")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Home)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Home();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HomeExtend, "HomeExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HomeExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineEnd, "LineEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineEndExtend, "LineEndExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineEndExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DocumentStart, "DocumentStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DocumentStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DocumentStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DocumentStartExtend, "DocumentStartExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DocumentStartExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DocumentStartExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DocumentEnd, "DocumentEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DocumentEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DocumentEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DocumentEndExtend, "DocumentEndExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DocumentEndExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DocumentEndExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PageUp, "PageUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PageUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PageUpExtend, "PageUpExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PageUpExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageUpExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PageDown, "PageDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PageDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PageDownExtend, "PageDownExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PageDownExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageDownExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __EditToggleOvertype, "EditToggleOvertype")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __EditToggleOvertype)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EditToggleOvertype();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Cancel, "Cancel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Cancel)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cancel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DeleteBack, "DeleteBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DeleteBack)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Tab, "Tab")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Tab)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Tab();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __BackTab, "BackTab")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __BackTab)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BackTab();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __NewLine, "NewLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __NewLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->NewLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __FormFeed, "FormFeed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __FormFeed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FormFeed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VCHome, "VCHome")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VCHome)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHome();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VCHomeExtend, "VCHomeExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VCHomeExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ZoomIn, "ZoomIn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ZoomIn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ZoomIn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ZoomOut, "ZoomOut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ZoomOut)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ZoomOut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DelWordLeft, "DelWordLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DelWordLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelWordLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DelWordRight, "DelWordRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DelWordRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelWordRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DelWordRightEnd, "DelWordRightEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DelWordRightEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelWordRightEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineCut, "LineCut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineCut)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineCut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineDelete, "LineDelete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineDelete)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDelete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineTranspose, "LineTranspose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineTranspose)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineTranspose();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineDuplicate, "LineDuplicate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineDuplicate)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDuplicate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LowerCase, "LowerCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LowerCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LowerCase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __UpperCase, "UpperCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __UpperCase)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpperCase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineScrollDown, "LineScrollDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineScrollDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineScrollDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineScrollUp, "LineScrollUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineScrollUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineScrollUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DeleteBackNotLine, "DeleteBackNotLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DeleteBackNotLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteBackNotLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HomeDisplay, "HomeDisplay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HomeDisplay)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeDisplay();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HomeDisplayExtend, "HomeDisplayExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HomeDisplayExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineEndDisplay, "LineEndDisplay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineEndDisplay)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndDisplay();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineEndDisplayExtend, "LineEndDisplayExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineEndDisplayExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HomeWrap, "HomeWrap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HomeWrap)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeWrap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HomeWrapExtend, "HomeWrapExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HomeWrapExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineEndWrap, "LineEndWrap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineEndWrap)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndWrap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineEndWrapExtend, "LineEndWrapExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineEndWrapExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VCHomeWrap, "VCHomeWrap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VCHomeWrap)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeWrap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VCHomeWrapExtend, "VCHomeWrapExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VCHomeWrapExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeWrapExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineCopy, "LineCopy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineCopy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineCopy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MoveCaretInsideView, "MoveCaretInsideView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MoveCaretInsideView)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoveCaretInsideView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineLength, "LineLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->LineLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __BraceHighlight, "BraceHighlight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __BraceHighlight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos1 = arg.GetNumber(0)
	//int pos2 = arg.GetNumber(1)
	//pThis->GetEntity()->BraceHighlight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __BraceHighlightIndicator, "BraceHighlightIndicator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useBraceHighlightIndicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __BraceHighlightIndicator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useBraceHighlightIndicator = arg.GetNumber(0)
	//int indicator = arg.GetNumber(1)
	//pThis->GetEntity()->BraceHighlightIndicator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __BraceBadLight, "BraceBadLight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __BraceBadLight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->BraceBadLight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __BraceBadLightIndicator, "BraceBadLightIndicator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useBraceBadLightIndicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __BraceBadLightIndicator)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useBraceBadLightIndicator = arg.GetNumber(0)
	//int indicator = arg.GetNumber(1)
	//pThis->GetEntity()->BraceBadLightIndicator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __BraceMatch, "BraceMatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __BraceMatch)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->BraceMatch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetViewEOL, "GetViewEOL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetViewEOL)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewEOL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetViewEOL, "SetViewEOL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetViewEOL)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->SetViewEOL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetDocPointer, "GetDocPointer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetDocPointer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocPointer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetDocPointer, "SetDocPointer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "docPointer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetDocPointer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* docPointer = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocPointer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetModEventMask, "SetModEventMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetModEventMask)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mask = arg.GetNumber(0)
	//pThis->GetEntity()->SetModEventMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetEdgeColumn, "GetEdgeColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetEdgeColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEdgeColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetEdgeColumn, "SetEdgeColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetEdgeColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdgeColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetEdgeMode, "GetEdgeMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetEdgeMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEdgeMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetEdgeMode, "SetEdgeMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetEdgeMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdgeMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetEdgeColour, "GetEdgeColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetEdgeColour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEdgeColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetEdgeColour, "SetEdgeColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "edgeColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetEdgeColour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& edgeColour = arg.GetNumber(0)
	//pThis->GetEntity()->SetEdgeColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SearchAnchor, "SearchAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SearchAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SearchAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SearchNext, "SearchNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SearchNext)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->SearchNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SearchPrev, "SearchPrev")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SearchPrev)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->SearchPrev();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LinesOnScreen, "LinesOnScreen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LinesOnScreen)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LinesOnScreen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __UsePopUp, "UsePopUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "allowPopUp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __UsePopUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool allowPopUp = arg.GetNumber(0)
	//pThis->GetEntity()->UsePopUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SelectionIsRectangle, "SelectionIsRectangle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SelectionIsRectangle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectionIsRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetZoom, "SetZoom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "zoom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetZoom)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int zoom = arg.GetNumber(0)
	//pThis->GetEntity()->SetZoom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetZoom, "GetZoom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetZoom)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetZoom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CreateDocument, "CreateDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CreateDocument)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AddRefDocument, "AddRefDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "docPointer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AddRefDocument)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* docPointer = arg.GetNumber(0)
	//pThis->GetEntity()->AddRefDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ReleaseDocument, "ReleaseDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "docPointer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ReleaseDocument)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* docPointer = arg.GetNumber(0)
	//pThis->GetEntity()->ReleaseDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetModEventMask, "GetModEventMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetModEventMask)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModEventMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSTCFocus, "SetSTCFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSTCFocus)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool focus = arg.GetNumber(0)
	//pThis->GetEntity()->SetSTCFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSTCFocus, "GetSTCFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSTCFocus)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSTCFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetStatus, "SetStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "statusCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetStatus)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int statusCode = arg.GetNumber(0)
	//pThis->GetEntity()->SetStatus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetStatus, "GetStatus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetStatus)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStatus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMouseDownCaptures, "SetMouseDownCaptures")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "captures", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMouseDownCaptures)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool captures = arg.GetNumber(0)
	//pThis->GetEntity()->SetMouseDownCaptures();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMouseDownCaptures, "GetMouseDownCaptures")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMouseDownCaptures)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMouseDownCaptures();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSTCCursor, "SetSTCCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursorType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSTCCursor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursorType = arg.GetNumber(0)
	//pThis->GetEntity()->SetSTCCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSTCCursor, "GetSTCCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSTCCursor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSTCCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetControlCharSymbol, "SetControlCharSymbol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "symbol", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetControlCharSymbol)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int symbol = arg.GetNumber(0)
	//pThis->GetEntity()->SetControlCharSymbol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetControlCharSymbol, "GetControlCharSymbol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetControlCharSymbol)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetControlCharSymbol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordPartLeft, "WordPartLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordPartLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordPartLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordPartLeftExtend, "WordPartLeftExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordPartLeftExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordPartLeftExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordPartRight, "WordPartRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordPartRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordPartRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordPartRightExtend, "WordPartRightExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordPartRightExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordPartRightExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetVisiblePolicy, "SetVisiblePolicy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visiblePolicy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "visibleSlop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetVisiblePolicy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visiblePolicy = arg.GetNumber(0)
	//int visibleSlop = arg.GetNumber(1)
	//pThis->GetEntity()->SetVisiblePolicy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DelLineLeft, "DelLineLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DelLineLeft)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelLineLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DelLineRight, "DelLineRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DelLineRight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DelLineRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetXOffset, "SetXOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newOffset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetXOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newOffset = arg.GetNumber(0)
	//pThis->GetEntity()->SetXOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetXOffset, "GetXOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetXOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ChooseCaretX, "ChooseCaretX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ChooseCaretX)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ChooseCaretX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetXCaretPolicy, "SetXCaretPolicy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPolicy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretSlop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetXCaretPolicy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPolicy = arg.GetNumber(0)
	//int caretSlop = arg.GetNumber(1)
	//pThis->GetEntity()->SetXCaretPolicy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetYCaretPolicy, "SetYCaretPolicy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPolicy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caretSlop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetYCaretPolicy)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPolicy = arg.GetNumber(0)
	//int caretSlop = arg.GetNumber(1)
	//pThis->GetEntity()->SetYCaretPolicy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetPrintWrapMode, "SetPrintWrapMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetPrintWrapMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintWrapMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPrintWrapMode, "GetPrintWrapMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPrintWrapMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintWrapMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetHotspotActiveForeground, "SetHotspotActiveForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetHotspotActiveForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useSetting = arg.GetNumber(0)
	//const wxColour& fore = arg.GetNumber(1)
	//pThis->GetEntity()->SetHotspotActiveForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetHotspotActiveForeground, "GetHotspotActiveForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetHotspotActiveForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotActiveForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetHotspotActiveBackground, "SetHotspotActiveBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useSetting", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetHotspotActiveBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool useSetting = arg.GetNumber(0)
	//const wxColour& back = arg.GetNumber(1)
	//pThis->GetEntity()->SetHotspotActiveBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetHotspotActiveBackground, "GetHotspotActiveBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetHotspotActiveBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotActiveBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetHotspotActiveUnderline, "SetHotspotActiveUnderline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetHotspotActiveUnderline)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool underline = arg.GetNumber(0)
	//pThis->GetEntity()->SetHotspotActiveUnderline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetHotspotActiveUnderline, "GetHotspotActiveUnderline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetHotspotActiveUnderline)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotActiveUnderline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetHotspotSingleLine, "SetHotspotSingleLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "singleLine", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetHotspotSingleLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool singleLine = arg.GetNumber(0)
	//pThis->GetEntity()->SetHotspotSingleLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetHotspotSingleLine, "GetHotspotSingleLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetHotspotSingleLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHotspotSingleLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ParaDown, "ParaDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ParaDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParaDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ParaDownExtend, "ParaDownExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ParaDownExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParaDownExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ParaUp, "ParaUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ParaUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParaUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ParaUpExtend, "ParaUpExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ParaUpExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ParaUpExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PositionBefore, "PositionBefore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PositionBefore)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->PositionBefore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PositionAfter, "PositionAfter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PositionAfter)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->PositionAfter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PositionRelative, "PositionRelative")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "relative", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PositionRelative)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int relative = arg.GetNumber(1)
	//pThis->GetEntity()->PositionRelative();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CopyRange, "CopyRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CopyRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CopyRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CopyText, "CopyText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CopyText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int length = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->CopyText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionMode, "SetSelectionMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionMode, "GetSelectionMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionMode)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineSelStartPosition, "GetLineSelStartPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineSelStartPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineSelStartPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineSelEndPosition, "GetLineSelEndPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineSelEndPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineSelEndPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineDownRectExtend, "LineDownRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineDownRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDownRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineUpRectExtend, "LineUpRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineUpRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineUpRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CharLeftRectExtend, "CharLeftRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CharLeftRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharLeftRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CharRightRectExtend, "CharRightRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CharRightRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CharRightRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HomeRectExtend, "HomeRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HomeRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HomeRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VCHomeRectExtend, "VCHomeRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VCHomeRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LineEndRectExtend, "LineEndRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LineEndRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineEndRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PageUpRectExtend, "PageUpRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PageUpRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageUpRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PageDownRectExtend, "PageDownRectExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PageDownRectExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageDownRectExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StutteredPageUp, "StutteredPageUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StutteredPageUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StutteredPageUpExtend, "StutteredPageUpExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StutteredPageUpExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageUpExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StutteredPageDown, "StutteredPageDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StutteredPageDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StutteredPageDownExtend, "StutteredPageDownExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StutteredPageDownExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StutteredPageDownExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordLeftEnd, "WordLeftEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordLeftEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordLeftEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordLeftEndExtend, "WordLeftEndExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordLeftEndExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordLeftEndExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordRightEnd, "WordRightEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordRightEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordRightEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WordRightEndExtend, "WordRightEndExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WordRightEndExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WordRightEndExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetWhitespaceChars, "SetWhitespaceChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetWhitespaceChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& characters = arg.GetNumber(0)
	//pThis->GetEntity()->SetWhitespaceChars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetWhitespaceChars, "GetWhitespaceChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetWhitespaceChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWhitespaceChars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetPunctuationChars, "SetPunctuationChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "characters", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetPunctuationChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& characters = arg.GetNumber(0)
	//pThis->GetEntity()->SetPunctuationChars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPunctuationChars, "GetPunctuationChars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPunctuationChars)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPunctuationChars();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCharsDefault, "SetCharsDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCharsDefault)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetCharsDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetCurrent, "AutoCompGetCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetCurrent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetCurrent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetCaseInsensitiveBehaviour, "AutoCompSetCaseInsensitiveBehaviour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "behaviour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetCaseInsensitiveBehaviour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int behaviour = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetCaseInsensitiveBehaviour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetCaseInsensitiveBehaviour, "AutoCompGetCaseInsensitiveBehaviour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetCaseInsensitiveBehaviour)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetCaseInsensitiveBehaviour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetMulti, "AutoCompSetMulti")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "multi", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetMulti)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int multi = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetMulti();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetMulti, "AutoCompGetMulti")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetMulti)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetMulti();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompSetOrder, "AutoCompSetOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompSetOrder)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int order = arg.GetNumber(0)
	//pThis->GetEntity()->AutoCompSetOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AutoCompGetOrder, "AutoCompGetOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AutoCompGetOrder)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AutoCompGetOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Allocate, "Allocate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Allocate)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bytes = arg.GetNumber(0)
	//pThis->GetEntity()->Allocate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __FindColumn, "FindColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __FindColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->FindColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretSticky, "GetCaretSticky")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretSticky)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretSticky();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretSticky, "SetCaretSticky")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "useCaretStickyBehaviour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretSticky)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int useCaretStickyBehaviour = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretSticky();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ToggleCaretSticky, "ToggleCaretSticky")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ToggleCaretSticky)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToggleCaretSticky();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetPasteConvertEndings, "SetPasteConvertEndings")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "convert", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetPasteConvertEndings)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool convert = arg.GetNumber(0)
	//pThis->GetEntity()->SetPasteConvertEndings();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPasteConvertEndings, "GetPasteConvertEndings")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPasteConvertEndings)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPasteConvertEndings();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SelectionDuplicate, "SelectionDuplicate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SelectionDuplicate)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectionDuplicate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretLineBackAlpha, "SetCaretLineBackAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretLineBackAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alpha = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretLineBackAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretLineBackAlpha, "GetCaretLineBackAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretLineBackAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretLineBackAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretStyle, "SetCaretStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretStyle = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretStyle, "GetCaretStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetIndicatorCurrent, "SetIndicatorCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetIndicatorCurrent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndicatorCurrent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetIndicatorCurrent, "GetIndicatorCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetIndicatorCurrent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndicatorCurrent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetIndicatorValue, "SetIndicatorValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetIndicatorValue)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetIndicatorValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetIndicatorValue, "GetIndicatorValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetIndicatorValue)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndicatorValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorFillRange, "IndicatorFillRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorFillRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int fillLength = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorFillRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorClearRange, "IndicatorClearRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clearLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorClearRange)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int clearLength = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorClearRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorAllOnFor, "IndicatorAllOnFor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorAllOnFor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorAllOnFor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorValueAt, "IndicatorValueAt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorValueAt)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorValueAt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorStart, "IndicatorStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorEnd, "IndicatorEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetPositionCacheSize, "SetPositionCacheSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetPositionCacheSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetPositionCacheSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPositionCacheSize, "GetPositionCacheSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPositionCacheSize)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPositionCacheSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CopyAllowLine, "CopyAllowLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CopyAllowLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CopyAllowLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCharacterPointer, "GetCharacterPointer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCharacterPointer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCharacterPointer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetRangePointer, "GetRangePointer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rangeLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetRangePointer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int rangeLength = arg.GetNumber(1)
	//pThis->GetEntity()->GetRangePointer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetGapPosition, "GetGapPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetGapPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGapPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorSetAlpha, "IndicatorSetAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorSetAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int alpha = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorGetAlpha, "IndicatorGetAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorGetAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorSetOutlineAlpha, "IndicatorSetOutlineAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorSetOutlineAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//int alpha = arg.GetNumber(1)
	//pThis->GetEntity()->IndicatorSetOutlineAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IndicatorGetOutlineAlpha, "IndicatorGetOutlineAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indicator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IndicatorGetOutlineAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indicator = arg.GetNumber(0)
	//pThis->GetEntity()->IndicatorGetOutlineAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetExtraAscent, "SetExtraAscent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extraAscent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetExtraAscent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extraAscent = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraAscent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetExtraAscent, "GetExtraAscent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetExtraAscent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraAscent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetExtraDescent, "SetExtraDescent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extraDescent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetExtraDescent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extraDescent = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraDescent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetExtraDescent, "GetExtraDescent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetExtraDescent)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraDescent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarkerSymbolDefined, "GetMarkerSymbolDefined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarkerSymbolDefined)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//pThis->GetEntity()->GetMarkerSymbolDefined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginSetText, "MarginSetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginSetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->MarginSetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginGetText, "MarginGetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginGetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->MarginGetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginSetStyle, "MarginSetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginSetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->MarginSetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginGetStyle, "MarginGetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginGetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->MarginGetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginSetStyles, "MarginSetStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginSetStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//const wxString& styles = arg.GetNumber(1)
	//pThis->GetEntity()->MarginSetStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginGetStyles, "MarginGetStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginGetStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->MarginGetStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginTextClearAll, "MarginTextClearAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginTextClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarginTextClearAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginSetStyleOffset, "MarginSetStyleOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginSetStyleOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->MarginSetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarginGetStyleOffset, "MarginGetStyleOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarginGetStyleOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarginGetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMarginOptions, "SetMarginOptions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "marginOptions", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMarginOptions)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int marginOptions = arg.GetNumber(0)
	//pThis->GetEntity()->SetMarginOptions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMarginOptions, "GetMarginOptions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMarginOptions)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMarginOptions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationSetText, "AnnotationSetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationSetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->AnnotationSetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationGetText, "AnnotationGetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationGetText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationGetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationSetStyle, "AnnotationSetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationSetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->AnnotationSetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationGetStyle, "AnnotationGetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationGetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationGetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationSetStyles, "AnnotationSetStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationSetStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//const wxString& styles = arg.GetNumber(1)
	//pThis->GetEntity()->AnnotationSetStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationGetStyles, "AnnotationGetStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationGetStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationGetStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationGetLines, "AnnotationGetLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationGetLines)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationGetLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationClearAll, "AnnotationClearAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationClearAll)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AnnotationClearAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationSetVisible, "AnnotationSetVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationSetVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationSetVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationGetVisible, "AnnotationGetVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationGetVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AnnotationGetVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationSetStyleOffset, "AnnotationSetStyleOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationSetStyleOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationSetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationGetStyleOffset, "AnnotationGetStyleOffset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationGetStyleOffset)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AnnotationGetStyleOffset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ReleaseAllExtendedStyles, "ReleaseAllExtendedStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ReleaseAllExtendedStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReleaseAllExtendedStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AllocateExtendedStyles, "AllocateExtendedStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numberStyles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AllocateExtendedStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numberStyles = arg.GetNumber(0)
	//pThis->GetEntity()->AllocateExtendedStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AddUndoAction, "AddUndoAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "token", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AddUndoAction)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int token = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->AddUndoAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CharPositionFromPoint, "CharPositionFromPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CharPositionFromPoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->CharPositionFromPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CharPositionFromPointClose, "CharPositionFromPointClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CharPositionFromPointClose)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->CharPositionFromPointClose();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMouseSelectionRectangularSwitch, "SetMouseSelectionRectangularSwitch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mouseSelectionRectangularSwitch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMouseSelectionRectangularSwitch)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool mouseSelectionRectangularSwitch = arg.GetNumber(0)
	//pThis->GetEntity()->SetMouseSelectionRectangularSwitch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMouseSelectionRectangularSwitch, "GetMouseSelectionRectangularSwitch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMouseSelectionRectangularSwitch)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMouseSelectionRectangularSwitch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMultipleSelection, "SetMultipleSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "multipleSelection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMultipleSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool multipleSelection = arg.GetNumber(0)
	//pThis->GetEntity()->SetMultipleSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMultipleSelection, "GetMultipleSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMultipleSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMultipleSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAdditionalSelectionTyping, "SetAdditionalSelectionTyping")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "additionalSelectionTyping", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAdditionalSelectionTyping)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool additionalSelectionTyping = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalSelectionTyping();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetAdditionalSelectionTyping, "GetAdditionalSelectionTyping")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetAdditionalSelectionTyping)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalSelectionTyping();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAdditionalCaretsBlink, "SetAdditionalCaretsBlink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "additionalCaretsBlink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAdditionalCaretsBlink)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool additionalCaretsBlink = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalCaretsBlink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetAdditionalCaretsBlink, "GetAdditionalCaretsBlink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetAdditionalCaretsBlink)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalCaretsBlink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAdditionalCaretsVisible, "SetAdditionalCaretsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "additionalCaretsBlink", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAdditionalCaretsVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool additionalCaretsBlink = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalCaretsVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetAdditionalCaretsVisible, "GetAdditionalCaretsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetAdditionalCaretsVisible)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalCaretsVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelections, "GetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelections)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionEmpty, "GetSelectionEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionEmpty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ClearSelections, "ClearSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ClearSelections)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AddSelection, "AddSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caret", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AddSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caret = arg.GetNumber(0)
	//int anchor = arg.GetNumber(1)
	//pThis->GetEntity()->AddSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DropSelectionN, "DropSelectionN")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DropSelectionN)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->DropSelectionN();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMainSelection, "SetMainSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMainSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->SetMainSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetMainSelection, "GetMainSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetMainSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMainSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionNCaret, "SetSelectionNCaret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionNCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNCaret();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionNCaret, "GetSelectionNCaret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionNCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNCaret();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionNAnchor, "SetSelectionNAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "posAnchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionNAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int posAnchor = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionNAnchor, "GetSelectionNAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionNAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionNCaretVirtualSpace, "SetSelectionNCaretVirtualSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "space", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionNCaretVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int space = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNCaretVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionNCaretVirtualSpace, "GetSelectionNCaretVirtualSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionNCaretVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNCaretVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionNAnchorVirtualSpace, "SetSelectionNAnchorVirtualSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "space", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionNAnchorVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int space = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNAnchorVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionNAnchorVirtualSpace, "GetSelectionNAnchorVirtualSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionNAnchorVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNAnchorVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionNStart, "SetSelectionNStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionNStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionNStart, "GetSelectionNStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionNStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelectionNEnd, "SetSelectionNEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelectionNEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelectionNEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectionNEnd, "GetSelectionNEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectionNEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectionNEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetRectangularSelectionCaret, "SetRectangularSelectionCaret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetRectangularSelectionCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionCaret();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetRectangularSelectionCaret, "GetRectangularSelectionCaret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetRectangularSelectionCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionCaret();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetRectangularSelectionAnchor, "SetRectangularSelectionAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "posAnchor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetRectangularSelectionAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int posAnchor = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetRectangularSelectionAnchor, "GetRectangularSelectionAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetRectangularSelectionAnchor)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetRectangularSelectionCaretVirtualSpace, "SetRectangularSelectionCaretVirtualSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "space", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetRectangularSelectionCaretVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int space = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionCaretVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetRectangularSelectionCaretVirtualSpace, "GetRectangularSelectionCaretVirtualSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetRectangularSelectionCaretVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionCaretVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetRectangularSelectionAnchorVirtualSpace, "SetRectangularSelectionAnchorVirtualSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "space", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetRectangularSelectionAnchorVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int space = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionAnchorVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetRectangularSelectionAnchorVirtualSpace, "GetRectangularSelectionAnchorVirtualSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetRectangularSelectionAnchorVirtualSpace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionAnchorVirtualSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetVirtualSpaceOptions, "SetVirtualSpaceOptions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "virtualSpaceOptions", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetVirtualSpaceOptions)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int virtualSpaceOptions = arg.GetNumber(0)
	//pThis->GetEntity()->SetVirtualSpaceOptions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetVirtualSpaceOptions, "GetVirtualSpaceOptions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetVirtualSpaceOptions)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVirtualSpaceOptions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetRectangularSelectionModifier, "SetRectangularSelectionModifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetRectangularSelectionModifier)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int modifier = arg.GetNumber(0)
	//pThis->GetEntity()->SetRectangularSelectionModifier();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetRectangularSelectionModifier, "GetRectangularSelectionModifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetRectangularSelectionModifier)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRectangularSelectionModifier();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAdditionalSelForeground, "SetAdditionalSelForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAdditionalSelForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& fore = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalSelForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAdditionalSelBackground, "SetAdditionalSelBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "back", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAdditionalSelBackground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& back = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalSelBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAdditionalSelAlpha, "SetAdditionalSelAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAdditionalSelAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alpha = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalSelAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetAdditionalSelAlpha, "GetAdditionalSelAlpha")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetAdditionalSelAlpha)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalSelAlpha();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetAdditionalCaretForeground, "SetAdditionalCaretForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fore", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetAdditionalCaretForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& fore = arg.GetNumber(0)
	//pThis->GetEntity()->SetAdditionalCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetAdditionalCaretForeground, "GetAdditionalCaretForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetAdditionalCaretForeground)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAdditionalCaretForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __RotateSelection, "RotateSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __RotateSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RotateSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SwapMainAnchorCaret, "SwapMainAnchorCaret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SwapMainAnchorCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SwapMainAnchorCaret();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ChangeLexerState, "ChangeLexerState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ChangeLexerState)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->ChangeLexerState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ContractedFoldNext, "ContractedFoldNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ContractedFoldNext)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineStart = arg.GetNumber(0)
	//pThis->GetEntity()->ContractedFoldNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VerticalCentreCaret, "VerticalCentreCaret")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VerticalCentreCaret)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VerticalCentreCaret();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MoveSelectedLinesUp, "MoveSelectedLinesUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MoveSelectedLinesUp)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoveSelectedLinesUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MoveSelectedLinesDown, "MoveSelectedLinesDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MoveSelectedLinesDown)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoveSelectedLinesDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetIdentifier, "SetIdentifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "identifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetIdentifier)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int identifier = arg.GetNumber(0)
	//pThis->GetEntity()->SetIdentifier();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetIdentifier, "GetIdentifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetIdentifier)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIdentifier();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __RGBAImageSetWidth, "RGBAImageSetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __RGBAImageSetWidth)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->RGBAImageSetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __RGBAImageSetHeight, "RGBAImageSetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __RGBAImageSetHeight)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->RGBAImageSetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __RGBAImageSetScale, "RGBAImageSetScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "scalePercent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __RGBAImageSetScale)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int scalePercent = arg.GetNumber(0)
	//pThis->GetEntity()->RGBAImageSetScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkerDefineRGBAImage, "MarkerDefineRGBAImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "markerNumber", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkerDefineRGBAImage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int markerNumber = arg.GetNumber(0)
	//const unsigned char* pixels = arg.GetNumber(1)
	//pThis->GetEntity()->MarkerDefineRGBAImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __RegisterRGBAImage, "RegisterRGBAImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __RegisterRGBAImage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//const unsigned char* pixels = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterRGBAImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ScrollToStart, "ScrollToStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ScrollToStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ScrollToStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ScrollToEnd, "ScrollToEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ScrollToEnd)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ScrollToEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetTechnology, "SetTechnology")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "technology", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetTechnology)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int technology = arg.GetNumber(0)
	//pThis->GetEntity()->SetTechnology();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTechnology, "GetTechnology")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTechnology)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTechnology();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CreateLoader, "CreateLoader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CreateLoader)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bytes = arg.GetNumber(0)
	//pThis->GetEntity()->CreateLoader();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VCHomeDisplay, "VCHomeDisplay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VCHomeDisplay)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeDisplay();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __VCHomeDisplayExtend, "VCHomeDisplayExtend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __VCHomeDisplayExtend)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->VCHomeDisplayExtend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCaretLineVisibleAlways, "GetCaretLineVisibleAlways")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCaretLineVisibleAlways)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCaretLineVisibleAlways();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetCaretLineVisibleAlways, "SetCaretLineVisibleAlways")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alwaysVisible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetCaretLineVisibleAlways)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool alwaysVisible = arg.GetNumber(0)
	//pThis->GetEntity()->SetCaretLineVisibleAlways();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetLineEndTypesAllowed, "SetLineEndTypesAllowed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineEndBitSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetLineEndTypesAllowed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineEndBitSet = arg.GetNumber(0)
	//pThis->GetEntity()->SetLineEndTypesAllowed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineEndTypesAllowed, "GetLineEndTypesAllowed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineEndTypesAllowed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineEndTypesAllowed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineEndTypesActive, "GetLineEndTypesActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineEndTypesActive)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineEndTypesActive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetRepresentation, "SetRepresentation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encodedCharacter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "representation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetRepresentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& encodedCharacter = arg.GetNumber(0)
	//const wxString& representation = arg.GetNumber(1)
	//pThis->GetEntity()->SetRepresentation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetRepresentation, "GetRepresentation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encodedCharacter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetRepresentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& encodedCharacter = arg.GetNumber(0)
	//pThis->GetEntity()->GetRepresentation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ClearRepresentation, "ClearRepresentation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encodedCharacter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ClearRepresentation)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& encodedCharacter = arg.GetNumber(0)
	//pThis->GetEntity()->ClearRepresentation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StartRecord, "StartRecord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StartRecord)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StartRecord();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StopRecord, "StopRecord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StopRecord)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StopRecord();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetLexer, "SetLexer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lexer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetLexer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lexer = arg.GetNumber(0)
	//pThis->GetEntity()->SetLexer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLexer, "GetLexer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLexer)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLexer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Colourise, "Colourise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Colourise)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->Colourise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetProperty, "SetProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetProperty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& key = arg.GetNumber(0)
	//const wxString& value = arg.GetNumber(1)
	//pThis->GetEntity()->SetProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetKeyWords, "SetKeyWords")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keywordSet", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keyWords", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetKeyWords)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int keywordSet = arg.GetNumber(0)
	//const wxString& keyWords = arg.GetNumber(1)
	//pThis->GetEntity()->SetKeyWords();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetLexerLanguage, "SetLexerLanguage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "language", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetLexerLanguage)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& language = arg.GetNumber(0)
	//pThis->GetEntity()->SetLexerLanguage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetProperty, "GetProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetProperty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& key = arg.GetNumber(0)
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPropertyExpanded, "GetPropertyExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPropertyExpanded)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& key = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyExpanded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPropertyInt, "GetPropertyInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPropertyInt)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& key = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyInt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetStyleBitsNeeded, "GetStyleBitsNeeded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetStyleBitsNeeded)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleBitsNeeded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PrivateLexerCall, "PrivateLexerCall")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "operation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pointer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PrivateLexerCall)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int operation = arg.GetNumber(0)
	//void* pointer = arg.GetNumber(1)
	//pThis->GetEntity()->PrivateLexerCall();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PropertyNames, "PropertyNames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PropertyNames)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PropertyNames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PropertyType, "PropertyType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PropertyType)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->PropertyType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DescribeProperty, "DescribeProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DescribeProperty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->DescribeProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DescribeKeyWordSets, "DescribeKeyWordSets")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DescribeKeyWordSets)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DescribeKeyWordSets();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineEndTypesSupported, "GetLineEndTypesSupported")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineEndTypesSupported)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineEndTypesSupported();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AllocateSubStyles, "AllocateSubStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleBase", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "numberStyles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AllocateSubStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleBase = arg.GetNumber(0)
	//int numberStyles = arg.GetNumber(1)
	//pThis->GetEntity()->AllocateSubStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSubStylesStart, "GetSubStylesStart")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleBase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSubStylesStart)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleBase = arg.GetNumber(0)
	//pThis->GetEntity()->GetSubStylesStart();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSubStylesLength, "GetSubStylesLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleBase", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSubStylesLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleBase = arg.GetNumber(0)
	//pThis->GetEntity()->GetSubStylesLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetStyleFromSubStyle, "GetStyleFromSubStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "subStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetStyleFromSubStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int subStyle = arg.GetNumber(0)
	//pThis->GetEntity()->GetStyleFromSubStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetPrimaryStyleFromStyle, "GetPrimaryStyleFromStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetPrimaryStyleFromStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->GetPrimaryStyleFromStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __FreeSubStyles, "FreeSubStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __FreeSubStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FreeSubStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetIdentifiers, "SetIdentifiers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "identifiers", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetIdentifiers)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//const wxString& identifiers = arg.GetNumber(1)
	//pThis->GetEntity()->SetIdentifiers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DistanceToSecondaryStyles, "DistanceToSecondaryStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DistanceToSecondaryStyles)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DistanceToSecondaryStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSubStyleBases, "GetSubStyleBases")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSubStyleBases)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSubStyleBases();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCurrentLine, "GetCurrentLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCurrentLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetSpec, "StyleSetSpec")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleNum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "spec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetSpec)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleNum = arg.GetNumber(0)
	//const wxString& spec = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetSpec();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleGetFont, "StyleGetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleGetFont)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->StyleGetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetFont, "StyleSetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "styleNum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetFont)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleNum = arg.GetNumber(0)
	//wxFont& font = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetFontAttr, "StyleSetFontAttr")
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

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetFontAttr)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int styleNum = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//const wxString& faceName = arg.GetNumber(2)
	//bool bold = arg.GetNumber(3)
	//bool italic = arg.GetNumber(4)
	//bool underline = arg.GetNumber(5)
	//wxFontEncoding encoding = arg.GetNumber(6)
	//pThis->GetEntity()->StyleSetFontAttr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetCharacterSet, "StyleSetCharacterSet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "characterSet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetCharacterSet)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int characterSet = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetCharacterSet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __StyleSetFontEncoding, "StyleSetFontEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __StyleSetFontEncoding)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//wxFontEncoding encoding = arg.GetNumber(1)
	//pThis->GetEntity()->StyleSetFontEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __CmdKeyExecute, "CmdKeyExecute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __CmdKeyExecute)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmd = arg.GetNumber(0)
	//pThis->GetEntity()->CmdKeyExecute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetMargins)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int right = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PointFromPosition, "PointFromPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PointFromPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->PointFromPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ScrollToLine, "ScrollToLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ScrollToLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollToLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ScrollToColumn, "ScrollToColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ScrollToColumn)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollToColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SendMsg, "SendMsg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SendMsg)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//wxUIntPtr wp = arg.GetNumber(1)
	//wxIntPtr lp = arg.GetNumber(2)
	//pThis->GetEntity()->SendMsg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetVScrollBar, "SetVScrollBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetVScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxScrollBar* bar = arg.GetNumber(0)
	//pThis->GetEntity()->SetVScrollBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetHScrollBar, "SetHScrollBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetHScrollBar)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxScrollBar* bar = arg.GetNumber(0)
	//pThis->GetEntity()->SetHScrollBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLastKeydownProcessed, "GetLastKeydownProcessed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLastKeydownProcessed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastKeydownProcessed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetLastKeydownProcessed, "SetLastKeydownProcessed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetLastKeydownProcessed)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool val = arg.GetNumber(0)
	//pThis->GetEntity()->SetLastKeydownProcessed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SaveFile, "SaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SaveFile)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __LoadFile)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DoDragEnter, "DoDragEnter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultRes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DoDragEnter)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxDragResult defaultRes = arg.GetNumber(2)
	//pThis->GetEntity()->DoDragEnter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DoDragOver, "DoDragOver")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultRes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DoDragOver)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxDragResult defaultRes = arg.GetNumber(2)
	//pThis->GetEntity()->DoDragOver();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DoDragLeave, "DoDragLeave")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DoDragLeave)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoDragLeave();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DoDropText, "DoDropText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DoDropText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long x = arg.GetNumber(0)
	//long y = arg.GetNumber(1)
	//const wxString& data = arg.GetNumber(2)
	//pThis->GetEntity()->DoDropText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AnnotationClearLine, "AnnotationClearLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AnnotationClearLine)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->AnnotationClearLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AddTextRaw, "AddTextRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AddTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* text = arg.GetNumber(0)
	//int length = arg.GetNumber(1)
	//pThis->GetEntity()->AddTextRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __InsertTextRaw, "InsertTextRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __InsertTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//const char* text = arg.GetNumber(1)
	//pThis->GetEntity()->InsertTextRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetCurLineRaw, "GetCurLineRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "linePos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetCurLineRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* linePos = arg.GetNumber(0)
	//pThis->GetEntity()->GetCurLineRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineRaw, "GetLineRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int line = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelectedTextRaw, "GetSelectedTextRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelectedTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedTextRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTextRangeRaw, "GetTextRangeRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTextRangeRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startPos = arg.GetNumber(0)
	//int endPos = arg.GetNumber(1)
	//pThis->GetEntity()->GetTextRangeRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetTextRaw, "SetTextRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* text = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetTextRaw, "GetTextRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __AppendTextRaw, "AppendTextRaw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __AppendTextRaw)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* text = arg.GetNumber(0)
	//int length = arg.GetNumber(1)
	//pThis->GetEntity()->AppendTextRaw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLibraryVersionInfo, "GetLibraryVersionInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLibraryVersionInfo)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLibraryVersionInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __WriteText, "WriteText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __WriteText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->WriteText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Remove)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long from = arg.GetNumber(0)
	//long to = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __Replace)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long from = arg.GetNumber(0)
	//long to = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetInsertionPoint, "SetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetInsertionPoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetInsertionPoint, "GetInsertionPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetInsertionPoint)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInsertionPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLastPosition, "GetLastPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLastPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long from = arg.GetNumber(0)
	//long to = arg.GetNumber(1)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SelectNone, "SelectNone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SelectNone)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectNone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetSelection)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long* from = arg.GetNumber(0)
	//long* to = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IsEditable, "IsEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IsEditable)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetEditable, "SetEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetEditable)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool editable = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineLength, "GetLineLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineLength)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetLineText, "GetLineText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetLineText)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetNumberOfLines, "GetNumberOfLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetNumberOfLines)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberOfLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __IsModified, "IsModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __IsModified)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __MarkDirty, "MarkDirty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __MarkDirty)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarkDirty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __DiscardEdits, "DiscardEdits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __DiscardEdits)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DiscardEdits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//long end = arg.GetNumber(1)
	//const wxTextAttr& style = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __GetStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long position = arg.GetNumber(0)
	//wxTextAttr& style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __SetDefaultStyle, "SetDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __SetDefaultStyle)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttr& style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __XYToPosition, "XYToPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __XYToPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long x = arg.GetNumber(0)
	//long y = arg.GetNumber(1)
	//pThis->GetEntity()->XYToPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __PositionToXY, "PositionToXY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __PositionToXY)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//long* x = arg.GetNumber(1)
	//long* y = arg.GetNumber(2)
	//pThis->GetEntity()->PositionToXY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __ShowPosition, "ShowPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __ShowPosition)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HitTest)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//long* pos = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StyledTextCtrl, __HitTest_1, "HitTest_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StyledTextCtrl, __HitTest_1)
{
	Object_wx_StyledTextCtrl *pThis = Object_wx_StyledTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//wxTextCoord* col = arg.GetNumber(1)
	//wxTextCoord* row = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStyledTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StyledTextCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__StyledTextCtrl);
	Gura_AssignFunction(__StyledTextCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_StyledTextCtrl, __Create);
	Gura_AssignMethod(wx_StyledTextCtrl, __AddText);
	Gura_AssignMethod(wx_StyledTextCtrl, __AddStyledText);
	Gura_AssignMethod(wx_StyledTextCtrl, __InsertText);
	Gura_AssignMethod(wx_StyledTextCtrl, __ChangeInsertion);
	Gura_AssignMethod(wx_StyledTextCtrl, __ClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, __DeleteRange);
	Gura_AssignMethod(wx_StyledTextCtrl, __ClearDocumentStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLength);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCharAt);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCurrentPos);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetStyleAt);
	Gura_AssignMethod(wx_StyledTextCtrl, __Redo);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetUndoCollection);
	Gura_AssignMethod(wx_StyledTextCtrl, __SelectAll);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSavePoint);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetStyledText);
	Gura_AssignMethod(wx_StyledTextCtrl, __CanRedo);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerLineFromHandle);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerDeleteHandle);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetUndoCollection);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetViewWhiteSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetViewWhiteSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __PositionFromPoint);
	Gura_AssignMethod(wx_StyledTextCtrl, __PositionFromPointClose);
	Gura_AssignMethod(wx_StyledTextCtrl, __GotoLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __GotoPos);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCurLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetEndStyled);
	Gura_AssignMethod(wx_StyledTextCtrl, __ConvertEOLs);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetEOLMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetEOLMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __StartStyling);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetStyling);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetBufferedDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetBufferedDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetTabWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTabWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __ClearTabStops);
	Gura_AssignMethod(wx_StyledTextCtrl, __AddTabStop);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetNextTabStop);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCodePage);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetIMEInteraction);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetIMEInteraction);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerDefine);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerSetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerSetBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerSetBackgroundSelected);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerEnableHighlight);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerAdd);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerDelete);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerDeleteAll);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerGet);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerNext);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerPrevious);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerDefineBitmap);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerAddSet);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerSetAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMarginType);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarginType);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMarginWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarginWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMarginMask);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarginMask);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMarginSensitive);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarginSensitive);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMarginCursor);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarginCursor);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetBold);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetItalic);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetSize);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetFaceName);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetEOLFilled);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleResetDefault);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetUnderline);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetBold);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetItalic);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetSize);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetFaceName);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetEOLFilled);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetUnderline);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetCase);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetCharacterSet);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetChangeable);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetHotSpot);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetCase);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetSizeFractional);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetSizeFractional);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetWeight);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetWeight);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetHotSpot);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelEOLFilled);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelEOLFilled);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __CmdKeyAssign);
	Gura_AssignMethod(wx_StyledTextCtrl, __CmdKeyClear);
	Gura_AssignMethod(wx_StyledTextCtrl, __CmdKeyClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetStyleBytes);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretPeriod);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretPeriod);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWordChars);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetWordChars);
	Gura_AssignMethod(wx_StyledTextCtrl, __BeginUndoAction);
	Gura_AssignMethod(wx_StyledTextCtrl, __EndUndoAction);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorSetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorGetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorSetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorGetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorSetUnder);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorGetUnder);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorSetHoverStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorGetHoverStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorSetHoverForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorGetHoverForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorSetFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorGetFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWhitespaceForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWhitespaceBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWhitespaceSize);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetWhitespaceSize);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetStyleBits);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetStyleBits);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetLineState);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineState);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMaxLineState);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretLineVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretLineVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretLineBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretLineBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetChangeable);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompShow);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompCancel);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompActive);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompPosStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompComplete);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompStops);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetSeparator);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetSeparator);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSelect);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetCancelAtStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetCancelAtStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetFillUps);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetChooseSingle);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetChooseSingle);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetIgnoreCase);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetIgnoreCase);
	Gura_AssignMethod(wx_StyledTextCtrl, __UserListShow);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetAutoHide);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetAutoHide);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetDropRestOfWord);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetDropRestOfWord);
	Gura_AssignMethod(wx_StyledTextCtrl, __RegisterImage);
	Gura_AssignMethod(wx_StyledTextCtrl, __ClearRegisteredImages);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetTypeSeparator);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetTypeSeparator);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetMaxWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetMaxWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetMaxHeight);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetMaxHeight);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetIndent);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetIndent);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetUseTabs);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetUseTabs);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetLineIndentation);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineIndentation);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineIndentPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, __CountCharacters);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetUseHorizontalScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetUseHorizontalScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetIndentationGuides);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetIndentationGuides);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetHighlightGuide);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetHighlightGuide);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineEndPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCodePage);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetReadOnly);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCurrentPos);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetEmptySelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetPrintMagnification);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPrintMagnification);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetPrintColourMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPrintColourMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __FindText);
	Gura_AssignMethod(wx_StyledTextCtrl, __FormatRange);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetFirstVisibleLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineCount);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMarginLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarginLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMarginRight);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarginRight);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetModify);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectedText);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTextRange);
	Gura_AssignMethod(wx_StyledTextCtrl, __HideSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineFromPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __PositionFromLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineScroll);
	Gura_AssignMethod(wx_StyledTextCtrl, __EnsureCaretVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __ScrollRange);
	Gura_AssignMethod(wx_StyledTextCtrl, __ReplaceSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetReadOnly);
	Gura_AssignMethod(wx_StyledTextCtrl, __CanPaste);
	Gura_AssignMethod(wx_StyledTextCtrl, __CanUndo);
	Gura_AssignMethod(wx_StyledTextCtrl, __EmptyUndoBuffer);
	Gura_AssignMethod(wx_StyledTextCtrl, __Undo);
	Gura_AssignMethod(wx_StyledTextCtrl, __Cut);
	Gura_AssignMethod(wx_StyledTextCtrl, __Copy);
	Gura_AssignMethod(wx_StyledTextCtrl, __Paste);
	Gura_AssignMethod(wx_StyledTextCtrl, __Clear);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetText);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetText);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTextLength);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetOvertype);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetOvertype);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetTargetStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTargetStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetTargetEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTargetEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetTargetRange);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTargetText);
	Gura_AssignMethod(wx_StyledTextCtrl, __ReplaceTarget);
	Gura_AssignMethod(wx_StyledTextCtrl, __ReplaceTargetRE);
	Gura_AssignMethod(wx_StyledTextCtrl, __SearchInTarget);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSearchFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSearchFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipShow);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipCancel);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipActive);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipPosAtStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipSetPosAtStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipSetHighlight);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipSetBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipSetForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipSetForegroundHighlight);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipUseStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __CallTipSetPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __VisibleFromDocLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __DocLineFromVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __WrapCount);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetFoldLevel);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetFoldLevel);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLastChild);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetFoldParent);
	Gura_AssignMethod(wx_StyledTextCtrl, __ShowLines);
	Gura_AssignMethod(wx_StyledTextCtrl, __HideLines);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetAllLinesVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetFoldExpanded);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetFoldExpanded);
	Gura_AssignMethod(wx_StyledTextCtrl, __ToggleFold);
	Gura_AssignMethod(wx_StyledTextCtrl, __FoldLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __FoldChildren);
	Gura_AssignMethod(wx_StyledTextCtrl, __ExpandChildren);
	Gura_AssignMethod(wx_StyledTextCtrl, __FoldAll);
	Gura_AssignMethod(wx_StyledTextCtrl, __EnsureVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAutomaticFold);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetAutomaticFold);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetFoldFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, __EnsureVisibleEnforcePolicy);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetTabIndents);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTabIndents);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetBackSpaceUnIndents);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetBackSpaceUnIndents);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMouseDwellTime);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMouseDwellTime);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordStartPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordEndPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWrapMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetWrapMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWrapVisualFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetWrapVisualFlags);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWrapVisualFlagsLocation);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetWrapVisualFlagsLocation);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWrapStartIndent);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetWrapStartIndent);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWrapIndentMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetWrapIndentMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetLayoutCache);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLayoutCache);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetScrollWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetScrollWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetScrollWidthTracking);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetScrollWidthTracking);
	Gura_AssignMethod(wx_StyledTextCtrl, __TextWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetEndAtLastLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetEndAtLastLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __TextHeight);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetUseVerticalScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetUseVerticalScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, __AppendText);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTwoPhaseDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetTwoPhaseDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPhasesDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetPhasesDraw);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetFirstVisibleLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMultiPaste);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMultiPaste);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTag);
	Gura_AssignMethod(wx_StyledTextCtrl, __TargetFromSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __LinesJoin);
	Gura_AssignMethod(wx_StyledTextCtrl, __LinesSplit);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetFoldMarginColour);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetFoldMarginHiColour);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineDown);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineDownExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineUp);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineUpExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __CharLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, __CharLeftExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __CharRight);
	Gura_AssignMethod(wx_StyledTextCtrl, __CharRightExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordLeftExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordRight);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordRightExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __Home);
	Gura_AssignMethod(wx_StyledTextCtrl, __HomeExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineEndExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __DocumentStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __DocumentStartExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __DocumentEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __DocumentEndExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __PageUp);
	Gura_AssignMethod(wx_StyledTextCtrl, __PageUpExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __PageDown);
	Gura_AssignMethod(wx_StyledTextCtrl, __PageDownExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __EditToggleOvertype);
	Gura_AssignMethod(wx_StyledTextCtrl, __Cancel);
	Gura_AssignMethod(wx_StyledTextCtrl, __DeleteBack);
	Gura_AssignMethod(wx_StyledTextCtrl, __Tab);
	Gura_AssignMethod(wx_StyledTextCtrl, __BackTab);
	Gura_AssignMethod(wx_StyledTextCtrl, __NewLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __FormFeed);
	Gura_AssignMethod(wx_StyledTextCtrl, __VCHome);
	Gura_AssignMethod(wx_StyledTextCtrl, __VCHomeExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __ZoomIn);
	Gura_AssignMethod(wx_StyledTextCtrl, __ZoomOut);
	Gura_AssignMethod(wx_StyledTextCtrl, __DelWordLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, __DelWordRight);
	Gura_AssignMethod(wx_StyledTextCtrl, __DelWordRightEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineCut);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineDelete);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineTranspose);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineDuplicate);
	Gura_AssignMethod(wx_StyledTextCtrl, __LowerCase);
	Gura_AssignMethod(wx_StyledTextCtrl, __UpperCase);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineScrollDown);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineScrollUp);
	Gura_AssignMethod(wx_StyledTextCtrl, __DeleteBackNotLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __HomeDisplay);
	Gura_AssignMethod(wx_StyledTextCtrl, __HomeDisplayExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineEndDisplay);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineEndDisplayExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __HomeWrap);
	Gura_AssignMethod(wx_StyledTextCtrl, __HomeWrapExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineEndWrap);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineEndWrapExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __VCHomeWrap);
	Gura_AssignMethod(wx_StyledTextCtrl, __VCHomeWrapExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineCopy);
	Gura_AssignMethod(wx_StyledTextCtrl, __MoveCaretInsideView);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineLength);
	Gura_AssignMethod(wx_StyledTextCtrl, __BraceHighlight);
	Gura_AssignMethod(wx_StyledTextCtrl, __BraceHighlightIndicator);
	Gura_AssignMethod(wx_StyledTextCtrl, __BraceBadLight);
	Gura_AssignMethod(wx_StyledTextCtrl, __BraceBadLightIndicator);
	Gura_AssignMethod(wx_StyledTextCtrl, __BraceMatch);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetViewEOL);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetViewEOL);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetDocPointer);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetDocPointer);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetModEventMask);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetEdgeColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetEdgeColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetEdgeMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetEdgeMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetEdgeColour);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetEdgeColour);
	Gura_AssignMethod(wx_StyledTextCtrl, __SearchAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, __SearchNext);
	Gura_AssignMethod(wx_StyledTextCtrl, __SearchPrev);
	Gura_AssignMethod(wx_StyledTextCtrl, __LinesOnScreen);
	Gura_AssignMethod(wx_StyledTextCtrl, __UsePopUp);
	Gura_AssignMethod(wx_StyledTextCtrl, __SelectionIsRectangle);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetZoom);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetZoom);
	Gura_AssignMethod(wx_StyledTextCtrl, __CreateDocument);
	Gura_AssignMethod(wx_StyledTextCtrl, __AddRefDocument);
	Gura_AssignMethod(wx_StyledTextCtrl, __ReleaseDocument);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetModEventMask);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSTCFocus);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSTCFocus);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetStatus);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetStatus);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMouseDownCaptures);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMouseDownCaptures);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSTCCursor);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSTCCursor);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetControlCharSymbol);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetControlCharSymbol);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordPartLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordPartLeftExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordPartRight);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordPartRightExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetVisiblePolicy);
	Gura_AssignMethod(wx_StyledTextCtrl, __DelLineLeft);
	Gura_AssignMethod(wx_StyledTextCtrl, __DelLineRight);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetXOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetXOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, __ChooseCaretX);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetXCaretPolicy);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetYCaretPolicy);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetPrintWrapMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPrintWrapMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetHotspotActiveForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetHotspotActiveForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetHotspotActiveBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetHotspotActiveBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetHotspotActiveUnderline);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetHotspotActiveUnderline);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetHotspotSingleLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetHotspotSingleLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __ParaDown);
	Gura_AssignMethod(wx_StyledTextCtrl, __ParaDownExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __ParaUp);
	Gura_AssignMethod(wx_StyledTextCtrl, __ParaUpExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __PositionBefore);
	Gura_AssignMethod(wx_StyledTextCtrl, __PositionAfter);
	Gura_AssignMethod(wx_StyledTextCtrl, __PositionRelative);
	Gura_AssignMethod(wx_StyledTextCtrl, __CopyRange);
	Gura_AssignMethod(wx_StyledTextCtrl, __CopyText);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionMode);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineSelStartPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineSelEndPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineDownRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineUpRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __CharLeftRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __CharRightRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __HomeRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __VCHomeRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __LineEndRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __PageUpRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __PageDownRectExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __StutteredPageUp);
	Gura_AssignMethod(wx_StyledTextCtrl, __StutteredPageUpExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __StutteredPageDown);
	Gura_AssignMethod(wx_StyledTextCtrl, __StutteredPageDownExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordLeftEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordLeftEndExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordRightEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __WordRightEndExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetWhitespaceChars);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetWhitespaceChars);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetPunctuationChars);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPunctuationChars);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCharsDefault);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetCurrent);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetCaseInsensitiveBehaviour);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetCaseInsensitiveBehaviour);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetMulti);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetMulti);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompSetOrder);
	Gura_AssignMethod(wx_StyledTextCtrl, __AutoCompGetOrder);
	Gura_AssignMethod(wx_StyledTextCtrl, __Allocate);
	Gura_AssignMethod(wx_StyledTextCtrl, __FindColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretSticky);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretSticky);
	Gura_AssignMethod(wx_StyledTextCtrl, __ToggleCaretSticky);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetPasteConvertEndings);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPasteConvertEndings);
	Gura_AssignMethod(wx_StyledTextCtrl, __SelectionDuplicate);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretLineBackAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretLineBackAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetIndicatorCurrent);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetIndicatorCurrent);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetIndicatorValue);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetIndicatorValue);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorFillRange);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorClearRange);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorAllOnFor);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorValueAt);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetPositionCacheSize);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPositionCacheSize);
	Gura_AssignMethod(wx_StyledTextCtrl, __CopyAllowLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCharacterPointer);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetRangePointer);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetGapPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorSetAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorGetAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorSetOutlineAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __IndicatorGetOutlineAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetExtraAscent);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetExtraAscent);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetExtraDescent);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetExtraDescent);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarkerSymbolDefined);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginSetText);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginGetText);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginSetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginGetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginSetStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginGetStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginTextClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginSetStyleOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarginGetStyleOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMarginOptions);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMarginOptions);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationSetText);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationGetText);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationSetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationGetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationSetStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationGetStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationGetLines);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationClearAll);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationSetVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationGetVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationSetStyleOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationGetStyleOffset);
	Gura_AssignMethod(wx_StyledTextCtrl, __ReleaseAllExtendedStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __AllocateExtendedStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __AddUndoAction);
	Gura_AssignMethod(wx_StyledTextCtrl, __CharPositionFromPoint);
	Gura_AssignMethod(wx_StyledTextCtrl, __CharPositionFromPointClose);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMouseSelectionRectangularSwitch);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMouseSelectionRectangularSwitch);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMultipleSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMultipleSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAdditionalSelectionTyping);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetAdditionalSelectionTyping);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAdditionalCaretsBlink);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetAdditionalCaretsBlink);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAdditionalCaretsVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetAdditionalCaretsVisible);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelections);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionEmpty);
	Gura_AssignMethod(wx_StyledTextCtrl, __ClearSelections);
	Gura_AssignMethod(wx_StyledTextCtrl, __AddSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __DropSelectionN);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMainSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetMainSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionNCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionNCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionNAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionNAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionNCaretVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionNCaretVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionNAnchorVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionNAnchorVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionNStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionNStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelectionNEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectionNEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetRectangularSelectionCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetRectangularSelectionCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetRectangularSelectionAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetRectangularSelectionAnchor);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetRectangularSelectionCaretVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetRectangularSelectionCaretVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetRectangularSelectionAnchorVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetRectangularSelectionAnchorVirtualSpace);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetVirtualSpaceOptions);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetVirtualSpaceOptions);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetRectangularSelectionModifier);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetRectangularSelectionModifier);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAdditionalSelForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAdditionalSelBackground);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAdditionalSelAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetAdditionalSelAlpha);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetAdditionalCaretForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetAdditionalCaretForeground);
	Gura_AssignMethod(wx_StyledTextCtrl, __RotateSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __SwapMainAnchorCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, __ChangeLexerState);
	Gura_AssignMethod(wx_StyledTextCtrl, __ContractedFoldNext);
	Gura_AssignMethod(wx_StyledTextCtrl, __VerticalCentreCaret);
	Gura_AssignMethod(wx_StyledTextCtrl, __MoveSelectedLinesUp);
	Gura_AssignMethod(wx_StyledTextCtrl, __MoveSelectedLinesDown);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetIdentifier);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetIdentifier);
	Gura_AssignMethod(wx_StyledTextCtrl, __RGBAImageSetWidth);
	Gura_AssignMethod(wx_StyledTextCtrl, __RGBAImageSetHeight);
	Gura_AssignMethod(wx_StyledTextCtrl, __RGBAImageSetScale);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkerDefineRGBAImage);
	Gura_AssignMethod(wx_StyledTextCtrl, __RegisterRGBAImage);
	Gura_AssignMethod(wx_StyledTextCtrl, __ScrollToStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __ScrollToEnd);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetTechnology);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTechnology);
	Gura_AssignMethod(wx_StyledTextCtrl, __CreateLoader);
	Gura_AssignMethod(wx_StyledTextCtrl, __VCHomeDisplay);
	Gura_AssignMethod(wx_StyledTextCtrl, __VCHomeDisplayExtend);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCaretLineVisibleAlways);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetCaretLineVisibleAlways);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetLineEndTypesAllowed);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineEndTypesAllowed);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineEndTypesActive);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetRepresentation);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetRepresentation);
	Gura_AssignMethod(wx_StyledTextCtrl, __ClearRepresentation);
	Gura_AssignMethod(wx_StyledTextCtrl, __StartRecord);
	Gura_AssignMethod(wx_StyledTextCtrl, __StopRecord);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetLexer);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLexer);
	Gura_AssignMethod(wx_StyledTextCtrl, __Colourise);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetProperty);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetKeyWords);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetLexerLanguage);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetProperty);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPropertyExpanded);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPropertyInt);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetStyleBitsNeeded);
	Gura_AssignMethod(wx_StyledTextCtrl, __PrivateLexerCall);
	Gura_AssignMethod(wx_StyledTextCtrl, __PropertyNames);
	Gura_AssignMethod(wx_StyledTextCtrl, __PropertyType);
	Gura_AssignMethod(wx_StyledTextCtrl, __DescribeProperty);
	Gura_AssignMethod(wx_StyledTextCtrl, __DescribeKeyWordSets);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineEndTypesSupported);
	Gura_AssignMethod(wx_StyledTextCtrl, __AllocateSubStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSubStylesStart);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSubStylesLength);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetStyleFromSubStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetPrimaryStyleFromStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __FreeSubStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetIdentifiers);
	Gura_AssignMethod(wx_StyledTextCtrl, __DistanceToSecondaryStyles);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSubStyleBases);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCurrentLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetSpec);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleGetFont);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetFont);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetFontAttr);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetCharacterSet);
	Gura_AssignMethod(wx_StyledTextCtrl, __StyleSetFontEncoding);
	Gura_AssignMethod(wx_StyledTextCtrl, __CmdKeyExecute);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetMargins);
	Gura_AssignMethod(wx_StyledTextCtrl, __PointFromPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __ScrollToLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __ScrollToColumn);
	Gura_AssignMethod(wx_StyledTextCtrl, __SendMsg);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetVScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetHScrollBar);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLastKeydownProcessed);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetLastKeydownProcessed);
	Gura_AssignMethod(wx_StyledTextCtrl, __SaveFile);
	Gura_AssignMethod(wx_StyledTextCtrl, __LoadFile);
	Gura_AssignMethod(wx_StyledTextCtrl, __DoDragEnter);
	Gura_AssignMethod(wx_StyledTextCtrl, __DoDragOver);
	Gura_AssignMethod(wx_StyledTextCtrl, __DoDragLeave);
	Gura_AssignMethod(wx_StyledTextCtrl, __DoDropText);
	Gura_AssignMethod(wx_StyledTextCtrl, __AnnotationClearLine);
	Gura_AssignMethod(wx_StyledTextCtrl, __AddTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __InsertTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetCurLineRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelectedTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTextRangeRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __AppendTextRaw);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLibraryVersionInfo);
	Gura_AssignMethod(wx_StyledTextCtrl, __WriteText);
	Gura_AssignMethod(wx_StyledTextCtrl, __Remove);
	Gura_AssignMethod(wx_StyledTextCtrl, __Replace);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetInsertionPoint);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetInsertionPoint);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLastPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __SelectNone);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetSelection);
	Gura_AssignMethod(wx_StyledTextCtrl, __IsEditable);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetEditable);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineLength);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetLineText);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetNumberOfLines);
	Gura_AssignMethod(wx_StyledTextCtrl, __IsModified);
	Gura_AssignMethod(wx_StyledTextCtrl, __MarkDirty);
	Gura_AssignMethod(wx_StyledTextCtrl, __DiscardEdits);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __GetStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __SetDefaultStyle);
	Gura_AssignMethod(wx_StyledTextCtrl, __XYToPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __PositionToXY);
	Gura_AssignMethod(wx_StyledTextCtrl, __ShowPosition);
	Gura_AssignMethod(wx_StyledTextCtrl, __HitTest);
	Gura_AssignMethod(wx_StyledTextCtrl, __HitTest_1);
}

Gura_ImplementDescendantCreator(wx_StyledTextCtrl)
{
	return new Object_wx_StyledTextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
