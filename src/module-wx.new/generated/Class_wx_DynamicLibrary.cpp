//----------------------------------------------------------------------------
// wxDynamicLibrary
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDynamicLibrary
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDynamicLibrary
//----------------------------------------------------------------------------
Object_wx_DynamicLibrary::~Object_wx_DynamicLibrary()
{
}

Object *Object_wx_DynamicLibrary::Clone() const
{
	return nullptr;
}

String Object_wx_DynamicLibrary::ToString(bool exprFlag)
{
	String rtn("<wx.DynamicLibrary:");
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
Gura_DeclareMethod(wx_DynamicLibrary, wxDynamicLibrary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, wxDynamicLibrary)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDynamicLibrary();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, wxDynamicLibrary_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, wxDynamicLibrary_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxDynamicLibrary();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, CanonicalizeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, CanonicalizeName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int cat = arg.GetNumber(1)
	//pThis->GetEntity()->CanonicalizeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, CanonicalizePluginName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, CanonicalizePluginName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int cat = arg.GetNumber(1)
	//pThis->GetEntity()->CanonicalizePluginName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, Detach)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, GetProgramHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, GetProgramHandle)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProgramHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, GetSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "success", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, GetSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int success = arg.GetNumber(1)
	//pThis->GetEntity()->GetSymbol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, GetSymbolAorW)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, GetSymbolAorW)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetSymbolAorW();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, HasSymbol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, HasSymbol)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->HasSymbol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, IsLoaded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, IsLoaded)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsLoaded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, ListLoaded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, ListLoaded)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ListLoaded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, GetModuleFromAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, GetModuleFromAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int addr = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->GetModuleFromAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, Load)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, Unload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, Unload)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Unload();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DynamicLibrary, Unload_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, Unload_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handle = arg.GetNumber(0)
	//pThis->GetEntity()->Unload();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDynamicLibrary
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DynamicLibrary)
{
	Gura_AssignMethod(wx_DynamicLibrary, wxDynamicLibrary);
	Gura_AssignMethod(wx_DynamicLibrary, wxDynamicLibrary_1);
	Gura_AssignMethod(wx_DynamicLibrary, CanonicalizeName);
	Gura_AssignMethod(wx_DynamicLibrary, CanonicalizePluginName);
	Gura_AssignMethod(wx_DynamicLibrary, Detach);
	Gura_AssignMethod(wx_DynamicLibrary, GetProgramHandle);
	Gura_AssignMethod(wx_DynamicLibrary, GetSymbol);
	Gura_AssignMethod(wx_DynamicLibrary, GetSymbolAorW);
	Gura_AssignMethod(wx_DynamicLibrary, HasSymbol);
	Gura_AssignMethod(wx_DynamicLibrary, IsLoaded);
	Gura_AssignMethod(wx_DynamicLibrary, ListLoaded);
	Gura_AssignMethod(wx_DynamicLibrary, GetModuleFromAddress);
	Gura_AssignMethod(wx_DynamicLibrary, Load);
	Gura_AssignMethod(wx_DynamicLibrary, Unload);
	Gura_AssignMethod(wx_DynamicLibrary, Unload_1);
}

Gura_ImplementDescendantCreator(wx_DynamicLibrary)
{
	return new Object_wx_DynamicLibrary((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
