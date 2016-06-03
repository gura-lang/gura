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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxZlibInputStream, "wxZlibInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxZlibInputStream)
{
	//int stream = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxZlibInputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxZlibInputStream_1, "wxZlibInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxZlibInputStream_1)
{
	//int stream = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxZlibInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ZlibInputStream, __CanHandleGZip, "CanHandleGZip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZlibInputStream, __CanHandleGZip)
{
	Object_wx_ZlibInputStream *pThis = Object_wx_ZlibInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanHandleGZip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZlibInputStream, __SetDictionary, "SetDictionary")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "datalen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZlibInputStream, __SetDictionary)
{
	Object_wx_ZlibInputStream *pThis = Object_wx_ZlibInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int datalen = arg.GetNumber(1)
	//pThis->GetEntity()->SetDictionary();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZlibInputStream, __SetDictionary_1, "SetDictionary_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZlibInputStream, __SetDictionary_1)
{
	Object_wx_ZlibInputStream *pThis = Object_wx_ZlibInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->SetDictionary();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxZlibInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZlibInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__wxZlibInputStream);
	Gura_AssignFunction(__wxZlibInputStream_1);
	// Method assignment
	Gura_AssignMethod(wx_ZlibInputStream, __CanHandleGZip);
	Gura_AssignMethod(wx_ZlibInputStream, __SetDictionary);
	Gura_AssignMethod(wx_ZlibInputStream, __SetDictionary_1);
}

Gura_ImplementDescendantCreator(wx_ZlibInputStream)
{
	return new Object_wx_ZlibInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
