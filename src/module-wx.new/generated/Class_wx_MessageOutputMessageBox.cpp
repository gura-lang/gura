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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MessageOutputMessageBox, wxMessageOutputMessageBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageOutputMessageBox, wxMessageOutputMessageBox)
{
	Object_wx_MessageOutputMessageBox *pThis = Object_wx_MessageOutputMessageBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMessageOutputMessageBox();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageOutputMessageBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutputMessageBox)
{
	Gura_AssignMethod(wx_MessageOutputMessageBox, wxMessageOutputMessageBox);
}

Gura_ImplementDescendantCreator(wx_MessageOutputMessageBox)
{
	return new Object_wx_MessageOutputMessageBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
