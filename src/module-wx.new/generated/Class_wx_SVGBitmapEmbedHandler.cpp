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

//----------------------------------------------------------------------------
// Class implementation for wxSVGBitmapEmbedHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGBitmapEmbedHandler)
{
}

Gura_ImplementDescendantCreator(wx_SVGBitmapEmbedHandler)
{
	return new Object_wx_SVGBitmapEmbedHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
