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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ImageHandler, wxImageHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, wxImageHandler)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxImageHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, CanRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, CanRead)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->CanRead();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, CanRead_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, CanRead_1)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->CanRead();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, GetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, GetExtension)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, GetAltExtensions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, GetAltExtensions)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAltExtensions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, GetImageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, GetImageCount)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->GetImageCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, GetMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, GetMimeType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, GetName)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, GetType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "verbose", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, LoadFile)
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

Gura_DeclareMethod(wx_ImageHandler, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "verbose", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SaveFile)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//int verbose = arg.GetNumber(2)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, SetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SetExtension)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extension = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, SetAltExtensions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extensions", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SetAltExtensions)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extensions = arg.GetNumber(0)
	//pThis->GetEntity()->SetAltExtensions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, SetMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SetMimeType)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mimetype = arg.GetNumber(0)
	//pThis->GetEntity()->SetMimeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, SetName)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, GetLibraryVersionInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ImageHandler, GetLibraryVersionInfo)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLibraryVersionInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, DoGetImageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, DoGetImageCount)
{
	Object_wx_ImageHandler *pThis = Object_wx_ImageHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->DoGetImageCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ImageHandler, DoCanRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHandler, DoCanRead)
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
	Gura_AssignMethod(wx_ImageHandler, wxImageHandler);
	Gura_AssignMethod(wx_ImageHandler, CanRead);
	Gura_AssignMethod(wx_ImageHandler, CanRead_1);
	Gura_AssignMethod(wx_ImageHandler, GetExtension);
	Gura_AssignMethod(wx_ImageHandler, GetAltExtensions);
	Gura_AssignMethod(wx_ImageHandler, GetImageCount);
	Gura_AssignMethod(wx_ImageHandler, GetMimeType);
	Gura_AssignMethod(wx_ImageHandler, GetName);
	Gura_AssignMethod(wx_ImageHandler, GetType);
	Gura_AssignMethod(wx_ImageHandler, LoadFile);
	Gura_AssignMethod(wx_ImageHandler, SaveFile);
	Gura_AssignMethod(wx_ImageHandler, SetExtension);
	Gura_AssignMethod(wx_ImageHandler, SetAltExtensions);
	Gura_AssignMethod(wx_ImageHandler, SetMimeType);
	Gura_AssignMethod(wx_ImageHandler, SetName);
	Gura_AssignMethod(wx_ImageHandler, GetLibraryVersionInfo);
	Gura_AssignMethod(wx_ImageHandler, DoGetImageCount);
	Gura_AssignMethod(wx_ImageHandler, DoCanRead);
}

Gura_ImplementDescendantCreator(wx_ImageHandler)
{
	return new Object_wx_ImageHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
