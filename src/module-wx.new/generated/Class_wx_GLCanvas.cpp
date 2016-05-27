//----------------------------------------------------------------------------
// wxGLCanvas
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLCanvas
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLCanvas
//----------------------------------------------------------------------------
Object_wx_GLCanvas::~Object_wx_GLCanvas()
{
}

Object *Object_wx_GLCanvas::Clone() const
{
	return nullptr;
}

String Object_wx_GLCanvas::ToString(bool exprFlag)
{
	String rtn("<wx.GLCanvas:");
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
// Class implementation for wxGLCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLCanvas)
{
}

Gura_ImplementDescendantCreator(wx_GLCanvas)
{
	return new Object_wx_GLCanvas((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
