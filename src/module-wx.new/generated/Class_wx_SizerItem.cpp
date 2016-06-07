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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SizerItem, "SizerItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SizerItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SizerItem)
{
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int proportion = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//wxSizerItem(width, height, proportion, flag, border, userData);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SizerItem_1, "SizerItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SizerItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SizerItem_1)
{
	//wxWindow* window = arg.GetNumber(0)
	//const wxSizerFlags& flags = arg.GetNumber(1)
	//wxSizerItem(window, flags);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SizerItem_2, "SizerItem_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SizerItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SizerItem_2)
{
	//wxWindow* window = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//wxObject* userData = arg.GetNumber(4)
	//wxSizerItem(window, proportion, flag, border, userData);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SizerItem_3, "SizerItem_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SizerItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SizerItem_3)
{
	//wxSizer* sizer = arg.GetNumber(0)
	//const wxSizerFlags& flags = arg.GetNumber(1)
	//wxSizerItem(sizer, flags);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SizerItem_4, "SizerItem_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SizerItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SizerItem_4)
{
	//wxSizer* sizer = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//int flag = arg.GetNumber(2)
	//int border = arg.GetNumber(3)
	//wxObject* userData = arg.GetNumber(4)
	//wxSizerItem(sizer, proportion, flag, border, userData);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SizerItem, __AssignWindow, "AssignWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __AssignWindow)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->AssignWindow(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __AssignSizer, "AssignSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __AssignSizer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->AssignSizer(sizer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __AssignSpacer, "AssignSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __AssignSpacer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->AssignSpacer(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __AssignSpacer_1, "AssignSpacer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __AssignSpacer_1)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//int h = arg.GetNumber(1)
	//pThis->GetEntity()->AssignSpacer(w, h);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __CalcMin, "CalcMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __CalcMin)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __DeleteWindows, "DeleteWindows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __DeleteWindows)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteWindows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __DetachSizer, "DetachSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __DetachSizer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DetachSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetBorder, "GetBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetBorder)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetFlag, "GetFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetFlag)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetId)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetMinSize, "GetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetMinSize)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetMinSize, "SetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetMinSize)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetMinSize_1, "SetMinSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetMinSize_1)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMinSize(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetPosition)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetProportion, "GetProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetProportion)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetRatio, "GetRatio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetRatio)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRatio();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetRect, "GetRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetRect)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetSize)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetSizer, "GetSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetSizer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetSpacer, "GetSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetSpacer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetUserData, "GetUserData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetUserData)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUserData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __GetWindow)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __IsShown, "IsShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __IsShown)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __IsSizer, "IsSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __IsSizer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __IsSpacer, "IsSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __IsSpacer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __IsWindow, "IsWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SizerItem, __IsWindow)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetBorder, "SetBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetBorder)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int border = arg.GetNumber(0)
	//pThis->GetEntity()->SetBorder(border);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetDimension, "SetDimension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetDimension)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pos = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//pThis->GetEntity()->SetDimension(pos, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetFlag, "SetFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetFlag)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlag(flag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetId, "SetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetId)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetInitSize, "SetInitSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetInitSize)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetInitSize(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetProportion, "SetProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetProportion)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int proportion = arg.GetNumber(0)
	//pThis->GetEntity()->SetProportion(proportion);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetRatio, "SetRatio")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetRatio)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->SetRatio(width, height);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetRatio_1, "SetRatio_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetRatio_1)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize size = arg.GetNumber(0)
	//pThis->GetEntity()->SetRatio(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetRatio_2, "SetRatio_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ratio", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetRatio_2)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//float ratio = arg.GetNumber(0)
	//pThis->GetEntity()->SetRatio(ratio);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetSizer, "SetSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetSizer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->SetSizer(sizer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetSpacer, "SetSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetSpacer)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSpacer(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetUserData, "SetUserData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetUserData)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxObject* userData = arg.GetNumber(0)
	//pThis->GetEntity()->SetUserData(userData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __SetWindow, "SetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __SetWindow)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SizerItem, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SizerItem, __Show)
{
	Object_wx_SizerItem *pThis = Object_wx_SizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->Show(show);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSizerItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerItem)
{
	// Constructor assignment
	Gura_AssignFunction(__SizerItem);
	Gura_AssignFunction(__SizerItem_1);
	Gura_AssignFunction(__SizerItem_2);
	Gura_AssignFunction(__SizerItem_3);
	Gura_AssignFunction(__SizerItem_4);
	// Method assignment
	Gura_AssignMethod(wx_SizerItem, __AssignWindow);
	Gura_AssignMethod(wx_SizerItem, __AssignSizer);
	Gura_AssignMethod(wx_SizerItem, __AssignSpacer);
	Gura_AssignMethod(wx_SizerItem, __AssignSpacer_1);
	Gura_AssignMethod(wx_SizerItem, __CalcMin);
	Gura_AssignMethod(wx_SizerItem, __DeleteWindows);
	Gura_AssignMethod(wx_SizerItem, __DetachSizer);
	Gura_AssignMethod(wx_SizerItem, __GetBorder);
	Gura_AssignMethod(wx_SizerItem, __GetFlag);
	Gura_AssignMethod(wx_SizerItem, __GetId);
	Gura_AssignMethod(wx_SizerItem, __GetMinSize);
	Gura_AssignMethod(wx_SizerItem, __SetMinSize);
	Gura_AssignMethod(wx_SizerItem, __SetMinSize_1);
	Gura_AssignMethod(wx_SizerItem, __GetPosition);
	Gura_AssignMethod(wx_SizerItem, __GetProportion);
	Gura_AssignMethod(wx_SizerItem, __GetRatio);
	Gura_AssignMethod(wx_SizerItem, __GetRect);
	Gura_AssignMethod(wx_SizerItem, __GetSize);
	Gura_AssignMethod(wx_SizerItem, __GetSizer);
	Gura_AssignMethod(wx_SizerItem, __GetSpacer);
	Gura_AssignMethod(wx_SizerItem, __GetUserData);
	Gura_AssignMethod(wx_SizerItem, __GetWindow);
	Gura_AssignMethod(wx_SizerItem, __IsShown);
	Gura_AssignMethod(wx_SizerItem, __IsSizer);
	Gura_AssignMethod(wx_SizerItem, __IsSpacer);
	Gura_AssignMethod(wx_SizerItem, __IsWindow);
	Gura_AssignMethod(wx_SizerItem, __SetBorder);
	Gura_AssignMethod(wx_SizerItem, __SetDimension);
	Gura_AssignMethod(wx_SizerItem, __SetFlag);
	Gura_AssignMethod(wx_SizerItem, __SetId);
	Gura_AssignMethod(wx_SizerItem, __SetInitSize);
	Gura_AssignMethod(wx_SizerItem, __SetProportion);
	Gura_AssignMethod(wx_SizerItem, __SetRatio);
	Gura_AssignMethod(wx_SizerItem, __SetRatio_1);
	Gura_AssignMethod(wx_SizerItem, __SetRatio_2);
	Gura_AssignMethod(wx_SizerItem, __SetSizer);
	Gura_AssignMethod(wx_SizerItem, __SetSpacer);
	Gura_AssignMethod(wx_SizerItem, __SetUserData);
	Gura_AssignMethod(wx_SizerItem, __SetWindow);
	Gura_AssignMethod(wx_SizerItem, __Show);
}

Gura_ImplementDescendantCreator(wx_SizerItem)
{
	return new Object_wx_SizerItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
