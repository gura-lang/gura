//----------------------------------------------------------------------------
// wxGraphicsFont
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsFont
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsFont
//----------------------------------------------------------------------------
Object_wx_GraphicsFont::~Object_wx_GraphicsFont()
{
}

Object *Object_wx_GraphicsFont::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsFont::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsFont:");
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
// Class implementation for wxGraphicsFont
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsFont)
{
	// Class assignment
	Gura_AssignValueEx("GraphicsFont", Reference());
}

Gura_ImplementDescendantCreator(wx_GraphicsFont)
{
	return new Object_wx_GraphicsFont((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
