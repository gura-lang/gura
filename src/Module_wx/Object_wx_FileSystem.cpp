//----------------------------------------------------------------------------
// wxFileSystem
// extracted from filesys.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileSystem: public wxFileSystem, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileSystem *_pObj;
public:
	inline wx_FileSystem() : wxFileSystem(), _sig(NULL), _pObj(NULL) {}
	~wx_FileSystem();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileSystem *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileSystem::~wx_FileSystem()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileSystem::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystem
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileSystem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileSystem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileSystem)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FileSystem *pEntity = new wx_FileSystem();
	Object_wx_FileSystem *pObj = Object_wx_FileSystem::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileSystem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_FileSystem, AddHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_FileSystemHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_FileSystem, AddHandler)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFileSystemHandler *handler = Object_wx_FileSystemHandler::GetObject(args, 0)->GetEntity();
	wxFileSystem::AddHandler(handler);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileSystem, HasHandlerForPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileSystem, HasHandlerForPath)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileSystem::HasHandlerForPath(location);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileSystem, ChangePathTo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "is_dir", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, ChangePathTo)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	bool is_dir = false;
	if (args.IsValid(1)) is_dir = args.GetBoolean(1);
	pThis->GetEntity()->ChangePathTo(location, is_dir);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileSystem, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, GetPath)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileSystem, FileNameToURL)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_wx_FileName, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileSystem, FileNameToURL)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFileName *filename = Object_wx_FileName::GetObject(args, 0)->GetEntity();
	wxString rtn = wxFileSystem::FileNameToURL(*filename);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystem, FindFileInPath)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, FindFileInPath)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString file = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->FindFileInPath(&str, path, file);
	Value value;
	if (rtn) value = Value(env, str.ToUTF8());
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_FileSystem, FindFirst)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, FindFirst)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString wildcard = wxString::FromUTF8(args.GetString(0));
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxString rtn = pThis->GetEntity()->FindFirst(wildcard, flags);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystem, FindNext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, FindNext)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->FindNext();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystem, OpenFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, OpenFile)
{
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	int flags = wxFS_READ;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxFSFile *rtn = (wxFSFile *)pThis->GetEntity()->OpenFile(location, flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_FSFile(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_FileSystem, URLToFileName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileSystem, URLToFileName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	wxFileName rtn = wxFileSystem::URLToFileName(url);
	return ReturnValue(env, sig, args, Value(new Object_wx_FileName(new wxFileName(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileSystem
//----------------------------------------------------------------------------
Object_wx_FileSystem::~Object_wx_FileSystem()
{
}

Object *Object_wx_FileSystem::Clone() const
{
	return NULL;
}

String Object_wx_FileSystem::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FileSystem:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FileSystem::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(FileSystem);
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystem)
{
	Gura_AssignMethod(wx_FileSystem, AddHandler);
	Gura_AssignMethod(wx_FileSystem, HasHandlerForPath);
	Gura_AssignMethod(wx_FileSystem, ChangePathTo);
	Gura_AssignMethod(wx_FileSystem, GetPath);
	Gura_AssignMethod(wx_FileSystem, FileNameToURL);
	Gura_AssignMethod(wx_FileSystem, FindFileInPath);
	Gura_AssignMethod(wx_FileSystem, FindFirst);
	Gura_AssignMethod(wx_FileSystem, FindNext);
	Gura_AssignMethod(wx_FileSystem, OpenFile);
	Gura_AssignMethod(wx_FileSystem, URLToFileName);
}

Gura_ImplementDescendantCreator(wx_FileSystem)
{
	return new Object_wx_FileSystem((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
