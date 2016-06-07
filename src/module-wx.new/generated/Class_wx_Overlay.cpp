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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Overlay, "Overlay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Overlay));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Overlay)
{
	//wxOverlay();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Overlay, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Overlay, __Reset)
{
	Object_wx_Overlay *pThis = Object_wx_Overlay::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxOverlay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Overlay)
{
	// Constructor assignment
	Gura_AssignFunction(__Overlay);
	// Method assignment
	Gura_AssignMethod(wx_Overlay, __Reset);
}

Gura_ImplementDescendantCreator(wx_Overlay)
{
	return new Object_wx_Overlay((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
