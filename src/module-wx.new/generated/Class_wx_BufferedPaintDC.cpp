//----------------------------------------------------------------------------
// wxBufferedPaintDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedPaintDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedPaintDC
//----------------------------------------------------------------------------
Object_wx_BufferedPaintDC::~Object_wx_BufferedPaintDC()
{
}

Object *Object_wx_BufferedPaintDC::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedPaintDC::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedPaintDC:");
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
Gura_DeclareFunctionAlias(__BufferedPaintDC, "BufferedPaintDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BufferedPaintDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BufferedPaintDC)
{
	//wxWindow* window = arg.GetNumber(0)
	//wxBitmap& buffer = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//wxBufferedPaintDC(window, buffer, style);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BufferedPaintDC_1, "BufferedPaintDC_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BufferedPaintDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BufferedPaintDC_1)
{
	//wxWindow* window = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//wxBufferedPaintDC(window, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedPaintDC)
{
	// Constructor assignment
	Gura_AssignFunction(__BufferedPaintDC);
	Gura_AssignFunction(__BufferedPaintDC_1);
}

Gura_ImplementDescendantCreator(wx_BufferedPaintDC)
{
	return new Object_wx_BufferedPaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
