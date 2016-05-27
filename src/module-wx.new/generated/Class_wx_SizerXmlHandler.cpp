//----------------------------------------------------------------------------
// wxSizerXmlHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizerXmlHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizerXmlHandler
//----------------------------------------------------------------------------
Object_wx_SizerXmlHandler::~Object_wx_SizerXmlHandler()
{
}

Object *Object_wx_SizerXmlHandler::Clone() const
{
	return nullptr;
}

String Object_wx_SizerXmlHandler::ToString(bool exprFlag)
{
	String rtn("<wx.SizerXmlHandler:");
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
// Class implementation for wxSizerXmlHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SizerXmlHandler)
{
}

Gura_ImplementDescendantCreator(wx_SizerXmlHandler)
{
	return new Object_wx_SizerXmlHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
