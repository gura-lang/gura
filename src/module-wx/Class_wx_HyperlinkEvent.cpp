//----------------------------------------------------------------------------
// wxHyperlinkEvent
// extracted from hyperlink.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HyperlinkEvent: public wxHyperlinkEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HyperlinkEvent *_pObj;
public:
	inline wx_HyperlinkEvent(wxObject * generator, int id, const wxString & url) : wxHyperlinkEvent(generator, id, url), _sig(nullptr), _pObj(nullptr) {}
	~wx_HyperlinkEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HyperlinkEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HyperlinkEvent::~wx_HyperlinkEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HyperlinkEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHyperlinkEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(HyperlinkEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_HyperlinkEvent));
	DeclareArg(env, "generator", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HyperlinkEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxObject *generator = Object_wx_Object::GetObject(args, 0)->GetEntity();
	int id = args.GetInt(1);
	wxString url = wxString::FromUTF8(args.GetString(2));
	wx_HyperlinkEvent *pEntity = new wx_HyperlinkEvent(generator, id, url);
	Object_wx_HyperlinkEvent *pObj = Object_wx_HyperlinkEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HyperlinkEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_HyperlinkEvent, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HyperlinkEvent, GetURL)
{
	Object_wx_HyperlinkEvent *pThis = Object_wx_HyperlinkEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetURL();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HyperlinkEvent, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HyperlinkEvent, SetURL)
{
	Object_wx_HyperlinkEvent *pThis = Object_wx_HyperlinkEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetURL(url);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHyperlinkEvent
//----------------------------------------------------------------------------
Object_wx_HyperlinkEvent::~Object_wx_HyperlinkEvent()
{
}

Object *Object_wx_HyperlinkEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HyperlinkEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HyperlinkEvent:");
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
// Class implementation for wxHyperlinkEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HyperlinkEvent)
{
	Gura_AssignFunction(HyperlinkEvent);
	Gura_AssignMethod(wx_HyperlinkEvent, GetURL);
	Gura_AssignMethod(wx_HyperlinkEvent, SetURL);
}

Gura_ImplementDescendantCreator(wx_HyperlinkEvent)
{
	return new Object_wx_HyperlinkEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
