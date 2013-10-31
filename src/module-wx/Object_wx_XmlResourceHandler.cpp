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
	Gura::Signal _sig;
	Object_wx_XmlResourceHandler *_pObj;
public:
	//inline wx_XmlResourceHandler() : wxXmlResourceHandler(), _sig(NULL), _pObj(NULL) {}
	~wx_XmlResourceHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_XmlResourceHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XmlResourceHandler::~wx_XmlResourceHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_XmlResourceHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlResourceHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(XmlResourceHandlerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_XmlResourceHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(XmlResourceHandlerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_XmlResourceHandler *pEntity = new wx_XmlResourceHandler();
	Object_wx_XmlResourceHandler *pObj = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_XmlResourceHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, AddStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, AddStyle)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	int value = args.GetInt(1);
	pThis->GetEntity()->AddStyle(name, value);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, AddWindowStyles)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, AddWindowStyles)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->AddWindowStyles();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CanHandle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CanHandle)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CanHandle(node);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateChildren)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "this_hnd_only", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateChildren)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxObject *parent = Object_wx_Object::GetObject(args, 0)->GetEntity();
	bool this_hnd_only = false;
	if (args.IsValid(1)) this_hnd_only = args.GetBoolean(1);
	pThis->GetEntity()->CreateChildren(parent, this_hnd_only);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateChildrenPrivately)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "rootnode", VTYPE_wx_XmlNode, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateChildrenPrivately)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxObject *parent = Object_wx_Object::GetObject(args, 0)->GetEntity();
	wxXmlNode *rootnode = (wxXmlNode *)(NULL);
	if (args.IsValid(1)) rootnode = Object_wx_XmlNode::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->CreateChildrenPrivately(parent, rootnode);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateResFromNode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "instance", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateResFromNode)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxObject *parent = Object_wx_Object::GetObject(args, 1)->GetEntity();
	wxObject *instance = (wxObject *)(NULL);
	if (args.IsValid(2)) instance = Object_wx_Object::GetObject(args, 2)->GetEntity();
	wxObject *rtn = (wxObject *)pThis->GetEntity()->CreateResFromNode(node, parent, instance);
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateResource)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "instance", VTYPE_wx_Object, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateResource)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxObject *parent = Object_wx_Object::GetObject(args, 1)->GetEntity();
	wxObject *instance = Object_wx_Object::GetObject(args, 2)->GetEntity();
	wxObject *rtn = (wxObject *)pThis->GetEntity()->CreateResource(node, parent, instance);
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, DoCreateResource)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, DoCreateResource)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxObject *rtn = (wxObject *)pThis->GetEntity()->DoCreateResource();
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetBitmap)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetBitmap)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxT("bitmap");
	if (args.IsValid(0)) param = wxString::FromUTF8(args.GetString(0));
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(1)) size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	wxBitmap rtn = pThis->GetEntity()->GetBitmap(param, *size);
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetBool)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultv", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetBool)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxString::FromUTF8(args.GetString(0));
	bool defaultv = false;
	if (args.IsValid(1)) defaultv = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->GetBool(param, defaultv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "default", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetColour)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxString::FromUTF8(args.GetString(0));
	wxColour *default = (wxColour *)(&wxNullColour);
	if (args.IsValid(1)) default = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxColour rtn = pThis->GetEntity()->GetColour(param, *default);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetCurFileSystem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetCurFileSystem)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileSystem &rtn = pThis->GetEntity()->GetCurFileSystem();
	return ReturnValue(env, sig, args, Value(new Object_wx_FileSystem(new wxFileSystem(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetDimension)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultv", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetDimension)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxString::FromUTF8(args.GetString(0));
	wxCoord defaultv = 0;
	if (args.IsValid(1)) defaultv = static_cast<wxCoord>(args.GetInt(1));
	wxCoord rtn = pThis->GetEntity()->GetDimension(param, defaultv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetFont)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxT("font");
	if (args.IsValid(0)) param = wxString::FromUTF8(args.GetString(0));
	wxFont rtn = pThis->GetEntity()->GetFont(param);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetID)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetID)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetID();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetIcon)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetIcon)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxT("icon");
	if (args.IsValid(0)) param = wxString::FromUTF8(args.GetString(0));
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(1)) size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	wxIcon rtn = pThis->GetEntity()->GetIcon(param, *size);
	return ReturnValue(env, sig, args, Value(new Object_wx_Icon(new wxIcon(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetLong)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultv", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetLong)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxString::FromUTF8(args.GetString(0));
	long defaultv = 0;
	if (args.IsValid(1)) defaultv = args.GetLong(1);
	long rtn = pThis->GetEntity()->GetLong(param, defaultv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetName)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetNodeContent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetNodeContent)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetNodeContent(node);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParamNode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParamNode)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxString::FromUTF8(args.GetString(0));
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->GetParamNode(param);
	return ReturnValue(env, sig, args, Value(new Object_wx_XmlNode(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParamValue)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParamValue)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetParamValue(param);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetPosition)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxT("pos");
	if (args.IsValid(0)) param = wxString::FromUTF8(args.GetString(0));
	wxPoint rtn = pThis->GetEntity()->GetPosition(param);
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetSize)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxT("size");
	if (args.IsValid(0)) param = wxString::FromUTF8(args.GetString(0));
	wxSize rtn = pThis->GetEntity()->GetSize(param);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaults", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetStyle)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxT("style");
	if (args.IsValid(0)) param = wxString::FromUTF8(args.GetString(0));
	int defaults = 0;
	if (args.IsValid(1)) defaults = args.GetInt(1);
	int rtn = pThis->GetEntity()->GetStyle(param, defaults);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetText)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetText(param);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, HasParam)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "param", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, HasParam)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString param = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasParam(param);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, IsOfClass)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "classname", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResourceHandler, IsOfClass)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxString classname = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->IsOfClass(node, classname);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, SetParentResource)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "res", VTYPE_wx_XmlResource, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, SetParentResource)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxXmlResource *res = Object_wx_XmlResource::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetParentResource(res);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_XmlResourceHandler, SetupWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "wnd", VTYPE_wx_Window, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_XmlResourceHandler, SetupWindow)
{
#if 0
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *wnd = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetupWindow(wnd);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxXmlResourceHandler
//----------------------------------------------------------------------------
Object_wx_XmlResourceHandler::~Object_wx_XmlResourceHandler()
{
}

Object *Object_wx_XmlResourceHandler::Clone() const
{
	return NULL;
}

String Object_wx_XmlResourceHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.XmlResourceHandler:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_XmlResourceHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
