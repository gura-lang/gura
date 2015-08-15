//----------------------------------------------------------------------------
// wxXmlNode
// extracted from xmlnode.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_XmlNode: public wxXmlNode, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_XmlNode *_pObj;
public:
	//inline wx_XmlNode(wxXmlNode* parent, wxXmlNodeType type, const wxString& name, const wxString& content, wxXmlProperty* props, wxXmlNode* next) : wxXmlNode(parent, type, name, content, props, next), _pObj(nullptr) {}
	inline wx_XmlNode(const wxXmlNode& node) : wxXmlNode(node), _pObj(nullptr) {}
	inline wx_XmlNode(wxXmlNodeType type, const wxString& name, const wxString& content) : wxXmlNode(type, name, content), _pObj(nullptr) {}
	~wx_XmlNode();
	inline void AssocWithGura(Object_wx_XmlNode *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XmlNode::~wx_XmlNode()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_XmlNode::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlNode
//----------------------------------------------------------------------------
Gura_DeclareFunction(XmlNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_XmlNode));
	DeclareArg(env, "parent", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "content", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "props", VTYPE_wx_XmlProperty, OCCUR_ZeroOrOnce);
	DeclareArg(env, "next", VTYPE_wx_XmlNode, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(XmlNode)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxXmlNode *parent = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxXmlNodeType type = static_cast<wxXmlNodeType>(args.GetInt(1));
	wxString name = wxString::FromUTF8(args.GetString(2));
	wxString content = wxEmptyString;
	if (args.IsValid(3)) content = wxString::FromUTF8(args.GetString(3));
	wxXmlProperty *props = (wxXmlProperty *)();
	if (args.IsValid(4)) props = Object_wx_XmlProperty::GetObject(args, 4)->GetEntity();
	wxXmlNode *next = (wxXmlNode *)();
	if (args.IsValid(5)) next = Object_wx_XmlNode::GetObject(args, 5)->GetEntity();
	wx_XmlNode *pEntity = new wx_XmlNode(parent, type, name, content, props, next);
	Object_wx_XmlNode *pObj = Object_wx_XmlNode::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlNode(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(XmlNode_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_XmlNode));
	DeclareArg(env, "node", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlNode_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxXmlNode *node = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wx_XmlNode *pEntity = new wx_XmlNode(*node);
	Object_wx_XmlNode *pObj = Object_wx_XmlNode::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlNode(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(XmlNode_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_XmlNode));
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "content", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlNode_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxXmlNodeType type = static_cast<wxXmlNodeType>(args.GetInt(0));
	wxString name = wxString::FromUTF8(args.GetString(1));
	wxString content = wxEmptyString;
	if (args.IsValid(2)) content = wxString::FromUTF8(args.GetString(2));
	wx_XmlNode *pEntity = new wx_XmlNode(type, name, content);
	Object_wx_XmlNode *pObj = Object_wx_XmlNode::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlNode(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_XmlNode, AddChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_XmlNode, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, AddChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *child = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddChild(child);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, AddProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, AddProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->AddProperty(name, value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, AddProperty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prop", VTYPE_wx_XmlProperty, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, AddProperty_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlProperty *prop = Object_wx_XmlProperty::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddProperty(prop);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, DeleteProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, DeleteProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->DeleteProperty(name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, GetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->GetChildren();
	return ReturnValue(env, args, Value(new Object_wx_XmlNode(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlNode, GetContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetContent)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetContent();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlNode, GetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "grandparent", VTYPE_wx_XmlNode, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetDepth)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *grandparent = (wxXmlNode *)(nullptr);
	if (args.IsValid(0)) grandparent = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->GetDepth(grandparent);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, GetNodeContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetNodeContent)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetNodeContent();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlNode, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_XmlNode, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, args, Value(new Object_wx_XmlNode(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlNode, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *rtn = (wxXmlNode *)pThis->GetEntity()->GetParent();
	return ReturnValue(env, args, Value(new Object_wx_XmlNode(rtn, nullptr, OwnerFalse)));
}

#if 0
Gura_DeclareMethod(wx_XmlNode, GetPropVal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "propName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetPropVal)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString propName = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->GetPropVal(propName, value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, GetPropVal_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "propName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetPropVal_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString propName = wxString::FromUTF8(args.GetString(0));
	wxString defaultVal = wxString::FromUTF8(args.GetString(1));
	wxString rtn = pThis->GetEntity()->GetPropVal(propName, defaultVal);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}
#endif

Gura_DeclareMethod(wx_XmlNode, GetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlProperty *rtn = (wxXmlProperty *)pThis->GetEntity()->GetProperties();
	return ReturnValue(env, args, Value(new Object_wx_XmlProperty(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlNode, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, GetType)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNodeType rtn = pThis->GetEntity()->GetType();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, HasProp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "propName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, HasProp)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString propName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasProp(propName);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, InsertChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "followingNode", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, InsertChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *child = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxXmlNode *followingNode = Object_wx_XmlNode::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->InsertChild(child, followingNode);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, InsertChildAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareArg(env, "precedingNode", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, InsertChildAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *child = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	wxXmlNode *precedingNode = Object_wx_XmlNode::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->InsertChildAfter(child, precedingNode);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, IsWhitespaceOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, IsWhitespaceOnly)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsWhitespaceOnly();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, RemoveChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_XmlNode, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlNode, RemoveChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *child = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->RemoveChild(child);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_XmlNode, SetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "child", VTYPE_wx_XmlNode, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *child = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetChildren(child);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "con", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetContent)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString con = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetContent(con);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "next", VTYPE_wx_XmlNode, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *next = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNext(next);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_XmlNode, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNode *parent = Object_wx_XmlNode::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetParent(parent);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prop", VTYPE_wx_XmlProperty, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetProperties)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlProperty *prop = Object_wx_XmlProperty::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetProperties(prop);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetType)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlNodeType type = static_cast<wxXmlNodeType>(args.GetInt(0));
	pThis->GetEntity()->SetType(type);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxXmlNode
//----------------------------------------------------------------------------
Object_wx_XmlNode::~Object_wx_XmlNode()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_XmlNode::Clone() const
{
	return nullptr;
}

String Object_wx_XmlNode::ToString(bool exprFlag)
{
	String rtn("<wx.XmlNode:");
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
// Class implementation for wxXmlNode
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlNode)
{
	Gura_AssignFunction(XmlNode);
	Gura_AssignFunction(XmlNode_1);
	Gura_AssignFunction(XmlNode_2);
	Gura_AssignMethod(wx_XmlNode, AddChild);
	Gura_AssignMethod(wx_XmlNode, AddProperty);
	Gura_AssignMethod(wx_XmlNode, AddProperty_1);
	Gura_AssignMethod(wx_XmlNode, DeleteProperty);
	Gura_AssignMethod(wx_XmlNode, GetChildren);
	Gura_AssignMethod(wx_XmlNode, GetContent);
	Gura_AssignMethod(wx_XmlNode, GetDepth);
	Gura_AssignMethod(wx_XmlNode, GetNodeContent);
	Gura_AssignMethod(wx_XmlNode, GetName);
	Gura_AssignMethod(wx_XmlNode, GetNext);
	Gura_AssignMethod(wx_XmlNode, GetParent);
	//Gura_AssignMethod(wx_XmlNode, GetPropVal);
	//Gura_AssignMethod(wx_XmlNode, GetPropVal_1);
	Gura_AssignMethod(wx_XmlNode, GetProperties);
	Gura_AssignMethod(wx_XmlNode, GetType);
	Gura_AssignMethod(wx_XmlNode, HasProp);
	Gura_AssignMethod(wx_XmlNode, InsertChild);
	Gura_AssignMethod(wx_XmlNode, InsertChildAfter);
	Gura_AssignMethod(wx_XmlNode, IsWhitespaceOnly);
	Gura_AssignMethod(wx_XmlNode, RemoveChild);
	Gura_AssignMethod(wx_XmlNode, SetChildren);
	Gura_AssignMethod(wx_XmlNode, SetContent);
	Gura_AssignMethod(wx_XmlNode, SetName);
	Gura_AssignMethod(wx_XmlNode, SetNext);
	Gura_AssignMethod(wx_XmlNode, SetParent);
	Gura_AssignMethod(wx_XmlNode, SetProperties);
	Gura_AssignMethod(wx_XmlNode, SetType);
}

Gura_ImplementDescendantCreator(wx_XmlNode)
{
	return new Object_wx_XmlNode((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
