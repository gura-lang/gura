//----------------------------------------------------------------------------
// wxLogGui
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogGui
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogGui
//----------------------------------------------------------------------------
Object_wx_LogGui::~Object_wx_LogGui()
{
}

Object *Object_wx_LogGui::Clone() const
{
	return nullptr;
}

String Object_wx_LogGui::ToString(bool exprFlag)
{
	String rtn("<wx.LogGui:");
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
Gura_DeclareMethod(wx_LogGui, wxLogGui)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, wxLogGui)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxLogGui();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogGui, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, Flush)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogGui, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, GetTitle)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogGui, GetSeverityIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, GetSeverityIcon)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSeverityIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogGui, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, Clear)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogGui, DoShowSingleLogMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogGui, DoShowSingleLogMessage)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->DoShowSingleLogMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LogGui, DoShowMultipleLogMessages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "messages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "severities", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "times", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogGui, DoShowMultipleLogMessages)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int messages = arg.GetNumber(0)
	//int severities = arg.GetNumber(1)
	//int times = arg.GetNumber(2)
	//int title = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->DoShowMultipleLogMessages();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogGui
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogGui)
{
	Gura_AssignMethod(wx_LogGui, wxLogGui);
	Gura_AssignMethod(wx_LogGui, Flush);
	Gura_AssignMethod(wx_LogGui, GetTitle);
	Gura_AssignMethod(wx_LogGui, GetSeverityIcon);
	Gura_AssignMethod(wx_LogGui, Clear);
	Gura_AssignMethod(wx_LogGui, DoShowSingleLogMessage);
	Gura_AssignMethod(wx_LogGui, DoShowMultipleLogMessages);
}

Gura_ImplementDescendantCreator(wx_LogGui)
{
	return new Object_wx_LogGui((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
