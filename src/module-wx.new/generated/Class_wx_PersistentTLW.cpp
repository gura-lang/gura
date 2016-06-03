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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxPersistentTLW, "wxPersistentTLW")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "book", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPersistentTLW)
{
	//int book = arg.GetNumber(0)
	//wxPersistentTLW();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PersistentTLW, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentTLW, __Save)
{
	Object_wx_PersistentTLW *pThis = Object_wx_PersistentTLW::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PersistentTLW, __Restore, "Restore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PersistentTLW, __Restore)
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
	// Constructor assignment
	Gura_AssignFunction(__wxPersistentTLW);
	// Method assignment
	Gura_AssignMethod(wx_PersistentTLW, __Save);
	Gura_AssignMethod(wx_PersistentTLW, __Restore);
}

Gura_ImplementDescendantCreator(wx_PersistentTLW)
{
	return new Object_wx_PersistentTLW((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
