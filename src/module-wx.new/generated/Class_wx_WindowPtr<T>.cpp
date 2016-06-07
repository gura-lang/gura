//----------------------------------------------------------------------------
// wxWindowPtr<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowPtr<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowPtr<T>
//----------------------------------------------------------------------------
Object_wx_WindowPtr<T>::~Object_wx_WindowPtr<T>()
{
}

Object *Object_wx_WindowPtr<T>::Clone() const
{
	return nullptr;
}

String Object_wx_WindowPtr<T>::ToString(bool exprFlag)
{
	String rtn("<wx.WindowPtr<T>:");
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
Gura_DeclareMethodAlias(wx_WindowPtr<T>, __wxWindowPtr, "wxWindowPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_WindowPtr<T>, __wxWindowPtr)
{
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxWindowPtr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WindowPtr<T>, __wxWindowPtr_1, "wxWindowPtr_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowPtr<T>, __wxWindowPtr_1)
{
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* ptr = arg.GetNumber(0)
	//explicit _rtn = pThis->GetEntity()->wxWindowPtr(ptr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WindowPtr<T>, __wxWindowPtr_2, "wxWindowPtr_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowPtr<T>, __wxWindowPtr_2)
{
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* ptr = arg.GetNumber(0)
	//Deleter d = arg.GetNumber(1)
	//explicit _rtn = pThis->GetEntity()->wxWindowPtr(ptr, d);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WindowPtr<T>, __wxWindowPtr_3, "wxWindowPtr_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tocopy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowPtr<T>, __wxWindowPtr_3)
{
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxWindowPtr<T>& tocopy = arg.GetNumber(0)
	//pThis->GetEntity()->wxWindowPtr(tocopy);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WindowPtr<T>, __reset, "reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowPtr<T>, __reset)
{
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* ptr = arg.GetNumber(0)
	//pThis->GetEntity()->reset(ptr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowPtr<T>)
{
	// Class assignment
	Gura_AssignValueEx("WindowPtr<T>", Reference());
	// Method assignment
	Gura_AssignMethod(wx_WindowPtr<T>, __wxWindowPtr);
	Gura_AssignMethod(wx_WindowPtr<T>, __wxWindowPtr_1);
	Gura_AssignMethod(wx_WindowPtr<T>, __wxWindowPtr_2);
	Gura_AssignMethod(wx_WindowPtr<T>, __wxWindowPtr_3);
	Gura_AssignMethod(wx_WindowPtr<T>, __reset);
}

Gura_ImplementDescendantCreator(wx_WindowPtr<T>)
{
	return new Object_wx_WindowPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
