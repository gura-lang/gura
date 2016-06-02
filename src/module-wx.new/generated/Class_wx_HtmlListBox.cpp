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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlListBox, wxHtmlListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, wxHtmlListBox)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxHtmlListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, wxHtmlListBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlListBox, wxHtmlListBox_1)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlListBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, Create)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, GetFileSystem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlListBox, GetFileSystem)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileSystem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, GetFileSystem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlListBox, GetFileSystem_1)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileSystem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, OnLinkClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, OnLinkClicked)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int link = arg.GetNumber(1)
	//pThis->GetEntity()->OnLinkClicked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, GetSelectedTextBgColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, GetSelectedTextBgColour)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colBg = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectedTextBgColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, GetSelectedTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colFg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, GetSelectedTextColour)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colFg = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelectedTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, OnGetItemMarkup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, OnGetItemMarkup)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetItemMarkup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlListBox, OnGetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlListBox, OnGetItem)
{
	Object_wx_HtmlListBox *pThis = Object_wx_HtmlListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->OnGetItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlListBox)
{
	Gura_AssignMethod(wx_HtmlListBox, wxHtmlListBox);
	Gura_AssignMethod(wx_HtmlListBox, wxHtmlListBox_1);
	Gura_AssignMethod(wx_HtmlListBox, Create);
	Gura_AssignMethod(wx_HtmlListBox, GetFileSystem);
	Gura_AssignMethod(wx_HtmlListBox, GetFileSystem_1);
	Gura_AssignMethod(wx_HtmlListBox, OnLinkClicked);
	Gura_AssignMethod(wx_HtmlListBox, GetSelectedTextBgColour);
	Gura_AssignMethod(wx_HtmlListBox, GetSelectedTextColour);
	Gura_AssignMethod(wx_HtmlListBox, OnGetItemMarkup);
	Gura_AssignMethod(wx_HtmlListBox, OnGetItem);
}

Gura_ImplementDescendantCreator(wx_HtmlListBox)
{
	return new Object_wx_HtmlListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
