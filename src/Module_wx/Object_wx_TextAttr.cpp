//----------------------------------------------------------------------------
// wxTextAttr
// extracted from textattr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextAttr: public wxTextAttr, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TextAttr *_pObj;
public:
	inline wx_TextAttr() : wxTextAttr(), _sig(NULL), _pObj(NULL) {}
	inline wx_TextAttr(const wxColour& colText, const wxColour& colBack, const wxFont& font, wxTextAttrAlignment alignment) : wxTextAttr(colText, colBack, font, alignment), _sig(NULL), _pObj(NULL) {}
	~wx_TextAttr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextAttr *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextAttr::~wx_TextAttr()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TextAttr::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextAttr)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextAttr)
{
	wx_TextAttr *pEntity = new wx_TextAttr();
	Object_wx_TextAttr *pObj = Object_wx_TextAttr::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TextAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(TextAttr_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextAttr));
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextAttr_1)
{
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBack = (wxColour *)(&wxNullColour);
	if (args.IsValid(1)) colBack = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxFont *font = (wxFont *)(&wxNullFont);
	if (args.IsValid(2)) font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	wxTextAttrAlignment alignment = wxTEXT_ALIGNMENT_DEFAULT;
	if (args.IsValid(3)) alignment = static_cast<wxTextAttrAlignment>(args.GetInt(3));
	wx_TextAttr *pEntity = new wx_TextAttr(*colText, *colBack, *font, alignment);
	Object_wx_TextAttr *pObj = Object_wx_TextAttr::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TextAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_TextAttr, GetAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetAlignment)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment rtn = pSelf->GetEntity()->GetAlignment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetBackgroundColour)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pSelf->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextAttr, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetFont)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxFont &rtn = pSelf->GetEntity()->GetFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextAttr, GetLeftIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetLeftIndent)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetLeftIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetLeftSubIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetLeftSubIndent)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetLeftSubIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetRightIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetRightIndent)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetRightIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetTabs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetTabs)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxArrayInt rtn = pSelf->GetEntity()->GetTabs();
	return ReturnValue(env, sig, args, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetTextColour)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pSelf->GetEntity()->GetTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextAttr, HasAlignment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasAlignment)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasAlignment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasBackgroundColour)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasFont)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasFont();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasLeftIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasLeftIndent)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasLeftIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasRightIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasRightIndent)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasRightIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasTabs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasTabs)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasTabs();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasTextColour)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasTextColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetFlags)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, IsDefault)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, IsDefault)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsDefault();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, Merge)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "overlay", VTYPE_wx_TextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, Merge)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttr *overlay = Object_wx_TextAttr::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->Merge(*overlay);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TextAttr, Merge_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareArg(env, "overlay", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TextAttr, Merge_1)
{
	wxTextAttr *base = Object_wx_TextAttr::GetObject(args, 0)->GetEntity();
	wxTextAttr *overlay = Object_wx_TextAttr::GetObject(args, 1)->GetEntity();
	wxTextAttr rtn = wxTextAttr::Merge(*base, *overlay);
	return ReturnValue(env, sig, args, Value(new Object_wx_TextAttr(new wxTextAttr(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextAttr, SetAlignment)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetAlignment)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment alignment = static_cast<wxTextAttrAlignment>(args.GetInt(0));
	pSelf->GetEntity()->SetAlignment(alignment);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetBackgroundColour)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetBackgroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFlags)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	pSelf->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFont)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetLeftIndent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "subIndent", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, SetLeftIndent)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	int subIndent = 0;
	if (args.IsValid(1)) subIndent = args.GetInt(1);
	pSelf->GetEntity()->SetLeftIndent(indent, subIndent);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetRightIndent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetRightIndent)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	pSelf->GetEntity()->SetRightIndent(indent);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetTabs)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tabs", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_TextAttr, SetTabs)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayInt> tabs(CreateArrayInt(args.GetList(0)));
	pSelf->GetEntity()->SetTabs(*tabs);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetTextColour)
{
	Object_wx_TextAttr *pSelf = Object_wx_TextAttr::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetTextColour(*colour);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTextAttr
//----------------------------------------------------------------------------
Object_wx_TextAttr::~Object_wx_TextAttr()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TextAttr::Clone() const
{
	return NULL;
}

String Object_wx_TextAttr::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TextAttr:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TextAttr::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(TextAttr);
	Gura_AssignFunction(TextAttr_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttr)
{
	Gura_AssignMethod(wx_TextAttr, GetAlignment);
	Gura_AssignMethod(wx_TextAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, GetFont);
	Gura_AssignMethod(wx_TextAttr, GetLeftIndent);
	Gura_AssignMethod(wx_TextAttr, GetLeftSubIndent);
	Gura_AssignMethod(wx_TextAttr, GetRightIndent);
	Gura_AssignMethod(wx_TextAttr, GetTabs);
	Gura_AssignMethod(wx_TextAttr, GetTextColour);
	Gura_AssignMethod(wx_TextAttr, HasAlignment);
	Gura_AssignMethod(wx_TextAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, HasFont);
	Gura_AssignMethod(wx_TextAttr, HasLeftIndent);
	Gura_AssignMethod(wx_TextAttr, HasRightIndent);
	Gura_AssignMethod(wx_TextAttr, HasTabs);
	Gura_AssignMethod(wx_TextAttr, HasTextColour);
	Gura_AssignMethod(wx_TextAttr, GetFlags);
	Gura_AssignMethod(wx_TextAttr, IsDefault);
	Gura_AssignMethod(wx_TextAttr, Merge);
	Gura_AssignMethod(wx_TextAttr, Merge_1);
	Gura_AssignMethod(wx_TextAttr, SetAlignment);
	Gura_AssignMethod(wx_TextAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, SetFlags);
	Gura_AssignMethod(wx_TextAttr, SetFont);
	Gura_AssignMethod(wx_TextAttr, SetLeftIndent);
	Gura_AssignMethod(wx_TextAttr, SetRightIndent);
	Gura_AssignMethod(wx_TextAttr, SetTabs);
	Gura_AssignMethod(wx_TextAttr, SetTextColour);
}

Gura_ImplementDescendantCreator(wx_TextAttr)
{
	return new Object_wx_TextAttr((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
