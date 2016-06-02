//----------------------------------------------------------------------------
// wxTextCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextCtrl
//----------------------------------------------------------------------------
Object_wx_TextCtrl::~Object_wx_TextCtrl()
{
}

Object *Object_wx_TextCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_TextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TextCtrl:");
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
Gura_DeclareMethod(wx_TextCtrl, wxTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, wxTextCtrl)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, wxTextCtrl_1)
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

Gura_ImplementMethod(wx_TextCtrl, wxTextCtrl_1)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, Create)
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

Gura_ImplementMethod(wx_TextCtrl, Create)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_TextCtrl, DiscardEdits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, DiscardEdits)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DiscardEdits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, EmulateKeyPress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, EmulateKeyPress)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->EmulateKeyPress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, GetDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, GetDefaultStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, GetLineLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, GetLineLength)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineNo = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, GetLineText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, GetLineText)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lineNo = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, GetNumberOfLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, GetNumberOfLines)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberOfLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, GetStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int position = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, HitTest)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, HitTest_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, HitTest_1)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int row = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, IsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, IsModified)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, IsMultiLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, IsMultiLine)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMultiLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, IsSingleLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, IsSingleLine)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSingleLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, LoadFile)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int fileType = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, MarkDirty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, MarkDirty)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarkDirty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, OnDropFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, OnDropFiles)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnDropFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, PositionToXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, PositionToXY)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->PositionToXY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, PositionToCoords)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, PositionToCoords)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->PositionToCoords();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SaveFile)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int fileType = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetDefaultStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetDefaultStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetModified)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int modified = arg.GetNumber(0)
	//pThis->GetEntity()->SetModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, SetStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, ShowPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, ShowPosition)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextCtrl, XYToPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, XYToPosition)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->XYToPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextCtrl)
{
	Gura_AssignMethod(wx_TextCtrl, wxTextCtrl);
	Gura_AssignMethod(wx_TextCtrl, wxTextCtrl_1);
	Gura_AssignMethod(wx_TextCtrl, Create);
	Gura_AssignMethod(wx_TextCtrl, DiscardEdits);
	Gura_AssignMethod(wx_TextCtrl, EmulateKeyPress);
	Gura_AssignMethod(wx_TextCtrl, GetDefaultStyle);
	Gura_AssignMethod(wx_TextCtrl, GetLineLength);
	Gura_AssignMethod(wx_TextCtrl, GetLineText);
	Gura_AssignMethod(wx_TextCtrl, GetNumberOfLines);
	Gura_AssignMethod(wx_TextCtrl, GetStyle);
	Gura_AssignMethod(wx_TextCtrl, HitTest);
	Gura_AssignMethod(wx_TextCtrl, HitTest_1);
	Gura_AssignMethod(wx_TextCtrl, IsModified);
	Gura_AssignMethod(wx_TextCtrl, IsMultiLine);
	Gura_AssignMethod(wx_TextCtrl, IsSingleLine);
	Gura_AssignMethod(wx_TextCtrl, LoadFile);
	Gura_AssignMethod(wx_TextCtrl, MarkDirty);
	Gura_AssignMethod(wx_TextCtrl, OnDropFiles);
	Gura_AssignMethod(wx_TextCtrl, PositionToXY);
	Gura_AssignMethod(wx_TextCtrl, PositionToCoords);
	Gura_AssignMethod(wx_TextCtrl, SaveFile);
	Gura_AssignMethod(wx_TextCtrl, SetDefaultStyle);
	Gura_AssignMethod(wx_TextCtrl, SetModified);
	Gura_AssignMethod(wx_TextCtrl, SetStyle);
	Gura_AssignMethod(wx_TextCtrl, ShowPosition);
	Gura_AssignMethod(wx_TextCtrl, XYToPosition);
}

Gura_ImplementDescendantCreator(wx_TextCtrl)
{
	return new Object_wx_TextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
