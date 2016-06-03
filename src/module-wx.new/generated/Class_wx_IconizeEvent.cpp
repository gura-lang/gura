//----------------------------------------------------------------------------
// wxIconizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIconizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Object_wx_IconizeEvent::~Object_wx_IconizeEvent()
{
}

Object *Object_wx_IconizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_IconizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.IconizeEvent:");
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
Gura_DeclareFunctionAlias(__IconizeEvent, "IconizeEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconized", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_IconizeEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__IconizeEvent)
{
	//int id = arg.GetNumber(0)
	//int iconized = arg.GetNumber(1)
	//wxIconizeEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_IconizeEvent, __IsIconized, "IsIconized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IconizeEvent, __IsIconized)
{
	Object_wx_IconizeEvent *pThis = Object_wx_IconizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIconized();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IconizeEvent, __Iconized, "Iconized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IconizeEvent, __Iconized)
{
	Object_wx_IconizeEvent *pThis = Object_wx_IconizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Iconized();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconizeEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__IconizeEvent);
	// Method assignment
	Gura_AssignMethod(wx_IconizeEvent, __IsIconized);
	Gura_AssignMethod(wx_IconizeEvent, __Iconized);
}

Gura_ImplementDescendantCreator(wx_IconizeEvent)
{
	return new Object_wx_IconizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
