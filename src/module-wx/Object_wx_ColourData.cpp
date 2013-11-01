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
	Gura::Signal _sig;
	Object_wx_ColourData *_pObj;
public:
	inline wx_ColourData() : wxColourData(), _sig(NULL), _pObj(NULL) {}
	~wx_ColourData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ColourData *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ColourData::~wx_ColourData()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ColourData::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColourData
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ColourData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ColourData *pEntity = new wx_ColourData();
	Object_wx_ColourData *pObj = Object_wx_ColourData::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ColourData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ColourData, GetChooseFull)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourData, GetChooseFull)
{
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetChooseFull();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ColourData, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourData, GetColour)
{
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour &rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourData, GetCustomColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourData, GetCustomColour)
{
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int i = args.GetInt(0);
	const wxColour &rtn = pThis->GetEntity()->GetCustomColour(i);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourData, SetChooseFull)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourData, SetChooseFull)
{
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetChooseFull(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_ColourData, SetColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourData, SetColour)
{
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_ColourData, SetCustomColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourData, SetCustomColour)
{
	Object_wx_ColourData *pThis = Object_wx_ColourData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int i = args.GetInt(0);
	wxColour *colour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetCustomColour(i, *colour);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxColourData
//----------------------------------------------------------------------------
Object_wx_ColourData::~Object_wx_ColourData()
{
}

Object *Object_wx_ColourData::Clone() const
{
	return NULL;
}

String Object_wx_ColourData::ToString(bool exprFlag)
{
	String rtn("<wx.ColourData:");
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
	return new Object_wx_ColourData((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
