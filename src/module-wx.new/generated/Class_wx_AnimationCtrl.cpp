//----------------------------------------------------------------------------
// wxAnimationCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnimationCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnimationCtrl
//----------------------------------------------------------------------------
Object_wx_AnimationCtrl::~Object_wx_AnimationCtrl()
{
}

Object *Object_wx_AnimationCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_AnimationCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.AnimationCtrl:");
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
// Class implementation for wxAnimationCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnimationCtrl)
{
}

Gura_ImplementDescendantCreator(wx_AnimationCtrl)
{
	return new Object_wx_AnimationCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
