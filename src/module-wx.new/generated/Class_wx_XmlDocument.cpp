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
Gura_DeclareMethod(wx_XmlDocument, wxXmlDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, wxXmlDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, wxXmlDocument_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, wxXmlDocument_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//pThis->GetEntity()->wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, wxXmlDocument_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, wxXmlDocument_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//pThis->GetEntity()->wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, wxXmlDocument_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, wxXmlDocument_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//pThis->GetEntity()->wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, ~wxXmlDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, ~wxXmlDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxXmlDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, AppendToProlog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, AppendToProlog)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->AppendToProlog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, DetachDocumentNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, DetachDocumentNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DetachDocumentNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, DetachRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, DetachRoot)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DetachRoot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, GetEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, GetFileEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, GetFileEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFileEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, GetDoctype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, GetDoctype)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDoctype();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, GetDocumentNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, GetDocumentNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, GetRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, GetRoot)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRoot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, GetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, GetVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, Load)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, Load_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, Load_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int encoding = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indentstep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, Save)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int indentstep = arg.GetNumber(1)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, Save_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indentstep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, Save_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indentstep = arg.GetNumber(1)
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, SetDocumentNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetDocumentNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, SetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enc = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, SetFileEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetFileEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, SetDoctype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doctype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetDoctype)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doctype = arg.GetNumber(0)
	//pThis->GetEntity()->SetDoctype();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, SetRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetRoot)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->SetRoot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, SetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "version", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int version = arg.GetNumber(0)
	//pThis->GetEntity()->SetVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlDocument, GetLibraryVersionInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlDocument, GetLibraryVersionInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLibraryVersionInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlDocument
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlDocument)
{
	Gura_AssignMethod(wx_XmlDocument, wxXmlDocument);
	Gura_AssignMethod(wx_XmlDocument, wxXmlDocument_1);
	Gura_AssignMethod(wx_XmlDocument, wxXmlDocument_2);
	Gura_AssignMethod(wx_XmlDocument, wxXmlDocument_3);
	Gura_AssignMethod(wx_XmlDocument, ~wxXmlDocument);
	Gura_AssignMethod(wx_XmlDocument, AppendToProlog);
	Gura_AssignMethod(wx_XmlDocument, DetachDocumentNode);
	Gura_AssignMethod(wx_XmlDocument, DetachRoot);
	Gura_AssignMethod(wx_XmlDocument, GetEncoding);
	Gura_AssignMethod(wx_XmlDocument, GetFileEncoding);
	Gura_AssignMethod(wx_XmlDocument, GetDoctype);
	Gura_AssignMethod(wx_XmlDocument, GetDocumentNode);
	Gura_AssignMethod(wx_XmlDocument, GetRoot);
	Gura_AssignMethod(wx_XmlDocument, GetVersion);
	Gura_AssignMethod(wx_XmlDocument, IsOk);
	Gura_AssignMethod(wx_XmlDocument, Load);
	Gura_AssignMethod(wx_XmlDocument, Load_1);
	Gura_AssignMethod(wx_XmlDocument, Save);
	Gura_AssignMethod(wx_XmlDocument, Save_1);
	Gura_AssignMethod(wx_XmlDocument, SetDocumentNode);
	Gura_AssignMethod(wx_XmlDocument, SetEncoding);
	Gura_AssignMethod(wx_XmlDocument, SetFileEncoding);
	Gura_AssignMethod(wx_XmlDocument, SetDoctype);
	Gura_AssignMethod(wx_XmlDocument, SetRoot);
	Gura_AssignMethod(wx_XmlDocument, SetVersion);
	Gura_AssignMethod(wx_XmlDocument, GetLibraryVersionInfo);
}

Gura_ImplementDescendantCreator(wx_XmlDocument)
{
	return new Object_wx_XmlDocument((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
