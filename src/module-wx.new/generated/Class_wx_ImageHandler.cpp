//----------------------------------------------------------------------------
// wxImageHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxImageHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxImageHandler
//----------------------------------------------------------------------------
Object_wx_ImageHandler::~Object_wx_ImageHandler()
{
}

Object *Object_wx_ImageHandler::Clone() const
{
	return nullptr;
}

String Object_wx_ImageHandler::ToString(bool exprFlag)
{
	String rtn("<wx.ImageHandler:");
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
Gura_DeclareFunctionAlias(__ImageHandler, "ImageHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ImageHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ImageHandler)
{
	//wxImageHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ImageHandler, __CanRead, "CanRead")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __CanRead)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->CanRead();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __CanRead_1, "CanRead_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __CanRead_1)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->CanRead();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __GetExtension, "GetExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, __GetExtension)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __GetAltExtensions, "GetAltExtensions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, __GetAltExtensions)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAltExtensions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __GetImageCount, "GetImageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __GetImageCount)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->GetImageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __GetMimeType, "GetMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, __GetMimeType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, __GetName)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, __GetType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "verbose", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __LoadFile)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//int verbose = arg.GetNumber(2)
	//int index = arg.GetNumber(3)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __SaveFile, "SaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "verbose", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __SaveFile)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//int verbose = arg.GetNumber(2)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __SetExtension, "SetExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __SetExtension)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extension = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __SetAltExtensions, "SetAltExtensions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extensions", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __SetAltExtensions)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extensions = arg.GetNumber(0)
	//pThis->GetEntity()->SetAltExtensions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __SetMimeType, "SetMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __SetMimeType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mimetype = arg.GetNumber(0)
	//pThis->GetEntity()->SetMimeType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __SetName)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __GetLibraryVersionInfo, "GetLibraryVersionInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, __GetLibraryVersionInfo)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLibraryVersionInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __DoGetImageCount, "DoGetImageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __DoGetImageCount)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->DoGetImageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHandler, __DoCanRead, "DoCanRead")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, __DoCanRead)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->DoCanRead();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxImageHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ImageHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__ImageHandler);
	// Method assignment
	Gura_AssignMethod(wx_ImageHandler, __CanRead);
	Gura_AssignMethod(wx_ImageHandler, __CanRead_1);
	Gura_AssignMethod(wx_ImageHandler, __GetExtension);
	Gura_AssignMethod(wx_ImageHandler, __GetAltExtensions);
	Gura_AssignMethod(wx_ImageHandler, __GetImageCount);
	Gura_AssignMethod(wx_ImageHandler, __GetMimeType);
	Gura_AssignMethod(wx_ImageHandler, __GetName);
	Gura_AssignMethod(wx_ImageHandler, __GetType);
	Gura_AssignMethod(wx_ImageHandler, __LoadFile);
	Gura_AssignMethod(wx_ImageHandler, __SaveFile);
	Gura_AssignMethod(wx_ImageHandler, __SetExtension);
	Gura_AssignMethod(wx_ImageHandler, __SetAltExtensions);
	Gura_AssignMethod(wx_ImageHandler, __SetMimeType);
	Gura_AssignMethod(wx_ImageHandler, __SetName);
	Gura_AssignMethod(wx_ImageHandler, __GetLibraryVersionInfo);
	Gura_AssignMethod(wx_ImageHandler, __DoGetImageCount);
	Gura_AssignMethod(wx_ImageHandler, __DoCanRead);
}

Gura_ImplementDescendantCreator(wx_ImageHandler)
{
	return new Object_wx_ImageHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
