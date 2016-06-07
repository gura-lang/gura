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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ActivityIndicator, "ActivityIndicator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ActivityIndicator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ActivityIndicator)
{
	//wxActivityIndicator();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ActivityIndicator_1, "ActivityIndicator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ActivityIndicator));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ActivityIndicator_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxActivityIndicator(parent, winid, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ActivityIndicator, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ActivityIndicator, __Create)
{
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create(parent, winid, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ActivityIndicator, __Start, "Start")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActivityIndicator, __Start)
{
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Start();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ActivityIndicator, __Stop, "Stop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActivityIndicator, __Stop)
{
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ActivityIndicator, __IsRunning, "IsRunning")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ActivityIndicator, __IsRunning)
{
	Object_wx_ActivityIndicator *pThis = Object_wx_ActivityIndicator::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRunning();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxActivityIndicator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActivityIndicator)
{
	// Constructor assignment
	Gura_AssignFunction(__ActivityIndicator);
	Gura_AssignFunction(__ActivityIndicator_1);
	// Method assignment
	Gura_AssignMethod(wx_ActivityIndicator, __Create);
	Gura_AssignMethod(wx_ActivityIndicator, __Start);
	Gura_AssignMethod(wx_ActivityIndicator, __Stop);
	Gura_AssignMethod(wx_ActivityIndicator, __IsRunning);
}

Gura_ImplementDescendantCreator(wx_ActivityIndicator)
{
	return new Object_wx_ActivityIndicator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
