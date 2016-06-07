//----------------------------------------------------------------------------
// wxPowerResourceBlocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerResourceBlocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPowerResourceBlocker
//----------------------------------------------------------------------------
Object_wx_PowerResourceBlocker::~Object_wx_PowerResourceBlocker()
{
}

Object *Object_wx_PowerResourceBlocker::Clone() const
{
	return nullptr;
}

String Object_wx_PowerResourceBlocker::ToString(bool exprFlag)
{
	String rtn("<wx.PowerResourceBlocker:");
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
Gura_DeclareFunctionAlias(__PowerResourceBlocker, "PowerResourceBlocker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "reason", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PowerResourceBlocker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PowerResourceBlocker)
{
	//wxPowerResourceKind kind = arg.GetNumber(0)
	//const wxString& reason = arg.GetNumber(1)
	//explicit _rtn = wxPowerResourceBlocker(kind, reason);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PowerResourceBlocker, __IsInEffect, "IsInEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PowerResourceBlocker, __IsInEffect)
{
	Object_wx_PowerResourceBlocker *pThis = Object_wx_PowerResourceBlocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsInEffect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPowerResourceBlocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerResourceBlocker)
{
	// Constructor assignment
	Gura_AssignFunction(__PowerResourceBlocker);
	// Method assignment
	Gura_AssignMethod(wx_PowerResourceBlocker, __IsInEffect);
}

Gura_ImplementDescendantCreator(wx_PowerResourceBlocker)
{
	return new Object_wx_PowerResourceBlocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
