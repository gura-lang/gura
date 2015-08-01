//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetApp);

static Environment *_pEnv = nullptr;

Gura_DeclareFunction(IMPLEMENT_APP)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "constructor", VTYPE_function, OCCUR_Once);
}

Gura_ImplementFunction(IMPLEMENT_APP)
{
	Signal &sig = env.GetSignal();
	//if (!CheckWxReady(sig)) return Value::Null;
	const Function *pFunc = args.GetFunction(0);
	AutoPtr<Args> pArgsSub(new Args());
	Value rtn = pFunc->Eval(env, *pArgsSub);
	if (!rtn.IsInstanceOf(VTYPE_wx_App)) {
		sig.SetError(ERR_ValueError,
				"constructructor must return an instance of wx.App");
		return Value::Null;
	}
	do {
		Expr_Block *pExprBlock = new Expr_Block();
		pExprBlock->AddExpr(new Expr_Value(rtn));
		AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
			Gura_UserSymbol(GetApp), pExprBlock, FUNCTYPE_Function));
		_pEnv->AssignFunction(pFunc.release());
	} while (0);
	do {
		Object_wx_App *pObj = Object_wx_App::GetObject(rtn);
		wxApp::SetInstance(pObj->GetEntity());
		int argc = 0;
		char *argv[1] = { nullptr };
		::wxEntry(argc, argv);
	} while (0);
	return Value::Null;
}

Gura_DeclareFunction(BusyCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(BusyCursor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	::wxBeginBusyCursor();
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	SeqPostHandler *pSeqPostHandler = nullptr;
	Value rtn = pExprBlock->Exec2(env, pSeqPostHandler);
	::wxEndBusyCursor();
	return rtn;
}

Gura_DeclareFunction(CaretSuspend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(CaretSuspend)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxCaretSuspend cs(win);
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	SeqPostHandler *pSeqPostHandler = nullptr;
	Value rtn = pExprBlock->Exec2(env, pSeqPostHandler);
	return rtn;
}

Gura_DeclareFunction(ClipboardLocker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(ClipboardLocker)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxClipboardLocker clipboardLocker;
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	SeqPostHandler *pSeqPostHandler = nullptr;
	Value rtn = pExprBlock->Exec2(env, pSeqPostHandler);
	return rtn;
}

#if 0
Gura_DeclareFunction(DynamicCast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ptr", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "classname", VTYPE_Class, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DynamicCast)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	Object_wx_Object *pObj = Object_wx_Object::GetObject(args, 0);
	Class *pClass = args.GetClass(1);
	Object_wx_Object *pObjNew = new Object_wx_Object(Class::Reference(pClass),
											pObj->GetEntity(), nullptr, OwnerFalse);
	return ReturnValue(env, args, Value(pObjNew));
}
#endif

Gura_DeclareFunction(CHECK_GCC_VERSION)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CHECK_GCC_VERSION)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	bool rtn = wxCHECK_GCC_VERSION(major, minor);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(CHECK_VERSION)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "release", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CHECK_VERSION)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	int release = args.GetInt(2);
	bool rtn = wxCHECK_VERSION(major, minor, release);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(CHECK_VERSION_FULL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "release", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "subrel", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CHECK_VERSION_FULL)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	int release = args.GetInt(2);
	int subrel = args.GetInt(3);
	bool rtn = wxCHECK_VERSION_FULL(major, minor, release, subrel);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(CHECK_W32API_VERSION)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CHECK_W32API_VERSION)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	bool rtn = wxCHECK_W32API_VERSION(major, minor);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Entry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Entry)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int argc = args.GetInt(0);
	wxChar argv = static_cast<wxChar>(args.GetInt(1));
	int rtn = wxEntry(argc, argv);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Entry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pCmdLine", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "nCmdShow", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Entry_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char pCmdLine = ;
	if (args.IsValid(2)) pCmdLine = args.GetChar(2);
	int nCmdShow = SW_SHOWNORMAL;
	if (args.IsValid(3)) nCmdShow = args.GetInt(3);
	int rtn = wxEntry(, , pCmdLine, nCmdShow);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(EntryCleanup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(EntryCleanup)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxEntryCleanup();
	return Value::Null;
}

Gura_DeclareFunction(EntryStart)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EntryStart)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int argc = args.GetInt(0);
	wxChar argv = static_cast<wxChar>(args.GetInt(1));
	bool rtn = wxEntryStart(argc, argv);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(HandleFatalExceptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "doIt", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HandleFatalExceptions)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	bool doIt = true;
	if (args.IsValid(0)) doIt = args.GetBoolean(0);
	bool rtn = wxHandleFatalExceptions(doIt);
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif
}

Gura_DeclareFunction(InitAllImageHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(InitAllImageHandlers)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxInitAllImageHandlers();
	return Value::Null;
}

Gura_DeclareFunction(Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Initialize)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxInitialize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(SafeYield)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "onlyIfNeeded", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SafeYield)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *win = (wxWindow *)(nullptr);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool onlyIfNeeded = false;
	if (args.IsValid(1)) onlyIfNeeded = args.GetBoolean(1);
	bool rtn = wxSafeYield(win, onlyIfNeeded);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Uninitialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(Uninitialize)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxUninitialize();
	return Value::Null;
}

Gura_DeclareFunction(Yield)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Yield)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxYield();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(WakeUpIdle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(WakeUpIdle)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWakeUpIdle();
	return Value::Null;
}

Gura_DeclareFunction(Execute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "sync", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "callback", VTYPE_wx_Process, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Execute)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString command = wxString::FromUTF8(args.GetString(0));
	int sync = wxEXEC_ASYNC;
	if (args.IsValid(1)) sync = args.GetInt(1);
	wxProcess *callback = (wxProcess *)(nullptr);
	if (args.IsValid(2)) callback = Object_wx_Process::GetObject(args, 2)->GetEntity();
	long rtn = wxExecute(command, sync, callback);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Execute_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "callback", VTYPE_wx_Process, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Execute_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char argv = args.GetChar(0);
	int flags = wxEXEC_ASYNC;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxProcess *callback = (wxProcess *)(nullptr);
	if (args.IsValid(2)) callback = Object_wx_Process::GetObject(args, 2)->GetEntity();
	long rtn = wxExecute(argv, flags, callback);
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_NotImplemented(sig);
	return Value::Null;
#endif
}

Gura_DeclareFunction(Execute_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Execute_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString command = wxString::FromUTF8(args.GetString(0));
	std::unique_ptr<wxArrayString> output(CreateArrayString(args.GetList(1)));
	int flags = 0;
	if (args.IsValid(2)) flags = args.GetInt(2);
	long rtn = wxExecute(command, *output, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Execute_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "errors", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Execute_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString command = wxString::FromUTF8(args.GetString(0));
	std::unique_ptr<wxArrayString> output(CreateArrayString(args.GetList(1)));
	std::unique_ptr<wxArrayString> errors(CreateArrayString(args.GetList(2)));
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	long rtn = wxExecute(command, *output, *errors, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Exit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(Exit)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxExit();
	return Value::Null;
}

Gura_DeclareFunction(Kill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sig", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "*rc", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Kill)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	long pid = args.GetLong(0);
	int sig = wxSIGTERM;
	if (args.IsValid(1)) sig = args.GetInt(1);
	wxKillError *rc = nullptr;
	if (args.IsValid(2)) *rc = static_cast<wxKillError>(args.GetInt(2));
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	int rtn = wxKill(pid, sig, *rc, flags);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetProcessId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetProcessId)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned rtn = wxGetProcessId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Shell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Shell)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString command = nullptr;
	if (args.IsValid(0)) command = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxShell(command);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Shutdown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_wx_ShutdownFlags, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Shutdown)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxShutdownFlags *flags = Object_wx_ShutdownFlags::GetObject(args, 0)->GetEntity();
	bool rtn = wxShutdown(*flags);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CRIT_SECT_DECLARE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CRIT_SECT_DECLARE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCRIT_SECT_DECLARE();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CRIT_SECT_DECLARE_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CRIT_SECT_DECLARE_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCRIT_SECT_DECLARE();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CRIT_SECT_LOCKER)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CRIT_SECT_LOCKER)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCRIT_SECT_LOCKER(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CRITICAL_SECTION)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CRITICAL_SECTION)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCRITICAL_SECTION();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ENTER_CRIT_SECT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cs", VTYPE_wx_CriticalSection, OCCUR_Once);
}

Gura_ImplementFunction(ENTER_CRIT_SECT)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxCriticalSection *cs = Object_wx_CriticalSection::GetObject(args, 0)->GetEntity();
	wxENTER_CRIT_SECT(*cs);
	return Value::Null;
}

Gura_DeclareFunction(IsMainThread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsMainThread)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	bool rtn = wxIsMainThread();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif
}

Gura_DeclareFunction(LEAVE_CRIT_SECT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cs", VTYPE_wx_CriticalSection, OCCUR_Once);
}

Gura_ImplementFunction(LEAVE_CRIT_SECT)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxCriticalSection *cs = Object_wx_CriticalSection::GetObject(args, 0)->GetEntity();
	wxLEAVE_CRIT_SECT(*cs);
	return Value::Null;
}

Gura_DeclareFunction(MutexGuiEnter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(MutexGuiEnter)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxMutexGuiEnter();
	return Value::Null;
}

Gura_DeclareFunction(MutexGuiLeave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(MutexGuiLeave)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxMutexGuiLeave();
	return Value::Null;
}

Gura_DeclareFunction(Dos2UnixFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(Dos2UnixFilename)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString s = wxString::FromUTF8(args.GetString(0));
	wxDos2UnixFilename(s);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FileExists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileExists)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileExists(filename);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(FileModificationTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileModificationTime)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FileNameFromPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileNameFromPath)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxFileNameFromPath(path);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(FileNameFromPath_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileNameFromPath_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char path = args.GetChar(0);
	char rtn = wxFileNameFromPath(path);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FindFirstFile_)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "spec", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindFirstFile_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char spec = args.GetChar(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxString rtn = wxFindFirstFile(spec, flags);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FindNextFile_)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindNextFile_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxFindNextFile();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetDiskSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*total", VTYPE_wx_LongLong, OCCUR_ZeroOrOnce);
	DeclareArg(env, "*free", VTYPE_wx_LongLong, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetDiskSpace)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxLongLong **total = (wxLongLong *)(&nullptr);
	if (args.IsValid(1)) *total = Object_wx_LongLong::GetObject(args, 1)->GetEntity();
	wxLongLong **free = (wxLongLong *)(&nullptr);
	if (args.IsValid(2)) *free = Object_wx_LongLong::GetObject(args, 2)->GetEntity();
	bool rtn = wxGetDiskSpace(path, **total, **free);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetFileKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fd", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFileKind)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int fd = args.GetInt(0);
	wxFileKind rtn = wxGetFileKind(fd);
	return ReturnValue(env, args, Value(new Object_wx_FileKind(new wxFileKind(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetFileKind_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFileKind_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxFileKind rtn = wxGetFileKind();
	return ReturnValue(env, args, Value(new Object_wx_FileKind(new wxFileKind(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetOSDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetOSDirectory)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetOSDirectory();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(IsAbsolutePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsAbsolutePath)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxIsAbsolutePath(filename);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(DirExists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DirExists)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dirname = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxDirExists(dirname);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(PathOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PathOnly)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxPathOnly(path);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(Unix2DosFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(Unix2DosFilename)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString s = wxString::FromUTF8(args.GetString(0));
	wxUnix2DosFilename(s);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHANGE_UMASK)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(CHANGE_UMASK)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int mask = args.GetInt(0);
	wxCHANGE_UMASK(mask);
	return Value::Null;
}

Gura_DeclareFunction(ConcatFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file2", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file3", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ConcatFiles)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file1 = wxString::FromUTF8(args.GetString(0));
	wxString file2 = wxString::FromUTF8(args.GetString(1));
	wxString file3 = wxString::FromUTF8(args.GetString(2));
	bool rtn = wxConcatFiles(file1, file2, file3);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunctionAlias(CopyFile_, "CopyFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file2", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "overwrite", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CopyFile_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file1 = wxString::FromUTF8(args.GetString(0));
	wxString file2 = wxString::FromUTF8(args.GetString(1));
	bool overwrite = true;
	if (args.IsValid(2)) overwrite = args.GetBoolean(2);
	bool rtn = wxCopyFile(file1, file2, overwrite);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(GetCwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetCwd)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetCwd();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(IsWild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsWild)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString pattern = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxIsWild(pattern);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(MatchWild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dot_special", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MatchWild)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString pattern = wxString::FromUTF8(args.GetString(0));
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool dot_special = args.GetBoolean(2);
	bool rtn = wxMatchWild(pattern, text, dot_special);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Mkdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "perm", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Mkdir)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	int perm = 0777;
	if (args.IsValid(1)) perm = args.GetInt(1);
	bool rtn = wxMkdir(dir, perm);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(ParseCommonDialogsFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wildCard", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "descriptions", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "filters", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ParseCommonDialogsFilter)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString wildCard = wxString::FromUTF8(args.GetString(0));
	std::unique_ptr<wxArrayString> descriptions(CreateArrayString(args.GetList(1)));
	std::unique_ptr<wxArrayString> filters(CreateArrayString(args.GetList(2)));
	int rtn = wxParseCommonDialogsFilter(wildCard, *descriptions, *filters);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(RemoveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RemoveFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxRemoveFile(file);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(RenameFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file2", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "overwrite", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RenameFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString file1 = wxString::FromUTF8(args.GetString(0));
	wxString file2 = wxString::FromUTF8(args.GetString(1));
	bool overwrite = true;
	if (args.IsValid(2)) overwrite = args.GetBoolean(2);
	bool rtn = wxRenameFile(file1, file2, overwrite);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Rmdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Rmdir)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = wxRmdir(dir, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(SetWorkingDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SetWorkingDirectory)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxSetWorkingDirectory(dir);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(SplitPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fullname", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SplitPath)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString fullname = wxString::FromUTF8(args.GetString(0));
	wxString path;
	wxString name;
	wxString ext;
	wxSplitPath(fullname, &path, &name, &ext);
	return Value::CreateList(env, Value(path.ToUTF8()),
					Value(name.ToUTF8()), Value(ext.ToUTF8()));
}

Gura_DeclareFunction(TransferFileToStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TransferFileToStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	Stream & stream = args.GetStream(1);
	bool rtn = wxTransferFileToStream(filename, stream);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(TransferStreamToFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TransferStreamToFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(1));
	bool rtn = wxTransferStreamToFile(, filename);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetEmailAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetEmailAddress)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetEmailAddress();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetEmailAddress_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetEmailAddress_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char buf = args.GetChar(0);
	int sz = args.GetInt(1);
	bool rtn = wxGetEmailAddress(buf, sz);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetFreeMemory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFreeMemory)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxMemorySize rtn = wxGetFreeMemory();
	return ReturnValue(env, args, Value(new Object_wx_MemorySize(new wxMemorySize(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetFullHostName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFullHostName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetFullHostName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetHomeDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetHomeDir)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetHomeDir();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetHostName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetHostName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetHostName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetOsDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetOsDescription)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetOsDescription();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetOsVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetOsVersion)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int major = 0;
	int minor = 0;
	wxOperatingSystemId rtn = wxGetOsVersion(&major, &minor);
	return ReturnValue(env, args,
			Value::CreateList(env, Value(rtn), Value(major), Value(minor)));
}

Gura_DeclareFunction(IsPlatformLittleEndian)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsPlatformLittleEndian)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxIsPlatformLittleEndian();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(IsPlatform64Bit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsPlatform64Bit)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxIsPlatform64Bit();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(GetUserHome)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "user", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserHome)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString user = wxT("");
	if (args.IsValid(0)) user = wxString::FromUTF8(args.GetString(0));
	wxChar rtn = wxGetUserHome(user);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetUserId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserId)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetUserId();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetUserId_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserId_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char buf = args.GetChar(0);
	int sz = args.GetInt(1);
	bool rtn = wxGetUserId(buf, sz);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetUserName_)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserName_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxGetUserName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetUserName__1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserName__1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char buf = args.GetChar(0);
	int sz = args.GetInt(1);
	bool rtn = wxGetUserName(buf, sz);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(copystring)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(copystring)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char s = args.GetChar(0);
	char rtn = copystring(s);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetTranslation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "domain", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetTranslation)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString _domain;
	const wxChar *domain = nullptr;
	if (args.IsValid(1)) {
		_domain = wxString::FromUTF8(args.GetString(1));
		domain = _domain;
	}
	wxString rtn = wxGetTranslation(str, domain);
	return ReturnValue(env, args, Value(rtn.ToUTF8()));
}

Gura_DeclareFunction(GetTranslation_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "strPlural", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "domain", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetTranslation_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString strPlural = wxString::FromUTF8(args.GetString(1));
	size_t n = args.GetSizeT(2);
	wxString _domain;
	const wxChar *domain = nullptr;
	if (args.IsValid(3)) {
		_domain = wxString::FromUTF8(args.GetString(3));
		domain = _domain;
	}
	wxChar rtn = wxGetTranslation(str, strPlural, n, domain);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char p = args.GetChar(0);
	bool rtn = wxIsEmpty(p);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Strcmp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "p1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "p2", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Strcmp)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char p1 = args.GetChar(0);
	char p2 = args.GetChar(1);
	int rtn = wxStrcmp(p1, p2);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Stricmp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "p1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "p2", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Stricmp)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char p1 = args.GetChar(0);
	char p2 = args.GetChar(1);
	int rtn = wxStricmp(p1, p2);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(StringEq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "s2", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringEq)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString s1 = wxString::FromUTF8(args.GetString(0));
	wxString s2 = wxString::FromUTF8(args.GetString(1));
	bool rtn = wxStringEq(s1, s2);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(StringMatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "s2", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "subString", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "exact", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringMatch)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString s1 = wxString::FromUTF8(args.GetString(0));
	wxString s2 = wxString::FromUTF8(args.GetString(1));
	bool subString = true;
	if (args.IsValid(2)) subString = args.GetBoolean(2);
	bool exact = false;
	if (args.IsValid(3)) exact = args.GetBoolean(3);
	bool rtn = wxStringMatch(s1, s2, subString, exact);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(StringTokenize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "delims", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringTokenize)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString delims = wxDEFAULT_DELIMITERS;
	if (args.IsValid(1)) delims = wxString::FromUTF8(args.GetString(1));
	wxStringTokenizerMode mode = wxTOKEN_DEFAULT;
	if (args.IsValid(2)) mode = static_cast<wxStringTokenizerMode>(args.GetInt(2));
	wxArrayString rtn = wxStringTokenize(str, delims, mode);
	return ReturnValue(env, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareFunction(Strlen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Strlen)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char p = args.GetChar(0);
	size_t rtn = wxStrlen(p);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Snprintf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Snprintf)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString buf = wxString::FromUTF8(args.GetString(0));
	size_t len = args.GetSizeT(1);
	wxString format = wxString::FromUTF8(args.GetString(2));
	int rtn = wxSnprintf(buf, len, format, );
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(TRANSLATE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TRANSLATE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxString s = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxTRANSLATE(s);
	return ReturnValue(env, args, Value(rtn.ToUTF8()));
#else
	return ReturnValue(env, args, args.GetValue(0));
#endif	
}

Gura_DeclareFunction(Vsnprintf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Vsnprintf)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString buf = wxString::FromUTF8(args.GetString(0));
	size_t len = args.GetSizeT(1);
	wxString format = wxString::FromUTF8(args.GetString(2));
	int rtn = wxVsnprintf(buf, len, format, );
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(PLURAL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sing", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "plur", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PLURAL)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString sing = wxString::FromUTF8(args.GetString(0));
	wxString plur = wxString::FromUTF8(args.GetString(1));
	size_t n = args.GetSizeT(2);
	//wxString rtn = wxPLURAL(sing, plur, n);
	wxString rtn = wxGetTranslation(sing, plur, n);
	return ReturnValue(env, args, Value(rtn.ToUTF8()));
}

Gura_DeclareFunction(AboutBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_AboutDialogInfo, OCCUR_Once);
}

Gura_ImplementFunction(AboutBox)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxAboutDialogInfo *info = Object_wx_AboutDialogInfo::GetObject(args, 0)->GetEntity();
	wxAboutBox(*info);
	return Value::Null;
}

Gura_DeclareFunction(BeginBusyCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BeginBusyCursor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxCursor *cursor = (wxCursor *)(wxHOURGLASS_CURSOR);
	if (args.IsValid(0)) cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	wxBeginBusyCursor(cursor);
	return Value::Null;
}

Gura_DeclareFunction(Bell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(Bell)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxBell();
	return Value::Null;
}

Gura_DeclareFunction(CreateFileTipProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "currentTip", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CreateFileTipProvider)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	size_t currentTip = args.GetSizeT(1);
	wxTipProvider *rtn = (wxTipProvider *)wxCreateFileTipProvider(filename, currentTip);
	return ReturnValue(env, args, Value(new Object_wx_TipProvider(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareFunction(DirSelector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "default_path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DirSelector)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString message = wxDirSelectorPromptStr;
	if (args.IsValid(0)) message = wxString::FromUTF8(args.GetString(0));
	wxString default_path = wxT("");
	if (args.IsValid(1)) default_path = wxString::FromUTF8(args.GetString(1));
	long style = 0;
	if (args.IsValid(2)) style = args.GetLong(2);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(4)) parent = Object_wx_Window::GetObject(args, 4)->GetEntity();
	wxString rtn = wxDirSelector(message, default_path, style, *pos, parent);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(FileSelector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "default_path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "default_filename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "default_extension", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileSelector)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString default_path = wxT("");
	if (args.IsValid(1)) default_path = wxString::FromUTF8(args.GetString(1));
	wxString default_filename = wxT("");
	if (args.IsValid(2)) default_filename = wxString::FromUTF8(args.GetString(2));
	wxString default_extension = wxT("");
	if (args.IsValid(3)) default_extension = wxString::FromUTF8(args.GetString(3));
	wxString wildcard = wxT("*.*");
	if (args.IsValid(4)) wildcard = wxString::FromUTF8(args.GetString(4));
	int flags = 0;
	if (args.IsValid(5)) flags = args.GetInt(5);
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(6)) parent = Object_wx_Window::GetObject(args, 6)->GetEntity();
	int x = -1;
	if (args.IsValid(7)) x = args.GetInt(7);
	int y = -1;
	if (args.IsValid(8)) y = args.GetInt(8);
	wxString rtn = wxFileSelector(message, default_path, default_filename, default_extension, wildcard, flags, parent, x, y);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(EndBusyCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(EndBusyCursor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxEndBusyCursor();
	return Value::Null;
}

Gura_DeclareFunction(GenericAboutBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_AboutDialogInfo, OCCUR_Once);
}

Gura_ImplementFunction(GenericAboutBox)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxAboutDialogInfo *info = Object_wx_AboutDialogInfo::GetObject(args, 0)->GetEntity();
	wxGenericAboutBox(*info);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetColourFromUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "colInit", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetColourFromUser)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = nullptr;
	if (args.IsValid(0)) parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxColour *colInit = (wxColour *)&wxNullColour;
	if (args.IsValid(1)) colInit = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxString caption = wxEmptyString;
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	wxColour rtn = wxGetColourFromUser(parent, *colInit, caption);
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareFunction(GetFontFromUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fontInit", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFontFromUser)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = nullptr;
	if (args.IsValid(0)) parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxFont *fontInit = (wxFont *)&wxNullFont;
	if (args.IsValid(1)) fontInit = Object_wx_Font::GetObject(args, 1)->GetEntity();
	wxString caption = wxEmptyString;
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	wxFont rtn = wxGetFontFromUser(parent, *fontInit, caption);
	return ReturnValue(env, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareFunction(GetMultipleChoices)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "aChoices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "centre", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetMultipleChoices)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxArrayInt selections;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	std::unique_ptr<wxArrayString> aChoices(CreateArrayString(args.GetList(2)));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = -1;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = -1;
	if (args.IsValid(5)) y = args.GetInt(5);
	bool centre = true;
	if (args.IsValid(6)) centre = args.GetBoolean(6);
	int width = 150;
	if (args.IsValid(7)) width = args.GetInt(7);
	int height = 200;
	if (args.IsValid(8)) height = args.GetInt(8);
	size_t rtn = wxGetMultipleChoices(selections, message, caption, *aChoices, parent, x, y, centre, width, height);
	return ReturnValue(env, args, ArrayIntToValue(env, selections));
}

Gura_DeclareFunction(GetNumberFromUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "prompt", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "min", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "max", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetNumberFromUser)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString prompt = wxString::FromUTF8(args.GetString(1));
	wxString caption = wxString::FromUTF8(args.GetString(2));
	long value = args.GetLong(3);
	long min = 0;
	if (args.IsValid(4)) min = args.GetLong(4);
	long max = 100;
	if (args.IsValid(5)) max = args.GetLong(5);
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(6)) parent = Object_wx_Window::GetObject(args, 6)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(7)) pos = Object_wx_Point::GetObject(args, 7)->GetEntity();
	long rtn = wxGetNumberFromUser(message, prompt, caption, value, min, max, parent, *pos);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(GetPasswordFromUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "default_value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "centre", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPasswordFromUser)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxT("Input text");
	if (args.IsValid(1)) caption = wxString::FromUTF8(args.GetString(1));
	wxString default_value = wxT("");
	if (args.IsValid(2)) default_value = wxString::FromUTF8(args.GetString(2));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = wxDefaultCoord;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = wxDefaultCoord;
	if (args.IsValid(5)) y = args.GetInt(5);
	bool centre = true;
	if (args.IsValid(6)) centre = args.GetBoolean(6);
	wxString rtn = wxGetPasswordFromUser(message, caption, default_value, parent, x, y, centre);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetTextFromUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "default_value", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "centre", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetTextFromUser)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxT("Input text");
	if (args.IsValid(1)) caption = wxString::FromUTF8(args.GetString(1));
	wxString default_value = wxT("");
	if (args.IsValid(2)) default_value = wxString::FromUTF8(args.GetString(2));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = wxDefaultCoord;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = wxDefaultCoord;
	if (args.IsValid(5)) y = args.GetInt(5);
	bool centre = true;
	if (args.IsValid(6)) centre = args.GetBoolean(6);
	wxString rtn = wxGetTextFromUser(message, caption, default_value, parent, x, y, centre);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetSingleChoice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "aChoices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "centre", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetSingleChoice)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	std::unique_ptr<wxArrayString> aChoices(CreateArrayString(args.GetList(2)));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = -1;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = -1;
	if (args.IsValid(5)) y = args.GetInt(5);
	bool centre = true;
	if (args.IsValid(6)) centre = args.GetBoolean(6);
	int width = 150;
	if (args.IsValid(7)) width = args.GetInt(7);
	int height = 200;
	if (args.IsValid(8)) height = args.GetInt(8);
	wxString rtn = wxGetSingleChoice(message, caption, *aChoices, parent, x, y, centre, width, height);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetSingleChoiceIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "aChoices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "centre", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetSingleChoiceIndex)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	std::unique_ptr<wxArrayString> aChoices(CreateArrayString(args.GetList(2)));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = -1;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = -1;
	if (args.IsValid(5)) y = args.GetInt(5);
	bool centre = true;
	if (args.IsValid(6)) centre = args.GetBoolean(6);
	int width = 150;
	if (args.IsValid(7)) width = args.GetInt(7);
	int height = 200;
	if (args.IsValid(8)) height = args.GetInt(8);
	int rtn = wxGetSingleChoiceIndex(message, caption, *aChoices, parent, x, y, centre, width, height);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(GetSingleChoiceData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "aChoices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "client_data[]", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "centre", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetSingleChoiceData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	std::unique_ptr<wxArrayString> aChoices(CreateArrayString(args.GetList(2)));
	wxString client_data[] = wxString::FromUTF8(args.GetString(3));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(4)) parent = Object_wx_Window::GetObject(args, 4)->GetEntity();
	int x = -1;
	if (args.IsValid(5)) x = args.GetInt(5);
	int y = -1;
	if (args.IsValid(6)) y = args.GetInt(6);
	bool centre = true;
	if (args.IsValid(7)) centre = args.GetBoolean(7);
	int width = 150;
	if (args.IsValid(8)) width = args.GetInt(8);
	int height = 200;
	if (args.IsValid(9)) height = args.GetInt(9);
	wxString rtn = wxGetSingleChoiceData(message, caption, *aChoices, client_data[], parent, x, y, centre, width, height);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetSingleChoiceData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "choices[]", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "client_data[]", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "centre", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetSingleChoiceData_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	int n = args.GetInt(2);
	wxString choices[] = wxString::FromUTF8(args.GetString(3));
	wxString client_data[] = wxString::FromUTF8(args.GetString(4));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(5)) parent = Object_wx_Window::GetObject(args, 5)->GetEntity();
	int x = -1;
	if (args.IsValid(6)) x = args.GetInt(6);
	int y = -1;
	if (args.IsValid(7)) y = args.GetInt(7);
	bool centre = true;
	if (args.IsValid(8)) centre = args.GetBoolean(8);
	int width = 150;
	if (args.IsValid(9)) width = args.GetInt(9);
	int height = 200;
	if (args.IsValid(10)) height = args.GetInt(10);
	wxString rtn = wxGetSingleChoiceData(message, caption, n, choices[], client_data[], parent, x, y, centre, width, height);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(IsBusy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsBusy)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxIsBusy();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunctionAlias(MessageBox_, "MessageBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MessageBox_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxT("Message");
	if (args.IsValid(1)) caption = wxString::FromUTF8(args.GetString(1));
	int style = wxOK;
	if (args.IsValid(2)) style = args.GetInt(2);
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = -1;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = -1;
	if (args.IsValid(5)) y = args.GetInt(5);
	int rtn = wxMessageBox(message, caption, style, parent, x, y);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(ShowTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "tipProvider", VTYPE_wx_TipProvider, OCCUR_Once);
	DeclareArg(env, "showAtStartup", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ShowTip)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxTipProvider *tipProvider = Object_wx_TipProvider::GetObject(args, 1)->GetEntity();
	bool showAtStartup = true;
	if (args.IsValid(2)) showAtStartup = args.GetBoolean(2);
	bool rtn = wxShowTip(parent, tipProvider, showAtStartup);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Finite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Finite)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	double x = args.GetDouble(0);
	int rtn = wxFinite(x);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(IsNaN)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsNaN)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	double x = args.GetDouble(0);
	bool rtn = wxIsNaN(x);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(BITMAP)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(BITMAP)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxBITMAP();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ClientDisplayRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(ClientDisplayRect)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	wxClientDisplayRect(x, y, width, height);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetClientDisplayRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetClientDisplayRect)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxRect rtn = wxGetClientDisplayRect();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareFunction(ColourDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourDisplay)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxColourDisplay();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(DisplayDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DisplayDepth)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int rtn = wxDisplayDepth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(DisplaySize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(DisplaySize)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	wxDisplaySize(width, height);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetDisplaySize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetDisplaySize)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxSize rtn = wxGetDisplaySize();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareFunction(DisplaySizeMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(DisplaySizeMM)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	wxDisplaySizeMM(width, height);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetDisplaySizeMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetDisplaySizeMM)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxSize rtn = wxGetDisplaySizeMM();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareFunction(DROP_ICON)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DROP_ICON)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char name = args.GetChar(0);
	wxIconOrCursor rtn = wxDROP_ICON(name);
	return ReturnValue(env, args, Value(new Object_wx_IconOrCursor(new wxIconOrCursor(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ICON)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(ICON)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxICON();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(MakeMetafilePlaceable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "minX", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minY", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxX", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "maxY", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "scale", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MakeMetafilePlaceable)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int minX = args.GetInt(1);
	int minY = args.GetInt(2);
	int maxX = args.GetInt(3);
	int maxY = args.GetInt(4);
	float scale = 1.0;
	if (args.IsValid(5)) scale = args.GetFloat(5);
	bool rtn = wxMakeMetafilePlaceable(filename, minX, minY, maxX, maxY, scale);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_Once);
}

Gura_ImplementFunction(SetCursor)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxCursor *cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	wxSetCursor(*cursor);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterCommand)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString rtn = wxGetPrinterCommand();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString rtn = wxGetPrinterFile();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterMode)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int rtn = wxGetPrinterMode();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterOptions)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString rtn = wxGetPrinterOptions();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterOrientation)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int rtn = wxGetPrinterOrientation();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterPreviewCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterPreviewCommand)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString rtn = wxGetPrinterPreviewCommand();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterScaling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(GetPrinterScaling)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	float x = args.GetFloat(0);
	float y = args.GetFloat(1);
	wxGetPrinterScaling(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterTranslation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(GetPrinterTranslation)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	float x = args.GetFloat(0);
	float y = args.GetFloat(1);
	wxGetPrinterTranslation(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetPrinterCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterCommand)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString command = wxString::FromUTF8(args.GetString(0));
	wxSetPrinterCommand(command);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetPrinterFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterFile)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxSetPrinterFile(filename);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetPrinterMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterMode)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int mode = args.GetInt(0);
	wxSetPrinterMode(mode);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetPrinterOptions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "options", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterOptions)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString options = wxString::FromUTF8(args.GetString(0));
	wxSetPrinterOptions(options);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetPrinterOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterOrientation)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int orientation = args.GetInt(0);
	wxSetPrinterOrientation(orientation);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetPrinterPreviewCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterPreviewCommand)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString command = wxString::FromUTF8(args.GetString(0));
	wxSetPrinterPreviewCommand(command);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetPrinterScaling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterScaling)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	float x = args.GetFloat(0);
	float y = args.GetFloat(1);
	wxSetPrinterScaling(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetPrinterTranslation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterTranslation)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	float x = args.GetFloat(0);
	float y = args.GetFloat(1);
	wxSetPrinterTranslation(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ClipboardOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClipboardOpen)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	bool rtn = wxClipboardOpen();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(CloseClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CloseClipboard)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	bool rtn = wxCloseClipboard();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(EmptyClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EmptyClipboard)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	bool rtn = wxEmptyClipboard();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(EnumClipboardFormats)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EnumClipboardFormats)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	int dataFormat = args.GetInt(0);
	int rtn = wxEnumClipboardFormats(dataFormat);
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(GetClipboardData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetClipboardData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	int dataFormat = args.GetInt(0);
	wxObject *rtn = (wxObject *)wxGetClipboardData(dataFormat);
	return ReturnValue(env, args, Value(new Object_wx_Object(rtn, nullptr, OwnerFalse)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(GetClipboardFormatName_)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "formatName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "maxCount", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetClipboardFormatName_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
#if 0
	int dataFormat = args.GetInt(0);
	wxString formatName = wxString::FromUTF8(args.GetString(1));
	int maxCount = args.GetInt(2);
	bool rtn = wxGetClipboardFormatName(dataFormat, formatName, maxCount);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(IsClipboardFormatAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsClipboardFormatAvailable)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	int dataFormat = args.GetInt(0);
	bool rtn = wxIsClipboardFormatAvailable(dataFormat);
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(OpenClipboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(OpenClipboard)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	bool rtn = wxOpenClipboard();
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(RegisterClipboardFormat_)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "formatName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegisterClipboardFormat_)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
#if 0
	wxString formatName = wxString::FromUTF8(args.GetString(0));
	int rtn = wxRegisterClipboardFormat(formatName);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(SetClipboardData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SetClipboardData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	int dataFormat = args.GetInt(0);
	wxObject *data = Object_wx_Object::GetObject(args, 1)->GetEntity();
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	bool rtn = wxSetClipboardData(dataFormat, data, width, height);
	return ReturnValue(env, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(CONCAT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CONCAT)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCONCAT(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(DYNLIB_FUNCTION)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(DYNLIB_FUNCTION)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxDYNLIB_FUNCTION(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetKeyState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetKeyState)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxKeyCode key = static_cast<wxKeyCode>(args.GetInt(0));
	bool rtn = wxGetKeyState(key);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(LL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LL)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxLongLong_t rtn = wxLL();
	return ReturnValue(env, args, Value(new Object_wx_LongLong_t(new wxLongLong_t(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(NewId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NewId)
{
	Signal &sig = env.GetSignal();
	//if (!CheckWxReady(sig)) return Value::Null;
	long rtn = wxNewId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(NewIds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NewIds)
{
	Signal &sig = env.GetSignal();
	//if (!CheckWxReady(sig)) return Value::Null;
	Iterator *pIterator = new Iterator_NewIds();
	return ReturnIterator(env, args, pIterator);
}

Gura_DeclareFunction(ON_BLOCK_EXIT0)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT0)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxON_BLOCK_EXIT0();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxON_BLOCK_EXIT1(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxON_BLOCK_EXIT2(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT_OBJ0)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT_OBJ0)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxON_BLOCK_EXIT_OBJ0(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT_OBJ1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT_OBJ1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxON_BLOCK_EXIT_OBJ1(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT_OBJ2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT_OBJ2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxON_BLOCK_EXIT_OBJ2(, , , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(RegisterId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(RegisterId)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	long id = args.GetLong(0);
	wxRegisterId(id);
	return Value::Null;
}

Gura_DeclareFunction(DDECleanUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(DDECleanUp)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxDDECleanUp();
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(DDEInitialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(DDEInitialize)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxDDEInitialize();
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(EnableTopLevelWindows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EnableTopLevelWindows)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	wxEnableTopLevelWindows(enable);
	return Value::Null;
}

Gura_DeclareFunction(FindMenuItemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "menuString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "itemString", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindMenuItemId)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxFrame *frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	wxString menuString = wxString::FromUTF8(args.GetString(1));
	wxString itemString = wxString::FromUTF8(args.GetString(2));
	int rtn = wxFindMenuItemId(frame, menuString, itemString);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(FindWindowByLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindWindowByLabel)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(1)) parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxFindWindowByLabel(label, parent);
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareFunction(FindWindowByName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindWindowByName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxWindow *parent = (wxWindow *)(nullptr);
	if (args.IsValid(1)) parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxFindWindowByName(name, parent);
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareFunction(FindWindowAtPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindWindowAtPoint)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxFindWindowAtPoint(*pt);
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareFunction(FindWindowAtPointer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindWindowAtPointer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxFindWindowAtPointer(*pt);
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareFunction(GetActiveWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetActiveWindow)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)wxGetActiveWindow();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareFunction(GetBatteryState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetBatteryState)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxBatteryState rtn = wxGetBatteryState();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(GetDisplayName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetDisplayName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString rtn = wxGetDisplayName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPowerType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPowerType)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxPowerType rtn = wxGetPowerType();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(GetMousePosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetMousePosition)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxPoint rtn = wxGetMousePosition();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareFunction(GetMouseState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetMouseState)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxMouseState rtn = wxGetMouseState();
	return ReturnValue(env, args, Value(new Object_wx_MouseState(new wxMouseState(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareFunction(GetResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetResource)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	wxString value = wxString::FromUTF8(args.GetString(2));
	wxString file = nullptr;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxGetResource(section, entry, value, file);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetResource_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetResource_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	float value = args.GetFloat(2);
	wxString file = nullptr;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxGetResource(section, entry, value, file);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetResource_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetResource_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	long value = args.GetLong(2);
	wxString file = nullptr;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxGetResource(section, entry, value, file);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetResource_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetResource_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	int value = args.GetInt(2);
	wxString file = nullptr;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxGetResource(section, entry, value, file);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetStockLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetStockLabel)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(0));
	long flags = wxSTOCK_WITH_MNEMONIC;
	if (args.IsValid(1)) flags = args.GetLong(1);
	wxString rtn = wxGetStockLabel(id, flags);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetTopLevelParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetTopLevelParent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxGetTopLevelParent(win);
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareFunction(LaunchDefaultBrowser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LaunchDefaultBrowser)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = wxLaunchDefaultBrowser(url, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(LoadUserResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "resourceName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "resourceType", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LoadUserResource)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxString resourceName = wxString::FromUTF8(args.GetString(0));
	wxString resourceType = wxT("TEXT");
	if (args.IsValid(1)) resourceType = wxString::FromUTF8(args.GetString(1));
	wxString rtn = wxLoadUserResource(resourceName, resourceType);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(PostDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "object", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementFunction(PostDelete)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxObject *object = Object_wx_Object::GetObject(args, 0)->GetEntity();
	wxPostDelete(object);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(PostEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dest", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
}

Gura_ImplementFunction(PostEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxEvtHandler *dest = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	wxEvent *event = Object_wx_Event::GetObject(args, 1)->GetEntity();
	wxPostEvent(dest, *event);
	return Value::Null;
}

Gura_DeclareFunction(SetDisplayName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "displayName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetDisplayName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString displayName = wxString::FromUTF8(args.GetString(0));
	wxSetDisplayName(displayName);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(StripMenuCodes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StripMenuCodes)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	int flags = wxStrip_All;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxString rtn = wxStripMenuCodes(str, flags);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(STRINGIZE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(STRINGIZE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxSTRINGIZE();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(STRINGIZE_T)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(STRINGIZE_T)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxSTRINGIZE_T();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SUPPRESS_GCC_PRIVATE_DTOR_WARNING)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(SUPPRESS_GCC_PRIVATE_DTOR_WARNING)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxSUPPRESS_GCC_PRIVATE_DTOR_WARNING();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ULL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ULL)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxLongLong_t rtn = wxULL();
	return ReturnValue(env, args, Value(new Object_wx_LongLong_t(new wxLongLong_t(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(VaCopy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(VaCopy)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxVaCopy(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(WriteResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WriteResource)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	wxString value = wxString::FromUTF8(args.GetString(2));
	wxString file = nullptr;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxWriteResource(section, entry, value, file);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(WriteResource_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WriteResource_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	float value = args.GetFloat(2);
	wxString file = nullptr;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxWriteResource(section, entry, value, file);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(WriteResource_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WriteResource_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	long value = args.GetLong(2);
	wxString file = nullptr;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxWriteResource(section, entry, value, file);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(WriteResource_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WriteResource_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	int value = args.GetInt(2);
	wxString file = nullptr;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxWriteResource(section, entry, value, file);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(INT32_SWAP_ALWAYS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT32_SWAP_ALWAYS)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxInt32 value = static_cast<wxInt32>(args.GetULong(0));
	wxInt32 rtn = wxINT32_SWAP_ALWAYS(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(UINT32_SWAP_ALWAYS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT32_SWAP_ALWAYS)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxUint32 value = static_cast<wxUint32>(args.GetULong(0));
	wxUint32 rtn = wxUINT32_SWAP_ALWAYS(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(INT16_SWAP_ALWAYS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT16_SWAP_ALWAYS)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxInt16 value = static_cast<wxInt16>(args.GetUShort(0));
	wxInt16 rtn = wxINT16_SWAP_ALWAYS(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(UINT16_SWAP_ALWAYS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT16_SWAP_ALWAYS)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxUint16 value = static_cast<wxUint16>(args.GetUShort(0));
	wxUint16 rtn = wxUINT16_SWAP_ALWAYS(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(INT32_SWAP_ON_BE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT32_SWAP_ON_BE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxInt32 value = static_cast<wxInt32>(args.GetULong(0));
	wxInt32 rtn = wxINT32_SWAP_ON_BE(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(UINT32_SWAP_ON_BE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT32_SWAP_ON_BE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxUint32 value = static_cast<wxUint32>(args.GetULong(0));
	wxUint32 rtn = wxUINT32_SWAP_ON_BE(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(INT16_SWAP_ON_BE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT16_SWAP_ON_BE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxInt16 value = static_cast<wxInt16>(args.GetUShort(0));
	wxInt16 rtn = wxINT16_SWAP_ON_BE(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(UINT16_SWAP_ON_BE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT16_SWAP_ON_BE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxUint16 value = static_cast<wxUint16>(args.GetUShort(0));
	wxUint16 rtn = wxUINT16_SWAP_ON_BE(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(INT32_SWAP_ON_LE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT32_SWAP_ON_LE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxInt32 value = static_cast<wxInt32>(args.GetULong(0));
	wxInt32 rtn = wxINT32_SWAP_ON_LE(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(UINT32_SWAP_ON_LE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT32_SWAP_ON_LE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxUint32 value = static_cast<wxUint32>(args.GetULong(0));
	wxUint32 rtn = wxUINT32_SWAP_ON_LE(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(INT16_SWAP_ON_LE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT16_SWAP_ON_LE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxInt16 value = static_cast<wxInt16>(args.GetUShort(0));
	wxInt16 rtn = wxINT16_SWAP_ON_LE(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(UINT16_SWAP_ON_LE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT16_SWAP_ON_LE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxUint16 value = static_cast<wxUint16>(args.GetUShort(0));
	wxUint16 rtn = wxUINT16_SWAP_ON_LE(value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(DebugMsg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fmt", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(DebugMsg)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString fmt = wxString::FromUTF8(args.GetString(0));
	wxDebugMsg(fmt, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Error)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Error)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString msg = wxString::FromUTF8(args.GetString(0));
	wxString title = wxT("wxWidgets Internal Error");
	if (args.IsValid(1)) title = wxString::FromUTF8(args.GetString(1));
	wxError(msg, title);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FatalError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FatalError)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString msg = wxString::FromUTF8(args.GetString(0));
	wxString title = wxT("wxWidgets Fatal Error");
	if (args.IsValid(1)) title = wxString::FromUTF8(args.GetString(1));
	wxFatalError(msg, title);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(LogError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogError)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogError(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogFatalError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogFatalError)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogFatalError(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogWarning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogWarning)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogWarning(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogMessage)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogMessage(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogVerbose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogVerbose)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogVerbose(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once, FLAG_NoCast);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogStatus)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogStatus(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogStatusEx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogStatusEx)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxFrame *frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	const char *formatString = args.GetString(1);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(2)).c_str());
	wxLogStatus(frame, wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogSysError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogSysError)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogSysError(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogDebug)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogDebug)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogDebug(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogTrace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogTrace)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::FormatValueList(
								sig, formatString, args.GetList(1)).c_str());
	wxLogTrace(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogTrace_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(LogTrace_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char mask = args.GetChar(0);
	char formatString = args.GetChar(1);
	wxLogTrace(mask, formatString, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(LogTrace_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "mask", VTYPE_wx_TraceMask, OCCUR_Once);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementFunction(LogTrace_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxTraceMask *mask = Object_wx_TraceMask::GetObject(args, 0)->GetEntity();
	char formatString = args.GetChar(1);
	wxLogTrace(*mask, formatString, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SafeShowMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SafeShowMessage)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	wxString text = wxString::FromUTF8(args.GetString(1));
	wxSafeShowMessage(title, text);
	return Value::Null;
}

Gura_DeclareFunction(SysErrorCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SysErrorCode)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned rtn = wxSysErrorCode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(SysErrorMsg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "errCode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SysErrorMsg)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	unsigned errCode = 0;
	if (args.IsValid(0)) errCode = args.GetInt(0);
	wxChar rtn = wxSysErrorMsg(errCode);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Trace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fmt", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(Trace)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString fmt = wxString::FromUTF8(args.GetString(0));
	wxTrace(fmt, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(TraceLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "fmt", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(TraceLevel)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int level = args.GetInt(0);
	wxString fmt = wxString::FromUTF8(args.GetString(1));
	wxTraceLevel(level, fmt, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetElapsedTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "resetTimer", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetElapsedTime)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	bool resetTimer = true;
	if (args.IsValid(0)) resetTimer = args.GetBoolean(0);
	long rtn = wxGetElapsedTime(resetTimer);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetLocalTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetLocalTime)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	long rtn = wxGetLocalTime();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(GetLocalTimeMillis)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetLocalTimeMillis)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxLongLong rtn = wxGetLocalTimeMillis();
	return ReturnValue(env, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareFunction(GetUTCTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUTCTime)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	long rtn = wxGetUTCTime();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(MicroSleep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "microseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(MicroSleep)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned microseconds = args.GetInt(0);
	wxMicroSleep(microseconds);
	return Value::Null;
}

Gura_DeclareFunction(MilliSleep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(MilliSleep)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned milliseconds = args.GetInt(0);
	wxMilliSleep(milliseconds);
	return Value::Null;
}

Gura_DeclareFunction(Now)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Now)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxNow();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(Sleep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "secs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(Sleep)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int secs = args.GetInt(0);
	wxSleep(secs);
	return Value::Null;
}

Gura_DeclareFunction(StartTimer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(StartTimer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxStartTimer();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Usleep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(Usleep)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned milliseconds = args.GetInt(0);
	wxUsleep(milliseconds);
	return Value::Null;
}

Gura_DeclareFunction(OnAssert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "lineNumber", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "func", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "cond", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "msg", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(OnAssert)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	char fileName = args.GetChar(0);
	int lineNumber = args.GetInt(1);
	char func = args.GetChar(2);
	char cond = args.GetChar(3);
	char msg = nullptr;
	if (args.IsValid(4)) msg = args.GetChar(4);
	wxOnAssert(fileName, lineNumber, func, cond, msg);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ASSERT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ASSERT)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxASSERT();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ASSERT_MIN_BITSIZE)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ASSERT_MIN_BITSIZE)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxASSERT_MIN_BITSIZE(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ASSERT_MSG)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "condition", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(ASSERT_MSG)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool condition = args.GetBoolean(0);
	wxString msg = wxString::FromUTF8(args.GetString(1));
	wxASSERT_MSG(condition, msg);
	return Value::Null;
}

Gura_DeclareFunction(COMPILE_TIME_ASSERT)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(COMPILE_TIME_ASSERT)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCOMPILE_TIME_ASSERT(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(COMPILE_TIME_ASSERT2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(COMPILE_TIME_ASSERT2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCOMPILE_TIME_ASSERT(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FAIL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(FAIL)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	//wxFAIL();
	return Value::Null;
}

Gura_DeclareFunction(FAIL_MSG)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(FAIL_MSG)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString msg = wxString::FromUTF8(args.GetString(0));
	wxFAIL_MSG(msg);
	return Value::Null;
}

Gura_DeclareFunction(CHECK)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCHECK(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHECK_MSG)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK_MSG)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCHECK_MSG(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHECK_RET)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK_RET)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCHECK_RET(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHECK2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCHECK2(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHECK2_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK2_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxCHECK2(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Trap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(Trap)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxTrap();
	return Value::Null;
}

Gura_DeclareFunction(IsDebuggerRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsDebuggerRunning)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxIsDebuggerRunning();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(GetEnv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "var", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetEnv)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString var = wxString::FromUTF8(args.GetString(0));
	wxString value;
	bool rtn = wxGetEnv(var, &value);
	Value valueRtn;
	if (rtn) {
		valueRtn = Value(value.ToUTF8());
	}
	return ReturnValue(env, args, valueRtn);
}

Gura_DeclareFunction(SetEnv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "var", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SetEnv)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString var = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	bool rtn = wxSetEnv(var, value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(UnsetEnv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "var", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UnsetEnv)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxString var = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxUnsetEnv(var);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Isalnum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isalnum)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIsalnum(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Isalpha)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isalpha)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIsalpha(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Iscntrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Iscntrl)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIscntrl(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Isdigit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isdigit)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIsdigit(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Isgraph)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isgraph)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIsgraph(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Islower)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Islower)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIslower(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Isprint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isprint)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIsprint(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Ispunct)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Ispunct)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIspunct(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Isspace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isspace)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIsspace(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Isupper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isupper)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIsupper(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Isxdigit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isxdigit)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	bool rtn = wxIsxdigit(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Tolower)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Tolower)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	wxChar rtn = wxTolower(c);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareFunction(Toupper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Toupper)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int c = args.GetInt(0);
	wxChar rtn = wxToupper(c);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for 
//----------------------------------------------------------------------------
void RegisterFunctions(Environment &env, Signal &sig)
{
	_pEnv = &env;
	Gura_RealizeUserSymbol(GetApp);
	Gura_AssignFunction(IMPLEMENT_APP);
	Gura_AssignFunction(BusyCursor);
	Gura_AssignFunction(CaretSuspend);
	Gura_AssignFunction(ClipboardLocker);
	//Gura_AssignFunction(DynamicCast);
	Gura_AssignFunction(CHECK_GCC_VERSION);
	Gura_AssignFunction(CHECK_VERSION);
	Gura_AssignFunction(CHECK_VERSION_FULL);
	Gura_AssignFunction(CHECK_W32API_VERSION);
	Gura_AssignFunction(Entry);
	Gura_AssignFunction(Entry_1);
	Gura_AssignFunction(EntryCleanup);
	Gura_AssignFunction(EntryStart);
	Gura_AssignFunction(HandleFatalExceptions);
	Gura_AssignFunction(InitAllImageHandlers);
	Gura_AssignFunction(Initialize);
	Gura_AssignFunction(SafeYield);
	Gura_AssignFunction(Uninitialize);
	Gura_AssignFunction(Yield);
	Gura_AssignFunction(WakeUpIdle);
	Gura_AssignFunction(Execute);
	Gura_AssignFunction(Execute_1);
	Gura_AssignFunction(Execute_2);
	Gura_AssignFunction(Execute_3);
	Gura_AssignFunction(Exit);
	Gura_AssignFunction(Kill);
	Gura_AssignFunction(GetProcessId);
	Gura_AssignFunction(Shell);
	Gura_AssignFunction(Shutdown);
	Gura_AssignFunction(CRIT_SECT_DECLARE);
	Gura_AssignFunction(CRIT_SECT_DECLARE_1);
	Gura_AssignFunction(CRIT_SECT_LOCKER);
	Gura_AssignFunction(CRITICAL_SECTION);
	Gura_AssignFunction(ENTER_CRIT_SECT);
	Gura_AssignFunction(IsMainThread);
	Gura_AssignFunction(LEAVE_CRIT_SECT);
	Gura_AssignFunction(MutexGuiEnter);
	Gura_AssignFunction(MutexGuiLeave);
	Gura_AssignFunction(Dos2UnixFilename);
	Gura_AssignFunction(FileExists);
	Gura_AssignFunction(FileModificationTime);
	Gura_AssignFunction(FileNameFromPath);
	Gura_AssignFunction(FileNameFromPath_1);
	Gura_AssignFunction(FindFirstFile_);
	Gura_AssignFunction(FindNextFile_);
	Gura_AssignFunction(GetDiskSpace);
	Gura_AssignFunction(GetFileKind);
	Gura_AssignFunction(GetFileKind_1);
	Gura_AssignFunction(GetOSDirectory);
	Gura_AssignFunction(IsAbsolutePath);
	Gura_AssignFunction(DirExists);
	Gura_AssignFunction(PathOnly);
	Gura_AssignFunction(Unix2DosFilename);
	Gura_AssignFunction(CHANGE_UMASK);
	Gura_AssignFunction(ConcatFiles);
	Gura_AssignFunction(CopyFile_);
	Gura_AssignFunction(GetCwd);
	Gura_AssignFunction(IsWild);
	Gura_AssignFunction(MatchWild);
	Gura_AssignFunction(Mkdir);
	Gura_AssignFunction(ParseCommonDialogsFilter);
	Gura_AssignFunction(RemoveFile);
	Gura_AssignFunction(RenameFile);
	Gura_AssignFunction(Rmdir);
	Gura_AssignFunction(SetWorkingDirectory);
	Gura_AssignFunction(SplitPath);
	Gura_AssignFunction(TransferFileToStream);
	Gura_AssignFunction(TransferStreamToFile);
	Gura_AssignFunction(GetEmailAddress);
	Gura_AssignFunction(GetEmailAddress_1);
	Gura_AssignFunction(GetFreeMemory);
	Gura_AssignFunction(GetFullHostName);
	Gura_AssignFunction(GetHomeDir);
	Gura_AssignFunction(GetHostName);
	Gura_AssignFunction(GetOsDescription);
	Gura_AssignFunction(GetOsVersion);
	Gura_AssignFunction(IsPlatformLittleEndian);
	Gura_AssignFunction(IsPlatform64Bit);
	Gura_AssignFunction(GetUserHome);
	Gura_AssignFunction(GetUserId);
	Gura_AssignFunction(GetUserId_1);
	Gura_AssignFunction(GetUserName_);
	Gura_AssignFunction(GetUserName__1);
	Gura_AssignFunction(copystring);
	Gura_AssignFunctionEx(GetTranslation, "_");
	Gura_AssignFunction(GetTranslation);
	Gura_AssignFunction(GetTranslation_1);
	Gura_AssignFunction(IsEmpty);
	Gura_AssignFunction(Strcmp);
	Gura_AssignFunction(Stricmp);
	Gura_AssignFunction(StringEq);
	Gura_AssignFunction(StringMatch);
	Gura_AssignFunction(StringTokenize);
	Gura_AssignFunction(Strlen);
	Gura_AssignFunction(Snprintf);
	Gura_AssignFunction(TRANSLATE);
	Gura_AssignFunction(Vsnprintf);
	Gura_AssignFunction(PLURAL);
	Gura_AssignFunction(AboutBox);
	Gura_AssignFunction(BeginBusyCursor);
	Gura_AssignFunction(Bell);
	Gura_AssignFunction(CreateFileTipProvider);
	Gura_AssignFunction(DirSelector);
	Gura_AssignFunction(FileSelector);
	Gura_AssignFunction(EndBusyCursor);
	Gura_AssignFunction(GenericAboutBox);
	Gura_AssignFunction(GetColourFromUser);
	Gura_AssignFunction(GetFontFromUser);
	Gura_AssignFunction(GetMultipleChoices);
	Gura_AssignFunction(GetNumberFromUser);
	Gura_AssignFunction(GetPasswordFromUser);
	Gura_AssignFunction(GetTextFromUser);
	Gura_AssignFunction(GetSingleChoice);
	Gura_AssignFunction(GetSingleChoiceIndex);
	Gura_AssignFunction(GetSingleChoiceData);
	Gura_AssignFunction(GetSingleChoiceData_1);
	Gura_AssignFunction(IsBusy);
	Gura_AssignFunction(MessageBox_);
	Gura_AssignFunction(ShowTip);
	Gura_AssignFunction(Finite);
	Gura_AssignFunction(IsNaN);
	Gura_AssignFunction(BITMAP);
	Gura_AssignFunction(ClientDisplayRect);
	Gura_AssignFunction(GetClientDisplayRect);
	Gura_AssignFunction(ColourDisplay);
	Gura_AssignFunction(DisplayDepth);
	Gura_AssignFunction(DisplaySize);
	Gura_AssignFunction(GetDisplaySize);
	Gura_AssignFunction(DisplaySizeMM);
	Gura_AssignFunction(GetDisplaySizeMM);
	Gura_AssignFunction(DROP_ICON);
	Gura_AssignFunction(ICON);
	Gura_AssignFunction(MakeMetafilePlaceable);
	Gura_AssignFunction(SetCursor);
	Gura_AssignFunction(GetPrinterCommand);
	Gura_AssignFunction(GetPrinterFile);
	Gura_AssignFunction(GetPrinterMode);
	Gura_AssignFunction(GetPrinterOptions);
	Gura_AssignFunction(GetPrinterOrientation);
	Gura_AssignFunction(GetPrinterPreviewCommand);
	Gura_AssignFunction(GetPrinterScaling);
	Gura_AssignFunction(GetPrinterTranslation);
	Gura_AssignFunction(SetPrinterCommand);
	Gura_AssignFunction(SetPrinterFile);
	Gura_AssignFunction(SetPrinterMode);
	Gura_AssignFunction(SetPrinterOptions);
	Gura_AssignFunction(SetPrinterOrientation);
	Gura_AssignFunction(SetPrinterPreviewCommand);
	Gura_AssignFunction(SetPrinterScaling);
	Gura_AssignFunction(SetPrinterTranslation);
	Gura_AssignFunction(ClipboardOpen);
	Gura_AssignFunction(CloseClipboard);
	Gura_AssignFunction(EmptyClipboard);
	Gura_AssignFunction(EnumClipboardFormats);
	Gura_AssignFunction(GetClipboardData);
	Gura_AssignFunction(GetClipboardFormatName_);
	Gura_AssignFunction(IsClipboardFormatAvailable);
	Gura_AssignFunction(OpenClipboard);
	Gura_AssignFunction(RegisterClipboardFormat_);
	Gura_AssignFunction(SetClipboardData);
	Gura_AssignFunction(CONCAT);
	Gura_AssignFunction(DYNLIB_FUNCTION);
	Gura_AssignFunction(GetKeyState);
	Gura_AssignFunction(LL);
	Gura_AssignFunction(NewId);
	Gura_AssignFunction(NewIds);
	Gura_AssignFunction(ON_BLOCK_EXIT0);
	Gura_AssignFunction(ON_BLOCK_EXIT1);
	Gura_AssignFunction(ON_BLOCK_EXIT2);
	Gura_AssignFunction(ON_BLOCK_EXIT_OBJ0);
	Gura_AssignFunction(ON_BLOCK_EXIT_OBJ1);
	Gura_AssignFunction(ON_BLOCK_EXIT_OBJ2);
	Gura_AssignFunction(RegisterId);
	Gura_AssignFunction(DDECleanUp);
	Gura_AssignFunction(DDEInitialize);
	Gura_AssignFunction(EnableTopLevelWindows);
	Gura_AssignFunction(FindMenuItemId);
	Gura_AssignFunction(FindWindowByLabel);
	Gura_AssignFunction(FindWindowByName);
	Gura_AssignFunction(FindWindowAtPoint);
	Gura_AssignFunction(FindWindowAtPointer);
	Gura_AssignFunction(GetActiveWindow);
	Gura_AssignFunction(GetBatteryState);
	Gura_AssignFunction(GetDisplayName);
	Gura_AssignFunction(GetPowerType);
	Gura_AssignFunction(GetMousePosition);
	Gura_AssignFunction(GetMouseState);
	Gura_AssignFunction(GetResource);
	Gura_AssignFunction(GetResource_1);
	Gura_AssignFunction(GetResource_2);
	Gura_AssignFunction(GetResource_3);
	Gura_AssignFunction(GetStockLabel);
	Gura_AssignFunction(GetTopLevelParent);
	Gura_AssignFunction(LaunchDefaultBrowser);
	Gura_AssignFunction(LoadUserResource);
	Gura_AssignFunction(PostDelete);
	Gura_AssignFunction(PostEvent);
	Gura_AssignFunction(SetDisplayName);
	Gura_AssignFunction(StripMenuCodes);
	Gura_AssignFunction(STRINGIZE);
	Gura_AssignFunction(STRINGIZE_T);
	Gura_AssignFunction(SUPPRESS_GCC_PRIVATE_DTOR_WARNING);
	Gura_AssignFunction(ULL);
	Gura_AssignFunction(VaCopy);
	Gura_AssignFunction(WriteResource);
	Gura_AssignFunction(WriteResource_1);
	Gura_AssignFunction(WriteResource_2);
	Gura_AssignFunction(WriteResource_3);
	Gura_AssignFunction(INT32_SWAP_ALWAYS);
	Gura_AssignFunction(UINT32_SWAP_ALWAYS);
	Gura_AssignFunction(INT16_SWAP_ALWAYS);
	Gura_AssignFunction(UINT16_SWAP_ALWAYS);
	Gura_AssignFunction(INT32_SWAP_ON_BE);
	Gura_AssignFunction(UINT32_SWAP_ON_BE);
	Gura_AssignFunction(INT16_SWAP_ON_BE);
	Gura_AssignFunction(UINT16_SWAP_ON_BE);
	Gura_AssignFunction(INT32_SWAP_ON_LE);
	Gura_AssignFunction(UINT32_SWAP_ON_LE);
	Gura_AssignFunction(INT16_SWAP_ON_LE);
	Gura_AssignFunction(UINT16_SWAP_ON_LE);
	Gura_AssignFunction(DebugMsg);
	Gura_AssignFunction(Error);
	Gura_AssignFunction(FatalError);
	Gura_AssignFunction(LogError);
	Gura_AssignFunction(LogFatalError);
	Gura_AssignFunction(LogWarning);
	Gura_AssignFunction(LogMessage);
	Gura_AssignFunction(LogVerbose);
	Gura_AssignFunction(LogStatus);
	Gura_AssignFunction(LogStatusEx);
	Gura_AssignFunction(LogSysError);
	Gura_AssignFunction(LogDebug);
	Gura_AssignFunction(LogTrace);
	Gura_AssignFunction(LogTrace_1);
	Gura_AssignFunction(LogTrace_2);
	Gura_AssignFunction(SafeShowMessage);
	Gura_AssignFunction(SysErrorCode);
	Gura_AssignFunction(SysErrorMsg);
	Gura_AssignFunction(Trace);
	Gura_AssignFunction(TraceLevel);
	Gura_AssignFunction(GetElapsedTime);
	Gura_AssignFunction(GetLocalTime);
	Gura_AssignFunction(GetLocalTimeMillis);
	Gura_AssignFunction(GetUTCTime);
	Gura_AssignFunction(MicroSleep);
	Gura_AssignFunction(MilliSleep);
	Gura_AssignFunction(Now);
	Gura_AssignFunction(Sleep);
	Gura_AssignFunction(StartTimer);
	Gura_AssignFunction(Usleep);
	Gura_AssignFunction(OnAssert);
	Gura_AssignFunction(ASSERT);
	Gura_AssignFunction(ASSERT_MIN_BITSIZE);
	Gura_AssignFunction(ASSERT_MSG);
	Gura_AssignFunction(COMPILE_TIME_ASSERT);
	Gura_AssignFunction(COMPILE_TIME_ASSERT2);
	Gura_AssignFunction(FAIL);
	Gura_AssignFunction(FAIL_MSG);
	Gura_AssignFunction(CHECK);
	Gura_AssignFunction(CHECK_MSG);
	Gura_AssignFunction(CHECK_RET);
	Gura_AssignFunction(CHECK2);
	Gura_AssignFunction(CHECK2_1);
	Gura_AssignFunction(Trap);
	Gura_AssignFunction(IsDebuggerRunning);
	Gura_AssignFunction(GetEnv);
	Gura_AssignFunction(SetEnv);
	Gura_AssignFunction(UnsetEnv);
	Gura_AssignFunction(Isalnum);
	Gura_AssignFunction(Isalpha);
	Gura_AssignFunction(Iscntrl);
	Gura_AssignFunction(Isdigit);
	Gura_AssignFunction(Isgraph);
	Gura_AssignFunction(Islower);
	Gura_AssignFunction(Isprint);
	Gura_AssignFunction(Ispunct);
	Gura_AssignFunction(Isspace);
	Gura_AssignFunction(Isupper);
	Gura_AssignFunction(Isxdigit);
	Gura_AssignFunction(Tolower);
	Gura_AssignFunction(Toupper);
}

Gura_EndModuleScope(wx)
