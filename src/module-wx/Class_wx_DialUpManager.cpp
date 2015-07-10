//----------------------------------------------------------------------------
// wxDialUpManager
// extracted from dialup.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DialUpManager: public wxDialUpManager, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_DialUpManager *_pObj;
public:
	~wx_DialUpManager();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DialUpManager *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DialUpManager::~wx_DialUpManager()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DialUpManager::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDialUpManager
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DialUpManager, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, Create)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDialUpManager *rtn = (wxDialUpManager *)pThis->GetEntity()->Create();
	return ReturnValue(env, sig, args, Value(new Object_wx_DialUpManager(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DialUpManager, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, IsOk)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, GetISPNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "names", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, GetISPNames)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::unique_ptr<wxArrayString> names(CreateArrayString(args.GetList(0)));
	size_t rtn = pThis->GetEntity()->GetISPNames(*names);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, Dial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nameOfISP", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "username", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "password", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "async", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, Dial)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString nameOfISP = wxEmptyString;
	if (args.IsValid(0)) nameOfISP = wxString::FromUTF8(args.GetString(0));
	wxString username = wxEmptyString;
	if (args.IsValid(1)) username = wxString::FromUTF8(args.GetString(1));
	wxString password = wxEmptyString;
	if (args.IsValid(2)) password = wxString::FromUTF8(args.GetString(2));
	bool async = true;
	if (args.IsValid(3)) async = args.GetBoolean(3);
	bool rtn = pThis->GetEntity()->Dial(nameOfISP, username, password, async);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, IsDialing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, IsDialing)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDialing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, CancelDialing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, CancelDialing)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CancelDialing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, HangUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, HangUp)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HangUp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, IsAlwaysOnline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, IsAlwaysOnline)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsAlwaysOnline();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, IsOnline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, IsOnline)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOnline();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, SetOnlineStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "isOnline", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, SetOnlineStatus)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool isOnline = true;
	if (args.IsValid(0)) isOnline = args.GetBoolean(0);
	pThis->GetEntity()->SetOnlineStatus(isOnline);
	return Value::Null;
}

Gura_DeclareMethod(wx_DialUpManager, EnableAutoCheckOnlineStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nSeconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, EnableAutoCheckOnlineStatus)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nSeconds = 60;
	if (args.IsValid(0)) nSeconds = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->EnableAutoCheckOnlineStatus(nSeconds);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpManager, DisableAutoCheckOnlineStatus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpManager, DisableAutoCheckOnlineStatus)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisableAutoCheckOnlineStatus();
	return Value::Null;
}

Gura_DeclareMethod(wx_DialUpManager, SetWellKnownHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "hostname", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "portno", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, SetWellKnownHost)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString hostname = wxString::FromUTF8(args.GetString(0));
	int portno = 80;
	if (args.IsValid(1)) portno = args.GetInt(1);
	pThis->GetEntity()->SetWellKnownHost(hostname, portno);
	return Value::Null;
}

Gura_DeclareMethod(wx_DialUpManager, SetConnectCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "commandDial", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "commandHangup", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpManager, SetConnectCommand)
{
	Object_wx_DialUpManager *pThis = Object_wx_DialUpManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString commandDial = wxT("/usr/bin/pon");
	if (args.IsValid(0)) commandDial = wxString::FromUTF8(args.GetString(0));
	wxString commandHangup = wxT("/usr/bin/poff");
	if (args.IsValid(1)) commandHangup = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetConnectCommand(commandDial, commandHangup);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDialUpManager
//----------------------------------------------------------------------------
Object_wx_DialUpManager::~Object_wx_DialUpManager()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DialUpManager::Clone() const
{
	return nullptr;
}

String Object_wx_DialUpManager::ToString(bool exprFlag)
{
	String rtn("<wx.DialUpManager:");
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
// Class implementation for wxDialUpManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpManager)
{
	Gura_AssignMethod(wx_DialUpManager, Create);
	Gura_AssignMethod(wx_DialUpManager, IsOk);
	Gura_AssignMethod(wx_DialUpManager, GetISPNames);
	Gura_AssignMethod(wx_DialUpManager, Dial);
	Gura_AssignMethod(wx_DialUpManager, IsDialing);
	Gura_AssignMethod(wx_DialUpManager, CancelDialing);
	Gura_AssignMethod(wx_DialUpManager, HangUp);
	Gura_AssignMethod(wx_DialUpManager, IsAlwaysOnline);
	Gura_AssignMethod(wx_DialUpManager, IsOnline);
	Gura_AssignMethod(wx_DialUpManager, SetOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, EnableAutoCheckOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, DisableAutoCheckOnlineStatus);
	Gura_AssignMethod(wx_DialUpManager, SetWellKnownHost);
	Gura_AssignMethod(wx_DialUpManager, SetConnectCommand);
}

Gura_ImplementDescendantCreator(wx_DialUpManager)
{
	return new Object_wx_DialUpManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
