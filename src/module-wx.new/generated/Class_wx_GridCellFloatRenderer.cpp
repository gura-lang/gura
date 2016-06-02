//----------------------------------------------------------------------------
// wxGridCellFloatRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellFloatRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
Object_wx_GridCellFloatRenderer::~Object_wx_GridCellFloatRenderer()
{
}

Object *Object_wx_GridCellFloatRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellFloatRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellFloatRenderer:");
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
Gura_DeclareMethod(wx_GridCellFloatRenderer, wxGridCellFloatRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, wxGridCellFloatRenderer)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int precision = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->wxGridCellFloatRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, GetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, GetFormat)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, GetPrecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, GetPrecision)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrecision();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, GetWidth)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetFormat)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetParameters)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int params = arg.GetNumber(0)
	//pThis->GetEntity()->SetParameters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetPrecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetPrecision)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int precision = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrecision();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellFloatRenderer, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellFloatRenderer, SetWidth)
{
	Object_wx_GridCellFloatRenderer *pThis = Object_wx_GridCellFloatRenderer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellFloatRenderer)
{
	Gura_AssignMethod(wx_GridCellFloatRenderer, wxGridCellFloatRenderer);
	Gura_AssignMethod(wx_GridCellFloatRenderer, GetFormat);
	Gura_AssignMethod(wx_GridCellFloatRenderer, GetPrecision);
	Gura_AssignMethod(wx_GridCellFloatRenderer, GetWidth);
	Gura_AssignMethod(wx_GridCellFloatRenderer, SetFormat);
	Gura_AssignMethod(wx_GridCellFloatRenderer, SetParameters);
	Gura_AssignMethod(wx_GridCellFloatRenderer, SetPrecision);
	Gura_AssignMethod(wx_GridCellFloatRenderer, SetWidth);
}

Gura_ImplementDescendantCreator(wx_GridCellFloatRenderer)
{
	return new Object_wx_GridCellFloatRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
