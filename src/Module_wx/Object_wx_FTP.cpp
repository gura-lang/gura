//----------------------------------------------------------------------------
// wxFTP
// extracted from ftp.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FTP: public wxFTP, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FTP *_pObj;
public:
	inline wx_FTP() : wxFTP(), _sig(NULL), _pObj(NULL) {}
	~wx_FTP();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FTP *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FTP::~wx_FTP()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FTP::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFTP
//----------------------------------------------------------------------------
Gura_DeclareFunction(FTPEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FTP));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FTPEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FTP *pEntity = new wx_FTP();
	Object_wx_FTP *pObj = Object_wx_FTP::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FTP(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FTP, Abort)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, Abort)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Abort();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, CheckCommand)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ret", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, CheckCommand)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString command = wxString::FromUTF8(args.GetString(0));
	char ret = args.GetChar(1);
	bool rtn = pThis->GetEntity()->CheckCommand(command, ret);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, SendCommand)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, SendCommand)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString command = wxString::FromUTF8(args.GetString(0));
	char rtn = pThis->GetEntity()->SendCommand(command);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetLastResult)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetLastResult)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLastResult();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FTP, ChDir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, ChDir)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->ChDir(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, MkDir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, MkDir)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->MkDir(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, RmDir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, RmDir)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->RmDir(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, Pwd)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, Pwd)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->Pwd();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FTP, Rename)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "src", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dst", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, Rename)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString src = wxString::FromUTF8(args.GetString(0));
	wxString dst = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->Rename(src, dst);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, RmFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, RmFile)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->RmFile(path);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, SetAscii)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, SetAscii)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->SetAscii();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, SetBinary)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, SetBinary)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->SetBinary();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, SetPassive)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pasv", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_FTP, SetPassive)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool pasv = args.GetBoolean(0);
	pThis->GetEntity()->SetPassive(pasv);
	return Value::Null;
}

Gura_DeclareMethod(wx_FTP, SetTransferMode)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, SetTransferMode)
{
#if 0
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->SetTransferMode();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FTP, SetUser)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "user", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FTP, SetUser)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString user = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetUser(user);
	return Value::Null;
}

Gura_DeclareMethod(wx_FTP, SetPassword)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "passwd", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FTP, SetPassword)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString passwd = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetPassword(passwd);
	return Value::Null;
}

Gura_DeclareMethod(wx_FTP, FileExists)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, FileExists)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->FileExists(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetFileSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetFileSize)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->GetFileSize(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetDirList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "files", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetDirList)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> files(CreateArrayString(args.GetList(0)));
	wxString wildcard = wxT("");
	if (args.IsValid(1)) wildcard = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->GetDirList(*files, wildcard);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetFilesList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "files", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetFilesList)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> files(CreateArrayString(args.GetList(0)));
	wxString wildcard = wxT("");
	if (args.IsValid(1)) wildcard = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->GetFilesList(*files, wildcard);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FTP, GetOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetOutputStream)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString file = wxString::FromUTF8(args.GetString(0));
	wxOutputStream *rtn = (wxOutputStream *)pThis->GetEntity()->GetOutputStream(file);
	return ReturnValue(env, sig, args, Value(new Object_wx_OutputStream(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_FTP, GetInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FTP, GetInputStream)
{
	Object_wx_FTP *pThis = Object_wx_FTP::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxInputStream *rtn = (wxInputStream *)pThis->GetEntity()->GetInputStream(path);
	return ReturnValue(env, sig, args, Value(new Object_wx_InputStream(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFTP
//----------------------------------------------------------------------------
Object_wx_FTP::~Object_wx_FTP()
{
}

Object *Object_wx_FTP::Clone() const
{
	return NULL;
}

String Object_wx_FTP::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FTP:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FTP::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(FTPEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxFTP
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FTP)
{
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
	return new Object_wx_FTP((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
