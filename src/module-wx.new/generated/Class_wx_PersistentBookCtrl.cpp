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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PersistentBookCtrl, "PersistentBookCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "book", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PersistentBookCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PersistentBookCtrl)
{
	//wxBookCtrlBase* book = arg.GetNumber(0)
	//wxPersistentBookCtrl(book);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PersistentBookCtrl, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentBookCtrl, __Save)
{
	Object_wx_PersistentBookCtrl *pThis = Object_wx_PersistentBookCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentBookCtrl, __Restore, "Restore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentBookCtrl, __Restore)
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
	// Constructor assignment
	Gura_AssignFunction(__PersistentBookCtrl);
	// Method assignment
	Gura_AssignMethod(wx_PersistentBookCtrl, __Save);
	Gura_AssignMethod(wx_PersistentBookCtrl, __Restore);
}

Gura_ImplementDescendantCreator(wx_PersistentBookCtrl)
{
	return new Object_wx_PersistentBookCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
