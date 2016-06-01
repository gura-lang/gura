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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FileSystemHandler, wxFileSystemHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemHandler, wxFileSystemHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFileSystemHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, CanOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, CanOpen)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->CanOpen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, FindFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, FindFirst)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int wildcard = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->FindFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, FindNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileSystemHandler, FindNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FindNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetMimeTypeFromExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetMimeTypeFromExt)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetMimeTypeFromExt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, OpenFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, OpenFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fs = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//pThis->GetEntity()->OpenFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetAnchor)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetLeftLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetLeftLocation)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetLeftLocation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetProtocol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetProtocol)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetProtocol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetRightLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetRightLocation)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->GetRightLocation();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemHandler)
{
	Gura_AssignMethod(wx_FileSystemHandler, wxFileSystemHandler);
	Gura_AssignMethod(wx_FileSystemHandler, CanOpen);
	Gura_AssignMethod(wx_FileSystemHandler, FindFirst);
	Gura_AssignMethod(wx_FileSystemHandler, FindNext);
	Gura_AssignMethod(wx_FileSystemHandler, GetMimeTypeFromExt);
	Gura_AssignMethod(wx_FileSystemHandler, OpenFile);
	Gura_AssignMethod(wx_FileSystemHandler, GetAnchor);
	Gura_AssignMethod(wx_FileSystemHandler, GetLeftLocation);
	Gura_AssignMethod(wx_FileSystemHandler, GetProtocol);
	Gura_AssignMethod(wx_FileSystemHandler, GetRightLocation);
}

Gura_ImplementDescendantCreator(wx_FileSystemHandler)
{
	return new Object_wx_FileSystemHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
