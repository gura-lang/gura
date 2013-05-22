//----------------------------------------------------------------------------
// wxLog
// extracted from log.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(DoLog);
Gura_DeclarePrivUserSymbol(DoLogString);
Gura_DeclarePrivUserSymbol(Flush);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Log: public wxLog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Log *_pObj;
public:
	//virtual void DoLog(wxLogLevel level, const wxChar *msg, time_t timestamp);
	//virtual void DoLogString(const wxChar *msg, time_t timestamp);
	//virtual void Flush();
	~wx_Log();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Log *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Log::~wx_Log()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Log::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLog
//----------------------------------------------------------------------------
Gura_DeclareFunction(Log)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Log));
}

Gura_ImplementFunction(Log)
{
	if (!CheckWxReady(sig)) return Value::Null;
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, AddTraceMask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_string, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Log, AddTraceMask)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString mask = wxString::FromUTF8(args.GetString(0));
	wxLog::AddTraceMask(mask);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, ClearTraceMasks)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Log, ClearTraceMasks)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLog::ClearTraceMasks();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, GetTraceMasks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, GetTraceMasks)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArrayString rtn = wxLog::GetTraceMasks();
	return ReturnValue(env, sig, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareClassMethod(wx_Log, OnLog)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_Log, OnLog)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxLogLevel level = static_cast<wxLogLevel>(args.GetInt(0));
	char message = args.GetChar(1);
	wxLog::OnLog(level, message);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, GetActiveTarget)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, GetActiveTarget)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLog *rtn = (wxLog *)wxLog::GetActiveTarget();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Log(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareClassMethod(wx_Log, SetActiveTarget)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "logtarget", VTYPE_wx_Log, OCCUR_Once, FLAG_Nil);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, SetActiveTarget)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLog *logtarget = args.IsValid(0)?
					Object_wx_Log::GetObject(args, 0)->GetEntity() : NULL;
	wxLog *rtn = (wxLog *)wxLog::SetActiveTarget(logtarget);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Log(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareClassMethod(wx_Log, Suspend)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Log, Suspend)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLog::Suspend();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, Resume)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Log, Resume)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLog::Resume();
	return Value::Null;
}

Gura_DeclareMethod(wx_Log, DoLog)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*msg", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Log, DoLog)
{
#if 0
	Object_wx_Log *pThis = Object_wx_Log::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLogLevel level = static_cast<wxLogLevel>(args.GetInt(0));
	wxChar *msg = static_cast<wxChar>(args.GetInt(1));
	pThis->GetEntity()->DoLog(level, *msg, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Log, DoLogString)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "*msg", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Log, DoLogString)
{
#if 0
	Object_wx_Log *pThis = Object_wx_Log::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar *msg = static_cast<wxChar>(args.GetInt(0));
	pThis->GetEntity()->DoLogString(*msg, );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, DontCreateOnDemand)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Log, DontCreateOnDemand)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLog::DontCreateOnDemand();
	return Value::Null;
}

Gura_DeclareMethod(wx_Log, Flush)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Log, Flush)
{
	Object_wx_Log *pThis = Object_wx_Log::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Flush();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, FlushActive)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_Log, FlushActive)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLog::FlushActive();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, SetVerbose)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "verbose", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, SetVerbose)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool verbose = true;
	if (args.IsValid(0)) verbose = args.GetBoolean(0);
	wxLog::SetVerbose(verbose);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, GetVerbose)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, GetVerbose)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxLog::GetVerbose();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Log, SetLogLevel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "logLevel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Log, SetLogLevel)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLogLevel logLevel = static_cast<wxLogLevel>(args.GetInt(0));
	wxLog::SetLogLevel(logLevel);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, GetLogLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, GetLogLevel)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxLogLevel rtn = wxLog::GetLogLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Log, SetRepetitionCounting)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "repetCounting", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, SetRepetitionCounting)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool repetCounting = true;
	if (args.IsValid(0)) repetCounting = args.GetBoolean(0);
	wxLog::SetRepetitionCounting(repetCounting);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, GetRepetitionCounting)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, GetRepetitionCounting)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool rtn = wxLog::GetRepetitionCounting();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Log, SetTimestamp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementClassMethod(wx_Log, SetTimestamp)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	if (args.IsValid(0)) {
		const char *format = args.GetString(0);
		wxLog::SetTimestamp(format);
	} else {
		wxLog::SetTimestamp(NULL);
	}
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareClassMethod(wx_Log, GetTimestamp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, GetTimestamp)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString rtn = wxString(wxLog::GetTimestamp());
	return ReturnValue(env, sig, args, Value(env, rtn.ToUTF8()));
}

Gura_DeclareClassMethod(wx_Log, SetTraceMask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Log, SetTraceMask)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxTraceMask mask = static_cast<wxTraceMask>(args.GetInt(0));
	wxLog::SetTraceMask(mask);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Log, IsAllowedTraceMask)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Log, IsAllowedTraceMask)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString mask = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxLog::IsAllowedTraceMask(mask);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Log, RemoveTraceMask)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mask", VTYPE_string, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Log, RemoveTraceMask)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString mask = wxString::FromUTF8(args.GetString(0));
	wxLog::RemoveTraceMask(mask);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxLog
//----------------------------------------------------------------------------
Object_wx_Log::~Object_wx_Log()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Log::Clone() const
{
	return NULL;
}

String Object_wx_Log::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Log:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Log::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(DoLog);
	Gura_RealizeUserSymbol(DoLogString);
	Gura_RealizeUserSymbol(Flush);
	Gura_AssignFunction(Log);
}

//----------------------------------------------------------------------------
// Class implementation for wxLog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Log)
{
	Gura_AssignMethod(wx_Log, AddTraceMask);
	Gura_AssignMethod(wx_Log, ClearTraceMasks);
	Gura_AssignMethod(wx_Log, GetTraceMasks);
	Gura_AssignMethod(wx_Log, OnLog);
	Gura_AssignMethod(wx_Log, GetActiveTarget);
	Gura_AssignMethod(wx_Log, SetActiveTarget);
	Gura_AssignMethod(wx_Log, Suspend);
	Gura_AssignMethod(wx_Log, Resume);
	Gura_AssignMethod(wx_Log, DoLog);
	Gura_AssignMethod(wx_Log, DoLogString);
	Gura_AssignMethod(wx_Log, DontCreateOnDemand);
	Gura_AssignMethod(wx_Log, Flush);
	Gura_AssignMethod(wx_Log, FlushActive);
	Gura_AssignMethod(wx_Log, SetVerbose);
	Gura_AssignMethod(wx_Log, GetVerbose);
	Gura_AssignMethod(wx_Log, SetLogLevel);
	Gura_AssignMethod(wx_Log, GetLogLevel);
	Gura_AssignMethod(wx_Log, SetRepetitionCounting);
	Gura_AssignMethod(wx_Log, GetRepetitionCounting);
	Gura_AssignMethod(wx_Log, SetTimestamp);
	Gura_AssignMethod(wx_Log, GetTimestamp);
	Gura_AssignMethod(wx_Log, SetTraceMask);
	Gura_AssignMethod(wx_Log, IsAllowedTraceMask);
	Gura_AssignMethod(wx_Log, RemoveTraceMask);
}

Gura_ImplementDescendantCreator(wx_Log)
{
	return new Object_wx_Log((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
