//----------------------------------------------------------------------------
// wxCmdLineArgs
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCmdLineArgs
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCmdLineArgs
//----------------------------------------------------------------------------
Object_wx_CmdLineArgs::~Object_wx_CmdLineArgs()
{
}

Object *Object_wx_CmdLineArgs::Clone() const
{
	return nullptr;
}

String Object_wx_CmdLineArgs::ToString(bool exprFlag)
{
	String rtn("<wx.CmdLineArgs:");
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
Gura_DeclareMethodAlias(wx_CmdLineArgs, __begin, "begin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArgs, __begin)
{
	Object_wx_CmdLineArgs *pThis = Object_wx_CmdLineArgs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArgs, __end, "end")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArgs, __end)
{
	Object_wx_CmdLineArgs *pThis = Object_wx_CmdLineArgs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CmdLineArgs, __size, "size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CmdLineArgs, __size)
{
	Object_wx_CmdLineArgs *pThis = Object_wx_CmdLineArgs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCmdLineArgs
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CmdLineArgs)
{
	// Method assignment
	Gura_AssignMethod(wx_CmdLineArgs, __begin);
	Gura_AssignMethod(wx_CmdLineArgs, __end);
	Gura_AssignMethod(wx_CmdLineArgs, __size);
}

Gura_ImplementDescendantCreator(wx_CmdLineArgs)
{
	return new Object_wx_CmdLineArgs((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
