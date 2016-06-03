//----------------------------------------------------------------------------
// wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxQueryNewPaletteEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
Object_wx_QueryNewPaletteEvent::~Object_wx_QueryNewPaletteEvent()
{
}

Object *Object_wx_QueryNewPaletteEvent::Clone() const
{
	return nullptr;
}

String Object_wx_QueryNewPaletteEvent::ToString(bool exprFlag)
{
	String rtn("<wx.QueryNewPaletteEvent:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxQueryNewPaletteEvent, "wxQueryNewPaletteEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_QueryNewPaletteEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxQueryNewPaletteEvent)
{
	//int winid = arg.GetNumber(0)
	//wxQueryNewPaletteEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_QueryNewPaletteEvent, __SetPaletteRealized, "SetPaletteRealized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "realized", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_QueryNewPaletteEvent, __SetPaletteRealized)
{
	Object_wx_QueryNewPaletteEvent *pThis = Object_wx_QueryNewPaletteEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int realized = arg.GetNumber(0)
	//pThis->GetEntity()->SetPaletteRealized();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_QueryNewPaletteEvent, __GetPaletteRealized, "GetPaletteRealized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_QueryNewPaletteEvent, __GetPaletteRealized)
{
	Object_wx_QueryNewPaletteEvent *pThis = Object_wx_QueryNewPaletteEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPaletteRealized();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_QueryNewPaletteEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxQueryNewPaletteEvent);
	// Method assignment
	Gura_AssignMethod(wx_QueryNewPaletteEvent, __SetPaletteRealized);
	Gura_AssignMethod(wx_QueryNewPaletteEvent, __GetPaletteRealized);
}

Gura_ImplementDescendantCreator(wx_QueryNewPaletteEvent)
{
	return new Object_wx_QueryNewPaletteEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
