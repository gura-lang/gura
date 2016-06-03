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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DynamicLibrary, "DynamicLibrary")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DynamicLibrary));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DynamicLibrary)
{
	//wxDynamicLibrary();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DynamicLibrary_1, "DynamicLibrary_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DynamicLibrary));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DynamicLibrary_1)
{
	//const wxString& name = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxDynamicLibrary();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DynamicLibrary, __CanonicalizeName, "CanonicalizeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, __CanonicalizeName)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxDynamicLibraryCategory cat = arg.GetNumber(1)
	//pThis->GetEntity()->CanonicalizeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __CanonicalizePluginName, "CanonicalizePluginName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, __CanonicalizePluginName)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxPluginCategory cat = arg.GetNumber(1)
	//pThis->GetEntity()->CanonicalizePluginName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __Detach, "Detach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, __Detach)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __GetProgramHandle, "GetProgramHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, __GetProgramHandle)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProgramHandle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __GetSymbol, "GetSymbol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "success", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, __GetSymbol)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//bool* success = arg.GetNumber(1)
	//pThis->GetEntity()->GetSymbol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __GetSymbolAorW, "GetSymbolAorW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, __GetSymbolAorW)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->GetSymbolAorW();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __HasSymbol, "HasSymbol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, __HasSymbol)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->HasSymbol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __IsLoaded, "IsLoaded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, __IsLoaded)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsLoaded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __ListLoaded, "ListLoaded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, __ListLoaded)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ListLoaded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __GetModuleFromAddress, "GetModuleFromAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, __GetModuleFromAddress)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const void* addr = arg.GetNumber(0)
	//wxString* path = arg.GetNumber(1)
	//pThis->GetEntity()->GetModuleFromAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, __Load)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __Unload, "Unload")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibrary, __Unload)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Unload();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibrary, __Unload_1, "Unload_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibrary, __Unload_1)
{
	Object_wx_DynamicLibrary *pThis = Object_wx_DynamicLibrary::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDllType handle = arg.GetNumber(0)
	//pThis->GetEntity()->Unload();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDynamicLibrary
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DynamicLibrary)
{
	// Constructor assignment
	Gura_AssignFunction(__DynamicLibrary);
	Gura_AssignFunction(__DynamicLibrary_1);
	// Method assignment
	Gura_AssignMethod(wx_DynamicLibrary, __CanonicalizeName);
	Gura_AssignMethod(wx_DynamicLibrary, __CanonicalizePluginName);
	Gura_AssignMethod(wx_DynamicLibrary, __Detach);
	Gura_AssignMethod(wx_DynamicLibrary, __GetProgramHandle);
	Gura_AssignMethod(wx_DynamicLibrary, __GetSymbol);
	Gura_AssignMethod(wx_DynamicLibrary, __GetSymbolAorW);
	Gura_AssignMethod(wx_DynamicLibrary, __HasSymbol);
	Gura_AssignMethod(wx_DynamicLibrary, __IsLoaded);
	Gura_AssignMethod(wx_DynamicLibrary, __ListLoaded);
	Gura_AssignMethod(wx_DynamicLibrary, __GetModuleFromAddress);
	Gura_AssignMethod(wx_DynamicLibrary, __Load);
	Gura_AssignMethod(wx_DynamicLibrary, __Unload);
	Gura_AssignMethod(wx_DynamicLibrary, __Unload_1);
}

Gura_ImplementDescendantCreator(wx_DynamicLibrary)
{
	return new Object_wx_DynamicLibrary((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
