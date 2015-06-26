//----------------------------------------------------------------------------
// wxCoord
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCoord
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCoord
//----------------------------------------------------------------------------
Object_wx_Coord::~Object_wx_Coord()
{
}

Object *Object_wx_Coord::Clone() const
{
	return new Object_wx_Coord(*this);
}

String Object_wx_Coord::ToString(bool exprFlag)
{
	String rtn("<wx.Coord:");
	char buff[64];
	::sprintf(buff, "%p>", GetEntity());
	rtn += buff;
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxCoord
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Coord)
{
	
	
}

Gura_ImplementDescendantCreator(wx_Coord)
{
	return new Object_wx_Coord((pClass == nullptr)? this : pClass, nullptr);
}

Gura_EndModuleScope(wx)
