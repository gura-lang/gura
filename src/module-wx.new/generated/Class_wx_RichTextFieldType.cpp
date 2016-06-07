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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextFieldType, "RichTextFieldType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFieldType));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextFieldType)
{
	//const wxString& name = arg.GetNumber(0)
	//wxRichTextFieldType(name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextFieldType_1, "RichTextFieldType_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFieldType));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextFieldType_1)
{
	//const wxRichTextFieldType& fieldType = arg.GetNumber(0)
	//wxRichTextFieldType(fieldType);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextFieldType, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFieldType, __Copy)
{
	Object_wx_RichTextFieldType *pThis = Object_wx_RichTextFieldType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextFieldType& fieldType = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(fieldType);
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
	//wxRichTextField* obj = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//wxRichTextDrawingContext& context = arg.GetNumber(2)
	//const wxRichTextRange& range = arg.GetNumber(3)
	//const wxRichTextSelection& selection = arg.GetNumber(4)
	//const wxRect& rect = arg.GetNumber(5)
	//int descent = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//pThis->GetEntity()->Draw(obj, dc, context, range, selection, rect, descent, style);
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
	//wxRichTextField* obj = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//wxRichTextDrawingContext& context = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//const wxRect& parentRect = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//pThis->GetEntity()->Layout(obj, dc, context, rect, parentRect, style);
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
	//wxRichTextField* obj = arg.GetNumber(0)
	//const wxRichTextRange& range = arg.GetNumber(1)
	//wxSize& size = arg.GetNumber(2)
	//int& descent = arg.GetNumber(3)
	//wxDC& dc = arg.GetNumber(4)
	//wxRichTextDrawingContext& context = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//const wxPoint& position = arg.GetNumber(7)
	//const wxSize& parentSize = arg.GetNumber(8)
	//wxArrayInt* partialExtents = arg.GetNumber(9)
	//pThis->GetEntity()->GetRangeSize(obj, range, size, descent, dc, context, flags, position, parentSize, partialExtents);
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
	//wxRichTextField* obj = arg.GetNumber(0)
	//pThis->GetEntity()->CanEditProperties(obj);
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
	//wxRichTextField* obj = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//wxRichTextBuffer* buffer = arg.GetNumber(2)
	//pThis->GetEntity()->EditProperties(obj, parent, buffer);
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
	//wxRichTextField* obj = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertiesMenuLabel(obj);
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
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxRichTextField* obj = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateField(buffer, obj);
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
	//wxRichTextField* obj = arg.GetNumber(0)
	//pThis->GetEntity()->IsTopLevel(obj);
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
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName(name);
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
	// Constructor assignment
	Gura_AssignFunction(__RichTextFieldType);
	Gura_AssignFunction(__RichTextFieldType_1);
	// Method assignment
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
