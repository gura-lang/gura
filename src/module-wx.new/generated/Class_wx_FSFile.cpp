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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FSFile, "FSFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "anchor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "modif", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FSFile));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FSFile)
{
	//wxInputStream* stream = arg.GetNumber(0)
	//const wxString& location = arg.GetNumber(1)
	//const wxString& mimetype = arg.GetNumber(2)
	//const wxString& anchor = arg.GetNumber(3)
	//wxDateTime modif = arg.GetNumber(4)
	//wxFSFile(stream, location, mimetype, anchor, modif);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FSFile, __DetachStream, "DetachStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __DetachStream)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream* _rtn = pThis->GetEntity()->DetachStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetAnchor, "GetAnchor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetAnchor)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetAnchor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetLocation, "GetLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetLocation)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetLocation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetMimeType, "GetMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetMimeType)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetModificationTime, "GetModificationTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetModificationTime)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDateTime _rtn = pThis->GetEntity()->GetModificationTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSFile, __GetStream, "GetStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FSFile, __GetStream)
{
	Object_wx_FSFile *pThis = Object_wx_FSFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream* _rtn = pThis->GetEntity()->GetStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFSFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FSFile)
{
	// Constructor assignment
	Gura_AssignFunction(__FSFile);
	// Method assignment
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
