//----------------------------------------------------------------------------
// wxXmlResourceHandler
// extracted from xmlresh.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_XmlResourceHandler: public wxXmlResourceHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_XmlResourceHandler *_pObj;
public:
	//inline wx_XmlResourceHandler() : wxXmlResourceHandler(), _pObj(nullptr) {}
	~wx_XmlResourceHandler();
	inline void AssocWithGura(Object_wx_XmlResourceHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XmlResourceHandler::~wx_XmlResourceHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_XmlResourceHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlResourceHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(XmlResourceHandlerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_XmlResourceHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(XmlResourceHandlerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_XmlResourceHandler *pEntity = new wx_XmlResourceHandler();
	Object_wx_XmlResourceHandler *pObj = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlResourceHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, AddStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, AddStyle)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	int value = arg.GetInt(1);
	pThis->GetEntity()->AddStyle(name, value);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, AddWindowStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, AddWindowStyles)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->AddWindowStyles();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CanHandle)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CanHandle(node);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "this_hnd_only", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateChildren)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *parent = Object_wx_Object::GetObject(arg, 0)->GetEntity();
	bool this_hnd_only = false;
	if (arg.IsValid(1)) this_hnd_only = arg.GetBoolean(1);
	pThis->GetEntity()->CreateChildren(parent, this_hnd_only);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateChildrenPrivately)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "rootnode", VTYPE_wx_XmlNode, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateChildrenPrivately)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *parent = Object_wx_Object::GetObject(arg, 0)->GetEntity();
	wxXmlNode *rootnode = (wxXmlNode *)(nullptr);
	if (arg.IsValid(1)) rootnode = Object_wx_XmlNode::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->CreateChildrenPrivately(parent, rootnode);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateResFromNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "instance", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateResFromNode)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxObject *parent = Object_wx_Object::GetObject(arg, 1)->GetEntity();
	wxObject *instance = (wxObject *)(nullptr);
	if (arg.IsValid(2)) instance = Object_wx_Object::GetObject(arg, 2)->GetEntity();
	wxObject *rtn = (wxObject *)pThis->GetEntity()->CreateResFromNode(node, parent, instance);
	return ReturnValue(env, arg, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "instance", VTYPE_wx_Object, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateResource)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxObject *parent = Object_wx_Object::GetObject(arg, 1)->GetEntity();
	wxObject *instance = Object_wx_Object::GetObject(arg, 2)->GetEntity();
	wxObject *rtn = (wxObject *)pThis->GetEntity()->CreateResource(node, parent, instance);
	return ReturnValue(env, arg, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, DoCreateResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, DoCreateResource)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxObject *rtn = (wxObject *)pThis->GetEntity()->DoCreateResource();
	return ReturnValue(env, arg, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetBitmap)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxT("bitmap");
	if (arg.IsValid(0)) param = wxString::FromUTF8(arg.GetString(0));
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(1)) size = Object_wx_Size::GetObject(arg, 1)->GetEntity();
	wxBitmap rtn = pThis->GetEntity()->GetBitmap(param, *size);
	return ReturnValue(env, arg, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultv", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetBool)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxString::FromUTF8(arg.GetString(0));
	bool defaultv = false;
	if (arg.IsValid(1)) defaultv = arg.GetBoolean(1);
	bool rtn = pThis->GetEntity()->GetBool(param, defaultv);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "default", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetColour)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxString::FromUTF8(arg.GetString(0));
	wxColour *default = (wxColour *)(&wxNullColour);
	if (arg.IsValid(1)) default = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	wxColour rtn = pThis->GetEntity()->GetColour(param, *default);
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetCurFileSystem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetCurFileSystem)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileSystem &rtn = pThis->GetEntity()->GetCurFileSystem();
	return ReturnValue(env, arg, Value(new Object_wx_FileSystem(new wxFileSystem(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetDimension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultv", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetDimension)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxString::FromUTF8(arg.GetString(0));
	wxCoord defaultv = 0;
	if (arg.IsValid(1)) defaultv = static_cast<wxCoord>(arg.GetInt(1));
	wxCoord rtn = pThis->GetEntity()->GetDimension(param, defaultv);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetFont)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxT("font");
	if (arg.IsValid(0)) param = wxString::FromUTF8(arg.GetString(0));
	wxFont rtn = pThis->GetEntity()->GetFont(param);
	return ReturnValue(env, arg, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetID)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetID();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetIcon)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxT("icon");
	if (arg.IsValid(0)) param = wxString::FromUTF8(arg.GetString(0));
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(1)) size = Object_wx_Size::GetObject(arg, 1)->GetEntity();
	wxIcon rtn = pThis->GetEntity()->GetIcon(param, *size);
	return ReturnValue(env, arg, Value(new Object_wx_Icon(new wxIcon(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultv", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetLong)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxString::FromUTF8(arg.GetString(0));
	long defaultv = 0;
	if (arg.IsValid(1)) defaultv = arg.GetLong(1);
	long rtn = pThis->GetEntity()->GetLong(param, defaultv);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetNodeContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetNodeContent)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetNodeContent(node);
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParamNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParamNode)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxString::FromUTF8(arg.GetString(0));
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->GetParamNode(param);
	return ReturnValue(env, arg, Value(new Object_wx_XmlNode(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParamValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParamValue)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetParamValue(param);
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetPosition)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxT("pos");
	if (arg.IsValid(0)) param = wxString::FromUTF8(arg.GetString(0));
	wxPoint rtn = pThis->GetEntity()->GetPosition(param);
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxT("size");
	if (arg.IsValid(0)) param = wxString::FromUTF8(arg.GetString(0));
	wxSize rtn = pThis->GetEntity()->GetSize(param);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaults", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetStyle)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxT("style");
	if (arg.IsValid(0)) param = wxString::FromUTF8(arg.GetString(0));
	int defaults = 0;
	if (arg.IsValid(1)) defaults = arg.GetInt(1);
	int rtn = pThis->GetEntity()->GetStyle(param, defaults);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetText)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetText(param);
	return ReturnValue(env, arg, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, HasParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, HasParam)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString param = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->HasParam(param);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, IsOfClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "classname", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, IsOfClass)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(arg, 0)->GetEntity();
	wxString classname = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->IsOfClass(node, classname);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, SetParentResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "res", VTYPE_wx_XmlResource, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, SetParentResource)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlResource *res = Object_wx_XmlResource::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetParentResource(res);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, SetupWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, SetupWindow)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *wnd = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetupWindow(wnd);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxXmlResourceHandler
//----------------------------------------------------------------------------
Object_wx_XmlResourceHandler::~Object_wx_XmlResourceHandler()
{
}

Object *Object_wx_XmlResourceHandler::Clone() const
{
	return nullptr;
}

String Object_wx_XmlResourceHandler::ToString(bool exprFlag)
{
	String rtn("<wx.XmlResourceHandler:");
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
// Class implementation for wxXmlResourceHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlResourceHandler)
{
	Gura_AssignFunction(XmlResourceHandlerEmpty);
	Gura_AssignMethod(wx_XmlResourceHandler, AddStyle);
	Gura_AssignMethod(wx_XmlResourceHandler, AddWindowStyles);
	Gura_AssignMethod(wx_XmlResourceHandler, CanHandle);
	Gura_AssignMethod(wx_XmlResourceHandler, CreateChildren);
	Gura_AssignMethod(wx_XmlResourceHandler, CreateChildrenPrivately);
	Gura_AssignMethod(wx_XmlResourceHandler, CreateResFromNode);
	Gura_AssignMethod(wx_XmlResourceHandler, CreateResource);
	Gura_AssignMethod(wx_XmlResourceHandler, DoCreateResource);
	Gura_AssignMethod(wx_XmlResourceHandler, GetBitmap);
	Gura_AssignMethod(wx_XmlResourceHandler, GetBool);
	Gura_AssignMethod(wx_XmlResourceHandler, GetColour);
	Gura_AssignMethod(wx_XmlResourceHandler, GetCurFileSystem);
	Gura_AssignMethod(wx_XmlResourceHandler, GetDimension);
	Gura_AssignMethod(wx_XmlResourceHandler, GetFont);
	Gura_AssignMethod(wx_XmlResourceHandler, GetID);
	Gura_AssignMethod(wx_XmlResourceHandler, GetIcon);
	Gura_AssignMethod(wx_XmlResourceHandler, GetLong);
	Gura_AssignMethod(wx_XmlResourceHandler, GetName);
	Gura_AssignMethod(wx_XmlResourceHandler, GetNodeContent);
	Gura_AssignMethod(wx_XmlResourceHandler, GetParamNode);
	Gura_AssignMethod(wx_XmlResourceHandler, GetParamValue);
	Gura_AssignMethod(wx_XmlResourceHandler, GetPosition);
	Gura_AssignMethod(wx_XmlResourceHandler, GetSize);
	Gura_AssignMethod(wx_XmlResourceHandler, GetStyle);
	Gura_AssignMethod(wx_XmlResourceHandler, GetText);
	Gura_AssignMethod(wx_XmlResourceHandler, HasParam);
	Gura_AssignMethod(wx_XmlResourceHandler, IsOfClass);
	Gura_AssignMethod(wx_XmlResourceHandler, SetParentResource);
	Gura_AssignMethod(wx_XmlResourceHandler, SetupWindow);
}

Gura_ImplementDescendantCreator(wx_XmlResourceHandler)
{
	return new Object_wx_XmlResourceHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
