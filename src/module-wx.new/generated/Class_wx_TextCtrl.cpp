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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TextCtrl, "TextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextCtrl)
{
	//wxTextCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TextCtrl_1, "TextCtrl_1")
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
	SetClassToConstruct(Gura_UserClass(wx_TextCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxTextCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_TextCtrl, __Create)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __DiscardEdits, "DiscardEdits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, __DiscardEdits)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DiscardEdits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __EmulateKeyPress, "EmulateKeyPress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __EmulateKeyPress)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxKeyEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->EmulateKeyPress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __GetDefaultStyle, "GetDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, __GetDefaultStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __GetLineLength, "GetLineLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __GetLineLength)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long lineNo = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __GetLineText, "GetLineText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __GetLineText)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long lineNo = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __GetNumberOfLines, "GetNumberOfLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, __GetNumberOfLines)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNumberOfLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __GetStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long position = arg.GetNumber(0)
	//wxTextAttr& style = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __HitTest)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//long* pos = arg.GetNumber(1)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __HitTest_1, "HitTest_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __HitTest_1)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//wxTextCoord* col = arg.GetNumber(1)
	//wxTextCoord* row = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __IsModified, "IsModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, __IsModified)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __IsMultiLine, "IsMultiLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, __IsMultiLine)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMultiLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __IsSingleLine, "IsSingleLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, __IsSingleLine)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSingleLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __LoadFile)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//int fileType = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __MarkDirty, "MarkDirty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextCtrl, __MarkDirty)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MarkDirty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __OnDropFiles, "OnDropFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __OnDropFiles)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDropFilesEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnDropFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __PositionToXY, "PositionToXY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __PositionToXY)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//long* x = arg.GetNumber(1)
	//long* y = arg.GetNumber(2)
	//pThis->GetEntity()->PositionToXY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __PositionToCoords, "PositionToCoords")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __PositionToCoords)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//pThis->GetEntity()->PositionToCoords();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __SaveFile, "SaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __SaveFile)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//int fileType = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __SetDefaultStyle, "SetDefaultStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __SetDefaultStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttr& style = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __SetModified, "SetModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __SetModified)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool modified = arg.GetNumber(0)
	//pThis->GetEntity()->SetModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __SetStyle)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//long end = arg.GetNumber(1)
	//const wxTextAttr& style = arg.GetNumber(2)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __ShowPosition, "ShowPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __ShowPosition)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//pThis->GetEntity()->ShowPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextCtrl, __XYToPosition, "XYToPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextCtrl, __XYToPosition)
{
	Object_wx_TextCtrl *pThis = Object_wx_TextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long x = arg.GetNumber(0)
	//long y = arg.GetNumber(1)
	//pThis->GetEntity()->XYToPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__TextCtrl);
	Gura_AssignFunction(__TextCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_TextCtrl, __Create);
	Gura_AssignMethod(wx_TextCtrl, __DiscardEdits);
	Gura_AssignMethod(wx_TextCtrl, __EmulateKeyPress);
	Gura_AssignMethod(wx_TextCtrl, __GetDefaultStyle);
	Gura_AssignMethod(wx_TextCtrl, __GetLineLength);
	Gura_AssignMethod(wx_TextCtrl, __GetLineText);
	Gura_AssignMethod(wx_TextCtrl, __GetNumberOfLines);
	Gura_AssignMethod(wx_TextCtrl, __GetStyle);
	Gura_AssignMethod(wx_TextCtrl, __HitTest);
	Gura_AssignMethod(wx_TextCtrl, __HitTest_1);
	Gura_AssignMethod(wx_TextCtrl, __IsModified);
	Gura_AssignMethod(wx_TextCtrl, __IsMultiLine);
	Gura_AssignMethod(wx_TextCtrl, __IsSingleLine);
	Gura_AssignMethod(wx_TextCtrl, __LoadFile);
	Gura_AssignMethod(wx_TextCtrl, __MarkDirty);
	Gura_AssignMethod(wx_TextCtrl, __OnDropFiles);
	Gura_AssignMethod(wx_TextCtrl, __PositionToXY);
	Gura_AssignMethod(wx_TextCtrl, __PositionToCoords);
	Gura_AssignMethod(wx_TextCtrl, __SaveFile);
	Gura_AssignMethod(wx_TextCtrl, __SetDefaultStyle);
	Gura_AssignMethod(wx_TextCtrl, __SetModified);
	Gura_AssignMethod(wx_TextCtrl, __SetStyle);
	Gura_AssignMethod(wx_TextCtrl, __ShowPosition);
	Gura_AssignMethod(wx_TextCtrl, __XYToPosition);
}

Gura_ImplementDescendantCreator(wx_TextCtrl)
{
	return new Object_wx_TextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
