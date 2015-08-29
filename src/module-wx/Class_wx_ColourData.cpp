//----------------------------------------------------------------------------
// wxColourData
// extracted from colour.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ColourData: public wxColourData, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ColourData *_pObj;
public:
	inline wx_ColourData() : wxColourData(), _pObj(nullptr) {}
	~wx_ColourData();
	inline void AssocWithGura(Object_wx_ColourData *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ColourData::~wx_ColourData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ColourData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColourData
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ColourData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourData)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ColourData *pEntity = new wx_ColourData();
	Object_wx_ColourData *pObj = Object_wx_ColourData::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ColourData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_ColourData, GetChooseFull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourData, GetChooseFull)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetChooseFull();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ColourData, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourData, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour &rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourData, GetCustomColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourData, GetCustomColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int i = arg.GetInt(0);
	const wxColour &rtn = pThis->GetEntity()->GetCustomColour(i);
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourData, SetChooseFull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourData, SetChooseFull)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool flag = arg.GetBoolean(0);
	pThis->GetEntity()->SetChooseFull(flag);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourData, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourData, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetColour(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourData, SetCustomColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourData, SetCustomColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int i = arg.GetInt(0);
	wxColour *colour = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetCustomColour(i, *colour);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxColourData
//----------------------------------------------------------------------------
Object_wx_ColourData::~Object_wx_ColourData()
{
}

Object *Object_wx_ColourData::Clone() const
{
	return nullptr;
}

String Object_wx_ColourData::ToString(bool exprFlag)
{
	String rtn("<wx.ColourData:");
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
// Class implementation for wxColourData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourData)
{
	Gura_AssignFunction(ColourData);
	Gura_AssignMethod(wx_ColourData, GetChooseFull);
	Gura_AssignMethod(wx_ColourData, GetColour);
	Gura_AssignMethod(wx_ColourData, GetCustomColour);
	Gura_AssignMethod(wx_ColourData, SetChooseFull);
	Gura_AssignMethod(wx_ColourData, SetColour);
	Gura_AssignMethod(wx_ColourData, SetCustomColour);
}

Gura_ImplementDescendantCreator(wx_ColourData)
{
	return new Object_wx_ColourData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
