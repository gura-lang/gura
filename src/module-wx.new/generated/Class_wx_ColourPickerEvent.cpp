//----------------------------------------------------------------------------
// wxColourPickerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourPickerEvent
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ColourPickerEvent, wxColourPickerEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ColourPickerEvent, wxColourPickerEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerEvent *pThis = Object_wx_ColourPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxColourPickerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourPickerEvent, wxColourPickerEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "generator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerEvent, wxColourPickerEvent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerEvent *pThis = Object_wx_ColourPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int generator = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int colour = arg.GetNumber(2)
	//pThis->GetEntity()->wxColourPickerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourPickerEvent, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ColourPickerEvent, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerEvent *pThis = Object_wx_ColourPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourPickerEvent, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourPickerEvent, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ColourPickerEvent *pThis = Object_wx_ColourPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxColourPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourPickerEvent)
{
	Gura_AssignMethod(wx_ColourPickerEvent, wxColourPickerEvent);
	Gura_AssignMethod(wx_ColourPickerEvent, wxColourPickerEvent_1);
	Gura_AssignMethod(wx_ColourPickerEvent, GetColour);
	Gura_AssignMethod(wx_ColourPickerEvent, SetColour);
}

Gura_ImplementDescendantCreator(wx_ColourPickerEvent)
{
	return new Object_wx_ColourPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
