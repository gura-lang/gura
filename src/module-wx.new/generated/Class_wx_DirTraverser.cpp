//----------------------------------------------------------------------------
// wxDirTraverser
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDirTraverser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDirTraverser
//----------------------------------------------------------------------------
Object_wx_DirTraverser::~Object_wx_DirTraverser()
{
}

Object *Object_wx_DirTraverser::Clone() const
{
	return nullptr;
}

String Object_wx_DirTraverser::ToString(bool exprFlag)
{
	String rtn("<wx.DirTraverser:");
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
Gura_DeclareMethodAlias(wx_DirTraverser, __OnDir, "OnDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirTraverser, __OnDir)
{
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//pThis->GetEntity()->OnDir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirTraverser, __OnFile, "OnFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirTraverser, __OnFile)
{
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->OnFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DirTraverser, __OnOpenError, "OnOpenError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "openerrorname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirTraverser, __OnOpenError)
{
	Object_wx_DirTraverser *pThis = Object_wx_DirTraverser::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int openerrorname = arg.GetNumber(0)
	//pThis->GetEntity()->OnOpenError();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDirTraverser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirTraverser)
{
	// Method assignment
	Gura_AssignMethod(wx_DirTraverser, __OnDir);
	Gura_AssignMethod(wx_DirTraverser, __OnFile);
	Gura_AssignMethod(wx_DirTraverser, __OnOpenError);
}

Gura_ImplementDescendantCreator(wx_DirTraverser)
{
	return new Object_wx_DirTraverser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
