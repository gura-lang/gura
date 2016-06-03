//----------------------------------------------------------------------------
// wxGridCellRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellRenderer::~Object_wx_GridCellRenderer()
{
}

Object *Object_wx_GridCellRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellRenderer:");
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
Gura_DeclareFunctionAlias(__wxGridCellRenderer, "wxGridCellRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxGridCellRenderer)
{
	//wxGridCellRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridCellRenderer, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellRenderer, __Clone)
{
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellRenderer, __Draw, "Draw")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isSelected", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellRenderer, __Draw)
{
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//int row = arg.GetNumber(4)
	//int col = arg.GetNumber(5)
	//int isSelected = arg.GetNumber(6)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellRenderer, __GetBestSize, "GetBestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellRenderer, __GetBestSize)
{
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//pThis->GetEntity()->GetBestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellRenderer, __GetBestHeight, "GetBestHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellRenderer, __GetBestHeight)
{
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//int width = arg.GetNumber(5)
	//pThis->GetEntity()->GetBestHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellRenderer, __GetBestWidth, "GetBestWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellRenderer, __GetBestWidth)
{
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//int height = arg.GetNumber(5)
	//pThis->GetEntity()->GetBestWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxGridCellRenderer);
	// Method assignment
	Gura_AssignMethod(wx_GridCellRenderer, __Clone);
	Gura_AssignMethod(wx_GridCellRenderer, __Draw);
	Gura_AssignMethod(wx_GridCellRenderer, __GetBestSize);
	Gura_AssignMethod(wx_GridCellRenderer, __GetBestHeight);
	Gura_AssignMethod(wx_GridCellRenderer, __GetBestWidth);
}

Gura_ImplementDescendantCreator(wx_GridCellRenderer)
{
	return new Object_wx_GridCellRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
