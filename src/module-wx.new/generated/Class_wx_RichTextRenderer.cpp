//----------------------------------------------------------------------------
// wxRichTextRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextRenderer
//----------------------------------------------------------------------------
Object_wx_RichTextRenderer::~Object_wx_RichTextRenderer()
{
}

Object *Object_wx_RichTextRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextRenderer:");
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
// Class implementation for wxRichTextRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextRenderer)
{
}

Gura_ImplementDescendantCreator(wx_RichTextRenderer)
{
	return new Object_wx_RichTextRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
