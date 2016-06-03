//----------------------------------------------------------------------------
// wxGridCellStringRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellStringRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellStringRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellStringRenderer::~Object_wx_GridCellStringRenderer()
{
}

Object *Object_wx_GridCellStringRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellStringRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellStringRenderer:");
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
Gura_DeclareMethodAlias(wx_GridCellStringRenderer, __wxGridCellStringRenderer, "wxGridCellStringRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellStringRenderer, __wxGridCellStringRenderer)
{
	Object_wx_GridCellStringRenderer *pThis = Object_wx_GridCellStringRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellStringRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellStringRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellStringRenderer)
{
	Gura_AssignMethod(wx_GridCellStringRenderer, __wxGridCellStringRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellStringRenderer)
{
	return new Object_wx_GridCellStringRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
