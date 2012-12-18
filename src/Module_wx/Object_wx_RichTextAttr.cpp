//----------------------------------------------------------------------------
// wxRichTextAttr
// extracted from richtextattr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RichTextAttr: public wxRichTextAttr, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RichTextAttr *_pObj;
public:
	inline wx_RichTextAttr() : wxRichTextAttr(), _sig(NULL), _pObj(NULL) {}
	inline wx_RichTextAttr(const wxColour& colText, const wxColour& colBack, wxTextAttrAlignment alignment) : wxRichTextAttr(colText, colBack, alignment), _sig(NULL), _pObj(NULL) {}
	inline wx_RichTextAttr(const wxTextAttrEx& attr) : wxRichTextAttr(attr), _sig(NULL), _pObj(NULL) {}
	~wx_RichTextAttr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RichTextAttr *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RichTextAttr::~wx_RichTextAttr()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RichTextAttr::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(RichTextAttr)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextAttr)
{
	wx_RichTextAttr *pEntity = new wx_RichTextAttr();
	Object_wx_RichTextAttr *pObj = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(RichTextAttr_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextAttr));
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextAttr_2)
{
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBack = (wxColour *)(&wxNullColour);
	if (args.IsValid(1)) colBack = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxTextAttrAlignment alignment = wxTEXT_ALIGNMENT_DEFAULT;
	if (args.IsValid(2)) alignment = static_cast<wxTextAttrAlignment>(args.GetInt(2));
	wx_RichTextAttr *pEntity = new wx_RichTextAttr(*colText, *colBack, alignment);
	Object_wx_RichTextAttr *pObj = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(RichTextAttr_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_RichTextAttr));
	DeclareArg(env, "attr", VTYPE_wx_TextAttrEx, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RichTextAttr_1)
{
	wxTextAttrEx *attr = Object_wx_TextAttrEx::GetObject(args, 0)->GetEntity();
	wx_RichTextAttr *pEntity = new wx_RichTextAttr(*attr);
	Object_wx_RichTextAttr *pObj = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RichTextAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_RichTextAttr, Apply)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareArg(env, "compareWith", VTYPE_wx_RichTextAttr, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, Apply)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
	wxRichTextAttr *compareWith = (wxRichTextAttr *)(NULL);
	if (args.IsValid(1)) compareWith = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->Apply(*style, compareWith);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, Combine)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "style", VTYPE_wx_RichTextAttr, OCCUR_Once);
	DeclareArg(env, "compareWith", VTYPE_wx_RichTextAttr, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, Combine)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxRichTextAttr *style = Object_wx_RichTextAttr::GetObject(args, 0)->GetEntity();
	wxRichTextAttr *compareWith = (wxRichTextAttr *)(NULL);
	if (args.IsValid(1)) compareWith = Object_wx_RichTextAttr::GetObject(args, 1)->GetEntity();
	wxRichTextAttr rtn = pSelf->GetEntity()->Combine(*style, compareWith);
	return ReturnValue(env, sig, args, Value(new Object_wx_RichTextAttr(new wxRichTextAttr(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextAttr, CreateFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, CreateFont)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont rtn = pSelf->GetEntity()->CreateFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextAttr, GetAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetAlignment)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment rtn = pSelf->GetEntity()->GetAlignment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetBackgroundColour)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pSelf->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextAttr, GetBulletFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetBulletFont)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetBulletFont();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextAttr, GetBulletName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetBulletName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetBulletName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextAttr, GetBulletNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetBulletNumber)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetBulletNumber();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetBulletStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetBulletStyle)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetBulletStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetBulletText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetBulletText)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetBulletText();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextAttr, GetCharacterStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetCharacterStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetCharacterStyleName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextAttr, GetFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetFlags)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetFontAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetFontAttributes)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetFontAttributes(*font);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetFontFaceName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetFontFaceName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetFontFaceName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextAttr, GetFontSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetFontSize)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFontSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetFontStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetFontStyle)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFontStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetFontUnderlined)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetFontUnderlined)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetFontUnderlined();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetFontWeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetFontWeight)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetFontWeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetLeftIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetLeftIndent)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetLeftIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetLeftSubIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetLeftSubIndent)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetLeftSubIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetLineSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetLineSpacing)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetLineSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetListStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetListStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetListStyleName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextAttr, GetOutlineLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetOutlineLevel)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetOutlineLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetParagraphSpacingAfter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetParagraphSpacingAfter)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetParagraphSpacingAfter();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetParagraphSpacingBefore)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetParagraphSpacingBefore)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetParagraphSpacingBefore();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetParagraphStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetParagraphStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetParagraphStyleName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextAttr, GetRightIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetRightIndent)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetRightIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetTabs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetTabs)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxArrayInt rtn = pSelf->GetEntity()->GetTabs();
	return ReturnValue(env, sig, args, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetTextColour)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pSelf->GetEntity()->GetTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RichTextAttr, GetTextEffectFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetTextEffectFlags)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetTextEffectFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetTextEffects)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetTextEffects)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetTextEffects();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, GetURL)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, GetURL)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetURL();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_RichTextAttr, HasAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasAlignment)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasAlignment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasBackgroundColour)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasBulletName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasBulletName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasBulletName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasBulletNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasBulletNumber)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasBulletNumber();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasBulletStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasBulletStyle)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasBulletStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasBulletText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasBulletText)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasBulletText();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasCharacterStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasCharacterStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasCharacterStyleName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasFontFaceName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasFontFaceName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasFontFaceName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasFlag)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasFlag)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long flag = args.GetLong(0);
	bool rtn = pSelf->GetEntity()->HasFlag(flag);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasFont)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasFont();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasFontItalic)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasFontItalic)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasFontItalic();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasLeftIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasLeftIndent)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasLeftIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasLineSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasLineSpacing)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasLineSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasListStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasListStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasListStyleName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasOutlineLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasOutlineLevel)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasOutlineLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasPageBreak)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasPageBreak)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasPageBreak();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasParagraphSpacingAfter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasParagraphSpacingAfter)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasParagraphSpacingAfter();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasParagraphSpacingBefore)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasParagraphSpacingBefore)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasParagraphSpacingBefore();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasParagraphStyleName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasParagraphStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasParagraphStyleName();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasRightIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasRightIndent)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasRightIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasFontSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasFontSize)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasFontSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasTabs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasTabs)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasTabs();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasTextColour)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasTextColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasTextEffects)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasTextEffects)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasTextEffects();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasFontUnderlined)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasFontUnderlined)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasFontUnderlined();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasURL)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasURL)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasURL();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, HasFontWeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, HasFontWeight)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasFontWeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, IsCharacterStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, IsCharacterStyle)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsCharacterStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, IsDefault)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, IsDefault)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsDefault();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, IsParagraphStyle)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, IsParagraphStyle)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsParagraphStyle();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_RichTextAttr, SetAlignment)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetAlignment)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment alignment = static_cast<wxTextAttrAlignment>(args.GetInt(0));
	pSelf->GetEntity()->SetAlignment(alignment);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetBackgroundColour)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colBack = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBackgroundColour(*colBack);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetBulletFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetBulletFont)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString font = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetBulletFont(font);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetBulletName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetBulletName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetBulletName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetBulletNumber)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetBulletNumber)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pSelf->GetEntity()->SetBulletNumber(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetBulletStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetBulletStyle)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int style = args.GetInt(0);
	pSelf->GetEntity()->SetBulletStyle(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetBulletText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetBulletText)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetBulletText(text);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetCharacterStyleName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetCharacterStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetCharacterStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetFlags)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	pSelf->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetFontFaceName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "faceName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetFontFaceName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString faceName = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetFontFaceName(faceName);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetFontSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetFontSize)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pointSize = args.GetInt(0);
	pSelf->GetEntity()->SetFontSize(pointSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetFontStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fontStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetFontStyle)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int fontStyle = args.GetInt(0);
	pSelf->GetEntity()->SetFontStyle(fontStyle);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetFontUnderlined)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "underlined", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetFontUnderlined)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool underlined = args.GetBoolean(0);
	pSelf->GetEntity()->SetFontUnderlined(underlined);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetFontWeight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "fontWeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetFontWeight)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int fontWeight = args.GetInt(0);
	pSelf->GetEntity()->SetFontWeight(fontWeight);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetLeftIndent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "subIndent", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, SetLeftIndent)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	int subIndent = 0;
	if (args.IsValid(1)) subIndent = args.GetInt(1);
	pSelf->GetEntity()->SetLeftIndent(indent, subIndent);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetLineSpacing)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetLineSpacing)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pSelf->GetEntity()->SetLineSpacing(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetListStyleName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetListStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetListStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetOutlineLevel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetOutlineLevel)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	pSelf->GetEntity()->SetOutlineLevel(level);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetPageBreak)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageBreak", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, SetPageBreak)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool pageBreak = true;
	if (args.IsValid(0)) pageBreak = args.GetBoolean(0);
	pSelf->GetEntity()->SetPageBreak(pageBreak);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetParagraphSpacingAfter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetParagraphSpacingAfter)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pSelf->GetEntity()->SetParagraphSpacingAfter(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetParagraphSpacingBefore)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetParagraphSpacingBefore)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int spacing = args.GetInt(0);
	pSelf->GetEntity()->SetParagraphSpacingBefore(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetParagraphStyleName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetParagraphStyleName)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetParagraphStyleName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetRightIndent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetRightIndent)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	pSelf->GetEntity()->SetRightIndent(indent);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetTabs)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tabs", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_RichTextAttr, SetTabs)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayInt> tabs(CreateArrayInt(args.GetList(0)));
	pSelf->GetEntity()->SetTabs(*tabs);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetTextColour)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetTextColour(*colText);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetTextEffectFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetTextEffectFlags)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int flags = args.GetInt(0);
	pSelf->GetEntity()->SetTextEffectFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetTextEffects)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "effects", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetTextEffects)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int effects = args.GetInt(0);
	pSelf->GetEntity()->SetTextEffects(effects);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, SetURL)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAttr, SetURL)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetURL(url);
	return Value::Null;
}

Gura_DeclareMethod(wx_RichTextAttr, wxTextAttrEx)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RichTextAttr, wxTextAttrEx)
{
	Object_wx_RichTextAttr *pSelf = Object_wx_RichTextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRichTextAttr
//----------------------------------------------------------------------------
Object_wx_RichTextAttr::~Object_wx_RichTextAttr()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_RichTextAttr::Clone() const
{
	return NULL;
}

String Object_wx_RichTextAttr::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RichTextAttr:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RichTextAttr::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RichTextAttr);
	Gura_AssignFunction(RichTextAttr_2);
	Gura_AssignFunction(RichTextAttr_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextAttr)
{
	Gura_AssignMethod(wx_RichTextAttr, Apply);
	Gura_AssignMethod(wx_RichTextAttr, Combine);
	Gura_AssignMethod(wx_RichTextAttr, CreateFont);
	Gura_AssignMethod(wx_RichTextAttr, GetAlignment);
	Gura_AssignMethod(wx_RichTextAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_RichTextAttr, GetBulletFont);
	Gura_AssignMethod(wx_RichTextAttr, GetBulletName);
	Gura_AssignMethod(wx_RichTextAttr, GetBulletNumber);
	Gura_AssignMethod(wx_RichTextAttr, GetBulletStyle);
	Gura_AssignMethod(wx_RichTextAttr, GetBulletText);
	Gura_AssignMethod(wx_RichTextAttr, GetCharacterStyleName);
	Gura_AssignMethod(wx_RichTextAttr, GetFlags);
	Gura_AssignMethod(wx_RichTextAttr, GetFontAttributes);
	Gura_AssignMethod(wx_RichTextAttr, GetFontFaceName);
	Gura_AssignMethod(wx_RichTextAttr, GetFontSize);
	Gura_AssignMethod(wx_RichTextAttr, GetFontStyle);
	Gura_AssignMethod(wx_RichTextAttr, GetFontUnderlined);
	Gura_AssignMethod(wx_RichTextAttr, GetFontWeight);
	Gura_AssignMethod(wx_RichTextAttr, GetLeftIndent);
	Gura_AssignMethod(wx_RichTextAttr, GetLeftSubIndent);
	Gura_AssignMethod(wx_RichTextAttr, GetLineSpacing);
	Gura_AssignMethod(wx_RichTextAttr, GetListStyleName);
	Gura_AssignMethod(wx_RichTextAttr, GetOutlineLevel);
	Gura_AssignMethod(wx_RichTextAttr, GetParagraphSpacingAfter);
	Gura_AssignMethod(wx_RichTextAttr, GetParagraphSpacingBefore);
	Gura_AssignMethod(wx_RichTextAttr, GetParagraphStyleName);
	Gura_AssignMethod(wx_RichTextAttr, GetRightIndent);
	Gura_AssignMethod(wx_RichTextAttr, GetTabs);
	Gura_AssignMethod(wx_RichTextAttr, GetTextColour);
	Gura_AssignMethod(wx_RichTextAttr, GetTextEffectFlags);
	Gura_AssignMethod(wx_RichTextAttr, GetTextEffects);
	Gura_AssignMethod(wx_RichTextAttr, GetURL);
	Gura_AssignMethod(wx_RichTextAttr, HasAlignment);
	Gura_AssignMethod(wx_RichTextAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_RichTextAttr, HasBulletName);
	Gura_AssignMethod(wx_RichTextAttr, HasBulletNumber);
	Gura_AssignMethod(wx_RichTextAttr, HasBulletStyle);
	Gura_AssignMethod(wx_RichTextAttr, HasBulletText);
	Gura_AssignMethod(wx_RichTextAttr, HasCharacterStyleName);
	Gura_AssignMethod(wx_RichTextAttr, HasFontFaceName);
	Gura_AssignMethod(wx_RichTextAttr, HasFlag);
	Gura_AssignMethod(wx_RichTextAttr, HasFont);
	Gura_AssignMethod(wx_RichTextAttr, HasFontItalic);
	Gura_AssignMethod(wx_RichTextAttr, HasLeftIndent);
	Gura_AssignMethod(wx_RichTextAttr, HasLineSpacing);
	Gura_AssignMethod(wx_RichTextAttr, HasListStyleName);
	Gura_AssignMethod(wx_RichTextAttr, HasOutlineLevel);
	Gura_AssignMethod(wx_RichTextAttr, HasPageBreak);
	Gura_AssignMethod(wx_RichTextAttr, HasParagraphSpacingAfter);
	Gura_AssignMethod(wx_RichTextAttr, HasParagraphSpacingBefore);
	Gura_AssignMethod(wx_RichTextAttr, HasParagraphStyleName);
	Gura_AssignMethod(wx_RichTextAttr, HasRightIndent);
	Gura_AssignMethod(wx_RichTextAttr, HasFontSize);
	Gura_AssignMethod(wx_RichTextAttr, HasTabs);
	Gura_AssignMethod(wx_RichTextAttr, HasTextColour);
	Gura_AssignMethod(wx_RichTextAttr, HasTextEffects);
	Gura_AssignMethod(wx_RichTextAttr, HasFontUnderlined);
	Gura_AssignMethod(wx_RichTextAttr, HasURL);
	Gura_AssignMethod(wx_RichTextAttr, HasFontWeight);
	Gura_AssignMethod(wx_RichTextAttr, IsCharacterStyle);
	Gura_AssignMethod(wx_RichTextAttr, IsDefault);
	Gura_AssignMethod(wx_RichTextAttr, IsParagraphStyle);
	Gura_AssignMethod(wx_RichTextAttr, SetAlignment);
	Gura_AssignMethod(wx_RichTextAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_RichTextAttr, SetBulletFont);
	Gura_AssignMethod(wx_RichTextAttr, SetBulletName);
	Gura_AssignMethod(wx_RichTextAttr, SetBulletNumber);
	Gura_AssignMethod(wx_RichTextAttr, SetBulletStyle);
	Gura_AssignMethod(wx_RichTextAttr, SetBulletText);
	Gura_AssignMethod(wx_RichTextAttr, SetCharacterStyleName);
	Gura_AssignMethod(wx_RichTextAttr, SetFlags);
	Gura_AssignMethod(wx_RichTextAttr, SetFontFaceName);
	Gura_AssignMethod(wx_RichTextAttr, SetFontSize);
	Gura_AssignMethod(wx_RichTextAttr, SetFontStyle);
	Gura_AssignMethod(wx_RichTextAttr, SetFontUnderlined);
	Gura_AssignMethod(wx_RichTextAttr, SetFontWeight);
	Gura_AssignMethod(wx_RichTextAttr, SetLeftIndent);
	Gura_AssignMethod(wx_RichTextAttr, SetLineSpacing);
	Gura_AssignMethod(wx_RichTextAttr, SetListStyleName);
	Gura_AssignMethod(wx_RichTextAttr, SetOutlineLevel);
	Gura_AssignMethod(wx_RichTextAttr, SetPageBreak);
	Gura_AssignMethod(wx_RichTextAttr, SetParagraphSpacingAfter);
	Gura_AssignMethod(wx_RichTextAttr, SetParagraphSpacingBefore);
	Gura_AssignMethod(wx_RichTextAttr, SetParagraphStyleName);
	Gura_AssignMethod(wx_RichTextAttr, SetRightIndent);
	Gura_AssignMethod(wx_RichTextAttr, SetTabs);
	Gura_AssignMethod(wx_RichTextAttr, SetTextColour);
	Gura_AssignMethod(wx_RichTextAttr, SetTextEffectFlags);
	Gura_AssignMethod(wx_RichTextAttr, SetTextEffects);
	Gura_AssignMethod(wx_RichTextAttr, SetURL);
	Gura_AssignMethod(wx_RichTextAttr, wxTextAttrEx);
}

Gura_ImplementDescendantCreator(wx_RichTextAttr)
{
	return new Object_wx_RichTextAttr((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
