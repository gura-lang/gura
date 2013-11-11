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
	Gura::Signal _sig;
	Object_wx_LanguageInfo *_pObj;
public:
	inline wx_LanguageInfo() : wxLanguageInfo(), _sig(NULL), _pObj(NULL) {}
	~wx_LanguageInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_LanguageInfo *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_LanguageInfo::~wx_LanguageInfo()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_LanguageInfo::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxLanguageInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(LanguageInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_LanguageInfo *pEntity = new wx_LanguageInfo();
	pEntity->Language = 0;
_MS(pEntity->WinLang = 0);
_MS(pEntity->WinSublang = 0);
	if (args.IsValid(0)) pEntity->Language = args.GetInt(0);
	if (args.IsValid(1)) pEntity->CanonicalName = wxString::FromUTF8(args.GetString(1));
	if (args.IsValid(2)) pEntity->Description = wxString::FromUTF8(args.GetString(2));
_MS(if (args.IsValid(3)) pEntity->WinLang = args.GetInt(3));
_MS(if (args.IsValid(4)) pEntity->WinSublang = args.GetInt(4));
	Object_wx_LanguageInfo *pObj = Object_wx_LanguageInfo::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_LanguageInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxLanguageInfo
//----------------------------------------------------------------------------
Object_wx_LanguageInfo::~Object_wx_LanguageInfo()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_LanguageInfo::Clone() const
{
	return NULL;
}

bool Object_wx_LanguageInfo::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(Language));
	symbols.insert(Gura_UserSymbol(CanonicalName));
	symbols.insert(Gura_UserSymbol(Description));
#ifdef __WIN32__
	symbols.insert(Gura_UserSymbol(WinLang));
	symbols.insert(Gura_UserSymbol(WinSublang));
#endif
	return true;
}

Value Object_wx_LanguageInfo::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(Language))) {
		return Value(GetEntity()->Language);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(CanonicalName))) {
		return Value(env, GetEntity()->CanonicalName.ToUTF8());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Description))) {
		return Value(env, GetEntity()->Description.ToUTF8());
#ifdef __WIN32__
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(WinLang))) {
		return Value(GetEntity()->WinLang);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(WinSublang))) {
		return Value(GetEntity()->WinSublang);
#endif
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_wx_LanguageInfo::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_UserSymbol(Language))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		GetEntity()->Language = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(CanonicalName))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		GetEntity()->CanonicalName = wxString::FromUTF8(value.GetString());
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Description))) {
		if (!value.MustBe_string(sig)) return Value::Null;
		GetEntity()->Description = wxString::FromUTF8(value.GetString());
		return value;
#ifdef __WIN32__
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(WinLang))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		GetEntity()->WinLang = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(WinSublang))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		GetEntity()->WinSublang = value.GetInt();
		return value;
#endif
	}
	return Value::Null;
}

String Object_wx_LanguageInfo::ToString(bool exprFlag)
{
	String rtn("<wx.LanguageInfo:");
	if (GetEntity() == NULL) {
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
	Gura_RealizeUserSymbol(Language);
	Gura_RealizeUserSymbol(CanonicalName);
	Gura_RealizeUserSymbol(WinLang);
	Gura_RealizeUserSymbol(WinSublang);
	Gura_RealizeUserSymbol(Description);
	Gura_AssignFunction(LanguageInfo);
}

Gura_ImplementDescendantCreator(wx_LanguageInfo)
{
	return new Object_wx_LanguageInfo((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
