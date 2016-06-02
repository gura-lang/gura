//----------------------------------------------------------------------------
// wxPersistentBookCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistentBookCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistentBookCtrl
//----------------------------------------------------------------------------
Object_wx_PersistentBookCtrl::~Object_wx_PersistentBookCtrl()
{
}

Object *Object_wx_PersistentBookCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_PersistentBookCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.PersistentBookCtrl:");
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
Gura_DeclareMethod(wx_PersistentBookCtrl, wxPersistentBookCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "book", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PersistentBookCtrl, wxPersistentBookCtrl)
{
	Object_wx_PersistentBookCtrl *pThis = Object_wx_PersistentBookCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int book = arg.GetNumber(0)
	//pThis->GetEntity()->wxPersistentBookCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentBookCtrl, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentBookCtrl, Save)
{
	Object_wx_PersistentBookCtrl *pThis = Object_wx_PersistentBookCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PersistentBookCtrl, Restore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentBookCtrl, Restore)
{
	Object_wx_PersistentBookCtrl *pThis = Object_wx_PersistentBookCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Restore();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPersistentBookCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentBookCtrl)
{
	Gura_AssignMethod(wx_PersistentBookCtrl, wxPersistentBookCtrl);
	Gura_AssignMethod(wx_PersistentBookCtrl, Save);
	Gura_AssignMethod(wx_PersistentBookCtrl, Restore);
}

Gura_ImplementDescendantCreator(wx_PersistentBookCtrl)
{
	return new Object_wx_PersistentBookCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
