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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRichTextContextMenuPropertiesInfo, "wxRichTextContextMenuPropertiesInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextContextMenuPropertiesInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextContextMenuPropertiesInfo)
{
	//wxRichTextContextMenuPropertiesInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __Init)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __AddItem, "AddItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __AddItem)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->AddItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __AddMenuItems, "AddMenuItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startCmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __AddMenuItems)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//int startCmd = arg.GetNumber(1)
	//pThis->GetEntity()->AddMenuItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __AddItems, "AddItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __AddItems)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//int container = arg.GetNumber(1)
	//int obj = arg.GetNumber(2)
	//pThis->GetEntity()->AddItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __Clear)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __GetLabel)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __GetObject, "GetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __GetObject)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __GetObjects, "GetObjects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __GetObjects)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObjects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __GetObjects_1, "GetObjects_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __GetObjects_1)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObjects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __GetLabels, "GetLabels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __GetLabels)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __GetLabels_1, "GetLabels_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __GetLabels_1)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextContextMenuPropertiesInfo, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextContextMenuPropertiesInfo, __GetCount)
{
	Object_wx_RichTextContextMenuPropertiesInfo *pThis = Object_wx_RichTextContextMenuPropertiesInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextContextMenuPropertiesInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextContextMenuPropertiesInfo);
	// Method assignment
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __Init);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __AddItem);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __AddMenuItems);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __AddItems);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __Clear);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __GetLabel);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __GetObject);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __GetObjects);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __GetObjects_1);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __GetLabels);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __GetLabels_1);
	Gura_AssignMethod(wx_RichTextContextMenuPropertiesInfo, __GetCount);
}

Gura_ImplementDescendantCreator(wx_RichTextContextMenuPropertiesInfo)
{
	return new Object_wx_RichTextContextMenuPropertiesInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
