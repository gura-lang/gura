//----------------------------------------------------------------------------
// wxFileType
// extracted from filetype.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileType: public wxFileType, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileType *_pObj;
public:
	//inline wx_FileType() : wxFileType(), _pObj(nullptr) {}
	~wx_FileType();
	inline void AssocWithGura(Object_wx_FileType *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileType::~wx_FileType()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileType::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileType
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileTypeEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_FileType));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(FileTypeEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_FileType *pEntity = new wx_FileType();
	Object_wx_FileType *pObj = Object_wx_FileType::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileType(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, GetMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "mimeType", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetMimeType)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString mimeType = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetMimeType(mimeType);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, GetMimeType_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "mimeTypes", VTYPE_string, OCCUR_Once, FLAG_List);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetMimeType_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> mimeTypes(CreateArrayString(args.GetList(0)));
	bool rtn = pThis->GetEntity()->GetMimeType(*mimeTypes);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, GetExtensions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "extensions", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetExtensions)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayString> extensions(CreateArrayString(args.GetList(0)));
	bool rtn = pThis->GetEntity()->GetExtensions(*extensions);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileType, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "iconLoc", VTYPE_wx_IconLocation, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIconLocation *iconLoc = Object_wx_IconLocation::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->GetIcon(iconLoc);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileType, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "desc", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetDescription)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString desc = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetDescription(desc);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, GetOpenCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetOpenCommand)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString command = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetOpenCommand(command, );
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, GetOpenCommand_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetOpenCommand_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->GetOpenCommand(filename);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileType, GetPrintCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileType, GetPrintCommand)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString command = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->GetPrintCommand(command, );
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FileType, ExpandCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "command", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FileType, ExpandCommand)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString command = wxString::FromUTF8(args.GetString(0));
	wxString rtn = wxFileType::ExpandCommand(command, );
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFileType
//----------------------------------------------------------------------------
Object_wx_FileType::~Object_wx_FileType()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_FileType::Clone() const
{
	return nullptr;
}

String Object_wx_FileType::ToString(bool exprFlag)
{
	String rtn("<wx.FileType:");
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
// Class implementation for wxFileType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileType)
{
	Gura_AssignFunction(FileTypeEmpty);
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
	return new Object_wx_FileType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
