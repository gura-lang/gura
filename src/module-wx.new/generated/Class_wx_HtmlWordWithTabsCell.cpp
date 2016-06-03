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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlWordWithTabsCell, __wxHtmlWordWithTabsCell, "wxHtmlWordWithTabsCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "word", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wordOrig", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "linepos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWordWithTabsCell, __wxHtmlWordWithTabsCell)
{
	Object_wx_HtmlWordWithTabsCell *pThis = Object_wx_HtmlWordWithTabsCell::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int word = arg.GetNumber(0)
	//int wordOrig = arg.GetNumber(1)
	//int linepos = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//pThis->GetEntity()->wxHtmlWordWithTabsCell();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWordWithTabsCell)
{
	Gura_AssignMethod(wx_HtmlWordWithTabsCell, __wxHtmlWordWithTabsCell);
}

Gura_ImplementDescendantCreator(wx_HtmlWordWithTabsCell)
{
	return new Object_wx_HtmlWordWithTabsCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
