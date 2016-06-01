//----------------------------------------------------------------------------
// wxLogInterposer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogInterposer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogInterposer
//----------------------------------------------------------------------------
Object_wx_LogInterposer::~Object_wx_LogInterposer()
{
}

Object *Object_wx_LogInterposer::Clone() const
{
	return nullptr;
}

String Object_wx_LogInterposer::ToString(bool exprFlag)
{
	String rtn("<wx.LogInterposer:");
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
Gura_DeclareMethod(wx_LogInterposer, wxLogInterposer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogInterposer, wxLogInterposer)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogInterposer *pThis = Object_wx_LogInterposer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxLogInterposer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogInterposer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogInterposer)
{
	Gura_AssignMethod(wx_LogInterposer, wxLogInterposer);
}

Gura_ImplementDescendantCreator(wx_LogInterposer)
{
	return new Object_wx_LogInterposer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
