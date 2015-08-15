//----------------------------------------------------------------------------
// wxString
// extracted from wxstring.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_String: public wxString, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_String *_pObj;
public:
	inline wx_String() : wxString(), _pObj(nullptr) {}
	inline wx_String(const wxString& x) : wxString(x), _pObj(nullptr) {}
	//inline wx_String(wxChar ch, size_t n) : wxString(ch, n), _pObj(nullptr) {}
	//inline wx_String(const wxChar* psz, size_t nLength) : wxString(psz, nLength), _pObj(nullptr) {}
	//inline wx_String(const unsigned char* psz, size_t nLength) : wxString(psz, nLength), _pObj(nullptr) {}
	//inline wx_String(const wchar_t* psz, wxMBConv& conv, size_t nLength) : wxString(psz, conv, nLength), _pObj(nullptr) {}
	//inline wx_String(const char* psz, wxMBConv& conv, size_t nLength) : wxString(psz, conv, nLength), _pObj(nullptr) {}
	~wx_String();
	inline void AssocWithGura(Object_wx_String *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_String::~wx_String()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_String::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxString
//----------------------------------------------------------------------------
Gura_DeclareFunction(String)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(String)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_String *pEntity = args.IsValid(0)?
		new wx_String(wxString::FromUTF8(args.GetString(0))) : new wx_String();
	Object_wx_String *pObj = Object_wx_String::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(String_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(String_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	size_t n = 1;
	if (args.IsValid(1)) n = args.GetSizeT(1);
	wx_String *pEntity = new wx_String(ch, n);
	Object_wx_String *pObj = Object_wx_String::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(String_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "nLength", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(String_2)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxString psz = wxString::FromUTF8(args.GetString(0));
	size_t nLength = wxSTRING_MAXLEN;
	if (args.IsValid(1)) nLength = args.GetSizeT(1);
	wx_String *pEntity = new wx_String(psz, nLength);
	Object_wx_String *pObj = Object_wx_String::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(String_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nLength", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(String_3)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	unsigned char psz = args.GetUChar(0);
	size_t nLength = wxSTRING_MAXLEN;
	if (args.IsValid(1)) nLength = args.GetSizeT(1);
	wx_String *pEntity = new wx_String(psz, nLength);
	Object_wx_String *pObj = Object_wx_String::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(String_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
	DeclareArg(env, "nLength", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(String_4)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(0));
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	size_t nLength = wxSTRING_MAXLEN;
	if (args.IsValid(2)) nLength = args.GetSizeT(2);
	wx_String *pEntity = new wx_String(psz, *conv, nLength);
	Object_wx_String *pObj = Object_wx_String::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(String_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
	DeclareArg(env, "nLength", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(String_5)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char psz = args.GetChar(0);
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	size_t nLength = wxSTRING_MAXLEN;
	if (args.IsValid(2)) nLength = args.GetSizeT(2);
	wx_String *pEntity = new wx_String(psz, *conv, nLength);
	Object_wx_String *pObj = Object_wx_String::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Alloc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Alloc)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t nLen = args.GetSizeT(0);
	pThis->GetEntity()->Alloc(nLen);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Append)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->Append(psz);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Append_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Append_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	int count = 1;
	if (args.IsValid(1)) count = args.GetInt(1);
	wxString rtn = pThis->GetEntity()->Append(ch, count);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, AfterFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, AfterFirst)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = pThis->GetEntity()->AfterFirst(ch);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, AfterLast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, AfterLast)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = pThis->GetEntity()->AfterLast(ch);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, BeforeFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, BeforeFirst)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = pThis->GetEntity()->BeforeFirst(ch);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, BeforeLast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, BeforeLast)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = pThis->GetEntity()->BeforeLast(ch);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, c_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, c_str)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->c_str();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, char_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, char_str)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMBConv *conv = (wxMBConv *)(&wxConvLibc);
	if (args.IsValid(0)) conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	wxWritableCharBuffer rtn = pThis->GetEntity()->char_str(*conv);
	return ReturnValue(env, args, Value(new Object_wx_WritableCharBuffer(new wxWritableCharBuffer(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Cmp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Cmp)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString s = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->Cmp(s);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, CmpNoCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, CmpNoCase)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString s = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->CmpNoCase(s);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, CompareTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "cmp", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, CompareTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	wxString::caseCompare cmp = wxString::exact;
	if (args.IsValid(1)) cmp = static_cast<wxString::caseCompare>(args.GetInt(1));
	int rtn = pThis->GetEntity()->CompareTo(psz, cmp);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Contains)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Contains(str);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Empty)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "fromEnd", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Find)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	bool fromEnd = false;
	if (args.IsValid(1)) fromEnd = args.GetBoolean(1);
	int rtn = pThis->GetEntity()->Find(ch, fromEnd);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "sz", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Find_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString sz = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->Find(sz);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, First)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, First)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar c = static_cast<wxChar>(args.GetInt(0));
	int rtn = pThis->GetEntity()->First(c);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, First_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, First_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->First(psz);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, First_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, First_2)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->First(str);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, fn_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, fn_str)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wchar_t rtn = pThis->GetEntity()->fn_str();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, fn_str_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, fn_str_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char rtn = pThis->GetEntity()->fn_str();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, fn_str_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, fn_str_2)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCharBuffer rtn = pThis->GetEntity()->fn_str();
	return ReturnValue(env, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_String, Format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*format", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, Format)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxChar *format = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = wxString::Format(*format, );
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Freq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Freq)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	int rtn = pThis->GetEntity()->Freq(ch);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_String, From8BitData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, From8BitData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char buf = args.GetChar(0);
	size_t len = args.GetSizeT(1);
	wxString rtn = wxString::From8BitData(buf, len);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_String, From8BitData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, From8BitData_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char buf = args.GetChar(0);
	wxString rtn = wxString::From8BitData(buf);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_String, FromAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, FromAscii)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char s = args.GetChar(0);
	wxString rtn = wxString::FromAscii(s);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_String, FromAscii_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, FromAscii_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	char c = args.GetChar(0);
	wxString rtn = wxString::FromAscii(c);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, GetChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, GetChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxChar rtn = pThis->GetEntity()->GetChar(n);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, GetData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetData();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, GetWritableChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, GetWritableChar)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxChar rtn = pThis->GetEntity()->GetWritableChar(n);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, GetWriteBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, GetWriteBuf)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t len = args.GetSizeT(0);
	wxChar rtn = pThis->GetEntity()->GetWriteBuf(len);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Index)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	size_t rtn = pThis->GetEntity()->Index(ch);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Index_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "sz", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Index_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString sz = wxString::FromUTF8(args.GetString(0));
	size_t rtn = pThis->GetEntity()->Index(sz);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsAscii)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsAscii();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsEmpty)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsNull)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsNull();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Is_number)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Is_number)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Is_number();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsSameAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caseSensitive", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsSameAs)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	bool caseSensitive = true;
	if (args.IsValid(1)) caseSensitive = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->IsSameAs(psz, caseSensitive);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsSameAs_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "caseSensitive", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsSameAs_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar c = static_cast<wxChar>(args.GetInt(0));
	bool caseSensitive = true;
	if (args.IsValid(1)) caseSensitive = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->IsSameAs(c, caseSensitive);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsWord)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsWord();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Last)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Last)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->Last();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Last_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Last_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->Last();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Left)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Left)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t count = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->Left(count);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Len)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Len)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->Len();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Length)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->Length();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Lower)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Lower)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->Lower();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, LowerCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, LowerCase)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->LowerCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, MakeLower)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, MakeLower)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->MakeLower();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, MakeUpper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, MakeUpper)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->MakeUpper();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Matches)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szMask", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Matches)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szMask = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Matches(szMask);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, mb_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, mb_str)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	char rtn = pThis->GetEntity()->mb_str(*conv);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, mb_str_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, mb_str_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	wxCharBuffer rtn = pThis->GetEntity()->mb_str(*conv);
	return ReturnValue(env, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Mid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Mid)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t first = args.GetSizeT(0);
	size_t count = wxString::npos;
	if (args.IsValid(1)) count = args.GetSizeT(1);
	wxString rtn = pThis->GetEntity()->Mid(first, count);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Pad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pad", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fromRight", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Pad)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t count = args.GetSizeT(0);
	wxChar pad = ' ';
	if (args.IsValid(1)) pad = static_cast<wxChar>(args.GetInt(1));
	bool fromRight = true;
	if (args.IsValid(2)) fromRight = args.GetBoolean(2);
	wxString rtn = pThis->GetEntity()->Pad(count, pad, fromRight);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Prepend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Prepend)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->Prepend(str);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Printf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pszFormat", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Printf)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString pszFormat = wxString::FromUTF8(args.GetString(0));
	int rtn = pThis->GetEntity()->Printf(pszFormat, );
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->Remove(pos);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Remove_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Remove_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = args.GetSizeT(0);
	size_t len = args.GetSizeT(1);
	wxString rtn = pThis->GetEntity()->Remove(pos, len);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, RemoveLast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, RemoveLast)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->RemoveLast();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szOld", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "szNew", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "replaceAll", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString szOld = wxString::FromUTF8(args.GetString(0));
	wxString szNew = wxString::FromUTF8(args.GetString(1));
	bool replaceAll = true;
	if (args.IsValid(2)) replaceAll = args.GetBoolean(2);
	size_t rtn = pThis->GetEntity()->Replace(szOld, szNew, replaceAll);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Right)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Right)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t count = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->Right(count);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, SetChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_String, SetChar)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxChar ch = static_cast<wxChar>(args.GetInt(1));
	pThis->GetEntity()->SetChar(n, ch);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Shrink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Shrink)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Shrink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, StartsWith)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*prefix", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*rest", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, StartsWith)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar *prefix = static_cast<wxChar>(args.GetInt(0));
	wxString *rest = nullptr;
	if (args.IsValid(1)) *rest = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->StartsWith(*prefix, *rest);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, EndsWith)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*suffix", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*rest", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, EndsWith)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar *suffix = static_cast<wxChar>(args.GetInt(0));
	wxString *rest = nullptr;
	if (args.IsValid(1)) *rest = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->EndsWith(*suffix, *rest);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Strip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Strip)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->Strip();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, SubString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, SubString)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t from = args.GetSizeT(0);
	size_t to = args.GetSizeT(1);
	wxString rtn = pThis->GetEntity()->SubString(from, to);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, To8BitData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, To8BitData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char rtn = pThis->GetEntity()->To8BitData();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, To8BitData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, To8BitData_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCharBuffer rtn = pThis->GetEntity()->To8BitData();
	return ReturnValue(env, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToAscii)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	char rtn = pThis->GetEntity()->ToAscii();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToAscii_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToAscii_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCharBuffer rtn = pThis->GetEntity()->ToAscii();
	return ReturnValue(env, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToDouble)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double *val = args.GetDouble(0);
	bool rtn = pThis->GetEntity()->ToDouble(*val);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToLong)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long *val = args.GetLong(0);
	int base = 10;
	if (args.IsValid(1)) base = args.GetInt(1);
	bool rtn = pThis->GetEntity()->ToLong(*val, base);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToLongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_wx_LongLong_t, OCCUR_Once);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToLongLong)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLongLong_t **val = Object_wx_LongLong_t::GetObject(args, 0)->GetEntity();
	int base = 10;
	if (args.IsValid(1)) base = args.GetInt(1);
	bool rtn = pThis->GetEntity()->ToLongLong(**val, base);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToULong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToULong)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned *val = args.GetInt(0);
	int base = 10;
	if (args.IsValid(1)) base = args.GetInt(1);
	bool rtn = pThis->GetEntity()->ToULong(*val, base);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToULongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_wx_ULongLong_t, OCCUR_Once);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToULongLong)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxULongLong_t **val = Object_wx_ULongLong_t::GetObject(args, 0)->GetEntity();
	int base = 10;
	if (args.IsValid(1)) base = args.GetInt(1);
	bool rtn = pThis->GetEntity()->ToULongLong(**val, base);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToUTF8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToUTF8)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCharBuffer rtn = pThis->GetEntity()->ToUTF8();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Trim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "fromRight", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Trim)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool fromRight = true;
	if (args.IsValid(0)) fromRight = args.GetBoolean(0);
	wxString rtn = pThis->GetEntity()->Trim(fromRight);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Truncate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Truncate)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t len = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->Truncate(len);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, UngetWriteBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, UngetWriteBuf)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UngetWriteBuf();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, UngetWriteBuf_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_String, UngetWriteBuf_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t len = args.GetSizeT(0);
	pThis->GetEntity()->UngetWriteBuf(len);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Upper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Upper)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->Upper();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, UpperCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, UpperCase)
{
	Signal &sig = env.GetSignal();
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UpperCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, utf8_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, utf8_str)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCharBuffer rtn = pThis->GetEntity()->utf8_str();
	return ReturnValue(env, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wc_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, wc_str)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	wchar_t rtn = pThis->GetEntity()->wc_str(*conv);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wc_str_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, wc_str_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	wxWCharBuffer rtn = pThis->GetEntity()->wc_str(*conv);
	return ReturnValue(env, args, Value(new Object_wx_WCharBuffer(new wxWCharBuffer(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wchar_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, wchar_str)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_String *pThis = Object_wx_String::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWritableWCharBuffer rtn = pThis->GetEntity()->wchar_str();
	return ReturnValue(env, args, Value(new Object_wx_WritableWCharBuffer(new wxWritableWCharBuffer(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxString
//----------------------------------------------------------------------------
Object_wx_String::~Object_wx_String()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_String::Clone() const
{
	return nullptr;
}

String Object_wx_String::ToString(bool exprFlag)
{
	if (exprFlag) return MakeQuotedString(GetEntity()->ToUTF8());
	return String(GetEntity()->ToUTF8());
}

//----------------------------------------------------------------------------
// Class implementation for wxString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClassWithCast(wx_String)
{
	Gura_AssignFunction(String);
	Gura_AssignFunction(String_1);
	Gura_AssignFunction(String_2);
	Gura_AssignFunction(String_3);
	Gura_AssignFunction(String_4);
	Gura_AssignFunction(String_5);
	Gura_AssignMethod(wx_String, Alloc);
	Gura_AssignMethod(wx_String, Append);
	Gura_AssignMethod(wx_String, Append_1);
	Gura_AssignMethod(wx_String, AfterFirst);
	Gura_AssignMethod(wx_String, AfterLast);
	Gura_AssignMethod(wx_String, BeforeFirst);
	Gura_AssignMethod(wx_String, BeforeLast);
	Gura_AssignMethod(wx_String, c_str);
	Gura_AssignMethod(wx_String, char_str);
	Gura_AssignMethod(wx_String, Clear);
	Gura_AssignMethod(wx_String, Cmp);
	Gura_AssignMethod(wx_String, CmpNoCase);
	Gura_AssignMethod(wx_String, CompareTo);
	Gura_AssignMethod(wx_String, Contains);
	Gura_AssignMethod(wx_String, Empty);
	Gura_AssignMethod(wx_String, Find);
	Gura_AssignMethod(wx_String, Find_1);
	Gura_AssignMethod(wx_String, First);
	Gura_AssignMethod(wx_String, First_1);
	Gura_AssignMethod(wx_String, First_2);
	Gura_AssignMethod(wx_String, fn_str);
	Gura_AssignMethod(wx_String, fn_str_1);
	Gura_AssignMethod(wx_String, fn_str_2);
	Gura_AssignMethod(wx_String, Format);
	Gura_AssignMethod(wx_String, Freq);
	Gura_AssignMethod(wx_String, From8BitData);
	Gura_AssignMethod(wx_String, From8BitData_1);
	Gura_AssignMethod(wx_String, FromAscii);
	Gura_AssignMethod(wx_String, FromAscii_1);
	Gura_AssignMethod(wx_String, GetChar);
	Gura_AssignMethod(wx_String, GetData);
	Gura_AssignMethod(wx_String, GetWritableChar);
	Gura_AssignMethod(wx_String, GetWriteBuf);
	Gura_AssignMethod(wx_String, Index);
	Gura_AssignMethod(wx_String, Index_1);
	Gura_AssignMethod(wx_String, IsAscii);
	Gura_AssignMethod(wx_String, IsEmpty);
	Gura_AssignMethod(wx_String, IsNull);
	Gura_AssignMethod(wx_String, Is_number);
	Gura_AssignMethod(wx_String, IsSameAs);
	Gura_AssignMethod(wx_String, IsSameAs_1);
	Gura_AssignMethod(wx_String, IsWord);
	Gura_AssignMethod(wx_String, Last);
	Gura_AssignMethod(wx_String, Last_1);
	Gura_AssignMethod(wx_String, Left);
	Gura_AssignMethod(wx_String, Len);
	Gura_AssignMethod(wx_String, Length);
	Gura_AssignMethod(wx_String, Lower);
	Gura_AssignMethod(wx_String, LowerCase);
	Gura_AssignMethod(wx_String, MakeLower);
	Gura_AssignMethod(wx_String, MakeUpper);
	Gura_AssignMethod(wx_String, Matches);
	Gura_AssignMethod(wx_String, mb_str);
	Gura_AssignMethod(wx_String, mb_str_1);
	Gura_AssignMethod(wx_String, Mid);
	Gura_AssignMethod(wx_String, Pad);
	Gura_AssignMethod(wx_String, Prepend);
	Gura_AssignMethod(wx_String, Printf);
	Gura_AssignMethod(wx_String, Remove);
	Gura_AssignMethod(wx_String, Remove_1);
	Gura_AssignMethod(wx_String, RemoveLast);
	Gura_AssignMethod(wx_String, Replace);
	Gura_AssignMethod(wx_String, Right);
	Gura_AssignMethod(wx_String, SetChar);
	Gura_AssignMethod(wx_String, Shrink);
	Gura_AssignMethod(wx_String, StartsWith);
	Gura_AssignMethod(wx_String, EndsWith);
	Gura_AssignMethod(wx_String, Strip);
	Gura_AssignMethod(wx_String, SubString);
	Gura_AssignMethod(wx_String, To8BitData);
	Gura_AssignMethod(wx_String, To8BitData_1);
	Gura_AssignMethod(wx_String, ToAscii);
	Gura_AssignMethod(wx_String, ToAscii_1);
	Gura_AssignMethod(wx_String, ToDouble);
	Gura_AssignMethod(wx_String, ToLong);
	Gura_AssignMethod(wx_String, ToLongLong);
	Gura_AssignMethod(wx_String, ToULong);
	Gura_AssignMethod(wx_String, ToULongLong);
	Gura_AssignMethod(wx_String, ToUTF8);
	Gura_AssignMethod(wx_String, Trim);
	Gura_AssignMethod(wx_String, Truncate);
	Gura_AssignMethod(wx_String, UngetWriteBuf);
	Gura_AssignMethod(wx_String, UngetWriteBuf_1);
	Gura_AssignMethod(wx_String, Upper);
	Gura_AssignMethod(wx_String, UpperCase);
	Gura_AssignMethod(wx_String, utf8_str);
	Gura_AssignMethod(wx_String, wc_str);
	Gura_AssignMethod(wx_String, wc_str_1);
	Gura_AssignMethod(wx_String, wchar_str);
	Gura_AssignClassValue(exact, wxString::exact);
	Gura_AssignClassValue(ignoreCase, wxString::ignoreCase);
}

Gura_ImplementDescendantCreator(wx_String)
{
	return new Object_wx_String((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_ImplementCastFrom(wx_String)
{
	if (!value.Is_string()) return false;
	const char *str = value.GetString();
	wx_String *pEntity = new wx_String(wxString::FromUTF8(str));
	Object_wx_String *pObj = new Object_wx_String(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(pObj);
	value = Value(pObj);
	return true;
}

Gura_ImplementCastTo(wx_String)
{
	// Object_wx_String::ToString would cast to string
	return false;
}

Gura_EndModuleScope(wx)
