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
Gura_DeclareMethod(wx_FSInputStream, wxFileInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSInputStream, wxFileInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_FSInputStream *pThis = Object_wx_FSInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxFileInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSInputStream, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSInputStream, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_FSInputStream *pThis = Object_wx_FSInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFSInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FSInputStream)
{
	Gura_AssignMethod(wx_FSInputStream, wxFileInputStream);
	Gura_AssignMethod(wx_FSInputStream, IsOk);
}

Gura_ImplementDescendantCreator(wx_FSInputStream)
{
	return new Object_wx_FSInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
