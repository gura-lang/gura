//----------------------------------------------------------------------------
// wxRichTextFieldType
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFieldType
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFieldType
//----------------------------------------------------------------------------
Object_wx_RichTextFieldType::~Object_wx_RichTextFieldType()
{
}

Object *Object_wx_RichTextFieldType::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFieldType::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFieldType:");
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
Gura_DeclareMethodAlias(wx_RichTextFieldType, __wxRichTextFieldType, "wxRichTextFieldType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __wxRichTextFieldType)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextFieldType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __wxRichTextFieldType_1, "wxRichTextFieldType_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __wxRichTextFieldType_1)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextFieldType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __Copy)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __Draw, "Draw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __Draw)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int context = arg.GetNumber(2)
	//int range = arg.GetNumber(3)
	//int selection = arg.GetNumber(4)
	//int rect = arg.GetNumber(5)
	//int descent = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __Layout)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int context = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//int parentRect = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __GetRangeSize, "GetRangeSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partialExtents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __GetRangeSize)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int range = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int descent = arg.GetNumber(3)
	//int dc = arg.GetNumber(4)
	//int context = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//int position = arg.GetNumber(7)
	//int parentSize = arg.GetNumber(8)
	//int partialExtents = arg.GetNumber(9)
	//pThis->GetEntity()->GetRangeSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __CanEditProperties)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __EditProperties)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int buffer = arg.GetNumber(2)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __UpdateField, "UpdateField")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __UpdateField)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateField();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __IsTopLevel, "IsTopLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __IsTopLevel)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->IsTopLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __SetName)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFieldType, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFieldType, __GetName)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextFieldType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFieldType)
{
	Gura_AssignMethod(wx_RichTextFieldType, __wxRichTextFieldType);
	Gura_AssignMethod(wx_RichTextFieldType, __wxRichTextFieldType_1);
	Gura_AssignMethod(wx_RichTextFieldType, __Copy);
	Gura_AssignMethod(wx_RichTextFieldType, __Draw);
	Gura_AssignMethod(wx_RichTextFieldType, __Layout);
	Gura_AssignMethod(wx_RichTextFieldType, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextFieldType, __CanEditProperties);
	Gura_AssignMethod(wx_RichTextFieldType, __EditProperties);
	Gura_AssignMethod(wx_RichTextFieldType, __GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextFieldType, __UpdateField);
	Gura_AssignMethod(wx_RichTextFieldType, __IsTopLevel);
	Gura_AssignMethod(wx_RichTextFieldType, __SetName);
	Gura_AssignMethod(wx_RichTextFieldType, __GetName);
}

Gura_ImplementDescendantCreator(wx_RichTextFieldType)
{
	return new Object_wx_RichTextFieldType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
