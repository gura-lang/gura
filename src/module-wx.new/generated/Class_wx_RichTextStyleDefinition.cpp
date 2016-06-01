//----------------------------------------------------------------------------
// wxRichTextStyleDefinition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleDefinition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextStyleDefinition::~Object_wx_RichTextStyleDefinition()
{
}

Object *Object_wx_RichTextStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleDefinition:");
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
Gura_DeclareMethod(wx_RichTextStyleDefinition, wxRichTextStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, wxRichTextStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, ~wxRichTextStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, ~wxRichTextStyleDefinition)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRichTextStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetBaseStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetBaseStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBaseStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyle_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetStyleMergedWithBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetStyleMergedWithBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->GetStyleMergedWithBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetBaseStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetBaseStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetBaseStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int descr = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, GetProperties_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, GetProperties_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleDefinition, SetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, SetProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int props = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperties();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleDefinition)
{
	Gura_AssignMethod(wx_RichTextStyleDefinition, wxRichTextStyleDefinition);
	Gura_AssignMethod(wx_RichTextStyleDefinition, ~wxRichTextStyleDefinition);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetBaseStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetDescription);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetName);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetStyle_1);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetStyleMergedWithBase);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetBaseStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetDescription);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetName);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetProperties);
	Gura_AssignMethod(wx_RichTextStyleDefinition, GetProperties_1);
	Gura_AssignMethod(wx_RichTextStyleDefinition, SetProperties);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleDefinition)
{
	return new Object_wx_RichTextStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
