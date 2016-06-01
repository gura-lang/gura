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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PGCell, wxPGCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, wxPGCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPGCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, wxPGCell_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, wxPGCell_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->wxPGCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, wxPGCell_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fgCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bgCol", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, wxPGCell_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int fgCol = arg.GetNumber(2)
	//int bgCol = arg.GetNumber(3)
	//pThis->GetEntity()->wxPGCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, ~wxPGCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, ~wxPGCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPGCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, HasText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, HasText)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, MergeFrom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "srcCell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, MergeFrom)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int srcCell = arg.GetNumber(0)
	//pThis->GetEntity()->MergeFrom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, SetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, SetFgCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, SetFgCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetFgCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, SetBgCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGCell, SetBgCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetBgCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, GetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, GetFgCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, GetFgCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFgCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGCell, GetBgCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGCell, GetBgCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGCell *pThis = Object_wx_PGCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBgCol();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGCell)
{
	Gura_AssignMethod(wx_PGCell, wxPGCell);
	Gura_AssignMethod(wx_PGCell, wxPGCell_1);
	Gura_AssignMethod(wx_PGCell, wxPGCell_2);
	Gura_AssignMethod(wx_PGCell, ~wxPGCell);
	Gura_AssignMethod(wx_PGCell, GetData);
	Gura_AssignMethod(wx_PGCell, HasText);
	Gura_AssignMethod(wx_PGCell, MergeFrom);
	Gura_AssignMethod(wx_PGCell, SetText);
	Gura_AssignMethod(wx_PGCell, SetBitmap);
	Gura_AssignMethod(wx_PGCell, SetFgCol);
	Gura_AssignMethod(wx_PGCell, SetFont);
	Gura_AssignMethod(wx_PGCell, SetBgCol);
	Gura_AssignMethod(wx_PGCell, GetText);
	Gura_AssignMethod(wx_PGCell, GetBitmap);
	Gura_AssignMethod(wx_PGCell, GetFgCol);
	Gura_AssignMethod(wx_PGCell, GetFont);
	Gura_AssignMethod(wx_PGCell, GetBgCol);
}

Gura_ImplementDescendantCreator(wx_PGCell)
{
	return new Object_wx_PGCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
