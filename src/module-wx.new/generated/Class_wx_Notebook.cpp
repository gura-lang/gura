//----------------------------------------------------------------------------
// wxNotebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNotebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNotebook
//----------------------------------------------------------------------------
Object_wx_Notebook::~Object_wx_Notebook()
{
}

Object *Object_wx_Notebook::Clone() const
{
	return nullptr;
}

String Object_wx_Notebook::ToString(bool exprFlag)
{
	String rtn("<wx.Notebook:");
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
Gura_DeclareFunctionAlias(__wxNotebook, "wxNotebook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Notebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxNotebook)
{
	//wxNotebook();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxNotebook_1, "wxNotebook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Notebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxNotebook_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//wxNotebook();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Notebook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __Create)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_Notebook, __GetRowCount, "GetRowCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Notebook, __GetRowCount)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __GetThemeBackgroundColour, "GetThemeBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Notebook, __GetThemeBackgroundColour)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetThemeBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __OnSelChange, "OnSelChange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __OnSelChange)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSelChange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __SetPadding, "SetPadding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "padding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __SetPadding)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int padding = arg.GetNumber(0)
	//pThis->GetEntity()->SetPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __GetPageImage, "GetPageImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __GetPageImage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nPage = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __SetPageImage, "SetPageImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __SetPageImage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __GetPageText, "GetPageText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __GetPageText)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nPage = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __SetPageText, "SetPageText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __SetPageText)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Notebook, __GetSelection)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __SetSelection)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __ChangeSelection, "ChangeSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __ChangeSelection)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Notebook, __InsertPage, "InsertPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, __InsertPage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int select = arg.GetNumber(3)
	//int imageId = arg.GetNumber(4)
	//pThis->GetEntity()->InsertPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Notebook)
{
	// Constructor assignment
	Gura_AssignFunction(__wxNotebook);
	Gura_AssignFunction(__wxNotebook_1);
	// Method assignment
	Gura_AssignMethod(wx_Notebook, __Create);
	Gura_AssignMethod(wx_Notebook, __GetRowCount);
	Gura_AssignMethod(wx_Notebook, __GetThemeBackgroundColour);
	Gura_AssignMethod(wx_Notebook, __OnSelChange);
	Gura_AssignMethod(wx_Notebook, __SetPadding);
	Gura_AssignMethod(wx_Notebook, __GetPageImage);
	Gura_AssignMethod(wx_Notebook, __SetPageImage);
	Gura_AssignMethod(wx_Notebook, __GetPageText);
	Gura_AssignMethod(wx_Notebook, __SetPageText);
	Gura_AssignMethod(wx_Notebook, __GetSelection);
	Gura_AssignMethod(wx_Notebook, __SetSelection);
	Gura_AssignMethod(wx_Notebook, __ChangeSelection);
	Gura_AssignMethod(wx_Notebook, __InsertPage);
}

Gura_ImplementDescendantCreator(wx_Notebook)
{
	return new Object_wx_Notebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
