//----------------------------------------------------------------------------
// wxArchiveOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveOutputStream
//----------------------------------------------------------------------------
Object_wx_ArchiveOutputStream::~Object_wx_ArchiveOutputStream()
{
}

Object *Object_wx_ArchiveOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveOutputStream:");
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
Gura_DeclareMethodAlias(wx_ArchiveOutputStream, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveOutputStream, __Close)
{
	Object_wx_ArchiveOutputStream *pThis = Object_wx_ArchiveOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArchiveOutputStream, __CloseEntry, "CloseEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveOutputStream, __CloseEntry)
{
	Object_wx_ArchiveOutputStream *pThis = Object_wx_ArchiveOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArchiveOutputStream, __CopyArchiveMetaData, "CopyArchiveMetaData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveOutputStream, __CopyArchiveMetaData)
{
	Object_wx_ArchiveOutputStream *pThis = Object_wx_ArchiveOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArchiveInputStream& stream = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CopyArchiveMetaData(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArchiveOutputStream, __CopyEntry, "CopyEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveOutputStream, __CopyEntry)
{
	Object_wx_ArchiveOutputStream *pThis = Object_wx_ArchiveOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArchiveEntry* entry = arg.GetNumber(0)
	//wxArchiveInputStream& stream = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->CopyEntry(entry, stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArchiveOutputStream, __PutNextDirEntry, "PutNextDirEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveOutputStream, __PutNextDirEntry)
{
	Object_wx_ArchiveOutputStream *pThis = Object_wx_ArchiveOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxDateTime& dt = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->PutNextDirEntry(name, dt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArchiveOutputStream, __PutNextEntry, "PutNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveOutputStream, __PutNextEntry)
{
	Object_wx_ArchiveOutputStream *pThis = Object_wx_ArchiveOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArchiveEntry* entry = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->PutNextEntry(entry);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArchiveOutputStream, __PutNextEntry_1, "PutNextEntry_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveOutputStream, __PutNextEntry_1)
{
	Object_wx_ArchiveOutputStream *pThis = Object_wx_ArchiveOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxDateTime& dt = arg.GetNumber(1)
	//wxFileOffset size = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->PutNextEntry(name, dt, size);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveOutputStream)
{
	// Class assignment
	Gura_AssignValueEx("ArchiveOutputStream", Reference());
	// Method assignment
	Gura_AssignMethod(wx_ArchiveOutputStream, __Close);
	Gura_AssignMethod(wx_ArchiveOutputStream, __CloseEntry);
	Gura_AssignMethod(wx_ArchiveOutputStream, __CopyArchiveMetaData);
	Gura_AssignMethod(wx_ArchiveOutputStream, __CopyEntry);
	Gura_AssignMethod(wx_ArchiveOutputStream, __PutNextDirEntry);
	Gura_AssignMethod(wx_ArchiveOutputStream, __PutNextEntry);
	Gura_AssignMethod(wx_ArchiveOutputStream, __PutNextEntry_1);
}

Gura_ImplementDescendantCreator(wx_ArchiveOutputStream)
{
	return new Object_wx_ArchiveOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
