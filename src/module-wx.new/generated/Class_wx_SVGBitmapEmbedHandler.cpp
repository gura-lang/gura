//----------------------------------------------------------------------------
// wxSVGBitmapEmbedHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSVGBitmapEmbedHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSVGBitmapEmbedHandler
//----------------------------------------------------------------------------
Object_wx_SVGBitmapEmbedHandler::~Object_wx_SVGBitmapEmbedHandler()
{
}

Object *Object_wx_SVGBitmapEmbedHandler::Clone() const
{
	return nullptr;
}

String Object_wx_SVGBitmapEmbedHandler::ToString(bool exprFlag)
{
	String rtn("<wx.SVGBitmapEmbedHandler:");
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
Gura_DeclareMethodAlias(wx_SVGBitmapEmbedHandler, __ProcessBitmap, "ProcessBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGBitmapEmbedHandler, __ProcessBitmap)
{
	Object_wx_SVGBitmapEmbedHandler *pThis = Object_wx_SVGBitmapEmbedHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//wxCoord x = arg.GetNumber(1)
	//wxCoord y = arg.GetNumber(2)
	//wxOutputStream& stream = arg.GetNumber(3)
	//pThis->GetEntity()->ProcessBitmap(bitmap, x, y, stream);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSVGBitmapEmbedHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGBitmapEmbedHandler)
{
	// Class assignment
	Gura_AssignValueEx("SVGBitmapEmbedHandler", Reference());
	// Method assignment
	Gura_AssignMethod(wx_SVGBitmapEmbedHandler, __ProcessBitmap);
}

Gura_ImplementDescendantCreator(wx_SVGBitmapEmbedHandler)
{
	return new Object_wx_SVGBitmapEmbedHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
