//----------------------------------------------------------------------------
// wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellDateTimeRenderer::~Object_wx_GridCellDateTimeRenderer()
{
}

Object *Object_wx_GridCellDateTimeRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellDateTimeRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellDateTimeRenderer:");
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
Gura_DeclareFunctionAlias(__wxGridCellDateTimeRenderer, "wxGridCellDateTimeRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "outformat", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "informat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGridCellDateTimeRenderer)
{
	//int outformat = arg.GetNumber(0)
	//int informat = arg.GetNumber(1)
	//wxGridCellDateTimeRenderer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridCellDateTimeRenderer, __SetParameters, "SetParameters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellDateTimeRenderer, __SetParameters)
{
	Object_wx_GridCellDateTimeRenderer *pThis = Object_wx_GridCellDateTimeRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int params = arg.GetNumber(0)
	//pThis->GetEntity()->SetParameters();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellDateTimeRenderer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxGridCellDateTimeRenderer);
	// Method assignment
	Gura_AssignMethod(wx_GridCellDateTimeRenderer, __SetParameters);
}

Gura_ImplementDescendantCreator(wx_GridCellDateTimeRenderer)
{
	return new Object_wx_GridCellDateTimeRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
