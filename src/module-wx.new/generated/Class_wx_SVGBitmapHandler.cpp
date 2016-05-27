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
// Class implementation for wxSVGBitmapHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGBitmapHandler)
{
}

Gura_ImplementDescendantCreator(wx_SVGBitmapHandler)
{
	return new Object_wx_SVGBitmapHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
