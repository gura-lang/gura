//----------------------------------------------------------------------------
// wxAcceleratorEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAcceleratorEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Object_wx_AcceleratorEntry::~Object_wx_AcceleratorEntry()
{
}

Object *Object_wx_AcceleratorEntry::Clone() const
{
	return nullptr;
}

String Object_wx_AcceleratorEntry::ToString(bool exprFlag)
{
	String rtn("<wx.AcceleratorEntry:");
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
Gura_DeclareMethod(wx_AcceleratorEntry, wxAcceleratorEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, wxAcceleratorEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int keyCode = arg.GetNumber(1)
	//int cmd = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//pThis->GetEntity()->wxAcceleratorEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, wxAcceleratorEntry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, wxAcceleratorEntry_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->wxAcceleratorEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetKeyCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetKeyCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetMenuItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetMenuItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMenuItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int keyCode = arg.GetNumber(1)
	//int cmd = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, ToString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, ToString)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, ToRawString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, ToRawString)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ToRawString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, FromString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, FromString)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->FromString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorEntry)
{
	Gura_AssignMethod(wx_AcceleratorEntry, wxAcceleratorEntry);
	Gura_AssignMethod(wx_AcceleratorEntry, wxAcceleratorEntry_1);
	Gura_AssignMethod(wx_AcceleratorEntry, GetCommand);
	Gura_AssignMethod(wx_AcceleratorEntry, GetFlags);
	Gura_AssignMethod(wx_AcceleratorEntry, GetKeyCode);
	Gura_AssignMethod(wx_AcceleratorEntry, GetMenuItem);
	Gura_AssignMethod(wx_AcceleratorEntry, Set);
	Gura_AssignMethod(wx_AcceleratorEntry, IsOk);
	Gura_AssignMethod(wx_AcceleratorEntry, ToString);
	Gura_AssignMethod(wx_AcceleratorEntry, ToRawString);
	Gura_AssignMethod(wx_AcceleratorEntry, FromString);
}

Gura_ImplementDescendantCreator(wx_AcceleratorEntry)
{
	return new Object_wx_AcceleratorEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
