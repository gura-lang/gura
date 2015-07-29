//----------------------------------------------------------------------------
// wxView
// extracted from view.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Activate);
Gura_DeclarePrivUserSymbol(Close);
Gura_DeclarePrivUserSymbol(OnActivateView);
Gura_DeclarePrivUserSymbol(OnChangeFilename);
Gura_DeclarePrivUserSymbol(OnClose);
Gura_DeclarePrivUserSymbol(OnClosingDoocument);
Gura_DeclarePrivUserSymbol(OnCreate);
Gura_DeclarePrivUserSymbol(OnCreatePrintout);
Gura_DeclarePrivUserSymbol(OnDraw);
Gura_DeclarePrivUserSymbol(OnUpdate);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_View: public wxView, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_View *_pObj;
public:
	//inline wx_View() : wxView(), _pObj(nullptr) {}
	//virtual void Activate(bool activate);
	//virtual bool Close(bool deleteWindow);
	//virtual void OnActivateView(bool activate, wxView * activeView, wxView * deactiveView);
	//virtual void OnChangeFilename();
	//virtual bool OnClose(bool deleteWindow);
	//virtual void OnClosingDoocument();
	//virtual bool OnCreate(wxDocument* doc, long flags);
	//virtual wxPrintout* OnCreatePrintout();
	//virtual void OnDraw(wxDC* dc);
	//virtual void OnUpdate(wxView* sender, wxObject* hint);
	~wx_View();
	inline void AssocWithGura(Object_wx_View *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_View::~wx_View()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_View::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxView
//----------------------------------------------------------------------------
Gura_DeclareFunction(ViewEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_View));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ViewEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_View *pEntity = new wx_View();
	Object_wx_View *pObj = Object_wx_View::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_View(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_View, Activate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "activate", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, Activate)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool activate = args.GetBoolean(0);
	pThis->GetEntity()->Activate(activate);
	return Value::Null;
}

Gura_DeclareMethod(wx_View, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "deleteWindow", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_View, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool deleteWindow = true;
	if (args.IsValid(0)) deleteWindow = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Close(deleteWindow);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_View, GetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_View, GetDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *rtn = (wxDocument *)pThis->GetEntity()->GetDocument();
	return ReturnValue(env, args, Value(new Object_wx_Document(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_View, GetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_View, GetDocumentManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocManager *rtn = (wxDocManager *)pThis->GetEntity()->GetDocumentManager();
	return ReturnValue(env, args, Value(new Object_wx_DocManager(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_View, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_View, GetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetFrame();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_View, GetViewName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_View, GetViewName)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetViewName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_View, OnActivateView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "activate", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "activeView", VTYPE_wx_View, OCCUR_Once);
	DeclareArg(env, "deactiveView", VTYPE_wx_View, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, OnActivateView)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool activate = args.GetBoolean(0);
	wxView *activeView = Object_wx_View::GetObject(args, 1)->GetEntity();
	wxView *deactiveView = Object_wx_View::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->OnActivateView(activate, activeView, deactiveView);
	return Value::Null;
}

Gura_DeclareMethod(wx_View, OnChangeFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, OnChangeFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnChangeFilename();
	return Value::Null;
}

Gura_DeclareMethod(wx_View, OnClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "deleteWindow", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_View, OnClose)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool deleteWindow = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->OnClose(deleteWindow);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_View, OnClosingDoocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_View, OnClosingDoocument)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnClosingDoocument();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_View, OnCreate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_View, OnCreate)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	long flags = args.GetLong(1);
	bool rtn = pThis->GetEntity()->OnCreate(doc, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_View, OnCreatePrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_View, OnCreatePrintout)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintout *rtn = (wxPrintout *)pThis->GetEntity()->OnCreatePrintout();
	return ReturnValue(env, args, Value(new Object_wx_Printout(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_View, OnDraw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, OnDraw)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnDraw(dc);
	return Value::Null;
}

Gura_DeclareMethod(wx_View, OnUpdate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sender", VTYPE_wx_View, OCCUR_Once);
	DeclareArg(env, "hint", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, OnUpdate)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *sender = Object_wx_View::GetObject(args, 0)->GetEntity();
	wxObject *hint = Object_wx_Object::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->OnUpdate(sender, hint);
	return Value::Null;
}

Gura_DeclareMethod(wx_View, SetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, SetDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDocument(doc);
	return Value::Null;
}

Gura_DeclareMethod(wx_View, SetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, SetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *frame = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFrame(frame);
	return Value::Null;
}

Gura_DeclareMethod(wx_View, SetViewName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_View, SetViewName)
{
	Signal &sig = env.GetSignal();
	Object_wx_View *pThis = Object_wx_View::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetViewName(name);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxView
//----------------------------------------------------------------------------
Object_wx_View::~Object_wx_View()
{
}

Object *Object_wx_View::Clone() const
{
	return nullptr;
}

String Object_wx_View::ToString(bool exprFlag)
{
	String rtn("<wx.View:");
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
// Class implementation for wxView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_View)
{
	Gura_RealizeUserSymbol(Activate);
	Gura_RealizeUserSymbol(Close);
	Gura_RealizeUserSymbol(OnActivateView);
	Gura_RealizeUserSymbol(OnChangeFilename);
	Gura_RealizeUserSymbol(OnClose);
	Gura_RealizeUserSymbol(OnClosingDoocument);
	Gura_RealizeUserSymbol(OnCreate);
	Gura_RealizeUserSymbol(OnCreatePrintout);
	Gura_RealizeUserSymbol(OnDraw);
	Gura_RealizeUserSymbol(OnUpdate);
	Gura_AssignFunction(ViewEmpty);
	Gura_AssignMethod(wx_View, Activate);
	Gura_AssignMethod(wx_View, Close);
	Gura_AssignMethod(wx_View, GetDocument);
	Gura_AssignMethod(wx_View, GetDocumentManager);
	Gura_AssignMethod(wx_View, GetFrame);
	Gura_AssignMethod(wx_View, GetViewName);
	Gura_AssignMethod(wx_View, OnActivateView);
	Gura_AssignMethod(wx_View, OnChangeFilename);
	Gura_AssignMethod(wx_View, OnClose);
	Gura_AssignMethod(wx_View, OnClosingDoocument);
	Gura_AssignMethod(wx_View, OnCreate);
	Gura_AssignMethod(wx_View, OnCreatePrintout);
	Gura_AssignMethod(wx_View, OnDraw);
	Gura_AssignMethod(wx_View, OnUpdate);
	Gura_AssignMethod(wx_View, SetDocument);
	Gura_AssignMethod(wx_View, SetFrame);
	Gura_AssignMethod(wx_View, SetViewName);
}

Gura_ImplementDescendantCreator(wx_View)
{
	return new Object_wx_View((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
