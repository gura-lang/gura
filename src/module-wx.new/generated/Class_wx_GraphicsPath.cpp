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
Gura_DeclareMethod(wx_GraphicsPath, AddArc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startAngle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endAngle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clockwise", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddArc)
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

Gura_DeclareMethod(wx_GraphicsPath, AddArc_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "startAngle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endAngle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clockwise", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddArc_1)
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

Gura_DeclareMethod(wx_GraphicsPath, AddArcToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddArcToPoint)
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

Gura_DeclareMethod(wx_GraphicsPath, AddCircle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "r", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddCircle)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int r = arg.GetNumber(2)
	//pThis->GetEntity()->AddCircle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, AddCurveToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cx1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cy1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cx2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cy2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddCurveToPoint)
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

Gura_DeclareMethod(wx_GraphicsPath, AddCurveToPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "c2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "e", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddCurveToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c1 = arg.GetNumber(0)
	//int c2 = arg.GetNumber(1)
	//int e = arg.GetNumber(2)
	//pThis->GetEntity()->AddCurveToPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, AddEllipse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddEllipse)
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

Gura_DeclareMethod(wx_GraphicsPath, AddLineToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddLineToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->AddLineToPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, AddLineToPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddLineToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->AddLineToPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, AddPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddPath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->AddPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, AddQuadCurveToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddQuadCurveToPoint)
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

Gura_DeclareMethod(wx_GraphicsPath, AddRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddRectangle)
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

Gura_DeclareMethod(wx_GraphicsPath, AddRoundedRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, AddRoundedRectangle)
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

Gura_DeclareMethod(wx_GraphicsPath, CloseSubpath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, CloseSubpath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseSubpath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, Contains)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//int fillStyle = arg.GetNumber(1)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, Contains_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, Contains_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int fillStyle = arg.GetNumber(2)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, GetBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, GetBox)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, GetBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, GetBox_1)
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

Gura_DeclareMethod(wx_GraphicsPath, GetCurrentPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, GetCurrentPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetCurrentPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, GetCurrentPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, GetCurrentPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, GetNativePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsPath, GetNativePath)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNativePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, MoveToPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, MoveToPoint)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->MoveToPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, MoveToPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, MoveToPoint_1)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->MoveToPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, Transform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "matrix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, Transform)
{
	Object_wx_GraphicsPath *pThis = Object_wx_GraphicsPath::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int matrix = arg.GetNumber(0)
	//pThis->GetEntity()->Transform();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsPath, UnGetNativePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsPath, UnGetNativePath)
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
	Gura_AssignMethod(wx_GraphicsPath, AddArc);
	Gura_AssignMethod(wx_GraphicsPath, AddArc_1);
	Gura_AssignMethod(wx_GraphicsPath, AddArcToPoint);
	Gura_AssignMethod(wx_GraphicsPath, AddCircle);
	Gura_AssignMethod(wx_GraphicsPath, AddCurveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, AddCurveToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, AddEllipse);
	Gura_AssignMethod(wx_GraphicsPath, AddLineToPoint);
	Gura_AssignMethod(wx_GraphicsPath, AddLineToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, AddPath);
	Gura_AssignMethod(wx_GraphicsPath, AddQuadCurveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, AddRectangle);
	Gura_AssignMethod(wx_GraphicsPath, AddRoundedRectangle);
	Gura_AssignMethod(wx_GraphicsPath, CloseSubpath);
	Gura_AssignMethod(wx_GraphicsPath, Contains);
	Gura_AssignMethod(wx_GraphicsPath, Contains_1);
	Gura_AssignMethod(wx_GraphicsPath, GetBox);
	Gura_AssignMethod(wx_GraphicsPath, GetBox_1);
	Gura_AssignMethod(wx_GraphicsPath, GetCurrentPoint);
	Gura_AssignMethod(wx_GraphicsPath, GetCurrentPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, GetNativePath);
	Gura_AssignMethod(wx_GraphicsPath, MoveToPoint);
	Gura_AssignMethod(wx_GraphicsPath, MoveToPoint_1);
	Gura_AssignMethod(wx_GraphicsPath, Transform);
	Gura_AssignMethod(wx_GraphicsPath, UnGetNativePath);
}

Gura_ImplementDescendantCreator(wx_GraphicsPath)
{
	return new Object_wx_GraphicsPath((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
