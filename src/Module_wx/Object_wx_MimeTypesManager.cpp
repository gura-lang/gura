//----------------------------------------------------------------------------
// wxMimeTypesManager
// extracted from mimetype.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MimeTypesManager: public wxMimeTypesManager, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MimeTypesManager *_pObj;
public:
	inline wx_MimeTypesManager() : wxMimeTypesManager(), _sig(NULL), _pObj(NULL) {}
	~wx_MimeTypesManager();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MimeTypesManager *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MimeTypesManager::~wx_MimeTypesManager()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MimeTypesManager::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMimeTypesManager
//----------------------------------------------------------------------------
Gura_DeclareFunction(MimeTypesManagerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MimeTypesManager));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MimeTypesManagerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_MimeTypesManager *pEntity = new wx_MimeTypesManager();
	Object_wx_MimeTypesManager *pObj = Object_wx_MimeTypesManager::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MimeTypesManager(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_MimeTypesManager, AddFallbacks)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fallbacks", VTYPE_wx_FileTypeInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, AddFallbacks)
{
	Object_wx_MimeTypesManager *pSelf = Object_wx_MimeTypesManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileTypeInfo *fallbacks = Object_wx_FileTypeInfo::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->AddFallbacks(fallbacks);
	return Value::Null;
}

Gura_DeclareMethod(wx_MimeTypesManager, GetFileTypeFromExtension)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, GetFileTypeFromExtension)
{
	Object_wx_MimeTypesManager *pSelf = Object_wx_MimeTypesManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString extension = wxString::FromUTF8(args.GetString(0));
	wxFileType *rtn = (wxFileType *)pSelf->GetEntity()->GetFileTypeFromExtension(extension);
	return ReturnValue(env, sig, args, Value(new Object_wx_FileType(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_MimeTypesManager, GetFileTypeFromMimeType)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mimeType", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, GetFileTypeFromMimeType)
{
	Object_wx_MimeTypesManager *pSelf = Object_wx_MimeTypesManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString mimeType = wxString::FromUTF8(args.GetString(0));
	wxFileType *rtn = (wxFileType *)pSelf->GetEntity()->GetFileTypeFromMimeType(mimeType);
	return ReturnValue(env, sig, args, Value(new Object_wx_FileType(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_MimeTypesManager, IsOfType)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mimeType", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, IsOfType)
{
	Object_wx_MimeTypesManager *pSelf = Object_wx_MimeTypesManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString mimeType = wxString::FromUTF8(args.GetString(0));
	wxString wildcard = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->IsOfType(mimeType, wildcard);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MimeTypesManager, ReadMailcap)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fallback", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, ReadMailcap)
{
	Object_wx_MimeTypesManager *pSelf = Object_wx_MimeTypesManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool fallback = false;
	if (args.IsValid(1)) fallback = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->ReadMailcap(filename, fallback);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_MimeTypesManager, ReadMimeTypes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, ReadMimeTypes)
{
	Object_wx_MimeTypesManager *pSelf = Object_wx_MimeTypesManager::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->ReadMimeTypes(filename);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Object_wx_MimeTypesManager::~Object_wx_MimeTypesManager()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_MimeTypesManager::Clone() const
{
	return NULL;
}

String Object_wx_MimeTypesManager::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MimeTypesManager:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MimeTypesManager::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MimeTypesManagerEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MimeTypesManager)
{
	Gura_AssignMethod(wx_MimeTypesManager, AddFallbacks);
	Gura_AssignMethod(wx_MimeTypesManager, GetFileTypeFromExtension);
	Gura_AssignMethod(wx_MimeTypesManager, GetFileTypeFromMimeType);
	Gura_AssignMethod(wx_MimeTypesManager, IsOfType);
	Gura_AssignMethod(wx_MimeTypesManager, ReadMailcap);
	Gura_AssignMethod(wx_MimeTypesManager, ReadMimeTypes);
}

Gura_ImplementDescendantCreator(wx_MimeTypesManager)
{
	return new Object_wx_MimeTypesManager((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
