//----------------------------------------------------------------------------
// wxPGProperty
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGProperty
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGProperty
//----------------------------------------------------------------------------
Object_wx_PGProperty::~Object_wx_PGProperty()
{
}

Object *Object_wx_PGProperty::Clone() const
{
	return nullptr;
}

String Object_wx_PGProperty::ToString(bool exprFlag)
{
	String rtn("<wx.PGProperty:");
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
Gura_DeclareMethod(wx_PGProperty, wxPGProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, wxPGProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPGProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, wxPGProperty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, wxPGProperty_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->wxPGProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, ~wxPGProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, ~wxPGProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPGProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, OnSetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, OnSetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnSetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, DoGetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, DoGetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DoGetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, ValidateValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validationInfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, ValidateValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int validationInfo = arg.GetNumber(1)
	//pThis->GetEntity()->ValidateValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, StringToValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, StringToValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int argFlags = arg.GetNumber(2)
	//pThis->GetEntity()->StringToValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IntToValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, IntToValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//int number = arg.GetNumber(1)
	//int argFlags = arg.GetNumber(2)
	//pThis->GetEntity()->IntToValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, ValueToString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, ValueToString)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int argFlags = arg.GetNumber(1)
	//pThis->GetEntity()->ValueToString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetValueFromString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetValueFromString)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetValueFromString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetValueFromInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetValueFromInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetValueFromInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, OnMeasureImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, OnMeasureImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->OnMeasureImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, OnEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "propgrid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd_primary", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, OnEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int propgrid = arg.GetNumber(0)
	//int wnd_primary = arg.GetNumber(1)
	//int event = arg.GetNumber(2)
	//pThis->GetEntity()->OnEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, ChildChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "thisValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childIndex", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, ChildChanged)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int thisValue = arg.GetNumber(0)
	//int childIndex = arg.GetNumber(1)
	//int childValue = arg.GetNumber(2)
	//pThis->GetEntity()->ChildChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, DoGetEditorClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, DoGetEditorClass)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DoGetEditorClass();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, DoGetValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, DoGetValidator)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DoGetValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, OnCustomPaint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paintdata", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, OnCustomPaint)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int paintdata = arg.GetNumber(2)
	//pThis->GetEntity()->OnCustomPaint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetCellRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetCellRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetCellRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetChoiceSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetChoiceSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChoiceSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, RefreshChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, RefreshChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RefreshChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, DoSetAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, DoSetAttribute)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->DoSetAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, DoGetAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, DoGetAttribute)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->DoGetAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetEditorDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetEditorDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEditorDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, OnValidationFailure)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pendingValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, OnValidationFailure)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pendingValue = arg.GetNumber(0)
	//pThis->GetEntity()->OnValidationFailure();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, AddChoice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, AddChoice)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->AddChoice();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, wxDEPRECATED)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, wxDEPRECATED)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDEPRECATED();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, AddPrivateChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, AddPrivateChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prop = arg.GetNumber(0)
	//pThis->GetEntity()->AddPrivateChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, AdaptListToValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "list", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, AdaptListToValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int list = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->AdaptListToValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, AppendChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, AppendChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int childProperty = arg.GetNumber(0)
	//pThis->GetEntity()->AppendChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, AreAllChildrenSpecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pendingList", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, AreAllChildrenSpecified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pendingList = arg.GetNumber(0)
	//pThis->GetEntity()->AreAllChildrenSpecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, AreChildrenComponents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, AreChildrenComponents)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AreChildrenComponents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, ChangeFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, ChangeFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//int set = arg.GetNumber(1)
	//pThis->GetEntity()->ChangeFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, DeleteChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, DeleteChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, DeleteChoice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, DeleteChoice)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteChoice();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GenerateComposedValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GenerateComposedValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GenerateComposedValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetAttribute)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetAttribute_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetAttribute_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int defVal = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetAttributeAsLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetAttributeAsLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int defVal = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttributeAsLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetAttributeAsDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetAttributeAsDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int defVal = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttributeAsDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetAttributesAsList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetAttributesAsList)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAttributesAsList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetColumnEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetColumnEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetBaseName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetBaseName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBaseName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetCell_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetCell_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetOrCreateCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetOrCreateCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->GetOrCreateCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetChildCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetChildCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetChildrenHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lh", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetChildrenHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int lh = arg.GetNumber(0)
	//int iMax = arg.GetNumber(1)
	//pThis->GetEntity()->GetChildrenHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetChoices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetChoices)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChoices();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetDefaultValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetDefaultValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetDisplayedString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetDisplayedString)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDisplayedString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetEditorClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetEditorClass)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEditorClass();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetGrid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetGrid)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetGrid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetGridIfDisplayed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetGridIfDisplayed)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetGridIfDisplayed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetHelpString)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetIndexInParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetIndexInParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIndexInParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetLastVisibleSubItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetLastVisibleSubItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLastVisibleSubItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetMainParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetMainParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMainParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetMaxLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetMaxLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetPropertyByName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetPropertyByName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPropertyByName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetValidator)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetValueImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetValueImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValueImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetValueAsString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, GetValueAsString)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int argFlags = arg.GetNumber(0)
	//pThis->GetEntity()->GetValueAsString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, wxDEPRECATED_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, wxDEPRECATED_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int argFlags = arg.GetNumber(0)
	//pThis->GetEntity()->wxDEPRECATED();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetValueType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetValueType)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValueType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, GetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, HasFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, HasFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, HasVisibleChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, HasVisibleChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasVisibleChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hide", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hide = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, Index)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, InsertChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childProperty", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, InsertChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int childProperty = arg.GetNumber(1)
	//pThis->GetEntity()->InsertChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, InsertChoice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, InsertChoice)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->InsertChoice();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IsCategory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, IsCategory)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsCategory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, IsEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IsExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, IsExpanded)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IsRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, IsRoot)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsRoot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IsSomeParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "candidateParent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, IsSomeParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int candidateParent = arg.GetNumber(0)
	//pThis->GetEntity()->IsSomeParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IsTextEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, IsTextEditable)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsTextEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IsValueUnspecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, IsValueUnspecified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsValueUnspecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, IsVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, Item)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, Item)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, RefreshEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, RefreshEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RefreshEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetAttribute)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetAutoUnspecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetAutoUnspecified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->SetAutoUnspecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int editor = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetEditor_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "editorName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetEditor_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int editorName = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//int cell = arg.GetNumber(1)
	//pThis->GetEntity()->SetCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetChoices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetChoices)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int choices = arg.GetNumber(0)
	//pThis->GetEntity()->SetChoices();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int clientData = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clientObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetClientObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int clientObject = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetChoiceSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetChoiceSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int newValue = arg.GetNumber(0)
	//pThis->GetEntity()->SetChoiceSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetDefaultValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetDefaultValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetFlagRecursively)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetFlagRecursively)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//int set = arg.GetNumber(1)
	//pThis->GetEntity()->SetFlagRecursively();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetHelpString)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int helpString = arg.GetNumber(0)
	//pThis->GetEntity()->SetHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetMaxLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetMaxLength)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int maxLen = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetModifiedStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetModifiedStatus)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int modified = arg.GetNumber(0)
	//pThis->GetEntity()->SetModifiedStatus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int newName = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetParentalType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetParentalType)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentalType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetValidator)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int validator = arg.GetNumber(0)
	//pThis->GetEntity()->SetValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pList", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int pList = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetValueImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetValueImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetValueImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetValueInEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetValueInEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValueInEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetValueToUnspecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, SetValueToUnspecified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetValueToUnspecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, SetWasModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PGProperty, SetWasModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int set = arg.GetNumber(0)
	//pThis->GetEntity()->SetWasModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, UpdateParentValues)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, UpdateParentValues)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UpdateParentValues();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, UsesAutoUnspecified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, UsesAutoUnspecified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UsesAutoUnspecified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PGProperty, Empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PGProperty, Empty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PGProperty *pThis = Object_wx_PGProperty::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Empty();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPGProperty
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGProperty)
{
	Gura_AssignMethod(wx_PGProperty, wxPGProperty);
	Gura_AssignMethod(wx_PGProperty, wxPGProperty_1);
	Gura_AssignMethod(wx_PGProperty, ~wxPGProperty);
	Gura_AssignMethod(wx_PGProperty, OnSetValue);
	Gura_AssignMethod(wx_PGProperty, DoGetValue);
	Gura_AssignMethod(wx_PGProperty, ValidateValue);
	Gura_AssignMethod(wx_PGProperty, StringToValue);
	Gura_AssignMethod(wx_PGProperty, IntToValue);
	Gura_AssignMethod(wx_PGProperty, ValueToString);
	Gura_AssignMethod(wx_PGProperty, SetValueFromString);
	Gura_AssignMethod(wx_PGProperty, SetValueFromInt);
	Gura_AssignMethod(wx_PGProperty, OnMeasureImage);
	Gura_AssignMethod(wx_PGProperty, OnEvent);
	Gura_AssignMethod(wx_PGProperty, ChildChanged);
	Gura_AssignMethod(wx_PGProperty, DoGetEditorClass);
	Gura_AssignMethod(wx_PGProperty, DoGetValidator);
	Gura_AssignMethod(wx_PGProperty, OnCustomPaint);
	Gura_AssignMethod(wx_PGProperty, GetCellRenderer);
	Gura_AssignMethod(wx_PGProperty, GetChoiceSelection);
	Gura_AssignMethod(wx_PGProperty, RefreshChildren);
	Gura_AssignMethod(wx_PGProperty, DoSetAttribute);
	Gura_AssignMethod(wx_PGProperty, DoGetAttribute);
	Gura_AssignMethod(wx_PGProperty, GetEditorDialog);
	Gura_AssignMethod(wx_PGProperty, OnValidationFailure);
	Gura_AssignMethod(wx_PGProperty, AddChoice);
	Gura_AssignMethod(wx_PGProperty, wxDEPRECATED);
	Gura_AssignMethod(wx_PGProperty, AddPrivateChild);
	Gura_AssignMethod(wx_PGProperty, AdaptListToValue);
	Gura_AssignMethod(wx_PGProperty, AppendChild);
	Gura_AssignMethod(wx_PGProperty, AreAllChildrenSpecified);
	Gura_AssignMethod(wx_PGProperty, AreChildrenComponents);
	Gura_AssignMethod(wx_PGProperty, ChangeFlag);
	Gura_AssignMethod(wx_PGProperty, DeleteChildren);
	Gura_AssignMethod(wx_PGProperty, DeleteChoice);
	Gura_AssignMethod(wx_PGProperty, Enable);
	Gura_AssignMethod(wx_PGProperty, GenerateComposedValue);
	Gura_AssignMethod(wx_PGProperty, GetAttribute);
	Gura_AssignMethod(wx_PGProperty, GetAttribute_1);
	Gura_AssignMethod(wx_PGProperty, GetAttributeAsLong);
	Gura_AssignMethod(wx_PGProperty, GetAttributeAsDouble);
	Gura_AssignMethod(wx_PGProperty, GetAttributesAsList);
	Gura_AssignMethod(wx_PGProperty, GetColumnEditor);
	Gura_AssignMethod(wx_PGProperty, GetBaseName);
	Gura_AssignMethod(wx_PGProperty, GetCell);
	Gura_AssignMethod(wx_PGProperty, GetCell_1);
	Gura_AssignMethod(wx_PGProperty, GetOrCreateCell);
	Gura_AssignMethod(wx_PGProperty, GetChildCount);
	Gura_AssignMethod(wx_PGProperty, GetChildrenHeight);
	Gura_AssignMethod(wx_PGProperty, GetChoices);
	Gura_AssignMethod(wx_PGProperty, GetClientData);
	Gura_AssignMethod(wx_PGProperty, GetClientObject);
	Gura_AssignMethod(wx_PGProperty, GetDefaultValue);
	Gura_AssignMethod(wx_PGProperty, GetDisplayedString);
	Gura_AssignMethod(wx_PGProperty, GetEditorClass);
	Gura_AssignMethod(wx_PGProperty, GetFlags);
	Gura_AssignMethod(wx_PGProperty, GetGrid);
	Gura_AssignMethod(wx_PGProperty, GetGridIfDisplayed);
	Gura_AssignMethod(wx_PGProperty, GetHelpString);
	Gura_AssignMethod(wx_PGProperty, GetIndexInParent);
	Gura_AssignMethod(wx_PGProperty, GetLabel);
	Gura_AssignMethod(wx_PGProperty, GetLastVisibleSubItem);
	Gura_AssignMethod(wx_PGProperty, GetMainParent);
	Gura_AssignMethod(wx_PGProperty, GetMaxLength);
	Gura_AssignMethod(wx_PGProperty, GetName);
	Gura_AssignMethod(wx_PGProperty, GetParent);
	Gura_AssignMethod(wx_PGProperty, GetPropertyByName);
	Gura_AssignMethod(wx_PGProperty, GetValidator);
	Gura_AssignMethod(wx_PGProperty, GetValue);
	Gura_AssignMethod(wx_PGProperty, GetValueImage);
	Gura_AssignMethod(wx_PGProperty, GetValueAsString);
	Gura_AssignMethod(wx_PGProperty, wxDEPRECATED_1);
	Gura_AssignMethod(wx_PGProperty, GetValueType);
	Gura_AssignMethod(wx_PGProperty, GetY);
	Gura_AssignMethod(wx_PGProperty, HasFlag);
	Gura_AssignMethod(wx_PGProperty, HasVisibleChildren);
	Gura_AssignMethod(wx_PGProperty, Hide);
	Gura_AssignMethod(wx_PGProperty, Index);
	Gura_AssignMethod(wx_PGProperty, InsertChild);
	Gura_AssignMethod(wx_PGProperty, InsertChoice);
	Gura_AssignMethod(wx_PGProperty, IsCategory);
	Gura_AssignMethod(wx_PGProperty, IsEnabled);
	Gura_AssignMethod(wx_PGProperty, IsExpanded);
	Gura_AssignMethod(wx_PGProperty, IsRoot);
	Gura_AssignMethod(wx_PGProperty, IsSomeParent);
	Gura_AssignMethod(wx_PGProperty, IsTextEditable);
	Gura_AssignMethod(wx_PGProperty, IsValueUnspecified);
	Gura_AssignMethod(wx_PGProperty, IsVisible);
	Gura_AssignMethod(wx_PGProperty, Item);
	Gura_AssignMethod(wx_PGProperty, RefreshEditor);
	Gura_AssignMethod(wx_PGProperty, SetAttribute);
	Gura_AssignMethod(wx_PGProperty, SetAutoUnspecified);
	Gura_AssignMethod(wx_PGProperty, SetBackgroundColour);
	Gura_AssignMethod(wx_PGProperty, SetEditor);
	Gura_AssignMethod(wx_PGProperty, SetEditor_1);
	Gura_AssignMethod(wx_PGProperty, SetCell);
	Gura_AssignMethod(wx_PGProperty, SetChoices);
	Gura_AssignMethod(wx_PGProperty, SetClientData);
	Gura_AssignMethod(wx_PGProperty, SetClientObject);
	Gura_AssignMethod(wx_PGProperty, SetChoiceSelection);
	Gura_AssignMethod(wx_PGProperty, SetDefaultValue);
	Gura_AssignMethod(wx_PGProperty, SetFlagRecursively);
	Gura_AssignMethod(wx_PGProperty, SetHelpString);
	Gura_AssignMethod(wx_PGProperty, SetLabel);
	Gura_AssignMethod(wx_PGProperty, SetMaxLength);
	Gura_AssignMethod(wx_PGProperty, SetModifiedStatus);
	Gura_AssignMethod(wx_PGProperty, SetName);
	Gura_AssignMethod(wx_PGProperty, SetParentalType);
	Gura_AssignMethod(wx_PGProperty, SetTextColour);
	Gura_AssignMethod(wx_PGProperty, SetValidator);
	Gura_AssignMethod(wx_PGProperty, SetValue);
	Gura_AssignMethod(wx_PGProperty, SetValueImage);
	Gura_AssignMethod(wx_PGProperty, SetValueInEvent);
	Gura_AssignMethod(wx_PGProperty, SetValueToUnspecified);
	Gura_AssignMethod(wx_PGProperty, SetWasModified);
	Gura_AssignMethod(wx_PGProperty, UpdateParentValues);
	Gura_AssignMethod(wx_PGProperty, UsesAutoUnspecified);
	Gura_AssignMethod(wx_PGProperty, Empty);
}

Gura_ImplementDescendantCreator(wx_PGProperty)
{
	return new Object_wx_PGProperty((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
