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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PaintDC, wxPaintDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PaintDC, wxPaintDC)
{
	Object_wx_PaintDC *pThis = Object_wx_PaintDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->wxPaintDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPaintDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaintDC)
{
	Gura_AssignMethod(wx_PaintDC, wxPaintDC);
}

Gura_ImplementDescendantCreator(wx_PaintDC)
{
	return new Object_wx_PaintDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
