//----------------------------------------------------------------------------
// wxPaintEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPaintEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPaintEvent
//----------------------------------------------------------------------------
Object_wx_PaintEvent::~Object_wx_PaintEvent()
{
}

Object *Object_wx_PaintEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PaintEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PaintEvent:");
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
Gura_DeclareMethodAlias(wx_PaintEvent, __wxPaintEvent, "wxPaintEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PaintEvent, __wxPaintEvent)
{
	Object_wx_PaintEvent *pThis = Object_wx_PaintEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->wxPaintEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPaintEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintEvent)
{
	Gura_AssignMethod(wx_PaintEvent, __wxPaintEvent);
}

Gura_ImplementDescendantCreator(wx_PaintEvent)
{
	return new Object_wx_PaintEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
