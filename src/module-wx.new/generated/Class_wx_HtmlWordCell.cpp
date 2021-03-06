//----------------------------------------------------------------------------
// wxHtmlWordCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWordCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWordCell
//----------------------------------------------------------------------------
Object_wx_HtmlWordCell::~Object_wx_HtmlWordCell()
{
}

Object *Object_wx_HtmlWordCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWordCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWordCell:");
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
Gura_DeclareFunctionAlias(__HtmlWordCell, "HtmlWordCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "word", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWordCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlWordCell)
{
	//const wxString& word = arg.GetNumber(0)
	//const wxDC& dc = arg.GetNumber(1)
	//wxHtmlWordCell(word, dc);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWordCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWordCell)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlWordCell);
}

Gura_ImplementDescendantCreator(wx_HtmlWordCell)
{
	return new Object_wx_HtmlWordCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
