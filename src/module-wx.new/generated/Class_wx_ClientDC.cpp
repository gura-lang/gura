//----------------------------------------------------------------------------
// wxClientDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClientDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClientDC
//----------------------------------------------------------------------------
Object_wx_ClientDC::~Object_wx_ClientDC()
{
}

Object *Object_wx_ClientDC::Clone() const
{
	return nullptr;
}

String Object_wx_ClientDC::ToString(bool exprFlag)
{
	String rtn("<wx.ClientDC:");
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
Gura_DeclareFunctionAlias(__ClientDC, "ClientDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ClientDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ClientDC)
{
	//wxWindow* window = arg.GetNumber(0)
	//wxClientDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClientDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientDC)
{
	// Constructor assignment
	Gura_AssignFunction(__ClientDC);
}

Gura_ImplementDescendantCreator(wx_ClientDC)
{
	return new Object_wx_ClientDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
