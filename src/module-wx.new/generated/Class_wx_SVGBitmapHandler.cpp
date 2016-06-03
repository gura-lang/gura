//----------------------------------------------------------------------------
// wxSVGBitmapHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSVGBitmapHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSVGBitmapHandler
//----------------------------------------------------------------------------
Object_wx_SVGBitmapHandler::~Object_wx_SVGBitmapHandler()
{
}

Object *Object_wx_SVGBitmapHandler::Clone() const
{
	return nullptr;
}

String Object_wx_SVGBitmapHandler::ToString(bool exprFlag)
{
	String rtn("<wx.SVGBitmapHandler:");
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
Gura_DeclareMethodAlias(wx_SVGBitmapHandler, __ProcessBitmap, "ProcessBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGBitmapHandler, __ProcessBitmap)
{
	Object_wx_SVGBitmapHandler *pThis = Object_wx_SVGBitmapHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int stream = arg.GetNumber(3)
	//pThis->GetEntity()->ProcessBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSVGBitmapHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGBitmapHandler)
{
	// Method assignment
	Gura_AssignMethod(wx_SVGBitmapHandler, __ProcessBitmap);
}

Gura_ImplementDescendantCreator(wx_SVGBitmapHandler)
{
	return new Object_wx_SVGBitmapHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
