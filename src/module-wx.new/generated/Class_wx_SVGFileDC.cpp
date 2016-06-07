//----------------------------------------------------------------------------
// wxSVGFileDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSVGFileDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSVGFileDC
//----------------------------------------------------------------------------
Object_wx_SVGFileDC::~Object_wx_SVGFileDC()
{
}

Object *Object_wx_SVGFileDC::Clone() const
{
	return nullptr;
}

String Object_wx_SVGFileDC::ToString(bool exprFlag)
{
	String rtn("<wx.SVGFileDC:");
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
Gura_DeclareFunctionAlias(__SVGFileDC, "SVGFileDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dpi", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SVGFileDC));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SVGFileDC)
{
	//const wxString& filename = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//double dpi = arg.GetNumber(3)
	//wxSVGFileDC(filename, width, height, dpi);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SVGFileDC, __EndDoc, "EndDoc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SVGFileDC, __EndDoc)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDoc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __EndPage, "EndPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SVGFileDC, __EndPage)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SVGFileDC, __Clear)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __SetBitmapHandler, "SetBitmapHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __SetBitmapHandler)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSVGBitmapHandler* handler = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __SetLogicalFunction, "SetLogicalFunction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __SetLogicalFunction)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRasterOperationMode function = arg.GetNumber(0)
	//pThis->GetEntity()->SetLogicalFunction(function);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __SetClippingRegion, "SetClippingRegion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __SetClippingRegion)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxCoord width = arg.GetNumber(2)
	//wxCoord height = arg.GetNumber(3)
	//pThis->GetEntity()->SetClippingRegion(x, y, width, height);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __SetClippingRegion_1, "SetClippingRegion_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __SetClippingRegion_1)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//const wxSize& sz = arg.GetNumber(1)
	//pThis->GetEntity()->SetClippingRegion(pt, sz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __SetClippingRegion_2, "SetClippingRegion_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __SetClippingRegion_2)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetClippingRegion(rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __SetClippingRegion_3, "SetClippingRegion_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __SetClippingRegion_3)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRegion& region = arg.GetNumber(0)
	//pThis->GetEntity()->SetClippingRegion(region);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __DestroyClippingRegion, "DestroyClippingRegion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SVGFileDC, __DestroyClippingRegion)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DestroyClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __CrossHair, "CrossHair")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __CrossHair)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->CrossHair(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __FloodFill, "FloodFill")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __FloodFill)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//const wxColour& colour = arg.GetNumber(2)
	//wxFloodFillStyle style = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->FloodFill(x, y, colour, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __GetClippingBox, "GetClippingBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __GetClippingBox)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord* x = arg.GetNumber(0)
	//wxCoord* y = arg.GetNumber(1)
	//wxCoord* width = arg.GetNumber(2)
	//wxCoord* height = arg.GetNumber(3)
	//pThis->GetEntity()->GetClippingBox(x, y, width, height);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __GetPixel, "GetPixel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __GetPixel)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxColour* colour = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->GetPixel(x, y, colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __SetPalette, "SetPalette")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __SetPalette)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPalette& palette = arg.GetNumber(0)
	//pThis->GetEntity()->SetPalette(palette);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SVGFileDC, __StartDoc, "StartDoc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, __StartDoc)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& message = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->StartDoc(message);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSVGFileDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGFileDC)
{
	// Constructor assignment
	Gura_AssignFunction(__SVGFileDC);
	// Method assignment
	Gura_AssignMethod(wx_SVGFileDC, __EndDoc);
	Gura_AssignMethod(wx_SVGFileDC, __EndPage);
	Gura_AssignMethod(wx_SVGFileDC, __Clear);
	Gura_AssignMethod(wx_SVGFileDC, __SetBitmapHandler);
	Gura_AssignMethod(wx_SVGFileDC, __SetLogicalFunction);
	Gura_AssignMethod(wx_SVGFileDC, __SetClippingRegion);
	Gura_AssignMethod(wx_SVGFileDC, __SetClippingRegion_1);
	Gura_AssignMethod(wx_SVGFileDC, __SetClippingRegion_2);
	Gura_AssignMethod(wx_SVGFileDC, __SetClippingRegion_3);
	Gura_AssignMethod(wx_SVGFileDC, __DestroyClippingRegion);
	Gura_AssignMethod(wx_SVGFileDC, __CrossHair);
	Gura_AssignMethod(wx_SVGFileDC, __FloodFill);
	Gura_AssignMethod(wx_SVGFileDC, __GetClippingBox);
	Gura_AssignMethod(wx_SVGFileDC, __GetPixel);
	Gura_AssignMethod(wx_SVGFileDC, __SetPalette);
	Gura_AssignMethod(wx_SVGFileDC, __StartDoc);
}

Gura_ImplementDescendantCreator(wx_SVGFileDC)
{
	return new Object_wx_SVGFileDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
