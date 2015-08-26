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
	//Gura::Signal *_pSig;
	Object_wx_MDIClientWindow *_pObj;
public:
	inline wx_MDIClientWindow() : wxMDIClientWindow(), _pObj(nullptr) {}
	~wx_MDIClientWindow();
	inline void AssocWithGura(Object_wx_MDIClientWindow *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MDIClientWindow::~wx_MDIClientWindow()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MDIClientWindow::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIClientWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(MDIClientWindowEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MDIClientWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MDIClientWindowEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_MDIClientWindow *pEntity = new wx_MDIClientWindow();
	Object_wx_MDIClientWindow *pObj = Object_wx_MDIClientWindow::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MDIClientWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_MDIClientWindow, CreateClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_MDIParentFrame, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIClientWindow, CreateClient)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIClientWindow *pThis = Object_wx_MDIClientWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMDIParentFrame *parent = Object_wx_MDIParentFrame::GetObject(args, 0)->GetEntity();
	long style = 0;
	if (args.IsValid(1)) style = args.GetLong(1);
	bool rtn = pThis->GetEntity()->CreateClient(parent, style);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMDIClientWindow
//----------------------------------------------------------------------------
Object_wx_MDIClientWindow::~Object_wx_MDIClientWindow()
{
}

Object *Object_wx_MDIClientWindow::Clone() const
{
	return nullptr;
}

String Object_wx_MDIClientWindow::ToString(bool exprFlag)
{
	String rtn("<wx.MDIClientWindow:");
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
// Class implementation for wxMDIClientWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIClientWindow)
{
	Gura_AssignFunction(MDIClientWindowEmpty);
	Gura_AssignMethod(wx_MDIClientWindow, CreateClient);
}

Gura_ImplementDescendantCreator(wx_MDIClientWindow)
{
	return new Object_wx_MDIClientWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
