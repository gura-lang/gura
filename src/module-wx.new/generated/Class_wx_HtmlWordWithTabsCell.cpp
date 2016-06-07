//----------------------------------------------------------------------------
// wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
Object_wx_HtmlWordWithTabsCell::~Object_wx_HtmlWordWithTabsCell()
{
}

Object *Object_wx_HtmlWordWithTabsCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWordWithTabsCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWordWithTabsCell:");
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
Gura_DeclareFunctionAlias(__HtmlWordWithTabsCell, "HtmlWordWithTabsCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "word", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wordOrig", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "linepos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWordWithTabsCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlWordWithTabsCell)
{
	//const wxString& word = arg.GetNumber(0)
	//const wxString& wordOrig = arg.GetNumber(1)
	//size_t linepos = arg.GetNumber(2)
	//const wxDC& dc = arg.GetNumber(3)
	//wxHtmlWordWithTabsCell(word, wordOrig, linepos, dc);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWordWithTabsCell)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlWordWithTabsCell);
}

Gura_ImplementDescendantCreator(wx_HtmlWordWithTabsCell)
{
	return new Object_wx_HtmlWordWithTabsCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
