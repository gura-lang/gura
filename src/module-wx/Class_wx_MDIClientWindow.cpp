//----------------------------------------------------------------------------
// wxMDIClientWindow
// extracted from mdi.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MDIClientWindow: public wxMDIClientWindow, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MDIClientWindow *_pObj;
public:
	inline wx_MDIClientWindow() : wxMDIClientWindow(), _sig(NULL), _pObj(NULL) {}
	~wx_MDIClientWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MDIClientWindow *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MDIClientWindow::~wx_MDIClientWindow()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MDIClientWindow::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIClientWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(MDIClientWindowEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MDIClientWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MDIClientWindowEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_MDIClientWindow *pEntity = new wx_MDIClientWindow();
	Object_wx_MDIClientWindow *pObj = Object_wx_MDIClientWindow::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MDIClientWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MDIClientWindow, CreateClient)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_MDIParentFrame, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIClientWindow, CreateClient)
{
	Object_wx_MDIClientWindow *pThis = Object_wx_MDIClientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMDIParentFrame *parent = Object_wx_MDIParentFrame::GetObject(args, 0)->GetEntity();
	long style = 0;
	if (args.IsValid(1)) style = args.GetLong(1);
	bool rtn = pThis->GetEntity()->CreateClient(parent, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMDIClientWindow
//----------------------------------------------------------------------------
Object_wx_MDIClientWindow::~Object_wx_MDIClientWindow()
{
}

Object *Object_wx_MDIClientWindow::Clone() const
{
	return NULL;
}

String Object_wx_MDIClientWindow::ToString(bool exprFlag)
{
	String rtn("<wx.MDIClientWindow:");
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
// Class implementation for wxMDIClientWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIClientWindow)
{
	Gura_AssignFunction(MDIClientWindowEmpty);
	Gura_AssignMethod(wx_MDIClientWindow, CreateClient);
}

Gura_ImplementDescendantCreator(wx_MDIClientWindow)
{
	return new Object_wx_MDIClientWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
