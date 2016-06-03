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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxLogGui, "wxLogGui")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxLogGui)
{
	//wxLogGui();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_LogGui, __Flush, "Flush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, __Flush)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogGui, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, __GetTitle)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogGui, __GetSeverityIcon, "GetSeverityIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, __GetSeverityIcon)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSeverityIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogGui, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LogGui, __Clear)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogGui, __DoShowSingleLogMessage, "DoShowSingleLogMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogGui, __DoShowSingleLogMessage)
{
	Object_wx_LogGui *pThis = Object_wx_LogGui::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->DoShowSingleLogMessage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LogGui, __DoShowMultipleLogMessages, "DoShowMultipleLogMessages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "messages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "severities", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "times", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LogGui, __DoShowMultipleLogMessages)
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
	// Constructor assignment
	Gura_AssignFunction(__wxLogGui);
	// Method assignment
	Gura_AssignMethod(wx_LogGui, __Flush);
	Gura_AssignMethod(wx_LogGui, __GetTitle);
	Gura_AssignMethod(wx_LogGui, __GetSeverityIcon);
	Gura_AssignMethod(wx_LogGui, __Clear);
	Gura_AssignMethod(wx_LogGui, __DoShowSingleLogMessage);
	Gura_AssignMethod(wx_LogGui, __DoShowMultipleLogMessages);
}

Gura_ImplementDescendantCreator(wx_LogGui)
{
	return new Object_wx_LogGui((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
