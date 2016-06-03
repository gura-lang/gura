//----------------------------------------------------------------------------
// wxPaintDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPaintDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPaintDC
//----------------------------------------------------------------------------
Object_wx_PaintDC::~Object_wx_PaintDC()
{
}

Object *Object_wx_PaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_PaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.PaintDC:");
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
Gura_DeclareFunctionAlias(__PaintDC, "PaintDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PaintDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PaintDC)
{
	//wxWindow* window = arg.GetNumber(0)
	//wxPaintDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintDC)
{
	// Constructor assignment
	Gura_AssignFunction(__PaintDC);
}

Gura_ImplementDescendantCreator(wx_PaintDC)
{
	return new Object_wx_PaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
