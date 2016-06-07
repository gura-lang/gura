//----------------------------------------------------------------------------
// wxMaximizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMaximizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Object_wx_MaximizeEvent::~Object_wx_MaximizeEvent()
{
}

Object *Object_wx_MaximizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MaximizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MaximizeEvent:");
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
Gura_DeclareFunctionAlias(__MaximizeEvent, "MaximizeEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MaximizeEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MaximizeEvent)
{
	//int id = arg.GetNumber(0)
	//wxMaximizeEvent(id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MaximizeEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__MaximizeEvent);
}

Gura_ImplementDescendantCreator(wx_MaximizeEvent)
{
	return new Object_wx_MaximizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
