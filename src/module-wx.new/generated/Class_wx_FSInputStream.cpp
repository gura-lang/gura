//----------------------------------------------------------------------------
// wxFSInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFSInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFSInputStream
//----------------------------------------------------------------------------
Object_wx_FSInputStream::~Object_wx_FSInputStream()
{
}

Object *Object_wx_FSInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FSInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FSInputStream:");
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
Gura_DeclareMethodAlias(wx_FSInputStream, __wxFileInputStream, "wxFileInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSInputStream, __wxFileInputStream)
{
	Object_wx_FSInputStream *pThis = Object_wx_FSInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxFileInputStream(filename, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSInputStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSInputStream, __IsOk)
{
	Object_wx_FSInputStream *pThis = Object_wx_FSInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFSInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FSInputStream)
{
	// Class assignment
	Gura_AssignValueEx("FSInputStream", Reference());
	// Method assignment
	Gura_AssignMethod(wx_FSInputStream, __wxFileInputStream);
	Gura_AssignMethod(wx_FSInputStream, __IsOk);
}

Gura_ImplementDescendantCreator(wx_FSInputStream)
{
	return new Object_wx_FSInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
