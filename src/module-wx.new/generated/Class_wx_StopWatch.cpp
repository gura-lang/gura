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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_StopWatch, wxStopWatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, wxStopWatch)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxStopWatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StopWatch, Pause)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Pause)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Pause();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StopWatch, Resume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Resume)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StopWatch, Start)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StopWatch, Start)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->Start();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StopWatch, Time)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Time)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Time();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StopWatch, TimeInMicro)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, TimeInMicro)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->TimeInMicro();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStopWatch
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StopWatch)
{
	Gura_AssignMethod(wx_StopWatch, wxStopWatch);
	Gura_AssignMethod(wx_StopWatch, Pause);
	Gura_AssignMethod(wx_StopWatch, Resume);
	Gura_AssignMethod(wx_StopWatch, Start);
	Gura_AssignMethod(wx_StopWatch, Time);
	Gura_AssignMethod(wx_StopWatch, TimeInMicro);
}

Gura_ImplementDescendantCreator(wx_StopWatch)
{
	return new Object_wx_StopWatch((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
