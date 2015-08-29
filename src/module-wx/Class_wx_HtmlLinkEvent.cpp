//----------------------------------------------------------------------------
// wxHtmlLinkEvent
// extracted from htwindow.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlLinkEvent: public wxHtmlLinkEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlLinkEvent *_pObj;
public:
	~wx_HtmlLinkEvent();
	inline void AssocWithGura(Object_wx_HtmlLinkEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlLinkEvent::~wx_HtmlLinkEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlLinkEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlLinkEvent, wxHyperlinkEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "linkinfo", VTYPE_wx_HtmlLinkInfo, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlLinkEvent, wxHyperlinkEvent)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlLinkEvent *pThis = Object_wx_HtmlLinkEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = arg.GetInt(0);
	wxHtmlLinkInfo *linkinfo = Object_wx_HtmlLinkInfo::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->wxHyperlinkEvent(id, *linkinfo);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlLinkEvent, GetLinkInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkEvent, GetLinkInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlLinkEvent *pThis = Object_wx_HtmlLinkEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxHtmlLinkInfo &rtn = pThis->GetEntity()->GetLinkInfo();
	return ReturnValue(env, arg, Value(new Object_wx_HtmlLinkInfo(new wxHtmlLinkInfo(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Object_wx_HtmlLinkEvent::~Object_wx_HtmlLinkEvent()
{
}

Object *Object_wx_HtmlLinkEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlLinkEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlLinkEvent:");
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
// Class implementation for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlLinkEvent)
{
	Gura_AssignMethod(wx_HtmlLinkEvent, wxHyperlinkEvent);
	Gura_AssignMethod(wx_HtmlLinkEvent, GetLinkInfo);
}

Gura_ImplementDescendantCreator(wx_HtmlLinkEvent)
{
	return new Object_wx_HtmlLinkEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
