//----------------------------------------------------------------------------
// wxFileType
// extracted from filetype.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileType: public wxFileType, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FileType *_pObj;
public:
	//inline wx_FileType() : wxFileType(), _sig(NULL), _pObj(NULL) {}
	~wx_FileType();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FileType *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileType::~wx_FileType()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FileType::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileType
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileTypeEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileType));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileTypeEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_FileType *pEntity = new wx_FileType();
	Object_wx_FileType *pObj = Object_wx_FileType::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FileType(pEntity, pEntity, OwnerFalse);
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

Gura_DeclareMethod(wx_FileType, GetMimeType)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "mimeType", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetMimeType)
{
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString mimeType = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetMimeType(mimeType);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileType, GetMimeType_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "mimeTypes", VTYPE_string, OCCUR_Once, FLAG_List);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetMimeType_1)
{
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> mimeTypes(CreateArrayString(args.GetList(0)));
	bool rtn = pThis->GetEntity()->GetMimeType(*mimeTypes);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileType, GetExtensions)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extensions", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetExtensions)
{
	Object_wx_FileType *pThis = Object_wx_FileType::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayString> extensions(CreateArrayString(args.GetList(0)));
	bool rtn = pThis->GetEntity()->GetExtensions(*extensions);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileType, GetIcon)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "iconLoc", VTYPE_wx_IconLocation, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetIcon)
{
	Object_wx_FileType *pThis = Object_wx_FileType::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIconLocation *iconLoc = Object_wx_IconLocation::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->GetIcon(iconLoc);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileType, GetDescription)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "desc", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetDescription)
{
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString desc = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetDescription(desc);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileType, GetOpenCommand)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetOpenCommand)
{
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString command = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetOpenCommand(command, );
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FileType, GetOpenCommand_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetOpenCommand_1)
{
	Object_wx_FileType *pThis = Object_wx_FileType::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetOpenCommand(filename);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileType, GetPrintCommand)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetPrintCommand)
{
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString command = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetPrintCommand(command, );
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FileType, ExpandCommand)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileType, ExpandCommand)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString command = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxFileType::ExpandCommand(command, );
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFileType
//----------------------------------------------------------------------------
Object_wx_FileType::~Object_wx_FileType()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_FileType::Clone() const
{
	return NULL;
}

String Object_wx_FileType::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FileType:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FileType::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(FileTypeEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxFileType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileType)
{
	Gura_AssignMethod(wx_FileType, GetMimeType);
	Gura_AssignMethod(wx_FileType, GetMimeType_1);
	Gura_AssignMethod(wx_FileType, GetExtensions);
	Gura_AssignMethod(wx_FileType, GetIcon);
	Gura_AssignMethod(wx_FileType, GetDescription);
	Gura_AssignMethod(wx_FileType, GetOpenCommand);
	Gura_AssignMethod(wx_FileType, GetOpenCommand_1);
	Gura_AssignMethod(wx_FileType, GetPrintCommand);
	Gura_AssignMethod(wx_FileType, ExpandCommand);
}

Gura_ImplementDescendantCreator(wx_FileType)
{
	return new Object_wx_FileType((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
