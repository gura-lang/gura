//----------------------------------------------------------------------------
// wxTreebookEvent
// extracted from treebookevent.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TreebookEvent: public wxTreebookEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TreebookEvent *_pObj;
public:
	inline wx_TreebookEvent(wxEventType commandType, int id, int nSel, int nOldSel) : wxTreebookEvent(commandType, id, nSel, nOldSel), _sig(NULL), _pObj(NULL) {}
	~wx_TreebookEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TreebookEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TreebookEvent::~wx_TreebookEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TreebookEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreebookEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreebookEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TreebookEvent));
	DeclareArg(env, "commandType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "nSel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "nOldSel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreebookEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEventType commandType = wxEVT_NULL;
	if (args.IsValid(0)) commandType = static_cast<wxEventType>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	int nSel = wxNOT_FOUND;
	if (args.IsValid(2)) nSel = args.GetInt(2);
	int nOldSel = wxNOT_FOUND;
	if (args.IsValid(3)) nOldSel = args.GetInt(3);
	wx_TreebookEvent *pEntity = new wx_TreebookEvent(commandType, id, nSel, nOldSel);
	Object_wx_TreebookEvent *pObj = Object_wx_TreebookEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TreebookEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TreebookEvent, GetOldSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreebookEvent, GetOldSelection)
{
	Object_wx_TreebookEvent *pThis = Object_wx_TreebookEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOldSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreebookEvent, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreebookEvent, GetSelection)
{
	Object_wx_TreebookEvent *pThis = Object_wx_TreebookEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTreebookEvent
//----------------------------------------------------------------------------
Object_wx_TreebookEvent::~Object_wx_TreebookEvent()
{
}

Object *Object_wx_TreebookEvent::Clone() const
{
	return NULL;
}

String Object_wx_TreebookEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TreebookEvent:");
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
// Class implementation for wxTreebookEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreebookEvent)
{
	Gura_AssignFunction(TreebookEvent);
	Gura_AssignMethod(wx_TreebookEvent, GetOldSelection);
	Gura_AssignMethod(wx_TreebookEvent, GetSelection);
}

Gura_ImplementDescendantCreator(wx_TreebookEvent)
{
	return new Object_wx_TreebookEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
