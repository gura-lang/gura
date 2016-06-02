//----------------------------------------------------------------------------
// wxFilterInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilterInputStream
//----------------------------------------------------------------------------
Object_wx_FilterInputStream::~Object_wx_FilterInputStream()
{
}

Object *Object_wx_FilterInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FilterInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FilterInputStream:");
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
Gura_DeclareMethod(wx_FilterInputStream, wxFilterInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterInputStream, wxFilterInputStream)
{
	Object_wx_FilterInputStream *pThis = Object_wx_FilterInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxFilterInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterInputStream, wxFilterInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterInputStream, wxFilterInputStream_1)
{
	Object_wx_FilterInputStream *pThis = Object_wx_FilterInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxFilterInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFilterInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterInputStream)
{
	Gura_AssignMethod(wx_FilterInputStream, wxFilterInputStream);
	Gura_AssignMethod(wx_FilterInputStream, wxFilterInputStream_1);
}

Gura_ImplementDescendantCreator(wx_FilterInputStream)
{
	return new Object_wx_FilterInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
