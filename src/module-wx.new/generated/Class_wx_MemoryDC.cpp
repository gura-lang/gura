//----------------------------------------------------------------------------
// wxMemoryDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryDC
//----------------------------------------------------------------------------
Object_wx_MemoryDC::~Object_wx_MemoryDC()
{
}

Object *Object_wx_MemoryDC::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryDC::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryDC:");
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
Gura_DeclareMethodAlias(wx_MemoryDC, __wxMemoryDC, "wxMemoryDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryDC, __wxMemoryDC)
{
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMemoryDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryDC, __wxMemoryDC_1, "wxMemoryDC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryDC, __wxMemoryDC_1)
{
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->wxMemoryDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryDC, __wxMemoryDC_2, "wxMemoryDC_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryDC, __wxMemoryDC_2)
{
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->wxMemoryDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryDC, __SelectObject, "SelectObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryDC, __SelectObject)
{
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SelectObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryDC, __SelectObjectAsSource, "SelectObjectAsSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryDC, __SelectObjectAsSource)
{
	Object_wx_MemoryDC *pThis = Object_wx_MemoryDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SelectObjectAsSource();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryDC)
{
	Gura_AssignMethod(wx_MemoryDC, __wxMemoryDC);
	Gura_AssignMethod(wx_MemoryDC, __wxMemoryDC_1);
	Gura_AssignMethod(wx_MemoryDC, __wxMemoryDC_2);
	Gura_AssignMethod(wx_MemoryDC, __SelectObject);
	Gura_AssignMethod(wx_MemoryDC, __SelectObjectAsSource);
}

Gura_ImplementDescendantCreator(wx_MemoryDC)
{
	return new Object_wx_MemoryDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
