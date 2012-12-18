//----------------------------------------------------------------------------
// wxString
// extracted from wxstring.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_String: public wxString, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_String *_pObj;
public:
	inline wx_String() : wxString(), _sig(NULL), _pObj(NULL) {}
	inline wx_String(const wxString& x) : wxString(x), _sig(NULL), _pObj(NULL) {}
	//inline wx_String(wxChar ch, size_t n) : wxString(ch, n), _sig(NULL), _pObj(NULL) {}
	//inline wx_String(const wxChar* psz, size_t nLength) : wxString(psz, nLength), _sig(NULL), _pObj(NULL) {}
	//inline wx_String(const unsigned char* psz, size_t nLength) : wxString(psz, nLength), _sig(NULL), _pObj(NULL) {}
	//inline wx_String(const wchar_t* psz, wxMBConv& conv, size_t nLength) : wxString(psz, conv, nLength), _sig(NULL), _pObj(NULL) {}
	//inline wx_String(const char* psz, wxMBConv& conv, size_t nLength) : wxString(psz, conv, nLength), _sig(NULL), _pObj(NULL) {}
	~wx_String();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_String *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_String::~wx_String()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_String::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxString
//----------------------------------------------------------------------------
Gura_DeclareFunction(String)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "str", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(String)
{
	wx_String *pEntity = args.IsValid(0)?
		new wx_String(wxString::FromUTF8(args.GetString(0))) : new wx_String();
	Object_wx_String *pObj = Object_wx_String::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(String_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(String_1)
{
#if 0
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	size_t n = 1;
	if (args.IsValid(1)) n = args.GetSizeT(1);
	wx_String *pEntity = new wx_String(ch, n);
	Object_wx_String *pObj = Object_wx_String::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(String_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "nLength", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(String_2)
{
#if 0
	wxString psz = wxString::FromUTF8(args.GetString(0));
	size_t nLength = wxSTRING_MAXLEN;
	if (args.IsValid(1)) nLength = args.GetSizeT(1);
	wx_String *pEntity = new wx_String(psz, nLength);
	Object_wx_String *pObj = Object_wx_String::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(String_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nLength", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(String_3)
{
#if 0
	unsigned char psz = args.GetUChar(0);
	size_t nLength = wxSTRING_MAXLEN;
	if (args.IsValid(1)) nLength = args.GetSizeT(1);
	wx_String *pEntity = new wx_String(psz, nLength);
	Object_wx_String *pObj = Object_wx_String::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(String_4)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
#if 0
	wchar_t psz = static_cast<wchar_t>(args.GetUShort(0));
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	size_t nLength = wxSTRING_MAXLEN;
	if (args.IsValid(2)) nLength = args.GetSizeT(2);
	wx_String *pEntity = new wx_String(psz, *conv, nLength);
	Object_wx_String *pObj = Object_wx_String::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(String_5)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
#if 0
	char psz = args.GetChar(0);
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	size_t nLength = wxSTRING_MAXLEN;
	if (args.IsValid(2)) nLength = args.GetSizeT(2);
	wx_String *pEntity = new wx_String(psz, *conv, nLength);
	Object_wx_String *pObj = Object_wx_String::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_String(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Alloc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Alloc)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t nLen = args.GetSizeT(0);
	pSelf->GetEntity()->Alloc(nLen);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Append)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Append)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pSelf->GetEntity()->Append(psz);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Append_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Append_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	int count = 1;
	if (args.IsValid(1)) count = args.GetInt(1);
	wxString rtn = pSelf->GetEntity()->Append(ch, count);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, AfterFirst)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, AfterFirst)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = pSelf->GetEntity()->AfterFirst(ch);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, AfterLast)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, AfterLast)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = pSelf->GetEntity()->AfterLast(ch);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, BeforeFirst)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, BeforeFirst)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = pSelf->GetEntity()->BeforeFirst(ch);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, BeforeLast)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, BeforeLast)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = pSelf->GetEntity()->BeforeLast(ch);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, c_str)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, c_str)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pSelf->GetEntity()->c_str();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, char_str)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, char_str)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMBConv *conv = (wxMBConv *)(&wxConvLibc);
	if (args.IsValid(0)) conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	wxWritableCharBuffer rtn = pSelf->GetEntity()->char_str(*conv);
	return ReturnValue(env, sig, args, Value(new Object_wx_WritableCharBuffer(new wxWritableCharBuffer(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Clear)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Cmp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Cmp)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString s = wxString::FromUTF8(args.GetString(0));
	int rtn = pSelf->GetEntity()->Cmp(s);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, CmpNoCase)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, CmpNoCase)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString s = wxString::FromUTF8(args.GetString(0));
	int rtn = pSelf->GetEntity()->CmpNoCase(s);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, CompareTo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "cmp", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, CompareTo)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	wxString::caseCompare cmp = wxString::exact;
	if (args.IsValid(1)) cmp = static_cast<wxString::caseCompare>(args.GetInt(1));
	int rtn = pSelf->GetEntity()->CompareTo(psz, cmp);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Contains)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Contains)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->Contains(str);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Empty)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Empty)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Empty();
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Find)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "fromEnd", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Find)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	bool fromEnd = false;
	if (args.IsValid(1)) fromEnd = args.GetBoolean(1);
	int rtn = pSelf->GetEntity()->Find(ch, fromEnd);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Find_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "sz", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Find_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString sz = wxString::FromUTF8(args.GetString(0));
	int rtn = pSelf->GetEntity()->Find(sz);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, First)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, First)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar c = static_cast<wxChar>(args.GetInt(0));
	int rtn = pSelf->GetEntity()->First(c);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, First_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, First_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	int rtn = pSelf->GetEntity()->First(psz);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, First_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, First_2)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	int rtn = pSelf->GetEntity()->First(str);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, fn_str)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, fn_str)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wchar_t rtn = pSelf->GetEntity()->fn_str();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, fn_str_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, fn_str_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char rtn = pSelf->GetEntity()->fn_str();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, fn_str_2)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, fn_str_2)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCharBuffer rtn = pSelf->GetEntity()->fn_str();
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_String, Format)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*format", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, Format)
{
#if 0
	wxChar *format = static_cast<wxChar>(args.GetInt(0));
	wxString rtn = wxString::Format(*format, );
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Freq)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Freq)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	int rtn = pSelf->GetEntity()->Freq(ch);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_String, From8BitData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, From8BitData)
{
#if 0
	char buf = args.GetChar(0);
	size_t len = args.GetSizeT(1);
	wxString rtn = wxString::From8BitData(buf, len);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_String, From8BitData_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, From8BitData_1)
{
#if 0
	char buf = args.GetChar(0);
	wxString rtn = wxString::From8BitData(buf);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_String, FromAscii)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, FromAscii)
{
#if 0
	char s = args.GetChar(0);
	wxString rtn = wxString::FromAscii(s);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_String, FromAscii_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_String, FromAscii_1)
{
#if 0
	char c = args.GetChar(0);
	wxString rtn = wxString::FromAscii(c);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, GetChar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, GetChar)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxChar rtn = pSelf->GetEntity()->GetChar(n);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, GetData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, GetData)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pSelf->GetEntity()->GetData();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, GetWritableChar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, GetWritableChar)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxChar rtn = pSelf->GetEntity()->GetWritableChar(n);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, GetWriteBuf)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, GetWriteBuf)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t len = args.GetSizeT(0);
	wxChar rtn = pSelf->GetEntity()->GetWriteBuf(len);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Index)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Index)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar ch = static_cast<wxChar>(args.GetInt(0));
	size_t rtn = pSelf->GetEntity()->Index(ch);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Index_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "sz", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Index_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString sz = wxString::FromUTF8(args.GetString(0));
	size_t rtn = pSelf->GetEntity()->Index(sz);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, IsAscii)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsAscii)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsAscii();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, IsEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsEmpty)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsEmpty();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, IsNull)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsNull)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsNull();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, IsNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsNumber)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsNumber();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, IsSameAs)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "psz", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "caseSensitive", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsSameAs)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString psz = wxString::FromUTF8(args.GetString(0));
	bool caseSensitive = true;
	if (args.IsValid(1)) caseSensitive = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->IsSameAs(psz, caseSensitive);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, IsSameAs_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "caseSensitive", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsSameAs_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar c = static_cast<wxChar>(args.GetInt(0));
	bool caseSensitive = true;
	if (args.IsValid(1)) caseSensitive = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->IsSameAs(c, caseSensitive);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, IsWord)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, IsWord)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsWord();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Last)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Last)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pSelf->GetEntity()->Last();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Last_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Last_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pSelf->GetEntity()->Last();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Left)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Left)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t count = args.GetSizeT(0);
	wxString rtn = pSelf->GetEntity()->Left(count);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Len)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Len)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->Len();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Length)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Length)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->Length();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Lower)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Lower)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->Lower();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, LowerCase)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, LowerCase)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->LowerCase();
	return Value::Null;
}

Gura_DeclareMethod(wx_String, MakeLower)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, MakeLower)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->MakeLower();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, MakeUpper)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, MakeUpper)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->MakeUpper();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Matches)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szMask", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Matches)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString szMask = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->Matches(szMask);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, mb_str)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, mb_str)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	char rtn = pSelf->GetEntity()->mb_str(*conv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, mb_str_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, mb_str_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	wxCharBuffer rtn = pSelf->GetEntity()->mb_str(*conv);
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Mid)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "count", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Mid)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t first = args.GetSizeT(0);
	size_t count = wxSTRING_MAXLEN;
	if (args.IsValid(1)) count = args.GetSizeT(1);
	wxString rtn = pSelf->GetEntity()->Mid(first, count);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Pad)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pad", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fromRight", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Pad)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t count = args.GetSizeT(0);
	wxChar pad = ' ';
	if (args.IsValid(1)) pad = static_cast<wxChar>(args.GetInt(1));
	bool fromRight = true;
	if (args.IsValid(2)) fromRight = args.GetBoolean(2);
	wxString rtn = pSelf->GetEntity()->Pad(count, pad, fromRight);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Prepend)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Prepend)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pSelf->GetEntity()->Prepend(str);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Printf)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pszFormat", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Printf)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString pszFormat = wxString::FromUTF8(args.GetString(0));
	int rtn = pSelf->GetEntity()->Printf(pszFormat, );
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Remove)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Remove)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	wxString rtn = pSelf->GetEntity()->Remove(pos);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Remove_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Remove_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	size_t len = args.GetSizeT(1);
	wxString rtn = pSelf->GetEntity()->Remove(pos, len);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, RemoveLast)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, RemoveLast)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->RemoveLast();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, Replace)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "szOld", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "szNew", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "replaceAll", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Replace)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString szOld = wxString::FromUTF8(args.GetString(0));
	wxString szNew = wxString::FromUTF8(args.GetString(1));
	bool replaceAll = true;
	if (args.IsValid(2)) replaceAll = args.GetBoolean(2);
	size_t rtn = pSelf->GetEntity()->Replace(szOld, szNew, replaceAll);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_String, Right)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Right)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t count = args.GetSizeT(0);
	wxString rtn = pSelf->GetEntity()->Right(count);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, SetChar)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_String, SetChar)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxChar ch = static_cast<wxChar>(args.GetInt(1));
	pSelf->GetEntity()->SetChar(n, ch);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Shrink)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Shrink)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Shrink();
	return Value::Null;
}

Gura_DeclareMethod(wx_String, StartsWith)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*prefix", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*rest", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, StartsWith)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar *prefix = static_cast<wxChar>(args.GetInt(0));
	wxString *rest = NULL;
	if (args.IsValid(1)) *rest = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->StartsWith(*prefix, *rest);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, EndsWith)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*suffix", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "*rest", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, EndsWith)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxChar *suffix = static_cast<wxChar>(args.GetInt(0));
	wxString *rest = NULL;
	if (args.IsValid(1)) *rest = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->EndsWith(*suffix, *rest);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Strip)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Strip)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->Strip();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, SubString)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, SubString)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t from = args.GetSizeT(0);
	size_t to = args.GetSizeT(1);
	wxString rtn = pSelf->GetEntity()->SubString(from, to);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, To8BitData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, To8BitData)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char rtn = pSelf->GetEntity()->To8BitData();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, To8BitData_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, To8BitData_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCharBuffer rtn = pSelf->GetEntity()->To8BitData();
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, ToAscii)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToAscii)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	char rtn = pSelf->GetEntity()->ToAscii();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, ToAscii_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToAscii_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCharBuffer rtn = pSelf->GetEntity()->ToAscii();
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, ToDouble)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToDouble)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	double *val = args.GetDouble(0);
	bool rtn = pSelf->GetEntity()->ToDouble(*val);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, ToLong)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToLong)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long *val = args.GetLong(0);
	int base = 10;
	if (args.IsValid(1)) base = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ToLong(*val, base);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, ToLongLong)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_wx_LongLong_t, OCCUR_Once);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToLongLong)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxLongLong_t **val = Object_wx_LongLong_t::GetObject(args, 0)->GetEntity();
	int base = 10;
	if (args.IsValid(1)) base = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ToLongLong(**val, base);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, ToULong)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToULong)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned *val = args.GetInt(0);
	int base = 10;
	if (args.IsValid(1)) base = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ToULong(*val, base);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, ToULongLong)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "*val", VTYPE_wx_ULongLong_t, OCCUR_Once);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToULongLong)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxULongLong_t **val = Object_wx_ULongLong_t::GetObject(args, 0)->GetEntity();
	int base = 10;
	if (args.IsValid(1)) base = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->ToULongLong(**val, base);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, ToUTF8)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, ToUTF8)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCharBuffer rtn = pSelf->GetEntity()->ToUTF8();
	return ReturnValue(env, sig, args, Value(env, rtn));
}

Gura_DeclareMethod(wx_String, Trim)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "fromRight", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Trim)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool fromRight = true;
	if (args.IsValid(0)) fromRight = args.GetBoolean(0);
	wxString rtn = pSelf->GetEntity()->Trim(fromRight);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Truncate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Truncate)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t len = args.GetSizeT(0);
	wxString rtn = pSelf->GetEntity()->Truncate(len);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, UngetWriteBuf)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, UngetWriteBuf)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->UngetWriteBuf();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, UngetWriteBuf_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_String, UngetWriteBuf_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t len = args.GetSizeT(0);
	pSelf->GetEntity()->UngetWriteBuf(len);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, Upper)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, Upper)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->Upper();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_String, UpperCase)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, UpperCase)
{
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->UpperCase();
	return Value::Null;
}

Gura_DeclareMethod(wx_String, utf8_str)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, utf8_str)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCharBuffer rtn = pSelf->GetEntity()->utf8_str();
	return ReturnValue(env, sig, args, Value(new Object_wx_CharBuffer(new wxCharBuffer(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, wc_str)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, wc_str)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	wchar_t rtn = pSelf->GetEntity()->wc_str(*conv);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, wc_str_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, wc_str_1)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	wxWCharBuffer rtn = pSelf->GetEntity()->wc_str(*conv);
	return ReturnValue(env, sig, args, Value(new Object_wx_WCharBuffer(new wxWCharBuffer(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_String, wchar_str)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_String, wchar_str)
{
#if 0
	Object_wx_String *pSelf = Object_wx_String::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWritableWCharBuffer rtn = pSelf->GetEntity()->wchar_str();
	return ReturnValue(env, sig, args, Value(new Object_wx_WritableWCharBuffer(new wxWritableWCharBuffer(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxString
//----------------------------------------------------------------------------
Object_wx_String::~Object_wx_String()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_String::Clone() const
{
	return NULL;
}

String Object_wx_String::ToString(Signal sig, bool exprFlag)
{
	String rtn = GetEntity()->ToUTF8();
	if (exprFlag) return MakeQuotedString(rtn.c_str());
	return rtn;
}

void Object_wx_String::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(String);
	Gura_AssignFunction(String_1);
	Gura_AssignFunction(String_2);
	Gura_AssignFunction(String_3);
	Gura_AssignFunction(String_4);
	Gura_AssignFunction(String_5);
}

//----------------------------------------------------------------------------
// Class implementation for wxString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClassWithCast(wx_String)
{
	Environment &env = *this;
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
	Gura_AssignMethod(wx_String, IsNumber);
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
	Gura_AssignValue(exact, wxString::exact);
	Gura_AssignValue(ignoreCase, wxString::ignoreCase);
}

Gura_ImplementDescendantCreator(wx_String)
{
	return new Object_wx_String((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_ImplementCastFrom(wx_String)
{
	if (!value.IsString()) return false;
	const char *str = value.GetString();
	wx_String *pEntity = new wx_String(wxString::FromUTF8(str));
	Object_wx_String *pObj = new Object_wx_String(pEntity, pEntity, OwnerTrue);
	pEntity->AssocWithGura(sig, pObj);
	value = Value(pObj);
	return true;
}

Gura_ImplementCastTo(wx_String)
{
	// Object_wx_String::ToString would cast to string
	return false;
}

}}
