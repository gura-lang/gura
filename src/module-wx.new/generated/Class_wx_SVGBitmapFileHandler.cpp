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
// Class implementation for wxSVGBitmapFileHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGBitmapFileHandler)
{
}

Gura_ImplementDescendantCreator(wx_SVGBitmapFileHandler)
{
	return new Object_wx_SVGBitmapFileHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
