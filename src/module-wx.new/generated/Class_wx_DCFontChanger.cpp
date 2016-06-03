//----------------------------------------------------------------------------
// wxDCFontChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCFontChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCFontChanger
//----------------------------------------------------------------------------
Object_wx_DCFontChanger::~Object_wx_DCFontChanger()
{
}

Object *Object_wx_DCFontChanger::Clone() const
{
	return nullptr;
}

String Object_wx_DCFontChanger::ToString(bool exprFlag)
{
	String rtn("<wx.DCFontChanger:");
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
Gura_DeclareMethodAlias(wx_DCFontChanger, __wxDCFontChanger, "wxDCFontChanger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCFontChanger, __wxDCFontChanger)
{
	Object_wx_DCFontChanger *pThis = Object_wx_DCFontChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->wxDCFontChanger();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DCFontChanger, __wxDCFontChanger_1, "wxDCFontChanger_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCFontChanger, __wxDCFontChanger_1)
{
	Object_wx_DCFontChanger *pThis = Object_wx_DCFontChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int font = arg.GetNumber(1)
	//pThis->GetEntity()->wxDCFontChanger();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DCFontChanger, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCFontChanger, __Set)
{
	Object_wx_DCFontChanger *pThis = Object_wx_DCFontChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCFontChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCFontChanger)
{
	Gura_AssignMethod(wx_DCFontChanger, __wxDCFontChanger);
	Gura_AssignMethod(wx_DCFontChanger, __wxDCFontChanger_1);
	Gura_AssignMethod(wx_DCFontChanger, __Set);
}

Gura_ImplementDescendantCreator(wx_DCFontChanger)
{
	return new Object_wx_DCFontChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
