//----------------------------------------------------------------------------
// wxRichTextBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextBox
//----------------------------------------------------------------------------
Object_wx_RichTextBox::~Object_wx_RichTextBox()
{
}

Object *Object_wx_RichTextBox::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextBox::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextBox:");
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
Gura_DeclareFunctionAlias(__RichTextBox, "RichTextBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextBox)
{
	//wxRichTextObject* parent = arg.GetNumber(0)
	//wxRichTextBox(parent);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextBox_1, "RichTextBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextBox_1)
{
	//const wxRichTextBox& obj = arg.GetNumber(0)
	//wxRichTextBox(obj);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextBox, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextBox, __Draw)
{
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRichTextRange& range = arg.GetNumber(2)
	//const wxRichTextSelection& selection = arg.GetNumber(3)
	//const wxRect& rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Draw(dc, context, range, selection, rect, descent, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBox, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, __GetXMLNodeName)
{
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBox, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, __CanEditProperties)
{
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBox, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBox, __EditProperties)
{
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties(parent, buffer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBox, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBox, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, __Clone)
{
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextBox, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBox, __Copy)
{
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextBox& obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy(obj);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextBox)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextBox);
	Gura_AssignFunction(__RichTextBox_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextBox, __Draw);
	Gura_AssignMethod(wx_RichTextBox, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextBox, __CanEditProperties);
	Gura_AssignMethod(wx_RichTextBox, __EditProperties);
	Gura_AssignMethod(wx_RichTextBox, __GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextBox, __Clone);
	Gura_AssignMethod(wx_RichTextBox, __Copy);
}

Gura_ImplementDescendantCreator(wx_RichTextBox)
{
	return new Object_wx_RichTextBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
