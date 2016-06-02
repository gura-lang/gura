//----------------------------------------------------------------------------
// wxSVGBitmapFileHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSVGBitmapFileHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSVGBitmapFileHandler
//----------------------------------------------------------------------------
Object_wx_SVGBitmapFileHandler::~Object_wx_SVGBitmapFileHandler()
{
}

Object *Object_wx_SVGBitmapFileHandler::Clone() const
{
	return nullptr;
}

String Object_wx_SVGBitmapFileHandler::ToString(bool exprFlag)
{
	String rtn("<wx.SVGBitmapFileHandler:");
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
Gura_DeclareMethod(wx_SVGBitmapFileHandler, ProcessBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SVGBitmapFileHandler, ProcessBitmap)
{
	Object_wx_SVGBitmapFileHandler *pThis = Object_wx_SVGBitmapFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int stream = arg.GetNumber(3)
	//pThis->GetEntity()->ProcessBitmap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSVGBitmapFileHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGBitmapFileHandler)
{
	Gura_AssignMethod(wx_SVGBitmapFileHandler, ProcessBitmap);
}

Gura_ImplementDescendantCreator(wx_SVGBitmapFileHandler)
{
	return new Object_wx_SVGBitmapFileHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
