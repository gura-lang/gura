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
	//Gura::Signal *_pSig;
	Object_wx_RichTextXMLHandler *_pObj;
public:
	inline wx_RichTextXMLHandler(const wxString& name, const wxString& ext, int type) : wxRichTextXMLHandler(name, ext, type), _pObj(nullptr) {}
	~wx_RichTextXMLHandler();
	inline void AssocWithGura(Object_wx_RichTextXMLHandler *pObj) {
		_pObj = pObj;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxT("XML");
	if (arg.IsValid(0)) name = wxString::FromUTF8(arg.GetString(0));
	wxString ext = wxT("xml");
	if (arg.IsValid(1)) ext = wxString::FromUTF8(arg.GetString(1));
	int type = wxRICHTEXT_TYPE_XML;
	if (arg.IsValid(2)) type = arg.GetInt(2);
	wx_RichTextXMLHandler *pEntity = new wx_RichTextXMLHandler(name, ext, type);
	Object_wx_RichTextXMLHandler *pObj = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RichTextXMLHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RichTextXMLHandler, CanLoad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, CanLoad)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanLoad();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextXMLHandler, CanSave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, CanSave)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanSave();
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextAttrEx *attr = Object_wx_TextAttrEx::GetObject(arg, 0)->GetEntity();
	bool isPara = false;
	if (arg.IsValid(1)) isPara = arg.GetBoolean(1);
	wxString rtn = pThis->GetEntity()->CreateStyle(*attr, isPara);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(arg, 0)->GetEntity();
	wxInputStream *stream = Object_wx_InputStream::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoLoadFile(buffer, *stream);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(arg, 0)->GetEntity();
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->DoSaveFile(buffer, *stream);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(arg, 0)->GetEntity();
	wxRichTextObject *obj = Object_wx_RichTextObject::GetObject(arg, 1)->GetEntity();
	int level = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->ExportXML(*stream, *obj, level);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetNodeContent(node);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxString param = wxString::FromUTF8(arg.GetString(1));
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->GetParamNode(node, param);
	return ReturnValue(env, arg, Value(new Object_wx_XmlNode(rtn, nullptr, OwnerFalse)));
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxString param = wxString::FromUTF8(arg.GetString(1));
	wxString rtn = pThis->GetEntity()->GetParamValue(node, param);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextAttrEx *attr = Object_wx_TextAttrEx::GetObject(arg, 0)->GetEntity();
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 1)->GetEntity();
	bool isPara = false;
	if (arg.IsValid(2)) isPara = arg.GetBoolean(2);
	bool rtn = pThis->GetEntity()->GetStyle(*attr, node, isPara);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxString param = wxEmptyString;
	if (arg.IsValid(1)) param = wxString::FromUTF8(arg.GetString(1));
	bool translate = false;
	if (arg.IsValid(2)) translate = arg.GetBoolean(2);
	wxString rtn = pThis->GetEntity()->GetText(node, param, translate);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxString param = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->HasParam(node, param);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRichTextBuffer *buffer = Object_wx_RichTextBuffer::GetObject(arg, 0)->GetEntity();
	wxRichTextObject *obj = Object_wx_RichTextObject::GetObject(arg, 1)->GetEntity();
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->ImportXML(buffer, obj, node);
	return ReturnValue(env, arg, Value(rtn));
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
