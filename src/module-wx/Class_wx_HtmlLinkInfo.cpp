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
	Gura::Signal _sig;
	Object_wx_HtmlLinkInfo *_pObj;
public:
	inline wx_HtmlLinkInfo() : wxHtmlLinkInfo(), _sig(NULL), _pObj(NULL) {}
	inline wx_HtmlLinkInfo(const wxString& href, const wxString& target) : wxHtmlLinkInfo(href, target), _sig(NULL), _pObj(NULL) {}
	~wx_HtmlLinkInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlLinkInfo *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlLinkInfo::~wx_HtmlLinkInfo()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlLinkInfo::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlLinkInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlLinkInfoEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlLinkInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlLinkInfoEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_HtmlLinkInfo *pEntity = new wx_HtmlLinkInfo();
	Object_wx_HtmlLinkInfo *pObj = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlLinkInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(HtmlLinkInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HtmlLinkInfo));
	DeclareArg(env, "href", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "target", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlLinkInfo)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString href = wxString::FromUTF8(args.GetString(0));
	wxString target = wxEmptyString;
	if (args.IsValid(1)) target = wxString::FromUTF8(args.GetString(1));
	wx_HtmlLinkInfo *pEntity = new wx_HtmlLinkInfo(href, target);
	Object_wx_HtmlLinkInfo *pObj = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlLinkInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_HtmlLinkInfo, GetEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, GetEvent)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMouseEvent *rtn = (wxMouseEvent *)pThis->GetEntity()->GetEvent();
	return ReturnValue(env, sig, args, Value(new Object_wx_MouseEvent(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlLinkInfo, GetHtmlCell)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, GetHtmlCell)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxHtmlCell *rtn = (wxHtmlCell *)pThis->GetEntity()->GetHtmlCell();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlCell(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlLinkInfo, GetHref)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, GetHref)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetHref();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlLinkInfo, GetTarget)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlLinkInfo, GetTarget)
{
	Object_wx_HtmlLinkInfo *pThis = Object_wx_HtmlLinkInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetTarget();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlLinkInfo
//----------------------------------------------------------------------------
Object_wx_HtmlLinkInfo::~Object_wx_HtmlLinkInfo()
{
}

Object *Object_wx_HtmlLinkInfo::Clone() const
{
	return NULL;
}

String Object_wx_HtmlLinkInfo::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlLinkInfo:");
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
	return new Object_wx_HtmlLinkInfo((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
