//----------------------------------------------------------------------------
// wxOverlay
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxOverlay
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxOverlay
//----------------------------------------------------------------------------
Object_wx_Overlay::~Object_wx_Overlay()
{
}

Object *Object_wx_Overlay::Clone() const
{
	return nullptr;
}

String Object_wx_Overlay::ToString(bool exprFlag)
{
	String rtn("<wx.Overlay:");
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
Gura_DeclareMethod(wx_Overlay, wxOverlay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Overlay, wxOverlay)
{
	Signal &sig = env.GetSignal();
	Object_wx_Overlay *pThis = Object_wx_Overlay::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxOverlay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Overlay, ~wxOverlay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Overlay, ~wxOverlay)
{
	Signal &sig = env.GetSignal();
	Object_wx_Overlay *pThis = Object_wx_Overlay::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxOverlay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Overlay, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Overlay, Reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_Overlay *pThis = Object_wx_Overlay::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxOverlay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Overlay)
{
	Gura_AssignMethod(wx_Overlay, wxOverlay);
	Gura_AssignMethod(wx_Overlay, ~wxOverlay);
	Gura_AssignMethod(wx_Overlay, Reset);
}

Gura_ImplementDescendantCreator(wx_Overlay)
{
	return new Object_wx_Overlay((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
