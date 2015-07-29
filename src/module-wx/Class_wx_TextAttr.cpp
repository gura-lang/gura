//----------------------------------------------------------------------------
// wxTextAttr
// extracted from textattr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextAttr: public wxTextAttr, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TextAttr *_pObj;
public:
	inline wx_TextAttr() : wxTextAttr(), _pObj(nullptr) {}
	inline wx_TextAttr(const wxColour& colText, const wxColour& colBack, const wxFont& font, wxTextAttrAlignment alignment) : wxTextAttr(colText, colBack, font, alignment), _pObj(nullptr) {}
	~wx_TextAttr();
	inline void AssocWithGura(Object_wx_TextAttr *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextAttr::~wx_TextAttr()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextAttr::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(TextAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextAttr)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TextAttr *pEntity = new wx_TextAttr();
	Object_wx_TextAttr *pObj = Object_wx_TextAttr::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(TextAttr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TextAttr));
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TextAttr_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBack = (wxColour *)(&wxNullColour);
	if (args.IsValid(1)) colBack = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxFont *font = (wxFont *)(&wxNullFont);
	if (args.IsValid(2)) font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	wxTextAttrAlignment alignment = wxTEXT_ALIGNMENT_DEFAULT;
	if (args.IsValid(3)) alignment = static_cast<wxTextAttrAlignment>(args.GetInt(3));
	wx_TextAttr *pEntity = new wx_TextAttr(*colText, *colBack, *font, alignment);
	Object_wx_TextAttr *pObj = Object_wx_TextAttr::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TextAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_TextAttr, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment rtn = pThis->GetEntity()->GetAlignment();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextAttr, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextAttr, GetLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetLeftIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLeftIndent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetLeftSubIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetLeftSubIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLeftSubIndent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetRightIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRightIndent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetTabs)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArrayInt rtn = pThis->GetEntity()->GetTabs();
	return ReturnValue(env, args, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextAttr, HasAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasAlignment();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasFont();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasLeftIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasLeftIndent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasRightIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasRightIndent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasTabs)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTabs();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, HasTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, HasTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTextColour();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, IsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, IsDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDefault();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TextAttr, Merge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "overlay", VTYPE_wx_TextAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, Merge)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextAttr *overlay = Object_wx_TextAttr::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Merge(*overlay);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TextAttr, Merge_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareArg(env, "overlay", VTYPE_wx_TextAttr, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TextAttr, Merge_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxTextAttr *base = Object_wx_TextAttr::GetObject(args, 0)->GetEntity();
	wxTextAttr *overlay = Object_wx_TextAttr::GetObject(args, 1)->GetEntity();
	wxTextAttr rtn = wxTextAttr::Merge(*base, *overlay);
	return ReturnValue(env, args, Value(new Object_wx_TextAttr(new wxTextAttr(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TextAttr, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextAttrAlignment alignment = static_cast<wxTextAttrAlignment>(args.GetInt(0));
	pThis->GetEntity()->SetAlignment(alignment);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "subIndent", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TextAttr, SetLeftIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	int subIndent = 0;
	if (args.IsValid(1)) subIndent = args.GetInt(1);
	pThis->GetEntity()->SetLeftIndent(indent, subIndent);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetRightIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	pThis->GetEntity()->SetRightIndent(indent);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "tabs", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_TextAttr, SetTabs)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	std::unique_ptr<wxArrayInt> tabs(CreateArrayInt(args.GetList(0)));
	pThis->GetEntity()->SetTabs(*tabs);
	return Value::Null;
}

Gura_DeclareMethod(wx_TextAttr, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*colour);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTextAttr
//----------------------------------------------------------------------------
Object_wx_TextAttr::~Object_wx_TextAttr()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TextAttr::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttr::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttr:");
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
// Class implementation for wxTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttr)
{
	Gura_AssignFunction(TextAttr);
	Gura_AssignFunction(TextAttr_1);
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
	return new Object_wx_TextAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
