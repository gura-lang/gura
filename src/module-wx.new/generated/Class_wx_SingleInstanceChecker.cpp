//----------------------------------------------------------------------------
// wxSingleInstanceChecker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSingleInstanceChecker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Object_wx_SingleInstanceChecker::~Object_wx_SingleInstanceChecker()
{
}

Object *Object_wx_SingleInstanceChecker::Clone() const
{
	return nullptr;
}

String Object_wx_SingleInstanceChecker::ToString(bool exprFlag)
{
	String rtn("<wx.SingleInstanceChecker:");
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
Gura_DeclareMethod(wx_SingleInstanceChecker, wxSingleInstanceChecker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, wxSingleInstanceChecker)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSingleInstanceChecker();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleInstanceChecker, wxSingleInstanceChecker_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, wxSingleInstanceChecker_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->wxSingleInstanceChecker();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleInstanceChecker, ~wxSingleInstanceChecker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, ~wxSingleInstanceChecker)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxSingleInstanceChecker();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleInstanceChecker, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleInstanceChecker, CreateDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, CreateDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleInstanceChecker, IsAnotherRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, IsAnotherRunning)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAnotherRunning();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SingleInstanceChecker)
{
	Gura_AssignMethod(wx_SingleInstanceChecker, wxSingleInstanceChecker);
	Gura_AssignMethod(wx_SingleInstanceChecker, wxSingleInstanceChecker_1);
	Gura_AssignMethod(wx_SingleInstanceChecker, ~wxSingleInstanceChecker);
	Gura_AssignMethod(wx_SingleInstanceChecker, Create);
	Gura_AssignMethod(wx_SingleInstanceChecker, CreateDefault);
	Gura_AssignMethod(wx_SingleInstanceChecker, IsAnotherRunning);
}

Gura_ImplementDescendantCreator(wx_SingleInstanceChecker)
{
	return new Object_wx_SingleInstanceChecker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
