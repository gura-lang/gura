//----------------------------------------------------------------------------
// wxXmlDocument
// extracted from xmldocument.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_XmlDocument: public wxXmlDocument, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_XmlDocument *_pObj;
public:
	inline wx_XmlDocument() : wxXmlDocument(), _pSig(nullptr), _pObj(nullptr) {}
	//inline wx_XmlDocument(const wxString& filename, const wxString& encoding, int flags) : wxXmlDocument(filename, encoding, flags), _pSig(nullptr), _pObj(nullptr) {}
	//inline wx_XmlDocument(wxInputStream& stream, const wxString& encoding, int flags) : wxXmlDocument(stream, encoding, flags), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_XmlDocument(const wxXmlDocument& doc) : wxXmlDocument(doc), _pSig(nullptr), _pObj(nullptr) {}
	~wx_XmlDocument();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_XmlDocument *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XmlDocument::~wx_XmlDocument()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_XmlDocument::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlDocument
//----------------------------------------------------------------------------
Gura_DeclareFunction(XmlDocumentEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XmlDocument));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlDocumentEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_XmlDocument *pEntity = new wx_XmlDocument();
	Object_wx_XmlDocument *pObj = Object_wx_XmlDocument::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlDocument(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(XmlDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_XmlDocument));
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(XmlDocument)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString encoding = wxT("UTF-8");
	if (args.IsValid(1)) encoding = wxString::FromUTF8(args.GetString(1));
	int flags = wxXMLDOC_NONE;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wx_XmlDocument *pEntity = new wx_XmlDocument(filename, encoding, flags);
	Object_wx_XmlDocument *pObj = Object_wx_XmlDocument::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlDocument(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(XmlDocument_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_XmlDocument));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(XmlDocument_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxString encoding = wxT("UTF-8");
	if (args.IsValid(1)) encoding = wxString::FromUTF8(args.GetString(1));
	int flags = wxXMLDOC_NONE;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wx_XmlDocument *pEntity = new wx_XmlDocument(*stream, encoding, flags);
	Object_wx_XmlDocument *pObj = Object_wx_XmlDocument::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlDocument(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(XmlDocument_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_XmlDocument));
	DeclareArg(env, "doc", VTYPE_wx_XmlDocument, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlDocument_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxXmlDocument *doc = Object_wx_XmlDocument::GetObject(args, 0)->GetEntity();
	wx_XmlDocument *pEntity = new wx_XmlDocument(*doc);
	Object_wx_XmlDocument *pObj = Object_wx_XmlDocument::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlDocument(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_XmlDocument, DetachRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, DetachRoot)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->DetachRoot();
	return ReturnValue(env, args, Value(new Object_wx_XmlNode(rtn, nullptr, OwnerFalse)));
}

#if 0
Gura_DeclareMethod(wx_XmlDocument, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, GetEncoding)
{
#if defined(__WXMSW__)
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetEncoding();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}
#endif

Gura_DeclareMethod(wx_XmlDocument, GetFileEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, GetFileEncoding)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFileEncoding();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlDocument, GetRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, GetRoot)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->GetRoot();
	return ReturnValue(env, args, Value(new Object_wx_XmlNode(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlDocument, GetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, GetVersion)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetVersion();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlDocument, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, IsOk)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlDocument, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, Load)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString encoding = wxT("UTF-8");
	if (args.IsValid(1)) encoding = wxString::FromUTF8(args.GetString(1));
	int flags = wxXMLDOC_NONE;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Load(filename, encoding, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlDocument, Load_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, Load_1)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxString encoding = wxT("UTF-8");
	if (args.IsValid(1)) encoding = wxString::FromUTF8(args.GetString(1));
	int flags = wxXMLDOC_NONE;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Load(*stream, encoding, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlDocument, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "indentstep", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, Save)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int indentstep = 1;
	if (args.IsValid(1)) indentstep = args.GetInt(1);
	bool rtn = pThis->GetEntity()->Save(filename, indentstep);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlDocument, Save_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "indentstep", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlDocument, Save_1)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	int indentstep = 1;
	if (args.IsValid(1)) indentstep = args.GetInt(1);
	bool rtn = pThis->GetEntity()->Save(*stream, indentstep);
	return ReturnValue(env, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_XmlDocument, SetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enc", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetEncoding)
{
#if defined(__WXMSW__)
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString enc = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetEncoding(enc);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}
#endif

Gura_DeclareMethod(wx_XmlDocument, SetFileEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetFileEncoding)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString encoding = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetFileEncoding(encoding);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlDocument, SetRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetRoot)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetRoot(node);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlDocument, SetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "version", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlDocument, SetVersion)
{
	Object_wx_XmlDocument *pThis = Object_wx_XmlDocument::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString version = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetVersion(version);
	return Value::Null;
}

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
// Class implementation for wxXmlDocument
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlDocument)
{
	Gura_AssignFunction(XmlDocumentEmpty);
	Gura_AssignFunction(XmlDocument);
	Gura_AssignFunction(XmlDocument_1);
	Gura_AssignFunction(XmlDocument_2);
	Gura_AssignMethod(wx_XmlDocument, DetachRoot);
	//Gura_AssignMethod(wx_XmlDocument, GetEncoding);
	Gura_AssignMethod(wx_XmlDocument, GetFileEncoding);
	Gura_AssignMethod(wx_XmlDocument, GetRoot);
	Gura_AssignMethod(wx_XmlDocument, GetVersion);
	Gura_AssignMethod(wx_XmlDocument, IsOk);
	Gura_AssignMethod(wx_XmlDocument, Load);
	Gura_AssignMethod(wx_XmlDocument, Load_1);
	Gura_AssignMethod(wx_XmlDocument, Save);
	Gura_AssignMethod(wx_XmlDocument, Save_1);
	//Gura_AssignMethod(wx_XmlDocument, SetEncoding);
	Gura_AssignMethod(wx_XmlDocument, SetFileEncoding);
	Gura_AssignMethod(wx_XmlDocument, SetRoot);
	Gura_AssignMethod(wx_XmlDocument, SetVersion);
}

Gura_ImplementDescendantCreator(wx_XmlDocument)
{
	return new Object_wx_XmlDocument((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
