//----------------------------------------------------------------------------
// wxHtmlLinkInfo
// extracted from htlnkinf.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlLinkInfo: public wxHtmlLinkInfo, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlLinkInfo *_pObj;
public:
	inline wx_HtmlLinkInfo() : wxHtmlLinkInfo(), _pObj(nullptr) {}
	inline wx_HtmlLinkInfo(const wxString& href, const wxString& target) : wxHtmlLinkInfo(href, target), _pObj(nullptr) {}
	~wx_HtmlLinkInfo();
	inline void AssocWithGura(Object_wx_HtmlLinkInfo *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlLinkInfo::~wx_HtmlLinkInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlLinkInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlLinkInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlLinkInfoEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlLinkInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlLinkInfoEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_HtmlLinkInfo *pEntity = new wx_HtmlLinkInfo();
	Object_wx_HtmlLinkInfo *pObj = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlLinkInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(HtmlLinkInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlLinkInfo));
	DeclareArg(env, "href", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "target", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlLinkInfo)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString href = wxString::FromUTF8(args.GetString(0));
	wxString target = wxEmptyString;
	if (args.IsValid(1)) target = wxString::FromUTF8(args.GetString(1));
	wx_HtmlLinkInfo *pEntity = new wx_HtmlLinkInfo(href, target);
	Object_wx_HtmlLinkInfo *pObj = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlLinkInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_HtmlLinkInfo, GetEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, GetEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMouseEvent *rtn = (wxMouseEvent *)pThis->GetEntity()->GetEvent();
	return ReturnValue(env, args, Value(new Object_wx_MouseEvent(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlLinkInfo, GetHtmlCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, GetHtmlCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlCell *rtn = (wxHtmlCell *)pThis->GetEntity()->GetHtmlCell();
	return ReturnValue(env, args, Value(new Object_wx_HtmlCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlLinkInfo, GetHref)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, GetHref)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetHref();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlLinkInfo, GetTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, GetTarget)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetTarget();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlLinkInfo
//----------------------------------------------------------------------------
Object_wx_HtmlLinkInfo::~Object_wx_HtmlLinkInfo()
{
}

Object *Object_wx_HtmlLinkInfo::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlLinkInfo::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlLinkInfo:");
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
// Class implementation for wxHtmlLinkInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlLinkInfo)
{
	Gura_AssignFunction(HtmlLinkInfoEmpty);
	Gura_AssignFunction(HtmlLinkInfo);
	Gura_AssignMethod(wx_HtmlLinkInfo, GetEvent);
	Gura_AssignMethod(wx_HtmlLinkInfo, GetHtmlCell);
	Gura_AssignMethod(wx_HtmlLinkInfo, GetHref);
	Gura_AssignMethod(wx_HtmlLinkInfo, GetTarget);
}

Gura_ImplementDescendantCreator(wx_HtmlLinkInfo)
{
	return new Object_wx_HtmlLinkInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
