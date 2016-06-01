//----------------------------------------------------------------------------
// wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
Object_wx_RichTextContextMenuPropertiesInfo::~Object_wx_RichTextContextMenuPropertiesInfo()
{
}

Object *Object_wx_RichTextContextMenuPropertiesInfo::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextContextMenuPropertiesInfo::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextContextMenuPropertiesInfo:");
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
Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, wxRichTextContextMenuPropertiesInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, wxRichTextContextMenuPropertiesInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextContextMenuPropertiesInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, AddItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, AddItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->AddItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, AddMenuItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startCmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, AddMenuItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int startCmd = arg.GetNumber(1)
	//pThis->GetEntity()->AddMenuItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, AddItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, AddItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//int container = arg.GetNumber(1)
	//int obj = arg.GetNumber(2)
	//pThis->GetEntity()->AddItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, GetObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, GetObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, GetObjects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, GetObjects)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetObjects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, GetObjects_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, GetObjects_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetObjects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, GetLabels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, GetLabels)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLabels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, GetLabels_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, GetLabels_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLabels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextContextMenuPropertiesInfo, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextContextMenuPropertiesInfo)
{
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, wxRichTextContextMenuPropertiesInfo);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, Init);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, AddItem);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, AddMenuItems);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, AddItems);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, Clear);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, GetLabel);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, GetObject);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, GetObjects);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, GetObjects_1);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, GetLabels);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, GetLabels_1);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, GetCount);
}

Gura_ImplementDescendantCreator(wx_RichTextContextMenuPropertiesInfo)
{
	return new Object_wx_RichTextContextMenuPropertiesInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
