//----------------------------------------------------------------------------
// wxTreebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreebook
//----------------------------------------------------------------------------
Object_wx_Treebook::~Object_wx_Treebook()
{
}

Object *Object_wx_Treebook::Clone() const
{
	return nullptr;
}

String Object_wx_Treebook::ToString(bool exprFlag)
{
	String rtn("<wx.Treebook:");
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
Gura_DeclareFunctionAlias(__Treebook, "Treebook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Treebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Treebook)
{
	//wxTreebook();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Treebook_1, "Treebook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Treebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Treebook_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxTreebook(parent, id, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Treebook, __AddPage, "AddPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bSelect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __AddPage)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//bool bSelect = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//pThis->GetEntity()->AddPage(page, text, bSelect, imageId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __AddSubPage, "AddSubPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bSelect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __AddSubPage)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//bool bSelect = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//pThis->GetEntity()->AddSubPage(page, text, bSelect, imageId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __CollapseNode, "CollapseNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __CollapseNode)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pageId = arg.GetNumber(0)
	//pThis->GetEntity()->CollapseNode(pageId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __Create)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_Treebook, __DeletePage, "DeletePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __DeletePage)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pagePos = arg.GetNumber(0)
	//pThis->GetEntity()->DeletePage(pagePos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __ExpandNode, "ExpandNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __ExpandNode)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pageId = arg.GetNumber(0)
	//bool expand = arg.GetNumber(1)
	//pThis->GetEntity()->ExpandNode(pageId, expand);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __GetPageParent, "GetPageParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __GetPageParent)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageParent(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Treebook, __GetSelection)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __InsertPage, "InsertPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bSelect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __InsertPage)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pagePos = arg.GetNumber(0)
	//wxWindow* page = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//bool bSelect = arg.GetNumber(3)
	//int imageId = arg.GetNumber(4)
	//pThis->GetEntity()->InsertPage(pagePos, page, text, bSelect, imageId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __InsertSubPage, "InsertSubPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bSelect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __InsertSubPage)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pagePos = arg.GetNumber(0)
	//wxWindow* page = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//bool bSelect = arg.GetNumber(3)
	//int imageId = arg.GetNumber(4)
	//pThis->GetEntity()->InsertSubPage(pagePos, page, text, bSelect, imageId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Treebook, __IsNodeExpanded, "IsNodeExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, __IsNodeExpanded)
{
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pageId = arg.GetNumber(0)
	//pThis->GetEntity()->IsNodeExpanded(pageId);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Treebook)
{
	// Constructor assignment
	Gura_AssignFunction(__Treebook);
	Gura_AssignFunction(__Treebook_1);
	// Method assignment
	Gura_AssignMethod(wx_Treebook, __AddPage);
	Gura_AssignMethod(wx_Treebook, __AddSubPage);
	Gura_AssignMethod(wx_Treebook, __CollapseNode);
	Gura_AssignMethod(wx_Treebook, __Create);
	Gura_AssignMethod(wx_Treebook, __DeletePage);
	Gura_AssignMethod(wx_Treebook, __ExpandNode);
	Gura_AssignMethod(wx_Treebook, __GetPageParent);
	Gura_AssignMethod(wx_Treebook, __GetSelection);
	Gura_AssignMethod(wx_Treebook, __InsertPage);
	Gura_AssignMethod(wx_Treebook, __InsertSubPage);
	Gura_AssignMethod(wx_Treebook, __IsNodeExpanded);
}

Gura_ImplementDescendantCreator(wx_Treebook)
{
	return new Object_wx_Treebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
