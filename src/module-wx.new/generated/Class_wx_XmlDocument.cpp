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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__XmlDocument, "XmlDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XmlDocument));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlDocument)
{
	//wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__XmlDocument_1, "XmlDocument_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XmlDocument));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlDocument_1)
{
	//const wxXmlDocument& doc = arg.GetNumber(0)
	//wxXmlDocument(doc);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__XmlDocument_2, "XmlDocument_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XmlDocument));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlDocument_2)
{
	//const wxString& filename = arg.GetNumber(0)
	//const wxString& encoding = arg.GetNumber(1)
	//wxXmlDocument(filename, encoding);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__XmlDocument_3, "XmlDocument_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XmlDocument));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlDocument_3)
{
	//wxInputStream& stream = arg.GetNumber(0)
	//const wxString& encoding = arg.GetNumber(1)
	//wxXmlDocument(stream, encoding);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_XmlDocument, __AppendToProlog, "AppendToProlog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __AppendToProlog)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* node = arg.GetNumber(0)
	//pThis->GetEntity()->AppendToProlog(node);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __DetachDocumentNode, "DetachDocumentNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __DetachDocumentNode)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* _rtn = pThis->GetEntity()->DetachDocumentNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __DetachRoot, "DetachRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __DetachRoot)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* _rtn = pThis->GetEntity()->DetachRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetEncoding, "GetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetEncoding)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetFileEncoding, "GetFileEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetFileEncoding)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetFileEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetDoctype, "GetDoctype")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetDoctype)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxXmlDoctype& _rtn = pThis->GetEntity()->GetDoctype();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetDocumentNode, "GetDocumentNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetDocumentNode)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* _rtn = pThis->GetEntity()->GetDocumentNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetRoot, "GetRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetRoot)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* _rtn = pThis->GetEntity()->GetRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetVersion)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __IsOk)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __Load)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//const wxString& encoding = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->Load(filename, encoding, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __Load_1, "Load_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __Load_1)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream& stream = arg.GetNumber(0)
	//const wxString& encoding = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->Load(stream, encoding, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indentstep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __Save)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//int indentstep = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Save(filename, indentstep);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __Save_1, "Save_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indentstep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, __Save_1)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOutputStream& stream = arg.GetNumber(0)
	//int indentstep = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Save(stream, indentstep);
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
	//wxXmlNode* node = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentNode(node);
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
	//const wxString& enc = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding(enc);
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
	//const wxString& encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileEncoding(encoding);
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
	//const wxXmlDoctype& doctype = arg.GetNumber(0)
	//pThis->GetEntity()->SetDoctype(doctype);
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
	//wxXmlNode* node = arg.GetNumber(0)
	//pThis->GetEntity()->SetRoot(node);
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
	//const wxString& version = arg.GetNumber(0)
	//pThis->GetEntity()->SetVersion(version);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlDocument, __GetLibraryVersionInfo, "GetLibraryVersionInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, __GetLibraryVersionInfo)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVersionInfo _rtn = pThis->GetEntity()->GetLibraryVersionInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlDocument
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlDocument)
{
	// Constructor assignment
	Gura_AssignFunction(__XmlDocument);
	Gura_AssignFunction(__XmlDocument_1);
	Gura_AssignFunction(__XmlDocument_2);
	Gura_AssignFunction(__XmlDocument_3);
	// Method assignment
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
