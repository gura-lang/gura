//----------------------------------------------------------------------------
// wxGridCellBoolRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellBoolRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellBoolRenderer::~Object_wx_GridCellBoolRenderer()
{
}

Object *Object_wx_GridCellBoolRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellBoolRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellBoolRenderer:");
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
Gura_DeclareMethod(wx_GridCellBoolRenderer, wxGridCellBoolRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellBoolRenderer, wxGridCellBoolRenderer)
{
	Object_wx_GridCellBoolRenderer *pThis = Object_wx_GridCellBoolRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellBoolRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellBoolRenderer)
{
	Gura_AssignMethod(wx_GridCellBoolRenderer, wxGridCellBoolRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellBoolRenderer)
{
	return new Object_wx_GridCellBoolRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
