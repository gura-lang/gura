//----------------------------------------------------------------------------
// wxZlibInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZlibInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZlibInputStream
//----------------------------------------------------------------------------
Object_wx_ZlibInputStream::~Object_wx_ZlibInputStream()
{
}

Object *Object_wx_ZlibInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZlibInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZlibInputStream:");
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
Gura_DeclareMethod(wx_ZlibInputStream, wxZlibInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZlibInputStream, wxZlibInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZlibInputStream *pThis = Object_wx_ZlibInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxZlibInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZlibInputStream, wxZlibInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZlibInputStream, wxZlibInputStream_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZlibInputStream *pThis = Object_wx_ZlibInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxZlibInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZlibInputStream, CanHandleGZip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZlibInputStream, CanHandleGZip)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZlibInputStream *pThis = Object_wx_ZlibInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanHandleGZip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZlibInputStream, SetDictionary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "datalen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZlibInputStream, SetDictionary)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZlibInputStream *pThis = Object_wx_ZlibInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int datalen = arg.GetNumber(1)
	//pThis->GetEntity()->SetDictionary();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZlibInputStream, SetDictionary_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZlibInputStream, SetDictionary_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZlibInputStream *pThis = Object_wx_ZlibInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->SetDictionary();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxZlibInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZlibInputStream)
{
	Gura_AssignMethod(wx_ZlibInputStream, wxZlibInputStream);
	Gura_AssignMethod(wx_ZlibInputStream, wxZlibInputStream_1);
	Gura_AssignMethod(wx_ZlibInputStream, CanHandleGZip);
	Gura_AssignMethod(wx_ZlibInputStream, SetDictionary);
	Gura_AssignMethod(wx_ZlibInputStream, SetDictionary_1);
}

Gura_ImplementDescendantCreator(wx_ZlibInputStream)
{
	return new Object_wx_ZlibInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
