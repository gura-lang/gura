//----------------------------------------------------------------------------
// wxMessageOutputMessageBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageOutputMessageBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageOutputMessageBox
//----------------------------------------------------------------------------
Object_wx_MessageOutputMessageBox::~Object_wx_MessageOutputMessageBox()
{
}

Object *Object_wx_MessageOutputMessageBox::Clone() const
{
	return nullptr;
}

String Object_wx_MessageOutputMessageBox::ToString(bool exprFlag)
{
	String rtn("<wx.MessageOutputMessageBox:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxMessageOutputMessageBox, "wxMessageOutputMessageBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MessageOutputMessageBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxMessageOutputMessageBox)
{
	//wxMessageOutputMessageBox();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageOutputMessageBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutputMessageBox)
{
	// Constructor assignment
	Gura_AssignFunction(__wxMessageOutputMessageBox);
}

Gura_ImplementDescendantCreator(wx_MessageOutputMessageBox)
{
	return new Object_wx_MessageOutputMessageBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
