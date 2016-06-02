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
Gura_DeclareMethod(wx_FSFile, wxFSFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modif", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSFile, wxFSFile)
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

Gura_DeclareMethod(wx_FSFile, DetachStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, DetachStream)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DetachStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSFile, GetAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, GetAnchor)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAnchor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSFile, GetLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, GetLocation)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLocation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSFile, GetMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, GetMimeType)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSFile, GetModificationTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, GetModificationTime)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetModificationTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSFile, GetStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, GetStream)
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
	Gura_AssignMethod(wx_FSFile, wxFSFile);
	Gura_AssignMethod(wx_FSFile, DetachStream);
	Gura_AssignMethod(wx_FSFile, GetAnchor);
	Gura_AssignMethod(wx_FSFile, GetLocation);
	Gura_AssignMethod(wx_FSFile, GetMimeType);
	Gura_AssignMethod(wx_FSFile, GetModificationTime);
	Gura_AssignMethod(wx_FSFile, GetStream);
}

Gura_ImplementDescendantCreator(wx_FSFile)
{
	return new Object_wx_FSFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
