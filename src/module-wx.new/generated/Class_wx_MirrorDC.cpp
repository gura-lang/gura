//----------------------------------------------------------------------------
// wxMirrorDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMirrorDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMirrorDC
//----------------------------------------------------------------------------
Object_wx_MirrorDC::~Object_wx_MirrorDC()
{
}

Object *Object_wx_MirrorDC::Clone() const
{
	return nullptr;
}

String Object_wx_MirrorDC::ToString(bool exprFlag)
{
	String rtn("<wx.MirrorDC:");
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
// Class implementation for wxMirrorDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MirrorDC)
{
}

Gura_ImplementDescendantCreator(wx_MirrorDC)
{
	return new Object_wx_MirrorDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
