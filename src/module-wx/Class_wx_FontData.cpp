//----------------------------------------------------------------------------
// wxFontData
// extracted from fontdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FontData: public wxFontData, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FontData *_pObj;
public:
	inline wx_FontData() : wxFontData(), _pObj(nullptr) {}
	~wx_FontData();
	inline void AssocWithGura(Object_wx_FontData *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FontData::~wx_FontData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FontData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFontData
//----------------------------------------------------------------------------
Gura_DeclareFunction(FontData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FontData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_FontData *pEntity = new wx_FontData();
	Object_wx_FontData *pObj = Object_wx_FontData::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FontData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_FontData, EnableEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, EnableEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool enable = arg.GetBoolean(0);
	pThis->GetEntity()->EnableEffects(enable);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, GetAllowSymbols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetAllowSymbols)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetAllowSymbols();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FontData, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontData, GetChosenFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetChosenFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont rtn = pThis->GetEntity()->GetChosenFont();
	return ReturnValue(env, arg, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontData, GetEnableEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetEnableEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetEnableEffects();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FontData, GetInitialFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetInitialFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont rtn = pThis->GetEntity()->GetInitialFont();
	return ReturnValue(env, arg, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_FontData, GetShowHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FontData, GetShowHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetShowHelp();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FontData, SetAllowSymbols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "allowSymbols", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetAllowSymbols)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool allowSymbols = arg.GetBoolean(0);
	pThis->GetEntity()->SetAllowSymbols(allowSymbols);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetChosenFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetChosenFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetChosenFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetInitialFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetInitialFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetInitialFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int min = arg.GetInt(0);
	int max = arg.GetInt(1);
	pThis->GetEntity()->SetRange(min, max);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetShowHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "showHelp", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetShowHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool showHelp = arg.GetBoolean(0);
	pThis->GetEntity()->SetShowHelp(showHelp);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFontData
//----------------------------------------------------------------------------
Object_wx_FontData::~Object_wx_FontData()
{
}

Object *Object_wx_FontData::Clone() const
{
	return nullptr;
}

String Object_wx_FontData::ToString(bool exprFlag)
{
	String rtn("<wx.FontData:");
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
// Class implementation for wxFontData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontData)
{
	Gura_AssignFunction(FontData);
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
	return new Object_wx_FontData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
