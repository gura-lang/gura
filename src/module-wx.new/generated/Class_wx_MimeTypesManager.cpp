//----------------------------------------------------------------------------
// wxMimeTypesManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMimeTypesManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Object_wx_MimeTypesManager::~Object_wx_MimeTypesManager()
{
}

Object *Object_wx_MimeTypesManager::Clone() const
{
	return nullptr;
}

String Object_wx_MimeTypesManager::ToString(bool exprFlag)
{
	String rtn("<wx.MimeTypesManager:");
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
Gura_DeclareMethod(wx_MimeTypesManager, wxMimeTypesManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MimeTypesManager, wxMimeTypesManager)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMimeTypesManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MimeTypesManager, AddFallbacks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fallbacks", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, AddFallbacks)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fallbacks = arg.GetNumber(0)
	//pThis->GetEntity()->AddFallbacks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MimeTypesManager, GetFileTypeFromExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, GetFileTypeFromExtension)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extension = arg.GetNumber(0)
	//pThis->GetEntity()->GetFileTypeFromExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MimeTypesManager, GetFileTypeFromMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, GetFileTypeFromMimeType)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mimeType = arg.GetNumber(0)
	//pThis->GetEntity()->GetFileTypeFromMimeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MimeTypesManager, IsOfType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, IsOfType)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mimeType = arg.GetNumber(0)
	//int wildcard = arg.GetNumber(1)
	//pThis->GetEntity()->IsOfType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MimeTypesManager, Associate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ftInfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, Associate)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ftInfo = arg.GetNumber(0)
	//pThis->GetEntity()->Associate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MimeTypesManager, Unassociate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ft", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, Unassociate)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ft = arg.GetNumber(0)
	//pThis->GetEntity()->Unassociate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MimeTypesManager, EnumAllFileTypes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimetypes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, EnumAllFileTypes)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mimetypes = arg.GetNumber(0)
	//pThis->GetEntity()->EnumAllFileTypes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MimeTypesManager)
{
	Gura_AssignMethod(wx_MimeTypesManager, wxMimeTypesManager);
	Gura_AssignMethod(wx_MimeTypesManager, AddFallbacks);
	Gura_AssignMethod(wx_MimeTypesManager, GetFileTypeFromExtension);
	Gura_AssignMethod(wx_MimeTypesManager, GetFileTypeFromMimeType);
	Gura_AssignMethod(wx_MimeTypesManager, IsOfType);
	Gura_AssignMethod(wx_MimeTypesManager, Associate);
	Gura_AssignMethod(wx_MimeTypesManager, Unassociate);
	Gura_AssignMethod(wx_MimeTypesManager, EnumAllFileTypes);
}

Gura_ImplementDescendantCreator(wx_MimeTypesManager)
{
	return new Object_wx_MimeTypesManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
