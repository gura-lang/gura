//----------------------------------------------------------------------------
// wxCommandEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommandEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCommandEvent
//----------------------------------------------------------------------------
Object_wx_CommandEvent::~Object_wx_CommandEvent()
{
}

Object *Object_wx_CommandEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CommandEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CommandEvent:");
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
Gura_DeclareFunctionAlias(__CommandEvent, "CommandEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandEventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CommandEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CommandEvent)
{
	//wxEventType commandEventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxCommandEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CommandEvent, __GetClientData, "GetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, __GetClientData)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __GetClientObject, "GetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, __GetClientObject)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __GetExtraLong, "GetExtraLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, __GetExtraLong)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __GetInt, "GetInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, __GetInt)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, __GetSelection)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, __GetString)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __IsChecked, "IsChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, __IsChecked)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __IsSelection, "IsSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandEvent, __IsSelection)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __SetClientData, "SetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, __SetClientData)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* clientData = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __SetClientObject, "SetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clientObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, __SetClientObject)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxClientData* clientObject = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __SetExtraLong, "SetExtraLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extraLong", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, __SetExtraLong)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long extraLong = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __SetInt, "SetInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "intCommand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, __SetInt)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int intCommand = arg.GetNumber(0)
	//pThis->GetEntity()->SetInt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CommandEvent, __SetString, "SetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandEvent, __SetString)
{
	Object_wx_CommandEvent *pThis = Object_wx_CommandEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCommandEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__CommandEvent);
	// Method assignment
	Gura_AssignMethod(wx_CommandEvent, __GetClientData);
	Gura_AssignMethod(wx_CommandEvent, __GetClientObject);
	Gura_AssignMethod(wx_CommandEvent, __GetExtraLong);
	Gura_AssignMethod(wx_CommandEvent, __GetInt);
	Gura_AssignMethod(wx_CommandEvent, __GetSelection);
	Gura_AssignMethod(wx_CommandEvent, __GetString);
	Gura_AssignMethod(wx_CommandEvent, __IsChecked);
	Gura_AssignMethod(wx_CommandEvent, __IsSelection);
	Gura_AssignMethod(wx_CommandEvent, __SetClientData);
	Gura_AssignMethod(wx_CommandEvent, __SetClientObject);
	Gura_AssignMethod(wx_CommandEvent, __SetExtraLong);
	Gura_AssignMethod(wx_CommandEvent, __SetInt);
	Gura_AssignMethod(wx_CommandEvent, __SetString);
}

Gura_ImplementDescendantCreator(wx_CommandEvent)
{
	return new Object_wx_CommandEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
