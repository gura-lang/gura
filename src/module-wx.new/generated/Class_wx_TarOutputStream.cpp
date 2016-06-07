//----------------------------------------------------------------------------
// wxTarOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTarOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Object_wx_TarOutputStream::~Object_wx_TarOutputStream()
{
}

Object *Object_wx_TarOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TarOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TarOutputStream:");
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
Gura_DeclareFunctionAlias(__TarOutputStream, "TarOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TarOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TarOutputStream)
{
	//wxOutputStream& stream = arg.GetNumber(0)
	//wxTarFormat format = arg.GetNumber(1)
	//wxMBConv& conv = arg.GetNumber(2)
	//wxTarOutputStream(stream, format, conv);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TarOutputStream_1, "TarOutputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TarOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TarOutputStream_1)
{
	//wxOutputStream* stream = arg.GetNumber(0)
	//wxTarFormat format = arg.GetNumber(1)
	//wxMBConv& conv = arg.GetNumber(2)
	//wxTarOutputStream(stream, format, conv);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TarOutputStream, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, __Close)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __CloseEntry, "CloseEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, __CloseEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __CopyArchiveMetaData, "CopyArchiveMetaData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __CopyArchiveMetaData)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTarInputStream& s = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CopyArchiveMetaData(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __CopyEntry, "CopyEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inputStream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __CopyEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTarEntry* entry = arg.GetNumber(0)
	//wxTarInputStream& inputStream = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->CopyEntry(entry, inputStream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __GetBlockingFactor, "GetBlockingFactor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, __GetBlockingFactor)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetBlockingFactor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __SetBlockingFactor, "SetBlockingFactor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __SetBlockingFactor)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int factor = arg.GetNumber(0)
	//pThis->GetEntity()->SetBlockingFactor(factor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __PutNextDirEntry, "PutNextDirEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __PutNextDirEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxDateTime& dt = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->PutNextDirEntry(name, dt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __PutNextEntry, "PutNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __PutNextEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTarEntry* entry = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->PutNextEntry(entry);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __PutNextEntry_1, "PutNextEntry_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __PutNextEntry_1)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxDateTime& dt = arg.GetNumber(1)
	//wxFileOffset size = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->PutNextEntry(name, dt, size);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__TarOutputStream);
	Gura_AssignFunction(__TarOutputStream_1);
	// Method assignment
	Gura_AssignMethod(wx_TarOutputStream, __Close);
	Gura_AssignMethod(wx_TarOutputStream, __CloseEntry);
	Gura_AssignMethod(wx_TarOutputStream, __CopyArchiveMetaData);
	Gura_AssignMethod(wx_TarOutputStream, __CopyEntry);
	Gura_AssignMethod(wx_TarOutputStream, __GetBlockingFactor);
	Gura_AssignMethod(wx_TarOutputStream, __SetBlockingFactor);
	Gura_AssignMethod(wx_TarOutputStream, __PutNextDirEntry);
	Gura_AssignMethod(wx_TarOutputStream, __PutNextEntry);
	Gura_AssignMethod(wx_TarOutputStream, __PutNextEntry_1);
}

Gura_ImplementDescendantCreator(wx_TarOutputStream)
{
	return new Object_wx_TarOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
