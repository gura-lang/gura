//----------------------------------------------------------------------------
// wxRichTextXMLHandler
// extracted from richtextxmlhandler.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextXMLHandler: public wxRichTextXMLHandler, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_RichTextXMLHandler *_pObj;
public:
	inline wx_RichTextXMLHandler(const wxString& name, const wxString& ext, int type) : wxRichTextXMLHandler(name, ext, type), _pSig(nullptr), _pObj(nullptr) {}
	~wx_RichTextXMLHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextXMLHandler *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextXMLHandler::~wx_RichTextXMLHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RichTextXMLHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextXMLHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextXMLHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextXMLHandler));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextXMLHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxT("XML");
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wxString ext = wxT("xml");
	if (args.IsValid(1)) ext = wxString::FromUTF8(args.GetString(1));
	int type = wxRICHTEXT_TYPE_XML;
	if (args.IsValid(2)) type = args.GetInt(2);
	wx_RichTextXMLHandler *pEntity = new wx_RichTextXMLHandler(name, ext, type);
	Object_wx_RichTextXMLHandler *pObj = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextXMLHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_RichTextXMLHandler, CanLoad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, CanLoad)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanLoad();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextXMLHandler, CanSave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, CanSave)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanSave();
	return ReturnValue(env, sig, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_RichTextXMLHandler, CreateStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareArg(env, "isPara", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, CreateStyle)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx *attr = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	bool isPara = false;
	if (args.IsValid(1)) isPara = args.GetBoolean(1);
	wxString rtn = pThis->GetEntity()->CreateStyle(*attr, isPara);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}
#endif

Gura_DeclareMethod(wx_RichTextXMLHandler, DoLoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, DoLoadFile)
{
#if 0
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoLoadFile(buffer, *stream);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, DoSaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, DoSaveFile)
{
#if 0
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoSaveFile(buffer, *stream);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, ExportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "obj", VTYPE_wx_RichTextObject, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, ExportXML)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxRichTextObject *obj = Object_wx_RichTextObject::GetObject(args, 1)->GetEntity();
	int level = args.GetInt(2);
	bool rtn = pThis->GetEntity()->ExportXML(*stream, *obj, level);
	return ReturnValue(env, sig, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_RichTextXMLHandler, GetNodeContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, GetNodeContent)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetNodeContent(node);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}
#endif

#if 0
Gura_DeclareMethod(wx_RichTextXMLHandler, GetParamNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, GetParamNode)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxString param = wxString::FromUTF8(args.GetString(1));
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->GetParamNode(node, param);
	return ReturnValue(env, sig, args, Value(new Object_wx_XmlNode(rtn, nullptr, OwnerFalse)));
}
#endif

#if 0
Gura_DeclareMethod(wx_RichTextXMLHandler, GetParamValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, GetParamValue)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxString param = wxString::FromUTF8(args.GetString(1));
	wxString rtn = pThis->GetEntity()->GetParamValue(node, param);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}
#endif

#if 0
Gura_DeclareMethod(wx_RichTextXMLHandler, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "isPara", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, GetStyle)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextAttrEx *attr = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 1)->GetEntity();
	bool isPara = false;
	if (args.IsValid(2)) isPara = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->GetStyle(*attr, node, isPara);
	return ReturnValue(env, sig, args, Value(rtn));
}
#endif

#if 0
Gura_DeclareMethod(wx_RichTextXMLHandler, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "translate", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, GetText)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxString param = wxEmptyString;
	if (args.IsValid(1)) param = wxString::FromUTF8(args.GetString(1));
	bool translate = false;
	if (args.IsValid(2)) translate = args.GetBoolean(2);
	wxString rtn = pThis->GetEntity()->GetText(node, param, translate);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}
#endif

#if 0
Gura_DeclareMethod(wx_RichTextXMLHandler, HasParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, HasParam)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxString param = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->HasParam(node, param);
	return ReturnValue(env, sig, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_RichTextXMLHandler, ImportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buffer", VTYPE_wx_RichTextBuffer, OCCUR_Once);
	DeclareArg(env, "obj", VTYPE_wx_RichTextObject, OCCUR_Once);
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, ImportXML)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(args, 0)->GetEntity();
	wxRichTextObject *obj = Object_wx_RichTextObject::GetObject(args, 1)->GetEntity();
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->ImportXML(buffer, obj, node);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextXMLHandler
//----------------------------------------------------------------------------
Object_wx_RichTextXMLHandler::~Object_wx_RichTextXMLHandler()
{
}

Object *Object_wx_RichTextXMLHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextXMLHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextXMLHandler:");
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
// Class implementation for wxRichTextXMLHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextXMLHandler)
{
	Gura_AssignFunction(RichTextXMLHandler);
	Gura_AssignMethod(wx_RichTextXMLHandler, CanLoad);
	Gura_AssignMethod(wx_RichTextXMLHandler, CanSave);
	//Gura_AssignMethod(wx_RichTextXMLHandler, CreateStyle);
	Gura_AssignMethod(wx_RichTextXMLHandler, DoLoadFile);
	Gura_AssignMethod(wx_RichTextXMLHandler, DoSaveFile);
	Gura_AssignMethod(wx_RichTextXMLHandler, ExportXML);
	//Gura_AssignMethod(wx_RichTextXMLHandler, GetNodeContent);
	//Gura_AssignMethod(wx_RichTextXMLHandler, GetParamNode);
	//Gura_AssignMethod(wx_RichTextXMLHandler, GetParamValue);
	//Gura_AssignMethod(wx_RichTextXMLHandler, GetStyle);
	//Gura_AssignMethod(wx_RichTextXMLHandler, GetText);
	//Gura_AssignMethod(wx_RichTextXMLHandler, HasParam);
	Gura_AssignMethod(wx_RichTextXMLHandler, ImportXML);
}

Gura_ImplementDescendantCreator(wx_RichTextXMLHandler)
{
	return new Object_wx_RichTextXMLHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
