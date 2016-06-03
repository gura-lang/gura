//----------------------------------------------------------------------------
// wxPostScriptDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPostScriptDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPostScriptDC
//----------------------------------------------------------------------------
Object_wx_PostScriptDC::~Object_wx_PostScriptDC()
{
}

Object *Object_wx_PostScriptDC::Clone() const
{
	return nullptr;
}

String Object_wx_PostScriptDC::ToString(bool exprFlag)
{
	String rtn("<wx.PostScriptDC:");
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
Gura_DeclareFunctionAlias(__wxPostScriptDC, "wxPostScriptDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxPostScriptDC)
{
	//wxPostScriptDC();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPostScriptDC_1, "wxPostScriptDC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxPostScriptDC_1)
{
	//int printData = arg.GetNumber(0)
	//wxPostScriptDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPostScriptDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PostScriptDC)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPostScriptDC);
	Gura_AssignFunction(__wxPostScriptDC_1);
}

Gura_ImplementDescendantCreator(wx_PostScriptDC)
{
	return new Object_wx_PostScriptDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
