//----------------------------------------------------------------------------
// wxLogWindow
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnFrameCreate);
Gura_DeclarePrivUserSymbol(OnFrameClose);
Gura_DeclarePrivUserSymbol(OnFrameDelete);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LogWindow: public wxLogWindow, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_LogWindow *_pObj;
public:
	//inline wx_LogWindow(wxFrame *parent, const wxChar *title, bool show, bool passToOld) : wxLogWindow(*parent, *title, show, passToOld), _pObj(nullptr) {}
	//virtual void OnFrameCreate(wxFrame *frame);
	//virtual bool OnFrameClose(wxFrame *frame);
	//virtual void OnFrameDelete(wxFrame *frame);
	~wx_LogWindow();
	inline void AssocWithGura(Object_wx_LogWindow *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LogWindow::~wx_LogWindow()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LogWindow::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLogWindow
//----------------------------------------------------------------------------
Gura_DeclareFunction(LogWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxFrame **parent = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	wxChar *title = static_cast<wxChar>(args.GetInt(1));
	bool show = true;
	if (args.IsValid(2)) show = args.GetBoolean(2);
	bool passToOld = true;
	if (args.IsValid(3)) passToOld = args.GetBoolean(3);
	wx_LogWindow *pEntity = new wx_LogWindow(**parent, *title, show, passToOld);
	Object_wx_LogWindow *pObj = Object_wx_LogWindow::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_LogWindow(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogWindow, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_LogWindow, Show)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = true;
	if (args.IsValid(0)) show = args.GetBoolean(0);
	pThis->GetEntity()->Show(show);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogWindow, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LogWindow, GetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame *rtn = (wxFrame *)pThis->GetEntity()->GetFrame();
	return ReturnValue(env, args, Value(new Object_wx_Frame(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_LogWindow, OnFrameCreate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*frame", VTYPE_wx_Frame, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_LogWindow, OnFrameCreate)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame **frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFrameCreate(**frame);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogWindow, OnFrameClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*frame", VTYPE_wx_Frame, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_LogWindow, OnFrameClose)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame **frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->OnFrameClose(**frame);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogWindow, OnFrameDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*frame", VTYPE_wx_Frame, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_LogWindow, OnFrameDelete)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_LogWindow *pThis = Object_wx_LogWindow::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame **frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFrameDelete(**frame);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxLogWindow
//----------------------------------------------------------------------------
Object_wx_LogWindow::~Object_wx_LogWindow()
{
}

Object *Object_wx_LogWindow::Clone() const
{
	return nullptr;
}

String Object_wx_LogWindow::ToString(bool exprFlag)
{
	String rtn("<wx.LogWindow:");
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
// Class implementation for wxLogWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogWindow)
{
	Gura_RealizeUserSymbol(OnFrameCreate);
	Gura_RealizeUserSymbol(OnFrameClose);
	Gura_RealizeUserSymbol(OnFrameDelete);
	Gura_AssignFunction(LogWindow);
	Gura_AssignMethod(wx_LogWindow, Show);
	Gura_AssignMethod(wx_LogWindow, GetFrame);
	Gura_AssignMethod(wx_LogWindow, OnFrameCreate);
	Gura_AssignMethod(wx_LogWindow, OnFrameClose);
	Gura_AssignMethod(wx_LogWindow, OnFrameDelete);
}

Gura_ImplementDescendantCreator(wx_LogWindow)
{
	return new Object_wx_LogWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
