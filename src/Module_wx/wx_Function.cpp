//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(GetApp);

static Environment *_pEnv = NULL;

Gura_DeclareFunction(IMPLEMENT_APP)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "constructor", VTYPE_function, OCCUR_Once);
}

Gura_ImplementFunction(IMPLEMENT_APP)
{
	const Function *pFunc = args.GetFunction(0);
	Args argsSub(ValueList::Null);
	Value rtn = pFunc->Eval(env, sig, argsSub);
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
		char *argv[1] = { NULL };
		::wxEntry(argc, argv);
	} while (0);
	return Value::Null;
}

Gura_DeclareFunction(BusyCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(BusyCursor)
{
	::wxBeginBusyCursor();
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Value rtn = pExprBlock->Exec(env, sig);
	::wxEndBusyCursor();
	return rtn;
}

Gura_DeclareFunction(CaretSuspend)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(CaretSuspend)
{
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxCaretSuspend cs(win);
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	Value rtn = pExprBlock->Exec(env, sig);
	return rtn;
}

#if 0
Gura_DeclareFunction(DynamicCast)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ptr", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "classname", VTYPE_Class, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DynamicCast)
{
	Object_wx_Object *pObj = Object_wx_Object::GetObject(args, 0);
	Class *pClass = args.GetClass(1);
	Object_wx_Object *pObjNew = new Object_wx_Object(Class::Reference(pClass),
											pObj->GetEntity(), NULL, OwnerFalse);
	return ReturnValue(env, sig, args, Value(pObjNew));
}
#endif

Gura_DeclareFunction(CHECK_GCC_VERSION)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CHECK_GCC_VERSION)
{
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	bool rtn = wxCHECK_GCC_VERSION(major, minor);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(CHECK_VERSION)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "release", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CHECK_VERSION)
{
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	int release = args.GetInt(2);
	bool rtn = wxCHECK_VERSION(major, minor, release);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(CHECK_VERSION_FULL)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "release", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "subrel", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CHECK_VERSION_FULL)
{
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	int release = args.GetInt(2);
	int subrel = args.GetInt(3);
	bool rtn = wxCHECK_VERSION_FULL(major, minor, release, subrel);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(CHECK_W32API_VERSION)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CHECK_W32API_VERSION)
{
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	bool rtn = wxCHECK_W32API_VERSION(major, minor);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Entry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Entry)
{
#if 0
	int argc = args.GetInt(0);
	wxChar argv = static_cast<wxChar>(args.GetInt(1));
	int rtn = wxEntry(argc, argv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Entry_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pCmdLine", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "nCmdShow", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Entry_1)
{
#if 0
	char pCmdLine = ;
	if (args.IsValid(2)) pCmdLine = args.GetChar(2);
	int nCmdShow = SW_SHOWNORMAL;
	if (args.IsValid(3)) nCmdShow = args.GetInt(3);
	int rtn = wxEntry(, , pCmdLine, nCmdShow);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(EntryCleanup)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(EntryCleanup)
{
	wxEntryCleanup();
	return Value::Null;
}

Gura_DeclareFunction(EntryStart)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EntryStart)
{
#if 0
	int argc = args.GetInt(0);
	wxChar argv = static_cast<wxChar>(args.GetInt(1));
	bool rtn = wxEntryStart(argc, argv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(HandleFatalExceptions)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "doIt", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HandleFatalExceptions)
{
#if defined(__WXMSW__)
	bool doIt = true;
	if (args.IsValid(0)) doIt = args.GetBoolean(0);
	bool rtn = wxHandleFatalExceptions(doIt);
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif
}

Gura_DeclareFunction(InitAllImageHandlers)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(InitAllImageHandlers)
{
	wxInitAllImageHandlers();
	return Value::Null;
}

Gura_DeclareFunction(Initialize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Initialize)
{
	bool rtn = wxInitialize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(SafeYield)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "onlyIfNeeded", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SafeYield)
{
	wxWindow *win = (wxWindow *)(NULL);
	if (args.IsValid(0)) win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool onlyIfNeeded = false;
	if (args.IsValid(1)) onlyIfNeeded = args.GetBoolean(1);
	bool rtn = wxSafeYield(win, onlyIfNeeded);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Uninitialize)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(Uninitialize)
{
	wxUninitialize();
	return Value::Null;
}

Gura_DeclareFunction(Yield)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Yield)
{
	bool rtn = wxYield();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(WakeUpIdle)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(WakeUpIdle)
{
	wxWakeUpIdle();
	return Value::Null;
}

Gura_DeclareFunction(Execute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "sync", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "callback", VTYPE_wx_Process, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Execute)
{
	wxString command = wxString::FromUTF8(args.GetString(0));
	int sync = wxEXEC_ASYNC;
	if (args.IsValid(1)) sync = args.GetInt(1);
	wxProcess *callback = (wxProcess *)(NULL);
	if (args.IsValid(2)) callback = Object_wx_Process::GetObject(args, 2)->GetEntity();
	long rtn = wxExecute(command, sync, callback);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Execute_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "callback", VTYPE_wx_Process, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Execute_1)
{
#if 0
	char argv = args.GetChar(0);
	int flags = wxEXEC_ASYNC;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxProcess *callback = (wxProcess *)(NULL);
	if (args.IsValid(2)) callback = Object_wx_Process::GetObject(args, 2)->GetEntity();
	long rtn = wxExecute(argv, flags, callback);
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_NotImplemented(sig);
	return Value::Null;
#endif
}

Gura_DeclareFunction(Execute_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Execute_2)
{
	wxString command = wxString::FromUTF8(args.GetString(0));
	std::auto_ptr<wxArrayString> output(CreateArrayString(args.GetList(1)));
	int flags = 0;
	if (args.IsValid(2)) flags = args.GetInt(2);
	long rtn = wxExecute(command, *output, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Execute_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "errors", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Execute_3)
{
	wxString command = wxString::FromUTF8(args.GetString(0));
	std::auto_ptr<wxArrayString> output(CreateArrayString(args.GetList(1)));
	std::auto_ptr<wxArrayString> errors(CreateArrayString(args.GetList(2)));
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	long rtn = wxExecute(command, *output, *errors, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Exit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(Exit)
{
	wxExit();
	return Value::Null;
}

Gura_DeclareFunction(Kill)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sig", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "*rc", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Kill)
{
#if 0
	long pid = args.GetLong(0);
	int sig = wxSIGTERM;
	if (args.IsValid(1)) sig = args.GetInt(1);
	wxKillError *rc = NULL;
	if (args.IsValid(2)) *rc = static_cast<wxKillError>(args.GetInt(2));
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	int rtn = wxKill(pid, sig, *rc, flags);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetProcessId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetProcessId)
{
	unsigned rtn = wxGetProcessId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Shell)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Shell)
{
#if 0
	wxString command = NULL;
	if (args.IsValid(0)) command = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxShell(command);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Shutdown)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_wx_ShutdownFlags, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Shutdown)
{
#if 0
	wxShutdownFlags *flags = Object_wx_ShutdownFlags::GetObject(args, 0)->GetEntity();
	bool rtn = wxShutdown(*flags);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CRIT_SECT_DECLARE)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CRIT_SECT_DECLARE)
{
#if 0
	wxCRIT_SECT_DECLARE();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CRIT_SECT_DECLARE_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CRIT_SECT_DECLARE_1)
{
#if 0
	wxCRIT_SECT_DECLARE();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CRIT_SECT_LOCKER)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CRIT_SECT_LOCKER)
{
#if 0
	wxCRIT_SECT_LOCKER(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CRITICAL_SECTION)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CRITICAL_SECTION)
{
#if 0
	wxCRITICAL_SECTION();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ENTER_CRIT_SECT)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cs", VTYPE_wx_CriticalSection, OCCUR_Once);
}

Gura_ImplementFunction(ENTER_CRIT_SECT)
{
	wxCriticalSection *cs = Object_wx_CriticalSection::GetObject(args, 0)->GetEntity();
	wxENTER_CRIT_SECT(*cs);
	return Value::Null;
}

Gura_DeclareFunction(IsMainThread)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsMainThread)
{
#if defined(__WXMSW__)
	bool rtn = wxIsMainThread();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif
}

Gura_DeclareFunction(LEAVE_CRIT_SECT)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cs", VTYPE_wx_CriticalSection, OCCUR_Once);
}

Gura_ImplementFunction(LEAVE_CRIT_SECT)
{
	wxCriticalSection *cs = Object_wx_CriticalSection::GetObject(args, 0)->GetEntity();
	wxLEAVE_CRIT_SECT(*cs);
	return Value::Null;
}

Gura_DeclareFunction(MutexGuiEnter)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(MutexGuiEnter)
{
	wxMutexGuiEnter();
	return Value::Null;
}

Gura_DeclareFunction(MutexGuiLeave)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(MutexGuiLeave)
{
	wxMutexGuiLeave();
	return Value::Null;
}

Gura_DeclareFunction(Dos2UnixFilename)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(Dos2UnixFilename)
{
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileExists)
{
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileExists(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(FileModificationTime)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileModificationTime)
{
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FileNameFromPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileNameFromPath)
{
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxFileNameFromPath(path);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(FileNameFromPath_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileNameFromPath_1)
{
#if 0
	char path = args.GetChar(0);
	char rtn = wxFileNameFromPath(path);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FindFirstFile_)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "spec", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindFirstFile_)
{
#if 0
	char spec = args.GetChar(0);
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxString rtn = wxFindFirstFile(spec, flags);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FindNextFile_)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindNextFile_)
{
	wxString rtn = wxFindNextFile();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetDiskSpace)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "*total", VTYPE_wx_LongLong, OCCUR_ZeroOrOnce);
	DeclareArg(env, "*free", VTYPE_wx_LongLong, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetDiskSpace)
{
#if 0
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxLongLong **total = (wxLongLong *)(&NULL);
	if (args.IsValid(1)) *total = Object_wx_LongLong::GetObject(args, 1)->GetEntity();
	wxLongLong **free = (wxLongLong *)(&NULL);
	if (args.IsValid(2)) *free = Object_wx_LongLong::GetObject(args, 2)->GetEntity();
	bool rtn = wxGetDiskSpace(path, **total, **free);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetFileKind)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fd", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFileKind)
{
#if 0
	int fd = args.GetInt(0);
	wxFileKind rtn = wxGetFileKind(fd);
	return ReturnValue(env, sig, args, Value(new Object_wx_FileKind(new wxFileKind(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetFileKind_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFileKind_1)
{
#if 0
	wxFileKind rtn = wxGetFileKind();
	return ReturnValue(env, sig, args, Value(new Object_wx_FileKind(new wxFileKind(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetOSDirectory)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetOSDirectory)
{
	wxString rtn = wxGetOSDirectory();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(IsAbsolutePath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsAbsolutePath)
{
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxIsAbsolutePath(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(DirExists)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DirExists)
{
	wxString dirname = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxDirExists(dirname);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(PathOnly)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PathOnly)
{
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxPathOnly(path);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(Unix2DosFilename)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(Unix2DosFilename)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(CHANGE_UMASK)
{
	int mask = args.GetInt(0);
	wxCHANGE_UMASK(mask);
	return Value::Null;
}

Gura_DeclareFunction(ConcatFiles)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file2", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file3", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ConcatFiles)
{
	wxString file1 = wxString::FromUTF8(args.GetString(0));
	wxString file2 = wxString::FromUTF8(args.GetString(1));
	wxString file3 = wxString::FromUTF8(args.GetString(2));
	bool rtn = wxConcatFiles(file1, file2, file3);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(CopyFile_)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file2", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "overwrite", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CopyFile_)
{
	wxString file1 = wxString::FromUTF8(args.GetString(0));
	wxString file2 = wxString::FromUTF8(args.GetString(1));
	bool overwrite = true;
	if (args.IsValid(2)) overwrite = args.GetBoolean(2);
	bool rtn = wxCopyFile(file1, file2, overwrite);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetCwd)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetCwd)
{
	wxString rtn = wxGetCwd();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(IsWild)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsWild)
{
	wxString pattern = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxIsWild(pattern);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(MatchWild)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dot_special", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MatchWild)
{
	wxString pattern = wxString::FromUTF8(args.GetString(0));
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool dot_special = args.GetBoolean(2);
	bool rtn = wxMatchWild(pattern, text, dot_special);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Mkdir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "perm", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Mkdir)
{
	wxString dir = wxString::FromUTF8(args.GetString(0));
	int perm = 0777;
	if (args.IsValid(1)) perm = args.GetInt(1);
	bool rtn = wxMkdir(dir, perm);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(ParseCommonDialogsFilter)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wildCard", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "descriptions", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "filters", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ParseCommonDialogsFilter)
{
	wxString wildCard = wxString::FromUTF8(args.GetString(0));
	std::auto_ptr<wxArrayString> descriptions(CreateArrayString(args.GetList(1)));
	std::auto_ptr<wxArrayString> filters(CreateArrayString(args.GetList(2)));
	int rtn = wxParseCommonDialogsFilter(wildCard, *descriptions, *filters);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(RemoveFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RemoveFile)
{
	wxString file = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxRemoveFile(file);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(RenameFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file2", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "overwrite", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RenameFile)
{
	wxString file1 = wxString::FromUTF8(args.GetString(0));
	wxString file2 = wxString::FromUTF8(args.GetString(1));
	bool overwrite = true;
	if (args.IsValid(2)) overwrite = args.GetBoolean(2);
	bool rtn = wxRenameFile(file1, file2, overwrite);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Rmdir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Rmdir)
{
	wxString dir = wxString::FromUTF8(args.GetString(0));
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = wxRmdir(dir, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(SetWorkingDirectory)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SetWorkingDirectory)
{
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxSetWorkingDirectory(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(SplitPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fullname", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SplitPath)
{
	wxString fullname = wxString::FromUTF8(args.GetString(0));
	wxString path;
	wxString name;
	wxString ext;
	wxSplitPath(fullname, &path, &name, &ext);
	return Value::CreateAsList(env, Value(env, path.ToUTF8()),
					Value(env, name.ToUTF8()), Value(env, ext.ToUTF8()));
}

Gura_DeclareFunction(TransferFileToStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TransferFileToStream)
{
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	Stream & stream = args.GetStream(1);
	bool rtn = wxTransferFileToStream(filename, stream);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(TransferStreamToFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TransferStreamToFile)
{
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(1));
	bool rtn = wxTransferStreamToFile(, filename);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetEmailAddress)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetEmailAddress)
{
	wxString rtn = wxGetEmailAddress();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetEmailAddress_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetEmailAddress_1)
{
#if 0
	char buf = args.GetChar(0);
	int sz = args.GetInt(1);
	bool rtn = wxGetEmailAddress(buf, sz);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetFreeMemory)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFreeMemory)
{
#if 0
	wxMemorySize rtn = wxGetFreeMemory();
	return ReturnValue(env, sig, args, Value(new Object_wx_MemorySize(new wxMemorySize(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetFullHostName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFullHostName)
{
	wxString rtn = wxGetFullHostName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetHomeDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetHomeDir)
{
	wxString rtn = wxGetHomeDir();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetHostName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetHostName)
{
	wxString rtn = wxGetHostName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetOsDescription)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetOsDescription)
{
	wxString rtn = wxGetOsDescription();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetOsVersion)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetOsVersion)
{
	int major = 0;
	int minor = 0;
	wxOperatingSystemId rtn = wxGetOsVersion(&major, &minor);
	return ReturnValue(env, sig, args,
			Value::CreateAsList(env, Value(rtn), Value(major), Value(minor)));
}

Gura_DeclareFunction(IsPlatformLittleEndian)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsPlatformLittleEndian)
{
	bool rtn = wxIsPlatformLittleEndian();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(IsPlatform64Bit)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsPlatform64Bit)
{
	bool rtn = wxIsPlatform64Bit();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetUserHome)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "user", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserHome)
{
#if 0
	wxString user = wxT("");
	if (args.IsValid(0)) user = wxString::FromUTF8(args.GetString(0));
	wxChar rtn = wxGetUserHome(user);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetUserId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserId)
{
	wxString rtn = wxGetUserId();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetUserId_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserId_1)
{
#if 0
	char buf = args.GetChar(0);
	int sz = args.GetInt(1);
	bool rtn = wxGetUserId(buf, sz);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetUserName_)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserName_)
{
	wxString rtn = wxGetUserName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetUserName__1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUserName__1)
{
#if 0
	char buf = args.GetChar(0);
	int sz = args.GetInt(1);
	bool rtn = wxGetUserName(buf, sz);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(copystring)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(copystring)
{
#if 0
	char s = args.GetChar(0);
	char rtn = copystring(s);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetTranslation)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "domain", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetTranslation)
{
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString _domain;
	const wxChar *domain = NULL;
	if (args.IsValid(1)) {
		_domain = wxString::FromUTF8(args.GetString(1));
		domain = _domain;
	}
	wxString rtn = wxGetTranslation(str, domain);
	return ReturnValue(env, sig, args, Value(env, rtn.ToUTF8()));
}

Gura_DeclareFunction(GetTranslation_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "strPlural", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "domain", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetTranslation_1)
{
#if 0
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString strPlural = wxString::FromUTF8(args.GetString(1));
	size_t n = args.GetSizeT(2);
	wxString _domain;
	const wxChar *domain = NULL;
	if (args.IsValid(3)) {
		_domain = wxString::FromUTF8(args.GetString(3));
		domain = _domain;
	}
	wxChar rtn = wxGetTranslation(str, strPlural, n, domain);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(IsEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsEmpty)
{
#if 0
	char p = args.GetChar(0);
	bool rtn = wxIsEmpty(p);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Strcmp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "p1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "p2", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Strcmp)
{
#if 0
	char p1 = args.GetChar(0);
	char p2 = args.GetChar(1);
	int rtn = wxStrcmp(p1, p2);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Stricmp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "p1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "p2", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Stricmp)
{
#if 0
	char p1 = args.GetChar(0);
	char p2 = args.GetChar(1);
	int rtn = wxStricmp(p1, p2);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(StringEq)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "s2", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringEq)
{
	wxString s1 = wxString::FromUTF8(args.GetString(0));
	wxString s2 = wxString::FromUTF8(args.GetString(1));
	bool rtn = wxStringEq(s1, s2);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(StringMatch)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s1", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "s2", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "subString", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "exact", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringMatch)
{
#if 0
	wxString s1 = wxString::FromUTF8(args.GetString(0));
	wxString s2 = wxString::FromUTF8(args.GetString(1));
	bool subString = true;
	if (args.IsValid(2)) subString = args.GetBoolean(2);
	bool exact = false;
	if (args.IsValid(3)) exact = args.GetBoolean(3);
	bool rtn = wxStringMatch(s1, s2, subString, exact);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(StringTokenize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "delims", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringTokenize)
{
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString delims = wxDEFAULT_DELIMITERS;
	if (args.IsValid(1)) delims = wxString::FromUTF8(args.GetString(1));
	wxStringTokenizerMode mode = wxTOKEN_DEFAULT;
	if (args.IsValid(2)) mode = static_cast<wxStringTokenizerMode>(args.GetInt(2));
	wxArrayString rtn = wxStringTokenize(str, delims, mode);
	return ReturnValue(env, sig, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareFunction(Strlen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Strlen)
{
#if 0
	char p = args.GetChar(0);
	size_t rtn = wxStrlen(p);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Snprintf)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Snprintf)
{
#if 0
	wxString buf = wxString::FromUTF8(args.GetString(0));
	size_t len = args.GetSizeT(1);
	wxString format = wxString::FromUTF8(args.GetString(2));
	int rtn = wxSnprintf(buf, len, format, );
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(TRANSLATE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TRANSLATE)
{
#if defined(__WXMSW__)
	wxString s = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxTRANSLATE(s);
	return ReturnValue(env, sig, args, Value(env, rtn.ToUTF8()));
#else
	return ReturnValue(env, sig, args, args.GetValue(0));
#endif	
}

Gura_DeclareFunction(Vsnprintf)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Vsnprintf)
{
#if 0
	wxString buf = wxString::FromUTF8(args.GetString(0));
	size_t len = args.GetSizeT(1);
	wxString format = wxString::FromUTF8(args.GetString(2));
	int rtn = wxVsnprintf(buf, len, format, );
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(PLURAL)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sing", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "plur", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PLURAL)
{
	wxString sing = wxString::FromUTF8(args.GetString(0));
	wxString plur = wxString::FromUTF8(args.GetString(1));
	size_t n = args.GetSizeT(2);
	//wxString rtn = wxPLURAL(sing, plur, n);
	wxString rtn = wxGetTranslation(sing, plur, n);
	return ReturnValue(env, sig, args, Value(env, rtn.ToUTF8()));
}

Gura_DeclareFunction(AboutBox)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_AboutDialogInfo, OCCUR_Once);
}

Gura_ImplementFunction(AboutBox)
{
	wxAboutDialogInfo *info = Object_wx_AboutDialogInfo::GetObject(args, 0)->GetEntity();
	wxAboutBox(*info);
	return Value::Null;
}

Gura_DeclareFunction(BeginBusyCursor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(BeginBusyCursor)
{
	wxCursor *cursor = (wxCursor *)(wxHOURGLASS_CURSOR);
	if (args.IsValid(0)) cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	wxBeginBusyCursor(cursor);
	return Value::Null;
}

Gura_DeclareFunction(Bell)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(Bell)
{
	wxBell();
	return Value::Null;
}

Gura_DeclareFunction(CreateFileTipProvider)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "currentTip", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CreateFileTipProvider)
{
	wxString filename = wxString::FromUTF8(args.GetString(0));
	size_t currentTip = args.GetSizeT(1);
	wxTipProvider *rtn = (wxTipProvider *)wxCreateFileTipProvider(filename, currentTip);
	return ReturnValue(env, sig, args, Value(new Object_wx_TipProvider(rtn, NULL, OwnerFalse)));
}

Gura_DeclareFunction(DirSelector)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "default_path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DirSelector)
{
	wxString message = wxDirSelectorPromptStr;
	if (args.IsValid(0)) message = wxString::FromUTF8(args.GetString(0));
	wxString default_path = wxT("");
	if (args.IsValid(1)) default_path = wxString::FromUTF8(args.GetString(1));
	long style = 0;
	if (args.IsValid(2)) style = args.GetLong(2);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(4)) parent = Object_wx_Window::GetObject(args, 4)->GetEntity();
	wxString rtn = wxDirSelector(message, default_path, style, *pos, parent);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(FileSelector)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(6)) parent = Object_wx_Window::GetObject(args, 6)->GetEntity();
	int x = -1;
	if (args.IsValid(7)) x = args.GetInt(7);
	int y = -1;
	if (args.IsValid(8)) y = args.GetInt(8);
	wxString rtn = wxFileSelector(message, default_path, default_filename, default_extension, wildcard, flags, parent, x, y);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(EndBusyCursor)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(EndBusyCursor)
{
	wxEndBusyCursor();
	return Value::Null;
}

Gura_DeclareFunction(GenericAboutBox)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_AboutDialogInfo, OCCUR_Once);
}

Gura_ImplementFunction(GenericAboutBox)
{
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "colInit", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetColourFromUser)
{
	wxWindow *parent = NULL;
	if (args.IsValid(0)) parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxColour *colInit = (wxColour *)&wxNullColour;
	if (args.IsValid(1)) colInit = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxString caption = wxEmptyString;
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	wxColour rtn = wxGetColourFromUser(parent, *colInit, caption);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(GetFontFromUser)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fontInit", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareArg(env, "caption", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetFontFromUser)
{
	wxWindow *parent = NULL;
	if (args.IsValid(0)) parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxFont *fontInit = (wxFont *)&wxNullFont;
	if (args.IsValid(1)) fontInit = Object_wx_Font::GetObject(args, 1)->GetEntity();
	wxString caption = wxEmptyString;
	if (args.IsValid(2)) caption = wxString::FromUTF8(args.GetString(2));
	wxFont rtn = wxGetFontFromUser(parent, *fontInit, caption);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(GetMultipleChoices)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxArrayInt selections;
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	std::auto_ptr<wxArrayString> aChoices(CreateArrayString(args.GetList(2)));
	wxWindow *parent = (wxWindow *)(NULL);
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
	return ReturnValue(env, sig, args, ArrayIntToValue(env, selections));
}

Gura_DeclareFunction(GetNumberFromUser)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString prompt = wxString::FromUTF8(args.GetString(1));
	wxString caption = wxString::FromUTF8(args.GetString(2));
	long value = args.GetLong(3);
	long min = 0;
	if (args.IsValid(4)) min = args.GetLong(4);
	long max = 100;
	if (args.IsValid(5)) max = args.GetLong(5);
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(6)) parent = Object_wx_Window::GetObject(args, 6)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(7)) pos = Object_wx_Point::GetObject(args, 7)->GetEntity();
	long rtn = wxGetNumberFromUser(message, prompt, caption, value, min, max, parent, *pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetPasswordFromUser)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxT("Input text");
	if (args.IsValid(1)) caption = wxString::FromUTF8(args.GetString(1));
	wxString default_value = wxT("");
	if (args.IsValid(2)) default_value = wxString::FromUTF8(args.GetString(2));
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = wxDefaultCoord;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = wxDefaultCoord;
	if (args.IsValid(5)) y = args.GetInt(5);
	bool centre = true;
	if (args.IsValid(6)) centre = args.GetBoolean(6);
	wxString rtn = wxGetPasswordFromUser(message, caption, default_value, parent, x, y, centre);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetTextFromUser)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxT("Input text");
	if (args.IsValid(1)) caption = wxString::FromUTF8(args.GetString(1));
	wxString default_value = wxT("");
	if (args.IsValid(2)) default_value = wxString::FromUTF8(args.GetString(2));
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = wxDefaultCoord;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = wxDefaultCoord;
	if (args.IsValid(5)) y = args.GetInt(5);
	bool centre = true;
	if (args.IsValid(6)) centre = args.GetBoolean(6);
	wxString rtn = wxGetTextFromUser(message, caption, default_value, parent, x, y, centre);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetSingleChoice)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	std::auto_ptr<wxArrayString> aChoices(CreateArrayString(args.GetList(2)));
	wxWindow *parent = (wxWindow *)(NULL);
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
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetSingleChoiceIndex)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	std::auto_ptr<wxArrayString> aChoices(CreateArrayString(args.GetList(2)));
	wxWindow *parent = (wxWindow *)(NULL);
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
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetSingleChoiceData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
#if 0
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	std::auto_ptr<wxArrayString> aChoices(CreateArrayString(args.GetList(2)));
	wxString client_data[] = wxString::FromUTF8(args.GetString(3));
	wxWindow *parent = (wxWindow *)(NULL);
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
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetSingleChoiceData_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
#if 0
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxString::FromUTF8(args.GetString(1));
	int n = args.GetInt(2);
	wxString choices[] = wxString::FromUTF8(args.GetString(3));
	wxString client_data[] = wxString::FromUTF8(args.GetString(4));
	wxWindow *parent = (wxWindow *)(NULL);
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
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(IsBusy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsBusy)
{
	bool rtn = wxIsBusy();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(MessageBox_)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxString message = wxString::FromUTF8(args.GetString(0));
	wxString caption = wxT("Message");
	if (args.IsValid(1)) caption = wxString::FromUTF8(args.GetString(1));
	int style = wxOK;
	if (args.IsValid(2)) style = args.GetInt(2);
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(3)) parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	int x = -1;
	if (args.IsValid(4)) x = args.GetInt(4);
	int y = -1;
	if (args.IsValid(5)) y = args.GetInt(5);
	int rtn = wxMessageBox(message, caption, style, parent, x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(ShowTip)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "tipProvider", VTYPE_wx_TipProvider, OCCUR_Once);
	DeclareArg(env, "showAtStartup", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ShowTip)
{
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxTipProvider *tipProvider = Object_wx_TipProvider::GetObject(args, 1)->GetEntity();
	bool showAtStartup = true;
	if (args.IsValid(2)) showAtStartup = args.GetBoolean(2);
	bool rtn = wxShowTip(parent, tipProvider, showAtStartup);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Finite)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Finite)
{
	double x = args.GetDouble(0);
	int rtn = wxFinite(x);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(IsNaN)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsNaN)
{
	double x = args.GetDouble(0);
	bool rtn = wxIsNaN(x);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(BITMAP)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(BITMAP)
{
#if 0
	wxBITMAP();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ClientDisplayRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(ClientDisplayRect)
{
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetClientDisplayRect)
{
	wxRect rtn = wxGetClientDisplayRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(ColourDisplay)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourDisplay)
{
	bool rtn = wxColourDisplay();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(DisplayDepth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DisplayDepth)
{
	int rtn = wxDisplayDepth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(DisplaySize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(DisplaySize)
{
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetDisplaySize)
{
	wxSize rtn = wxGetDisplaySize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(DisplaySizeMM)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(DisplaySizeMM)
{
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetDisplaySizeMM)
{
	wxSize rtn = wxGetDisplaySizeMM();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(DROP_ICON)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DROP_ICON)
{
#if 0
	char name = args.GetChar(0);
	wxIconOrCursor rtn = wxDROP_ICON(name);
	return ReturnValue(env, sig, args, Value(new Object_wx_IconOrCursor(new wxIconOrCursor(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ICON)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(ICON)
{
#if 0
	wxICON();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(MakeMetafilePlaceable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
#if 0
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int minX = args.GetInt(1);
	int minY = args.GetInt(2);
	int maxX = args.GetInt(3);
	int maxY = args.GetInt(4);
	float scale = 1.0;
	if (args.IsValid(5)) scale = args.GetFloat(5);
	bool rtn = wxMakeMetafilePlaceable(filename, minX, minY, maxX, maxY, scale);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SetCursor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cursor", VTYPE_wx_Cursor, OCCUR_Once);
}

Gura_ImplementFunction(SetCursor)
{
	wxCursor *cursor = Object_wx_Cursor::GetObject(args, 0)->GetEntity();
	wxSetCursor(*cursor);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterCommand)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterCommand)
{
#if 0
	wxString rtn = wxGetPrinterCommand();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterFile)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterFile)
{
#if 0
	wxString rtn = wxGetPrinterFile();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterMode)
{
#if 0
	int rtn = wxGetPrinterMode();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterOptions)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterOptions)
{
#if 0
	wxString rtn = wxGetPrinterOptions();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterOrientation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterOrientation)
{
#if 0
	int rtn = wxGetPrinterOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterPreviewCommand)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPrinterPreviewCommand)
{
#if 0
	wxString rtn = wxGetPrinterPreviewCommand();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPrinterScaling)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(GetPrinterScaling)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(GetPrinterTranslation)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterCommand)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterFile)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterMode)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "options", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterOptions)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterOrientation)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterPreviewCommand)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterScaling)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(SetPrinterTranslation)
{
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClipboardOpen)
{
#if defined(__WXMSW__)
	bool rtn = wxClipboardOpen();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(CloseClipboard)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CloseClipboard)
{
#if defined(__WXMSW__)
	bool rtn = wxCloseClipboard();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(EmptyClipboard)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EmptyClipboard)
{
#if defined(__WXMSW__)
	bool rtn = wxEmptyClipboard();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(EnumClipboardFormats)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EnumClipboardFormats)
{
#if defined(__WXMSW__)
	int dataFormat = args.GetInt(0);
	int rtn = wxEnumClipboardFormats(dataFormat);
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(GetClipboardData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetClipboardData)
{
#if defined(__WXMSW__)
	int dataFormat = args.GetInt(0);
	wxObject *rtn = (wxObject *)wxGetClipboardData(dataFormat);
	return ReturnValue(env, sig, args, Value(new Object_wx_Object(rtn, NULL, OwnerFalse)));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(GetClipboardFormatName_)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "formatName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "maxCount", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetClipboardFormatName_)
{
#if defined(__WXMSW__)
#if 0
	int dataFormat = args.GetInt(0);
	wxString formatName = wxString::FromUTF8(args.GetString(1));
	int maxCount = args.GetInt(2);
	bool rtn = wxGetClipboardFormatName(dataFormat, formatName, maxCount);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsClipboardFormatAvailable)
{
#if defined(__WXMSW__)
	int dataFormat = args.GetInt(0);
	bool rtn = wxIsClipboardFormatAvailable(dataFormat);
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(OpenClipboard)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(OpenClipboard)
{
#if defined(__WXMSW__)
	bool rtn = wxOpenClipboard();
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(RegisterClipboardFormat_)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "formatName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegisterClipboardFormat_)
{
#if defined(__WXMSW__)
#if 0
	wxString formatName = wxString::FromUTF8(args.GetString(0));
	int rtn = wxRegisterClipboardFormat(formatName);
	return ReturnValue(env, sig, args, Value(rtn));
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dataFormat", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SetClipboardData)
{
#if defined(__WXMSW__)
	int dataFormat = args.GetInt(0);
	wxObject *data = Object_wx_Object::GetObject(args, 1)->GetEntity();
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	bool rtn = wxSetClipboardData(dataFormat, data, width, height);
	return ReturnValue(env, sig, args, Value(rtn));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(CONCAT)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CONCAT)
{
#if 0
	wxCONCAT(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(DYNLIB_FUNCTION)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(DYNLIB_FUNCTION)
{
#if 0
	wxDYNLIB_FUNCTION(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetKeyState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetKeyState)
{
	wxKeyCode key = static_cast<wxKeyCode>(args.GetInt(0));
	bool rtn = wxGetKeyState(key);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(LL)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LL)
{
#if 0
	wxLongLong_t rtn = wxLL();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong_t(new wxLongLong_t(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(NewId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NewId)
{
	long rtn = wxNewId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(NewIds)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NewIds)
{
	Iterator *pIterator = new Iterator_NewIds();
	return ReturnIterator(env, sig, args, pIterator);
}

Gura_DeclareFunction(ON_BLOCK_EXIT0)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT0)
{
#if 0
	wxON_BLOCK_EXIT0();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT1)
{
#if 0
	wxON_BLOCK_EXIT1(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT2)
{
#if 0
	wxON_BLOCK_EXIT2(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT_OBJ0)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT_OBJ0)
{
#if 0
	wxON_BLOCK_EXIT_OBJ0(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT_OBJ1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT_OBJ1)
{
#if 0
	wxON_BLOCK_EXIT_OBJ1(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ON_BLOCK_EXIT_OBJ2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ON_BLOCK_EXIT_OBJ2)
{
#if 0
	wxON_BLOCK_EXIT_OBJ2(, , , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(RegisterId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(RegisterId)
{
	long id = args.GetLong(0);
	wxRegisterId(id);
	return Value::Null;
}

Gura_DeclareFunction(DDECleanUp)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(DDECleanUp)
{
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
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(DDEInitialize)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(EnableTopLevelWindows)
{
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	wxEnableTopLevelWindows(enable);
	return Value::Null;
}

Gura_DeclareFunction(FindMenuItemId)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "menuString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "itemString", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindMenuItemId)
{
	wxFrame *frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	wxString menuString = wxString::FromUTF8(args.GetString(1));
	wxString itemString = wxString::FromUTF8(args.GetString(2));
	int rtn = wxFindMenuItemId(frame, menuString, itemString);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(FindWindowByLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindWindowByLabel)
{
	wxString label = wxString::FromUTF8(args.GetString(0));
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(1)) parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxFindWindowByLabel(label, parent);
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareFunction(FindWindowByName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindWindowByName)
{
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxWindow *parent = (wxWindow *)(NULL);
	if (args.IsValid(1)) parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxFindWindowByName(name, parent);
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareFunction(FindWindowAtPoint)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindWindowAtPoint)
{
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxFindWindowAtPoint(*pt);
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareFunction(FindWindowAtPointer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindWindowAtPointer)
{
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxFindWindowAtPointer(*pt);
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareFunction(GetActiveWindow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetActiveWindow)
{
	wxWindow *rtn = (wxWindow *)wxGetActiveWindow();
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareFunction(GetBatteryState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetBatteryState)
{
	wxBatteryState rtn = wxGetBatteryState();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetDisplayName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetDisplayName)
{
#if 0
	wxString rtn = wxGetDisplayName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetPowerType)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetPowerType)
{
	wxPowerType rtn = wxGetPowerType();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetMousePosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetMousePosition)
{
	wxPoint rtn = wxGetMousePosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(GetMouseState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetMouseState)
{
	wxMouseState rtn = wxGetMouseState();
	return ReturnValue(env, sig, args, Value(new Object_wx_MouseState(new wxMouseState(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(GetResource)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetResource)
{
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	wxString value = wxString::FromUTF8(args.GetString(2));
	wxString file = NULL;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxGetResource(section, entry, value, file);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetResource_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetResource_1)
{
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	float value = args.GetFloat(2);
	wxString file = NULL;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxGetResource(section, entry, value, file);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetResource_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetResource_2)
{
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	long value = args.GetLong(2);
	wxString file = NULL;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxGetResource(section, entry, value, file);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetResource_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetResource_3)
{
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	int value = args.GetInt(2);
	wxString file = NULL;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxGetResource(section, entry, value, file);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(GetStockLabel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetStockLabel)
{
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(0));
	long flags = wxSTOCK_WITH_MNEMONIC;
	if (args.IsValid(1)) flags = args.GetLong(1);
	wxString rtn = wxGetStockLabel(id, flags);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(GetTopLevelParent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetTopLevelParent)
{
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindow *rtn = (wxWindow *)wxGetTopLevelParent(win);
	return ReturnValue(env, sig, args, Value(new Object_wx_Window(rtn, NULL, OwnerFalse)));
}

Gura_DeclareFunction(LaunchDefaultBrowser)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LaunchDefaultBrowser)
{
	wxString url = wxString::FromUTF8(args.GetString(0));
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	bool rtn = wxLaunchDefaultBrowser(url, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(LoadUserResource)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "resourceName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "resourceType", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LoadUserResource)
{
#if defined(__WXMSW__)
	wxString resourceName = wxString::FromUTF8(args.GetString(0));
	wxString resourceType = wxT("TEXT");
	if (args.IsValid(1)) resourceType = wxString::FromUTF8(args.GetString(1));
	wxString rtn = wxLoadUserResource(resourceName, resourceType);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareFunction(PostDelete)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "object", VTYPE_wx_Object, OCCUR_Once);
}

Gura_ImplementFunction(PostDelete)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dest", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_Event, OCCUR_Once);
}

Gura_ImplementFunction(PostEvent)
{
	wxEvtHandler *dest = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	wxEvent *event = Object_wx_Event::GetObject(args, 1)->GetEntity();
	wxPostEvent(dest, *event);
	return Value::Null;
}

Gura_DeclareFunction(SetDisplayName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "displayName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SetDisplayName)
{
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StripMenuCodes)
{
	wxString str = wxString::FromUTF8(args.GetString(0));
	int flags = wxStrip_All;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxString rtn = wxStripMenuCodes(str, flags);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(STRINGIZE)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(STRINGIZE)
{
#if 0
	wxSTRINGIZE();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(STRINGIZE_T)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(STRINGIZE_T)
{
#if 0
	wxSTRINGIZE_T();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SUPPRESS_GCC_PRIVATE_DTOR_WARNING)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(SUPPRESS_GCC_PRIVATE_DTOR_WARNING)
{
#if 0
	wxSUPPRESS_GCC_PRIVATE_DTOR_WARNING();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ULL)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ULL)
{
#if 0
	wxLongLong_t rtn = wxULL();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong_t(new wxLongLong_t(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(VaCopy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(VaCopy)
{
#if 0
	wxVaCopy(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(WriteResource)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WriteResource)
{
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	wxString value = wxString::FromUTF8(args.GetString(2));
	wxString file = NULL;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxWriteResource(section, entry, value, file);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(WriteResource_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WriteResource_1)
{
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	float value = args.GetFloat(2);
	wxString file = NULL;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxWriteResource(section, entry, value, file);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(WriteResource_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WriteResource_2)
{
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	long value = args.GetLong(2);
	wxString file = NULL;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxWriteResource(section, entry, value, file);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(WriteResource_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "section", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "entry", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(WriteResource_3)
{
#if 0
	wxString section = wxString::FromUTF8(args.GetString(0));
	wxString entry = wxString::FromUTF8(args.GetString(1));
	int value = args.GetInt(2);
	wxString file = NULL;
	if (args.IsValid(3)) file = wxString::FromUTF8(args.GetString(3));
	bool rtn = wxWriteResource(section, entry, value, file);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(INT32_SWAP_ALWAYS)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT32_SWAP_ALWAYS)
{
	wxInt32 value = static_cast<wxInt32>(args.GetULong(0));
	wxInt32 rtn = wxINT32_SWAP_ALWAYS(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(UINT32_SWAP_ALWAYS)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT32_SWAP_ALWAYS)
{
	wxUint32 value = static_cast<wxUint32>(args.GetULong(0));
	wxUint32 rtn = wxUINT32_SWAP_ALWAYS(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(INT16_SWAP_ALWAYS)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT16_SWAP_ALWAYS)
{
	wxInt16 value = static_cast<wxInt16>(args.GetUShort(0));
	wxInt16 rtn = wxINT16_SWAP_ALWAYS(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(UINT16_SWAP_ALWAYS)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT16_SWAP_ALWAYS)
{
	wxUint16 value = static_cast<wxUint16>(args.GetUShort(0));
	wxUint16 rtn = wxUINT16_SWAP_ALWAYS(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(INT32_SWAP_ON_BE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT32_SWAP_ON_BE)
{
	wxInt32 value = static_cast<wxInt32>(args.GetULong(0));
	wxInt32 rtn = wxINT32_SWAP_ON_BE(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(UINT32_SWAP_ON_BE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT32_SWAP_ON_BE)
{
	wxUint32 value = static_cast<wxUint32>(args.GetULong(0));
	wxUint32 rtn = wxUINT32_SWAP_ON_BE(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(INT16_SWAP_ON_BE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT16_SWAP_ON_BE)
{
	wxInt16 value = static_cast<wxInt16>(args.GetUShort(0));
	wxInt16 rtn = wxINT16_SWAP_ON_BE(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(UINT16_SWAP_ON_BE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT16_SWAP_ON_BE)
{
	wxUint16 value = static_cast<wxUint16>(args.GetUShort(0));
	wxUint16 rtn = wxUINT16_SWAP_ON_BE(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(INT32_SWAP_ON_LE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT32_SWAP_ON_LE)
{
	wxInt32 value = static_cast<wxInt32>(args.GetULong(0));
	wxInt32 rtn = wxINT32_SWAP_ON_LE(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(UINT32_SWAP_ON_LE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT32_SWAP_ON_LE)
{
	wxUint32 value = static_cast<wxUint32>(args.GetULong(0));
	wxUint32 rtn = wxUINT32_SWAP_ON_LE(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(INT16_SWAP_ON_LE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(INT16_SWAP_ON_LE)
{
	wxInt16 value = static_cast<wxInt16>(args.GetUShort(0));
	wxInt16 rtn = wxINT16_SWAP_ON_LE(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(UINT16_SWAP_ON_LE)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UINT16_SWAP_ON_LE)
{
	wxUint16 value = static_cast<wxUint16>(args.GetUShort(0));
	wxUint16 rtn = wxUINT16_SWAP_ON_LE(value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(DebugMsg)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fmt", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(DebugMsg)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Error)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FatalError)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogError)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogError(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogFatalError)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogFatalError)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogFatalError(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogWarning)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogWarning)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogWarning(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogMessage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogMessage)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogMessage(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogVerbose)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogVerbose)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogVerbose(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogStatus)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once, FLAG_NoCast);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogStatus)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogStatus(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogStatusEx)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogStatusEx)
{
	wxFrame *frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	const char *formatString = args.GetString(1);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(2)).c_str());
	wxLogStatus(frame, wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogSysError)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogSysError)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogSysError(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogDebug)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogDebug)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogDebug(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogTrace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
}

Gura_ImplementFunction(LogTrace)
{
	const char *formatString = args.GetString(0);
	wxString str = wxString::FromUTF8(Formatter::Format(
								sig, formatString, args.GetList(1)).c_str());
	wxLogTrace(wxT("%s"), str.c_str());
	return Value::Null;
}

Gura_DeclareFunction(LogTrace_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(LogTrace_1)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "mask", VTYPE_wx_TraceMask, OCCUR_Once);
	DeclareArg(env, "formatString", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementFunction(LogTrace_2)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(SafeShowMessage)
{
	wxString title = wxString::FromUTF8(args.GetString(0));
	wxString text = wxString::FromUTF8(args.GetString(1));
	wxSafeShowMessage(title, text);
	return Value::Null;
}

Gura_DeclareFunction(SysErrorCode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SysErrorCode)
{
	unsigned rtn = wxSysErrorCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(SysErrorMsg)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "errCode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SysErrorMsg)
{
#if 0
	unsigned errCode = 0;
	if (args.IsValid(0)) errCode = args.GetInt(0);
	wxChar rtn = wxSysErrorMsg(errCode);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Trace)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fmt", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(Trace)
{
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
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "fmt", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(TraceLevel)
{
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "resetTimer", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetElapsedTime)
{
	bool resetTimer = true;
	if (args.IsValid(0)) resetTimer = args.GetBoolean(0);
	long rtn = wxGetElapsedTime(resetTimer);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetLocalTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetLocalTime)
{
	long rtn = wxGetLocalTime();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetLocalTimeMillis)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetLocalTimeMillis)
{
	wxLongLong rtn = wxGetLocalTimeMillis();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(GetUTCTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetUTCTime)
{
	long rtn = wxGetUTCTime();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(MicroSleep)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "microseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(MicroSleep)
{
	unsigned microseconds = args.GetInt(0);
	wxMicroSleep(microseconds);
	return Value::Null;
}

Gura_DeclareFunction(MilliSleep)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(MilliSleep)
{
	unsigned milliseconds = args.GetInt(0);
	wxMilliSleep(milliseconds);
	return Value::Null;
}

Gura_DeclareFunction(Now)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Now)
{
	wxString rtn = wxNow();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareFunction(Sleep)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "secs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(Sleep)
{
	int secs = args.GetInt(0);
	wxSleep(secs);
	return Value::Null;
}

Gura_DeclareFunction(StartTimer)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(StartTimer)
{
	wxStartTimer();
	return Value::Null;
}

Gura_DeclareFunction(Usleep)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(Usleep)
{
	unsigned milliseconds = args.GetInt(0);
	wxUsleep(milliseconds);
	return Value::Null;
}

Gura_DeclareFunction(OnAssert)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "lineNumber", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "func", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "cond", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "msg", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(OnAssert)
{
#if 0
	char fileName = args.GetChar(0);
	int lineNumber = args.GetInt(1);
	char func = args.GetChar(2);
	char cond = args.GetChar(3);
	char msg = NULL;
	if (args.IsValid(4)) msg = args.GetChar(4);
	wxOnAssert(fileName, lineNumber, func, cond, msg);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ASSERT)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ASSERT)
{
#if 0
	wxASSERT();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ASSERT_MIN_BITSIZE)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(ASSERT_MIN_BITSIZE)
{
#if 0
	wxASSERT_MIN_BITSIZE(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(ASSERT_MSG)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "condition", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(ASSERT_MSG)
{
	bool condition = args.GetBoolean(0);
	wxString msg = wxString::FromUTF8(args.GetString(1));
	wxASSERT_MSG(condition, msg);
	return Value::Null;
}

Gura_DeclareFunction(COMPILE_TIME_ASSERT)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(COMPILE_TIME_ASSERT)
{
#if 0
	wxCOMPILE_TIME_ASSERT(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(COMPILE_TIME_ASSERT2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(COMPILE_TIME_ASSERT2)
{
#if 0
	wxCOMPILE_TIME_ASSERT(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(FAIL)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(FAIL)
{
	//wxFAIL();
	return Value::Null;
}

Gura_DeclareFunction(FAIL_MSG)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "msg", VTYPE_string, OCCUR_Once);
}

Gura_ImplementFunction(FAIL_MSG)
{
	wxString msg = wxString::FromUTF8(args.GetString(0));
	wxFAIL_MSG(msg);
	return Value::Null;
}

Gura_DeclareFunction(CHECK)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK)
{
#if 0
	wxCHECK(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHECK_MSG)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK_MSG)
{
#if 0
	wxCHECK_MSG(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHECK_RET)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK_RET)
{
#if 0
	wxCHECK_RET(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHECK2)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK2)
{
#if 0
	wxCHECK2(, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(CHECK2_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
}

Gura_ImplementFunction(CHECK2_1)
{
#if 0
	wxCHECK2(, , );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(Trap)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(Trap)
{
	wxTrap();
	return Value::Null;
}

Gura_DeclareFunction(IsDebuggerRunning)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IsDebuggerRunning)
{
	bool rtn = wxIsDebuggerRunning();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(GetEnv)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "var", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GetEnv)
{
	wxString var = wxString::FromUTF8(args.GetString(0));
	wxString value;
	bool rtn = wxGetEnv(var, &value);
	Value valueRtn;
	if (rtn) {
		valueRtn = Value(env, value.ToUTF8());
	}
	return ReturnValue(env, sig, args, valueRtn);
}

Gura_DeclareFunction(SetEnv)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "var", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SetEnv)
{
	wxString var = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	bool rtn = wxSetEnv(var, value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(UnsetEnv)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "var", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(UnsetEnv)
{
	wxString var = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxUnsetEnv(var);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Isalnum)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isalnum)
{
	int c = args.GetInt(0);
	bool rtn = wxIsalnum(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Isalpha)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isalpha)
{
	int c = args.GetInt(0);
	bool rtn = wxIsalpha(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Iscntrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Iscntrl)
{
	int c = args.GetInt(0);
	bool rtn = wxIscntrl(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Isdigit)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isdigit)
{
	int c = args.GetInt(0);
	bool rtn = wxIsdigit(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Isgraph)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isgraph)
{
	int c = args.GetInt(0);
	bool rtn = wxIsgraph(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Islower)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Islower)
{
	int c = args.GetInt(0);
	bool rtn = wxIslower(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Isprint)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isprint)
{
	int c = args.GetInt(0);
	bool rtn = wxIsprint(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Ispunct)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Ispunct)
{
	int c = args.GetInt(0);
	bool rtn = wxIspunct(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Isspace)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isspace)
{
	int c = args.GetInt(0);
	bool rtn = wxIsspace(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Isupper)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isupper)
{
	int c = args.GetInt(0);
	bool rtn = wxIsupper(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Isxdigit)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Isxdigit)
{
	int c = args.GetInt(0);
	bool rtn = wxIsxdigit(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Tolower)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Tolower)
{
	int c = args.GetInt(0);
	wxChar rtn = wxTolower(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareFunction(Toupper)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Toupper)
{
	int c = args.GetInt(0);
	wxChar rtn = wxToupper(c);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for 
//----------------------------------------------------------------------------
void RegisterFunctions(Environment &env, Signal sig)
{
	_pEnv = &env;
	Gura_RealizeUserSymbol(GetApp);
	Gura_AssignFunction(IMPLEMENT_APP);
	Gura_AssignFunction(BusyCursor);
	Gura_AssignFunction(CaretSuspend);
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
	Gura_AssignFunctionEx(CopyFile_, "CopyFile");
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
	Gura_AssignFunctionEx(MessageBox_, "MessageBox");
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

}}
