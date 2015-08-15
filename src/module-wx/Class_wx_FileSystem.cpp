//----------------------------------------------------------------------------
// wxFileSystem
// extracted from filesys.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileSystem: public wxFileSystem, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileSystem *_pObj;
public:
	inline wx_FileSystem() : wxFileSystem(), _pObj(nullptr) {}
	~wx_FileSystem();
	inline void AssocWithGura(Object_wx_FileSystem *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileSystem::~wx_FileSystem()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileSystem::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystem
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileSystem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileSystem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileSystem)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_FileSystem *pEntity = new wx_FileSystem();
	Object_wx_FileSystem *pObj = Object_wx_FileSystem::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileSystem(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareClassMethod(wx_FileSystem, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_FileSystemHandler, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_FileSystem, AddHandler)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFileSystemHandler *handler = Object_wx_FileSystemHandler::GetObject(args, 0)->GetEntity();
	wxFileSystem::AddHandler(handler);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileSystem, HasHandlerForPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileSystem, HasHandlerForPath)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFileSystem::HasHandlerForPath(location);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileSystem, ChangePathTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "is_dir", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, ChangePathTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(args.GetString(0));
	bool is_dir = false;
	if (args.IsValid(1)) is_dir = args.GetBoolean(1);
	pThis->GetEntity()->ChangePathTo(location, is_dir);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystem, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FileSystem, FileNameToURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_wx_FileName, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileSystem, FileNameToURL)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFileName *filename = Object_wx_FileName::GetObject(args, 0)->GetEntity();
	wxString rtn = wxFileSystem::FileNameToURL(*filename);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystem, FindFileInPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, FindFileInPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxString file = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->FindFileInPath(&str, path, file);
	Value value;
	if (rtn) value = Value(str.ToUTF8());
	return ReturnValue(env, args, value);
}

Gura_DeclareMethod(wx_FileSystem, FindFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, FindFirst)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString wildcard = wxString::FromUTF8(args.GetString(0));
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxString rtn = pThis->GetEntity()->FindFirst(wildcard, flags);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystem, FindNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, FindNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->FindNext();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystem, OpenFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystem, OpenFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystem *pThis = Object_wx_FileSystem::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(args.GetString(0));
	int flags = wxFS_READ;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxFSFile *rtn = (wxFSFile *)pThis->GetEntity()->OpenFile(location, flags);
	return ReturnValue(env, args, Value(new Object_wx_FSFile(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_FileSystem, URLToFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileSystem, URLToFileName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString url = wxString::FromUTF8(args.GetString(0));
	wxFileName rtn = wxFileSystem::URLToFileName(url);
	return ReturnValue(env, args, Value(new Object_wx_FileName(new wxFileName(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileSystem
//----------------------------------------------------------------------------
Object_wx_FileSystem::~Object_wx_FileSystem()
{
}

Object *Object_wx_FileSystem::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystem::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystem:");
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
// Class implementation for wxFileSystem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystem)
{
	Gura_AssignFunction(FileSystem);
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
	return new Object_wx_FileSystem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
