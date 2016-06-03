//----------------------------------------------------------------------------
// wxTarInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTarInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarInputStream
//----------------------------------------------------------------------------
Object_wx_TarInputStream::~Object_wx_TarInputStream()
{
}

Object *Object_wx_TarInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TarInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TarInputStream:");
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
Gura_DeclareFunctionAlias(__TarInputStream, "TarInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TarInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TarInputStream)
{
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//wxTarInputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TarInputStream_1, "TarInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TarInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TarInputStream_1)
{
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//wxTarInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TarInputStream, __CloseEntry, "CloseEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarInputStream, __CloseEntry)
{
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarInputStream, __GetNextEntry, "GetNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarInputStream, __GetNextEntry)
{
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarInputStream, __OpenEntry, "OpenEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarInputStream, __OpenEntry)
{
	Object_wx_TarInputStream *pThis = Object_wx_TarInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->OpenEntry();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTarInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__TarInputStream);
	Gura_AssignFunction(__TarInputStream_1);
	// Method assignment
	Gura_AssignMethod(wx_TarInputStream, __CloseEntry);
	Gura_AssignMethod(wx_TarInputStream, __GetNextEntry);
	Gura_AssignMethod(wx_TarInputStream, __OpenEntry);
}

Gura_ImplementDescendantCreator(wx_TarInputStream)
{
	return new Object_wx_TarInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
