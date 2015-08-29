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
	//Gura::Signal *_pSig;
	Object_wx_FontMapper *_pObj;
public:
	inline wx_FontMapper() : wxFontMapper(), _pObj(nullptr) {}
	~wx_FontMapper();
	inline void AssocWithGura(Object_wx_FontMapper *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontMapper::~wx_FontMapper()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FontMapper::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_FontMapper *pEntity = new wx_FontMapper();
	Object_wx_FontMapper *pObj = Object_wx_FontMapper::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FontMapper(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString charset = wxString::FromUTF8(arg.GetString(0));
	bool interactive = true;
	if (arg.IsValid(1)) interactive = arg.GetBoolean(1);
	wxFontEncoding rtn = pThis->GetEntity()->CharsetToEncoding(charset, interactive);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_FontMapper, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, Get)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFontMapper *rtn = (wxFontMapper *)wxFontMapper::Get();
	return ReturnValue(env, arg, Value(new Object_wx_FontMapper(rtn, nullptr, OwnerFalse)));
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxFontEncoding encoding = static_cast<wxFontEncoding>(arg.GetInt(0));
	wxChar rtn = wxFontMapper::GetAllEncodingNames(encoding);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(arg.GetInt(0));
	wxNativeEncodingInfo info;
	wxString facename = wxEmptyString;
	if (arg.IsValid(1)) facename = wxString::FromUTF8(arg.GetString(1));
	bool interactive = true;
	if (arg.IsValid(2)) interactive = arg.GetBoolean(2);
	bool rtn = pThis->GetEntity()->GetAltForEncoding(encoding, &info, facename, interactive);
	Value value;
	if (rtn) {
		value = Value(new Object_wx_NativeEncodingInfo(new wxNativeEncodingInfo(info), nullptr, OwnerTrue));
	}
	return ReturnValue(env, arg, value);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(arg.GetInt(0));
	wxFontEncoding alt_encoding = static_cast<wxFontEncoding>(arg.GetInt(1));
	wxString facename = wxEmptyString;
	if (arg.IsValid(2)) facename = wxString::FromUTF8(arg.GetString(2));
	bool interactive = true;
	if (arg.IsValid(3)) interactive = arg.GetBoolean(3);
	bool rtn = pThis->GetEntity()->GetAltForEncoding(encoding, alt_encoding, facename, interactive);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FontMapper, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetEncoding)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	size_t n = arg.GetSizeT(0);
	wxFontEncoding rtn = wxFontMapper::GetEncoding(n);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_FontMapper, GetEncodingDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetEncodingDescription)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(arg.GetInt(0));
	wxString rtn = wxFontMapper::GetEncodingDescription(encoding);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FontMapper, GetEncodingFromName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetEncodingFromName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString encoding = wxString::FromUTF8(arg.GetString(0));
	wxFontEncoding rtn = wxFontMapper::GetEncodingFromName(encoding);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_FontMapper, GetEncodingName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetEncodingName)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(arg.GetInt(0));
	wxString rtn = wxFontMapper::GetEncodingName(encoding);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_FontMapper, GetSupportedEncodingsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, GetSupportedEncodingsCount)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	size_t rtn = wxFontMapper::GetSupportedEncodingsCount();
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFontEncoding encoding = static_cast<wxFontEncoding>(arg.GetInt(0));
	wxString facename = wxEmptyString;
	if (arg.IsValid(1)) facename = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->IsEncodingAvailable(encoding, facename);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FontMapper, SetDialogParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetDialogParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDialogParent(parent);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, SetDialogTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetDialogTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString title = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetDialogTitle(title);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_FontMapper, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mapper", VTYPE_wx_FontMapper, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontMapper, Set)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxFontMapper *mapper = Object_wx_FontMapper::GetObject(arg, 0)->GetEntity();
	wxFontMapper *rtn = (wxFontMapper *)wxFontMapper::Set(mapper);
	return ReturnValue(env, arg, Value(new Object_wx_FontMapper(rtn, nullptr, OwnerFalse)));
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxConfigBase *config = Object_wx_ConfigBase::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetConfig(config);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontMapper, SetConfigPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "prefix", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontMapper, SetConfigPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontMapper *pThis = Object_wx_FontMapper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString prefix = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetConfigPath(prefix);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFontMapper
//----------------------------------------------------------------------------
Object_wx_FontMapper::~Object_wx_FontMapper()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_FontMapper::Clone() const
{
	return nullptr;
}

String Object_wx_FontMapper::ToString(bool exprFlag)
{
	String rtn("<wx.FontMapper:");
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
	return new Object_wx_FontMapper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
