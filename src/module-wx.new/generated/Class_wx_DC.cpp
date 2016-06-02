//----------------------------------------------------------------------------
// wxDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDC
//----------------------------------------------------------------------------
Object_wx_DC::~Object_wx_DC()
{
}

Object *Object_wx_DC::Clone() const
{
	return nullptr;
}

String Object_wx_DC::ToString(bool exprFlag)
{
	String rtn("<wx.DC:");
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
Gura_DeclareMethod(wx_DC, DeviceToLogicalX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->DeviceToLogicalX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalXRel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalXRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->DeviceToLogicalXRel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//pThis->GetEntity()->DeviceToLogicalY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalYRel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalYRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//pThis->GetEntity()->DeviceToLogicalYRel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->LogicalToDeviceX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceXRel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceXRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->LogicalToDeviceXRel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//pThis->GetEntity()->LogicalToDeviceY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceYRel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceYRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//pThis->GetEntity()->LogicalToDeviceYRel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, Clear)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawArc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xEnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yEnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawArc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xStart = arg.GetNumber(0)
	//int yStart = arg.GetNumber(1)
	//int xEnd = arg.GetNumber(2)
	//int yEnd = arg.GetNumber(3)
	//int xc = arg.GetNumber(4)
	//int yc = arg.GetNumber(5)
	//pThis->GetEntity()->DrawArc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawArc_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ptEnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "centre", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawArc_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptStart = arg.GetNumber(0)
	//int ptEnd = arg.GetNumber(1)
	//int centre = arg.GetNumber(2)
	//pThis->GetEntity()->DrawArc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "useMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawBitmap)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int useMask = arg.GetNumber(3)
	//pThis->GetEntity()->DrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawBitmap_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "useMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawBitmap_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//int useMask = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawCheckMark)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCheckMark)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->DrawCheckMark();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawCheckMark_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCheckMark_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->DrawCheckMark();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawCircle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCircle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int radius = arg.GetNumber(2)
	//pThis->GetEntity()->DrawCircle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawCircle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCircle_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int radius = arg.GetNumber(1)
	//pThis->GetEntity()->DrawCircle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipse)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->DrawEllipse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipse_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipse_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->DrawEllipse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipse_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipse_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->DrawEllipse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipticArc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipticArc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//int start = arg.GetNumber(4)
	//int end = arg.GetNumber(5)
	//pThis->GetEntity()->DrawEllipticArc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipticArc_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sa", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ea", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipticArc_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//int sa = arg.GetNumber(2)
	//int ea = arg.GetNumber(3)
	//pThis->GetEntity()->DrawEllipticArc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawIcon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->DrawIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawIcon_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawIcon_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//pThis->GetEntity()->DrawIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indexAccel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rectBounding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawLabel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int alignment = arg.GetNumber(3)
	//int indexAccel = arg.GetNumber(4)
	//int rectBounding = arg.GetNumber(5)
	//pThis->GetEntity()->DrawLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLabel_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indexAccel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawLabel_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int alignment = arg.GetNumber(2)
	//int indexAccel = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawLine)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//int y1 = arg.GetNumber(1)
	//int x2 = arg.GetNumber(2)
	//int y2 = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLine_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawLine_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt1 = arg.GetNumber(0)
	//int pt2 = arg.GetNumber(1)
	//pThis->GetEntity()->DrawLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawLines)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int points = arg.GetNumber(1)
	//int xoffset = arg.GetNumber(2)
	//int yoffset = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLines_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawLines_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int points = arg.GetNumber(0)
	//int xoffset = arg.GetNumber(1)
	//int yoffset = arg.GetNumber(2)
	//pThis->GetEntity()->DrawLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawPoint)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->DrawPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawPoint_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawPoint_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->DrawPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fill_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawPolygon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int points = arg.GetNumber(1)
	//int xoffset = arg.GetNumber(2)
	//int yoffset = arg.GetNumber(3)
	//int fill_style = arg.GetNumber(4)
	//pThis->GetEntity()->DrawPolygon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawPolygon_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fill_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawPolygon_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int points = arg.GetNumber(0)
	//int xoffset = arg.GetNumber(1)
	//int yoffset = arg.GetNumber(2)
	//int fill_style = arg.GetNumber(3)
	//pThis->GetEntity()->DrawPolygon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawPolyPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fill_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawPolyPolygon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//int points = arg.GetNumber(2)
	//int xoffset = arg.GetNumber(3)
	//int yoffset = arg.GetNumber(4)
	//int fill_style = arg.GetNumber(5)
	//pThis->GetEntity()->DrawPolyPolygon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectangle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->DrawRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRectangle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectangle_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//pThis->GetEntity()->DrawRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRectangle_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectangle_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->DrawRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRotatedText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRotatedText)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int angle = arg.GetNumber(3)
	//pThis->GetEntity()->DrawRotatedText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRotatedText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRotatedText_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int point = arg.GetNumber(1)
	//int angle = arg.GetNumber(2)
	//pThis->GetEntity()->DrawRotatedText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRoundedRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectangle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//int radius = arg.GetNumber(4)
	//pThis->GetEntity()->DrawRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRoundedRectangle_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectangle_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//int radius = arg.GetNumber(2)
	//pThis->GetEntity()->DrawRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRoundedRectangle_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectangle_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//int radius = arg.GetNumber(1)
	//pThis->GetEntity()->DrawRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawSpline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawSpline)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int points = arg.GetNumber(1)
	//pThis->GetEntity()->DrawSpline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawSpline_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawSpline_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int points = arg.GetNumber(0)
	//pThis->GetEntity()->DrawSpline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawSpline_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x3", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y3", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawSpline_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x1 = arg.GetNumber(0)
	//int y1 = arg.GetNumber(1)
	//int x2 = arg.GetNumber(2)
	//int y2 = arg.GetNumber(3)
	//int x3 = arg.GetNumber(4)
	//int y3 = arg.GetNumber(5)
	//pThis->GetEntity()->DrawSpline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawText)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawText_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int pt = arg.GetNumber(1)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GradientFillConcentric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GradientFillConcentric)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//int initialColour = arg.GetNumber(1)
	//int destColour = arg.GetNumber(2)
	//pThis->GetEntity()->GradientFillConcentric();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GradientFillConcentric_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "circleCenter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GradientFillConcentric_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//int initialColour = arg.GetNumber(1)
	//int destColour = arg.GetNumber(2)
	//int circleCenter = arg.GetNumber(3)
	//pThis->GetEntity()->GradientFillConcentric();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GradientFillLinear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nDirection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GradientFillLinear)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//int initialColour = arg.GetNumber(1)
	//int destColour = arg.GetNumber(2)
	//int nDirection = arg.GetNumber(3)
	//pThis->GetEntity()->GradientFillLinear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, FloodFill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, FloodFill)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int colour = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->FloodFill();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, FloodFill_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, FloodFill_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->FloodFill();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, CrossHair)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, CrossHair)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->CrossHair();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, CrossHair_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, CrossHair_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->CrossHair();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DestroyClippingRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, DestroyClippingRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DestroyClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetClippingBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetClippingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->GetClippingBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetClippingRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetClippingRegion_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegion_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetClippingRegion_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegion_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetDeviceClippingRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetDeviceClippingRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->SetDeviceClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetCharHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetCharHeight)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCharHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetCharWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetCharWidth)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCharWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetFontMetrics)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetFontMetrics)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontMetrics();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetMultiLineTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightLine", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetMultiLineTextExtent)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//int w = arg.GetNumber(1)
	//int h = arg.GetNumber(2)
	//int heightLine = arg.GetNumber(3)
	//int font = arg.GetNumber(4)
	//pThis->GetEntity()->GetMultiLineTextExtent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetMultiLineTextExtent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetMultiLineTextExtent_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->GetMultiLineTextExtent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetPartialTextExtents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetPartialTextExtents)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int widths = arg.GetNumber(1)
	//pThis->GetEntity()->GetPartialTextExtents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "externalLeading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetTextExtent)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//int w = arg.GetNumber(1)
	//int h = arg.GetNumber(2)
	//int descent = arg.GetNumber(3)
	//int externalLeading = arg.GetNumber(4)
	//int font = arg.GetNumber(5)
	//pThis->GetEntity()->GetTextExtent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetTextExtent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetTextExtent_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextExtent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetBackgroundMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetBackgroundMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetFont)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetLayoutDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetLayoutDirection)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetTextBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetTextBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetTextForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetTextForeground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetBackgroundMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBackgroundMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetFont)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetTextBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetTextBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetTextForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetTextForeground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextForeground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetLayoutDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetLayoutDirection)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, CalcBoundingBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, CalcBoundingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->CalcBoundingBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, MaxX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, MaxX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MaxX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, MaxY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, MaxY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MaxY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, MinX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, MinX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MinX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, MinY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, MinY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MinY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, ResetBoundingBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, ResetBoundingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetBoundingBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, StartDoc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, StartDoc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->StartDoc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, StartPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, StartPage)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StartPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, EndDoc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, EndDoc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDoc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, EndPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, EndPage)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, Blit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xdest", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ydest", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xsrc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ysrc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "logicalFunc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "useMask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xsrcMask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ysrcMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, Blit)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xdest = arg.GetNumber(0)
	//int ydest = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//int source = arg.GetNumber(4)
	//int xsrc = arg.GetNumber(5)
	//int ysrc = arg.GetNumber(6)
	//int logicalFunc = arg.GetNumber(7)
	//int useMask = arg.GetNumber(8)
	//int xsrcMask = arg.GetNumber(9)
	//int ysrcMask = arg.GetNumber(10)
	//pThis->GetEntity()->Blit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, StretchBlit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xdest", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ydest", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstHeight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xsrc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ysrc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcWidth", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "srcHeight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "logicalFunc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "useMask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xsrcMask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ysrcMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, StretchBlit)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xdest = arg.GetNumber(0)
	//int ydest = arg.GetNumber(1)
	//int dstWidth = arg.GetNumber(2)
	//int dstHeight = arg.GetNumber(3)
	//int source = arg.GetNumber(4)
	//int xsrc = arg.GetNumber(5)
	//int ysrc = arg.GetNumber(6)
	//int srcWidth = arg.GetNumber(7)
	//int srcHeight = arg.GetNumber(8)
	//int logicalFunc = arg.GetNumber(9)
	//int useMask = arg.GetNumber(10)
	//int xsrcMask = arg.GetNumber(11)
	//int ysrcMask = arg.GetNumber(12)
	//pThis->GetEntity()->StretchBlit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetBrush)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetPen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetPen)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int brush = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBrush)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int brush = arg.GetNumber(0)
	//pThis->GetEntity()->SetBrush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetPen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetPen)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pen = arg.GetNumber(0)
	//pThis->GetEntity()->SetPen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, CopyAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, CopyAttributes)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->CopyAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetDepth)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDepth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetDeviceOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetDeviceOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDeviceOrigin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetLogicalFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetLogicalFunction)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLogicalFunction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetMapMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetMapMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMapMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetPixel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetPixel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int colour = arg.GetNumber(2)
	//pThis->GetEntity()->GetPixel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetPPI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetPPI)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPPI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetSize)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetSize_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetSizeMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetSizeMM)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//pThis->GetEntity()->GetSizeMM();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetSizeMM_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetSizeMM_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSizeMM();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetUserScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetUserScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetUserScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, IsOk)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetAxisOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xLeftRight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yBottomUp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetAxisOrientation)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xLeftRight = arg.GetNumber(0)
	//int yBottomUp = arg.GetNumber(1)
	//pThis->GetEntity()->SetAxisOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetDeviceOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetDeviceOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetDeviceOrigin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetLogicalFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetLogicalFunction)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int function = arg.GetNumber(0)
	//pThis->GetEntity()->SetLogicalFunction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetMapMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetMapMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMapMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetPalette)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int palette = arg.GetNumber(0)
	//pThis->GetEntity()->SetPalette();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetUserScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetUserScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xScale = arg.GetNumber(0)
	//int yScale = arg.GetNumber(1)
	//pThis->GetEntity()->SetUserScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, CanUseTransformMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, CanUseTransformMatrix)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUseTransformMatrix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetTransformMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "matrix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetTransformMatrix)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int matrix = arg.GetNumber(0)
	//pThis->GetEntity()->SetTransformMatrix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetTransformMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetTransformMatrix)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTransformMatrix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, ResetTransformMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, ResetTransformMatrix)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetTransformMatrix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, CanDrawBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, CanDrawBitmap)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanDrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, CanGetTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, CanGetTextExtent)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanGetTextExtent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetHandle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetAsBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "subrect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetAsBitmap)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int subrect = arg.GetNumber(0)
	//pThis->GetEntity()->GetAsBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetLogicalScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetLogicalScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetLogicalScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetLogicalScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetLogicalScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetLogicalScale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetLogicalOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetLogicalOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetLogicalOrigin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetLogicalOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GetLogicalOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetLogicalOrigin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, GetLogicalOrigin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, GetLogicalOrigin_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLogicalOrigin();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DC)
{
	Gura_AssignMethod(wx_DC, DeviceToLogicalX);
	Gura_AssignMethod(wx_DC, DeviceToLogicalXRel);
	Gura_AssignMethod(wx_DC, DeviceToLogicalY);
	Gura_AssignMethod(wx_DC, DeviceToLogicalYRel);
	Gura_AssignMethod(wx_DC, LogicalToDeviceX);
	Gura_AssignMethod(wx_DC, LogicalToDeviceXRel);
	Gura_AssignMethod(wx_DC, LogicalToDeviceY);
	Gura_AssignMethod(wx_DC, LogicalToDeviceYRel);
	Gura_AssignMethod(wx_DC, Clear);
	Gura_AssignMethod(wx_DC, DrawArc);
	Gura_AssignMethod(wx_DC, DrawArc_1);
	Gura_AssignMethod(wx_DC, DrawBitmap);
	Gura_AssignMethod(wx_DC, DrawBitmap_1);
	Gura_AssignMethod(wx_DC, DrawCheckMark);
	Gura_AssignMethod(wx_DC, DrawCheckMark_1);
	Gura_AssignMethod(wx_DC, DrawCircle);
	Gura_AssignMethod(wx_DC, DrawCircle_1);
	Gura_AssignMethod(wx_DC, DrawEllipse);
	Gura_AssignMethod(wx_DC, DrawEllipse_1);
	Gura_AssignMethod(wx_DC, DrawEllipse_2);
	Gura_AssignMethod(wx_DC, DrawEllipticArc);
	Gura_AssignMethod(wx_DC, DrawEllipticArc_1);
	Gura_AssignMethod(wx_DC, DrawIcon);
	Gura_AssignMethod(wx_DC, DrawIcon_1);
	Gura_AssignMethod(wx_DC, DrawLabel);
	Gura_AssignMethod(wx_DC, DrawLabel_1);
	Gura_AssignMethod(wx_DC, DrawLine);
	Gura_AssignMethod(wx_DC, DrawLine_1);
	Gura_AssignMethod(wx_DC, DrawLines);
	Gura_AssignMethod(wx_DC, DrawLines_1);
	Gura_AssignMethod(wx_DC, DrawPoint);
	Gura_AssignMethod(wx_DC, DrawPoint_1);
	Gura_AssignMethod(wx_DC, DrawPolygon);
	Gura_AssignMethod(wx_DC, DrawPolygon_1);
	Gura_AssignMethod(wx_DC, DrawPolyPolygon);
	Gura_AssignMethod(wx_DC, DrawRectangle);
	Gura_AssignMethod(wx_DC, DrawRectangle_1);
	Gura_AssignMethod(wx_DC, DrawRectangle_2);
	Gura_AssignMethod(wx_DC, DrawRotatedText);
	Gura_AssignMethod(wx_DC, DrawRotatedText_1);
	Gura_AssignMethod(wx_DC, DrawRoundedRectangle);
	Gura_AssignMethod(wx_DC, DrawRoundedRectangle_1);
	Gura_AssignMethod(wx_DC, DrawRoundedRectangle_2);
	Gura_AssignMethod(wx_DC, DrawSpline);
	Gura_AssignMethod(wx_DC, DrawSpline_1);
	Gura_AssignMethod(wx_DC, DrawSpline_2);
	Gura_AssignMethod(wx_DC, DrawText);
	Gura_AssignMethod(wx_DC, DrawText_1);
	Gura_AssignMethod(wx_DC, GradientFillConcentric);
	Gura_AssignMethod(wx_DC, GradientFillConcentric_1);
	Gura_AssignMethod(wx_DC, GradientFillLinear);
	Gura_AssignMethod(wx_DC, FloodFill);
	Gura_AssignMethod(wx_DC, FloodFill_1);
	Gura_AssignMethod(wx_DC, CrossHair);
	Gura_AssignMethod(wx_DC, CrossHair_1);
	Gura_AssignMethod(wx_DC, DestroyClippingRegion);
	Gura_AssignMethod(wx_DC, GetClippingBox);
	Gura_AssignMethod(wx_DC, SetClippingRegion);
	Gura_AssignMethod(wx_DC, SetClippingRegion_1);
	Gura_AssignMethod(wx_DC, SetClippingRegion_2);
	Gura_AssignMethod(wx_DC, SetDeviceClippingRegion);
	Gura_AssignMethod(wx_DC, GetCharHeight);
	Gura_AssignMethod(wx_DC, GetCharWidth);
	Gura_AssignMethod(wx_DC, GetFontMetrics);
	Gura_AssignMethod(wx_DC, GetMultiLineTextExtent);
	Gura_AssignMethod(wx_DC, GetMultiLineTextExtent_1);
	Gura_AssignMethod(wx_DC, GetPartialTextExtents);
	Gura_AssignMethod(wx_DC, GetTextExtent);
	Gura_AssignMethod(wx_DC, GetTextExtent_1);
	Gura_AssignMethod(wx_DC, GetBackgroundMode);
	Gura_AssignMethod(wx_DC, GetFont);
	Gura_AssignMethod(wx_DC, GetLayoutDirection);
	Gura_AssignMethod(wx_DC, GetTextBackground);
	Gura_AssignMethod(wx_DC, GetTextForeground);
	Gura_AssignMethod(wx_DC, SetBackgroundMode);
	Gura_AssignMethod(wx_DC, SetFont);
	Gura_AssignMethod(wx_DC, SetTextBackground);
	Gura_AssignMethod(wx_DC, SetTextForeground);
	Gura_AssignMethod(wx_DC, SetLayoutDirection);
	Gura_AssignMethod(wx_DC, CalcBoundingBox);
	Gura_AssignMethod(wx_DC, MaxX);
	Gura_AssignMethod(wx_DC, MaxY);
	Gura_AssignMethod(wx_DC, MinX);
	Gura_AssignMethod(wx_DC, MinY);
	Gura_AssignMethod(wx_DC, ResetBoundingBox);
	Gura_AssignMethod(wx_DC, StartDoc);
	Gura_AssignMethod(wx_DC, StartPage);
	Gura_AssignMethod(wx_DC, EndDoc);
	Gura_AssignMethod(wx_DC, EndPage);
	Gura_AssignMethod(wx_DC, Blit);
	Gura_AssignMethod(wx_DC, StretchBlit);
	Gura_AssignMethod(wx_DC, GetBackground);
	Gura_AssignMethod(wx_DC, GetBrush);
	Gura_AssignMethod(wx_DC, GetPen);
	Gura_AssignMethod(wx_DC, SetBackground);
	Gura_AssignMethod(wx_DC, SetBrush);
	Gura_AssignMethod(wx_DC, SetPen);
	Gura_AssignMethod(wx_DC, CopyAttributes);
	Gura_AssignMethod(wx_DC, GetDepth);
	Gura_AssignMethod(wx_DC, GetDeviceOrigin);
	Gura_AssignMethod(wx_DC, GetLogicalFunction);
	Gura_AssignMethod(wx_DC, GetMapMode);
	Gura_AssignMethod(wx_DC, GetPixel);
	Gura_AssignMethod(wx_DC, GetPPI);
	Gura_AssignMethod(wx_DC, GetSize);
	Gura_AssignMethod(wx_DC, GetSize_1);
	Gura_AssignMethod(wx_DC, GetSizeMM);
	Gura_AssignMethod(wx_DC, GetSizeMM_1);
	Gura_AssignMethod(wx_DC, GetUserScale);
	Gura_AssignMethod(wx_DC, IsOk);
	Gura_AssignMethod(wx_DC, SetAxisOrientation);
	Gura_AssignMethod(wx_DC, SetDeviceOrigin);
	Gura_AssignMethod(wx_DC, SetLogicalFunction);
	Gura_AssignMethod(wx_DC, SetMapMode);
	Gura_AssignMethod(wx_DC, SetPalette);
	Gura_AssignMethod(wx_DC, SetUserScale);
	Gura_AssignMethod(wx_DC, CanUseTransformMatrix);
	Gura_AssignMethod(wx_DC, SetTransformMatrix);
	Gura_AssignMethod(wx_DC, GetTransformMatrix);
	Gura_AssignMethod(wx_DC, ResetTransformMatrix);
	Gura_AssignMethod(wx_DC, CanDrawBitmap);
	Gura_AssignMethod(wx_DC, CanGetTextExtent);
	Gura_AssignMethod(wx_DC, GetHandle);
	Gura_AssignMethod(wx_DC, GetAsBitmap);
	Gura_AssignMethod(wx_DC, SetLogicalScale);
	Gura_AssignMethod(wx_DC, GetLogicalScale);
	Gura_AssignMethod(wx_DC, SetLogicalOrigin);
	Gura_AssignMethod(wx_DC, GetLogicalOrigin);
	Gura_AssignMethod(wx_DC, GetLogicalOrigin_1);
}

Gura_ImplementDescendantCreator(wx_DC)
{
	return new Object_wx_DC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
