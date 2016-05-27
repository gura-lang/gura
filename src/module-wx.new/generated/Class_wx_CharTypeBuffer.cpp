//----------------------------------------------------------------------------
// wxCharTypeBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCharTypeBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCharTypeBuffer
//----------------------------------------------------------------------------
Object_wx_CharTypeBuffer::~Object_wx_CharTypeBuffer()
{
}

Object *Object_wx_CharTypeBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_CharTypeBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.CharTypeBuffer:");
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
// Class implementation for wxCharTypeBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CharTypeBuffer)
{
}

Gura_ImplementDescendantCreator(wx_CharTypeBuffer)
{
	return new Object_wx_CharTypeBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
