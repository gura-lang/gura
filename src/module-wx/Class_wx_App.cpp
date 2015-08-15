//----------------------------------------------------------------------------
// wxApp
// extracted from app.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(CreateLogTarget);
Gura_DeclarePrivUserSymbol(CreateTraits);
Gura_DeclarePrivUserSymbol(Dispatch);
Gura_DeclarePrivUserSymbol(ExitMainLoop);
Gura_DeclarePrivUserSymbol(GetTopWindow);
Gura_DeclarePrivUserSymbol(MainLoop);
Gura_DeclarePrivUserSymbol(OnExceptionInMainLoop);
Gura_DeclarePrivUserSymbol(OnInit);
Gura_DeclarePrivUserSymbol(OnExit);
Gura_DeclarePrivUserSymbol(OnRun);
Gura_DeclarePrivUserSymbol(OnUnhandledException);
Gura_DeclarePrivUserSymbol(Pending);
Gura_DeclarePrivUserSymbol(HandleEvent);

static Environment *_pEnv = nullptr;

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_App: public wxApp, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	AutoPtr<Object_wx_App> _pObj;
public:
	inline wx_App() : wxApp(), _pObj(nullptr) {}
	//virtual wxLog* CreateLogTarget();
	//virtual wxAppTraits * CreateTraits();
	//virtual void Dispatch();
	virtual void ExitMainLoop();
	//virtual wxWindow * GetTopWindow();
	//virtual int MainLoop();
	//virtual bool OnExceptionInMainLoop();
	virtual bool OnInit();
	virtual int OnExit();
	//virtual int OnRun();
	virtual void OnUnhandledException();
	//virtual bool Pending();
	virtual void HandleEvent(wxEvtHandler *handler, wxEventFunction func, wxEvent& event);
	~wx_App();
	inline void AssocWithGura(Object_wx_App *pObj) {
		_pObj.reset(Object_wx_App::Reference(pObj));
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_App::~wx_App()
{
}

void wx_App::GuraObjectDeleted()
{
}

void wx_App::ExitMainLoop()
{
	SetWxReadyFlag(false);
	//::printf("ExitMainLoop\n");
	wxApp::ExitMainLoop();
}

bool wx_App::OnInit()
{
	SetWxReadyFlag(true);
	InitializeObjects(*_pEnv);
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnInit);
	if (pFunc == nullptr) return wxApp::OnInit();
	Environment &env = *_pObj;
	ValueList valList;
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

int wx_App::OnExit()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnExit);
	if (pFunc == nullptr) return wxApp::OnExit();
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

void wx_App::OnUnhandledException()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnUnhandledException);
	if (pFunc == nullptr) {
		wxApp::OnUnhandledException();
		return;
	}
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	CheckMethodResult(_pObj->GetSignal());
}

void wx_App::HandleEvent(wxEvtHandler *handler, wxEventFunction func, wxEvent& event)
{
	wxApp::HandleEvent(handler, func, event);
	if (_pObj->GetSignal().IsSignalled()) {
		const_cast<wx_App *>(this)->ExitMainLoop();
	}
}

//----------------------------------------------------------------------------
// Gura interfaces for wxApp
//----------------------------------------------------------------------------
Gura_DeclareFunction(App)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_App));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(App)
{
	Signal &sig = env.GetSignal();
	//if (!CheckWxReady(sig)) return Value::Nil;
	wx_App *pEntity = new wx_App();
	Object_wx_App *pObj = Object_wx_App::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_App(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_App, CreateLogTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, CreateLogTarget)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLog *rtn = (wxLog *)pThis->GetEntity()->CreateLogTarget();
	return ReturnValue(env, args, Value(new Object_wx_Log(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, CreateTraits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, CreateTraits)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAppTraits *rtn = (wxAppTraits *)pThis->GetEntity()->CreateTraits();
	return ReturnValue(env, args, Value(new Object_wx_AppTraits(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, Dispatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, Dispatch)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Dispatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, ExitMainLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, ExitMainLoop)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ExitMainLoop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, FilterEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, FilterEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvent *event = Object_wx_Event::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->FilterEvent(*event);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, GetAppName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetAppName)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetAppName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_App, GetClassName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetClassName)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetClassName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_App, GetExitOnFrameDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetExitOnFrameDelete)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetExitOnFrameDelete();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_App, GetInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_App, GetInstance)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxAppConsole *rtn = (wxAppConsole *)wxApp::GetInstance();
	wxApp *rtnEx = wxDynamicCast(rtn, wxApp);
	if (rtnEx != nullptr) {
		return ReturnValue(env, args, Value(new Object_wx_App(rtnEx, nullptr, OwnerFalse)));
	}
	return ReturnValue(env, args, Value(new Object_wx_AppConsole(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_App, GetTopWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetTopWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetTopWindow();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, args, value);
}

Gura_DeclareMethod(wx_App, GetTraits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetTraits)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxAppTraits *rtn = (wxAppTraits *)pThis->GetEntity()->GetTraits();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_AppTraits(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, args, value);
}

Gura_DeclareMethod(wx_App, GetUseBestVisual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetUseBestVisual)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetUseBestVisual();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, GetVendorName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetVendorName)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetVendorName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_App, IsActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, IsActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsActive();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_App, IsMainLoopRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_App, IsMainLoopRunning)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	bool rtn = wxApp::IsMainLoopRunning();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, MainLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, MainLoop)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxApp::SetInstance(pThis->GetEntity());
	int argc = 0;
	char *argv[1] = { nullptr };
	::wxEntry(argc, argv);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, OnActivate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_ActivateEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_App, OnActivate)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxActivateEvent *event = Object_wx_ActivateEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxApp::OnActivate(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, OnCharHook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_App, OnCharHook)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxApp::OnCharHook(*event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, OnAssertFailure)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*file", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "line", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*func", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*cond", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*msg", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_App, OnAssertFailure)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar *file = static_cast<wxChar>(args.GetInt(0));
	int line = args.GetInt(1);
	wxChar *func = static_cast<wxChar>(args.GetInt(2));
	wxChar *cond = static_cast<wxChar>(args.GetInt(3));
	wxChar *msg = static_cast<wxChar>(args.GetInt(4));
	pThis->GetEntity()->wxApp::OnAssertFailure(*file, line, *func, *cond, *msg);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, OnCmdLineError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parser", VTYPE_wx_CmdLineParser, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnCmdLineError)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCmdLineParser *parser = Object_wx_CmdLineParser::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->wxApp::OnCmdLineError(*parser);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnCmdLineHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parser", VTYPE_wx_CmdLineParser, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnCmdLineHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCmdLineParser *parser = Object_wx_CmdLineParser::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->wxApp::OnCmdLineHelp(*parser);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnCmdLineParsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parser", VTYPE_wx_CmdLineParser, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnCmdLineParsed)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCmdLineParser *parser = Object_wx_CmdLineParser::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->wxApp::OnCmdLineParsed(*parser);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnExceptionInMainLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnExceptionInMainLoop)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->wxApp::OnExceptionInMainLoop();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnExit)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->wxApp::OnExit();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnFatalException)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, OnFatalException)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->wxApp::OnFatalException();
	return Value::Nil;
}

#if 0
Gura_DeclareMethod(wx_App, OnIdle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_IdleEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, OnIdle)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIdleEvent *event = Object_wx_IdleEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxApp::OnIdle(*event);
	return Value::Nil;
}
#endif

Gura_DeclareMethod(wx_App, OnEndSession)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, OnEndSession)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnEndSession(*event);
	return Value::Nil;
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_App, OnInit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnInit)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->wxApp::OnInit();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnInitCmdLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parser", VTYPE_wx_CmdLineParser, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, OnInitCmdLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCmdLineParser *parser = Object_wx_CmdLineParser::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxApp::OnInitCmdLine(*parser);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, OnRun)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnRun)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->wxApp::OnRun();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnUnhandledException)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, OnUnhandledException)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->wxApp::OnUnhandledException();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, ProcessMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, ProcessMessage)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ProcessMessage();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, Pending)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, Pending)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->wxApp::Pending();
	return ReturnValue(env, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_App, SendIdleEvents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_IdleEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, SendIdleEvents)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxIdleEvent *event = Object_wx_IdleEvent::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SendIdleEvents(win, *event);
	return ReturnValue(env, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_App, SetAppName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetAppName)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetAppName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetClassName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetClassName)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetClassName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetExitOnFrameDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetExitOnFrameDelete)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetExitOnFrameDelete(flag);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_App, SetInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "app", VTYPE_wx_AppConsole, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_App, SetInstance)
{
	Signal &sig = env.GetSignal();
	//if (!CheckWxReady(sig)) return Value::Nil;
	wxAppConsole *app = Object_wx_AppConsole::GetObject(args, 0)->GetEntity();
	wxApp::SetInstance(app);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetTopWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetTopWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTopWindow(window);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetVendorName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetVendorName)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetVendorName(name);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetUseBestVisual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "forceTrueColour", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, SetUseBestVisual)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool flag = args.GetBoolean(0);
	bool forceTrueColour = false;
	if (args.IsValid(1)) forceTrueColour = args.GetBoolean(1);
	pThis->GetEntity()->SetUseBestVisual(flag, forceTrueColour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, HandleEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*handler", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "func", VTYPE_wx_EventFunction, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_App, HandleEvent)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler **handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	wxEventFunction *func = Object_wx_EventFunction::GetObject(args, 1)->GetEntity();
	wxEvent *event = Object_wx_Event::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->wxApp::HandleEvent(**handler, *func, *event);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, Yield)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "onlyIfNeeded", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, Yield)
{
	Signal &sig = env.GetSignal();
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool onlyIfNeeded = false;
	if (args.IsValid(0)) onlyIfNeeded = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Yield(onlyIfNeeded);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxApp
//----------------------------------------------------------------------------
Object_wx_App::~Object_wx_App()
{
}

Object *Object_wx_App::Clone() const
{
	return nullptr;
}

String Object_wx_App::ToString(bool exprFlag)
{
	String rtn("<wx.App:");
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
// Class implementation for wxApp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_App)
{
	_pEnv = &env;
	Gura_RealizeUserSymbol(CreateLogTarget);
	Gura_RealizeUserSymbol(CreateTraits);
	Gura_RealizeUserSymbol(Dispatch);
	Gura_RealizeUserSymbol(ExitMainLoop);
	Gura_RealizeUserSymbol(GetTopWindow);
	Gura_RealizeUserSymbol(MainLoop);
	Gura_RealizeUserSymbol(OnExceptionInMainLoop);
	Gura_RealizeUserSymbol(OnInit);
	Gura_RealizeUserSymbol(OnExit);
	Gura_RealizeUserSymbol(OnRun);
	Gura_RealizeUserSymbol(OnUnhandledException);
	Gura_RealizeUserSymbol(Pending);
	Gura_RealizeUserSymbol(HandleEvent);
	Gura_AssignFunction(App);
	Gura_AssignMethod(wx_App, CreateLogTarget);
	Gura_AssignMethod(wx_App, CreateTraits);
	Gura_AssignMethod(wx_App, Dispatch);
	Gura_AssignMethod(wx_App, ExitMainLoop);
	Gura_AssignMethod(wx_App, FilterEvent);
	Gura_AssignMethod(wx_App, GetAppName);
	Gura_AssignMethod(wx_App, GetClassName);
	Gura_AssignMethod(wx_App, GetExitOnFrameDelete);
	Gura_AssignMethod(wx_App, GetInstance);
	Gura_AssignMethod(wx_App, GetTopWindow);
	Gura_AssignMethod(wx_App, GetTraits);
	Gura_AssignMethod(wx_App, GetUseBestVisual);
	Gura_AssignMethod(wx_App, GetVendorName);
	Gura_AssignMethod(wx_App, IsActive);
	Gura_AssignMethod(wx_App, IsMainLoopRunning);
	Gura_AssignMethod(wx_App, MainLoop);
	Gura_AssignMethod(wx_App, OnActivate);
	Gura_AssignMethod(wx_App, OnCharHook);
	Gura_AssignMethod(wx_App, OnAssertFailure);
	Gura_AssignMethod(wx_App, OnCmdLineError);
	Gura_AssignMethod(wx_App, OnCmdLineHelp);
	Gura_AssignMethod(wx_App, OnCmdLineParsed);
	Gura_AssignMethod(wx_App, OnExceptionInMainLoop);
	Gura_AssignMethod(wx_App, OnExit);
	Gura_AssignMethod(wx_App, OnFatalException);
	//Gura_AssignMethod(wx_App, OnIdle);
	Gura_AssignMethod(wx_App, OnEndSession);
	Gura_AssignMethod(wx_App, OnInit);
	Gura_AssignMethod(wx_App, OnInitCmdLine);
	Gura_AssignMethod(wx_App, OnRun);
	Gura_AssignMethod(wx_App, OnUnhandledException);
	Gura_AssignMethod(wx_App, ProcessMessage);
	Gura_AssignMethod(wx_App, Pending);
	//Gura_AssignMethod(wx_App, SendIdleEvents);
	Gura_AssignMethod(wx_App, SetAppName);
	Gura_AssignMethod(wx_App, SetClassName);
	Gura_AssignMethod(wx_App, SetExitOnFrameDelete);
	Gura_AssignMethod(wx_App, SetInstance);
	Gura_AssignMethod(wx_App, SetTopWindow);
	Gura_AssignMethod(wx_App, SetVendorName);
	Gura_AssignMethod(wx_App, SetUseBestVisual);
	Gura_AssignMethod(wx_App, HandleEvent);
	Gura_AssignMethod(wx_App, Yield);
}

Gura_ImplementDescendantCreator(wx_App)
{
	return new Object_wx_App((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
