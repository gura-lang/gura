//----------------------------------------------------------------------------
// wxXmlDocument
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlDocument
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlDocument
//----------------------------------------------------------------------------
Object_wx_XmlDocument::~Object_wx_XmlDocument()
{
}

Object *Object_wx_XmlDocument::Clone() const
{
	return nullptr;
}

String Object_wx_XmlDocument::ToString(bool exprFlag)
{
	String rtn("<wx.XmlDocument:");
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
Gura_DeclareMethodAlias(wx_XmlDocument, __wxXmlDocument, "wxXmlDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __wxXmlDocument)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __wxXmlDocument_1, "wxXmlDocument_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __wxXmlDocument_1)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//pThis->GetEntity()->wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __wxXmlDocument_2, "wxXmlDocument_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __wxXmlDocument_2)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//pThis->GetEntity()->wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __wxXmlDocument_3, "wxXmlDocument_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __wxXmlDocument_3)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//pThis->GetEntity()->wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __AppendToProlog, "AppendToProlog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __AppendToProlog)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->AppendToProlog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __DetachDocumentNode, "DetachDocumentNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __DetachDocumentNode)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DetachDocumentNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __DetachRoot, "DetachRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __DetachRoot)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DetachRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetEncoding, "GetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetEncoding)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetFileEncoding, "GetFileEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetFileEncoding)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetDoctype, "GetDoctype")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetDoctype)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDoctype();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetDocumentNode, "GetDocumentNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetDocumentNode)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetRoot, "GetRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetRoot)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetVersion)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __IsOk)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __Load)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __Load_1, "Load_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __Load_1)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indentstep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __Save)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int indentstep = arg.GetNumber(1)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __Save_1, "Save_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indentstep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __Save_1)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indentstep = arg.GetNumber(1)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __SetDocumentNode, "SetDocumentNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __SetDocumentNode)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __SetEncoding, "SetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __SetEncoding)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enc = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __SetFileEncoding, "SetFileEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __SetFileEncoding)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __SetDoctype, "SetDoctype")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doctype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __SetDoctype)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doctype = arg.GetNumber(0)
	//pThis->GetEntity()->SetDoctype();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __SetRoot, "SetRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __SetRoot)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->SetRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __SetVersion, "SetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "version", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __SetVersion)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int version = arg.GetNumber(0)
	//pThis->GetEntity()->SetVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetLibraryVersionInfo, "GetLibraryVersionInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetLibraryVersionInfo)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLibraryVersionInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlDocument
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlDocument)
{
	Gura_AssignMethod(wx_XmlDocument, __wxXmlDocument);
	Gura_AssignMethod(wx_XmlDocument, __wxXmlDocument_1);
	Gura_AssignMethod(wx_XmlDocument, __wxXmlDocument_2);
	Gura_AssignMethod(wx_XmlDocument, __wxXmlDocument_3);
	Gura_AssignMethod(wx_XmlDocument, __AppendToProlog);
	Gura_AssignMethod(wx_XmlDocument, __DetachDocumentNode);
	Gura_AssignMethod(wx_XmlDocument, __DetachRoot);
	Gura_AssignMethod(wx_XmlDocument, __GetEncoding);
	Gura_AssignMethod(wx_XmlDocument, __GetFileEncoding);
	Gura_AssignMethod(wx_XmlDocument, __GetDoctype);
	Gura_AssignMethod(wx_XmlDocument, __GetDocumentNode);
	Gura_AssignMethod(wx_XmlDocument, __GetRoot);
	Gura_AssignMethod(wx_XmlDocument, __GetVersion);
	Gura_AssignMethod(wx_XmlDocument, __IsOk);
	Gura_AssignMethod(wx_XmlDocument, __Load);
	Gura_AssignMethod(wx_XmlDocument, __Load_1);
	Gura_AssignMethod(wx_XmlDocument, __Save);
	Gura_AssignMethod(wx_XmlDocument, __Save_1);
	Gura_AssignMethod(wx_XmlDocument, __SetDocumentNode);
	Gura_AssignMethod(wx_XmlDocument, __SetEncoding);
	Gura_AssignMethod(wx_XmlDocument, __SetFileEncoding);
	Gura_AssignMethod(wx_XmlDocument, __SetDoctype);
	Gura_AssignMethod(wx_XmlDocument, __SetRoot);
	Gura_AssignMethod(wx_XmlDocument, __SetVersion);
	Gura_AssignMethod(wx_XmlDocument, __GetLibraryVersionInfo);
}

Gura_ImplementDescendantCreator(wx_XmlDocument)
{
	return new Object_wx_XmlDocument((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
