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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridCellRenderer, wxGridCellRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellRenderer, wxGridCellRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellRenderer, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellRenderer, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellRenderer, Draw)
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

Gura_ImplementMethod(wx_GridCellRenderer, Draw)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_GridCellRenderer, GetBestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellRenderer, GetBestSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//pThis->GetEntity()->GetBestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellRenderer, GetBestHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellRenderer, GetBestHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//int width = arg.GetNumber(5)
	//pThis->GetEntity()->GetBestHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellRenderer, GetBestWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellRenderer, GetBestWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int grid = arg.GetNumber(0)
	//int attr = arg.GetNumber(1)
	//int dc = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//int height = arg.GetNumber(5)
	//pThis->GetEntity()->GetBestWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellRenderer, ~wxGridCellRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellRenderer, ~wxGridCellRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellRenderer *pThis = Object_wx_GridCellRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxGridCellRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellRenderer)
{
	Gura_AssignMethod(wx_GridCellRenderer, wxGridCellRenderer);
	Gura_AssignMethod(wx_GridCellRenderer, Clone);
	Gura_AssignMethod(wx_GridCellRenderer, Draw);
	Gura_AssignMethod(wx_GridCellRenderer, GetBestSize);
	Gura_AssignMethod(wx_GridCellRenderer, GetBestHeight);
	Gura_AssignMethod(wx_GridCellRenderer, GetBestWidth);
	Gura_AssignMethod(wx_GridCellRenderer, ~wxGridCellRenderer);
}

Gura_ImplementDescendantCreator(wx_GridCellRenderer)
{
	return new Object_wx_GridCellRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
