//----------------------------------------------------------------------------
// wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
Object_wx_GridRowHeaderRendererDefault::~Object_wx_GridRowHeaderRendererDefault()
{
}

Object *Object_wx_GridRowHeaderRendererDefault::Clone() const
{
	return nullptr;
}

String Object_wx_GridRowHeaderRendererDefault::ToString(bool exprFlag)
{
	String rtn("<wx.GridRowHeaderRendererDefault:");
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
Gura_DeclareMethodAlias(wx_GridRowHeaderRendererDefault, __DrawBorder, "DrawBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridRowHeaderRendererDefault, __DrawBorder)
{
	Object_wx_GridRowHeaderRendererDefault *pThis = Object_wx_GridRowHeaderRendererDefault::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBorder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridRowHeaderRendererDefault)
{
	// Class assignment
	Gura_AssignValueEx("GridRowHeaderRendererDefault", Reference());
	// Method assignment
	Gura_AssignMethod(wx_GridRowHeaderRendererDefault, __DrawBorder);
}

Gura_ImplementDescendantCreator(wx_GridRowHeaderRendererDefault)
{
	return new Object_wx_GridRowHeaderRendererDefault((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
