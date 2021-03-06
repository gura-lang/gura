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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__MimeTypesManager, "MimeTypesManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MimeTypesManager));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MimeTypesManager)
{
	//wxMimeTypesManager();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MimeTypesManager, __AddFallbacks, "AddFallbacks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fallbacks", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __AddFallbacks)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFileTypeInfo* fallbacks = arg.GetNumber(0)
	//pThis->GetEntity()->AddFallbacks(fallbacks);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __GetFileTypeFromExtension, "GetFileTypeFromExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __GetFileTypeFromExtension)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& extension = arg.GetNumber(0)
	//wxFileType* _rtn = pThis->GetEntity()->GetFileTypeFromExtension(extension);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __GetFileTypeFromMimeType, "GetFileTypeFromMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __GetFileTypeFromMimeType)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& mimeType = arg.GetNumber(0)
	//wxFileType* _rtn = pThis->GetEntity()->GetFileTypeFromMimeType(mimeType);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __IsOfType, "IsOfType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __IsOfType)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& mimeType = arg.GetNumber(0)
	//const wxString& wildcard = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->IsOfType(mimeType, wildcard);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __Associate, "Associate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ftInfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __Associate)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFileTypeInfo& ftInfo = arg.GetNumber(0)
	//wxFileType* _rtn = pThis->GetEntity()->Associate(ftInfo);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __Unassociate, "Unassociate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ft", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __Unassociate)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFileType* ft = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Unassociate(ft);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MimeTypesManager, __EnumAllFileTypes, "EnumAllFileTypes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "mimetypes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, __EnumAllFileTypes)
{
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString& mimetypes = arg.GetNumber(0)
	//size_t _rtn = pThis->GetEntity()->EnumAllFileTypes(mimetypes);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MimeTypesManager)
{
	// Constructor assignment
	Gura_AssignFunction(__MimeTypesManager);
	// Method assignment
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
