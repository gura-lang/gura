//----------------------------------------------------------------------------
// wxDir
// extracted from dir.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Dir: public wxDir, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Dir *_pObj;
public:
	inline wx_Dir() : wxDir(), _sig(NULL), _pObj(NULL) {}
	inline wx_Dir(const wxString& dir) : wxDir(dir), _sig(NULL), _pObj(NULL) {}
	~wx_Dir();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Dir *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Dir::~wx_Dir()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Dir::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDir
//----------------------------------------------------------------------------
Gura_DeclareFunction(DirEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Dir));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DirEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Dir *pEntity = new wx_Dir();
	Object_wx_Dir *pObj = Object_wx_Dir::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Dir(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Dir)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Dir));
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Dir)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	wx_Dir *pEntity = new wx_Dir(dir);
	Object_wx_Dir *pObj = Object_wx_Dir::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Dir(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareClassMethod(wx_Dir, Exists)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Dir, Exists)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxDir::Exists(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Dir, GetAllFiles)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "files", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Dir, GetAllFiles)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString dirname = wxString::FromUTF8(args.GetString(0));
	std::auto_ptr<wxArrayString> files(CreateArrayString(args.GetList(1)));
	wxString filespec = wxEmptyString;
	if (args.IsValid(2)) filespec = wxString::FromUTF8(args.GetString(2));
	int flags = wxDIR_DEFAULT;
	if (args.IsValid(3)) flags = args.GetInt(3);
	size_t rtn = wxDir::GetAllFiles(dirname, *files, filespec, flags);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Dir, FindFirst)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Dir, FindFirst)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString dirname = wxString::FromUTF8(args.GetString(0));
	wxString filespec = wxString::FromUTF8(args.GetString(1));
	int flags = wxDIR_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wxString rtn = wxDir::FindFirst(dirname, filespec, flags);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Dir, GetFirst)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, GetFirst)
{
#if 0
	Object_wx_Dir *pSelf = Object_wx_Dir::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString filespec = wxEmptyString;
	if (args.IsValid(1)) filespec = wxString::FromUTF8(args.GetString(1));
	int flags = wxDIR_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pSelf->GetEntity()->GetFirst(filename, filespec, flags);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dir, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, GetName)
{
	Object_wx_Dir *pSelf = Object_wx_Dir::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Dir, GetNext)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, GetNext)
{
#if 0
	Object_wx_Dir *pSelf = Object_wx_Dir::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->GetNext(filename);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Dir, GetTotalSize)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Dir, GetTotalSize)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString dir = wxString::FromUTF8(args.GetString(0));
	wxULongLong rtn = wxDir::GetTotalSize(dir, *filesSkipped);
	return ReturnValue(env, sig, args, Value(new Object_wx_ULongLong(new wxULongLong(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dir, HasFiles)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, HasFiles)
{
	Object_wx_Dir *pSelf = Object_wx_Dir::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filespec = wxEmptyString;
	if (args.IsValid(0)) filespec = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->HasFiles(filespec);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dir, HasSubDirs)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dirspec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, HasSubDirs)
{
	Object_wx_Dir *pSelf = Object_wx_Dir::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString dirspec = wxEmptyString;
	if (args.IsValid(0)) dirspec = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->HasSubDirs(dirspec);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dir, IsOpened)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, IsOpened)
{
	Object_wx_Dir *pSelf = Object_wx_Dir::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOpened();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dir, Open)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, Open)
{
	Object_wx_Dir *pSelf = Object_wx_Dir::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->Open(dir);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dir, Traverse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sink", VTYPE_wx_DirTraverser, OCCUR_Once);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, Traverse)
{
	Object_wx_Dir *pSelf = Object_wx_Dir::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDirTraverser *sink = Object_wx_DirTraverser::GetObject(args, 0)->GetEntity();
	wxString filespec = wxEmptyString;
	if (args.IsValid(1)) filespec = wxString::FromUTF8(args.GetString(1));
	int flags = wxDIR_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	size_t rtn = pSelf->GetEntity()->Traverse(*sink, filespec, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDir
//----------------------------------------------------------------------------
Object_wx_Dir::~Object_wx_Dir()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Dir::Clone() const
{
	return NULL;
}

String Object_wx_Dir::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Dir:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Dir::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DirEmpty);
	Gura_AssignFunction(Dir);
}

//----------------------------------------------------------------------------
// Class implementation for wxDir
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dir)
{
	Gura_AssignMethod(wx_Dir, Exists);
	Gura_AssignMethod(wx_Dir, GetAllFiles);
	Gura_AssignMethod(wx_Dir, FindFirst);
	Gura_AssignMethod(wx_Dir, GetFirst);
	Gura_AssignMethod(wx_Dir, GetName);
	Gura_AssignMethod(wx_Dir, GetNext);
	Gura_AssignMethod(wx_Dir, GetTotalSize);
	Gura_AssignMethod(wx_Dir, HasFiles);
	Gura_AssignMethod(wx_Dir, HasSubDirs);
	Gura_AssignMethod(wx_Dir, IsOpened);
	Gura_AssignMethod(wx_Dir, Open);
	Gura_AssignMethod(wx_Dir, Traverse);
}

Gura_ImplementDescendantCreator(wx_Dir)
{
	return new Object_wx_Dir((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
