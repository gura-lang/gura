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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextStyleDefinition, "RichTextStyleDefinition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleDefinition));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextStyleDefinition)
{
	//const wxString& name = arg.GetNumber(0)
	//wxRichTextStyleDefinition(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __GetBaseStyle, "GetBaseStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __GetBaseStyle)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetBaseStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __GetDescription, "GetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __GetDescription)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __GetName)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __GetStyle)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextAttr _rtn = pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __GetStyle_1, "GetStyle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __GetStyle_1)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr _rtn = pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __GetStyleMergedWithBase, "GetStyleMergedWithBase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __GetStyleMergedWithBase)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextStyleSheet* sheet = arg.GetNumber(0)
	//wxRichTextAttr _rtn = pThis->GetEntity()->GetStyleMergedWithBase(sheet);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __SetBaseStyle, "SetBaseStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __SetBaseStyle)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetBaseStyle(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __SetDescription, "SetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __SetDescription)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& descr = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescription(descr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __SetName)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __SetStyle)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextAttr& style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __GetProperties, "GetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __GetProperties)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextProperties& _rtn = pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __GetProperties_1, "GetProperties_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __GetProperties_1)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextProperties& _rtn = pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleDefinition, __SetProperties, "SetProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleDefinition, __SetProperties)
{
	Object_wx_RichTextStyleDefinition *pThis = Object_wx_RichTextStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextProperties& props = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperties(props);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleDefinition)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextStyleDefinition);
	// Method assignment
	Gura_AssignMethod(wx_RichTextStyleDefinition, __GetBaseStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __GetDescription);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __GetName);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __GetStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __GetStyle_1);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __GetStyleMergedWithBase);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __SetBaseStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __SetDescription);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __SetName);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __SetStyle);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __GetProperties);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __GetProperties_1);
	Gura_AssignMethod(wx_RichTextStyleDefinition, __SetProperties);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleDefinition)
{
	return new Object_wx_RichTextStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
