//----------------------------------------------------------------------------
// wxHtmlColourCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlColourCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlColourCell
//----------------------------------------------------------------------------
Object_wx_HtmlColourCell::~Object_wx_HtmlColourCell()
{
}

Object *Object_wx_HtmlColourCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlColourCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlColourCell:");
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
Gura_DeclareMethod(wx_HtmlColourCell, wxHtmlColourCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlColourCell, wxHtmlColourCell)
{
	Object_wx_HtmlColourCell *pThis = Object_wx_HtmlColourCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int clr = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxHtmlColourCell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlColourCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlColourCell)
{
	Gura_AssignMethod(wx_HtmlColourCell, wxHtmlColourCell);
}

Gura_ImplementDescendantCreator(wx_HtmlColourCell)
{
	return new Object_wx_HtmlColourCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
