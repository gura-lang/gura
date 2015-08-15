//----------------------------------------------------------------------------
// wxColourPickerEvent
// extracted from clrpicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ColourPickerEvent: public wxColourPickerEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ColourPickerEvent *_pObj;
public:
	inline wx_ColourPickerEvent(wxObject * generator, int id, const wxColour& colour) : wxColourPickerEvent(generator, id, colour), _pObj(nullptr) {}
	~wx_ColourPickerEvent();
	inline void AssocWithGura(Object_wx_ColourPickerEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ColourPickerEvent::~wx_ColourPickerEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ColourPickerEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxColourPickerEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ColourPickerEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ColourPickerEvent));
	DeclareArg(env, "generator", VTYPE_wx_Object, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ColourPickerEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxObject *generator = Object_wx_Object::GetObject(args, 0)->GetEntity();
	int id = args.GetInt(1);
	wxColour *colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wx_ColourPickerEvent *pEntity = new wx_ColourPickerEvent(generator, id, *colour);
	Object_wx_ColourPickerEvent *pObj = Object_wx_ColourPickerEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ColourPickerEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ColourPickerEvent, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ColourPickerEvent, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerEvent *pThis = Object_wx_ColourPickerEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ColourPickerEvent, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerEvent, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerEvent *pThis = Object_wx_ColourPickerEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *pos = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetColour(*pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxColourPickerEvent
//----------------------------------------------------------------------------
Object_wx_ColourPickerEvent::~Object_wx_ColourPickerEvent()
{
}

Object *Object_wx_ColourPickerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ColourPickerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ColourPickerEvent:");
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
// Class implementation for wxColourPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourPickerEvent)
{
	Gura_AssignFunction(ColourPickerEvent);
	Gura_AssignMethod(wx_ColourPickerEvent, GetColour);
	Gura_AssignMethod(wx_ColourPickerEvent, SetColour);
}

Gura_ImplementDescendantCreator(wx_ColourPickerEvent)
{
	return new Object_wx_ColourPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
