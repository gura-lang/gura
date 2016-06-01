//----------------------------------------------------------------------------
// wxWithImages
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWithImages
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWithImages
//----------------------------------------------------------------------------
Object_wx_WithImages::~Object_wx_WithImages()
{
}

Object *Object_wx_WithImages::Clone() const
{
	return nullptr;
}

String Object_wx_WithImages::ToString(bool exprFlag)
{
	String rtn("<wx.WithImages:");
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
// Class implementation for wxWithImages
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WithImages)
{
	
}

Gura_ImplementDescendantCreator(wx_WithImages)
{
	return new Object_wx_WithImages((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
