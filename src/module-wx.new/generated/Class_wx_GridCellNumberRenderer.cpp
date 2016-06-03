//----------------------------------------------------------------------------
// wxGridCellNumberRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellNumberRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellNumberRenderer::~Object_wx_GridCellNumberRenderer()
{
}

Object *Object_wx_GridCellNumberRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellNumberRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellNumberRenderer:");
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
Gura_DeclareMethodAlias(wx_GridCellNumberRenderer, __wxGridCellNumberRenderer, "wxGridCellNumberRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellNumberRenderer, __wxGridCellNumberRenderer)
{
	Object_wx_GridCellNumberRenderer *pThis = Object_wx_GridCellNumberRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellNumberRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellNumberRenderer)
{
	Gura_AssignMethod(wx_GridCellNumberRenderer, __wxGridCellNumberRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellNumberRenderer)
{
	return new Object_wx_GridCellNumberRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
