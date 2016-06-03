//----------------------------------------------------------------------------
// wxGridTableMessage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridTableMessage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridTableMessage
//----------------------------------------------------------------------------
Object_wx_GridTableMessage::~Object_wx_GridTableMessage()
{
}

Object *Object_wx_GridTableMessage::Clone() const
{
	return nullptr;
}

String Object_wx_GridTableMessage::ToString(bool exprFlag)
{
	String rtn("<wx.GridTableMessage:");
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
Gura_DeclareFunctionAlias(__wxGridTableMessage, "wxGridTableMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridTableMessage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxGridTableMessage)
{
	//wxGridTableMessage();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGridTableMessage_1, "wxGridTableMessage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "comInt1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "comInt2", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridTableMessage));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxGridTableMessage_1)
{
	//int table = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int comInt1 = arg.GetNumber(2)
	//int comInt2 = arg.GetNumber(3)
	//wxGridTableMessage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridTableMessage, __SetTableObject, "SetTableObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, __SetTableObject)
{
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//pThis->GetEntity()->SetTableObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableMessage, __GetTableObject, "GetTableObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, __GetTableObject)
{
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTableObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableMessage, __SetId, "SetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, __SetId)
{
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableMessage, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, __GetId)
{
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableMessage, __SetCommandInt, "SetCommandInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comInt1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, __SetCommandInt)
{
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int comInt1 = arg.GetNumber(0)
	//pThis->GetEntity()->SetCommandInt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableMessage, __GetCommandInt, "GetCommandInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, __GetCommandInt)
{
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCommandInt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableMessage, __SetCommandInt2, "SetCommandInt2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comInt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, __SetCommandInt2)
{
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int comInt2 = arg.GetNumber(0)
	//pThis->GetEntity()->SetCommandInt2();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridTableMessage, __GetCommandInt2, "GetCommandInt2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, __GetCommandInt2)
{
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCommandInt2();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridTableMessage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridTableMessage)
{
	// Constructor assignment
	Gura_AssignFunction(__wxGridTableMessage);
	Gura_AssignFunction(__wxGridTableMessage_1);
	// Method assignment
	Gura_AssignMethod(wx_GridTableMessage, __SetTableObject);
	Gura_AssignMethod(wx_GridTableMessage, __GetTableObject);
	Gura_AssignMethod(wx_GridTableMessage, __SetId);
	Gura_AssignMethod(wx_GridTableMessage, __GetId);
	Gura_AssignMethod(wx_GridTableMessage, __SetCommandInt);
	Gura_AssignMethod(wx_GridTableMessage, __GetCommandInt);
	Gura_AssignMethod(wx_GridTableMessage, __SetCommandInt2);
	Gura_AssignMethod(wx_GridTableMessage, __GetCommandInt2);
}

Gura_ImplementDescendantCreator(wx_GridTableMessage)
{
	return new Object_wx_GridTableMessage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
