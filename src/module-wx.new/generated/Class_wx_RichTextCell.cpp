//----------------------------------------------------------------------------
// wxRichTextCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCell
//----------------------------------------------------------------------------
Object_wx_RichTextCell::~Object_wx_RichTextCell()
{
}

Object *Object_wx_RichTextCell::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCell::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCell:");
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
Gura_DeclareMethod(wx_RichTextCell, wxRichTextCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, wxRichTextCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, wxRichTextCell_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, wxRichTextCell_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, Draw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, Draw)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int selection = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "contextObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int pt = arg.GetNumber(2)
	//int textPosition = arg.GetNumber(3)
	//int obj = arg.GetNumber(4)
	//int contextObj = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, GetXMLNodeName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, CanEditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, CanEditProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, EditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, EditProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, GetPropertiesMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, GetPropertiesMenuLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, GetColSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, GetColSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, SetColSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, SetColSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int span = arg.GetNumber(0)
	//pThis->GetEntity()->SetColSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, GetRowSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, GetRowSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRowSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, SetRowSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, SetRowSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int span = arg.GetNumber(0)
	//pThis->GetEntity()->SetRowSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextCell, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextCell, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextCell, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextCell *pThis = Object_wx_RichTextCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCell)
{
	Gura_AssignMethod(wx_RichTextCell, wxRichTextCell);
	Gura_AssignMethod(wx_RichTextCell, wxRichTextCell_1);
	Gura_AssignMethod(wx_RichTextCell, Draw);
	Gura_AssignMethod(wx_RichTextCell, HitTest);
	Gura_AssignMethod(wx_RichTextCell, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextCell, CanEditProperties);
	Gura_AssignMethod(wx_RichTextCell, EditProperties);
	Gura_AssignMethod(wx_RichTextCell, GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextCell, GetColSpan);
	Gura_AssignMethod(wx_RichTextCell, SetColSpan);
	Gura_AssignMethod(wx_RichTextCell, GetRowSpan);
	Gura_AssignMethod(wx_RichTextCell, SetRowSpan);
	Gura_AssignMethod(wx_RichTextCell, Clone);
	Gura_AssignMethod(wx_RichTextCell, Copy);
}

Gura_ImplementDescendantCreator(wx_RichTextCell)
{
	return new Object_wx_RichTextCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
