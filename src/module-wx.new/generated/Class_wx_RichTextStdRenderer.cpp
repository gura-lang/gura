//----------------------------------------------------------------------------
// wxRichTextStdRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStdRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStdRenderer
//----------------------------------------------------------------------------
Object_wx_RichTextStdRenderer::~Object_wx_RichTextStdRenderer()
{
}

Object *Object_wx_RichTextStdRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStdRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStdRenderer:");
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
// Class implementation for wxRichTextStdRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStdRenderer)
{
}

Gura_ImplementDescendantCreator(wx_RichTextStdRenderer)
{
	return new Object_wx_RichTextStdRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
