//----------------------------------------------------------------------------
// wxFileSystemHandler
// extracted from filesysh.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(CanOpen);
Gura_DeclarePrivUserSymbol(FindFirst);
Gura_DeclarePrivUserSymbol(FindNext);
Gura_DeclarePrivUserSymbol(OpenFile);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileSystemHandler: public wxFileSystemHandler, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileSystemHandler *_pObj;
public:
	//inline wx_FileSystemHandler() : wxFileSystemHandler(), _pObj(nullptr) {}
	//virtual bool CanOpen(const wxString& location);
	//virtual wxString FindFirst(const wxString& wildcard, int flags);
	//virtual wxString FindNext();
	//virtual wxFSFile* OpenFile(wxFileSystem& fs, const wxString& location);
	~wx_FileSystemHandler();
	inline void AssocWithGura(Object_wx_FileSystemHandler *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileSystemHandler::~wx_FileSystemHandler()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileSystemHandler::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileSystemHandlerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileSystemHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileSystemHandlerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_FileSystemHandler *pEntity = new wx_FileSystemHandler();
	Object_wx_FileSystemHandler *pObj = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileSystemHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, CanOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, CanOpen)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->CanOpen(location);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FileSystemHandler, GetAnchor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetAnchor)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetAnchor(location);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetLeftLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetLeftLocation)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetLeftLocation(location);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetMimeTypeFromExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetMimeTypeFromExt)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetMimeTypeFromExt(location);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetProtocol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetProtocol)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetProtocol(location);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetRightLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetRightLocation)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString location = wxString::FromUTF8(arg.GetString(0));
	wxString rtn = pThis->GetEntity()->GetRightLocation(location);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileSystemHandler, FindFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, FindFirst)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString wildcard = wxString::FromUTF8(arg.GetString(0));
	int flags = 0;
	if (arg.IsValid(1)) flags = arg.GetInt(1);
	wxString rtn = pThis->GetEntity()->FindFirst(wildcard, flags);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystemHandler, FindNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, FindNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->FindNext();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystemHandler, OpenFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fs", VTYPE_wx_FileSystem, OCCUR_Once);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, OpenFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileSystem *fs = Object_wx_FileSystem::GetObject(arg, 0)->GetEntity();
	wxString location = wxString::FromUTF8(arg.GetString(1));
	wxFSFile *rtn = (wxFSFile *)pThis->GetEntity()->OpenFile(*fs, location);
	return ReturnValue(env, arg, Value(new Object_wx_FSFile(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Object_wx_FileSystemHandler::~Object_wx_FileSystemHandler()
{
}

Object *Object_wx_FileSystemHandler::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystemHandler::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystemHandler:");
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
// Class implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemHandler)
{
	Gura_RealizeUserSymbol(CanOpen);
	Gura_RealizeUserSymbol(FindFirst);
	Gura_RealizeUserSymbol(FindNext);
	Gura_RealizeUserSymbol(OpenFile);
	Gura_AssignFunction(FileSystemHandlerEmpty);
	Gura_AssignMethod(wx_FileSystemHandler, CanOpen);
	Gura_AssignMethod(wx_FileSystemHandler, GetAnchor);
	Gura_AssignMethod(wx_FileSystemHandler, GetLeftLocation);
	Gura_AssignMethod(wx_FileSystemHandler, GetMimeTypeFromExt);
	Gura_AssignMethod(wx_FileSystemHandler, GetProtocol);
	Gura_AssignMethod(wx_FileSystemHandler, GetRightLocation);
	Gura_AssignMethod(wx_FileSystemHandler, FindFirst);
	Gura_AssignMethod(wx_FileSystemHandler, FindNext);
	Gura_AssignMethod(wx_FileSystemHandler, OpenFile);
}

Gura_ImplementDescendantCreator(wx_FileSystemHandler)
{
	return new Object_wx_FileSystemHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
