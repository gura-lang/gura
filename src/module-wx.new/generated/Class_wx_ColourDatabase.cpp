//----------------------------------------------------------------------------
// wxColourDatabase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourDatabase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColourDatabase
//----------------------------------------------------------------------------
Object_wx_ColourDatabase::~Object_wx_ColourDatabase()
{
}

Object *Object_wx_ColourDatabase::Clone() const
{
	return nullptr;
}

String Object_wx_ColourDatabase::ToString(bool exprFlag)
{
	String rtn("<wx.ColourDatabase:");
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
Gura_DeclareMethod(wx_ColourDatabase, wxColourDatabase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ColourDatabase, wxColourDatabase)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxColourDatabase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourDatabase, AddColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colourName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDatabase, AddColour)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colourName = arg.GetNumber(0)
	//int colour = arg.GetNumber(1)
	//pThis->GetEntity()->AddColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourDatabase, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colourName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDatabase, Find)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colourName = arg.GetNumber(0)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ColourDatabase, FindName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDatabase, FindName)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->FindName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxColourDatabase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourDatabase)
{
	Gura_AssignMethod(wx_ColourDatabase, wxColourDatabase);
	Gura_AssignMethod(wx_ColourDatabase, AddColour);
	Gura_AssignMethod(wx_ColourDatabase, Find);
	Gura_AssignMethod(wx_ColourDatabase, FindName);
}

Gura_ImplementDescendantCreator(wx_ColourDatabase)
{
	return new Object_wx_ColourDatabase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
