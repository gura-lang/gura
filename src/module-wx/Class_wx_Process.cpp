//----------------------------------------------------------------------------
// wxProcess
// extracted from process.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Process: public wxProcess, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Process *_pObj;
public:
	inline wx_Process(wxEvtHandler * parent, int id) : wxProcess(parent, id), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Process(int flags) : wxProcess(flags), _sig(nullptr), _pObj(nullptr) {}
	~wx_Process();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Process *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Process::~wx_Process()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Process::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxProcess
//----------------------------------------------------------------------------
Gura_DeclareFunction(Process)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Process));
	DeclareArg(env, "parent", VTYPE_wx_EvtHandler, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Process)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEvtHandler *parent = (wxEvtHandler *)(nullptr);
	if (args.IsValid(0)) parent = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_Process *pEntity = new wx_Process(parent, id);
	Object_wx_Process *pObj = Object_wx_Process::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Process(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Process_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Process));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Process_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int flags = args.GetInt(0);
	wx_Process *pEntity = new wx_Process(flags);
	Object_wx_Process *pObj = Object_wx_Process::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Process(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Process, CloseOutput)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, CloseOutput)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CloseOutput();
	return Value::Null;
}

Gura_DeclareMethod(wx_Process, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, Detach)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Detach();
	return Value::Null;
}

Gura_DeclareMethod(wx_Process, GetErrorStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Process, GetErrorStream)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *rtn = (wxInputStream *)pThis->GetEntity()->GetErrorStream();
	return ReturnValue(env, sig, args, Value(new Object_wx_InputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Process, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Process, GetInputStream)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *rtn = (wxInputStream *)pThis->GetEntity()->GetInputStream();
	return ReturnValue(env, sig, args, Value(new Object_wx_InputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Process, GetOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Process, GetOutputStream)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *rtn = (wxOutputStream *)pThis->GetEntity()->GetOutputStream();
	return ReturnValue(env, sig, args, Value(new Object_wx_OutputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Process, IsErrorAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Process, IsErrorAvailable)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsErrorAvailable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Process, IsInputAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Process, IsInputAvailable)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsInputAvailable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Process, IsInputOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Process, IsInputOpened)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsInputOpened();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Process, Kill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "signal", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Process, Kill)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int pid = args.GetInt(0);
	wxSignal signal = wxSIGNONE;
	if (args.IsValid(1)) signal = static_cast<wxSignal>(args.GetInt(1));
	int flags = wxKILL_NOCHILDREN;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wxKillError rtn = wxProcess::Kill(pid, signal, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Process, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Process, Exists)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int pid = args.GetInt(0);
	bool rtn = wxProcess::Exists(pid);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Process, OnTerminate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "status", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Process, OnTerminate)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pid = args.GetInt(0);
	int status = args.GetInt(1);
	pThis->GetEntity()->OnTerminate(pid, status);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Process, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cmd", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Process, Open)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString cmd = wxString::FromUTF8(args.GetString(0));
	int flags = wxEXEC_ASYNC;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxProcess *rtn = (wxProcess *)wxProcess::Open(cmd, flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_Process(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Process, GetPid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Process, GetPid)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetPid();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Process, Redirect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Process, Redirect)
{
	Object_wx_Process *pThis = Object_wx_Process::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Redirect();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxProcess
//----------------------------------------------------------------------------
Object_wx_Process::~Object_wx_Process()
{
}

Object *Object_wx_Process::Clone() const
{
	return nullptr;
}

String Object_wx_Process::ToString(bool exprFlag)
{
	String rtn("<wx.Process:");
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
// Class implementation for wxProcess
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Process)
{
	Gura_AssignFunction(Process);
	Gura_AssignFunction(Process_1);
	Gura_AssignMethod(wx_Process, CloseOutput);
	Gura_AssignMethod(wx_Process, Detach);
	Gura_AssignMethod(wx_Process, GetErrorStream);
	Gura_AssignMethod(wx_Process, GetInputStream);
	Gura_AssignMethod(wx_Process, GetOutputStream);
	Gura_AssignMethod(wx_Process, IsErrorAvailable);
	Gura_AssignMethod(wx_Process, IsInputAvailable);
	Gura_AssignMethod(wx_Process, IsInputOpened);
	Gura_AssignMethod(wx_Process, Kill);
	Gura_AssignMethod(wx_Process, Exists);
	Gura_AssignMethod(wx_Process, OnTerminate);
	Gura_AssignMethod(wx_Process, Open);
	Gura_AssignMethod(wx_Process, GetPid);
	Gura_AssignMethod(wx_Process, Redirect);
}

Gura_ImplementDescendantCreator(wx_Process)
{
	return new Object_wx_Process((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
