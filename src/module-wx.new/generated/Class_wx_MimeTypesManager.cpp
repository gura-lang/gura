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
Gura_DeclareMethodAlias(wx_MimeTypesManager, __wxMimeTypesManager, "wxMimeTypesManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MimeTypesManager, __wxMimeTypesManager)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMimeTypesManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __AddFallbacks, "AddFallbacks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fallbacks", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __AddFallbacks)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fallbacks = arg.GetNumber(0)
	//pThis->GetEntity()->AddFallbacks();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __GetFileTypeFromExtension, "GetFileTypeFromExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __GetFileTypeFromExtension)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extension = arg.GetNumber(0)
	//pThis->GetEntity()->GetFileTypeFromExtension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __GetFileTypeFromMimeType, "GetFileTypeFromMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __GetFileTypeFromMimeType)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mimeType = arg.GetNumber(0)
	//pThis->GetEntity()->GetFileTypeFromMimeType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __IsOfType, "IsOfType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __IsOfType)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mimeType = arg.GetNumber(0)
	//int wildcard = arg.GetNumber(1)
	//pThis->GetEntity()->IsOfType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __Associate, "Associate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ftInfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __Associate)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ftInfo = arg.GetNumber(0)
	//pThis->GetEntity()->Associate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __Unassociate, "Unassociate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ft", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __Unassociate)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ft = arg.GetNumber(0)
	//pThis->GetEntity()->Unassociate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __EnumAllFileTypes, "EnumAllFileTypes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimetypes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __EnumAllFileTypes)
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
	Gura_AssignMethod(wx_MimeTypesManager, __wxMimeTypesManager);
	Gura_AssignMethod(wx_MimeTypesManager, __AddFallbacks);
	Gura_AssignMethod(wx_MimeTypesManager, __GetFileTypeFromExtension);
	Gura_AssignMethod(wx_MimeTypesManager, __GetFileTypeFromMimeType);
	Gura_AssignMethod(wx_MimeTypesManager, __IsOfType);
	Gura_AssignMethod(wx_MimeTypesManager, __Associate);
	Gura_AssignMethod(wx_MimeTypesManager, __Unassociate);
	Gura_AssignMethod(wx_MimeTypesManager, __EnumAllFileTypes);
}

Gura_ImplementDescendantCreator(wx_MimeTypesManager)
{
	return new Object_wx_MimeTypesManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
