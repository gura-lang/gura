//----------------------------------------------------------------------------
// wxLogInterposerTemp
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogInterposerTemp
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogInterposerTemp
//----------------------------------------------------------------------------
Object_wx_LogInterposerTemp::~Object_wx_LogInterposerTemp()
{
}

Object *Object_wx_LogInterposerTemp::Clone() const
{
	return nullptr;
}

String Object_wx_LogInterposerTemp::ToString(bool exprFlag)
{
	String rtn("<wx.LogInterposerTemp:");
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
Gura_DeclareMethod(wx_LogInterposerTemp, wxLogInterposerTemp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogInterposerTemp, wxLogInterposerTemp)
{
	Signal &sig = env.GetSignal();
	Object_wx_LogInterposerTemp *pThis = Object_wx_LogInterposerTemp::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxLogInterposerTemp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogInterposerTemp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogInterposerTemp)
{
	Gura_AssignMethod(wx_LogInterposerTemp, wxLogInterposerTemp);
}

Gura_ImplementDescendantCreator(wx_LogInterposerTemp)
{
	return new Object_wx_LogInterposerTemp((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
