//----------------------------------------------------------------------------
// wxHtmlContainerCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlContainerCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlContainerCell
//----------------------------------------------------------------------------
Object_wx_HtmlContainerCell::~Object_wx_HtmlContainerCell()
{
}

Object *Object_wx_HtmlContainerCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlContainerCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlContainerCell:");
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
Gura_DeclareMethod(wx_HtmlContainerCell, wxHtmlContainerCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, wxHtmlContainerCell)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxHtmlContainerCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetAlignHor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetAlignHor)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignHor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetAlignVer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetAlignVer)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignVer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetBackgroundColour)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetIndent)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ind = arg.GetNumber(0)
	//pThis->GetEntity()->GetIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, GetIndentUnits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, GetIndentUnits)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ind = arg.GetNumber(0)
	//pThis->GetEntity()->GetIndentUnits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, InsertCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, InsertCell)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//pThis->GetEntity()->InsertCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetAlign)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tag = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetAlignHor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "al", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetAlignHor)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int al = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignHor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetAlignVer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "al", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetAlignVer)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int al = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignVer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetBackgroundColour)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int clr = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clr2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetBorder)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int clr1 = arg.GetNumber(0)
	//int clr2 = arg.GetNumber(1)
	//int border = arg.GetNumber(2)
	//pThis->GetEntity()->SetBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "what", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetIndent)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//int what = arg.GetNumber(1)
	//int units = arg.GetNumber(2)
	//pThis->GetEntity()->SetIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetMinHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetMinHeight)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int h = arg.GetNumber(0)
	//int align = arg.GetNumber(1)
	//pThis->GetEntity()->SetMinHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetWidthFloat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetWidthFloat)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidthFloat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlContainerCell, SetWidthFloat_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pixel_scale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlContainerCell, SetWidthFloat_1)
{
	Object_wx_HtmlContainerCell *pThis = Object_wx_HtmlContainerCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tag = arg.GetNumber(0)
	//int pixel_scale = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidthFloat();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlContainerCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlContainerCell)
{
	Gura_AssignMethod(wx_HtmlContainerCell, wxHtmlContainerCell);
	Gura_AssignMethod(wx_HtmlContainerCell, GetAlignHor);
	Gura_AssignMethod(wx_HtmlContainerCell, GetAlignVer);
	Gura_AssignMethod(wx_HtmlContainerCell, GetBackgroundColour);
	Gura_AssignMethod(wx_HtmlContainerCell, GetIndent);
	Gura_AssignMethod(wx_HtmlContainerCell, GetIndentUnits);
	Gura_AssignMethod(wx_HtmlContainerCell, InsertCell);
	Gura_AssignMethod(wx_HtmlContainerCell, SetAlign);
	Gura_AssignMethod(wx_HtmlContainerCell, SetAlignHor);
	Gura_AssignMethod(wx_HtmlContainerCell, SetAlignVer);
	Gura_AssignMethod(wx_HtmlContainerCell, SetBackgroundColour);
	Gura_AssignMethod(wx_HtmlContainerCell, SetBorder);
	Gura_AssignMethod(wx_HtmlContainerCell, SetIndent);
	Gura_AssignMethod(wx_HtmlContainerCell, SetMinHeight);
	Gura_AssignMethod(wx_HtmlContainerCell, SetWidthFloat);
	Gura_AssignMethod(wx_HtmlContainerCell, SetWidthFloat_1);
}

Gura_ImplementDescendantCreator(wx_HtmlContainerCell)
{
	return new Object_wx_HtmlContainerCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
