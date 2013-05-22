//----------------------------------------------------------------------------
// wxLogWindow
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(OnFrameCreate);
Gura_DeclarePrivUserSymbol(OnFrameClose);
Gura_DeclarePrivUserSymbol(OnFrameDelete);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogWindow: public wxLogWindow, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_LogWindow *_pObj;
public:
	//inline wx_LogWindow(wxFrame *parent, const wxChar *title, bool show, bool passToOld) : wxLogWindow(*parent, *title, show, passToOld), _sig(NULL), _pObj(NULL) {}
	//virtual void OnFrameCreate(wxFrame *frame);
	//virtual bool OnFrameClose(wxFrame *frame);
	//virtual void OnFrameDelete(wxFrame *frame);
	~wx_LogWindow();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LogWindow *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogWindow::~wx_LogWindow()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LogWindow::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_LogWindow));
	DeclareArg(env, "*parent", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "*title", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "passToOld", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(LogWindow)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxFrame **parent = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	wxChar *title = static_cast<wxChar>(args.GetInt(1));
	bool show = true;
	if (args.IsValid(2)) show = args.GetBoolean(2);
	bool passToOld = true;
	if (args.IsValid(3)) passToOld = args.GetBoolean(3);
	wx_LogWindow *pEntity = new wx_LogWindow(**parent, *title, show, passToOld);
	Object_wx_LogWindow *pObj = Object_wx_LogWindow::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LogWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_LogWindow, Show)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_LogWindow, Show)
{
#if 0
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = true;
	if (args.IsValid(0)) show = args.GetBoolean(0);
	pThis->GetEntity()->Show(show);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_LogWindow, GetFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LogWindow, GetFrame)
{
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFrame *rtn = (wxFrame *)pThis->GetEntity()->GetFrame();
	return ReturnValue(env, sig, args, Value(new Object_wx_Frame(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_LogWindow, OnFrameCreate)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*frame", VTYPE_wx_Frame, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_LogWindow, OnFrameCreate)
{
#if 0
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFrame **frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFrameCreate(**frame);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_LogWindow, OnFrameClose)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*frame", VTYPE_wx_Frame, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LogWindow, OnFrameClose)
{
#if 0
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFrame **frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->OnFrameClose(**frame);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_LogWindow, OnFrameDelete)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*frame", VTYPE_wx_Frame, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_LogWindow, OnFrameDelete)
{
#if 0
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFrame **frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFrameDelete(**frame);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxLogWindow
//----------------------------------------------------------------------------
Object_wx_LogWindow::~Object_wx_LogWindow()
{
}

Object *Object_wx_LogWindow::Clone() const
{
	return NULL;
}

String Object_wx_LogWindow::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.LogWindow:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_LogWindow::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(OnFrameCreate);
	Gura_RealizeUserSymbol(OnFrameClose);
	Gura_RealizeUserSymbol(OnFrameDelete);
	Gura_AssignFunction(LogWindow);
}

//----------------------------------------------------------------------------
// Class implementation for wxLogWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogWindow)
{
	Gura_AssignMethod(wx_LogWindow, Show);
	Gura_AssignMethod(wx_LogWindow, GetFrame);
	Gura_AssignMethod(wx_LogWindow, OnFrameCreate);
	Gura_AssignMethod(wx_LogWindow, OnFrameClose);
	Gura_AssignMethod(wx_LogWindow, OnFrameDelete);
}

Gura_ImplementDescendantCreator(wx_LogWindow)
{
	return new Object_wx_LogWindow((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
