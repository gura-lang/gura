//----------------------------------------------------------------------------
// wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Object_wx_AutoBufferedPaintDC::~Object_wx_AutoBufferedPaintDC()
{
}

Object *Object_wx_AutoBufferedPaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_AutoBufferedPaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.AutoBufferedPaintDC:");
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
Gura_DeclareMethodAlias(wx_AutoBufferedPaintDC, __wxAutoBufferedPaintDC, "wxAutoBufferedPaintDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutoBufferedPaintDC, __wxAutoBufferedPaintDC)
{
	Object_wx_AutoBufferedPaintDC *pThis = Object_wx_AutoBufferedPaintDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->wxAutoBufferedPaintDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAutoBufferedPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AutoBufferedPaintDC)
{
	Gura_AssignMethod(wx_AutoBufferedPaintDC, __wxAutoBufferedPaintDC);
}

Gura_ImplementDescendantCreator(wx_AutoBufferedPaintDC)
{
	return new Object_wx_AutoBufferedPaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
