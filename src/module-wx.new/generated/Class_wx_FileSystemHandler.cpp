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
Gura_DeclareFunctionAlias(__FileSystemHandler, "FileSystemHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileSystemHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileSystemHandler)
{
	//wxFileSystemHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileSystemHandler, __CanOpen, "CanOpen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __CanOpen)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& location = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CanOpen(location);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __FindFirst, "FindFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __FindFirst)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& wildcard = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxString _rtn = pThis->GetEntity()->FindFirst(wildcard, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __FindNext, "FindNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemHandler, __FindNext)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->FindNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetMimeTypeFromExt, "GetMimeTypeFromExt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetMimeTypeFromExt)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& location = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetMimeTypeFromExt(location);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __OpenFile, "OpenFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "fs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __OpenFile)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFileSystem& fs = arg.GetNumber(0)
	//const wxString& location = arg.GetNumber(1)
	//wxFSFile* _rtn = pThis->GetEntity()->OpenFile(fs, location);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetAnchor, "GetAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetAnchor)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& location = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetAnchor(location);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetLeftLocation, "GetLeftLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetLeftLocation)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& location = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetLeftLocation(location);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetProtocol, "GetProtocol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetProtocol)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& location = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetProtocol(location);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileSystemHandler, __GetRightLocation, "GetRightLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, __GetRightLocation)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& location = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetRightLocation(location);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__FileSystemHandler);
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
