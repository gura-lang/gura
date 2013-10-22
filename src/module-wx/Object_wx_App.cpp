//----------------------------------------------------------------------------
// wxApp
// extracted from app.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

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

static Environment *_pEnv = NULL;

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_App: public wxApp, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	AutoPtr<Object_wx_App> _pObj;
public:
	inline wx_App() : wxApp(), _sig(NULL), _pObj(NULL) {}
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
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_App *pObj) {
		_sig = sig, _pObj.reset(Object_wx_App::Reference(pObj));
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
	if (pFunc == NULL) return wxApp::OnInit();
	Environment &env = *_pObj;
	ValueList valList;
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

int wx_App::OnExit()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnExit);
	if (pFunc == NULL) return wxApp::OnExit();
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

void wx_App::OnUnhandledException()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnUnhandledException);
	if (pFunc == NULL) {
		wxApp::OnUnhandledException();
		return;
	}
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	CheckMethodResult(_sig);
}

void wx_App::HandleEvent(wxEvtHandler *handler, wxEventFunction func, wxEvent& event)
{
	wxApp::HandleEvent(handler, func, event);
	if (_sig.IsSignalled()) {
		const_cast<wx_App *>(this)->ExitMainLoop();
	}
}

//----------------------------------------------------------------------------
// Gura interfaces for wxApp
//----------------------------------------------------------------------------
Gura_DeclareFunction(App)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_App));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(App)
{
	//if (!CheckWxReady(sig)) return Value::Null;
	wx_App *pEntity = new wx_App();
	Object_wx_App *pObj = Object_wx_App::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_App(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_App, CreateLogTarget)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, CreateLogTarget)
{
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLog *rtn = (wxLog *)pThis->GetEntity()->CreateLogTarget();
	return ReturnValue(env, sig, args, Value(new Object_wx_Log(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, CreateTraits)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, CreateTraits)
{
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAppTraits *rtn = (wxAppTraits *)pThis->GetEntity()->CreateTraits();
	return ReturnValue(env, sig, args, Value(new Object_wx_AppTraits(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, Dispatch)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, Dispatch)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Dispatch();
	return Value::Null;
}

Gura_DeclareMethod(wx_App, ExitMainLoop)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, ExitMainLoop)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ExitMainLoop();
	return Value::Null;
}

Gura_DeclareMethod(wx_App, FilterEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, FilterEvent)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvent *event = Object_wx_Event::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->FilterEvent(*event);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, GetAppName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetAppName)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetAppName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_App, GetClassName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetClassName)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetClassName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_App, GetExitOnFrameDelete)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetExitOnFrameDelete)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetExitOnFrameDelete();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_App, GetInstance)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_App, GetInstance)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxAppConsole *rtn = (wxAppConsole *)wxApp::GetInstance();
	wxApp *rtnEx = wxDynamicCast(rtn, wxApp);
	if (rtnEx != NULL) {
		return ReturnValue(env, sig, args, Value(new Object_wx_App(rtnEx, NULL, OwnerFalse)));
	}
	return ReturnValue(env, sig, args, Value(new Object_wx_AppConsole(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_App, GetTopWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetTopWindow)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetTopWindow();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_App, GetTraits)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetTraits)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxAppTraits *rtn = (wxAppTraits *)pThis->GetEntity()->GetTraits();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_AppTraits(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_App, GetUseBestVisual)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetUseBestVisual)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetUseBestVisual();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, GetVendorName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, GetVendorName)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetVendorName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_App, IsActive)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, IsActive)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsActive();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_App, IsMainLoopRunning)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_App, IsMainLoopRunning)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxApp::IsMainLoopRunning();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, MainLoop)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, MainLoop)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxApp::SetInstance(pThis->GetEntity());
	int argc = 0;
	char *argv[1] = { NULL };
	::wxEntry(argc, argv);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, OnActivate)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_ActivateEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_App, OnActivate)
{
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxActivateEvent *event = Object_wx_ActivateEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxApp::OnActivate(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, OnCharHook)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_KeyEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_App, OnCharHook)
{
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxKeyEvent *event = Object_wx_KeyEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxApp::OnCharHook(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, OnAssertFailure)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
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
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar *file = static_cast<wxChar>(args.GetInt(0));
	int line = args.GetInt(1);
	wxChar *func = static_cast<wxChar>(args.GetInt(2));
	wxChar *cond = static_cast<wxChar>(args.GetInt(3));
	wxChar *msg = static_cast<wxChar>(args.GetInt(4));
	pThis->GetEntity()->wxApp::OnAssertFailure(*file, line, *func, *cond, *msg);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, OnCmdLineError)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parser", VTYPE_wx_CmdLineParser, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnCmdLineError)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCmdLineParser *parser = Object_wx_CmdLineParser::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->wxApp::OnCmdLineError(*parser);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnCmdLineHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parser", VTYPE_wx_CmdLineParser, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnCmdLineHelp)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCmdLineParser *parser = Object_wx_CmdLineParser::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->wxApp::OnCmdLineHelp(*parser);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnCmdLineParsed)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parser", VTYPE_wx_CmdLineParser, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnCmdLineParsed)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCmdLineParser *parser = Object_wx_CmdLineParser::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->wxApp::OnCmdLineParsed(*parser);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnExceptionInMainLoop)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnExceptionInMainLoop)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxApp::OnExceptionInMainLoop();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnExit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnExit)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->wxApp::OnExit();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnFatalException)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, OnFatalException)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->wxApp::OnFatalException();
	return Value::Null;
}

Gura_DeclareMethod(wx_App, OnIdle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_IdleEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, OnIdle)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIdleEvent *event = Object_wx_IdleEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxApp::OnIdle(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, OnEndSession)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, OnEndSession)
{
#if defined(__WXMSW__)
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnEndSession(*event);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_App, OnInit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnInit)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxApp::OnInit();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnInitCmdLine)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parser", VTYPE_wx_CmdLineParser, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, OnInitCmdLine)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCmdLineParser *parser = Object_wx_CmdLineParser::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxApp::OnInitCmdLine(*parser);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, OnRun)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, OnRun)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->wxApp::OnRun();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, OnUnhandledException)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, OnUnhandledException)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->wxApp::OnUnhandledException();
	return Value::Null;
}

Gura_DeclareMethod(wx_App, ProcessMessage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, ProcessMessage)
{
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ProcessMessage();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, Pending)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, Pending)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxApp::Pending();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, SendIdleEvents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_IdleEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, SendIdleEvents)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxIdleEvent *event = Object_wx_IdleEvent::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SendIdleEvents(win, *event);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_App, SetAppName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetAppName)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetAppName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, SetClassName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetClassName)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetClassName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, SetExitOnFrameDelete)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetExitOnFrameDelete)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetExitOnFrameDelete(flag);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_App, SetInstance)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "app", VTYPE_wx_AppConsole, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_App, SetInstance)
{
	//if (!CheckWxReady(sig)) return Value::Null;
	wxAppConsole *app = Object_wx_AppConsole::GetObject(args, 0)->GetEntity();
	wxApp::SetInstance(app);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, SetTopWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetTopWindow)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTopWindow(window);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, SetVendorName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetVendorName)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetVendorName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, SetUseBestVisual)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "forceTrueColour", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, SetUseBestVisual)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	bool forceTrueColour = false;
	if (args.IsValid(1)) forceTrueColour = args.GetBoolean(1);
	pThis->GetEntity()->SetUseBestVisual(flag, forceTrueColour);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, HandleEvent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*handler", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "func", VTYPE_wx_EventFunction, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_App, HandleEvent)
{
#if 0
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler **handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	wxEventFunction *func = Object_wx_EventFunction::GetObject(args, 1)->GetEntity();
	wxEvent *event = Object_wx_Event::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->wxApp::HandleEvent(**handler, *func, *event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_App, Yield)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "onlyIfNeeded", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_App, Yield)
{
	Object_wx_App *pThis = Object_wx_App::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool onlyIfNeeded = false;
	if (args.IsValid(0)) onlyIfNeeded = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Yield(onlyIfNeeded);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxApp
//----------------------------------------------------------------------------
Object_wx_App::~Object_wx_App()
{
}

Object *Object_wx_App::Clone() const
{
	return NULL;
}

String Object_wx_App::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.App:");
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
	Gura_AssignMethod(wx_App, OnIdle);
	Gura_AssignMethod(wx_App, OnEndSession);
	Gura_AssignMethod(wx_App, OnInit);
	Gura_AssignMethod(wx_App, OnInitCmdLine);
	Gura_AssignMethod(wx_App, OnRun);
	Gura_AssignMethod(wx_App, OnUnhandledException);
	Gura_AssignMethod(wx_App, ProcessMessage);
	Gura_AssignMethod(wx_App, Pending);
	Gura_AssignMethod(wx_App, SendIdleEvents);
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
	return new Object_wx_App((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
