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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_SVGFileDC, wxSVGFileDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dpi", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, wxSVGFileDC)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int height = arg.GetNumber(2)
	//int dpi = arg.GetNumber(3)
	//pThis->GetEntity()->wxSVGFileDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, EndDoc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SVGFileDC, EndDoc)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndDoc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, EndPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SVGFileDC, EndPage)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SVGFileDC, Clear)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, SetBitmapHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, SetBitmapHandler)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmapHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, SetLogicalFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, SetLogicalFunction)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int function = arg.GetNumber(0)
	//pThis->GetEntity()->SetLogicalFunction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, SetClippingRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, SetClippingRegion)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, SetClippingRegion_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, SetClippingRegion_1)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, SetClippingRegion_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, SetClippingRegion_2)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, SetClippingRegion_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, SetClippingRegion_3)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int region = arg.GetNumber(0)
	//pThis->GetEntity()->SetClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, DestroyClippingRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SVGFileDC, DestroyClippingRegion)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DestroyClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, CrossHair)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, CrossHair)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->CrossHair();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, FloodFill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, FloodFill)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int colour = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->FloodFill();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, GetClippingBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, GetClippingBox)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//int height = arg.GetNumber(3)
	//pThis->GetEntity()->GetClippingBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, GetPixel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, GetPixel)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//int colour = arg.GetNumber(2)
	//pThis->GetEntity()->GetPixel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, SetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "palette", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, SetPalette)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int palette = arg.GetNumber(0)
	//pThis->GetEntity()->SetPalette();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SVGFileDC, StartDoc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGFileDC, StartDoc)
{
	Object_wx_SVGFileDC *pThis = Object_wx_SVGFileDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->StartDoc();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSVGFileDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGFileDC)
{
	Gura_AssignMethod(wx_SVGFileDC, wxSVGFileDC);
	Gura_AssignMethod(wx_SVGFileDC, EndDoc);
	Gura_AssignMethod(wx_SVGFileDC, EndPage);
	Gura_AssignMethod(wx_SVGFileDC, Clear);
	Gura_AssignMethod(wx_SVGFileDC, SetBitmapHandler);
	Gura_AssignMethod(wx_SVGFileDC, SetLogicalFunction);
	Gura_AssignMethod(wx_SVGFileDC, SetClippingRegion);
	Gura_AssignMethod(wx_SVGFileDC, SetClippingRegion_1);
	Gura_AssignMethod(wx_SVGFileDC, SetClippingRegion_2);
	Gura_AssignMethod(wx_SVGFileDC, SetClippingRegion_3);
	Gura_AssignMethod(wx_SVGFileDC, DestroyClippingRegion);
	Gura_AssignMethod(wx_SVGFileDC, CrossHair);
	Gura_AssignMethod(wx_SVGFileDC, FloodFill);
	Gura_AssignMethod(wx_SVGFileDC, GetClippingBox);
	Gura_AssignMethod(wx_SVGFileDC, GetPixel);
	Gura_AssignMethod(wx_SVGFileDC, SetPalette);
	Gura_AssignMethod(wx_SVGFileDC, StartDoc);
}

Gura_ImplementDescendantCreator(wx_SVGFileDC)
{
	return new Object_wx_SVGFileDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
