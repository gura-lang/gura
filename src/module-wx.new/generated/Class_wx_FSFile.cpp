//----------------------------------------------------------------------------
// wxFSFile
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFSFile
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFSFile
//----------------------------------------------------------------------------
Object_wx_FSFile::~Object_wx_FSFile()
{
}

Object *Object_wx_FSFile::Clone() const
{
	return nullptr;
}

String Object_wx_FSFile::ToString(bool exprFlag)
{
	String rtn("<wx.FSFile:");
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
Gura_DeclareMethodAlias(wx_FSFile, __wxFSFile, "wxFSFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modif", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSFile, __wxFSFile)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//int mimetype = arg.GetNumber(2)
	//int anchor = arg.GetNumber(3)
	//int modif = arg.GetNumber(4)
	//pThis->GetEntity()->wxFSFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __DetachStream, "DetachStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __DetachStream)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DetachStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetAnchor, "GetAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetAnchor)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetLocation, "GetLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetLocation)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLocation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetMimeType, "GetMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetMimeType)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetModificationTime, "GetModificationTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetModificationTime)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModificationTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetStream, "GetStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetStream)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFSFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FSFile)
{
	Gura_AssignMethod(wx_FSFile, __wxFSFile);
	Gura_AssignMethod(wx_FSFile, __DetachStream);
	Gura_AssignMethod(wx_FSFile, __GetAnchor);
	Gura_AssignMethod(wx_FSFile, __GetLocation);
	Gura_AssignMethod(wx_FSFile, __GetMimeType);
	Gura_AssignMethod(wx_FSFile, __GetModificationTime);
	Gura_AssignMethod(wx_FSFile, __GetStream);
}

Gura_ImplementDescendantCreator(wx_FSFile)
{
	return new Object_wx_FSFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
