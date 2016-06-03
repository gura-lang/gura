//----------------------------------------------------------------------------
// wxHtmlWidgetCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWidgetCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Object_wx_HtmlWidgetCell::~Object_wx_HtmlWidgetCell()
{
}

Object *Object_wx_HtmlWidgetCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWidgetCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWidgetCell:");
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
Gura_DeclareFunctionAlias(__HtmlWidgetCell, "HtmlWidgetCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWidgetCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlWidgetCell)
{
	//int wnd = arg.GetNumber(0)
	//int w = arg.GetNumber(1)
	//wxHtmlWidgetCell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWidgetCell)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlWidgetCell);
}

Gura_ImplementDescendantCreator(wx_HtmlWidgetCell)
{
	return new Object_wx_HtmlWidgetCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
