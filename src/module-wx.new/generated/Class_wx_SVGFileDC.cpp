//----------------------------------------------------------------------------
// wxSVGFileDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSVGFileDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSVGFileDC
//----------------------------------------------------------------------------
Object_wx_SVGFileDC::~Object_wx_SVGFileDC()
{
}

Object *Object_wx_SVGFileDC::Clone() const
{
	return nullptr;
}

String Object_wx_SVGFileDC::ToString(bool exprFlag)
{
	String rtn("<wx.SVGFileDC:");
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
// Class implementation for wxSVGFileDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SVGFileDC)
{
}

Gura_ImplementDescendantCreator(wx_SVGFileDC)
{
	return new Object_wx_SVGFileDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
