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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxPaintEvent, "wxPaintEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPaintEvent)
{
	//int id = arg.GetNumber(0)
	//wxPaintEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPaintEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPaintEvent);
}

Gura_ImplementDescendantCreator(wx_PaintEvent)
{
	return new Object_wx_PaintEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
