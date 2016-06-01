//----------------------------------------------------------------------------
// wxPostScriptDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPostScriptDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPostScriptDC
//----------------------------------------------------------------------------
Object_wx_PostScriptDC::~Object_wx_PostScriptDC()
{
}

Object *Object_wx_PostScriptDC::Clone() const
{
	return nullptr;
}

String Object_wx_PostScriptDC::ToString(bool exprFlag)
{
	String rtn("<wx.PostScriptDC:");
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
Gura_DeclareMethod(wx_PostScriptDC, wxPostScriptDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PostScriptDC, wxPostScriptDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_PostScriptDC *pThis = Object_wx_PostScriptDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPostScriptDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PostScriptDC, wxPostScriptDC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PostScriptDC, wxPostScriptDC_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PostScriptDC *pThis = Object_wx_PostScriptDC::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->wxPostScriptDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPostScriptDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PostScriptDC)
{
	Gura_AssignMethod(wx_PostScriptDC, wxPostScriptDC);
	Gura_AssignMethod(wx_PostScriptDC, wxPostScriptDC_1);
}

Gura_ImplementDescendantCreator(wx_PostScriptDC)
{
	return new Object_wx_PostScriptDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
