//----------------------------------------------------------------------------
// wxRichTextField
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextField
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextField
//----------------------------------------------------------------------------
Object_wx_RichTextField::~Object_wx_RichTextField()
{
}

Object *Object_wx_RichTextField::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextField::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextField:");
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
Gura_DeclareFunctionAlias(__wxRichTextField, "wxRichTextField")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextField));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextField)
{
	//int fieldType = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//wxRichTextField();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRichTextField_1, "wxRichTextField_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextField));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextField_1)
{
	//wxRichTextField();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextField, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextField, __Draw)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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

Gura_DeclareMethodAlias(wx_RichTextField, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, __Layout)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __GetRangeSize, "GetRangeSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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

Gura_ImplementMethod(wx_RichTextField, __GetRangeSize)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int descent = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//int context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//int position = arg.GetNumber(6)
	//int parentSize = arg.GetNumber(7)
	//int partialExtents = arg.GetNumber(8)
	//pThis->GetEntity()->GetRangeSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __GetXMLNodeName)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __CanEditProperties)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, __EditProperties)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __AcceptsFocus, "AcceptsFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __AcceptsFocus)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __CalculateRange, "CalculateRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, __CalculateRange)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __IsAtomic, "IsAtomic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __IsAtomic)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAtomic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __IsEmpty)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __IsTopLevel, "IsTopLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __IsTopLevel)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTopLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __SetFieldType, "SetFieldType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, __SetFieldType)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//pThis->GetEntity()->SetFieldType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __GetFieldType, "GetFieldType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __GetFieldType)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFieldType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __UpdateField, "UpdateField")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, __UpdateField)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateField();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, __Clone)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextField, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, __Copy)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextField
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextField)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextField);
	Gura_AssignFunction(__wxRichTextField_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextField, __Draw);
	Gura_AssignMethod(wx_RichTextField, __Layout);
	Gura_AssignMethod(wx_RichTextField, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextField, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextField, __CanEditProperties);
	Gura_AssignMethod(wx_RichTextField, __EditProperties);
	Gura_AssignMethod(wx_RichTextField, __GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextField, __AcceptsFocus);
	Gura_AssignMethod(wx_RichTextField, __CalculateRange);
	Gura_AssignMethod(wx_RichTextField, __IsAtomic);
	Gura_AssignMethod(wx_RichTextField, __IsEmpty);
	Gura_AssignMethod(wx_RichTextField, __IsTopLevel);
	Gura_AssignMethod(wx_RichTextField, __SetFieldType);
	Gura_AssignMethod(wx_RichTextField, __GetFieldType);
	Gura_AssignMethod(wx_RichTextField, __UpdateField);
	Gura_AssignMethod(wx_RichTextField, __Clone);
	Gura_AssignMethod(wx_RichTextField, __Copy);
}

Gura_ImplementDescendantCreator(wx_RichTextField)
{
	return new Object_wx_RichTextField((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
