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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ColourDatabase, "ColourDatabase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ColourDatabase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ColourDatabase)
{
	//wxColourDatabase();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ColourDatabase, __AddColour, "AddColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colourName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDatabase, __AddColour)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colourName = arg.GetNumber(0)
	//int colour = arg.GetNumber(1)
	//pThis->GetEntity()->AddColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ColourDatabase, __Find, "Find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colourName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDatabase, __Find)
{
	Object_wx_ColourDatabase *pThis = Object_wx_ColourDatabase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colourName = arg.GetNumber(0)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ColourDatabase, __FindName, "FindName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ColourDatabase, __FindName)
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
	// Constructor assignment
	Gura_AssignFunction(__ColourDatabase);
	// Method assignment
	Gura_AssignMethod(wx_ColourDatabase, __AddColour);
	Gura_AssignMethod(wx_ColourDatabase, __Find);
	Gura_AssignMethod(wx_ColourDatabase, __FindName);
}

Gura_ImplementDescendantCreator(wx_ColourDatabase)
{
	return new Object_wx_ColourDatabase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
