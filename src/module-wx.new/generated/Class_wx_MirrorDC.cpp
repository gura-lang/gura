//----------------------------------------------------------------------------
// wxMirrorDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMirrorDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMirrorDC
//----------------------------------------------------------------------------
Object_wx_MirrorDC::~Object_wx_MirrorDC()
{
}

Object *Object_wx_MirrorDC::Clone() const
{
	return nullptr;
}

String Object_wx_MirrorDC::ToString(bool exprFlag)
{
	String rtn("<wx.MirrorDC:");
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
Gura_DeclareMethodAlias(wx_MirrorDC, __wxMirrorDC, "wxMirrorDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mirror", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MirrorDC, __wxMirrorDC)
{
	Object_wx_MirrorDC *pThis = Object_wx_MirrorDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int mirror = arg.GetNumber(1)
	//pThis->GetEntity()->wxMirrorDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMirrorDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MirrorDC)
{
	Gura_AssignMethod(wx_MirrorDC, __wxMirrorDC);
}

Gura_ImplementDescendantCreator(wx_MirrorDC)
{
	return new Object_wx_MirrorDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
