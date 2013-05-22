//----------------------------------------------------------------------------
// wxTextAttrEx
// extracted from textattrex.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextAttrEx: public wxTextAttrEx, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TextAttrEx *_pObj;
public:
	inline wx_TextAttrEx() : wxTextAttrEx(), _sig(NULL), _pObj(NULL) {}
	inline wx_TextAttrEx(const wxTextAttrEx& attr) : wxTextAttrEx(attr), _sig(NULL), _pObj(NULL) {}
	~wx_TextAttrEx();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextAttrEx *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextAttrEx::~wx_TextAttrEx()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TextAttrEx::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrEx
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextAttrEx)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextAttrEx));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextAttrEx)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TextAttrEx *pEntity = new wx_TextAttrEx();
	Object_wx_TextAttrEx *pObj = Object_wx_TextAttrEx::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TextAttrEx(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletFont)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetBulletFont();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetBulletName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletNumber)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBulletNumber();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletStyle)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBulletStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetBulletText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetBulletText)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetBulletText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetCharacterStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetCharacterStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetCharacterStyleName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetLineSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetLineSpacing)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLineSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetListStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetListStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetListStyleName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetOutlineLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetOutlineLevel)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOutlineLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetParagraphSpacingAfter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetParagraphSpacingAfter)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetParagraphSpacingAfter();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetParagraphSpacingBefore)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetParagraphSpacingBefore)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetParagraphSpacingBefore();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetParagraphStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetParagraphStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetParagraphStyleName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, GetTextEffectFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetTextEffectFlags)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTextEffectFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetTextEffects)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetTextEffects)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTextEffects();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, GetURL)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, GetURL)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetURL();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TextAttrEx, HasBulletName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasBulletName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBulletName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasBulletNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasBulletNumber)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBulletNumber();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasBulletStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasBulletStyle)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBulletStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasBulletText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasBulletText)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBulletText();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasCharacterStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasCharacterStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasCharacterStyleName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasLineSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasLineSpacing)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasLineSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasListStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasListStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasListStyleName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasOutlineLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasOutlineLevel)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasOutlineLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasPageBreak)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasPageBreak)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasPageBreak();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasParagraphSpacingAfter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasParagraphSpacingAfter)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasParagraphSpacingAfter();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasParagraphSpacingBefore)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasParagraphSpacingBefore)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasParagraphSpacingBefore();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasParagraphStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasParagraphStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasParagraphStyleName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasTextEffects)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasTextEffects)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTextEffects();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, HasURL)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, HasURL)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasURL();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, Init)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrEx, Init)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Init();
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, IsCharacterStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, IsCharacterStyle)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsCharacterStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, IsDefault)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, IsDefault)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDefault();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, IsParagraphStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, IsParagraphStyle)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsParagraphStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletFont)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString font = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetBulletFont(font);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletNumber)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletNumber)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetBulletNumber(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetBulletName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletStyle)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int style = args.GetInt(0);
	pThis->GetEntity()->SetBulletStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetBulletText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetBulletText)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetBulletText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetCharacterStyleName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetCharacterStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetCharacterStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetLineSpacing)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetLineSpacing)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pThis->GetEntity()->SetLineSpacing(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetListStyleName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetListStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetListStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetOutlineLevel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetOutlineLevel)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	pThis->GetEntity()->SetOutlineLevel(level);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetPageBreak)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageBreak", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttrEx, SetPageBreak)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool pageBreak = true;
	if (args.IsValid(0)) pageBreak = args.GetBoolean(0);
	pThis->GetEntity()->SetPageBreak(pageBreak);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetParagraphSpacingAfter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetParagraphSpacingAfter)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pThis->GetEntity()->SetParagraphSpacingAfter(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetParagraphSpacingBefore)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetParagraphSpacingBefore)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pThis->GetEntity()->SetParagraphSpacingBefore(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetParagraphStyleName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetParagraphStyleName)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetParagraphStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetTextEffectFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetTextEffectFlags)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pThis->GetEntity()->SetTextEffectFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetTextEffects)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "effects", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetTextEffects)
{
	Object_wx_TextAttrEx *pThis = Object_wx_TextAttrEx::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int effects = args.GetInt(0);
	pThis->GetEntity()->SetTextEffects(effects);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttrEx, SetURL)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrEx, SetURL)
{
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
	return NULL;
}

String Object_wx_TextAttrEx::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TextAttrEx:");
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
	return new Object_wx_TextAttrEx((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
