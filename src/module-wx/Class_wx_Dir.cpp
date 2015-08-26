//----------------------------------------------------------------------------
// wxDir
// extracted from dir.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Dir: public wxDir, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Dir *_pObj;
public:
	inline wx_Dir() : wxDir(), _pObj(nullptr) {}
	inline wx_Dir(const wxString& dir) : wxDir(dir), _pObj(nullptr) {}
	~wx_Dir();
	inline void AssocWithGura(Object_wx_Dir *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Dir::~wx_Dir()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Dir::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDir
//----------------------------------------------------------------------------
Gura_DeclareFunction(DirEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Dir));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DirEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Dir *pEntity = new wx_Dir();
	Object_wx_Dir *pObj = Object_wx_Dir::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Dir(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(Dir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Dir));
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Dir)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	wx_Dir *pEntity = new wx_Dir(dir);
	Object_wx_Dir *pObj = Object_wx_Dir::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Dir(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareClassMethod(wx_Dir, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Dir, Exists)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxDir::Exists(dir);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Dir, GetAllFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString dirname = wxString::FromUTF8(args.GetString(0));
	std::unique_ptr<wxArrayString> files(CreateArrayString(args.GetList(1)));
	wxString filespec = wxEmptyString;
	if (args.IsValid(2)) filespec = wxString::FromUTF8(args.GetString(2));
	int flags = wxDIR_DEFAULT;
	if (args.IsValid(3)) flags = args.GetInt(3);
	size_t rtn = wxDir::GetAllFiles(dirname, *files, filespec, flags);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Dir, FindFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Dir, FindFirst)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString dirname = wxString::FromUTF8(args.GetString(0));
	wxString filespec = wxString::FromUTF8(args.GetString(1));
	int flags = wxDIR_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	wxString rtn = wxDir::FindFirst(dirname, filespec, flags);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Dir, GetFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, GetFirst)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Dir *pThis = Object_wx_Dir::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString filespec = wxEmptyString;
	if (args.IsValid(1)) filespec = wxString::FromUTF8(args.GetString(1));
	int flags = wxDIR_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	bool rtn = pThis->GetEntity()->GetFirst(filename, filespec, flags);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Dir, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, GetNext)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Dir *pThis = Object_wx_Dir::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetNext(filename);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_Dir, GetTotalSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Dir, GetTotalSize)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString dir = wxString::FromUTF8(args.GetString(0));
	wxULongLong rtn = wxDir::GetTotalSize(dir, *filesSkipped);
	return ReturnValue(env, args, Value(new Object_wx_ULongLong(new wxULongLong(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, HasFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, HasFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filespec = wxEmptyString;
	if (args.IsValid(0)) filespec = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasFiles(filespec);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dir, HasSubDirs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dirspec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, HasSubDirs)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dirspec = wxEmptyString;
	if (args.IsValid(0)) dirspec = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasSubDirs(dirspec);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dir, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, IsOpened)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOpened();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dir, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, Open)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Open(dir);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dir, Traverse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "sink", VTYPE_wx_DirTraverser, OCCUR_Once);
	DeclareArg(env, "filespec", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dir, Traverse)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDirTraverser *sink = Object_wx_DirTraverser::GetObject(args, 0)->GetEntity();
	wxString filespec = wxEmptyString;
	if (args.IsValid(1)) filespec = wxString::FromUTF8(args.GetString(1));
	int flags = wxDIR_DEFAULT;
	if (args.IsValid(2)) flags = args.GetInt(2);
	size_t rtn = pThis->GetEntity()->Traverse(*sink, filespec, flags);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDir
//----------------------------------------------------------------------------
Object_wx_Dir::~Object_wx_Dir()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Dir::Clone() const
{
	return nullptr;
}

String Object_wx_Dir::ToString(bool exprFlag)
{
	String rtn("<wx.Dir:");
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
// Class implementation for wxDir
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dir)
{
	Gura_AssignFunction(DirEmpty);
	Gura_AssignFunction(Dir);
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
	return new Object_wx_Dir((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
