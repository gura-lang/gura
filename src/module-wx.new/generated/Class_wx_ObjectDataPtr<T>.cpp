//----------------------------------------------------------------------------
// wxObjectDataPtr<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxObjectDataPtr<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxObjectDataPtr<T>
//----------------------------------------------------------------------------
Object_wx_ObjectDataPtr<T>::~Object_wx_ObjectDataPtr<T>()
{
}

Object *Object_wx_ObjectDataPtr<T>::Clone() const
{
	return nullptr;
}

String Object_wx_ObjectDataPtr<T>::ToString(bool exprFlag)
{
	String rtn("<wx.ObjectDataPtr<T>:");
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
Gura_DeclareMethod(wx_ObjectDataPtr<T>, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ObjectDataPtr<T>, get)
{
	Signal &sig = env.GetSignal();
	Object_wx_ObjectDataPtr<T> *pThis = Object_wx_ObjectDataPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ObjectDataPtr<T>, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ObjectDataPtr<T>, reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_ObjectDataPtr<T> *pThis = Object_wx_ObjectDataPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ObjectDataPtr<T>, unspecified_bool_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ObjectDataPtr<T>, unspecified_bool_type)
{
	Signal &sig = env.GetSignal();
	Object_wx_ObjectDataPtr<T> *pThis = Object_wx_ObjectDataPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->unspecified_bool_type();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxObjectDataPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ObjectDataPtr<T>)
{
	Gura_AssignMethod(wx_ObjectDataPtr<T>, get);
	Gura_AssignMethod(wx_ObjectDataPtr<T>, reset);
	Gura_AssignMethod(wx_ObjectDataPtr<T>, unspecified_bool_type);
}

Gura_ImplementDescendantCreator(wx_ObjectDataPtr<T>)
{
	return new Object_wx_ObjectDataPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
