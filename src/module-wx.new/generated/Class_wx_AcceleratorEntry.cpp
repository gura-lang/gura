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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AcceleratorEntry, "AcceleratorEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorEntry));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AcceleratorEntry)
{
	//int flags = arg.GetNumber(0)
	//int keyCode = arg.GetNumber(1)
	//int cmd = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//wxAcceleratorEntry();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__AcceleratorEntry_1, "AcceleratorEntry_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AcceleratorEntry));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AcceleratorEntry_1)
{
	//int entry = arg.GetNumber(0)
	//wxAcceleratorEntry();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AcceleratorEntry, __GetCommand, "GetCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __GetCommand)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCommand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AcceleratorEntry, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __GetFlags)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AcceleratorEntry, __GetKeyCode, "GetKeyCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __GetKeyCode)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKeyCode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AcceleratorEntry, __GetMenuItem, "GetMenuItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __GetMenuItem)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMenuItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AcceleratorEntry, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "keyCode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __Set)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int keyCode = arg.GetNumber(1)
	//int cmd = arg.GetNumber(2)
	//int item = arg.GetNumber(3)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AcceleratorEntry, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __IsOk)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AcceleratorEntry, __ToString, "ToString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __ToString)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AcceleratorEntry, __ToRawString, "ToRawString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __ToRawString)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToRawString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AcceleratorEntry, __FromString, "FromString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, __FromString)
{
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->FromString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorEntry)
{
	// Constructor assignment
	Gura_AssignFunction(__AcceleratorEntry);
	Gura_AssignFunction(__AcceleratorEntry_1);
	// Method assignment
	Gura_AssignMethod(wx_AcceleratorEntry, __GetCommand);
	Gura_AssignMethod(wx_AcceleratorEntry, __GetFlags);
	Gura_AssignMethod(wx_AcceleratorEntry, __GetKeyCode);
	Gura_AssignMethod(wx_AcceleratorEntry, __GetMenuItem);
	Gura_AssignMethod(wx_AcceleratorEntry, __Set);
	Gura_AssignMethod(wx_AcceleratorEntry, __IsOk);
	Gura_AssignMethod(wx_AcceleratorEntry, __ToString);
	Gura_AssignMethod(wx_AcceleratorEntry, __ToRawString);
	Gura_AssignMethod(wx_AcceleratorEntry, __FromString);
}

Gura_ImplementDescendantCreator(wx_AcceleratorEntry)
{
	return new Object_wx_AcceleratorEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
