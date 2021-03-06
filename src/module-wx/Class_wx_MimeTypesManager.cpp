//----------------------------------------------------------------------------
// wxMimeTypesManager
// extracted from mimetype.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MimeTypesManager: public wxMimeTypesManager, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MimeTypesManager *_pObj;
public:
	inline wx_MimeTypesManager() : wxMimeTypesManager(), _pObj(nullptr) {}
	~wx_MimeTypesManager();
	inline void AssocWithGura(Object_wx_MimeTypesManager *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MimeTypesManager::~wx_MimeTypesManager()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MimeTypesManager::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMimeTypesManager
//----------------------------------------------------------------------------
Gura_DeclareFunction(MimeTypesManagerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MimeTypesManager));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MimeTypesManagerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_MimeTypesManager *pEntity = new wx_MimeTypesManager();
	Object_wx_MimeTypesManager *pObj = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MimeTypesManager(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_MimeTypesManager, AddFallbacks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fallbacks", VTYPE_wx_FileTypeInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_MimeTypesManager, AddFallbacks)
{
	Signal &sig = env.GetSignal();
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileTypeInfo *fallbacks = Object_wx_FileTypeInfo::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->AddFallbacks(fallbacks);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MimeTypesManager, GetFileTypeFromExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extension", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, GetFileTypeFromExtension)
{
	Signal &sig = env.GetSignal();
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString extension = wxString::FromUTF8(arg.GetString(0));
	wxFileType *rtn = (wxFileType *)pThis->GetEntity()->GetFileTypeFromExtension(extension);
	return ReturnValue(env, arg, Value(new Object_wx_FileType(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MimeTypesManager, GetFileTypeFromMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mimeType", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, GetFileTypeFromMimeType)
{
	Signal &sig = env.GetSignal();
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString mimeType = wxString::FromUTF8(arg.GetString(0));
	wxFileType *rtn = (wxFileType *)pThis->GetEntity()->GetFileTypeFromMimeType(mimeType);
	return ReturnValue(env, arg, Value(new Object_wx_FileType(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MimeTypesManager, IsOfType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mimeType", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, IsOfType)
{
	Signal &sig = env.GetSignal();
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString mimeType = wxString::FromUTF8(arg.GetString(0));
	wxString wildcard = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->IsOfType(mimeType, wildcard);
	return ReturnValue(env, arg, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_MimeTypesManager, ReadMailcap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "fallback", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, ReadMailcap)
{
	Signal &sig = env.GetSignal();
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	bool fallback = false;
	if (arg.IsValid(1)) fallback = arg.GetBoolean(1);
	bool rtn = pThis->GetEntity()->ReadMailcap(filename, fallback);
	return ReturnValue(env, arg, Value(rtn));
}
#endif

#if 0
Gura_DeclareMethod(wx_MimeTypesManager, ReadMimeTypes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MimeTypesManager, ReadMimeTypes)
{
	Signal &sig = env.GetSignal();
	Object_wx_MimeTypesManager *pThis = Object_wx_MimeTypesManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->ReadMimeTypes(filename);
	return ReturnValue(env, arg, Value(rtn));
}
#endif

//----------------------------------------------------------------------------
// Object implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Object_wx_MimeTypesManager::~Object_wx_MimeTypesManager()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_MimeTypesManager::Clone() const
{
	return nullptr;
}

String Object_wx_MimeTypesManager::ToString(bool exprFlag)
{
	String rtn("<wx.MimeTypesManager:");
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
// Class implementation for wxMimeTypesManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MimeTypesManager)
{
	Gura_AssignFunction(MimeTypesManagerEmpty);
	Gura_AssignMethod(wx_MimeTypesManager, AddFallbacks);
	Gura_AssignMethod(wx_MimeTypesManager, GetFileTypeFromExtension);
	Gura_AssignMethod(wx_MimeTypesManager, GetFileTypeFromMimeType);
	Gura_AssignMethod(wx_MimeTypesManager, IsOfType);
	//Gura_AssignMethod(wx_MimeTypesManager, ReadMailcap);
	//Gura_AssignMethod(wx_MimeTypesManager, ReadMimeTypes);
}

Gura_ImplementDescendantCreator(wx_MimeTypesManager)
{
	return new Object_wx_MimeTypesManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
