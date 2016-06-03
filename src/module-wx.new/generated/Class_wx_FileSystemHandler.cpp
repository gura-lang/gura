//----------------------------------------------------------------------------
// wxFileSystemHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystemHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Object_wx_FileSystemHandler::~Object_wx_FileSystemHandler()
{
}

Object *Object_wx_FileSystemHandler::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystemHandler::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystemHandler:");
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
Gura_DeclareFunctionAlias(__wxFileSystemHandler, "wxFileSystemHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxFileSystemHandler)
{
	//wxFileSystemHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileSystemHandler, __CanOpen, "CanOpen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __CanOpen)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->CanOpen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __FindFirst, "FindFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __FindFirst)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wildcard = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->FindFirst();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __FindNext, "FindNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemHandler, __FindNext)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FindNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetMimeTypeFromExt, "GetMimeTypeFromExt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetMimeTypeFromExt)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetMimeTypeFromExt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __OpenFile, "OpenFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __OpenFile)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fs = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//pThis->GetEntity()->OpenFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetAnchor, "GetAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetAnchor)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetLeftLocation, "GetLeftLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetLeftLocation)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetLeftLocation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetProtocol, "GetProtocol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetProtocol)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetProtocol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetRightLocation, "GetRightLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetRightLocation)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetRightLocation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFileSystemHandler);
	// Method assignment
	Gura_AssignMethod(wx_FileSystemHandler, __CanOpen);
	Gura_AssignMethod(wx_FileSystemHandler, __FindFirst);
	Gura_AssignMethod(wx_FileSystemHandler, __FindNext);
	Gura_AssignMethod(wx_FileSystemHandler, __GetMimeTypeFromExt);
	Gura_AssignMethod(wx_FileSystemHandler, __OpenFile);
	Gura_AssignMethod(wx_FileSystemHandler, __GetAnchor);
	Gura_AssignMethod(wx_FileSystemHandler, __GetLeftLocation);
	Gura_AssignMethod(wx_FileSystemHandler, __GetProtocol);
	Gura_AssignMethod(wx_FileSystemHandler, __GetRightLocation);
}

Gura_ImplementDescendantCreator(wx_FileSystemHandler)
{
	return new Object_wx_FileSystemHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
