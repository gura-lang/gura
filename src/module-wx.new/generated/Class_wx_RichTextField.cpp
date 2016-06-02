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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextField, wxRichTextField)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, wxRichTextField)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextField();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, wxRichTextField_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, wxRichTextField_1)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextField();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, Draw)
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

Gura_ImplementMethod(wx_RichTextField, Draw)
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

Gura_DeclareMethod(wx_RichTextField, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, Layout)
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

Gura_DeclareMethod(wx_RichTextField, GetRangeSize)
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

Gura_ImplementMethod(wx_RichTextField, GetRangeSize)
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

Gura_DeclareMethod(wx_RichTextField, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, GetXMLNodeName)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, CanEditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, CanEditProperties)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, EditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, EditProperties)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, GetPropertiesMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, GetPropertiesMenuLabel)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, AcceptsFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, AcceptsFocus)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, CalculateRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, CalculateRange)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, IsAtomic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, IsAtomic)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAtomic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, IsEmpty)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, IsTopLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, IsTopLevel)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTopLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, SetFieldType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fieldType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, SetFieldType)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fieldType = arg.GetNumber(0)
	//pThis->GetEntity()->SetFieldType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, GetFieldType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, GetFieldType)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFieldType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, UpdateField)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, UpdateField)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//pThis->GetEntity()->UpdateField();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextField, Clone)
{
	Object_wx_RichTextField *pThis = Object_wx_RichTextField::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextField, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextField, Copy)
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
	Gura_AssignMethod(wx_RichTextField, wxRichTextField);
	Gura_AssignMethod(wx_RichTextField, wxRichTextField_1);
	Gura_AssignMethod(wx_RichTextField, Draw);
	Gura_AssignMethod(wx_RichTextField, Layout);
	Gura_AssignMethod(wx_RichTextField, GetRangeSize);
	Gura_AssignMethod(wx_RichTextField, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextField, CanEditProperties);
	Gura_AssignMethod(wx_RichTextField, EditProperties);
	Gura_AssignMethod(wx_RichTextField, GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextField, AcceptsFocus);
	Gura_AssignMethod(wx_RichTextField, CalculateRange);
	Gura_AssignMethod(wx_RichTextField, IsAtomic);
	Gura_AssignMethod(wx_RichTextField, IsEmpty);
	Gura_AssignMethod(wx_RichTextField, IsTopLevel);
	Gura_AssignMethod(wx_RichTextField, SetFieldType);
	Gura_AssignMethod(wx_RichTextField, GetFieldType);
	Gura_AssignMethod(wx_RichTextField, UpdateField);
	Gura_AssignMethod(wx_RichTextField, Clone);
	Gura_AssignMethod(wx_RichTextField, Copy);
}

Gura_ImplementDescendantCreator(wx_RichTextField)
{
	return new Object_wx_RichTextField((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
