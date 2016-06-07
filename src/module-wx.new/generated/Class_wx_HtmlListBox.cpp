//----------------------------------------------------------------------------
// wxHtmlListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlListBox
//----------------------------------------------------------------------------
Object_wx_HtmlListBox::~Object_wx_HtmlListBox()
{
}

Object *Object_wx_HtmlListBox::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlListBox::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlListBox:");
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
Gura_DeclareFunctionAlias(__HtmlListBox, "HtmlListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlListBox)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxHtmlListBox(parent, id, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HtmlListBox_1, "HtmlListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlListBox_1)
{
	//wxHtmlListBox();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlListBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, __Create)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create(parent, id, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlListBox, __GetFileSystem, "GetFileSystem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlListBox, __GetFileSystem)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileSystem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlListBox, __GetFileSystem_1, "GetFileSystem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlListBox, __GetFileSystem_1)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileSystem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlListBox, __OnLinkClicked, "OnLinkClicked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, __OnLinkClicked)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//const wxHtmlLinkInfo& link = arg.GetNumber(1)
	//pThis->GetEntity()->OnLinkClicked(n, link);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlListBox, __GetSelectedTextBgColour, "GetSelectedTextBgColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, __GetSelectedTextBgColour)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colBg = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectedTextBgColour(colBg);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlListBox, __GetSelectedTextColour, "GetSelectedTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colFg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, __GetSelectedTextColour)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colFg = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectedTextColour(colFg);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlListBox, __OnGetItemMarkup, "OnGetItemMarkup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, __OnGetItemMarkup)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetItemMarkup(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlListBox, __OnGetItem, "OnGetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, __OnGetItem)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetItem(n);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlListBox)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlListBox);
	Gura_AssignFunction(__HtmlListBox_1);
	// Method assignment
	Gura_AssignMethod(wx_HtmlListBox, __Create);
	Gura_AssignMethod(wx_HtmlListBox, __GetFileSystem);
	Gura_AssignMethod(wx_HtmlListBox, __GetFileSystem_1);
	Gura_AssignMethod(wx_HtmlListBox, __OnLinkClicked);
	Gura_AssignMethod(wx_HtmlListBox, __GetSelectedTextBgColour);
	Gura_AssignMethod(wx_HtmlListBox, __GetSelectedTextColour);
	Gura_AssignMethod(wx_HtmlListBox, __OnGetItemMarkup);
	Gura_AssignMethod(wx_HtmlListBox, __OnGetItem);
}

Gura_ImplementDescendantCreator(wx_HtmlListBox)
{
	return new Object_wx_HtmlListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
