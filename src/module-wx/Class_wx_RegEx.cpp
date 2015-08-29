//----------------------------------------------------------------------------
// wxRegEx
// extracted from regex.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RegEx: public wxRegEx, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RegEx *_pObj;
public:
	inline wx_RegEx() : wxRegEx(), _pObj(nullptr) {}
	inline wx_RegEx(const wxString& expr, int flags) : wxRegEx(expr, flags), _pObj(nullptr) {}
	~wx_RegEx();
	inline void AssocWithGura(Object_wx_RegEx *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RegEx::~wx_RegEx()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RegEx::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRegEx
//----------------------------------------------------------------------------
Gura_DeclareFunction(RegExEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RegEx));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegExEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_RegEx *pEntity = new wx_RegEx();
	Object_wx_RegEx *pObj = Object_wx_RegEx::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RegEx(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(RegEx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RegEx));
	DeclareArg(env, "expr", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegEx)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString expr = wxString::FromUTF8(arg.GetString(0));
	int flags = wxRE_DEFAULT;
	if (arg.IsValid(1)) flags = arg.GetInt(1);
	wx_RegEx *pEntity = new wx_RegEx(expr, flags);
	Object_wx_RegEx *pObj = Object_wx_RegEx::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_RegEx(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_RegEx, Compile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pattern", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, Compile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString pattern = wxString::FromUTF8(arg.GetString(0));
	int flags = wxRE_DEFAULT;
	if (arg.IsValid(1)) flags = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->Compile(pattern, flags);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RegEx, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, IsValid)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsValid();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RegEx, GetMatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, GetMatch)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t start = arg.GetSizeT(0);
	size_t len = arg.GetSizeT(1);
	size_t index = 0;
	if (arg.IsValid(2)) index = arg.GetSizeT(2);
	bool rtn = pThis->GetEntity()->GetMatch(start, len, index);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, GetMatch_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, GetMatch_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	size_t index = 0;
	if (arg.IsValid(1)) index = arg.GetSizeT(1);
	wxString rtn = pThis->GetEntity()->GetMatch(text, index);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RegEx, GetMatchCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, GetMatchCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetMatchCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RegEx, Matches)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, Matches)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	int flags = 0;
	if (arg.IsValid(1)) flags = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->Matches(text, flags);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RegEx, Matches_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, Matches_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	int flags = arg.GetInt(1);
	size_t len = arg.GetSizeT(2);
	bool rtn = pThis->GetEntity()->Matches(text, flags, len);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RegEx, Matches_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, Matches_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	int flags = 0;
	if (arg.IsValid(1)) flags = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->Matches(text, flags);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_RegEx, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "replacement", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "maxMatches", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, Replace)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	wxString replacement = wxString::FromUTF8(arg.GetString(1));
	size_t maxMatches = 0;
	if (arg.IsValid(2)) maxMatches = arg.GetSizeT(2);
	int rtn = pThis->GetEntity()->Replace(text, replacement, maxMatches);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, ReplaceAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "replacement", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, ReplaceAll)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	wxString replacement = wxString::FromUTF8(arg.GetString(1));
	int rtn = pThis->GetEntity()->ReplaceAll(text, replacement);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, ReplaceFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "replacement", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RegEx, ReplaceFirst)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	wxString replacement = wxString::FromUTF8(arg.GetString(1));
	int rtn = pThis->GetEntity()->ReplaceFirst(text, replacement);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxRegEx
//----------------------------------------------------------------------------
Object_wx_RegEx::~Object_wx_RegEx()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RegEx::Clone() const
{
	return nullptr;
}

String Object_wx_RegEx::ToString(bool exprFlag)
{
	String rtn("<wx.RegEx:");
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
// Class implementation for wxRegEx
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegEx)
{
	Gura_AssignFunction(RegExEmpty);
	Gura_AssignFunction(RegEx);
	Gura_AssignMethod(wx_RegEx, Compile);
	Gura_AssignMethod(wx_RegEx, IsValid);
	Gura_AssignMethod(wx_RegEx, GetMatch);
	Gura_AssignMethod(wx_RegEx, GetMatch_1);
	Gura_AssignMethod(wx_RegEx, GetMatchCount);
	Gura_AssignMethod(wx_RegEx, Matches);
	Gura_AssignMethod(wx_RegEx, Matches_1);
	Gura_AssignMethod(wx_RegEx, Matches_2);
	Gura_AssignMethod(wx_RegEx, Replace);
	Gura_AssignMethod(wx_RegEx, ReplaceAll);
	Gura_AssignMethod(wx_RegEx, ReplaceFirst);
}

Gura_ImplementDescendantCreator(wx_RegEx)
{
	return new Object_wx_RegEx((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
