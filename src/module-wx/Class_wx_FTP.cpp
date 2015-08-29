//----------------------------------------------------------------------------
// wxFTP
// extracted from ftp.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FTP: public wxFTP, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FTP *_pObj;
public:
	inline wx_FTP() : wxFTP(), _pObj(nullptr) {}
	~wx_FTP();
	inline void AssocWithGura(Object_wx_FTP *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FTP::~wx_FTP()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FTP::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFTP
//----------------------------------------------------------------------------
Gura_DeclareFunction(FTPEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FTP));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FTPEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_FTP *pEntity = new wx_FTP();
	Object_wx_FTP *pObj = Object_wx_FTP::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FTP(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_FTP, Abort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, Abort)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Abort();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, CheckCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ret", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, CheckCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString command = wxString::FromUTF8(arg.GetString(0));
	char ret = arg.GetChar(1);
	bool rtn = pThis->GetEntity()->CheckCommand(command, ret);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, SendCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, SendCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString command = wxString::FromUTF8(arg.GetString(0));
	char rtn = pThis->GetEntity()->SendCommand(command);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetLastResult)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetLastResult)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLastResult();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FTP, ChDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, ChDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->ChDir(dir);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, MkDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, MkDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->MkDir(dir);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, RmDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, RmDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->RmDir(dir);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, Pwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, Pwd)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->Pwd();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FTP, Rename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "src", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dst", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, Rename)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString src = wxString::FromUTF8(arg.GetString(0));
	wxString dst = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->Rename(src, dst);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, RmFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, RmFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString path = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->RmFile(path);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, SetAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, SetAscii)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->SetAscii();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, SetBinary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, SetBinary)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->SetBinary();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, SetPassive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pasv", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_FTP, SetPassive)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool pasv = arg.GetBoolean(0);
	pThis->GetEntity()->SetPassive(pasv);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FTP, SetTransferMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, SetTransferMode)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->SetTransferMode();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FTP, SetUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "user", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FTP, SetUser)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString user = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetUser(user);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FTP, SetPassword)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "passwd", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FTP, SetPassword)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString passwd = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetPassword(passwd);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FTP, FileExists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, FileExists)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->FileExists(filename);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetFileSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetFileSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	int rtn = pThis->GetEntity()->GetFileSize(filename);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetDirList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "files", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetDirList)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> files(CreateArrayString(arg.GetList(0)));
	wxString wildcard = wxT("");
	if (arg.IsValid(1)) wildcard = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->GetDirList(*files, wildcard);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetFilesList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "files", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetFilesList)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> files(CreateArrayString(arg.GetList(0)));
	wxString wildcard = wxT("");
	if (arg.IsValid(1)) wildcard = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->GetFilesList(*files, wildcard);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString file = wxString::FromUTF8(arg.GetString(0));
	wxOutputStream *rtn = (wxOutputStream *)pThis->GetEntity()->GetOutputStream(file);
	return ReturnValue(env, arg, Value(new Object_wx_OutputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_FTP, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_FTP *pThis = Object_wx_FTP::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString path = wxString::FromUTF8(arg.GetString(0));
	wxInputStream *rtn = (wxInputStream *)pThis->GetEntity()->GetInputStream(path);
	return ReturnValue(env, arg, Value(new Object_wx_InputStream(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFTP
//----------------------------------------------------------------------------
Object_wx_FTP::~Object_wx_FTP()
{
}

Object *Object_wx_FTP::Clone() const
{
	return nullptr;
}

String Object_wx_FTP::ToString(bool exprFlag)
{
	String rtn("<wx.FTP:");
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
// Class implementation for wxFTP
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FTP)
{
	Gura_AssignFunction(FTPEmpty);
	Gura_AssignMethod(wx_FTP, Abort);
	Gura_AssignMethod(wx_FTP, CheckCommand);
	Gura_AssignMethod(wx_FTP, SendCommand);
	Gura_AssignMethod(wx_FTP, GetLastResult);
	Gura_AssignMethod(wx_FTP, ChDir);
	Gura_AssignMethod(wx_FTP, MkDir);
	Gura_AssignMethod(wx_FTP, RmDir);
	Gura_AssignMethod(wx_FTP, Pwd);
	Gura_AssignMethod(wx_FTP, Rename);
	Gura_AssignMethod(wx_FTP, RmFile);
	Gura_AssignMethod(wx_FTP, SetAscii);
	Gura_AssignMethod(wx_FTP, SetBinary);
	Gura_AssignMethod(wx_FTP, SetPassive);
	Gura_AssignMethod(wx_FTP, SetTransferMode);
	Gura_AssignMethod(wx_FTP, SetUser);
	Gura_AssignMethod(wx_FTP, SetPassword);
	Gura_AssignMethod(wx_FTP, FileExists);
	Gura_AssignMethod(wx_FTP, GetFileSize);
	Gura_AssignMethod(wx_FTP, GetDirList);
	Gura_AssignMethod(wx_FTP, GetFilesList);
	Gura_AssignMethod(wx_FTP, GetOutputStream);
	Gura_AssignMethod(wx_FTP, GetInputStream);
}

Gura_ImplementDescendantCreator(wx_FTP)
{
	return new Object_wx_FTP((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
