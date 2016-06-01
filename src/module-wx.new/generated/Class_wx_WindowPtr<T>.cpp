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
Gura_DeclareMethod(wx_WindowPtr<T>, wxWindowPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WindowPtr<T>, wxWindowPtr)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxWindowPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WindowPtr<T>, wxWindowPtr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowPtr<T>, wxWindowPtr_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->wxWindowPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WindowPtr<T>, wxWindowPtr_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowPtr<T>, wxWindowPtr_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//int d = arg.GetNumber(1)
	//pThis->GetEntity()->wxWindowPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WindowPtr<T>, wxWindowPtr_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tocopy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowPtr<T>, wxWindowPtr_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tocopy = arg.GetNumber(0)
	//pThis->GetEntity()->wxWindowPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WindowPtr<T>, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowPtr<T>, reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_WindowPtr<T> *pThis = Object_wx_WindowPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowPtr<T>)
{
	Gura_AssignMethod(wx_WindowPtr<T>, wxWindowPtr);
	Gura_AssignMethod(wx_WindowPtr<T>, wxWindowPtr_1);
	Gura_AssignMethod(wx_WindowPtr<T>, wxWindowPtr_2);
	Gura_AssignMethod(wx_WindowPtr<T>, wxWindowPtr_3);
	Gura_AssignMethod(wx_WindowPtr<T>, reset);
}

Gura_ImplementDescendantCreator(wx_WindowPtr<T>)
{
	return new Object_wx_WindowPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
