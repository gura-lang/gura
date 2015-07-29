//----------------------------------------------------------------------------
// wxTextAttrEx
// extracted from textattrex.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextAttrEx: public wxTextAttrEx, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TextAttrEx *_pObj;
public:
	inline wx_TextAttrEx() : wxTextAttrEx(), _pObj(nullptr) {}
	inline wx_TextAttrEx(const wxTextAttrEx& attr) : wxTextAttrEx(attr), _pObj(nullptr) {}
	~wx_TextAttrEx();
	inline void AssocWithGura(Object_wx_TextAttrEx *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextAttrEx::~wx_TextAttrEx()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextAttrEx::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrEx
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextAttrEx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextAttrEx));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextAttrEx)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TextAttrEx *pEntity = new wx_TextAttrEx();
	Object_wx_TextAttrEx *pObj = Object_wx_TextAttrEx::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextAttrEx(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetBulletFont();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetBulletName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletNumber)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBulletNumber();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBulletStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetBulletText();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetCharacterStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetCharacterStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetCharacterStyleName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetLineSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLineSpacing();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetListStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetListStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetListStyleName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetOutlineLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetOutlineLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOutlineLevel();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetParagraphSpacingAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetParagraphSpacingAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetParagraphSpacingAfter();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetParagraphSpacingBefore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetParagraphSpacingBefore)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetParagraphSpacingBefore();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetParagraphStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetParagraphStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetParagraphStyleName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetTextEffectFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetTextEffectFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTextEffectFlags();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetTextEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetTextEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTextEffects();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetURL();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, HasBulletName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasBulletName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBulletName();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasBulletNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasBulletNumber)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBulletNumber();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasBulletStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasBulletStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBulletStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasBulletText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasBulletText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBulletText();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasCharacterStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasCharacterStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasCharacterStyleName();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasLineSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasLineSpacing();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasListStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasListStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasListStyleName();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasOutlineLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasOutlineLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasOutlineLevel();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasPageBreak)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasPageBreak)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasPageBreak();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasParagraphSpacingAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasParagraphSpacingAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasParagraphSpacingAfter();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasParagraphSpacingBefore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasParagraphSpacingBefore)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasParagraphSpacingBefore();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasParagraphStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasParagraphStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasParagraphStyleName();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasTextEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasTextEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTextEffects();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasURL();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrEx, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Init();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, IsCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, IsCharacterStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsCharacterStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, IsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, IsDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDefault();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, IsParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, IsParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsParagraphStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString font = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetBulletFont(font);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletNumber)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetBulletNumber(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetBulletName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int style = args.GetInt(0);
	pThis->GetEntity()->SetBulletStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetBulletText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetCharacterStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetCharacterStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetCharacterStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetLineSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pThis->GetEntity()->SetLineSpacing(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetListStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetListStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetListStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetOutlineLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetOutlineLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	pThis->GetEntity()->SetOutlineLevel(level);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetPageBreak)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageBreak", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, SetPageBreak)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool pageBreak = true;
	if (args.IsValid(0)) pageBreak = args.GetBoolean(0);
	pThis->GetEntity()->SetPageBreak(pageBreak);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetParagraphSpacingAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetParagraphSpacingAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pThis->GetEntity()->SetParagraphSpacingAfter(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetParagraphSpacingBefore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetParagraphSpacingBefore)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pThis->GetEntity()->SetParagraphSpacingBefore(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetParagraphStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetParagraphStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParagraphStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetTextEffectFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetTextEffectFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pThis->GetEntity()->SetTextEffectFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetTextEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "effects", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetTextEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int effects = args.GetInt(0);
	pThis->GetEntity()->SetTextEffects(effects);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetURL(url);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrEx
//----------------------------------------------------------------------------
Object_wx_TextAttrEx::~Object_wx_TextAttrEx()
{
}

Object *Object_wx_TextAttrEx::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrEx::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrEx:");
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
// Class implementation for wxTextAttrEx
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrEx)
{
	Gura_AssignFunction(TextAttrEx);
	Gura_AssignMethod(wx_TextAttrEx, GetBulletFont);
	Gura_AssignMethod(wx_TextAttrEx, GetBulletName);
	Gura_AssignMethod(wx_TextAttrEx, GetBulletNumber);
	Gura_AssignMethod(wx_TextAttrEx, GetBulletStyle);
	Gura_AssignMethod(wx_TextAttrEx, GetBulletText);
	Gura_AssignMethod(wx_TextAttrEx, GetCharacterStyleName);
	Gura_AssignMethod(wx_TextAttrEx, GetLineSpacing);
	Gura_AssignMethod(wx_TextAttrEx, GetListStyleName);
	Gura_AssignMethod(wx_TextAttrEx, GetOutlineLevel);
	Gura_AssignMethod(wx_TextAttrEx, GetParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttrEx, GetParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttrEx, GetParagraphStyleName);
	Gura_AssignMethod(wx_TextAttrEx, GetTextEffectFlags);
	Gura_AssignMethod(wx_TextAttrEx, GetTextEffects);
	Gura_AssignMethod(wx_TextAttrEx, GetURL);
	Gura_AssignMethod(wx_TextAttrEx, HasBulletName);
	Gura_AssignMethod(wx_TextAttrEx, HasBulletNumber);
	Gura_AssignMethod(wx_TextAttrEx, HasBulletStyle);
	Gura_AssignMethod(wx_TextAttrEx, HasBulletText);
	Gura_AssignMethod(wx_TextAttrEx, HasCharacterStyleName);
	Gura_AssignMethod(wx_TextAttrEx, HasLineSpacing);
	Gura_AssignMethod(wx_TextAttrEx, HasListStyleName);
	Gura_AssignMethod(wx_TextAttrEx, HasOutlineLevel);
	Gura_AssignMethod(wx_TextAttrEx, HasPageBreak);
	Gura_AssignMethod(wx_TextAttrEx, HasParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttrEx, HasParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttrEx, HasParagraphStyleName);
	Gura_AssignMethod(wx_TextAttrEx, HasTextEffects);
	Gura_AssignMethod(wx_TextAttrEx, HasURL);
	Gura_AssignMethod(wx_TextAttrEx, Init);
	Gura_AssignMethod(wx_TextAttrEx, IsCharacterStyle);
	Gura_AssignMethod(wx_TextAttrEx, IsDefault);
	Gura_AssignMethod(wx_TextAttrEx, IsParagraphStyle);
	Gura_AssignMethod(wx_TextAttrEx, SetBulletFont);
	Gura_AssignMethod(wx_TextAttrEx, SetBulletNumber);
	Gura_AssignMethod(wx_TextAttrEx, SetBulletName);
	Gura_AssignMethod(wx_TextAttrEx, SetBulletStyle);
	Gura_AssignMethod(wx_TextAttrEx, SetBulletText);
	Gura_AssignMethod(wx_TextAttrEx, SetCharacterStyleName);
	Gura_AssignMethod(wx_TextAttrEx, SetLineSpacing);
	Gura_AssignMethod(wx_TextAttrEx, SetListStyleName);
	Gura_AssignMethod(wx_TextAttrEx, SetOutlineLevel);
	Gura_AssignMethod(wx_TextAttrEx, SetPageBreak);
	Gura_AssignMethod(wx_TextAttrEx, SetParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttrEx, SetParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttrEx, SetParagraphStyleName);
	Gura_AssignMethod(wx_TextAttrEx, SetTextEffectFlags);
	Gura_AssignMethod(wx_TextAttrEx, SetTextEffects);
	Gura_AssignMethod(wx_TextAttrEx, SetURL);
}

Gura_ImplementDescendantCreator(wx_TextAttrEx)
{
	return new Object_wx_TextAttrEx((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
