//----------------------------------------------------------------------------
// wxHtmlCellEvent
// extracted from htwindow.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlCellEvent: public wxHtmlCellEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_HtmlCellEvent *_pObj;
public:
	//inline wx_HtmlCellEvent(wxEventType commandType, int id, wxHtmlCell * cell, const wxPoint & point) : wxHtmlCellEvent(commandType, id, cell, point), _pObj(nullptr) {}
	~wx_HtmlCellEvent();
	inline void AssocWithGura(Object_wx_HtmlCellEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlCellEvent::~wx_HtmlCellEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlCellEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlCellEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlCellEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_HtmlCellEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "cell", VTYPE_wx_HtmlCell, OCCUR_Once);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(HtmlCellEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxEventType commandType = static_cast<wxEventType>(args.GetInt(0));
	int id = args.GetInt(1);
	wxHtmlCell *cell = Object_wx_HtmlCell::GetObject(args, 2)->GetEntity();
	wxPoint *point = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wx_HtmlCellEvent *pEntity = new wx_HtmlCellEvent(commandType, id, cell, *point);
	Object_wx_HtmlCellEvent *pObj = Object_wx_HtmlCellEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlCellEvent(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_HtmlCellEvent, GetCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCellEvent, GetCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCellEvent *pThis = Object_wx_HtmlCellEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlCell *rtn = (wxHtmlCell *)pThis->GetEntity()->GetCell();
	return ReturnValue(env, args, Value(new Object_wx_HtmlCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCellEvent, GetPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCellEvent, GetPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCellEvent *pThis = Object_wx_HtmlCellEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPoint();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlCellEvent, SetLinkClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "linkclicked", VTYPE_boolean, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCellEvent, SetLinkClicked)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlCellEvent *pThis = Object_wx_HtmlCellEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool linkclicked = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->SetLinkClicked(linkclicked);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCellEvent, GetLinkClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCellEvent, GetLinkClicked)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCellEvent *pThis = Object_wx_HtmlCellEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetLinkClicked();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlCellEvent
//----------------------------------------------------------------------------
Object_wx_HtmlCellEvent::~Object_wx_HtmlCellEvent()
{
}

Object *Object_wx_HtmlCellEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlCellEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlCellEvent:");
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
// Class implementation for wxHtmlCellEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlCellEvent)
{
	Gura_AssignFunction(HtmlCellEvent);
	Gura_AssignMethod(wx_HtmlCellEvent, GetCell);
	Gura_AssignMethod(wx_HtmlCellEvent, GetPoint);
	Gura_AssignMethod(wx_HtmlCellEvent, SetLinkClicked);
	Gura_AssignMethod(wx_HtmlCellEvent, GetLinkClicked);
}

Gura_ImplementDescendantCreator(wx_HtmlCellEvent)
{
	return new Object_wx_HtmlCellEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
