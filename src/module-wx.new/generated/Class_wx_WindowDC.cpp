//----------------------------------------------------------------------------
// wxWindowDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowDC
//----------------------------------------------------------------------------
Object_wx_WindowDC::~Object_wx_WindowDC()
{
}

Object *Object_wx_WindowDC::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDC::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDC:");
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
Gura_DeclareMethodAlias(wx_WindowDC, __wxWindowDC, "wxWindowDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowDC, __wxWindowDC)
{
	Object_wx_WindowDC *pThis = Object_wx_WindowDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->wxWindowDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDC)
{
	Gura_AssignMethod(wx_WindowDC, __wxWindowDC);
}

Gura_ImplementDescendantCreator(wx_WindowDC)
{
	return new Object_wx_WindowDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
