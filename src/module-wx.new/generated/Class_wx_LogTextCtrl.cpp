//----------------------------------------------------------------------------
// wxLogTextCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogTextCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogTextCtrl
//----------------------------------------------------------------------------
Object_wx_LogTextCtrl::~Object_wx_LogTextCtrl()
{
}

Object *Object_wx_LogTextCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_LogTextCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.LogTextCtrl:");
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
Gura_DeclareMethod(wx_LogTextCtrl, wxLogTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pTextCtrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogTextCtrl, wxLogTextCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogTextCtrl *pThis = Object_wx_LogTextCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pTextCtrl = arg.GetNumber(0)
	//pThis->GetEntity()->wxLogTextCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogTextCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogTextCtrl)
{
	Gura_AssignMethod(wx_LogTextCtrl, wxLogTextCtrl);
}

Gura_ImplementDescendantCreator(wx_LogTextCtrl)
{
	return new Object_wx_LogTextCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
