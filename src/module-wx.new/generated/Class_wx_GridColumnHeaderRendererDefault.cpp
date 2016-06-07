//----------------------------------------------------------------------------
// wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
Object_wx_GridColumnHeaderRendererDefault::~Object_wx_GridColumnHeaderRendererDefault()
{
}

Object *Object_wx_GridColumnHeaderRendererDefault::Clone() const
{
	return nullptr;
}

String Object_wx_GridColumnHeaderRendererDefault::ToString(bool exprFlag)
{
	String rtn("<wx.GridColumnHeaderRendererDefault:");
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
Gura_DeclareMethodAlias(wx_GridColumnHeaderRendererDefault, __DrawBorder, "DrawBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridColumnHeaderRendererDefault, __DrawBorder)
{
	Object_wx_GridColumnHeaderRendererDefault *pThis = Object_wx_GridColumnHeaderRendererDefault::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGrid& grid = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBorder(grid, dc, rect);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridColumnHeaderRendererDefault)
{
	// Class assignment
	Gura_AssignValueEx("GridColumnHeaderRendererDefault", Reference());
	// Method assignment
	Gura_AssignMethod(wx_GridColumnHeaderRendererDefault, __DrawBorder);
}

Gura_ImplementDescendantCreator(wx_GridColumnHeaderRendererDefault)
{
	return new Object_wx_GridColumnHeaderRendererDefault((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
