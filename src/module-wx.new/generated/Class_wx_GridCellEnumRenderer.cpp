//----------------------------------------------------------------------------
// wxGridCellEnumRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellEnumRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellEnumRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellEnumRenderer::~Object_wx_GridCellEnumRenderer()
{
}

Object *Object_wx_GridCellEnumRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellEnumRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellEnumRenderer:");
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
Gura_DeclareMethod(wx_GridCellEnumRenderer, wxGridCellEnumRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEnumRenderer, wxGridCellEnumRenderer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEnumRenderer *pThis = Object_wx_GridCellEnumRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int choices = arg.GetNumber(0)
	//pThis->GetEntity()->wxGridCellEnumRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellEnumRenderer, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellEnumRenderer, SetParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridCellEnumRenderer *pThis = Object_wx_GridCellEnumRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int params = arg.GetNumber(0)
	//pThis->GetEntity()->SetParameters();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellEnumRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellEnumRenderer)
{
	Gura_AssignMethod(wx_GridCellEnumRenderer, wxGridCellEnumRenderer);
	Gura_AssignMethod(wx_GridCellEnumRenderer, SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellEnumRenderer)
{
	return new Object_wx_GridCellEnumRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
