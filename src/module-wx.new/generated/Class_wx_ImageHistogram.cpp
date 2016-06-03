//----------------------------------------------------------------------------
// wxImageHistogram
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxImageHistogram
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxImageHistogram
//----------------------------------------------------------------------------
Object_wx_ImageHistogram::~Object_wx_ImageHistogram()
{
}

Object *Object_wx_ImageHistogram::Clone() const
{
	return nullptr;
}

String Object_wx_ImageHistogram::ToString(bool exprFlag)
{
	String rtn("<wx.ImageHistogram:");
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
Gura_DeclareFunctionAlias(__wxImageHistogram, "wxImageHistogram")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxImageHistogram)
{
	//wxImageHistogram();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ImageHistogram, __MakeKey, "MakeKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHistogram, __MakeKey)
{
	Object_wx_ImageHistogram *pThis = Object_wx_ImageHistogram::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int g = arg.GetNumber(1)
	//int b = arg.GetNumber(2)
	//pThis->GetEntity()->MakeKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ImageHistogram, __FindFirstUnusedColour, "FindFirstUnusedColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "g", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startR", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startG", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startB", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ImageHistogram, __FindFirstUnusedColour)
{
	Object_wx_ImageHistogram *pThis = Object_wx_ImageHistogram::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int r = arg.GetNumber(0)
	//int g = arg.GetNumber(1)
	//int b = arg.GetNumber(2)
	//int startR = arg.GetNumber(3)
	//int startG = arg.GetNumber(4)
	//int startB = arg.GetNumber(5)
	//pThis->GetEntity()->FindFirstUnusedColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxImageHistogram
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ImageHistogram)
{
	// Constructor assignment
	Gura_AssignFunction(__wxImageHistogram);
	// Method assignment
	Gura_AssignMethod(wx_ImageHistogram, __MakeKey);
	Gura_AssignMethod(wx_ImageHistogram, __FindFirstUnusedColour);
}

Gura_ImplementDescendantCreator(wx_ImageHistogram)
{
	return new Object_wx_ImageHistogram((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
