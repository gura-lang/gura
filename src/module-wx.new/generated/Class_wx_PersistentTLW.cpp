//----------------------------------------------------------------------------
// wxPersistentTLW
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistentTLW
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistentTLW
//----------------------------------------------------------------------------
Object_wx_PersistentTLW::~Object_wx_PersistentTLW()
{
}

Object *Object_wx_PersistentTLW::Clone() const
{
	return nullptr;
}

String Object_wx_PersistentTLW::ToString(bool exprFlag)
{
	String rtn("<wx.PersistentTLW:");
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
Gura_DeclareMethod(wx_PersistentTLW, wxPersistentTLW)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "book", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentTLW, wxPersistentTLW)
{
	Object_wx_PersistentTLW *pThis = Object_wx_PersistentTLW::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int book = arg.GetNumber(0)
	//pThis->GetEntity()->wxPersistentTLW();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentTLW, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentTLW, Save)
{
	Object_wx_PersistentTLW *pThis = Object_wx_PersistentTLW::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentTLW, Restore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentTLW, Restore)
{
	Object_wx_PersistentTLW *pThis = Object_wx_PersistentTLW::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Restore();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPersistentTLW
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentTLW)
{
	Gura_AssignMethod(wx_PersistentTLW, wxPersistentTLW);
	Gura_AssignMethod(wx_PersistentTLW, Save);
	Gura_AssignMethod(wx_PersistentTLW, Restore);
}

Gura_ImplementDescendantCreator(wx_PersistentTLW)
{
	return new Object_wx_PersistentTLW((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
