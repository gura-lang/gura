//----------------------------------------------------------------------------
// wxSizerItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizerItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizerItem
//----------------------------------------------------------------------------
Object_wx_SizerItem::~Object_wx_SizerItem()
{
}

Object *Object_wx_SizerItem::Clone() const
{
	return nullptr;
}

String Object_wx_SizerItem::ToString(bool exprFlag)
{
	String rtn("<wx.SizerItem:");
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
Gura_DeclareMethod(wx_SizerItem, wxSizerItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, wxSizerItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->wxSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, wxSizerItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, wxSizerItem_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, wxSizerItem_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, wxSizerItem_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->wxSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, wxSizerItem_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, wxSizerItem_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, wxSizerItem_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, wxSizerItem_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//int userData = arg.GetNumber(4)
	//pThis->GetEntity()->wxSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, ~wxSizerItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, ~wxSizerItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, AssignWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, AssignWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->AssignWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, AssignSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, AssignSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->AssignSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, AssignSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, AssignSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->AssignSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, AssignSpacer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, AssignSpacer_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->AssignSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, DeleteWindows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, DeleteWindows)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteWindows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, DetachSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, DetachSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DetachSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetMinSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetMinSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetRatio)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetRatio)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRatio();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetUserData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetUserData)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUserData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, GetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, IsShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, IsSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, IsSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, IsSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, IsSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, IsWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, IsWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetBorder)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int border = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetDimension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetDimension)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetDimension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetInitSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetInitSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetInitSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetProportion)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int proportion = arg.GetNumber(0)
	//pThis->GetEntity()->SetProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetRatio)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetRatio)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetRatio();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetRatio_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetRatio_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetRatio();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetRatio_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ratio", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetRatio_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ratio = arg.GetNumber(0)
	//pThis->GetEntity()->SetRatio();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->SetSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetUserData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetUserData)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int userData = arg.GetNumber(0)
	//pThis->GetEntity()->SetUserData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, SetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, SetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SizerItem, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizerItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerItem)
{
	Gura_AssignMethod(wx_SizerItem, wxSizerItem);
	Gura_AssignMethod(wx_SizerItem, wxSizerItem_1);
	Gura_AssignMethod(wx_SizerItem, wxSizerItem_2);
	Gura_AssignMethod(wx_SizerItem, wxSizerItem_3);
	Gura_AssignMethod(wx_SizerItem, wxSizerItem_4);
	Gura_AssignMethod(wx_SizerItem, ~wxSizerItem);
	Gura_AssignMethod(wx_SizerItem, AssignWindow);
	Gura_AssignMethod(wx_SizerItem, AssignSizer);
	Gura_AssignMethod(wx_SizerItem, AssignSpacer);
	Gura_AssignMethod(wx_SizerItem, AssignSpacer_1);
	Gura_AssignMethod(wx_SizerItem, CalcMin);
	Gura_AssignMethod(wx_SizerItem, DeleteWindows);
	Gura_AssignMethod(wx_SizerItem, DetachSizer);
	Gura_AssignMethod(wx_SizerItem, GetBorder);
	Gura_AssignMethod(wx_SizerItem, GetFlag);
	Gura_AssignMethod(wx_SizerItem, GetId);
	Gura_AssignMethod(wx_SizerItem, GetMinSize);
	Gura_AssignMethod(wx_SizerItem, SetMinSize);
	Gura_AssignMethod(wx_SizerItem, SetMinSize_1);
	Gura_AssignMethod(wx_SizerItem, GetPosition);
	Gura_AssignMethod(wx_SizerItem, GetProportion);
	Gura_AssignMethod(wx_SizerItem, GetRatio);
	Gura_AssignMethod(wx_SizerItem, GetRect);
	Gura_AssignMethod(wx_SizerItem, GetSize);
	Gura_AssignMethod(wx_SizerItem, GetSizer);
	Gura_AssignMethod(wx_SizerItem, GetSpacer);
	Gura_AssignMethod(wx_SizerItem, GetUserData);
	Gura_AssignMethod(wx_SizerItem, GetWindow);
	Gura_AssignMethod(wx_SizerItem, IsShown);
	Gura_AssignMethod(wx_SizerItem, IsSizer);
	Gura_AssignMethod(wx_SizerItem, IsSpacer);
	Gura_AssignMethod(wx_SizerItem, IsWindow);
	Gura_AssignMethod(wx_SizerItem, SetBorder);
	Gura_AssignMethod(wx_SizerItem, SetDimension);
	Gura_AssignMethod(wx_SizerItem, SetFlag);
	Gura_AssignMethod(wx_SizerItem, SetId);
	Gura_AssignMethod(wx_SizerItem, SetInitSize);
	Gura_AssignMethod(wx_SizerItem, SetProportion);
	Gura_AssignMethod(wx_SizerItem, SetRatio);
	Gura_AssignMethod(wx_SizerItem, SetRatio_1);
	Gura_AssignMethod(wx_SizerItem, SetRatio_2);
	Gura_AssignMethod(wx_SizerItem, SetSizer);
	Gura_AssignMethod(wx_SizerItem, SetSpacer);
	Gura_AssignMethod(wx_SizerItem, SetUserData);
	Gura_AssignMethod(wx_SizerItem, SetWindow);
	Gura_AssignMethod(wx_SizerItem, Show);
}

Gura_ImplementDescendantCreator(wx_SizerItem)
{
	return new Object_wx_SizerItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
