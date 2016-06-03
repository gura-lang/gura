//----------------------------------------------------------------------------
// wxZlibOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZlibOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZlibOutputStream
//----------------------------------------------------------------------------
Object_wx_ZlibOutputStream::~Object_wx_ZlibOutputStream()
{
}

Object *Object_wx_ZlibOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZlibOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZlibOutputStream:");
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
Gura_DeclareFunctionAlias(__wxZlibOutputStream, "wxZlibOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ZlibOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxZlibOutputStream)
{
	//int stream = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//wxZlibOutputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxZlibOutputStream_1, "wxZlibOutputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ZlibOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxZlibOutputStream_1)
{
	//int stream = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//wxZlibOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ZlibOutputStream, __CanHandleGZip, "CanHandleGZip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZlibOutputStream, __CanHandleGZip)
{
	Object_wx_ZlibOutputStream *pThis = Object_wx_ZlibOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanHandleGZip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZlibOutputStream, __SetDictionary, "SetDictionary")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "datalen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZlibOutputStream, __SetDictionary)
{
	Object_wx_ZlibOutputStream *pThis = Object_wx_ZlibOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int datalen = arg.GetNumber(1)
	//pThis->GetEntity()->SetDictionary();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZlibOutputStream, __SetDictionary_1, "SetDictionary_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZlibOutputStream, __SetDictionary_1)
{
	Object_wx_ZlibOutputStream *pThis = Object_wx_ZlibOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->SetDictionary();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxZlibOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZlibOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__wxZlibOutputStream);
	Gura_AssignFunction(__wxZlibOutputStream_1);
	// Method assignment
	Gura_AssignMethod(wx_ZlibOutputStream, __CanHandleGZip);
	Gura_AssignMethod(wx_ZlibOutputStream, __SetDictionary);
	Gura_AssignMethod(wx_ZlibOutputStream, __SetDictionary_1);
}

Gura_ImplementDescendantCreator(wx_ZlibOutputStream)
{
	return new Object_wx_ZlibOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
