//----------------------------------------------------------------------------
// wxListItemAttr
// extracted from listattr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListItemAttr: public wxListItemAttr, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ListItemAttr *_pObj;
public:
	inline wx_ListItemAttr() : wxListItemAttr(), _sig(NULL), _pObj(NULL) {}
	inline wx_ListItemAttr(const wxColour& colText, const wxColour& colBack, const wxFont& font) : wxListItemAttr(colText, colBack, font), _sig(NULL), _pObj(NULL) {}
	~wx_ListItemAttr();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ListItemAttr *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListItemAttr::~wx_ListItemAttr()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ListItemAttr::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListItemAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(ListItemAttrEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListItemAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListItemAttrEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ListItemAttr *pEntity = new wx_ListItemAttr();
	Object_wx_ListItemAttr *pObj = Object_wx_ListItemAttr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ListItemAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(ListItemAttr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ListItemAttr));
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListItemAttr)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBack = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxFont *font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	wx_ListItemAttr *pEntity = new wx_ListItemAttr(*colText, *colBack, *font);
	Object_wx_ListItemAttr *pObj = Object_wx_ListItemAttr::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ListItemAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ListItemAttr, GetBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, GetBackgroundColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItemAttr, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, GetFont)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItemAttr, GetTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, GetTextColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItemAttr, HasBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, HasBackgroundColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItemAttr, HasFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, HasFont)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasFont();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItemAttr, HasTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, HasTextColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasTextColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItemAttr, SetBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetBackgroundColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItemAttr, SetFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetFont)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListItemAttr, SetTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetTextColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*colour);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxListItemAttr
//----------------------------------------------------------------------------
Object_wx_ListItemAttr::~Object_wx_ListItemAttr()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ListItemAttr::Clone() const
{
	return NULL;
}

String Object_wx_ListItemAttr::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ListItemAttr:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ListItemAttr::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ListItemAttrEmpty);
	Gura_AssignFunction(ListItemAttr);
}

//----------------------------------------------------------------------------
// Class implementation for wxListItemAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListItemAttr)
{
	Gura_AssignMethod(wx_ListItemAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, GetFont);
	Gura_AssignMethod(wx_ListItemAttr, GetTextColour);
	Gura_AssignMethod(wx_ListItemAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, HasFont);
	Gura_AssignMethod(wx_ListItemAttr, HasTextColour);
	Gura_AssignMethod(wx_ListItemAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, SetFont);
	Gura_AssignMethod(wx_ListItemAttr, SetTextColour);
}

Gura_ImplementDescendantCreator(wx_ListItemAttr)
{
	return new Object_wx_ListItemAttr((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
