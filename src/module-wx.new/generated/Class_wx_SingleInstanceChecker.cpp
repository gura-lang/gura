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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SingleInstanceChecker, "SingleInstanceChecker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SingleInstanceChecker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SingleInstanceChecker)
{
	//wxSingleInstanceChecker();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SingleInstanceChecker_1, "SingleInstanceChecker_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SingleInstanceChecker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SingleInstanceChecker_1)
{
	//const wxString& name = arg.GetNumber(0)
	//const wxString& path = arg.GetNumber(1)
	//wxSingleInstanceChecker();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SingleInstanceChecker, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, __Create)
{
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxString& path = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SingleInstanceChecker, __CreateDefault, "CreateDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, __CreateDefault)
{
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SingleInstanceChecker, __IsAnotherRunning, "IsAnotherRunning")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleInstanceChecker, __IsAnotherRunning)
{
	Object_wx_SingleInstanceChecker *pThis = Object_wx_SingleInstanceChecker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAnotherRunning();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SingleInstanceChecker)
{
	// Constructor assignment
	Gura_AssignFunction(__SingleInstanceChecker);
	Gura_AssignFunction(__SingleInstanceChecker_1);
	// Method assignment
	Gura_AssignMethod(wx_SingleInstanceChecker, __Create);
	Gura_AssignMethod(wx_SingleInstanceChecker, __CreateDefault);
	Gura_AssignMethod(wx_SingleInstanceChecker, __IsAnotherRunning);
}

Gura_ImplementDescendantCreator(wx_SingleInstanceChecker)
{
	return new Object_wx_SingleInstanceChecker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
