//----------------------------------------------------------------------------
// wxFontMapper
// extracted from fontmap.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FontMapper: public wxFontMapper, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FontMapper *_pObj;
public:
	inline wx_FontMapper() : wxFontMapper(), _sig(NULL), _pObj(NULL) {}
	~wx_FontMapper();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FontMapper *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontMapper::~wx_FontMapper()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FontMapper::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontMapper
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontMapper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontMapper));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontMapper)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FontMapper *pEntity = new wx_FontMapper();
	Object_wx_FontMapper *pObj = Object_wx_FontMapper::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FontMapper(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FontMapper, CharsetToEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "charset", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "interactive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontMapper, CharsetToEncoding)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString charset = wxString::FromUTF8(args.GetString(0));
	bool interactive = true;
	if (args.IsValid(1)) interactive = args.GetBoolean(1);
	wxFontEncoding rtn = pThis->GetEntity()->CharsetToEncoding(charset, interactive);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FontMapper, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, Get)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFontMapper *rtn = (wxFontMapper *)wxFontMapper::Get();
	return ReturnValue(env, sig, args, Value(new Object_wx_FontMapper(rtn, NULL, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_FontMapper, GetAllEncodingNames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetAllEncodingNames)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wxChar rtn = wxFontMapper::GetAllEncodingNames(encoding);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontMapper, GetAltForEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "facename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "interactive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontMapper, GetAltForEncoding)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wxNativeEncodingInfo info;
	wxString facename = wxEmptyString;
	if (args.IsValid(1)) facename = wxString::FromUTF8(args.GetString(1));
	bool interactive = true;
	if (args.IsValid(2)) interactive = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->GetAltForEncoding(encoding, &info, facename, interactive);
	Value value;
	if (rtn) {
		value = Value(new Object_wx_NativeEncodingInfo(new wxNativeEncodingInfo(info), NULL, OwnerTrue));
	}
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_FontMapper, GetAltForEncoding_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "alt_encoding", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "facename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "interactive", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontMapper, GetAltForEncoding_1)
{
#if 0
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wxFontEncoding alt_encoding = static_cast<wxFontEncoding>(args.GetInt(1));
	wxString facename = wxEmptyString;
	if (args.IsValid(2)) facename = wxString::FromUTF8(args.GetString(2));
	bool interactive = true;
	if (args.IsValid(3)) interactive = args.GetBoolean(3);
	bool rtn = pThis->GetEntity()->GetAltForEncoding(encoding, alt_encoding, facename, interactive);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FontMapper, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetEncoding)
{
	if (!CheckWxReady(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxFontEncoding rtn = wxFontMapper::GetEncoding(n);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FontMapper, GetEncodingDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetEncodingDescription)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wxString rtn = wxFontMapper::GetEncodingDescription(encoding);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FontMapper, GetEncodingFromName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetEncodingFromName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString encoding = wxString::FromUTF8(args.GetString(0));
	wxFontEncoding rtn = wxFontMapper::GetEncodingFromName(encoding);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FontMapper, GetEncodingName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetEncodingName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wxString rtn = wxFontMapper::GetEncodingName(encoding);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FontMapper, GetSupportedEncodingsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetSupportedEncodingsCount)
{
	if (!CheckWxReady(sig)) return Value::Null;
	size_t rtn = wxFontMapper::GetSupportedEncodingsCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontMapper, IsEncodingAvailable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "facename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontMapper, IsEncodingAvailable)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	wxString facename = wxEmptyString;
	if (args.IsValid(1)) facename = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->IsEncodingAvailable(encoding, facename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontMapper, SetDialogParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetDialogParent)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDialogParent(parent);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontMapper, SetDialogTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetDialogTitle)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDialogTitle(title);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_FontMapper, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mapper", VTYPE_wx_FontMapper, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, Set)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFontMapper *mapper = Object_wx_FontMapper::GetObject(args, 0)->GetEntity();
	wxFontMapper *rtn = (wxFontMapper *)wxFontMapper::Set(mapper);
	return ReturnValue(env, sig, args, Value(new Object_wx_FontMapper(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_FontMapper, SetConfig)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "config", VTYPE_wx_ConfigBase, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_FontMapper, SetConfig)
{
#if 0
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *config = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetConfig(config);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontMapper, SetConfigPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prefix", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetConfigPath)
{
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString prefix = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetConfigPath(prefix);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFontMapper
//----------------------------------------------------------------------------
Object_wx_FontMapper::~Object_wx_FontMapper()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_FontMapper::Clone() const
{
	return NULL;
}

String Object_wx_FontMapper::ToString(bool exprFlag)
{
	String rtn("<wx.FontMapper:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontMapper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontMapper)
{
	Gura_AssignFunction(FontMapper);
	Gura_AssignMethod(wx_FontMapper, CharsetToEncoding);
	Gura_AssignMethod(wx_FontMapper, Get);
	Gura_AssignMethod(wx_FontMapper, GetAllEncodingNames);
	Gura_AssignMethod(wx_FontMapper, GetAltForEncoding);
	Gura_AssignMethod(wx_FontMapper, GetAltForEncoding_1);
	Gura_AssignMethod(wx_FontMapper, GetEncoding);
	Gura_AssignMethod(wx_FontMapper, GetEncodingDescription);
	Gura_AssignMethod(wx_FontMapper, GetEncodingFromName);
	Gura_AssignMethod(wx_FontMapper, GetEncodingName);
	Gura_AssignMethod(wx_FontMapper, GetSupportedEncodingsCount);
	Gura_AssignMethod(wx_FontMapper, IsEncodingAvailable);
	Gura_AssignMethod(wx_FontMapper, SetDialogParent);
	Gura_AssignMethod(wx_FontMapper, SetDialogTitle);
	Gura_AssignMethod(wx_FontMapper, Set);
	Gura_AssignMethod(wx_FontMapper, SetConfig);
	Gura_AssignMethod(wx_FontMapper, SetConfigPath);
}

Gura_ImplementDescendantCreator(wx_FontMapper)
{
	return new Object_wx_FontMapper((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
