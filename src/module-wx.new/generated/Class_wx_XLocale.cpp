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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxXLocale, "wxXLocale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XLocale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxXLocale)
{
	//wxXLocale();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxXLocale_1, "wxXLocale_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lang", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XLocale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxXLocale_1)
{
	//int lang = arg.GetNumber(0)
	//wxXLocale();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxXLocale_2, "wxXLocale_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XLocale));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxXLocale_2)
{
	//int loc = arg.GetNumber(0)
	//wxXLocale();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_XLocale, __GetCLocale, "GetCLocale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XLocale, __GetCLocale)
{
	Object_wx_XLocale *pThis = Object_wx_XLocale::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCLocale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XLocale, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XLocale, __IsOk)
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
	// Constructor assignment
	Gura_AssignFunction(__wxXLocale);
	Gura_AssignFunction(__wxXLocale_1);
	Gura_AssignFunction(__wxXLocale_2);
	// Method assignment
	Gura_AssignMethod(wx_XLocale, __GetCLocale);
	Gura_AssignMethod(wx_XLocale, __IsOk);
}

Gura_ImplementDescendantCreator(wx_XLocale)
{
	return new Object_wx_XLocale((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
