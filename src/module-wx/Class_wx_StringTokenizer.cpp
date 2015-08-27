//----------------------------------------------------------------------------
// wxStringTokenizer
// extracted from tokenizr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StringTokenizer: public wxStringTokenizer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StringTokenizer *_pObj;
public:
	inline wx_StringTokenizer() : wxStringTokenizer(), _pObj(nullptr) {}
	inline wx_StringTokenizer(const wxString& str, const wxString& delims, wxStringTokenizerMode mode) : wxStringTokenizer(str, delims, mode), _pObj(nullptr) {}
	~wx_StringTokenizer();
	inline void AssocWithGura(Object_wx_StringTokenizer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StringTokenizer::~wx_StringTokenizer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StringTokenizer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStringTokenizer
//----------------------------------------------------------------------------
Gura_DeclareFunction(StringTokenizerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StringTokenizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringTokenizerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_StringTokenizer *pEntity = new wx_StringTokenizer();
	Object_wx_StringTokenizer *pObj = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StringTokenizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(StringTokenizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StringTokenizer));
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "delims", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StringTokenizer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxString delims = wxT(" trn");
	if (args.IsValid(1)) delims = wxString::FromUTF8(args.GetString(1));
	wxStringTokenizerMode mode = wxTOKEN_DEFAULT;
	if (args.IsValid(2)) mode = static_cast<wxStringTokenizerMode>(args.GetInt(2));
	wx_StringTokenizer *pEntity = new wx_StringTokenizer(str, delims, mode);
	Object_wx_StringTokenizer *pObj = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StringTokenizer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_StringTokenizer, CountTokens)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, CountTokens)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->CountTokens();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StringTokenizer, HasMoreTokens)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, HasMoreTokens)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasMoreTokens();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StringTokenizer, GetLastDelimiter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, GetLastDelimiter)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetLastDelimiter();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StringTokenizer, GetNextToken)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, GetNextToken)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetNextToken();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StringTokenizer, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_StringTokenizer, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, GetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetString();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StringTokenizer, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "to_tokenize", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "delims", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StringTokenizer, SetString)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString to_tokenize = wxString::FromUTF8(args.GetString(0));
	wxString delims = wxT(" trn");
	if (args.IsValid(1)) delims = wxString::FromUTF8(args.GetString(1));
	wxStringTokenizerMode mode = wxTOKEN_DEFAULT;
	if (args.IsValid(2)) mode = static_cast<wxStringTokenizerMode>(args.GetInt(2));
	pThis->GetEntity()->SetString(to_tokenize, delims, mode);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxStringTokenizer
//----------------------------------------------------------------------------
Object_wx_StringTokenizer::~Object_wx_StringTokenizer()
{
}

Object *Object_wx_StringTokenizer::Clone() const
{
	return nullptr;
}

String Object_wx_StringTokenizer::ToString(bool exprFlag)
{
	String rtn("<wx.StringTokenizer:");
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
// Class implementation for wxStringTokenizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringTokenizer)
{
	Gura_AssignFunction(StringTokenizerEmpty);
	Gura_AssignFunction(StringTokenizer);
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
	return new Object_wx_StringTokenizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
