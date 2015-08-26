//----------------------------------------------------------------------------
// wxListItemAttr
// extracted from listattr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListItemAttr: public wxListItemAttr, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ListItemAttr *_pObj;
public:
	inline wx_ListItemAttr() : wxListItemAttr(), _pObj(nullptr) {}
	inline wx_ListItemAttr(const wxColour& colText, const wxColour& colBack, const wxFont& font) : wxListItemAttr(colText, colBack, font), _pObj(nullptr) {}
	~wx_ListItemAttr();
	inline void AssocWithGura(Object_wx_ListItemAttr *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListItemAttr::~wx_ListItemAttr()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ListItemAttr::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListItemAttr
//----------------------------------------------------------------------------
Gura_DeclareFunction(ListItemAttrEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListItemAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListItemAttrEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ListItemAttr *pEntity = new wx_ListItemAttr();
	Object_wx_ListItemAttr *pObj = Object_wx_ListItemAttr::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ListItemAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(ListItemAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ListItemAttr));
	DeclareArg(env, "colText", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "colBack", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListItemAttr)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxColour *colText = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	wxColour *colBack = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxFont *font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	wx_ListItemAttr *pEntity = new wx_ListItemAttr(*colText, *colBack, *font);
	Object_wx_ListItemAttr *pObj = Object_wx_ListItemAttr::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ListItemAttr(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_ListItemAttr, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetBackgroundColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItemAttr, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItemAttr, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListItemAttr, HasBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, HasBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasBackgroundColour();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItemAttr, HasFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, HasFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasFont();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItemAttr, HasTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListItemAttr, HasTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasTextColour();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListItemAttr, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItemAttr, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*colour);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxListItemAttr
//----------------------------------------------------------------------------
Object_wx_ListItemAttr::~Object_wx_ListItemAttr()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ListItemAttr::Clone() const
{
	return nullptr;
}

String Object_wx_ListItemAttr::ToString(bool exprFlag)
{
	String rtn("<wx.ListItemAttr:");
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
// Class implementation for wxListItemAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListItemAttr)
{
	Gura_AssignFunction(ListItemAttrEmpty);
	Gura_AssignFunction(ListItemAttr);
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
	return new Object_wx_ListItemAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
