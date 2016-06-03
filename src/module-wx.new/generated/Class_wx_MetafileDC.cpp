//----------------------------------------------------------------------------
// wxMetafileDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMetafileDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMetafileDC
//----------------------------------------------------------------------------
Object_wx_MetafileDC::~Object_wx_MetafileDC()
{
}

Object *Object_wx_MetafileDC::Clone() const
{
	return nullptr;
}

String Object_wx_MetafileDC::ToString(bool exprFlag)
{
	String rtn("<wx.MetafileDC:");
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
Gura_DeclareMethodAlias(wx_MetafileDC, __wxMetafileDC, "wxMetafileDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MetafileDC, __wxMetafileDC)
{
	Object_wx_MetafileDC *pThis = Object_wx_MetafileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->wxMetafileDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MetafileDC, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MetafileDC, __Close)
{
	Object_wx_MetafileDC *pThis = Object_wx_MetafileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMetafileDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MetafileDC)
{
	Gura_AssignMethod(wx_MetafileDC, __wxMetafileDC);
	Gura_AssignMethod(wx_MetafileDC, __Close);
}

Gura_ImplementDescendantCreator(wx_MetafileDC)
{
	return new Object_wx_MetafileDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
