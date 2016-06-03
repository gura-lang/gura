//----------------------------------------------------------------------------
// wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellAutoWrapStringRenderer::~Object_wx_GridCellAutoWrapStringRenderer()
{
}

Object *Object_wx_GridCellAutoWrapStringRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAutoWrapStringRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAutoWrapStringRenderer:");
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
Gura_DeclareFunctionAlias(__wxGridCellAutoWrapStringRenderer, "wxGridCellAutoWrapStringRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellAutoWrapStringRenderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxGridCellAutoWrapStringRenderer)
{
	//wxGridCellAutoWrapStringRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAutoWrapStringRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxGridCellAutoWrapStringRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellAutoWrapStringRenderer)
{
	return new Object_wx_GridCellAutoWrapStringRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
