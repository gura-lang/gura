//----------------------------------------------------------------------------
// wxGraphicsPath
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsPath
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsPath
//----------------------------------------------------------------------------
Object_wx_GraphicsPath::~Object_wx_GraphicsPath()
{
}

Object *Object_wx_GraphicsPath::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsPath::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsPath:");
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
Gura_DeclareMethodAlias(wx_GraphicsPath, __AddArc, "AddArc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startAngle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endAngle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clockwise", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddArc)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int r = arg.GetNumber(2)
	//int startAngle = arg.GetNumber(3)
	//int endAngle = arg.GetNumber(4)
	//int clockwise = arg.GetNumber(5)
	//pThis->GetEntity()->AddArc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddArc_1, "AddArc_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startAngle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endAngle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clockwise", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddArc_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//int r = arg.GetNumber(1)
	//int startAngle = arg.GetNumber(2)
	//int endAngle = arg.GetNumber(3)
	//int clockwise = arg.GetNumber(4)
	//pThis->GetEntity()->AddArc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddArcToPoint, "AddArcToPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddArcToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//int y1 = arg.GetNumber(1)
	//int x2 = arg.GetNumber(2)
	//int y2 = arg.GetNumber(3)
	//int r = arg.GetNumber(4)
	//pThis->GetEntity()->AddArcToPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddCircle, "AddCircle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddCircle)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int r = arg.GetNumber(2)
	//pThis->GetEntity()->AddCircle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddCurveToPoint, "AddCurveToPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cx1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cy1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cx2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cy2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddCurveToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cx1 = arg.GetNumber(0)
	//int cy1 = arg.GetNumber(1)
	//int cx2 = arg.GetNumber(2)
	//int cy2 = arg.GetNumber(3)
	//int x = arg.GetNumber(4)
	//int y = arg.GetNumber(5)
	//pThis->GetEntity()->AddCurveToPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddCurveToPoint_1, "AddCurveToPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "e", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddCurveToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c1 = arg.GetNumber(0)
	//int c2 = arg.GetNumber(1)
	//int e = arg.GetNumber(2)
	//pThis->GetEntity()->AddCurveToPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddEllipse, "AddEllipse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddEllipse)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//pThis->GetEntity()->AddEllipse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddLineToPoint, "AddLineToPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddLineToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->AddLineToPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddLineToPoint_1, "AddLineToPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddLineToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->AddLineToPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddPath, "AddPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddPath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->AddPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddQuadCurveToPoint, "AddQuadCurveToPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddQuadCurveToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cx = arg.GetNumber(0)
	//int cy = arg.GetNumber(1)
	//int x = arg.GetNumber(2)
	//int y = arg.GetNumber(3)
	//pThis->GetEntity()->AddQuadCurveToPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddRectangle, "AddRectangle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddRectangle)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//pThis->GetEntity()->AddRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __AddRoundedRectangle, "AddRoundedRectangle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __AddRoundedRectangle)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//int radius = arg.GetNumber(4)
	//pThis->GetEntity()->AddRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __CloseSubpath, "CloseSubpath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, __CloseSubpath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseSubpath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __Contains, "Contains")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __Contains)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//int fillStyle = arg.GetNumber(1)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __Contains_1, "Contains_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __Contains_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int fillStyle = arg.GetNumber(2)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __GetBox, "GetBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, __GetBox)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __GetBox_1, "GetBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __GetBox_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int w = arg.GetNumber(2)
	//int h = arg.GetNumber(3)
	//pThis->GetEntity()->GetBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __GetCurrentPoint, "GetCurrentPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __GetCurrentPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetCurrentPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __GetCurrentPoint_1, "GetCurrentPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, __GetCurrentPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __GetNativePath, "GetNativePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, __GetNativePath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNativePath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __MoveToPoint, "MoveToPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __MoveToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->MoveToPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __MoveToPoint_1, "MoveToPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __MoveToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __Transform, "Transform")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "matrix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __Transform)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int matrix = arg.GetNumber(0)
	//pThis->GetEntity()->Transform();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsPath, __UnGetNativePath, "UnGetNativePath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, __UnGetNativePath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->UnGetNativePath();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsPath
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsPath)
{
	// Method assignment
	Gura_AssignMethod(wx_GraphicsPath, __AddArc);
	Gura_AssignMethod(wx_GraphicsPath, __AddArc_1);
	Gura_AssignMethod(wx_GraphicsPath, __AddArcToPoint);
	Gura_AssignMethod(wx_GraphicsPath, __AddCircle);
	Gura_AssignMethod(wx_GraphicsPath, __AddCurveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, __AddCurveToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, __AddEllipse);
	Gura_AssignMethod(wx_GraphicsPath, __AddLineToPoint);
	Gura_AssignMethod(wx_GraphicsPath, __AddLineToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, __AddPath);
	Gura_AssignMethod(wx_GraphicsPath, __AddQuadCurveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, __AddRectangle);
	Gura_AssignMethod(wx_GraphicsPath, __AddRoundedRectangle);
	Gura_AssignMethod(wx_GraphicsPath, __CloseSubpath);
	Gura_AssignMethod(wx_GraphicsPath, __Contains);
	Gura_AssignMethod(wx_GraphicsPath, __Contains_1);
	Gura_AssignMethod(wx_GraphicsPath, __GetBox);
	Gura_AssignMethod(wx_GraphicsPath, __GetBox_1);
	Gura_AssignMethod(wx_GraphicsPath, __GetCurrentPoint);
	Gura_AssignMethod(wx_GraphicsPath, __GetCurrentPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, __GetNativePath);
	Gura_AssignMethod(wx_GraphicsPath, __MoveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, __MoveToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, __Transform);
	Gura_AssignMethod(wx_GraphicsPath, __UnGetNativePath);
}

Gura_ImplementDescendantCreator(wx_GraphicsPath)
{
	return new Object_wx_GraphicsPath((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
