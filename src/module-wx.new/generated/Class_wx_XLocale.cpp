//----------------------------------------------------------------------------
// wxXLocale
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXLocale
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXLocale
//----------------------------------------------------------------------------
Object_wx_XLocale::~Object_wx_XLocale()
{
}

Object *Object_wx_XLocale::Clone() const
{
	return nullptr;
}

String Object_wx_XLocale::ToString(bool exprFlag)
{
	String rtn("<wx.XLocale:");
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
Gura_DeclareMethod(wx_XLocale, wxXLocale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XLocale, wxXLocale)
{
	Object_wx_XLocale *pThis = Object_wx_XLocale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxXLocale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XLocale, wxXLocale_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XLocale, wxXLocale_1)
{
	Object_wx_XLocale *pThis = Object_wx_XLocale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lang = arg.GetNumber(0)
	//pThis->GetEntity()->wxXLocale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XLocale, wxXLocale_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XLocale, wxXLocale_2)
{
	Object_wx_XLocale *pThis = Object_wx_XLocale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int loc = arg.GetNumber(0)
	//pThis->GetEntity()->wxXLocale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XLocale, GetCLocale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XLocale, GetCLocale)
{
	Object_wx_XLocale *pThis = Object_wx_XLocale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCLocale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XLocale, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XLocale, IsOk)
{
	Object_wx_XLocale *pThis = Object_wx_XLocale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXLocale
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XLocale)
{
	Gura_AssignMethod(wx_XLocale, wxXLocale);
	Gura_AssignMethod(wx_XLocale, wxXLocale_1);
	Gura_AssignMethod(wx_XLocale, wxXLocale_2);
	Gura_AssignMethod(wx_XLocale, GetCLocale);
	Gura_AssignMethod(wx_XLocale, IsOk);
}

Gura_ImplementDescendantCreator(wx_XLocale)
{
	return new Object_wx_XLocale((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
