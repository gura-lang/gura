//----------------------------------------------------------------------------
// wxActivityIndicator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxActivityIndicator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxActivityIndicator
//----------------------------------------------------------------------------
Object_wx_ActivityIndicator::~Object_wx_ActivityIndicator()
{
}

Object *Object_wx_ActivityIndicator::Clone() const
{
	return nullptr;
}

String Object_wx_ActivityIndicator::ToString(bool exprFlag)
{
	String rtn("<wx.ActivityIndicator:");
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
Gura_DeclareMethod(wx_ActivityIndicator, wxActivityIndicator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActivityIndicator, wxActivityIndicator)
{
	Signal &sig = env.GetSignal();
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxActivityIndicator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActivityIndicator, wxActivityIndicator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActivityIndicator, wxActivityIndicator_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxActivityIndicator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActivityIndicator, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActivityIndicator, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActivityIndicator, Start)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActivityIndicator, Start)
{
	Signal &sig = env.GetSignal();
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Start();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActivityIndicator, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActivityIndicator, Stop)
{
	Signal &sig = env.GetSignal();
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ActivityIndicator, IsRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActivityIndicator, IsRunning)
{
	Signal &sig = env.GetSignal();
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsRunning();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxActivityIndicator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActivityIndicator)
{
	Gura_AssignMethod(wx_ActivityIndicator, wxActivityIndicator);
	Gura_AssignMethod(wx_ActivityIndicator, wxActivityIndicator_1);
	Gura_AssignMethod(wx_ActivityIndicator, Create);
	Gura_AssignMethod(wx_ActivityIndicator, Start);
	Gura_AssignMethod(wx_ActivityIndicator, Stop);
	Gura_AssignMethod(wx_ActivityIndicator, IsRunning);
}

Gura_ImplementDescendantCreator(wx_ActivityIndicator)
{
	return new Object_wx_ActivityIndicator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
