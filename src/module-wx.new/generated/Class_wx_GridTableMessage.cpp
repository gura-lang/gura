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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridTableMessage, wxGridTableMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, wxGridTableMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGridTableMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, wxGridTableMessage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "comInt1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "comInt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, wxGridTableMessage_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int comInt1 = arg.GetNumber(2)
	//int comInt2 = arg.GetNumber(3)
	//pThis->GetEntity()->wxGridTableMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, SetTableObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "table", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, SetTableObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int table = arg.GetNumber(0)
	//pThis->GetEntity()->SetTableObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, GetTableObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, GetTableObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTableObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, SetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, SetCommandInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comInt1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, SetCommandInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int comInt1 = arg.GetNumber(0)
	//pThis->GetEntity()->SetCommandInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, GetCommandInt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, GetCommandInt)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCommandInt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, SetCommandInt2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comInt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableMessage, SetCommandInt2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int comInt2 = arg.GetNumber(0)
	//pThis->GetEntity()->SetCommandInt2();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableMessage, GetCommandInt2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableMessage, GetCommandInt2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableMessage *pThis = Object_wx_GridTableMessage::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCommandInt2();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridTableMessage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridTableMessage)
{
	Gura_AssignMethod(wx_GridTableMessage, wxGridTableMessage);
	Gura_AssignMethod(wx_GridTableMessage, wxGridTableMessage_1);
	Gura_AssignMethod(wx_GridTableMessage, SetTableObject);
	Gura_AssignMethod(wx_GridTableMessage, GetTableObject);
	Gura_AssignMethod(wx_GridTableMessage, SetId);
	Gura_AssignMethod(wx_GridTableMessage, GetId);
	Gura_AssignMethod(wx_GridTableMessage, SetCommandInt);
	Gura_AssignMethod(wx_GridTableMessage, GetCommandInt);
	Gura_AssignMethod(wx_GridTableMessage, SetCommandInt2);
	Gura_AssignMethod(wx_GridTableMessage, GetCommandInt2);
}

Gura_ImplementDescendantCreator(wx_GridTableMessage)
{
	return new Object_wx_GridTableMessage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
