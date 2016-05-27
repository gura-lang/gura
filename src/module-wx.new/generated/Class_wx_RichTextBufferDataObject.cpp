//----------------------------------------------------------------------------
// wxRichTextBufferDataObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextBufferDataObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextBufferDataObject
//----------------------------------------------------------------------------
Object_wx_RichTextBufferDataObject::~Object_wx_RichTextBufferDataObject()
{
}

Object *Object_wx_RichTextBufferDataObject::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextBufferDataObject::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextBufferDataObject:");
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
// Class implementation for wxRichTextBufferDataObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextBufferDataObject)
{
}

Gura_ImplementDescendantCreator(wx_RichTextBufferDataObject)
{
	return new Object_wx_RichTextBufferDataObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
