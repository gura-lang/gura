//----------------------------------------------------------------------------
// wxFileSystemHandler
// extracted from filesysh.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(CanOpen);
Gura_DeclarePrivUserSymbol(FindFirst);
Gura_DeclarePrivUserSymbol(FindNext);
Gura_DeclarePrivUserSymbol(OpenFile);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileSystemHandler: public wxFileSystemHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileSystemHandler *_pObj;
public:
	//inline wx_FileSystemHandler() : wxFileSystemHandler(), _sig(NULL), _pObj(NULL) {}
	//virtual bool CanOpen(const wxString& location);
	//virtual wxString FindFirst(const wxString& wildcard, int flags);
	//virtual wxString FindNext();
	//virtual wxFSFile* OpenFile(wxFileSystem& fs, const wxString& location);
	~wx_FileSystemHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileSystemHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileSystemHandler::~wx_FileSystemHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileSystemHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileSystemHandlerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileSystemHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileSystemHandlerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_FileSystemHandler *pEntity = new wx_FileSystemHandler();
	Object_wx_FileSystemHandler *pObj = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileSystemHandler(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileSystemHandler, CanOpen)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, CanOpen)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->CanOpen(location);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileSystemHandler, GetAnchor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetAnchor)
{
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetAnchor(location);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetLeftLocation)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetLeftLocation)
{
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetLeftLocation(location);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetMimeTypeFromExt)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetMimeTypeFromExt)
{
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetMimeTypeFromExt(location);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetProtocol)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetProtocol)
{
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetProtocol(location);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileSystemHandler, GetRightLocation)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, GetRightLocation)
{
#if 0
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetRightLocation(location);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileSystemHandler, FindFirst)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, FindFirst)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString wildcard = wxString::FromUTF8(args.GetString(0));
	int flags = 0;
	if (args.IsValid(1)) flags = args.GetInt(1);
	wxString rtn = pThis->GetEntity()->FindFirst(wildcard, flags);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystemHandler, FindNext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, FindNext)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->FindNext();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileSystemHandler, OpenFile)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fs", VTYPE_wx_FileSystem, OCCUR_Once);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileSystemHandler, OpenFile)
{
	Object_wx_FileSystemHandler *pThis = Object_wx_FileSystemHandler::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileSystem *fs = Object_wx_FileSystem::GetObject(args, 0)->GetEntity();
	wxString location = wxString::FromUTF8(args.GetString(1));
	wxFSFile *rtn = (wxFSFile *)pThis->GetEntity()->OpenFile(*fs, location);
	return ReturnValue(env, sig, args, Value(new Object_wx_FSFile(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Object_wx_FileSystemHandler::~Object_wx_FileSystemHandler()
{
}

Object *Object_wx_FileSystemHandler::Clone() const
{
	return NULL;
}

String Object_wx_FileSystemHandler::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FileSystemHandler:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FileSystemHandler::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(CanOpen);
	Gura_RealizeUserSymbol(FindFirst);
	Gura_RealizeUserSymbol(FindNext);
	Gura_RealizeUserSymbol(OpenFile);
	Gura_AssignFunction(FileSystemHandlerEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemHandler)
{
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
	return new Object_wx_FileSystemHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
