//----------------------------------------------------------------------------
// wxFontEnumerator
// extracted from fontenum.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(EnumerateFacenames);
Gura_DeclarePrivUserSymbol(EnumerateEncodings);
Gura_DeclarePrivUserSymbol(OnFacename);
Gura_DeclarePrivUserSymbol(OnFontEncoding);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FontEnumerator: public wxFontEnumerator, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FontEnumerator *_pObj;
public:
	inline wx_FontEnumerator() : wxFontEnumerator(), _sig(NULL), _pObj(NULL) {}
	virtual bool EnumerateFacenames(wxFontEncoding encoding, bool fixedWidthOnly);
	virtual bool EnumerateEncodings(const wxString& font);
	virtual bool OnFacename(const wxString& font);
	virtual bool OnFontEncoding(const wxString& font, const wxString& encoding);
	~wx_FontEnumerator();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FontEnumerator *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontEnumerator::~wx_FontEnumerator()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FontEnumerator::GuraObjectDeleted()
{
	_pObj = NULL;
}

bool wx_FontEnumerator::EnumerateFacenames(wxFontEncoding encoding, bool fixedWidthOnly)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, EnumerateFacenames);
	if (pFunc == NULL) return wxFontEnumerator::EnumerateFacenames(encoding, fixedWidthOnly);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(static_cast<int>(encoding)));
	valList.push_back(Value(fixedWidthOnly));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_FontEnumerator::EnumerateEncodings(const wxString& font)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, EnumerateEncodings);
	if (pFunc == NULL) return wxFontEnumerator::EnumerateEncodings(font);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(env, font.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_FontEnumerator::OnFacename(const wxString& font)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnFacename);
	if (pFunc == NULL) return wxFontEnumerator::OnFacename(font);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(env, font.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_FontEnumerator::OnFontEncoding(const wxString& font, const wxString& encoding)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnFontEncoding);
	if (pFunc == NULL) return wxFontEnumerator::EnumerateEncodings(font);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(env, font.ToUTF8()));
	valList.push_back(Value(env, encoding.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontEnumerator
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontEnumerator)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontEnumerator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontEnumerator)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FontEnumerator *pEntity = new wx_FontEnumerator();
	Object_wx_FontEnumerator *pObj = Object_wx_FontEnumerator::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FontEnumerator(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FontEnumerator, EnumerateFacenames)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fixedWidthOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontEnumerator, EnumerateFacenames)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFontEncoding encoding = wxFONTENCODING_SYSTEM;
	if (args.IsValid(0)) encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	bool fixedWidthOnly = false;
	if (args.IsValid(1)) fixedWidthOnly = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->wxFontEnumerator::EnumerateFacenames(encoding, fixedWidthOnly);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontEnumerator, EnumerateEncodings)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontEnumerator, EnumerateEncodings)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString font = wxT("");
	if (args.IsValid(0)) font = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->wxFontEnumerator::EnumerateEncodings(font);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FontEnumerator, GetEncodings)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "facename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontEnumerator, GetEncodings)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString facename = wxT("");
	if (args.IsValid(0)) facename = wxString::FromUTF8(args.GetString(0));
	wxArrayString rtn = wxFontEnumerator::GetEncodings(facename);
	return ReturnValue(env, sig, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareClassMethod(wx_FontEnumerator, GetFacenames)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "encoding", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fixedWidthOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontEnumerator, GetFacenames)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFontEncoding encoding = wxFONTENCODING_SYSTEM;
	if (args.IsValid(0)) encoding = static_cast<wxFontEncoding>(args.GetInt(0));
	bool fixedWidthOnly = false;
	if (args.IsValid(1)) fixedWidthOnly = args.GetBoolean(1);
	wxArrayString rtn = wxFontEnumerator::GetFacenames(encoding, fixedWidthOnly);
	return ReturnValue(env, sig, args, ArrayStringToValue(env, rtn));
}

Gura_DeclareClassMethod(wx_FontEnumerator, IsValidFacename)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "facename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FontEnumerator, IsValidFacename)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString facename = wxString::FromUTF8(args.GetString(0));
	bool rtn = wxFontEnumerator::IsValidFacename(facename);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontEnumerator, OnFacename)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontEnumerator, OnFacename)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString font = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->wxFontEnumerator::OnFacename(font);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontEnumerator, OnFontEncoding)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "encoding", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontEnumerator, OnFontEncoding)
{
	Object_wx_FontEnumerator *pThis = Object_wx_FontEnumerator::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString font = wxString::FromUTF8(args.GetString(0));
	wxString encoding = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->wxFontEnumerator::OnFontEncoding(font, encoding);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFontEnumerator
//----------------------------------------------------------------------------
Object_wx_FontEnumerator::~Object_wx_FontEnumerator()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_FontEnumerator::Clone() const
{
	return NULL;
}

String Object_wx_FontEnumerator::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FontEnumerator:");
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
// Class implementation for wxFontEnumerator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontEnumerator)
{
	Gura_RealizeUserSymbol(EnumerateFacenames);
	Gura_RealizeUserSymbol(EnumerateEncodings);
	Gura_RealizeUserSymbol(OnFacename);
	Gura_RealizeUserSymbol(OnFontEncoding);
	Gura_AssignFunction(FontEnumerator);
	Gura_AssignMethod(wx_FontEnumerator, EnumerateFacenames);
	Gura_AssignMethod(wx_FontEnumerator, EnumerateEncodings);
	Gura_AssignMethod(wx_FontEnumerator, GetEncodings);
	Gura_AssignMethod(wx_FontEnumerator, GetFacenames);
	Gura_AssignMethod(wx_FontEnumerator, IsValidFacename);
	Gura_AssignMethod(wx_FontEnumerator, OnFacename);
	Gura_AssignMethod(wx_FontEnumerator, OnFontEncoding);
}

Gura_ImplementDescendantCreator(wx_FontEnumerator)
{
	return new Object_wx_FontEnumerator((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
