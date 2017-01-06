//----------------------------------------------------------------------------
// wxLanguageInfo
// (handcoded)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(Language);
Gura_DeclarePrivUserSymbol(CanonicalName);
Gura_DeclarePrivUserSymbol(WinLang);
Gura_DeclarePrivUserSymbol(WinSublang);
Gura_DeclarePrivUserSymbol(Description);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_LanguageInfo: public wxLanguageInfo, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_LanguageInfo *_pObj;
public:
	inline wx_LanguageInfo() : wxLanguageInfo(), _pObj(nullptr) {}
	~wx_LanguageInfo();
	inline void AssocWithGura(Object_wx_LanguageInfo *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LanguageInfo::~wx_LanguageInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_LanguageInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLanguageInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(LanguageInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LanguageInfo));
	DeclareArg(env, "Language", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "CanonicalName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "Description", VTYPE_string, OCCUR_ZeroOrOnce);
#ifdef __WIN32__
	DeclareArg(env, "WinLang", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "WinSublang", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(LanguageInfo)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_LanguageInfo *pEntity = new wx_LanguageInfo();
	pEntity->Language = 0;
_MS(pEntity->WinLang = 0);
_MS(pEntity->WinSublang = 0);
	if (arg.IsValid(0)) pEntity->Language = arg.GetInt(0);
	if (arg.IsValid(1)) pEntity->CanonicalName = wxString::FromUTF8(arg.GetString(1));
	if (arg.IsValid(2)) pEntity->Description = wxString::FromUTF8(arg.GetString(2));
_MS(if (arg.IsValid(3)) pEntity->WinLang = arg.GetInt(3));
_MS(if (arg.IsValid(4)) pEntity->WinSublang = arg.GetInt(4));
	Object_wx_LanguageInfo *pObj = Object_wx_LanguageInfo::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_LanguageInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// wx.LanguageInfo#CanonicalName
Gura_DeclareProperty_RW(wx_LanguageInfo, CanonicalName)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(wx_LanguageInfo, CanonicalName)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	return Value(pObjThis->GetEntity()->CanonicalName.ToUTF8());
}

Gura_ImplementPropertySetter(wx_LanguageInfo, CanonicalName)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	pObjThis->GetEntity()->CanonicalName = wxString::FromUTF8(value.GetString());
	return value;
}

// wx.LanguageInfo#Description
Gura_DeclareProperty_RW(wx_LanguageInfo, Description)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(wx_LanguageInfo, Description)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	return Value(pObjThis->GetEntity()->Description.ToUTF8());
}

Gura_ImplementPropertySetter(wx_LanguageInfo, Description)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	pObjThis->GetEntity()->Description = wxString::FromUTF8(value.GetString());
	return value;
}

// wx.LanguageInfo#Language
Gura_DeclareProperty_RW(wx_LanguageInfo, Language)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(wx_LanguageInfo, Language)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	return Value(pObjThis->GetEntity()->Language);
}

Gura_ImplementPropertySetter(wx_LanguageInfo, Language)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	pObjThis->GetEntity()->Language = value.GetInt();
	return value;
}

#ifdef __WIN32__

// wx.LanguageInfo#WinLang
Gura_DeclareProperty_RW(wx_LanguageInfo, WinLang)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(wx_LanguageInfo, WinLang)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	return Value(pObjThis->GetEntity()->WinLang);
}

Gura_ImplementPropertySetter(wx_LanguageInfo, WinLang)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	pObjThis->GetEntity()->WinLang = value.GetInt();
	return value;
}

// wx.LanguageInfo#WinSublang
Gura_DeclareProperty_RW(wx_LanguageInfo, WinSublang)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(wx_LanguageInfo, WinSublang)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	return Value(pObjThis->GetEntity()->WinSublang);
}

Gura_ImplementPropertySetter(wx_LanguageInfo, WinSublang)
{
	Object_wx_LanguageInfo *pObjThis = Object_wx_LanguageInfo::GetObject(valueThis);
	pObjThis->GetEntity()->WinSublang = value.GetInt();
	return value;
}

#endif

//----------------------------------------------------------------------------
// Object implementation for wxLanguageInfo
//----------------------------------------------------------------------------
Object_wx_LanguageInfo::~Object_wx_LanguageInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_LanguageInfo::Clone() const
{
	return nullptr;
}

String Object_wx_LanguageInfo::ToString(bool exprFlag)
{
	String rtn("<wx.LanguageInfo:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p", GetEntity());
		rtn += buff;
		::sprintf(buff, "%d", GetEntity()->Language);
		rtn += buff;
		rtn += ":";
		rtn += GetEntity()->CanonicalName.ToUTF8();
		rtn += ":";
		rtn += GetEntity()->Description.ToUTF8();
#ifdef __WIN32__
		::sprintf(buff, "%d", GetEntity()->WinLang);
		rtn += ":";
		rtn += buff;
		::sprintf(buff, "%d", GetEntity()->WinSublang);
		rtn += ":";
		rtn += buff;
#endif
		rtn += ">";
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxLanguageInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LanguageInfo)
{
	// Assignment of properties
	Gura_AssignProperty(wx_LanguageInfo, CanonicalName);
	Gura_AssignProperty(wx_LanguageInfo, Description);
	Gura_AssignProperty(wx_LanguageInfo, Language);
#ifdef __WIN32__
	Gura_AssignProperty(wx_LanguageInfo, WinLang);
	Gura_AssignProperty(wx_LanguageInfo, WinSublang);
#endif
	Gura_RealizeUserSymbol(Language);
	Gura_RealizeUserSymbol(CanonicalName);
	Gura_RealizeUserSymbol(WinLang);
	Gura_RealizeUserSymbol(WinSublang);
	Gura_RealizeUserSymbol(Description);
	Gura_AssignFunction(LanguageInfo);
}

Gura_ImplementDescendantCreator(wx_LanguageInfo)
{
	return new Object_wx_LanguageInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
