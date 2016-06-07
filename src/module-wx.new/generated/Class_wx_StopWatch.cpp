//----------------------------------------------------------------------------
// wxStopWatch
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStopWatch
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStopWatch
//----------------------------------------------------------------------------
Object_wx_StopWatch::~Object_wx_StopWatch()
{
}

Object *Object_wx_StopWatch::Clone() const
{
	return nullptr;
}

String Object_wx_StopWatch::ToString(bool exprFlag)
{
	String rtn("<wx.StopWatch:");
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
Gura_DeclareFunctionAlias(__StopWatch, "StopWatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StopWatch));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StopWatch)
{
	//wxStopWatch();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StopWatch, __Pause, "Pause")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, __Pause)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Pause();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StopWatch, __Resume, "Resume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, __Resume)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StopWatch, __Start, "Start")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StopWatch, __Start)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->Start(milliseconds);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StopWatch, __Time, "Time")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, __Time)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Time();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StopWatch, __TimeInMicro, "TimeInMicro")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, __TimeInMicro)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TimeInMicro();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStopWatch
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StopWatch)
{
	// Constructor assignment
	Gura_AssignFunction(__StopWatch);
	// Method assignment
	Gura_AssignMethod(wx_StopWatch, __Pause);
	Gura_AssignMethod(wx_StopWatch, __Resume);
	Gura_AssignMethod(wx_StopWatch, __Start);
	Gura_AssignMethod(wx_StopWatch, __Time);
	Gura_AssignMethod(wx_StopWatch, __TimeInMicro);
}

Gura_ImplementDescendantCreator(wx_StopWatch)
{
	return new Object_wx_StopWatch((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
