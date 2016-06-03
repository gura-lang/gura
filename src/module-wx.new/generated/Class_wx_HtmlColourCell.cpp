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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlColourCell, "HtmlColourCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlColourCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlColourCell)
{
	//int clr = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxHtmlColourCell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlColourCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlColourCell)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlColourCell);
}

Gura_ImplementDescendantCreator(wx_HtmlColourCell)
{
	return new Object_wx_HtmlColourCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
