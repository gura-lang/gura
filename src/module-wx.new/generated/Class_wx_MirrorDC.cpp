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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__MirrorDC, "MirrorDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mirror", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MirrorDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MirrorDC)
{
	//wxDC& dc = arg.GetNumber(0)
	//bool mirror = arg.GetNumber(1)
	//wxMirrorDC(dc, mirror);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMirrorDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MirrorDC)
{
	// Constructor assignment
	Gura_AssignFunction(__MirrorDC);
}

Gura_ImplementDescendantCreator(wx_MirrorDC)
{
	return new Object_wx_MirrorDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
