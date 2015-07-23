//----------------------------------------------------------------------------
// wxHtmlTagHandler
// extracted from httaghnd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetSupportedTags);
Gura_DeclarePrivUserSymbol(HandleTag);
Gura_DeclarePrivUserSymbol(SetParser);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlTagHandler: public wxHtmlTagHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlTagHandler *_pObj;
public:
	//inline wx_HtmlTagHandler() : wxHtmlTagHandler(), _pObj(nullptr) {}
	//virtual wxString GetSupportedTags();
	//virtual bool HandleTag(const wxHtmlTag& tag);
	//virtual void SetParser(wxHtmlParser *parser);
	~wx_HtmlTagHandler();
	inline void AssocWithGura(Object_wx_HtmlTagHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlTagHandler::~wx_HtmlTagHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlTagHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlTagHandlerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlTagHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlTagHandlerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_HtmlTagHandler *pEntity = new wx_HtmlTagHandler();
	Object_wx_HtmlTagHandler *pObj = Object_wx_HtmlTagHandler::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlTagHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlTagHandler, GetSupportedTags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTagHandler, GetSupportedTags)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetSupportedTags();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlTagHandler, HandleTag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tag", VTYPE_wx_HtmlTag, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlTagHandler, HandleTag)
{
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlTag *tag = Object_wx_HtmlTag::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->HandleTag(*tag);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlTagHandler, ParseInner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "tag", VTYPE_wx_HtmlTag, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlTagHandler, ParseInner)
{
#if 0
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlTag *tag = Object_wx_HtmlTag::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->ParseInner(*tag);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlTagHandler, SetParser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*parser", VTYPE_wx_HtmlParser, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlTagHandler, SetParser)
{
#if 0
	Object_wx_HtmlTagHandler *pThis = Object_wx_HtmlTagHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlParser **parser = Object_wx_HtmlParser::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetParser(**parser);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagHandler
//----------------------------------------------------------------------------
Object_wx_HtmlTagHandler::~Object_wx_HtmlTagHandler()
{
}

Object *Object_wx_HtmlTagHandler::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTagHandler::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTagHandler:");
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
// Class implementation for wxHtmlTagHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTagHandler)
{
	Gura_RealizeUserSymbol(GetSupportedTags);
	Gura_RealizeUserSymbol(HandleTag);
	Gura_RealizeUserSymbol(SetParser);
	Gura_AssignFunction(HtmlTagHandlerEmpty);
	Gura_AssignMethod(wx_HtmlTagHandler, GetSupportedTags);
	Gura_AssignMethod(wx_HtmlTagHandler, HandleTag);
	Gura_AssignMethod(wx_HtmlTagHandler, ParseInner);
	Gura_AssignMethod(wx_HtmlTagHandler, SetParser);
}

Gura_ImplementDescendantCreator(wx_HtmlTagHandler)
{
	return new Object_wx_HtmlTagHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
