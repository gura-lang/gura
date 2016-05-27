//----------------------------------------------------------------------------
// wxGraphicsMatrix
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsMatrix
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsMatrix
//----------------------------------------------------------------------------
Object_wx_GraphicsMatrix::~Object_wx_GraphicsMatrix()
{
}

Object *Object_wx_GraphicsMatrix::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsMatrix::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsMatrix:");
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
// Class implementation for wxGraphicsMatrix
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsMatrix)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsMatrix)
{
	return new Object_wx_GraphicsMatrix((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
