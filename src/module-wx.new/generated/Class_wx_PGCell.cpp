//----------------------------------------------------------------------------
// wxPGCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGCell
//----------------------------------------------------------------------------
Object_wx_PGCell::~Object_wx_PGCell()
{
}

Object *Object_wx_PGCell::Clone() const
{
	return nullptr;
}

String Object_wx_PGCell::ToString(bool exprFlag)
{
	String rtn("<wx.PGCell:");
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
Gura_DeclareFunctionAlias(__PGCell, "PGCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PGCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PGCell)
{
	//wxPGCell();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PGCell_1, "PGCell_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PGCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PGCell_1)
{
	//const wxPGCell& other = arg.GetNumber(0)
	//wxPGCell();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PGCell_2, "PGCell_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fgCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bgCol", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PGCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PGCell_2)
{
	//const wxString& text = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//const wxColour& fgCol = arg.GetNumber(2)
	//const wxColour& bgCol = arg.GetNumber(3)
	//wxPGCell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PGCell, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, __GetData)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __HasText, "HasText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, __HasText)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __MergeFrom, "MergeFrom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "srcCell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, __MergeFrom)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPGCell& srcCell = arg.GetNumber(0)
	//pThis->GetEntity()->MergeFrom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, __SetText)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, __SetBitmap)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __SetFgCol, "SetFgCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, __SetFgCol)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetFgCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, __SetFont)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __SetBgCol, "SetBgCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, __SetBgCol)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetBgCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, __GetText)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, __GetBitmap)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __GetFgCol, "GetFgCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, __GetFgCol)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFgCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, __GetFont)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PGCell, __GetBgCol, "GetBgCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, __GetBgCol)
{
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBgCol();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGCell)
{
	// Constructor assignment
	Gura_AssignFunction(__PGCell);
	Gura_AssignFunction(__PGCell_1);
	Gura_AssignFunction(__PGCell_2);
	// Method assignment
	Gura_AssignMethod(wx_PGCell, __GetData);
	Gura_AssignMethod(wx_PGCell, __HasText);
	Gura_AssignMethod(wx_PGCell, __MergeFrom);
	Gura_AssignMethod(wx_PGCell, __SetText);
	Gura_AssignMethod(wx_PGCell, __SetBitmap);
	Gura_AssignMethod(wx_PGCell, __SetFgCol);
	Gura_AssignMethod(wx_PGCell, __SetFont);
	Gura_AssignMethod(wx_PGCell, __SetBgCol);
	Gura_AssignMethod(wx_PGCell, __GetText);
	Gura_AssignMethod(wx_PGCell, __GetBitmap);
	Gura_AssignMethod(wx_PGCell, __GetFgCol);
	Gura_AssignMethod(wx_PGCell, __GetFont);
	Gura_AssignMethod(wx_PGCell, __GetBgCol);
}

Gura_ImplementDescendantCreator(wx_PGCell)
{
	return new Object_wx_PGCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
