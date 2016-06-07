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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GridCellBoolRenderer, "GridCellBoolRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellBoolRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridCellBoolRenderer)
{
	//wxGridCellBoolRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellBoolRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__GridCellBoolRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellBoolRenderer)
{
	return new Object_wx_GridCellBoolRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
