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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextBox, wxRichTextBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBox, wxRichTextBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBox, wxRichTextBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, wxRichTextBox_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBox, Draw)
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

Gura_ImplementMethod(wx_RichTextBox, Draw)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RichTextBox, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, GetXMLNodeName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBox, CanEditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, CanEditProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBox, EditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBox, EditProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBox, GetPropertiesMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, GetPropertiesMenuLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBox, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextBox, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextBox, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextBox, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextBox *pThis = Object_wx_RichTextBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextBox)
{
	Gura_AssignMethod(wx_RichTextBox, wxRichTextBox);
	Gura_AssignMethod(wx_RichTextBox, wxRichTextBox_1);
	Gura_AssignMethod(wx_RichTextBox, Draw);
	Gura_AssignMethod(wx_RichTextBox, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextBox, CanEditProperties);
	Gura_AssignMethod(wx_RichTextBox, EditProperties);
	Gura_AssignMethod(wx_RichTextBox, GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextBox, Clone);
	Gura_AssignMethod(wx_RichTextBox, Copy);
}

Gura_ImplementDescendantCreator(wx_RichTextBox)
{
	return new Object_wx_RichTextBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
