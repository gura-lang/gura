//----------------------------------------------------------------------------
// wxStringTokenizer
// extracted from tokenizr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StringTokenizer: public wxStringTokenizer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StringTokenizer *_pObj;
public:
	inline wx_StringTokenizer() : wxStringTokenizer(), _sig(NULL), _pObj(NULL) {}
	inline wx_StringTokenizer(const wxString& str, const wxString& delims, wxStringTokenizerMode mode) : wxStringTokenizer(str, delims, mode), _sig(NULL), _pObj(NULL) {}
	~wx_StringTokenizer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StringTokenizer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StringTokenizer::~wx_StringTokenizer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StringTokenizer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStringTokenizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(StringTokenizerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StringTokenizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringTokenizerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_StringTokenizer *pEntity = new wx_StringTokenizer();
	Object_wx_StringTokenizer *pObj = Object_wx_StringTokenizer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StringTokenizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(StringTokenizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StringTokenizer));
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "delims", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringTokenizer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString delims = wxT(" trn");
	if (args.IsValid(1)) delims = wxString::FromUTF8(args.GetString(1));
	wxStringTokenizerMode mode = wxTOKEN_DEFAULT;
	if (args.IsValid(2)) mode = static_cast<wxStringTokenizerMode>(args.GetInt(2));
	wx_StringTokenizer *pEntity = new wx_StringTokenizer(str, delims, mode);
	Object_wx_StringTokenizer *pObj = Object_wx_StringTokenizer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StringTokenizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_StringTokenizer, CountTokens)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, CountTokens)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->CountTokens();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StringTokenizer, HasMoreTokens)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, HasMoreTokens)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasMoreTokens();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StringTokenizer, GetLastDelimiter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, GetLastDelimiter)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxChar rtn = pThis->GetEntity()->GetLastDelimiter();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StringTokenizer, GetNextToken)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, GetNextToken)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetNextToken();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StringTokenizer, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, GetPosition)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StringTokenizer, GetString)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, GetString)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetString();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StringTokenizer, SetString)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "to_tokenize", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "delims", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, SetString)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString to_tokenize = wxString::FromUTF8(args.GetString(0));
	wxString delims = wxT(" trn");
	if (args.IsValid(1)) delims = wxString::FromUTF8(args.GetString(1));
	wxStringTokenizerMode mode = wxTOKEN_DEFAULT;
	if (args.IsValid(2)) mode = static_cast<wxStringTokenizerMode>(args.GetInt(2));
	pThis->GetEntity()->SetString(to_tokenize, delims, mode);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxStringTokenizer
//----------------------------------------------------------------------------
Object_wx_StringTokenizer::~Object_wx_StringTokenizer()
{
}

Object *Object_wx_StringTokenizer::Clone() const
{
	return NULL;
}

String Object_wx_StringTokenizer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StringTokenizer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StringTokenizer::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(StringTokenizerEmpty);
	Gura_AssignFunction(StringTokenizer);
}

//----------------------------------------------------------------------------
// Class implementation for wxStringTokenizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringTokenizer)
{
	Gura_AssignMethod(wx_StringTokenizer, CountTokens);
	Gura_AssignMethod(wx_StringTokenizer, HasMoreTokens);
	Gura_AssignMethod(wx_StringTokenizer, GetLastDelimiter);
	Gura_AssignMethod(wx_StringTokenizer, GetNextToken);
	Gura_AssignMethod(wx_StringTokenizer, GetPosition);
	Gura_AssignMethod(wx_StringTokenizer, GetString);
	Gura_AssignMethod(wx_StringTokenizer, SetString);
}

Gura_ImplementDescendantCreator(wx_StringTokenizer)
{
	return new Object_wx_StringTokenizer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
