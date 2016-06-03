//----------------------------------------------------------------------------
// wxPropertyGridManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridManager
//----------------------------------------------------------------------------
Object_wx_PropertyGridManager::~Object_wx_PropertyGridManager()
{
}

Object *Object_wx_PropertyGridManager::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridManager::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridManager:");
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
Gura_DeclareMethodAlias(wx_PropertyGridManager, __AddPage, "AddPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __AddPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int bmp = arg.GetNumber(1)
	//int pageObj = arg.GetNumber(2)
	//pThis->GetEntity()->AddPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __Clear)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __ClearPage, "ClearPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __ClearPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->ClearPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __CommitChangesFromEditor, "CommitChangesFromEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __CommitChangesFromEditor)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CommitChangesFromEditor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __Create)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_PropertyGridManager, __EnableCategories, "EnableCategories")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __EnableCategories)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableCategories();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __EnsureVisible)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetColumnCount)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetDescBoxHeight, "GetDescBoxHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetDescBoxHeight)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescBoxHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetGrid, "GetGrid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetGrid)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGrid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetVIterator, "GetVIterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetVIterator)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetVIterator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetCurrentPage, "GetCurrentPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetCurrentPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPage, "GetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ind = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPage_1, "GetPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPage_1)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPageByName, "GetPageByName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPageByName)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageByName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPageCount, "GetPageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPageCount)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPageName, "GetPageName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPageName)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPageRoot, "GetPageRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPageRoot)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageRoot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetSelectedPage, "GetSelectedPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetSelectedPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetSelectedProperty, "GetSelectedProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetSelectedProperty)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetSelection)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetToolBar, "GetToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetToolBar)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __InsertPage, "InsertPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __InsertPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bmp = arg.GetNumber(2)
	//int pageObj = arg.GetNumber(3)
	//pThis->GetEntity()->InsertPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __IsAnyModified, "IsAnyModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __IsAnyModified)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAnyModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __IsFrozen, "IsFrozen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __IsFrozen)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFrozen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __IsPageModified, "IsPageModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __IsPageModified)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->IsPageModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __IsPropertySelected, "IsPropertySelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __IsPropertySelected)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertySelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __RemovePage, "RemovePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __RemovePage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SelectPage, "SelectPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SelectPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SelectPage_1, "SelectPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SelectPage_1)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SelectPage_2, "SelectPage_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SelectPage_2)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SelectProperty, "SelectProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SelectProperty)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int focus = arg.GetNumber(1)
	//pThis->GetEntity()->SelectProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetColumnCount, "SetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colCount", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetColumnCount)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colCount = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetColumnTitle, "SetColumnTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetColumnTitle)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetDescription, "SetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "content", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetDescription)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int content = arg.GetNumber(1)
	//pThis->GetEntity()->SetDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetDescBoxHeight, "SetDescBoxHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ht", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetDescBoxHeight)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ht = arg.GetNumber(0)
	//int refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetDescBoxHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetSplitterLeft, "SetSplitterLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "subProps", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "allPages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetSplitterLeft)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int subProps = arg.GetNumber(0)
	//int allPages = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetPageSplitterLeft, "SetPageSplitterLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subProps", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetPageSplitterLeft)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int subProps = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageSplitterLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetPageSplitterPosition, "SetPageSplitterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetPageSplitterPosition)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int column = arg.GetNumber(2)
	//pThis->GetEntity()->SetPageSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetSplitterPosition, "SetSplitterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetSplitterPosition)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __ShowHeader, "ShowHeader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __ShowHeader)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHeader();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __CreatePropertyGrid, "CreatePropertyGrid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __CreatePropertyGrid)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreatePropertyGrid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGridManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridManager)
{
	Gura_AssignMethod(wx_PropertyGridManager, __AddPage);
	Gura_AssignMethod(wx_PropertyGridManager, __Clear);
	Gura_AssignMethod(wx_PropertyGridManager, __ClearPage);
	Gura_AssignMethod(wx_PropertyGridManager, __CommitChangesFromEditor);
	Gura_AssignMethod(wx_PropertyGridManager, __Create);
	Gura_AssignMethod(wx_PropertyGridManager, __EnableCategories);
	Gura_AssignMethod(wx_PropertyGridManager, __EnsureVisible);
	Gura_AssignMethod(wx_PropertyGridManager, __GetColumnCount);
	Gura_AssignMethod(wx_PropertyGridManager, __GetDescBoxHeight);
	Gura_AssignMethod(wx_PropertyGridManager, __GetGrid);
	Gura_AssignMethod(wx_PropertyGridManager, __GetVIterator);
	Gura_AssignMethod(wx_PropertyGridManager, __GetCurrentPage);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPage);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPage_1);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPageByName);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPageCount);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPageName);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPageRoot);
	Gura_AssignMethod(wx_PropertyGridManager, __GetSelectedPage);
	Gura_AssignMethod(wx_PropertyGridManager, __GetSelectedProperty);
	Gura_AssignMethod(wx_PropertyGridManager, __GetSelection);
	Gura_AssignMethod(wx_PropertyGridManager, __GetToolBar);
	Gura_AssignMethod(wx_PropertyGridManager, __InsertPage);
	Gura_AssignMethod(wx_PropertyGridManager, __IsAnyModified);
	Gura_AssignMethod(wx_PropertyGridManager, __IsFrozen);
	Gura_AssignMethod(wx_PropertyGridManager, __IsPageModified);
	Gura_AssignMethod(wx_PropertyGridManager, __IsPropertySelected);
	Gura_AssignMethod(wx_PropertyGridManager, __RemovePage);
	Gura_AssignMethod(wx_PropertyGridManager, __SelectPage);
	Gura_AssignMethod(wx_PropertyGridManager, __SelectPage_1);
	Gura_AssignMethod(wx_PropertyGridManager, __SelectPage_2);
	Gura_AssignMethod(wx_PropertyGridManager, __SelectProperty);
	Gura_AssignMethod(wx_PropertyGridManager, __SetColumnCount);
	Gura_AssignMethod(wx_PropertyGridManager, __SetColumnTitle);
	Gura_AssignMethod(wx_PropertyGridManager, __SetDescription);
	Gura_AssignMethod(wx_PropertyGridManager, __SetDescBoxHeight);
	Gura_AssignMethod(wx_PropertyGridManager, __SetSplitterLeft);
	Gura_AssignMethod(wx_PropertyGridManager, __SetPageSplitterLeft);
	Gura_AssignMethod(wx_PropertyGridManager, __SetPageSplitterPosition);
	Gura_AssignMethod(wx_PropertyGridManager, __SetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGridManager, __ShowHeader);
	Gura_AssignMethod(wx_PropertyGridManager, __CreatePropertyGrid);
}

Gura_ImplementDescendantCreator(wx_PropertyGridManager)
{
	return new Object_wx_PropertyGridManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
