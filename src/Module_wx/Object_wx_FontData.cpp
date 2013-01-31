//----------------------------------------------------------------------------
// wxFontData
// extracted from fontdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FontData: public wxFontData, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FontData *_pObj;
public:
	inline wx_FontData() : wxFontData(), _sig(NULL), _pObj(NULL) {}
	~wx_FontData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FontData *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontData::~wx_FontData()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FontData::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontData
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FontData *pEntity = new wx_FontData();
	Object_wx_FontData *pObj = Object_wx_FontData::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FontData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_FontData, EnableEffects)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, EnableEffects)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableEffects(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontData, GetAllowSymbols)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetAllowSymbols)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetAllowSymbols();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontData, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetColour)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontData, GetChosenFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetChosenFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont rtn = pThis->GetEntity()->GetChosenFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontData, GetEnableEffects)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetEnableEffects)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetEnableEffects();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontData, GetInitialFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetInitialFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont rtn = pThis->GetEntity()->GetInitialFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontData, GetShowHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetShowHelp)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetShowHelp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FontData, SetAllowSymbols)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "allowSymbols", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetAllowSymbols)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool allowSymbols = args.GetBoolean(0);
	pThis->GetEntity()->SetAllowSymbols(allowSymbols);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontData, SetChosenFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetChosenFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetChosenFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontData, SetColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetColour)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontData, SetInitialFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetInitialFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetInitialFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontData, SetRange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetRange)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int min = args.GetInt(0);
	int max = args.GetInt(1);
	pThis->GetEntity()->SetRange(min, max);
	return Value::Null;
}

Gura_DeclareMethod(wx_FontData, SetShowHelp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "showHelp", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetShowHelp)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool showHelp = args.GetBoolean(0);
	pThis->GetEntity()->SetShowHelp(showHelp);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFontData
//----------------------------------------------------------------------------
Object_wx_FontData::~Object_wx_FontData()
{
}

Object *Object_wx_FontData::Clone() const
{
	return NULL;
}

String Object_wx_FontData::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FontData:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FontData::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(FontData);
}

//----------------------------------------------------------------------------
// Class implementation for wxFontData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontData)
{
	Gura_AssignMethod(wx_FontData, EnableEffects);
	Gura_AssignMethod(wx_FontData, GetAllowSymbols);
	Gura_AssignMethod(wx_FontData, GetColour);
	Gura_AssignMethod(wx_FontData, GetChosenFont);
	Gura_AssignMethod(wx_FontData, GetEnableEffects);
	Gura_AssignMethod(wx_FontData, GetInitialFont);
	Gura_AssignMethod(wx_FontData, GetShowHelp);
	Gura_AssignMethod(wx_FontData, SetAllowSymbols);
	Gura_AssignMethod(wx_FontData, SetChosenFont);
	Gura_AssignMethod(wx_FontData, SetColour);
	Gura_AssignMethod(wx_FontData, SetInitialFont);
	Gura_AssignMethod(wx_FontData, SetRange);
	Gura_AssignMethod(wx_FontData, SetShowHelp);
}

Gura_ImplementDescendantCreator(wx_FontData)
{
	return new Object_wx_FontData((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
