//----------------------------------------------------------------------------
// wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
Object_wx_GridCornerHeaderRendererDefault::~Object_wx_GridCornerHeaderRendererDefault()
{
}

Object *Object_wx_GridCornerHeaderRendererDefault::Clone() const
{
	return nullptr;
}

String Object_wx_GridCornerHeaderRendererDefault::ToString(bool exprFlag)
{
	String rtn("<wx.GridCornerHeaderRendererDefault:");
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
Gura_DeclareMethodAlias(wx_GridCornerHeaderRendererDefault, __DrawBorder, "DrawBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCornerHeaderRendererDefault, __DrawBorder)
{
	Object_wx_GridCornerHeaderRendererDefault *pThis = Object_wx_GridCornerHeaderRendererDefault::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBorder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCornerHeaderRendererDefault)
{
	Gura_AssignMethod(wx_GridCornerHeaderRendererDefault, __DrawBorder);
}

Gura_ImplementDescendantCreator(wx_GridCornerHeaderRendererDefault)
{
	return new Object_wx_GridCornerHeaderRendererDefault((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
