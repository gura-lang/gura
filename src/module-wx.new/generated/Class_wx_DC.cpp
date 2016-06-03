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
Gura_DeclareMethodAlias(wx_DC, __DeviceToLogicalX, "DeviceToLogicalX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DeviceToLogicalX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//pThis->GetEntity()->DeviceToLogicalX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DeviceToLogicalXRel, "DeviceToLogicalXRel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DeviceToLogicalXRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//pThis->GetEntity()->DeviceToLogicalXRel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DeviceToLogicalY, "DeviceToLogicalY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DeviceToLogicalY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord y = arg.GetNumber(0)
	//pThis->GetEntity()->DeviceToLogicalY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DeviceToLogicalYRel, "DeviceToLogicalYRel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DeviceToLogicalYRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord y = arg.GetNumber(0)
	//pThis->GetEntity()->DeviceToLogicalYRel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __LogicalToDeviceX, "LogicalToDeviceX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __LogicalToDeviceX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//pThis->GetEntity()->LogicalToDeviceX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __LogicalToDeviceXRel, "LogicalToDeviceXRel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __LogicalToDeviceXRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//pThis->GetEntity()->LogicalToDeviceXRel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __LogicalToDeviceY, "LogicalToDeviceY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __LogicalToDeviceY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord y = arg.GetNumber(0)
	//pThis->GetEntity()->LogicalToDeviceY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __LogicalToDeviceYRel, "LogicalToDeviceYRel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __LogicalToDeviceYRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord y = arg.GetNumber(0)
	//pThis->GetEntity()->LogicalToDeviceYRel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __Clear)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawArc, "DrawArc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xEnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yEnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawArc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord xStart = arg.GetNumber(0)
	//wxCoord yStart = arg.GetNumber(1)
	//wxCoord xEnd = arg.GetNumber(2)
	//wxCoord yEnd = arg.GetNumber(3)
	//wxCoord xc = arg.GetNumber(4)
	//wxCoord yc = arg.GetNumber(5)
	//pThis->GetEntity()->DrawArc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawArc_1, "DrawArc_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ptEnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "centre", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawArc_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& ptStart = arg.GetNumber(0)
	//const wxPoint& ptEnd = arg.GetNumber(1)
	//const wxPoint& centre = arg.GetNumber(2)
	//pThis->GetEntity()->DrawArc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawBitmap, "DrawBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "useMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawBitmap)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//wxCoord x = arg.GetNumber(1)
	//wxCoord y = arg.GetNumber(2)
	//bool useMask = arg.GetNumber(3)
	//pThis->GetEntity()->DrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawBitmap_1, "DrawBitmap_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "useMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawBitmap_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//const wxPoint& pt = arg.GetNumber(1)
	//bool useMask = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawCheckMark, "DrawCheckMark")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawCheckMark)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->DrawCheckMark();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawCheckMark_1, "DrawCheckMark_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawCheckMark_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->DrawCheckMark();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawCircle, "DrawCircle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawCircle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord radius = arg.GetNumber(2)
	//pThis->GetEntity()->DrawCircle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawCircle_1, "DrawCircle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawCircle_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//wxCoord radius = arg.GetNumber(1)
	//pThis->GetEntity()->DrawCircle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawEllipse, "DrawEllipse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawEllipse)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->DrawEllipse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawEllipse_1, "DrawEllipse_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawEllipse_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//const wxSize& size = arg.GetNumber(1)
	//pThis->GetEntity()->DrawEllipse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawEllipse_2, "DrawEllipse_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawEllipse_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->DrawEllipse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawEllipticArc, "DrawEllipticArc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawEllipticArc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//double start = arg.GetNumber(4)
	//double end = arg.GetNumber(5)
	//pThis->GetEntity()->DrawEllipticArc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawEllipticArc_1, "DrawEllipticArc_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sa", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ea", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawEllipticArc_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//const wxSize& sz = arg.GetNumber(1)
	//double sa = arg.GetNumber(2)
	//double ea = arg.GetNumber(3)
	//pThis->GetEntity()->DrawEllipticArc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawIcon, "DrawIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawIcon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//wxCoord x = arg.GetNumber(1)
	//wxCoord y = arg.GetNumber(2)
	//pThis->GetEntity()->DrawIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawIcon_1, "DrawIcon_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawIcon_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//const wxPoint& pt = arg.GetNumber(1)
	//pThis->GetEntity()->DrawIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawLabel, "DrawLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indexAccel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rectBounding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawLabel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int alignment = arg.GetNumber(3)
	//int indexAccel = arg.GetNumber(4)
	//wxRect* rectBounding = arg.GetNumber(5)
	//pThis->GetEntity()->DrawLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawLabel_1, "DrawLabel_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indexAccel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawLabel_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//int alignment = arg.GetNumber(2)
	//int indexAccel = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawLine, "DrawLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawLine)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x1 = arg.GetNumber(0)
	//wxCoord y1 = arg.GetNumber(1)
	//wxCoord x2 = arg.GetNumber(2)
	//wxCoord y2 = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawLine_1, "DrawLine_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawLine_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt1 = arg.GetNumber(0)
	//const wxPoint& pt2 = arg.GetNumber(1)
	//pThis->GetEntity()->DrawLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawLines, "DrawLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawLines)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//const wxPoint points = arg.GetNumber(1)
	//wxCoord xoffset = arg.GetNumber(2)
	//wxCoord yoffset = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawLines_1, "DrawLines_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawLines_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPointList* points = arg.GetNumber(0)
	//wxCoord xoffset = arg.GetNumber(1)
	//wxCoord yoffset = arg.GetNumber(2)
	//pThis->GetEntity()->DrawLines();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawPoint, "DrawPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawPoint)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->DrawPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawPoint_1, "DrawPoint_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawPoint_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->DrawPoint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawPolygon, "DrawPolygon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fill_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawPolygon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//const wxPoint points = arg.GetNumber(1)
	//wxCoord xoffset = arg.GetNumber(2)
	//wxCoord yoffset = arg.GetNumber(3)
	//wxPolygonFillMode fill_style = arg.GetNumber(4)
	//pThis->GetEntity()->DrawPolygon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawPolygon_1, "DrawPolygon_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fill_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawPolygon_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPointList* points = arg.GetNumber(0)
	//wxCoord xoffset = arg.GetNumber(1)
	//wxCoord yoffset = arg.GetNumber(2)
	//wxPolygonFillMode fill_style = arg.GetNumber(3)
	//pThis->GetEntity()->DrawPolygon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawPolyPolygon, "DrawPolyPolygon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yoffset", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fill_style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawPolyPolygon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//const int count = arg.GetNumber(1)
	//const wxPoint points = arg.GetNumber(2)
	//wxCoord xoffset = arg.GetNumber(3)
	//wxCoord yoffset = arg.GetNumber(4)
	//wxPolygonFillMode fill_style = arg.GetNumber(5)
	//pThis->GetEntity()->DrawPolyPolygon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawRectangle, "DrawRectangle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawRectangle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->DrawRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawRectangle_1, "DrawRectangle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawRectangle_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//const wxSize& sz = arg.GetNumber(1)
	//pThis->GetEntity()->DrawRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawRectangle_2, "DrawRectangle_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawRectangle_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->DrawRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawRotatedText, "DrawRotatedText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawRotatedText)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxCoord x = arg.GetNumber(1)
	//wxCoord y = arg.GetNumber(2)
	//double angle = arg.GetNumber(3)
	//pThis->GetEntity()->DrawRotatedText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawRotatedText_1, "DrawRotatedText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawRotatedText_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//const wxPoint& point = arg.GetNumber(1)
	//double angle = arg.GetNumber(2)
	//pThis->GetEntity()->DrawRotatedText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawRoundedRectangle, "DrawRoundedRectangle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawRoundedRectangle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//double radius = arg.GetNumber(4)
	//pThis->GetEntity()->DrawRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawRoundedRectangle_1, "DrawRoundedRectangle_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawRoundedRectangle_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//const wxSize& sz = arg.GetNumber(1)
	//double radius = arg.GetNumber(2)
	//pThis->GetEntity()->DrawRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawRoundedRectangle_2, "DrawRoundedRectangle_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawRoundedRectangle_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//double radius = arg.GetNumber(1)
	//pThis->GetEntity()->DrawRoundedRectangle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawSpline, "DrawSpline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawSpline)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//const wxPoint points = arg.GetNumber(1)
	//pThis->GetEntity()->DrawSpline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawSpline_1, "DrawSpline_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "points", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawSpline_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPointList* points = arg.GetNumber(0)
	//pThis->GetEntity()->DrawSpline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawSpline_2, "DrawSpline_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x3", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y3", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawSpline_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x1 = arg.GetNumber(0)
	//wxCoord y1 = arg.GetNumber(1)
	//wxCoord x2 = arg.GetNumber(2)
	//wxCoord y2 = arg.GetNumber(3)
	//wxCoord x3 = arg.GetNumber(4)
	//wxCoord y3 = arg.GetNumber(5)
	//pThis->GetEntity()->DrawSpline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawText, "DrawText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawText)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxCoord x = arg.GetNumber(1)
	//wxCoord y = arg.GetNumber(2)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DrawText_1, "DrawText_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __DrawText_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//const wxPoint& pt = arg.GetNumber(1)
	//pThis->GetEntity()->DrawText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GradientFillConcentric, "GradientFillConcentric")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GradientFillConcentric)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//const wxColour& initialColour = arg.GetNumber(1)
	//const wxColour& destColour = arg.GetNumber(2)
	//pThis->GetEntity()->GradientFillConcentric();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GradientFillConcentric_1, "GradientFillConcentric_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "circleCenter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GradientFillConcentric_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//const wxColour& initialColour = arg.GetNumber(1)
	//const wxColour& destColour = arg.GetNumber(2)
	//const wxPoint& circleCenter = arg.GetNumber(3)
	//pThis->GetEntity()->GradientFillConcentric();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GradientFillLinear, "GradientFillLinear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "destColour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nDirection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GradientFillLinear)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//const wxColour& initialColour = arg.GetNumber(1)
	//const wxColour& destColour = arg.GetNumber(2)
	//wxDirection nDirection = arg.GetNumber(3)
	//pThis->GetEntity()->GradientFillLinear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __FloodFill, "FloodFill")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __FloodFill)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//const wxColour& colour = arg.GetNumber(2)
	//wxFloodFillStyle style = arg.GetNumber(3)
	//pThis->GetEntity()->FloodFill();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __FloodFill_1, "FloodFill_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __FloodFill_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//const wxColour& col = arg.GetNumber(1)
	//wxFloodFillStyle style = arg.GetNumber(2)
	//pThis->GetEntity()->FloodFill();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __CrossHair, "CrossHair")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __CrossHair)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->CrossHair();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __CrossHair_1, "CrossHair_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __CrossHair_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->CrossHair();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __DestroyClippingRegion, "DestroyClippingRegion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __DestroyClippingRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DestroyClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetClippingBox, "GetClippingBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetClippingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord* x = arg.GetNumber(0)
	//wxCoord* y = arg.GetNumber(1)
	//wxCoord* width = arg.GetNumber(2)
	//wxCoord* height = arg.GetNumber(3)
	//pThis->GetEntity()->GetClippingBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetClippingRegion, "SetClippingRegion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetClippingRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetClippingRegion_1, "SetClippingRegion_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetClippingRegion_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//const wxSize& sz = arg.GetNumber(1)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetClippingRegion_2, "SetClippingRegion_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetClippingRegion_2)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetDeviceClippingRegion, "SetDeviceClippingRegion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetDeviceClippingRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->SetDeviceClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetCharHeight, "GetCharHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetCharHeight)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCharHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetCharWidth, "GetCharWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetCharWidth)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCharWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetFontMetrics, "GetFontMetrics")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetFontMetrics)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFontMetrics();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetMultiLineTextExtent, "GetMultiLineTextExtent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightLine", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetMultiLineTextExtent)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//wxCoord* w = arg.GetNumber(1)
	//wxCoord* h = arg.GetNumber(2)
	//wxCoord* heightLine = arg.GetNumber(3)
	//const wxFont* font = arg.GetNumber(4)
	//pThis->GetEntity()->GetMultiLineTextExtent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetMultiLineTextExtent_1, "GetMultiLineTextExtent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetMultiLineTextExtent_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//pThis->GetEntity()->GetMultiLineTextExtent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetPartialTextExtents, "GetPartialTextExtents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetPartialTextExtents)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxArrayInt& widths = arg.GetNumber(1)
	//pThis->GetEntity()->GetPartialTextExtents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetTextExtent, "GetTextExtent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "externalLeading", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetTextExtent)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//wxCoord* w = arg.GetNumber(1)
	//wxCoord* h = arg.GetNumber(2)
	//wxCoord* descent = arg.GetNumber(3)
	//wxCoord* externalLeading = arg.GetNumber(4)
	//const wxFont* font = arg.GetNumber(5)
	//pThis->GetEntity()->GetTextExtent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetTextExtent_1, "GetTextExtent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetTextExtent_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextExtent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetBackgroundMode, "GetBackgroundMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetBackgroundMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetFont)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetLayoutDirection, "GetLayoutDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetLayoutDirection)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutDirection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetTextBackground, "GetTextBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetTextBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetTextForeground, "GetTextForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetTextForeground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetBackgroundMode, "SetBackgroundMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetBackgroundMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetFont)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetTextBackground, "SetTextBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetTextBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetTextForeground, "SetTextForeground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetTextForeground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextForeground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetLayoutDirection, "SetLayoutDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetLayoutDirection)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxLayoutDirection dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutDirection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __CalcBoundingBox, "CalcBoundingBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __CalcBoundingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->CalcBoundingBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __MaxX, "MaxX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __MaxX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MaxX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __MaxY, "MaxY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __MaxY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MaxY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __MinX, "MinX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __MinX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MinX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __MinY, "MinY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __MinY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MinY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __ResetBoundingBox, "ResetBoundingBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __ResetBoundingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetBoundingBox();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __StartDoc, "StartDoc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __StartDoc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& message = arg.GetNumber(0)
	//pThis->GetEntity()->StartDoc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __StartPage, "StartPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __StartPage)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->StartPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __EndDoc, "EndDoc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __EndDoc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDoc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __EndPage, "EndPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __EndPage)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __Blit, "Blit")
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

Gura_ImplementMethod(wx_DC, __Blit)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord xdest = arg.GetNumber(0)
	//wxCoord ydest = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//wxDC* source = arg.GetNumber(4)
	//wxCoord xsrc = arg.GetNumber(5)
	//wxCoord ysrc = arg.GetNumber(6)
	//wxRasterOperationMode logicalFunc = arg.GetNumber(7)
	//bool useMask = arg.GetNumber(8)
	//wxCoord xsrcMask = arg.GetNumber(9)
	//wxCoord ysrcMask = arg.GetNumber(10)
	//pThis->GetEntity()->Blit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __StretchBlit, "StretchBlit")
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

Gura_ImplementMethod(wx_DC, __StretchBlit)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord xdest = arg.GetNumber(0)
	//wxCoord ydest = arg.GetNumber(1)
	//wxCoord dstWidth = arg.GetNumber(2)
	//wxCoord dstHeight = arg.GetNumber(3)
	//wxDC* source = arg.GetNumber(4)
	//wxCoord xsrc = arg.GetNumber(5)
	//wxCoord ysrc = arg.GetNumber(6)
	//wxCoord srcWidth = arg.GetNumber(7)
	//wxCoord srcHeight = arg.GetNumber(8)
	//wxRasterOperationMode logicalFunc = arg.GetNumber(9)
	//bool useMask = arg.GetNumber(10)
	//wxCoord xsrcMask = arg.GetNumber(11)
	//wxCoord ysrcMask = arg.GetNumber(12)
	//pThis->GetEntity()->StretchBlit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetBackground, "GetBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetBrush, "GetBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetBrush)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetPen, "GetPen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetPen)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetBackground, "SetBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBrush& brush = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetBrush, "SetBrush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "brush", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetBrush)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBrush& brush = arg.GetNumber(0)
	//pThis->GetEntity()->SetBrush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetPen, "SetPen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetPen)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPen& pen = arg.GetNumber(0)
	//pThis->GetEntity()->SetPen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __CopyAttributes, "CopyAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __CopyAttributes)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDC& dc = arg.GetNumber(0)
	//pThis->GetEntity()->CopyAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetDepth, "GetDepth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetDepth)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDepth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetDeviceOrigin, "GetDeviceOrigin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetDeviceOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDeviceOrigin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetLogicalFunction, "GetLogicalFunction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetLogicalFunction)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLogicalFunction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetMapMode, "GetMapMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetMapMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMapMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetPixel, "GetPixel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetPixel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxColour* colour = arg.GetNumber(2)
	//pThis->GetEntity()->GetPixel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetPPI, "GetPPI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetPPI)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPPI();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetSize)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord* width = arg.GetNumber(0)
	//wxCoord* height = arg.GetNumber(1)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetSize_1, "GetSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetSize_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetSizeMM, "GetSizeMM")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetSizeMM)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord* width = arg.GetNumber(0)
	//wxCoord* height = arg.GetNumber(1)
	//pThis->GetEntity()->GetSizeMM();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetSizeMM_1, "GetSizeMM_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetSizeMM_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSizeMM();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetUserScale, "GetUserScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetUserScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double* x = arg.GetNumber(0)
	//double* y = arg.GetNumber(1)
	//pThis->GetEntity()->GetUserScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __IsOk)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetAxisOrientation, "SetAxisOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xLeftRight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yBottomUp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetAxisOrientation)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool xLeftRight = arg.GetNumber(0)
	//bool yBottomUp = arg.GetNumber(1)
	//pThis->GetEntity()->SetAxisOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetDeviceOrigin, "SetDeviceOrigin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetDeviceOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->SetDeviceOrigin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetLogicalFunction, "SetLogicalFunction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetLogicalFunction)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRasterOperationMode function = arg.GetNumber(0)
	//pThis->GetEntity()->SetLogicalFunction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetMapMode, "SetMapMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetMapMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMappingMode mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMapMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetPalette, "SetPalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetPalette)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPalette& palette = arg.GetNumber(0)
	//pThis->GetEntity()->SetPalette();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetUserScale, "SetUserScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetUserScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double xScale = arg.GetNumber(0)
	//double yScale = arg.GetNumber(1)
	//pThis->GetEntity()->SetUserScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __CanUseTransformMatrix, "CanUseTransformMatrix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __CanUseTransformMatrix)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanUseTransformMatrix();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetTransformMatrix, "SetTransformMatrix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "matrix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetTransformMatrix)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAffineMatrix2D& matrix = arg.GetNumber(0)
	//pThis->GetEntity()->SetTransformMatrix();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetTransformMatrix, "GetTransformMatrix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetTransformMatrix)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTransformMatrix();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __ResetTransformMatrix, "ResetTransformMatrix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __ResetTransformMatrix)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetTransformMatrix();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __CanDrawBitmap, "CanDrawBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __CanDrawBitmap)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanDrawBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __CanGetTextExtent, "CanGetTextExtent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __CanGetTextExtent)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanGetTextExtent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetHandle, "GetHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetHandle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHandle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetAsBitmap, "GetAsBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "subrect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetAsBitmap)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect* subrect = arg.GetNumber(0)
	//pThis->GetEntity()->GetAsBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetLogicalScale, "SetLogicalScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetLogicalScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double x = arg.GetNumber(0)
	//double y = arg.GetNumber(1)
	//pThis->GetEntity()->SetLogicalScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetLogicalScale, "GetLogicalScale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetLogicalScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double* x = arg.GetNumber(0)
	//double* y = arg.GetNumber(1)
	//pThis->GetEntity()->GetLogicalScale();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __SetLogicalOrigin, "SetLogicalOrigin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __SetLogicalOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->SetLogicalOrigin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetLogicalOrigin, "GetLogicalOrigin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, __GetLogicalOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord* x = arg.GetNumber(0)
	//wxCoord* y = arg.GetNumber(1)
	//pThis->GetEntity()->GetLogicalOrigin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DC, __GetLogicalOrigin_1, "GetLogicalOrigin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, __GetLogicalOrigin_1)
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
	// Class assignment
	Gura_AssignValueEx("DC", Reference());
	// Method assignment
	Gura_AssignMethod(wx_DC, __DeviceToLogicalX);
	Gura_AssignMethod(wx_DC, __DeviceToLogicalXRel);
	Gura_AssignMethod(wx_DC, __DeviceToLogicalY);
	Gura_AssignMethod(wx_DC, __DeviceToLogicalYRel);
	Gura_AssignMethod(wx_DC, __LogicalToDeviceX);
	Gura_AssignMethod(wx_DC, __LogicalToDeviceXRel);
	Gura_AssignMethod(wx_DC, __LogicalToDeviceY);
	Gura_AssignMethod(wx_DC, __LogicalToDeviceYRel);
	Gura_AssignMethod(wx_DC, __Clear);
	Gura_AssignMethod(wx_DC, __DrawArc);
	Gura_AssignMethod(wx_DC, __DrawArc_1);
	Gura_AssignMethod(wx_DC, __DrawBitmap);
	Gura_AssignMethod(wx_DC, __DrawBitmap_1);
	Gura_AssignMethod(wx_DC, __DrawCheckMark);
	Gura_AssignMethod(wx_DC, __DrawCheckMark_1);
	Gura_AssignMethod(wx_DC, __DrawCircle);
	Gura_AssignMethod(wx_DC, __DrawCircle_1);
	Gura_AssignMethod(wx_DC, __DrawEllipse);
	Gura_AssignMethod(wx_DC, __DrawEllipse_1);
	Gura_AssignMethod(wx_DC, __DrawEllipse_2);
	Gura_AssignMethod(wx_DC, __DrawEllipticArc);
	Gura_AssignMethod(wx_DC, __DrawEllipticArc_1);
	Gura_AssignMethod(wx_DC, __DrawIcon);
	Gura_AssignMethod(wx_DC, __DrawIcon_1);
	Gura_AssignMethod(wx_DC, __DrawLabel);
	Gura_AssignMethod(wx_DC, __DrawLabel_1);
	Gura_AssignMethod(wx_DC, __DrawLine);
	Gura_AssignMethod(wx_DC, __DrawLine_1);
	Gura_AssignMethod(wx_DC, __DrawLines);
	Gura_AssignMethod(wx_DC, __DrawLines_1);
	Gura_AssignMethod(wx_DC, __DrawPoint);
	Gura_AssignMethod(wx_DC, __DrawPoint_1);
	Gura_AssignMethod(wx_DC, __DrawPolygon);
	Gura_AssignMethod(wx_DC, __DrawPolygon_1);
	Gura_AssignMethod(wx_DC, __DrawPolyPolygon);
	Gura_AssignMethod(wx_DC, __DrawRectangle);
	Gura_AssignMethod(wx_DC, __DrawRectangle_1);
	Gura_AssignMethod(wx_DC, __DrawRectangle_2);
	Gura_AssignMethod(wx_DC, __DrawRotatedText);
	Gura_AssignMethod(wx_DC, __DrawRotatedText_1);
	Gura_AssignMethod(wx_DC, __DrawRoundedRectangle);
	Gura_AssignMethod(wx_DC, __DrawRoundedRectangle_1);
	Gura_AssignMethod(wx_DC, __DrawRoundedRectangle_2);
	Gura_AssignMethod(wx_DC, __DrawSpline);
	Gura_AssignMethod(wx_DC, __DrawSpline_1);
	Gura_AssignMethod(wx_DC, __DrawSpline_2);
	Gura_AssignMethod(wx_DC, __DrawText);
	Gura_AssignMethod(wx_DC, __DrawText_1);
	Gura_AssignMethod(wx_DC, __GradientFillConcentric);
	Gura_AssignMethod(wx_DC, __GradientFillConcentric_1);
	Gura_AssignMethod(wx_DC, __GradientFillLinear);
	Gura_AssignMethod(wx_DC, __FloodFill);
	Gura_AssignMethod(wx_DC, __FloodFill_1);
	Gura_AssignMethod(wx_DC, __CrossHair);
	Gura_AssignMethod(wx_DC, __CrossHair_1);
	Gura_AssignMethod(wx_DC, __DestroyClippingRegion);
	Gura_AssignMethod(wx_DC, __GetClippingBox);
	Gura_AssignMethod(wx_DC, __SetClippingRegion);
	Gura_AssignMethod(wx_DC, __SetClippingRegion_1);
	Gura_AssignMethod(wx_DC, __SetClippingRegion_2);
	Gura_AssignMethod(wx_DC, __SetDeviceClippingRegion);
	Gura_AssignMethod(wx_DC, __GetCharHeight);
	Gura_AssignMethod(wx_DC, __GetCharWidth);
	Gura_AssignMethod(wx_DC, __GetFontMetrics);
	Gura_AssignMethod(wx_DC, __GetMultiLineTextExtent);
	Gura_AssignMethod(wx_DC, __GetMultiLineTextExtent_1);
	Gura_AssignMethod(wx_DC, __GetPartialTextExtents);
	Gura_AssignMethod(wx_DC, __GetTextExtent);
	Gura_AssignMethod(wx_DC, __GetTextExtent_1);
	Gura_AssignMethod(wx_DC, __GetBackgroundMode);
	Gura_AssignMethod(wx_DC, __GetFont);
	Gura_AssignMethod(wx_DC, __GetLayoutDirection);
	Gura_AssignMethod(wx_DC, __GetTextBackground);
	Gura_AssignMethod(wx_DC, __GetTextForeground);
	Gura_AssignMethod(wx_DC, __SetBackgroundMode);
	Gura_AssignMethod(wx_DC, __SetFont);
	Gura_AssignMethod(wx_DC, __SetTextBackground);
	Gura_AssignMethod(wx_DC, __SetTextForeground);
	Gura_AssignMethod(wx_DC, __SetLayoutDirection);
	Gura_AssignMethod(wx_DC, __CalcBoundingBox);
	Gura_AssignMethod(wx_DC, __MaxX);
	Gura_AssignMethod(wx_DC, __MaxY);
	Gura_AssignMethod(wx_DC, __MinX);
	Gura_AssignMethod(wx_DC, __MinY);
	Gura_AssignMethod(wx_DC, __ResetBoundingBox);
	Gura_AssignMethod(wx_DC, __StartDoc);
	Gura_AssignMethod(wx_DC, __StartPage);
	Gura_AssignMethod(wx_DC, __EndDoc);
	Gura_AssignMethod(wx_DC, __EndPage);
	Gura_AssignMethod(wx_DC, __Blit);
	Gura_AssignMethod(wx_DC, __StretchBlit);
	Gura_AssignMethod(wx_DC, __GetBackground);
	Gura_AssignMethod(wx_DC, __GetBrush);
	Gura_AssignMethod(wx_DC, __GetPen);
	Gura_AssignMethod(wx_DC, __SetBackground);
	Gura_AssignMethod(wx_DC, __SetBrush);
	Gura_AssignMethod(wx_DC, __SetPen);
	Gura_AssignMethod(wx_DC, __CopyAttributes);
	Gura_AssignMethod(wx_DC, __GetDepth);
	Gura_AssignMethod(wx_DC, __GetDeviceOrigin);
	Gura_AssignMethod(wx_DC, __GetLogicalFunction);
	Gura_AssignMethod(wx_DC, __GetMapMode);
	Gura_AssignMethod(wx_DC, __GetPixel);
	Gura_AssignMethod(wx_DC, __GetPPI);
	Gura_AssignMethod(wx_DC, __GetSize);
	Gura_AssignMethod(wx_DC, __GetSize_1);
	Gura_AssignMethod(wx_DC, __GetSizeMM);
	Gura_AssignMethod(wx_DC, __GetSizeMM_1);
	Gura_AssignMethod(wx_DC, __GetUserScale);
	Gura_AssignMethod(wx_DC, __IsOk);
	Gura_AssignMethod(wx_DC, __SetAxisOrientation);
	Gura_AssignMethod(wx_DC, __SetDeviceOrigin);
	Gura_AssignMethod(wx_DC, __SetLogicalFunction);
	Gura_AssignMethod(wx_DC, __SetMapMode);
	Gura_AssignMethod(wx_DC, __SetPalette);
	Gura_AssignMethod(wx_DC, __SetUserScale);
	Gura_AssignMethod(wx_DC, __CanUseTransformMatrix);
	Gura_AssignMethod(wx_DC, __SetTransformMatrix);
	Gura_AssignMethod(wx_DC, __GetTransformMatrix);
	Gura_AssignMethod(wx_DC, __ResetTransformMatrix);
	Gura_AssignMethod(wx_DC, __CanDrawBitmap);
	Gura_AssignMethod(wx_DC, __CanGetTextExtent);
	Gura_AssignMethod(wx_DC, __GetHandle);
	Gura_AssignMethod(wx_DC, __GetAsBitmap);
	Gura_AssignMethod(wx_DC, __SetLogicalScale);
	Gura_AssignMethod(wx_DC, __GetLogicalScale);
	Gura_AssignMethod(wx_DC, __SetLogicalOrigin);
	Gura_AssignMethod(wx_DC, __GetLogicalOrigin);
	Gura_AssignMethod(wx_DC, __GetLogicalOrigin_1);
}

Gura_ImplementDescendantCreator(wx_DC)
{
	return new Object_wx_DC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
