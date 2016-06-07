//----------------------------------------------------------------------------
// wxConfigPathChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConfigPathChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConfigPathChanger
//----------------------------------------------------------------------------
Object_wx_ConfigPathChanger::~Object_wx_ConfigPathChanger()
{
}

Object *Object_wx_ConfigPathChanger::Clone() const
{
	return nullptr;
}

String Object_wx_ConfigPathChanger::ToString(bool exprFlag)
{
	String rtn("<wx.ConfigPathChanger:");
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
Gura_DeclareFunctionAlias(__ConfigPathChanger, "ConfigPathChanger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pContainer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strEntry", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ConfigPathChanger));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ConfigPathChanger)
{
	//const wxConfigBase* pContainer = arg.GetNumber(0)
	//const wxString& strEntry = arg.GetNumber(1)
	//wxConfigPathChanger(pContainer, strEntry);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ConfigPathChanger, __Name, "Name")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigPathChanger, __Name)
{
	Object_wx_ConfigPathChanger *pThis = Object_wx_ConfigPathChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->Name();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ConfigPathChanger, __UpdateIfDeleted, "UpdateIfDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigPathChanger, __UpdateIfDeleted)
{
	Object_wx_ConfigPathChanger *pThis = Object_wx_ConfigPathChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpdateIfDeleted();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxConfigPathChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConfigPathChanger)
{
	// Constructor assignment
	Gura_AssignFunction(__ConfigPathChanger);
	// Method assignment
	Gura_AssignMethod(wx_ConfigPathChanger, __Name);
	Gura_AssignMethod(wx_ConfigPathChanger, __UpdateIfDeleted);
}

Gura_ImplementDescendantCreator(wx_ConfigPathChanger)
{
	return new Object_wx_ConfigPathChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
